# RobZ outline, step kit: why each load is out of line

Source: plan/reports/robz-breed-outline.tsv, the 279 rows with step `kit`. Mod: RobZ Realism 1.31.0, read only. Scratch and scripts: E:\arsenal-tmp\robz-toe\whykit\ (classify.js holds the row-to-class map).

Method: each row was tested against magazine size (`filling` line of the weapon's stuff file), sibling breeds with the same weapon (breeds.tsv), unit lines that buy the breed (the loaded units files: every `units/<side>/*.set` included by units_4x.set plus the shared vehicles/squads files, side-aware), year suffix / year list, and the owner's notes. Each row got one class (the first that fits, mistakes first).
- DATA = read from files, certain. [I] = inferred. [T] = needs an in-game test. History lines are from memory, unverified.
- "used in" = first unit line that buys the breed (+N more). cards.tsv misses vehicle crews and hero cards (39 kit breeds have no row there, 29 of them do have unit lines), so usage here comes from the units files, not cards.tsv.
- Grenade count forms (`0 1`, `1.5 0.5`) are read with the rule in modweb/humans/breeds.md:15 (code reading, not run in game).

## Summary

| # | reason class | rows | verdict | confidence |
|---|---|---|---|---|
| 1 | Spare ammo the weapon cannot load | 6 | likely mistake | high (data) |
| 2 | Pistol given a rifle-size count (paste slip) | 1 | likely mistake | high |
| 3 | MG assistant carries ammo that does not fit the team gun | 1 | likely mistake | medium |
| 4 | Count copied from another weapon, not whole magazines | 7 | likely mistake | medium |
| 5 | Unit-wide round count applied to a weapon it does not divide | 6 | possible slip | low |
| 6 | Row is magazine-exact; the standard is the odd one | 2 | standard to fix, not the row | medium |
| 7 | One breed differs from its twins (drift?) | 3 | possible slip | low |
| 8 | Year variant (file suffix or year list) | 8 | deliberate | medium |
| 9 | Two loads split by unit kind, consistent across year lists | 4 | deliberate | medium |
| 10 | Role/tier: paratroopers and elites carry more | 15 | deliberate | medium |
| 11 | Role: crew, officers, leaders, special carry less | 12 | deliberate | medium |
| 12 | Role: MG assistants / ammo bearers | 5 | deliberate | medium |
| 13 | Tier: militia, partisans, conscripts carry less | 8 | deliberate | high |
| 14 | Side or unit-type number for weapons with no shared standard | 16 | deliberate | medium |
| 15 | Grenade / mine / smoke counts set per unit type or role | 49 | deliberate | medium |
| 16 | Random count form (n dev) | 9 | deliberate | medium |
| 17 | Spare ammo belongs to a second weapon the breed carries | 1 | not a deviation | high |
| 18 | Same load written another way (tool artifact) | 21 | not a deviation | high |
| 19 | Ammo is present, listed after another item (tool artifact) | 24 | not a deviation | high |
| 20 | Weapon used by under 4 breeds: no macro by the 4-use rule | 81 | not a deviation | high |
| | total | 279 | | |

Likely mistakes: classes 1-4 = 15 rows. Possible slips or a standard to revisit: classes 5-7 = 11 rows. Deliberate: classes 8-16 = 126 rows. Not a deviation (tool artifacts or the 4-use macro rule): classes 17-20 = 127 rows.
Tests asked for, by result: role (crew, officer, assistant, sniper, paratrooper, miner) explains classes 10-12 and most of 15; year variant explains 8 rows (class 8); tier (elite, paratroop, militia, Volksgrenadier) classes 10, 13, 16; side-wide or unit-type convention class 14; magazine size was checked for every gun row: 14 rows are not whole magazines (classes 2, 4, 5) and 2 rows are whole while their standard is not (class 6); twin drift class 7 (3 rows); typo: none (213 vs 210 is the standard being off, 142 is a copied PPSh drum count); unused breeds: 10 kit breeds, listed at the end.

## Per class

### 1. Spare ammo the weapon cannot load (6, likely mistake, confidence high (data))

DATA: luger and valter both fill `ammo walther_mag` (stuff/pistol/luger:2, stuff/pistol/valter:2). `ammo 9x19` is its own item (stuff/ammo/9x19.ammo, tags `bullet small stackable pierce 9_pistol`), loaded only by steyer_pistol_1912, orita and Fnab_m1943. A filling takes any stuff whose tags hold ALL filling words (modweb/humans/inventory.md:18, eStuff.cpp:250-264), so 9x19 rounds never go into a luger or valter: the soldier has only the 8 rounds in the gun.
[I] The author meant 9 mm Parabellum, which is historically right for a Luger/P38, but in this mod that cartridge is `walther_mag`. Fix: `ammo walther_mag` 32 (`pistol_luger`) / 16 (`pistol_valter`). [T] confirm in game: pistol shows 8 rounds, no reload.

| file:line | what | standard | reason | evidence | used in |
|---|---|---|---|---|---|
| axm/axm_fin_sissi_mgun_vision.set:20 | luger followed by ammo it does not load ({item  "ammo 9x19" 40}) | walther_mag 32 (6) | Luger spare is `ammo 9x19`; luger fills `ammo walther_mag`, so the 40 rounds never load | stuff/pistol/luger:2 filling "ammo walther_mag" 8; 9x19.ammo tags lack walther_mag | axis_minor/vehicles:123 |
| axm/axm_rom_bazooker.set:19 | valter followed by ammo it does not load ({item  "ammo 9x19" 40}) | walther_mag 16 (57) | valter + `ammo 9x19` 40, no 9x19 weapon carried; looks copied from the assistant (Orita) file | stuff/pistol/valter:2 filling "ammo walther_mag" 8; twin axm_rom_bazooker_assist has orita | axis_minor/squads:83 |
| axm/axm_bul_officer.set:26 | valter followed by ammo it does not load ({item  "ammo 9x19" 40}) | walther_mag 16 (57) | valter + `ammo 9x19` 40, no 9x19 weapon carried | stuff/pistol/valter:2 | **none** |
| axm/axm_fin_pio_flamer.set:22 | luger followed by ammo it does not load ({item  "ammo 9x19" 40}) | walther_mag 32 (6) | same: Luger + `ammo 9x19` 40, flamer has no other 9x19 weapon | stuff/pistol/luger:2 | axis_minor/squads:14 +1 |
| axm/axm_fin_pio_mgun.set:20 | luger followed by ammo it does not load ({item  "ammo 9x19" 40}) | walther_mag 32 (6) | same: Luger + `ammo 9x19` 40 | stuff/pistol/luger:2 | axis_minor/squads:14 |
| axm/axm_fin_sissi_mgun.set:20 | luger followed by ammo it does not load ({item  "ammo 9x19" 40}) | walther_mag 32 (6) | same: Luger + `ammo 9x19` 40 | stuff/pistol/luger:2 | axis_minor/squads:23 |

### 2. Pistol given a rifle-size count (paste slip) (1, likely mistake, confidence high)

DATA: 160 rounds for a 7-round pistol. Every other alpini weapon line in the file set uses 160, the only other Beretta breeds have 35.

| file:line | what | standard | reason | evidence | used in |
|---|---|---|---|---|---|
| axm/axm_ita_alpini_sniper.set:24 | beretta_m1934 with 9x17 160, standard is 35 (+125) | 9x17 35 (2) | Beretta M1934 pistol with 160 rounds (22.9 magazines); 160 is the alpini rifle/SMG count, pasted onto the pistol line | stuff/pistol/beretta_m1934:2 filling 7; other Beretta breeds carry 35 (axm_ita_alpini_mgun, axm_ita_bersaglieri_mgun) | axis_minor/squads:27 |

### 3. MG assistant carries ammo that does not fit the team gun (1, likely mistake, confidence medium)

DATA: squad `mg3` (units/jap/squads_44-45.set:89) = jap_mgun3 (type11_mg, arisaka6-5_clip 180) + jap_mg3_asst. The Type 11 fills `ammo arisaka6-5_clip` (stuff/mgun/type11_mg:3), the assistant carries 7.7 mm `arisaka7-7_clip` 200 for a type99rifle. Ammo is not shared between soldiers by name match anyway, but an assistant's bulk ammo is the pattern this mod uses to feed the team gun (rows in class 12).
[I] When type97rifle (no stuff file, see "Other cases") was replaced, both rifle and ammo moved to 7.7 mm. History, from memory: the Type 11 took 6.5 mm rifle chargers in its hopper, so 6.5 mm for the assistant is what matches.

| file:line | what | standard | reason | evidence | used in |
|---|---|---|---|---|---|
| jap/jap_mg3_asst.set:18 | type99rifle with arisaka7-7_clip 200, standard is 60 (+140) | arisaka7-7_clip 60 (23) | assistant of the Type 11 LMG team (squad mg3: jap_mgun3 + jap_mg3_asst) carries a Type 99 rifle and 200 rounds of 7.7 mm; the Type 11 fills arisaka6-5_clip, so none of it feeds the gun. Older pair mgun3_asst/mgun3_ammo had type97rifle + arisaka6-5_clip 90/180; otsu_mg_asst (same gun) has type38 + arisaka6-5_clip 180 | units/jap/squads_44-45.set:89; stuff/mgun/type11_mg:3 filling "ammo arisaka6-5_clip" 30 | jap/squads_44-45:89 |

### 4. Count copied from another weapon, not whole magazines (7, likely mistake, confidence medium)

DATA: count / magazine size from the weapon's stuff `filling` line. These counts are the drum or magazine count of a different weapon. The owner's own note "ppsh drum and stick mag change; no it fucks shit up" (tings to do.txt:82) shows the drum/stick split was a known trap.

| file:line | what | standard | reason | evidence | used in |
|---|---|---|---|---|---|
| axm/axm_bul_smg.set:18 | mp40 with mp40_mag 120, standard is 192 (-72) | mp40_mag 192 (73) | mp40 with 120 (rifle number) = 3.75 magazines; breed has no unit line (leftover), squadleader twin has 128 = 4 mags | stuff/smg/mp40 filling 32 | **none** |
| axm/axm_fin_tankman.set:20 | suomi_m31r with ppsh_mag 142 (only load) | ppsh_mag 142 (1) | suomi_m31r fills 40 per magazine; 142 is the PPSh 2-drum count; 3.55 magazines | stuff/smg/suomi_m31r:2 filling "ammo ppsh_mag" 40 40 | axis_minor/vehicles:81 +1 |
| axm/axm_hun_smg_ppsh.set:18 | ppsh with ppsh_mag 240, standard is 142 (+98) | ppsh_mag 142 (18) | ppsh drum 71: 240 = 3.38 drums; 240 is the Hungarian rifle count (axm_hun_rifle feg_35m 240) | stuff/smg/ppsh:2 filling 71 | axis_minor/squads:10 +1 |
| axm/axm_ita_vehicle_supporter.set:20 | mab_38a with mab_38a_mag 128, standard is 200 (-72) | mab_38a_mag 200 (4) | mab_38a fills 40; 128 (= 4 x 32, the MP40/Sten count) gives 3.2 magazines; crew role explains fewer, not the odd number | stuff/smg/mab_38a:2 filling 40 | axis_minor/squads:31 +17 |
| ger_ss/ss_kosaken_sl.set:19 | ppsh41 with ppsh41_mag 142, standard is 105 (+37) | ppsh41_mag 105 (16) | ppsh41 (35-round stick) given 142 = 2 x 71, the PPSh drum count; 4.06 magazines | stuff/smg/ppsh41:2 filling 35; ppsh (drum) fills 71; owner note "ppsh drum and stick mag change" (tings to do.txt:82) | ger/squads_44:16 |
| ger_ss/ss_kosaken_sl_asst.set:19 | ppsh41 with ppsh41_mag 142, standard is 105 (+37) | ppsh41_mag 105 (16) | same as ss_kosaken_sl | stuff/smg/ppsh41:2 | ger/squads_44:16 |
| ger_ss/ss_kosaken_smg.set:19 | ppsh41 with ppsh41_mag 142, standard is 105 (+37) | ppsh41_mag 105 (16) | same as ss_kosaken_sl | stuff/smg/ppsh41:2 | ger/squads_44:16 |

### 5. Unit-wide round count applied to a weapon it does not divide (6, possible slip, confidence low)

DATA: the unit type uses one number for every weapon (alpini 160, Hungarian assault 190). For the weapon in the row it is not a whole number of clips or magazines. Low risk: a partial magazine just reloads short.

| file:line | what | standard | reason | evidence | used in |
|---|---|---|---|---|---|
| axm/axm_hun_assualt_pzf.set:19 | danuvia_39m with 9x25 190 (no std) | none | assault group uses 190 for every weapon (danuvia, feg_43m); for the 40-round Danuvia it is 4.75 mags | stuff/smg/danuvia_39m:2 filling "ammo 9x25" 40 40 | axis_minor/squads:25 +2 |
| axm/axm_hun_assualt_smg.set:19 | danuvia_39m with 9x25 190 (no std) | none | same assault-group 190 | stuff/smg/danuvia_39m:2 | axis_minor/squads:25 +1 |
| axm/axm_hun_assualt_squadleader.set:19 | danuvia_39m with 9x25 190 (no std) | none | same assault-group 190 | stuff/smg/danuvia_39m:2 | axis_minor/squads:25 +1 |
| axm/axm_ita_alpini_rifle.set:18 | m9138_carcano with 7x51 160 (no std) | none | alpini use 160 for every weapon; carcano clip 6: 26.7 clips | stuff/rifle/m9138_carcano:2 filling 6 36 | axis_minor/squads:27 |
| axm/axm_ita_alpini_rifle2.set:18 | carcano_m91 with 6x52 160, standard is 240 (-80) | 6x52 240 (2) | alpini 160; bersaglieri twin axm_ita_bersaglieri_rifle has 240 (40 clips) | stuff/rifle/carcano_m91:2 filling 6 36 | axis_minor/squads:27 |
| axm/axm_ita_alpini_sniper.set:22 | carcano_m91_scoped with 6x52 160 (only load) | 6x52 160 (1) | alpini 160 on the scoped Carcano; 26.7 clips | stuff/rifle/sniper/carcano_m91_scoped | axis_minor/squads:27 |

### 6. Row is magazine-exact; the standard is the odd one (2, standard to fix, not the row, confidence medium)

DATA: suomi_m31 fills `ammo ppsh_mag` 71 per drum. 213 = 3 drums exactly. The standard 210 (7 breeds: axm_fin_kaukopartio_squadleader, _pio_smg, _pio_squadleader, _sissi_smg, _sissi_smg_vision, _sissi_squadleader, _sissi_squadleader_vision) is 2.96 drums. The mod already has `smg_ppsh_213` for the PPSh drum. If anything changes, it is the 7 breeds at 210.

| file:line | what | standard | reason | evidence | used in |
|---|---|---|---|---|---|
| axm/axm_fin_at_rifleassist.set:18 | suomi_m31 with ppsh_mag 213, standard is 210 (+3) | ppsh_mag 210 (7) | 213 = exactly 3 drums of 71; the 7 breeds at 210 (axm_fin_pio_smg, _sissi_smg, ...) are 2.96 drums: the standard is the inexact one (210 looks taken from the PPSh-41 6 x 35) | stuff/smg/suomi_m31:2 filling "ammo ppsh_mag" 71 71 | axis_minor/squads:74 |
| axm/axm_fin_kaukopartio_smg.set:18 | suomi_m31 with ppsh_mag 213, standard is 210 (+3) | ppsh_mag 210 (7) | same: 213 = 3 drums | stuff/smg/suomi_m31:2 | axis_minor/squads:18 +1 |

### 7. One breed differs from its twins (drift?) (3, possible slip, confidence low)

DATA: a breed whose twins (same unit group, same weapon) all carry another value. Could be on purpose; no comment in the file says so.

| file:line | what | standard | reason | evidence | used in |
|---|---|---|---|---|---|
| eng/eng_anzac_rifle.set:18 | em3 with british303_clip 100, standard is 50 (+50) | british303_clip 50 (28) | ANZAC rifleman 100; every other em3 user incl. eng_anzac_at_rifle/_rifle_grenadier/_mg_assist has 50 | breeds.tsv em3 rows | eng/vehicles_43-44:133 |
| eng/eng_rifleman_smoke.set:29 | em3 with british303_clip 60, standard is 50 (+10) | british303_clip 50 (28) | smoke rifleman 60 vs 50 (+1 clip); same file has one mk1 grenade (row below) | breeds.tsv em3 rows | eng/squads_42-45:11 +3 |
| eng/sniper.set:21 | em2 with british303_clip 50 (no std) | none | em2 (a rifle/sniper stuff) 50 in the 1940-41 sniper; eng_paratroopr_em2 has 100 | units/eng/squads_40-41.set:68 | eng/squads_40-41:68 +1 |

### 8. Year variant (file suffix or year list) (8, deliberate, confidence medium)

DATA: the year explains the weapon, not an odd count: these are the only breeds with a period weapon (De Lisle, silenced Sten, MKb 42, MP 43, FG 42), so the load has under 4 uses. For the Japanese snipers the old 1942-43 list breeds (sniper, sniper2) carry 60 and their 1944-45 replacements (jap_sniper_type99 / _type97, class 20 rows) carry 100: a rebalance between generations [I].

| file:line | what | standard | reason | evidence | used in |
|---|---|---|---|---|---|
| eng/elite2_40.set:18 | de_lisle with rifle 70 (only load) | rifle 70 (2) | _40 file: De Lisle carbine is a 1940-41 commando weapon; same load as eng_commando_silence_carbine | units/eng/squads_40-41.set | eng/squads_40-41:15 |
| eng/elite_40.set:18 | sten_v_silencer with sten_mag 128 (only load) | sten_mag 128 (2) | _40 file: silenced Sten; same load as eng_commando_silencesmg | stuff/smg/sten_v_silencer fills 32: 128 = 4 mags | eng/squads_40-41:15 |
| eng/squadleader2_40.set:18 | em3_mark1 with rifle_grenade 25 (only load) | rifle_grenade 25 (1) | _40 file: em3_mark1 rifle-grenade launcher, 25 grenades | stuff/rifle/em3_mark1 fills 1: 25 = 25 mags | eng/squads_40-41:5 |
| ger/grenadier_stg_42.set:18 | mkb42 with stg44_mag 180 (only load) | stg44_mag 180 (1) | year-named file (MKb 42), stg44_mag 180 = 6 mags, same as sg44 standard | stuff/smg/mkb42 | ger/squads_42:85 |
| ger/grenadier_stg_43.set:18 | mp43 with stg44_mag 180 (only load) | stg44_mag 180 (1) | year-named file (MP 43), 180 = 6 mags | stuff/smg/mp43 | ger/squads_43:89 |
| ger2/ost_fallschirm_sl_asst_fg_44.set:20 | fg42_sc with fg42_mag 160 (only load) | fg42_mag 160 (1) | _44 file, FG42 scoped, 160 = 8 mags | stuff/rifle/fg42_sc fills 20: 160 = 8 mags | ger2/squads:19 |
| jap/sniper.set:21 | type99sniper with arisaka7-7_clip 60 (no std) | none | old 1942-43 list sniper: 60; its 1944-45 replacement jap_sniper_type99 has 100 | units/jap/squads_42-43.set:90 vs squads_44-45.set:107 | jap/squads_42-43:90 +1 |
| jap/sniper2.set:21 | type97sniper with arisaka6-5_clip 60 (no std) | none | old 1942-43 list: 60; replacement jap_sniper_type97 has 100 | units/jap/squads_42-43.set:89 | jap/squads_42-43:89 |

### 9. Two loads split by unit kind, consistent across year lists (4, deliberate, confidence medium)

DATA: Soviet mosin_s snipers: buy-card snipers carry 120 in both year lists (sniper 1941-42, rus_sniper_mosin 1943-45); the hero jeep snipers carry 100 in both lists (sniper2 1943, rus_vetsniper 1944-45). Consistent pairs, so deliberate [I]. Odd only in that the veteran carries less.

| file:line | what | standard | reason | evidence | used in |
|---|---|---|---|---|---|
| rus/rus_sniper_mosin.set:21 | mosin_s with mosin_clip 120 (no std) | none | regular sniper card (1943-45): 120 | units/rus/squads_43-45.set:101 | rus/squads_43-45:101 |
| rus/rus_vetsniper.set:21 | mosin_s with mosin_clip 100 (no std) | none | hero jeep sniper (1944-45): 100 | units/rus/vehicles_44-45.set:122 | rus/vehicles_44-45:122 |
| rus/sniper.set:21 | mosin_s with mosin_clip 120 (no std) | none | regular sniper card (1941-42): 120 | units/rus/squads_41-42.set:96 | rus/squads_41-42:96 +1 |
| rus/sniper2.set:21 | mosin_s with mosin_clip 100 (no std) | none | hero jeep sniper (1943): 100 | units/rus/vehicles_43.set:98 | rus/vehicles_43:98 |

### 10. Role/tier: paratroopers and elites carry more (15, deliberate, confidence medium)

DATA: paratroopers (fallschirm, ss_fallschirm, ost_fallschirm, ita paratrooper, teishin, British para) and the elite/bersaglieri tiers carry 1.5-2x the standard of the same weapon, all whole clips. Same pattern in every side that has paratroopers, so deliberate [I].

| file:line | what | standard | reason | evidence | used in |
|---|---|---|---|---|---|
| axm/axm_ita_bersaglieri_smg.set:18 | mab_38a with mab_38a_mag 240, standard is 200 (+40) | mab_38a_mag 200 (4) | bersaglieri 240 on every weapon (rifle, mg assist, smg) | stuff/smg/mab_38a fills 40: 200 = 5 mags | axis_minor/squads:21 +3 |
| axm/axm_ita_paratrooper_smg.set:19 | mab_38a with mab_38a_mag 240, standard is 200 (+40) | mab_38a_mag 200 (4) | Italian paratroopers 240 on every weapon | stuff/smg/mab_38a fills 40: 200 = 5 mags | axis_minor/squads:34 |
| axm/axm_ita_paratrooper_squadleader.set:19 | mab_38a with mab_38a_mag 240, standard is 200 (+40) | mab_38a_mag 200 (4) | Italian paratroopers 240 | stuff/smg/mab_38a fills 40: 200 = 5 mags | axis_minor/squads:34 |
| eng/eng_paratroopr_em2.set:19 | em2 with british303_clip 100 (no std) | none | British paratrooper with em2: 100 | stuff/rifle/sniper/em2 fills 10: 100 = 10 mags | eng/vehicles_43-44:162 |
| ger/fallschirm_sa_41.set:20 | g41 with mauser_clip 120, standard is 80 (+40) | mauser_clip 80 (10) | paratrooper G41: 120 vs 80 in the 5 other _41 G41 breeds | fusilier_sa_41, grenadier_sa_41, jager_sa_41 = 80 | ger/squads_41:40 +3 |
| ger/fallschirm_sniper.set:22 | mauzer_s with mauser_clip 120, standard is 60 (+60) | mauser_clip 60 (8) | paratrooper sniper 120 vs 60 for ground snipers (sniper, ger_sniper_mauzer) | stuff/rifle/sniper/mauzer_s fills 5: 60 = 12 mags | ger/squads_41:40 +5 |
| ger/ger_fallschirm_sniper.set:22 | mauzer_s with mauser_clip 120, standard is 60 (+60) | mauser_clip 60 (8) | same as fallschirm_sniper | stuff/rifle/sniper/mauzer_s fills 5: 60 = 12 mags | ger/squads_44:76 +1 |
| ger2/ost_fallschirm_mg_asst.set:20 | mauzer_vet with mauser_clip 80, standard is 60 (+20) | mauser_clip 60 (20) | ger2 paratrooper MG assistant 80, same as ger fallschirm_mg_asst (macro rifle_mauzer_80) but with mauzer_vet |  | ger2/squads:19 |
| ger2/ost_fallschirm_sniper.set:22 | mauzer_s with mauser_clip 120, standard is 60 (+60) | mauser_clip 60 (8) | same (ger2 paratrooper sniper) | stuff/rifle/sniper/mauzer_s fills 5: 60 = 12 mags | ger2/squads:19 |
| ger_ss/ss_fallschirm_mg_asst.set:19 | mauzer with mauser_clip 90, standard is 60 (+30) | mauser_clip 60 (106) | SS paratrooper MG assistant 90 | stuff/rifle/mauzer fills 5: 60 = 12 mags | ger/squads_44:78 +1 |
| ger_ss/ss_fallschirm_rifle.set:19 | mauzer with mauser_clip 120, standard is 60 (+60) | mauser_clip 60 (106) | SS paratrooper rifle 120 | stuff/rifle/mauzer fills 5: 60 = 12 mags | ger/squads_44:78 +1 |
| jap/elite3.set:18 | type99_mg with type99_mag 240, standard is 180 (+60) | type99_mag 180 (10) | elite3 240 (elite tier) | units/jap/squads_42-43.set:25 | jap/squads_42-43:25 +1 |
| jap/elite4.set:18 | type100smg with type100_mag 240, standard is 180 (+60) | type100_mag 180 (25) | elite4 240 (elite tier) | units/jap/squads_42-43.set:25 | jap/squads_42-43:25 +1 |
| jap/jap_teishin_mg.set:18 | type99_mg with type99_mag 240, standard is 180 (+60) | type99_mag 180 (10) | teishin (paratroopers) 240 | stuff/mgun/type99_mg fills 30: 180 = 6 mags | jap/squads_44-45:36 +1 |
| jap/jap_teishin_type100_44_apminer.set:18 | type100_44 with type100_mag 240, standard is 180 (+60) | type100_mag 180 (3) | teishin 240 | stuff/smg/type100_44 fills 30: 180 = 6 mags | jap/squads_44-45:36 +1 |

### 11. Role: crew, officers, leaders, special carry less (12, deliberate, confidence medium)

DATA: tank crews, vehicle supporters, officers, a squad leader, the kamikaze and an AT-mine layer carry fewer rounds, all whole magazines (except axm_ita_vehicle_supporter, class 4). Same within each side's crew breeds (jap tankman/tankman2 used by 84/88 vehicle lines), so deliberate.

| file:line | what | standard | reason | evidence | used in |
|---|---|---|---|---|---|
| axm/axm_bul_miner_at.set:18 | mannlicher_m1895 with 8x50 25 (no std) | none | AT-mine layer: rifle 25 vs AP-miner twin 120 (carries 4 AT mines) | axm_bul_miner_ap 120 | axis_minor/squads:61 |
| axm/axm_bul_squadleader.set:18 | mp40 with mp40_mag 128, standard is 192 (-64) | mp40_mag 192 (73) | squad leader 128 = 4 mags vs 192 | stuff/smg/mp40 fills 32: 192 = 6 mags | axis_minor/squads:8 |
| axm/axm_fin_vehicle_supporter.set:20 | mosin_fin with 7x53 25, standard is 120 (-95) | 7x53 120 (7) | vehicle crew rifle with 25 (5 clips); infantry Finns 120 | stuff/rifle/mosin_fin fills 5: 120 = 24 mags | axis_minor/vehicles:32 +4 |
| axm/axm_hun_tankcommander.set:21 | danuvia_39m with 9x25 80 (no std) | none | tank commander SMG 80 = 2 mags | stuff/smg/danuvia_39m fills 40: 80 = 2 mags | axis_minor/vehicles:56 +14 |
| axm/axm_hun_tankcommander_single.set:21 | danuvia_39m with 9x25 80 (no std) | none | tank commander SMG 80 = 2 mags | stuff/smg/danuvia_39m fills 40: 80 = 2 mags | axis_minor/squads:36 |
| axm/axm_hun_vehicle_supporter.set:20 | danuvia_39m with 9x25 80 (no std) | none | vehicle crew SMG 80 = 2 mags | stuff/smg/danuvia_39m fills 40: 80 = 2 mags | axis_minor/vehicles:11 +3 |
| ger2/ost_officer2.set:25 | mp41 with mp40_mag 64, standard is 192 (-128) | mp40_mag 192 (7) | officer (hero card) MP41 64 = 2 mags | units/ger2/vehicles_all.set:127 | ger2/vehicles_all:127 |
| jap/jap_tankman2_single.set:19 | type100smg with type100_mag 30, standard is 180 (-150) | type100_mag 180 (25) | tank crew SMG 30 = 1 magazine | stuff/smg/type100smg fills 30: 180 = 6 mags | jap/squads_44-45:58 |
| jap/jap_tankman_single.set:19 | nambu with nambu_mag 24, standard is 32 (-8) | nambu_mag 32 (3) | tank crew pistol 24 = 3 mags vs officers 32 | stuff/pistol/nambu fills 8: 32 = 4 mags | jap/squads_44-45:58 |
| jap/kamikaze.set:21 | type100smg with type100_mag 60, standard is 180 (-120) | type100_mag 180 (25) | kamikaze 60 = 2 mags | stuff/smg/type100smg fills 30: 180 = 6 mags | jap/squads_42-43:63 |
| jap/tankman.set:19 | nambu with nambu_mag 24, standard is 32 (-8) | nambu_mag 32 (3) | tank crew pistol 24 = 3 mags | used by 84 vehicle lines | jap/squads_42-43:48 +45 |
| jap/tankman2.set:19 | type100smg with type100_mag 30, standard is 180 (-150) | type100_mag 180 (25) | tank crew SMG 30 = 1 magazine | used by 88 vehicle lines | jap/squads_42-43:48 +47 |

### 12. Role: MG assistants / ammo bearers (5, deliberate, confidence medium)

DATA: MG assistants carry more rounds or the gun's ammo. otsu_mg_ammo/_asst feed the Type 11 (it fills arisaka6-5_clip, the same clips they carry), which is the pattern jap_mg3_asst (class 3) breaks.

| file:line | what | standard | reason | evidence | used in |
|---|---|---|---|---|---|
| axm/axm_hun_assualt_mgun_assist.set:19 | feg_35m with 8x56 320 (no std) | none | MG assistant rifle 320 vs hun rifle 240 | stuff/rifle/feg_35m fills 5: 320 = 64 mags | axis_minor/squads:25 +1 |
| axm/axm_ita_alpini_mgun_assist.set:18 | m9138_carcano with 7x51 180 (no std) | none | alpini MG assistant 180 vs alpini rifle 160 | stuff/rifle/m9138_carcano fills 6: 180 = 30 mags | axis_minor/squads:27 +1 |
| eng/eng_anzac_mg_assist.set:18 | em3 followed by ammo it does not load ({item "ammo bren_mag" 224}) | british303_clip 50 (28) | assistant lists Bren magazines (224) before his own 100 rifle rounds; the em3 ammo is there | line 19 ammo british303_clip 100 | eng/vehicles_43-44:133 |
| jap/otsu_mg_ammo.set:18 | type38rifle_bayonet with arisaka6-5_clip 180, standard is 60 (+120) | arisaka6-5_clip 60 (9) | Type 11 team ammo bearer: 180 rifle rounds = 6 hoppers of the Type 11, which fills arisaka6-5_clip | stuff/mgun/type11_mg:3 | jap/vehicles_all:140 |
| jap/otsu_mg_asst.set:18 | type38rifle_bayonet with arisaka6-5_clip 180, standard is 60 (+120) | arisaka6-5_clip 60 (9) | Type 11 team assistant: 180, same reason | stuff/rifle/type38rifle_bayonet fills 5: 60 = 12 mags | jap/vehicles_all:140 |

### 13. Tier: militia, partisans, conscripts carry less (8, deliberate, confidence high)

DATA: Soviet home guard, partisans and conscripts carry 30-40 rifle rounds, 1 PPSh drum, 150 MG rounds: half the standard, all whole magazines. Deliberate.

| file:line | what | standard | reason | evidence | used in |
|---|---|---|---|---|---|
| rus/conscript_rifle.set:18 | mosin with mosin_clip 40, standard is 60 (-20) | mosin_clip 60 (30) | conscript 40 | stuff/rifle/mosin fills 5: 60 = 12 mags | rus/squads_41-42:7 |
| rus/home_guard.set:18 | mosin with mosin_clip 30, standard is 60 (-30) | mosin_clip 60 (30) | home guard 30 | stuff/rifle/mosin fills 5: 60 = 12 mags | rus/squads_41-42:5 +1 |
| rus/home_guard2.set:18 | ppsh with ppsh_mag 71, standard is 142 (-71) | ppsh_mag 142 (18) | home guard 1 drum | stuff/smg/ppsh fills 71: 142 = 2 mags | rus/squads_41-42:5 +1 |
| rus/home_guard_mg.set:18 | mg34 with mg_mauser drum 150, standard is 300 (-150) | mg_mauser drum 300 (19) | home guard MG 150 | stuff/mgun/mg34 fills 50: 300 = 6 mags | rus/squads_41-42:5 +1 |
| rus/rus_partisan_at.set:18 | mauzer with mauser_clip 30, standard is 60 (-30) | mauser_clip 60 (106) | partisan 30 | stuff/rifle/mauzer fills 5: 60 = 12 mags | rus/squads_43-45:4 |
| rus/rus_partisan_mg.set:18 | mg34 with mg_mauser drum 150, standard is 300 (-150) | mg_mauser drum 300 (19) | partisan MG 150 | stuff/mgun/mg34 fills 50: 300 = 6 mags | rus/squads_43-45:4 |
| rus/rus_partisan_rifle.set:18 | mosin with mosin_clip 30, standard is 60 (-30) | mosin_clip 60 (30) | partisan 30 | stuff/rifle/mosin fills 5: 60 = 12 mags | rus/squads_43-45:4 |
| rus/rus_partisan_smg.set:18 | ppsh with ppsh_mag 71, standard is 142 (-71) | ppsh_mag 142 (18) | partisan 1 drum | stuff/smg/ppsh fills 71: 142 = 2 mags | rus/squads_43-45:4 |

### 14. Side or unit-type number for weapons with no shared standard (16, deliberate, confidence medium)

DATA: weapons with no standard shared across sides, or a unit group that uses its own number: Bulgarian infantry 120, Hungarian 160-320, Italian alpini 160 / paratroopers 240, British commandos 50 (em3_vet; SAS/para em3_vet breeds 100). Within each group the value repeats, so deliberate.

| file:line | what | standard | reason | evidence | used in |
|---|---|---|---|---|---|
| axm/axm_bul_mgun_assist.set:18 | mauzer with mauser_rifle mauser 120, standard is mauser_clip 60 | mauser_clip 60 (106) | Bulgarian infantry 120 (ammo written `mauser_rifle mauser`, an alias of mauser_clip) | ammo/magazines/mauser_clip.mauser.mauser_rifle.ammo | axis_minor/squads:66 |
| axm/axm_bul_miner_ap.set:19 | mannlicher_m1895 with 8x50 120 (no std) | none | Bulgarian AP miner 120 | stuff/rifle/mannlicher_m1895 fills 5: 120 = 24 mags | axis_minor/squads:60 |
| axm/axm_bul_rifle.set:18 | mauzer with mauser_clip 120, standard is 60 (+60) | mauser_clip 60 (106) | Bulgarian infantry 120 | stuff/rifle/mauzer fills 5: 60 = 12 mags | axis_minor/squads:8 |
| axm/axm_fin_at_rifle.set:18 | boyes with ptr 50 (no std) | none | Finnish Boys 50 | stuff/rifle/ptr/boyes fills 5: 50 = 10 mags | axis_minor/squads:74 |
| axm/axm_hun_assualt_rifle.set:19 | feg_43m with 7x57 190 (no std) | none | Hungarian assault rifle 190 (38 clips) | stuff/rifle/feg_43m fills 5: 190 = 38 mags | axis_minor/squads:25 +1 |
| axm/axm_hun_rifle.set:18 | feg_35m with 8x56 240 (no std) | none | Hungarian rifle 240 | stuff/rifle/feg_35m fills 5: 240 = 48 mags | axis_minor/squads:16 |
| axm/axm_hun_rifle3.set:18 | feg_43m with 7x57 320 (no std) | none | Hungarian rifle3 320 | stuff/rifle/feg_43m fills 5: 320 = 64 mags | axis_minor/squads:16 |
| axm/axm_hun_smg_danuvia.set:18 | danuvia_39m with 9x25 160 (no std) | none | Hungarian SMG 160 = 4 mags | stuff/smg/danuvia_39m fills 40: 160 = 4 mags | axis_minor/squads:10 +1 |
| axm/axm_ita_alpini_mgun.set:18 | breda_30 with breda_mag 320 (no std) | none | alpini Breda 320 | stuff/mgun/breda_30 fills 20: 320 = 16 mags | axis_minor/squads:27 +1 |
| axm/axm_ita_alpini_smg.set:18 | mab_38a with mab_38a_mag 160, standard is 200 (-40) | mab_38a_mag 200 (4) | alpini 160 = 4 mags | stuff/smg/mab_38a fills 40: 200 = 5 mags | axis_minor/squads:27 |
| axm/axm_ita_alpini_squadleader.set:18 | mab_38a with mab_38a_mag 160, standard is 200 (-40) | mab_38a_mag 200 (4) | alpini 160 = 4 mags | stuff/smg/mab_38a fills 40: 200 = 5 mags | axis_minor/squads:27 |
| axm/axm_ita_paratrooper_mgun.set:19 | breda_30 with breda_mag 240 (no std) | none | paratrooper Breda 240 | stuff/mgun/breda_30 fills 20: 240 = 12 mags | axis_minor/squads:34 +1 |
| eng/elite2.set:18 | em3_vet with british303_clip 50, standard is 100 (-50) | british303_clip 100 (5) | commando group 50 (elite2, eng_commando_bren_assist, eng_commando_carbine); SAS/para em3_vet breeds 100 |  | eng/squads_40-41:58 |
| eng/eng_anzac_at_rifle.set:23 | boyes with ptr 25 (no std) | none | ANZAC Boys 25 | stuff/rifle/ptr/boyes fills 5: 25 = 5 mags | eng/vehicles_43-44:133 |
| eng/eng_commando_bren_assist.set:18 | em3_vet with british303_clip 50, standard is 100 (-50) | british303_clip 100 (5) | commando 50 |  | eng/squads_42-45:21 |
| eng/eng_commando_carbine.set:18 | em3_vet with british303_clip 50, standard is 100 (-50) | british303_clip 100 (5) | commando 50 |  | eng/squads_42-45:21 +1 |

### 15. Grenade / mine / smoke counts set per unit type or role (49, deliberate, confidence medium)

DATA: grenade, mine and smoke counts that no macro covers. Patterns: dedicated AP miners 25-34 mines (eng 34, rus 33, jap/usa 32, pioneer 31, guard 25) while the older ap_miner breeds use the 15 macro and the German s_mine miners 15-29; sappers 16/18 AP and 6 AT in rus and rus_guard alike; ANZAC 4 mk1 + 2 n73 on three breeds; SNLF and assault troops 2-4 type99; Hungarians 1-2 molotovs (Soviets 0-1 random). The 25-34 spread between near-identical AP miner files (same layout: SMG, mines, barbwire_kit, 5 bandages) has no visible reason [I]: possibly filled to an inventory limit per SMG weight; [T] to check.

| file:line | what | standard | reason | evidence | used in |
|---|---|---|---|---|---|
| axm/axm_bul_squadleader.set:21 | {"grenade m24x5" 2}, nearest at_grenade_m24x5_x0_1 = count 0 1 | at_grenade_m24x5_x0_1 (57) | squad leader 2 AT bundle grenades vs 0-1 random |  | axis_minor/squads:8 |
| axm/axm_fin_kaukopartio_rifle.set:29 | {"mine antipersonnel" 3}, nearest mine_antipersonnel_x5 = count 5 | mine_antipersonnel_x5 (18) | long-range patrol rifleman 3 AP mines |  | axis_minor/squads:18 +1 |
| axm/axm_fin_kaukopartio_squadleader.set:24 | {"smoke grenade" 3}, nearest smoke_x1 = count 1 | smoke_x1 (166) | patrol leader 3 smoke |  | axis_minor/squads:18 |
| axm/axm_hun_assualt_rifle.set:23 | {"grenade molotov_coctail" 1}, nearest fire_molotov_coctail_x0_1 = cou | fire_molotov_coctail_x0_1 (51) | Hungarian 1 molotov (side uses 1-2, Soviets 0-1 random) |  | axis_minor/squads:25 +1 |
| axm/axm_hun_rifle.set:22 | {"grenade molotov_coctail" 2}, nearest fire_molotov_coctail_x0_1 = cou | fire_molotov_coctail_x0_1 (51) | Hungarian rifleman 2 molotovs |  | axis_minor/squads:16 |
| axm/axm_hun_rifle3.set:22 | {"grenade molotov_coctail" 1}, nearest fire_molotov_coctail_x0_1 = cou | fire_molotov_coctail_x0_1 (51) | Hungarian 1 molotov |  | axis_minor/squads:16 |
| axm/axm_hun_smg_danuvia.set:22 | {"grenade molotov_coctail"}, nearest fire_molotov_coctail_x0_1 = count | fire_molotov_coctail_x0_1 (51) | no count = 1 molotov |  | axis_minor/squads:10 +1 |
| axm/axm_hun_smg_ppsh.set:22 | {"grenade molotov_coctail"}, nearest fire_molotov_coctail_x0_1 = count | fire_molotov_coctail_x0_1 (51) | no count = 1 molotov |  | axis_minor/squads:10 +1 |
| axm/axm_ita_alpini_smg.set:23 | {"ccm34smoke" 1}, nearest smoke_ccm34smoke_x2 = count 2 | smoke_ccm34smoke_x2 (4) | Italian smoke 1 |  | axis_minor/squads:27 |
| axm/axm_ita_paratrooper_squadleader.set:24 | {"ccm34smoke" 4}, nearest smoke_ccm34smoke_x2 = count 2 | smoke_ccm34smoke_x2 (4) | paratrooper leader 4 smoke |  | axis_minor/squads:34 |
| axm/axm_ita_vehicle_supporter.set:24 | {"ccm34smoke" 1}, nearest smoke_ccm34smoke_x2 = count 2 | smoke_ccm34smoke_x2 (4) | crew smoke 1 |  | axis_minor/squads:31 +17 |
| eng/eng_anzac_sl.set:21 | {"grenade mk1" 4}, nearest frag_mk1_x2 = count 2 | frag_mk1_x2 (72) | ANZAC 4 mk1 (3 breeds same) |  | eng/vehicles_43-44:133 |
| eng/eng_anzac_sl.set:22 | {"grenade n73at" 2}, nearest at_grenade_n73at_x1 = count 1 | at_grenade_n73at_x1 (48) | ANZAC 2 n73 AT |  | eng/vehicles_43-44:133 |
| eng/eng_anzac_smg.set:21 | {"grenade mk1" 4}, nearest frag_mk1_x2 = count 2 | frag_mk1_x2 (72) | ANZAC 4 mk1 |  | eng/vehicles_43-44:133 |
| eng/eng_anzac_smg.set:22 | {"grenade n73at" 2}, nearest at_grenade_n73at_x1 = count 1 | at_grenade_n73at_x1 (48) | ANZAC 2 n73 |  | eng/vehicles_43-44:133 |
| eng/eng_anzac_smg_thompson.set:21 | {"grenade mk1" 4}, nearest frag_mk1_x2 = count 2 | frag_mk1_x2 (72) | ANZAC 4 mk1 |  | eng/vehicles_43-44:133 |
| eng/eng_anzac_smg_thompson.set:22 | {"grenade n73at" 2}, nearest at_grenade_n73at_x1 = count 1 | at_grenade_n73at_x1 (48) | ANZAC 2 n73 |  | eng/vehicles_43-44:133 |
| eng/eng_ap_miner.set:20 | {"mine antipersonnel" 34}, nearest mine_antipersonnel_x5 = count 5 | mine_antipersonnel_x5 (18) | dedicated AP miner 34 |  | eng/squads_42-45:35 |
| eng/eng_at_miner.set:20 | {"mine antitank" 9}, nearest mine_antitank_x1 = count 1 | mine_antitank_x1 (15) | dedicated AT miner 9 (ger/rus/jap at_miner 7-8) |  | eng/squads_42-45:37 |
| eng/eng_pioneer_1trench.set:22 | {"grenade satchel" 2}, nearest frag_satchel_x1 = count 1 | frag_satchel_x1 (13) | pioneer 2 satchels |  | eng/squads_42-45:6 |
| eng/eng_pioneer_3trench.set:22 | {"mine antipersonnel" 7}, nearest mine_antipersonnel_x5 = count 5 | mine_antipersonnel_x5 (18) | pioneer 7 AP mines |  | eng/squads_42-45:6 |
| eng/eng_pioneer_ap_miner.set:22 | {"mine antipersonnel" 31}, nearest mine_antipersonnel_x5 = count 5 | mine_antipersonnel_x5 (18) | pioneer AP miner 31 |  | eng/squads_42-45:6 |
| eng/eng_pioneer_minedisposal.set:22 | {"mine antipersonnel" 7}, nearest mine_antipersonnel_x5 = count 5 | mine_antipersonnel_x5 (18) | mine-disposal pioneer 7 AP mines |  | eng/squads_42-45:6 |
| eng/saper2.set:20 | {"mine antitank" 6}, nearest mine_antitank_x1 = count 1 | mine_antitank_x1 (15) | sapper 6 AT mines (rus/guard sapper_rifle1 also 6) |  | eng/vehicles_41:66 +2 |
| ger2/ost_straf_ppsh.set:21 | {"dynamite_ladung" 1}, nearest explosive_dynamite_ladung_x2 = count 2 | explosive_dynamite_ladung_x2 (11) | penal-unit SMG 1 dynamite bundle vs 2 |  | ger2/vehicles_all:125 |
| ger_ss/ss_sturmpio4.set:22 | {"mine antitank" 3}, nearest mine_antitank_x1 = count 1 | mine_antitank_x1 (15) | SS assault pioneer 3 AT mines |  | ger/squads_44:42 |
| jap/jap_ap_miner.set:20 | {"mine antipersonnel" 32}, nearest mine_antipersonnel_x5 = count 5 | mine_antipersonnel_x5 (18) | AP miner 32 |  | jap/squads_44-45:48 |
| jap/jap_snlf_mg_asst.set:22 | {"grenade type99" 2}, nearest frag_type99_x1 = count 1 | frag_type99_x1 (5) | SNLF 2 type99 |  | jap/squads_44-45:44 +1 |
| jap/jap_snlf_rifle_type99.set:22 | {"grenade type99" 2}, nearest frag_type99_x1 = count 1 | frag_type99_x1 (5) | SNLF 2 type99 |  | jap/squads_44-45:44 |
| jap/jap_snlf_type100_44.set:21 | {"grenade type99" 4}, nearest frag_type99_x1 = count 1 | frag_type99_x1 (5) | SNLF SMG 4 type99 |  | jap/squads_44-45:44 |
| jap/sturmovik.set:21 | {"grenade type99" 4}, nearest frag_type99_x1 = count 1 | frag_type99_x1 (5) | assault 4 type99 |  | jap/squads_42-43:30 +1 |
| jap/sturmovik4.set:21 | {"grenade type99" 2}, nearest frag_type99_x1 = count 1 | frag_type99_x1 (5) | assault 2 type99 |  | jap/squads_42-43:30 +1 |
| rus/rus_ap_miner.set:21 | {"mine antipersonnel" 33}, nearest mine_antipersonnel_x5 = count 5 | mine_antipersonnel_x5 (18) | AP miner 33 |  | rus/squads_43-45:56 |
| rus/rus_sapper_rifle1.set:23 | {"mine antitank" 6}, nearest mine_antitank_x1 = count 1 | mine_antitank_x1 (15) | sapper 6 AT mines |  | rus/squads_43-45:16 |
| rus/rus_sapper_rifle2.set:23 | {"mine antipersonnel" 18}, nearest mine_antipersonnel_x5 = count 5 | mine_antipersonnel_x5 (18) | sapper 18 AP |  | rus/squads_43-45:16 |
| rus/rus_sapper_smg.set:23 | {"mine antipersonnel" 16}, nearest mine_antipersonnel_x5 = count 5 | mine_antipersonnel_x5 (18) | sapper 16 AP |  | rus/squads_43-45:16 |
| rus_guard/guard_ap_miner.set:21 | {"mine antipersonnel" 25}, nearest mine_antipersonnel_x5 = count 5 | mine_antipersonnel_x5 (18) | guard AP miner 25 |  | rus_guard/squads_43-45:36 |
| rus_guard/guard_sapper_rifle1.set:23 | {"mine antitank" 6}, nearest mine_antitank_x1 = count 1 | mine_antitank_x1 (15) | sapper 6 AT |  | rus_guard/squads_43-45:6 |
| rus_guard/guard_sapper_rifle2.set:23 | {"mine antipersonnel" 18}, nearest mine_antipersonnel_x5 = count 5 | mine_antipersonnel_x5 (18) | sapper 18 AP |  | rus_guard/squads_43-45:6 |
| rus_guard/guard_sapper_smg.set:23 | {"mine antipersonnel" 16}, nearest mine_antipersonnel_x5 = count 5 | mine_antipersonnel_x5 (18) | sapper 16 AP |  | rus_guard/squads_43-45:6 |
| usa/usa_ap_miner.set:21 | {"mine antipersonnel" 32}, nearest mine_antipersonnel_x5 = count 5 | mine_antipersonnel_x5 (18) | AP miner 32 |  | usa/squads_43-45:55 |
| usa/usa_armor_rifle.set:21 | {"grenade m61" 1}, nearest frag_m61_x2 = count 2 | frag_m61_x2 (100) | armored-infantry rifleman 1 grenade |  | usa/squads_43-45:4 +1 |
| usa/usa_engineer.set:22 | {"grenade satchel" 2}, nearest frag_satchel_x1 = count 1 | frag_satchel_x1 (13) | engineer 2 satchels |  | usa/squads_43-45:16 |
| usa/usa_engineer2.set:22 | {"mine antipersonnel" 20}, nearest mine_antipersonnel_x5 = count 5 | mine_antipersonnel_x5 (18) | engineer 20 AP mines |  | usa/squads_43-45:16 |
| usa/usa_engineer3.set:22 | {"mine antitank" 5}, nearest mine_antitank_x1 = count 1 | mine_antitank_x1 (15) | engineer 5 AT mines |  | usa/squads_43-45:16 |
| usa/usa_engineer4.set:22 | {"grenade satchel" 2}, nearest frag_satchel_x1 = count 1 | frag_satchel_x1 (13) | engineer 2 satchels |  | usa/squads_43-45:16 |
| usa/usa_nightfighter_carbine.set:54 | {"grenade m61" 1}, nearest frag_m61_x2 = count 2 | frag_m61_x2 (100) | night fighter 1 grenade |  | usa/vehicles_43-45:126 |
| usa/usa_nightfighter_leader.set:23 | {"grenade m61" 1}, nearest frag_m61_x2 = count 2 | frag_m61_x2 (100) | night fighter leader 1 grenade |  | usa/vehicles_43-45:126 |
| usa/usa_raiderdemo.set:25 | {"dynamite" 3}, nearest explosive_dynamite_x1 = count 1 | explosive_dynamite_x1 (26) | demolition man 3 dynamite |  | usa/vehicles_43-45:137 |

### 16. Random count form (n dev) (9, deliberate, confidence medium)

DATA: `{item "x" n dev}` gives n plus a uniform random in [-dev, +dev], rounded (modweb/humans/breeds.md:15, from code reading, not run). So `0 1` = 0 or 1 (one 25% of the time), `0.25 1` = 0 or 1 (about 37%), `1.5 0.5` = 1 or 2 (50/50). Volksgrenadiers get 1.5 vs 2: tier. `0.25 1` on eng squad leaders and guard elites vs `0 1` on their line troops: a slightly higher chance for leaders/elites [I].

| file:line | what | standard | reason | evidence | used in |
|---|---|---|---|---|---|
| eng/eng_smg_wp.set:22 | {"grenade n73at" 0 1}, nearest at_grenade_n73at_x1 = count 1 (odd coun | at_grenade_n73at_x1 (48) | `0 1` = 0 +-1 random: 0 or 1 (25% one) | humans/breeds.md:15 | eng/squads_42-45:55 |
| eng/eng_squadleader.set:22 | {"grenade n73at" 0.25 1}, nearest at_grenade_n73at_x1 = count 1 (odd c | at_grenade_n73at_x1 (48) | `0.25 1`: 0 or 1 (about 37% one) |  | eng/squads_42-45:11 +2 |
| eng/eng_squadleader2.set:22 | {"grenade n73at" 0.25 1}, nearest at_grenade_n73at_x1 = count 1 (odd c | at_grenade_n73at_x1 (48) | `0.25 1` |  | eng/squads_42-45:4 |
| ger/ger_volksgren_pzfst2.set:22 | {"grenade m24" 1.5 0.5}, nearest frag_m24_x2 = count 2 (odd count form | frag_m24_x2 (244) | `1.5 0.5`: 1 or 2 grenades (50/50) vs 2 |  | ger/squads_44:10 +2 |
| ger/ger_volksgren_smg.set:21 | {"grenade m24" 1.5 0.5}, nearest frag_m24_x2 = count 2 (odd count form | frag_m24_x2 (244) | `1.5 0.5` |  | ger/squads_44:10 +1 |
| ger/ger_volksgren_stg44.set:21 | {"grenade m24" 1.5 0.5}, nearest frag_m24_x2 = count 2 (odd count form | frag_m24_x2 (244) | `1.5 0.5` |  | ger/squads_44:10 +2 |
| rus_guard/guard_elite_guard_rifle.set:25 | {"grenade rpg43" 0.25 1}, nearest at_grenade_rpg43_x1 = count 1 (odd c | at_grenade_rpg43_x1 (18) | `0.25 1` vs guard line `0 1` |  | rus_guard/squads_43-45:26 |
| rus_guard/guard_elite_guard_sa.set:26 | {"grenade rpg43" 0.25 1}, nearest at_grenade_rpg43_x1 = count 1 (odd c | at_grenade_rpg43_x1 (18) | `0.25 1` |  | rus_guard/squads_43-45:26 |
| rus_guard/guard_elite_guard_sl.set:25 | {"grenade rpg43" 0.25 1}, nearest at_grenade_rpg43_x1 = count 1 (odd c | at_grenade_rpg43_x1 (18) | `0.25 1` |  | rus_guard/squads_43-45:24 +1 |

### 17. Spare ammo belongs to a second weapon the breed carries (1, not a deviation, confidence high)

DATA: axm_rom_bazooker_assist carries smg_orita (fills 9x19) plus valter plus `ammo 9x19` 40: the 40 rounds are extra Orita ammo, not pistol ammo. Not a deviation; the twin axm_rom_bazooker (class 1) copied the 9x19 line without the Orita.

| file:line | what | standard | reason | evidence | used in |
|---|---|---|---|---|---|
| axm/axm_rom_bazooker_assist.set:20 | valter followed by ammo it does not load ({item  "ammo 9x19" 40}) | walther_mag 16 (57) | valter + `ammo 9x19` 40, but this breed also carries the Orita SMG (`smg_orita`), which fills 9x19: the 40 rounds are extra Orita ammo; the valter has only its filled 8 | stuff/smg/orita filling "ammo 9x19"; breed_kit.inc:249 smg_orita | axis_minor/squads:83 |

### 18. Same load written another way (tool artifact) (21, not a deviation, confidence high)

DATA: `{item "ppsh41" filling "ammo ppsh41_mag" 35}` with a full magazine is the same as `filled`. Item names are tag sets, so `"garand_clip ammo"` = `"ammo garand_clip"` (modweb/humans/breeds.md:15 [I], not run). A literal with no count is count 1, the same as the _x1 macro. Side notes: Soviet tank crews carry 210 ppsh41 rounds (6 mags, standard 105); usa_raider/_raiderasst carry 88 garand (11 clips, standard 80); usa_raiderdemo 180 m3a (5.6 mags, standard 192).

| file:line | what | standard | reason | evidence | used in |
|---|---|---|---|---|---|
| eng/eng_rifleman_smoke.set:33 | {"grenade mk1"}, nearest frag_mk1_x2 = count 2 | frag_mk1_x2 (72) | `{item "grenade mk1"}` no count = 1 = macro frag_mk1_x1 (12 uses) |  | eng/squads_42-45:11 +3 |
| rus/rus_bazookerassist.set:22 | {"grenade rpg40"}, nearest at_grenade_rpg40_x1 = count 1 | at_grenade_rpg40_x1 (20) | no count = 1 = at_grenade_rpg40_x1 |  | rus/squads_43-45:87 |
| rus/rus_elite_tankcommander.set:19 | other weapon form: {item "pps43" filling "ammo pps43_mag" 35} | pps43_mag 210 (14) | `filling "ammo pps43_mag" 35` = one full magazine = `filled` |  | **none** |
| rus/rus_elite_tankman.set:19 | other weapon form: {item "ppsh41" filling "ammo ppsh41_mag" 35} | ppsh41_mag 105 (16) | `filling "ammo ppsh41_mag" 35` = filled |  | **none** |
| rus/vet_tankman.set:19 | other weapon form: {item "ppsh41" filling "ammo ppsh41_mag" 35} | ppsh41_mag 105 (16) | `filling "<ammo>" <mag size>` = one full magazine = `filled` |  | rus/squads_41-42:54 +3 |
| rus_guard/elite_tankman.set:19 | other weapon form: {item "ppsh41" filling "ammo ppsh41_mag" 35} | ppsh41_mag 105 (16) | `filling "<ammo>" <mag size>` = one full magazine = `filled` |  | rus_guard/vehicles_43-45:113 +2 |
| rus_guard/elite_tankman2.set:19 | other weapon form: {item "pps43" filling "ammo pps43_mag" 35} | pps43_mag 210 (14) | `filling "<ammo>" <mag size>` = one full magazine = `filled` |  | rus_guard/vehicles_43-45:113 +2 |
| rus_guard/guard_elite_tankcommander.set:19 | other weapon form: {item "pps43" filling "ammo pps43_mag" 35} | pps43_mag 210 (14) | `filling "<ammo>" <mag size>` = one full magazine = `filled` |  | **none** |
| rus_guard/guard_elite_tankman.set:19 | other weapon form: {item "ppsh41" filling "ammo ppsh41_mag" 35} | ppsh41_mag 105 (16) | `filling "<ammo>" <mag size>` = one full magazine = `filled` |  | **none** |
| rus_guard/rus_guard_tankman2_single.set:19 | other weapon form: {item "pps43" filling "ammo pps43_mag" 35} | pps43_mag 210 (14) | `filling "<ammo>" <mag size>` = one full magazine = `filled` |  | rus_guard/squads_43-45:46 |
| rus_guard/rus_guard_vet_tankman2_single.set:19 | other weapon form: {item "pps43" filling "ammo pps43_mag" 35} | pps43_mag 210 (14) | `filling "<ammo>" <mag size>` = one full magazine = `filled` |  | rus_guard/squads_43-45:48 |
| rus_guard/tankman2.set:19 | other weapon form: {item "pps43" filling "ammo pps43_mag" 35} | pps43_mag 210 (14) | `filling "<ammo>" <mag size>` = one full magazine = `filled` |  | rus_guard/vehicles_43-45:45 +42 |
| rus_guard/vet_tankman.set:19 | other weapon form: {item "ppsh41" filling "ammo ppsh41_mag" 35} | ppsh41_mag 105 (16) | `filling "<ammo>" <mag size>` = one full magazine = `filled` |  | vehicles:393 +1 |
| rus_guard/vet_tankman2.set:19 | other weapon form: {item "pps43" filling "ammo pps43_mag" 35} | pps43_mag 210 (14) | `filling "<ammo>" <mag size>` = one full magazine = `filled` |  | vehicles:393 +1 |
| usa/usa_engineer.set:23 | {"mine antitank"}, nearest mine_antitank_x1 = count 1 | mine_antitank_x1 (15) | no count = 1 = mine_antitank_x1 |  | usa/squads_43-45:16 |
| usa/usa_raider.set:24 | other weapon form: {item "garand" filling "garand_clip ammo" 8} | garand_clip 80 (51) | `"garand_clip ammo"` (words reversed) for filling and spare; item lookup is by tag set, so same item [I]; spare 88 = 11 clips vs 80 | modweb/humans/breeds.md:15, humans/inventory.md:18 | usa/vehicles_43-45:137 |
| usa/usa_raiderasst.set:24 | other weapon form: {item "garand" filling "garand_clip ammo" 8} | garand_clip 80 (51) | same as usa_raider; also carries `bar_mag ammo` 180 for the BAR man |  | usa/vehicles_43-45:137 |
| usa/usa_raiderbar.set:24 | other weapon form: {item "bar_rifle" filling "bar_mag ammo" 20} | bar_mag 240 (12) | BAR `filling "bar_mag ammo" 20` = filled |  | usa/vehicles_43-45:137 |
| usa/usa_raiderdemo.set:26 | other weapon form: {item "m3a" filling "m3a_mag ammo" 32} | m3a_mag 192 (8) | M3A `filling "m3a_mag ammo" 32` = filled; spare 180 (5.6 mags) vs 192 |  | usa/vehicles_43-45:137 |
| usa/usa_ranger_sniper.set:29 | other weapon form: {item "m1903a4" filling "springfield_clip ammo" 5} | springfield_clip 100 (4) | m1903a4 `filling ... 5` = filled |  | usa/squads_43-45:41 |
| rus/rus_bazooker.set:20 | {"grenade rpg40"}, nearest at_grenade_rpg40_x1 = count 1 | at_grenade_rpg40_x1 (20) | no count = 1 = at_grenade_rpg40_x1 |  | rus/squads_43-45:87 |

### 19. Ammo is present, listed after another item (tool artifact) (24, not a deviation, confidence high)

DATA: the outline step reads the line right after a weapon as its ammo. Here a flare gun, a second weapon or another item sits between the weapon and its ammo, and the ammo follows later in the same inventory. Order does not matter to the engine. Side note: usa_radioman_240 carries 128 m3a rounds while the other four US radiomen carry 192. [I] "Order does not matter" is from the item-by-tag rule, not tested.

| file:line | what | standard | reason | evidence | used in |
|---|---|---|---|---|---|
| axm/axm_fin_sissi_mgun_assist_vision.set:19 | mosin_fin with no ammo line (next: {item  "LSM26_mag" 400}) | 7x53 120 (7) | `mosin_fin` then `{item  "LSM26_mag" 400}` (MG ammo for the gunner) then its own `ammo 7x53` 120 | file lines 19-21 | axis_minor/vehicles:123 |
| axm/axm_rom_bazooker.set:18 | weapon panzershreck with no ammo line (next: {item "valter" filled}) | panzershreck 7 (4) | SMG/launcher, then a flare gun or other item, then its ammo |  | axis_minor/squads:83 |
| ger/bazooker.set:18 | weapon panzershreck with no ammo line (next: {item "bandage" 3}) | panzershreck 7 (4) | SMG/launcher, then a flare gun or other item, then its ammo |  | ger/squads_43:97 |
| ger/ger_panzerschreck.set:18 | weapon panzershreck with no ammo line (next: {item "bandage" 3}) | panzershreck 7 (4) | SMG/launcher, then a flare gun or other item, then its ammo |  | ger/squads_44:133 |
| ger/ger_pzgren_panzershreck.set:18 | weapon panzershreck with no ammo line (next: {item "bandage" 5}) | panzershreck 7 (4) | SMG/launcher, then a flare gun or other item, then its ammo |  | ger/squads_44:137 |
| ger/ger_pzgren_pio_at.set:18 | weapon panzershreck with no ammo line (next: {item "bandage" 3}) | panzershreck 7 (4) | SMG/launcher, then a flare gun or other item, then its ammo |  | ger/squads_44:46 |
| ger/ger_volksgren_mg.set:20 | valter with no ammo line (next: {item "small_shovel" 1}) | walther_mag 16 (57) | `valter` then small_shovel then `ammo walther_mag` 16 |  | ger/squads_44:8 +2 |
| ger/sturmovik5.set:18 | weapon panzershreck with no ammo line (next: {item "bandage" 5}) | panzershreck 7 (4) | SMG/launcher, then a flare gun or other item, then its ammo |  | ger/squads_43:99 |
| ger2/ost_panzershreck.set:18 | weapon panzershreck with no ammo line (next: {item "bandage" 3}) | panzershreck 7 (4) | SMG/launcher, then a flare gun or other item, then its ammo |  | ger2/squads:47 +1 |
| ger_ss/ss_sturmpio_at.set:18 | weapon panzershreck with no ammo line (next: {item "bandage" 3}) | panzershreck 7 (4) | SMG/launcher, then a flare gun or other item, then its ammo |  | ger/squads_44:42 |
| jap/jap_snlf_at2.set:18 | weapon weapon type_4at with no ammo line (next: {item "type100smg" fil | type_4 5 (5) | `weapon weapon type_4at` (word doubled; tag lookup still finds type_4at.weapon [I]); ammo type_4 7 later in the list (standard 5) | stuff/bazooka/type_4at.weapon | jap/squads_44-45:84 |
| jap/jap_type4_atassist.set:18 | weapon weapon type_4at with no ammo line (next: {item "type100smg" fil | type_4 5 (5) | same doubled word; ammo type_4 7 later |  | jap/squads_44-45:82 |
| axm/axm_bul_radioman.set:18 | mp40 with no ammo line (next: {item "mortar_flaergun" filled}) | mp40_mag 192 (73) | SMG/launcher, then a flare gun or other item, then its ammo |  | axis_minor/squads:85 |
| eng/eng_radioman_airstrike.set:18 | sten_mk2 with no ammo line (next: {item "airstrike_rp3_flaregun" fille | sten_mag 128 (28) | SMG/launcher, then a flare gun or other item, then its ammo |  | eng/vehicles_43-44:158 |
| ger/ger_radioman_mortar.set:18 | mp40 with no ammo line (next: {item "mortar_flaergun" filled}) | mp40_mag 192 (73) | SMG/launcher, then a flare gun or other item, then its ammo |  | ger/squads_44:191 |
| ger/radioman_mortar.set:18 | mp40 with no ammo line (next: {item "mortar_flaergun" filled}) | mp40_mag 192 (73) | SMG/launcher, then a flare gun or other item, then its ammo |  | ger/squads_41:114 +2 |
| ger2/ost_radioman.set:18 | mp40 with no ammo line (next: {item "mortar_flaergun" filled}) | mp40_mag 192 (73) | SMG/launcher, then a flare gun or other item, then its ammo |  | **none** |
| rus/radioman_mortar.set:18 | ppsh with no ammo line (next: {item "mortar_flaergun" filled}) | ppsh_mag 142 (18) | SMG/launcher, then a flare gun or other item, then its ammo |  | rus/squads_41-42:103 |
| rus/rus_radioman_mortar.set:18 | ppsh with no ammo line (next: {item "mortar_flaergun" filled}) | ppsh_mag 142 (18) | SMG/launcher, then a flare gun or other item, then its ammo |  | rus/squads_43-45:107 |
| usa/radioman_mortar.set:18 | m3a with no ammo line (next: {item "mortar_flaergun" filled}) | m3a_mag 192 (8) | SMG/launcher, then a flare gun or other item, then its ammo |  | usa/squads_42:103 |
| usa/usa_radioman_105.set:18 | m3a with no ammo line (next: {item "artillery_105_flaregun" filled}) | m3a_mag 192 (8) | SMG/launcher, then a flare gun or other item, then its ammo |  | usa/squads_43-45:119 |
| usa/usa_radioman_155.set:18 | m3a with no ammo line (next: {item "artillery_155_flaregun" filled}) | m3a_mag 192 (8) | SMG/launcher, then a flare gun or other item, then its ammo |  | usa/squads_43-45:120 |
| usa/usa_radioman_240.set:18 | m3a with no ammo line (next: {item "artillery_240_flaregun" filled}) | m3a_mag 192 (8) | SMG/launcher, then a flare gun or other item, then its ammo |  | usa/squads_43-45:121 |
| usa/usa_radioman_mortar.set:18 | m3a with no ammo line (next: {item "mortar_flaergun" filled}) | m3a_mag 192 (8) | SMG/launcher, then a flare gun or other item, then its ammo |  | usa/squads_43-45:118 |

### 20. Weapon used by under 4 breeds: no macro by the 4-use rule (81, not a deviation, confidence high)

DATA: the macro step makes a macro only for loads used 4+ times. Each of these weapons appears in 1-3 breeds and the row's load is that weapon's most used one (or the weapon has no repeat at all). Nothing to fix. Includes unique weapons (Owen, Solothurn, De Lisle, Type 4 rifle, M18 recoilless, flare guns, light mortars), tank-crew pistols and the 2-3 officer breeds per side.

| file:line | what | standard | reason | evidence | used in |
|---|---|---|---|---|---|
| axm/axm_bul_mgun.set:18 | zb_vz26 with zb_vz26_mag 120 (only load) | zb_vz26_mag 120 (1) | only load of a weapon used by <4 breeds | stuff/mgun/zb_vz26 fills 20: 120 = 6 mags | axis_minor/squads:66 |
| axm/axm_fin_kaukopartio_mgun.set:18 | lsm26 with LSM26_mag 320 (only load) | LSM26_mag 320 (2) | only load of a weapon used by <4 breeds | stuff/mgun/lsm26 fills 20: 320 = 16 mags | axis_minor/squads:18 |
| axm/axm_fin_sissi_mgun_vision.set:18 | lsm26 with LSM26_mag 320 (only load) | LSM26_mag 320 (2) | only load of a weapon used by <4 breeds | stuff/mgun/lsm26 fills 20: 320 = 16 mags | axis_minor/vehicles:123 |
| axm/axm_fin_sniper.set:22 | mosin_s_fin with 7x53 120 (only load) | 7x53 120 (1) | only load of a weapon used by <4 breeds | stuff/rifle/sniper/mosin_s_fin fills 5: 120 = 24 mags | axis_minor/squads:89 |
| axm/axm_hun_assualt_mgun.set:19 | solothurn_31m with solothurn31m_mag 240 (only load) | solothurn31m_mag 240 (1) | only load of a weapon used by <4 breeds | stuff/mgun/solothurn_31m fills 30: 240 = 8 mags | axis_minor/squads:25 +2 |
| axm/axm_hun_squadleader_smg.set:18 | danuvia_43m with 9x25 160 (only load) | 9x25 160 (1) | only load of a weapon used by <4 breeds | stuff/smg/danuvia_43m fills 40: 160 = 4 mags | axis_minor/squads:10 +1 |
| axm/axm_ita_alpini_mgun.set:20 | beretta_m1934 with 9x17 35 (only load) | 9x17 35 (2) | only load of a weapon used by <4 breeds | stuff/pistol/beretta_m1934 fills 7: 35 = 5 mags | axis_minor/squads:27 +1 |
| axm/axm_ita_bersaglieri_mgun.set:20 | beretta_m1934 with 9x17 35 (only load) | 9x17 35 (2) | only load of a weapon used by <4 breeds | stuff/pistol/beretta_m1934 fills 7: 35 = 5 mags | axis_minor/squads:21 +2 |
| axm/axm_ita_bersaglieri_mgun_assist.set:18 | carcano_m91 with 6x52 240 (only load) | 6x52 240 (2) | only load of a weapon used by <4 breeds | stuff/rifle/carcano_m91 fills 6: 240 = 40 mags | axis_minor/squads:21 +4 |
| axm/axm_ita_bersaglieri_rifle.set:18 | carcano_m91 with 6x52 240 (only load) | 6x52 240 (2) | only load of a weapon used by <4 breeds | stuff/rifle/carcano_m91 fills 6: 240 = 40 mags | axis_minor/squads:21 +4 |
| axm/axm_ita_bersaglieri_rifle2.set:18 | m38_carcano with 7x51 240 (only load) | 7x51 240 (1) | only load of a weapon used by <4 breeds | stuff/rifle/m38_carcano fills 6: 240 = 40 mags | axis_minor/squads:21 |
| axm/axm_ita_paratrooper_mgun_assist.set:19 | scottix with 6x52 240 (only load) | 6x52 240 (2) | only load of a weapon used by <4 breeds | stuff/rifle/scottix fills 6: 240 = 40 mags | axis_minor/squads:34 +1 |
| axm/axm_ita_paratrooper_rifle.set:19 | scottix with 6x52 240 (only load) | 6x52 240 (2) | only load of a weapon used by <4 breeds | stuff/rifle/scottix fills 6: 240 = 40 mags | axis_minor/squads:34 |
| axm/axm_ita_tankcommander.set:21 | glisenti with 9x19c 35 (only load) | 9x19c 35 (2) | only load of a weapon used by <4 breeds | stuff/pistol/glisenti fills 7: 35 = 5 mags | axis_minor/vehicles:51 +15 |
| axm/axm_ita_tankman.set:19 | Bodeo_m1889 with 10x20 30 (only load) | 10x20 30 (2) | only load of a weapon used by <4 breeds | stuff/pistol/Bodeo_m1889 fills 6: 30 = 5 mags | axis_minor/vehicles:51 +14 |
| axm/axm_ita_vettankcommander.set:21 | glisenti with 9x19c 35 (only load) | 9x19c 35 (2) | only load of a weapon used by <4 breeds | stuff/pistol/glisenti fills 7: 35 = 5 mags | axis_minor/vehicles:147 |
| axm/axm_ita_vettankman.set:19 | Bodeo_m1889 with 10x20 30 (only load) | 10x20 30 (2) | only load of a weapon used by <4 breeds | stuff/pistol/Bodeo_m1889 fills 6: 30 = 5 mags | axis_minor/vehicles:147 |
| axm/axm_rom_mgun.set:18 | zb_30lmg with zb30_mag 240 (only load) | zb30_mag 240 (1) | only load of a weapon used by <4 breeds | stuff/mgun/zb_30lmg fills 30: 240 = 8 mags | axis_minor/squads:12 |
| axm/axm_rom_rifle.set:18 | zb_24rifle with 7x57 120 (only load) | 7x57 120 (1) | only load of a weapon used by <4 breeds | stuff/rifle/zb_24rifle fills 5: 120 = 24 mags | axis_minor/squads:12 +1 |
| axm/axm_rom_tankcommander.set:21 | steyer_pistol_1912 with 9x19 40 (only load) | 9x19 40 (1) | only load of a weapon used by <4 breeds | stuff/pistol/steyer_pistol_1912 fills 8: 40 = 5 mags | axis_minor/vehicles:59 +3 |
| eng/eng_anzac_smg.set:18 | owen_gun with owen_mag 320 (only load) | owen_mag 320 (1) | only load of a weapon used by <4 breeds | stuff/smg/owen_gun fills 32: 320 = 10 mags | eng/vehicles_43-44:133 |
| eng/eng_commando_silence_carbine.set:18 | de_lisle with rifle 70 (only load) | rifle 70 (2) | only load of a weapon used by <4 breeds | stuff/rifle/de_lisle fills 7: 70 = 10 mags | eng/squads_42-45:19 |
| eng/eng_commando_silencesmg.set:18 | sten_v_silencer with sten_mag 128 (only load) | sten_mag 128 (2) | only load of a weapon used by <4 breeds | stuff/smg/sten_v_silencer fills 32: 128 = 4 mags | eng/squads_42-45:19 |
| eng/eng_light_mortar.set:18 | mortar_mkvii with mortar50 eng fg 6 (only load) | mortar50 eng fg 6 (1) | only load of a weapon used by <4 breeds | stuff/reactive/mortar_mkvii fills 1: 6 = 6 mags | _macros.inc:1205 +1 |
| eng/eng_sas_bran_assist.set:23 | weapon piatrocket with piatrocket 5 (only load) | piatrocket 5 (2) | only load of a weapon used by <4 breeds |  | eng/squads_42-45:27 +1 |
| eng/sturmovik3.set:23 | weapon piatrocket with piatrocket 5 (only load) | piatrocket 5 (2) | only load of a weapon used by <4 breeds |  | eng/squads_40-41:20 +2 |
| ger/fallschirm_sa.set:20 | g43 with g43_mag 20 (only load) | g43_mag 20 (3) | only load of a weapon used by <4 breeds | stuff/rifle/g43 fills 10: 20 = 2 mags | ger/squads_43:47 +1 |
| ger/ger_light_mortar.set:19 | mortar_legrw_36 with mortar50 ger fg 12 (only load) | mortar50 ger fg 12 (3) | only load of a weapon used by <4 breeds | stuff/reactive/mortar_legrw_36 fills 1: 12 = 12 mags | ger/vehicles_41:30 +5 |
| ger/ger_volkssturm_smg_faustpatrone.set:18 | mp3008 with mp40_mag 192 (only load) | mp40_mag 192 (1) | only load of a weapon used by <4 breeds | stuff/smg/mp3008 fills 32: 192 = 6 mags | ger/squads_44:4 |
| ger/ger_volkssturm_smg_panzerfaust.set:18 | vsg with stg44_mag 180 (only load) | stg44_mag 180 (1) | only load of a weapon used by <4 breeds | stuff/rifle/vsg fills 30: 180 = 6 mags | ger/squads_44:4 |
| ger2/ost_light_mortar.set:19 | mortar_legrw_36 with mortar50 ger fg 12 (only load) | mortar50 ger fg 12 (3) | only load of a weapon used by <4 breeds | stuff/reactive/mortar_legrw_36 fills 1: 12 = 12 mags | ger2/vehicles_all:50 +1 |
| ger2/ost_rifle2.set:18 | g43 with g43_mag 20 (only load) | g43_mag 20 (3) | only load of a weapon used by <4 breeds | stuff/rifle/g43 fills 10: 20 = 2 mags | ger2/squads:11 |
| ger2/ost_sl_asst.set:18 | g43 with g43_mag 20 (only load) | g43_mag 20 (3) | only load of a weapon used by <4 breeds | stuff/rifle/g43 fills 10: 20 = 2 mags | ger2/squads:9 +1 |
| ger2/ost_straf_mp28.set:18 | mp28 with mp28_mag 180 (only load) | mp28_mag 180 (1) | only load of a weapon used by <4 breeds | stuff/smg/mp28 fills 30: 180 = 6 mags | ger2/vehicles_all:125 |
| ger_ss/ss_light_mortar.set:19 | mortar_legrw_36 with mortar50 ger fg 12 (only load) | mortar50 ger fg 12 (3) | only load of a weapon used by <4 breeds | stuff/reactive/mortar_legrw_36 fills 1: 12 = 12 mags | _macros.inc:1261 +1 |
| jap/elite_ig1h.set:18 | type_4_rifle with arisaka7-7_clip 60 (only load) | arisaka7-7_clip 60 (3) | only load of a weapon used by <4 breeds | stuff/rifle/type_4_rifle fills 10: 60 = 6 mags | jap/vehicles_all:147 |
| jap/elite_ig1h_ammo.set:18 | type_4_rifle with arisaka7-7_clip 60 (only load) | arisaka7-7_clip 60 (3) | only load of a weapon used by <4 breeds | stuff/rifle/type_4_rifle fills 10: 60 = 6 mags | **none** |
| jap/elite_ig1h_asst.set:18 | type_4_rifle with arisaka7-7_clip 60 (only load) | arisaka7-7_clip 60 (3) | only load of a weapon used by <4 breeds | stuff/rifle/type_4_rifle fills 10: 60 = 6 mags | **none** |
| jap/elite_ig2_scoped.set:18 | type99_mg_scoped with type99_mag 180 (only load) | type99_mag 180 (1) | only load of a weapon used by <4 breeds | stuff/mgun/type99_mg_scoped fills 30: 180 = 6 mags | **none** |
| jap/jap_charger_smg_type100_44.set:18 | type100_44_bayonet with type100_mag 180 (only load) | type100_mag 180 (3) | only load of a weapon used by <4 breeds | stuff/smg/type100_44_bayonet fills 30: 180 = 6 mags | jap/squads_44-45:4 |
| jap/jap_elite_takasago_smg2.set:19 | type100_44_bayonet with type100_mag 180 (only load) | type100_mag 180 (3) | only load of a weapon used by <4 breeds | stuff/smg/type100_44_bayonet fills 30: 180 = 6 mags | jap/squads_44-45:34 |
| jap/jap_kanoeshidan_type100_44.set:18 | type100_44 with type100_mag 180 (only load) | type100_mag 180 (3) | only load of a weapon used by <4 breeds | stuff/smg/type100_44 fills 30: 180 = 6 mags | jap/squads_44-45:30 +1 |
| jap/jap_mgun2.set:18 | type96_mg with type96_mag 180 (only load) | type96_mag 180 (2) | only load of a weapon used by <4 breeds | stuff/mgun/type96_mg fills 30: 180 = 6 mags | jap/squads_44-45:14 +5 |
| jap/jap_mgun3.set:18 | type11_mg with arisaka6-5_clip 180 (only load) | arisaka6-5_clip 180 (3) | only load of a weapon used by <4 breeds | stuff/mgun/type11_mg fills 30: 180 = 6 mags | jap/squads_44-45:89 |
| jap/jap_officer.set:20 | nambu with nambu_mag 32 (only load) | nambu_mag 32 (3) | only load of a weapon used by <4 breeds | stuff/pistol/nambu fills 8: 32 = 4 mags | jap/squads_44-45:109 +1 |
| jap/jap_rifle_grenadier.set:21 | type99rifle_at with rifle_grenade_at 6 (only load) | rifle_grenade_at 6 (1) | only load of a weapon used by <4 breeds | stuff/rifle/type99rifle_at fills 1: 6 = 6 mags | jap/squads_44-45:14 +5 |
| jap/jap_smg2b.set:18 | type100_44_bayonet with type100_mag 180 (only load) | type100_mag 180 (3) | only load of a weapon used by <4 breeds | stuff/smg/type100_44_bayonet fills 30: 180 = 6 mags | jap/squads_44-45:10 |
| jap/jap_smgb.set:18 | type100_44 with type100_mag 180 (only load) | type100_mag 180 (3) | only load of a weapon used by <4 breeds | stuff/smg/type100_44 fills 30: 180 = 6 mags | jap/squads_44-45:14 +6 |
| jap/jap_sniper_type97.set:21 | type97sniper with arisaka6-5_clip 100 (no std) | none | only load of a weapon used by <4 breeds | stuff/rifle/sniper/type97sniper fills 5: 100 = 20 mags | jap/squads_44-45:106 |
| jap/jap_sniper_type99.set:21 | type99sniper with arisaka7-7_clip 100 (no std) | none | only load of a weapon used by <4 breeds | stuff/rifle/sniper/type99sniper fills 5: 100 = 20 mags | jap/squads_44-45:107 +1 |
| jap/jap_snlf_type100_44.set:18 | type100_44 with type100_mag 180 (only load) | type100_mag 180 (3) | only load of a weapon used by <4 breeds | stuff/smg/type100_44 fills 30: 180 = 6 mags | jap/squads_44-45:44 |
| jap/light_mortar.set:20 | type89_grenadelauncher with 5cm_grenade fg 8 (only load) | 5cm_grenade fg 8 (1) | only load of a weapon used by <4 breeds | stuff/rifle/type89_grenadelauncher fills 1: 8 = 8 mags | jap/squads_42-43:62 +1 |
| jap/mgun2.set:18 | type96_mg with type96_mag 180 (only load) | type96_mag 180 (2) | only load of a weapon used by <4 breeds | stuff/mgun/type96_mg fills 30: 180 = 6 mags | jap/squads_42-43:13 +1 |
| jap/mgun3.set:18 | type11_mg with arisaka6-5_clip 180 (only load) | arisaka6-5_clip 180 (3) | only load of a weapon used by <4 breeds | stuff/mgun/type11_mg fills 30: 180 = 6 mags | jap/squads_42-43:71 |
| jap/oficer.set:25 | nambu with nambu_mag 32 (only load) | nambu_mag 32 (3) | only load of a weapon used by <4 breeds | stuff/pistol/nambu fills 8: 32 = 4 mags | jap/squads_42-43:92 |
| jap/otsu_mg.set:18 | type11_mg with arisaka6-5_clip 180 (only load) | arisaka6-5_clip 180 (3) | only load of a weapon used by <4 breeds | stuff/mgun/type11_mg fills 30: 180 = 6 mags | jap/vehicles_all:140 |
| jap/super_officer.set:20 | nambu with nambu_mag 32 (only load) | nambu_mag 32 (3) | only load of a weapon used by <4 breeds | stuff/pistol/nambu fills 8: 32 = 4 mags | jap/vehicles_all:143 |
| rus/home_guard3.set:18 | mp38 with mp40_mag 96 (only load) | mp40_mag 96 (2) | only load of a weapon used by <4 breeds | stuff/smg/mp38 fills 32: 96 = 3 mags | rus/squads_41-42:5 +1 |
| rus/oficer.set:25 | tt with tt_mag 32 (only load) | tt_mag 32 (3) | only load of a weapon used by <4 breeds | stuff/pistol/tt fills 8: 32 = 4 mags | rus/squads_41-42:99 |
| rus/rus_officer.set:20 | tt with tt_mag 32 (only load) | tt_mag 32 (3) | only load of a weapon used by <4 breeds | stuff/pistol/tt fills 8: 32 = 4 mags | rus/squads_43-45:104 +1 |
| rus/rus_partisan_mp38.set:18 | mp38 with mp40_mag 96 (only load) | mp40_mag 96 (2) | only load of a weapon used by <4 breeds | stuff/smg/mp38 fills 32: 96 = 3 mags | rus/squads_43-45:4 |
| rus/rus_sniper_svtscoped.set:21 | svt40_s with svt40_mag 20 (only load) | svt40_mag 20 (2) | only load of a weapon used by <4 breeds |  | rus/squads_43-45:102 |
| rus/sniper3.set:21 | svt40_s with svt40_mag 20 (only load) | svt40_mag 20 (2) | only load of a weapon used by <4 breeds |  | rus/squads_41-42:97 |
| rus_guard/guard_officer.set:25 | tt with tt_mag 32 (only load) | tt_mag 32 (3) | only load of a weapon used by <4 breeds | stuff/pistol/tt fills 8: 32 = 4 mags | rus_guard/squads_43-45:81 +1 |
| rus_guard/guard_sniper_mosin.set:21 | mosin_s_vet with mosin_clip 120 (only load) | mosin_clip 120 (1) | only load of a weapon used by <4 breeds |  | rus_guard/squads_43-45:78 |
| rus_guard/guard_sniper_svtscope.set:21 | svt40_s_vet with svt40_mag 20 (only load) | svt40_mag 20 (1) | only load of a weapon used by <4 breeds |  | rus_guard/squads_43-45:79 |
| usa/devil_brigade_radio.set:26 | mortar_flaergun with mortar_flaer 5 (only load) | mortar_flaer 5 (1) | only load of a weapon used by <4 breeds | stuff/pistol/mortar_flaergun fills 1: 5 = 5 mags | usa/squads_42:32 |
| usa/paramarine.set:19 | johnson with springfield_clip 80 (only load) | springfield_clip 80 (3) | only load of a weapon used by <4 breeds | stuff/rifle/johnson fills 10: 80 = 8 mags | usa/squads_42:23 +2 |
| usa/shotgun.set:18 | m12_shotgun with shotgun 90 (only load) | shotgun 90 (2) | only load of a weapon used by <4 breeds | stuff/rifle/m12_shotgun fills 6: 90 = 15 mags | usa/squads_42:66 |
| usa/usa_devil_brigade_radio.set:26 | mortar_60_flaregun with mortar_60_flare 5 (only load) | mortar_60_flare 5 (1) | only load of a weapon used by <4 breeds | stuff/pistol/mortar_60_flaregun fills 1: 5 = 5 mags | usa/squads_43-45:45 |
| usa/usa_elite_101st_para4.set:24 | weapon m18recoilless with m18recoilless 8 (only load) | m18recoilless 8 (2) | only load of a weapon used by <4 breeds |  | usa/squads_43-45:29 +1 |
| usa/usa_engineer_at.set:21 | weapon bazooka with bazooka 4 (only load) | bazooka 4 (1) | only load of a weapon used by <4 breeds |  | usa/squads_43-45:16 |
| usa/usa_marine_shotgun.set:18 | m12_shotgun with shotgun 90 (only load) | shotgun 90 (2) | only load of a weapon used by <4 breeds | stuff/rifle/m12_shotgun fills 6: 90 = 15 mags | usa/squads_43-45:20 +1 |
| usa/usa_nightfighter_carbine.set:51 | m3_carbine with m2carbine_mag 240 (only load) | m2carbine_mag 240 (2) | only load of a weapon used by <4 breeds | stuff/rifle/sniper/m3_carbine fills 30: 240 = 8 mags | usa/vehicles_43-45:126 |
| usa/usa_nightfighter_leader.set:20 | m3_carbine with m2carbine_mag 240 (only load) | m2carbine_mag 240 (2) | only load of a weapon used by <4 breeds | stuff/rifle/sniper/m3_carbine fills 30: 240 = 8 mags | usa/vehicles_43-45:126 |
| usa/usa_paramarine.set:19 | johnson with springfield_clip 80 (only load) | springfield_clip 80 (3) | only load of a weapon used by <4 breeds | stuff/rifle/johnson fills 10: 80 = 8 mags | usa/squads_43-45:34 +1 |
| usa/usa_paramarine3_asst.set:19 | johnson with springfield_clip 80 (only load) | springfield_clip 80 (3) | only load of a weapon used by <4 breeds | stuff/rifle/johnson fills 10: 80 = 8 mags | usa/squads_43-45:34 +2 |
| usa/usa_ranger_carbine.set:19 | m2_carbine with m2carbine_mag 180 (only load) | m2carbine_mag 180 (1) | only load of a weapon used by <4 breeds | stuff/rifle/m2_carbine fills 30: 180 = 6 mags | usa/squads_43-45:40 +1 |
| usa/usa_ranger_recoiless.set:18 | m1903 with springfield_clip 100 (only load) | springfield_clip 100 (2) | only load of a weapon used by <4 breeds | stuff/rifle/m1903 fills 5: 100 = 20 mags | usa/squads_43-45:86 |
| usa/usa_ranger_recoiless.set:21 | weapon m18recoilless with m18recoilless 8 (only load) | m18recoilless 8 (2) | only load of a weapon used by <4 breeds |  | usa/squads_43-45:86 |
| usa/usa_ranger_springfield2.set:18 | m1903 with springfield_clip 100 (only load) | springfield_clip 100 (2) | only load of a weapon used by <4 breeds | stuff/rifle/m1903 fills 5: 100 = 20 mags | usa/squads_43-45:39 +1 |

## Other cases asked for

### Weapons with no ammo line (a `gun filled` entry not in `gun+ammo` form)
All 24 such kit rows were opened (class 19 table). In every one the weapon's ammo is in the same inventory, only later:
- 12 radiomen (axm_bul_radioman, eng_radioman_airstrike, ger_radioman_mortar, ger/radioman_mortar, ost_radioman, rus/radioman_mortar, rus_radioman_mortar, usa radioman_mortar, usa_radioman_105/155/240, usa_radioman_mortar): SMG filled, flare gun filled, SMG ammo, flare ammo. The flare gun is not followed by "SMG magazines it cannot load": both ammo lines are there, the SMG ammo just comes first. Not a fault.
- 8 Panzerschreck men (ger/bazooker, ger_panzerschreck, ger_pzgren_panzershreck, ger_pzgren_pio_at, sturmovik5, ost_panzershreck, ss_sturmpio_at, axm_rom_bazooker): rockets 5-7 come after bandage and AT grenade.
- ger_volksgren_mg valter (shovel between), jap_snlf_at2 / jap_type4_atassist (`weapon weapon type_4at`, SMG between), axm_fin_sissi_mgun_assist_vision (LSM26 ammo for the gunner between).
- eng_anzac_mg_assist: em3 then Bren magazines then its own 100 rifle rounds (class 12).
Two forms that look broken but resolve by tag set [I] (modweb/humans/breeds.md:15, not run in game): `{item  "LSM26_mag" 320}` with no `ammo` word (5 Finnish breeds; matches stuff/ammo/magazines/LSM26_mag.ammo, and the lsm26 itself fills plain `"LSM26_mag"`), `"breda_mag" 160` (bersaglieri MG pair), `"thompson_drum" 150` (eng_anzac_sl, eng_anzac_smg_thompson, usa_raiderchad), and the reversed `"garand_clip ammo"` (5 US raider/ranger files). [T] one game.log check for `No Stuff found` would settle all of them.

### Luger / valter + `ammo 9x19`
`ammo 9x19` appears in 7 breed files (grep of resource/set/breed). 6 are dead ammo (class 1): axm_fin_sissi_mgun, _sissi_mgun_vision, _pio_mgun, _pio_flamer (luger), axm_rom_bazooker, axm_bul_officer (valter). 1 is fine: axm_rom_bazooker_assist (feeds its Orita, class 17).

### Flare guns + SMG magazines
No case where a flare gun is the only weapon next to SMG magazines: every radioman with flare gun + SMG ammo also has the SMG (see above). Side note: usa_radioman_240 carries 128 m3a rounds (4 mags), the other four US radiomen 192.

### type97rifle (no stuff file)
DATA: `{item "type97rifle" filled}` in jap/mgun3_ammo.set:18 and jap/mgun3_asst.set:18. No file named type97rifle in resource/set/stuff (rifle/ has type99rifle, _at, _bayonet; rifle/sniper/ has type97sniper), no localization entry. Both breeds have no unit line: squad `mg3` in the 1942-43 list (units/jap/squads_42-43.set:71) has mgun3 alone, and the 1944-45 squad uses jap_mgun3 + jap_mg3_asst. So the missing stuff never loads today.
If they were used: limits LOG-07 [V] says `No Stuff found` substitutes dummy_checker and crashes later when used. [I] intended weapon: a 6.5 mm Arisaka (type38rifle, which their 180/90 arisaka6-5_clip fits) or type97sniper. Their successor jap_mg3_asst switched to type99rifle with 7.7 mm (class 3).

## Breeds no unit line uses
Checked against the loaded units files (units_4x.set includes + shared vehicles/squads files), by side. Registration in soldier.set / soldiers.set alone is not counted as a use.

| breed | kit rows | registered in | note |
|---|---|---|---|
| axis_minor/axm_bul_smg | mp40 120 (class 4) | soldiers.set:560, soldier.set:109 | Bulgarian squad uses axm_bul_rifle x7 + squadleader |
| axis_minor/axm_bul_officer | valter + 9x19 (class 1) | none found | fix only if it gets a card |
| ger2/ost_radioman | mp40 (class 19) | soldiers.set:246, soldier.set:352 | |
| jap/elite_ig1h_ammo, jap/elite_ig1h_asst | type_4_rifle 60 (class 20) | soldiers.set:856-857, soldier.set:561-562 | elite_ig1h itself is used (hero_jap_guard, units/jap/vehicles_all.set:147) |
| jap/elite_ig2_scoped | type99_mg_scoped 180 (class 20) | soldiers.set:707, soldier.set:947 | |
| rus/rus_elite_tankman, rus/rus_elite_tankcommander | filling form (class 18) | soldiers.set:2618/2651 with role `tankman` | [I] a `tankman` tag pool may pick them; no vehicle line names them |
| rus_guard/guard_elite_tankman, rus_guard/guard_elite_tankcommander | filling form (class 18) | soldiers.set:2619/2652 role `tankman` | same |
| jap/mgun3_ammo, jap/mgun3_asst (not kit rows) | type97rifle | | see above |

## Questions for the owner
1. Luger/valter with `ammo 9x19` 40 (6 breeds): meant as pistol spare ammo? (then walther_mag)
2. axm_ita_alpini_sniper: Beretta with 160 rounds, meant 35?
3. jap_mg3_asst: should it carry 6.5 mm for the Type 11 (type38 + arisaka6-5_clip)?
4. ss_kosaken ppsh41 142 and axm_fin_tankman suomi_m31r 142: meant 105 / 120 (whole magazines)?
5. Finnish suomi_m31: 213 (3 drums) or 210 as standard?
6. eng_anzac_rifle 100 rounds vs 50 for all other em3 men: on purpose?
7. AP miners 25-34 mines per side: one value meant, or filled to fit?
8. Are rus/rus_guard elite tank crews picked by the `tankman` tag, or leftovers?
9. axm_bul_smg, axm_bul_officer, ost_radioman, elite_ig1h_ammo/_asst, elite_ig2_scoped: keep or delete?
10. Veteran/hero Soviet snipers carry 100 vs 120 for the card sniper: on purpose?
