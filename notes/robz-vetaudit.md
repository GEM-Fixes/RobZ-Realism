# RobZ Realism 1.31.0: veteran and elite vehicles and cannons against the owner's rules

Mod `E:\RobZ Realism\robz realism mod 1.31.0` (`resource/`), read-only audit, date 2026-11-19. Nothing in the mod or game was changed.
Scripts and output: `E:\arsenal-tmp\vetaudit\` (`audit.js` main, `extract.js` def/model/weapon reader, `report.js` tables, `mp.js` buy-list scan). Full unit x field list: `E:\arsenal-tmp\vetaudit\audit.tsv` (573 rows, conforming rows too). Weapon values come from the vetguns resolver (`E:\arsenal-tmp\vetguns\sim.js`, see `plan/reports/robz-vetguns.md`). Defs expanded with `tools/lib/sdlx.js` (macros, includes, mod over vanilla). Nothing run in game [T].

## Rules as given

| class | reload | start time | gear | turn time | turret / traverse speed | gun / elevation speed | stealth |
|---|---|---|---|---|---|---|---|
| artillery vet | x0.60 | - | - | - | - | - | - |
| AT cannon vet | x0.80 | - | - | x0.90 | +0.003 ("turn speeds") | +0.003 | +10% |
| AT cannon elite | x0.60 | - | - | x0.80 | +0.006 | +0.006 | +20% |
| vehicle vet | x0.85 | x0.85 | +0.03 | x0.90 | +0.0001 | +0.0002 | - |
| vehicle elite | x0.70 | x0.75 | +0.06 | x0.80 | +0.0002 | +0.0004 | - |

## Where each field lives in this mod (key mapping)

| rule word | key audited | where it is written | sure? |
|---|---|---|---|
| start time | `{StartTime}` inside `{Chassis {Locomotion ...}}` | vehicles: written in each def; cannons: `("loco_*")` macros in `properties/cannon_armor.ext` (`loco_nomove` 10, `loco_medium` 3 ...) | [V] read |
| gear | each forward value of `{Gears g1 .. gN}` in the same locomotion block; the last value is skipped when it is 1 (top gear); `{RearGears}` not counted | vehicle defs | [I] (skip-top-gear and no-rear-gear inferred from the conforming vets: they all leave the final 1 and RearGears alone) |
| turn time | `{TurnTime}` in the locomotion block | vehicles: def; cannons: `loco_*` / `loco_*_vet` macros (`loco_nomove` 120 -> `loco_nomove_vet` 108, `loco_medium` 16 -> `loco_medium_vet` 14.4) | [I] for cannons (carriage turn time; no other turn-time key exists) |
| turret speed | effective speed of the traverse bone: def `{bone "turret" {speed x}}`, else the model's `{bone revolute "turret" {speed}}` in the `.mdl` named by `{Extension}` | def bone blocks at the end of each def; model when the def has none | [V] read; traverse bone choice [I]: `turret`; casemates stug3g/stug4g/stuh42/jagdpanzer_iv use `gun_rot2` (limits -12 12 / -20 20); m12gmc uses `mantlet` (-14 14); jagdpanther `turret` (-11 11) |
| gun speed | effective speed of the elevation bone `gun_rot` (def, else model) | same | [I] jagdpanther uses `gun_rot1`; turan2/turan3 have no `gun_rot`, their elevation bone is `mantlet` (model only, 0.009) |
| AT "turn speeds" | both bones above (traverse and elevation) | cannon defs `{bone "turret"}`, `{bone "gun_rot"}` | [I] |
| stealth | visibility multiplier of the unit's vision term: def `{props ... "vision_cannon_X"}` -> `set/vision/settings.set` (`{cannon_05_vet actor "vision_cannon_maximum_vet"}`) -> value in the `"cannon"` define of `set/vision/vision_presets.inc` (`cannon_05` 1.7, `cannon_05_vet` 1.53; firing/visible/still scale the same) | props line of the def | [I] "+10% stealth" read as visibility x0.90 (+20% as x0.80). No `_elite` term exists, so elite cannons can only use the `_vet` (x0.90) term |
| reload | effective `rechargeTime` of the weapon in each `{Weaponry {place "x" {weapon "name"}}}`, base place vs same place in the vet; compared per ammo `{parameters}` block (21-22 blocks per gun from `gun/.presets`, all equal unless stated) | `set/stuff/gun/*`, often through `{from}` and the `range_*` macros of `gun/.presets` (`range_medium_howitzer` sets 12, `range_light_howitzer` 8) | [V] resolver; `mp` on and off give the same reload for every weapon here. MG and small-arm places are not held to the rule (listed as info) |

Not used: `{placer}` carries no speeds in these defs; no other speed or stealth key differs between base and vet.

## Units and classification

46 vet/elite defs (45 audited + mg42_lafette_vet) found under `entity/-vehicle/**` (names with `_vet`, `_veteran`, `_elite`, `_elite_gun`, `elite_`, `veteran_`, `_ace`). `_ace` is read as elite [I]. Also checked, not counted: `pz5g_veteran/panther5g_hungarian.def` (normal name, base gun). Excluded: the `cannon/x/*_x`, `*_xx` and `mortars/x/` defs (wreck models, only `{Extension "*_x.mdl"}`), `44m_buzoganyveto` (Hungarian name, not a vet), humanskins and inventory.
MP buy lists (`set/multiplayer/units/**`): every vehicle/cannon flagged vet/elite/ace there points at one of these defs; none missing. Not sold in MP (def only): m26e4_ace, pz6e_hun_vet, m4a4_firefly_vet, stug4g_vet, t34_3_fin_vet, turan2_vet.

Base pairing: suffix/prefix stripped, same folder; `veteran_tiger` -> `pz6e` (same Pz6e.mdl, smallest diff), `pz6e_hun_vet` -> `pz6e_hun`, `pz6bh_vet`/`pz6bh_ace` -> `tank_heavy/pz6bh/pz6bh`, `pz5g_veteran`/`pz5g_ace` -> `tank_medium/pz5g/pz5g`. Every unit found a base.

Cannon classification (owner please correct):

| unit | class | reason |
|---|---|---|
| flak36a_vet | AT | 88 mm Flak 36, direct-fire tank-gun table (88mm_flak36), AA/AT dual role |
| pak43_vet | AT | 88 mm PaK 43 |
| pak38_elite | AT | 50 mm PaK 38 |
| elite_resita | AT | 75 mm Resita M1943 |
| type4_75mm_elite | AT | Type 4 75 mm AA gun, direct fire, no howitzer curve [I] |
| longtom_155mm_vet | artillery | 155 mm Long Tom |
| m115_vet | artillery | 203 mm M115 |
| m114_vet | artillery | 155 mm M114 |
| m2a1l_vet | artillery | 105 mm M2A1 |
| pdr25_vet | artillery | 25-pounder gun-howitzer [I] (if AT: its `gun` place x0.60 would be off too) |
| type4_200mm_elite | artillery | Type 4 200 mm rocket launcher; no elite artillery rule, vet x0.60 applied [I] |
| pm_38_vet, sgrw_42_vet, sgrw_34_vet | artillery | mortars |
| mg42_lafette_vet | not audited | MG 42 tripod: no rule for MG emplacements |

Vehicles: all 31 in `tank_heavy`/`tank_medium` (tanks, tank destroyers, assault guns, SPGs m12gmc / m149 / m9053, assault howitzer stuh42) get the vehicle rule.

## Counts

| class | grade | units audited | fully conforming | off | rule rows checked | rows off | rows unchanged where a change is due | rounding-only rows |
|---|---|---|---|---|---|---|---|---|
| vehicles | vet | 21 | 9 | 12 | 170 | 22 | 40 | 9 |
| vehicles | elite | 10 | 4 | 6 | 80 | 9 | 24 | 0 |
| AT cannons | vet | 2 | 0 | 2 | 11 | 5 | 0 | 0 |
| AT cannons | elite | 3 | 0 | 3 | 17 | 9 | 1 | 0 |
| artillery | vet | 8 | 4 | 4 | 13 | 3 | 1 | 0 |
| artillery | elite | 1 | 1 | 0 | 1 | 0 | 0 | 0 |
| **all** | | **45** | **18** | **27** | 292 | 48 | 66 | 9 |

Fully conforming: m115_vet, type4_200mm_elite, pm_38_vet, sgrw_42_vet, sgrw_34_vet, is2_elite, m26_pershing_vet, pz6bh_ace, pz6bh_vet, veteran_tiger, m36_vet, m4a3e2_jumbo_76_vet, m4a4_firefly_vet, pz4h_vet, pz4j_vet, pz5g_ace, pz5g_veteran, t34_3_elite.

Counts exclude mg42_lafette_vet (no rule) and panther5g_hungarian (not flagged). "off" = at least one rule field off or unchanged. Rows: one per field, gear and ammo groups expanded.

## Deviations (only rows that are off or unchanged)

Off by = actual minus expected (factor for x-rules, absolute for +-rules). Statuses: `off` changed but not as the rule says; `unchanged` vet equals base where a change is due.

### vehicles

Grouped (same field, same actual change):

- VEH/vet gears: +0 (unchanged) instead of +0.03: 7 units: pz6e_hun_vet, m12gmc_vet, m149_vet, m9053_vet, t34_3_fin_vet, turan2_vet, turan3_vet
- VEH/vet gun_speed: +0 (unchanged) instead of +0.0002: 6 units: pz6e_hun_vet, m12gmc_vet, m149_vet, m9053_vet, turan2_vet, turan3_vet
- VEH/vet starttime: x1 (unchanged) instead of x0.85: 6 units: pz6e_hun_vet, m12gmc_vet, m149_vet, m9053_vet, t34_3_fin_vet, turan3_vet
- VEH/vet turntime: x1 (unchanged) instead of x0.9: 6 units: pz6e_hun_vet, m12gmc_vet, m149_vet, m9053_vet, t34_3_fin_vet, turan3_vet
- VEH/vet turret_speed: +0.0002 instead of +0.0001: 5 units: jagdpanther_vet, jagdpanzer_iv_vet, stug3g_vet, stug4g_vet, stuh42_vet
- VEH/elite gears: +0 (unchanged) instead of +0.06: 3 units: achilles_elite_gun, cometa34_elite_gun, m4a4_firefly_elite_gun
- VEH/elite gun_speed: +0 (unchanged) instead of +0.0004: 3 units: achilles_elite_gun, cometa34_elite_gun, m4a4_firefly_elite_gun
- VEH/elite reload: x1 (unchanged) instead of x0.7: 3 units: achilles_elite_gun, cometa34_elite_gun, m4a4_firefly_elite_gun
- VEH/elite starttime: x1 (unchanged) instead of x0.75: 3 units: achilles_elite_gun, cometa34_elite_gun, m4a4_firefly_elite_gun
- VEH/elite turntime: x1 (unchanged) instead of x0.8: 3 units: achilles_elite_gun, cometa34_elite_gun, m4a4_firefly_elite_gun
- VEH/elite turret_speed: +0 (unchanged) instead of +0.0002: 3 units: achilles_elite_gun, cometa34_elite_gun, m4a4_firefly_elite_gun
- VEH/vet turret_speed: +0 (unchanged) instead of +0.0001: 3 units: m12gmc_vet, m149_vet, m9053_vet
- VEH/elite starttime: x0.7 instead of x0.75: 2 units: pz6e_ace, stug3g_ace
- VEH/vet gears: +0.05 instead of +0.03: 2 units: pz6e_hun_vet, turan2_vet
- VEH/vet reload: x1 (unchanged) instead of x0.85: 2 units: m149_vet, m9053_vet
- VEH/vet turret_speed: +0.0015 instead of +0.0001: 2 units: pz6e_hun_vet, turan3_vet
- VEH/elite gears: +0.08 instead of +0.06: 1 unit: m26e4_ace
- VEH/elite gears: +0.11 instead of +0.06: 1 unit: m26e4_ace
- VEH/elite gun_speed: +0.0005 instead of +0.0004: 1 unit: m26e4_ace
- VEH/elite turntime: x0.84615 instead of x0.8: 1 unit: m26e4_ace
- VEH/elite turret_speed: +0.0004 instead of +0.0002: 1 unit: stug3g_ace
- VEH/elite turret_speed: +0.0005 instead of +0.0002: 1 unit: m26e4_ace
- VEH/vet gears: +0.125 instead of +0.03: 1 unit: t34_3_fin_vet
- VEH/vet gears: +0.45 instead of +0.03: 1 unit: turan2_vet
- VEH/vet gun_speed: +0.0025 instead of +0.0002: 1 unit: t34_3_fin_vet
- VEH/vet reload: x0.6 instead of x0.85: 1 unit: m12gmc_vet
- VEH/vet reload: x0.6875 instead of x0.85: 1 unit: turan2_vet
- VEH/vet reload: x0.69 instead of x0.85: 1 unit: m12gmc_vet
- VEH/vet reload: x0.9625 instead of x0.85: 1 unit: stuh42_vet
- VEH/vet reload: x0.97143 instead of x0.85: 1 unit: turan3_vet
- VEH/vet starttime: x0.66667 instead of x0.85: 1 unit: turan2_vet
- VEH/vet turntime: x0.84211 instead of x0.9: 1 unit: stug4g_vet
- VEH/vet turntime: x0.94737 instead of x0.9: 1 unit: turan2_vet
- VEH/vet turret_speed: +0.0033 instead of +0.0001: 1 unit: turan2_vet
- VEH/vet turret_speed: +0.0057 instead of +0.0001: 1 unit: t34_3_fin_vet

| unit (vet def) | base def | field | base | vet | expected | rule | actual | off by | status |
|---|---|---|---|---|---|---|---|---|---|
| tank_heavy/m26e4/m26e4_ace.def | tank_heavy/m26e4/m26e4.def | turntime: locomotion TurnTime | 26 | 22 | 20.8 | x0.8 | x0.84615 | +0.046154 (factor) | off |
| tank_heavy/m26e4/m26e4_ace.def | tank_heavy/m26e4/m26e4.def | gears: Gears[1/4] | 0.1 | 0.18 | 0.16 | +0.06 | +0.08 | +0.02 | off |
| tank_heavy/m26e4/m26e4_ace.def | tank_heavy/m26e4/m26e4.def | gears: Gears[2/4] | 0.18 | 0.26 | 0.24 | +0.06 | +0.08 | +0.02 | off |
| tank_heavy/m26e4/m26e4_ace.def | tank_heavy/m26e4/m26e4.def | gears: Gears[3/4] | 0.25 | 0.36 | 0.31 | +0.06 | +0.11 | +0.05 | off |
| tank_heavy/m26e4/m26e4_ace.def | tank_heavy/m26e4/m26e4.def | turret_speed: bone turret speed | 0.0025 | 0.003 | 0.0027 | +0.0002 | +0.0005 | +0.0003 | off |
| tank_heavy/m26e4/m26e4_ace.def | tank_heavy/m26e4/m26e4.def | gun_speed: bone gun_rot speed | 0.0005 | 0.001 | 0.0009 | +0.0004 | +0.0005 | +0.0001 | off |
| tank_heavy/pz6e/pz6e_hun_vet.def | tank_heavy/pz6e/pz6e_hun.def | starttime: locomotion StartTime | 36 | 36 | 30.6 | x0.85 | x1 | +0.15 (factor) | unchanged |
| tank_heavy/pz6e/pz6e_hun_vet.def | tank_heavy/pz6e/pz6e_hun.def | turntime: locomotion TurnTime | 24 | 24 | 21.6 | x0.9 | x1 | +0.1 (factor) | unchanged |
| tank_heavy/pz6e/pz6e_hun_vet.def | tank_heavy/pz6e/pz6e_hun.def | gears: Gears[1/3] | 0.1 | 0.1 | 0.13 | +0.03 | +0 | -0.03 | unchanged |
| tank_heavy/pz6e/pz6e_hun_vet.def | tank_heavy/pz6e/pz6e_hun.def | gears: Gears[2/3] | 0.2 | 0.2 | 0.23 | +0.03 | +0 | -0.03 | unchanged |
| tank_heavy/pz6e/pz6e_hun_vet.def | tank_heavy/pz6e/pz6e_hun.def | gears: Gears[3/3] | 0.7 | 0.75 | 0.73 | +0.03 | +0.05 | +0.02 | off |
| tank_heavy/pz6e/pz6e_hun_vet.def | tank_heavy/pz6e/pz6e_hun.def | turret_speed: bone turret speed | 0.002 | 0.0035 | 0.0021 | +0.0001 | +0.0015 | +0.0014 | off |
| tank_heavy/pz6e/pz6e_hun_vet.def | tank_heavy/pz6e/pz6e_hun.def | gun_speed: bone gun_rot speed | 0.01 | 0.01 | 0.0102 | +0.0002 | +0 | -0.0002 | unchanged |
| tank_heavy/pz6e_ace/pz6e_ace.def | tank_heavy/pz6e/pz6e.def | starttime: locomotion StartTime | 60 | 42 | 45 | x0.75 | x0.7 | -0.05 (factor) | off |
| tank_medium/achilles/achilles_elite_gun.def | tank_medium/achilles/achilles.def | starttime: locomotion StartTime | 30 | 30 | 22.5 | x0.75 | x1 | +0.25 (factor) | unchanged |
| tank_medium/achilles/achilles_elite_gun.def | tank_medium/achilles/achilles.def | turntime: locomotion TurnTime | 17 | 17 | 13.6 | x0.8 | x1 | +0.2 (factor) | unchanged |
| tank_medium/achilles/achilles_elite_gun.def | tank_medium/achilles/achilles.def | gears: Gears[1/4] | 0.1 | 0.1 | 0.16 | +0.06 | +0 | -0.06 | unchanged |
| tank_medium/achilles/achilles_elite_gun.def | tank_medium/achilles/achilles.def | gears: Gears[2/4] | 0.2 | 0.2 | 0.26 | +0.06 | +0 | -0.06 | unchanged |
| tank_medium/achilles/achilles_elite_gun.def | tank_medium/achilles/achilles.def | gears: Gears[3/4] | 0.3 | 0.3 | 0.36 | +0.06 | +0 | -0.06 | unchanged |
| tank_medium/achilles/achilles_elite_gun.def | tank_medium/achilles/achilles.def | turret_speed: bone turret speed | 0.002 | 0.002 | 0.0022 | +0.0002 | +0 | -0.0002 | unchanged |
| tank_medium/achilles/achilles_elite_gun.def | tank_medium/achilles/achilles.def | gun_speed: bone gun_rot speed | 0.0007 | 0.0007 | 0.0011 | +0.0004 | +0 | -0.0004 | unchanged |
| tank_medium/achilles/achilles_elite_gun.def | tank_medium/achilles/achilles.def | reload: place gun: 76mm_mk4_2 -> 76mm_mk4_2elite [22 ammo blocks incl. default] | 8 | 8 | 5.6 | x0.7 | x1 | +0.3 (factor) | unchanged |
| tank_medium/cometa34/cometa34_elite_gun.def | tank_medium/cometa34/cometa34.def | starttime: locomotion StartTime | 28 | 28 | 21 | x0.75 | x1 | +0.25 (factor) | unchanged |
| tank_medium/cometa34/cometa34_elite_gun.def | tank_medium/cometa34/cometa34.def | turntime: locomotion TurnTime | 18 | 18 | 14.4 | x0.8 | x1 | +0.2 (factor) | unchanged |
| tank_medium/cometa34/cometa34_elite_gun.def | tank_medium/cometa34/cometa34.def | gears: Gears[1/4] | 0.15 | 0.15 | 0.21 | +0.06 | +0 | -0.06 | unchanged |
| tank_medium/cometa34/cometa34_elite_gun.def | tank_medium/cometa34/cometa34.def | gears: Gears[2/4] | 0.25 | 0.25 | 0.31 | +0.06 | +0 | -0.06 | unchanged |
| tank_medium/cometa34/cometa34_elite_gun.def | tank_medium/cometa34/cometa34.def | gears: Gears[3/4] | 0.35 | 0.35 | 0.41 | +0.06 | +0 | -0.06 | unchanged |
| tank_medium/cometa34/cometa34_elite_gun.def | tank_medium/cometa34/cometa34.def | turret_speed: bone turret speed | 0.0034 | 0.0034 | 0.0036 | +0.0002 | +0 | -0.0002 | unchanged |
| tank_medium/cometa34/cometa34_elite_gun.def | tank_medium/cometa34/cometa34.def | gun_speed: bone gun_rot speed | 0.0007 | 0.0007 | 0.0011 | +0.0004 | +0 | -0.0004 | unchanged |
| tank_medium/cometa34/cometa34_elite_gun.def | tank_medium/cometa34/cometa34.def | reload: place gun: 77mm_hv -> 77mm_hv_elite [22 ammo blocks incl. default] | 8.8 | 8.8 | 6.16 | x0.7 | x1 | +0.3 (factor) | unchanged |
| tank_medium/jagdpanther/jagdpanther_vet.def | tank_medium/jagdpanther/jagdpanther.def | turret_speed: bone turret speed | 0.001 | 0.0012 | 0.0011 | +0.0001 | +0.0002 | +0.0001 | off |
| tank_medium/jagdpanzer_iv/jagdpanzer_iv_vet.def | tank_medium/jagdpanzer_iv/jagdpanzer_iv.def | turret_speed: bone gun_rot2 speed | 0.001 | 0.0012 | 0.0011 | +0.0001 | +0.0002 | +0.0001 | off |
| tank_medium/m12gmc/m12gmc_vet.def | tank_medium/m12gmc/m12gmc.def | starttime: locomotion StartTime | 30 | 30 | 25.5 | x0.85 | x1 | +0.15 (factor) | unchanged |
| tank_medium/m12gmc/m12gmc_vet.def | tank_medium/m12gmc/m12gmc.def | turntime: locomotion TurnTime | 17 | 17 | 15.3 | x0.9 | x1 | +0.1 (factor) | unchanged |
| tank_medium/m12gmc/m12gmc_vet.def | tank_medium/m12gmc/m12gmc.def | gears: Gears[1/4] | 0.1 | 0.1 | 0.13 | +0.03 | +0 | -0.03 | unchanged |
| tank_medium/m12gmc/m12gmc_vet.def | tank_medium/m12gmc/m12gmc.def | gears: Gears[2/4] | 0.2 | 0.2 | 0.23 | +0.03 | +0 | -0.03 | unchanged |
| tank_medium/m12gmc/m12gmc_vet.def | tank_medium/m12gmc/m12gmc.def | gears: Gears[3/4] | 0.3 | 0.3 | 0.33 | +0.03 | +0 | -0.03 | unchanged |
| tank_medium/m12gmc/m12gmc_vet.def | tank_medium/m12gmc/m12gmc.def | turret_speed: bone mantlet speed | 0.0005 | 0.0005 | 0.0006 | +0.0001 | +0 | -0.0001 | unchanged |
| tank_medium/m12gmc/m12gmc_vet.def | tank_medium/m12gmc/m12gmc.def | gun_speed: bone gun_rot speed | 0.0005 | 0.0005 | 0.0007 | +0.0002 | +0 | -0.0002 | unchanged |
| tank_medium/m12gmc/m12gmc_vet.def | tank_medium/m12gmc/m12gmc.def | reload: place gun: 155mm_m12 -> 155mm_m12_vet [19 ammo blocks incl. default] | 20 | 13.8 | 17 | x0.85 | x0.69 | -0.16 (factor) | off |
| tank_medium/m12gmc/m12gmc_vet.def | tank_medium/m12gmc/m12gmc.def | reload: place gun1_2: 155mm_m12_2 -> 155mm_m12_2_vet [21 ammo blocks incl. default] | 20 | 12 | 17 | x0.85 | x0.6 | -0.25 (factor) | off |
| tank_medium/m149/m149_vet.def | tank_medium/m149/m149.def | starttime: locomotion StartTime | 30 | 30 | 25.5 | x0.85 | x1 | +0.15 (factor) | unchanged |
| tank_medium/m149/m149_vet.def | tank_medium/m149/m149.def | turntime: locomotion TurnTime | 17 | 17 | 15.3 | x0.9 | x1 | +0.1 (factor) | unchanged |
| tank_medium/m149/m149_vet.def | tank_medium/m149/m149.def | gears: Gears[1/4] | 0.1 | 0.1 | 0.13 | +0.03 | +0 | -0.03 | unchanged |
| tank_medium/m149/m149_vet.def | tank_medium/m149/m149.def | gears: Gears[2/4] | 0.2 | 0.2 | 0.23 | +0.03 | +0 | -0.03 | unchanged |
| tank_medium/m149/m149_vet.def | tank_medium/m149/m149.def | gears: Gears[3/4] | 0.3 | 0.3 | 0.33 | +0.03 | +0 | -0.03 | unchanged |
| tank_medium/m149/m149_vet.def | tank_medium/m149/m149.def | turret_speed: bone turret speed | 0.0005 | 0.0005 | 0.0006 | +0.0001 | +0 | -0.0001 | unchanged |
| tank_medium/m149/m149_vet.def | tank_medium/m149/m149.def | gun_speed: bone gun_rot speed | 0.0005 | 0.0005 | 0.0007 | +0.0002 | +0 | -0.0002 | unchanged |
| tank_medium/m149/m149_vet.def | tank_medium/m149/m149.def | reload: place gun: 149mm_obice -> 149mm_obice_vet [19 ammo blocks incl. default] | 13.8 | 13.8 | 11.73 | x0.85 | x1 | +0.15 (factor) | unchanged |
| tank_medium/m4a4_firefly/m4a4_firefly_elite_gun.def | tank_medium/m4a4_firefly/m4a4_firefly.def | starttime: locomotion StartTime | 34 | 34 | 25.5 | x0.75 | x1 | +0.25 (factor) | unchanged |
| tank_medium/m4a4_firefly/m4a4_firefly_elite_gun.def | tank_medium/m4a4_firefly/m4a4_firefly.def | turntime: locomotion TurnTime | 18 | 18 | 14.4 | x0.8 | x1 | +0.2 (factor) | unchanged |
| tank_medium/m4a4_firefly/m4a4_firefly_elite_gun.def | tank_medium/m4a4_firefly/m4a4_firefly.def | gears: Gears[1/4] | 0.1 | 0.1 | 0.16 | +0.06 | +0 | -0.06 | unchanged |
| tank_medium/m4a4_firefly/m4a4_firefly_elite_gun.def | tank_medium/m4a4_firefly/m4a4_firefly.def | gears: Gears[2/4] | 0.2 | 0.2 | 0.26 | +0.06 | +0 | -0.06 | unchanged |
| tank_medium/m4a4_firefly/m4a4_firefly_elite_gun.def | tank_medium/m4a4_firefly/m4a4_firefly.def | gears: Gears[3/4] | 0.3 | 0.3 | 0.36 | +0.06 | +0 | -0.06 | unchanged |
| tank_medium/m4a4_firefly/m4a4_firefly_elite_gun.def | tank_medium/m4a4_firefly/m4a4_firefly.def | turret_speed: bone turret speed | 0.0041 | 0.0041 | 0.0043 | +0.0002 | +0 | -0.0002 | unchanged |
| tank_medium/m4a4_firefly/m4a4_firefly_elite_gun.def | tank_medium/m4a4_firefly/m4a4_firefly.def | gun_speed: bone gun_rot speed | 0.0007 | 0.0007 | 0.0011 | +0.0004 | +0 | -0.0004 | unchanged |
| tank_medium/m4a4_firefly/m4a4_firefly_elite_gun.def | tank_medium/m4a4_firefly/m4a4_firefly.def | reload: place gun: 76mm_mk4 -> 76mm_mk4_elite [22 ammo blocks incl. default] | 9.5 | 9.5 | 6.65 | x0.7 | x1 | +0.3 (factor) | unchanged |
| tank_medium/m9053/m9053_vet.def | tank_medium/m9053/m9053.def | starttime: locomotion StartTime | 30 | 30 | 25.5 | x0.85 | x1 | +0.15 (factor) | unchanged |
| tank_medium/m9053/m9053_vet.def | tank_medium/m9053/m9053.def | turntime: locomotion TurnTime | 17 | 17 | 15.3 | x0.9 | x1 | +0.1 (factor) | unchanged |
| tank_medium/m9053/m9053_vet.def | tank_medium/m9053/m9053.def | gears: Gears[1/4] | 0.1 | 0.1 | 0.13 | +0.03 | +0 | -0.03 | unchanged |
| tank_medium/m9053/m9053_vet.def | tank_medium/m9053/m9053.def | gears: Gears[2/4] | 0.2 | 0.2 | 0.23 | +0.03 | +0 | -0.03 | unchanged |
| tank_medium/m9053/m9053_vet.def | tank_medium/m9053/m9053.def | gears: Gears[3/4] | 0.3 | 0.3 | 0.33 | +0.03 | +0 | -0.03 | unchanged |
| tank_medium/m9053/m9053_vet.def | tank_medium/m9053/m9053.def | turret_speed: bone turret speed | 0.004 | 0.004 | 0.0041 | +0.0001 | +0 | -0.0001 | unchanged |
| tank_medium/m9053/m9053_vet.def | tank_medium/m9053/m9053.def | gun_speed: bone gun_rot speed | 0.002 | 0.002 | 0.0022 | +0.0002 | +0 | -0.0002 | unchanged |
| tank_medium/m9053/m9053_vet.def | tank_medium/m9053/m9053.def | reload: place gun: 90mm_m90_53 -> 90mm_m90_53_vet [21 ammo blocks incl. default] | 9 | 9 | 7.65 | x0.85 | x1 | +0.15 (factor) | unchanged |
| tank_medium/stug3g/stug3g_vet.def | tank_medium/stug3g/stug3g.def | turret_speed: bone gun_rot2 speed | 0.002 | 0.0022 | 0.0021 | +0.0001 | +0.0002 | +0.0001 | off |
| tank_medium/stug3g_ace/stug3g_ace.def | tank_medium/stug3g/stug3g.def | starttime: locomotion StartTime | 35 | 24.5 | 26.25 | x0.75 | x0.7 | -0.05 (factor) | off |
| tank_medium/stug3g_ace/stug3g_ace.def | tank_medium/stug3g/stug3g.def | turret_speed: bone gun_rot2 speed | 0.002 | 0.0024 | 0.0022 | +0.0002 | +0.0004 | +0.0002 | off |
| tank_medium/stug4g/stug4g_vet.def | tank_medium/stug4g/stug4g.def | turntime: locomotion TurnTime | 19 | 16 | 17.1 | x0.9 | x0.84211 | -0.057895 (factor) | off |
| tank_medium/stug4g/stug4g_vet.def | tank_medium/stug4g/stug4g.def | turret_speed: bone gun_rot2 speed | 0.002 | 0.0022 | 0.0021 | +0.0001 | +0.0002 | +0.0001 | off |
| tank_medium/stuh42/stuh42_vet.def | tank_medium/stuh42/stuh42.def | turret_speed: bone gun_rot2 speed | 0.001 | 0.0012 | 0.0011 | +0.0001 | +0.0002 | +0.0001 | off |
| tank_medium/stuh42/stuh42_vet.def | tank_medium/stuh42/stuh42.def | reload: place gun: 105mm_stuh42 -> 105mm_stuh42_vet [22 ammo blocks incl. default] | 16 | 15.4 | 13.6 | x0.85 | x0.9625 | +0.1125 (factor) | off |
| tank_medium/t34_3_fin/t34_3_fin_vet.def | tank_medium/t34_3_fin/t34_3_fin.def | starttime: locomotion StartTime | 24 | 24 | 20.4 | x0.85 | x1 | +0.15 (factor) | unchanged |
| tank_medium/t34_3_fin/t34_3_fin_vet.def | tank_medium/t34_3_fin/t34_3_fin.def | turntime: locomotion TurnTime | 16 | 16 | 14.4 | x0.9 | x1 | +0.1 (factor) | unchanged |
| tank_medium/t34_3_fin/t34_3_fin_vet.def | tank_medium/t34_3_fin/t34_3_fin.def | gears: Gears[1/3] | 0.1 | 0.1 | 0.13 | +0.03 | +0 | -0.03 | unchanged |
| tank_medium/t34_3_fin/t34_3_fin_vet.def | tank_medium/t34_3_fin/t34_3_fin.def | gears: Gears[2/3] | 0.25 | 0.25 | 0.28 | +0.03 | +0 | -0.03 | unchanged |
| tank_medium/t34_3_fin/t34_3_fin_vet.def | tank_medium/t34_3_fin/t34_3_fin.def | gears: Gears[3/3] | 0.625 | 0.75 | 0.655 | +0.03 | +0.125 | +0.095 | off |
| tank_medium/t34_3_fin/t34_3_fin_vet.def | tank_medium/t34_3_fin/t34_3_fin.def | turret_speed: bone turret speed | 0.0043 | 0.01 | 0.0044 | +0.0001 | +0.0057 | +0.0056 | off |
| tank_medium/t34_3_fin/t34_3_fin_vet.def | tank_medium/t34_3_fin/t34_3_fin.def | gun_speed: bone gun_rot speed | 0.0005 | 0.003 | 0.0007 | +0.0002 | +0.0025 | +0.0023 | off |
| tank_medium/turan2/turan2_vet.def | tank_medium/turan2/turan2.def | starttime: locomotion StartTime | 45 | 30 | 38.25 | x0.85 | x0.66667 | -0.18333 (factor) | off |
| tank_medium/turan2/turan2_vet.def | tank_medium/turan2/turan2.def | turntime: locomotion TurnTime | 19 | 18 | 17.1 | x0.9 | x0.94737 | +0.047368 (factor) | off |
| tank_medium/turan2/turan2_vet.def | tank_medium/turan2/turan2.def | gears: Gears[1/4] | 0.1 | 0.1 | 0.13 | +0.03 | +0 | -0.03 | unchanged |
| tank_medium/turan2/turan2_vet.def | tank_medium/turan2/turan2.def | gears: Gears[2/4] | 0.2 | 0.25 | 0.23 | +0.03 | +0.05 | +0.02 | off |
| tank_medium/turan2/turan2_vet.def | tank_medium/turan2/turan2.def | gears: Gears[3/4] | 0.3 | 0.75 | 0.33 | +0.03 | +0.45 | +0.42 | off |
| tank_medium/turan2/turan2_vet.def | tank_medium/turan2/turan2.def | turret_speed: bone turret speed | 0.0012 | 0.0045 | 0.0013 | +0.0001 | +0.0033 | +0.0032 | off |
| tank_medium/turan2/turan2_vet.def | tank_medium/turan2/turan2.def | gun_speed: bone mantlet speed | 0.009 | 0.009 | 0.0092 | +0.0002 | +0 | -0.0002 | unchanged |
| tank_medium/turan2/turan2_vet.def | tank_medium/turan2/turan2.def | reload: place gun: 75mm_41m -> 75mm_41m_vet [21 ammo blocks incl. default] | 8 | 5.5 | 6.8 | x0.85 | x0.6875 | -0.1625 (factor) | off |
| tank_medium/turan3/turan3_vet.def | tank_medium/turan3/turan3.def | starttime: locomotion StartTime | 45 | 45 | 38.25 | x0.85 | x1 | +0.15 (factor) | unchanged |
| tank_medium/turan3/turan3_vet.def | tank_medium/turan3/turan3.def | turntime: locomotion TurnTime | 19 | 19 | 17.1 | x0.9 | x1 | +0.1 (factor) | unchanged |
| tank_medium/turan3/turan3_vet.def | tank_medium/turan3/turan3.def | gears: Gears[1/4] | 0.1 | 0.1 | 0.13 | +0.03 | +0 | -0.03 | unchanged |
| tank_medium/turan3/turan3_vet.def | tank_medium/turan3/turan3.def | gears: Gears[2/4] | 0.2 | 0.2 | 0.23 | +0.03 | +0 | -0.03 | unchanged |
| tank_medium/turan3/turan3_vet.def | tank_medium/turan3/turan3.def | gears: Gears[3/4] | 0.3 | 0.3 | 0.33 | +0.03 | +0 | -0.03 | unchanged |
| tank_medium/turan3/turan3_vet.def | tank_medium/turan3/turan3.def | turret_speed: bone turret speed | 0.003 | 0.0045 | 0.0031 | +0.0001 | +0.0015 | +0.0014 | off |
| tank_medium/turan3/turan3_vet.def | tank_medium/turan3/turan3.def | gun_speed: bone mantlet speed | 0.009 | 0.009 | 0.0092 | +0.0002 | +0 | -0.0002 | unchanged |
| tank_medium/turan3/turan3_vet.def | tank_medium/turan3/turan3.def | reload: place gun: 75mm_43m -> 75mm_43m_vet [22 ammo blocks incl. default] | 7 | 6.8 | 5.95 | x0.85 | x0.97143 | +0.12143 (factor) | off |

### AT cannons

Grouped (same field, same actual change):

- AT/elite stealth: x0.9 instead of x0.8: 3 units: pak38_elite, elite_resita, type4_75mm_elite
- AT/elite turntime: x0.9 instead of x0.8: 3 units: pak38_elite, elite_resita, type4_75mm_elite
- AT/vet gun_speed: +0.0003 instead of +0.003: 2 units: flak36a_vet, pak43_vet
- AT/vet turret_speed: +0.0003 instead of +0.003: 2 units: flak36a_vet, pak43_vet
- AT/elite gun_speed: +0.0004 instead of +0.006: 1 unit: type4_75mm_elite
- AT/elite reload: x0.8 instead of x0.6: 1 unit: elite_resita
- AT/elite reload: x1 (unchanged) instead of x0.6: 1 unit: elite_resita
- AT/elite turret_speed: +0.002 instead of +0.006: 1 unit: type4_75mm_elite
- AT/vet reload: x0.85 instead of x0.8: 1 unit: pak43_vet

| unit (vet def) | base def | field | base | vet | expected | rule | actual | off by | status |
|---|---|---|---|---|---|---|---|---|---|
| cannon/flak36a/flak36a_vet.def | cannon/flak36a/flak36a.def | turret_speed: bone turret speed | 0.002 | 0.0023 | 0.005 | +0.003 | +0.0003 | -0.0027 | off |
| cannon/flak36a/flak36a_vet.def | cannon/flak36a/flak36a.def | gun_speed: bone gun_rot speed | 0.0005 | 0.0008 | 0.0035 | +0.003 | +0.0003 | -0.0027 | off |
| cannon/pak38/pak38_elite.def | cannon/pak38/pak38.def | turntime: locomotion TurnTime | 16 | 14.4 | 12.8 | x0.8 | x0.9 | +0.1 (factor) | off |
| cannon/pak38/pak38_elite.def | cannon/pak38/pak38.def | stealth: vision prop vision_cannon_medium -> vision_cannon_medium_vet | 1.2 | 1.08 | 0.96 | x0.8 | x0.9 | +0.1 (factor) | off |
| cannon/pak43/pak43_vet.def | cannon/pak43/pak43.def | turret_speed: bone turret speed | 0.0005 | 0.0008 | 0.0035 | +0.003 | +0.0003 | -0.0027 | off |
| cannon/pak43/pak43_vet.def | cannon/pak43/pak43.def | gun_speed: bone gun_rot speed | 0.0004 | 0.0007 | 0.0034 | +0.003 | +0.0003 | -0.0027 | off |
| cannon/pak43/pak43_vet.def | cannon/pak43/pak43.def | reload: place gun: 88mm_pak43 -> 88mm_pak43_vet [22 ammo blocks incl. default] | 11 | 9.35 | 8.8 | x0.8 | x0.85 | +0.05 (factor) | off |
| cannon/resita/elite_resita.def | cannon/resita/resita.def | turntime: locomotion TurnTime | 16 | 14.4 | 12.8 | x0.8 | x0.9 | +0.1 (factor) | off |
| cannon/resita/elite_resita.def | cannon/resita/resita.def | stealth: vision prop vision_cannon_medium -> vision_cannon_medium_vet | 1.2 | 1.08 | 0.96 | x0.8 | x0.9 | +0.1 (factor) | off |
| cannon/resita/elite_resita.def | cannon/resita/resita.def | reload: place gun: 75mm_dt -> 75mm_dt_elite [22 ammo blocks incl. default] | 5 | 4 | 3 | x0.6 | x0.8 | +0.2 (factor) | off |
| cannon/resita/elite_resita.def | cannon/resita/resita.def | reload: place gun1_2: 75mm_dt_2 -> 75mm_dt_2 [19 ammo blocks incl. default] | 7 | 7 | 4.2 | x0.6 | x1 | +0.4 (factor) | unchanged |
| cannon/type4_75mm/type4_75mm_elite.def | cannon/type4_75mm/type4_75mm.def | turntime: locomotion TurnTime | 25 | 22.5 | 20 | x0.8 | x0.9 | +0.1 (factor) | off |
| cannon/type4_75mm/type4_75mm_elite.def | cannon/type4_75mm/type4_75mm.def | turret_speed: bone turret speed | 0.002 | 0.004 | 0.008 | +0.006 | +0.002 | -0.004 | off |
| cannon/type4_75mm/type4_75mm_elite.def | cannon/type4_75mm/type4_75mm.def | gun_speed: bone gun_rot speed | 0.0005 | 0.0009 | 0.0065 | +0.006 | +0.0004 | -0.0056 | off |
| cannon/type4_75mm/type4_75mm_elite.def | cannon/type4_75mm/type4_75mm.def | stealth: vision prop vision_cannon_high -> vision_cannon_high_vet | 1.3 | 1.17 | 1.04 | x0.8 | x0.9 | +0.1 (factor) | off |

### artillery

Grouped (same field, same actual change):

- ART/vet reload: x0.69 instead of x0.6: 2 units: longtom_155mm_vet, m114_vet
- ART/vet reload: x0.8 instead of x0.6: 1 unit: m2a1l_vet
- ART/vet reload: x1 (unchanged) instead of x0.6: 1 unit: pdr25_vet

| unit (vet def) | base def | field | base | vet | expected | rule | actual | off by | status |
|---|---|---|---|---|---|---|---|---|---|
| cannon/longtom_155mm/longtom_155mm_vet.def | cannon/longtom_155mm/longtom_155mm.def | reload: place gun: 155mm_longtom -> 155mm_longtom_vet [19 ammo blocks incl. default] | 20 | 13.8 | 12 | x0.6 | x0.69 | +0.09 (factor) | off |
| cannon/m114/m114_vet.def | cannon/m114/m114.def | reload: place gun: 155mm_m114 -> 155mm_m114_vet [19 ammo blocks incl. default] | 20 | 13.8 | 12 | x0.6 | x0.69 | +0.09 (factor) | off |
| cannon/m2a1l/m2a1l_vet.def | cannon/m2a1l/m2a1l.def | reload: place gun: 105mm_m2a1 -> 105mm_m2a1_vet [19 ammo blocks incl. default] | 12 | 9.6 | 7.2 | x0.6 | x0.8 | +0.2 (factor) | off |
| cannon/pdr25/pdr25_vet.def | cannon/pdr25/pdr25.def | reload: place gun1_2: 88mm_oqfmk2_2 -> 88mm_oqfmk2_2 [21 ammo blocks incl. default] | 9.5 | 9.5 | 5.7 | x0.6 | x1 | +0.4 (factor) | unchanged |

## Rounding cases (counted as conforming)

- m26_pershing_vet reload (place gun: 90mm_m3 -> 90mm_m3_vet): 11.5 -> 9.77, expected 9.775 (x0.84957)
- pz6bh_vet reload (place gun: 88mm_kwk43 -> 88mm_kwk43_vet): 13 -> 11, expected 11.05 (x0.84615)
- jagdpanzer_iv_vet reload (place gun: 75mm_stuk42 -> 75mm_stuk42_vet): 8.5 -> 7.22, expected 7.225 (x0.84941)
- m36_vet reload (place gun: 90mm_m3_m36 -> 90mm_m3_m36_vet): 9.5 -> 8, expected 8.075 (x0.84211)
- m36_vet reload (place gun1_2: 90mm_m3_m36_2 -> 90mm_m3_m36_2_vet): 9.5 -> 8, expected 8.075 (x0.84211)
- m4a3e2_jumbo_76_vet reload (place gun: 76mm_m1a2 -> 76mm_m1a2_vet): 8.5 -> 7.22, expected 7.225 (x0.84941)
- m4a4_firefly_vet reload (place gun: 76mm_mk4 -> 76mm_mk4_vet): 9.5 -> 8, expected 8.075 (x0.84211)
- pz5g_veteran reload (place gun: 75mm_kwk42 -> 75mm_kwk42_veteran): 9.5 -> 8, expected 8.075 (x0.84211)
- stug4g_vet starttime (locomotion StartTime): 45 -> 38, expected 38.25 (x0.84444)

## panther5g_hungarian (not flagged vet, lives in pz5g_veteran folder)

- starttime locomotion StartTime: 50 -> 37.5 (off, change x0.75)
- turntime locomotion TurnTime: 20 -> 16 (off, change x0.8)
- gears Gears[1/4]: 0.1 -> 0.16 (off, change +0.06)
- gears Gears[2/4]: 0.2 -> 0.26 (off, change +0.06)
- gears Gears[3/4]: 0.3 -> 0.36 (off, change +0.06)
- turret_speed bone turret speed: 0.0028 -> 0.003 (off, change +0.0002)
- gun_speed bone gun_rot speed: 0.0006 -> 0.001 (off, change +0.0004)
- reload place gun: 75mm_kwk42 -> 75mm_kwk42: 9.5 -> 9.5 (unchanged, change x1)

## Changes outside the rules (info)

- pdr25_vet (ART/vet) turret_speed bone turret speed: 0.0007 -> 0.0009
- pdr25_vet (ART/vet) gun_speed bone gun_rot speed: 0.0007 -> 0.0009
- type4_200mm_elite (ART/elite) turntime locomotion TurnTime: 4 -> 3.6
- type4_200mm_elite (ART/elite) bone_other bone basis speed (info): 0.001 -> 0.007
- type4_200mm_elite (ART/elite) bone_other bone foresight speed (info): 0.004 -> 0.01
- type4_200mm_elite (ART/elite) stealth vision prop vision_cannon_medium -> vision_cannon_medium_vet: 1.2 -> 1.08
- mg42_lafette_vet (MG/vet) stealth vision prop vision_cannon_low -> vision_cannon_low_vet: 1.1 -> 0.99
- mg42_lafette_vet (MG/vet) reload place mgun: mg42_mount_optic -> mg42_mount_optic_vet [(weapon default),ap]: 9 -> 6.75 (MG/small arm: reload rule not applied)
- m26e4_ace (VEH/elite) maxspeed locomotion MaxSpeed (info, no rule): 26 -> 28
- m26e4_ace (VEH/elite) bone_other bone turret_mgun speed (info): 0.03 -> 0.04
- m4a3e2_jumbo_76_vet (VEH/vet) reload place mgun2: browning_m19_optic -> browning_an_m2 [(weapon default)]: 12 -> 9 (MG/small arm: reload rule not applied)
- m4a3e2_jumbo_76_vet (VEH/vet) reload_ammo_one_side place mgun2: browning_m19_optic -> browning_an_m2 [ap,inc]: - -> 9 (ammo block exists only in vet weapon)
- m9053_vet (VEH/vet) reload_ammo_one_side place gun: 90mm_m90_53 -> 90mm_m90_53_vet [heat_shell]: - -> 9 (ammo block exists only in vet weapon)
- stug4g_vet (VEH/vet) bone_other bone mgun_turret speed (info): 0.002 -> 0.0022
- turan2_vet (VEH/vet) maxspeed locomotion MaxSpeed (info, no rule): 30 -> 32
- turan2_vet (VEH/vet) reload_ammo_one_side place gun: 75mm_41m -> 75mm_41m_vet [heat_shell]: 8 -> - (ammo block exists only in base weapon)
- turan2_vet (VEH/vet) reload_ammo_one_side place gun: 75mm_41m -> 75mm_41m_vet [cu]: - -> 5.5 (ammo block exists only in vet weapon)

## Lists

**Vet/elite units with no findable base:** none.

**Vet/elite identical to base in a field that should change** (status `unchanged` above):
- whole unit unchanged except the gun stuff: achilles_elite_gun, cometa34_elite_gun, m4a4_firefly_elite_gun (and their elite gun keeps the base reload: 76mm_mk4_2elite 8, 77mm_hv_elite 8.8, 76mm_mk4_elite 9.5); m149_vet and m9053_vet (gun reload also unchanged: 149mm_obice_vet = 13.8, 90mm_m90_53_vet = 9); m12gmc_vet (only the gun is faster)
- chassis unchanged, turret changed: pz6e_hun_vet, turan3_vet, t34_3_fin_vet (start time, turn time, low gears)
- gun elevation unchanged: pz6e_hun_vet (model gun_rot 0.01 both), turan2_vet, turan3_vet (model mantlet 0.009 both)
- turan2_vet Gears[1] 0.1 unchanged
- second gun mode kept on the base weapon: pdr25_vet `gun1_2` 88mm_oqfmk2_2 (9.5), elite_resita `gun1_2` 75mm_dt_2 (7); no `_vet`/`_elite` stuff exists for them

**Base value absent so the rule cannot be applied:** none for a rule field. Ammo blocks present on one side only (not compared): m9053_vet `heat_shell` (vet only), turan2_vet `heat_shell` (base only) and `cu` (vet only), m4a3e2_jumbo_76_vet MG `ap,inc` (vet MG is a different gun).

**Rule fields that do not exist for the unit type:**
- casemate vehicles (stug3g_vet, stug3g_ace, stug4g_vet, stuh42_vet, jagdpanzer_iv_vet) have no turret; traverse bone `gun_rot2` audited as "turret speed" [I]; m12gmc `mantlet`, jagdpanther `turret` (limited -11 11)
- turan2/turan3: no `gun_rot`; elevation is the model bone `mantlet` [I]
- elite cannon stealth: there is no elite vision term in `settings.set` / `vision_presets.inc`, and no `loco_*_elite` macro in `cannon_armor.ext`; elite cannons reuse the `_vet` term and `_vet` locomotion macro, so x0.80 stealth and x0.80 turn time are impossible without new entries
- mortars have no turret/gun speeds (no rule needs them); type4_200mm has only `basis`/`foresight` bones

## Ambiguities in the rules as they meet this data

1. OWNER ANSWER 2026-11-19: the rule is +0.0003 (vet) / +0.0006 (elite). So flak36a_vet and pak43_vet conform on turn speeds; off are pak38_elite (turret 0.0015 -> 0.0075, gun 0.001 -> 0.007: +0.006, 10x the rule; due 0.0021 / 0.0016), elite_resita (0.0006 -> 0.0066 both: +0.006; due 0.0012 both), type4_75mm_elite (turret 0.002 -> 0.004: +0.002, due 0.0026; gun 0.0005 -> 0.0009: +0.0004, due 0.0011). The tables above still show the +0.003 / +0.006 reading. Original note: AT "turn speeds +0.003 / +0.006": the bone speeds are 0.0004 to 0.002, so +0.003 multiplies them 2 to 8 times. The two vet AT guns use +0.0003 (flak36a, pak43), the two elite AT guns pak38_elite and elite_resita use +0.006 exactly (pak38 turret 0.0015 -> 0.0075, x5), type4_75mm_elite +0.002/+0.0004. If +0.0003/+0.0006 was meant, the vets conform and pak38_elite, elite_resita, type4_75mm_elite are off instead. The TSV note column gives the alternate verdict per row.
2. Casemate traverse: all 5 casemate vets give the traverse bone `gun_rot2` (or jagdpanther `turret`) +0.0002 (the gun rule) instead of +0.0001 (the turret rule). Likely the author treated both casemate bones as "gun"; if so they conform.
3. SPGs with howitzers: m12gmc_vet reload x0.69 / x0.60 (artillery-like), stuh42_vet x0.9625. Whether SPG howitzers follow the vehicle x0.85 or the artillery x0.60 rule is not stated.
4. `_elite_gun` units (achilles, cometa34, m4a4_firefly) look like "elite gun only" variants, not elite vehicles; held to the elite vehicle rule they fail every field.
5. Elite artillery and elite AT stealth/turn time have no data path (see above). type4_200mm_elite also changed turn time x0.90, stealth to the vet term and basis/foresight speeds, outside any rule.
6. Gears: rule read as "+0.03 per forward gear, top gear 1 untouched, RearGears untouched", matching all conforming vets. pz6e_hun (3 gears, last 0.7) and t34_3_fin (last 0.625) have no top gear 1, so the last gear is checked too.
7. Reload rounding: several vets use rounded seconds (8 instead of 8.075, 11 instead of 11.05, 9.77 instead of 9.775). Counted as conforming (within 1%), listed under rounding cases.
8. `pdr25` and `type4_75mm` classification (artillery / AT) is a guess; see the table.
9. Vehicle MG reload is not held to the rule; m4a3e2_jumbo_76_vet swaps its AA MG to a different gun (browning_an_m2).

## Checked by hand against the raw files

1. VEH vet `pz4h_vet` vs `pz4h`: def diff shows StartTime 48 -> 40.8, TurnTime 19 -> 17.1, Gears 0.1 0.2 0.3 1 -> 0.13 0.23 0.33 1, turret 0.0036 -> 0.0037, gun_rot 0.001 -> 0.0012; `set/stuff/gun/75mm_kwk40(l48)` `{rechargeTime 8}`, `_vet` `{rechargeTime 6.8}`: all match the TSV (x0.85, +0.03, x0.90, +0.0001, +0.0002).
2. AT vet `pak43_vet` vs `pak43`: def diff `("loco_nomove")` -> `("loco_nomove_vet")` (TurnTime 120 / 108 in `properties/cannon_armor.ext:231-252`), `vision_cannon_maximum` -> `_vet` (1.7 / 1.53 in `vision_presets.inc:103-111`), bone gun_rot 0.0004 -> 0.0007, turret 0.0005 -> 0.0008; `88mm_pak43` `{rechargeTime 11}`, `88mm_pak43_vet` `{rechargeTime 9.35}` (x0.85): matches.
3. Artillery vet `m2a1l_vet`: `105mm_m2a1` has no own rechargeTime, it comes from `("range_medium_howitzer")` -> `gun/.presets:1690` `{rechargeTime 12}`; `105mm_m2a1_vet` line 5 `{rechargeTime 9.6}` = x0.80: matches.
4. VEH elite `m26e4_ace` vs `m26e4`: def diff StartTime 16 -> 12, TurnTime 26 -> 22, Gears 0.1 0.18 0.25 1.0 -> 0.18 0.26 0.36 1.0, turret 0.0025 -> 0.0030, gun_rot 0.0005 -> 0.0010 (also MaxSpeed 26 -> 28): matches.
5. AT elite `pak38_elite` vs `pak38`: def diff `loco_medium` -> `loco_medium_vet`, `vision_cannon_medium` -> `_vet`, turret 0.0015 -> 0.0075, gun_rot 0.001 -> 0.007: matches.
6. VEH vet `turan2_vet`: `75mm_41m` reload 8 from `range_light_howitzer` (`gun/.presets:1603`), `75mm_41m_vet` line 5 `{rechargeTime 5.5}`; def turret 0.0012 -> 0.0045: matches.

## Fixes applied 2026-11-19

The owner said "Fix the rest". Written in place in the mod; undo copies of the 32 edited files in `<mod>/.arsenal-undo/vetrules-20261119/` (same paths), the 3 new files listed in its `NEW-FILES.txt`. Scripts and outputs: `E:\arsenal-tmp\vetrules\` (`apply.js` edits, `audit2.js` adapted audit, `audit-before.tsv` / `audit-after.tsv`, `stuffdiff.js`, `defcheck.js`, `fmtcheck.js`, `lint-before.txt` / `lint-after.txt`). Nothing run in game [T].

### Decisions followed

1. Casemate traverse +0.0002 (jagdpanther_vet, jagdpanzer_iv_vet, stug3g_vet, stug4g_vet, stuh42_vet) and stug3g_ace +0.0004 left as is; their other off fields fixed.
2. m12gmc_vet: chassis and bones by the vehicle rule, reload by the artillery rule x0.60 on both modes; longtom_155mm_vet, m114_vet, m2a1l_vet reload x0.60.
3. `*_elite_gun` (achilles, cometa34, m4a4_firefly): only the gun is elite, reload x0.70 of base; chassis/turret/gun speed untouched (audited as reload only).
4. pdr25_vet second mode: new `88mm_oqfmk2_2_vet` x0.60, mounted on `gun1_2`.
5. Elite AT cannons: new vision terms `cannon_03_elite` / `cannon_04_elite` (`vision_presets.inc`, inside the `"cannon"` define, so every `("cannon")` call in `vision_generic.inc` picks them up), mapped in `settings.set` to props `vision_cannon_medium_elite` / `vision_cannon_high_elite`; new macros `loco_medium_elite` / `loco_big_elite` beside the `_vet` ones in `properties/cannon_armor.ext`. Wired like the `_vet` ones: the `_vet` names occur only in `settings.set`, `vision_presets.inc`, `cannon_armor.ext` and defs (no interaction, ai or other .set file; `interaction_entity/dummy.inc` lists only the base `vision_cannon_*` props, not `_vet`, so `_elite` is not added there either). Bone speeds base +0.0006.
6. Reload and the other listed chassis/bone deviations set to the exact rule value. Owner change: the MaxSpeed bonus removed (see below). Other changes outside the rules untouched (m26e4_ace `turret_mgun`, turan2_vet mass/fuel/TurnStart/TurnStop/BrakeTime/StopTime/RearGears/`cu` ammo, m9053_vet `heat_shell`, type4_200mm_elite extras, mg42_lafette_vet, extra ammo blocks).
7. Conforming and rounding-conforming units not touched.
8. Prices, localization, Lua, interface files not touched.

Owner change to decision 6 (top speed): every audited pair compared for `MaxSpeed`, `maxSpeedAtMaxTurn` and the chassis `{speed {Normal} {Slow}}` block (ordered moves never exceed Normal/Slow, `movement/vehicle-physics`). Only two units differed, both set back to base: m26e4_ace and turan2_vet. No cannon differs (the `loco_*_vet` / new `_elite` macros keep the base MaxSpeed).

### Changes per unit

| unit | field | old | new | rule / base |
|---|---|---|---|---|
| pak38_elite | TurnTime (macro) | 14.4 (`loco_medium_vet`) | 12.8 (`loco_medium_elite`) | x0.80 of 16 |
| pak38_elite | stealth (vision prop) | `vision_cannon_medium_vet` 1.08 / firing 1.17 | `vision_cannon_medium_elite` 0.96 / firing 1.04 | x0.80 of 1.2 / 1.3 |
| pak38_elite | bone turret speed | 0.0075 | 0.0021 | 0.0015 +0.0006 |
| pak38_elite | bone gun_rot speed | 0.007 | 0.0016 | 0.001 +0.0006 |
| elite_resita | TurnTime (macro) | 14.4 (`loco_medium_vet`) | 12.8 (`loco_medium_elite`) | x0.80 of 16 |
| elite_resita | stealth | `vision_cannon_medium_vet` 1.08 | `vision_cannon_medium_elite` 0.96 | x0.80 of 1.2 |
| elite_resita | bone turret / gun_rot speed | 0.0066 / 0.0066 | 0.0012 / 0.0012 | 0.0006 +0.0006 |
| elite_resita | reload `gun` (`75mm_dt_elite`, edited) | 4 | 3 | x0.60 of 5 |
| elite_resita | reload `gun1_2` | `75mm_dt_2` 7 (recovery 7) | new `75mm_dt_2_elite` 4.2 (recovery 4.2) | x0.60 of 7 |
| type4_75mm_elite | TurnTime (macro) | 22.5 (`loco_big_vet`) | 20 (`loco_big_elite`) | x0.80 of 25 |
| type4_75mm_elite | stealth | `vision_cannon_high_vet` 1.17 / firing 1.26 | `vision_cannon_high_elite` 1.04 / firing 1.12 | x0.80 of 1.3 / 1.4 |
| type4_75mm_elite | bone turret speed | 0.004 | 0.0026 | 0.002 +0.0006 |
| type4_75mm_elite | bone gun_rot speed | 0.0009 | 0.0011 | 0.0005 +0.0006 |
| pak43_vet | reload `gun` | `88mm_pak43_vet` 9.35 | new `88mm_pak43_vet_at` 8.8 | x0.80 of 11 |
| pdr25_vet | reload `gun1_2` | `88mm_oqfmk2_2` 9.5 | new `88mm_oqfmk2_2_vet` 5.7 | x0.60 of 9.5 |
| longtom_155mm_vet | reload `gun` (`155mm_longtom_vet`) | 13.8 (recovery 13.8) | 12 (recovery 12) | x0.60 of 20 |
| m114_vet | reload `gun` (`155mm_m114_vet`) | 13.8 (recovery 13.8) | 12 (recovery 12) | x0.60 of 20 |
| m2a1l_vet | reload `gun` (`105mm_m2a1_vet`) | 9.6 (recovery 9.6) | 7.2 (recovery 7.2) | x0.60 of 12 |
| m26e4_ace | MaxSpeed | 28 | 26 | base (owner change) |
| m26e4_ace | chassis speed Normal / Slow | 28 / 28 | 26 / 26 | base (owner change) |
| m26e4_ace | TurnTime | 22 | 20.8 | x0.80 of 26 |
| m26e4_ace | Gears | 0.18 0.26 0.36 1.0 | 0.16 0.24 0.31 1.0 | +0.06, top 1 kept |
| m26e4_ace | bone turret speed | 0.0030 | 0.0027 | 0.0025 +0.0002 |
| m26e4_ace | bone gun_rot speed | 0.0010 | 0.0009 | 0.0005 +0.0004 |
| pz6e_hun_vet | StartTime | 36 | 30.6 | x0.85 |
| pz6e_hun_vet | TurnTime | 24 | 21.6 | x0.90 |
| pz6e_hun_vet | Gears (3, no top gear 1) | 0.1 0.2 0.75 | 0.13 0.23 0.73 | +0.03 each (base 0.1 0.2 0.7) |
| pz6e_hun_vet | turret speed | 0.0035 (macro `turret_speed_medium_low`) | 0.0021 (def bone, macro line replaced) | 0.002 +0.0001 |
| pz6e_hun_vet | gun_rot speed | 0.01 (model) | 0.0102 (new def bone) | 0.01 +0.0002 |
| pz6e_ace | StartTime | 42 | 45 | x0.75 of 60 |
| stug3g_ace | StartTime | 24.5 | 26.25 | x0.75 of 35 |
| stug4g_vet | TurnTime | 16 | 17.1 | x0.90 of 19 |
| stuh42_vet | reload `gun` (`105mm_stuh42_vet`) | 15.4 | 13.6 | x0.85 of 16 |
| m12gmc_vet | StartTime / TurnTime | 30 / 17 | 25.5 / 15.3 | x0.85 / x0.90 |
| m12gmc_vet | Gears | 0.1 0.2 0.3 1 | 0.13 0.23 0.33 1 | +0.03 |
| m12gmc_vet | bone mantlet (traverse) / gun_rot speed | 0.0005 / 0.0005 | 0.0006 / 0.0007 | +0.0001 / +0.0002 |
| m12gmc_vet | reload `gun` (`155mm_m12_vet`) | 13.8 (recovery 13.8) | 12 (recovery 12) | x0.60 of 20 (decision 2) |
| m12gmc_vet | reload `gun1_2` (`155mm_m12_2_vet`) | 12 | 12 (unchanged, already x0.60) | x0.60 of 20 |
| m149_vet | StartTime / TurnTime | 30 / 17 | 25.5 / 15.3 | x0.85 / x0.90 |
| m149_vet | Gears | 0.1 0.2 0.3 1 | 0.13 0.23 0.33 1 | +0.03 |
| m149_vet | bone turret / gun_rot speed | 0.0005 / 0.0005 | 0.0006 / 0.0007 | +0.0001 / +0.0002 |
| m149_vet | reload `gun` (`149mm_obice_vet`) | 13.8 (recovery 13.8) | 11.73 (recovery 11.73) | x0.85 of 13.8 |
| m9053_vet | StartTime / TurnTime | 30 / 17 | 25.5 / 15.3 | x0.85 / x0.90 |
| m9053_vet | Gears | 0.1 0.2 0.3 1 | 0.13 0.23 0.33 1 | +0.03 |
| m9053_vet | turret / gun_rot speed | 0.004 / 0.002 (model) | 0.0041 / 0.0022 (new def bones) | +0.0001 / +0.0002 |
| m9053_vet | reload `gun` (`90mm_m90_53_vet`, all blocks incl. vet-only `heat_shell`) | 9 | 7.65 | x0.85 of 9 |
| t34_3_fin_vet | StartTime / TurnTime | 24 / 16 | 20.4 / 14.4 | x0.85 / x0.90 |
| t34_3_fin_vet | Gears (3, no top gear 1) | 0.1 0.25 0.75 | 0.13 0.28 0.655 | +0.03 each (base 0.1 0.25 0.625) |
| t34_3_fin_vet | bone turret / gun_rot speed | 0.01 / 0.003 | 0.0044 / 0.0007 | 0.0043 +0.0001 / 0.0005 +0.0002 |
| turan2_vet | MaxSpeed | 32 | 30 | base (owner change) |
| turan2_vet | maxSpeedAtMaxTurn | 11 | 4 | base (owner change) |
| turan2_vet | chassis speed Normal / Slow | 10 / 16 | 28 / 28 | base (owner change; note: ordered moves get faster, the vet values were lower than base) |
| turan2_vet | StartTime / TurnTime | 30 / 18 | 38.25 / 17.1 | x0.85 of 45 / x0.90 of 19 |
| turan2_vet | Gears | 0.1 0.25 0.75 (3 gears) | 0.13 0.23 0.33 1 (base count 4) | +0.03, top 1 kept |
| turan2_vet | bone turret speed | 0.0045 | 0.0013 | 0.0012 +0.0001 |
| turan2_vet | mantlet (elevation) speed | 0.009 (model) | 0.0092 (new def bone) | +0.0002 |
| turan2_vet | reload `gun` (`75mm_41m_vet`) | 5.5 | 6.8 | x0.85 of 8 (vet becomes slower than before) |
| turan3_vet | StartTime / TurnTime | 45 / 19 | 38.25 / 17.1 | x0.85 / x0.90 |
| turan3_vet | Gears | 0.1 0.2 0.3 1 | 0.13 0.23 0.33 1 | +0.03 |
| turan3_vet | bone turret speed | 0.0045 | 0.0031 | 0.003 +0.0001 |
| turan3_vet | mantlet (elevation) speed | 0.009 (model) | 0.0092 (new def bone) | +0.0002 |
| turan3_vet | reload `gun` (`75mm_43m_vet`) | 6.8 | 5.95 | x0.85 of 7 |
| achilles_elite_gun | reload `gun` (`76mm_mk4_2elite`) | 8.0 | 5.6 | x0.70 of 8 |
| cometa34_elite_gun | reload `gun` (`77mm_hv_elite`, line added) | 8.8 | 6.16 | x0.70 of 8.8 |
| m4a4_firefly_elite_gun | reload `gun` (`76mm_mk4_elite`, line added) | 9.5 | 6.65 | x0.70 of 9.5 |

Reload values are the resolver's effective values (default and every `{parameters}` block, mods on and off). Where the vet artillery file writes `recoveryTime` next to `rechargeTime` with the same value (the mod's pattern for magazine artillery, as in the conforming m115_vet 54/54 and 88mm_oqfmk2_vet 5.7/5.7), the recovery time got the same factor; the audit only checks rechargeTime.

### New files

- `resource/set/stuff/gun/88mm_pak43_vet_at`: `{from "88mm_pak43_vet"}` + `{rechargeTime 8.8}` + the vet's `("accuracy_max_10m_he")` repeated. New file because `88mm_pak43_vet` is also mounted by jagdpanther_vet (vehicle x0.85, conforming at 9.35) and nashorn_ger2 (not audited); both keep 9.35.
- `resource/set/stuff/gun/75mm_dt_2_elite`: `{from "75mm_dt_2"}` + `{curve "gun_heavy"}` + rechargeTime/recoveryTime 4.2. New because `75mm_dt_2` is the base resita's arty mode. The curve line is needed: the folder `.presets` resets the curve to `gun_std` (the base gets `gun_heavy` from a range macro that also sets range and gravity, so the macro itself could not be repeated).
- `resource/set/stuff/gun/88mm_oqfmk2_2_vet`: `{from "88mm_oqfmk2_2"}` + `{curve "gun_medium"}` + `{rechargeTime 5.7}`. New because `88mm_oqfmk2_2` is the base pdr25's second mode. Same curve reason.
- New entries in existing files: `loco_medium_elite`, `loco_big_elite` (`properties/cannon_armor.ext`); `cannon_03_elite`, `cannon_04_elite` (`set/vision/vision_presets.inc`); `{cannon_03_elite actor "vision_cannon_medium_elite"}`, `{cannon_04_elite actor "vision_cannon_high_elite"}` (`set/vision/settings.set`).

Edited in place (single user each, checked over mod + game files incl. defs, .set/.inc, missions, `{from}`): `75mm_dt_elite`, `149mm_obice_vet`, `90mm_m90_53_vet`, `75mm_41m_vet`, `75mm_43m_vet`, `105mm_stuh42_vet`, `155mm_m12_vet`, `155mm_longtom_vet`, `155mm_m114_vet`, `105mm_m2a1_vet`, `76mm_mk4_2elite`, `77mm_hv_elite`, `76mm_mk4_elite`.

### Checks

- Audit re-run (`audit2.js`: AT bones +0.0003/+0.0006, decision 1 rows counted as accepted, m12gmc reload x0.60, `_elite_gun` reload only), same rules before and after:

| state | units | fully conforming | off | rule rows | rows off | rows unchanged | rounding rows | accepted (decision 1) |
|---|---|---|---|---|---|---|---|---|
| before | 45 | 22 | 23 | 271 | 41 | 45 | 9 | 6 |
| after | 45 | 45 | 0 | 271 | 0 | 0 | 9 | 6 |

  Remaining non-ok rows: the 9 rounding rows (decision 7, untouched) and the 6 casemate traverse rows (decision 1). No MaxSpeed row is left. `E:\arsenal-tmp\vetrules\audit-after.tsv`.
- Stuff resolve, before (undo copies) vs after, all 1356 mod stuff files, 3 merge readings x mods on/off: 8034 same, 78 differ = the 13 edited files x 6, each only in rechargeTime (and recoveryTime for the 5 artillery files); 24 resolutions fail the same way on both sides (bombing `.ammo`, as before). The 3 new files differ from their `{from}` target only in rechargeTime/recoveryTime under all 3 readings.
- Def expansion, all 5184 mod files under `entity/`: only the 16 edited defs differ.
- sdllint (`--game`) on before/after mirrors (changed files + `properties/` + `set/vision/` + `gun/.presets`): 0 findings on both sides, same info lines. All 35 files CRLF (as their undo copies), braces and parens balanced, non-ASCII byte counts unchanged.
- Units outside the audit that use a touched name: nashorn_ger2 (`88mm_pak43_vet`), resita (`75mm_dt_2`), pdr25 (`88mm_oqfmk2_2`), the users of `loco_medium_vet` / `loco_big_vet` / `vision_cannon_*_vet` (pak38_ger2, pak40_ger2, zis2_guard, zis3_guard, np_52k_43_guard; also audited flak36a_vet, type4_200mm_elite): none moved (those files and macros are unchanged; def expansion identical).

### Not done / open

- Nothing from the deviation list is left. Not run in game [T]: new vision terms, new loco macros and the new stuff files load only if the engine reads them as the tools do; check game.log for `pattern not found` / unknown actor after loading elite_resita, pak38_elite, type4_75mm_elite, pak43_vet, pdr25_vet.
- CORRECTED 2026-11-19: turan2_vet Normal/Slow was put back to 10/16 afterwards (it was not a bonus). Earlier text: [I] turan2_vet chassis speeds Normal/Slow went from 10/16 to the base 28/28 under the owner's "set back to base" for top-speed keys; that makes its ordered moves much faster than before (the vet values were below base, likely copied from t34_3_fin). Revert those two lines if only bonuses were meant.
- [I] recoveryTime scaled together with rechargeTime in the artillery files listed above (mod's own pattern); the rule names only reload.
