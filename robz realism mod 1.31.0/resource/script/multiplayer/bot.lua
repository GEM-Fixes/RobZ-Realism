-- Robz competitive multiplayer bot.
-- The engine only lets a bot buy units (Spawn) and send a group to a flag (CaptureFlag), so all tactics here are
-- built from those two commands: what to buy, how groups are split, which flags are held, and how attacks are massed.
require([[/script/multiplayer/bot.data]])
require([[/script/multiplayer/bot.units]])
require([[/script/multiplayer/bot.maps]])

local C = BotConfig
local Api = BotApi
local unpack = unpack or table.unpack

local S = {
	t = 0, running = false, nextThink = 3, nextReport = 20,
	flags = {}, squads = {}, queue = {}, lastEvtT = -100, lastEvtInfo = nil,
	army = nil, armyName = nil, years = nil, cool = {}, fails = {}, failedRecently = {}, want = nil, firstBuy = false,
	geo = nil, side = nil, sideFixed = false, enemyCaps = {}, mapName = nil, mapTried = 0, mapInfo = "",
	primary = nil, wave = nil, waveId = 0, secondary = nil, tie = {},
	bought = 0, lost = 0, errs = 0, lastErrT = -1000, logFile = nil, logDir = nil, enemyTanks = false,
	-- robzbot.dll state
	pending = {}, unitInfo = {}, enemies = {}, home = nil, screenFor = {}, nextMicro = 0,
	stat = { moves = 0, runs = 0, calm = 0, atk = 0, disband = 0, badLayout = 0, engaged = 0, prone = 0, cover = 0, bound = 0, spotCover = 0, built = 0, mgBack = 0 },
	empSquads = {},
	vehKills = {}, softVeh = {},
	lineT = {}, lanes = {}, capTeam = {}, capCool = {}, names = {}, atList = {}, walls = {}, faceVotes = { 0, 0, 0, 0 }, faceCal = 0,smokeT = {}, men = {}, singleT = {}, lastSingleT = -1000, later = {}, coverRes = {},
}
local R = nil            -- the robzbot.dll table when loaded
local RInfo = "not tried"

------------------------------------------------------------------ output
local function Log(msg)
	if not C.Debug then return end
	local line = string.format("[%02d:%02d] %s", math.floor(S.t / 60), S.t % 60, msg)
	pcall(function() print("[robz bot " .. tostring(Api.Instance.playerId) .. "] " .. line) end)   -- ends up in game.log
	if S.logFile then pcall(function() S.logFile:write(line .. "\n"); S.logFile:flush() end) end
end

local function Chat(msg)
	if not C.Debug then return end
	if not pcall(function() Api.Commands:SayChat(msg) end) then
		pcall(function() Api.Commands:SayChat(Api.Instance.playerId, msg) end)
	end
end

local function Safe(name, fn, ...)
	local args = { ... }
	local ok, err = pcall(function() return fn(unpack(args)) end)
	if not ok then
		S.errs = S.errs + 1
		Log("ERROR in " .. name .. ": " .. tostring(err))
		if S.t - S.lastErrT > 60 then S.lastErrT = S.t; Chat("[AI] script error in " .. name .. ": " .. tostring(err)) end
	end
end

local function OpenLog()
	if not C.Debug or not io or not io.open then return end
	local up = os.getenv and os.getenv("USERPROFILE")
	if not up then return end
	local tail = "\\my games\\men of war - assault squad 2\\log\\"
	for _, d in ipairs({ up .. "\\Documents" .. tail, up .. "\\OneDrive\\Documents" .. tail, up .. "\\OneDrive\\Dokumente" .. tail, up .. "\\OneDrive\\Documenten" .. tail }) do
		local f = io.open(d .. "robz_bot_" .. tostring(Api.Instance.playerId) .. ".log", "a")
		if f then S.logFile = f; S.logDir = d; f:write("\n===== new game " .. os.date("%Y-%m-%d %H:%M:%S") .. " =====\n"); f:flush(); return end
	end
end

------------------------------------------------------------------ helpers
local function Dist(p, q) local dx, dy = p[1] - q[1], p[2] - q[2]; return math.sqrt(dx * dx + dy * dy) end
local function Other(side) if side == "a" then return "b" else return "a" end end
local function FlagPos(name)
	if not S.geo or not name then return nil end
	local st = S.flags[name]
	return S.geo.f[st and st.key or string.lower(name)]
end
local function BasePos() return S.geo and S.geo[S.side] end
local function EnemyBasePos() return S.geo and S.geo[Other(S.side)] end
local function SquadPos(sq) return sq.pos or FlagPos(sq.flag) or BasePos() end
local Vehicle = { light = true, tank = true, td = true, heavy = true }
local function IsVehicleRole(r) return Vehicle[r] == true end
-- a gun or vehicle with its crew: bought whole, never disbanded, counted per piece
-- towed guns (emplacements and AT guns) move only with the game's squad order, so they keep their crew together
local Gun = { emplace = true, atgun = true }
local function IsCrewed(r) return Vehicle[r] == true or Gun[r] == true end
local function Strength(sq)
	local s = BotStrength[sq.role] or 1
	if not IsCrewed(sq.role) then s = s * math.max(1, C.InfantrySplit or 4) / 4 end
	return s
end
local function Count(t) local n = 0; for _ in pairs(t) do n = n + 1 end; return n end

------------------------------------------------------------------ robzbot.dll
local function LoadRobz()
	if not C.UseRobzDll then RInfo = "disabled in bot.data"; return end
	if not package or not package.loadlib then RInfo = "package.loadlib is missing"; return end
	local errs = {}
	for _, p in ipairs(C.RobzDllPaths or {}) do
		local open, err = package.loadlib(p, "robzbot_open")
		if open then
			local ok, api, why = pcall(open, Api.Instance.playerId, Api.Instance.hostId)
			if ok and type(api) == "table" then R = api; RInfo = "loaded v" .. tostring(api.version) .. " from " .. p; return end
			RInfo = "found " .. p .. " but it failed to start: " .. tostring(ok and why or api)
			return
		end
		table.insert(errs, p .. ": " .. tostring(err))
	end
	RInfo = "not loaded (" .. table.concat(errs, " | ") .. ")"
end

local function EnemyNear(p, range)
	for _, e in ipairs(S.enemies) do
		local dx, dy = e.x - p[1], e.y - p[2]
		if dx * dx + dy * dy < range * range then return true end
	end
	return false
end

-- any enemy at all (the director's full picture) near a point: soldiers walk there instead of sprinting in blind
local function AnyEnemyNear(p, range)
	for _, e in ipairs(S.allEnemies or S.enemies) do
		local dx, dy = e.x - p[1], e.y - p[2]
		if dx * dx + dy * dy < range * range then return true end
	end
	return false
end

-- an enemy our side can see near a point (what a soldier there is being shot by)
local function SeenNear(p, range)
	for _, e in ipairs(S.enemies or {}) do
		local dx, dy = e.x - p[1], e.y - p[2]
		if dx * dx + dy * dy < range * range then return true end
	end
	return false
end

-- stance orders: never the stance he already has, and at most one per PoseGap seconds per soldier (force: standing
-- up to move skips the wait). Replays: humans change stance ~2 times per 10 minutes
local function SetPose(sq, pose, force)
	local cur = sq.prone and (sq.poseKind or 1) or 0
	if cur == pose then return false end
	if not force and S.t - (sq.poseT or -1e9) < (C.PoseGap or 0) then return false end
	if not pcall(R.Pose, sq.uid, pose) then return false end
	sq.prone = (pose ~= 0) or nil; sq.poseKind = pose; sq.poseT = S.t
	S.stat.poses = (S.stat.poses or 0) + 1
	return true
end

-- how far (degrees) a vehicle's hull points away from an enemy
local function FaceOff(sq, en)
	if not (sq.fx and sq.pos) or (sq.fx == 0 and sq.fy == 0) then return 0 end
	local h = math.atan2(sq.fy, sq.fx) + (S.faceCal or 0)
	local t = math.atan2(en.y - sq.pos[2], en.x - sq.pos[1])
	local d = math.abs((t - h + math.pi) % (2 * math.pi) - math.pi)
	return d * 180 / math.pi
end
-- a tank / TD fights hull first. The turn is a move to where it stands with a facing point at the enemy: the game's
-- look-at order then rotates the hull (eLookAt -> Rotate). Any new order cancels that turn, so while it runs nothing
-- else is sent - the attack follows once the hull points at the enemy. A turn that runs out of time (blocked, target
-- moving) is not tried on that target again for TurnRetry s; the tank fires as it stands meanwhile.
-- Returns true while the vehicle is turning (no attack order sent).
local function FaceThenAttack(sq, en)
	local tol = (sq.role == "td") and (C.FaceTolTD or 12) or (C.FaceTolTank or 30)
	local off = sq.fx and FaceOff(sq, en) or 0
	local tr = sq.turning
	if off <= tol then
		if tr then S.stat.turnOk = (S.stat.turnOk or 0) + 1 end
		sq.turning = nil
		pcall(R.Attack, sq.uid, en.id)
		return false
	end
	if tr and tr.id == en.id then
		if S.t < tr.untilT then return true end
		sq.turning = nil; sq.turnFail = { id = en.id, untilT = S.t + (C.TurnRetry or 20) }
		S.stat.turnFail = (S.stat.turnFail or 0) + 1
		if S.stat.turnFail <= 3 then Log(string.format("%s %s could not turn to enemy %s (still %d degrees off) - firing as it stands", sq.role, tostring(sq.uid), tostring(en.id), math.floor(off))) end
		pcall(R.Attack, sq.uid, en.id)
		return false
	end
	if sq.turnFail and sq.turnFail.id == en.id and S.t < sq.turnFail.untilT then
		pcall(R.Attack, sq.uid, en.id)
		return false
	end
	pcall(R.Move, sq.uid, sq.pos[1], sq.pos[2], false, 0, en.x, en.y)
	sq.turning = { id = en.id, untilT = S.t + (C.TurnMax or 10) }
	S.stat.faced = (S.stat.faced or 0) + 1
	if S.stat.faced <= 4 then Log(string.format("%s %s turns its hull to enemy %s (%s), %d degrees off", sq.role, tostring(sq.uid), tostring(en.id), S.names[en.id] or "?", math.floor(off))) end
	return true
end

-- a known enemy machine gun or crewed vehicle within DangerDist of p (fog ignored): soldiers there walk - the advance
-- order stops to shoot and drops into cover - instead of sprinting upright across its field of fire
local function DangerNear(p)
	local r = C.DangerDist
	if not (r and p) then return false end
	local r2 = r * r
	for _, m in ipairs(S.mgList or {}) do
		local dx, dy = m[1] - p[1], m[2] - p[2]
		if dx * dx + dy * dy < r2 then return true end
	end
	local wr = S.wreck or {}
	for _, en in ipairs(S.allEnemies or {}) do
		if not en.human and not wr[en.id] then
			local dx, dy = en.x - p[1], en.y - p[2]
			if dx * dx + dy * dy < r2 then return true end
		end
	end
	return false
end

local IntelDry   -- map intel: a spot in deep water / no-go ground moves to the nearest passable cell (defined below)
local IntelFirePos, IntelFlagValue   -- map intel phase 3: firing positions on our side of a flag, flag value 0-100 (below)

local function MoveUnit(sq, d)
	if IntelDry then d = IntelDry(d) end
	local run = false
	sq.retreat = nil
	if C.Run and sq.pos then
		-- falling back (destination further from the enemy base): always run; else run when no enemy is close
		local eb = EnemyBasePos()
		local retreat = eb and Dist(d, eb) > Dist(sq.pos, eb) + 200
		-- the capture team walks into a zone the enemy can shoot into (they jogged in and all died)
		local calmDest = (sq.capFlag and sq.task ~= "dig" and C.CapWalkDist) or C.CalmDestDist or C.CalmDist
		run = Dist(sq.pos, d) > C.RunDist and (retreat or (not AnyEnemyNear(sq.pos, C.CalmDist) and not AnyEnemyNear(d, calmDest)))
		if run and not retreat and sq.human and (DangerNear(sq.pos) or DangerNear(d)) then
			run = false; S.stat.dangerWalk = (S.stat.dangerWalk or 0) + 1
		end
		sq.retreat = run and retreat or nil
	end
	sq.coveredAt = nil; sq.coverEnt = nil
	local ok, r = pcall(R.Move, sq.uid, d[1], d[2], run, 0)
	if not ok then Log("Move failed for unit " .. tostring(sq.uid) .. ": " .. tostring(r)); return end
	if r == 2 then S.stat.badLayout = S.stat.badLayout + 1 end
	if S.stat.moves == 0 then Log("first unit move: result " .. tostring(r) .. " (1 = ok, 2 = run flag skipped: command layout check failed)") end
	S.stat.moves = S.stat.moves + 1
	if run then S.stat.runs = S.stat.runs + 1 end
	sq.running = run; sq.dest = d
end

-- how far a point is along the line from our base toward theirs (game units), plus that direction
local function Prog(p)
	local h, e = BasePos(), EnemyBasePos()
	if not h or not e then return nil end
	local dx, dy = e[1] - h[1], e[2] - h[2]
	local L = math.max(1, math.sqrt(dx * dx + dy * dy))
	return ((p[1] - h[1]) * dx + (p[2] - h[2]) * dy) / L, dx / L, dy / L
end

local function NearestEnemyMan(p)
	local best, bd = nil, math.huge
	for _, e in ipairs(S.allEnemies or S.enemies) do
		if e.human then
			local dx, dy = e.x - p[1], e.y - p[2]
			local d = dx * dx + dy * dy
			if d < bd then best, bd = e, d end
		end
	end
	return best, math.sqrt(bd)
end

-- vehicles fight the way players use them (replays): they stay a class-dependent distance behind our own infantry
-- front and keep away from enemy infantry (bazookas, AT grenades); bigger guns hang further back
local function VehDestPlan(sq, d)
	if not d or not S.front or sq.exploit then return d end
	local W = S.wave
	if W and W.launched and W.full and sq.flag == W.target then return d end   -- full-force attack: everyone goes in
	local back = C.VehBack and C.VehBack[sq.role]
	if not back then return d end
	-- opening minutes: light tanks and armoured cars lead the infantry to grab ground (no hanging back)
	local early = C.EarlyPush and S.t < C.EarlyPush and sq.role == "light"
	if early then back = -600 end
	local pr, ux, uy = Prog(d)
	if not pr then return d end
	local cap = S.front - back
	if pr > cap then d = { d[1] - ux * (pr - cap), d[2] - uy * (pr - cap) } end
	local minInf = C.VehMinInf and C.VehMinInf[sq.role]
	if minInf and early then minInf = minInf * 0.5 end
	if minInf then
		for _ = 1, 6 do
			local e, de = NearestEnemyMan(d)
			if not e or de >= minInf then break end
			d = { d[1] - ux * (minInf - de + 100), d[2] - uy * (minInf - de + 100) }
		end
	end
	local minArm = C.VehMinArmor and C.VehMinArmor[sq.role]
	if minArm then
		for _ = 1, 6 do
			local best, bd = nil, math.huge
			for _, e in ipairs(S.allEnemies or {}) do
				if not e.human then local dd = Dist(d, { e.x, e.y }); if dd < bd then best, bd = e, dd end end
			end
			if not best or bd >= minArm then break end
			d = { d[1] - ux * (minArm - bd + 100), d[2] - uy * (minArm - bd + 100) }
		end
	end
	-- a spot behind a wall or house is useless for a tank (they sat at the back, unable to shoot): if the spot can't
	-- see the nearest known enemy (or the flag), slide it sideways until it can
	if R.Clear and C.VehClearShift and sq.z then
		local e, ed = nil, math.huge
		for _, en in ipairs(S.allEnemies or {}) do local dd = Dist(d, { en.x, en.y }); if dd < ed then e, ed = en, dd end end
		local tgt = (e and ed < 4000) and { e.x, e.y } or FlagPos(sq.flag or sq.pflag or "")
		if tgt and Dist(d, tgt) > 300 then
			local z = sq.z
			local ok, clear = pcall(R.Clear, d[1], d[2], z, tgt[1], tgt[2], z)
			if ok and not clear then
				local tx, ty = tgt[1] - d[1], tgt[2] - d[2]
				local tl = math.max(1, math.sqrt(tx * tx + ty * ty))
				local px, py = -ty / tl, tx / tl
				for i = 1, (C.VehClearSteps or 6) do
					local hit = nil
					for _, sgn in ipairs({ 1, -1 }) do
						local s = sgn * i * C.VehClearShift
						local q = { d[1] + px * s, d[2] + py * s }
						local ok2, c2 = pcall(R.Clear, q[1], q[2], z, tgt[1], tgt[2], z)
						if ok2 and c2 then hit = q; break end
					end
					if hit then d = hit; S.stat.vehClear = (S.stat.vehClear or 0) + 1; break end
				end
			end
		end
	end
	return d
end

-- light vehicles keep out of reach of anything that kills them (AT soldiers, guns, tanks - the director's AT scan):
-- applied last, straight away from the nearest threat, even in a full-force attack
local function KeepFromAT(d, minAT)
	if d and minAT and S.atList and #S.atList > 0 then
		for _ = 1, 8 do
			local th, bd = nil, math.huge
			for _, a in ipairs(S.atList) do local dd = Dist(d, a); if dd < bd then th, bd = a, dd end end
			if not th or bd >= minAT then break end
			local ax, ay = d[1] - th[1], d[2] - th[2]
			if bd < 1 then local b = BasePos() or { th[1] + 100, th[2] }; ax, ay = b[1] - th[1], b[2] - th[2]; bd = math.max(1, Dist(b, th)) end
			local k = (minAT - bd + 50) / math.max(1, math.sqrt(ax * ax + ay * ay))
			d = { d[1] + ax * k, d[2] + ay * k }
		end
	end
	return d
end
local function VehDest(sq, d)
	return KeepFromAT(VehDestPlan(sq, d), C.VehMinAT and C.VehMinAT[sq.role])
end
-- the way an attack on a flag comes from: our nearest held flag, else our base
local function ApproachFrom(p)
	local from, fd = BasePos(), Dist(p, BasePos())
	for _, st in pairs(S.flags) do
		if st.owner == "us" then
			local q = FlagPos(st.name)
			if q then local d = Dist(p, q); if d > 1 and d < fd then from, fd = q, d end end
		end
	end
	return from
end

-- a unit's place on a line: 0, +1, -1, +2, -2 ... slots, then a second row
local function LaneOf(sq, flagName)
	sq.lane = sq.lane or {}
	if not sq.lane[flagName] then
		local n = S.lanes[flagName] or 0
		S.lanes[flagName] = n + 1
		sq.lane[flagName] = n
	end
	local n = sq.lane[flagName] % 24
	local k = n % 12
	local slot = (k % 2 == 1) and ((k + 1) / 2) or (-k / 2)
	return slot, (n >= 12) and 1 or 0
end

-- a firing position for this gunner at this flag: each gunner gets his own (in order of arrival), later ones share,
-- 6 m to the side per round; nil when the map has none for our side
local function FirePosFor(sq, flagName)
	if not (C.UseFirePos and IntelFirePos) then return nil end
	local fps = IntelFirePos(flagName)
	if not fps then return nil end
	sq.fpLane = sq.fpLane or {}
	if not sq.fpLane[flagName] then
		S.fpLanes = S.fpLanes or {}
		local n = S.fpLanes[flagName] or 0
		S.fpLanes[flagName] = n + 1
		sq.fpLane[flagName] = n
	end
	local n = sq.fpLane[flagName]
	local q = fps[(n % #fps) + 1]
	local wrap = math.floor(n / #fps)
	local off = (wrap % 2 == 1) and ((wrap + 1) / 2 * 120) or (-wrap / 2 * 120)
	sq.fpLogged = sq.fpLogged or {}
	if not sq.fpLogged[flagName] then
		sq.fpLogged[flagName] = true; S.stat.firePos = (S.stat.firePos or 0) + 1
		if q.src == "human" then
			S.stat.firePosHuman = (S.stat.firePosHuman or 0) + 1
			if S.stat.firePosHuman <= 2 then Log(string.format("%s %s takes a spot players held in replays at %s (%.0f,%.0f)", tostring(sq.role), tostring(sq.uid), flagName, q[1], q[2])) end
		end
		if S.stat.firePos <= 3 then Log(string.format("%s %s takes firing position %d of %d at %s (%.0f,%.0f, %s)", tostring(sq.role), tostring(sq.uid), (n % #fps) + 1, #fps, flagName, q[1], q[2], q.src == "human" and "where players set up in replays" or "from the map analysis")) end
	end
	return { q[1] + off, q[2] }
end

-- is the flag still defended (director), or can the line go in?
local function LinePhase(flagName)
	local st = S.flags[flagName]
	if not st or st.owner == "us" then return "assault" end
	local defenders = S.dir and (S.dir.near[flagName] or 0) or ((st.owner == "them") and 1 or 0)
	if defenders < 0.3 then return "assault" end
	S.lineT[flagName] = S.lineT[flagName] or S.t
	local early = C.EarlyPush and S.t < C.EarlyPush         -- opening minutes: go in sooner to take a foothold
	local lineMax = early and (C.EarlyLineMax or C.LineMax) or C.LineMax
	local ratio = early and (C.EarlyAssaultRatio or C.AssaultRatio) or C.AssaultRatio
	if S.t - S.lineT[flagName] > lineMax and (not S.dir or defenders < (early and (C.EarlyMaxDefenders or 1.5) or 1.5)) then return "assault" end
	local ours = 0
	local p = FlagPos(flagName)
	for _, sq in pairs(S.squads) do
		if sq.flag == flagName and sq.pos and p and Dist(sq.pos, p) < 2500 then ours = ours + Strength(sq) end
	end
	if ours >= defenders * ratio then return "assault" end
	return "line"
end

-- where one unit goes for an order, and in which phase: attackers form a line across the approach, holders spread
-- over the screen point or the flag zone
local function UnitDest(sq, flagName, task)
	local p = FlagPos(flagName)
	if not p then return nil end
	if not sq.ang then sq.ang = math.random() * 2 * math.pi; sq.rf = 0.2 + 0.7 * math.random() end
	local rad = (S.geo.radius and S.geo.radius[string.lower(flagName)]) or 25
	if rad <= 0 then rad = 25 end
	local cx, cy = p[1], p[2]
	if task == "dig" then
		-- defensive line behind the flag (our side), spread sideways toward the flags next to it, facing the enemy
		local eb = EnemyBasePos()
		local dx, dy = eb[1] - p[1], eb[2] - p[2]
		local len = math.max(1, math.sqrt(dx * dx + dy * dy))
		local ux, uy = dx / len, dy / len
		local px, py = -uy, ux
		sq.lane = sq.lane or {}
		local lkey = flagName .. "#dig"
		local slot, row = LaneOf(sq, lkey)
		sq.digSpot = sq.digSpot or {}
		local cached = sq.digSpot[flagName]
		if cached and cached.lane == sq.lane[lkey] then return cached.d, "dig" end
		-- gunners, snipers and AT riflemen take the map's firing positions for this flag (covered, seeing the zone)
		local fpd = sq.ranged and FirePosFor(sq, flagName)
		if fpd then
			sq.digSpot[flagName] = { lane = sq.lane[lkey], d = fpd }
			return fpd, "dig"
		end
		local back, side
		if sq.ranged then
			back = C.MGDigBack + (sq.snp and 200 or 0) + row * 150; side = slot * C.DigSpacing * 2.5
		else
			-- alternate bands: 25 m and 50 m behind the point; the lane numbers share out over both
			local bands = C.DigBands or { 500, 1000 }
			local n = sq.lane[lkey]
			local m = math.floor(n / #bands)
			local k = m % 12
			local s = (k % 2 == 1) and ((k + 1) / 2) or (-k / 2)
			back = bands[(n % #bands) + 1] + ((m >= 12) and 120 or 0)
			side = s * C.DigSpacing
		end
		local d = { p[1] - ux * back + px * side, p[2] - uy * back + py * side }
		-- not behind a building: the spot must see the front of the flag zone; else slide sideways until it does
		if R.Clear then
			local z = p[3] or 0
			local front = { p[1] + ux * rad * 0.5, p[2] + uy * rad * 0.5 }
			local ok, clear = pcall(R.Clear, d[1], d[2], z, front[1], front[2], z)
			if ok and not clear then
				local found = nil
				for i = 1, 6 do
					for _, sgn in ipairs({ 1, -1 }) do
						local s2 = side + sgn * i * C.DigClearShift
						local d2 = { p[1] - ux * back + px * s2, p[2] - uy * back + py * s2 }
						local ok2, c2 = pcall(R.Clear, d2[1], d2[2], z, front[1], front[2], z)
						if ok2 and c2 then found = d2; break end
					end
					if found then break end
				end
				if found then d = found; S.stat.digMoved = (S.stat.digMoved or 0) + 1 end
			end
		end
		sq.digSpot[flagName] = { lane = sq.lane[lkey], d = d }
		return d, "dig"
	end
	local attack = task == "attack" or task == "attack2" or task == "grab"
	if attack or (task == "gather" and S.wave and S.wave.stagePt) then
		local from = ApproachFrom(p)
		local dx, dy = p[1] - from[1], p[2] - from[2]
		local len = math.max(1, math.sqrt(dx * dx + dy * dy))
		local ux, uy = dx / len, dy / len           -- toward the flag
		local px, py = -uy, ux                      -- along the line
		local slot, row = LaneOf(sq, flagName)
		local phase = (task == "gather") and "gather" or LinePhase(flagName)
		-- infantry split over three approaches (straight on and both flanks) so the flag is hit from several sides
		if C.AttackSpread and sq.uid and sq.human and phase ~= "gather" then
			local g = (sq.uid % 3) - 1
			if g ~= 0 then
				local a = g * C.AttackSpread
				local c, s = math.cos(a), math.sin(a)
				ux, uy = ux * c - uy * s, ux * s + uy * c
				px, py = -uy, ux
			end
		end
		local back, side
		if phase == "assault" then
			back = rad * 0.25 + row * 50
			side = math.max(-rad * 0.8, math.min(rad * 0.8, slot * C.LineSpacing * 0.8))
		else
			-- gunners support the attack from a firing position on our side of the flag when the map has one
			local fpd = sq.ranged and phase == "line" and FirePosFor(sq, flagName)
			if fpd then return fpd, phase end
			back = (phase == "gather") and C.StageBack or (rad + C.LineGap)
			back = math.min(back, len * 0.6) + row * 60
			if sq.ranged then back = back + (C.MGLineBack or 0) end     -- gunners fire from behind the riflemen
			side = slot * C.LineSpacing
		end
		return { p[1] - ux * back + px * side, p[2] - uy * back + py * side }, phase
	end
	if task == "hold" and S.screenFor[flagName] then
		cx, cy = S.screenFor[flagName][1], S.screenFor[flagName][2]; rad = math.max(rad, 35)
	elseif task == "garrison" then
		rad = math.min(rad * 0.25, 20)
	elseif task == "gather" and S.wave and S.wave.stagePt then
		cx, cy = S.wave.stagePt[1], S.wave.stagePt[2]; rad = 45
	else
		rad = rad * 0.8
	end
	return { cx + math.cos(sq.ang) * rad * sq.rf, cy + math.sin(sq.ang) * rad * sq.rf }, task
end

local function OwnerOf(occ)
	if occ == nil then return "none" end
	if occ == Api.Instance.team then return "us" end
	if occ == Api.Instance.enemyTeam then return "them" end
	return "none"
end

------------------------------------------------------------------ map knowledge
local function MapFromLog()
	if not S.logDir then return nil end
	local f = io.open(S.logDir .. "game.log", "r")
	if not f then return nil end
	local txt = f:read("*a"); f:close()
	if not txt then return nil end
	local last
	for m in string.gmatch(txt, "Loading map '([^']+)'") do last = m end
	if not last then for m in string.gmatch(txt, "map/multi/([%w_%-%.]+)") do last = m end end
	if last then last = string.lower(string.match(last, "([^/\\]+)$") or last) end
	return last
end

local function DetectMap()
	local names, n = {}, 0
	for _, f in pairs(Api.Scene.Flags) do names[string.lower(f.name)] = true; n = n + 1 end
	if n == 0 then return false end
	local logName = nil
	pcall(function() logName = MapFromLog() end)
	local matches, byLog = {}, nil
	for mname, variants in pairs(BotMaps) do
		for _, v in ipairs(variants) do
			local ok, m = true, 0
			for k in pairs(v.f) do m = m + 1; if not names[k] then ok = false; break end end
			if ok and m == n then
				table.insert(matches, { name = mname, v = v })
				if logName and mname == logName then byLog = { name = mname, v = v } end
			end
		end
	end
	local pick, how = nil, nil
	if byLog then pick, how = byLog, "game log" elseif #matches == 1 then pick, how = matches[1], "flag names" end
	if pick then
		S.geo = { f = pick.v.f, a = pick.v.a, b = pick.v.b }
		S.geo.scale = math.max(500, Dist(S.geo.a, S.geo.b))
		S.mapName = pick.name
		S.mapInfo = pick.name .. " (" .. pick.v.mode .. ", found by " .. how .. ")"
	else
		S.mapInfo = "unknown map (log says '" .. tostring(logName) .. "', " .. #matches .. " maps share these flag names) - using map-free tactics"
	end
	Log("map: " .. S.mapInfo)
	return true
end

local function GuessSide()
	local tm, et = Api.Instance.team, Api.Instance.enemyTeam
	Log("team value=" .. tostring(tm) .. " (" .. type(tm) .. ") enemy=" .. tostring(et))
	if type(tm) == "string" then
		local l = string.lower(tm)
		if l == "a" or l == "b" then S.sideFixed = true; return l end
	end
	if type(tm) == "number" and type(et) == "number" then if tm < et then return "a" else return "b" end end
	return "a"
end

-- the enemy grabs flags near its own base first; if its first captures are nearer the base we think is ours, we guessed wrong
local function CheckSide(flagName)
	if S.sideFixed or not S.geo or S.t > 420 then return end
	local p = FlagPos(flagName); if not p then return end
	table.insert(S.enemyCaps, (Dist(p, BasePos()) - Dist(p, EnemyBasePos())) / S.geo.scale)
	if #S.enemyCaps >= 2 then
		local sum = 0; for _, v in ipairs(S.enemyCaps) do sum = sum + v end
		if sum / #S.enemyCaps < -0.1 then S.side = Other(S.side); Log("side corrected to " .. S.side .. " (enemy captures were near our assumed base)") end
		S.sideFixed = true
	end
end

-- real flag positions from the map points; our base = where our first units appeared, the enemy's = mirrored through the flags
local IntelNear, IntelVeg, IntelBases   -- map intel helpers, defined below
local function GeoFromPoints()
	if not R or (S.geo and S.geo.fromDll) or not S.home then return end
	local keys = {}
	for _, st in pairs(S.flags) do keys[st.key] = true end
	local ok, pts = pcall(R.Points)
	if not ok or type(pts) ~= "table" then Log("Points failed: " .. tostring(pts)); return end
	local f, radius, n, cx, cy = {}, {}, 0, 0, 0
	local dump = {}
	for _, p in ipairs(pts) do
		local key = string.lower(p.name or "")
		table.insert(dump, string.format("%s(%s) %.0f,%.0f r%.0f", tostring(p.name), p.flag and "flag" or "-", p.x, p.y, p.radius or 0))
		if keys[key] and not f[key] then f[key] = { p.x, p.y, p.z or 0 }; radius[key] = p.radius; n = n + 1; cx = cx + p.x; cy = cy + p.y end
	end
	Log("map points: " .. table.concat(dump, "; "))
	S.mapPts = {}
	for _, p in ipairs(pts) do table.insert(S.mapPts, { p.x, p.y, string.lower(p.name or "") }) end
	if n == 0 then Log("no map point matches a flag name - keeping the old map data"); return end
	cx, cy = cx / n, cy / n
	if not S.side then S.side = GuessSide() end
	local home = S.home
	local enemy = { 2 * cx - home[1], 2 * cy - home[2] }
	S.geo = { f = f, radius = radius, fromDll = true }
	S.geo[S.side] = home; S.geo[Other(S.side)] = enemy
	S.geo.scale = math.max(500, Dist(home, enemy))
	S.sideFixed = true; S.mapTried = 99
	S.mapInfo = string.format("from the map itself: %d flags, our base %.0f,%.0f, enemy base about %.0f,%.0f", n, home[1], home[2], enemy[1], enemy[2])
	Log("map: " .. S.mapInfo)
	S.intelBasesSet = nil; IntelBases()
end

------------------------------------------------------------------ map intel
-- One file per map in maps/, baked offline from the map pak (scratchpad/mapintel): the real playable bounds, every
-- mode's flags and spawn points, and the map's objects sorted into houses, buildings, walls, fences, hedges,
-- fortifications, rocks, bridges, water (rects {x, y, width, length, turn, height}) plus a 10 m bush/tree grid.
local IntelRects = { "house", "building", "wall", "fence", "hedge", "fort", "rock", "bridge", "water" }

-- how many objects of the given classes lie within r of p
IntelNear = function(p, r, classes)
	local d = S.intel; if not (d and p) then return 0 end
	local n, r2 = 0, r * r
	for _, c in ipairs(classes) do
		for _, o in ipairs(d[c] or {}) do
			local dx, dy = o[1] - p[1], o[2] - p[2]
			if dx * dx + dy * dy <= r2 then n = n + 1 end
		end
	end
	return n
end

-- bush + tree cells (10 m) with something in them within r of p
IntelVeg = function(p, r)
	local g = S.intel and S.intel.grid; if not (g and p) then return 0 end
	local n, c = 0, g.cell
	local x1, x2 = math.max(0, math.floor((p[1] - r - g.x0) / c)), math.min(g.nx - 1, math.floor((p[1] + r - g.x0) / c))
	local y1, y2 = math.max(0, math.floor((p[2] - r - g.y0) / c)), math.min(g.ny - 1, math.floor((p[2] + r - g.y0) / c))
	for iy = y1, y2 do
		for ix = x1, x2 do
			local i = iy * g.nx + ix + 1
			if string.byte(g.bush, i) ~= 48 or string.byte(g.tree, i) ~= 48 then
				local dx, dy = g.x0 + (ix + 0.5) * c - p[1], g.y0 + (iy + 0.5) * c - p[2]
				if dx * dx + dy * dy <= r * r then n = n + 1 end
			end
		end
	end
	return n
end

-- terrain grid from map.net, same 10 m cells: g = ground letter per cell (. ground, r road, s shallow water, w deep
-- water, x no-go, b bridge), h = mean height per cell (character index in 0-9A-Za-z, times hstep, plus hmin, game units)
local function IntelCell(p)
	local g = S.intel and S.intel.grid; if not (g and g.g and p) then return nil end
	local ix, iy = math.floor((p[1] - g.x0) / g.cell), math.floor((p[2] - g.y0) / g.cell)
	if ix < 0 or iy < 0 or ix >= g.nx or iy >= g.ny then return nil end
	return iy * g.nx + ix + 1, ix, iy
end
local function AlphaVal(b) if b <= 57 then return b - 48 elseif b <= 90 then return b - 55 else return b - 61 end end
local function IntelHeight(p)
	local i = IntelCell(p); local g = i and S.intel.grid
	if not (g and g.h) then return nil end
	return g.hmin + AlphaVal(string.byte(g.h, i)) * g.hstep
end
local NoGo = { w = true, x = true }
IntelDry = function(d)
	local i, ix, iy = IntelCell(d)
	if not i then return d end
	local g = S.intel.grid
	local here = string.sub(g.g, i, i)
	if not NoGo[here] then return d end
	local best, bd = nil, math.huge
	for ry = -3, 3 do
		for rx = -3, 3 do
			local jx, jy = ix + rx, iy + ry
			if jx >= 0 and jy >= 0 and jx < g.nx and jy < g.ny then
				local j = jy * g.nx + jx + 1
				if not NoGo[string.sub(g.g, j, j)] then
					local q = { g.x0 + (jx + 0.5) * g.cell, g.y0 + (jy + 0.5) * g.cell }
					local dd = Dist(q, d)
					if dd < bd then best, bd = q, dd end
				end
			end
		end
	end
	if not best then return d end
	S.stat.dry = (S.stat.dry or 0) + 1
	if S.stat.dry <= 3 then Log(string.format("move target %.0f,%.0f is %s - moved %d m to passable ground", d[1], d[2], here == "w" and "deep water" or "no-go ground", math.floor(bd / 20))) end
	return best
end

-- value analysis baked per mode (phase 3): flag value / defensibility, firing positions per team, routes, choke points
local function IntelVal(flagName)
	local v = S.intel and S.intel.val
	return v and v.lflags and v.lflags[string.lower(flagName or "")]
end
IntelFlagValue = function(flagName) local f = IntelVal(flagName); return f and f.v end
-- spots human players held with MGs / snipers / AT rifles in replays (phase 4) come first, then the computed ones
IntelFirePos = function(flagName)
	local t = S.intelTeam
	if not t then return nil end
	S.fpCache = S.fpCache or {}
	local key = string.lower(flagName or "")
	if S.fpCache[key] ~= nil then return S.fpCache[key] or nil end
	local out = {}
	local function add(q, src)
		for _, o in ipairs(out) do if math.abs(o[1] - q[1]) < 300 and math.abs(o[2] - q[2]) < 300 then return end end
		if #out < 6 then table.insert(out, { q[1], q[2], src = src }) end
	end
	local L = S.learn and S.learn[t] and S.learn[t].spots
	if L then
		for k, list in pairs(L) do
			if string.lower(k) == key then
				local r = {}
				for _, q in ipairs(list) do if q[4] == "ranged" then table.insert(r, q) end end
				table.sort(r, function(a, b) return a[3] > b[3] end)
				for _, q in ipairs(r) do add(q, "human") end
			end
		end
	end
	local f = IntelVal(flagName)
	for _, q in ipairs(f and f.fp and f.fp[t] or {}) do add(q, "map") end
	S.fpCache[key] = (#out > 0) and out or false
	return S.fpCache[key] or nil
end

-- flags human players took first on this map (phase 4), for our team: rank 1 = first; nil when not in the opening
local function LearnedOpenRank(flagName)
	local o = S.learn and S.intelTeam and S.learn[S.intelTeam] and S.learn[S.intelTeam].open
	if not o then return nil end
	for i, n in ipairs(o) do if string.lower(n) == string.lower(flagName or "") then return i, #o end end
	return nil
end

-- the team spawns from the map file: the one nearest where our men appeared is ours, the other is the enemy base
IntelBases = function()
	local d = S.intel
	if not (d and d.bases and S.geo and S.home and S.side) or S.intelBasesSet then return end
	local a, b = d.bases.a, d.bases.b
	if not (a and b) then return end
	local mine, theirs, letter = a, b, "a"
	if Dist(b, S.home) < Dist(a, S.home) then mine, theirs, letter = b, a, "b" end
	if Dist(mine, S.home) > 0.35 * Dist(a, b) then Log("map intel: our men did not appear near either team spawn - keeping the guessed enemy base"); return end
	S.intelTeam = letter
	S.geo[Other(S.side)] = { theirs[1], theirs[2] }
	S.geo.scale = math.max(500, Dist(S.home, theirs))
	S.intelBasesSet = true
	Log(string.format("map intel: enemy base set to its spawn at %.0f,%.0f (%d m from ours)", theirs[1], theirs[2], math.floor(Dist(S.home, theirs) / 20)))
end

-- which map this is, from where its flags stand: every map's flag spots are in maps/_index
local function IntelFromIndex()
	if not (S.mapPts and #S.mapPts > 0) then return nil end
	if S.intelIndex == nil then
		MapIntelIndex = nil
		local ok, ret = pcall(require, "/script/multiplayer/maps/_index")
		S.intelIndex = (ok and type(ret) == "table" and ret) or MapIntelIndex or false
		MapIntelIndex = nil
		if not S.intelIndex then Log("map intel: no map index (" .. tostring(ret) .. ")") end
	end
	if not S.intelIndex then return nil end
	local keys, live = {}, {}
	for _, st in pairs(S.flags) do keys[st.key] = true end
	for _, q in ipairs(S.mapPts) do if q[3] and keys[q[3]] then table.insert(live, q) end end
	if #live == 0 then return nil end
	local best, bestExtra, ties = nil, math.huge, 0
	for mname, fl in pairs(S.intelIndex) do
		local hit = 0
		for _, q in ipairs(live) do
			for _, e in ipairs(fl) do
				if e[1] == q[3] and math.abs(e[2] - q[1]) < 150 and math.abs(e[3] - q[2]) < 150 then hit = hit + 1; break end
			end
		end
		if hit == #live then
			local extra = #fl - hit
			if extra < bestExtra then best, bestExtra, ties = mname, extra, 1 elseif extra == bestExtra then ties = ties + 1 end
		end
	end
	if best then Log(string.format("map intel: flags stand exactly where they do on %s%s", best, ties > 1 and (" (" .. ties .. " maps share this layout)") or "")) end
	return best
end

local function LoadIntel()
	if S.intel ~= nil or S.t < 3 then return end
	S.intelTry = (S.intelTry or 0) + 1
	local name = S.mapName
	if not name then pcall(function() name = MapFromLog() end) end
	if not name then name = IntelFromIndex() end
	if not name then if S.intelTry >= 20 then S.intel = false; Log("map intel: map name unknown - none loaded") end; return end
	MapIntelData = nil
	local ok, ret = pcall(require, "/script/multiplayer/maps/" .. name)
	local d = (type(ret) == "table" and ret) or MapIntelData
	MapIntelData = nil
	if not ok or type(d) ~= "table" or not d.world then
		S.intel = false
		Log("map intel: none for '" .. name .. "'" .. (ok and "" or (" (" .. tostring(ret) .. ")")))
		return
	end
	-- the mode whose flag names match the flags in play
	local names = {}
	for _, f in pairs(Api.Scene.Flags) do names[string.lower(f.name)] = true end
	local best, bs = nil, -math.huge
	for mn, md in pairs(d.modes or {}) do
		local s = 0
		for k, f in pairs(md.flags) do if names[string.lower(k)] then s = s + 1 elseif f[3] > 0 then s = s - 1 end end
		if s > bs then best, bs = mn, s end
	end
	d.mode = best; d.md = best and d.modes[best]
	d.val = best and d.value and d.value[best]
	if d.val and d.val.flags then
		d.val.lflags = {}
		for k, f in pairs(d.val.flags) do d.val.lflags[string.lower(k)] = f end
	end
	-- team spawn centres (zero-radius map points named a1, b2 ... are spawn markers on some maps)
	if d.md then
		local acc = {}
		local function add(t, x, y) local q = acc[t] or { 0, 0, 0 }; q[1], q[2], q[3] = q[1] + x, q[2] + y, q[3] + 1; acc[t] = q end
		for _, sp in ipairs(d.md.spawns or {}) do add(sp.t, sp[1], sp[2]) end
		for k, f in pairs(d.md.flags) do local t = string.match(string.lower(k), "^([ab])%d+$"); if t and f[3] == 0 then add(t, f[1], f[2]) end end
		d.bases = {}
		for t, q in pairs(acc) do d.bases[t] = { q[1] / q[3], q[2] / q[3] } end
	end
	S.intel = d
	-- what human players did on this map in replays (phase 4), for the same mode
	MapLearned = nil
	local okL, retL = pcall(require, "/script/multiplayer/maps/_learned")
	local all = (okL and type(retL) == "table" and retL) or MapLearned
	MapLearned = nil
	local L = type(all) == "table" and all[name]
	if L and L.mode == best then
		S.learn = L; S.fpCache = nil
		local function desc(t) local x = L[t]; if not x then return t .. " none" end; local n = 0; for _, l in pairs(x.spots or {}) do n = n + #l end; return string.format("%s: opening %s, %d spots", t, table.concat(x.open or {}, ">"), n) end
		Log(string.format("map intel learned from %d replay(s) of human players: %s; %s", L.games or 0, desc("a"), desc("b")))
	else
		Log("map intel: no replays of human players on this map" .. ((L and " in this mode") or ""))
	end
	local cnt = {}
	for _, c in ipairs(IntelRects) do table.insert(cnt, #(d[c] or {}) .. " " .. c) end
	local pb = d.pather or d.world
	Log(string.format("map intel: %s, mode %s, playable %d x %d m; %s", name, tostring(best), math.floor((pb[3] - pb[1]) / 20), math.floor((pb[4] - pb[2]) / 20), table.concat(cnt, ", ")))
	-- what each flag offers: buildings, walls/fences/hedges, fortifications and vegetation within its radius + 20 m
	local rows = {}
	for k, f in pairs(d.md and d.md.flags or {}) do
		if f[3] > 0 then
			local p, r = { f[1], f[2] }, math.max(f[3] + 400, 700)
			local hh = IntelHeight(p)
			local elev = hh and string.format(" elev %d m", math.floor((hh - d.grid.hmin) / 20)) or ""
			local fv = d.val and d.val.lflags and d.val.lflags[string.lower(k)]
			if fv then elev = elev .. string.format(" value %d (contested %.1f, hold %.1f, firing spots a%d/b%d)", fv.v, fv.mid, fv.hold, #(fv.fp and fv.fp.a or {}), #(fv.fp and fv.fp.b or {})) end
			table.insert(rows, string.format("%s bldg %d wall %d fort %d veg %d%s", k, IntelNear(p, r, { "house", "building" }), IntelNear(p, r, { "wall", "fence", "hedge" }), IntelNear(p, r, { "fort" }), IntelVeg(p, r), elev))
		end
	end
	table.sort(rows)
	Log("map intel per flag: " .. table.concat(rows, "; "))
	if d.val then Log(string.format("map intel value: %d strong points, %d choke points on drive routes", #(d.strong or {}), #(d.val.choke or {}))) end
	IntelBases()
end

------------------------------------------------------------------ flags
local function UpdateFlags()
	for _, f in pairs(Api.Scene.Flags) do
		local name = f.name
		local own = OwnerOf(f.occupant)
		local st = S.flags[name]
		if not st then
			st = { name = name, key = string.lower(name), owner = own, changed = S.t, heat = 0, losses = 0, lostAt = -9999, failUntil = -1 }
			S.flags[name] = st
			S.tie[name] = math.random() * 0.5
		elseif st.owner ~= own then
			if st.owner == "us" then st.lostAt = S.t; st.heat = st.heat + 1 end
			if own == "them" then st.heat = st.heat + 0.5; CheckSide(name) end
			Log("flag " .. name .. ": " .. st.owner .. " -> " .. own)
			st.owner = own; st.changed = S.t
		end
	end
end

------------------------------------------------------------------ squads
local function RegisterSquad(id, info)
	if S.squads[id] then return end
	info = info or { r = "inf", n = "?", c = 150 }
	S.squads[id] = { id = id, role = info.r, unit = info.n, info = info, born = S.t, task = nil, flag = nil, orderT = -9999 }
end

-- with the DLL every soldier and vehicle on the field is its own "group" (crews inside vehicles are left out)
local function UpdateUnits()
	local ok, list = pcall(R.Units)
	if not ok or type(list) ~= "table" then Log("Units failed: " .. tostring(list)); return end
	local alive = {}
	local sx, sy, sn = 0, 0, 0
	for _, u in ipairs(list) do
		if not u.boarded then
			local id = "u" .. u.id
			alive[id] = true
			local sq = S.squads[id]
			if not sq then
				local info = S.unitInfo[u.id] or { r = u.human and "inf" or "light", n = "?", c = 50 }
				-- crew who leave a vehicle fight as infantry; an emplacement's crew stay with their gun
				if u.human and IsVehicleRole(info.r) then info = { r = "inf", n = info.n .. " crew", c = 30 } end
				RegisterSquad(id, info); sq = S.squads[id]; sq.uid = u.id; sq.human = u.human
			end
			sq.pos = { u.x, u.y }; sq.z = u.z; sq.hp = u.hp
			if u.mg ~= nil then sq.mg = u.mg end
			if u.atr ~= nil then sq.atr = u.atr end
			if u.snp ~= nil then sq.snp = u.snp end
			if u.rl ~= nil then sq.rl = u.rl end
			if u.fx and u.fy then
				-- hull heading from the v11 DLL. Which way the model's axis points is learned from how vehicles drive:
				-- each clear move votes for the 90-degree offset between the axis and the direction of travel
				if sq.lastP and not u.human then
					local mx, my = u.x - sq.lastP[1], u.y - sq.lastP[2]
					if mx * mx + my * my > 80 * 80 and (u.fx ~= 0 or u.fy ~= 0) then
						local off = (math.atan2(my, mx) - math.atan2(u.fy, u.fx)) % (2 * math.pi)
						local b = math.floor(off / (math.pi / 2) + 0.5) % 4 + 1
						S.faceVotes[b] = S.faceVotes[b] + 1
						local best = 1
						for i = 2, 4 do if S.faceVotes[i] > S.faceVotes[best] then best = i end end
						local cal = (best - 1) * math.pi / 2
						if (cal ~= S.faceCal or not S.faceLogged) and S.faceVotes[best] >= 5 then
							S.faceCal = cal; S.faceLogged = true
							Log(string.format("vehicle heading offset learned: %d degrees (votes %d/%d/%d/%d)", (best - 1) * 90, S.faceVotes[1], S.faceVotes[2], S.faceVotes[3], S.faceVotes[4]))
						end
					end
				end
				sq.fx, sq.fy = u.fx, u.fy
			end
			sq.lastP = { u.x, u.y }
			-- standing still since when (sandbag builders put up a wall wherever they stop)
			if not sq.stillPos or Dist(sq.stillPos, sq.lastP) > 60 then sq.stillPos = { u.x, u.y }; sq.stillSince = S.t end
			-- long-range shooters (machine gun, AT rifle, sniper rifle) keep their distance from the enemy
			sq.ranged = u.human and (sq.mg or sq.atr or sq.snp or sq.role == "sniper") and true or false
			sq.bags = u.bags or 0; sq.gren = u.gren or 0; sq.atgren = u.atgren or 0; sq.smoke = u.smoke or 0; sq.z = u.z or 0
			if u.human then sx, sy, sn = sx + u.x, sy + u.y, sn + 1 end
		end
	end
	if not S.home and sn > 0 then
		S.home = { sx / sn, sy / sn }
		local ex = list[1]
		Log(string.format("first units seen: %d, home %.0f,%.0f, sample unit id %s hp %s human %s squad %s", #list, S.home[1], S.home[2], tostring(ex.id), tostring(ex.hp), tostring(ex.human), tostring(ex.squad)))
	end
	for id, sq in pairs(S.squads) do
		if not alive[id] and sq.human and sq.pos then
			-- a soldier died: if an enemy vehicle was close, it probably killed him (a jeep that keeps killing gets hunted)
			local best, bd = nil, C.PestRange or 2400
			for _, en in ipairs(S.allEnemies or {}) do
				if not en.human then local d = Dist(sq.pos, { en.x, en.y }); if d < bd then best, bd = en, d end end
			end
			if best then
				S.vehKills[best.id] = (S.vehKills[best.id] or 0) + 1
				if S.vehKills[best.id] == (C.PestKills or 3) then Log(string.format("enemy vehicle %s has killed %d of our men: hunting it and buying anti-tank", tostring(best.id), S.vehKills[best.id])) end
			end
		end
		if not alive[id] then
			local f = sq.flag and S.flags[sq.flag]
			if f and f.owner ~= "us" then f.losses = f.losses + Strength(sq) end
			S.squads[id] = nil; S.lost = S.lost + 1
		end
	end
end

-- new squads: remember which purchase each soldier came from, then disband the squad
local function ProcessPending()
	for id, p in pairs(S.pending) do
		local ok, m = pcall(R.SquadMembers, id)
		if ok and type(m) == "table" and #m > 0 then
			for _, uid in ipairs(m) do S.unitInfo[uid] = p.info end
			if p.info and p.info.n and p.info.n ~= "?" then S.men[p.info.n] = math.max(S.men[p.info.n] or 0, #m) end
			local vehicle = p.info and IsCrewed(p.info.r)
			if p.info and Gun[p.info.r] then
				S.empSquads[id] = { n = p.info.n, r = p.info.r, uids = m, t = S.t }   -- moved by PlaceEmplacements with the game's squad order
			end
			if C.DisbandSquads and not vehicle then
				local dok, res = pcall(R.Disband, id)
				if dok and res then S.stat.disband = S.stat.disband + 1 end
				if S.stat.disband <= 2 then Log(string.format("disband squad %s (%d men, %s): %s", tostring(id), #m, p.info and p.info.n or "?", tostring(dok and res or res))) end
			end
			S.pending[id] = nil
		elseif S.t - p.t > 15 then
			S.pending[id] = nil
		end
	end
end

------------------------------------------------------------------ combat (DLL v5)
local AtRoles = { atinf = true, atgun = true }
-- stand-off distances for long-range shooters: falls back inside min, moves up only beyond want, fights out to max
local function KeepRange(sq)
	if not (C.MGKeep and sq.ranged) then return nil end
	if sq.snp or sq.role == "sniper" then return C.SniperMin, C.SniperWant, C.SniperMax end
	if sq.atr and not sq.mg then return C.ATRMin, C.ATRWant, C.ATRMax end
	return C.MGMin, C.MGWant, C.MGMax
end
local TankRoles = { tank = true, td = true, heavy = true }
local AttackTasks = { attack = true, attack2 = true, grab = true }

local function NearestOf(p, list)
	local best, bd = nil, math.huge
	for _, e in ipairs(list) do
		local dx, dy = e.x - p[1], e.y - p[2]
		local d = dx * dx + dy * dy
		if d < bd then best, bd = e, d end
	end
	return best, math.sqrt(bd)
end

local function CoverKey(c) return math.floor(c.x / 30) .. "_" .. math.floor(c.y / 30) end

-- the best free cover near `around` for a fight toward `enemy` (sandbags, walls, craters...), nil when there is none.
-- keepIn: {point, radius} the cover must lie inside (flag holders stay in the flag zone)
local function PickCover(sq, around, enemy, budget, keepIn, radius)
	if budget.n <= 0 or not R.Covers then return nil end
	budget.n = budget.n - 1
	local ok, list = pcall(R.Covers, sq.uid, around[1], around[2], radius or C.CoverRadius)
	if not ok or type(list) ~= "table" then return nil end
	local de = enemy and Dist(around, enemy)
	-- how many of our soldiers already use each sandbag
	local users, mgUsers = {}, {}
	for _, o in pairs(S.squads) do
		if o.coverEnt and o ~= sq then
			users[o.coverEnt] = (users[o.coverEnt] or 0) + 1
			if o.mg then mgUsers[o.coverEnt] = (mgUsers[o.coverEnt] or 0) + 1 end
		end
	end
	local best, bs = nil, math.huge
	for _, c in ipairs(list) do
		local key = CoverKey(c)
		local res = S.coverRes[key]
		local cp = { c.x, c.y }
		local wrongSide = false
		if enemy and c.wall and c.x1 then
			-- the soldier must be behind the wall: he and the enemy on opposite sides of the wall's line
			local wx, wy = c.x2 - c.x1, c.y2 - c.y1
			local sp = wx * (c.y - c.y1) - wy * (c.x - c.x1)
			local se = wx * (enemy[2] - c.y1) - wy * (enemy[1] - c.x1)
			wrongSide = sp * se >= 0
		end
		if not wrongSide and (not res or res.t < S.t or res.uid == sq.uid) and (not keepIn or Dist(cp, keepIn[1]) < keepIn[2]) then
			local s = Dist(cp, sq.pos) * 0.5 + Dist(cp, around)
			c.bag = c.name and (string.find(string.lower(c.name), "sandbag", 1, true) or string.find(string.lower(c.name), "bag", 1, true)) and true or false
			if c.bag then
				-- sandbags first, until a few men are already on that one
				if sq.mg then
					-- machine gunners want sandbags most of all: any sandbag no other gun is using (riflemen make room)
					if (mgUsers[c.ent] or 0) == 0 then s = s - C.SandbagBonus * (C.MGSandbagMult or 2.5) else s = s + 100 end
				elseif (users[c.ent] or 0) < C.SandbagCrowd then s = s - C.SandbagBonus else s = s + 100 end
			end
			if enemy then
				local dce = Dist(cp, enemy)
				if dce > de + 150 then s = s + 400 end      -- would mean falling back
				if dce < 300 then s = s + 600 end           -- right in their faces
				if c.wall and c.x1 then
					local ex, ey = enemy[1] - c.x, enemy[2] - c.y
					local el = math.max(1, math.sqrt(ex * ex + ey * ey))
					-- a wall running toward the enemy shields nothing
					local wx, wy = c.x2 - c.x1, c.y2 - c.y1
					local wl = math.max(1, math.sqrt(wx * wx + wy * wy))
					if math.abs((wx * ex + wy * ey) / (wl * el)) > 0.7 then s = s + 200 end
					-- a standing-height wall: he can only fire if he can lean out at an end of it
					if (c.kind or 0) >= 3 then
						local de1 = Dist(cp, { c.x1, c.y1 })
						local de2 = Dist(cp, { c.x2, c.y2 })
						if math.min(de1, de2) > 40 then s = s + 350 end
					end
				else
					s = s + 120                                -- no wall: a crater, a bush, a fold in the ground
				end
			end
			-- low cover (sandbags, low walls, craters): he fires over it lying or crouched
			if c.kind == 1 or c.kind == 2 then s = s - 60 end
			if s < bs then best, bs = c, s end
		end
	end
	if best then
		S.coverRes[CoverKey(best)] = { uid = sq.uid, t = S.t + 60 }
		sq.coverEnt = best.bag and best.ent or nil
		if best.bag then S.stat.bagCover = (S.stat.bagCover or 0) + 1 end
	end
	return best
end

-- the flag zone a holder must not leave
local function KeepZone(sq)
	if (sq.task == "garrison" or sq.task == "hold") and sq.pflag and not S.screenFor[sq.pflag] then
		local p = FlagPos(sq.pflag)
		local rad = (S.geo.radius and S.geo.radius[string.lower(sq.pflag)]) or 200
		if p then return { p, rad * 0.9 } end
	end
	return nil
end

-- get down where he is: the best cover close by, else flat on the ground
local function GoDown(sq, f, budget)
	local c = PickCover(sq, sq.pos, f.enemy, budget, KeepZone(sq))
	if c and Dist({ c.x, c.y }, sq.pos) > 20 then
		local ok, r = pcall(R.Cover, sq.uid, c.x, c.y, Dist({ c.x, c.y }, sq.pos) > 100)
		if ok and r then f.mode = "cover"; f.coverPt = { c.x, c.y }; f.proneAt = S.t + (C.ProneAfter or 2); sq.prone = nil; S.stat.cover = S.stat.cover + 1; return end
	end
	-- no cover: gunners lie down; riflemen keep the stance the game gives them under fire
	-- machine gunners and AT riflemen go flat straight away (best accuracy); rocket men crouch (they can't fire lying)
	if sq.rl then SetPose(sq, 2, true)
	elseif sq.ranged or C.PoseRiflemen then SetPose(sq, 1, sq.mg or sq.atr) end
	f.mode = "prone"; f.coverPt = nil; f.proneAt = S.t + (C.ProneAfter or 2); S.stat.prone = S.stat.prone + 1
end

-- where a soldier at his spot should face: the flag he attacks, else the nearest enemy (director), else their base
local function SpotThreat(sq)
	if (sq.ophase == "line" or sq.ophase == "gather") and sq.pflag then
		local p = FlagPos(sq.pflag)
		if p then return p end
	end
	local at = sq.dest or sq.pos
	local e2, d2 = NearestOf(at, S.allEnemies or {})
	if e2 and d2 < 3000 then return { e2.x, e2.y } end
	return EnemyBasePos()
end

-- sandbag walls we put up (so two men don't build on the same spot)
local function WallNear(p, r)
	for _, w in ipairs(S.walls) do
		if S.t - w.t < (C.WallMemory or 600) and Dist(p, w) < r then return true end
	end
	return false
end

-- one sandbag wall just in front of `at`, across the direction to `ep`
local function BuildWall(sq, at, ep, now)
	local dx, dy = ep[1] - at[1], ep[2] - at[2]
	local l = math.max(1, math.sqrt(dx * dx + dy * dy))
	local ux, uy = dx / l, dy / l
	local cx, cy = at[1] + ux * 25, at[2] + uy * 25
	local h = C.BuildLen / 2
	if sq.prone then SetPose(sq, 0, true) end
	local ok, r = pcall(R.Build, sq.uid, cx + uy * h, cy - ux * h, cx - uy * h, cy + ux * h)
	if ok and r and r ~= 0 then
		table.insert(S.walls, { cx, cy, t = now })
		if #S.walls > 400 then table.remove(S.walls, 1) end
		S.stat.built = S.stat.built + 1; sq.coveredAt = nil
		return true
	end
	S.stat.buildFail = (S.stat.buildFail or 0) + 1
	if S.stat.buildFail <= 3 then Log("sandbag build refused: " .. tostring(r)) end
	return false
end

-- every soldier: seen an enemy close or taken a hit -> get into cover or prone and fight; attackers that are winning
-- their fight move up in short bounds (half the line moves while the other half fires); no contact for a while -> plan
local function Combat()
	if not S.geo then return end
	local budget = { n = C.CoverCalls }
	local now = S.t
	local humans = {}
	for _, sq in pairs(S.squads) do if sq.uid and sq.human and sq.pos and not Gun[sq.role] then table.insert(humans, sq) end end
	for _, sq in ipairs(humans) do
		local en, de = NearestOf(sq.pos, S.enemies)
		local hurt = sq.lastHp and sq.hp and sq.hp >= 0 and sq.hp < sq.lastHp - 0.001
		sq.lastHp = sq.hp
		local kMin, kWant, kMax = KeepRange(sq)
		local engageAt = kMax or C.EngageDist
		local contact = (en and de < engageAt) or hurt
		-- a long-range shooter stays in his fight (at range) while any known enemy is within his reach, so he doesn't walk back in
		if kMax and not contact and AnyEnemyNear(sq.pos, kMax) then contact = true end
		if contact then sq.lastContact = now end
		local f = sq.fight
		local busy = (sq.atkUntil or 0) > now     -- an AT man going for a tank is left alone		-- sandbag builders keep at it under fire: while building, and on the way to the spot they build at
		local destKey = sq.dest and (math.floor(sq.dest[1] / 60) .. "_" .. math.floor(sq.dest[2] / 60))
		local arrived = sq.dest and Dist(sq.pos, sq.dest) < (C.SpotArrive or 80)
		local spotTask = sq.task == "hold" or sq.task == "garrison" or sq.task == "dig" or sq.ophase == "line" or sq.ophase == "gather"
		local wantBuild = C.BuildSandbags and R.Build and (sq.bags or 0) > 0 and destKey and (sq.builtFor ~= destKey or (sq.wallN or 1) < (C.WallsPerSpot or 1)) and spotTask
		local building = (sq.buildAt and now - sq.buildAt < C.BuildTime) or (wantBuild and sq.task == "dig" and not arrived and not f)
		-- all game long: a soldier with sandbags who has stopped somewhere (any task, even mid-attack) walls himself in,
		-- unless the enemy is close; machine gunners do it almost as soon as they stop
		local stillFor = sq.stillSince and (now - sq.stillSince) or 0
		local fortify = C.Fortify and R.Build and (sq.bags or 0) > 0 and not busy and not building and not wantBuild
			and now >= (sq.fortT or 0)
			and stillFor >= (sq.mg and (C.FortifyStillMG or 4) or (C.FortifyStill or 12))
			and not (en and de < (sq.mg and (C.FortifyEnemyMinMG or 900) or (C.FortifyEnemyMin or 1300)))
			and not WallNear(sq.pos, C.FortifyGap or 120)
		-- grenades: a visible enemy soldier within throwing range (or a vehicle within AT-grenade range, for a man who
		-- has one) gets a grenade - unless our own men are next to him. The soldier keeps his place; no charging.
		local gTarget = nil
		if C.Grenades and R.Throw and not sq.ranged and not busy and now >= (sq.grenT or 0) and not (sq.buildAt and now - sq.buildAt < C.BuildTime) then
			local gd = math.huge
			for _, e in ipairs(S.enemies) do
				local kind = e.human and 1 or 2
				local have = e.human and (sq.gren or 0) or (sq.atgren or 0)
				local range = e.human and C.GrenadeRange or C.AtGrenadeRange
				if have > 0 then
					local d = Dist({ e.x, e.y }, sq.pos)
					if d < range and d < gd then
						local friendly = false
						for _, o in ipairs(humans) do
							if o ~= sq and Dist(o.pos, { e.x, e.y }) < C.GrenadeSafe then friendly = true; break end
						end
						if not friendly then gTarget, gd = { e = e, kind = kind }, d end
					end
				end
			end
		end
		-- long-range shooter: too close to the enemy -> fall back to his range (cover there if any)
		local mgNear, mgD = nil, math.huge
		if kMin then
			-- AT riflemen only back away from enemy soldiers, not vehicles (they hovered at 90 m from the jeep)
			local src = S.allEnemies or S.enemies
			if sq.atr and not sq.mg then
				src = {}
				for _, e in ipairs(S.allEnemies or S.enemies) do if e.human then table.insert(src, e) end end
			end
			mgNear, mgD = NearestOf(sq.pos, src)
		end
		if building then
			-- keep building (or keep going to the spot he builds at); he takes cover behind it when the time is up
		elseif wantBuild and arrived and not busy then
			-- at his spot with sandbags: build a wall just in front of him, across the enemy's direction, even under fire
			local ep = SpotThreat(sq)
			local dx, dy = ep[1] - sq.dest[1], ep[2] - sq.dest[2]
			local l = math.max(1, math.sqrt(dx * dx + dy * dy))
			local ux, uy = dx / l, dy / l
			local wn = (sq.builtFor == destKey) and (sq.wallN or 1) or 0      -- walls already up at this spot
			local off = (wn == 0) and 0 or ((wn % 2 == 1) and 1 or -1) * math.ceil(wn / 2) * C.BuildLen   -- next wall beside the last
			local cx, cy = sq.pos[1] + ux * 25 + uy * off, sq.pos[2] + uy * 25 - ux * off
			local h = C.BuildLen / 2
			if sq.prone then SetPose(sq, 0, true) end
			local ok, r = pcall(R.Build, sq.uid, cx + uy * h, cy - ux * h, cx - uy * h, cy + ux * h)
			sq.wallN = wn + 1; sq.builtFor = destKey; sq.coveredAt = nil
			if not (ok and r and r ~= 0) then S.stat.buildFail = (S.stat.buildFail or 0) + 1; if S.stat.buildFail <= 3 then Log("sandbag build refused: " .. tostring(r)) end end
			if ok and r and r ~= 0 then
				sq.buildAt = now; S.stat.built = S.stat.built + 1
				table.insert(S.walls, { cx, cy, t = now })
				if f then sq.fight = nil end      -- he builds now; the fight resumes from behind the bags afterwards
			end
		elseif fortify then
			local ep = (f and f.enemy) or SpotThreat(sq)
			sq.fortT = now + (C.FortifyRetry or 20)
			if BuildWall(sq, sq.pos, ep, now) then
				sq.buildAt = now - C.BuildTime + (C.FortifyHold or 25)     -- left alone 25 s to finish (not the full BuildTime)
				S.stat.fortify = (S.stat.fortify or 0) + 1
				if sq.mg then S.stat.mgWall = (S.stat.mgWall or 0) + 1 end
				if f then sq.fight = nil end
			end
		elseif gTarget then
			-- throw, then (as after a bound) get back down in cover a few seconds later
			local e = gTarget.e
			local ok, r = pcall(R.Throw, sq.uid, gTarget.kind, e.id)
			sq.grenT = now + ((ok and r and r ~= 0) and C.GrenadeGap or 6)
			if ok and r and r ~= 0 then
				sq.prone = nil; sq.coveredAt = nil; sq.running = false; sq.lastContact = now
				f = f or { since = now, untilT = now }
				f.enemy = { e.x, e.y }; f.mode = "bound"; f.boundEnd = now + 5
				sq.fight = f
				S.stat.grenades = (S.stat.grenades or 0) + 1
			end
		elseif mgNear and mgD < kMin and now >= (sq.mgMoveT or 0) and not busy then
			local l = math.max(1, mgD)
			local ep = { mgNear.x, mgNear.y }
			local bp = { mgNear.x + (sq.pos[1] - mgNear.x) / l * kWant, mgNear.y + (sq.pos[2] - mgNear.y) / l * kWant }
			local c = PickCover(sq, bp, ep, budget)
			local moved = false
			if c and not sq.prone then local ok, r = pcall(R.Cover, sq.uid, c.x, c.y, true); moved = ok and r end
			if not moved then
				if sq.prone and SetPose(sq, 0, true) then table.insert(S.later, { t = now + 1, sq = sq, d = bp, force = true, run = true })
				else pcall(R.Move, sq.uid, bp[1], bp[2], true, 0) end
			end
			f = f or { since = now, untilT = now }
			f.enemy = ep; f.mode = "bound"; f.boundEnd = now + 8
			sq.fight = f; sq.lastContact = now; sq.mgMoveT = now + 10; sq.coveredAt = nil
			S.stat.mgBack = S.stat.mgBack + 1
		elseif contact and not f and not busy then
			S.stat.engaged = S.stat.engaged + 1
			f = { since = now, untilT = now + C.EngageHold, enemy = en and { en.x, en.y } or (sq.dest or EnemyBasePos()) }
			sq.fight = f; sq.running = false
			GoDown(sq, f, budget)
		elseif f and f.proneAt and now >= f.proneAt and f.mode ~= "bound" and not busy then
			-- still standing 2 s into the fight: down. In the open he lies flat; once at his cover he crouches behind it
			if f.coverPt and Dist(sq.pos, f.coverPt) > 50 and now - f.proneAt < 15 then
				f.proneAt = now + 2                       -- still running to the cover: look again shortly
			else
				f.proneAt = nil
				if f.coverPt or sq.rl then SetPose(sq, 2, true) else SetPose(sq, 1, true) end
				S.stat.downAfter = (S.stat.downAfter or 0) + 1
			end
		elseif f then
			if en and de < C.EngageDist * 1.5 then f.enemy = { en.x, en.y } end
			if now - (sq.lastContact or 0) >= C.Disengage then
				sq.fight = nil; sq.resend = true            -- fight over: Think sends him on with his plan
			elseif f.mode == "bound" and now >= f.boundEnd then
				GoDown(sq, f, budget); f.untilT = now + C.EngageHold
			elseif f.mode ~= "bound" and now >= f.untilT and AttackTasks[sq.task] and sq.pflag
				and (math.floor(now / C.BoundEvery) + sq.uid) % 2 == 0
				and not (kWant and AnyEnemyNear(sq.pos, kWant)) then
				-- fire and movement: only when our men around him outnumber what he can see
				local ours, theirs = 0, 0
				for _, o in ipairs(humans) do if Dist(o.pos, sq.pos) < 800 then ours = ours + 1 end end
				for _, e in ipairs(S.enemies) do
					if Dist({ e.x, e.y }, sq.pos) < C.EngageDist * 1.2 then theirs = theirs + (e.human and 1 or 4) end
				end
				local d = UnitDest(sq, sq.pflag, sq.task)
				local dd = d and Dist(sq.pos, d) or 0
				if d and dd > 150 and ours >= theirs * C.BoundRatio then
					local k = math.min(C.BoundStep, dd) / dd
					local bp = { sq.pos[1] + (d[1] - sq.pos[1]) * k, sq.pos[2] + (d[2] - sq.pos[2]) * k }
					local c = PickCover(sq, bp, f.enemy, budget)
					-- only cover that is a short dash forward: not a building across the street in the open (replay 2:30-3:30)
					if c and (Dist(sq.pos, { c.x, c.y }) > C.BoundStep * 1.25 or Dist({ c.x, c.y }, d) > dd) then c = nil end
					local moved = false
					if c then
						local ok, r = pcall(R.Cover, sq.uid, c.x, c.y, true)   -- rush to the next cover
						moved = ok and r
						if moved then sq.prone = nil end
					end
					if not moved then
						if sq.prone and SetPose(sq, 0, true) then table.insert(S.later, { t = now + 1, sq = sq, d = bp, force = true })
						else pcall(R.Move, sq.uid, bp[1], bp[2], false, 0) end
					end
					f.mode = "bound"; f.boundEnd = now + 7; S.stat.bound = S.stat.bound + 1
				else
					f.untilT = now + 4                        -- not yet: keep firing, look again shortly
				end
			end
		elseif not busy and not sq.coveredAt and arrived and spotTask then
			-- arrived at his spot (and done building): take the best cover there he can fire from - his own sandbags
			local ep = SpotThreat(sq)
			if sq.buildAt and now - sq.buildAt > C.BuildTime and sq.builtFor == destKey then
				sq.coveredAt = now; if sq.ranged or C.PoseRiflemen then SetPose(sq, 2) end      -- behind his own sandbags
			elseif not sq.buildAt or now - sq.buildAt > C.BuildTime then
				sq.coveredAt = now
				local c = PickCover(sq, sq.dest, ep, budget, KeepZone(sq))
				if c and Dist({ c.x, c.y }, sq.pos) > 20 then
					local ok, r = pcall(R.Cover, sq.uid, c.x, c.y, false)
					if ok and r then S.stat.spotCover = S.stat.spotCover + 1 end
				elseif not c then
					if sq.ranged then SetPose(sq, 1) elseif C.PoseRiflemen then SetPose(sq, 2) end   -- no cover: gunner lies down
				end
			end
		end
	end
	-- machine gun nests: a gunner who has stopped and has no sandbags of his own gets a wall from the nearest man
	-- carrying some (he walks over and builds it in front of the gun)
	local bagMen, bagTotal = 0, 0
	for _, sq in ipairs(humans) do
		if (sq.bags or 0) > 0 then bagMen = bagMen + 1; bagTotal = bagTotal + sq.bags end
	end
	S.bagMen, S.bagTotal = bagMen, bagTotal
	if C.Fortify and C.MGNests and R.Build then
		for _, mg in ipairs(humans) do
			if mg.mg and (mg.bags or 0) == 0 and now >= (mg.nestT or 0) and mg.stillSince and now - mg.stillSince >= (C.NestStill or 6)
				and not WallNear(mg.pos, C.FortifyGap or 120) and not SeenNear(mg.pos, C.FortifyEnemyMinMG or 900) then
				mg.nestT = now + 15
				local helper, hd = nil, C.NestHelpDist or 700
				for _, o in ipairs(humans) do
					if o ~= mg and (o.bags or 0) > 0 and not o.mg and not o.fight and (o.atkUntil or 0) <= now
						and not (o.buildAt and now - o.buildAt < C.BuildTime) then
						local d = Dist(o.pos, mg.pos)
						if d < hd then helper, hd = o, d end
					end
				end
				if helper then
					local ep = (mg.fight and mg.fight.enemy) or SpotThreat(mg)
					if BuildWall(helper, mg.pos, ep, now) then
						helper.buildAt = now - C.BuildTime + (C.NestHold or 35)
						mg.nestT = now + 90
						S.stat.mgNest = (S.stat.mgNest or 0) + 1
						if S.stat.mgNest <= 3 then Log(string.format("unit %s builds sandbags for machine gunner %s", tostring(helper.uid), tostring(mg.uid))) end
					end
				end
			end
		end
	end
	for k, v in pairs(S.coverRes) do if v.t < now then S.coverRes[k] = nil end end
end

-- moves held back a second (after standing a soldier up)
local function FlushLater()
	if #S.later == 0 then return end
	local keep = {}
	for _, l in ipairs(S.later) do
		if l.t > S.t then table.insert(keep, l)
		elseif S.squads[l.sq.id] == l.sq and (l.force or not l.sq.fight) then
			if l.run then pcall(R.Move, l.sq.uid, l.d[1], l.d[2], true, 0) else MoveUnit(l.sq, l.d) end
		end
	end
	S.later = keep
end

-- every few seconds: combat reactions, stop running near enemies, point anti-tank weapons at visible enemy vehicles
local function Micro()
	local ok, e = pcall(R.Enemies, C.Director and true or false)
	if ok and type(e) == "table" then
		-- wrecks: a knocked-out vehicle can still look alive to the game. Drop vehicles with no health left, and any
		-- vehicle our anti-tank weapons have been firing at for a while without hurting it (dead crew, burnt hull)
		S.wreck = S.wreck or {}; S.vehWatch = S.vehWatch or {}
		local live = {}
		for _, en in ipairs(e) do
			local keep = true
			if not en.human then
				local w = S.vehWatch[en.id]
				if w then
					if en.hp and w.hp and en.hp < w.hp - 0.001 then w.hp = en.hp; w.hpT = S.t end
					if w.x and Dist({ en.x, en.y }, { w.x, w.y }) > 120 then S.wreck[en.id] = nil; w.firstAtk = nil; w.x, w.y = en.x, en.y end
				end
				if en.hp and en.hp >= 0 and en.hp <= 0.001 then keep = false end
				if S.wreck[en.id] and S.wreck[en.id] > S.t then keep = false end
			end
			if keep then table.insert(live, en) end
		end
		e = live
		if R.All and C.CrewCheck then
			local anyVeh = false
			for _, en in ipairs(e) do if not en.human then anyVeh = true; break end end
			if anyVeh then
				local foes = {}
				for _, en in ipairs(e) do if en.player then foes[en.player] = true end end
				local ok2, all = pcall(R.All)
				if ok2 and type(all) == "table" then
					local inside, outside = {}, {}
					for _, u in ipairs(all) do
						if u.human and foes[u.player] then table.insert(u.boarded and inside or outside, u) end
					end
					local crewed = {}
					for _, en in ipairs(e) do
						local has = en.human
						if not has then
							for _, u in ipairs(inside) do local dx, dy = u.x - en.x, u.y - en.y; if dx * dx + dy * dy < C.CrewDist * C.CrewDist then has = true; break end end
						end
						if not has then
							for _, u in ipairs(outside) do local dx, dy = u.x - en.x, u.y - en.y; if dx * dx + dy * dy < C.GunCrewDist * C.GunCrewDist then has = true; break end end
						end
						if has then table.insert(crewed, en)
						elseif not S.wreck[en.id] then
							S.wreck[en.id] = S.t + 60
							S.stat.wrecks = (S.stat.wrecks or 0) + 1
							if S.stat.wrecks <= 5 then Log(string.format("enemy vehicle %s has no crew: ignored (dead or abandoned)", tostring(en.id))) end
						else
							S.wreck[en.id] = S.t + 60
						end
					end
					e = crewed
				end
			end
		end
		S.allEnemies = e
		local vis = {}
		for _, en in ipairs(e) do if en.seen ~= false then table.insert(vis, en) end end
		S.enemies = vis               -- what our soldiers can see; the director uses S.allEnemies
	end
	if C.Combat and R.Pose then Combat() end
	-- smoke: a flag our men are fighting for with enemies on it gets a smoke grenade on the flag point
	if C.Smoke and R.Throw and S.dir and S.cls and S.geo then
		for name in pairs(S.flags) do
			local c = S.cls[name]
			local atk = S.wave and S.wave.launched and S.wave.target == name and S.flags[name].owner ~= "us"
			if (atk or ((c == "mid" or c == "eback") and (S.dir.near[name] or 0) >= 0.5)) and S.t >= (S.smokeT[name] or 0) then
				local p = FlagPos(name)
				local rad = (S.geo.radius and S.geo.radius[string.lower(name)]) or 240
				local ours = 0
				for _, sq in pairs(S.squads) do
					if sq.uid and sq.human and sq.pos and p and not Gun[sq.role] and Dist(sq.pos, p) < rad + 1200 then ours = ours + 1 end
				end
				if ours >= 2 and p then
					-- where the fire comes from: the enemies around the flag (director), else the enemy base
					local sx, sy, sn = 0, 0, 0
					for _, en in ipairs(S.allEnemies or {}) do
						local dd = Dist({ en.x, en.y }, p)
						if dd < rad + 2500 then sx, sy, sn = sx + en.x, sy + en.y, sn + 1 end
					end
					local ep = (sn > 0) and { sx / sn, sy / sn } or EnemyBasePos()
					local dx, dy = ep[1] - p[1], ep[2] - p[2]
					local el = math.max(1, math.sqrt(dx * dx + dy * dy))
					local ux, uy = dx / el, dy / el
					local fwd = math.min(rad * 0.7, el * 0.5)
					local side = rad * 0.9
					-- the front edge toward the enemy, both sides, then the middle of the flag
					local pts = {
						{ p[1] + ux * fwd, p[2] + uy * fwd },
						{ p[1] + ux * rad * 0.2 - uy * side, p[2] + uy * rad * 0.2 + ux * side },
						{ p[1] + ux * rad * 0.2 + uy * side, p[2] + uy * rad * 0.2 - ux * side },
						{ p[1], p[2] },
					}
					local used, thrown = {}, 0
					local reach = C.SmokeRange * (C.SmokeMaxFrac or 0.95)
					for i = 1, math.min(#pts, C.SmokeCount or 1) do
						local q = pts[i]
						-- thrown from max range: the man furthest from the point who can still reach it (he stays back)
						local best, bd = nil, -1
						for _, sq in pairs(S.squads) do
							if sq.uid and sq.human and sq.pos and not used[sq.id] and not Gun[sq.role] and (sq.smoke or 0) > 0 and not sq.ranged then
								local d = Dist(sq.pos, q)
								if d < reach and d > bd then best, bd = sq, d end
							end
						end
						if best then
							used[best.id] = true
							local ok2, r = pcall(R.Throw, best.uid, 3, q[1], q[2])
							if ok2 and r and r ~= 0 then thrown = thrown + 1 end
						end
					end
					if thrown > 0 then
						S.smokeT[name] = S.t + (atk and (C.SmokeAttackEvery or C.SmokeEvery) or C.SmokeEvery); S.stat.smoke = (S.stat.smoke or 0) + thrown
						Log(string.format("smoke screen on flag %s: %d grenades toward the enemy side", name, thrown))
					else
						S.smokeT[name] = S.t + 6
					end
				end
			end
		end
	end
	local vehicles = {}
	for _, en in ipairs(S.enemies) do if not en.human then table.insert(vehicles, en) end end
	local hunt = {}
	for _, en in ipairs(S.allEnemies or {}) do if not en.human then table.insert(hunt, en) end end
	local pests = {}
	for _, en in ipairs(S.allEnemies or {}) do if not en.human and (S.vehKills[en.id] or 0) >= (C.PestKills or 3) then table.insert(pests, en) end end
	local alive = {}
	for _, en in ipairs(S.allEnemies or {}) do alive[en.id] = true end
	for _, sq in pairs(S.squads) do
		if sq.uid and sq.pos then
			-- his target is gone from the enemy list (destroyed, abandoned, or a wreck): an attack order keeps him
			-- shooting the hull forever, so cancel it with a stop where he stands and hand him back to the planner
			if sq.atkTarget and not alive[sq.atkTarget] then
				pcall(R.Move, sq.uid, sq.pos[1], sq.pos[2], false, 0)
				sq.atkTarget = nil; sq.atkUntil = 0; sq.resend = true
				S.stat.atkStop = (S.stat.atkStop or 0) + 1
				if S.stat.atkStop <= 5 then Log(string.format("unit %s: target dead or abandoned, stopped firing at it", tostring(sq.uid))) end
			end
			-- light vehicle with enemy anti-tank (AT soldier, gun, tank) close: back off out of its reach, then the
			-- planner sends it in again somewhere safer (VehDest keeps VehMinAT from known AT)
			if not sq.human and sq.role == "light" and C.LightFleeDist and S.atList and #S.atList > 0 and S.t >= (sq.fleeUntil or 0) then
				local th, td = nil, C.LightFleeDist
				for _, a in ipairs(S.atList) do local dd = Dist(sq.pos, a); if dd < td then th, td = a, dd end end
				if th then
					local ax, ay = sq.pos[1] - th[1], sq.pos[2] - th[2]
					local al = math.max(1, math.sqrt(ax * ax + ay * ay))
					ax, ay = ax / al, ay / al
					local b = BasePos()
					if b then
						local bx, by = b[1] - sq.pos[1], b[2] - sq.pos[2]
						local bl = math.max(1, math.sqrt(bx * bx + by * by))
						ax, ay = ax + 0.6 * bx / bl, ay + 0.6 * by / bl
						local l2 = math.max(0.01, math.sqrt(ax * ax + ay * ay)); ax, ay = ax / l2, ay / l2
					end
					local go = (C.LightFleeTo or 2600) - td + 200
					sq.dest = { sq.pos[1] + ax * go, sq.pos[2] + ay * go }; sq.running = false; sq.retreat = true
					pcall(R.Move, sq.uid, sq.dest[1], sq.dest[2], true, 0)
					sq.fleeUntil = S.t + (C.LightFleeTime or 10); sq.resend = true; sq.atkUntil = 0; sq.atkTarget = nil
					S.stat.lightFlee = (S.stat.lightFlee or 0) + 1
					if S.stat.lightFlee <= 5 then Log(string.format("light vehicle %s pulls back: enemy anti-tank at %d m", tostring(sq.uid), math.floor(td / 20))) end
				end
			end
			if sq.running and sq.dest and not sq.retreat and AnyEnemyNear(sq.pos, C.CalmStop or C.CalmDist) then
				pcall(R.Move, sq.uid, sq.dest[1], sq.dest[2], false, 0)
				sq.running = false; S.stat.calm = S.stat.calm + 1
			end
			-- AT riflemen go for vehicles first, out to their full range; their fight with infantry waits
			local range = (sq.atr and sq.human and C.ATRVehRange) or (AtRoles[sq.role] and C.AtRange) or ((sq.role == "td") and (C.TDRange or C.TankRange)) or (TankRoles[sq.role] and C.TankRange) or nil
			local list = vehicles
				-- tanks / tank destroyers: the director's picture of enemy armour, so the attack order turns them to face
				-- a tank before it opens fire on them (the game only turns a vehicle's hull under an attack order)
				if not sq.human and C.TankDirector and (TankRoles[sq.role] or sq.role == "td") then list = hunt end
				if sq.human and (sq.atr or AtRoles[sq.role]) and C.AtHuntRange then range = math.max(range or 0, C.AtHuntRange); list = hunt end
				-- a vehicle that keeps killing our men: AT men go for it from further out, machine gunners shoot its crew
				if #pests > 0 and sq.human then
					if sq.atr or AtRoles[sq.role] then range = math.max(range or 0, (C.AtHuntRange or 2600) * 1.4); list = pests
					elseif sq.mg then
						local soft = {}
						for _, en in ipairs(pests) do if S.softVeh[en.id] then table.insert(soft, en) end end
						if #soft > 0 then range = C.MGMax or 2700; list = soft end
					end
				end
				-- a tank / tank destroyer being hit turns on its attacker: the game only turns a vehicle to bring its gun
				-- to bear under an attack order (aimer "require rotate"), so one that is shot from out of sight just sat
				-- there. Hit in the last 15 s: attack the nearest known enemy vehicle or gun, seen or not
				local hurtNow = false
				if not sq.human and (TankRoles[sq.role] or sq.role == "td") and sq.hp and sq.hp >= 0 then
					if sq.vHp and sq.hp < sq.vHp - 0.001 then sq.hurtT = S.t; hurtNow = true end
					sq.vHp = sq.hp
					if S.t - (sq.hurtT or -1e9) < 15 and #hunt > 0 then
						list = hunt; range = math.max(range or 0, C.HurtFaceRange or 4500)
					end
				end
				local oldOk = false
				if hurtNow and sq.atkTarget then for _, en in ipairs(vehicles) do if en.id == sq.atkTarget then oldOk = true; break end end end
				local armour = not sq.human and (TankRoles[sq.role] or sq.role == "td")
				-- a tank / TD keeps its hull toward what it is fighting: the turn is a move to where it stands with a
				-- facing point (v11 DLL), then the attack order again a moment later
				if armour and sq.atkTarget and sq.fx and S.t < (sq.atkUntil or 0) and (sq.turning or S.t >= (sq.faceT or 0)) then
					for _, en in ipairs(list) do
						if en.id == sq.atkTarget then
							if sq.turning or FaceOff(sq, en) > ((sq.role == "td") and (C.FaceTolTD or 12) or (C.FaceTolTank or 30)) then
								if FaceThenAttack(sq, en) then sq.atkUntil = S.t + (C.FaceWait or 2) end
								sq.faceT = S.t + (C.FaceEvery or 6)
							end
							break
						end
					end
				end
				-- out of range: a tank / TD drives up to 10 m inside its gun's reach of the nearest known enemy vehicle,
				-- ending the move facing it
				if armour and range and #list > 0 and S.t >= (sq.atkUntil or 0) and S.t >= (sq.approachT or 0) then
					local near, nd = nil, math.huge
					for _, en in ipairs(list) do local d = Dist(sq.pos, { en.x, en.y }); if d < nd then near, nd = en, d end end
					if near and nd >= range and nd < range + (C.ApproachExtra or 2500) then
						local k = (nd - (range - (C.ApproachInside or 200))) / nd
						local ap = IntelDry({ sq.pos[1] + (near.x - sq.pos[1]) * k, sq.pos[2] + (near.y - sq.pos[2]) * k })
						pcall(R.Move, sq.uid, ap[1], ap[2], false, 0, near.x, near.y)
						sq.approachT = S.t + 8; sq.atkUntil = S.t + 8; sq.running = false
						sq.orderT = S.t - C.ReorderPeriod + 25
						S.stat.approach = (S.stat.approach or 0) + 1
						if S.stat.approach <= 3 then Log(string.format("%s %s closes to within range of enemy %s (%s) at %d m", sq.role, tostring(sq.uid), tostring(near.id), S.names[near.id] or "?", math.floor(nd / 20))) end
					end
				end
				if range and #list > 0 and (S.t >= (sq.atkUntil or 0) or (hurtNow and not oldOk)) and not (sq.buildAt and S.t - sq.buildAt < C.BuildTime) then
				-- nearest enemy vehicle our side can see within range; one only the director knows about comes second
				local best, bd, inRange = nil, range, 0
				local seenBest, seenD = nil, range
				for _, en in ipairs(list) do
					local d = Dist(sq.pos, { en.x, en.y })
					if d < range then inRange = inRange + 1 end
					if d < bd then best, bd = en, d end
					if en.seen ~= false and d < seenD then seenBest, seenD = en, d end
				end
				if seenBest then best, bd = seenBest, seenD end
				if best then
					-- stay on the same target while it is alive and in range (turning to a new one wastes the shot) -
					-- unless it is unseen and there is one we can see
					if sq.atkTarget and sq.atkTarget ~= best.id then
						for _, en in ipairs(list) do
							if en.id == sq.atkTarget and Dist(sq.pos, { en.x, en.y }) < range and (en.seen ~= false or not seenBest) then best = en; bd = Dist(sq.pos, { en.x, en.y }); break end
						end
					end
					sq.atkTarget = best.id
					local turned = false
					local pest = (S.vehKills[best.id] or 0) >= (C.PestKills or 3)
					if pest and sq.atr and bd > (C.ATRMax or 2300) then
						-- AT rifle against a pest: get within max range (~105 m) first, then fire
						local k = (bd - (C.ATRWant or 2100)) / bd
						pcall(R.Move, sq.uid, sq.pos[1] + (best.x - sq.pos[1]) * k, sq.pos[2] + (best.y - sq.pos[2]) * k, true, 0)
					else
						-- AT soldiers get down first: AT rifles lie flat, rocket launchers (they can't fire lying) crouch
						if sq.human and C.AtPoses then
							local want = sq.rl and 2 or ((sq.atr or AtRoles[sq.role]) and 1 or nil)
							if want and (sq.poseKind ~= want or not sq.prone) then SetPose(sq, want, true); S.stat.atPose = (S.stat.atPose or 0) + 1 end
						end
						-- a tank / TD facing the wrong way turns first, attacks a moment later
						if armour and sq.fx then
							turned = FaceThenAttack(sq, best)
							sq.faceT = S.t + (C.FaceEvery or 6)
						else
							pcall(R.Attack, sq.uid, best.id)
						end
						if S.stat.atk < 3 or (armour and not sq.loggedAtk) then
							sq.loggedAtk = true
							Log(string.format("%s %s attacks enemy %s (%s) at %d m", tostring(sq.role), tostring(sq.uid), tostring(best.id), S.names[best.id] or "?", math.floor(bd / 20)))
						end
					end
					local w = S.vehWatch[best.id]
					if not w then w = { hp = best.hp, hpT = S.t, x = best.x, y = best.y }; S.vehWatch[best.id] = w end
					w.firstAtk = w.firstAtk or S.t
					-- shot at for 45 s without moving or being hurt while another enemy vehicle is in reach: a wreck, an
					-- empty hull or something we can't hurt - switch to the other one (replay 2026-11-01: 242 attack orders
					-- over 15 min on one fixed point while the Pz III ignored a live tank in range). Vehicle health from the
					-- game rarely drops (damage is per part), so this only fires when there is something else to shoot
					if inRange >= 2 and S.t - w.firstAtk > (C.WreckAfter or 45) and S.t - (w.hpT or w.firstAtk) > (C.WreckNoDamage or 30) then
						S.wreck[best.id] = S.t + (C.WreckIgnore or 120); w.firstAtk = nil; w.hpT = S.t
						Log(string.format("enemy %s (%s) takes no damage from us: ignored for %d s", tostring(best.id), S.names[best.id] or "?", C.WreckIgnore or 120))
					end
					sq.atkUntil = S.t + (turned and (C.FaceWait or 3) or (C.AtkHold or 15)); sq.running = false
					sq.orderT = S.t - C.ReorderPeriod + 25     -- the planner takes the unit back 25 s later unless it attacks again
					S.stat.atk = S.stat.atk + 1
				end
			end
				-- no armour to fight: a tank / TD goes for the enemy's machine guns (fog ignored, from the director scan),
				-- else enemy soldiers our side can see - hull first. An MG out of reach gets driven up to, unless enemy
				-- anti-tank soldiers stand near the spot it would stop at
				if armour and C.TankSoft and S.t >= (sq.atkUntil or 0) and S.t >= (sq.approachT or 0) then
					local reach = C.TankSoftRange or 2200
					local tgt, td = nil, reach
					local far, fd = nil, reach + (C.ApproachExtra or 2500)
					for _, m in ipairs(S.mgList or {}) do
						local d = Dist(sq.pos, m)
						if d < td then tgt, td = { id = m.id, x = m[1], y = m[2] }, d end
						if d < fd then far, fd = m, d end
					end
					if not tgt then
						for _, en in ipairs(S.enemies or {}) do
							if en.human then local d = Dist(sq.pos, { en.x, en.y }); if d < td then tgt, td = en, d end end
						end
					end
					if tgt then
						local turned = FaceThenAttack(sq, tgt)
						sq.atkUntil = S.t + (turned and (C.FaceWait or 2) or (C.TankSoftHold or 12)); sq.running = false
						sq.orderT = S.t - C.ReorderPeriod + 25
						S.stat.tankSoft = (S.stat.tankSoft or 0) + 1
						if S.stat.tankSoft <= 3 then Log(string.format("%s %s attacks enemy infantry %s (%s) at %d m", sq.role, tostring(sq.uid), tostring(tgt.id), S.names[tgt.id] or "?", math.floor(td / 20))) end
					elseif far and fd >= reach then
						local k = (fd - (reach - (C.ApproachInside or 200))) / fd
						local spot = { sq.pos[1] + (far[1] - sq.pos[1]) * k, sq.pos[2] + (far[2] - sq.pos[2]) * k }
						local safe = true
						for _, a in ipairs(S.atInf or {}) do if Dist(spot, a) < (C.TankAtSafe or 900) then safe = false; break end end
						if safe then
							spot = IntelDry(spot); pcall(R.Move, sq.uid, spot[1], spot[2], false, 0, far[1], far[2])
							sq.approachT = S.t + 8; sq.atkUntil = S.t + 8; sq.running = false
							sq.orderT = S.t - C.ReorderPeriod + 25
							S.stat.tankSoftGo = (S.stat.tankSoftGo or 0) + 1
							if S.stat.tankSoftGo <= 3 then Log(string.format("%s %s drives up on an enemy machine gun %d m away", sq.role, tostring(sq.uid), math.floor(fd / 20))) end
						end
					end
				end
		end
	end
end

------------------------------------------------------------------ team zones
-- every player's spawn: where his new soldiers first appear (averaged); our own player number from one of our units
local function NoteSpawns(all, foes)
	S.spawnAcc = S.spawnAcc or {}; S.seenIds = S.seenIds or {}; S.playerSeen = S.playerSeen or {}
	S.foePlayers = S.foePlayers or {}
	for p in pairs(foes or {}) do S.foePlayers[p] = true end
	for _, u in ipairs(all) do
		if u.player then
			S.playerSeen[u.player] = S.t
			if not S.myPlayer and S.squads["u" .. tostring(u.id)] then S.myPlayer = u.player end
			if not S.seenIds[u.id] then
				S.seenIds[u.id] = true
				if u.human and not u.boarded then
					local a = S.spawnAcc[u.player] or { x = 0, y = 0, n = 0 }
					if a.n < (C.SpawnSamples or 40) then a.x, a.y, a.n = a.x + u.x, a.y + u.y, a.n + 1 end
					S.spawnAcc[u.player] = a
				end
			end
		end
	end
end

local function SpawnOf(p)
	local a = S.spawnAcc and S.spawnAcc[p]
	if a and a.n >= 3 then return { a.x / a.n, a.y / a.n } end
end

-- Team games: our part of the front. The line from our spawn to the enemy spawn straight across; through its middle
-- a line at right angles = the team's frontage. Its length (end to end of the map) split by the number of players on
-- our team; each takes the slice in front of his own spawn, in spawn order. 1v1: no zone (the whole map is ours).
local function ZoneLat(p)
	local z = S.zone
	return (p[1] - z.m[1]) * z.vx + (p[2] - z.m[2]) * z.vy
end

local function UpdateZone()
	if not (C.TeamZones and S.geo and S.home and S.myPlayer) or S.t < (S.zoneT or 0) then return end
	S.zoneT = S.t + 15
	local home = S.home
	-- the enemy spawn most directly across from ours (else our spawn mirrored through the flags)
	local opp = EnemyBasePos()
	local best, bd = nil, math.huge
	for p in pairs(S.foePlayers or {}) do
		local q = SpawnOf(p)
		if q then local d = Dist(q, opp); if d < bd then best, bd = q, d end end
	end
	if best and bd < S.geo.scale * 0.6 then opp = best end
	local ax, ay = opp[1] - home[1], opp[2] - home[2]
	local al = math.max(1, math.sqrt(ax * ax + ay * ay))
	local z = { m = { (home[1] + opp[1]) / 2, (home[2] + opp[2]) / 2 }, ux = ax / al, uy = ay / al }
	z.vx, z.vy = -z.uy, z.ux
	local old = S.zone
	S.zone = z
	-- our team: us + every other player with men on the field who is not an enemy (and has been seen lately)
	local team = { { p = S.myPlayer, lat = ZoneLat(home) } }
	for p, t in pairs(S.playerSeen or {}) do
		if p ~= S.myPlayer and not S.foePlayers[p] and S.t - t < 90 then
			local q = SpawnOf(p)
			if q then table.insert(team, { p = p, lat = ZoneLat(q) }) end
		end
	end
	if #team < 2 then S.zone = nil; if old then Log("team zone: off (no teammates on the field)") end; return end
	-- the frontage end to end: everything on the map we know of, projected onto it, plus a margin past the outermost
	local lo, hi = math.huge, -math.huge
	-- with map intel: exactly where the line crosses the playable area's edges
	local pb = S.intel and (S.intel.pather or S.intel.world)
	if pb then
		for _, ax in ipairs({ { z.m[1], z.vx, pb[1], pb[3] }, { z.m[2], z.vy, pb[2], pb[4] } }) do
			local p, v, a, c = ax[1], ax[2], ax[3], ax[4]
			if math.abs(v) > 1e-6 then
				local t1, t2 = (a - p) / v, (c - p) / v
				if t1 > t2 then t1, t2 = t2, t1 end
				lo = (lo == math.huge) and t1 or math.max(lo, t1); hi = (hi == -math.huge) and t2 or math.min(hi, t2)
			end
		end
		if not (hi > lo + 500) then lo, hi = math.huge, -math.huge else z.src = "map bounds" end
	end
	if not z.src then
		local function take(q) local l = ZoneLat(q); if l < lo then lo = l end; if l > hi then hi = l end end
		for _, f in pairs(S.geo.f or {}) do take(f) end
		for _, q in ipairs(S.mapPts or {}) do take(q) end
		for p in pairs(S.spawnAcc or {}) do local q = SpawnOf(p); if q then take(q) end end
		take(home)
		local margin = math.max(C.ZoneMargin or 1000, (hi - lo) * (C.ZoneMarginShare or 0.08))
		lo, hi = lo - margin, hi + margin
		z.src = "estimate"
	end
	table.sort(team, function(a, b) return a.lat < b.lat end)
	local idx = 1
	for i, t in ipairs(team) do if t.p == S.myPlayer then idx = i end end
	local w = (hi - lo) / #team          -- our share of the frontage: 1 / number of players on the team
	z.lo, z.hi, z.w, z.n, z.i, z.len = lo + (idx - 1) * w, lo + idx * w, w, #team, idx, hi - lo
	-- a slice with no flag in it: widen it evenly until it takes in the nearest flag
	z.elo, z.ehi = z.lo, z.hi
	local nIn, gap = 0, math.huge
	for _, f in pairs(S.geo.f or {}) do
		local l = ZoneLat(f)
		if l >= z.lo and l <= z.hi then nIn = nIn + 1 else gap = math.min(gap, l < z.lo and z.lo - l or l - z.hi) end
	end
	if nIn == 0 and gap < math.huge then z.elo, z.ehi = z.lo - gap - 50, z.hi + gap + 50 end
	z.flags = nIn
	if not old or old.n ~= z.n or old.i ~= z.i or old.src ~= z.src or math.abs((old.lo or 0) - z.lo) > 400 then
		local names = {}
		for name in pairs(S.flags) do local p = FlagPos(name); if p then local l = ZoneLat(p); if l >= z.elo and l <= z.ehi then table.insert(names, name) end end end
		table.sort(names)
		Log(string.format("team zone: %d players, we are #%d; frontage %d m long at the midpoint (%s), our slice %d m wide (%.0f%%); flags in it: %s",
			z.n, z.i, math.floor(z.len / 20), z.src, math.floor(z.w / 20), 100 / z.n, (#names > 0) and table.concat(names, ", ") or "none"))
	end
end

-- how far (game units) a point lies outside our zone; 0 inside or with no zone
local function ZoneOut(p)
	local z = S.zone
	if not (z and p) then return 0 end
	local l = ZoneLat(p)
	if l < z.elo then return z.elo - l elseif l > z.ehi then return l - z.ehi end
	return 0
end

-- director: where the whole enemy army is (fog of war ignored) - per flag: strength on it and moving on it
local function Director()
	S.dir = nil
	if not (R and C.Director and S.geo) then return end
	local d = { near = {}, approach = {}, veh = 0, inf = 0, total = 0 }
	local fl = {}
	for name, st in pairs(S.flags) do
		local p = FlagPos(name)
		if p then table.insert(fl, { name = name, p = p, r = (S.geo.radius and S.geo.radius[st.key]) or 200 }) end
	end
	for _, en in ipairs(S.allEnemies or {}) do
		local w = en.human and (BotStrength.inf / 4) or 2.0
		if en.human then d.inf = d.inf + 1 else d.veh = d.veh + 1 end
		d.total = d.total + w
		for _, f in ipairs(fl) do
			local dx, dy = en.x - f.p[1], en.y - f.p[2]
			local dist = math.sqrt(dx * dx + dy * dy)
			if dist < f.r + C.DirNear then d.near[f.name] = (d.near[f.name] or 0) + w
			elseif dist < f.r + C.DirApproach then d.approach[f.name] = (d.approach[f.name] or 0) + w end
		end
	end
	-- weakness check (sees everything): how much anti-tank the enemy has, in total and around each flag
	if C.Exploit and R.All and S.t >= (S.atScanT or 0) then
		S.atScanT = S.t + 6
		local foes = {}
		for _, en in ipairs(S.allEnemies or {}) do if en.player then foes[en.player] = true end end
		local ok, all = pcall(R.All)
		if ok and type(all) == "table" then
			NoteSpawns(all, foes)
			local near, total = {}, 0
			local atl, mgl, ati = {}, {}, {}
			for _, u in ipairs(all) do
				if foes[u.player] and u.name then S.names[u.id] = u.name end
				if foes[u.player] and not u.boarded then
					local n = string.lower(u.name or "")
					local w = 0
					if u.human then
						if u.weapon == "mg" then table.insert(mgl, { u.x, u.y, id = u.id }) end
						if u.weapon == "atrifle" or (u.atgren or 0) > 0 then w = 1 end
						for _, p in ipairs(C.AtNames or {}) do if string.find(n, p, 1, true) then w = 1; break end end
					else
						w = 2
						for _, p in ipairs(C.NotAtVehicles or {}) do if string.find(n, p, 1, true) then w = 0; break end end
					end
					if w > 0 then
						total = total + w
						table.insert(atl, { u.x, u.y })
						if u.human then table.insert(ati, { u.x, u.y }) end
						for _, f in ipairs(fl) do
							local dx, dy = u.x - f.p[1], u.y - f.p[2]
							if dx * dx + dy * dy < (f.r + C.ExploitRadius) ^ 2 then near[f.name] = (near[f.name] or 0) + w end
						end
					end
				end
			end
			S.atNear, S.enemyAT, S.atList = near, total, atl
			S.mgList, S.atInf = mgl, ati      -- enemy machine gunners (with ids) and anti-tank soldiers, fog ignored
			local weak = total <= C.ExploitMaxATTotal
			if weak ~= S.enemyWeakAT then
				S.enemyWeakAT = weak
				Log(weak and string.format("weakness: enemy has almost no anti-tank (%d) - buying vehicles to exploit it", total) or string.format("enemy anti-tank back up (%d)", total))
			end
		end
	end
	-- real armour only (no trucks, halftracks, guns): this sizes our anti-tank. The bot used to count every vehicle
	if R.All and S.t >= (S.armScanT or 0) then
		S.armScanT = S.t + 6
		local foes = {}
		for _, en in ipairs(S.allEnemies or {}) do if en.player then foes[en.player] = true end end
		local ok, all = pcall(R.All)
		if ok and type(all) == "table" then
			local n = 0
			for _, u in ipairs(all) do
				if foes[u.player] and not u.human then
					local nm = string.lower(u.name or "")
					local w = 1
					for _, p in ipairs(C.NotAtVehicles or {}) do if string.find(nm, p, 1, true) then w = 0; break end end
					if w > 0 then for _, p in ipairs(C.ArmourIgnore or {}) do if string.find(nm, p, 1, true) then w = 0; break end end end
					if w == 0 then S.softVeh[u.id] = true end
					n = n + w
				end
			end
			if n ~= S.enemyArmour then Log(string.format("enemy armour now %d (of %d vehicles/guns)", n, d.veh)) end
			S.enemyArmour = n
		end
	end
	d.armour = S.enemyArmour or d.veh
	-- soft vehicles that keep killing our men (an MG jeep) are answered like armour
	d.pests = 0
	for _, en in ipairs(S.allEnemies or {}) do
		if not en.human and (S.vehKills[en.id] or 0) >= (C.PestKills or 3) and (S.softVeh[en.id] or not S.enemyArmour) then d.pests = d.pests + 1 end
	end
	d.armour = d.armour + d.pests
	S.dir = d
	if d.veh > 0 then S.enemyTanks = true end
	if d.armour > 0 then S.firstEnemyVehT = S.firstEnemyVehT or S.t end
end

local function UpdateSquads()
	if R then UpdateUnits(); return end
	local alive = {}
	for _, id in pairs(Api.Scene.Squads) do
		alive[id] = true
		if not S.squads[id] then RegisterSquad(id, nil) end
	end
	for id, sq in pairs(S.squads) do
		if not alive[id] then
			local f = sq.flag and S.flags[sq.flag]
			if f and f.owner ~= "us" then f.losses = f.losses + Strength(sq) end
			S.squads[id] = nil; S.lost = S.lost + 1
		end
	end
end

-- emplacements (MG nests, mortars, light guns): a crewed gun does not answer a plain move order on the gun, so each
-- emplacement squad is sent with the game's own squad order (the one the stock AI uses, which makes the crew move
-- the gun) to the flag we hold nearest the enemy. It stays there; it is only re-sent if that flag is lost or a
-- better (more forward) flag of ours exists and the gun hasn't arrived anywhere yet, or if it never got going.
local function EmplaceAnchor()
	local eb, hb = EnemyBasePos(), BasePos()
	if not eb or not hb then return nil end
	local anchor, ad = nil, math.huge
	for name, st in pairs(S.flags) do
		local p = FlagPos(name)
		if p and st.owner == "us" then local d = Dist(p, eb); if d < ad then anchor, ad = name, d end end
	end
	if not anchor then
		for name in pairs(S.flags) do local p = FlagPos(name); if p then local d = Dist(p, hb); if d < ad then anchor, ad = name, d end end end
	end
	return anchor
end

local function AtGunAnchor(forward)
	local eb = EnemyBasePos(); local fp = FlagPos(forward)
	if not eb or not fp then return forward end
	local best, bd = nil, math.huge
	for name, st in pairs(S.flags) do
		local p = FlagPos(name)
		if p and st.owner == "us" and name ~= forward and Dist(p, eb) > Dist(fp, eb) + 400 then
			local d = Dist(p, fp)
			if d < bd and d < (C.AtGunBackMax or 4000) then best, bd = name, d end
		end
	end
	return best or forward
end

local function EmplaceCount()
	local n = 0
	for _, e in pairs(S.empSquads) do if e.r ~= "atgun" then n = n + 1 end end
	for _, q in ipairs(S.queue) do if q.r == "emplace" then n = n + 1 end end
	return n
end

-- where a gun goes: behind our infantry front (AtGunBack / EmplaceBack), level with the anchor flag, spread sideways
local function GunSpot(e, anchor)
	local p = FlagPos(anchor); if not p then return nil end
	local pr, ux, uy = Prog(p); if not pr then return nil end
	local back = (e.r == "atgun") and (C.AtGunBack or 2000) or (C.EmplaceBack or 1200)
	local want = S.front and math.min(pr, S.front - back) or (pr - back)
	want = math.max(want, 400)
	local k = (e.idx or 0) % 7
	local slot = (k % 2 == 1) and ((k + 1) / 2) or (-k / 2)
	local side = slot * (C.GunSpread or 350)
	return { p[1] - ux * (pr - want) - uy * side, p[2] - uy * (pr - want) + ux * side }
end

-- the gun itself (not its crew) of an emplacement squad
local function GunUnit(e, near)
	for _, uid in ipairs(e.uids or {}) do local sq = S.squads["u" .. uid]; if sq and not sq.human and sq.pos then return sq end end
	if not near then return nil end
	local best, bd = nil, 300
	for _, sq in pairs(S.squads) do
		if sq.uid and not sq.human and Gun[sq.role] and sq.pos and not sq.gunOf then
			local d = Dist(sq.pos, near); if d < bd then best, bd = sq, d end
		end
	end
	return best
end

-- players move a gun with a plain move order on the gun. Returns true when this squad is handled that way
local function MoveGun(id, e, anchor, pos)
	if not (C.GunMove and R and R.Move) or e.noGun then return false end
	local gun = GunUnit(e, pos)
	if not gun then
		e.miss = (e.miss or 0) + 1
		if e.miss == 5 then Log(string.format("gun squad %s (%s): no gun unit found among its members, using the squad order", tostring(id), e.n or "?")); e.noGun = true end
		return false
	end
	gun.gunOf = id
	if not e.idx then S.gunIdx = (S.gunIdx or 0) + 1; e.idx = S.gunIdx end
	local spot = GunSpot(e, anchor)
	if not spot then return false end
	local far = Dist(gun.pos, spot) > 300
	-- stuck: ordered a while ago, still far from the spot and hasn't moved
	if e.spot and far and S.t - e.moveT > (C.GunStuckTime or 90) and Dist(gun.pos, e.movePos) < 40 then
		S.stat.gunStuck = (S.stat.gunStuck or 0) + 1
		Log(string.format("gun %s (%s) not moving after %ds: trying the squad order", tostring(gun.uid), e.n or "?", S.t - e.moveT))
		if (S.stat.gunStuck or 0) >= 3 and (S.stat.gunMoved or 0) == 0 and not S.gunsStuck then
			S.gunsStuck = true
			Log("guns never move here: no more gun / emplacement purchases")
		end
		e.noGun = true
		return false
	end
	if not e.moved and e.movePos and Dist(gun.pos, e.movePos) > 200 then
		e.moved = true; S.stat.gunMoved = (S.stat.gunMoved or 0) + 1
		if S.stat.gunMoved <= 3 then Log(string.format("gun %s (%s) is moving", tostring(gun.uid), e.n or "?")) end
	end
	if not e.spot or (Dist(e.spot, spot) > 400 and S.t - e.moveT > 30) then
		local ok, r = pcall(R.Move, gun.uid, spot[1], spot[2], false, 0)
		if ok then
			e.spot = spot; e.moveT = S.t; e.movePos = gun.pos; e.flag = anchor; e.t = S.t
			S.stat.empOrders = (S.stat.empOrders or 0) + 1
			local pr = Prog(gun.pos)
			Log(string.format("gun %s (%s) -> %.0f m from it, %s m behind the front", tostring(gun.uid), e.n or "?", Dist(gun.pos, spot) / 20, S.front and string.format("%.0f", (S.front - (Prog(spot) or 0)) / 20) or "?"))
		else
			Log("gun move failed: " .. tostring(r)); e.noGun = true; return false
		end
	end
	return true
end

local function PlaceEmplacements(guns)
	for _, sq in ipairs(guns) do sq.task = "emplace" end
	if not next(S.empSquads) or not S.geo then return end
	local alive = {}
	local ok, ids = pcall(function() return Api.Scene.Squads end)
	if not ok or type(ids) ~= "table" then return end
	for _, id in pairs(ids) do alive[id] = true end
	local anchor = EmplaceAnchor()
	if not anchor then return end
	for id, e in pairs(S.empSquads) do
		if not alive[id] then
			S.empSquads[id] = nil
		else
			-- where is the gun now (any member we can see)?
			local pos = nil
			for _, uid in ipairs(e.uids or {}) do local sq = S.squads["u" .. uid]; if sq and sq.pos then pos = sq.pos; break end end
			local anchor = (e.r == "atgun") and AtGunAnchor(anchor) or anchor
			if MoveGun(id, e, anchor, pos) then
				-- moved as a unit (above)
			else
			local cur = e.flag and S.flags[e.flag]
			local there = pos and e.flag and FlagPos(e.flag) and Dist(pos, FlagPos(e.flag)) < 900
			local lost = cur and cur.owner == "them"
			local better = e.flag ~= anchor and not there
			local stuck = e.flag and not there and pos and e.lastPos and Dist(pos, e.lastPos) < 40 and S.t - e.t > 60
			if not e.flag or lost or better or stuck then
				local ok2, err = pcall(function() Api.Commands:CaptureFlag(id, anchor) end)
				if ok2 then
					Log(string.format("emplacement squad %s (%s) -> flag %s%s", tostring(id), e.n or "?", anchor, stuck and " (re-sent: not moving)" or ""))
					S.stat.empOrders = (S.stat.empOrders or 0) + 1
				else
					Log("emplacement order failed: " .. tostring(err))
				end
				e.flag = anchor; e.t = S.t
			end
			if pos and (not e.lastPos or S.t - (e.posT or 0) >= 30) then e.lastPos = pos; e.posT = S.t end
			end
		end
	end
end

-- contested flags: the first CaptureTeam riflemen sent there go into the zone; everyone after them digs in around it.
-- While the flag is still defended (attack line phase) the whole line fights together instead.
local ZoneTasks = { attack = true, attack2 = true, grab = true, hold = true }
local function CapTeamTask(sq, flagName, task)
	sq.capFlag = nil
	if not C.CaptureTeam or not ZoneTasks[task] or not sq.human or not S.cls then return task end
	local c = S.cls[flagName]
	if c ~= "mid" and c ~= "eback" then return task end
	if task ~= "hold" and LinePhase(flagName) ~= "assault" then return task end
	local team = S.capTeam[flagName]
	if not team then team = {}; S.capTeam[flagName] = team end
	if team[sq.id] then sq.capFlag = flagName; return task end
	sq.capFlag = nil
	local n = 0
	for id in pairs(team) do
		local o = S.squads[id]
		if o and o.pflag == flagName then n = n + 1
		else
			-- a team man died: wait CapRefill seconds before sending the next one in (not a stream of men into the fire)
			if not o and C.CapRefill then
				S.capCool[flagName] = S.t + C.CapRefill; S.stat.capWait = (S.stat.capWait or 0) + 1
				if S.stat.capWait <= 5 then Log(string.format("capture team man lost on %s: next one goes in after %d s", flagName, C.CapRefill)) end
			end
			team[id] = nil
		end
	end
	if n < C.CaptureTeam and S.t >= (S.capCool[flagName] or 0) and not sq.ranged and not AtRoles[sq.role] and sq.role ~= "sniper" then
		team[sq.id] = true; sq.capFlag = flagName; return task
	end
	return "dig"
end

local function Order(sq, flagName, task)
	if not flagName then return end
	if sq.uid then
		if not (R and S.geo) then return end   -- single units can only be moved by the DLL, and only once flag positions are known
		sq.pflag = flagName
		task = CapTeamTask(sq, flagName, task)
		sq.task = task
		if sq.fight then return end      -- in a firefight: Micro decides when he moves (fire and movement)
		if (sq.atkUntil or 0) > S.t then return end          -- fighting a vehicle: keep facing it and firing
		if (sq.fleeUntil or 0) > S.t then return end         -- light vehicle pulling back from enemy anti-tank
		if sq.buildAt and S.t - sq.buildAt < C.BuildTime then return end   -- building sandbags: let him finish
		local d, phase = UnitDest(sq, flagName, task)
		if not d then return end
		local veh = IsVehicleRole(sq.role) and not sq.human
		if veh then d = VehDest(sq, d) end
		-- vehicles move in short hops (players ~55 m), re-sent as they get there
		if veh and C.VehStep and sq.pos then
			local dd = Dist(sq.pos, d)
			if dd > C.VehStep then local k = C.VehStep / dd; d = { sq.pos[1] + (d[1] - sq.pos[1]) * k, sq.pos[2] + (d[2] - sq.pos[2]) * k } end
			-- the hop toward it stays out of enemy AT reach too (the straight line can pass close to it)
			if sq.role == "light" and C.VehMinAT and C.VehMinAT[sq.role] and C.LightFleeDist then d = KeepFromAT(d, C.LightFleeDist + 400) end
		end
		-- defending or taking a flag: go straight to the best cover near the spot that faces the enemy (walls on the
		-- right side, sandbags, craters), instead of standing in the open and looking for cover once shot at
		if sq.human and not veh and (task == "hold" or task == "garrison" or task == "dig" or phase == "line") and R.Covers and C.SpotCoverRadius then
			local key = flagName .. task .. tostring(phase) .. math.floor(d[1] / 150) .. "_" .. math.floor(d[2] / 150)
			if sq.cdKey ~= key then
				sq.cdKey = key; sq.cdPt = nil
				local en, de = NearestOf(d, S.allEnemies or {})
				local threat = (en and de < 3000) and { en.x, en.y } or ((phase == "line") and FlagPos(flagName)) or EnemyBasePos()
				local c = PickCover(sq, d, threat, { n = 1 }, KeepZone(sq), C.SpotCoverRadius)
				if c then sq.cdPt = { c.x, c.y }; S.stat.coverSpot = (S.stat.coverSpot or 0) + 1 end
			end
			if sq.cdPt then d = sq.cdPt end
		end
		-- a gunner is never sent to a spot inside the enemy's close range; he holds where he is instead
		local kmin = KeepRange(sq)
		if kmin and sq.pos and AnyEnemyNear(d, kmin) and not AnyEnemyNear(sq.pos, kmin) then
			-- his spot is inside the enemy's close range: go as far toward it as is safe (the old rule left 16 MGs at base)
			local stop = nil
			for i = 1, 9 do
				local k = 1 - i * 0.1
				local q = { sq.pos[1] + (d[1] - sq.pos[1]) * k, sq.pos[2] + (d[2] - sq.pos[2]) * k }
				if not AnyEnemyNear(q, kmin) then stop = q; break end
			end
			if not stop or Dist(stop, sq.pos) < 200 then return end
			d = stop; S.stat.mgShort = (S.stat.mgShort or 0) + 1
		end
		-- under fire: no long walk anywhere (replay: men re-planned onto a flag 200 m away mid-firefight, shot running).
		-- He fights where he is; Combat's fire-and-movement moves him in short bounds. The plan resumes once it's quiet
		if sq.human and not veh and C.UnderFireHold and sq.pos and Dist(sq.pos, d) > (C.UnderFireMaxMove or 600)
			and (SeenNear(sq.pos, C.UnderFireHold) or S.t - (sq.lastContact or -1e9) < 15) then
			S.stat.heldFire = (S.stat.heldFire or 0) + 1
			return
		end
		-- otask / ophase: what the unit was last actually sent on
		local changed = sq.flag ~= flagName or sq.otask ~= task or sq.ophase ~= phase or sq.resend or (veh and sq.dest and Dist(sq.dest, d) > (C.VehFollow or 400) and S.t - sq.orderT > 10)
		if not changed and (sq.coveredAt or (S.t - sq.orderT) <= C.ReorderPeriod) then return end   -- dug in at his spot: leave him
		if changed and sq.flag and not sq.resend and (S.t - sq.orderT) < (C.RetargetMin or 15) then return end   -- no flip-flopping between plans
		sq.flag = flagName; sq.otask = task; sq.ophase = phase; sq.orderT = S.t; sq.resend = nil
		if sq.prone and SetPose(sq, 0, true) then
			-- he was put down: stand him up first, then send him a second later (a move right away could crawl)
			table.insert(S.later, { t = S.t + 1, sq = sq, d = d })
			sq.dest = d
			return
		end
		MoveUnit(sq, d)
		return
	end
	sq.task = task
	local reissue = (task == "attack" or task == "attack2" or task == "grab") and (S.t - sq.orderT) > C.ReorderPeriod
	if sq.flag ~= flagName or reissue then
		local ok, err = pcall(function() Api.Commands:CaptureFlag(sq.id, flagName) end)
		if not ok then Log("order failed for group " .. tostring(sq.id) .. " -> " .. tostring(flagName) .. ": " .. tostring(err)) end
		sq.flag = flagName; sq.orderT = S.t
	end
end

------------------------------------------------------------------ planning
local function NearestUnownedDist(p, unowned)
	local best = math.huge
	for _, u in ipairs(unowned) do local q = FlagPos(u.name); if q then local d = Dist(p, q); if d < best then best = d end end end
	return best
end

local function HoldNeed(f, nSquads, nOwned, unowned)
	if S.geo then
		local p = FlagPos(f.name)
		if p then
			local d = NearestUnownedDist(p, unowned) / S.geo.scale
			if d < C.FrontRange then if nSquads >= nOwned * 2 then return 2 else return 1 end end
			if d < C.MidRange then return 1 end
			if nSquads >= nOwned * 2 then return 1 end
			return 0
		end
	end
	if f.heat >= 1 and nSquads >= nOwned * 2 then return 2 end
	return 1
end

local function TargetScore(st, owned)
	local s = (st.owner == "none") and 3 or 2
	if S.t - st.lostAt < 120 then s = s + 3 end          -- counter-attack what we just lost before they dig in
	s = s - st.losses * 0.6                               -- where groups keep dying, try elsewhere
	if st.failUntil > S.t then s = s - 6 end
	local p = FlagPos(st.name)
	if p then
		local dmin = Dist(p, BasePos())
		for _, o in ipairs(owned) do local q = FlagPos(o.name); if q then local d = Dist(p, q); if d < dmin then dmin = d end end end
		s = s - 5 * dmin / S.geo.scale                                                   -- close to our ground
		s = s + 1.5 * (Dist(p, EnemyBasePos()) - Dist(p, BasePos())) / S.geo.scale      -- easier to hold
		local fv = IntelFlagValue and IntelFlagValue(st.name)
		if fv then s = s + (C.FlagValueWeight or 0) * fv / 100 end                       -- map intel: contested + defensible
		-- opening minutes: the flags human players went for first on this map, in their order (replays)
		if C.LearnOpenTime and S.t < C.LearnOpenTime then
			local rk, n = LearnedOpenRank(st.name)
			if rk then s = s + (C.LearnOpenWeight or 0) * (1 - (rk - 1) / math.max(1, n)) end
		end
		-- team games: a flag outside our part of the front belongs to a teammate
		local zo = ZoneOut(p)
		if zo > 0 then s = s - (C.ZoneOutPenalty or 4) - (C.ZoneOutPerWidth or 6) * zo / math.max(1, S.zone.w) end
	else
		s = s + (S.tie[st.name] or 0)
	end
	return s
end

local function Required(st)
	local base
	if st.owner == "none" then base = 2 + st.heat * 0.5
	else base = math.max(3, math.min(14, 4 + st.heat * 1.5 + st.losses * 0.5)) end
	-- director: enough to beat what is actually defending it
	if S.dir then base = math.max(base, (S.dir.near[st.name] or 0) * C.DirAttackRatio) end
	return base
end

local function StagingFor(target, owned)
	local p = FlagPos(target.name); if not p then return nil end
	local best, bd = nil, math.min(Dist(p, BasePos()), S.geo.scale * 0.7)
	for _, o in ipairs(owned) do
		local q = FlagPos(o.name)
		if q then local d = Dist(p, q); if d < bd then best, bd = o.name, d end end
	end
	return best
end

local function Think()
	if S.mapTried < 10 and not S.geo and S.t >= 2 then
		S.mapTried = S.mapTried + 1
		local had = DetectMap()
		if had then S.mapTried = 99 end
		if S.geo and not S.side then S.side = GuessSide() end
	end
	UpdateFlags(); UpdateSquads()
	LoadIntel()
	if R then GeoFromPoints(); Director(); UpdateZone() end
	S.front = nil
	if R and S.geo then
		local pr = {}
		for _, sq in pairs(S.squads) do
			if sq.human and sq.pos and not sq.garrison and not Gun[sq.role] then local v = Prog(sq.pos); if v then table.insert(pr, v) end end
		end
		if #pr >= 5 then table.sort(pr); S.front = pr[math.max(1, math.floor(#pr * 0.9))] end
	end
	for _, f in pairs(S.flags) do f.losses = f.losses * 0.97; f.heat = f.heat * 0.997 end

	local owned, unowned, neutral = {}, {}, 0
	for _, st in pairs(S.flags) do
		if st.owner == "us" then table.insert(owned, st) else table.insert(unowned, st); if st.owner == "none" then neutral = neutral + 1 end end
	end
	-- screen points: ground in front of each held flag, toward the nearest flag we don't own
	S.screenFor = {}
	if R and S.geo then
		for _, f in ipairs(owned) do
			local p, best, bd = FlagPos(f.name), nil, math.huge
			if p then
				for _, u in ipairs(unowned) do local q = FlagPos(u.name); if q then local d = Dist(p, q); if d < bd then best, bd = q, d end end end
				if best then S.screenFor[f.name] = { p[1] + (best[1] - p[1]) * C.ScreenAt, p[2] + (best[2] - p[2]) * C.ScreenAt } end
			end
		end
	end
	local list, emps = {}, {}
	for _, sq in pairs(S.squads) do
		if sq.uid and Gun[sq.role] then table.insert(emps, sq) else table.insert(list, sq) end   -- gun and its crew
	end
	PlaceEmplacements(emps)
	table.sort(list, function(a, b) if a.born ~= b.born then return a.born < b.born end return tostring(a.id) < tostring(b.id) end)
	if #list == 0 then return end

	-- 0) flag roles and garrisons (DLL only): back flags near our base need just one man, who captures and stays;
	--    middle flags are the contested ones; "eback" flags are the enemy's back flags
	local cls = {}
	if R and S.geo then
		S.screenFor = {}      -- middle flags are held on the flag itself, not in front of it
		for _, st in pairs(S.flags) do
			local p = FlagPos(st.name)
			if p then
				local a, b = Dist(p, BasePos()), Dist(p, EnemyBasePos())
				local k = a / math.max(1, a + b)
				cls[st.name] = (k < C.BackShare) and "back" or ((k > 1 - C.BackShare) and "eback" or "mid")
			end
		end
		S.garrison = S.garrison or {}
		local garrisoned = {}
		local names = {}
		for name, c in pairs(cls) do if c == "back" and ZoneOut(FlagPos(name)) == 0 then table.insert(names, name) end end
		table.sort(names)
		for _, name in ipairs(names) do
			local g = S.garrison[name] and S.squads[S.garrison[name]]
			if not g then
				-- nearest soldier who is not guarding a flag yet (plain infantry preferred)
				local p, best, bs = FlagPos(name), nil, nil
				for _, sq in ipairs(list) do
					if sq.uid and sq.human and not sq.garrison and sq.pos then
						local sc = Dist(sq.pos, p) / S.geo.scale + ((sq.role == "inf") and 0 or 0.6)
						if not bs or sc < bs then best, bs = sq, sc end
					end
				end
				if best then
					S.garrison[name] = best.id; best.garrison = name; g = best
					Log(string.format("garrison: unit %s (%s) guards back flag %s", tostring(best.uid), best.role, name))
				end
			end
			if g then garrisoned[g.id] = true; Order(g, name, "garrison") end
		end
		local rest = {}
		for _, sq in ipairs(list) do if not garrisoned[sq.id] then table.insert(rest, sq) end end
		list = rest
		if #list == 0 then return end
	end
	S.cls = cls

	-- 1) holders: groups already sitting on a held flag stay, up to what that flag needs (best holders first)
	-- needs and caps are in strength (1 = four soldiers), so they work however finely squads are split
	local total = 0
	for _, sq in ipairs(list) do total = total + Strength(sq) end
	local need, held = {}, {}
	local screening = R and C.Screen and S.geo
	for _, f in ipairs(owned) do
		need[f.name] = 0
		local c = cls[f.name]
		if c == "mid" then
			need[f.name] = math.max(C.MidHoldMin or 1, HoldNeed(f, total, #owned, unowned))   -- contested: keep men on it
		elseif c == "eback" then
			need[f.name] = 0.5                                                                   -- two men keep it ours
		elseif c == "back" then
			need[f.name] = 0                                                                     -- the garrison man holds it
		elseif C.HoldFlags or (screening and S.screenFor[f.name]) then
			need[f.name] = HoldNeed(f, total, #owned, unowned)
		end
		-- director: a flag the enemy is on or moving on gets enough holders to beat them (back flags too)
		if S.dir then
			local threat = (S.dir.near[f.name] or 0) + 0.5 * (S.dir.approach[f.name] or 0)
			if threat > 0 then need[f.name] = math.max(need[f.name], threat * C.DirDefendRatio) end
		end
		if ZoneOut(FlagPos(f.name)) > 0 then   -- a teammate's flag: help only against a real threat
			local threat = S.dir and ((S.dir.near[f.name] or 0) + 0.5 * (S.dir.approach[f.name] or 0)) or 0
			need[f.name] = threat * C.DirDefendRatio * (C.ZoneHelpShare or 0.4)
		end
	end
	local byPref = {}
	for _, sq in ipairs(list) do table.insert(byPref, sq) end
	table.sort(byPref, function(a, b) local pa, pb = BotHoldPref[a.role] or 3, BotHoldPref[b.role] or 3; if pa ~= pb then return pa > pb end return a.born < b.born end)
	local holders, maxHold = 0, math.max(1, total * C.HoldMaxShare)
	local free = {}
	for _, sq in ipairs(byPref) do
		local f = sq.flag and S.flags[sq.flag]
		if f and f.owner == "us" and (held[f.name] or 0) < (need[f.name] or 0) and holders < maxHold then
			held[f.name] = (held[f.name] or 0) + Strength(sq); holders = holders + Strength(sq)
			Order(sq, f.name, "hold")
		else
			sq.isFree = true; table.insert(free, sq)
		end
	end
	-- 2) fill flags that still lack holders with free groups that are not in the middle of an attack (nearest first)
	table.sort(owned, function(a, b) return (need[a.name] or 0) > (need[b.name] or 0) end)
	for _, f in ipairs(owned) do
		while (held[f.name] or 0) < (need[f.name] or 0) and holders < maxHold do
			local p, best, bs = FlagPos(f.name), nil, -math.huge
			for _, sq in ipairs(free) do
				if sq.isFree and sq.task ~= "attack" and sq.task ~= "attack2" then
					local sc = (BotHoldPref[sq.role] or 3)
					if p then local q = SquadPos(sq); if q then sc = sc - 4 * Dist(p, q) / S.geo.scale end end
					if sc > bs then best, bs = sq, sc end
				end
			end
			if not best then break end
			best.isFree = false; held[f.name] = (held[f.name] or 0) + Strength(best); holders = holders + Strength(best)
			Order(best, f.name, "hold")
		end
	end
	local pool = {}
	for _, sq in ipairs(free) do if sq.isFree then table.insert(pool, sq) end; sq.isFree = nil end
	if #pool == 0 then return end

	-- 3) everything else attacks
	local targets = {}
	for _, st in ipairs(unowned) do
		local c = cls[st.name]
		-- our own back flags are the garrison men's job, unless the enemy has taken one
		if c ~= "back" or st.owner == "them" then
			local s = TargetScore(st, owned)
			if c == "mid" then s = s + 3 end        -- the middle is where the game is decided
			if S.dir then s = s - (S.dir.near[st.name] or 0) * C.DirAvoid end   -- director: hit them where they are weak
			table.insert(targets, { st = st, s = s })
		end
	end
	table.sort(targets, function(a, b) return a.s > b.s end)
	-- team games: never far outside our part of the front (a flag at most half a slice past our edge, to help a neighbour)
	if S.zone and R and S.geo then
		local keep = {}
		for _, tg in ipairs(targets) do if ZoneOut(FlagPos(tg.st.name)) <= S.zone.w * (C.ZoneHelpReach or 0.5) then table.insert(keep, tg) end end
		if #keep < #targets then S.stat.zoneSkip = (S.stat.zoneSkip or 0) + (#targets - #keep) end
		targets = keep
	end
	if #targets == 0 then
		if R and S.geo and #owned > 0 then
			-- we hold every flag: spare units take the ground in front of the flags nearest the enemy base
			local front = {}
			for _, f in ipairs(owned) do table.insert(front, f) end
			table.sort(front, function(a, b) return Dist(FlagPos(a.name) or BasePos(), EnemyBasePos()) + 3 * ZoneOut(FlagPos(a.name)) < Dist(FlagPos(b.name) or BasePos(), EnemyBasePos()) + 3 * ZoneOut(FlagPos(b.name)) end)
			local eb = EnemyBasePos()
			for i = 1, math.min(#front, 2) do
				local p = FlagPos(front[i].name)
				if p then S.screenFor[front[i].name] = { p[1] + (eb[1] - p[1]) * C.ScreenAt * 0.6, p[2] + (eb[2] - p[2]) * C.ScreenAt * 0.6 } end
			end
			for i, sq in ipairs(pool) do Order(sq, front[((sq.uid or i) % math.min(#front, 2)) + 1].name, "hold") end
			return
		end
		if not C.HoldFlags then return end
		-- we hold every flag: stack the spare groups on the flags nearest the enemy
		local front = owned
		if S.geo then table.sort(front, function(a, b) return Dist(FlagPos(a.name) or BasePos(), EnemyBasePos()) < Dist(FlagPos(b.name) or BasePos(), EnemyBasePos()) end) end
		for i, sq in ipairs(pool) do Order(sq, front[((i - 1) % math.min(#front, 3)) + 1].name, "hold") end
		return
	end

	-- opening land grab: spread over the best neutral flags, a couple of groups each
	if not R and S.t < C.LandGrabTime and neutral > 0 then
		local cnt = {}
		for _, sq in ipairs(pool) do
			local f = sq.flag and S.flags[sq.flag]
			if sq.task == "grab" and f and f.owner ~= "us" and (cnt[f.name] or 0) < C.GrabPerFlag then cnt[f.name] = (cnt[f.name] or 0) + Strength(sq); sq.keep = true end
		end
		for _, sq in ipairs(pool) do
			if sq.keep then sq.keep = nil; Order(sq, sq.flag, "grab")
			else
				local best, bs = nil, -math.huge
				local q = SquadPos(sq)
				for _, tg in ipairs(targets) do
					if (cnt[tg.st.name] or 0) < C.GrabPerFlag then
						local sc = tg.s
						local p = FlagPos(tg.st.name)
						if p and q then sc = sc - 3 * Dist(p, q) / S.geo.scale end
						if sc > bs then best, bs = tg.st, sc end
					end
				end
				best = best or targets[1].st
				cnt[best.name] = (cnt[best.name] or 0) + Strength(sq)
				Order(sq, best.name, "grab")
			end
		end
		return
	end

	-- weakness check: each vehicle picks the target flag the enemy has (almost) no anti-tank near and goes for it
	if C.Exploit and S.atNear then
		local rest = {}
		for _, sq in ipairs(pool) do
			if sq.uid and not sq.human and (sq.role == "light" or sq.role == "tank" or sq.role == "heavy") then
				local best, bs = nil, math.huge
				for _, tg in ipairs(targets) do
					local a = S.atNear[tg.st.name] or 0
					if a <= C.ExploitMaxAT then
						local s = a * 10 - tg.s
						if s < bs then best, bs = tg.st, s end
					end
				end
				if best then
					if not sq.exploit or sq.exploitFlag ~= best.name then Log(string.format("vehicle %s (%s) -> %s: no enemy anti-tank there", tostring(sq.uid), sq.unit or "?", best.name)) end
					sq.exploit = true; sq.exploitFlag = best.name
					Order(sq, best.name, "attack")
				else
					sq.exploit = nil; sq.exploitFlag = nil
					table.insert(rest, sq)
				end
			else
				table.insert(rest, sq)
			end
		end
		pool = rest
		if #pool == 0 then return end
	end

	-- main target, kept until taken, failed, or something clearly better shows up
	local prim = S.primary and S.flags[S.primary]
	local primScore = nil
	for _, tg in ipairs(targets) do if prim and tg.st == prim then primScore = tg.s end end
	local function NewWave(st)
		S.waveId = S.waveId + 1
		S.primary = st.name
		S.wave = { id = S.waveId, target = st.name, staging = C.StageAtOwnFlags and StagingFor(st, owned) or nil, launched = false, created = S.t, req = Required(st) }
		-- with the DLL: gather on open ground short of the target, on the line from our nearest flag (or base)
		local tp = R and S.geo and st.owner == "them" and FlagPos(st.name)   -- neutral flags: go straight in, no waiting
		if tp then
			local from, fd = BasePos(), Dist(tp, BasePos())
			for _, o in ipairs(owned) do local q = FlagPos(o.name); if q and Dist(tp, q) < fd then from, fd = q, Dist(tp, q) end end
			if fd > C.StageBack + 60 then
				local k = C.StageBack / fd
				S.wave.stagePt = { tp[1] + (from[1] - tp[1]) * k, tp[2] + (from[2] - tp[2]) * k }
			end
		end
		Log(string.format("new attack #%d on %s (%s) need %.1f, staging %s", S.waveId, st.name, st.owner, S.wave.req, tostring(S.wave.staging)))
	end
	if not prim or prim.owner == "us" or not primScore then NewWave(targets[1].st)
	elseif targets[1].st ~= prim and targets[1].s > primScore + C.SwitchMargin and not S.wave.launched then NewWave(targets[1].st) end
	local W = S.wave
	local target = S.flags[W.target]
	if S.dir and not W.launched and target then W.req = Required(target) end   -- director: defenders change while we gather
	if W.staging and (not S.flags[W.staging] or S.flags[W.staging].owner ~= "us") then W.staging = C.StageAtOwnFlags and StagingFor(target, owned) or nil end

	local strength = 0
	for _, sq in ipairs(pool) do strength = strength + Strength(sq) end
	if W.launched then
		if S.t - W.launchedAt > C.WaveTimeout or strength < W.req * 0.35 then
			target.failUntil = S.t + 240
			Log(string.format("attack #%d on %s called off (strength %.1f, %ds)", W.id, W.target, strength, S.t - W.launchedAt))
			NewWave((targets[1].st ~= target or #targets == 1) and targets[1].st or targets[2].st)
			W = S.wave; target = S.flags[W.target]
		end
	end
	if not W.launched and ((not W.staging and not W.stagePt) or strength >= W.req or (S.t - W.created > C.GatherMax and strength >= W.req * (C.LaunchShare or 0.5)) or (S.t - W.created > C.GatherMax * 2 and strength >= W.req * 0.5) or S.t - W.created > C.GatherMax * 4) then
		W.launched = true; W.launchedAt = S.t; W.full = strength >= W.req * (C.FullForce or 1.5)
		Log(string.format("attack #%d launched on %s with %d groups (strength %.1f / %.1f)", W.id, W.target, #pool, strength, W.req))
	end

	-- split: what is beyond 1.6x the requirement goes to the second-best target (pressure on two points)
	local second = nil
	for _, tg in ipairs(targets) do if tg.st.name ~= W.target then second = tg.st; break end end
	local mainShare = W.req * 1.6
	table.sort(pool, function(a, b)
		local ka = (a.flag == W.target or a.flag == W.staging) and 0 or 1
		local kb = (b.flag == W.target or b.flag == W.staging) and 0 or 1
		if ka ~= kb then return ka < kb end
		return a.born < b.born
	end)
	local acc = 0
	for _, sq in ipairs(pool) do
		if second and W.launched and acc >= mainShare and strength - acc >= Required(second) * 0.8 then
			Order(sq, second.name, "attack2")
		elseif W.launched then
			acc = acc + Strength(sq); Order(sq, W.target, "attack")
		else
			acc = acc + Strength(sq)
			if sq.uid and W.stagePt then Order(sq, W.target, "gather") else Order(sq, W.staging, "gather") end
		end
	end
end

------------------------------------------------------------------ buying
local function Allowed(u)
	if not S.years or #u.y == 0 then return true end
	for _, y in ipairs(u.y) do if S.years[y] then return true end end
	return false
end

-- with the DLL: what the game itself says about a unit right now -> buyable at all?, seconds until it comes out, why not
local cdCache, cdCacheT = {}, -1
local function Ready(u)
	if not R or not R.Cooldown then return true, 0 end
	if cdCacheT ~= S.t then cdCache = {}; cdCacheT = S.t end
	local c = cdCache[u.n]
	if not c then
		local ok, rem, per, avail, hidden, unlocked = pcall(R.Cooldown, u.n)
		if not ok then c = { ok = true, rem = 0 }                                -- call failed: fall back to the old way
		elseif rem == nil then c = { ok = false, why = "no such unit" }
		elseif not avail then c = { ok = false, why = "not in this army's set" }
		elseif hidden then c = { ok = false, why = "another unit of its button has the turn" }
		else c = { ok = true, rem = math.max(0, rem) } end
		if ok and rem ~= nil and not unlocked and not S.loggedRank then S.loggedRank = true; Log("note: game reports " .. u.n .. " as rank-locked for this bot (ignored)") end
		cdCache[u.n] = c
	end
	return c.ok, c.rem or 0, c.why
end
-- planned only when it comes out within BuyLead seconds (vehicles are not saved for long before they exist)
local function ReadySoon(u)
	local ok, rem = Ready(u)
	return ok and rem <= (C.BuyLead or 30)
end

local function UpdateYears(u)
	if #u.y == 0 then return end
	local nxt = {}
	local any = false
	for _, y in ipairs(u.y) do if not S.years or S.years[y] then nxt[y] = true; any = true end end
	if not any then nxt = {}; for _, y in ipairs(u.y) do nxt[y] = true end end
	S.years = nxt
end

-- one-man purchases (an AT soldier, a sniper, an officer...): throttled so spare money goes into squads, not a stream
-- of lone soldiers
local function IsSingle(u)
	if IsCrewed(u.r) then return false end
	local m = S.men[u.n]
	if m then return m <= (C.SingleMen or 1) end
	return (u.c or 999) <= C.SingleGuessCost
end
local function SingleOk(u)
	if not C.SingleGap or not IsSingle(u) then return true end
	if S.t - S.lastSingleT < C.SingleGap then return false end
	if S.t - (S.singleT[u.n] or -1e9) < C.SingleSameGap then return false end
	local singles, soldiers = 0, 0
	for _, sq in pairs(S.squads) do
		if sq.human ~= false and not IsCrewed(sq.role) then
			soldiers = soldiers + 1
			if sq.info and sq.info.n and S.men[sq.info.n] and S.men[sq.info.n] <= (C.SingleMen or 1) then singles = singles + 1 end
		end
	end
	return singles < math.max(3, soldiers * C.SingleShare)
end

-- at most EmplaceMax emplacements alive or on order at once
local function EmplaceOk(u) if u.r == "emplace" and C.BuyEmplacements == false then return false end
	if S.gunsStuck and (u.r == "emplace" or u.r == "atgun") then return false end
	if u.r == "atgun" and C.BuyAtGuns == false then return false end
	if u.r == "light" and C.LightUntil and S.t >= C.LightUntil then
		local n = string.lower(u.n or "")
		for _, p in ipairs(C.JeepNames or {}) do if string.find(n, p, 1, true) then return false end end
	end return u.r ~= "emplace" or EmplaceCount() < (C.EmplaceMax or 4) end

local function TargetComp()
	local base = (S.t < 300) and BotComposition.early or ((S.t < 900) and BotComposition.mid or BotComposition.late)
	local comp, total = {}, 0
	for r, v in pairs(base) do comp[r] = v end
	if S.dir then
		-- director: counter what the enemy actually has. Anti-tank grows with their vehicle share, machine guns with their infantry
		local d = S.dir
		local arm = d.armour or d.veh
		local vehShare = d.total > 0 and (arm * 2.0) / d.total or 0
		if arm > 0 then
			local k = math.min(2.5, 0.5 + vehShare * 3)
			for r, v in pairs(BotComposition.antiTank) do if r ~= "td" or S.t >= (C.TDAfter or 600) then comp[r] = (comp[r] or 0) + v * k end end
			if arm >= 3 and S.t >= (C.TDAfter or 600) then comp.td = (comp.td or 0) + 0.04 * math.min(3, arm / 3) end
		end
		if arm > 0 and comp.light then
			local moved = comp.light * (C.LightWhenArmour or 0.5)
			comp.light = comp.light - moved
			comp.tank = (comp.tank or 0) + moved * 0.6
			comp.atinf = (comp.atinf or 0) + moved * 0.4
		end
		if d.inf >= 15 and vehShare < 0.3 then comp.support = (comp.support or 0) + 0.08 end
	elseif S.enemyTanks and S.t >= 180 then
		for r, v in pairs(BotComposition.antiTank) do comp[r] = (comp[r] or 0) + v end
	end
	if S.enemyWeakAT and S.t >= (C.ExploitAfter or 120) then
		comp.light = (comp.light or 0) + (C.ExploitLight or 0.2)
		if S.t >= 300 then comp.tank = (comp.tank or 0) + (C.ExploitTank or 0.1) end
	end
	local g = BotGuide and BotGuide[S.armyName]
	if g and g.comp then for r, k in pairs(g.comp) do if comp[r] then comp[r] = comp[r] * k end end end
	for _, v in pairs(comp) do total = total + v end
	for r, v in pairs(comp) do comp[r] = v / total end
	return comp
end

-- faction guide weight of a unit (1 = no opinion, 0 = never buy)
local function GuideW(u)
	local g = BotGuide and BotGuide[S.armyName]
	local w = g and g.w and g.w[u.n]
	if w then return w end
	local n = string.lower(u.n or "")
	for _, p in ipairs(C.WeakInfantry or {}) do if string.find(n, p, 1, true) then return C.WeakInfantryW or 0.1 end end
	if u.r == "inf" or u.r == "support" then
		for _, p in ipairs(C.GoodInfantry or {}) do if string.find(n, p, 1, true) then return C.GoodInfantryW or 1.6 end end
	end
	return 1
end

-- guide must-haves: how many of these names are alive or on order (a split purchase counts once)
local function OwnedOf(set)
	local n, seen = 0, {}
	for _, sq in pairs(S.squads) do if sq.info and set[sq.info.n] and not seen[sq.info] then seen[sq.info] = true; n = n + 1 end end
	for _, q in ipairs(S.queue) do if set[q.n] and not seen[q] then seen[q] = true; n = n + 1 end end
	-- just arrived: out of the queue but its soldiers aren't registered yet
	for _, q in ipairs(S.recentArr or {}) do if set[q.n] and not seen[q] and S.t - (q.arrivedT or -99) <= 8 then seen[q] = true; n = n + 1 end end
	return n
end

local function MustHave(ok)
	local g = BotGuide and BotGuide[S.armyName]
	if not (g and g.must and S.armyIdx) then return nil end
	for _, m in ipairs(g.must) do
		if S.t >= (m.after or 0) then
			m.set = m.set or {}
			for _, n in ipairs(m.names) do m.set[n] = true end
			if OwnedOf(m.set) < (m.count or 1) then
				for _, n in ipairs(m.names) do
					local u = S.armyIdx[n]
					if u and ok(u) then return u end
				end
			end
		end
	end
	return nil
end

local function CurrentComp()
	local comp, total = {}, 0
	local function add(r, c) comp[r] = (comp[r] or 0) + c; total = total + c end
	local seen = {}   -- a purchase split into several groups counts once
	for _, sq in pairs(S.squads) do if not seen[sq.info] then seen[sq.info] = true; add(sq.role, sq.info.c or 150) end end
	for _, q in ipairs(S.queue) do add(q.r, q.c) end
	if total > 0 then for r, v in pairs(comp) do comp[r] = v / total end end
	return comp
end

local function PickWant()
	local function ok(u) return GuideW(u) > 0 and Allowed(u) and (S.cool[u.n] or -1) <= S.t and ReadySoon(u) and SingleOk(u) and EmplaceOk(u) end
	local must = MustHave(ok)
	if must then
		if S.lastMust ~= must.n then S.lastMust = must.n; Log("guide must-have: " .. must.n) end
		return { u = must, since = S.t }
	end
	-- enemy armour on the field: keep enough anti-tank to deal with it. Early on that means the cheap, quick things
	-- (AT rifles, bazookas, light AT guns) so a light tank can't run riot; tank destroyers only later
	if C.AtReact and S.firstEnemyVehT and S.t - S.firstEnemyVehT >= C.AtReact and S.dir and (S.dir.armour or S.dir.veh) > 0 then
		local have = 0
		for _, sq in pairs(S.squads) do
			if sq.role == "atgun" or sq.role == "td" then have = have + 2
			elseif sq.human and (sq.role == "atinf" or sq.atr) then have = have + 1 end
		end
		for _, q in ipairs(S.queue) do if q.r == "atgun" or q.r == "td" then have = have + 2 elseif q.r == "atinf" then have = have + 1 end end
		local need = math.min(C.AtNeedMax or 8, 1 + 2 * (S.dir.armour or S.dir.veh))
		if have < need then
			local late = S.t >= (C.TDAfter or 600)
			local cands = {}
			for _, u in ipairs(S.army) do
				local fits = u.r == "atinf" or (u.r == "atgun" and (late or u.c <= (C.AtCheapMax or 350))) or (u.r == "td" and late)
				if fits and ok(u) then table.insert(cands, u) end
			end
			if #cands > 0 then
				table.sort(cands, function(a, b) return a.c / GuideW(a) < b.c / GuideW(b) end)
				local u = cands[math.min(#cands, math.random(1, 3))]
				if S.lastAtReact ~= u.n then S.lastAtReact = u.n; Log(string.format("enemy armour (%d): anti-tank %d/%d, buying %s", S.dir.armour or S.dir.veh, have, need, u.n)) end
				return { u = u, since = S.t }
			end
		end
	end
	local target, cur = TargetComp(), CurrentComp()
	local roleC, bestDef, bestRole = nil, nil, nil
	for role, share in pairs(target) do
		local cands = {}
		for _, u in ipairs(S.army) do if u.r == role and ok(u) then table.insert(cands, u) end end
		if #cands > 0 then
			local def = share - (cur[role] or 0) + math.random() * 0.03
			if not bestDef or def > bestDef then bestDef, bestRole, roleC = def, role, cands end
		end
	end
	if not roleC then
		roleC = {}
		for _, u in ipairs(S.army) do if ok(u) then table.insert(roleC, u) end end
		if #roleC == 0 then return nil end
	end
	-- early on prefer the cheaper end of the role, later the better (pricier) end; the faction guide tilts it
	table.sort(roleC, function(a, b) return a.c < b.c end)
	local pct = math.min(0.85, (C.QualityStart or 0.25) + S.t / 1800 * 0.55)
	local centre, spread = pct * (#roleC - 1), #roleC * 0.25 + 1
	local total, w = 0, {}
	for i, u in ipairs(roleC) do local z = (i - 1 - centre) / spread; w[i] = math.exp(-z * z) * GuideW(u) ^ 1.5; total = total + w[i] end
	local r, acc = math.random() * total, 0
	for i, u in ipairs(roleC) do acc = acc + w[i]; if r <= acc then return { u = u, since = S.t } end end
	return { u = roleC[#roleC], since = S.t }
end

-- game.log size now, so we can read only what the game writes after an order
local function GameLogPos()
	if not S.logDir then return nil end
	local f = io.open(S.logDir .. "game.log", "r"); if not f then return nil end
	local pos = f:seek("end"); f:close(); return pos
end

-- what did the game log while we called Spawn? "ok" (it logged "SpawnUnit <name>"), "missing" (it logged
-- "Not found - <name>", or logged nothing once we know logging works), or nil (can't tell)
local function SpawnVerdict(pos, name)
	if not pos then return nil end
	local f = io.open(S.logDir .. "game.log", "r"); if not f then return nil end
	f:seek("set", pos); local txt = f:read("*a") or ""; f:close()
	if string.find(txt, "SpawnUnit " .. name, 1, true) then S.logWorks = true; return "ok" end
	if string.find(txt, "Not found - " .. name, 1, true) then return "missing" end
	if S.logWorks then return "missing" end
	return nil
end

-- orders that never arrived: the unit doesn't exist for this army/year, so skip it for a long time
local function PurgeQueue()
	local keep = {}
	for _, q in ipairs(S.queue) do
		local age = S.t - q.t
		if not q.confirmed and age > C.ArrivalTimeout then
			S.fails[q.n] = (S.fails[q.n] or 0) + 1
			S.cool[q.n] = S.t + 1800
			Log("never arrived, skipping: " .. q.n)
		elseif q.confirmed and age > 240 then
			-- bought for sure but its groups never got matched to it; just forget it
		else
			table.insert(keep, q)
		end
	end
	S.queue = keep
end

-- a purchase arrived: it is real, so learn the year from it
local function Arrived(q)
	if q.arrived then return end
	q.arrived = true
	q.arrivedT = S.t
	S.recentArr = S.recentArr or {}
	table.insert(S.recentArr, q); if #S.recentArr > 8 then table.remove(S.recentArr, 1) end
	S.bought = S.bought + 1; S.firstBuy = true; S.fails[q.n] = 0
	UpdateYears(q.u)
	-- a cheaper unit that kept failing just before this one went through was not a money problem: it is not buyable here
	for name, ft in pairs(q.failed or {}) do
		if q.t - ft.t < 60 and ft.c <= q.c and name ~= q.n then S.cool[name] = S.t + 900; Log("not buyable here: " .. name) end
	end
	Log(string.format("arrived %s after %ds", q.n, S.t - q.t))
end

-- place one order; returns "placed", "missing" (not in this game, skipped from now on) or "poor" (can't afford yet / locked)
local function PlaceOrder(u, since)
	local logPos = nil
	pcall(function() logPos = GameLogPos() end)
	local split = IsCrewed(u.r) and (C.VehicleSplit or 6) or (C.InfantrySplit or 4)
	if not Api.Commands:Spawn(u.n, split) then return "poor" end
	-- the game also says yes to units it can't find, so check what it logged
	local verdict = nil
	pcall(function() verdict = SpawnVerdict(logPos, u.n) end)
	if verdict == "missing" then
		S.cool[u.n] = S.t + 1800
		Log(string.format("not available here: %s (%s)", u.n, u.r))
		return "missing"
	end
	table.insert(S.queue, { r = u.r, n = u.n, c = u.c, t = S.t, u = u, failed = S.failedRecently, confirmed = (verdict == "ok"), got = 0 })
	S.failedRecently = {}
	if IsSingle(u) then S.lastSingleT = S.t; S.singleT[u.n] = S.t end
	-- the same vehicle type not again for a while: a mix of light tanks and armoured cars, not five BA-64s
	local gap = C.SameUnitGap and C.SameUnitGap[u.r]
	if gap then S.cool[u.n] = math.max(S.cool[u.n] or -1, S.t + gap) end
	Log(string.format("ordered %s (%s, %d)%s%s", u.n, u.r, math.floor(u.c), since and string.format(" after %ds", S.t - since) or " (instead)", verdict == "ok" and "" or " (unconfirmed)"))
	return "placed"
end

-- other things worth buying right now: roles by how much the army lacks them, cheapest first inside a role
local function Alternatives(skip)
	local target, cur = TargetComp(), CurrentComp()
	local roles = {}
	for role, share in pairs(target) do table.insert(roles, { r = role, d = share - (cur[role] or 0) }) end
	table.sort(roles, function(a, b) return a.d > b.d end)
	local out = {}
	for _, ro in ipairs(roles) do
		local cands = {}
		for _, u in ipairs(S.army) do
			if u.r == ro.r and u.n ~= skip and GuideW(u) > 0 and Allowed(u) and (S.cool[u.n] or -1) <= S.t and SingleOk(u) and EmplaceOk(u) then
				local ok, rem = Ready(u)
				if ok and rem <= 0 then table.insert(cands, u) end      -- alternatives must be buyable right now
			end
		end
		-- cheapest first, but a unit the guide likes counts as cheaper
		table.sort(cands, function(a, b) return a.c / GuideW(a) < b.c / GuideW(b) end)
		for i = 1, math.min(2, #cands) do table.insert(out, cands[i]) end
	end
	return out
end

local function TryBuy()
	if not S.army then return end
	PurgeQueue()
	-- at most 2 orders we are unsure about at a time (keeps a run of "not found" units from piling up)
	local unsure = 0
	for _, q in ipairs(S.queue) do if not q.confirmed then unsure = unsure + 1 end end
	if unsure >= 2 then return end
	if not S.want then S.want = PickWant(); if not S.want then return end end
	local w = S.want
	local wok, wrem, why = Ready(w.u)
	if not wok then
		Log("dropping " .. w.u.n .. ": " .. tostring(why)); S.cool[w.u.n] = S.t + 120; S.want = nil; return
	end
	local r = "poor"
	if wrem <= 0 then r = PlaceOrder(w.u, w.since) end
	if r ~= "poor" then S.want = nil; return end
	-- can't buy the preferred unit yet: save for it if it's a vehicle or an emplacement and we already have a few
	-- soldiers on the field (buying cheap infantry every second would never let the money build up)
	local soldiers = 0
	for _, sq in pairs(S.squads) do if sq.human ~= false then soldiers = soldiers + 1 end end
	local saveable = IsCrewed(w.u.r)
	local saving = C.SaveForVehicles and saveable and soldiers >= C.SaveMinGroups and S.t - w.since < C.SaveMaxTime
	if R and wrem > 0 then saving = saveable end   -- comes out within BuyLead s: keep the money for it
	if saving then S.stat.saving = (S.stat.saving or 0) + 1 end
	-- saving for a tank still lets a cheap infantry squad through now and then (they stopped buying infantry once
	-- tanks came out)
	if saving and C.SaveAltGap and S.t - (S.lastAltT or -1e9) >= C.SaveAltGap then
		for _, u in ipairs(Alternatives(w.u.n)) do
			if (u.r == "inf" or u.r == "atinf" or u.r == "support") and u.c <= (C.SaveAltMaxCost or 220) then
				if PlaceOrder(u, nil) == "placed" then S.lastAltT = S.t end
				break
			end
		end
	end
	if not saving and S.t - (S.lastAltT or -1e9) >= (C.AltGap or 0) then
		-- buy something else we can afford right now (not more often than AltGap: fewer, bigger purchases)
		local tries = 0
		for _, u in ipairs(Alternatives(w.u.n)) do
			if tries >= C.AltTriesPerSecond then break end
			tries = tries + 1
			local r2 = PlaceOrder(u, nil)
			if r2 == "placed" then S.lastAltT = S.t; break end
		end
	end
	-- give up on the preferred unit after a while (it may be locked or too expensive) and pick again
	local wait = S.firstBuy and (C.BuyWaitBase + w.u.c * C.BuyWaitPerCost) or C.ProbeWait
	if R then wait = wait + wrem end   -- don't give up on a unit just because it isn't out yet
	if C.SaveForVehicles and IsCrewed(w.u.r) then wait = math.max(wait, C.SaveMaxTime + 5) end   -- saved for it: give it the whole window
	if S.want and S.t - w.since > wait then
		local n = (S.fails[w.u.n] or 0) + 1
		if IsCrewed(w.u.r) and S.firstBuy then n = 1 end    -- probably just money: don't lock a vehicle out for long
		S.fails[w.u.n] = n
		S.cool[w.u.n] = S.t + math.min(C.CooldownMax, C.CooldownBase * n)
		S.failedRecently[w.u.n] = { t = S.t, c = w.u.c }
		Log(string.format("gave up on %s (%s, %d) for now", w.u.n, w.u.r, math.floor(w.u.c)))
		S.want = nil
	end
end
------------------------------------------------------------------ status
local function Report()
	local own, them, tot = 0, 0, 0
	for _, f in pairs(S.flags) do tot = tot + 1; if f.owner == "us" then own = own + 1 elseif f.owner == "them" then them = them + 1 end end
	local tasks = {}
	for _, sq in pairs(S.squads) do local k = sq.task or "new"; tasks[k] = (tasks[k] or 0) + 1 end
	local ts = {}
	for k, v in pairs(tasks) do table.insert(ts, k .. " " .. v) end
	local W = S.wave
	local msg = string.format("[AI %d:%02d] flags %d/%d (enemy %d) | groups %d: %s | %s | bought %d lost %d%s",
		math.floor(S.t / 60), S.t % 60, own, tot, them, Count(S.squads), table.concat(ts, ", "),
		W and string.format("attack %s %s", W.target, W.launched and "launched" or ("gathering at " .. tostring(W.staging))) or "no attack",
		S.bought, S.lost, S.want and (" | buying " .. S.want.u.n) or "")
	if R then
		local st = S.stat
		msg = msg .. string.format(" | dll: enemies seen %d, moves %d (run %d, slowed %d), AT orders %d, disbanded %d%s",
			#S.enemies, st.moves, st.runs, st.calm, st.atk, st.disband, st.badLayout > 0 and (", run flag skipped " .. st.badLayout) or "")
		local fighting = 0
		for _, sq in pairs(S.squads) do if sq.fight then fighting = fighting + 1 end end
		local digging, mgs = 0, 0
		local atrs, snps, emps = 0, 0, 0
		for _, sq in pairs(S.squads) do
			if sq.task == "dig" then digging = digging + 1 end
			if sq.mg then mgs = mgs + 1 elseif sq.atr then atrs = atrs + 1 elseif sq.ranged then snps = snps + 1 end
			if sq.role == "emplace" then emps = emps + 1 end
		end
		msg = msg .. string.format(" | combat: fighting now %d, engagements %d, into cover %d, prone %d, bounds %d, dug in at spot %d | dug-in line %d, sandbag walls %d, long-range men %d MG / %d AT rifle / %d sniper (fell back %d), emplacements %d",
			fighting, st.engaged, st.cover, st.prone, st.bound, st.spotCover, digging, st.built, mgs, atrs, snps, st.mgBack, emps)
		msg = msg .. string.format(" | grenades %d, smokes %d, sandbag cover %d, dig spots moved off buildings %d",
			st.grenades or 0, st.smoke or 0, st.bagCover or 0, st.digMoved or 0)
		msg = msg .. string.format(" | sandbags: %d men carry %d, walls where they stopped %d (MGs %d), MG nests built for gunners %d",
			S.bagMen or 0, S.bagTotal or 0, st.fortify or 0, st.mgWall or 0, st.mgNest or 0)
		msg = msg .. string.format(" | armour: hull turns %d (faced %d, gave up %d), attacks on infantry/MGs %d, drives at MGs %d | walked under MG/vehicle threat %d | moves pulled out of water/no-go %d | gunners at map firing positions %d (players' replay spots %d)",
			st.faced or 0, st.turnOk or 0, st.turnFail or 0, st.tankSoft or 0, st.tankSoftGo or 0, st.dangerWalk or 0, st.dry or 0, st.firePos or 0, st.firePosHuman or 0)
		if S.zone then
			msg = msg .. string.format(" | zone: player %d of %d, slice %d m, %d flag(s), targets skipped %d", S.zone.i, S.zone.n, math.floor(S.zone.w / 20), S.zone.flags or 0, st.zoneSkip or 0)
		end
		if S.dir then
			local hot = {}
			for name, v in pairs(S.dir.near) do if v >= 0.5 then table.insert(hot, string.format("%s %.1f", name, v)) end end
			table.sort(hot)
			msg = msg .. string.format(" | director: enemy %d inf %d veh; on flags: %s", S.dir.inf, S.dir.veh, #hot > 0 and table.concat(hot, ", ") or "none")
		end
	end
	Log(msg)
	if S.t >= S.nextReport then S.nextReport = S.t + C.ReportPeriod; Chat(msg) end
end

------------------------------------------------------------------ split test
-- Buys one 10-man squad per split value (each value twice), waits for its groups to arrive, and reports how many came.
local T = nil
local function SquadIds()
	local ids = {}
	for _, id in pairs(Api.Scene.Squads) do ids[id] = true end
	return ids
end
local function SplitTestStep()
	if not T then
		local plan = {}
		for _, v in ipairs(SplitTestValues) do table.insert(plan, v); table.insert(plan, v) end
		local cands = {}
		for _, n in ipairs((SplitTestUnits and SplitTestUnits[S.armyName]) or {}) do table.insert(cands, n) end
		local rest = {}
		for _, u in ipairs(S.army or {}) do if u.r == "inf" then table.insert(rest, u) end end
		table.sort(rest, function(a, b) return a.c < b.c end)
		for _, u in ipairs(rest) do table.insert(cands, u.n) end
		T = { plan = plan, step = 1, cands = cands, ci = 1, unit = nil, phase = "buy", tryT = S.t, results = {} }
		Log("SPLIT TEST start: " .. #plan .. " purchases, " .. #cands .. " candidate squads")
		Chat("[AI] split test started - please wait, the bot is buying test squads")
	end
	if T.phase == "done" then return true end
	local v = T.plan[T.step]
	if T.phase == "buy" then
		local name = T.unit or T.cands[T.ci]
		if not name then Log("SPLIT TEST: nothing could be bought"); T.phase = "done"; return true end
		local before = SquadIds()
		local ok = Api.Commands:Spawn(name, v)
		if ok then
			T.unit = name
			T.phase = "wait"; T.boughtT = S.t; T.events = 0; T.lastEvtT = nil; T.before = before
			Log(string.format("SPLIT TEST bought %s with value %d", name, v))
		elseif not T.unit and S.t - T.tryT >= 3 then
			T.ci = T.ci + 1; T.tryT = S.t        -- this squad is not buyable here, try the next candidate
		end
	elseif T.phase == "wait" then
		local quietFor = T.lastEvtT and (S.t - T.lastEvtT) or 0
		if (T.events > 0 and quietFor >= 10) or S.t - T.boughtT >= 90 then
			local now, newIds = SquadIds(), 0
			for id in pairs(now) do if not T.before[id] then newIds = newIds + 1 end end
			local line = string.format("SPLIT TEST value %d -> %d spawn events, %d new groups (%s)", v, T.events, newIds, T.unit)
			Log(line)
			table.insert(T.results, v .. "=" .. T.events)
			T.step = T.step + 1
			if T.step > #T.plan then
				T.phase = "done"
				Log("SPLIT TEST RESULT (value=groups): " .. table.concat(T.results, "  "))
				Chat("[AI] split test result (value=groups): " .. table.concat(T.results, "  "))
				return true
			end
			T.phase = "buy"
		end
	end
	return false
end

------------------------------------------------------------------ engine events
local function Beat()
	S.t = S.t + 1
	if C.SplitTest and not S.testDone then
		local done = false
		Safe("split test", function() done = SplitTestStep() end)
		if done then S.testDone = true end
		if S.t > 1200 then S.testDone = true; Log("SPLIT TEST timed out") end
		if not S.testDone then return end
	end
	Safe("buy", TryBuy)
	if R then
		Safe("new squads", ProcessPending)
		Safe("later moves", FlushLater)
		if S.t >= S.nextMicro then S.nextMicro = S.t + C.MicroPeriod; Safe("micro", Micro) end
	end
	if S.t >= S.nextThink then
		S.nextThink = S.t + C.ThinkPeriod
		Safe("think", Think)
	end
	if S.t % 30 == 0 then
		Safe("enemy tanks", function() S.enemyTanks = Api.Commands:EnemyHasTanks() and true or false end)
		Safe("report", Report)
	end
end

local function Arm()
	S.lastBeatReal = os.time()
	S.timer = Api.Events:SetQuantTimer(function()
		S.timer = nil
		if not S.running then return end
		S.lastBeatReal = os.time()
		Beat()
		Arm()
	end, 1000)
end

-- watchdog: if the 1-second timer ever dies, restart it
local function OnQuant()
	if S.running and S.lastBeatReal and os.time() - S.lastBeatReal > 5 then
		Log("heartbeat restarted")
		if S.timer then pcall(function() Api.Events:KillQuantTimer(S.timer) end); S.timer = nil end
		Arm()
	end
end

function OnGameStart()
	math.randomseed(os.time() * (Api.Instance.hostId or 1))
	math.random(); math.random(); math.random()
	S.running = true
	OpenLog()
	S.armyName = Api.Instance.army
	S.army = BotUnits[S.armyName]
	S.armyIdx = {}; for _, u in ipairs(S.army or {}) do S.armyIdx[u.n] = u end
	do local g = BotGuide and BotGuide[S.armyName]; local nw = 0; if g and g.w then for _ in pairs(g.w) do nw = nw + 1 end end; Log(string.format("faction guide: %s", g and string.format("%d unit weights, %d must-haves", nw, g.must and #g.must or 0) or "none")) end
	Log("Robz bot start: army=" .. tostring(S.armyName) .. " player=" .. tostring(Api.Instance.playerId) .. " team=" .. tostring(Api.Instance.team) .. " teamSize=" .. tostring(Api.Instance.teamSize))
	if not S.army then Log("no unit list for army " .. tostring(S.armyName)); Chat("[AI] no unit list for army " .. tostring(S.armyName)) end
	Safe("load dll", LoadRobz)
	Log("robzbot.dll: " .. RInfo)
	Chat("[AI] unit control dll: " .. (R and "ON" or "OFF") .. " - " .. RInfo)
	Arm()
end

function OnGameStop()
	S.running = false
	if S.timer then pcall(function() Api.Events:KillQuantTimer(S.timer) end) end
	Log("game over: bought " .. S.bought .. ", lost " .. S.lost .. ", script errors " .. S.errs)
	if S.logFile then pcall(function() S.logFile:close() end); S.logFile = nil end
end

function OnGameSpawn(args)
	local id = args and args.squadId
	if id == nil then return end
	local info
	local L = S.lastEvtInfo
	if L and S.t - S.lastEvtT <= 2 and (L.got or 0) < 2 and not IsVehicleRole(L.r) then
		info = L                      -- a squad arrives as up to 2 groups at once
	else
		info = table.remove(S.queue, 1)
	end
	if info then info.got = (info.got or 0) + 1; Arrived(info) end
	S.lastEvtT = S.t; S.lastEvtInfo = info
	if T and T.phase == "wait" then T.events = T.events + 1; T.lastEvtT = S.t end
	if R then
		S.pending[id] = { info = info or { r = "inf", n = "?", c = 150 }, t = S.t }
		Safe("new squads", ProcessPending)
		return
	end
	RegisterSquad(id, info)
end

Api.Events:Subscribe(Api.Events.GameStart, function() Safe("start", OnGameStart) end)
Api.Events:Subscribe(Api.Events.GameEnd, function() Safe("stop", OnGameStop) end)
Api.Events:Subscribe(Api.Events.GameSpawn, function(args) Safe("spawn", OnGameSpawn, args) end)
Api.Events:Subscribe(Api.Events.Quant, function() Safe("quant", OnQuant) end)
