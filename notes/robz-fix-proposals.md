# RobZ Realism 1.31.0: fix proposals, broken cards and ammo

Prepared 2026-11-18. Nothing here is applied. Each item needs a yes or no; items marked "choice" need one word.
Paths are under `<mod>/resource/set/`. All "now" lines were read from the mod files today.
Each fix changes game data, so each is checked in game after it is applied (buy the card, read game.log).

## Applied 2026-11-18 on the owner's word ("Yes apply all")
- A, B, C, D, E as proposed with the default choices (26 edits in 23 files). Undo copies: `<mod>/.arsenal-undo/fixes-20261118b/`.
- `axm_rom_bazooker_assist.set`: `{item "ammo walther_mag" 16}` added after the Walther.
- type97: `breed/mp/jap/mgun3_ammo.set` and `mgun3_asst.set` moved to the undo folder; their 4 rows removed from
  `multiplayer/units/soldier.set` and `soldiers.set`. No card, map or script named them. Their name rows in
  `localization/desc/mod/human/jap.inc` are left (unused text).
- Guards: the PIAT card `bazookers_piat` already carries a PIAT (`guard_piat.set`). The bazooka card `bazookers` was the one
  titled "PIAT team"; its title is now "Guards Bazooka team" (`localization/desc/mod/squad/rus_guard/squad2.inc:19`).
- Data comparison against the original (`E:/arsenal-tmp/robz-toe/verify-fixes.txt`): only the intended differences.
- Not run in the game after these fixes [T].

## A. Cards that name a soldier that does not exist

A1. `multiplayer/units/jap/squads_42-43.set:79` card `elite3` (offered 1942-43)
- now: `member1(elite_takasago_lmg:1) member2(elite_rifle2:3)`; there is no `elite_rifle2` breed.
- proposed: `member2(elite_takasago_rifle2:3)` (the nearest name; that breed exists and is used by the Takasago squad at :23).
- choice: the 1944-45 copy of this card (`squads_44-45.set:96`) uses `jap_elite_takasago_rifle:2`, so `elite_takasago_rifle`
  is the other candidate.

A2. `multiplayer/units/axis_minor/squads.set:31` card `Bersaglieri_Mot`
- now: `member5(axm_bersaglieri_mgun:2)`; the breed file is `axm_ita_bersaglieri_mgun.set`.
- proposed: `member5(axm_ita_bersaglieri_mgun:2)`.

## B. Cards with one member too few for their macro (owner case 8)

The macro expects N members and the card passes N-1, so the last slot becomes broken text.
Proposed for all three: call the macro of the size the card really has; the squad is then exactly the members listed.

| Card | File:line | Now | Proposed |
|---|---|---|---|
| `ssvts_44` (ger_ss) | `multiplayer/units/ger/squads_44.set:14` | `squad_with6types`, 5 members | `squad_5`, same 5 members |
| `elites_44` (ger_ss) | `multiplayer/units/ger/squads_44.set:78` | `squad_with7types`, 6 members | `squad_6`, same 6 members |
| `gebirgs_42` (ger_ss) | `multiplayer/units/ger/squads_42.set:17` | `squad_with6types`, 5 members | `squad_5`, same 5 members |

- choice: if a sixth or seventh member was meant, name it. Hints: the Wehrmacht `elites_44` at `squads_44.set:76` has a sniper,
  a grenadier and a Panzerfaust man that the SS card lacks; `ssvts_44` in `squads_41.set:6` has `ssvt_pzfst:1`.

## C. Card title and gun do not agree

C1. `multiplayer/units/jap/squads_44-45.set:21-23` cards `riflemans`, `riflemans_2`, `riflemans_3`, titled
"Regular infantry section w/Type 99 LMG"
- now: `member5(jap_mgun2:1) member6(mgun2_asst:1) member7(mgun2_ammo:3)`. `jap_mgun2` carries the Type 96 and the two
  helpers carry Type 96 magazines, so these cards equal the Type 96 cards at :14-16.
- proposed: `member5(jap_mgun:1) member6(mgun_asst:1) member7(mgun_ammo:3)`. `jap_mgun` carries the Type 99 (180 rounds),
  `mgun_asst` and `mgun_ammo` carry Type 99 magazines (30 and 120). The 1942-43 card `riflemans_42` already uses `mgun`.
- cost stays as it is (163 / 145 / 145) unless you say otherwise.

## D. Ammunition the weapon cannot load

Luger and Walther fill only from `walther_mag` (`stuff/pistol/luger:2`, `stuff/pistol/valter:2`). `9x19` feeds the Orita,
FNAB-43, Glisenti and Steyr 1912 only. Proposed for all six: keep the count 40 (5 magazines of 8), change the ammo name.

| Breed file (`breed/mp/axis_minor/`) | Line | Now | Proposed |
|---|---|---|---|
| `axm_bul_officer.set` | 27 | `{item  "ammo 9x19" 40}` | `{item "ammo walther_mag" 40}` |
| `axm_fin_pio_flamer.set` | 23 | same | same |
| `axm_fin_pio_mgun.set` | 21 | same | same |
| `axm_fin_sissi_mgun.set` | 21 | same | same |
| `axm_fin_sissi_mgun_vision.set` | 20 | same | same |
| `axm_rom_bazooker.set` | 20 | same | same |

Not touched: `axm_rom_bazooker_assist.set` (its `9x19` feeds the Orita he carries; his Walther then has no spare
magazines. choice: add `{item "ammo walther_mag" 16}`?).

D2. `breed/mp/jap/jap_mg3_asst.set:18`, assistant of the Type 11 gun (6.5 mm, fills from `arisaka6-5_clip`)
- now: `("kit_rifle" gun(type99rifle) ammo(arisaka7-7_clip) rounds(200))` (7.7 mm, useless to the gun).
- proposed: `("kit_rifle" gun(type38rifle) ammo(arisaka6-5_clip) rounds(200))`; the Type 38 and the Type 11 share the clip.

## E. Counts that look pasted from another weapon

| # | Breed file (`breed/mp/`) | Weapon, magazine | Now | Proposed | Why |
|---|---|---|---|---|---|
| E1 | `axis_minor/axm_ita_alpini_sniper.set:23` | Beretta M1934, 7 | 160 | 35 | 160 is the rifle count on the line above; the two other Beretta carriers have 35 |
| E2 | `ger_ss/ss_kosaken_sl.set:19`, `_sl_asst.set:19`, `_smg.set:19` | PPSh-41 stick, 35 | 142 | 140 | 142 is two 71-round drums; 140 is 4 stick magazines |
| E3 | `axis_minor/axm_fin_tankman.set:20` | Suomi (stick), 40 | 142 | 160 | same drum count; choice 120 or 160 |
| E4 | `axis_minor/axm_ita_vehicle_supporter.set:20` | MAB 38A, 40 | 128 | 120 | 128 is 4 MP 40 magazines |
| E5 | `axis_minor/axm_hun_smg_ppsh.set:18` | PPSh drum, 71 | 240 | 213 | 3 drums |
| E6 | `axis_minor/axm_bul_smg.set:18` | MP 40, 32 | 120 | 128 | 4 magazines; no card uses this breed |
| E7 | `breed/breed_kit.inc:237` macro `smg_suomi_m31` (7 breeds) | Suomi drum, 71 | 210 | 213 | 3 drums; other Suomi breeds already have 213 |

These are small either way: the game fills partial magazines, so a count off a whole magazine works, it only leaves an
odd remainder [I].

## F. Left for a decision, no proposal
- `type97rifle` has no stuff file; only `jap/mgun3_ammo.set` and `jap/mgun3_asst.set` carry it and no card uses them.
  choice: delete the two lines, or name the weapon meant (the Type 97 sniper rifle?).
- `rus_guard/squads_43-45.set:69` is titled "PIAT team" and carries a bazooka (not re-checked by the coordinator).
  choice: change the title or the weapon.
