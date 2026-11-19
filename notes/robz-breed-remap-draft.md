# RobZ Realism 1.31.0: condensed breed macro remap (APPLIED 2026-11-18, not run in the game [T])

Drafted 2026-11-18 from the owner's rules. Per-soldier table: `robz-breed-remap-draft.tsv` (1,187 rows: role, level, proposed
call, and each value that would change as `now>new`). Applied to the mod on 2026-11-18: see "Applied" at the end; the draft text below is kept as the design record.

## Owner's rules this draft follows
1. One quality level per soldier (1 to 7) = the skill of the main weapon he carries.
2. Every member of a squad has the same level on his own main weapon.
3. Squad leader and assistant squad leader are one level above the squad.
4. An assistant (MG, AT, ammo bearer) has the same skills as the man he assists.
5. Other weapon skills are close to the main skill, a little lower.
6. Health, stamina and the infantry crew skills follow the level.
7. Rocket skill is 1, except: a soldier who carries a rocket weapon; and German (ger, ger2, ger_ss) and Hungarian soldiers
   of 1944-45 who are not assistants.
8. Only tank crews and tank support have notable crew skills.

## The macro: one call per soldier
`("soldier_<main>_<level>" rocket(N) body(line|hardy))`, e.g. `("soldier_rifle_5" rocket(1) body(line))`. It replaces the three calls a breed has today
(body tier, drive tier, skills tier). 4 main classes x 7 levels = 28 macros (26 in use) in place of the 142 tier macros
(34 body, 23 drive, 85 skills). Parameters cannot be computed or optional in this format, so each level is a fixed table.

```
(define "soldier_rifle_5"
	("body_%body_5")
	("breed_drive" tank(0.85) vehicle(1) cannon(0.9))
	("breed_skills" pistol(4) smg(3) mgun(3) rifle(5) rocket(%rocket) melee(4))
)
```
`body_line_5` and `body_hardy_5` are the two health rows of level 5 (tables below). Passing `%rocket` on and building a
macro name from `%body` are what `breed_vet` does today (`vet_%table`); checked by the expander, not in game [T].

### Skills per level (pistol smg mgun rifle melee), taken from the most common set in the mod today
| Level | main rifle | main smg | main mgun | main pistol |
|---|---|---|---|---|
| 1 | 1 1 1 1 2 | 1 1 1 1 2 | 1 1 1 1 2 | 1 1 1 1 2 |
| 2 | 1 1 1 2 2 | 2 2 1 1 2 | 2 1 2 1 2 | 2 2 2 2 2 |
| 3 | 2 2 2 3 3 | 2 3 2 2 3 | 2 2 3 2 3 | 3 3 3 3 3 |
| 4 | 4 3 2 4 4 | 4 4 2 3 4 | 4 3 4 3 4 | 4 4 4 4 4 |
| 5 | 4 3 3 5 4 | 4 5 3 3 4 | 4 3 5 3 4 | 5 5 5 5 5 |
| 6 | 5 5 5 6 5 | 5 6 5 5 5 | 5 5 6 5 5 | 6 5 5 5 5 |
| 7 | 6 6 6 7 6 | 6 7 6 6 6 | 6 6 7 6 6 | 7 6 6 6 6 |

At levels 6 and 7 the mod today sets every skill equal; on the owner's answer to Q1 the other skills are one below the main
skill there too (226 of the 260 level 6-7 soldiers change for this).
A rocket-main soldier (bazooka, Panzerschreck, PIAT man) uses the rifle column with `rocket(<level>)`.

### Body and infantry crew skills per level
| Level | health | stamina | speed | tank | vehicle | cannon |
|---|---|---|---|---|---|---|
| 1 | 100% | 75% | 0.9 | 0.75 | 1 | 0.8 |
| 2 | 150% | 100% | 0.9 | 0.75 | 1 | 0.8 |
| 3 | 150% | 100% | 0.9 | 0.75 | 1 | 0.8 |
| 4 | 150% | 100% | 0.9 | 0.75 | 1 | 0.8 |
| 5 | 200% | 150% | 0.9 | 0.85 | 1 | 0.9 |
| 6 | 350% | 200% | 0.9 | 0.95 | 1 | 1 |
| 7 | 400% | 200% | 0.9 | 0.95 | 1 | 1 |

### Health bump: SS and Japan only (owner, 2026-11-18)
Every `ger_ss` and `jap` infantry soldier passes `body(hardy)`; every other side passes `body(line)`.

| Level | line health / stamina | hardy health / stamina (PROPOSED sizes) |
|---|---|---|
| 1 | 100% / 75% | 150% / 75% |
| 2 to 4 | 150% / 100% | 200% / 100% |
| 5 | 200% / 150% | 300% / 150% |
| 6 | 350% / 200% | 400% / 200% |
| 7 | 400% / 200% | 450% / 200% |

The hardy sizes are a proposal: level 5 at 300% is what Japanese level-5 soldiers have today; the other rows add about one
step. Today the SS has no bump (200% at level 5, like the Wehrmacht), so this raises 253 of the 285 SS and Japanese
soldiers, and US (33), Soviet Guards (34), Soviet (26), British (23), minor Axis (23) soldiers that sit above the line
table today come down to it. Q7.

### Kamikaze, lunge mine, AT stick, banzai chargers: own special values, kept
9 Japanese breeds keep their explicit values and are not put on the table: `jap_kamikaze` (lunge mine, 300/200, speed 1.1,
stealth), `kamikaze` (300/200, speed 1.0), `ki_at_stick` (300/150), and the six chargers `charger_rifle`, `charger_smg`,
`jap_charger_rifle`, `jap_charger_smg_type100`, `jap_charger_smg_type100_44`, `jap_charger_throwgun` (250/200, speed 0.95,
melee 4 on level-1 skills). They could share one macro `soldier_charge` with their numbers as parameters. Q8.

Regeneration 100% and vision `mp_soldier` everywhere (the mod's common values). Extra perks a breed has today (stealth,
aimedshot, telescope, a `_vision` copy's vision) stay as their own lines after the call.

### Rocket value
| Soldier | rocket |
|---|---|
| carries a rocket weapon (any side, any year) | his level |
| German or Hungarian, 1944-45, not an assistant | level minus 1, at least 1 (what most of them have today) |
| everyone else | 1 |

"1944-45 German" = a breed used by a card in `ger/squads_44.set` or `ger2/squads.set`; no German breed is on both an early
and a 1944 list, so the split is clean. "Hungarian" = `axm_hun_*` (minor Axis infantry is tagged 44-45 only). Q2.

### Leaders and assistants
- Leader, assistant leader: the macro one level above the squad's (`soldier_smg_6` in a level-5 squad). That also raises
  health one step, which is what the mod does today where the leader is above (150% to 200% in 56 of 74 such cases). Q3.
- MG / AT / ammo assistant: the same call as the man he assists, whatever he carries himself.

### Crews and support (rule 8): own ladder, second pass
Not remapped in this draft: 91 crew breeds and 32 vehicle supporters. Today they use these sets (tank / vehicle / cannon):
crew 1/1/0.9, 1.1/1/0.95, 1.15/1.15/1 to 1.1, 1.2/1.2/1 to 1.1; support 0.85/1/1 and 1/1/1. Proposal: `crew_1` to `crew_4`
and `support_1`, `support_2`, built the same way once the infantry table is agreed.

## What this would change (992 infantry breeds; crews and support excluded)
| Part | Breeds changed | Typical change |
|---|---|---|
| Any value | 946 of 983 (96%) | |
| Weapon skills | 711 | steps of one level in 521; a two-level step in 161; larger in 37 |
| Rocket skill | 626 | down to 1 on every side except the 198 late German and Hungarian soldiers |
| Health, stamina, speed | 536 | 253 SS and Japanese up to the hardy row; 147 on other sides down to the line row |
| Infantry crew skills | 562 | see below |
| Leaders moved to squad + 1 | 36 | mostly German and SS, Soviet Guards |
| Assistants set to the man they assist | 66 | |

So the rules describe the shape of the data well, but a single table is a real rebalance, not a rename: 51 line soldiers
fit it exactly today (48 after the Q1 answer).

Infantry crew skills come in two ladders today, by side:
- ger, ger_ss, rus, rus_guard, usa: 0.75/1/0.8, 0.85/1/0.9, 0.95/1/1 (the table above).
- eng, jap, axis_minor: 0.8/1/1, 0.9/1/1, 1/1/1 (cannon always 1).
On the owner's answer to Q4 ("one ladder") the first is used for everyone (162 British, Japanese and minor Axis soldiers
lose cannon 1.0).

## Kept out of the table
- 94 infantry breeds are on no squad card; 46 assistants assist nobody on a card. They keep their own level.
- 9 "special" breeds (snipers, heroes) are mapped by level like everyone else; their extra perks stay. Q5.
- 72 breeds with no weapon whose skill could be read (medics, unarmed, flamethrowers) are left as they are.
- A soldier whose main weapon skill is below another skill today (95, mostly assistants and crews with a sidearm) takes
  his level from the main weapon, so some rise or fall: see the `skills now>new` column.

## Questions
- Q1. ANSWERED 2026-11-18 (owner): "Lower others by 1". Levels 6 and 7 have the other skills one below the main skill.
- Q2. No answer given; applied as drafted (level minus 1, at least 1). One number per call, easy to change.
- Q3. ANSWERED 2026-11-18 (owner): "Whole next level". Leaders and assistant leaders take the macro one level above the
  squad's, skills and health together, as drafted.
- Q4. ANSWERED 2026-11-18 (owner): "one ladder".
- Q5. ANSWERED 2026-11-18 (owner): "SS and Japan should be the only ones to get a health bump. Kamikazes / lunge mine /
  at stick infantry get extra special buffs".
- Q7. ANSWERED 2026-11-18 (owner): "Use the proposed health bumps".
- Q8. ANSWERED 2026-11-18 (owner): "charge troops should get the same buff that the faction buff is giving them". Read as: own values kept, health raised by the Japan bump of their level (+50 at levels 1 to 4, +100 at level 5). Reading is mine [I].
- Q6. ANSWERED 2026-11-18 (owner): "Roll it out at once".

## Applied 2026-11-18
Script: `E:/arsenal-tmp/robz-toe/apply/soldier-remap.js` (plan | apply | check). Per-soldier table as applied: `robz-breed-remap-applied.tsv`.
Undo copies: `<mod>/.arsenal-undo/soldier-remap-20261118/` (992 breed files and `breed_macros.inc`; `breed_soldier.inc` is new, delete it to undo).

- New file `resource/set/breed/breed_soldier.inc`, included from `breed_macros.inc`: `body_level_<L>_line|hardy` (14), `drive_level_<L>` (7), `skills_<main>_<L>` (28), `soldier_<main>_<L>` (28). Macro names differ from the draft above: the parameter is last in the name (`body_level_5_%body`).
- 992 infantry breeds rewritten: 955 change a value, 37 change form only. By side: ger 187, ger_ss 165, usa 134, jap 129, eng 110, rus 86, axis_minor 69, ger2 59, rus_guard 53.
- 916 breeds have the one call. 67 with their own vision (officer, sniper) or regeneration have three lines: explicit `breed_body` with the table health, stamina, speed and their own vision and regeneration, then `drive_level_<L>` and `skills_<main>_<L>`.
- 9 charge troops: own skills, crew skills, stamina, speed kept; health chargers 250 to 300, `jap_kamikaze` and `kamikaze` 300 to 350, `ki_at_stick` 300 to 400.
- 36 leaders moved to squad + 1; 66 soldiers changed level in all. Extra perks (stealth, aimedshot, telescope, tankgun, at_rifle, avoidance, field_glass) kept as lines after the call.
- Left as they were (195): 91 crews, 32 vehicle supporters (own ladder, second pass), 72 with no weapon skill to read (medics, unarmed, flamethrowers, and `usa_nightfighter_carbine`, `usa_nightfighter_leader`, whose perk blocks are multi-line; both on no card).
- The 142 old tier macros in `breed_tiers.inc` stay defined: crews, supporters and charge troops still call some.

Checks: every one of the 992 breeds re-expanded and compared with the plan: 992 match, 0 differ. `macrostd verify` against the first snapshot: 972 differing roots, all under `set/breed/mp/` except the 5 list files and 2 removed breeds of the earlier Type 97 fix; error codes unchanged (MACRO_UNDEFINED 151, UNREPLACED_PARAM 2). `MACROS.md` regenerated.
Not checked: load in the game, and whether the engine builds a macro name from a parameter inside a macro that was itself called with parameters (`breed_vet` does the same with `vet_%table`, also not run in game) [T].

## Applied 2026-11-18, second pass: crews, supporters, nightfighters
Owner: "Give the crews and supporters their own ladder." Same script, `node soldier-remap.js apply crew-remap-20261118`.
Undo copies: `<mod>/.arsenal-undo/crew-remap-20261118/` (137 files). Table as applied (both passes): `robz-breed-remap-applied.tsv`.

Call: `("crew_<grade>" body(line|hardy))`, `("support_<grade>" body(line|hardy))`, defined at the end of `breed_soldier.inc`. Rocket 1.
Values are the most common sets the mod had per grade [I: my choice of table, not given by the owner].

| Grade | Who | health line / hardy | stamina | speed | tank | vehicle | cannon | pistol smg mgun rifle melee |
|---|---|---|---|---|---|---|---|---|
| crew 1 | plain crewman (23) | 100% / 150% | 100% | 0.8 | 1 | 1 | 0.9 | 4 4 2 3 4 |
| crew 2 | plain commander, veteran crewman (32) | 150% / 200% | 100% | 0.8 | 1.1 | 1 | 0.95 | 4 4 4 3 4 |
| crew 3 | veteran commander, elite crewman (26) | 150% / 200% | 100% | 0.8 | 1.15 | 1.15 | 1 | 5 5 5 3 4 |
| crew 4 | elite commander (10) | 150% / 200% | 100% | 0.8 | 1.2 | 1.2 | 1.1 | 5 5 6 3 4 |
| support 1 | plain vehicle supporter (28) | 150% / 200% | 100% | 0.9 | 0.85 | 1 | 1 | 2 2 4 2 4 |
| support 2 | veteran or elite supporter (4) | 150% / 200% | 100% | 0.9 | 1 | 1 | 1 | 3 3 5 3 4 |

Grade comes from the breed name: `vet` +1, `elite` +2, commander (`tankman2`, `tankcommander`) +1. `hardy` = ger_ss and jap, as for infantry.
Larger changes this makes: the Soviet and Guards elite crews lose 400% health (now 150%); US veteran commanders go from tank 1.3 to 1.15;
British, Japanese plain supporters go from tank 1.0 to 0.85; Italian and Japanese crews gain weapon skills (were 2s).

Also in this pass:
- The first pass read squad cards only from `squads*.set` and weapons only one folder deep. Now every list file (hero and vehicle cards too) and
  nested weapon folders (`rifle/ptr`, `rifle/sniper`, ...) are read. 20 infantry breeds changed for it: assistants paired on hero cards,
  `eng/at_rifle`, `jap/at_rifle`, `jap/jap_at_rifle` and `axm_ita_alpini_sniper` take the level of the rifle they carry, and the SS `dr_pzgren_*`
  breeds (1944-45 lists only) get the late rocket skill.
- "1944-45 German" is now: on a 1944 or 1945 list (squads or vehicles) and on no 1940-43 list.
- A leader takes squad + 1 when the card has 4 or more men (was: 3 or more member rows).
- US nightfighters (hero card `hero_usa_m3_carbine`, "Marine Nightfighters", 3 leaders + 6 carbines, cost 2, lists 43, 44-45, 45): the earlier
  note "on no card" was wrong. `usa_nightfighter_carbine` is `soldier_rifle_6` (stealth, telescope, aimedshot kept; multi-line block rewritten),
  `usa_nightfighter_leader` is `soldier_rifle_7`.
- Held, not remapped (70): the breeds the first pass could not read, now readable: 30 snipers, 12 AT rifle men, 22 flamethrower men,
  4 SS `*_pzgren_sl_asst` (carry MG ammo only), `usa/elitec`, `eng/eng_paratroopr_em2`. Waiting for the owner's word.

Checks: 1,108 breeds re-expanded and compared with the plan: all match. `macrostd verify`: 1,095 differing roots, all breeds except the
earlier Type 97 fix; error codes unchanged. `MACROS.md` regenerated. Not loaded in the game [T].

## Applied 2026-11-18, third pass: held breeds mapped, crew health by tier
Owner: "yes map them"; "crew and support ladder hp should scale similar to normal infantry. normal being 3, vet being 5, elite being 7".
`node soldier-remap.js apply held-remap-20261118 all`. Undo copies: `<mod>/.arsenal-undo/held-remap-20261118/` (195 files).
This replaces the health columns of the second-pass crew table above.

- Crew and supporter call is now `("crew_<grade>" body(<tier>_<row>))`, e.g. `("crew_3" body(vet_hardy))`. Tier comes from the breed name
  (plain = normal, `vet`, `elite`) and gives the health and stamina of infantry level 3, 5, 7: 150%/100%, 200%/150%, 400%/200%
  (hardy: 200%/100%, 300%/150%, 450%/200%). Speed stays 0.8 for crews, 0.9 for supporters. Tank, vehicle, cannon and weapon skills still follow the grade.
- The 70 held breeds are on the infantry table by the level of the weapon they carry: 30 snipers (keep `mp_sniper` vision, stealth, telescope,
  aimedshot; written as three lines), 12 AT rifle men, 22 flamethrower men (flamethrower counted as an SMG: their old skills followed the SMG
  column), 4 SS `*_pzgren_sl_asst` (same call as their squad leader), `usa/elitec`, `eng/eng_paratroopr_em2`.
  Largest effect: snipers had 350% health and speed 1.0 whatever their level; now health follows the level (Guards and US snipers level 4: 150%,
  Soviet level 5: 200%, Japanese level 5: 300%, German level 6: 350%, SS level 6: 400%) and speed is 0.9.
- Only the 9 charge troops are off the tables now.
- US veteran commander tank 1.3 (`usa/vet_tankman2`, `usa_vet_tankman2_single`) was the highest value in the mod, on those two breeds only;
  other veteran commanders had 1.1 to 1.2 and elite commanders 1.2 (SS 1.25).

Checks: 1,178 breeds re-expanded and compared with the plan: all match. `macrostd verify`: 1,165 differing roots, all breeds except the earlier
Type 97 fix; error codes unchanged. `MACROS.md` regenerated. Not loaded in the game [T].

## Applied 2026-11-18, fourth pass: charge troops
Owner: "Put the charge troops in as well." `node soldier-remap.js apply charge-remap-20261118 all`; undo `<mod>/.arsenal-undo/charge-remap-20261118/`.
Call `("soldier_charge_<L>")`, no parameters; table at `breed_soldier.inc` [I: my numbers, chosen to sit closest to what they had].
Health = Japan row + 150% (300, 350, 350, 350, 450, 550, 600), stamina 200%, stamina regeneration 125%, speed 0.95, every weapon skill = level,
melee = level + 3 (7 at most), rocket 1, crew skills of the level.
- 6 chargers: level 1, values unchanged except crew skills (tank 0.9 to 0.75, cannon 1 to 0.8).
- `kamikaze`: level 2, 350% as before, skills 2 2 1 1 melee 2 to 2 2 2 2 melee 5, speed 1.0 to 0.95.
- `jap_kamikaze` (lunge mine): set to level 2 by hand; speed 1.1 to 0.95, stamina regeneration 150% to 125%; stealth kept.
- `ki_at_stick`: level 5, health 400% to 450%, stamina 150% to 200%, skills 3 3 3 5 melee 5 to 5 5 5 5 melee 7, rocket 3 to 1.
Checks: 1,187 breeds match the plan (every breed in `breed/mp` is now on a table); verify error codes unchanged. Not loaded in the game [T].

## Left out of line after the remap (survey 2026-11-18, `E:/arsenal-tmp/robz-toe/apply/survey.js`)
- `breed_tiers.inc`: all 142 macros are called by no breed now.
- 98 breeds write three lines instead of one: 33 sniper vision, 29 officer vision, 36 only for stamina regeneration 125% (ger 16, ger2 10 at level 7; jap 10 at level 6).
  `vision` is quoted in 73 and unquoted in 25.
- 48 of 290 cards have line soldiers of different levels (17 mix 4 and 5, 9 mix 6 and 7, 8 mix 5 and 6, 7 mix 2 and 3; worst `axis_minor flamers` 2 and 6).
- 43 of 170 assistants assist nobody on a card; 65 breeds are on no card (jap 22, ger 10).
- 173 groups of breed files (355 files) are identical within a side (e.g. every `*_single` copy).
- Extra perk lines: tankgun 134, stealth 97, avoidance 56, telescope + aimedshot 51 (37 with stealth), at_rifle 21, field_glass 18 (all with officer vision).
- 11 veterancy tables (standard 711, elite 188, crew 117, start5 65, standard_start3 33, standard_start2 26, elite_start2 18, ss_start3 18, ss_start1 7, crew_start3 2).
- Grenade kit macros carry counts in the name (`at_grenade_m24x5_xm1_2`, `smoke_x1p5_0p5`).

## Applied 2026-11-18, fifth pass: charge speed and stealth
Owner: "speed can go back on those. kamikaze, jap_kamikaze and ki_at_stick should all have stealth and 1.1 speed, otherwise uniform stats".
The charge call takes a speed: `("soldier_charge_<L>" speed(N))`. Chargers `speed(0.95)`; `kamikaze`, `jap_kamikaze` (both level 2) and
`ki_at_stick` (level 5) `speed(1.1)` plus `{"stealth"}` (added to `ki_at_stick`; the other two had it). Everything else from the charge table.
"Uniform" read as: on the table at their own level, not all three identical [I]. Undo `<mod>/.arsenal-undo/charge2-remap-20261118/`.
Checks: 1,187 breeds match the plan; verify error codes unchanged. Not loaded in the game [T].

## Applied 2026-11-18, sixth pass: kamikazes to level 5
Owner: "Up their level to level 5". `kamikaze` and `jap_kamikaze` are now `("soldier_charge_5" speed(1.1))` with stealth, identical to
`ki_at_stick`: health 450%, stamina 200%, weapon skills 5, melee 7, crew skills 0.85/1/0.9. Undo `<mod>/.arsenal-undo/charge3-remap-20261118/`.
Checks: 1,187 breeds match the plan; verify error codes unchanged. Not loaded in the game [T].

## Applied: clean-up pass (2026-11-18, undo `cleanup-20261118`)

Script `E:\arsenal-tmp\robz-toe\apply\cleanup.js plan|apply`. 890 of 1,187 breed files changed; own check: 0 breeds whose
perks or item amounts differ (compared as expanded text, amounts as distributions). Verify error codes unchanged. Not loaded in game [T].

- `breed_tiers.inc` (142 macros, none called) moved to the undo folder; its include line removed from `breed_macros.inc`.
- `("perks_sniper")` = stealth + telescope + aimedshot, 37 breeds. `("perks_officer")` = field_glass, 18 breeds. Defined in `breed_macros.inc`.
- `vision` quoted in the 25 breeds that had it unquoted.
- Grenade, mine and explosive kits: the 70 one-item macros with the count in the name are gone from `breed_kit.inc`. New, at its end:
  - `("give" item(grenade m24) count(2))`: 1,555 calls
  - `("give_chance" item(grenade m24x5) chance(25))`: 244 calls; chance 12 (12.5%, `-1 2`), 25 (`0 1`), 37 (37.5%, `0.25 1`), 50 (`0.5 0.5`)
  - `("give_1_or_2" item(smoke grenade))` (`1.5 0.5`): 44 calls
  - 64 literal item lines converted too. `0.25 0.5` is now written `0 1` and `0.5 1` is now `0.5 0.5` (same chance, by `eHumanBreed.cpp:83-94`).
- Left literal (centre spread: lines): `1 1`: 29, `5 1`: 13, `0.2 1`: 11, `6 1`: 10, `10 1`: 1, `2 1`: 1, `1 2`: 1, `1.5 1.5`: 1. These give a range of amounts, not a chance of one.
- [T] `-1 2` (chance 12) draws a negative amount in 37.5% of soldiers; what the game does then is not checked.
- Held: merging the 173 groups of identical breed files (owner asked what it means).

## Applied: pass seven (2026-11-18, undo `pass7-remap-20261118`; script backup `soldier-remap-v6.js`, patches `patch7.js`, `patch7b.js`)

Check: 1,187 breeds match the plan, a second run changes nothing, verify error codes unchanged. Not loaded in game [T]. Table: `robz-breed-remap-applied.tsv`.

- **Sight parameter (8).** Every soldier, crew and support call now ends `sight(soldier|officer|sniper)`; the body macros write `vision("mp_%sight")`.
  62 officers, snipers and crew commanders went from three lines to one. Counts: soldier 1,080, sniper 33, officer 29. [T] a parameter passed to a macro whose name ends in another parameter.
- **Three-line breeds left: 36**, all for stamina regeneration 125% (ger level 7: 16, ger2 level 7: 10, jap level 6: 10). 37 other breeds on the same sides and levels have 100%. Open: owner asked what the scaling is; there is none.
- **Squads levelled (6).** A line soldier takes the level most of his cards have. 16 breeds changed: axm_fin_pio_flamer 2 to 4, axm_hun_smg_danuvia 3 to 2,
  axm_ita_alpini_sniper 2 to 4, eng_bazooker 3 to 4, eng_pioneer_flamer 2 to 4, ger at_rifle2 4 to 5, ger bazooker2 4 to 5, ger_pzgren_mp40 5 to 6,
  ger_pzgren_smg_panzerfaust 4 to 5, sturmovik5b 5 to 6, ger_ss at_rifle2 4 to 5, jap at_rifle2 2 to 1, rus at_rifle2 2 to 3, rus bazooker2 2 to 3, rus flamer3 3 to 4, rus smg2 3 to 2.
  Corporals, sergeants, second-in-commands (`cpl`, `2ic`, `sic`, `ober`, `sgt`, `sa`, `chad`) stay one level above their squad. One card is still mixed:
  axis_minor `flamers` (axm_fin_pio_flamer 4, axm_fin_kaukopartio_rifle 6), because the flamer is shared with the pioneer squad.
  SS Fallschirmjäger (`ss_fallschirm_*`, cards `elites_44`, `elites_44_drop`) are excluded from levelling; they are uniform now (level 3, leader 4). Which mix the owner wants is open.
- **Tank gun skill (9)** is in the crew and support tables, no longer a line in the breed: crew 1/2/3/4 = lvl 2/4/7/10, support 1/2 = lvl 4/8. 38 breeds changed
  (elite crewmen 8 to 7 on eight sides; ger2 crews 5 to 2 and 7 to 4; SS and Guards crews 3 to 2 and 5 to 4; several veterans 5 to 4; full list in the tsv notes).
  11 infantry breeds (paratroopers and similar) keep their own `{"tankgun" lvl_4}` line.
- **AT rifle skill (9)** = the soldier's level; AT rifle assistants are now paired with the AT rifle man on their card. No value changed.
- **Veterancy table (9)** follows the level: `standard` up to level 5, `elite` from 6. 77 breeds standard to elite, 6 elite_start2 to standard_start2 (ger2 level 5),
  2 standard_start2 to elite_start2 (ger_ss level 6). Start-rank tables (start5, standard_start3, ss_start1, ss_start3, crew, crew_start3) untouched; 2 breeds have no table.

## Applied: pass eight (2026-11-18, undo `pass8-remap-20261118`; script backup `soldier-remap-v7.js`, `split.js`, `split2.js`, `patch8.js`)

Check: 1,188 breeds match the plan, second run changes nothing, verify error codes unchanged. Not loaded in game [T].

- **Flamer split.** New breed `axis_minor/axm_fin_kaukopartio_flamer` (copy of `axm_fin_pio_flamer`), level 6, veterancy table elite. Card `flamers` (axis_minor/squads.set:87) now uses it;
  the pioneer squad keeps `axm_fin_pio_flamer` at level 4. Same price rows added in `soldier.set` and `soldiers.set`; name "Liekinheitin Kaukopartio" added in
  `localization/desc/mod/human/axis_minor.inc` (wording is mine, [I]). Undo = restore the copies and delete the new breed file. No card is mixed now except by a leader or the SS Fallschirmjäger.
- **Stamina regeneration** 100% for everyone but the 9 charge troops (125%). 36 breeds went from 125% to 100% (ger level 7: 16, ger2 level 7: 10, jap level 6: 10). No three-line breed is left.
- **SS Fallschirmjäger** levels from the owner's sheet `MP and CP changes.xlsx`, tab CP Values 1.30.8 (copy: game `mods/testing/_dev/pricing/`), read off the command points per weapon class and level:
  rifle 9 / 0.6 = rifle level 3; mg_asst 9 / 0.6 = 3; smg 17 / 1.93 = SMG level 6; sl_asst_smg 17 / 1.93 = 6; sl 19 / 2.44 = 7; mg 65 / 3.51 = MG level 7.
  Before: all 3, leader and his assistant 4. The MG assistant stays at 3 as the sheet has him, not at his gunner's 7. `ss_fallschirm_smg` veterancy standard to elite.
  Prices in `soldier.set` / `soldiers.set` were not touched.

## Applied: pass nine (2026-11-19, undo `pass9-20261119` and `pass9b-remap-20261119`; scripts `pass9.js`, `patch9.js`, remap backup `soldier-remap-v8.js`)

Check: each of the 1,188 breeds expands to the same data before and after (own expander: same tokens in order from `{perks` on, same set of tokens in the header);
remap check 1,188 match; verify error codes unchanged. 21 more breeds now differ from the first snapshot only by header line order or a quoted helmet name. Not loaded in game [T].

- **Breed header in two lines** (all 1,188): `("breed_look" skin(S) portrait(P) icon(I) priority(N) nation(X))` and `("breed_armor" head(H))` or
  `("breed_armor_vest" vest(B) head(H))`, defined at the end of `set/breed/breed_macros.inc`. A per-family macro was not possible: there are 484 different
  headers, the most common shared by 21 breeds. 17 breeds keep a literal `{armors}` block (a commented-out line inside it, or no helmet). `{tags}` / `{behaviour}` lines stay.
- **Veterancy start rank as a parameter**: `("breed_vet" table(standard|elite|crew|ss) start(1|2|3|5))`. Tables renamed in `robz_vet.inc` and the ger_ss file:
  `vet_standard_start2` to `vet_from2_standard`, `vet_standard_start3` to `vet_from3_standard`, `vet_elite_start2` to `vet_from2_elite`, `vet_crew_start3` to `vet_from3_crew`,
  `vet_start5` to `vet_from5`, `vet_ss_start1` to `vet_ss`, `vet_ss_start3` to `vet_from3_ss`. `vet_start_1/2/3/5` pick the table. Numbers unchanged.
  Pairs that exist: standard 1 2 3 5, elite 1 2 5, crew 1 3, ss 1 3; another pair is an undefined macro. The 65 start(5) breeds carry table standard (45) or elite (20, level 6+); the word is not used at rank 5.
  `eng_rifleman_smoke` and `ss_at_miner` keep their own literal `{veterancy}` numbers (2/5/9/14/20).
- **Loose weapon lines**: 80 pairs to `("kit_loaded" gun(g43) ammo(ammo g43_mag) loaded(10) spare(20))` (new, in `breed_kit.inc`), 8 pistol pairs to `kit_pistol`.
  169 weapon lines stay literal: single-use weapons with no ammo line (Panzerfaust 45, flamethrower tanks 24, Panzerschreck / bazooka / PIAT 19, AT rifles 14),
  rifle grenade launchers whose grenades are range lines (20), and guns whose ammo line is not next to them (flare-gun carriers 16). List: `E:\arsenal-tmp\robz-toe\apply\pass9-left-weapons.txt`.
