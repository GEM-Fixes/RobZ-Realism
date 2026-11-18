-- Robz competitive bot settings. Times are in seconds.
BotConfig = {
	SplitTest      = false,  -- TEST: at the start, buy the same 10-man squad with different split values and report how many groups arrive (result: max 2)
	ArrivalTimeout = 75,     -- an order whose soldiers haven't arrived after this long is treated as "unit not found" and skipped
	Debug          = true,   -- writes robz_bot.log next to game.log and posts a short status in chat
	ReportPeriod   = 120,    -- seconds between chat status lines (Debug only)
	ThinkPeriod    = 2,      -- how often the bot re-plans
	RetargetMin    = 2,      -- a unit keeps a new order at least this long before it can be sent somewhere else

	InfantrySplit  = 1,      -- max soldiers per bot group for infantry: 1 = every soldier gets his own orders
	VehicleSplit   = 6,      -- vehicles keep vehicle + crew together (splitting the crew would pull them out of the vehicle)

	-- opening: spread out and grab neutral flags
	LandGrabTime   = 200,
	GrabPerFlag    = 2,

	-- holding flags
	HoldFlags      = false,  -- false: never send groups to flags our team already holds; everyone goes for neutral/enemy flags
	StageAtOwnFlags = false, -- true: attacks gather at the nearest held flag first (sends groups to held flags)
	HoldMaxShare   = 0.45,   -- at most this share of groups sit on flags (threatened flags ignore the cap)
	FrontRange     = 0.35,   -- a held flag is "front" if a flag we don't own is closer than this * base-to-base distance
	MidRange       = 0.60,

	-- attacking
	GatherMax      = 90,     -- after this long an attack launches with LaunchShare of the strength it wants...
	LaunchShare    = 0.8,    -- ...(it used to go with half, and lost men piecemeal)
	WaveTimeout    = 260,    -- an attack that has not taken its flag by then is called off
	SwitchMargin   = 2.0,    -- how much better another target must look before the bot changes its main target
	ReorderPeriod  = 150,    -- attackers get their order re-issued this often (unsticks them)

	-- buying: money is spent as soon as something useful is affordable
	AltTriesPerSecond = 4,   -- when the preferred unit can't be bought, try up to this many alternatives each second
	SaveForVehicles = true,  -- hold money for a wanted vehicle or emplacement instead of buying more infantry
	SaveMinGroups  = 40,     -- ...once at least this many soldiers are on the field
	SaveMaxTime    = 45,     -- ...for up to this many seconds (was 90: no infantry for 1.5 min per tank)
	SaveAltGap     = 25,     -- while saving, still buy one cheap infantry squad every 25 s
	SaveAltMaxCost = 220,
	SameUnitGap    = { light = 150, tank = 90, td = 90 },   -- the same vehicle type isn't bought again for this long (5 BA-64s in a row): mix T-60/T-70/BT/T-26
	EarlyPush      = 300,    -- first 5 min: light vehicles lead (no hanging back), lines assault sooner
	EarlyAssaultRatio = 0.7,
	EarlyLineMax   = 20,     -- infantry waits at most 20 s on the line before going in (later: LineMax)
	EarlyMaxDefenders = 2.5, -- ...even against a few defenders, to get a foothold
	-- light vehicles: closer in, but they back off from enemy anti-tank (AT soldiers, guns, tanks)
	VehMinAT       = { light = 2700, tank = 900, td = 1100, heavy = 800 },   -- planned spots stay this far from known enemy AT (light 135 m; tanks 45 m: out of panzerfaust/bazooka reach)
	LightFleeDist  = 1800,   -- enemy AT within 90 m of a light vehicle: it pulls back...
	LightFleeTo    = 2800,   -- ...to 140 m away
	LightFleeTime  = 10,
	-- tanks / TDs: keep the hull toward the target (turn on the spot with the v11 DLL), close in when out of range
	FaceTolTank    = 30,     -- degrees off before a tank turns
	FaceTolTD      = 12,     -- tank destroyers have little gun traverse
	FaceEvery      = 6,
	FaceWait       = 2,      -- while a hull turns, check again this often (no orders until it faces the target)
	TurnMax        = 10,     -- give a hull turn this long before firing as it stands
	TurnRetry      = 20,     -- ...and no new turn at that target for this long
	TankSoft       = true,   -- tanks / TDs with no armour to fight attack enemy MGs, then visible infantry
	TankSoftRange  = 2200,   -- 110 m
	TankSoftHold   = 12,
	TankAtSafe     = 900,    -- no drive up on an MG if enemy AT soldiers stand within 45 m of the stop
	DangerDist     = 2600,   -- soldiers walk (advance) instead of sprinting within 130 m of a known enemy MG or vehicle
	UseFirePos     = true,   -- map intel: MGs / snipers / AT rifles dig in (and support attacks) at the map's firing positions
	FlagValueWeight = 1.5,   -- map intel: attack-target bonus for the most valuable flag (contested + defensible), scaled 0-100
	LearnOpenTime  = 300,    -- replays: for the first 5 min, flags human players took first on this map get a bonus ...
	LearnOpenWeight = 2.5,   -- ... this much for their first pick, less down their order
	ApproachInside = 200,    -- drive to 10 m inside max range
	ApproachExtra  = 4000,   -- ...for enemy armour up to 200 m beyond it
	-- AT soldiers: AT rifles lie down before firing, bazooka/panzerschreck/panzerfaust crouch (they can't fire lying)
	AtPoses        = true,
	WreckIgnore    = 120,
	UnderFireHold  = 2400,   -- a soldier who sees an enemy within 120 m (or was hit in the last 15 s) gets no move longer than UnderFireMaxMove
	UnderFireMaxMove = 600,  -- 30 m (they were sent across the map mid-firefight and shot running)
	TankDirector   = true,   -- tanks/TDs aim at enemy armour the director knows of (turning to face it), not only armour in sight
	ProbeWait      = 4,      -- before the first purchase succeeds: try another unit after this long
	BuyWaitBase    = 25,     -- after that: wait this long + cost * BuyWaitPerCost for money before giving up on a unit
	BuyWaitPerCost = 0.07,
	CooldownBase   = 90,     -- a unit that could not be bought is skipped for CooldownBase * failures (max CooldownMax)
	CooldownMax    = 600,

	-- robzbot.dll (per-unit control). Without the DLL the bot plays the old squad-to-flag way.
	UseRobzDll     = true,
	RobzDllPaths   = { "mods/robz realism mod 1.30.10 godny implementation/robzbot.dll", "robzbot.dll" },
	DisbandSquads  = true,   -- break every infantry squad up on arrival (like pressing K); vehicles keep their crew
	-- distances are game units: 20 units = 1 metre
	Run            = true,   -- run when the destination is far and no enemy is close
	RunDist        = 400,    -- run only if the destination is farther than this (20 m). Replays: humans run ~56% of moves, the bot ran 11%
	CalmDist       = 1000,   -- any enemy this close to the unit: walk (50 m)
	CalmDestDist   = 600,    -- ...or this close to where he is going (30 m)
	CalmStop       = 700,    -- a running man stops running only when an enemy gets this close to him (35 m)
	-- stance: humans change stance ~2 times per 10 min; the bot did it 100+ times. The game crouches men under fire itself
	PoseGap        = 20,     -- seconds before the same soldier is given another stance order
	PoseRiflemen   = false,  -- false: only gunners (MG, AT rifle, sniper) are told to lie down; riflemen keep the game's own stance
	Screen         = true,   -- hold ground in front of our front-line flags instead of sitting on them
	ScreenAt       = 0.35,   -- ...this far from our flag toward the nearest flag we don't own
	StageBack      = 700,    -- attacks gather this far short of the target flag, on the ground between flags (35 m)
	MicroPeriod    = 2,      -- seconds between unit-level checks (combat reactions, anti-tank targeting)
	AtRange        = 1400,   -- anti-tank infantry / guns engage visible enemy vehicles within this range (70 m)
	TankRange      = 3000,   -- tanks engage visible enemy vehicles within this range (120 m; players fight armour at ~110 m)
	TDRange        = 3400,
	HurtFaceRange  = 4500,   -- a tank/TD that is being hit attacks (turns to face) the nearest known enemy vehicle or gun within 225 m   -- tank destroyers out to 170 m (players keep them 120-180 m from enemy armour)
	-- vehicles by class (replays, winning players): how far behind our own infantry front they stay, and the closest
	-- they let enemy infantry get. Light vehicles work just behind the riflemen; medium tanks stand off ~90 m behind;
	-- heavies come up close to their infantry; TDs sit back and snipe armour.
	VehBack        = { light = 200, tank = 500, td = 800, heavy = 400 },   -- 2026-11-02: tanks closer to the front (were 1200/1200/900)   -- (tank was 1800, td 1400: they sat behind walls at the back)
	VehClearShift  = 150,    -- a vehicle spot with no line of sight to the enemy (walls, houses) slides sideways in 7.5 m steps until it has one
	VehClearSteps  = 6,
	VehMinInf      = { light = 900, tank = 1200, td = 1400, heavy = 1000 },   -- (were 2000/1800/1500: tanks never reached enemy MGs)
	VehMinArmor    = { light = 2400, tank = 1600, td = 2200, heavy = 1200 },   -- and how close enemy vehicles may get
	FullForce      = 1.5,    -- an attack launched with this many times the strength it needs is "full force": vehicles drive in with it
	VehFollow      = 400,    -- a vehicle is re-sent when the front has moved its spot by more than 20 m
	-- attacks: infantry splits over three approaches (straight on, and each flank turned this many radians)
	AttackSpread   = 0.8,
	-- anti-tank: once enemy armour has been on the field this long with no AT gun / TD of ours, buy one (winners: ~3 min)
	AtReact        = 10,
	AtHuntRange    = 2600,   -- AT soldiers go after any enemy vehicle within 130 m that the director knows about, seen or not
	AtkHold        = 20,     -- a unit fighting a vehicle keeps at it (turning, firing) this long before the planner may move it
	CrewCheck      = true,   -- enemy vehicles with no crew inside (and no gun crew next to them) are dead/abandoned: ignored
	CrewDist       = 250,    -- crew counted inside a vehicle within 12 m of it
	GunCrewDist    = 200,    -- gun crew standing within 10 m of a gun
	BuyAtGuns      = false,  -- towed AT guns are not bought: AI-owned guns never move (every human gun moved, every AI gun stayed at spawn)
	LightUntil     = 180,    -- no jeeps after 3 min
	JeepNames      = { "kubel", "willys", "jeep", "gaz67", "gaz_67", "gaz-67", "horch", "bantam", "vw82", "type95_car", "type95car" },   -- no jeeps after LightUntil (halftracks, armoured cars, light tanks still bought)
	-- engaged soldiers: after ProneAfter s the ones in the open lie down; the ones who reached cover crouch behind it
	ProneAfter     = 2,
	-- a vehicle that has killed PestKills of our men (died within PestRange of it) is hunted and countered, even a jeep
	PestKills      = 3,
	PestRange      = 2400,   -- 120 m
	BuyEmplacements = false, -- MG nests / mortars / light guns are not bought for now (they did not leave spawn)
	LightWhenArmour = 0.6,   -- once the enemy has vehicles, this share of the armoured-car budget goes to tanks and AT instead     -- seconds after enemy armour appears before the bot starts buying anti-tank for it
	AtNeedMax      = 5,      -- anti-tank wanted: 1 + 2 per enemy armoured vehicle, capped (AT gun / TD = 2, AT soldier = 1)
	-- names (lower case, substring) of enemy guns: not counted as armour when sizing our anti-tank
	ArmourIgnore   = { "pak", "53k", "m1937", "m1942", "6pdr", "17pdr", "2pdr", "57mm", "37mm", "45mm", "76mm_gun", "m5_3in", "_gun", "cannon", "lig", "obice", "type1_47", "type94", "atgun" },
	AtCheapMax     = 350,    -- before TDAfter only AT guns up to this cost (light AT guns) - plus AT rifles / bazookas
	WreckAfter     = 45,     -- a vehicle our AT has fired at this long...
	WreckNoDamage  = 30,     -- ...without losing health for this long is treated as a wreck for 5 minutes
	TDAfter        = 600,    -- no tank destroyers before 10 min: early armour is answered with AT soldiers and AT guns (players' first TD ~17 min)
	AtGunBackMax   = 4000,   -- AT guns sit at our held flag one step back from the front (players: ~100 m behind the line)

	-- combat reactions (DLL v5): a soldier who sees an enemy this close, or loses health, is "engaged":
	-- he stops running, takes the best cover nearby (sandbags, walls, craters) or else goes prone, and fights.
	Combat         = true,
	EngageDist     = 2000,   -- 100 m (was 70 m: men under fire from 70-120 m kept walking)
	CoverRadius    = 320,    -- cover is looked for within 16 m of the soldier (or of his spot when he arrives)
	CoverCalls     = 6,      -- cover searches per check (they cost a little CPU)
	EngageHold     = 10,     -- seconds an engaged soldier stays down before he may move again
	Disengage      = 8,      -- no enemy in sight for this long: back to the plan
	BoundStep      = 320,    -- fire and movement: an attacker that is winning his fight moves up this far (16 m), then goes down again
	BoundEvery     = 10,     -- half the line moves while the other half fires, swapping every this many seconds
	BoundRatio     = 1.0,    -- bound only when our soldiers near him are at least this many times the enemies he can see
	-- firing lines: attackers line up across the approach instead of crowding the flag point
	LineGap        = 300,    -- the line forms this far outside the flag zone (15 m) while the flag is defended
	LineSpacing    = 110,    -- 5.5 m between soldiers on the line (winning humans ~5 m to the nearest friend; bot clumped)
	LineMax        = 90,     -- seconds a line waits before it assaults the flag anyway (only if the defence is thin by then)
	AssaultRatio   = 1.3,    -- ...or as soon as the attackers outnumber the defenders this much (director)
	-- contested flags (middle and enemy back flags): only a small team goes into the zone to capture / sit on it;
	-- everyone else digs in behind and between the flags, builds sandbags facing the enemy and covers the flag by fire
	CapRefill      = 20,     -- a capture team man killed: nobody new goes into that flag zone for 20 s (no pouring men in one by one)
	CapWalkDist    = 2400,   -- capture team walks (doesn't sprint) into a zone with any enemy within 120 m of it
	CaptureTeam    = 4,      -- (was 6: bot captures were 13-22 man blobs) replays: players take a flag with ~6 men inside 50 m (about 20 within 100 m a minute before)
	DigBands       = { 300, 700 },    -- replays: players dig in ~15 m behind a held flag and spread out to the sides (~50 m from the point)
	DigSpacing     = 180,    -- 9 m apart along the defensive line (players hold a ~150 m wide front)
	DigClearShift  = 80,     -- a spot whose view of the flag is blocked by a building is moved sideways in 4 m steps
	BuildSandbags  = true,   -- soldiers who carry sandbags build a short wall in front of their spot, facing the enemy
	BuildLen       = 90,     -- 4.5 m of sandbags per wall
	WallsPerSpot   = 2,      -- a builder puts up this many walls side by side at his spot (a proper line, not single bags)
	BuildTime      = 75,     -- seconds a builder is left alone to finish (no new orders, no cover moves, no AT hunting)
	SpotArrive     = 250,    -- a soldier within 12 m of his spot counts as there (builds sandbags, takes cover)
	SpotCoverRadius = 400,   -- defenders / line soldiers are sent to the best cover facing the enemy within 20 m of their spot (was 30 m: buildings across the street)
	SandbagBonus   = 250,    -- sandbags are the preferred cover...
	SandbagCrowd   = 3,      -- ...until this many soldiers are already using that sandbag
	-- sandbags all game (last game: 18 walls, none after minute 7 - only men arriving at a defence spot built)
	Fortify        = true,   -- any soldier carrying sandbags who stops somewhere puts up a wall facing the enemy
	FortifyStill   = 12,     -- ...after standing still this long (s)
	FortifyStillMG = 4,      -- machine gunners: almost as soon as they stop
	FortifyEnemyMin = 1300,  -- not with an enemy closer than 65 m (he'd stand up to build)
	FortifyEnemyMinMG = 900, -- gunners: 45 m
	FortifyGap     = 120,    -- not within 6 m of a wall we already built
	FortifyHold    = 25,     -- seconds he is left alone to build
	FortifyRetry   = 20,
	MGNests        = true,   -- a gunner without sandbags gets a wall built in front of him by the nearest carrier
	NestStill      = 6,
	NestHelpDist   = 700,    -- carrier within 35 m
	NestHold       = 35,
	MGSandbagMult  = 2.5,    -- gunners prefer sandbags 2.5x more than riflemen do, one gun per sandbag wall
	-- team games: each bot covers its own slice of the team's front (1v1: the whole map)
	TeamZones      = true,
	ZoneMargin     = 1000,   -- the frontage runs 50 m past the outermost flag / spawn / map point...
	ZoneMarginShare = 0.08,  -- ...or 8% of its length, whichever is more
	ZoneOutPenalty = 4,      -- attack score lost by a flag outside our slice...
	ZoneOutPerWidth = 6,     -- ...plus this per slice-width it lies outside
	ZoneHelpReach  = 0.5,    -- attacks reach at most half a slice past our edge (helping the neighbour)
	ZoneHelpShare  = 0.4,    -- a teammate's flag under attack: send this share of what we would send to our own
	-- machine gunners (any soldier carrying a machine gun) fight from long range and don't walk into the enemy
	MGKeep         = true,
	MGMin          = 1700,   -- an enemy closer than 85 m: the gunner falls back...
	MGWant         = 2100,   -- ...to about 105 m from it; he moves up when nothing is within this
	MGMax          = 2700,   -- he engages out to 135 m
	MGDigBack      = 700,    -- gunners dig in 35 m behind a contested flag
	MGLineBack     = 250,    -- in an attack line the gunners stay 12 m behind the riflemen	-- snipers and AT riflemen get the same treatment: they stay back and shoot from a distance
	SniperMin      = 1900,   -- 95 m
	SniperWant     = 2400,   -- 120 m
	SniperMax      = 3200,   -- 160 m
	ATRMin         = 1900,   -- 95 m: AT riflemen fight at the rifle's max range, 100-115 m
	ATRWant        = 2100,   -- 105 m
	ATRMax         = 2300,   -- 115 m
	ATRVehRange    = 2300,   -- AT riflemen fire at any visible enemy vehicle within 115 m before anything else
	-- grenades: a soldier throws one at a visible enemy in range; he stays where he is (no charging)
	Grenades       = false,  -- switched off for now (user request 2026-10-31); smoke is separate (Smoke)
	GrenadeRange   = 750,    -- 37 m
	AtGrenadeRange = 450,    -- 22 m: anti-tank grenades at vehicles
	GrenadeSafe    = 250,    -- not if one of our own men is within 12 m of the target
	GrenadeGap     = 20,     -- seconds between two grenades from one soldier
	-- emplacements (MG nests, mortars, light guns) go to the flag we hold nearest the enemy and stay there
	EmplaceMax     = 4,      -- at most this many alive (or on order) at once
	-- guns are moved by a plain move order on the gun (what players do). They go this far behind our infantry front
	GunMove        = true,
	AtGunBack      = 2000,   -- AT guns: 100 m behind the front (players ~118 m)
	EmplaceBack    = 1200,   -- MG nests / light guns: 60 m behind the front (players ~64 m)
	GunSpread      = 350,    -- 17 m apart sideways
	GunStuckTime   = 90,     -- a gun that has not moved 2 m this long after an order counts as stuck
	VehStep        = 1500,   -- a vehicle is moved at most 75 m per order (players: ~55 m moves, the bot: 155 m)
	-- smoke on contested flags: enemies on/near a flag our men are fighting for -> one smoke grenade onto the flag
	Smoke          = true,
	SmokeRange     = 900,
	SmokeCount     = 4,      -- smokes per flag at a time (different throwers): the front edge toward the enemy, both sides, the middle
	SmokeMaxFrac   = 0.95,   -- each thrown by the man furthest from its spot who can still reach it (max range)
	SmokeEvery     = 40,     -- seconds between smokes on the same flag
	SmokeAttackEvery = 25,   -- the flag our launched attack is going for gets smoke this often while our men close in
	-- single-soldier purchases (one-man units like AT soldiers, snipers, officers) are throttled so money goes into squads
	SingleGap      = 30,     -- seconds between any two one- or two-man purchases
	SingleMen      = 2,      -- a purchase of this many men or fewer counts as a "single" buy
	AltGap         = 15,     -- seconds between two "buy something else instead" purchases (bot bought 33 times per 10 min, humans ~11)
	SingleSameGap  = 90,     -- seconds before the same one-man unit is bought again
	SingleShare    = 0.25,   -- one-man purchases at most this share of our soldiers (at least 3 allowed)
	SingleGuessCost = 60,    -- before we have seen it arrive, a non-vehicle unit this cheap is assumed to be one man

	-- flag roles (with the DLL). A flag is a "back" flag when it is this much closer to our base than to theirs:
	-- distance to our base / (distance to ours + theirs) below BackShare. Back flags get ONE man who stays there.
	-- Everything else fights for the middle flags and the enemy's back flags.
	BackShare      = 0.42,
	MidHoldMin     = 2,      -- strength kept on each middle flag we hold (1 = four soldiers): the capture team + men dug in around it
	BuyLead        = 30,     -- a unit still on cooldown is only planned for when it comes out within this many seconds

	-- director (with the DLL, every difficulty): sees every enemy unit through the fog of war and steers the plan.
	-- Individual soldiers still only react to enemies they can actually see.
	Director       = true,
	DirNear        = 500,    -- enemies within the flag zone + this count as defending / attacking that flag (25 m)
	DirApproach    = 2000,   -- enemies within the flag zone + this count as moving on that flag (100 m)
	DirAvoid       = 1.2,    -- attack-target score lost per point of enemy strength on the flag (go where they are weak)
	DirAttackRatio = 1.4,    -- an attack wants this many times the defenders' strength before it launches
	DirDefendRatio = 1.1,    -- a threatened flag of ours gets this many times the attackers' strength as holders
}

-- share of the army's value per role, by game phase. Roles: inf support sniper atinf atgun emplace light tank td heavy
-- (emplace = MG nests, mortars, light infantry guns, 20 mm flak; light = armoured cars and light tanks)
BotComposition = {
	early = { inf = 0.50, support = 0.10, atinf = 0.08, emplace = 0.04, light = 0.28 },                                      -- (2026-11-01) aggressive opening: infantry + light tanks / armoured cars for a foothold                         -- first 5 min (players: AT man right away, MG nest/mortar ~4 min, first light vehicle ~7.5 min)
	mid   = { inf = 0.42, support = 0.10, atinf = 0.07, sniper = 0.02, emplace = 0.08, atgun = 0.04, light = 0.13, tank = 0.08, td = 0.03 }, -- (2026-11-01) fewer tanks, keep buying infantry -- 5-15 min (first medium tank ~13 min)
	late  = { inf = 0.40, support = 0.09, atinf = 0.06, sniper = 0.02, atgun = 0.05, emplace = 0.08, light = 0.11, tank = 0.10, td = 0.04, heavy = 0.02 },
	antiTank = { atinf = 0.07, td = 0.05, atgun = 0.03 },                                                                     -- added when the enemy has tanks
}

-- combat weight used to size attacks and garrisons: vehicles per vehicle, infantry per 4 soldiers (scaled to the split size)
BotStrength = { inf = 1.0, support = 0.9, sniper = 0.5, atinf = 0.8, atgun = 0.7, emplace = 0.8, light = 1.5, tank = 2.5, td = 2.0, heavy = 3.5 }
-- who should be left holding a flag (higher = better holder)
BotHoldPref = { atgun = 6, emplace = 6, support = 5, sniper = 5, inf = 4, atinf = 3, light = 2, td = 2, tank = 1, heavy = 0 }

-- split test: 10-man infantry squads per army (cheapest first); the test uses the first one the game lets it buy
SplitTestUnits = {
  ["axis_minor"] = { "Motorized_Hungarian_Rifles(axis_minor)", "romanian_rifle_squad(axis_minor)", "fin_pioneer(axis_minor)" },
  ["eng"] = { "smgs_40(eng)", "riflemans_40(eng)", "riflemans_can(eng)", "smgs(eng)", "riflemans(eng)", "riflemans_at(eng)", "riflemans_scot(eng)", "mech_rifles(eng)" },
  ["ger"] = { "home_guards(ger)", "grenadiers_40(ger)", "grenadiers_43(ger)", "grenadiers_42(ger)", "fusiliers_40(ger)", "fusiliers_43(ger)", "fusiliers_42(ger)", "jagers_44(ger)" },
  ["ger_ss"] = { "ssvts_41(ger_ss)", "grenadiers_41(ger_ss)", "grenadiers_42(ger_ss)", "grenadiers_43(ger_ss)", "pzgrens_41(ger_ss)", "pzgrens_42(ger_ss)", "pzgrens_43(ger_ss)", "sturmpios(ger_ss)" },
  ["ger2"] = { "elites(ger2)", "stormtroopers(ger2)", "elites_para(ger2)" },
  ["jap"] = { "riflemans_t96_4(jap)", "riflemans_4(jap)" },
  ["rus"] = { "conscripts(rus)", "home_guards_41(rus)", "smgsv4(rus)", "smgsv5(rus)", "smgsv3(rus)", "smgsv2(rus)", "smgs(rus)", "smgs_mot(rus)" },
  ["rus_guard"] = { "specialinf_smg(rus_guard)", "elite_guards_smg(rus_guard)" },
  ["usa"] = { "mech_armor_rifles(usa)" },
}
SplitTestValues = { 1, 2, 3, 5, 10 }   -- each value is tried twice

-- Faction advice from the Steam workshop guides (welkon's faction guides; Josh's Soviet guide for rus/rus_guard).
-- w: unit name -> weight when choosing inside a role (2.5 = strongly preferred, 1 = neutral, 0.3 = avoid, 0 = never)
-- must: kept on the field at all times once S.t >= after (lost ones get replaced); first buyable name is used
-- comp: multiplies the army composition shares for that faction
BotGuide = {
  usa = {
    w = {
      ["specialinf(usa)"] = 2.5, ["elites(usa)"] = 1.8, ["elites_101st(usa)"] = 1.6, ["storm_mech(usa)"] = 1.6,
      ["elite_101st_para3b(usa)"] = 2.5, ["elite3b(usa)"] = 1.6, ["mg2(usa)"] = 1.5,
      ["stormtrooper5(usa)"] = 2.0, ["stormtrooper_at(usa)"] = 2.0,
      ["browning_30cal"] = 1.6, ["30_browning_m1919a4_seq(usa)"] = 1.6, ["30_browning_m1919a4_seqx2(usa)"] = 1.6,
      ["browning_m2hb"] = 1.6, ["50_browning_m2hb_seq(usa)"] = 1.6, ["50_browning_m2hb_seqx2(usa)"] = 1.6, ["maxson"] = 1.6,
      ["60mm_brandt_usa"] = 2.0, ["np_m5cannon"] = 1.3,
      ["m8grayhound"] = 0.5, ["m20"] = 0.2, ["m3stuart_early"] = 1.5, ["m5a1"] = 1.5, ["m24"] = 1.5, ["m8"] = 2.5,
      ["m4sherman"] = 1.8, ["m4a1"] = 1.8, ["m4a3e2_jumbo"] = 2.5, ["m4a3e2_jumbo_76"] = 2.5, ["m36"] = 2.0, ["m36b1"] = 2.0,
      ["smgs(usa)"] = 0.3, ["mech_armor_rifles(usa)"] = 0.3, ["flamers(usa)"] = 0.2, ["snipers(usa)"] = 0.2,
      ["m4a3_105"] = 0.3, ["m8_howitzer"] = 0.4,
    },
    must = { { names = { "60mm_brandt_usa" }, after = 240, count = 1 } },
  },
  eng = {
    w = {
      ["smgs(eng)"] = 2.2, ["smgs_40(eng)"] = 1.8, ["pioneers(eng)"] = 2.0, ["elites(eng)"] = 2.0, ["elites_40(eng)"] = 2.0,
      ["stormtroopers(eng)"] = 2.0, ["at_rifles(eng)"] = 1.8, ["stormtrooper5(eng)"] = 2.5, ["elite3(eng)"] = 1.8,
      ["stormtrooper6(eng)"] = 1.8, ["oerlikon"] = 1.8, ["qf2"] = 1.6, ["qf2_40"] = 1.6, ["qf17"] = 1.6, ["qf17_43"] = 1.6,
      ["mk2a"] = 2.2, ["matildamk1"] = 1.5, ["churchill_mk_ix"] = 2.5, ["cometa34"] = 2.0, ["staghound_mk3"] = 1.8,
      ["riflemans_can(eng)"] = 0.3, ["mk3"] = 0.3, ["flamers(eng)"] = 0.5,
    },
  },
  ger2 = {
    w = {
      ["home_guards(ger2)"] = 0.2, ["riflemans(ger2)"] = 2.2, ["smgs(ger2)"] = 2.0, ["elites_para(ger2)"] = 1.8,
      ["storm_mech_ost(ger2)"] = 1.6, ["at_rifles2(ger2)"] = 2.0, ["bazookers(ger2)"] = 1.8, ["bazooker3(ger2)"] = 1.8,
      ["snipers(ger2)"] = 1.5, ["pz1b_ger2"] = 2.0, ["sdkfz234_ger2"] = 2.0, ["t34_2_ger"] = 2.2, ["pzkpfw756"] = 2.5,
      ["pz5g_ger2"] = 1.6, ["hetzer_ger2"] = 0.4, ["pz4j_ger2"] = 0.4,
    },
  },
  jap = {
    w = {
      ["home_guards_42(jap)"] = 1.5, ["home_guards(jap)"] = 1.5, ["home_guards_throwgun(jap)"] = 1.3,
      ["smgs(jap)"] = 1.8, ["smgs_42(jap)"] = 1.8, ["elites_ig(jap)"] = 2.5, ["elites_ig_42(jap)"] = 2.5,
      ["elites_takasago(jap)"] = 1.8, ["elites_42_takasago(jap)"] = 1.8, ["stormtroopers(jap)"] = 1.8, ["stormtroopers_42(jap)"] = 1.8,
      ["at_rifles(jap)"] = 1.8, ["stormtrooper5(jap)"] = 2.0, ["snipers2(jap)"] = 2.0, ["type89mortarinf(jap)"] = 2.0,
      ["type2_20mm"] = 2.0, ["t90_75m"] = 2.2, ["t90_75m_towed(jap)"] = 1.8, ["type93scout"] = 1.8, ["ss-d"] = 1.8,
      ["chi-nu"] = 2.2, ["chi-to"] = 2.2, ["chi-ha120"] = 2.0,
    },
    must = {
      { names = { "type89mortarinf(jap)", "type89mortarinfx2(jap)" }, after = 120, count = 1 },   -- a mortar every game
      { names = { "t90_75m", "t90_75m_towed(jap)", "pak47" }, after = 420, count = 1 },          -- AT gun: first big mid-game buy
    },
  },
  rus = {
    w = {
      ["riflemans(rus)"] = 2.0, ["riflemans_41(rus)"] = 2.0, ["riflemans_42(rus)"] = 2.0, ["riflemansv2(rus)"] = 2.0,
      ["riflemansv3(rus)"] = 2.0, ["riflemansv4(rus)"] = 2.0, ["riflemansv5(rus)"] = 2.0,
      ["home_guards(rus)"] = 0.4, ["home_guards_41(rus)"] = 0.4, ["home_guards_42(rus)"] = 0.4, ["conscripts(rus)"] = 0.4,
      ["smgs(rus)"] = 0.8, ["smgsv2(rus)"] = 0.8, ["smgsv3(rus)"] = 0.8, ["smgsv4(rus)"] = 0.8, ["smgsv5(rus)"] = 0.8,
      ["elites(rus)"] = 1.6, ["elites_40(rus)"] = 1.6, ["elites_42(rus)"] = 1.6, ["smg3(rus)"] = 1.4, ["shock(rus)"] = 1.2,
      ["at_rifles(rus)"] = 1.6, ["at_riflesv2(rus)"] = 1.6, ["bazookers(rus)"] = 1.8,
      ["maxim_1910_30"] = 1.8, ["maxim_1910_30_seq(rus)"] = 1.8, ["maxim_1910_30_seqx2(rus)"] = 1.8, ["dshk_stank"] = 1.6, ["dshk_zenit"] = 1.6,
      ["bm_37"] = 1.3, ["t60"] = 2.5, ["bt7_37_1"] = 1.6, ["bt7a"] = 1.4,
      ["t34_42"] = 2.8, ["t34_0"] = 2.8, ["t34_41"] = 2.8, ["t34_1"] = 2.8, ["kv1s"] = 1.6, ["kv85"] = 1.6, ["kv1"] = 1.4, ["su76"] = 0.3,
      ["is2"] = 2.2, ["is122"] = 1.8, ["isu122"] = 1.6, ["bs3_towed(rus)"] = 1.8,
    },
    must = {
      -- open with two rifle squads (one leads, one follows), then an MG for the line and something against vehicles
      { names = { "riflemans_42(rus)", "riflemans_41(rus)", "riflemansv4(rus)", "riflemansv5(rus)", "riflemans(rus)", "riflemansv2(rus)", "riflemansv3(rus)" }, after = 0, count = 2 },
      { names = { "maxim_1910_30", "maxim_1910_30_seq(rus)", "mgs2(rus)", "mgs2_41(rus)" }, after = 60, count = 1 },
      { names = { "at_riflesv2(rus)", "at_rifles(rus)", "bazookers(rus)" }, after = 90, count = 1 },
    },
    comp = { inf = 1.2, tank = 1.4, td = 0.45 },   -- cheap, big squads: lean on numbers; T-34/76s over SU-76s
  },
  rus_guard = {
    w = {
      ["specialinf_rifle(rus_guard)"] = 2.0, ["specialinf(rus_guard)"] = 1.8, ["elite_guards(rus_guard)"] = 1.6,
      ["guards_shock(rus_guard)"] = 1.4, ["at_rifles(rus_guard)"] = 1.8, ["bazookers(rus_guard)"] = 1.8,
      ["sg43_goryunov_guard(rus_guard)"] = 1.6, ["dshk_stank_guard(rus_guard)"] = 1.6, ["dshk_zenit_guard(rus_guard)"] = 1.6,
      ["t60_guard(rus_guard)"] = 2.2, ["t34_2_guard"] = 2.6, ["t34_3_guard"] = 2.6, ["is2_guard"] = 2.0, ["isu122_guard"] = 1.6, ["su76_guard"] = 0.3,
      ["recons(rus_guard)"] = 0.5,
    },
    must = { { names = { "at_rifles(rus_guard)", "bazookers(rus_guard)" }, after = 90, count = 1 } },
    comp = { tank = 1.4, td = 0.45 },
  },
}

-- infantry quality: unit names containing these are militia (Volkssturm, home guard, conscripts) and are bought only
-- when nothing else is affordable; plain infantry/support names containing GoodInfantry are preferred
BotConfig.WeakInfantry  = { "home_guard", "volkssturm", "conscript", "militia", "vehic_supporter" }
BotConfig.WeakInfantryW = 0.1
BotConfig.GoodInfantry  = { "elite", "storm", "sturm", "pzgren", "grenadier", "specialinf", "guard", "para", "ranger", "commando", "marine", "pioneer" }
BotConfig.GoodInfantryW = 1.6
BotConfig.QualityStart  = 0.45   -- inside a role, aim at the middle of the price range from the start (was the cheap end)
-- weakness checks (director sees everything): when the enemy has (almost) no anti-tank, buy cheap anti-infantry
-- vehicles / tanks and send each vehicle to the target flag with the least enemy anti-tank around it (a flank)
BotConfig.Exploit           = true
BotConfig.ExploitRadius     = 2500   -- enemy anti-tank within the flag zone + 125 m counts for that flag
BotConfig.ExploitMaxAT      = 1      -- a flag counts as open for our vehicles with at most this much AT near it (AT man = 1, gun/tank = 2)
BotConfig.ExploitMaxATTotal = 1      -- the whole enemy army with at most this much AT: buy extra vehicles
BotConfig.ExploitAfter      = 120
BotConfig.ExploitLight      = 0.25   -- extra share of light vehicles (armoured cars, MG cars, light tanks)...
BotConfig.ExploitTank       = 0.10   -- ...and of tanks after 5 min
BotConfig.AtNames           = { "bazook", "schreck", "faust", "piat", "_at", "at_", "pak", "zook" }
BotConfig.NotAtVehicles     = { "truck", "blitz", "opel", "kubel", "willys", "gaz", "dodge", "zis", "bedford", "horch", "ammo", "supply", "mortar", "maxim", "mg", "browning", "vickers", "flak", "nebel", "bm13", "bm31", "katyusha", "howitzer", "lefh", "sig33", "leig", "moto", "bike", "searchlight", "radio", "transport", "halftrack", "sdkfz251", "m3_halftrack", "universal", "bren_carrier" }