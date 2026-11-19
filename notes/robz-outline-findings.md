# RobZ Realism 1.31.0: why breeds are out of line, and loadouts against history

Read-only analysis, 2026-11-18. No mod file was changed. Nothing here was run in the game [T].
Detail reports (each ends with questions for the owner):

| Report | Covers |
|---|---|
| `robz-outline-why-kit.md` | the 279 equipment rows of `robz-breed-outline.tsv` |
| `robz-outline-why-perks.md` | the 329 perk-set rows and 21 veterancy rows |
| `robz-toe-ger.md` | 179 infantry cards of ger, ger2, ger_ss; 46 ToE line texts |
| `robz-toe-rus.md` | rus, rus_guard; 6 ToE line texts |
| `robz-toe-usa-eng.md` | usa, eng; 28 suggested ToE texts |
| `robz-toe-jap-minor.md` | jap, axis_minor; suggested ToE texts |

Marks: [C] checked by the coordinator in the mod files; [A] from the analyst's report, not re-checked; history dates are
mostly from memory unless the detail report names a page.

## 1. Why the 629 rows are out of line

| Reason | Equipment (279) | Perks (329) |
|---|---|---|
| Likely mistake | 15 | 3 high + 11 medium confidence |
| Possible slip | 11 | 18 low confidence |
| Deliberate (role, leader, side ladder, crew, hero) | 126 | 218 |
| Not a real deviation (rare weapon, other text form, ammo listed further down) | 127 | 4 text-only |
| Soldier no card uses | 10 breeds | 75 rows |

Main cause for perks: squads build their own small ladders (a base set, plus one level on the weapon carried, plus a leader
bump). Those sets have fewer than 4 users, so they got no tier macro. Main cause for equipment: weapons used by fewer than
4 breeds (81 rows) and loads that are a whole number of magazines for that weapon.

### Likely mistakes, equipment
- 6 breeds carry a Luger or Walther with `ammo 9x19` 40; both pistols fill only from `walther_mag` (`stuff/pistol/luger:2`,
  `valter:2`), so the rounds can never be loaded: 4 Finnish breeds, `axm_rom_bazooker`, `axm_bul_officer` [C].
- `axm_ita_alpini_sniper.set`: Beretta M1934 pistol with 160 rounds, the rifle count repeated on the pistol line [C].
- `jap_mg3_asst.set`: assistant of the 6.5 mm Type 11 gun carries a Type 99 rifle and 200 rounds of 7.7 mm [C].
- Counts copied from another weapon, not whole magazines: three `ss_kosaken` breeds (PPSh stick magazine of 35 with the drum
  count 142), `axm_fin_tankman` 142, `axm_ita_vehicle_supporter` 128, `axm_hun_smg_ppsh` 240, `axm_bul_smg` 120 [A].
- `suomi_m31`: 213 is exactly 3 drums; the 7 breeds on the "standard" 210 are the inexact ones [A].
- `type97rifle` has no stuff file; only `jap/mgun3_ammo` and `jap/mgun3_asst` carry it and no card uses them [A].

### Likely mistakes, perks and veterancy
- `ger_pzgren_smg_panzerfaust.set:15`: MP 40 with smg 4 / rifle 5; its StG twin has smg 5 / rifle 4 [C].
- `ss_pzgren_sl_stg.set:15`: rocket 5, no rocket weapon [C].
- `axm_fin_sissi_mgun_vision.set:14`: smg 1 / rifle 3; the plain breed has smg 5 / rifle 6; every other `_vision` copy
  matches its plain breed [C].
- `vet_standard_start2` (120/192) and `vet_standard_start3` (72/144): ranks 4 and 5 are 12 points above the base minus the
  start offset (108/180, 60/132) [C for start2].
- `vet_crew_start3`: an elite line pasted in (96/204 outside multiplayer; the multiplayer set is 180/360) [C].
- `eng_rifleman_smoke` and `ss_at_miner`: literal table 2/5/9/14/20, rank 5 about 12 times faster than `vet_standard`.
  `eng_rifleman_smoke` is the rifleman of the main British sections [A].
- Sibling mismatches: `jap_kanoeshidan_rifle_apminer`; `usa_radioman_105` / `_240` pistol 6 against `_155` pistol 3;
  `ki_rifle`, `ki_smoke` melee 3 against 5; three Volksgrenadier Panzerfaust men with rocket 1; British tank crews cannon 0.8
  against 0.9+ on every other side [A].

### Corrections to earlier cases in `robz-macrostd.md`
- Case 23 said 21 weapons had ammo they cannot load. Real count: 6 (above). The radiomen's flare guns have their flare
  ammo two lines further down (`ger_radioman_mortar.set:18-21` [C]).
- Case 25 said 128 filled weapons had no ammo line. In every out-of-line row the ammo is in the file, listed later [A].
- Case 29 (elite names on the standard table) is mostly a false alarm [A].

## 2. Cards that cannot work as written (data, not history)
- `jap/squads_42-43.set:79` card `elite3` asks for `elite_rifle2`: no such breed file [C].
- `axis_minor/squads.set:31` card `Bersaglieri_Mot` asks for `axm_bersaglieri_mgun`; the file is
  `axm_ita_bersaglieri_mgun` [C].
- `ger/squads_44.set:14` `ssvts_44`, `:78` `elites_44`, `ger/squads_42.set:17` `gebirgs_42`: one member too few for the
  macro (already owner case 8) [C].
- `jap/squads_44-45.set:21-23` "section w/Type 99 LMG": the gunner `jap_mgun2` carries a Type 96, so the cards equal the
  Type 96 cards [C].
- `rus_guard/squads_43-45.set:69` titled "PIAT team" carries a bazooka [A].
- `usa/squads_43-45.set:14` has `member5(usa_armor_mgun:0)` [A]. A card names `jap_kanoeShidan_type38rifle` with a capital
  the file name may not match [A].

## 3. Which years a card is really offered [C]
The year list decides, not only the tags (`set/multiplayer/units/units_4x.set`):

| Year list | ger | usa | eng | rus | rus_guard | jap | axis_minor | ger2 |
|---|---|---|---|---|---|---|---|---|
| 41 | squads_41 | none | squads_40-41 | squads_41-42 | none | none | squads | none |
| 42 | squads_42 | squads_42 | squads_42-45 | squads_41-42 | none | squads_42-43 | squads | none |
| 43 | squads_43 | squads_43-45 | squads_42-45 | squads_43-45 | squads_43-45 | squads_42-43 | squads | none |
| 44-45, 45 | squads_44 | squads_43-45 | squads_42-45 | squads_43-45 | squads_43-45 | squads_44-45 | squads | squads |

So tags 39 and 40 never apply, and a late weapon in a shared file shows in every year of that file unless the tags filter
it (the tag filter inside one list is not tested [T]).

## 4. Off the historical loadout (largest first; all [A], dates from memory unless the detail report cites a page)

### Weapons offered too early
| Side | Card or breed | Weapon | In mod | Historical |
|---|---|---|---|---|
| ger | elites_42, elite3_42 | FG 42 | 1942 | 1943 |
| ger, ger_ss | PzB 39 teams, SS mine teams | Hafthohlladung | 1940-42 | late 1942 |
| ger | rifleman card, G43 grenadier | Panzerfaust 60 | before 1944 | 1944 |
| ger | Volkssturm | MP 3008, Volkssturmgewehr | 1944 list (shared with 45) | 1945 |
| ger | Fallschirmjäger | Panzerwurfmine | 1941-42 | 1943 |
| rus | squads_41-42:70 | bazooka team | 1942 | lend-lease from late 1942-43 |
| rus | Shock Troops (smg3) | SN-42 armour | 1942 | 1943 |
| rus | 1941 crews, sappers | PPSh box magazine | 1941 | 1942 |
| eng | 1941 Thompson cards | Sten Mk II in place of Thompson | 1941 | Thompson |
| eng | Commando, Para, SAS | Sten Mk V, Mk VI, De Lisle | 1941-43 | 1944 |
| eng | SAS, rifle section | PIAT | 1941-42 | 1943 |
| usa | 1942 roster | M1919A6, M9A1 bazooka, M1903A4, M3 | 1942 | 1943-44 |
| usa | Rangers; 101st | M2 carbine; M18 recoilless | 1943-44; 1944 | 1945 |
| jap | Imperial Guard, SNLF | Type 4 rocket launcher | 1942-43 | 1945 |
| jap | most 1942-43 breeds | Type 3 AT grenade | 1942-43 | 1943-45 |
| jap | Teishin | TERA rifle | 1942 | 1943 |

### Weapons offered too late, or missing
- eng: Boys AT rifle in 1944-45; every rifle is the No.1 Mk III* to 1945 (no No.4, no No.4 (T), no Gammon bomb).
- rus: no SVT-40 in the 1941 squad; no RGD-33, RG-42, RPG-6; no infantry card uses the Maxim, SG-43 or DShK.
- axis_minor: infantry tagged 44-45 only, though the side loads in every year; Romania, Bulgaria and Finland appear in 1945.

### Squad make-up
- rus: 1943-45 rifle squad 11 men against 9 in the late-1942 table; paratroopers and Elite Guards use the DT, not the DP;
  two Guards squads differ from the owner's own note (`tings to do.txt:415-416`).
- usa: 1942 "Armored rifle squad" has 5 Thompsons; 1942 Marines carry Garands. Two BARs per squad follows the owner's notes.
- jap: sections mix 6.5 mm and 7.7 mm men.
- ger: G41 as an ordinary squad rifle in 1941 (up to 3), looks deliberate.

### Ammunition and grenades against standard issue
| Who | Mod | Standard issue |
|---|---|---|
| Soviet Mosin rifleman | 65 rounds | 100-120 |
| Japanese rifleman | 65 | 120 |
| German Fallschirmjäger rifleman | 120 | 60 (bandolier adds more) |
| Carcano rifleman | 246 | lower |
| DP squad gun | 14 pans (658) | fewer |
| Sten Mk II | 4 spare magazines | 5-8 |
| Soviet line rifleman grenades | about 1 | 2 |
| 1941 British assault section leader | 25 rifle grenades, no rifle rounds | |
| One British pioneer | 31 AP mines | |

The 65-round rifle load on two sides points to a mod-wide balance rule rather than a slip [I].

## 5. Not checked
- Nothing was run in the game. The random count forms (`0 1`, `1.5 0.5`, `-1 2`) are read from engine code, not tested.
- History: no primary tables were at hand; minor Axis and British establishment facts are the least sure.
- `cards.tsv` keeps one row per card name, so it misses the US 1942 roster, the British 1941 copies and vehicle crews. The
  analysts read the units files directly.
