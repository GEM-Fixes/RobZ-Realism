# RobZ Realism 1.31.0: the two armour sources, and the near-duplicate macros

Mod: `E:\RobZ Realism\robz realism mod 1.31.0`. Read-only study, nothing in the mod was changed.
Scratch scripts and raw output: `E:\arsenal-tmp\explain\` (`census.js` + `census.json`, `defs.js`, `alldefs.js`, `mapnames.js`, `chains.js`).
Tags: [V] verified (engine code read, or counted from the files), [I] inferred, [T] not tested in game.

## A. Two armour sources

### A1. What each source is and where it is written

| Source | Where written | What it holds |
|---|---|---|
| Armour areas: `{armor {setting "body" {thickness F S R T} {volumes "body*"} {threshold ..} {durability ..}}}` | Written by the `armor_*` macros. The vehicle calls one, e.g. `("armor_medium" turret(..) body(..))`. The macro bodies live in `resource/properties/tank_unarmed.ext` (tanks; `armor_tank`, `armor_light/medium/heavy`, `armor_mantlet`), `armoredcar.ext`, `car.ext`, `cannon_armor.ext`, and `properties/robz/armor.inc` (`armor_engine`) | One value per face group for a whole area (front, side, rear, top), plus the damage model: threshold, durability, break |
| Per-volume thickness: `{volume "body1" {thickness 30 {front 80} {rear 20} ..}}` | In the vehicle `.def` itself. 308 defs carry the block `; --- Godny hitbox armor (ported from GodnyMod ...)`. `godny port notes.txt` (mod root) says Godny's per-volume blocks were merged in, but the `armor_*` macros "are still Robz". Some are written as `vol_*` calls from `properties/robz/volumes.inc` | One value per face of one volume (six faces), and nothing else |

Example: Panzer IV H, `resource/entity/-vehicle/tank_medium/pz4h/pz4h.def` [V]

```
11  ; --- Godny hitbox armor (ported from GodnyMod: pz4h.def) ---
12  {volume "body1"  {tags "body"} {component "body"}
15      {thickness 30 {front 80} {rear 20} {top 0.1} {bottom 10} {right 20}}}
33  {volume "body3"  ... {thickness 20 {front 0.1} {rear 20} {top 8} {bottom 10}}}
66  {volume "mantlet" {thickness 50 {rear 15}}}
72  {volume "engine" {thickness 10}}
91  ("armor_medium" turret(50 30 30 10) body(80 30 20 22))
92  ("armor_engine"  t(30 30 20 22))
93  ("armor_mantlet" t(50))
```

`armor_medium` (tank_unarmed.ext:927) calls `armor_tank` (tank_unarmed.ext:586), which writes the area `{setting "body" {thickness 80 30 20 22} {volumes "body*"}}`.
`armorsim table pz4h` with the mod shows what the game uses [V, armorsim mirrors eGameEntityArmor.cpp]:

| Volume, face | Godny per-volume value | Robz area value | Used |
|---|---|---|---|
| body1 top | 0.1 | 22 | 22 |
| body1 right | 20 | 30 (side) | 30 |
| body3 front | 0.1 | 80 | 80 |
| mantlet rear | 15 | 50 | 50 |
| engine (all faces) | 10 | 30/30/20/22 | area |
| turret1 front | 30 | 50 | 50 |
| zip1, detail7 | 6, 7.5 | no area covers them | 6, 7.5 |

### A2. Which one the engine uses

- One function gives the thickness for every shell hit: `ePenetration::GetThickness` (`game/entity/eGameEntityArmor.cpp:89-139`). It starts from the volume's own value. If an armour area covers the volume and the area's value for the hit face is not 0, the area value replaces it. [V code]
- So the macro (area) wins, face by face, whenever its value is not 0. The volume value is used only (a) for volumes no area covers, or (b) on faces where the area value is 0. Left and right both use the area's `side` value. Bottom uses the area's `top` value. [V code]
- An area covers a volume when the area's pattern (`body*`, `turret*`, `engine*`, ...) matches the volume's first tag, which is its name. The first matching area in definition order wins. [V] modweb `damage/armor-thickness.md`
- The two values are never added together. [V code]
- Penetration, HE blast and the AI's "can I penetrate" check all call the same function (`eGameEntityArmor.cpp:144,210,231,251`, `eAimState.cpp:271,282`), so the same rule holds for AP, HE and AI aiming. [V code]
- The two sources also do different jobs. Only the area carries the damage model (threshold, durability, break → `break_armor` scripts). The volume block carries the faces the area cannot express (left ≠ right, bottom ≠ top) and the fallback value. [V]
- Webs: limits `GPL-04` [V eGameEntityArmor.cpp:105-138], `DMG-06` [V :89], `KEY-16` [V], `PORT-05` [V], `DMG-25` (several volumes of one part are flattened to one value) [V code], `DMG-23` (a second `{setting}` with the same name replaces the first's thickness: this is how `armor_engine` overrides the engine area from `armor_tank`) [V eGameEntityArmor.cpp:325]. Also modweb `damage/armor-thickness.md`, `gameplay/verified.md` line 6, and `damage/blast-armor.md`.
- Not tested in game for this mod. The rule is read from the as64 engine source. That the retail exe behaves the same is [I], and it matches `gameplay/verified`.

### A3. Counts (all 1,360 `.def` under `resource/entity/-vehicle`, read the way the engine reads them with `tools/armorsim/armordata.js`) [V count]

| Class | Live units | Wrecks (`/x/` folders) |
|---|---|---|
| Both sources | **454** | 0 |
| Only `armor_*` areas | 191 | 0 |
| Only per-volume thickness | 0 | 24 |
| Neither | 0 | 691 |

- In the 454 "both" units, the numbers disagree in **341** units: at least one face of a volume written in the vehicle gets a different value from the area. Those are 1,727 volumes. 113 units agree everywhere. [V]
- The 3,415 volumes written in the vehicles of the "both" units split like this: 686 are not covered by any area, so their own value is used (inventory 81, zip/zipl/zipr ~133, detail 51, shield 44, fuel 38, mantlet 37, ...). 1,002 are covered and agree. 742 are partly overridden. 985 are fully overridden: every non-zero face is replaced. [V]
- No mod area uses 0 on any face, so nowhere does a per-volume plate show through a covered face. [V]
- Godny link: 244 of the 308 Godny-ported defs have both sources, and 215 of those disagree. The other 126 disagreeing units are Robz/vanilla-style volume blocks. [V]
- 178 units disagree on `engine`: the Godny engine block is `{thickness 10}`, and `armor_engine` / `armor_tank` replace it. [V]
- I get 454 and 341, not 345. The earlier survey's method is not recorded (`plan/reports/robz-macrostd.md` item 13 only states the number), so I cannot reconcile them. 341 disagreeing units is the closest match.

Five disagreements (Godny volume value → value the game uses):

| Unit (def) | Volume / face | Volume | Used (area) |
|---|---|---|---|
| pz4h (`tank_medium/pz4h/pz4h.def`) | body3 front | 0.1 | 80 |
| is2 (`tank_heavy/is2/is2.def`) | mantlet front / rear | 115 / 15 | 100 / 100 |
| kv1 (`tank_heavy/kv1/kv1.def`) | turret front | 110 | 75 |
| m4a3e8 (`tank_medium/m4a3e8/m4a3e8.def`) | body1 right | 107.9 | 38 |
| pz5g (`tank_medium/pz5g/pz5g.def`) | turret2 front | 45 | 100 |

(Also cromwell_mk_vi body3 left/right 31.75 → 44, stug3g body4 front 0.1 → 80.)

### A4. What a clean-up would be, and what could go wrong

Three ways to go:
1. **Keep the Robz areas as the truth (no gameplay change).** On covered faces, rewrite the per-volume numbers so they equal what the game already uses, or comment that they are overridden. Leave the 686 uncovered volumes alone. Check with `armorsim table` before and after (the effective table must stay identical) and with `statsheet` (`ARMOR_VOLUME_SHADOWED` should drop to 0).
   - Do not delete the `{thickness}` lines. With `dbg_volumes` on, the engine warns "Incorrect thickness for volume" when an `able bullet|blast` volume has a 0 face (`eGameEntityVolumes.cpp:179-196`, called only under `dbg_volumes`, `eGameEntitySerialize.cpp:163`). [V code]
2. **Make Godny's per-plate values the truth (gameplay change).** Set area faces to 0, or give each plate its own area (`body1`, `body2`, ... as `armor_*_advanced` already does in 40 units).
   - Risks: Godny's values assume Godny's damage model, which was not ported (port notes). Many Godny faces are 0.1 on purpose: inner faces, or deck tops that real shells should never reach. Once exposed they become paper. For example, pz4h's upper deck would go from 22 to 0.1.
   - Areas also carry threshold and durability (`thr*thickness`, `dur*thickness`), so HE damage and part breaking change with them.
   - Every changed tank needs in-game testing [T].
3. **Leave both and document them.** Today's behaviour is stable. The cost is that editing a Godny `{thickness}` on a covered face does nothing, which is a trap for whoever edits next.

Other risks: one `armor_*` macro body is shared by hundreds of units (MACROS.md: `armor_medium` 291 calls, `armor_heavy` 198, `armor_light` 205), so editing a macro moves all of them. Where several volumes share one area, one value overwrites all of them (`DMG-25`).

## B. Near-duplicate macros

The 15 / 8 / 6 / 6 counts describe the mod before the macrostd `share` step. I rebuilt them from the undo copy `<mod>/.arsenal-undo/macrostd-20261118/share/` plus the unchanged current files: crew_human 80 sites / 15 bodies, armor_light 9 / 8, locomotion 6 / 6, cut_part 9 / 6 [V]. Since then `share` renamed most of them, so today only the vanilla-path files still use these names: crew_human 3, armor_light 5, locomotion 3, cut_part 3 [V].

### How same names collide [V code]
- `(define "x" ..)` is stored as `m_defines[name] = define` (`gem/io/eSDLReader.cpp:394`). A later define in the same read silently replaces the earlier one, with no log line. A call looks the name up when it is expanded (`eSDLReader.cpp:319`), so the latest body read so far wins. This also applies to a nested call inside another macro, e.g. `crew_2_human` calling `crew_human`.
- Defines belong to the top-level file being read (`GPL-11` [V eSDLReader.cpp:317]). Two vehicles never see each other's bodies. A collision can only happen inside one `.def` and its include chain.
- `PORT-61` [V eSDLReader.cpp:394] is the limits row for "same name, other body". No row states the plain "last define wins inside one chain" rule. That is a small gap in the webs.
- Live today: 8 defs read two `crew_human` bodies. humber, m20, m8grayhound, staghound, staghound_e1, staghound_mk3 and churchill_kangaroo read car_crew.ext, then tank_crew.ext. ha-to reads them the other way round. Each def's own calls match the body read last (humber uses `door1/door2/visor`, ha-to uses `bone/door/animation`), so they work, but only because of the include order [V files].
- Macro parameters: `name(value)` takes raw text up to the first `)` (`gem/io/eSDLParser.cpp:328`). A parameter can carry `{..}` blocks but never a `)`. There are no defaults: a missing parameter stays as literal `%name` (`GPL-11`). [V code] Passing whole blocks as a parameter has not been tried in game [T].

### crew_human (15 bodies: 3 in properties files, 12 in vehicle files)

| Group | Bodies (sites) | What differs | Name today | Merge? |
|---|---|---|---|---|
| One door: `door(%door)` + `anm` | 9 bodies, 51 sites: #1 (5), #2 (12), #4 (2), #5 (25), #6 (4), #7, #8, #9, #14 (car_crew.ext) | Same boarder. Only which optional placer keys are present: `group` (param / "crew" / none), `linkbone` (%bone / %place / none), `turnoff {sensor}{shadow}` (+`{targetable}` in car_crew), `visor`. #4 also uses `anm "%place"` | no_turnoff 122 calls, visor 31, link_bone 7 + 2_link_bone 2, no_targetable 138, no_linkbone 4, no_group 2, no_bone 6, no_group_targetable 3, car_crew's crew_human | Yes [I]: one core macro with `place door animation` + `placer_extra(...)` text, or thin named wrappers over one core. Every caller must pass every parameter |
| Two doors: `door1/door2` | 4 bodies, 26 sites: #3 (16), #11 (6), #12 (3), #15 (tank_crew.ext, vanilla) | Same two-door boarder. Placer differs: `visor "main"` (#11), `openForCrush` (#12). #15 has `visor %visor`, no linkbone/turnoff, `anm "left"/"right"` | two_doors 33, visor_main 18, open_for_crush_two_doors 9 + vis 2, tank_crew's crew_human | Yes [I]: same core with `anm1/anm2` + `placer_extra` |
| Fixed emit doors | 2 bodies: #10 (m15_contraereo, 2 doors), #13 (cannon_crew.ext, vanilla, 5 doors) | Door names hard-coded, count differs, `openForCrush`, `group "%place"` | open_for_crush 2, cannon_crew's crew_human | Truly different (structure). Keep |

- Two exact duplicates remain under different names: `crew_human_vis` (m15_contraereo.def:65) = `crew_human_open_for_crush_two_doors` (robz/crew.inc:92), and `crew_human_2_link_bone` (np_sdkfz234_1/crew.ext:31) = `crew_human_link_bone` (robz/crew.inc:27). [V]
- The 3 properties bodies (cannon_crew, car_crew, tank_crew) must keep the name `crew_human`, because vanilla files call it (directly and through `crew_2_human`, `crew_gun` ...). 2 equal vanilla. car_crew's is the mod's own (adds `turnoff`). [V]

### armor_light (8 bodies)

| Group | Bodies | What differs | Merge? |
|---|---|---|---|
| One per class, each wrapping a different base macro | armoredcar.ext (`armor_btr`), car.ext = car1.ext (`armor_car`), cannon_armor.ext (`armor_cannon`), construction_generic.inc (`armor_construction`), airborne_mp.ext (`armor_airborne`, mod-only, now `armor_light_airborne`, 0 calls) | Different base macro and target. This is vanilla's design: every class file has its own `armor_light`, so callers write `("armor_light")` for any class. 4 of these are byte-equal to vanilla | No. They are different by design and must keep the name |
| Tank, wrapping `armor_tank` | tank_unarmed.ext (now `armor_light`), spawner.ext (now `armor_light_tank_v2`, 4 calls) | Numbers only: track 6/7, track_b 15/12, pierce_dur 99999/60. spawner has no `("new_components")` | Yes, with `track/track_b/pierce_dur` parameters, plus the components call as a text parameter [I] |
| | tank_addon.ext (now `armor_light_tank`, 0 calls) | 15 plate parameters (bod1..7, tur2..7), pierce_dur 5000 | Truly different, and unused |

### locomotion (6 bodies) [V values]

| Group | Bodies | What differs |
|---|---|---|
| Wheeled | armoredcar.ext, car.ext (vanilla-equal), car1.ext (now `locomotion_max_speed_at_max_turn`) | armoredcar = car except SplineRadius 3 vs 1. car1: StartTime 24, Gears 0.05 0.25 0.4 0.9, RearGears 0.17 |
| Tracked | tank_unarmed.ext (differs from vanilla only in GearSwitchDelay 2.0 vs 0.5), spawner.ext (now `locomotion_v2`) | All values differ (MaxSpeed 25/40, StartTime 6/20, ...). spawner adds maxSpeedAtMaxTurn |
| Airborne | airborne_mp.ext (vanilla-equal, now `locomotion_steer_on`) | Only 6 keys, no MaxSpeed |

Within a group, the bodies can be merged by value parameters [I]. The no-argument `("locomotion")` form must stay in each class file, because vanilla calls it with no arguments and callers override single keys after it (`{Locomotion ("locomotion") {MaxSpeed 27}}`).

### cut_part (6 bodies, in `set/interaction_entity/`) [V]

| Body | What differs | Name today |
|---|---|---|
| cannon.inc:286 | `piece_medium_steel`, impulse up 8, rnd_dir 10, `{call "check_delete_part"}` | cut_part_call |
| cannon.inc:758 | same, `piece_big_steel` | cut_part_piece_big_steel |
| car.inc:294 = car.inc:773 | medium, up 4, rnd_dir 6, `{delay_effect 20 5 "stop"}` | cut_part_v2 (twice, identical) |
| moto.inc:192 | = car + `{burn ... "smoke_dead_wheel"}` | cut_part_burn |
| railway.inc:349 = 410 = 450 | medium, up 8, rnd_dir 10, delay_effect | cut_part (3×, identical) |
| tank/general_scripts_defines.inc:1224 (mod-only) | wrapped in `{if rand 0.5 ..}`, up 12, dir 9 3 | cut_part_rand |

- Five of the six are vanilla bodies. Vanilla itself redefines `cut_part` inside one file (cannon.inc 141 and 286; railway.inc 3×), so the redefinition inside one chain is intentional: calls after the second define get the second body.
- Mergeable [I]: one core with `piece`, `up`, `rnd` and a `tail(...)` text parameter covers cannon ×2, car, railway and moto.
- The random 50% tank body is a different structure. Keep it separate.

## Could not determine
- How the earlier survey got 345. My count is 454 both / 341 disagreeing.
- Whether Godny's 0.1 faces were meant as weak spots or as "never hit" inner faces. GodnyMod is not in reach, and the port notes do not say.
- Whether a `{..}` block passed as a macro parameter works in game. The code says plain text substitution, so it should [I/T].
- Nothing was tested in game. All gameplay effects above are from engine code and armorsim.
