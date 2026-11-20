Last updated: 2026-11-19

This file lists every change to RobZ Realism 1.31.0 that affects balance or gameplay since the import of the original mod; it is kept up to date with every change to the mod.

# RobZ Realism 1.31.0: balance and gameplay changes

## How to read this file

- Baseline: the imported mod, git commits efd0c93aa..3b6bd4535 ("Start (part N/28)").
- Covered: commits fb2612215..2566d233a (2026-11-16 to 2026-11-19), plus the not yet committed work of 2026-11-19 evening (undo tags shovelall-20261119, mortar60-20261119, pricecalc-20261119d; sections 3, 3a, 3b).
- Undo tag = folder name under `robz realism mod 1.31.0/.arsenal-undo/`. It holds the files as they were before the change. "git only" = no undo folder; undo with git.
- "old -> new" values come from a full macro expansion of the mod over vanilla at each commit, not from the notes.
- Paths are relative to `robz realism mod 1.31.0/resource/`.
- Nothing here was tested in the game. See "Not yet loaded in the game".

## Topics (newest first)

1. Veteran and elite vehicles and cannons (2026-11-19)
2. Sniper rifles (2026-11-19)
3. Price model (2026-11-19): calculator model, small shovel for every priced breed, 60 mm mortar call-in price
4. Grenade item names (2026-11-19)
5. Soldier breeds: skill, health and kit remap (2026-11-18 / 2026-11-19)
6. Bug fixes in cards, vehicles and props (2026-11-18)
7. Data fixes made with the localization work (2026-11-18)
8. SDK auto fixes (2026-11-17)

## 1. Veteran and elite vehicles and cannons

Date 2026-11-19. Undo tag: vetrules-20261119. Commit 243293645.
Why: the owner's rules for veteran and elite units (audit in `notes/robz-vetaudit.md`):

| Class | Reload | Start time | Gears | Turn time | Turret speed | Gun speed | Stealth |
|---|---|---|---|---|---|---|---|
| Artillery vet | x0.60 | - | - | - | - | - | - |
| AT cannon vet | x0.80 | - | - | x0.90 | +0.003 | +0.003 | +10% |
| AT cannon elite | x0.60 | - | - | x0.80 | +0.006 | +0.006 | +20% |
| Vehicle vet | x0.85 | x0.85 | +0.03 | x0.90 | +0.0001 | +0.0002 | - |
| Vehicle elite | x0.70 | x0.75 | +0.06 | x0.80 | +0.0002 | +0.0004 | - |

Stealth is the unit's vision term (lower = harder to see). "Turn time" on cannons is the `loco_*` macro TurnTime.

### 1a. Units (entity defs)

| Unit | Field | Old -> new |
|---|---|---|
| pak38_elite | vision term | vision_cannon_medium_vet -> vision_cannon_medium_elite |
| pak38_elite | TurnTime (loco macro) | 14.4 -> 12.8 (loco_medium_vet -> loco_medium_elite) |
| pak38_elite | turret / gun bone speed | 0.0075 -> 0.0021 / 0.007 -> 0.0016 |
| pak43_vet | weapon | 88mm_pak43_vet (reload 9.35) -> 88mm_pak43_vet_at (reload 8.8) |
| pdr25_vet | weapon gun1_2 | 88mm_oqfmk2_2 (reload 9.5) -> 88mm_oqfmk2_2_vet (reload 5.7, curve gun_medium) |
| elite_resita | vision term | vision_cannon_medium_vet -> vision_cannon_medium_elite |
| elite_resita | weapon gun1_2 (arty mode) | 75mm_dt_2 (reload 7 / 7) -> 75mm_dt_2_elite (reload 4.2 / 4.2, curve gun_heavy) |
| elite_resita | TurnTime (loco macro) | 14.4 -> 12.8 |
| elite_resita | turret / gun bone speed | 0.0066 -> 0.0012 / 0.0066 -> 0.0012 |
| type4_75mm_elite | vision term | vision_cannon_high_vet -> vision_cannon_high_elite |
| type4_75mm_elite | TurnTime (loco macro) | 22.5 -> 20 (loco_big_vet -> loco_big_elite) |
| type4_75mm_elite | turret / gun bone speed | 0.004 -> 0.0026 / 0.0009 -> 0.0011 |
| m26e4_ace | MaxSpeed | 28 -> 26 |
| m26e4_ace | speed Normal / Slow | 28 / 28 -> 26 / 26 |
| m26e4_ace | TurnTime | 22 -> 20.8 |
| m26e4_ace | Gears | 0.18 0.26 0.36 1.0 -> 0.16 0.24 0.31 1.0 |
| m26e4_ace | turret / gun bone speed | 0.0030 -> 0.0027 / 0.0010 -> 0.0009 |
| pz6e_ace | StartTime | 42 -> 45 |
| stug3g_ace | StartTime | 24.5 -> 26.25 |
| stug4g_vet | TurnTime | 16 -> 17.1 |
| pz6e_hun_vet | StartTime | 36 -> 30.6 |
| pz6e_hun_vet | TurnTime | 24 -> 21.6 |
| pz6e_hun_vet | Gears | 0.1 0.2 0.75 -> 0.13 0.23 0.73 |
| pz6e_hun_vet | turret bone speed | 0.0035 (macro turret_speed_medium_low) -> 0.0021 |
| pz6e_hun_vet | gun_rot bone speed | not set -> 0.0102 |
| m12gmc_vet | StartTime / TurnTime | 30 -> 25.5 / 17 -> 15.3 |
| m12gmc_vet | Gears | 0.1 0.2 0.3 -> 0.13 0.23 0.33 |
| m12gmc_vet | two bone speeds | 0.0005 -> 0.0006 and 0.0005 -> 0.0007 |
| m149_vet | StartTime / TurnTime | 30 -> 25.5 / 17 -> 15.3 |
| m149_vet | Gears | 0.1 0.2 0.3 -> 0.13 0.23 0.33 |
| m149_vet | two bone speeds | 0.0005 -> 0.0006 and 0.0005 -> 0.0007 |
| m9053_vet | StartTime / TurnTime | 30 -> 25.5 / 17 -> 15.3 |
| m9053_vet | Gears | 0.1 0.2 0.3 1 -> 0.13 0.23 0.33 1 |
| m9053_vet | turret / gun_rot bone speed | not set in def -> 0.0041 / 0.0022 |
| t34_3_fin_vet | StartTime / TurnTime | 24 -> 20.4 / 16 -> 14.4 |
| t34_3_fin_vet | Gears | 0.1 0.25 0.75 -> 0.13 0.28 0.655 |
| t34_3_fin_vet | two bone speeds | 0.003 -> 0.0007 and 0.01 -> 0.0044 |
| turan2_vet | MaxSpeed | 32 -> 30 |
| turan2_vet | maxSpeedAtMaxTurn | 11 -> 4 |
| turan2_vet | StartTime / TurnTime | 30 -> 38.25 / 18 -> 17.1 |
| turan2_vet | Gears | 0.1 0.25 0.75 -> 0.13 0.23 0.33 1 |
| turan2_vet | turret bone speed | 0.0045 -> 0.0013 |
| turan2_vet | mantlet bone speed | not set -> 0.0092 |
| turan2_vet | speed Normal / Slow | unchanged 10 / 16 (the audit note says 28 / 28; that is wrong) |
| turan3_vet | StartTime / TurnTime | 45 -> 38.25 / 19 -> 17.1 |
| turan3_vet | Gears | 0.1 0.2 0.3 1 -> 0.13 0.23 0.33 1 |
| turan3_vet | turret bone speed | 0.0045 -> 0.0031 |
| turan3_vet | mantlet bone speed | not set -> 0.0092 |

### 1b. Guns (set/stuff/gun)

| Gun (used by) | Field | Old -> new |
|---|---|---|
| 105mm_m2a1_vet (m7_priest) | rechargeTime / recoveryTime | 9.6 / 9.6 -> 7.2 / 7.2 |
| 105mm_stuh42_vet (stuh42) | rechargeTime | 15.4 -> 13.6 |
| 149mm_obice_vet (obice149a) | rechargeTime / recoveryTime | 13.8 / 13.8 (from 149mm_obice) -> 11.73 / 11.73 |
| 155mm_longtom_vet | rechargeTime / recoveryTime | 13.8 / 13.8 -> 12 / 12 |
| 155mm_m114_vet | rechargeTime / recoveryTime | 13.8 / 13.8 -> 12 / 12 |
| 155mm_m12_vet | rechargeTime / recoveryTime | 13.8 / 13.8 -> 12 / 12 |
| 75mm_41m_vet (turan2_vet) | rechargeTime | 5.5 -> 6.8 (slower; x0.85 of the base gun) |
| 75mm_43m_vet (zrinyi1) | rechargeTime | 6.8 -> 5.95 |
| 75mm_dt_elite (elite_resita AT mode) | rechargeTime | 4 -> 3 |
| 76mm_mk4_2elite | rechargeTime | 8.0 -> 5.6 |
| 76mm_mk4_elite | rechargeTime | 9.5 (from 76mm_mk4) -> 6.65 |
| 77mm_hv_elite (comet) | rechargeTime | 8.8 (from 77mm_hv) -> 6.16 |
| 90mm_m90_53_vet | rechargeTime | 9 -> 7.65 |
| 88mm_pak43_vet_at | new gun | from 88mm_pak43_vet, rechargeTime 8.8 |
| 88mm_oqfmk2_2_vet | new gun | from 88mm_oqfmk2_2, rechargeTime 5.7, curve gun_medium |
| 75mm_dt_2_elite | new gun | from 75mm_dt_2, rechargeTime 4.2, recoveryTime 4.2, curve gun_heavy |

### 1c. Shared terms and macros

| Item | Field | Old -> new |
|---|---|---|
| set/vision/vision_presets.inc cannon_03_elite | new term | base 0.96, firing 1.04, visible 0.96, still 0.96 (vet term: 1.08 / 1.17) |
| set/vision/vision_presets.inc cannon_04_elite | new term | base 1.04, firing 1.12, visible 1.04, still 1.04 (vet term: 1.17 / 1.26) |
| set/vision/settings.set | new actor terms | cannon_03_elite = vision_cannon_medium_elite, cannon_04_elite = vision_cannon_high_elite |
| properties/cannon_armor.ext loco_medium_elite | new macro | as loco_medium_vet, TurnTime 14.4 -> 12.8 |
| properties/cannon_armor.ext loco_big_elite | new macro | as loco_big_vet, TurnTime 22.5 -> 20 |

## 2. Sniper rifles

Date 2026-11-19. Undo tag: sniperfix-20261119. Commit 243293645.

| Weapon | Field | Old -> new | Why |
|---|---|---|---|
| mosin_s | recoveryTime (bolt cycle) | 2.8 -> 1.4 | owner rule: cycle time 1.4 s |
| mosin_s | tag | bolt_r280 -> bolt_r140 | follows the cycle time |
| mosin_s_vet | tags | inherits bolt_r140 from mosin_s (own tag bolt_r105, recovery 1.05 unchanged) | side effect of the line above |
| m1903a4_vet | base | `{from "pattern sniper_rifle"}` -> `{from "m1903a4"}` | bug: the vet rifle had the Mosin model, generic ammo, bullet speed 150 and no fire sound |
| m1903a4_vet | kept own values | PrepareTime 2.5, recoveryTime 1.05, range 150 150, tag bolt_r105 | owner vet rule |
| m1903a4_vet | inherited from m1903a4 | springfield_clip 5, bullet speed 855, fireSound rifle/m1903a4_s, rechargeTime 7.5 | follows the base rifle |

## 3. Price model

Dates 2026-11-19. Undo tags: pricecalc-20261119, pricecalc-20261119b, pricecalc-20261119c, pricemodel-20261119, shovel-20261119, shovelall-20261119, mortar60-20261119, pricecalc-20261119d. Commits 990aa6048, 001f235fb, 2566d233a; the last three tags are not committed yet.

The model work itself changed no real price. It changed only two things:
- `set/multiplayer/units/price_model.inc`. No file includes it. The game does not read it.
- `;{price ...}` comment lines next to soldier rows and squad cards. The game ignores comments.

Real data changed through the price work: the kit changes in 3a and the one price in 3b.

Check: the expanded unit sets are identical before and after (57b45f09b -> 990aa6048 and 990aa6048 -> 001f235fb). All 16 non-comment changed lines of 001f235fb are in price_model.inc. For pricecalc-20261119d: `pricecalc check` passed (comments only, a second apply changes nothing).

Hero cards (button hero, paid in SP) no longer get a computed-MP comment line (pricecalc-20261119d). The calculator cannot price them in MP. The model has no `{point_value}` yet, so these cards get no line at all, and 56 old lines were removed from 15 vehicle card files. Once a point value is set, the line will show the SP cost and what it is worth in MP.

Owner rules written into the model:

| Rule | Old -> new |
|---|---|
| Throwables (grenades): CP per tier | 0.05 -> 0.01; MP stays 0.05 |
| fg42_sc | priced as an auto rifle |
| m3_carbine | priced in the special carbine tier |
| Plain `panzerfaust` | = Panzerfaust 100 = pzf high tier |
| 60 mm mortar call-in | MP 20, CP 5 (the CP 5 -> 2 change made earlier on 2026-11-19 is withdrawn: owner, "the CP should be 5 for the 60 radio"; undo tag mortar60-20261119; a fresh seed from the rules file also gives CP 5) |
| `small_shovel` (digs a scrape; not the sandbag kit) | 8 MP -> free, in its own group `scrape_shovel`. Other spades stay 8 MP; sandbag kits stay priced per kit |
| Panzerfaust add-on | full add-on price -> price x chance of carrying it (`{item "x" 0 1 filled}` = 0.25), never more than once |

Effect on computed (not real) prices, example: card sturmgrens_44 302 -> 168 (real cost 134), sturmgrens_44_mech 358 -> 234 (real cost 223).

### 3a. Real kit change found through the price work

Date 2026-11-19. Undo tags: shovel-20261119, shovelall-20261119. Owner rules: a breed carries one small shovel; "All breeds have small".

| Breed | Item | Old -> new | Why |
|---|---|---|---|
| ger/ger_sturmgren_sl_asst | small_shovel | 2 -> 1 | the breed file listed it twice (already so in the original mod) |
| ger/ger_sturmgren_sg44_pzfst | small_shovel | 2 -> 1 | same |
| 800 breeds (list: undo tag shovelall-20261119, same paths) | small_shovel | 0 -> 1 | owner: every breed carries one small shovel |

Small shovel for every breed (shovelall-20261119):
- Scope: the 849 breeds the price calculator prices (870 `soldiers.set` rows; some breeds have two rows). 844 have a breed file in the mod. 44 already carried one shovel and 800 got one. Now all 844 carry exactly one.
- Line added: `{item "small_shovel" 1}`, put right before the `{in_hands N}` line (the last item of the kit). That is one of the places the 44 older ones use. Adding the item last does not move the `in_hands` index. No other line changed.
- Price: none changed. The shovel is free in the model (group `scrape_shovel`, price 0). The calculator gives the same result before and after on all 870 breed rows and 2440 cards (0 differences).
- Skipped, no breed file in the mod or game: eng/eng_elite_tankman, eng/eng_elite_tankcommander, jap/jap_elite_vehicle_supporter, axis_minor/axm_rom_vet_tankman2_single, axis_minor/axm_hun_tankmancommander_single. Their price rows point to files that do not exist (NO_BREED_FILE).
- Not touched: 344 breed files under `set/breed/mp/` that have no price row, none of them with a shovel: axis_minor 4, eng 45, ger 88, ger_ss 67, jap 47, rus 41, rus_guard 2, usa 50. Most are older or unprefixed versions of priced breeds, for example usa/devil_brigade_radio in the squads_42 card. Full list: `notes/robz-shovel-unpriced-breeds.tsv`. There is no breed folder outside `mp/`.
- No animal, dummy or other non-human breed is in the priced set. Officers, radiomen, crews, jap_kamikaze and jap_charger_throwgun got the shovel like everyone else.
- Inventory room: `GiveItems` (game/entity/eHumanBreed.cpp:83) puts each item with `PutWhole` (game/inventory/eInventoryLocation.cpp:277). That uses `FindPlace` with no rearrange, and an item that finds no place is deleted silently. The breed still loads. The mod's `stuff/special/small_shovel` has no `{size}`, so its size is 0x0 (eInventoryBox.cpp:63). It covers no cell, so it never pushes out another item. It still needs one free cell when it is placed (eInventoryBox.cpp:193-225, 585).
- [T] usa/usa_elite_101st_para4 (6x10 box): at the middle counts its kit covers all 60 cells. The shovel then has no free cell and is dropped silently, unless the random `{item "ammo m18recoilless wp" 1 1}` gives 0 rounds (about 1 time in 4). Next fullest kits (worst-case counts, simulated [I]): usa/usa_ranger_recoiless 2 free cells, eng/eng_pioneer_ap_miner 4, ger/ger_ap_miner 5. Items with no `{size}` (kits, mines, dynamite) were counted as 0x0.
- Found on the way, not changed: three kit items have no stuff in the mod or game, so the game gives nothing. axm_fin_sissi_squadleader has `knife_fin`, `small_inf_shovel` and `ammo_box_inf_fin`. axm_bul_mgun_assist has `ammo mauser_rifle mauser`.

### 3b. Real price change: 60 mm mortar call-in

Date 2026-11-19. Undo tag: mortar60-20261119. Owner: "Sheet is accurate". The sheet's Radio row prices the 60 mm call-in at 20 MP.

| What | File:line | Old -> new |
|---|---|---|
| level_93 score (MP). Its only price row is `mp/usa/usa_devil_brigade_radio` (soldiers.set:1854). The breed carries `mortar_60_flaregun`, the only 60 mm call-in | `set/multiplayer/units/soldiers.set:1848` | 75.0 -> 20.0 |
| Model, radio tier "60", cp | `set/multiplayer/units/price_model.inc:65` | 2 -> 5 (withdrawal, see section 3) |

The 75 and the 20 measure the same thing: the soldier row's `{score}`, which is the soldier's MP value. Model MP for the tier was already 20.
Not changed: the real CP of level_93 is still 2.0 (`soldiers.set:1847`), while the model now says 5. The owner's CP 5 was asked for the model only. The cards with this breed keep their own `cost()`: devils_brigade(usa) in usa/squads_43-45.set:62 costs 255.

## 4. Grenade item names

Date 2026-11-19. Undo tag: grenade-names-20261119. Commit 990aa6048.
Why: one naming form ("grenade X") for all grenade items.

| Old item name | New item name | Breeds | Effect |
|---|---|---|---|
| m24x5 | grenade m24x5 | axm_fin_kaukopartio_mgun_assist, axm_fin_kaukopartio_rifle | see "Not determined" |
| oto_mod35 | grenade oto_mod35 | axm_ita_paratrooper_mgun, axm_ita_paratrooper_mgun_assist, axm_ita_paratrooper_rifle, axm_ita_vehicle_supporter | see "Not determined" |
| molotov_coctail | grenade molotov_coctail | axm_fin_kaukopartio_mgun, axm_fin_kaukopartio_mgun_assist, axm_fin_kaukopartio_rifle, jap/ki_sa | see "Not determined" |
| ccm34smoke | ccm34smoke grenade | axm_ita_alpini_smg, axm_ita_bersaglieri_smg, axm_ita_paratrooper_mgun_assist, axm_ita_paratrooper_rifle, axm_ita_paratrooper_smg, axm_ita_paratrooper_squadleader, axm_ita_vehicle_supporter | see "Not determined" |
| 12 more names (word order only, e.g. "hohlladung grenade" -> "grenade hohlladung", "smoke grenade" -> "grenade smoke") | same words | many | none: item tags ignore word order |

Counts and amounts did not change in any breed (expansion check, 12 breeds differ only in these names).

## 5. Soldier breeds: skill, health and kit remap

Dates 2026-11-18 (commit cf7c41bd5) and 2026-11-19 (commit 57b45f09b). Design: `notes/robz-breed-remap-draft.md`.
Undo tags: soldier-remap-20261118, crew-remap-20261118, held-remap-20261118, charge-remap-20261118, charge2-remap-20261118, charge3-remap-20261118, pass7-remap-20261118, pass8-remap-20261118, fixes-20261118b (kit fixes). cleanup-20261118, pass9-20261119 and pass9b-remap-20261119 changed no values.
Why: owner rules. Every MP breed gets its perks from its role and level:
- Skill tables per level for rifle, smg, mgun and pistol.
- Body per level (health, stamina, tank / cannon perks): line troops vs hardy troops. SS and Japan are hardy.
- Rocket launcher skill 1, except rocket carriers and 1944-45 German / Hungarian non-assistants (level minus 1).
- Squad leaders = squad level + 1. Assistants copy the man they assist.
- Crews on a ladder crew_1..4 and support_1..2; crew health by tier (normal / vet / elite = level 3 / 5 / 7).
- Charge troops use the soldier_charge table. kamikaze, jap_kamikaze and ki_at_stick: level 5, speed 1.1.
- Pass 7 (57b45f09b): squads levelled; tankgun skill moved into the crew tables; veterancy table follows level.
- Pass 8 (57b45f09b): kaukopartio flamer split into its own breed; stamina regeneration 100% for all except charge troops (125%); SS Fallschirmjager levels from the owner's sheet.

Totals (expansion of all 1213 MP breeds, 4460f4dfd -> 001f235fb):
- 1159 breeds changed. 1158 in cf7c41bd5, 42 in 57b45f09b, 12 in 990aa6048 (names only, topic 4). 0 in 001f235fb.
- Field changes in cf7c41bd5: rocketlauncher 748, tank 668, melee 614, health 604, pistol 572, cannon 560, mgun 535, smg 449, rifle 431, stamina 367, speed 105, veterancy 89, vehicle 53, inventory 41, tankgun 38, stamina_regeneration 2.
- Field changes in 57b45f09b: stamina_regeneration 36 (125% -> 100%), 5 SS Fallschirmjager breeds (all skills and body), 1 veterancy, 1 new breed.
- Common value moves: speed 1 -> 0.9 (77 breeds); veterancy 24/60/108/168/240 -> 60/132/216/312/420 (82 breeds).
- New breed: axis_minor/axm_fin_kaukopartio_flamer (57b45f09b), with price row level_4 (cp 0.2, score 40); card "flamers" uses it.
- Removed breeds: jap/mgun3_ammo and jap/mgun3_asst (cf7c41bd5, undo fixes-20261118b), with their price rows. No card used them after the riflemans fix (topic 6).

Kit fixes inside the remap commit (undo fixes-20261118b), all checked in the expansion:

| Breed | Item | Old -> new | Why |
|---|---|---|---|
| axm_bul_officer, axm_fin_pio_flamer, axm_fin_pio_mgun, axm_fin_sissi_mgun, axm_fin_sissi_mgun_vision, axm_rom_bazooker | pistol ammo | ammo 9x19 -> ammo walther_mag (same count) | bug: ammo did not fit the pistol |
| axm_rom_bazooker_assist | pistol ammo | none -> ammo walther_mag 16 | bug: pistol had no ammo |
| jap/jap_mg3_asst | rifle | type99rifle + arisaka7-7_clip 200 -> type38rifle + arisaka6-5_clip 200 | bug: the gun it serves (Type 11) fires 6.5 mm |
| axm_ita_alpini_sniper | 9x17 ammo | 160 -> 35 | count fix |
| ger_ss/ss_kosaken_sl, ss_kosaken_sl_asst, ss_kosaken_smg | ammo ppsh41_mag | 142 -> 140 | count fix |
| axm_fin_tankman | ammo ppsh_mag | 142 -> 160 | count fix |
| axm_ita_vehicle_supporter | ammo mab_38a_mag | 128 -> 120 | count fix |
| axm_hun_smg_ppsh | ammo ppsh_mag | 240 -> 213 | count fix |
| axm_bul_smg | ammo mp40_mag | 120 -> 128 | count fix |
| smg_suomi_m31 kit macro: axm_fin_kaukopartio_squadleader, axm_fin_pio_smg, axm_fin_pio_squadleader, axm_fin_sissi_smg, axm_fin_sissi_smg_vision, axm_fin_sissi_squadleader | ammo ppsh_mag | 210 -> 213 | count fix |

### 5a. Every breed, old -> new

One row per breed and commit. Fields: hp health, sta stamina, sreg stamina regeneration, spd speed, tank / veh / can vehicle perks, pis pistol, smg, mg mgun, rif rifle, rl rocket launcher, mel melee, tg tankgun (numbers = lvl_N), vis vision, vet veterancy points lvl_1..lvl_5, inv inventory items removed (-) and added (+). Item names are shown in sorted word order. Breed folder = side.

#### Breeds: axis_minor (115 rows)

| Breed | Date | Changes (old>new) | Undo tag |
|---|---|---|---|
| axm_bul_at_rifle | 2026-11-18 | hp 150%>200%; sta 100%>150%; tank 0.75>0.85; can 0.8>0.9; smg 4>3; mg 1>3; rl 2>1 | held-remap-20261118 |
| axm_bul_at_rifle_assist | 2026-11-18 | hp 150%>200%; sta 100%>150%; tank 0.75>0.85; can 0.8>0.9; smg 4>3; mg 2>3; rl 2>1 | soldier-remap-20261118 |
| axm_bul_mgun | 2026-11-18 | hp 200%>150%; tank 0.8>0.75; can 1>0.8; pis 1>2; smg 1>2; mel 2>3 | soldier-remap-20261118 |
| axm_bul_mgun_assist | 2026-11-18 | hp 200%>150%; tank 0.8>0.75; can 1>0.8; pis 1>2; smg 1>2; mel 2>3 | soldier-remap-20261118 |
| axm_bul_miner_ap | 2026-11-18 | hp 200%>150%; tank 0.8>0.75; can 1>0.8; pis 2>4; smg 2>3; mg 1>2; mel 2>4 | soldier-remap-20261118 |
| axm_bul_miner_at | 2026-11-18 | hp 200%>150%; tank 0.8>0.75; can 1>0.8; pis 2>4; smg 2>3; mg 1>2; mel 2>4 | soldier-remap-20261118 |
| axm_bul_officer | 2026-11-18 | hp 300%>200%; sta 100%>150%; spd 1>0.9; tank 1>0.85; can 1>0.9; smg 1>5; mg 1>5; rif 1>5; mel 2>5; inv: -9x19 ammo 40, +ammo walther_mag 40 | fixes-20261118b, soldier-remap-20261118 |
| axm_bul_radioman | 2026-11-18 | hp 300%>150%; tank 0.8>0.75; can 1>0.8 | soldier-remap-20261118 |
| axm_bul_rifle | 2026-11-18 | tank 0.8>0.75; can 1>0.8; smg 1>2; mg 1>2; mel 2>3 | soldier-remap-20261118 |
| axm_bul_smg | 2026-11-18 | tank 0.8>0.75; can 1>0.8; mg 1>2; rif 1>2; mel 2>3; inv: -ammo mp40_mag 120, +ammo mp40_mag 128 | fixes-20261118b, soldier-remap-20261118 |
| axm_bul_squadleader | 2026-11-18 | hp 200%>150%; tank 0.8>0.75; can 1>0.8; pis 3>4; mel 2>4 | soldier-remap-20261118 |
| axm_bul_tankcommander | 2026-11-18 | rl 2>1 | crew-remap-20261118, held-remap-20261118 |
| axm_bul_tankman | 2026-11-18 | hp 100%>150%; rl 2>1 | crew-remap-20261118, held-remap-20261118 |
| axm_bul_vehicle_supporter | 2026-11-18 | rl 2>1 | crew-remap-20261118, held-remap-20261118 |
| axm_bul_vehicle_supporter_single | 2026-11-18 | rl 2>1 | crew-remap-20261118, held-remap-20261118 |
| axm_fin_at_rifle | 2026-11-18 | tank 0.8>0.75; can 1>0.8; mg 1>2; mel 2>3 | held-remap-20261118 |
| axm_fin_at_rifleassist | 2026-11-18 | tank 0.8>0.75; can 1>0.8; mg 1>2; mel 2>3 | soldier-remap-20261118 |
| axm_fin_elite_sniper | 2026-11-18 | hp 350%>400%; spd 1>0.9; tank 0.85>0.95; can 0.9>1; pis 2>6; smg 2>6; mg 2>6; rl 2>1; mel 4>6 | held-remap-20261118 |
| axm_fin_kaukopartio_flamer | 2026-11-19 | new breed | pass8-remap-20261118 |
| axm_fin_kaukopartio_mgun | 2026-11-19 | inv: -molotov_coctail 1, +grenade molotov_coctail 1 | grenade-names-20261119 |
| axm_fin_kaukopartio_mgun | 2026-11-18 | hp 200%>350%; sta 150%>200%; tank 0.9>0.95; pis 3>5; smg 3>5; rif 4>5; rl 3>1; mel 3>5; vet 24/60/108/168/240>60/132/216/312/420 | soldier-remap-20261118 |
| axm_fin_kaukopartio_mgun_assist | 2026-11-19 | inv: -m24x5 1, -molotov_coctail 1, +grenade m24x5 1, +grenade molotov_coctail 1 | grenade-names-20261119 |
| axm_fin_kaukopartio_mgun_assist | 2026-11-18 | hp 250%>350%; sta 150%>200%; tank 0.9>0.95; pis 3>5; smg 3>5; rif 6>5; rl 3>1; mel 3>5; vet 24/60/108/168/240>60/132/216/312/420 | soldier-remap-20261118 |
| axm_fin_kaukopartio_rifle | 2026-11-19 | inv: -m24x5 1, -molotov_coctail 1, +grenade m24x5 1, +grenade molotov_coctail 1 | grenade-names-20261119 |
| axm_fin_kaukopartio_rifle | 2026-11-18 | hp 200%>350%; sta 150%>200%; tank 0.9>0.95; pis 3>5; smg 3>5; mg 3>5; rl 3>1; mel 3>5; vet 24/60/108/168/240>60/132/216/312/420 | soldier-remap-20261118 |
| axm_fin_kaukopartio_smg | 2026-11-18 | hp 200%>350%; sta 150%>200%; tank 0.9>0.95; pis 3>5; rl 3>1; mel 3>5; vet 24/60/108/168/240>60/132/216/312/420 | soldier-remap-20261118 |
| axm_fin_kaukopartio_squadleader | 2026-11-18 | hp 200%>400%; sta 150%>200%; tank 0.9>0.95; pis 3>6; mg 5>6; rif 5>6; rl 3>1; mel 3>6; vet 24/60/108/168/240>60/132/216/312/420; inv: -ammo ppsh_mag 210, +ammo ppsh_mag 213 | soldier-remap-20261118 |
| axm_fin_officer | 2026-11-18 | hp 300%>200%; sta 100%>150%; spd 1>0.9; tank 1>0.85; can 1>0.9; smg 1>5; mg 1>5; rif 1>5; mel 2>5 | soldier-remap-20261118 |
| axm_fin_pio_flamer | 2026-11-18 | hp 250%>150%; tank 0.8>0.75; can 1>0.8; pis 2>4; smg 3>4; rif 4>3; mel 2>4; inv: -9x19 ammo 40, +ammo walther_mag 40 | fixes-20261118b, held-remap-20261118, soldier-remap-20261118 |
| axm_fin_pio_mgun | 2026-11-18 | hp 200%>150%; tank 0.8>0.75; can 1>0.8; pis 1>4; rif 4>3; mel 2>4; inv: -9x19 ammo 40, +ammo walther_mag 40 | fixes-20261118b, soldier-remap-20261118 |
| axm_fin_pio_rifle | 2026-11-18 | tank 0.8>0.75; can 1>0.8; pis 1>4; smg 1>3; mg 1>2; mel 2>4 | soldier-remap-20261118 |
| axm_fin_pio_rifle_dynamite | 2026-11-18 | tank 0.8>0.75; can 1>0.8; pis 1>4; smg 1>3; mg 1>2; mel 2>4 | soldier-remap-20261118 |
| axm_fin_pio_smg | 2026-11-18 | tank 0.8>0.75; can 1>0.8; pis 1>4; mg 1>2; rif 1>3; mel 2>4; inv: -ammo ppsh_mag 210, +ammo ppsh_mag 213 | soldier-remap-20261118 |
| axm_fin_pio_squadleader | 2026-11-18 | hp 150%>200%; sta 100%>150%; tank 0.8>0.85; can 1>0.9; pis 1>4; mg 1>3; rif 4>3; mel 2>4; inv: -ammo ppsh_mag 210, +ammo ppsh_mag 213 | soldier-remap-20261118 |
| axm_fin_sissi_mgun | 2026-11-18 | hp 200%>400%; sta 100%>200%; tank 0.8>0.95; pis 1>6; smg 5>6; mel 2>6; vet 24/60/108/168/240>60/132/216/312/420; inv: -9x19 ammo 40, +ammo walther_mag 40 | fixes-20261118b, soldier-remap-20261118 |
| axm_fin_sissi_mgun_assist | 2026-11-18 | hp 200%>400%; sta 100%>200%; tank 0.8>0.95; pis 1>6; smg 1>6; rif 7>6; mel 2>6; vet 24/60/108/168/240>60/132/216/312/420 | soldier-remap-20261118 |
| axm_fin_sissi_mgun_assist_vision | 2026-11-18 | hp 200%>400%; sta 100%>200%; spd 1.1>0.9; tank 0.8>0.95; pis 1>6; smg 1>6; rif 7>6; mel 2>6; vet 24/60/108/168/240>60/132/216/312/420 | crew-remap-20261118, soldier-remap-20261118 |
| axm_fin_sissi_mgun_vision | 2026-11-18 | hp 200%>400%; sta 100%>200%; spd 1.1>0.9; tank 0.8>0.95; pis 1>6; smg 1>6; rif 3>6; mel 2>6; vet 24/60/108/168/240>60/132/216/312/420; inv: -9x19 ammo 40, +ammo walther_mag 40 | fixes-20261118b, soldier-remap-20261118 |
| axm_fin_sissi_rifle | 2026-11-18 | hp 150%>400%; sta 100%>200%; tank 0.8>0.95; pis 1>6; smg 5>6; mg 5>6; mel 2>6; vet 24/60/108/168/240>60/132/216/312/420 | soldier-remap-20261118 |
| axm_fin_sissi_rifle_vision | 2026-11-18 | hp 150%>400%; sta 100%>200%; spd 1.1>0.9; tank 0.8>0.95; pis 1>6; smg 5>6; mg 5>6; mel 2>6; vet 24/60/108/168/240>60/132/216/312/420 | soldier-remap-20261118 |
| axm_fin_sissi_smg | 2026-11-18 | hp 150%>400%; sta 100%>200%; tank 0.8>0.95; pis 2>6; mg 5>6; rif 5>6; rl 3>1; mel 2>6; vet 24/60/108/168/240>60/132/216/312/420; inv: -ammo ppsh_mag 210, +ammo ppsh_mag 213 | soldier-remap-20261118 |
| axm_fin_sissi_smg_vision | 2026-11-18 | hp 150%>400%; sta 100%>200%; spd 1.1>0.9; tank 0.8>0.95; pis 2>6; mg 5>6; rif 5>6; rl 3>1; mel 2>6; vet 24/60/108/168/240>60/132/216/312/420; inv: -ammo ppsh_mag 210, +ammo ppsh_mag 213 | soldier-remap-20261118 |
| axm_fin_sissi_squadleader | 2026-11-18 | hp 200%>400%; sta 100%>200%; tank 0.8>0.95; pis 3>6; mg 5>6; rif 5>6; rl 3>1; mel 2>6; vet 24/60/108/168/240>60/132/216/312/420; inv: -ammo ppsh_mag 210, +ammo ppsh_mag 213 | soldier-remap-20261118 |
| axm_fin_sissi_squadleader_vision | 2026-11-18 | hp 200%>400%; sta 100%>200%; spd 1.1>0.9; tank 0.8>0.95; pis 3>6; mg 5>6; rif 5>6; rl 3>1; mel 2>6; vet 24/60/108/168/240>60/132/216/312/420; inv: -ammo ppsh_mag 210, +ammo ppsh_mag 213 | soldier-remap-20261118 |
| axm_fin_sniper | 2026-11-18 | hp 350%>200%; spd 1>0.9; tank 1>0.85; can 1>0.9; pis 2>4; smg 2>3; mg 1>3; mel 2>4 | held-remap-20261118 |
| axm_fin_tank_commander | 2026-11-18 | rl 2>1 | crew-remap-20261118, held-remap-20261118 |
| axm_fin_tankman | 2026-11-18 | hp 100%>150%; rl 2>1; inv: -ammo ppsh_mag 142, +ammo ppsh_mag 160 | crew-remap-20261118, fixes-20261118b, held-remap-20261118 |
| axm_fin_vehicle_supporter | 2026-11-18 | rl 2>1 | crew-remap-20261118, held-remap-20261118 |
| axm_ger_vehicle_supporter | 2026-11-18 | rl 2>1 | crew-remap-20261118, held-remap-20261118 |
| axm_hun_assualt_flamer | 2026-11-18 | hp 200%>150%; sta 200%>100%; tank 1>0.75; can 1>0.8; mg 4>2; rif 4>3; rl 4>3 | held-remap-20261118 |
| axm_hun_assualt_mgun | 2026-11-18 | hp 200%>150%; sta 200%>100%; tank 1>0.75; can 1>0.8; smg 4>3; rif 4>3; rl 4>3 | soldier-remap-20261118 |
| axm_hun_assualt_mgun_assist | 2026-11-18 | hp 200%>150%; sta 200%>100%; tank 1>0.75; can 1>0.8; smg 4>3; rif 4>3; rl 4>1 | soldier-remap-20261118 |
| axm_hun_assualt_pzf | 2026-11-18 | hp 200%>150%; sta 200%>100%; tank 1>0.75; can 1>0.8; mg 4>2; rif 4>3 | soldier-remap-20261118 |
| axm_hun_assualt_rifle | 2026-11-18 | hp 200%>150%; sta 200%>100%; tank 1>0.75; can 1>0.8; smg 4>3; mg 4>2; rl 4>3 | soldier-remap-20261118 |
| axm_hun_assualt_smg | 2026-11-18 | hp 200%>150%; sta 200%>100%; tank 1>0.75; can 1>0.8; mg 4>2; rif 4>3; rl 4>3 | soldier-remap-20261118 |
| axm_hun_assualt_squadleader | 2026-11-18 | hp 350%>200%; sta 200%>150%; tank 1>0.85; can 1>0.9; mg 4>3; rif 4>3 | soldier-remap-20261118 |
| axm_hun_elite_tankcommander | 2026-11-18 | hp 100%>400%; sta 100%>200%; tank 1.15>1.2; veh 1.15>1.2; can 1>1.1; pis 6>5; smg 2>5; mg 1>6; rif 1>3; mel 2>4; tg 8>10 | crew-remap-20261118, held-remap-20261118 |
| axm_hun_elite_tankman | 2026-11-18 | hp 100%>400%; sta 100%>200%; pis 2>5; smg 2>5; mg 1>5; rif 1>3; mel 2>4; tg 8>7 | crew-remap-20261118, held-remap-20261118 |
| axm_hun_rifle | 2026-11-18 | tank 0.8>0.75; can 1>0.8; pis 2>1 | soldier-remap-20261118 |
| axm_hun_rifle3 | 2026-11-18 | tank 0.8>0.75; can 1>0.8; pis 2>1 | soldier-remap-20261118 |
| axm_hun_smg_danuvia | 2026-11-18 | tank 0.8>0.75; can 1>0.8; smg 3>2 | soldier-remap-20261118 |
| axm_hun_smg_ppsh | 2026-11-18 | tank 0.8>0.75; can 1>0.8; inv: -ammo ppsh_mag 240, +ammo ppsh_mag 213 | fixes-20261118b, soldier-remap-20261118 |
| axm_hun_squadleader_smg | 2026-11-18 | hp 200%>150%; tank 0.8>0.75; can 1>0.8; pis 3>2; rif 3>2; rl 1>2; mel 2>3 | soldier-remap-20261118 |
| axm_hun_tankcommander | 2026-11-18 | rl 2>1 | crew-remap-20261118, held-remap-20261118 |
| axm_hun_tankcommander_single | 2026-11-18 | rl 2>1 | crew-remap-20261118, held-remap-20261118 |
| axm_hun_tankman | 2026-11-18 | hp 100%>150%; rl 2>1 | crew-remap-20261118, held-remap-20261118 |
| axm_hun_tankman_single | 2026-11-18 | hp 100%>150%; rl 2>1 | crew-remap-20261118, held-remap-20261118 |
| axm_hun_vehicle_supporter | 2026-11-18 | rl 2>1 | crew-remap-20261118, held-remap-20261118 |
| axm_hun_vet_tankcommander | 2026-11-18 | hp 100%>200%; sta 100%>150%; pis 6>5; smg 2>5; mg 4>5; rif 1>3; mel 2>4 | crew-remap-20261118, held-remap-20261118 |
| axm_hun_vet_tankman | 2026-11-18 | hp 100%>200%; sta 100%>150%; tank 1.15>1.1; veh 1.15>1; can 1>0.95; pis 2>4; smg 2>4; rif 1>3; mel 2>4; tg 8>4 | crew-remap-20261118, held-remap-20261118 |
| axm_ita_alpini_mgun | 2026-11-18 | hp 200%>150%; tank 0.8>0.75; can 1>0.8; pis 1>4; smg 1>3; mel 2>4 | soldier-remap-20261118 |
| axm_ita_alpini_mgun_assist | 2026-11-18 | tank 0.8>0.75; can 1>0.8; pis 2>4; rif 4>3; mel 2>4 | soldier-remap-20261118 |
| axm_ita_alpini_rifle | 2026-11-18 | hp 200%>150%; tank 0.8>0.75; can 1>0.8; pis 2>4; smg 1>3; mg 3>2; mel 2>4 | soldier-remap-20261118 |
| axm_ita_alpini_rifle2 | 2026-11-18 | tank 0.8>0.75; can 1>0.8; pis 2>4; mg 3>2; mel 2>4 | soldier-remap-20261118 |
| axm_ita_alpini_smg | 2026-11-19 | inv: -ccm34smoke 1, +ccm34smoke grenade 1 | grenade-names-20261119 |
| axm_ita_alpini_smg | 2026-11-18 | tank 0.8>0.75; can 1>0.8; pis 2>4; mel 2>4 | soldier-remap-20261118 |
| axm_ita_alpini_sniper | 2026-11-18 | hp 350%>150%; sta 150%>100%; spd 1>0.9; tank 1>0.75; can 1>0.8; pis 2>4; smg 2>3; mg 4>2; rif 5>4; mel 2>4; inv: -9x17 ammo 160, +9x17 ammo 35 | crew-remap-20261118, fixes-20261118b, soldier-remap-20261118 |
| axm_ita_alpini_squadleader | 2026-11-18 | sta 100%>150%; tank 0.8>0.85; can 1>0.9; pis 3>4; mg 2>3; mel 2>4 | soldier-remap-20261118 |
| axm_ita_bersaglieri_mgun | 2026-11-18 | sta 100%>150%; tank 0.8>0.85; can 1>0.9; pis 1>4; smg 4>3; rif 4>3; mel 2>4 | soldier-remap-20261118 |
| axm_ita_bersaglieri_mgun_assist | 2026-11-18 | sta 100%>150%; tank 0.8>0.85; can 1>0.9; pis 1>4; rif 5>3; mel 2>4 | soldier-remap-20261118 |
| axm_ita_bersaglieri_rifle | 2026-11-18 | sta 100%>150%; tank 0.8>0.85; can 1>0.9; pis 2>4; smg 4>3; mg 4>3; mel 2>4 | soldier-remap-20261118 |
| axm_ita_bersaglieri_rifle2 | 2026-11-18 | sta 100%>150%; tank 0.8>0.85; can 1>0.9; pis 2>4; smg 4>3; mg 4>3; mel 2>4 | soldier-remap-20261118 |
| axm_ita_bersaglieri_smg | 2026-11-19 | inv: -ccm34smoke 2, +ccm34smoke grenade 2 | grenade-names-20261119 |
| axm_ita_bersaglieri_smg | 2026-11-18 | sta 100%>150%; tank 0.8>0.85; can 1>0.9; pis 2>4; rif 4>3; mel 2>4 | soldier-remap-20261118 |
| axm_ita_paratrooper_mgun | 2026-11-19 | inv: -oto_mod35 1, +grenade oto_mod35 1 | grenade-names-20261119 |
| axm_ita_paratrooper_mgun | 2026-11-18 | hp 200%>400%; sta 150%>200%; tank 0.9>0.95; pis 3>6; smg 3>6; rif 7>6; rl 3>1; mel 3>6; vet 24/60/108/168/240>60/132/216/312/420 | soldier-remap-20261118 |
| axm_ita_paratrooper_mgun_assist | 2026-11-19 | inv: -ccm34smoke 2, -oto_mod35 2, +ccm34smoke grenade 2, +grenade oto_mod35 2 | grenade-names-20261119 |
| axm_ita_paratrooper_mgun_assist | 2026-11-18 | hp 200%>400%; sta 150%>200%; tank 0.9>0.95; pis 3>6; smg 3>6; rif 7>6; rl 3>1; mel 3>6; vet 24/60/108/168/240>60/132/216/312/420 | soldier-remap-20261118 |
| axm_ita_paratrooper_rifle | 2026-11-19 | inv: -ccm34smoke 2, -oto_mod35 2, +ccm34smoke grenade 2, +grenade oto_mod35 2 | grenade-names-20261119 |
| axm_ita_paratrooper_rifle | 2026-11-18 | hp 250%>400%; sta 150%>200%; tank 0.9>0.95; pis 3>6; smg 3>6; mg 5>6; rl 3>1; mel 3>6; vet 24/60/108/168/240>60/132/216/312/420 | soldier-remap-20261118 |
| axm_ita_paratrooper_smg | 2026-11-19 | inv: -ccm34smoke 2, +ccm34smoke grenade 2 | grenade-names-20261119 |
| axm_ita_paratrooper_smg | 2026-11-18 | hp 200%>400%; sta 150%>200%; tank 0.9>0.95; pis 3>6; mg 4>6; rif 5>6; rl 3>1; mel 3>6; vet 24/60/108/168/240>60/132/216/312/420 | soldier-remap-20261118 |
| axm_ita_paratrooper_squadleader | 2026-11-19 | inv: -ccm34smoke 4, +ccm34smoke grenade 4 | grenade-names-20261119 |
| axm_ita_paratrooper_squadleader | 2026-11-18 | hp 200%>400%; sta 150%>200%; tank 0.9>0.95; pis 3>6; mg 4>6; rif 7>6; rl 3>1; mel 3>6; vet 24/60/108/168/240>60/132/216/312/420 | soldier-remap-20261118 |
| axm_ita_tankcommander | 2026-11-18 | pis 2>4; smg 2>4; rif 1>3; mel 2>4; tg 6>4 | crew-remap-20261118, held-remap-20261118 |
| axm_ita_tankman | 2026-11-18 | hp 100%>150%; pis 2>4; smg 2>4; rif 1>3; mel 2>4 | crew-remap-20261118, held-remap-20261118 |
| axm_ita_vehicle_supporter | 2026-11-19 | inv: -ccm34smoke 1, -oto_mod35 1, +ccm34smoke grenade 1, +grenade oto_mod35 1 | grenade-names-20261119 |
| axm_ita_vehicle_supporter | 2026-11-18 | rl 2>1; inv: -ammo mab_38a_mag 128, +ammo mab_38a_mag 120 | crew-remap-20261118, fixes-20261118b, held-remap-20261118 |
| axm_ita_vettankcommander | 2026-11-18 | hp 150%>200%; sta 100%>150%; tank 1.1>1.15; veh 1>1.15; can 0.95>1; pis 2>5; smg 2>5; mg 4>5; rif 1>3; mel 2>4 | crew-remap-20261118, held-remap-20261118 |
| axm_ita_vettankman | 2026-11-18 | hp 100%>200%; sta 100%>150%; tank 1>1.1; can 0.9>0.95; pis 2>4; smg 2>4; rif 1>3; mel 2>4; tg 7>4 | crew-remap-20261118, held-remap-20261118 |
| axm_rom_bazooker | 2026-11-18 | hp 200%>150%; tank 0.8>0.75; can 1>0.8; pis 3>2; mg 1>2; rif 1>3; mel 2>3; inv: -9x19 ammo 40, +ammo walther_mag 40 | fixes-20261118b, soldier-remap-20261118 |
| axm_rom_bazooker_assist | 2026-11-18 | hp 200%>150%; tank 0.8>0.75; can 1>0.8; pis 3>2; mg 1>2; rif 1>3; rl 3>1; mel 2>3; inv: +ammo walther_mag 16 | fixes-20261118b, soldier-remap-20261118 |
| axm_rom_elite_vehicle_supporter | 2026-11-18 | hp 100%>400%; sta 100%>200%; spd 0.8>0.9; tank 1.15>1; veh 1.15>1; pis 5>3; smg 5>3; rif 5>3; rl 2>1 | crew-remap-20261118, held-remap-20261118 |
| axm_rom_mgun | 2026-11-18 | tank 0.8>0.75; can 1>0.8; smg 1>2; rif 3>2; mel 2>3 | soldier-remap-20261118 |
| axm_rom_mgunassist | 2026-11-18 | tank 0.8>0.75; can 1>0.8; smg 1>2; rif 3>2; mel 2>3 | soldier-remap-20261118 |
| axm_rom_minedisposal | 2026-11-18 | tank 1>0.75; can 1>0.8; pis 4>2; mg 1>2; rif 1>2; mel 2>3 | soldier-remap-20261118 |
| axm_rom_rifle | 2026-11-18 | tank 0.8>0.75; can 1>0.8; smg 1>2; mg 1>2; mel 2>3 | soldier-remap-20261118 |
| axm_rom_smg | 2026-11-18 | tank 0.8>0.75; can 1>0.8; mg 1>2; rif 1>2; mel 2>3 | soldier-remap-20261118 |
| axm_rom_squadleader | 2026-11-18 | hp 200%>150%; tank 0.8>0.75; can 1>0.8; pis 3>4; rif 4>3; mel 2>4 | soldier-remap-20261118 |
| axm_rom_tankcommander | 2026-11-18 | rl 2>1 | crew-remap-20261118, held-remap-20261118 |
| axm_rom_tankman | 2026-11-18 | hp 100%>150%; rl 2>1 | crew-remap-20261118, held-remap-20261118 |
| axm_rom_vehicle_supporter | 2026-11-18 | rl 2>1 | crew-remap-20261118, held-remap-20261118 |
| axm_rom_vet_tankcommander | 2026-11-18 | hp 150%>200%; sta 100%>150%; tank 1.2>1.15; veh 1.2>1.15; pis 4>5; mg 6>5; rl 2>1 | crew-remap-20261118, held-remap-20261118 |
| axm_rom_vet_tankcommander_single | 2026-11-18 | hp 150%>200%; sta 100%>150%; tank 1.2>1.15; veh 1.2>1.15; pis 4>5; mg 6>5; rl 2>1 | crew-remap-20261118, held-remap-20261118 |
| axm_rom_vet_tankman | 2026-11-18 | hp 150%>200%; sta 100%>150%; tank 1.2>1.1; veh 1.2>1; can 1>0.95; smg 5>4; mg 6>4; rl 2>1; tg 7>4 | crew-remap-20261118, held-remap-20261118 |

#### Breeds: eng (129 rows)

| Breed | Date | Changes (old>new) | Undo tag |
|---|---|---|---|
| ap_miner | 2026-11-18 | tank 0.8>0.75; can 1>0.8; mel 2>3 | soldier-remap-20261118 |
| at_miner | 2026-11-18 | tank 0.8>0.75; can 1>0.8 | soldier-remap-20261118 |
| at_rifle | 2026-11-18 | tank 0.8>0.75; can 1>0.8; pis 2>1; smg 3>1; mg 2>1; rif 4>2; rl 2>1; mel 3>2 | crew-remap-20261118, soldier-remap-20261118 |
| at_rifle2 | 2026-11-18 | tank 0.8>0.75; can 1>0.8; mg 2>1; rif 3>1; mel 3>2 | soldier-remap-20261118 |
| elite_40 | 2026-11-18 | sta 150%>200%; tank 0.9>0.95; pis 6>5; mg 6>5; rif 6>5; rl 6>1; mel 6>5 | soldier-remap-20261118 |
| elite_cpl | 2026-11-18 | hp 350%>400%; sta 150%>200%; tank 0.9>0.95; pis 7>6; mg 7>6; rif 7>6; rl 7>1; mel 7>6 | soldier-remap-20261118 |
| elite_tankman | 2026-11-18 | hp 100%>400%; sta 100%>200%; pis 4>5; smg 4>5; rif 2>3; mel 3>4; tg 8>7 | crew-remap-20261118, held-remap-20261118 |
| elite_tankman2 | 2026-11-18 | hp 150%>400%; sta 100%>200%; can 1>1.1; pis 4>5; smg 4>5; mg 7>6; rif 2>3; mel 3>4 | crew-remap-20261118, held-remap-20261118 |
| elite2 | 2026-11-18 | sta 150%>200%; tank 0.9>0.95; pis 6>5; smg 6>5; mg 6>5; rl 6>1; mel 6>5 | soldier-remap-20261118 |
| elite2_40 | 2026-11-18 | sta 150%>200%; tank 0.9>0.95; pis 6>5; smg 6>5; mg 6>5; rl 6>1; mel 6>5 | soldier-remap-20261118 |
| elite3 | 2026-11-18 | sta 150%>200%; tank 0.9>0.95; pis 6>5; smg 6>5; rif 6>5; rl 6>1; mel 6>5 | soldier-remap-20261118 |
| eng_anzac_at_rifle | 2026-11-18 | hp 250%>150%; sta 200%>100%; tank 0.9>0.75; can 1>0.8; pis 3>4; mg 3>2; rl 3>1; mel 3>4 | soldier-remap-20261118 |
| eng_anzac_mg | 2026-11-18 | hp 250%>150%; sta 200%>100%; tank 0.9>0.75; can 1>0.8; pis 3>4; rl 3>1; mel 3>4 | soldier-remap-20261118 |
| eng_anzac_mg_assist | 2026-11-18 | hp 250%>150%; sta 200%>100%; tank 0.9>0.75; can 1>0.8; pis 3>4; rif 4>3; rl 3>1; mel 3>4 | crew-remap-20261118, soldier-remap-20261118 |
| eng_anzac_rifle | 2026-11-18 | hp 250%>150%; sta 200%>100%; tank 0.9>0.75; can 1>0.8; pis 3>4; mg 3>2; rl 3>1; mel 3>4 | soldier-remap-20261118 |
| eng_anzac_rifle_grenadier | 2026-11-18 | hp 250%>150%; sta 200%>100%; tank 0.9>0.75; can 1>0.8; pis 3>4; mg 3>2; rl 3>1; mel 3>4 | soldier-remap-20261118 |
| eng_anzac_sl | 2026-11-18 | hp 250%>200%; sta 200%>150%; tank 0.9>0.85; can 1>0.9; pis 3>4; rl 3>1; mel 3>4 | soldier-remap-20261118 |
| eng_anzac_smg | 2026-11-18 | hp 250%>150%; sta 200%>100%; tank 0.9>0.75; can 1>0.8; pis 3>4; mg 3>2; rl 3>1; mel 3>4 | soldier-remap-20261118 |
| eng_anzac_smg_thompson | 2026-11-18 | hp 250%>150%; sta 200%>100%; tank 0.9>0.75; can 1>0.8; pis 3>4; mg 3>2; rl 3>1; mel 3>4 | soldier-remap-20261118 |
| eng_ap_miner | 2026-11-18 | tank 0.8>0.75; can 1>0.8; mel 2>3 | soldier-remap-20261118 |
| eng_at_miner | 2026-11-18 | tank 0.8>0.75; can 1>0.8 | soldier-remap-20261118 |
| eng_at_rifle | 2026-11-18 | tank 0.8>0.75; can 1>0.8; pis 2>4; rl 2>1; mel 3>4 | held-remap-20261118 |
| eng_at_rifle_assist | 2026-11-18 | tank 0.8>0.75; can 1>0.8; pis 2>4; smg 2>3; rif 3>4; mel 3>4 | soldier-remap-20261118 |
| eng_bazooker | 2026-11-18 | tank 0.8>0.75; can 1>0.8; pis 2>4; smg 3>4; rif 2>3; mel 3>4 | soldier-remap-20261118 |
| eng_bazooker_assist | 2026-11-18 | tank 0.8>0.75; can 1>0.8; rl 4>1 | soldier-remap-20261118 |
| eng_commando_bren | 2026-11-18 | sta 150%>200%; tank 0.9>0.95; pis 6>5; smg 6>5; rif 6>5; rl 6>1; mel 6>5 | soldier-remap-20261118 |
| eng_commando_bren_assist | 2026-11-18 | sta 150%>200%; tank 0.9>0.95; pis 6>5; smg 6>5; rif 6>5; rl 6>1; mel 6>5 | soldier-remap-20261118 |
| eng_commando_carbine | 2026-11-18 | sta 150%>200%; tank 0.9>0.95; pis 6>5; smg 6>5; mg 6>5; rl 6>1; mel 6>5 | soldier-remap-20261118 |
| eng_commando_cpl_smg | 2026-11-18 | hp 350%>400%; sta 150%>200%; tank 0.9>0.95; pis 7>6; mg 7>6; rif 7>6; rl 7>1; mel 7>6 | soldier-remap-20261118 |
| eng_commando_silence_carbine | 2026-11-18 | sta 150%>200%; tank 0.9>0.95; pis 6>5; smg 6>5; mg 6>5; rl 6>1; mel 6>5 | soldier-remap-20261118 |
| eng_commando_silencesmg | 2026-11-18 | sta 150%>200%; tank 0.9>0.95; pis 6>5; mg 6>5; rif 6>5; rl 6>1; mel 6>5 | soldier-remap-20261118 |
| eng_commando_sl | 2026-11-18 | hp 350%>400%; sta 150%>200%; tank 0.9>0.95; pis 7>6; mg 7>6; rif 7>6; rl 7>1; mel 7>6 | soldier-remap-20261118 |
| eng_commando_smg | 2026-11-18 | sta 150%>200%; tank 0.9>0.95; pis 6>5; mg 6>5; rif 6>5; rl 6>1; mel 6>5 | soldier-remap-20261118 |
| eng_flamer | 2026-11-18 | tank 0.8>0.75; can 1>0.8 | held-remap-20261118 |
| eng_flamer_assist | 2026-11-18 | tank 0.8>0.75; can 1>0.8 | soldier-remap-20261118 |
| eng_light_mortar | 2026-11-18 | hp 150%>100%; sta 100%>75%; tank 0.8>0.75; can 1>0.8; pis 2>1; smg 2>1; mg 2>1; rif 5>1; mel 4>2 | soldier-remap-20261118 |
| eng_light_mortar_assist | 2026-11-18 | hp 150%>200%; sta 100%>150%; tank 0.8>0.85; can 1>0.9; pis 2>4; smg 2>3; mg 2>3 | soldier-remap-20261118 |
| eng_mg_assist_canada | 2026-11-18 | tank 0.8>0.75; can 1>0.8; rif 3>2 | soldier-remap-20261118 |
| eng_mg_canada | 2026-11-18 | tank 0.8>0.75; can 1>0.8 | soldier-remap-20261118 |
| eng_mgun | 2026-11-18 | tank 0.8>0.75; can 1>0.8; pis 2>4; smg 2>3; rif 2>3 | soldier-remap-20261118 |
| eng_mgun_assist_scot | 2026-11-18 | hp 150%>200%; sta 100%>150%; tank 0.8>0.85; can 1>0.9; pis 3>4; rif 5>3; rl 2>1; mel 5>4 | soldier-remap-20261118 |
| eng_mgun_asst | 2026-11-18 | tank 0.8>0.75; can 1>0.8; pis 2>4; smg 2>3; rif 4>3 | soldier-remap-20261118 |
| eng_mgun_scot | 2026-11-18 | hp 150%>200%; sta 100%>150%; tank 0.8>0.85; can 1>0.9; pis 3>4; rl 2>1; mel 5>4 | soldier-remap-20261118 |
| eng_officer | 2026-11-18 | hp 250%>200%; spd 1>0.9; tank 1>0.85; can 1>0.9; mg 4>5; rif 4>5; rl 3>1; mel 4>5 | soldier-remap-20261118 |
| eng_paratrooper_bren | 2026-11-18 | hp 400%>350%; tank 1>0.95; pis 6>5; smg 6>5; rif 6>5; rl 6>1; mel 6>5 | soldier-remap-20261118 |
| eng_paratrooper_carbine | 2026-11-18 | hp 400%>350%; tank 1>0.95; pis 6>5; smg 6>5; mg 6>5; rl 6>1; mel 6>5 | soldier-remap-20261118 |
| eng_paratrooper_cpl_smg | 2026-11-18 | tank 1>0.95; pis 7>6; mg 7>6; rif 7>6; rl 7>1; mel 7>6 | soldier-remap-20261118 |
| eng_paratrooper_lightmortar | 2026-11-18 | hp 400%>350%; tank 1>0.95; pis 6>5; mg 6>5; rif 6>5; mel 6>5 | soldier-remap-20261118 |
| eng_paratrooper_sic | 2026-11-18 | tank 1>0.95; pis 7>6; mg 7>6; rif 7>6; rl 7>1; mel 7>6 | soldier-remap-20261118 |
| eng_paratrooper_smg | 2026-11-18 | hp 400%>350%; tank 1>0.95; pis 6>5; mg 6>5; rif 6>5; rl 6>1; mel 6>5 | soldier-remap-20261118 |
| eng_paratroopr_em2 | 2026-11-18 | hp 400%>350%; tank 1>0.95; pis 6>5; smg 6>5; mg 6>5; rl 6>1; mel 6>5 | held-remap-20261118 |
| eng_pioneer_1trench | 2026-11-18 | tank 0.8>0.75; can 1>0.8; pis 2>4; smg 2>3; rl 2>1 | soldier-remap-20261118 |
| eng_pioneer_3trench | 2026-11-18 | tank 0.8>0.75; can 1>0.8; pis 2>4; smg 2>3; rl 2>1 | soldier-remap-20261118 |
| eng_pioneer_ap_miner | 2026-11-18 | tank 0.8>0.75; can 1>0.8; pis 2>4; smg 2>3; rl 2>1 | soldier-remap-20261118 |
| eng_pioneer_at | 2026-11-18 | tank 0.8>0.75; can 1>0.8; pis 2>4; smg 2>3 | soldier-remap-20261118 |
| eng_pioneer_at_miner | 2026-11-18 | tank 0.8>0.75; can 1>0.8; pis 2>4; smg 2>3; rl 2>1 | soldier-remap-20261118 |
| eng_pioneer_flamer | 2026-11-18 | tank 0.8>0.75; can 1>0.8; pis 2>4; smg 2>4; rif 4>3; rl 2>1 | held-remap-20261118 |
| eng_pioneer_mg | 2026-11-18 | tank 0.8>0.75; can 1>0.8; pis 2>4; smg 2>3; rl 2>1 | soldier-remap-20261118 |
| eng_pioneer_minedisposal | 2026-11-18 | tank 0.8>0.75; can 1>0.8; pis 2>4; smg 2>3; rl 2>1 | soldier-remap-20261118 |
| eng_pioneer_sl | 2026-11-18 | hp 150%>200%; sta 100%>150%; tank 0.8>0.85; can 1>0.9; pis 3>4; rif 4>5; rl 3>1 | soldier-remap-20261118 |
| eng_radioman_airstrike | 2026-11-18 | tank 0.8>0.75; can 1>0.8 | soldier-remap-20261118 |
| eng_rifle_grenadier | 2026-11-18 | tank 0.8>0.75; can 1>0.8; pis 2>4; smg 2>3 | soldier-remap-20261118 |
| eng_rifle_piat | 2026-11-18 | tank 0.8>0.75; can 1>0.8; pis 2>4; smg 2>3 | soldier-remap-20261118 |
| eng_rifle_scot | 2026-11-18 | hp 150%>200%; sta 100%>150%; tank 0.8>0.85; can 1>0.9; pis 3>4; rl 2>1; mel 5>4 | soldier-remap-20261118 |
| eng_rifleman | 2026-11-18 | tank 0.8>0.75; can 1>0.8; pis 2>4; smg 2>3 | soldier-remap-20261118 |
| eng_rifleman_canada | 2026-11-18 | tank 0.8>0.75; can 1>0.8 | soldier-remap-20261118 |
| eng_rifleman_smoke | 2026-11-18 | tank 0.8>0.75; can 1>0.8; pis 2>4; smg 2>3 | soldier-remap-20261118 |
| eng_saper | 2026-11-18 | tank 0.8>0.75; can 1>0.8 | soldier-remap-20261118 |
| eng_saper2 | 2026-11-18 | tank 0.8>0.75; can 1>0.8 | soldier-remap-20261118 |
| eng_sas_2ic | 2026-11-18 | tank 1>0.95; pis 7>6; mg 7>6; rif 7>6; rl 7>1; mel 7>6 | soldier-remap-20261118 |
| eng_sas_at_rifle | 2026-11-18 | tank 1>0.95; pis 7>6; mg 7>6; rif 7>6; rl 7>1; mel 7>6; inv: -grenade n77_smoke 0.5 1, +grenade n77_smoke 0.5 0.5 | soldier-remap-20261118 |
| eng_sas_bran_assist | 2026-11-18 | tank 1>0.95; pis 7>6; smg 7>6; rif 7>6; mel 7>6; inv: -grenade n77_smoke 0.5 1, +grenade n77_smoke 0.5 0.5 | soldier-remap-20261118 |
| eng_sas_bren2 | 2026-11-18 | tank 1>0.95; pis 7>6; smg 7>6; rif 7>6; rl 7>1; mel 7>6; inv: -grenade n77_smoke 0.5 1, +grenade n77_smoke 0.5 0.5 | soldier-remap-20261118 |
| eng_sas_bren2_assist | 2026-11-18 | tank 1>0.95; pis 7>6; smg 7>6; rif 7>6; rl 7>1; mel 7>6; inv: -grenade n77_smoke 0.5 1, +grenade n77_smoke 0.5 0.5 | soldier-remap-20261118 |
| eng_sas_cpl | 2026-11-18 | tank 1>0.95; pis 7>6; mg 7>6; rif 7>6; rl 7>1; mel 7>6 | soldier-remap-20261118 |
| eng_sas_piat | 2026-11-18 | tank 1>0.95; pis 7>6; mg 7>6; rif 7>6; mel 7>6; inv: -grenade n77_smoke 0.5 1, +grenade n77_smoke 0.5 0.5 | soldier-remap-20261118 |
| eng_sas_piat_assist | 2026-11-18 | tank 1>0.95; pis 7>6; mg 7>6; rif 7>6; rl 7>1; mel 7>6; inv: -grenade n77_smoke 0.5 1, +grenade n77_smoke 0.5 0.5 | soldier-remap-20261118 |
| eng_sas_rifle1 | 2026-11-18 | tank 1>0.95; pis 7>6; smg 7>6; mg 7>6; rl 7>1; mel 7>6; inv: -grenade n77_smoke 0.5 1, +grenade n77_smoke 0.5 0.5 | soldier-remap-20261118 |
| eng_smg | 2026-11-18 | tank 0.8>0.75; can 1>0.8; pis 2>4; rif 2>3; mel 3>4 | soldier-remap-20261118 |
| eng_smg_wp | 2026-11-18 | tank 0.8>0.75; can 1>0.8; pis 2>4; rif 2>3; mel 3>4 | soldier-remap-20261118 |
| eng_sniper | 2026-11-18 | sta 150%>200%; spd 1>0.9; tank 1>0.95; pis 3>5; smg 3>5; mg 3>5; rl 2>1; mel 4>5; vet 24/60/108/168/240>60/132/216/312/420 | held-remap-20261118 |
| eng_squadleader | 2026-11-18 | sta 100%>150%; tank 0.8>0.85; can 1>0.9; rif 4>3; rl 2>1; mel 5>4 | soldier-remap-20261118 |
| eng_squadleader_asst | 2026-11-18 | sta 100%>150%; tank 0.8>0.85; can 1>0.9; smg 4>5; rif 5>3; rl 2>1; mel 5>4 | soldier-remap-20261118 |
| eng_squadleader_can | 2026-11-18 | hp 200%>150%; tank 0.8>0.75; can 1>0.8; pis 3>4; smg 4>3; rif 3>4; rl 2>1 | soldier-remap-20261118 |
| eng_squadleader_scot | 2026-11-18 | hp 200%>350%; sta 100%>200%; tank 0.8>0.95; mg 4>5; rif 5>6; rl 4>1; vet 24/60/108/168/240>60/132/216/312/420 | soldier-remap-20261118 |
| eng_squadleader2 | 2026-11-18 | sta 100%>150%; tank 0.8>0.85; can 1>0.9; rif 4>3; rl 2>1; mel 5>4 | soldier-remap-20261118 |
| eng_tankman_single | 2026-11-18 | hp 100%>150%; can 1>0.9; pis 3>4; smg 3>4; rif 2>3; mel 3>4 | crew-remap-20261118, held-remap-20261118 |
| eng_tankman2_single | 2026-11-18 | hp 100%>150%; tank 1>1.1; can 1>0.95; pis 3>4; smg 3>4; mg 2>4; rif 2>3; mel 3>4 | crew-remap-20261118, held-remap-20261118 |
| eng_vet_tankman2_single | 2026-11-18 | hp 150%>200%; sta 100%>150%; tank 1.2>1.15; veh 1.2>1.15; can 1.1>1; pis 3>5; smg 3>5; mg 4>5; rif 2>3; mel 3>4 | crew-remap-20261118, held-remap-20261118 |
| flamer | 2026-11-18 | tank 0.8>0.75; can 1>0.8 | held-remap-20261118 |
| flamer2 | 2026-11-18 | tank 0.8>0.75; can 1>0.8 | soldier-remap-20261118 |
| mgun_40 | 2026-11-18 | tank 0.8>0.75; can 1>0.8 | soldier-remap-20261118 |
| mgun_scot | 2026-11-18 | hp 150%>200%; sta 100%>150%; tank 0.8>0.85; can 1>0.9; pis 3>4; rl 2>1; mel 5>4 | soldier-remap-20261118 |
| mgun2 | 2026-11-18 | tank 0.8>0.75; can 1>0.8 | soldier-remap-20261118 |
| oficer | 2026-11-18 | hp 250%>200%; spd 1>0.9; tank 1>0.85; can 1>0.9; mg 4>5; rif 4>5; rl 3>1; mel 4>5 | soldier-remap-20261118 |
| para | 2026-11-18 | hp 400%>350%; tank 1>0.95; pis 6>5; mg 6>5; rif 6>5; rl 6>1; mel 6>5 | soldier-remap-20261118 |
| para_2ic | 2026-11-18 | tank 1>0.95; pis 7>6; mg 7>6; rif 7>6; rl 7>1; mel 7>6 | soldier-remap-20261118 |
| para_cpl | 2026-11-18 | tank 1>0.95; pis 7>6; mg 7>6; rif 7>6; rl 7>1; mel 7>6 | soldier-remap-20261118 |
| para_mortar | 2026-11-18 | hp 400%>350%; tank 1>0.95; pis 6>5; mg 6>5; rif 6>5; mel 6>5 | soldier-remap-20261118 |
| para2 | 2026-11-18 | hp 400%>350%; tank 1>0.95; pis 6>5; smg 6>5; rif 6>5; rl 6>1; mel 6>5 | soldier-remap-20261118 |
| para4 | 2026-11-18 | hp 400%>350%; tank 1>0.95; pis 6>5; smg 6>5; mg 6>5; rl 6>1; mel 6>5 | soldier-remap-20261118 |
| rifle_40 | 2026-11-18 | tank 0.8>0.75; can 1>0.8 | soldier-remap-20261118 |
| rifle_scot | 2026-11-18 | hp 150%>200%; sta 100%>150%; tank 0.8>0.85; can 1>0.9; pis 3>4; rl 2>1; mel 5>4 | soldier-remap-20261118 |
| rifle2_40 | 2026-11-18 | tank 0.8>0.75; can 1>0.8 | soldier-remap-20261118 |
| rifle3 | 2026-11-18 | tank 0.8>0.75; can 1>0.8 | soldier-remap-20261118 |
| saper | 2026-11-18 | tank 0.8>0.75; can 1>0.8 | soldier-remap-20261118 |
| saper2 | 2026-11-18 | tank 0.8>0.75; can 1>0.8 | soldier-remap-20261118 |
| saper3 | 2026-11-18 | tank 0.8>0.75; can 1>0.8 | soldier-remap-20261118 |
| smg_40 | 2026-11-18 | tank 0.8>0.75; can 1>0.8 | soldier-remap-20261118 |
| smg2_40 | 2026-11-18 | tank 0.8>0.75; can 1>0.8 | soldier-remap-20261118 |
| sniper | 2026-11-18 | sta 150%>200%; spd 1>0.9; tank 1>0.95; pis 3>5; smg 3>5; mg 3>5; rl 2>1; mel 4>5; vet 24/60/108/168/240>60/132/216/312/420 | held-remap-20261118 |
| squadleader_40 | 2026-11-18 | hp 200%>150%; tank 0.8>0.75; can 1>0.8; pis 3>4; smg 4>3; rif 3>4; rl 2>1 | soldier-remap-20261118 |
| squadleader_can | 2026-11-18 | hp 200%>150%; tank 0.8>0.75; can 1>0.8; pis 3>4; smg 4>3; rif 3>4; rl 2>1 | soldier-remap-20261118 |
| squadleader_scot | 2026-11-18 | hp 200%>350%; sta 100%>200%; tank 0.8>0.95; mg 4>5; rif 5>6; rl 4>1; vet 24/60/108/168/240>60/132/216/312/420 | soldier-remap-20261118 |
| squadleader2_40 | 2026-11-18 | hp 200%>150%; tank 0.8>0.75; can 1>0.8; pis 3>4; mg 3>2; rl 2>1 | soldier-remap-20261118 |
| sturmovik | 2026-11-18 | tank 1>0.95; pis 7>6; mg 7>6; rif 7>6; rl 7>1; mel 7>6; inv: -grenade n77_smoke 0.5 1, +grenade n77_smoke 0.5 0.5 | soldier-remap-20261118 |
| sturmovik_cpl | 2026-11-18 | tank 1>0.95; pis 7>6; mg 7>6; rif 7>6; rl 7>1; mel 7>6 | soldier-remap-20261118 |
| sturmovik2 | 2026-11-18 | tank 1>0.95; pis 7>6; smg 7>6; rif 7>6; rl 7>1; mel 7>6; inv: -grenade n77_smoke 0.5 1, +grenade n77_smoke 0.5 0.5 | soldier-remap-20261118 |
| sturmovik3 | 2026-11-18 | tank 1>0.95; pis 7>6; mg 7>6; rif 7>6; mel 7>6; inv: -grenade n77_smoke 0.5 1, +grenade n77_smoke 0.5 0.5 | soldier-remap-20261118 |
| sturmovik4 | 2026-11-18 | tank 1>0.95; pis 7>6; mg 7>6; rif 7>6; rl 7>1; mel 7>6; inv: -grenade n77_smoke 0.5 1, +grenade n77_smoke 0.5 0.5 | soldier-remap-20261118 |
| sturmovik6 | 2026-11-18 | tank 1>0.95; pis 7>6; smg 7>6; rif 7>6; rl 7>1; mel 7>6; inv: -grenade n77_smoke 0.5 1, +grenade n77_smoke 0.5 0.5 | soldier-remap-20261118 |
| sturmovik6b | 2026-11-18 | tank 1>0.95; pis 7>6; smg 7>6; mg 7>6; rl 7>1; mel 7>6; inv: -grenade n77_smoke 0.5 1, +grenade n77_smoke 0.5 0.5 | soldier-remap-20261118 |
| tankman | 2026-11-18 | hp 100%>150%; can 0.8>0.9; pis 3>4; smg 3>4; rif 2>3; mel 3>4 | crew-remap-20261118, held-remap-20261118 |
| tankman2 | 2026-11-18 | tank 1>1.1; can 0.8>0.95; pis 3>4; smg 3>4; mg 3>4; rif 2>3; mel 3>4 | crew-remap-20261118, held-remap-20261118 |
| vehicle_supporter | 2026-11-18 | tank 1>0.85; pis 3>2 | crew-remap-20261118, held-remap-20261118 |
| vehicle_supporter_40 | 2026-11-18 | tank 1>0.85; pis 3>2; mg 3>4; mel 3>4; tg 3>4 | crew-remap-20261118, held-remap-20261118 |
| vehicle_supporter_single | 2026-11-18 | tank 1>0.85; pis 3>2 | crew-remap-20261118, held-remap-20261118 |
| vet_tankman | 2026-11-18 | hp 150%>200%; sta 100%>150%; tank 1>1.1; can 0.8>0.95; pis 3>4; smg 3>4; mg 3>4; rif 2>3; mel 3>4 | crew-remap-20261118, held-remap-20261118 |
| vet_tankman2 | 2026-11-18 | hp 150%>200%; sta 100%>150%; tank 1.2>1.15; veh 1.2>1.15; can 1.1>1; pis 3>5; smg 3>5; mg 4>5; rif 2>3; mel 3>4 | crew-remap-20261118, held-remap-20261118 |

#### Breeds: ger (226 rows)

| Breed | Date | Changes (old>new) | Undo tag |
|---|---|---|---|
| ap_miner | 2026-11-18 | rl 2>1 | soldier-remap-20261118 |
| at_miner | 2026-11-18 | rl 2>1 | soldier-remap-20261118 |
| at_rifle | 2026-11-18 | hp 150%>200%; sta 100%>150%; tank 0.75>0.85; can 0.8>0.9; smg 4>3; mg 1>3; rl 2>1 | held-remap-20261118 |
| at_rifle2 | 2026-11-18 | hp 150%>200%; sta 100%>150%; tank 0.75>0.85; can 0.8>0.9; smg 4>5; mg 2>3; rif 5>3; rl 2>1 | soldier-remap-20261118 |
| bazooker | 2026-11-18 | hp 150%>200%; sta 100%>150%; tank 0.75>0.85; can 0.8>0.9; mg 2>3; rif 4>5 | soldier-remap-20261118 |
| bazooker2 | 2026-11-18 | hp 150%>200%; sta 100%>150%; tank 0.75>0.85; can 0.8>0.9; mg 2>3; rif 4>5; rl 5>1 | soldier-remap-20261118 |
| elite_tankman | 2026-11-18 | hp 100%>400%; sta 100%>200%; rl 2>1; tg 8>7 | crew-remap-20261118, held-remap-20261118 |
| elite_tankman2 | 2026-11-18 | hp 150%>400%; sta 100%>200%; can 1>1.1; pis 4>5; mg 7>6; rl 2>1 | crew-remap-20261118, held-remap-20261118 |
| elite_vehicle_supporter | 2026-11-18 | hp 100%>400%; sta 100%>200%; spd 0.8>0.9; tank 1.15>1; veh 1.15>1; pis 5>3; smg 5>3; rif 5>3; rl 2>1 | crew-remap-20261118, held-remap-20261118 |
| fallschirm_fg_42 | 2026-11-18 | pis 7>6; smg 7>6; mg 7>6; rl 7>1; mel 7>6 | soldier-remap-20261118 |
| fallschirm_fg_43 | 2026-11-18 | pis 7>6; smg 7>6; mg 7>6; rl 7>1; mel 7>6 | soldier-remap-20261118 |
| fallschirm_grenadier | 2026-11-18 | pis 7>6; smg 7>6; mg 7>6; rl 7>1; mel 7>6 | soldier-remap-20261118 |
| fallschirm_mg | 2026-11-18 | pis 7>6; smg 7>6; rif 7>6; rl 7>1; mel 7>6 | soldier-remap-20261118 |
| fallschirm_mg_39 | 2026-11-18 | pis 7>6; smg 7>6; rif 7>6; rl 7>1; mel 7>6 | soldier-remap-20261118 |
| fallschirm_mg_asst | 2026-11-18 | pis 7>6; smg 7>6; rif 7>6; rl 7>1; mel 7>6 | soldier-remap-20261118 |
| fallschirm_mg_asst_39 | 2026-11-18 | pis 7>6; smg 7>6; rif 7>6; rl 7>1; mel 7>6 | soldier-remap-20261118 |
| fallschirm_rifle | 2026-11-18 | pis 7>6; smg 7>6; mg 7>6; rl 7>1; mel 7>6 | soldier-remap-20261118 |
| fallschirm_rifle_39 | 2026-11-18 | pis 7>6; smg 7>6; mg 7>6; rl 7>1; mel 7>6 | soldier-remap-20261118 |
| fallschirm_sa | 2026-11-18 | pis 7>6; smg 7>6; mg 7>6; rl 7>1; mel 7>6 | soldier-remap-20261118 |
| fallschirm_sa_41 | 2026-11-18 | pis 7>6; smg 7>6; mg 7>6; rl 7>1; mel 7>6 | soldier-remap-20261118 |
| fallschirm_sl_40 | 2026-11-18 | pis 7>6; mg 7>6; rif 7>6; rl 7>1; mel 7>6 | soldier-remap-20261118 |
| fallschirm_sl_asst_fg_42 | 2026-11-18 | pis 7>6; mg 7>6; rif 7>6; rl 7>1; mel 7>6 | soldier-remap-20261118 |
| fallschirm_sl_asst_fg_43 | 2026-11-18 | pis 7>6; mg 7>6; rif 7>6; rl 7>1; mel 7>6 | soldier-remap-20261118 |
| fallschirm_sl_asst_smg | 2026-11-18 | pis 7>6; mg 7>6; rif 7>6; rl 7>1; mel 7>6 | soldier-remap-20261118 |
| fallschirm_sniper | 2026-11-18 | pis 7>6; smg 7>6; mg 7>6; rl 7>1; mel 7>6 | held-remap-20261118 |
| flamer | 2026-11-18 | rl 2>1 | held-remap-20261118 |
| flamer2 | 2026-11-18 | rl 2>1 | soldier-remap-20261118 |
| fusilier_mg | 2026-11-18 | tank 0.75>0.85; can 0.8>0.9; pis 5>4; rif 4>3; rl 2>1; mel 5>4 | soldier-remap-20261118 |
| fusilier_mg_39 | 2026-11-18 | tank 0.75>0.85; can 0.8>0.9; pis 5>4; rif 4>3; rl 2>1; mel 5>4 | soldier-remap-20261118 |
| fusilier_mg_asst | 2026-11-18 | tank 0.75>0.85; can 0.8>0.9; rif 5>3; rl 2>1; mel 5>4 | soldier-remap-20261118 |
| fusilier_rifle | 2026-11-18 | tank 0.75>0.85; can 0.8>0.9; mg 2>3; rl 3>1; mel 5>4 | soldier-remap-20261118 |
| fusilier_sa | 2026-11-18 | tank 0.75>0.85; can 0.8>0.9; mg 2>3; rl 3>1; mel 5>4 | soldier-remap-20261118 |
| fusilier_sa_41 | 2026-11-18 | tank 0.75>0.85; can 0.8>0.9; mg 2>3; rl 3>1; mel 5>4 | soldier-remap-20261118 |
| fusilier_sl | 2026-11-18 | hp 200%>350%; sta 100%>200%; tank 0.85>0.95; can 0.9>1; smg 5>6; mg 4>5; rl 4>1; vet 24/60/108/168/240>60/132/216/312/420 | soldier-remap-20261118 |
| fusilier_sl_asst | 2026-11-18 | hp 200%>350%; sta 150%>200%; tank 0.75>0.95; can 0.8>1; smg 4>6; mg 4>5; rl 4>1; vet 24/60/108/168/240>60/132/216/312/420 | soldier-remap-20261118 |
| fusilier_smg | 2026-11-18 | tank 0.75>0.85; can 0.8>0.9; mg 2>3; rl 3>1; mel 5>4 | soldier-remap-20261118 |
| gd_pzgren_mg | 2026-11-18 | rif 5>3; rl 4>1; mel 5>4 | soldier-remap-20261118 |
| gd_pzgren_mg_asst | 2026-11-18 | rif 5>3; rl 4>1; mel 5>4 | soldier-remap-20261118 |
| gd_pzgren_rifle | 2026-11-18 | rl 4>1; mel 5>4 | soldier-remap-20261118 |
| gd_pzgren_sa | 2026-11-18 | rl 4>1; mel 5>4 | soldier-remap-20261118 |
| gd_pzgren_sa_scope | 2026-11-18 | rl 4>1; mel 5>4 | soldier-remap-20261118 |
| gd_pzgren_sl_asst | 2026-11-18 | hp 200%>350%; sta 150%>200%; tank 0.85>0.95; can 0.9>1; pis 4>5; smg 3>6; mg 3>5; rl 4>1 | soldier-remap-20261118 |
| gd_pzgren_sl_smg | 2026-11-18 | hp 200%>350%; sta 150%>200%; tank 0.85>0.95; can 0.9>1; pis 4>5; smg 5>6; mg 3>5; rif 3>5; rl 4>1 | soldier-remap-20261118 |
| gebirgsjager_mg | 2026-11-19 | sreg 125%>100% | pass8-remap-20261118 |
| gebirgsjager_mg | 2026-11-18 | sta 225%>200%; spd 1>0.9; pis 7>6; smg 7>6; rif 7>6; rl 7>1; mel 7>6 | soldier-remap-20261118 |
| gebirgsjager_mg_41 | 2026-11-19 | sreg 125%>100% | pass8-remap-20261118 |
| gebirgsjager_mg_41 | 2026-11-18 | sta 225%>200%; spd 1>0.9; pis 7>6; smg 7>6; rif 7>6; rl 7>1; mel 7>6 | soldier-remap-20261118 |
| gebirgsjager_mg_asst | 2026-11-19 | sreg 125%>100% | pass8-remap-20261118 |
| gebirgsjager_mg_asst | 2026-11-18 | sta 225%>200%; spd 1>0.9; pis 7>6; smg 7>6; rif 7>6; rl 7>1; mel 7>6 | soldier-remap-20261118 |
| gebirgsjager_rifle | 2026-11-19 | sreg 125%>100% | pass8-remap-20261118 |
| gebirgsjager_rifle | 2026-11-18 | sta 225%>200%; spd 1>0.9; pis 7>6; smg 7>6; mg 7>6; rl 7>1; mel 7>6 | soldier-remap-20261118 |
| gebirgsjager_sa | 2026-11-19 | sreg 125%>100% | pass8-remap-20261118 |
| gebirgsjager_sa | 2026-11-18 | sta 225%>200%; spd 1>0.9; pis 7>6; smg 7>6; mg 7>6; rl 7>1; mel 7>6 | soldier-remap-20261118 |
| gebirgsjager_sa_41 | 2026-11-19 | sreg 125%>100% | pass8-remap-20261118 |
| gebirgsjager_sa_41 | 2026-11-18 | sta 225%>200%; spd 1>0.9; pis 7>6; smg 7>6; mg 7>6; rl 7>1; mel 7>6 | soldier-remap-20261118 |
| gebirgsjager_sl_asst_smg | 2026-11-19 | sreg 125%>100% | pass8-remap-20261118 |
| gebirgsjager_sl_asst_smg | 2026-11-18 | sta 225%>200%; spd 1>0.9; pis 7>6; mg 7>6; rif 7>6; rl 7>1; mel 7>6 | soldier-remap-20261118 |
| gebirgsjager_sl_smg | 2026-11-19 | sreg 125%>100% | pass8-remap-20261118 |
| gebirgsjager_sl_smg | 2026-11-18 | sta 225%>200%; spd 1>0.9; pis 7>6; mg 7>6; rif 7>6; rl 7>1; mel 7>6 | soldier-remap-20261118 |
| gebirgsjager_smg | 2026-11-19 | sreg 125%>100% | pass8-remap-20261118 |
| gebirgsjager_smg | 2026-11-18 | sta 225%>200%; spd 1>0.9; pis 7>6; mg 7>6; rif 7>6; rl 7>1; mel 7>6 | soldier-remap-20261118 |
| ger_ap_miner | 2026-11-18 | rl 2>3 | soldier-remap-20261118 |
| ger_at_miner | 2026-11-18 | rl 2>3 | soldier-remap-20261118 |
| ger_at_rifle | 2026-11-18 | hp 150%>200%; sta 100%>150%; tank 0.75>0.85; can 0.8>0.9; smg 4>3; mg 1>3; rl 2>4 | held-remap-20261118 |
| ger_at_rifleassist | 2026-11-18 | hp 150%>200%; sta 100%>150%; tank 0.75>0.85; can 0.8>0.9; smg 4>3; mg 2>3; rl 2>1 | soldier-remap-20261118 |
| ger_elite_tankman | 2026-11-18 | hp 100%>400%; sta 100%>200%; rl 2>1; tg 8>7 | crew-remap-20261118, held-remap-20261118 |
| ger_elite_tankman2 | 2026-11-18 | hp 150%>400%; sta 100%>200%; can 1>1.1; pis 4>5; mg 7>6; rl 2>1 | crew-remap-20261118, held-remap-20261118 |
| ger_fallschirm_fg_43 | 2026-11-18 | pis 7>6; smg 7>6; mg 7>6; rl 7>6; mel 7>6 | soldier-remap-20261118 |
| ger_fallschirm_grenadier | 2026-11-18 | pis 7>6; smg 7>6; mg 7>6; rl 7>6; mel 7>6 | soldier-remap-20261118 |
| ger_fallschirm_mg | 2026-11-18 | pis 7>6; smg 7>6; rif 7>6; rl 7>6; mel 7>6 | soldier-remap-20261118 |
| ger_fallschirm_mg_39 | 2026-11-18 | pis 7>6; smg 7>6; rif 7>6; rl 7>6; mel 7>6 | soldier-remap-20261118 |
| ger_fallschirm_mg_asst | 2026-11-18 | pis 7>6; smg 7>6; rif 7>6; rl 7>1; mel 7>6 | soldier-remap-20261118 |
| ger_fallschirm_mg_asst_39 | 2026-11-18 | pis 7>6; smg 7>6; rif 7>6; rl 7>1; mel 7>6 | soldier-remap-20261118 |
| ger_fallschirm_pzfst_stg | 2026-11-18 | pis 7>6; mg 7>6; rif 7>6; mel 7>6 | soldier-remap-20261118 |
| ger_fallschirm_rifle | 2026-11-18 | pis 7>6; smg 7>6; mg 7>6; rl 7>6; mel 7>6 | soldier-remap-20261118 |
| ger_fallschirm_sl | 2026-11-18 | pis 7>6; mg 7>6; rif 7>6; rl 7>6; mel 7>6 | soldier-remap-20261118 |
| ger_fallschirm_sl_asst_fg_44 | 2026-11-18 | pis 7>6; mg 7>6; rif 7>6; mel 7>6 | soldier-remap-20261118 |
| ger_fallschirm_sniper | 2026-11-18 | pis 7>6; smg 7>6; mg 7>6; rl 7>6; mel 7>6 | held-remap-20261118 |
| ger_flamer | 2026-11-18 | rl 2>1 | held-remap-20261118 |
| ger_flamerassist | 2026-11-18 | rl 2>1 | soldier-remap-20261118 |
| ger_fusilier_mg | 2026-11-18 | tank 0.75>0.85; can 0.8>0.9; pis 5>4; rif 4>3; rl 2>4; mel 5>4 | soldier-remap-20261118 |
| ger_fusilier_mg_asst | 2026-11-18 | tank 0.75>0.85; can 0.8>0.9; rif 5>3; rl 2>1; mel 5>4 | soldier-remap-20261118 |
| ger_fusilier_pzfst | 2026-11-18 | tank 0.75>0.85; can 0.8>0.9; mg 2>3; mel 5>4 | soldier-remap-20261118 |
| ger_fusilier_pzfst_sa | 2026-11-18 | tank 0.75>0.85; can 0.8>0.9; mg 2>3; rl 3>5; mel 5>4 | soldier-remap-20261118 |
| ger_fusilier_sa | 2026-11-18 | tank 0.75>0.85; can 0.8>0.9; mg 2>3; rl 3>4; mel 5>4 | soldier-remap-20261118 |
| ger_fusilier_sl | 2026-11-18 | hp 200%>350%; sta 100%>200%; tank 0.85>0.95; can 0.9>1; smg 5>6; mg 4>5; rl 4>5; vet 24/60/108/168/240>60/132/216/312/420 | soldier-remap-20261118 |
| ger_fusilier_sl_asst | 2026-11-18 | hp 200%>350%; sta 150%>200%; tank 0.75>0.95; can 0.8>1; smg 4>6; mg 4>5; rl 4>1; vet 24/60/108/168/240>60/132/216/312/420 | soldier-remap-20261118 |
| ger_fusilier_stg | 2026-11-18 | tank 0.75>0.85; can 0.8>0.9; mg 2>3; rl 3>4; mel 5>4 | soldier-remap-20261118 |
| ger_gd_pzgren_mg | 2026-11-18 | rif 5>3; mel 5>4 | soldier-remap-20261118 |
| ger_gd_pzgren_mg_asst | 2026-11-18 | rif 5>3; rl 4>1; mel 5>4 | soldier-remap-20261118 |
| ger_gd_pzgren_pzfst_sa | 2026-11-18 | mel 5>4 | soldier-remap-20261118 |
| ger_gd_pzgren_pzfst_stg | 2026-11-18 | mel 5>4 | soldier-remap-20261118 |
| ger_gd_pzgren_sa_scope | 2026-11-18 | mel 5>4 | soldier-remap-20261118 |
| ger_gd_pzgren_sl_asst_stg | 2026-11-18 | hp 200%>350%; sta 150%>200%; tank 0.85>0.95; can 0.9>1; pis 4>5; smg 5>6; mg 3>5; rif 3>5; rl 5>6 | soldier-remap-20261118 |
| ger_gd_pzgren_sl_stg | 2026-11-18 | hp 200%>350%; sta 150%>200%; tank 0.85>0.95; can 0.9>1; pis 4>5; smg 5>6; mg 3>5; rif 3>5; rl 4>5 | soldier-remap-20261118 |
| ger_gebirgsjager_mg | 2026-11-19 | sreg 125%>100% | pass8-remap-20261118 |
| ger_gebirgsjager_mg | 2026-11-18 | sta 225%>200%; spd 1>0.9; pis 7>6; smg 7>6; rif 7>6; rl 7>6; mel 7>6 | soldier-remap-20261118 |
| ger_gebirgsjager_mg_asst | 2026-11-19 | sreg 125%>100% | pass8-remap-20261118 |
| ger_gebirgsjager_mg_asst | 2026-11-18 | sta 225%>200%; spd 1>0.9; pis 7>6; smg 7>6; rif 7>6; rl 7>1; mel 7>6 | soldier-remap-20261118 |
| ger_gebirgsjager_pzfst_sa | 2026-11-19 | sreg 125%>100% | pass8-remap-20261118 |
| ger_gebirgsjager_pzfst_sa | 2026-11-18 | sta 225%>200%; spd 1>0.9; pis 7>6; smg 7>6; mg 7>6; mel 7>6 | soldier-remap-20261118 |
| ger_gebirgsjager_sl_asst_stg | 2026-11-19 | sreg 125%>100% | pass8-remap-20261118 |
| ger_gebirgsjager_sl_asst_stg | 2026-11-18 | sta 225%>200%; spd 1>0.9; pis 7>6; mg 7>6; rif 7>6; rl 7>1; mel 7>6 | soldier-remap-20261118 |
| ger_gebirgsjager_sl_stg | 2026-11-19 | sreg 125%>100% | pass8-remap-20261118 |
| ger_gebirgsjager_sl_stg | 2026-11-18 | sta 225%>200%; spd 1>0.9; pis 7>6; mg 7>6; rif 7>6; rl 7>6; mel 7>6 | soldier-remap-20261118 |
| ger_gebirgsjager_smg | 2026-11-19 | sreg 125%>100% | pass8-remap-20261118 |
| ger_gebirgsjager_smg | 2026-11-18 | sta 225%>200%; spd 1>0.9; pis 7>6; mg 7>6; rif 7>6; rl 7>6; mel 7>6 | soldier-remap-20261118 |
| ger_gebirgsjager_stg | 2026-11-19 | sreg 125%>100% | pass8-remap-20261118 |
| ger_gebirgsjager_stg | 2026-11-18 | sta 225%>200%; spd 1>0.9; pis 7>6; mg 7>6; rif 7>6; rl 7>6; mel 7>6 | soldier-remap-20261118 |
| ger_grenadier_mg | 2026-11-18 | rl 2>3 | soldier-remap-20261118 |
| ger_grenadier_mg_39 | 2026-11-18 | rl 2>3 | soldier-remap-20261118 |
| ger_grenadier_mg_asst | 2026-11-18 | rif 4>3; rl 2>1 | soldier-remap-20261118 |
| ger_grenadier_ober_44 | 2026-11-18 | sta 100%>150%; tank 0.75>0.85; can 0.8>0.9; pis 5>4; smg 4>3; mg 4>3; rl 3>5; mel 5>4 | soldier-remap-20261118 |
| ger_grenadier_rifle_44 | 2026-11-18 | rl 2>4 | soldier-remap-20261118 |
| ger_grenadier_rifle_grenadier | 2026-11-18 | rl 2>3 | soldier-remap-20261118 |
| ger_grenadier_sa_44 | 2026-11-18 | rl 2>4 | soldier-remap-20261118 |
| ger_grenadier_smg | 2026-11-18 | rl 2>3 | soldier-remap-20261118 |
| ger_grenadier_stg | 2026-11-18 | rl 2>4 | soldier-remap-20261118 |
| ger_jager_mg | 2026-11-18 | tank 0.75>0.85; can 0.8>0.9; pis 5>4; rif 4>3; rl 2>4; mel 5>4 | soldier-remap-20261118 |
| ger_jager_mg_asst | 2026-11-18 | tank 0.75>0.85; can 0.8>0.9; rif 5>3; rl 2>1; mel 5>4 | soldier-remap-20261118 |
| ger_jager_pzfst | 2026-11-18 | tank 0.75>0.85; can 0.8>0.9; mg 2>3; mel 5>4 | soldier-remap-20261118 |
| ger_jager_sa | 2026-11-18 | tank 0.75>0.85; can 0.8>0.9; mg 2>3; rl 3>4; mel 5>4 | soldier-remap-20261118 |
| ger_jager_sl_stg | 2026-11-18 | hp 200%>350%; sta 100%>200%; tank 0.85>0.95; can 0.9>1; smg 5>6; mg 4>5; rl 4>5; vet 24/60/108/168/240>60/132/216/312/420 | soldier-remap-20261118 |
| ger_jager_sl_stg_asst | 2026-11-18 | hp 200%>350%; sta 100%>200%; tank 0.85>0.95; can 0.9>1; smg 5>6; mg 4>5; rl 4>1; vet 24/60/108/168/240>60/132/216/312/420 | soldier-remap-20261118 |
| ger_jager_smg | 2026-11-18 | tank 0.75>0.85; can 0.8>0.9; mg 2>3; rl 3>4; mel 5>4 | soldier-remap-20261118 |
| ger_jager_stg | 2026-11-18 | tank 0.75>0.85; can 0.8>0.9; mg 2>3; rl 3>4; mel 5>4 | soldier-remap-20261118 |
| ger_light_mortar | 2026-11-18 | pis 4>1; smg 3>1; mg 2>1; rif 5>2; mel 4>2 | soldier-remap-20261118 |
| ger_light_mortar_assist | 2026-11-18 | hp 150%>200%; sta 100%>150%; tank 0.75>0.85; can 0.8>0.9; mg 2>3; rl 2>1 | soldier-remap-20261118 |
| ger_officer | 2026-11-18 | hp 250%>200%; sta 100%>150%; spd 1>0.9; rl 5>4 | soldier-remap-20261118 |
| ger_panzerfaust | 2026-11-18 | rl 5>4 | soldier-remap-20261118 |
| ger_panzerschreck | 2026-11-18 | hp 150%>200%; sta 100%>150%; tank 0.75>0.85; can 0.8>0.9; mg 2>3; rif 4>5 | soldier-remap-20261118 |
| ger_panzerschreckassist | 2026-11-18 | hp 150%>200%; sta 100%>150%; tank 0.75>0.85; can 0.8>0.9; mg 2>3; rif 4>5; rl 5>1 | soldier-remap-20261118 |
| ger_pzgren_g43 | 2026-11-18 | pis 5>4; smg 4>3; mg 4>3; mel 5>4 | soldier-remap-20261118 |
| ger_pzgren_g43_2 | 2026-11-18 | pis 5>4; smg 4>3; mg 4>3; rl 4>1; mel 5>4 | soldier-remap-20261118 |
| ger_pzgren_mg34 | 2026-11-18 | pis 5>4; smg 4>3; rif 4>3; mel 5>4 | soldier-remap-20261118 |
| ger_pzgren_mg34assist | 2026-11-18 | pis 5>4; smg 4>3; rif 4>3; rl 4>1; mel 5>4 | soldier-remap-20261118 |
| ger_pzgren_mg42 | 2026-11-18 | pis 5>4; smg 4>3; rif 4>3; mel 5>4 | soldier-remap-20261118 |
| ger_pzgren_mg42assist | 2026-11-18 | pis 5>4; smg 4>3; rif 5>3; rl 4>1; mel 5>4 | soldier-remap-20261118 |
| ger_pzgren_mp40 | 2026-11-18 | hp 200%>350%; sta 150%>200%; tank 0.85>0.95; can 0.9>1; smg 5>6; mg 4>5; rif 4>5; rl 6>5; vet 24/60/108/168/240>60/132/216/312/420 | soldier-remap-20261118 |
| ger_pzgren_panzerfaust | 2026-11-18 | hp 200%>150%; sta 150%>100%; tank 0.85>0.75; can 0.9>0.8; pis 5>4; smg 5>3; mg 4>2; rl 5>4; mel 5>4 | soldier-remap-20261118 |
| ger_pzgren_panzershreck | 2026-11-18 | hp 200%>350%; sta 150%>200%; tank 0.85>0.95; can 0.9>1; mg 4>5; rif 4>6; vet 24/60/108/168/240>60/132/216/312/420 | soldier-remap-20261118 |
| ger_pzgren_pio_flamer | 2026-11-18 | rl 2>3 | held-remap-20261118 |
| ger_pzgren_pio_mg | 2026-11-18 | rl 2>3 | soldier-remap-20261118 |
| ger_pzgren_pio_mg_asst | 2026-11-18 | rif 4>3; rl 2>1 | soldier-remap-20261118 |
| ger_pzgren_pio_sl | 2026-11-18 | sta 100%>150%; rif 4>3; rl 2>4; mel 5>4 | soldier-remap-20261118 |
| ger_pzgren_pio2 | 2026-11-18 | tank 0.85>0.75; can 0.9>0.8; rl 2>3 | soldier-remap-20261118 |
| ger_pzgren_pio3 | 2026-11-18 | tank 0.85>0.75; can 0.9>0.8; rl 2>3 | soldier-remap-20261118 |
| ger_pzgren_rifle | 2026-11-18 | pis 5>4; smg 4>3; mg 4>3; rl 4>1; mel 5>4 | soldier-remap-20261118 |
| ger_pzgren_sl | 2026-11-18 | hp 200%>350%; sta 150%>200%; tank 0.85>0.95; can 0.9>1; smg 5>6; mg 4>5; rif 4>5; rl 4>5; vet 24/60/108/168/240>60/132/216/312/420 | soldier-remap-20261118 |
| ger_pzgren_smg_panzerfaust | 2026-11-18 | pis 5>4; smg 4>5; mg 4>3; rif 5>3; mel 5>4 | soldier-remap-20261118 |
| ger_pzgren_stg_panzerfaust | 2026-11-18 | pis 5>4; mg 4>3; rif 4>3; mel 5>4 | soldier-remap-20261118 |
| ger_pzgren2ic | 2026-11-18 | pis 5>4; smg 4>3; mg 4>3; mel 5>4 | soldier-remap-20261118 |
| ger_radioman_mortar | 2026-11-18 | rl 2>3 | soldier-remap-20261118 |
| ger_saper | 2026-11-18 | tank 0.85>0.75; can 0.9>0.8; rl 2>3 | soldier-remap-20261118 |
| ger_sniper_g43 | 2026-11-18 | sta 150%>200%; spd 1>0.9; tank 0.75>0.95; can 0.8>1; pis 4>5; smg 3>5; mg 2>5; rl 2>5; mel 4>5; vet 24/60/108/168/240>60/132/216/312/420 | soldier-remap-20261118 |
| ger_sniper_mauzer | 2026-11-18 | sta 150%>200%; spd 1>0.9; tank 0.75>0.95; can 0.8>1; pis 4>5; smg 3>5; mg 2>5; rl 2>5; mel 4>5; vet 24/60/108/168/240>60/132/216/312/420 | held-remap-20261118 |
| ger_sniper_vet | 2026-11-18 | hp 350%>400%; spd 1>0.9; tank 0.85>0.95; can 0.9>1; pis 7>6; smg 7>6; mg 7>6; rl 7>1; mel 7>6; vet 24/60/108/168/240>60/132/216/312/420 | held-remap-20261118 |
| ger_squadleader_mp40 | 2026-11-18 | sta 100%>150%; pis 5>4; rif 4>3; rl 2>4; mel 5>4 | soldier-remap-20261118 |
| ger_squadleader_sg44 | 2026-11-18 | sta 100%>150%; pis 5>4; rif 4>3; rl 2>4; mel 5>4 | soldier-remap-20261118 |
| ger_sturmgren_sg44 | 2026-11-18 | rl 2>4 | soldier-remap-20261118 |
| ger_sturmgren_sl_asst | 2026-11-18 | hp 150%>200%; sta 100%>150%; tank 0.75>0.85; can 0.8>0.9; mg 2>3; rl 2>5 | soldier-remap-20261118 |
| ger_support | 2026-11-18 | rl 2>1 | crew-remap-20261118, held-remap-20261118 |
| ger_tankman_single | 2026-11-18 | hp 100%>150%; tank 1.1>1; veh 1.1>1; can 1.05>0.9; pis 5>4; mg 3>2; mel 5>4 | crew-remap-20261118, held-remap-20261118 |
| ger_tankman2_single | 2026-11-18 | tank 1.15>1.1; veh 1.15>1; can 1.1>0.95; pis 5>4; smg 5>4; mg 5>4; mel 5>4 | crew-remap-20261118, held-remap-20261118 |
| ger_vehicle_supporter | 2026-11-18 | rl 2>1 | crew-remap-20261118, held-remap-20261118 |
| ger_vehicle_supporter_single | 2026-11-18 | veh 1.05>1; can 1.05>1; pis 3>2; smg 3>2; mg 5>4; rif 3>2; rl 2>1 | crew-remap-20261118, held-remap-20261118 |
| ger_vet_tankman2_single | 2026-11-18 | hp 150%>200%; sta 100%>150%; can 1.1>1; mg 6>5; mel 5>4 | crew-remap-20261118, held-remap-20261118 |
| ger_volksgren_grenadier | 2026-11-18 | hp 100%>150%; sta 75%>100%; rl 2>1 | soldier-remap-20261118 |
| ger_volksgren_mg | 2026-11-18 | hp 100%>150%; sta 75%>100%; rl 2>1 | soldier-remap-20261118 |
| ger_volksgren_mg_asst | 2026-11-18 | hp 100%>150%; sta 75%>100%; pis 1>2; rif 2>1 | soldier-remap-20261118 |
| ger_volksgren_mg_asst2 | 2026-11-18 | hp 100%>150%; sta 75%>100%; pis 1>2; smg 2>1 | soldier-remap-20261118 |
| ger_volksgren_mg_asst3 | 2026-11-18 | hp 100%>150%; sta 75%>100%; pis 1>2; rif 2>1 | soldier-remap-20261118 |
| ger_volksgren_pzfst | 2026-11-18 | hp 100%>150%; sta 75%>100% | soldier-remap-20261118 |
| ger_volksgren_pzfst2 | 2026-11-18 | hp 100%>150%; sta 75%>100%; pis 1>2 | soldier-remap-20261118 |
| ger_volksgren_rifle | 2026-11-18 | hp 100%>150%; sta 75%>100% | soldier-remap-20261118 |
| ger_volksgren_sa | 2026-11-18 | hp 100%>150%; sta 75%>100%; rl 1>2 | soldier-remap-20261118 |
| ger_volksgren_sl_asst | 2026-11-18 | hp 100%>150%; sta 75%>100%; pis 1>2; mg 1>2; rl 1>3 | soldier-remap-20261118 |
| ger_volksgren_sl_smg | 2026-11-18 | hp 100%>150%; sta 75%>100%; pis 1>2; mg 1>2; rl 1>2 | soldier-remap-20261118 |
| ger_volksgren_sl_stg | 2026-11-18 | hp 100%>150%; sta 75%>100%; pis 1>2; mg 1>2; rl 1>2 | soldier-remap-20261118 |
| ger_volksgren_smg | 2026-11-18 | hp 100%>150%; sta 75%>100%; pis 1>2; rl 1>2 | soldier-remap-20261118 |
| ger_volksgren_stg44 | 2026-11-18 | hp 100%>150%; sta 75%>100%; pis 1>2; rl 1>2 | soldier-remap-20261118 |
| ger_volkssturm_rifle_faustpatrone | 2026-11-18 | spd 0.8>0.9; veh 0.8>1; rl 2>1 | soldier-remap-20261118 |
| ger_volkssturm_rifle_panzerfaust | 2026-11-18 | spd 0.8>0.9; veh 0.8>1; rl 2>1 | soldier-remap-20261118 |
| ger_volkssturm_smg_faustpatrone | 2026-11-18 | spd 0.8>0.9; veh 0.8>1; rl 2>1 | soldier-remap-20261118 |
| ger_volkssturm_smg_panzerfaust | 2026-11-18 | spd 0.8>0.9; veh 0.8>1; rl 2>1 | soldier-remap-20261118 |
| grenadier_mg | 2026-11-18 | rl 2>1 | soldier-remap-20261118 |
| grenadier_mg_39 | 2026-11-18 | rl 2>1 | soldier-remap-20261118 |
| grenadier_mg_asst | 2026-11-18 | rif 4>3; rl 2>1 | soldier-remap-20261118 |
| grenadier_ober | 2026-11-18 | sta 100%>150%; tank 0.75>0.85; can 0.8>0.9; pis 5>4; smg 4>3; mg 4>3; rl 3>1; mel 5>4 | soldier-remap-20261118 |
| grenadier_rifle | 2026-11-18 | rl 2>1 | soldier-remap-20261118 |
| grenadier_rifle_grenadier | 2026-11-18 | rl 2>1 | soldier-remap-20261118 |
| grenadier_sa | 2026-11-18 | rl 2>1 | soldier-remap-20261118 |
| grenadier_sa_41 | 2026-11-18 | rl 2>1 | soldier-remap-20261118 |
| grenadier_smg | 2026-11-18 | rl 2>1 | soldier-remap-20261118 |
| grenadier_stg_42 | 2026-11-18 | rl 2>1 | soldier-remap-20261118 |
| grenadier_stg_43 | 2026-11-18 | rl 2>1 | soldier-remap-20261118 |
| jager_mg | 2026-11-18 | tank 0.75>0.85; can 0.8>0.9; pis 5>4; rif 4>3; rl 2>1; mel 5>4 | soldier-remap-20261118 |
| jager_mg_asst | 2026-11-18 | tank 0.75>0.85; can 0.8>0.9; rif 5>3; rl 2>1; mel 5>4 | soldier-remap-20261118 |
| jager_rifle | 2026-11-18 | tank 0.75>0.85; can 0.8>0.9; mg 2>3; rl 3>1; mel 5>4 | soldier-remap-20261118 |
| jager_sa | 2026-11-18 | tank 0.75>0.85; can 0.8>0.9; mg 2>3; rl 3>1; mel 5>4 | soldier-remap-20261118 |
| jager_sa_41 | 2026-11-18 | tank 0.75>0.85; can 0.8>0.9; mg 2>3; rl 3>1; mel 5>4 | soldier-remap-20261118 |
| jager_sl_smg | 2026-11-18 | hp 200%>350%; sta 100%>200%; tank 0.85>0.95; can 0.9>1; smg 5>6; mg 4>5; rl 4>1; vet 24/60/108/168/240>60/132/216/312/420 | soldier-remap-20261118 |
| jager_sl_smg_asst | 2026-11-18 | hp 200%>350%; sta 100%>200%; tank 0.85>0.95; can 0.9>1; smg 5>6; mg 4>5; rl 4>1; vet 24/60/108/168/240>60/132/216/312/420 | soldier-remap-20261118 |
| jager_smg | 2026-11-18 | tank 0.75>0.85; can 0.8>0.9; mg 2>3; rl 3>1; mel 5>4 | soldier-remap-20261118 |
| oficer | 2026-11-18 | hp 250%>200%; sta 100%>150%; spd 1>0.9; rl 5>1 | soldier-remap-20261118 |
| radioman_mortar | 2026-11-18 | rl 2>1 | soldier-remap-20261118 |
| saper | 2026-11-18 | tank 0.85>0.75; can 0.9>0.8; rl 2>1 | soldier-remap-20261118 |
| sniper | 2026-11-18 | sta 150%>200%; spd 1>0.9; tank 0.75>0.95; can 0.8>1; pis 4>5; smg 3>5; mg 2>5; rl 2>1; mel 4>5; vet 24/60/108/168/240>60/132/216/312/420 | held-remap-20261118 |
| sniper3 | 2026-11-18 | sta 150%>200%; spd 1>0.9; tank 0.75>0.95; can 0.8>1; pis 4>5; smg 3>5; mg 2>5; rl 2>1; mel 4>5; vet 24/60/108/168/240>60/132/216/312/420 | soldier-remap-20261118 |
| squadleader | 2026-11-18 | sta 100%>150%; pis 5>4; rif 4>3; rl 2>1; mel 5>4 | soldier-remap-20261118 |
| sturmovik_sl_40 | 2026-11-18 | hp 200%>350%; sta 150%>200%; tank 0.85>0.95; can 0.9>1; smg 5>6; mg 4>5; rif 4>5; rl 4>1; vet 24/60/108/168/240>60/132/216/312/420 | soldier-remap-20261118 |
| sturmovik_sl_asst | 2026-11-18 | hp 200%>350%; sta 150%>200%; tank 0.85>0.95; can 0.9>1; smg 4>6; mg 4>5; rl 4>1; vet 24/60/108/168/240>60/132/216/312/420 | soldier-remap-20261118 |
| sturmovik2 | 2026-11-18 | pis 5>4; smg 4>3; mg 4>3; rl 4>1; mel 5>4 | soldier-remap-20261118 |
| sturmovik2_41 | 2026-11-18 | pis 5>4; smg 4>3; mg 4>3; rl 4>1; mel 5>4 | soldier-remap-20261118 |
| sturmovik4 | 2026-11-18 | pis 5>4; smg 4>3; mg 4>3; rl 4>1; mel 5>4 | soldier-remap-20261118 |
| sturmovik5 | 2026-11-18 | hp 200%>350%; sta 150%>200%; tank 0.85>0.95; can 0.9>1; mg 4>5; rif 4>6; vet 24/60/108/168/240>60/132/216/312/420 | soldier-remap-20261118 |
| sturmovik5b | 2026-11-18 | hp 200%>350%; sta 150%>200%; tank 0.85>0.95; can 0.9>1; smg 5>6; mg 4>5; rif 4>5; rl 6>1; vet 24/60/108/168/240>60/132/216/312/420 | soldier-remap-20261118 |
| sturmovik6 | 2026-11-18 | pis 5>4; smg 4>3; rif 4>3; rl 4>1; mel 5>4 | soldier-remap-20261118 |
| sturmovik6_39 | 2026-11-18 | pis 5>4; smg 4>3; rif 4>3; rl 4>1; mel 5>4 | soldier-remap-20261118 |
| sturmovik6b | 2026-11-18 | pis 5>4; smg 4>3; mg 5>3; rl 4>1; mel 5>4 | soldier-remap-20261118 |
| tankman | 2026-11-18 | hp 100%>150%; rl 2>1 | crew-remap-20261118, held-remap-20261118 |
| tankman2 | 2026-11-18 | rl 2>1 | crew-remap-20261118, held-remap-20261118 |
| vehicle_supporter | 2026-11-18 | rl 2>1 | crew-remap-20261118, held-remap-20261118 |
| vet_tankman | 2026-11-18 | hp 100%>200%; sta 100%>150%; tank 1.15>1.1; veh 1.15>1; can 1>0.95; pis 5>4; smg 5>4; rl 2>1; tg 5>4 | crew-remap-20261118, held-remap-20261118 |
| vet_tankman2 | 2026-11-18 | hp 150%>200%; sta 100%>150%; tank 1.2>1.15; veh 1.2>1.15; pis 4>5; mg 6>5; rl 2>1 | crew-remap-20261118, held-remap-20261118 |
| vet_vehicle_supporter | 2026-11-18 | hp 150%>200%; sta 100%>150%; mg 6>5; rif 4>3; rl 2>1; tg 6>8 | crew-remap-20261118, held-remap-20261118 |

#### Breeds: ger2 (82 rows)

| Breed | Date | Changes (old>new) | Undo tag |
|---|---|---|---|
| ost_ap_miner | 2026-11-18 | rl 2>3 | soldier-remap-20261118 |
| ost_at_miner | 2026-11-18 | rl 2>3 | soldier-remap-20261118 |
| ost_at_rifle | 2026-11-18 | hp 150%>200%; sta 100%>150%; tank 0.75>0.85; can 0.8>0.9; smg 4>3; mg 1>3; rl 2>4 | held-remap-20261118 |
| ost_at_rifle_ptrd | 2026-11-18 | hp 150%>200%; sta 100%>150%; tank 0.75>0.85; can 0.8>0.9; smg 4>3; mg 1>3; rl 2>4 | held-remap-20261118 |
| ost_at_rifleassist | 2026-11-18 | hp 150%>200%; sta 100%>150%; tank 0.75>0.85; can 0.8>0.9; smg 4>3; mg 2>3; rl 2>1 | soldier-remap-20261118 |
| ost_elite_tankman | 2026-11-18 | hp 100%>400%; sta 100%>200%; rl 2>1; tg 8>7 | crew-remap-20261118, held-remap-20261118 |
| ost_elite_tankman2 | 2026-11-18 | hp 150%>400%; sta 100%>200%; can 1>1.1; pis 4>5; mg 7>6; rl 2>1 | crew-remap-20261118, held-remap-20261118 |
| ost_fallschirm_grenadier | 2026-11-18 | pis 7>6; smg 7>6; mg 7>6; mel 7>6 | soldier-remap-20261118 |
| ost_fallschirm_mg | 2026-11-18 | pis 7>6; smg 7>6; rif 7>6; rl 7>6; mel 7>6 | soldier-remap-20261118 |
| ost_fallschirm_mg_asst | 2026-11-18 | pis 7>6; smg 7>6; rif 7>6; mel 7>6 | soldier-remap-20261118 |
| ost_fallschirm_pzfst_fg | 2026-11-18 | pis 7>6; smg 7>6; mg 7>6; mel 7>6 | soldier-remap-20261118 |
| ost_fallschirm_sl | 2026-11-18 | pis 7>6; mg 7>6; rif 7>6; rl 7>6; mel 7>6 | soldier-remap-20261118 |
| ost_fallschirm_sl_asst_fg_44 | 2026-11-18 | pis 7>6; mg 7>6; rif 7>6; mel 7>6 | soldier-remap-20261118 |
| ost_fallschirm_sniper | 2026-11-18 | pis 7>6; smg 7>6; mg 7>6; rl 7>6; mel 7>6 | held-remap-20261118 |
| ost_flamer | 2026-11-18 | rl 2>3 | held-remap-20261118 |
| ost_flamerassist | 2026-11-18 | rl 2>1 | soldier-remap-20261118 |
| ost_jager_mg | 2026-11-18 | tank 0.75>0.85; can 0.8>0.9; pis 5>4; rif 4>3; rl 2>4; mel 5>4; vet -1/0/84/180/288>-1/0/48/120/192 | soldier-remap-20261118 |
| ost_jager_mg_asst | 2026-11-18 | tank 0.75>0.85; can 0.8>0.9; rif 5>3; rl 2>1; mel 5>4; vet -1/0/84/180/288>-1/0/48/120/192 | soldier-remap-20261118 |
| ost_jager_pzfst | 2026-11-18 | tank 0.75>0.85; can 0.8>0.9; mg 2>3; mel 5>4; vet -1/0/84/180/288>-1/0/48/120/192 | soldier-remap-20261118 |
| ost_jager_sa | 2026-11-18 | tank 0.75>0.85; can 0.8>0.9; mg 2>3; rl 3>5; mel 5>4; vet -1/0/84/180/288>-1/0/48/120/192 | soldier-remap-20261118 |
| ost_jager_sl_stg | 2026-11-18 | hp 200%>350%; sta 150%>200%; tank 0.85>0.95; can 0.9>1; smg 5>6; mg 4>5; rl 4>5 | soldier-remap-20261118 |
| ost_jager_sl_stg_asst | 2026-11-18 | hp 200%>350%; sta 150%>200%; tank 0.85>0.95; can 0.9>1; smg 5>6; mg 4>5; rl 4>6 | soldier-remap-20261118 |
| ost_jager_smg | 2026-11-18 | tank 0.75>0.85; can 0.8>0.9; mg 2>3; rl 3>5; mel 5>4; vet -1/0/84/180/288>-1/0/48/120/192 | soldier-remap-20261118 |
| ost_jager_stg | 2026-11-18 | tank 0.75>0.85; can 0.8>0.9; mg 2>3; rl 3>5; mel 5>4; vet -1/0/84/180/288>-1/0/48/120/192 | soldier-remap-20261118 |
| ost_light_mortar | 2026-11-18 | pis 4>1; smg 3>1; mg 2>1; rif 5>2; mel 4>2 | soldier-remap-20261118 |
| ost_light_mortar_assist | 2026-11-18 | hp 150%>200%; sta 100%>150%; tank 0.75>0.85; can 0.8>0.9; mg 2>3; rl 2>1 | soldier-remap-20261118 |
| ost_mgun | 2026-11-18 | rl 2>3 | soldier-remap-20261118 |
| ost_mgun_asst | 2026-11-18 | rif 4>3; rl 2>1 | soldier-remap-20261118 |
| ost_officer | 2026-11-18 | hp 250%>200%; sta 100%>150%; spd 1>0.9; rl 5>4 | soldier-remap-20261118 |
| ost_officer2 | 2026-11-18 | hp 500%>350%; spd 1>0.9; tank 1>0.95; pis 6>5; mg 6>5; rif 6>5; rl 6>1; mel 6>5; vet 24/60/108/168/240>60/132/216/312/420 | soldier-remap-20261118 |
| ost_panzerfaust | 2026-11-18 | rl 5>4 | soldier-remap-20261118 |
| ost_panzershreck | 2026-11-18 | hp 150%>200%; sta 100%>150%; tank 0.75>0.85; can 0.8>0.9; mg 2>3; rif 4>5 | soldier-remap-20261118 |
| ost_panzershreckassist | 2026-11-18 | hp 150%>200%; sta 100%>150%; tank 0.75>0.85; can 0.8>0.9; mg 2>3; rif 4>5; rl 5>1 | soldier-remap-20261118 |
| ost_pzgren_g43_pzfaust | 2026-11-19 | sreg 125%>100% | pass8-remap-20261118 |
| ost_pzgren_g43_pzfaust | 2026-11-18 | sta 225%>200%; spd 1>0.9; tank 1>0.95; pis 7>6; smg 7>6; mg 7>6; mel 7>6 | soldier-remap-20261118 |
| ost_pzgren_g43scope | 2026-11-19 | sreg 125%>100% | pass8-remap-20261118 |
| ost_pzgren_g43scope | 2026-11-18 | sta 225%>200%; spd 1>0.9; tank 1>0.95; pis 7>6; smg 7>6; mg 7>6; mel 7>6 | soldier-remap-20261118 |
| ost_pzgren_mg34 | 2026-11-19 | sreg 125%>100% | pass8-remap-20261118 |
| ost_pzgren_mg34 | 2026-11-18 | sta 225%>200%; spd 1>0.9; tank 1>0.95; pis 7>6; smg 7>6; rif 7>6; rl 7>6; mel 7>6 | soldier-remap-20261118 |
| ost_pzgren_mgassist | 2026-11-19 | sreg 125%>100% | pass8-remap-20261118 |
| ost_pzgren_mgassist | 2026-11-18 | sta 225%>200%; spd 1>0.9; tank 1>0.95; pis 7>6; smg 7>6; rif 7>6; rl 7>1; mel 7>6 | soldier-remap-20261118 |
| ost_pzgren_pzfaust_g43 | 2026-11-19 | sreg 125%>100% | pass8-remap-20261118 |
| ost_pzgren_pzfaust_g43 | 2026-11-18 | sta 225%>200%; spd 1>0.9; tank 1>0.95; pis 7>6; smg 7>6; mg 7>6; mel 7>6 | soldier-remap-20261118 |
| ost_pzgren_pzfaust_rifle | 2026-11-19 | sreg 125%>100% | pass8-remap-20261118 |
| ost_pzgren_pzfaust_rifle | 2026-11-18 | sta 225%>200%; spd 1>0.9; tank 1>0.95; pis 7>6; smg 7>6; mg 7>6; mel 7>6 | soldier-remap-20261118 |
| ost_pzgren_sg44_pzfuast | 2026-11-19 | sreg 125%>100% | pass8-remap-20261118 |
| ost_pzgren_sg44_pzfuast | 2026-11-18 | sta 225%>200%; spd 1>0.9; tank 1>0.95; pis 7>6; mg 7>6; rif 7>6; mel 7>6 | soldier-remap-20261118 |
| ost_pzgren_sl | 2026-11-19 | sreg 125%>100% | pass8-remap-20261118 |
| ost_pzgren_sl | 2026-11-18 | sta 225%>200%; spd 1>0.9; tank 1>0.95; pis 7>6; mg 7>6; rif 7>6; rl 7>6; mel 7>6 | soldier-remap-20261118 |
| ost_pzgren_slassist | 2026-11-19 | sreg 125%>100% | pass8-remap-20261118 |
| ost_pzgren_slassist | 2026-11-18 | sta 225%>200%; spd 1>0.9; tank 1>0.95; pis 7>6; smg 7>6; rif 7>6; mel 7>6 | soldier-remap-20261118 |
| ost_pzgren_smg_pzfaust | 2026-11-19 | sreg 125%>100% | pass8-remap-20261118 |
| ost_pzgren_smg_pzfaust | 2026-11-18 | sta 225%>200%; spd 1>0.9; tank 1>0.95; pis 7>6; mg 7>6; rif 7>6; mel 7>6 | soldier-remap-20261118 |
| ost_radioman | 2026-11-18 | rl 2>1 | soldier-remap-20261118 |
| ost_recon_mg | 2026-11-18 | pis 3>2; rif 3>2 | soldier-remap-20261118 |
| ost_recon_pzfst | 2026-11-18 | pis 3>2 | soldier-remap-20261118 |
| ost_recon_rifle | 2026-11-18 | pis 3>2; rl 2>3 | soldier-remap-20261118 |
| ost_recon_sa | 2026-11-18 | pis 3>2; rl 2>3 | soldier-remap-20261118 |
| ost_recon_sl | 2026-11-18 | hp 200%>150%; tank 0.85>0.75; can 0.9>0.8; mg 3>2; rl 2>3 | soldier-remap-20261118 |
| ost_recon_sl_stg | 2026-11-18 | hp 200%>150%; tank 0.85>0.75; can 0.9>0.8; mg 3>2; rl 2>3 | soldier-remap-20261118 |
| ost_rifle_grenadier | 2026-11-18 | mg 3>2; rl 2>3 | soldier-remap-20261118 |
| ost_rifle_pzfst | 2026-11-18 | mg 3>2 | soldier-remap-20261118 |
| ost_rifle_single | 2026-11-18 | mg 3>2; rl 2>3 | soldier-remap-20261118 |
| ost_rifle2 | 2026-11-18 | mg 3>2; rl 2>4 | soldier-remap-20261118 |
| ost_saper | 2026-11-18 | tank 0.85>0.75; can 0.9>0.8; rl 2>3 | soldier-remap-20261118 |
| ost_sl_asst | 2026-11-18 | hp 150%>200%; sta 100%>150%; tank 0.75>0.85; can 0.8>0.9; smg 3>5; mg 2>3; rif 4>3; rl 2>5 | soldier-remap-20261118 |
| ost_smg | 2026-11-18 | rl 2>4 | soldier-remap-20261118 |
| ost_smg2 | 2026-11-18 | rl 2>4 | soldier-remap-20261118 |
| ost_smg3 | 2026-11-18 | rl 2>4 | soldier-remap-20261118 |
| ost_sniper | 2026-11-18 | hp 350%>400%; sta 150%>200%; spd 1>0.9; tank 0.75>0.95; can 0.8>1; pis 4>6; smg 4>6; mg 3>6; rl 3>6; mel 5>6 | held-remap-20261118 |
| ost_squadleader | 2026-11-18 | sta 125%>150%; pis 5>4; rif 4>3; rl 2>4; mel 5>4 | soldier-remap-20261118 |
| ost_squadleader2 | 2026-11-18 | sta 125%>150%; pis 5>4; rif 4>3; rl 2>4; mel 5>4 | soldier-remap-20261118 |
| ost_stg | 2026-11-18 | rl 2>4 | soldier-remap-20261118 |
| ost_straf_mauzer | 2026-11-18 | sta 100%>75%; tank 0.9>0.75; can 1>0.8; mel 1>2 | soldier-remap-20261118 |
| ost_straf_mp28 | 2026-11-18 | sta 100%>75%; tank 0.9>0.75; can 1>0.8; mel 1>2 | soldier-remap-20261118 |
| ost_straf_ppsh | 2026-11-18 | sta 100%>75%; tank 0.9>0.75; can 1>0.8; mel 1>2 | soldier-remap-20261118 |
| ost_support | 2026-11-18 | tank 1>0.85; pis 3>2; smg 3>2; mg 6>4; rif 4>2; rl 2>1; tg 6>4 | crew-remap-20261118, held-remap-20261118 |
| ost_tankman | 2026-11-18 | hp 100%>150%; can 0.8>0.9; pis 5>4; smg 5>4; mg 4>2; rl 2>1; tg 5>2 | crew-remap-20261118, held-remap-20261118 |
| ost_tankman2 | 2026-11-18 | tank 1>1.1; can 0.8>0.95; smg 5>4; mg 6>4; rl 2>1; tg 7>4 | crew-remap-20261118, held-remap-20261118 |
| tankman | 2026-11-18 | hp 100%>150%; can 0.8>0.9; pis 5>4; smg 5>4; mg 4>2; rl 2>1; tg 5>2 | crew-remap-20261118, held-remap-20261118 |
| tankman2 | 2026-11-18 | tank 1>1.1; can 0.8>0.95; smg 5>4; mg 6>4; rl 2>1; tg 7>4 | crew-remap-20261118, held-remap-20261118 |
| vehicle_supporter | 2026-11-18 | tank 1>0.85; pis 3>2; smg 3>2; mg 6>4; rif 4>2; rl 2>1; tg 6>4 | crew-remap-20261118, held-remap-20261118 |

#### Breeds: ger_ss (196 rows)

| Breed | Date | Changes (old>new) | Undo tag |
|---|---|---|---|
| ap_miner | 2026-11-18 | hp 150%>200%; rl 2>1 | soldier-remap-20261118 |
| at_miner | 2026-11-18 | hp 150%>200%; rl 2>1 | soldier-remap-20261118 |
| at_rifle | 2026-11-18 | hp 150%>300%; sta 100%>150%; tank 0.75>0.85; can 0.8>0.9; smg 4>3; mg 1>3; rl 2>1 | held-remap-20261118 |
| at_rifle2 | 2026-11-18 | hp 150%>300%; sta 100%>150%; tank 0.75>0.85; can 0.8>0.9; smg 4>5; mg 2>3; rif 5>3; rl 2>1 | soldier-remap-20261118 |
| bazooker | 2026-11-18 | pis 6>5; smg 3>5; mg 3>5; rif 5>6 | soldier-remap-20261118 |
| bazooker2 | 2026-11-18 | smg 3>5; mg 3>5; rl 6>1 | soldier-remap-20261118 |
| dr_pzgren_mg | 2026-11-18 | hp 200%>300%; rif 5>3 | crew-remap-20261118, soldier-remap-20261118 |
| dr_pzgren_mg_39 | 2026-11-18 | hp 200%>300%; rif 5>3; rl 4>1 | soldier-remap-20261118 |
| dr_pzgren_mg_asst | 2026-11-18 | hp 200%>300%; rif 5>3; rl 4>1 | crew-remap-20261118, soldier-remap-20261118 |
| dr_pzgren_pzfst | 2026-11-18 | hp 200%>300% | soldier-remap-20261118 |
| dr_pzgren_pzfst_stg | 2026-11-18 | hp 200%>300% | soldier-remap-20261118 |
| dr_pzgren_pzfst60_sa | 2026-11-18 | hp 200%>300% | soldier-remap-20261118 |
| dr_pzgren_rifle | 2026-11-18 | hp 200%>300% | crew-remap-20261118, soldier-remap-20261118 |
| dr_pzgren_sa | 2026-11-18 | hp 200%>300% | crew-remap-20261118, soldier-remap-20261118 |
| dr_pzgren_sa_41 | 2026-11-18 | hp 200%>300%; rl 4>1 | soldier-remap-20261118 |
| dr_pzgren_sl | 2026-11-18 | hp 200%>400%; sta 150%>200%; tank 0.85>0.95; can 0.9>1; pis 4>5; smg 5>6; mg 3>5; rif 3>5; rl 4>5; mel 4>5 | crew-remap-20261118, soldier-remap-20261118 |
| dr_pzgren_sl_asst | 2026-11-18 | hp 200%>400%; sta 150%>200%; tank 0.85>0.95; can 0.9>1; pis 4>5; smg 3>6; mg 3>5; rl 4>1; mel 4>5 | held-remap-20261118 |
| dr_pzgren_smg | 2026-11-18 | hp 200%>300%; rl 4>1 | soldier-remap-20261118 |
| dr_pzgren_stg | 2026-11-18 | hp 200%>300%; rl 4>1 | soldier-remap-20261118 |
| elite_tankman | 2026-11-18 | hp 100%>450%; sta 100%>200%; tank 1.2>1.15; veh 1.2>1.15; can 1.05>1; pis 7>5; mg 6>5; rif 4>3; mel 6>4; tg 8>7 | crew-remap-20261118, held-remap-20261118 |
| elite_tankman2 | 2026-11-18 | hp 150%>450%; sta 100%>200%; tank 1.25>1.2; veh 1.25>1.2; pis 6>5; smg 7>5; mg 7>6; rif 4>3; mel 6>4 | crew-remap-20261118, held-remap-20261118 |
| flamer | 2026-11-18 | hp 150%>200%; rl 2>1 | held-remap-20261118 |
| flamer2 | 2026-11-18 | hp 150%>200%; rl 2>1 | soldier-remap-20261118 |
| gebirgs_mg | 2026-11-18 | hp 200%>300%; tank 0.75>0.85; can 0.8>0.9; rl 4>1 | soldier-remap-20261118 |
| gebirgs_mg_asst | 2026-11-18 | hp 200%>300%; tank 0.75>0.85; can 0.8>0.9; rif 5>3; rl 4>1 | soldier-remap-20261118 |
| gebirgs_rifle | 2026-11-18 | hp 200%>300%; tank 0.75>0.85; can 0.8>0.9; rl 4>1 | soldier-remap-20261118 |
| gebirgs_sl | 2026-11-18 | hp 200%>400%; sta 150%>200%; tank 0.75>0.95; can 0.8>1; pis 4>5; smg 5>6; mg 4>5; rif 4>5; rl 4>1; mel 4>5; vet 24/60/108/168/240>60/132/216/312/420 | soldier-remap-20261118 |
| gebirgs_sl_asst | 2026-11-18 | hp 200%>400%; sta 150%>200%; tank 0.75>0.95; can 0.8>1; pis 4>5; smg 5>6; mg 4>5; rif 4>5; rl 4>1; mel 4>5; vet 24/60/108/168/240>60/132/216/312/420 | soldier-remap-20261118 |
| gebirgs_smg | 2026-11-18 | hp 200%>300%; tank 0.75>0.85; can 0.8>0.9; rl 4>1 | soldier-remap-20261118 |
| grenadier_mg | 2026-11-18 | hp 200%>300%; sta 125%>150%; tank 0.75>0.85; can 0.8>0.9; rl 4>1 | soldier-remap-20261118 |
| grenadier_mg_39 | 2026-11-18 | hp 200%>300%; sta 125%>150%; tank 0.75>0.85; can 0.8>0.9; rl 4>1 | soldier-remap-20261118 |
| grenadier_mg_asst | 2026-11-18 | hp 200%>300%; sta 125%>150%; tank 0.75>0.85; can 0.8>0.9; rif 5>3; rl 4>1 | soldier-remap-20261118 |
| grenadier_pzfst | 2026-11-18 | hp 200%>300%; sta 125%>150%; tank 0.75>0.85; can 0.8>0.9 | soldier-remap-20261118 |
| grenadier_rifle | 2026-11-18 | hp 200%>300%; sta 125%>150%; tank 0.75>0.85; can 0.8>0.9; rl 4>1 | soldier-remap-20261118 |
| grenadier_rifle_grenadier | 2026-11-18 | hp 200%>300%; sta 125%>150%; tank 0.75>0.85; can 0.8>0.9; rl 4>1 | soldier-remap-20261118 |
| grenadier_sa | 2026-11-18 | hp 200%>300%; sta 125%>150%; tank 0.75>0.85; can 0.8>0.9; rl 4>1 | soldier-remap-20261118 |
| grenadier_sa_41 | 2026-11-18 | hp 200%>300%; sta 125%>150%; tank 0.75>0.85; can 0.8>0.9; rl 4>1 | soldier-remap-20261118 |
| grenadier_sl | 2026-11-18 | hp 200%>400%; sta 125%>200%; tank 0.75>0.95; can 0.8>1; pis 4>5; smg 5>6; mg 3>5; rif 3>5; rl 4>1; mel 4>5; vet 24/60/108/168/240>60/132/216/312/420 | soldier-remap-20261118 |
| grenadier_sl_asst | 2026-11-18 | hp 200%>400%; sta 125%>200%; tank 0.75>0.95; can 0.8>1; pis 4>5; smg 3>6; mg 3>5; rl 4>1; mel 4>5; vet 24/60/108/168/240>60/132/216/312/420 | soldier-remap-20261118 |
| grenadier_smg | 2026-11-18 | hp 200%>300%; sta 125%>150%; tank 0.75>0.85; can 0.8>0.9; rl 4>1 | soldier-remap-20261118 |
| grenadier_stg | 2026-11-18 | hp 200%>300%; sta 125%>150%; tank 0.75>0.85; can 0.8>0.9; rl 4>5 | soldier-remap-20261118 |
| lssah_pzgren_at | 2026-11-18 | hp 200%>300%; tank 0.95>0.85; can 1>0.9; pis 5>4 | soldier-remap-20261118 |
| lssah_pzgren_at2 | 2026-11-18 | hp 200%>300%; tank 0.95>0.85; can 1>0.9; rl 5>1 | soldier-remap-20261118 |
| lssah_pzgren_mg | 2026-11-18 | hp 200%>300%; rif 5>3; rl 4>1 | soldier-remap-20261118 |
| lssah_pzgren_mg_39 | 2026-11-18 | hp 200%>300%; rif 5>3; rl 4>1 | soldier-remap-20261118 |
| lssah_pzgren_mg_asst | 2026-11-18 | hp 200%>300%; rif 5>3; rl 4>1 | soldier-remap-20261118 |
| lssah_pzgren_rifle | 2026-11-18 | hp 200%>300%; rl 4>1 | soldier-remap-20261118 |
| lssah_pzgren_sa | 2026-11-18 | hp 200%>300%; rl 4>1 | soldier-remap-20261118 |
| lssah_pzgren_sa_41 | 2026-11-18 | hp 200%>300%; rl 4>1 | soldier-remap-20261118 |
| lssah_pzgren_sl_asst | 2026-11-18 | hp 200%>400%; sta 150%>200%; tank 0.85>0.95; can 0.9>1; pis 4>5; smg 3>6; mg 3>5; rl 4>1; mel 4>5 | held-remap-20261118 |
| lssah_pzgren_sl_asst_sa | 2026-11-18 | hp 200%>400%; sta 150%>200%; tank 0.85>0.95; can 0.9>1; pis 4>5; smg 3>6; mg 3>5; rl 4>1; mel 4>5 | soldier-remap-20261118 |
| lssah_pzgren_sl_smg | 2026-11-18 | hp 200%>400%; sta 150%>200%; tank 0.85>0.95; can 0.9>1; pis 4>5; smg 5>6; mg 4>5; rif 4>5; rl 4>1; mel 4>5 | soldier-remap-20261118 |
| oficer | 2026-11-18 | hp 250%>300%; sta 100%>150%; spd 1>0.9; rl 5>1 | soldier-remap-20261118 |
| pzgren_mg | 2026-11-18 | hp 200%>300%; tank 0.75>0.85; can 0.8>0.9; rl 4>1 | soldier-remap-20261118 |
| pzgren_mg_39 | 2026-11-18 | hp 200%>300%; tank 0.75>0.85; can 0.8>0.9; rl 4>1 | soldier-remap-20261118 |
| pzgren_mg_asst | 2026-11-18 | hp 200%>300%; tank 0.75>0.85; can 0.8>0.9; rif 5>3; rl 4>1 | soldier-remap-20261118 |
| pzgren_rifle | 2026-11-18 | hp 200%>300%; tank 0.75>0.85; can 0.8>0.9; mg 4>3; rl 4>1 | soldier-remap-20261118 |
| pzgren_sa | 2026-11-18 | hp 200%>300%; tank 0.75>0.85; can 0.8>0.9; mg 4>3; rl 4>1 | soldier-remap-20261118 |
| pzgren_sa_41 | 2026-11-18 | hp 200%>300%; tank 0.75>0.85; can 0.8>0.9; mg 4>3; rl 4>1 | soldier-remap-20261118 |
| pzgren_sl_asst | 2026-11-18 | hp 200%>400%; sta 150%>200%; tank 0.75>0.95; can 0.8>1; pis 4>5; smg 3>6; mg 4>5; rl 4>1; mel 4>5; vet 24/60/108/168/240>60/132/216/312/420 | soldier-remap-20261118 |
| pzgren_sl_smg | 2026-11-18 | hp 200%>400%; sta 150%>200%; tank 0.75>0.95; can 0.8>1; pis 4>5; smg 5>6; mg 4>5; rif 3>5; rl 4>1; mel 4>5; vet 24/60/108/168/240>60/132/216/312/420 | soldier-remap-20261118 |
| saper | 2026-11-18 | hp 150%>200%; tank 0.85>0.75; can 0.9>0.8; rl 2>1 | soldier-remap-20261118 |
| sniper | 2026-11-18 | hp 350%>400%; sta 150%>200%; spd 1>0.9; tank 0.75>0.95; can 0.8>1; pis 4>5; smg 3>5; mg 2>5; rl 2>1; mel 4>5; vet 24/60/108/168/240>60/132/216/312/420 | held-remap-20261118 |
| sniper2 | 2026-11-18 | hp 350%>450%; spd 1>0.9; tank 0.85>0.95; can 0.9>1; pis 7>6; smg 7>6; mg 7>6; rl 7>1; mel 7>6; vet 24/60/108/168/240>60/132/216/312/420 | held-remap-20261118 |
| sniper2_early | 2026-11-18 | hp 350%>450%; spd 1>0.9; tank 0.85>0.95; can 0.9>1; pis 7>6; smg 7>6; mg 7>6; rl 7>1; mel 7>6; vet 24/60/108/168/240>60/132/216/312/420 | held-remap-20261118 |
| sniper3 | 2026-11-18 | hp 350%>400%; sta 150%>200%; spd 1>0.9; tank 0.75>0.95; can 0.8>1; pis 4>5; smg 3>5; mg 2>5; rl 2>1; mel 4>5; vet 24/60/108/168/240>60/132/216/312/420 | soldier-remap-20261118 |
| ss_ap_miner | 2026-11-18 | hp 150%>200%; rl 2>3 | soldier-remap-20261118 |
| ss_at_miner | 2026-11-18 | hp 150%>200%; rl 2>3 | soldier-remap-20261118 |
| ss_at_rifle | 2026-11-18 | hp 150%>300%; sta 100%>150%; tank 0.75>0.85; can 0.8>0.9; smg 4>3; mg 1>3; rl 2>4 | held-remap-20261118 |
| ss_at_rifleassist | 2026-11-18 | hp 150%>300%; sta 100%>150%; tank 0.75>0.85; can 0.8>0.9; smg 4>3; mg 2>3; rl 2>1 | soldier-remap-20261118 |
| ss_fallschirm_grenadier | 2026-11-18 | hp 400%>450%; pis 7>6; smg 7>6; mg 7>6; rl 7>1; mel 7>6 | soldier-remap-20261118 |
| ss_fallschirm_mg | 2026-11-19 | hp 200%>450%; sta 100%>200%; tank 0.75>0.95; can 0.8>1; pis 2>6; smg 2>6; mg 3>7; rif 2>6; rl 2>6; mel 3>6 | pass7-remap-20261118, pass8-remap-20261118 |
| ss_fallschirm_mg | 2026-11-18 | hp 250%>200%; sta 150%>100%; pis 3>2; smg 3>2; rif 3>2; rl 3>2 | soldier-remap-20261118 |
| ss_fallschirm_mg_asst | 2026-11-19 | mg 3>2; rif 2>3 | pass7-remap-20261118, pass8-remap-20261118 |
| ss_fallschirm_mg_asst | 2026-11-18 | hp 150%>200%; rif 3>2 | soldier-remap-20261118 |
| ss_fallschirm_pzfst_stg | 2026-11-18 | hp 400%>450%; pis 7>6; mg 7>6; rif 7>6; mel 7>6 | soldier-remap-20261118 |
| ss_fallschirm_rifle | 2026-11-18 | hp 150%>200%; rl 1>2 | soldier-remap-20261118 |
| ss_fallschirm_sl | 2026-11-19 | hp 200%>450%; sta 100%>200%; tank 0.75>0.95; can 0.8>1; pis 4>6; smg 4>7; mg 2>6; rif 3>6; rl 3>6; mel 4>6 | pass7-remap-20261118, pass8-remap-20261118 |
| ss_fallschirm_sl | 2026-11-18 | hp 250%>200%; sta 150%>100%; mg 4>2; rif 4>3; rl 4>3 | soldier-remap-20261118 |
| ss_fallschirm_sl_asst_smg | 2026-11-19 | hp 200%>400%; sta 100%>200%; tank 0.75>0.95; can 0.8>1; pis 4>5; smg 4>6; mg 2>5; rif 3>5; rl 4>6; mel 4>5 | pass7-remap-20261118, pass8-remap-20261118 |
| ss_fallschirm_sl_asst_smg | 2026-11-18 | hp 400%>200%; sta 200%>100%; tank 0.95>0.75; can 1>0.8; pis 3>4; smg 3>4; mg 3>2; rl 3>4; mel 3>4 | soldier-remap-20261118 |
| ss_fallschirm_smg | 2026-11-19 | hp 200%>400%; sta 100%>200%; tank 0.75>0.95; can 0.8>1; pis 2>5; smg 3>6; mg 2>5; rif 2>5; rl 2>5; mel 3>5; vet 24/60/108/168/240>60/132/216/312/420 | pass7-remap-20261118, pass8-remap-20261118 |
| ss_fallschirm_smg | 2026-11-18 | hp 150%>200%; rl 1>2 | soldier-remap-20261118 |
| ss_flamer | 2026-11-18 | hp 150%>200%; rl 2>3 | held-remap-20261118 |
| ss_flamerassist | 2026-11-18 | hp 150%>200%; rl 2>1 | soldier-remap-20261118 |
| ss_g43scope_sniper | 2026-11-18 | hp 350%>400%; sta 150%>200%; spd 1>0.9; tank 0.75>0.95; can 0.8>1; pis 4>5; smg 3>5; mg 2>5; rl 2>5; mel 4>5; vet 24/60/108/168/240>60/132/216/312/420 | soldier-remap-20261118 |
| ss_gebirgs_mg | 2026-11-18 | hp 200%>300%; tank 0.75>0.85; can 0.8>0.9 | soldier-remap-20261118 |
| ss_gebirgs_mg_asst | 2026-11-18 | hp 200%>300%; tank 0.75>0.85; can 0.8>0.9; rif 5>3; rl 4>1 | soldier-remap-20261118 |
| ss_gebirgs_pzfst | 2026-11-18 | hp 200%>300%; tank 0.75>0.85; can 0.8>0.9 | soldier-remap-20261118 |
| ss_gebirgs_pzfst_ber | 2026-11-18 | hp 200%>300%; tank 0.75>0.85; can 0.8>0.9; rl 4>5 | soldier-remap-20261118 |
| ss_gebirgs_rifle | 2026-11-18 | hp 200%>300%; tank 0.75>0.85; can 0.8>0.9 | soldier-remap-20261118 |
| ss_gebirgs_sl | 2026-11-18 | hp 200%>400%; sta 150%>200%; tank 0.75>0.95; can 0.8>1; pis 4>5; smg 5>6; mg 4>5; rif 4>5; rl 4>5; mel 4>5; vet 24/60/108/168/240>60/132/216/312/420 | soldier-remap-20261118 |
| ss_gebirgs_sl_asst | 2026-11-18 | hp 200%>400%; sta 150%>200%; tank 0.75>0.95; can 0.8>1; pis 4>5; smg 5>6; mg 4>5; rif 4>5; rl 4>1; mel 4>5; vet 24/60/108/168/240>60/132/216/312/420 | soldier-remap-20261118 |
| ss_gebirgs_sl_asst_k98 | 2026-11-18 | hp 200%>400%; sta 150%>200%; tank 0.75>0.95; can 0.8>1; pis 4>5; smg 5>6; mg 4>5; rif 4>5; rl 4>1; mel 4>5; vet 24/60/108/168/240>60/132/216/312/420 | soldier-remap-20261118 |
| ss_gebirgs_smg | 2026-11-18 | hp 200%>300%; tank 0.75>0.85; can 0.8>0.9 | soldier-remap-20261118 |
| ss_grenadier_mg | 2026-11-18 | hp 200%>300%; sta 125%>150%; tank 0.75>0.85; can 0.8>0.9 | soldier-remap-20261118 |
| ss_grenadier_mg_39 | 2026-11-18 | hp 200%>300%; sta 125%>150%; tank 0.75>0.85; can 0.8>0.9 | soldier-remap-20261118 |
| ss_grenadier_mg_asst | 2026-11-18 | hp 200%>300%; sta 125%>150%; tank 0.75>0.85; can 0.8>0.9; rif 5>3; rl 4>1 | soldier-remap-20261118 |
| ss_grenadier_pzfst | 2026-11-18 | hp 200%>300%; sta 125%>150%; tank 0.75>0.85; can 0.8>0.9 | soldier-remap-20261118 |
| ss_grenadier_rifle | 2026-11-18 | hp 200%>300%; sta 125%>150%; tank 0.75>0.85; can 0.8>0.9 | soldier-remap-20261118 |
| ss_grenadier_rifle_grenadier3 | 2026-11-18 | hp 200%>300%; sta 125%>150%; tank 0.75>0.85; can 0.8>0.9 | soldier-remap-20261118 |
| ss_grenadier_sa | 2026-11-18 | hp 200%>300%; sta 125%>150%; tank 0.75>0.85; can 0.8>0.9 | soldier-remap-20261118 |
| ss_grenadier_sa_44 | 2026-11-18 | hp 200%>300%; sta 125%>150%; tank 0.75>0.85; can 0.8>0.9; rl 4>5 | soldier-remap-20261118 |
| ss_grenadier_sl | 2026-11-18 | hp 200%>400%; sta 125%>200%; tank 0.75>0.95; can 0.8>1; pis 4>5; smg 5>6; mg 3>5; rif 3>5; rl 4>5; mel 4>5; vet 24/60/108/168/240>60/132/216/312/420 | soldier-remap-20261118 |
| ss_grenadier_sl_asst_44 | 2026-11-18 | hp 200%>400%; sta 125%>200%; tank 0.75>0.95; can 0.8>1; pis 4>5; smg 3>6; mg 3>5; rl 4>6; mel 4>5; vet 24/60/108/168/240>60/132/216/312/420 | soldier-remap-20261118 |
| ss_grenadier_smg | 2026-11-18 | hp 200%>300%; sta 125%>150%; tank 0.75>0.85; can 0.8>0.9 | soldier-remap-20261118 |
| ss_grenadier_stg | 2026-11-18 | hp 200%>300%; sta 125%>150%; tank 0.75>0.85; can 0.8>0.9; rl 4>5 | soldier-remap-20261118 |
| ss_kosaken_mg | 2026-11-18 | hp 100%>200%; pis 1>2; rif 2>1; mel 1>2 | soldier-remap-20261118 |
| ss_kosaken_mg_asst | 2026-11-18 | hp 100%>200%; pis 1>2; rif 2>1; mel 1>2 | soldier-remap-20261118 |
| ss_kosaken_rifle | 2026-11-18 | hp 100%>200%; mel 1>2 | soldier-remap-20261118 |
| ss_kosaken_sl | 2026-11-18 | hp 100%>200%; rl 1>2; mel 2>3; inv: -ammo ppsh41_mag 142, +ammo ppsh41_mag 140 | fixes-20261118b, soldier-remap-20261118 |
| ss_kosaken_sl_asst | 2026-11-18 | hp 100%>200%; mel 2>3; inv: -ammo ppsh41_mag 142, +ammo ppsh41_mag 140 | fixes-20261118b, soldier-remap-20261118 |
| ss_kosaken_smg | 2026-11-18 | hp 100%>200%; pis 1>2; mel 1>2; inv: -ammo ppsh41_mag 142, +ammo ppsh41_mag 140 | fixes-20261118b, soldier-remap-20261118 |
| ss_light_mortar | 2026-11-18 | hp 150%>200%; pis 4>1; smg 3>1; mg 2>1; rif 5>2; mel 4>2 | soldier-remap-20261118 |
| ss_light_mortar_assist | 2026-11-18 | hp 150%>300%; sta 100%>150%; tank 0.75>0.85; can 0.8>0.9; mg 2>3; rl 2>1 | soldier-remap-20261118 |
| ss_lssah_pzgren_at | 2026-11-18 | hp 200%>300%; tank 0.95>0.85; can 1>0.9; pis 5>4 | soldier-remap-20261118 |
| ss_lssah_pzgren_at2 | 2026-11-18 | hp 200%>300%; tank 0.95>0.85; can 1>0.9; rl 5>4 | soldier-remap-20261118 |
| ss_lssah_pzgren_mg | 2026-11-18 | hp 200%>300%; rif 5>3 | soldier-remap-20261118 |
| ss_lssah_pzgren_mg_39 | 2026-11-18 | hp 200%>300%; rif 5>3 | soldier-remap-20261118 |
| ss_lssah_pzgren_mg_asst | 2026-11-18 | hp 200%>300%; rif 5>3; rl 4>1 | soldier-remap-20261118 |
| ss_lssah_pzgren_pzfst | 2026-11-18 | hp 200%>300% | soldier-remap-20261118 |
| ss_lssah_pzgren_pzfst_stg | 2026-11-18 | hp 200%>300% | soldier-remap-20261118 |
| ss_lssah_pzgren_pzfst60_sa | 2026-11-18 | hp 200%>300% | soldier-remap-20261118 |
| ss_lssah_pzgren_sl_asst_sa | 2026-11-18 | hp 200%>400%; sta 150%>200%; tank 0.85>0.95; can 0.9>1; pis 4>5; smg 3>6; mg 3>5; rl 4>1; mel 4>5 | soldier-remap-20261118 |
| ss_lssah_pzgren_sl_stg | 2026-11-18 | hp 200%>400%; sta 150%>200%; tank 0.85>0.95; can 0.9>1; pis 4>5; smg 5>6; mg 4>5; rif 4>5; rl 4>5; mel 4>5 | soldier-remap-20261118 |
| ss_officer | 2026-11-18 | hp 250%>300%; sta 100%>150%; spd 1>0.9; rl 5>4 | soldier-remap-20261118 |
| ss_panzerfaust | 2026-11-18 | hp 150%>300%; sta 100%>150%; tank 0.75>0.85; can 0.8>0.9; mg 2>3; rl 6>5 | soldier-remap-20261118 |
| ss_panzershreck | 2026-11-18 | pis 6>5; smg 3>5; mg 3>5; rif 5>6 | soldier-remap-20261118 |
| ss_panzershreckassist | 2026-11-18 | smg 3>5; mg 3>5; rl 6>1 | soldier-remap-20261118 |
| ss_pzgren_mg | 2026-11-18 | hp 200%>300%; tank 0.75>0.85; can 0.8>0.9 | soldier-remap-20261118 |
| ss_pzgren_mg_asst | 2026-11-18 | hp 200%>300%; tank 0.75>0.85; can 0.8>0.9; rif 5>3; rl 4>1 | soldier-remap-20261118 |
| ss_pzgren_pzfst | 2026-11-18 | hp 200%>300%; tank 0.75>0.85; can 0.8>0.9; mg 4>3 | soldier-remap-20261118 |
| ss_pzgren_pzfst_sa | 2026-11-18 | hp 200%>300%; tank 0.75>0.85; can 0.8>0.9; mg 4>3 | soldier-remap-20261118 |
| ss_pzgren_sl_asst_pzfst | 2026-11-18 | hp 200%>400%; sta 150%>200%; tank 0.75>0.95; can 0.8>1; pis 4>5; smg 3>6; mg 4>5; rl 5>6; mel 4>5 | soldier-remap-20261118 |
| ss_pzgren_sl_stg | 2026-11-18 | hp 200%>400%; sta 150%>200%; tank 0.75>0.95; can 0.8>1; pis 4>5; smg 5>6; mg 4>5; rif 3>5; mel 4>5 | soldier-remap-20261118 |
| ss_pzgren_stg | 2026-11-18 | hp 200%>300%; tank 0.75>0.85; can 0.8>0.9; mg 4>3 | soldier-remap-20261118 |
| ss_saper | 2026-11-18 | hp 150%>200%; tank 0.85>0.75; can 0.9>0.8; rl 2>3 | soldier-remap-20261118 |
| ss_sniper_mauser | 2026-11-18 | hp 350%>400%; sta 150%>200%; spd 1>0.9; tank 0.75>0.95; can 0.8>1; pis 4>5; smg 3>5; mg 2>5; rl 2>5; mel 4>5; vet 24/60/108/168/240>60/132/216/312/420 | held-remap-20261118 |
| ss_ss_sturmgren_stg | 2026-11-18 | hp 200%>300%; sta 125%>150%; tank 0.75>0.85; can 0.8>0.9; rl 4>5 | soldier-remap-20261118 |
| ss_ssvt_mg | 2026-11-18 | hp 100%>200% | soldier-remap-20261118 |
| ss_ssvt_mg_asst | 2026-11-18 | hp 100%>200% | soldier-remap-20261118 |
| ss_ssvt_rifle | 2026-11-18 | hp 100%>200% | soldier-remap-20261118 |
| ss_ssvt_sl | 2026-11-18 | hp 150%>200%; sta 125%>100%; mel 2>3 | soldier-remap-20261118 |
| ss_ssvt_sl_asst | 2026-11-18 | hp 150%>200%; sta 125%>100%; smg 2>3; mg 1>2; rif 3>2; rl 2>1; mel 2>3 | soldier-remap-20261118 |
| ss_sturmgren_mg | 2026-11-18 | hp 200%>300%; sta 125%>150%; tank 0.75>0.85; can 0.8>0.9 | soldier-remap-20261118 |
| ss_sturmgren_mg_asst | 2026-11-18 | hp 200%>300%; sta 125%>150%; tank 0.75>0.85; can 0.8>0.9; smg 5>3; rl 4>1 | soldier-remap-20261118 |
| ss_sturmgren_sa | 2026-11-18 | hp 200%>300%; sta 125%>150%; tank 0.75>0.85; can 0.8>0.9 | soldier-remap-20261118 |
| ss_sturmgren_sa_scope | 2026-11-18 | hp 200%>300%; sta 125%>150%; tank 0.75>0.85; can 0.8>0.9; rl 4>5 | soldier-remap-20261118 |
| ss_sturmgren_sl | 2026-11-18 | hp 200%>400%; sta 125%>200%; tank 0.75>0.95; can 0.8>1; pis 4>5; smg 5>6; mg 3>5; rif 3>5; rl 4>5; mel 4>5; vet 24/60/108/168/240>60/132/216/312/420 | soldier-remap-20261118 |
| ss_sturmgren_sl_asst | 2026-11-18 | hp 200%>400%; sta 125%>200%; tank 0.75>0.95; can 0.8>1; pis 4>5; smg 5>6; mg 3>5; rif 3>5; rl 4>6; mel 4>5; vet 24/60/108/168/240>60/132/216/312/420 | soldier-remap-20261118 |
| ss_sturmgren_smg | 2026-11-18 | hp 200%>300%; sta 125%>150%; tank 0.75>0.85; can 0.8>0.9 | soldier-remap-20261118 |
| ss_sturmgren_stg_pzf | 2026-11-18 | hp 200%>300%; sta 125%>150%; tank 0.75>0.85; can 0.8>0.9; rl 4>5 | soldier-remap-20261118 |
| ss_sturmpio_at | 2026-11-18 | hp 150%>200% | soldier-remap-20261118 |
| ss_sturmpio_flamer | 2026-11-18 | hp 150%>200%; rl 2>3 | held-remap-20261118 |
| ss_sturmpio_mg | 2026-11-18 | hp 150%>200%; rl 2>3 | soldier-remap-20261118 |
| ss_sturmpio_mg_asst | 2026-11-18 | hp 150%>200%; rif 4>3; rl 2>1 | soldier-remap-20261118 |
| ss_sturmpio_sl | 2026-11-18 | hp 200%>300%; sta 100%>150%; rif 4>3; rl 2>4; mel 5>4 | soldier-remap-20261118 |
| ss_sturmpio1 | 2026-11-18 | hp 150%>200% | soldier-remap-20261118 |
| ss_sturmpio2 | 2026-11-18 | hp 150%>200%; tank 0.85>0.75; can 0.9>0.8; rl 2>3 | soldier-remap-20261118 |
| ss_sturmpio3 | 2026-11-18 | hp 150%>200%; tank 0.85>0.75; can 0.9>0.8; rl 2>3 | soldier-remap-20261118 |
| ss_sturmpio4 | 2026-11-18 | hp 150%>200%; rl 2>3 | soldier-remap-20261118 |
| ss_support | 2026-11-18 | hp 150%>200%; veh 1.05>1; can 1.05>1; pis 3>2; smg 3>2; mg 5>4; rif 3>2; rl 2>1 | crew-remap-20261118, held-remap-20261118 |
| ss_tankman | 2026-11-18 | hp 100%>200%; tank 1.1>1; veh 1.1>1; can 1.05>0.9; pis 5>4; mg 3>2; mel 5>4; tg 3>2 | crew-remap-20261118, held-remap-20261118 |
| ss_tankman2 | 2026-11-18 | hp 150%>200%; tank 1.15>1.1; veh 1.15>1; can 1.1>0.95; pis 5>4; smg 5>4; mg 5>4; mel 5>4; tg 5>4 | crew-remap-20261118, held-remap-20261118 |
| ss_tk_pzgren_mg | 2026-11-18 | hp 200%>300%; rif 5>3 | soldier-remap-20261118 |
| ss_tk_pzgren_mg_39 | 2026-11-18 | hp 200%>300%; rif 5>3 | soldier-remap-20261118 |
| ss_tk_pzgren_mg_asst | 2026-11-18 | hp 200%>300%; rif 5>3; rl 4>1 | soldier-remap-20261118 |
| ss_tk_pzgren_pzfst | 2026-11-18 | hp 200%>300% | soldier-remap-20261118 |
| ss_tk_pzgren_pzfst_stg | 2026-11-18 | hp 200%>300% | soldier-remap-20261118 |
| ss_tk_pzgren_pzfst60_sa | 2026-11-18 | hp 200%>300% | soldier-remap-20261118 |
| ss_tk_pzgren_rifle | 2026-11-18 | hp 200%>300% | soldier-remap-20261118 |
| ss_tk_pzgren_sa | 2026-11-18 | hp 200%>300% | soldier-remap-20261118 |
| ss_tk_pzgren_sl | 2026-11-18 | hp 200%>400%; sta 150%>200%; tank 0.85>0.95; can 0.9>1; pis 4>5; smg 5>6; mg 3>5; rif 3>5; rl 4>5; mel 4>5 | soldier-remap-20261118 |
| ss_tk_pzgren_sl_asst | 2026-11-18 | hp 200%>400%; sta 150%>200%; tank 0.85>0.95; can 0.9>1; pis 4>5; smg 3>6; mg 3>5; rl 4>1; mel 4>5 | held-remap-20261118 |
| ss_vehicle_supporter | 2026-11-18 | hp 150%>200%; veh 1.05>1; can 1.05>1; pis 3>2; smg 3>2; mg 5>4; rif 3>2; rl 2>1 | crew-remap-20261118, held-remap-20261118 |
| ss_vet_sniper | 2026-11-18 | hp 350%>450%; spd 1>0.9; tank 0.85>0.95; can 0.9>1; pis 7>6; smg 7>6; mg 7>6; rl 7>6; mel 7>6; vet 24/60/108/168/240>60/132/216/312/420 | held-remap-20261118 |
| ss_vet_tankman2 | 2026-11-18 | hp 150%>300%; sta 100%>150%; can 1.1>1; mg 6>5; mel 5>4 | crew-remap-20261118, held-remap-20261118 |
| ssvt_mg | 2026-11-18 | hp 100%>200% | soldier-remap-20261118 |
| ssvt_mg_asst | 2026-11-18 | hp 100%>200% | soldier-remap-20261118 |
| ssvt_pzfst | 2026-11-18 | hp 100%>200% | soldier-remap-20261118 |
| ssvt_rifle | 2026-11-18 | hp 100%>200% | soldier-remap-20261118 |
| ssvt_sl | 2026-11-18 | hp 150%>200%; sta 125%>100%; rl 2>1; mel 2>3 | soldier-remap-20261118 |
| ssvt_sl_asst | 2026-11-18 | hp 150%>200%; sta 125%>100%; smg 2>3; mg 1>2; rif 3>2; rl 2>1; mel 2>3 | soldier-remap-20261118 |
| tankman | 2026-11-18 | hp 100%>200%; tank 1.1>1; veh 1.1>1; can 1.05>0.9; pis 5>4; mg 3>2; mel 5>4; tg 3>2 | crew-remap-20261118, held-remap-20261118 |
| tankman2 | 2026-11-18 | hp 150%>200%; tank 1.15>1.1; veh 1.15>1; can 1.1>0.95; pis 5>4; smg 5>4; mg 5>4; mel 5>4; tg 5>4 | crew-remap-20261118, held-remap-20261118 |
| tk_pzgren_mg | 2026-11-18 | hp 200%>300%; rif 5>3; rl 4>1 | soldier-remap-20261118 |
| tk_pzgren_mg_39 | 2026-11-18 | hp 200%>300%; rif 5>3; rl 4>1 | soldier-remap-20261118 |
| tk_pzgren_mg_asst | 2026-11-18 | hp 200%>300%; rif 5>3; rl 4>1 | soldier-remap-20261118 |
| tk_pzgren_rifle | 2026-11-18 | hp 200%>300%; rl 4>1 | soldier-remap-20261118 |
| tk_pzgren_sa | 2026-11-18 | hp 200%>300%; rl 4>1 | soldier-remap-20261118 |
| tk_pzgren_sa_41 | 2026-11-18 | hp 200%>300%; rl 4>1 | soldier-remap-20261118 |
| tk_pzgren_sl | 2026-11-18 | hp 200%>400%; sta 150%>200%; tank 0.85>0.95; can 0.9>1; pis 4>5; smg 5>6; mg 3>5; rif 3>5; rl 4>1; mel 4>5; vet -1/0/48/120/192>-1/0/84/180/288 | soldier-remap-20261118 |
| tk_pzgren_sl_asst | 2026-11-18 | hp 200%>400%; sta 150%>200%; tank 0.85>0.95; can 0.9>1; pis 4>5; smg 3>6; mg 3>5; rl 4>1; mel 4>5; vet -1/0/48/120/192>-1/0/84/180/288 | held-remap-20261118 |
| vehicle_supporter | 2026-11-18 | hp 150%>200%; veh 1.05>1; can 1.05>1; pis 3>2; smg 3>2; mg 5>4; rif 3>2; rl 2>1 | crew-remap-20261118, held-remap-20261118 |
| vet_tankman | 2026-11-18 | hp 100%>300%; sta 100%>150%; veh 1.1>1; can 1.05>0.95; pis 5>4; mg 5>4; mel 5>4; tg 5>4 | crew-remap-20261118, held-remap-20261118 |
| vet_tankman2 | 2026-11-18 | hp 150%>300%; sta 100%>150%; can 1.1>1; mg 6>5; mel 5>4 | crew-remap-20261118, held-remap-20261118 |

#### Breeds: jap (155 rows)

| Breed | Date | Changes (old>new) | Undo tag |
|---|---|---|---|
| ap_miner | 2026-11-18 | hp 150%>200%; tank 0.8>0.75; can 1>0.8 | soldier-remap-20261118 |
| at_miner | 2026-11-18 | hp 150%>200%; tank 0.8>0.75; can 1>0.8 | soldier-remap-20261118 |
| at_rifle | 2026-11-18 | sta 100%>75%; tank 0.8>0.75; can 1>0.8; pis 2>1; smg 2>1; rif 3>1 | crew-remap-20261118, soldier-remap-20261118 |
| at_rifle2 | 2026-11-18 | sta 100%>75%; tank 0.8>0.75; can 1>0.8; pis 2>1; smg 2>1; rif 3>1 | soldier-remap-20261118 |
| charger_rifle | 2026-11-18 | hp 250%>300%; tank 0.9>0.75; can 1>0.8 | charge-remap-20261118, charge2-remap-20261118, soldier-remap-20261118 |
| charger_smg | 2026-11-18 | hp 250%>300%; tank 0.9>0.75; can 1>0.8 | charge-remap-20261118, charge2-remap-20261118, soldier-remap-20261118 |
| elite | 2026-11-18 | hp 400%>450%; tank 0.9>0.95; pis 7>6; smg 7>6; mg 7>6; rl 7>1; mel 7>6 | soldier-remap-20261118 |
| elite_ig1 | 2026-11-18 | tank 0.9>0.85; can 1>0.9; pis 3>4; rl 3>1; mel 5>4 | soldier-remap-20261118 |
| elite_ig1_ammo | 2026-11-18 | tank 0.9>0.85; can 1>0.9; pis 3>4; rl 3>1; mel 5>4 | soldier-remap-20261118 |
| elite_ig1b | 2026-11-18 | tank 0.9>0.85; can 1>0.9; pis 3>4; rl 3>1; mel 5>4 | soldier-remap-20261118 |
| elite_ig1h | 2026-11-18 | tank 0.9>0.85; can 1>0.9; pis 3>4; rl 3>1; mel 5>4 | soldier-remap-20261118 |
| elite_ig1h_ammo | 2026-11-18 | tank 0.9>0.85; can 1>0.9; pis 3>4; rl 3>1; mel 5>4 | soldier-remap-20261118 |
| elite_ig1h_asst | 2026-11-18 | tank 0.9>0.85; can 1>0.9; pis 3>4; mg 5>3; rl 3>1; mel 5>4 | soldier-remap-20261118 |
| elite_ig2 | 2026-11-18 | tank 0.9>0.85; can 1>0.9; pis 3>4; rl 3>1; mel 5>4 | soldier-remap-20261118 |
| elite_ig2_scoped | 2026-11-18 | tank 0.9>0.85; can 1>0.9; pis 3>4; rl 3>1; mel 5>4 | soldier-remap-20261118 |
| elite_ig3 | 2026-11-18 | tank 0.9>0.85; can 1>0.9; pis 3>4; rl 3>1; mel 5>4 | soldier-remap-20261118 |
| elite_ig3b_type2 | 2026-11-18 | tank 0.9>0.85; can 1>0.9; pis 3>4; rl 3>1; mel 5>4 | soldier-remap-20261118 |
| elite_ig4 | 2026-11-18 | tank 0.9>0.85; can 1>0.9; pis 3>4; mel 5>4 | soldier-remap-20261118 |
| elite_ig4_type2 | 2026-11-18 | tank 0.9>0.85; can 1>0.9; pis 3>4; mel 5>4 | soldier-remap-20261118 |
| elite_mgun_ammo | 2026-11-18 | hp 400%>450%; tank 0.9>0.95; pis 5>6; smg 5>6; mg 5>6; rl 5>1; mel 7>6 | soldier-remap-20261118 |
| elite_mgun_asst | 2026-11-18 | hp 400%>450%; tank 0.9>0.95; pis 7>6; smg 7>6; mg 7>6; rl 7>1; mel 7>6 | soldier-remap-20261118 |
| elite_takasago_lmg | 2026-11-19 | sreg 125%>100% | pass8-remap-20261118 |
| elite_takasago_lmg | 2026-11-18 | hp 350%>400%; sta 225%>200%; tank 1>0.95; pis 6>5; smg 4>5; rif 4>5; rl 4>1; mel 6>5 | soldier-remap-20261118 |
| elite_takasago_mgun_ammo | 2026-11-19 | sreg 125%>100% | pass8-remap-20261118 |
| elite_takasago_mgun_ammo | 2026-11-18 | hp 350%>400%; sta 225%>200%; tank 1>0.95; pis 6>5; smg 4>5; mg 4>5; rl 4>1; mel 6>5 | soldier-remap-20261118 |
| elite_takasago_mgun_asst | 2026-11-19 | sreg 125%>100% | pass8-remap-20261118 |
| elite_takasago_mgun_asst | 2026-11-18 | hp 350%>400%; sta 225%>200%; tank 1>0.95; pis 6>5; smg 4>5; mg 6>5; rl 4>1; mel 6>5 | soldier-remap-20261118 |
| elite_takasago_rifle | 2026-11-19 | sreg 125%>100% | pass8-remap-20261118 |
| elite_takasago_rifle | 2026-11-18 | hp 350%>400%; sta 225%>200%; tank 1>0.95; pis 6>5; smg 4>5; mg 4>5; rl 4>1; mel 6>5 | soldier-remap-20261118 |
| elite_takasago_rifle2 | 2026-11-19 | sreg 125%>100% | pass8-remap-20261118 |
| elite_takasago_rifle2 | 2026-11-18 | hp 350%>400%; sta 225%>200%; tank 1>0.95; pis 6>5; smg 4>5; mg 4>5; rl 4>1; mel 6>5 | soldier-remap-20261118 |
| elite_takasago_smg | 2026-11-19 | sreg 125%>100% | pass8-remap-20261118 |
| elite_takasago_smg | 2026-11-18 | hp 350%>400%; sta 225%>200%; tank 1>0.95; pis 6>5; mg 4>5; rif 4>5; rl 4>1; mel 6>5 | soldier-remap-20261118 |
| elite_vehicle_supporter | 2026-11-18 | hp 150%>450%; sta 100%>200%; pis 2>3; smg 2>3; rif 5>3; mel 2>4 | crew-remap-20261118, held-remap-20261118 |
| elite2 | 2026-11-18 | hp 400%>450%; tank 0.9>0.95; pis 7>6; smg 7>6; mg 7>6; rl 7>1; mel 7>6 | soldier-remap-20261118 |
| elite3 | 2026-11-18 | hp 400%>450%; tank 0.9>0.95; pis 7>6; smg 7>6; rif 7>6; rl 7>1; mel 7>6 | soldier-remap-20261118 |
| elite4 | 2026-11-18 | hp 400%>450%; tank 0.9>0.95; pis 7>6; mg 7>6; rif 7>6; rl 7>1; mel 7>6 | soldier-remap-20261118 |
| flamer | 2026-11-18 | hp 150%>200%; tank 0.8>0.75; can 1>0.8 | held-remap-20261118 |
| flamer2 | 2026-11-18 | hp 150%>200%; tank 0.8>0.75; can 1>0.8 | soldier-remap-20261118 |
| ig_light_mortar | 2026-11-18 | tank 0.9>0.85; can 1>0.9; pis 3>4; rl 3>1; mel 5>4 | soldier-remap-20261118 |
| ig_light_mortar_asst | 2026-11-18 | tank 0.9>0.85; can 1>0.9; pis 3>4; rl 3>1; mel 5>4 | soldier-remap-20261118 |
| jap_ap_miner | 2026-11-18 | hp 150%>200%; tank 0.8>0.75; can 1>0.8 | soldier-remap-20261118 |
| jap_at_miner | 2026-11-18 | hp 150%>200%; tank 0.8>0.75; can 1>0.8 | soldier-remap-20261118 |
| jap_at_rifle | 2026-11-18 | sta 100%>75%; tank 0.8>0.75; can 1>0.8; pis 2>1; smg 2>1; rif 3>1 | crew-remap-20261118, soldier-remap-20261118 |
| jap_at_rifleassist | 2026-11-18 | sta 100%>75%; tank 0.8>0.75; can 1>0.8; pis 2>1; smg 2>1; rif 3>1 | soldier-remap-20261118 |
| jap_charger_rifle | 2026-11-18 | hp 250%>300%; tank 0.9>0.75; can 1>0.8 | charge-remap-20261118, charge2-remap-20261118, soldier-remap-20261118 |
| jap_charger_smg_type100 | 2026-11-18 | hp 250%>300%; tank 0.9>0.75; can 1>0.8 | charge-remap-20261118, charge2-remap-20261118, soldier-remap-20261118 |
| jap_charger_smg_type100_44 | 2026-11-18 | hp 250%>300%; tank 0.9>0.75; can 1>0.8 | charge-remap-20261118, charge2-remap-20261118, soldier-remap-20261118 |
| jap_charger_throwgun | 2026-11-18 | hp 250%>300%; tank 0.9>0.75; can 1>0.8 | charge-remap-20261118, charge2-remap-20261118, soldier-remap-20261118 |
| jap_elite_takasago_lmg | 2026-11-19 | sreg 125%>100% | pass8-remap-20261118 |
| jap_elite_takasago_lmg | 2026-11-18 | hp 350%>400%; sta 225%>200%; tank 1>0.95; pis 6>5; smg 4>5; rif 4>5; rl 4>1; mel 6>5 | soldier-remap-20261118 |
| jap_elite_takasago_rifle | 2026-11-19 | sreg 125%>100% | pass8-remap-20261118 |
| jap_elite_takasago_rifle | 2026-11-18 | hp 350%>400%; sta 225%>200%; tank 1>0.95; pis 6>5; smg 4>5; mg 4>5; rl 4>1; mel 6>5 | soldier-remap-20261118 |
| jap_elite_takasago_rifle2 | 2026-11-19 | sreg 125%>100% | pass8-remap-20261118 |
| jap_elite_takasago_rifle2 | 2026-11-18 | hp 350%>400%; sta 225%>200%; tank 1>0.95; pis 6>5; smg 4>5; mg 4>5; rl 4>1; mel 6>5 | soldier-remap-20261118 |
| jap_elite_takasago_smg2 | 2026-11-19 | sreg 125%>100% | pass8-remap-20261118 |
| jap_elite_takasago_smg2 | 2026-11-18 | hp 350%>400%; sta 225%>200%; tank 1>0.95; pis 6>5; mg 4>5; rif 4>5; rl 4>1; mel 6>5 | soldier-remap-20261118 |
| jap_flamer | 2026-11-18 | hp 150%>200%; tank 0.8>0.75; can 1>0.8 | held-remap-20261118 |
| jap_flamerassist | 2026-11-18 | hp 150%>200%; tank 0.8>0.75; can 1>0.8 | soldier-remap-20261118 |
| jap_kamikaze | 2026-11-18 | hp 300%>450%; sreg 150%>125%; tank 0.8>0.85; can 1>0.9; pis 2>5; smg 2>5; mg 1>5; rif 1>5; mel 2>7 | charge-remap-20261118, charge2-remap-20261118, charge3-remap-20261118, soldier-remap-20261118 |
| jap_kanoe_shidan_type38 | 2026-11-18 | tank 0.9>0.85; can 1>0.9; pis 3>4; rl 3>1; mel 5>4 | soldier-remap-20261118 |
| jap_kanoeshidan_at | 2026-11-18 | tank 0.9>0.85; can 1>0.9; pis 3>4; mel 5>4 | soldier-remap-20261118 |
| jap_kanoeshidan_mg | 2026-11-18 | tank 0.9>0.85; can 1>0.9; pis 3>4; rl 3>1; mel 5>4 | soldier-remap-20261118 |
| jap_kanoeshidan_rifle_apminer | 2026-11-18 | tank 0.9>0.85; can 1>0.9; smg 4>3; mg 4>3; rl 4>1; mel 6>4 | soldier-remap-20261118 |
| jap_kanoeshidan_type100_44 | 2026-11-18 | tank 0.9>0.85; can 1>0.9; pis 3>4; rl 3>1; mel 5>4 | soldier-remap-20261118 |
| jap_kanoeshidan_type38rifle | 2026-11-18 | tank 0.9>0.85; can 1>0.9; pis 3>4; rl 3>1; mel 5>4 | soldier-remap-20261118 |
| jap_kanoeshidan_type99rifle | 2026-11-18 | tank 0.9>0.85; can 1>0.9; pis 3>4; rl 3>1; mel 5>4 | soldier-remap-20261118 |
| jap_light_mortar | 2026-11-18 | hp 150%>200%; tank 0.8>0.75; can 1>0.8; smg 1>2; mg 1>2; mel 2>3 | soldier-remap-20261118 |
| jap_mg_asst | 2026-11-18 | hp 150%>200%; tank 0.8>0.75; can 1>0.8; smg 1>2; rif 3>2; mel 2>3 | soldier-remap-20261118 |
| jap_mg3_asst | 2026-11-18 | hp 150%>200%; tank 0.8>0.75; can 1>0.8; smg 1>2; rif 3>2; mel 2>3; inv: -ammo arisaka7-7_clip 200, -type99rifle filled, +ammo arisaka6-5_clip 200, +type38rifle filled | fixes-20261118b, soldier-remap-20261118 |
| jap_mgun | 2026-11-18 | hp 150%>200%; tank 0.8>0.75; can 1>0.8; pis 1>2; smg 1>2; rif 1>2; mel 2>3 | soldier-remap-20261118 |
| jap_mgun2 | 2026-11-18 | hp 150%>200%; tank 0.8>0.75; can 1>0.8; pis 1>2; smg 1>2; rif 1>2; mel 2>3 | soldier-remap-20261118 |
| jap_mgun3 | 2026-11-18 | hp 150%>200%; tank 0.8>0.75; can 1>0.8; pis 1>2; smg 1>2; rif 1>2; mel 2>3 | soldier-remap-20261118 |
| jap_officer | 2026-11-18 | hp 250%>200%; sta 150%>100%; spd 1>0.9; tank 1>0.75; can 1>0.8; rl 3>1 | soldier-remap-20261118 |
| jap_rifle | 2026-11-18 | hp 150%>200%; tank 0.8>0.75; can 1>0.8; smg 1>2; mg 1>2; mel 2>3 | soldier-remap-20261118 |
| jap_rifle_grenadier | 2026-11-18 | hp 150%>200%; tank 0.8>0.75; can 1>0.8; smg 1>2; mg 1>2; mel 2>3 | soldier-remap-20261118 |
| jap_rifle2 | 2026-11-18 | hp 150%>200%; tank 0.8>0.75; can 1>0.8; smg 1>2; mg 1>2; mel 2>3 | soldier-remap-20261118 |
| jap_rifle2b | 2026-11-18 | hp 150%>200%; tank 0.8>0.75; can 1>0.8; smg 1>2; mg 1>2; mel 2>3 | soldier-remap-20261118 |
| jap_rifleb | 2026-11-18 | hp 150%>200%; tank 0.8>0.75; can 1>0.8; smg 1>2; mg 1>2; mel 2>3 | soldier-remap-20261118 |
| jap_saper | 2026-11-18 | hp 250%>200%; tank 0.8>0.75; can 1>0.8 | soldier-remap-20261118 |
| jap_smg | 2026-11-18 | hp 150%>200%; tank 0.8>0.75; can 1>0.8; mg 1>2; rif 1>2; mel 2>3 | soldier-remap-20261118 |
| jap_smg2 | 2026-11-18 | hp 150%>200%; tank 0.8>0.75; can 1>0.8; mg 1>2; rif 1>2; mel 2>3 | soldier-remap-20261118 |
| jap_smg2b | 2026-11-18 | hp 150%>200%; tank 0.8>0.75; can 1>0.8; mg 1>2; rif 1>2; mel 2>3 | soldier-remap-20261118 |
| jap_smg3 | 2026-11-18 | hp 150%>200%; tank 0.8>0.75; can 1>0.8; mg 1>2; rif 1>2; mel 2>3 | soldier-remap-20261118 |
| jap_smgb | 2026-11-18 | hp 150%>200%; tank 0.8>0.75; can 1>0.8; mg 1>2; rif 1>2; mel 2>3 | soldier-remap-20261118 |
| jap_sniper_type97 | 2026-11-18 | hp 350%>300%; spd 1>0.9; tank 1>0.85; can 1>0.9; pis 2>4; smg 2>3; mg 1>3; mel 2>4 | held-remap-20261118 |
| jap_sniper_type99 | 2026-11-18 | hp 350%>300%; spd 1>0.9; tank 1>0.85; can 1>0.9; pis 2>4; smg 2>3; mg 1>3; mel 2>4 | held-remap-20261118 |
| jap_snlf_at | 2026-11-18 | hp 400%>450%; tank 1>0.95; pis 7>6; mg 7>6; rif 7>6; mel 7>6 | soldier-remap-20261118 |
| jap_snlf_at2 | 2026-11-18 | hp 400%>450%; tank 1>0.95; pis 7>6; mg 7>6; rif 7>6; mel 7>6 | soldier-remap-20261118 |
| jap_snlf_atassist | 2026-11-18 | hp 400%>450%; tank 1>0.95; pis 7>6; mg 7>6; rif 7>6; rl 7>1; mel 7>6 | soldier-remap-20261118 |
| jap_snlf_mg | 2026-11-18 | hp 400%>450%; tank 1>0.95; pis 7>6; smg 7>6; rif 7>6; rl 7>1; mel 7>6 | soldier-remap-20261118 |
| jap_snlf_mg_asst | 2026-11-18 | hp 400%>450%; tank 1>0.95; pis 5>6; smg 5>6; mg 5>7; rif 7>6; rl 5>1; mel 7>6 | soldier-remap-20261118 |
| jap_snlf_mg_type99 | 2026-11-18 | hp 400%>450%; tank 1>0.95; pis 7>6; smg 7>6; rif 7>6; rl 7>1; mel 7>6 | soldier-remap-20261118 |
| jap_snlf_rifle_type99 | 2026-11-18 | hp 400%>450%; tank 1>0.95; pis 5>6; smg 5>6; mg 5>6; rl 5>1; mel 7>6 | soldier-remap-20261118 |
| jap_snlf_type100_44 | 2026-11-18 | hp 400%>450%; tank 1>0.95; pis 7>6; mg 7>6; rif 7>6; rl 7>1; mel 7>6 | soldier-remap-20261118 |
| jap_squadleader | 2026-11-18 | tank 0.8>0.75; can 1>0.8; mg 3>2; rif 4>3; mel 3>4 | soldier-remap-20261118 |
| jap_squadleader2 | 2026-11-18 | tank 0.8>0.75; can 1>0.8; pis 3>4; mel 2>4 | soldier-remap-20261118 |
| jap_tankman_single | 2026-11-18 | hp 100%>200%; tank 1.1>1; veh 1.1>1; can 1.1>0.9; pis 2>4; smg 2>4; rif 1>3; mel 2>4 | crew-remap-20261118, held-remap-20261118 |
| jap_tankman2_single | 2026-11-18 | hp 150%>200%; tank 1.15>1.1; veh 1.15>1; can 1.15>0.95; pis 2>4; smg 2>4; mg 3>4; rif 1>3; mel 2>4 | crew-remap-20261118, held-remap-20261118 |
| jap_teishin_mg | 2026-11-18 | hp 400%>450%; tank 0.9>0.95; pis 5>6; smg 5>6; rif 7>6; rl 5>1; mel 7>6 | soldier-remap-20261118 |
| jap_teishin_type100_44_apminer | 2026-11-18 | hp 400%>450%; tank 0.9>0.95; pis 5>6; mg 5>6; rif 5>6; rl 5>1; mel 7>6 | soldier-remap-20261118 |
| jap_teishin_type2rifle | 2026-11-18 | hp 400%>450%; tank 0.9>0.95; pis 7>6; smg 7>6; mg 7>6; rl 7>1; mel 7>6 | soldier-remap-20261118 |
| jap_teishin_type2rifle_apminer | 2026-11-18 | hp 400%>450%; tank 0.9>0.95; pis 5>6; smg 5>6; mg 5>6; rl 5>1; mel 7>6 | soldier-remap-20261118 |
| jap_type4_atassist | 2026-11-18 | hp 150%>200%; tank 0.8>0.75; can 1>0.8; rl 3>2 | soldier-remap-20261118 |
| kamikaze | 2026-11-18 | hp 300%>450%; spd 1>1.1; tank 0.8>0.85; can 1>0.9; pis 2>5; smg 2>5; mg 1>5; rif 1>5; mel 2>7 | charge-remap-20261118, charge2-remap-20261118, charge3-remap-20261118, soldier-remap-20261118 |
| ki_at_grenade | 2026-11-18 | tank 0.9>0.85; can 1>0.9; pis 3>4; rl 3>1; mel 5>4 | soldier-remap-20261118 |
| ki_at_stick | 2026-11-18 | hp 300%>450%; sta 150%>200%; sreg 100%>125%; spd 0.9>1.1; tank 0.9>0.85; can 1>0.9; pis 3>5; smg 3>5; mg 3>5; rl 3>1; mel 5>7 | charge-remap-20261118, charge2-remap-20261118, soldier-remap-20261118 |
| ki_rifle | 2026-11-18 | tank 0.9>0.85; can 1>0.9; pis 3>4; rl 3>1; mel 3>4 | soldier-remap-20261118 |
| ki_sa | 2026-11-19 | inv: -molotov_coctail 2, +grenade molotov_coctail 2 | grenade-names-20261119 |
| ki_sa | 2026-11-18 | hp 300%>400%; sta 150%>200%; tank 0.9>0.95; pis 4>5; smg 4>5; mg 4>5; rl 4>1; mel 6>5; vet 24/60/108/168/240>60/132/216/312/420 | soldier-remap-20261118 |
| ki_sl | 2026-11-18 | hp 300%>400%; sta 150%>200%; tank 0.9>0.95; pis 4>5; smg 4>5; mg 4>5; rl 4>1; mel 6>5; vet 24/60/108/168/240>60/132/216/312/420 | soldier-remap-20261118 |
| ki_smoke | 2026-11-18 | tank 0.9>0.85; can 1>0.9; pis 3>4; rl 3>1; mel 3>4 | soldier-remap-20261118 |
| light_mortar | 2026-11-18 | hp 150%>200%; tank 0.8>0.75; can 1>0.8; smg 1>2; mg 1>2; mel 2>3 | soldier-remap-20261118 |
| light_mortar_asst | 2026-11-18 | hp 150%>200%; tank 0.8>0.75; can 1>0.8; smg 1>2; mg 1>2; mel 2>3 | soldier-remap-20261118 |
| mgun | 2026-11-18 | hp 150%>200%; tank 0.8>0.75; can 1>0.8; pis 1>2; smg 1>2; rif 1>2; mel 2>3 | soldier-remap-20261118 |
| mgun_ammo | 2026-11-18 | hp 150%>200%; tank 0.8>0.75; can 1>0.8; smg 1>2; mg 1>3; rif 3>2; mel 2>3 | soldier-remap-20261118 |
| mgun_asst | 2026-11-18 | hp 150%>200%; tank 0.8>0.75; can 1>0.8; smg 1>2; rif 3>2; mel 2>3 | soldier-remap-20261118 |
| mgun2 | 2026-11-18 | hp 150%>200%; tank 0.8>0.75; can 1>0.8; pis 1>2; smg 1>2; rif 1>2; mel 2>3 | soldier-remap-20261118 |
| mgun2_ammo | 2026-11-18 | hp 150%>200%; tank 0.8>0.75; can 1>0.8; smg 1>2; mg 1>3; rif 3>2; mel 2>3 | soldier-remap-20261118 |
| mgun2_asst | 2026-11-18 | hp 150%>200%; tank 0.8>0.75; can 1>0.8; smg 1>2; rif 3>2; mel 2>3 | soldier-remap-20261118 |
| mgun3 | 2026-11-18 | hp 150%>200%; tank 0.8>0.75; can 1>0.8; pis 1>2; smg 1>2; rif 1>2; mel 2>3 | soldier-remap-20261118 |
| mgun3_ammo | 2026-11-18 | breed removed | fixes-20261118b |
| mgun3_asst | 2026-11-18 | breed removed | fixes-20261118b |
| oficer | 2026-11-18 | hp 250%>200%; sta 150%>100%; spd 1>0.9; tank 1>0.75; can 1>0.8; rl 3>1 | soldier-remap-20261118 |
| otsu_mg | 2026-11-18 | hp 150%>200%; tank 0.8>0.75; can 1>0.8; pis 1>2; smg 1>2; rif 1>2; mel 2>3 | soldier-remap-20261118 |
| otsu_mg_ammo | 2026-11-18 | hp 150%>200%; tank 0.8>0.75; can 1>0.8; pis 1>2; smg 1>2; mg 1>2; mel 2>3 | soldier-remap-20261118 |
| otsu_mg_asst | 2026-11-18 | hp 150%>200%; tank 0.8>0.75; can 1>0.8; pis 1>2; smg 1>2; mg 3>2; mel 2>3 | soldier-remap-20261118 |
| otsu_rifle | 2026-11-18 | hp 150%>200%; tank 0.8>0.75; can 1>0.8; pis 1>2; smg 1>2; mg 1>2; mel 2>3 | soldier-remap-20261118 |
| otsu_sa | 2026-11-18 | hp 150%>200%; tank 0.8>0.75; can 1>0.8; pis 3>4; smg 2>3; rl 2>1; mel 3>4 | soldier-remap-20261118 |
| otsu_sl | 2026-11-18 | hp 150%>200%; tank 0.8>0.75; can 1>0.8; pis 3>4; smg 2>3; rl 2>1; mel 3>4 | soldier-remap-20261118 |
| rifle | 2026-11-18 | hp 150%>200%; tank 0.8>0.75; can 1>0.8; smg 1>2; mg 1>2; mel 2>3 | soldier-remap-20261118 |
| rifle2 | 2026-11-18 | hp 150%>200%; tank 0.8>0.75; can 1>0.8; pis 2>1 | soldier-remap-20261118 |
| rifle2b | 2026-11-18 | hp 150%>200%; tank 0.8>0.75; can 1>0.8; pis 2>1 | soldier-remap-20261118 |
| rifleb | 2026-11-18 | hp 150%>200%; tank 0.8>0.75; can 1>0.8; smg 1>2; mg 1>2; mel 2>3 | soldier-remap-20261118 |
| saper | 2026-11-18 | hp 250%>200%; tank 0.8>0.75; can 1>0.8 | soldier-remap-20261118 |
| smg | 2026-11-18 | hp 150%>200%; tank 0.8>0.75; can 1>0.8; mg 1>2; rif 1>2; mel 2>3 | soldier-remap-20261118 |
| smg2 | 2026-11-18 | hp 150%>200%; tank 0.8>0.75; can 1>0.8 | soldier-remap-20261118 |
| smg3 | 2026-11-18 | hp 150%>200%; tank 0.8>0.75; can 1>0.8 | soldier-remap-20261118 |
| sniper | 2026-11-18 | hp 350%>300%; spd 1>0.9; tank 1>0.85; can 1>0.9; pis 2>4; smg 2>3; mg 1>3; mel 2>4 | held-remap-20261118 |
| sniper2 | 2026-11-18 | hp 350%>300%; spd 1>0.9; tank 1>0.85; can 1>0.9; pis 2>4; smg 2>3; mg 1>3; mel 2>4 | held-remap-20261118 |
| squadleader | 2026-11-18 | tank 0.8>0.75; can 1>0.8; mg 3>2; rif 4>3; mel 3>4 | soldier-remap-20261118 |
| squadleader2 | 2026-11-18 | tank 0.8>0.75; can 1>0.8; pis 3>2; rif 3>2; mel 2>3 | soldier-remap-20261118 |
| sturmovik | 2026-11-18 | hp 400%>450%; tank 1>0.95; pis 7>6; mg 7>6; rif 7>6; rl 7>1; mel 7>6 | soldier-remap-20261118 |
| sturmovik2 | 2026-11-18 | hp 400%>450%; tank 1>0.95; pis 7>6; smg 7>6; rif 7>6; rl 7>1; mel 7>6 | soldier-remap-20261118 |
| sturmovik3 | 2026-11-18 | hp 400%>450%; tank 1>0.95; pis 7>6; mg 7>6; rif 7>6; mel 7>6 | soldier-remap-20261118 |
| sturmovik4 | 2026-11-18 | hp 400%>450%; tank 1>0.95; pis 7>6; smg 7>6; mg 7>6; rl 7>1; mel 7>6 | soldier-remap-20261118 |
| sturmovik6 | 2026-11-18 | hp 400%>450%; tank 1>0.95; pis 7>6; smg 7>6; rif 7>6; rl 7>1; mel 7>6 | soldier-remap-20261118 |
| sturmovik6b | 2026-11-18 | hp 400%>450%; tank 1>0.95; pis 7>6; smg 7>6; mg 7>6; rl 7>1; mel 7>6 | soldier-remap-20261118 |
| super_officer | 2026-11-18 | hp 250%>200%; sta 150%>100%; spd 1>0.9; tank 1>0.75; can 1>0.8; rl 3>1 | soldier-remap-20261118 |
| tankman | 2026-11-18 | hp 100%>200%; tank 1.1>1; veh 1.1>1; can 1.1>0.9; pis 2>4; smg 2>4; rif 1>3; mel 2>4 | crew-remap-20261118, held-remap-20261118 |
| tankman2 | 2026-11-18 | hp 150%>200%; tank 1.15>1.1; veh 1.15>1; can 1.15>0.95; pis 2>4; smg 2>4; mg 3>4; rif 1>3; mel 2>4 | crew-remap-20261118, held-remap-20261118 |
| teishin_type97_atr | 2026-11-18 | hp 400%>450%; tank 0.9>0.95; pis 7>6; smg 7>6; mg 7>6; rl 7>1; mel 7>6; vet 24/60/108/168/240>60/132/216/312/420 | soldier-remap-20261118 |
| teishin_type97_atr_asst | 2026-11-18 | hp 400%>450%; tank 0.9>0.95; pis 7>6; smg 7>6; rif 7>6; rl 7>1; mel 7>6; vet 24/60/108/168/240>60/132/216/312/420 | soldier-remap-20261118 |
| vehicle_supporter | 2026-11-18 | hp 150%>200%; tank 1>0.85; mg 3>4; mel 2>4 | crew-remap-20261118, held-remap-20261118 |
| vehicle_supporter_single | 2026-11-18 | hp 150%>200%; tank 1>0.85; mg 3>4; mel 2>4 | crew-remap-20261118, held-remap-20261118 |

#### Breeds: rus (100 rows)

| Breed | Date | Changes (old>new) | Undo tag |
|---|---|---|---|
| at_rifle | 2026-11-18 | mg 1>2; mel 2>3 | held-remap-20261118 |
| at_rifle2 | 2026-11-18 | smg 2>3; mg 1>2; rif 3>2; mel 2>3 | soldier-remap-20261118 |
| bazooker | 2026-11-18 | mg 1>2; rif 1>3; mel 2>3 | soldier-remap-20261118 |
| bazooker2 | 2026-11-18 | smg 2>3; mg 1>2; rif 1>2; rl 3>1; mel 2>3 | soldier-remap-20261118 |
| elite | 2026-11-18 | hp 200%>150%; sta 150%>100%; tank 0.85>0.75; can 0.9>0.8; pis 3>4; mg 3>2; rl 3>1; mel 3>4 | soldier-remap-20261118 |
| elite_40 | 2026-11-18 | hp 200%>150%; sta 150%>100%; tank 0.85>0.75; can 0.9>0.8; pis 3>4; mg 3>2; rl 3>1; mel 3>4 | soldier-remap-20261118 |
| elite_mg_asst | 2026-11-18 | hp 200%>150%; sta 150%>100%; tank 0.85>0.75; can 0.9>0.8; pis 3>4; rif 4>3; rl 3>1; mel 3>4 | soldier-remap-20261118 |
| elite2 | 2026-11-18 | hp 200%>150%; sta 150%>100%; tank 0.85>0.75; can 0.9>0.8; pis 3>4; mg 3>2; rl 3>1; mel 3>4 | soldier-remap-20261118 |
| elite2_40 | 2026-11-18 | hp 200%>150%; sta 150%>100%; tank 0.85>0.75; can 0.9>0.8; pis 3>4; mg 3>2; rl 3>1; mel 3>4 | soldier-remap-20261118 |
| elite3 | 2026-11-18 | hp 200%>150%; sta 150%>100%; tank 0.85>0.75; can 0.9>0.8; pis 3>4; rl 3>1; mel 3>4 | soldier-remap-20261118 |
| elite3_40 | 2026-11-18 | hp 200%>150%; sta 150%>100%; tank 0.85>0.75; can 0.9>0.8; pis 3>4; rl 3>1; mel 3>4 | soldier-remap-20261118 |
| flamer | 2026-11-18 | rif 2>1 | held-remap-20261118 |
| flamer2 | 2026-11-18 | rif 2>1 | soldier-remap-20261118 |
| flamer3 | 2026-11-18 | pis 2>4; smg 3>4; mg 1>2; mel 3>4 | held-remap-20261118 |
| home_guard | 2026-11-18 | veh 0.8>1 | soldier-remap-20261118 |
| home_guard_mg | 2026-11-18 | veh 0.8>1 | soldier-remap-20261118 |
| home_guard2 | 2026-11-18 | veh 0.8>1 | soldier-remap-20261118 |
| home_guard3 | 2026-11-18 | veh 0.8>1 | soldier-remap-20261118 |
| mgun_41 | 2026-11-18 | pis 1>2 | soldier-remap-20261118 |
| mgun_asst_41 | 2026-11-18 | rif 2>1 | soldier-remap-20261118 |
| oficer | 2026-11-18 | hp 250%>150%; sta 150%>100%; spd 1>0.9; tank 0.85>0.75; can 0.9>0.8; rl 3>1 | soldier-remap-20261118 |
| rifle_41 | 2026-11-18 | pis 2>1 | soldier-remap-20261118 |
| rifle_sa | 2026-11-18 | smg 1>2; mg 1>2; mel 2>3 | soldier-remap-20261118 |
| rifle3 | 2026-11-18 | pis 2>1 | soldier-remap-20261118 |
| rus_at_rifle | 2026-11-18 | mg 1>2; mel 2>3 | held-remap-20261118 |
| rus_at_rifleassist | 2026-11-18 | mg 1>2; mel 2>3 | soldier-remap-20261118 |
| rus_bazooker | 2026-11-18 | mg 1>2; rif 1>3; mel 2>3 | soldier-remap-20261118 |
| rus_bazookerassist | 2026-11-18 | mg 1>2; rif 1>3; rl 3>1; mel 2>3 | soldier-remap-20261118 |
| rus_bsf_marine | 2026-11-18 | tank 0.85>0.95; can 0.9>1; rl 5>1; vet 24/60/108/168/240>60/132/216/312/420 | soldier-remap-20261118 |
| rus_bsf_marine_mg_asst | 2026-11-18 | tank 0.85>0.95; can 0.9>1; rif 6>5; rl 5>1; vet 24/60/108/168/240>60/132/216/312/420 | soldier-remap-20261118 |
| rus_bsf_marine2 | 2026-11-18 | tank 0.85>0.95; can 0.9>1; rl 5>1; vet 24/60/108/168/240>60/132/216/312/420 | soldier-remap-20261118 |
| rus_bsf_marine3 | 2026-11-18 | tank 0.85>0.95; can 0.9>1; rl 5>1; vet 24/60/108/168/240>60/132/216/312/420 | soldier-remap-20261118 |
| rus_elite_tankcommander | 2026-11-18 | spd 1>0.8; pis 4>5; mg 7>6; rl 3>1 | crew-remap-20261118, held-remap-20261118 |
| rus_elite_tankman | 2026-11-18 | spd 1>0.8; can 1.05>1; pis 3>5; smg 3>5; rl 3>1; mel 3>4; tg 8>7 | crew-remap-20261118, held-remap-20261118 |
| rus_flamer | 2026-11-18 | rif 2>1 | held-remap-20261118 |
| rus_flamerassist | 2026-11-18 | rif 2>1 | soldier-remap-20261118 |
| rus_marine_mg | 2026-11-18 | hp 200%>150%; sta 150%>100%; tank 0.85>0.75; can 0.9>0.8; pis 3>4; rl 3>1; mel 3>4 | soldier-remap-20261118 |
| rus_marine_mgassist | 2026-11-18 | hp 200%>150%; sta 150%>100%; tank 0.85>0.75; can 0.9>0.8; pis 3>4; rif 4>3; rl 3>1; mel 3>4 | soldier-remap-20261118 |
| rus_marine_rifle | 2026-11-18 | hp 200%>150%; sta 150%>100%; tank 0.85>0.75; can 0.9>0.8; pis 3>4; mg 3>2; rl 3>1; mel 3>4 | soldier-remap-20261118 |
| rus_marine_svt | 2026-11-18 | hp 200%>150%; sta 150%>100%; tank 0.85>0.75; can 0.9>0.8; pis 3>4; mg 3>2; rl 3>1; mel 3>4 | soldier-remap-20261118 |
| rus_mgun_asst | 2026-11-18 | smg 1>2; rif 3>2 | soldier-remap-20261118 |
| rus_officer | 2026-11-18 | hp 250%>150%; sta 150%>100%; spd 1>0.9; tank 0.85>0.75; can 0.9>0.8; rl 3>1 | soldier-remap-20261118 |
| rus_para_mg | 2026-11-18 | tank 0.75>0.95; can 0.8>1; pis 7>6; smg 7>6; rif 7>6; rl 7>1; mel 7>6 | soldier-remap-20261118 |
| rus_para_mg_asst | 2026-11-18 | tank 0.75>0.95; can 0.8>1; pis 7>6; smg 7>6; mg 7>6; rl 7>1; mel 7>6 | soldier-remap-20261118 |
| rus_para_rifle | 2026-11-18 | tank 0.75>0.95; can 0.8>1; pis 7>6; smg 7>6; mg 7>6; rl 7>1; mel 7>6 | soldier-remap-20261118 |
| rus_para_sa | 2026-11-18 | tank 0.75>0.95; can 0.8>1; pis 7>6; smg 7>6; mg 7>6; rl 7>1; mel 7>6 | soldier-remap-20261118 |
| rus_para_sl | 2026-11-18 | tank 0.75>0.95; can 0.8>1; pis 7>6; mg 7>6; rif 7>6; rl 7>1; mel 7>6 | soldier-remap-20261118 |
| rus_para_smg3 | 2026-11-18 | tank 0.75>0.95; can 0.8>1; pis 7>6; mg 7>6; rif 7>6; rl 7>1; mel 7>6 | soldier-remap-20261118 |
| rus_partisan_at | 2026-11-18 | veh 0.8>1 | soldier-remap-20261118 |
| rus_partisan_mg | 2026-11-18 | veh 0.8>1 | soldier-remap-20261118 |
| rus_partisan_mp38 | 2026-11-18 | veh 0.8>1 | soldier-remap-20261118 |
| rus_partisan_rifle | 2026-11-18 | veh 0.8>1 | soldier-remap-20261118 |
| rus_partisan_smg | 2026-11-18 | veh 0.8>1 | soldier-remap-20261118 |
| rus_rifle | 2026-11-18 | smg 1>2; mg 1>2 | soldier-remap-20261118 |
| rus_rifle_sa | 2026-11-18 | smg 1>2; mg 1>2; mel 2>3 | soldier-remap-20261118 |
| rus_saper | 2026-11-18 | tank 0.85>0.75; can 0.9>0.8 | soldier-remap-20261118 |
| rus_sapper_rifle1 | 2026-11-18 | tank 0.85>0.75; can 0.9>0.8; smg 1>2; mg 1>2; rl 2>1; mel 2>3 | soldier-remap-20261118 |
| rus_sapper_rifle2 | 2026-11-18 | tank 0.85>0.75; can 0.9>0.8; smg 1>2; mg 1>2; rl 2>1; mel 2>3 | soldier-remap-20261118 |
| rus_sapper_rifle3 | 2026-11-18 | tank 0.85>0.75; can 0.9>0.8; smg 1>2; mg 1>2; rl 2>1; mel 2>3 | soldier-remap-20261118 |
| rus_sapper_rifle4 | 2026-11-18 | tank 0.85>0.75; can 0.9>0.8; smg 1>2; mg 1>2; rl 2>1; mel 2>3 | soldier-remap-20261118 |
| rus_sapper_sl | 2026-11-18 | tank 0.85>0.75; can 0.9>0.8; pis 2>4; rif 2>3; rl 2>1; mel 3>4 | soldier-remap-20261118 |
| rus_sapper_smg | 2026-11-18 | tank 0.85>0.75; can 0.9>0.8; mg 1>2; rif 1>2; rl 2>1; mel 2>3 | soldier-remap-20261118 |
| rus_sapper_smg2 | 2026-11-18 | tank 0.85>0.75; can 0.9>0.8; mg 1>2; rif 1>2; rl 2>1; mel 2>3 | soldier-remap-20261118 |
| rus_shock_flame | 2026-11-18 | hp 200%>150%; sta 150%>100%; pis 3>4; rif 2>3; rl 2>1; mel 3>4 | held-remap-20261118 |
| rus_shock_mg | 2026-11-18 | hp 200%>150%; sta 150%>100%; pis 3>4; smg 2>3; rif 2>3; rl 2>1; mel 3>4 | soldier-remap-20261118 |
| rus_shock_mg_asst | 2026-11-18 | hp 200%>150%; sta 150%>100%; pis 3>4; smg 2>3; rif 4>3; rl 2>1; mel 3>4 | soldier-remap-20261118 |
| rus_shock_rifle | 2026-11-18 | hp 200%>150%; sta 150%>100%; pis 3>4; smg 2>3; rl 2>1; mel 3>4 | soldier-remap-20261118 |
| rus_shock_sa | 2026-11-18 | hp 200%>150%; sta 150%>100%; pis 3>4; smg 2>3; rl 2>1; mel 3>4 | soldier-remap-20261118 |
| rus_shock_sl | 2026-11-18 | tank 0.75>0.85; can 0.8>0.9; rif 4>5; rl 3>1 | soldier-remap-20261118 |
| rus_shock_sl_smg | 2026-11-18 | tank 0.75>0.85; can 0.8>0.9; pis 3>4; smg 4>5; mg 2>3; rif 2>3; rl 2>1; mel 3>4 | soldier-remap-20261118 |
| rus_shock_smg | 2026-11-18 | hp 200%>150%; sta 150%>100%; pis 3>4; rif 2>3; rl 2>1; mel 3>4 | soldier-remap-20261118 |
| rus_shock_smg2 | 2026-11-18 | hp 200%>150%; sta 150%>100%; pis 3>4; rif 2>3; rl 2>1; mel 3>4 | soldier-remap-20261118 |
| rus_shock_smg3 | 2026-11-18 | hp 200%>150%; sta 150%>100%; pis 3>4; rif 2>3; rl 2>1; mel 3>4 | soldier-remap-20261118 |
| rus_smg | 2026-11-18 | mg 1>2; rif 1>2 | soldier-remap-20261118 |
| rus_smg2 | 2026-11-18 | mg 1>2; rif 1>2 | soldier-remap-20261118 |
| rus_smg2_43 | 2026-11-18 | mg 1>2; rif 1>2 | soldier-remap-20261118 |
| rus_sniper_mosin | 2026-11-18 | hp 350%>200%; spd 1>0.9; tank 0.75>0.85; can 0.8>0.9; pis 2>4; smg 2>3; mg 1>3; mel 2>4 | held-remap-20261118 |
| rus_sniper_svtscoped | 2026-11-18 | hp 350%>200%; spd 1>0.9; tank 0.75>0.85; can 0.8>0.9; pis 2>4; smg 2>3; mg 1>3; mel 2>4 | soldier-remap-20261118 |
| rus_squadleader_smg | 2026-11-18 | hp 200%>150%; tank 0.85>0.75; can 0.9>0.8; mg 3>2; rif 4>3; rl 2>1; mel 3>4 | soldier-remap-20261118 |
| rus_squadleader2_43 | 2026-11-18 | hp 200%>150%; tank 0.85>0.75; can 0.9>0.8; mg 3>2; rif 4>3; rl 2>1; mel 3>4 | soldier-remap-20261118 |
| rus_tankman_single | 2026-11-18 | hp 100%>150%; tank 1.1>1; veh 1.1>1; pis 3>4; smg 3>4; rif 1>3; mel 2>4 | crew-remap-20261118, held-remap-20261118 |
| rus_tankman2_single | 2026-11-18 | tank 1.2>1.1; veh 1.1>1; pis 3>4; smg 3>4; mg 3>4; rif 1>3; mel 2>4 | crew-remap-20261118, held-remap-20261118 |
| rus_vet_tankman2_single | 2026-11-18 | hp 150%>200%; sta 100%>150%; tank 1.1>1.15; veh 1>1.15; can 0.95>1; pis 4>5; smg 4>5; rif 1>3; mel 2>4 | crew-remap-20261118, held-remap-20261118 |
| rus_vetsniper | 2026-11-18 | sta 150%>200%; spd 1>0.9; tank 0.85>0.95; can 0.9>1; pis 4>5; smg 4>5; mg 4>5; rl 4>1; mel 4>5; vet 24/60/108/168/240>60/132/216/312/420 | held-remap-20261118 |
| saper | 2026-11-18 | tank 0.85>0.75; can 0.9>0.8 | soldier-remap-20261118 |
| smg2 | 2026-11-18 | smg 3>2; mel 3>2 | soldier-remap-20261118 |
| smg3 | 2026-11-18 | hp 250%>150%; pis 3>4; rif 2>3; rl 2>1; mel 3>4 | soldier-remap-20261118 |
| sniper | 2026-11-18 | hp 350%>200%; spd 1>0.9; tank 0.75>0.85; can 0.8>0.9; pis 2>4; smg 2>3; mg 1>3; mel 2>4 | held-remap-20261118 |
| sniper2 | 2026-11-18 | sta 150%>200%; spd 1>0.9; tank 0.85>0.95; can 0.9>1; pis 4>5; smg 4>5; mg 4>5; rl 4>1; mel 4>5; vet 24/60/108/168/240>60/132/216/312/420 | held-remap-20261118 |
| sniper3 | 2026-11-18 | hp 350%>200%; spd 1>0.9; tank 0.75>0.85; can 0.8>0.9; pis 2>4; smg 2>3; mg 1>3; mel 2>4 | soldier-remap-20261118 |
| squadleader_41 | 2026-11-18 | hp 200%>150%; tank 0.85>0.75; can 0.9>0.8; pis 3>2; smg 3>2; mel 2>3 | soldier-remap-20261118 |
| tankman | 2026-11-18 | hp 100%>150%; tank 1.1>1; veh 1.1>1; pis 3>4; smg 3>4; rif 1>3; mel 2>4 | crew-remap-20261118, held-remap-20261118 |
| tankman_41 | 2026-11-18 | hp 100%>150%; pis 2>4; smg 2>4; rif 1>3; mel 2>4 | crew-remap-20261118, held-remap-20261118 |
| tankman2 | 2026-11-18 | tank 1.2>1.1; veh 1.1>1; pis 3>4; smg 3>4; mg 3>4; rif 1>3; mel 2>4 | crew-remap-20261118, held-remap-20261118 |
| tankman2_41 | 2026-11-18 | pis 2>4; smg 2>4; mg 2>4; rif 1>3; mel 2>4; tg 3>4 | crew-remap-20261118, held-remap-20261118 |
| vehicle_supporter | 2026-11-18 | mg 3>4; rl 2>1; mel 3>4 | crew-remap-20261118, held-remap-20261118 |
| vehicle_supporter_41 | 2026-11-18 | mg 2>4; rif 1>2; mel 2>4; tg 3>4 | crew-remap-20261118, held-remap-20261118 |
| vehicle_supporter_single | 2026-11-18 | mg 3>4; rl 2>1; mel 3>4 | crew-remap-20261118, held-remap-20261118 |
| vet_tankman | 2026-11-18 | sta 100%>150%; spd 0.9>0.8; tank 1>1.1; can 0.9>0.95; pis 5>4; smg 5>4; mg 5>4; rif 5>3; rl 5>1; mel 5>4; tg 5>4 | crew-remap-20261118, held-remap-20261118 |
| vet_tankman2 | 2026-11-18 | hp 150%>200%; sta 100%>150%; tank 1.1>1.15; veh 1>1.15; can 0.95>1; pis 4>5; smg 4>5; rif 1>3; mel 2>4 | crew-remap-20261118, held-remap-20261118 |

#### Breeds: rus_guard (69 rows)

| Breed | Date | Changes (old>new) | Undo tag |
|---|---|---|---|
| elite_tankman | 2026-11-18 | spd 1>0.8; can 1.05>1; pis 3>5; smg 3>5; rl 3>1; mel 3>4; tg 8>7 | crew-remap-20261118, held-remap-20261118 |
| elite_tankman2 | 2026-11-18 | spd 1>0.8; pis 4>5; mg 7>6; rl 3>1 | crew-remap-20261118, held-remap-20261118 |
| guard_at_rifle | 2026-11-18 | mg 1>2; mel 2>3 | held-remap-20261118 |
| guard_at_rifleassist | 2026-11-18 | mg 1>2; mel 2>3 | soldier-remap-20261118 |
| guard_bazooker | 2026-11-18 | mg 1>2; rif 1>3; mel 2>3 | soldier-remap-20261118 |
| guard_bazookerassist | 2026-11-18 | mg 1>2; rif 1>3; rl 3>1; mel 2>3 | soldier-remap-20261118 |
| guard_elite_guard_mg | 2026-11-18 | hp 200%>150%; tank 0.85>0.75; can 0.9>0.8; smg 1>2; rif 3>2 | soldier-remap-20261118 |
| guard_elite_guard_mg_asst | 2026-11-18 | hp 200%>150%; tank 0.85>0.75; can 0.9>0.8; smg 1>2; rif 3>2 | soldier-remap-20261118 |
| guard_elite_guard_rifle | 2026-11-18 | hp 200%>150%; tank 0.85>0.75; can 0.9>0.8; smg 1>2; mg 1>2 | soldier-remap-20261118 |
| guard_elite_guard_sa | 2026-11-18 | hp 200%>150%; tank 0.85>0.75; can 0.9>0.8; smg 1>2; mg 1>2 | soldier-remap-20261118 |
| guard_elite_guard_sl | 2026-11-18 | hp 250%>150%; sta 125%>100%; tank 0.85>0.75; can 0.9>0.8; pis 2>4; smg 3>4; rl 2>1; mel 3>4 | soldier-remap-20261118 |
| guard_elite_guard_smg | 2026-11-18 | hp 200%>150%; tank 0.85>0.75; can 0.9>0.8; mg 1>2; rif 1>2 | soldier-remap-20261118 |
| guard_elite_guard_smg2 | 2026-11-18 | hp 200%>150%; tank 0.85>0.75; can 0.9>0.8; mg 1>2; rif 1>2 | soldier-remap-20261118 |
| guard_elite_guards_shock_flame | 2026-11-18 | hp 250%>150%; sta 150%>100%; pis 3>4; rif 2>3; rl 2>1; mel 3>4 | held-remap-20261118 |
| guard_elite_guards_shock_mg | 2026-11-18 | hp 250%>150%; sta 150%>100%; pis 3>4; smg 2>3; rif 2>3; rl 2>1; mel 3>4 | soldier-remap-20261118 |
| guard_elite_guards_shock_mg_asst | 2026-11-18 | hp 250%>150%; sta 150%>100%; pis 3>4; smg 2>3; rif 4>3; rl 2>1; mel 3>4 | soldier-remap-20261118 |
| guard_elite_guards_shock_mg2 | 2026-11-18 | hp 250%>150%; sta 150%>100%; pis 3>4; smg 2>3; rif 2>3; rl 2>1; mel 3>4 | soldier-remap-20261118 |
| guard_elite_guards_shock_mg2_asst | 2026-11-18 | hp 250%>150%; sta 150%>100%; pis 3>4; smg 2>3; rif 4>3; rl 2>1; mel 3>4 | soldier-remap-20261118 |
| guard_elite_guards_shock_rifle | 2026-11-18 | hp 250%>150%; sta 150%>100%; pis 3>4; smg 2>3; rl 2>1; mel 3>4 | soldier-remap-20261118 |
| guard_elite_guards_shock_sa | 2026-11-18 | hp 250%>150%; sta 150%>100%; pis 3>4; smg 2>3; rl 2>1; mel 3>4 | soldier-remap-20261118 |
| guard_elite_guards_shock_sl | 2026-11-18 | hp 250%>200%; tank 0.75>0.85; can 0.8>0.9; rif 4>5; rl 3>1 | soldier-remap-20261118 |
| guard_elite_guards_shock_sl_smg | 2026-11-18 | hp 250%>200%; tank 0.75>0.85; can 0.8>0.9; pis 3>4; smg 4>5; mg 2>3; rif 2>3; rl 2>1; mel 3>4 | soldier-remap-20261118 |
| guard_elite_guards_shock_smg2 | 2026-11-18 | hp 250%>150%; sta 150%>100%; pis 3>4; rif 2>3; rl 2>1; mel 3>4 | soldier-remap-20261118 |
| guard_elite_guards_shock_smg3 | 2026-11-18 | hp 250%>150%; sta 150%>100%; pis 3>4; rif 2>3; rl 2>1; mel 3>4 | soldier-remap-20261118 |
| guard_elite_tankcommander | 2026-11-18 | spd 1>0.8; pis 4>5; mg 7>6; rl 3>1 | crew-remap-20261118, held-remap-20261118 |
| guard_elite_tankman | 2026-11-18 | spd 1>0.8; can 1.05>1; pis 3>5; smg 3>5; rl 3>1; mel 3>4; tg 8>7 | crew-remap-20261118, held-remap-20261118 |
| guard_mg | 2026-11-18 | hp 200%>150%; tank 0.85>0.75; can 0.9>0.8; smg 1>2; rif 3>2 | soldier-remap-20261118 |
| guard_mg_asst | 2026-11-18 | hp 200%>150%; tank 0.85>0.75; can 0.9>0.8; smg 1>2; rif 3>2 | soldier-remap-20261118 |
| guard_officer | 2026-11-18 | hp 250%>150%; sta 150%>100%; spd 1>0.9; tank 0.85>0.75; can 0.9>0.8; rl 3>1 | soldier-remap-20261118 |
| guard_piat | 2026-11-18 | mg 1>2; rif 1>3; mel 2>3 | soldier-remap-20261118 |
| guard_piatassist | 2026-11-18 | mg 1>2; rif 1>3; rl 3>1; mel 2>3 | soldier-remap-20261118 |
| guard_recon_rifle | 2026-11-18 | tank 0.85>0.75; can 0.9>0.8; smg 1>2; mg 1>2 | soldier-remap-20261118 |
| guard_recon_sl | 2026-11-18 | tank 0.85>0.75; can 0.9>0.8; pis 3>4; rif 2>3; rl 2>1 | soldier-remap-20261118 |
| guard_recon_smg | 2026-11-18 | tank 0.85>0.75; can 0.9>0.8; mg 1>2; rif 1>2 | soldier-remap-20261118 |
| guard_recon_smg2 | 2026-11-18 | tank 0.85>0.75; can 0.9>0.8; mg 1>2; rif 1>2 | soldier-remap-20261118 |
| guard_rifle | 2026-11-18 | hp 200%>150%; tank 0.85>0.75; can 0.9>0.8; smg 1>2; mg 1>2 | soldier-remap-20261118 |
| guard_sa | 2026-11-18 | hp 200%>150%; tank 0.85>0.75; can 0.9>0.8; smg 1>2; mg 1>2 | soldier-remap-20261118 |
| guard_sapper_rifle1 | 2026-11-18 | tank 0.85>0.75; can 0.9>0.8; smg 1>2; mg 1>2; rl 2>1; mel 2>3 | soldier-remap-20261118 |
| guard_sapper_rifle2 | 2026-11-18 | tank 0.85>0.75; can 0.9>0.8; smg 1>2; mg 1>2; rl 2>1; mel 2>3 | soldier-remap-20261118 |
| guard_sapper_rifle3 | 2026-11-18 | tank 0.85>0.75; can 0.9>0.8; smg 1>2; mg 1>2; rl 2>1; mel 2>3 | soldier-remap-20261118 |
| guard_sapper_rifle4 | 2026-11-18 | tank 0.85>0.75; can 0.9>0.8; smg 1>2; mg 1>2; rl 2>1; mel 2>3 | soldier-remap-20261118 |
| guard_sapper_rifle5 | 2026-11-18 | tank 0.85>0.75; can 0.9>0.8; smg 1>2; mg 1>2; rl 2>1; mel 2>3 | soldier-remap-20261118 |
| guard_sapper_sl | 2026-11-18 | tank 0.85>0.75; can 0.9>0.8; pis 2>4; rif 2>3; rl 2>1; mel 3>4 | soldier-remap-20261118 |
| guard_sapper_smg | 2026-11-18 | tank 0.85>0.75; can 0.9>0.8; mg 1>2; rif 1>2; rl 2>1; mel 2>3 | soldier-remap-20261118 |
| guard_sapper_smg2 | 2026-11-18 | tank 0.85>0.75; can 0.9>0.8; mg 1>2; rif 1>2; rl 2>1; mel 2>3 | soldier-remap-20261118 |
| guard_sl | 2026-11-18 | hp 250%>150%; sta 125%>100%; tank 0.85>0.75; can 0.9>0.8; pis 2>4; smg 3>4; rl 2>1; mel 3>4 | soldier-remap-20261118 |
| guard_smg | 2026-11-18 | hp 200%>150%; tank 0.85>0.75; can 0.9>0.8; mg 1>2; rif 1>2 | soldier-remap-20261118 |
| guard_smg2 | 2026-11-18 | hp 200%>150%; tank 0.85>0.75; can 0.9>0.8; mg 1>2; rif 1>2 | soldier-remap-20261118 |
| guard_sniper_elite | 2026-11-18 | hp 350%>150%; sta 150%>100%; spd 1>0.9; tank 0.85>0.75; can 0.9>0.8; pis 2>4; smg 2>3; rl 2>1 | held-remap-20261118 |
| guard_sniper_mosin | 2026-11-18 | hp 350%>150%; sta 150%>100%; spd 1>0.9; pis 2>4; smg 2>3; mg 1>2; mel 2>4 | held-remap-20261118 |
| guard_sniper_svtscope | 2026-11-18 | hp 350%>150%; sta 150%>100%; spd 1>0.9; pis 2>4; smg 2>3; mg 1>2; mel 2>4 | soldier-remap-20261118 |
| guards_shock_flame | 2026-11-18 | hp 250%>150%; sta 150%>100%; pis 3>4; rif 2>3; rl 2>1; mel 3>4 | held-remap-20261118 |
| guards_shock_mg | 2026-11-18 | hp 250%>150%; sta 150%>100%; pis 3>4; smg 2>3; rif 2>3; rl 2>1; mel 3>4 | soldier-remap-20261118 |
| guards_shock_mg_asst | 2026-11-18 | hp 250%>150%; sta 150%>100%; pis 3>4; smg 2>3; rif 4>3; rl 2>1; mel 3>4 | soldier-remap-20261118 |
| guards_shock_rifle | 2026-11-18 | hp 250%>150%; sta 150%>100%; pis 3>4; smg 2>3; rl 2>1; mel 3>4 | soldier-remap-20261118 |
| guards_shock_sa | 2026-11-18 | hp 250%>150%; sta 150%>100%; pis 3>4; smg 2>3; rl 2>1; mel 3>4 | soldier-remap-20261118 |
| guards_shock_sl | 2026-11-18 | hp 250%>200%; tank 0.75>0.85; can 0.8>0.9; rif 4>5; rl 3>1 | soldier-remap-20261118 |
| guards_shock_sl_smg | 2026-11-18 | hp 250%>200%; tank 0.75>0.85; can 0.8>0.9; pis 3>4; smg 4>5; mg 2>3; rif 2>3; rl 2>1; mel 3>4 | soldier-remap-20261118 |
| guards_shock_smg2 | 2026-11-18 | hp 250%>150%; sta 150%>100%; pis 3>4; rif 2>3; rl 2>1; mel 3>4 | soldier-remap-20261118 |
| guards_shock_smg3 | 2026-11-18 | hp 250%>150%; sta 150%>100%; pis 3>4; rif 2>3; rl 2>1; mel 3>4 | soldier-remap-20261118 |
| rus_guard_tankman_single | 2026-11-18 | spd 0.9>0.8; can 1>0.9; pis 5>4; smg 5>4; mg 3>2; rif 2>3; rl 2>1; mel 5>4; tg 3>2 | crew-remap-20261118, held-remap-20261118 |
| rus_guard_tankman2_single | 2026-11-18 | spd 0.9>0.8; can 1>0.95; pis 5>4; smg 5>4; mg 5>4; rif 5>3; rl 4>1; mel 5>4; tg 5>4 | crew-remap-20261118, held-remap-20261118 |
| rus_guard_vet_tankman2_single | 2026-11-18 | sta 100%>150%; spd 0.9>0.8; tank 1.1>1.15; veh 1>1.15; can 0.95>1; pis 6>5; smg 6>5; mg 6>5; rif 6>3; rl 6>1; mel 6>4 | crew-remap-20261118, held-remap-20261118 |
| tankman | 2026-11-18 | spd 0.9>0.8; can 1>0.9; pis 5>4; smg 5>4; mg 3>2; rif 2>3; rl 2>1; mel 5>4; tg 3>2 | crew-remap-20261118, held-remap-20261118 |
| tankman2 | 2026-11-18 | spd 0.9>0.8; can 1>0.95; pis 5>4; smg 5>4; mg 5>4; rif 5>3; rl 4>1; mel 5>4; tg 5>4 | crew-remap-20261118, held-remap-20261118 |
| vehicle_supporter | 2026-11-18 | mg 3>4; rl 2>1; mel 3>4 | crew-remap-20261118, held-remap-20261118 |
| vehicle_supporter_single | 2026-11-18 | mg 3>4; rl 2>1; mel 3>4 | crew-remap-20261118, held-remap-20261118 |
| vet_tankman | 2026-11-18 | sta 100%>150%; spd 0.9>0.8; tank 1>1.1; can 0.9>0.95; pis 5>4; smg 5>4; mg 5>4; rif 5>3; rl 5>1; mel 5>4; tg 5>4 | crew-remap-20261118, held-remap-20261118 |
| vet_tankman2 | 2026-11-18 | sta 100%>150%; spd 0.9>0.8; tank 1.1>1.15; veh 1>1.15; can 0.95>1; pis 6>5; smg 6>5; mg 6>5; rif 6>3; rl 6>1; mel 6>4 | crew-remap-20261118, held-remap-20261118 |

#### Breeds: usa (140 rows)

| Breed | Date | Changes (old>new) | Undo tag |
|---|---|---|---|
| bazooker | 2026-11-18 | rl 4>3 | soldier-remap-20261118 |
| bazooker2 | 2026-11-18 | rl 4>1 | soldier-remap-20261118 |
| devil_brigade_demo | 2026-11-18 | pis 6>5; smg 6>5; mg 6>5; rl 6>1; mel 6>5 | soldier-remap-20261118 |
| devil_brigade_grenadier | 2026-11-18 | pis 6>5; smg 6>5; mg 6>5; rl 6>1; mel 6>5 | soldier-remap-20261118 |
| devil_brigade_mg | 2026-11-18 | pis 6>5; smg 6>5; mg 6>5; rl 6>1; mel 6>5 | soldier-remap-20261118 |
| devil_brigade_radio | 2026-11-18 | pis 6>5; smg 6>5; mg 6>5; rl 6>1; mel 6>5 | soldier-remap-20261118 |
| devil_brigade_rifle | 2026-11-18 | pis 6>5; smg 6>5; mg 6>5; rl 6>1; mel 6>5 | soldier-remap-20261118 |
| devil_brigade_sl | 2026-11-18 | hp 350%>400%; smg 6>7; rl 6>1 | soldier-remap-20261118 |
| elite | 2026-11-18 | hp 250%>200%; smg 4>3; mg 4>3; rl 4>1 | soldier-remap-20261118 |
| elite_sgt | 2026-11-18 | hp 300%>350%; sta 150%>200%; tank 0.85>0.95; can 0.9>1; pis 4>5; mg 4>5; rif 4>5; rl 4>1; mel 4>5; vet 24/60/108/168/240>60/132/216/312/420 | soldier-remap-20261118 |
| elite_tankman | 2026-11-18 | hp 100%>400%; sta 100%>200%; can 1.05>1; pis 4>5; smg 4>5; rl 3>1; mel 3>4; tg 8>7 | crew-remap-20261118, held-remap-20261118 |
| elite_tankman2 | 2026-11-18 | hp 150%>400%; sta 100%>200%; pis 4>5; smg 4>5; mg 7>6; rl 3>1; mel 3>4 | crew-remap-20261118, held-remap-20261118 |
| elite3 | 2026-11-18 | hp 250%>200%; smg 4>3; mg 5>3; rl 4>1 | soldier-remap-20261118 |
| elite3b | 2026-11-18 | hp 250%>200%; smg 4>3; rif 5>3; rl 4>1 | soldier-remap-20261118 |
| elite4_sgt | 2026-11-18 | hp 250%>200%; pis 3>4; rl 3>1; mel 3>4 | soldier-remap-20261118 |
| elite5 | 2026-11-18 | hp 200%>150%; sta 150%>100%; tank 0.85>0.75; can 0.9>0.8; pis 3>4; mg 3>2; rl 3>1; mel 3>4 | soldier-remap-20261118 |
| elite6 | 2026-11-18 | hp 200%>150%; sta 150%>100%; tank 0.85>0.75; can 0.9>0.8; pis 3>4; mg 4>2; rl 3>1; mel 3>4 | soldier-remap-20261118 |
| eliteb | 2026-11-18 | hp 250%>200%; smg 4>3; mg 4>3; rl 4>1 | soldier-remap-20261118 |
| elitec | 2026-11-18 | hp 250%>200%; smg 4>3; mg 4>3; rl 4>1 | held-remap-20261118 |
| flamer | 2026-11-18 | pis 3>2 | held-remap-20261118 |
| flamer2 | 2026-11-18 | pis 3>2 | soldier-remap-20261118 |
| mgun | 2026-11-18 | mg 3>2 | soldier-remap-20261118 |
| mgun2 | 2026-11-18 | rif 3>2 | soldier-remap-20261118 |
| oficer | 2026-11-18 | hp 250%>200%; spd 1>0.9; mg 4>5; rif 4>5; rl 3>1; mel 4>5 | soldier-remap-20261118 |
| paramarine | 2026-11-18 | rl 5>1 | soldier-remap-20261118 |
| paramarine_sgt | 2026-11-18 | rl 5>1 | soldier-remap-20261118 |
| paramarine2 | 2026-11-18 | rl 5>1 | soldier-remap-20261118 |
| paramarine3 | 2026-11-18 | mg 6>5; rl 5>1 | soldier-remap-20261118 |
| paramarineb | 2026-11-18 | rl 5>1 | soldier-remap-20261118 |
| radioman_mortar | 2026-11-18 | pis 3>2 | soldier-remap-20261118 |
| rifle | 2026-11-18 | inv: -grenade m15_smoke 0.25 0.5, +grenade m15_smoke 0 1 | soldier-remap-20261118 |
| rifle2 | 2026-11-18 | inv: -grenade m15_smoke 0.25 0.5, +grenade m15_smoke 0 1 | soldier-remap-20261118 |
| rifle3 | 2026-11-18 | inv: -grenade m15_smoke 0.25 0.5, +grenade m15_smoke 0 1 | soldier-remap-20261118 |
| saper | 2026-11-18 | tank 0.85>0.75; can 0.9>0.8 | soldier-remap-20261118 |
| sniper | 2026-11-18 | hp 350%>150%; sta 150%>100%; spd 1>0.9; pis 3>4; mg 3>2; rl 2>1 | held-remap-20261118 |
| squadleader | 2026-11-18 | hp 200%>150%; tank 0.85>0.75; can 0.9>0.8; pis 3>4; mg 3>2; rl 2>1 | soldier-remap-20261118 |
| squadleader2 | 2026-11-18 | hp 200%>150%; tank 0.85>0.75; can 0.9>0.8; pis 3>4; mg 3>2; rl 2>1 | soldier-remap-20261118 |
| sturmovik | 2026-11-18 | rl 5>1 | soldier-remap-20261118 |
| sturmovik_sgt | 2026-11-18 | hp 400%>350%; rl 5>1 | soldier-remap-20261118 |
| sturmovik2 | 2026-11-18 | mg 6>5; rl 5>1 | soldier-remap-20261118 |
| sturmovik4 | 2026-11-18 | rl 5>1 | soldier-remap-20261118 |
| sturmovik5b | 2026-11-18 | rl 5>1 | soldier-remap-20261118 |
| sturmovik6 | 2026-11-18 | mg 6>5; rl 5>1 | soldier-remap-20261118 |
| sturmovik6b | 2026-11-18 | rl 5>1 | soldier-remap-20261118 |
| tankman | 2026-11-18 | hp 100%>150%; pis 3>4; smg 3>4; rif 2>3; rl 2>1; mel 3>4 | crew-remap-20261118, held-remap-20261118 |
| tankman2 | 2026-11-18 | pis 3>4; smg 3>4; mg 3>4; rif 2>3; rl 2>1; mel 3>4 | crew-remap-20261118, held-remap-20261118 |
| usa_82ndairborne_bar | 2026-11-18 | hp 250%>200%; smg 4>3; mg 5>3; rl 4>1 | soldier-remap-20261118 |
| usa_82ndairborne_barassist | 2026-11-18 | hp 250%>200%; smg 4>3; rif 5>3; rl 4>1 | soldier-remap-20261118 |
| usa_82ndairborne_carbine | 2026-11-18 | hp 250%>200%; smg 4>3; mg 4>3; rl 4>1 | soldier-remap-20261118 |
| usa_82ndairborne_mg | 2026-11-18 | hp 250%>200%; smg 4>3; rif 5>3; rl 4>1 | soldier-remap-20261118 |
| usa_82ndairborne_mgassist | 2026-11-18 | hp 250%>200%; smg 4>3; rif 5>3; rl 4>1 | soldier-remap-20261118 |
| usa_82ndairborne_rifle | 2026-11-18 | hp 250%>200%; smg 4>3; mg 4>3; rl 4>1 | soldier-remap-20261118 |
| usa_82ndairborne_sniper | 2026-11-18 | hp 250%>200%; smg 4>3; mg 4>3; rl 4>1 | held-remap-20261118 |
| usa_armor_mgun | 2026-11-18 | mg 3>2 | soldier-remap-20261118 |
| usa_armor_squadleader | 2026-11-18 | hp 200%>150%; tank 0.85>0.75; can 0.9>0.8; pis 3>4; mg 3>2; rl 2>1 | soldier-remap-20261118 |
| usa_bazooker | 2026-11-18 | rl 4>3 | soldier-remap-20261118 |
| usa_bazookerassist | 2026-11-18 | rl 4>1 | soldier-remap-20261118 |
| usa_devil_brigade_demo | 2026-11-18 | pis 6>5; smg 6>5; mg 6>5; rl 6>1; mel 6>5 | soldier-remap-20261118 |
| usa_devil_brigade_grenadier | 2026-11-18 | pis 6>5; smg 6>5; mg 6>5; rl 6>1; mel 6>5 | soldier-remap-20261118 |
| usa_devil_brigade_mg | 2026-11-18 | pis 6>5; smg 6>5; mg 6>5; rl 6>1; mel 6>5 | soldier-remap-20261118 |
| usa_devil_brigade_radio | 2026-11-18 | pis 6>5; smg 6>5; mg 6>5; rl 6>1; mel 6>5 | soldier-remap-20261118 |
| usa_devil_brigade_rifle | 2026-11-18 | pis 6>5; smg 6>5; mg 6>5; rl 6>1; mel 6>5 | soldier-remap-20261118 |
| usa_devil_brigade_sl | 2026-11-18 | hp 350%>400%; smg 6>7; rl 6>1 | soldier-remap-20261118 |
| usa_elite_101st_para | 2026-11-18 | rl 6>1 | soldier-remap-20261118 |
| usa_elite_101st_para_grenadier | 2026-11-18 | rl 6>1 | soldier-remap-20261118 |
| usa_elite_101st_para_sgt | 2026-11-18 | rl 6>1 | soldier-remap-20261118 |
| usa_elite_101st_para3 | 2026-11-18 | mg 7>6; rl 6>1 | soldier-remap-20261118 |
| usa_elite_101st_para3_asst | 2026-11-18 | rif 7>6; rl 6>1 | soldier-remap-20261118 |
| usa_elite_101st_para3b | 2026-11-18 | rl 6>1 | soldier-remap-20261118 |
| usa_elite_101st_para3b_asst | 2026-11-18 | rif 7>6; rl 6>1 | soldier-remap-20261118 |
| usa_elite_101st_parab | 2026-11-18 | rl 6>1 | soldier-remap-20261118 |
| usa_elite_grenadier | 2026-11-18 | hp 250%>200%; smg 4>3; mg 4>3; rl 4>1 | soldier-remap-20261118 |
| usa_elite_sgt | 2026-11-18 | hp 300%>350%; sta 150%>200%; tank 0.85>0.95; can 0.9>1; pis 4>5; mg 4>5; rif 4>5; rl 4>1; mel 4>5; vet 24/60/108/168/240>60/132/216/312/420 | soldier-remap-20261118 |
| usa_engineer | 2026-11-18 | tank 0.85>0.75; can 0.9>0.8 | soldier-remap-20261118 |
| usa_engineer_at | 2026-11-18 | rl 4>3 | soldier-remap-20261118 |
| usa_engineer_flamer | 2026-11-18 | pis 3>2 | held-remap-20261118 |
| usa_engineer_squadleader | 2026-11-18 | hp 200%>150%; tank 0.85>0.75; can 0.9>0.8; pis 3>4; mg 3>2; rl 2>1 | soldier-remap-20261118 |
| usa_engineer2 | 2026-11-18 | tank 0.85>0.75; can 0.9>0.8 | soldier-remap-20261118 |
| usa_engineer3 | 2026-11-18 | tank 0.85>0.75; can 0.9>0.8 | soldier-remap-20261118 |
| usa_engineer4 | 2026-11-18 | tank 0.85>0.75; can 0.9>0.8 | soldier-remap-20261118 |
| usa_flamer | 2026-11-18 | pis 3>2 | held-remap-20261118 |
| usa_flamerassist | 2026-11-18 | pis 3>2 | soldier-remap-20261118 |
| usa_marine_bar | 2026-11-18 | hp 200%>150%; sta 150%>100%; tank 0.85>0.75; can 0.9>0.8; pis 3>4; mg 4>2; rl 3>1; mel 3>4 | soldier-remap-20261118 |
| usa_marine_barassist | 2026-11-18 | hp 200%>150%; sta 150%>100%; tank 0.85>0.75; can 0.9>0.8; pis 3>4; mg 4>2; rl 3>1; mel 3>4 | soldier-remap-20261118 |
| usa_marine_grenadier | 2026-11-18 | hp 200%>150%; sta 150%>100%; tank 0.85>0.75; can 0.9>0.8; pis 3>4; mg 3>2; rl 3>1; mel 3>4 | soldier-remap-20261118 |
| usa_marine_rifle | 2026-11-18 | hp 200%>150%; sta 150%>100%; tank 0.85>0.75; can 0.9>0.8; pis 3>4; mg 3>2; rl 3>1; mel 3>4 | soldier-remap-20261118 |
| usa_marine_sgt | 2026-11-18 | hp 250%>200%; pis 3>4; rl 3>1; mel 3>4 | soldier-remap-20261118 |
| usa_marine_shotgun | 2026-11-18 | hp 200%>150%; sta 150%>100%; tank 0.85>0.75; can 0.9>0.8; pis 3>4; mg 3>2; rl 3>1; mel 3>4 | soldier-remap-20261118 |
| usa_mgun | 2026-11-18 | mg 3>2 | soldier-remap-20261118 |
| usa_mgun_asst | 2026-11-18 | mg 3>2 | soldier-remap-20261118 |
| usa_mgun2 | 2026-11-18 | rif 3>2 | soldier-remap-20261118 |
| usa_mgun2_asst | 2026-11-18 | rif 3>2 | soldier-remap-20261118 |
| usa_nightfighter_carbine | 2026-11-18 | spd ->0.9; rl 5>1 | crew-remap-20261118 |
| usa_nightfighter_leader | 2026-11-18 | hp 250%>400%; sta 150%>200%; tank 0.85>0.95; can 0.9>1; pis 4>6; mg 4>6; rif 5>7; rl 4>1; mel 4>6; vet 24/60/108/168/240>60/132/216/312/420 | crew-remap-20261118 |
| usa_officer | 2026-11-18 | hp 250%>200%; spd 1>0.9; mg 4>5; rif 4>5; rl 3>1; mel 4>5 | soldier-remap-20261118 |
| usa_paramarine | 2026-11-18 | rl 5>1 | soldier-remap-20261118 |
| usa_paramarine_boys | 2026-11-18 | rl 5>1 | soldier-remap-20261118 |
| usa_paramarine_grenadier | 2026-11-18 | rl 5>1 | soldier-remap-20261118 |
| usa_paramarine_sgt | 2026-11-18 | rl 5>1 | soldier-remap-20261118 |
| usa_paramarine2 | 2026-11-18 | rl 5>1 | soldier-remap-20261118 |
| usa_paramarine3 | 2026-11-18 | mg 6>5; rl 5>1 | soldier-remap-20261118 |
| usa_paramarine3_asst | 2026-11-18 | mg 6>5; rl 5>1 | soldier-remap-20261118 |
| usa_paramarineb | 2026-11-18 | rl 5>1 | soldier-remap-20261118 |
| usa_radioman_105 | 2026-11-18 | pis 6>2 | soldier-remap-20261118 |
| usa_radioman_155 | 2026-11-18 | pis 3>2 | soldier-remap-20261118 |
| usa_radioman_240 | 2026-11-18 | pis 6>2 | soldier-remap-20261118 |
| usa_radioman_mortar | 2026-11-18 | pis 3>2 | soldier-remap-20261118 |
| usa_raider | 2026-11-18 | hp 250%>200%; smg 4>3; mg 4>3; rl 4>1 | soldier-remap-20261118 |
| usa_raiderasst | 2026-11-18 | hp 250%>200%; smg 4>3; mg 4>3; rl 4>1 | soldier-remap-20261118 |
| usa_raiderbar | 2026-11-18 | hp 250%>200%; smg 4>3; mg 1>3; rl 4>1 | soldier-remap-20261118 |
| usa_raiderchad | 2026-11-18 | hp 250%>350%; sta 150%>200%; tank 0.85>0.95; can 0.9>1; pis 4>5; mg 4>5; rl 4>1; mel 4>5; vet 24/60/108/168/240>60/132/216/312/420 | soldier-remap-20261118 |
| usa_raiderdemo | 2026-11-18 | hp 250%>200%; mg 4>3; rif 5>3; rl 4>1 | soldier-remap-20261118 |
| usa_raidergren | 2026-11-18 | pis 3>4; rl 3>1; mel 3>4 | soldier-remap-20261118 |
| usa_ranger_bar | 2026-11-18 | mg 6>5; rl 5>1 | soldier-remap-20261118 |
| usa_ranger_bar2 | 2026-11-18 | mg 6>5; rl 5>1 | soldier-remap-20261118 |
| usa_ranger_barassist | 2026-11-18 | mg 6>5; rl 5>1 | soldier-remap-20261118 |
| usa_ranger_bazookaassist | 2026-11-18 | rl 5>1 | soldier-remap-20261118 |
| usa_ranger_carbine | 2026-11-18 | rl 5>1 | soldier-remap-20261118 |
| usa_ranger_garand | 2026-11-18 | rl 5>1 | soldier-remap-20261118 |
| usa_ranger_grenadier | 2026-11-18 | rl 5>1 | soldier-remap-20261118 |
| usa_ranger_mg | 2026-11-18 | rif 6>5; rl 5>1 | soldier-remap-20261118 |
| usa_ranger_mgassist | 2026-11-18 | mg 5>6; rif 6>5; rl 5>1 | soldier-remap-20261118 |
| usa_ranger_recoiless | 2026-11-18 | vet 24/60/108/168/240>60/132/216/312/420 | soldier-remap-20261118 |
| usa_ranger_sgt | 2026-11-18 | hp 400%>350%; rl 5>1 | soldier-remap-20261118 |
| usa_ranger_sniper | 2026-11-18 | rl 5>1; vet 24/60/108/168/240>60/132/216/312/420 | held-remap-20261118 |
| usa_ranger_springfield | 2026-11-18 | rl 5>1 | soldier-remap-20261118 |
| usa_ranger_springfield2 | 2026-11-18 | rl 5>1 | soldier-remap-20261118 |
| usa_rifle | 2026-11-18 | inv: -grenade m15_smoke 0.25 0.5, +grenade m15_smoke 0 1 | soldier-remap-20261118 |
| usa_rifle_at | 2026-11-18 | rl 4>3 | soldier-remap-20261118 |
| usa_rifle3 | 2026-11-18 | inv: -grenade m15_smoke 0.25 0.5, +grenade m15_smoke 0 1 | soldier-remap-20261118 |
| usa_saper | 2026-11-18 | tank 0.85>0.75; can 0.9>0.8 | soldier-remap-20261118 |
| usa_sniper | 2026-11-18 | hp 350%>150%; sta 150%>100%; spd 1>0.9; pis 3>4; mg 3>2; rl 2>1 | held-remap-20261118 |
| usa_squadleader | 2026-11-18 | hp 200%>150%; tank 0.85>0.75; can 0.9>0.8; pis 3>4; mg 3>2; rl 2>1 | soldier-remap-20261118 |
| usa_tankman_single | 2026-11-18 | hp 100%>150%; pis 3>4; smg 3>4; rif 2>3; rl 2>1; mel 3>4 | crew-remap-20261118, held-remap-20261118 |
| usa_tankman2_single | 2026-11-18 | pis 3>4; smg 3>4; mg 3>4; rif 2>3; rl 2>1; mel 3>4 | crew-remap-20261118, held-remap-20261118 |
| usa_vet_tankman2_single | 2026-11-18 | hp 150%>200%; sta 100%>150%; tank 1.3>1.15; veh 1.2>1.15; can 1.15>1; pis 3>5; smg 3>5; rif 2>3; rl 2>1; mel 3>4 | crew-remap-20261118, held-remap-20261118 |
| vehicle_supporter | 2026-11-18 | mg 3>4; rl 2>1; mel 3>4 | crew-remap-20261118, held-remap-20261118 |
| vehicle_supporter_single | 2026-11-18 | mg 3>4; rl 2>1; mel 3>4 | crew-remap-20261118, held-remap-20261118 |
| vet_tankman | 2026-11-18 | hp 100%>200%; sta 100%>150%; tank 1.2>1.1; veh 1.2>1; can 1.1>0.95; pis 3>4; smg 3>4; mg 3>4; rif 2>3; rl 2>1; mel 3>4; tg 5>4 | crew-remap-20261118, held-remap-20261118 |
| vet_tankman2 | 2026-11-18 | hp 150%>200%; sta 100%>150%; tank 1.3>1.15; veh 1.2>1.15; can 1.15>1; pis 3>5; smg 3>5; rif 2>3; rl 2>1; mel 3>4 | crew-remap-20261118, held-remap-20261118 |

## 6. Bug fixes in cards, vehicles and props

Date 2026-11-18. Commit cf7c41bd5.

### 6a. Squad cards (set/multiplayer/units)

Undo tag: fixes-20261118b. Costs and sizes did not change unless stated.

| Card (side) | Field | Old -> new | Why |
|---|---|---|---|
| ssvts_44 (ger_ss) | members | extra broken member "mp/ger_ss/1206" -> removed | bug: 6-type card macro used for 5 member types; the charge value became a member |
| elites_44 (ger_ss) | members | extra broken member "mp/ger_ss/607" -> removed | same bug |
| gebirgs_42 (ger_ss) | members | extra broken member "mp/ger_ss/06" -> removed | same bug |
| elite3 (jap) | member | elite_rifle2 -> elite_takasago_rifle2 | bug: wrong breed name |
| Bersaglieri_Mot (axis_minor) | member | axm_bersaglieri_mgun -> axm_ita_bersaglieri_mgun | bug: wrong breed name |
| riflemans, riflemans_2, riflemans_3 (jap, 1944-45) | MG team | jap_mgun2 / jap_mgun2_asst / jap_mgun2_ammo (Type 96) -> jap_mgun / jap_mgun_asst / jap_mgun_ammo (Type 99) | owner rule; costs 163 / 145 / 145 kept |
| soldiers.set price rows | rows | mp/jap/mgun3_ammo and mp/jap/mgun3_asst -> removed (breeds removed too) | unused breeds |

### 6b. Vehicles and props (entity)

| Unit | Field | Old -> new | Why | Undo tag |
|---|---|---|---|---|
| fiat35_art, fiat35_bomb, fiat35_inf | include | missing ammo_ita.inc -> resupply_generic.inc (as fiat626) | bug: the trucks had no resupply | fixes-20261118 |
| properties/resupply_generic.inc | defines | missing -> vanilla para_ammo, truck_ammo, truck_ammo_art restored | bug: undefined macros | fixes-20261118 |
| crate8_art, crate8_inf | resupply extender | none -> "supply_zone": radius 6, resupplyPeriod 3, limit 75 (inf), item maxima as vanilla | side effect of the line above | fixes-20261118 |
| 23 jungle, palm, mangrove and tsuga trees (jungle_lian_*, jungle_new_18..20, mangra_new_03, pacific_palm_new_01..04, palm_jungle_new_001..004, tsuga_new_01..04) | include and prop | missing tree_q.inc -> tree.inc, prop tree_q -> tree (as sibling trees) | bug: missing include | fixes-20261118 |
| sdkfz301wanze | shield extender | `(mod "not_mp" {on})` -> removed | reason not recorded; effect in "Not determined" | git only |
| nimrod | driver boarding path end | seat_sd222_gunner2 -> seat_driver_car | bug: driver path ended in a gunner seat [I] | git only |
| m1139 | one reverse boarding anim end | emit_tank_0 -> emit_tank_2 | reason not recorded; effect in "Not determined" | git only |

The three "git only" edits were in the files before the first macrostd step (its undo copy already has them). They are not covered by the "verify PASS" notes.

## 7. Data fixes made with the localization work

Date 2026-11-18. Commits f6742dc60, 16ef488c9, 353b75b28. Undo: git only (the cardrename-20261118 folder holds the renames).

| Unit / item | Field | Old -> new | Why |
|---|---|---|---|
| t20_fin | MG ammo in box | "ammo 7x54" 500 -> "ammo dt29_mag" 1260 | bug: ammo did not fit the DT |
| t34_3_fin_vet | MG ammo in box | "ammo 7x54" 2000 -> "ammo dt29_mag" 1890 | same |
| fiat35 | ammo box | "ammo_box_inf_ita" 5 -> "ammo_box_inf_axm" 2 | bug: box type; new stuff capacity/ammo_box_small_axm |
| np_sdkfz251_hun | grenades in box | "brandflasche" 10 -> "molotov_coctail" 10 | bug: item name |
| soldiers.set price row | breed path | mp/ger/ss_vet_sniper (no such breed) -> mp/ger_ss/ss_vet_sniper (level_20: cp 4.55, score 100, cw 0.5) | bug: the breed had no price row |
| soldiers.set price row | breed path | mp/jap/light_mortar_assist -> mp/jap/light_mortar_asst (level_29: cp 0.6, score 8) | same |
| soldiers.set price rows | rows | jap__type99_at and "mp/ger/f" -> removed | bogus rows |
| vehicles.set light_mortar_eng | crew | eng_light_mortar_assist:2 -> :1 (cost 170 / 140 unchanged) | team size fix |
| hero7_jap (jap) | member n2 | vehicle_supporter -> jap_elite_vehicle_supporter (type4_200mm_elite crew) | bug: wrong side |
| hero_jap_elite_aa (jap) | member n1 | elite_vehicle_supporter -> jap_elite_vehicle_supporter | same |
| 9 game presets (battle_zones, combat, presets*.inc) | unitLimits | "only-one=1,super_persh=1" -> "only-one=1;super_persh=1" | bug: wrong separator; the super_persh=1 limit likely starts to apply [I] |

Card renames ("(side)" and "hero_" names), the bot script name lists and the localization split changed no values (see the identical section).

## 8. SDK auto fixes

Date 2026-11-17. Commit 19487b2b2 "sdk auto fixes". Undo: git only.

| Item | Field | Old -> new | Why |
|---|---|---|---|
| set/material.set ice, water | ricochet `{angle}` table | {1 2}{10 20}{30 45}{45 60} -> {1 1}{10 10}{30 30}{45 45} | not recorded |
| set/material.set ground | ricochet `{angle}` table | {1 10}{2 15}{3 20}{4 25}{5 30}{10 40}{30 45}{45 60} -> {1 1}..{45 45} (identity) | not recorded |
| map 3v3_brettevillette combat.mi | environment | {Environment "multi/multi_01"} -> removed | not recorded |
| map 4v4_merville captureflag.mi | environment | {Environment "multi/multi_01"} -> removed | not recorded |
| map 6v6_desert_plains test.mi | environment | "multi_desert/multi_05" -> "multi/multi_05" | not recorded |

The rest of this commit changed no values (see the identical section).

## Changes checked as value-identical (no gameplay effect)

Method: each mod snapshot was expanded (macros, includes, `.presets`, mod over vanilla) with tools/macrostd/expand.js and compared token by token, unless stated.

| Change | Undo tag | How identity was checked |
|---|---|---|
| macrostd steps fmt, indent, dead, names, share, params, header, index, volumes, samedef | macrostd-20261118, macrostd-20261119 | macrostd verify PASS per step (notes); my expansion diff 4460f4dfd -> cf7c41bd5 shows only the fixes in topics 5 and 6 plus the three git-only edits in 6b |
| macrostd steps breed, kit, tiers, vet, guns | macrostd-20261118 | as above; all breed differences in that commit are explained by the remap rules or kit fixes |
| macrostd buylist (squad cards to macros) | macrostd-20261118 | card-level diff of the expanded units_4x.set roots: only the card fixes in 6a differ |
| cleanup | cleanup-20261118 | breed expansion before / after: 0 breeds differ |
| pass9, pass9b | pass9-20261119, pass9b-remap-20261119 | breed expansion 57b45f09b -> 990aa6048: only the 12 grenade-name breeds differ |
| vetguns (`{from}` rebuild of vet and elite guns) | vetguns-20261119 | resolver over 1356 stuff files: 8112 fields same, 0 differ |
| grenade names, word order only (12 names) | grenade-names-20261119 | item tags ignore word order (`modweb/refcheck/checker.md:11`) |
| price comment lines and price_model.inc | pricecalc-20261119, pricecalc-20261119b, pricemodel-20261119 | comments only; price_model.inc is included by nothing; unit expansion identical |
| card renames ("(side)", "hero_") and bot name lists | cardrename-20261118 (in `robz realism mod 1.31.0.arsenal-undo/`) | card content identical; bot.data.lua / bot.units.lua lines differ only in the renamed names |
| localization split and text fixes | lngsplit-20261118 (in `robz realism mod 1.31.0.arsenal-undo/`) | text only |
| stray `)` removed (blitz3_6eng, blitz3_6f, np_sdkfz250_1, 150mm_stuh43, 37mm_l40, 7 hero vehicle sets) | fixes-20261118, git only | the reader drops a stray `)` (tools/lib/sdlx.js:385) |
| sdkfz303 duplicate `{vision "tank_driver"}` removed | git only | last vision wins (src/game/entity/eActorVisor.cpp:110-113), "none" both times |
| fx particle lines, thunder sequence_dust, new .mtl files, logo.dds, rifle_cartridge_fra entity, guzzi shadow include | git only, fixes-20261118 | visual only |
| missing item count vs count 1 (e.g. `{item "grenade m24"}` -> `{item "grenade m24" 1}`) | macrostd | treated as the same [I]: the item gives 1 when no count is set |

## Not yet loaded in the game

Nothing in this file has been loaded or tested in the game. No game.log was read for any of these changes. Every entry is checked only against the data (git diffs and macro expansion). The notes say the same for the remap, the vet rules and the price model. The small shovel for every breed and the 60 mm call-in price (3a, 3b) are not loaded in the game either: no spawn test, no buy test.

## Not determined

| Item | What is unknown | What would settle it |
|---|---|---|
| material.set ricochet tables (topic 8) | why they were set to identity, and how much ricochet changes | the owner or the SDK tool log; an in-game shot test on ground, ice and water |
| map environment edits (topic 8) | what the three maps look like now (light, weather) | load each map in the game |
| ss_vet_sniper and light_mortar_asst price (topic 7) | what these two breeds cost before they had a price row | engine code for a breed with no price row, or the buy menu in a game on the old data |
| unitLimits separator (topic 7) | whether the "," form already worked, so whether super_persh=1 is a new limit | the engine parser for unitLimits, or an in-game buy test |
| 4 bare grenade names (topic 4) | whether a vanilla item also carries m24x5, oto_mod35, molotov_coctail or ccm34smoke without the "grenade" tag; in the mod only "X grenade" items carry them | scan vanilla set/stuff for those names |
| mosin_s_vet and m1903a4_vet bolt tags (topic 2) | mosin_s_vet now has bolt_r140 (inherited) and bolt_r105 (own); which one the game uses | engine code for repeated {tag} in a `{from}` chain, or an in-game cycle time check |
| sdkfz301wanze shield (topic 6b) | effect of removing `(mod "not_mp" {on})`: the shield likely no longer starts deployed outside MP [I] | in-game check in single player |
| m1139 boarding animation (topic 6b) | whether emit_tank_2 is the right animation for that exit | in-game boarding test |
| tree include fix (topic 6b) | how the 23 trees behaved with the missing include (props, collision, falling) | in-game check on a jungle map |
| human_full_test.inc closer (fixes-20261118) | nothing in the mod includes this file, so likely no effect; vanilla use not checked | grep vanilla data for human_full_test |
| small shovel in a full kit (topic 3a) [T] | usa_elite_101st_para4 fills its 60 cells, so the shovel is likely dropped silently unless the random wp round count is 0; the fit was worked out from engine code and stuff sizes, not seen in the game | spawn the breed several times and open its inventory |
| level_93 CP (topic 3b) | the model now says CP 5 for the 60 mm call-in; the breed's real CP is still 2.0 | owner: should the game value become 5 too |
| give_chance `-1 2` (pre-existing, not changed) | the 12% kit chance draws a negative count for about 37% of soldiers; what the game does then | in-game spawn test |
