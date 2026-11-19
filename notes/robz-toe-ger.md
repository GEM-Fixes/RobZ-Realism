# RobZ Realism 1.31.0: German infantry vs historical tables of organization (ger, ger2, ger_ss)

Read-only job. Nothing in the mod, game or repo was changed. Scratch: `E:\arsenal-tmp\robz-toe\toe-ger\` (expand.js, expanded.txt, compact.txt).

## Method and how sure each part is

- DATA (certain): every `squad/...` card of ger, ger2, ger_ss in `E:\arsenal-tmp\robz-toe\cards.tsv` (179 cards; the 71 `entity/...` cards
  are vehicles and guns with `vehicle_supporter`/`tankman` crews and are left out, see "Cards left out"). Each breed was matched in
  `breeds.tsv`; per card the men, weapon, rounds, grenades and AT kit below come from there. Card lines: `units/<side>/squads_*.set:line`
  as given in cards.tsv. All three German sides' squad cards live in `units/ger/squads_4x.set` (ger and ger_ss) and `units/ger2/squads.set`.
- Weapon names checked in the mod's stuff and localization: `panzerfaust` = Panzerfaust 100 (`localization/desc/vanilla/weapon.inc:116`,
  range 60 in `stuff/bazooka/panzerfaust.weapon`); `panzerfaust_60` = Panzerfaust 60 (range 45); `panzerfaust_30`, `faustpatrone_30` (range 30);
  `hohlladung` = "Hafthohlladung AT grenade" (`localization/desc/mod/stuff/grenade.inc:58`); `pwm1` = Panzerwurfmine; `zb30` = ZB vz.30
  (20-round magazine, `stuff/mgun/zb30`); `mab_38a` = Beretta MAB 38 (40-round magazine); `vsg` = Volkssturmgewehr (takes StG 44 magazines);
  `mp3008`, `mp41`, `mkb42`, `mp43`, `g41` = G41(W); `mg42_inf` loads a 50-round drum, `mg42_inf_250` a 250-round belt; `mauzer` = Kar98k,
  `mauzer_s` = scoped Kar98k, `valter` = P38, `luger` = P08, `sg44` = StG 44, `m24x5` = geballte Ladung (bundled charge).
- Count forms like `0 1`, `-1 2`, `1.5 0.5`: per `modweb/humans/breeds.md:15` (`n dev` = count + uniform random in [-dev,+dev], then
  `(int)(count+0.5)`), so `0 1` gives the item in about 1 of 4 men, `-1 2` in about 1 of 8, `1.5 0.5` gives 1 or 2 (half each).
  [I] This is code-read, not tested in game, and `GiveItems` uses the centre value when `exactCounts` is set: if MP spawns use exact
  counts, `0 1` means "never". Findings that depend on this are marked [T].
- HISTORY: no primary TO&E document was at hand. Each history line says how sure it is. Web checks done (page titles):
  "FG 42" (Wikipedia; Gran Sasso raid Sept 1943 as combat debut, 50 trial rifles end of 1942), "Gewehr 41" (Wikipedia; 3,400 sent to the
  Eastern Front end of 1941 for troop trials, formal adoption Dec 1942), "Volksgrenadier" and "grenadierkompanie kstn131v 1.9.1944"
  (blog reconstruction of KStN 131V Nov 1944: two Sturmzüge with StG 44 storm groups of 8 men, one rifle platoon with MG 42 and rifle
  grenades), "Wehrmacht Squad Regulations" (festung.net; MG Schütze 3 carries spare barrel and 2 ammo boxes). Two searches (Hafthohlladung
  date) were refused by the search tool; those dates are from memory, unverified.
- Historical baselines used below (from memory unless a page is named above):
  - Schützengruppe 1939-43: 10 men: leader (MP 38/40), deputy (K98k), MG team of 3 (No.1 and No.2 with pistols, No.3 K98k), 5-6 riflemen.
    From KStN 131 of 1 Nov 1943 ("Grenadierkompanie 1944"): 9 men (leader, deputy, MG No.1/No.2, 5 riflemen). Fairly sure of 10 then 9.
  - Panzergrenadier (gp) group on SdKfz 251: 10-12 men incl. driver, 2 MG 34/42 (one for the vehicle). Fairly sure of the two MGs.
  - Ammunition standard issue: K98k 60 rounds (2 pouch sets x 3 pockets x 2 clips) sure; MP 38/40 6 x 32 = 192 sure; StG 44 6 x 30 = 180
    fairly sure; pistol 1 loaded + 1 spare = 16 fairly sure; G43 rifle + 2 spare magazines in one pouch, extra clips for reloading, from memory;
    FG 42 bandolier of 8 x 20, from memory; Fallschirmjäger bandolier ca. 100-120 K98k rounds, from memory unverified.
  - LMG: No.2 carried 4 Gurttrommeln (200) and 1 Patronenkasten (300), No.3 2 Patronenkasten (600), squad total ca. 1,150 plus what riflemen
    carried, from memory, partly in "Wehrmacht Squad Regulations". Hand grenades: no fixed per-man issue; 1-2 stick grenades per man in combat
    plus squad stock, from memory.
  - Dates (from memory unless named above): MP 40 from early 1940 (MP 38 in 1939); MG 42 from mid 1942; Gewehrgranatgerät (Schiessbecher)
    from 1942; MKb 42(H) field trials from late 1942; MP 43 from mid 1943; G43 production from Oct 1943; Panzerschreck from late 1943;
    Faustpatrone/Panzerfaust 30 from Aug 1943; Panzerfaust 60 from Sept 1944; Panzerfaust 100 from Nov 1944; Hafthohlladung from about
    late 1942; Panzerwurfmine (L) from 1943; PzB 39 obsolete as AT rifle in 1942 and converted to GrB 39; MP 3008 and Volkssturmgewehr from
    Jan-Feb 1945; "Grenadier" name for infantry from Oct 1942; "Panzergrenadier" name from mid 1942 (before: Schützen); SS-VT became
    SS-Division "Reich" in late 1940; Prinz Eugen raised 1942; Cossack corps transferred to the Waffen-SS Feb 1945.

## Most important findings (most likely mistakes first)

1. Three ger_ss cards call a squad macro with one member too few, so the card's content gets a garbage breed. `units/ger/squads_44.set:14`
   `ssvts_44` uses `squad_with6types` with c1..c5; `squads_44.set:78` `elites_44` uses `squad_with7types` with c1..c6; `squads_42.set:17`
   `gebirgs_42` uses `squad_with6types` with c1..c5. The macro (`units/squads.set:689-700`) writes `mp/%side/%c6`; `%c6` is read as `%c`
   (the charge) plus "6", so content gets `mp/ger_ss/1206`, `mp/ger_ss/607` and `mp/ger_ss/06` (cards.tsv shows these as soldiers).
   [I] the game will log a missing breed or spawn the squad one man short. [T] check game.log when buying these cards. Fix: use the
   5-/6-member macro.
2. FG 42 on 1942 cards: `elites_42(ger)` (fallschirm_sl_asst_fg_42, `squads_42.set:43`) and `elite3_42(ger)` FG42 team (`squads_42.set:102`).
   The FG 42 first saw combat in 1943 (Wikipedia "FG 42").
3. Hafthohlladung on cards offered in 1940-42: `at_rifles(ger)` 40-45 (both men), `at_rifles(ger_ss)` 41-45, `ap_miners`, `at_miners`,
   `sappers(ger_ss)` 41-45 (every man). Introduced about late 1942 (from memory). Fix: start these cards at 43 or give 1940-42 versions
   with bundled charges (`m24x5`) instead.
4. Panzerfaust on cards offered before 1943/44: `riflemans2(ger)` (Kar98k rifleman, tags 39-45, breed ger_grenadier_rifle_44 carries
   `panzerfaust_60 0 1`) and `grenadier_sa(ger)` (G43 grenadier, 43-45, `panzerfaust_60 0 1`). [T] about 1 in 4 such men gets a
   Panzerfaust 60 in 1939-43.
5. Volkssturm `home_guards(ger)` tags 44 45 but 2 men carry MP 3008 and 2 the Volkssturmgewehr: both are 1945 weapons. Also the breed
   `ger_volkssturm_smg_panzerfaust` carries the vsg rifle, not an SMG (name and kit disagree).
6. Panzerwurfmine on 1941-42 Fallschirmjäger: `fallschirm_sa_41` (G41 + pwm1) in `elites_41` and `elites_42`. PWM from 1943 (from memory).
7. G41 used as an ordinary squad weapon in 1941-42: up to 3 per squad (`stormtroopers_41`, `gebirgsjager_41`, `ger_ss lssah/tk_pzgrens_41`,
   FJ `elites_41`). Only a troop-trial batch (ca. 3,400) reached the front at the end of 1941 (Wikipedia "Gewehr 41"). Likely deliberate
   [I] to give early squads a semi-auto tier.
8. Name anachronisms (titles only): "Grenadier squad 1940", "Fusilier squad 1940/1942", "Panzergrenadier squad 1941", "SS-Grenadier 1941",
   "SS-VT 1944", "Kosaken" under ger_ss in 1944. Look deliberate (one name per card line across years) [I].

## Cards per group

Mod squad: count, then man: weapon (rounds) and AT kit. "PF100/PF60/PF30" = Panzerfaust 100/60/30; "(25%)" = `0 1` form, "(12%)" = `-1 2`.
Unless said, riflemen carry 60 rifle rounds + 1 MG drum (50), MP 192, StG 180, pistol 16, and 2 stick grenades (m24) + bundled charge forms.

### ger, 1940-1943 squads (`units/ger/squads_41.set`, `squads_42.set`, `squads_43.set`)

| card | title | years | mod squad | historical squad | differences | severity |
|---|---|---|---|---|---|---|
| grenadiers_40 (squads_41.set:14) | Grenadier squad 1940 | 40 41 | 10: SL MP40, 2IC K98k, 6 K98k, MG34 + asst K98k | 10: SL MP, 2IC, MG34 team of 3, 6 riflemen | MG team 2 not 3; asst has rifle (hist. pistol); title "Grenadier" before Oct 1942 | fine (title) |
| fusiliers_40 (squads_41.set:18) | Fusilier squad 1940 | 40 41 | 10: SL MP40, 2IC, 6 K98k, MG34 + asst | as above | same squad as grenadiers_40; "Fusilier" title is 1943+ | fine (title) |
| stormtroopers_41 (squads_41.set:22) | Panzergrenadier squad 1941 | 41 | 10: SL MP40, 2IC, 3 G41 + dynamite, 1 K98k, 2 MG34 + 2 asst | Schützen group on SdKfz 251: ca. 10-12, 2 MG34, K98k | 3 G41 in 1941 (trial batch only) | wrong weapon |
| gebirgsjager_41 (squads_41.set:38) | Gebirgsjäger squad 1941 | 41 | 11: SL MP40, asst MP40, 3 G41, 4 K98k, MG34 + asst | ca. 10-11, MG34, K98k, 1 MP | 3 G41; 2 MP40 | wrong weapon |
| elites_41 (squads_41.set:40) | Fallschirmjäger squad 1941 | 41 | 11: SL MP40, asst MP40, sniper, G41 + PWM, 3 K98k, 2 MG34 + 2 asst | Crete 1941: ca. 10-12, MP40 heavy, 1-2 MG34, K98k | G41 and Panzerwurfmine in 1941 | wrong year |
| grenadiers_42 (squads_42.set:13) | Grenadier squad 1942 | 42 | 10: SL MP40, 2IC, 1 G41, 4 K98k, rifle grenadier, MG42 + asst | 10: SL MP, MG team, K98k; rifle grenade launcher from 1942 | 1 G41 (rare but possible) | fine |
| fusiliers_42 (squads_42.set:19) | Fusilier squad 1942 | 42 | 10: SL MP40, 2IC, 2 G41, 4 K98k, MG42 + asst | as grenadiers | 2 G41; title | fine (G41 high) |
| jagers_42 (squads_42.set:21) | Jäger squad 1942 | 42 | 11: SL MP40, asst MP40, 2 G41, 5 K98k, MG42 + asst | Jäger divisions from 1942, squad like infantry (10) | one man over; 2 G41 | count off |
| stormtroopers_42 (squads_42.set:25) | Panzergrenadier squad 1942 | 42 | 10: SL MP40, 2IC, 3 G41 + dynamite, 1 K98k, 2 MG42 + 2 asst | (gp) group: 2 MG34/42, K98k | 3 G41 | wrong weapon |
| gebirgsjager_42 (squads_42.set:41) | Gebirgsjäger squad 1942 | 42 | 11: SL MP40, asst MP40, 3 G41, 4 K98k, MG42(250 belt) + asst | ca. 10-11, MG34/42, K98k | 3 G41 | wrong weapon |
| elites_42 (squads_42.set:43) | Fallschirmjäger squad 1942 | 42 | 11: SL MP40, asst FG42, sniper, G41 + PWM, K98k, 2 rifle grenadiers, 2 MG42 + 2 asst | ca. 10-12, MP40, K98k, MG34/42 | FG42 and PWM before 1943 | wrong year |
| grenadiers_43 (squads_43.set:13) | Grenadier squad 1943 | 43 | 10: SL MP40, 2IC, 1 G43, 4 K98k, rifle grenadier, MG42 + asst | 10 (9 from Nov 1943) | G43 only late 1943 | fine |
| fusiliers_43 (squads_43.set:19) | Fusilier squad 1943 | 43 | 10: SL MP40, 2IC, 1 MP40, 2 G43, 3 K98k, MG42 + asst | as grenadiers | 2 G43 early | fine |
| jagers_43 (squads_43.set:21) | Jäger squad 1943 | 43 | 11: SL MP40, asst MP40, 3 MP40, 1 G43, 3 K98k, MG42 + asst | ca. 10 | 5 MP40 of 11, one man over | count off |
| stormtroopers_43 (squads_43.set:25) | Panzergrenadier squad 1943 | 43 | 10: SL MP40, 2IC, 3 G43, 1 K98k, 2 MG42 + 2 asst | (gp): 2 MG42, K98k, 1-2 MP | 3 G43 in 1943 | fine (G43 high) |
| grenadiers_elite_43 (squads_43.set:29) | Elite Pzgren 'Grossdeutschland' | 43 | 10: SL MP40, 2IC K98k, scoped G43, 2 G43, K98k, 2 MG42(250) + 2 asst | GD (gp) group: 2 MG42 | 3 G43 + scoped G43 in 1943 | fine (elite) |
| gebirgsjager_43 (squads_43.set:45) | Gebirgsjäger squad 1943 | 43 | 11: SL, asst, 3 MP40, 2 G43, 2 K98k, MG42 + asst | ca. 10-11, K98k | 5 MP40 | fine (balance [I]) |
| elites_43 (squads_43.set:47) | Fallschirmjäger squad 1943 | 43 | 11: SL MP40, asst FG42, sniper, FG42, G43, 2 rifle grenadiers, 2 MG42 + 2 asst | ca. 10-12, 2 MG42 common, FG42 from 1943 | fine | fine |

### ger, 1944-45 squads (`units/ger/squads_44.set`)

| card | title | years | mod squad | historical squad | differences | severity |
|---|---|---|---|---|---|---|
| home_guards :4 | Volkssturm squad | 44 45 | 10: 4 K98k + Faustpatrone (25%), 2 MP3008 + Faustpatrone (25%), 2 K98k + PF30 (25%), 2 Volkssturmgewehr + PF60 (25%) | Volkssturm: mixed rifles (often foreign), PF; MP3008/VG from 1945 | MP3008 and VG on a 1944 card; breed named smg carries vsg | wrong year |
| volksgrens :8 | Volksgrenadier squad | 44 45 | 9: SL MP40, asst MP40 + PF60 (25%), MG42 + asst K98k, K98k + PF30 (25%), 2 K98k + PF100 (25%), rifle grenadier | rifle platoon squad: leader, MG42, K98k, rifle grenades (KStN 131V reconstruction) | PF100 before Nov 1944 | fine |
| volksgrens_sturm :10 | Volksgrenadier Sturm squad | 44 45 | 9: SL StG, asst MP40, 3 StG, 2 StG + PF100, MP40, G43 | storm group 8: leader, deputy, 6, all StG 44 | 2 MP40 + 1 G43 instead of StG; one man over | count off |
| volksgrens_heavy :12 | Volksgrenadier Heavy Sturm squad | 44 45 | 9: SL StG, asst MP40, StG, 2 StG + PF100, 2 MG42, asst MP40, asst G43 | Sturmzug fire squad: 2 LMG + crew (rifles) | close | fine |
| sturmgrens_44 :20 | Sturmgrenadier squad | 44 45 | 8: all StG 44, PF60 (25%) x5, PF100 (25%) x2 | storm group 8, all StG 44 | matches | fine |
| grenadiers_44 :26 | Grenadier squad 1944 | 44 45 | 9: SL MP40, 2IC, G43, K98k, rifle grenadier, 2 K98k + PF100, MG42 + asst | 9 (KStN 131, 1.11.1943) | matches | fine |
| fusiliers_44 :38 | Fusilier squad 1944 | 44 45 | 9: SL MP40, 2IC, 2 StG, G43, G43 + PF60, K98k + PF60, MG42 + asst | Füsilier (division recon) squad, bicycle infantry like grenadiers | 2 StG plausible | fine |
| jagers_44 :40 | Jäger squad 1944 | 44 45 | 10: SL StG, asst StG, StG, 3 MP40, G43, K98k + PF60, MG42 + asst | ca. 9-10 | 6 automatics of 10 | fine (balance [I]) |
| pzgren_pios :46 | Panzergrenadier Pioneer squad | 44 45 | 10: SL MP40 + 2 Hafthohlladung, 3 K98k sappers (mines, charges, detector), flamer, 2 MG42 + 2 asst, Panzerschreck (5 rockets) | Panzerpionier group on 251/7: ca. 10-12, 2 LMG, flamethrower, demolitions | Panzerschreck inside the squad (was company level [I]) | fine |
| stormtroopers_44 :48 | Panzergrenadier squad 1944 | 44 45 | 9: SL StG, 2IC K98k, StG + PF60, G43, MP40 + PF60, 2 MG42 + 2 asst | (gp) 1944: 10-12 incl. driver, 2 MG42 | matches | fine |
| grenadiers_elite :54 | Elite Pzgren 'Grossdeutschland' | 44 45 | 9: SL StG, asst StG + PF100, StG + PF60, scoped G43, G43 + PF60, 2 MG42(250) + 2 asst | GD (gp): 2 MG42, StG common late | matches | fine |
| gebirgsjager_44 :74 | Gebirgsjäger squad 1944 | 44 45 | 10: SL StG, asst StG, 2 StG, 3 MP40, G43 + PF100, MG42 + asst | ca. 10-11, K98k majority | no K98k riflemen at all (only MG asst) | fine (balance [I]) |
| elites_44 :76 | Fallschirmjäger squad 1944 | 44 45 | 10: SL MP40, asst FG42 + PF30, sniper, 2 rifle grenadiers, StG + PF30, 2 MG42 + 2 asst | 1944 FJ: 9-12, 2 MG42, MP40/StG/FG42 | matches | fine |
| vehic_supporter :97 | Support crew | 39-45 | 2 K98k | - | - | fine |
| elite_tankmans :103 | Veteran tank crew | 39-45 | 1 MP40 (96) | crew: MP + pistols | MP40 on a 1939 tag (MP 38 then) | fine |

### ger single men and teams (`squads_44.set` unless named)

| card | title | years | mod | historical | differences | severity |
|---|---|---|---|---|---|---|
| riflemans2 :111 | Karabiner 98k Rifleman | 39-45 | K98k, PF60 (25%) | K98k | Panzerfaust 60 possible 1939-43 [T] | wrong year |
| grenadier_sa :115 | G43 grenadier | 43-45 | G43, PF60 (25%) | G43 from late 1943 | PF60 possible in 1943 [T] | wrong year |
| smgs2_40 :119 | MP40 SMG | 40-45 | MP40 | - | - | fine |
| grenadier_stg :121 | StG44 grenadier | 44 45 | StG, PF60 (25%) | - | - | fine |
| grenadier_sa_41 (squads_42.set:81) | G41 grenadier | 41 42 | G41 (80) | G41 trials end 1941, 1942 | rare | fine |
| grenadier_stg_42 (squads_42.set:85) | MKb42(H) grenadier | 42 | MKb42 (180) | trials from late 1942 | rare | fine |
| grenadier_stg_43 (squads_43.set:89) | MP43 grenadier | 43 | MP43 (180) | from mid 1943 | - | fine |
| at_rifles :125 | PzB 39 AT-Rifle team | 40-45 | PzB 39 (35) + Hafthohlladung; asst MP40, PzB 10, Hafthohlladung | PzB 39 1940-42; obsolete after | Hafthohlladung in 1940-42; PzB kept to 1945 | wrong year |
| bazookers :133 | Panzerschreck team | 43-45 | RPzB (7) + P38; asst K98k (3 rockets) | from late 1943 | - | fine |
| bazooker3 :135 | Panzerfaust team | 44 45 | 2 K98k, 2 PF60 each | - | - | fine |
| stormtrooper5 :137 | Pzgren Panzerschreck team | 43-45 | RPzB (7), asst MP40 (3 rockets) | - | - | fine |
| mg2 :141 | Grenadier MG34 team | 39-45 | MG34 (300) + P38, asst K98k (600 belt) | - | - | fine |
| mgs2 :145 | Grenadier MG42 team | 42-45 | MG42 (300) + P38, asst (600) | from mid 1942 | - | fine |
| elite3 :151 | FJ FG42 team | 43-45 | FG42 (160), 2 K98k (120) + PWM | - | - | fine |
| elite3_42 (squads_42.set:102) | FJ FG42 team | 42 | FG42 (160), 2 K98k (120) | FG42 combat from 1943 | FG42 in 1942 | wrong year |
| stormtrooper6_39 :155 | Pzgren MG34 team | 39-45 | MG34 (300), 2 asst K98k each MG drum 300 + spare barrel | - | title "Panzergrenadier" 1939 | fine (title) |
| stormtrooper6 :157 | Pzgren MG42 team | 42-45 | MG42, 2 asst (600 each) | - | - | fine |
| gd_pzgren_mg :159 | GD MG42 team | 43-45 | MG42(250), 2 asst | - | - | fine |
| fallschirm_mg_39 :161 | FJ MG34 team | 39-45 | MG34, 2 asst (K98k 80, 600) | - | - | fine |
| fallschirm_mg :162 | FJ MG42 team | 42-45 | MG42(250), 2 asst | - | - | fine |
| flamers :174 | Flamethrower team | 39-45 | flamethrower, asst MP40 | Flammenwerfer 35 from 1939 | MP40 on a 1939 tag | fine |
| snipers :178 | Karabiner 98k Sniper | 39-45 | scoped K98k (60) | - | - | fine |
| sniper3 :179 | G43 Sniper | 43-45 | scoped G43 (70) | ZF4 G43 from late 1943/44 | early | fine |
| officers_40 :184 | Officer | 39-45 | P08 (32) | pistol + MP | 32 pistol rounds | count off |
| radioman_mortar :191 | Radioman mortar call-in | 39-45 | MP40 + flare gun | - | - | fine |
| light_mortar_ger (vehicles_44.set:62) | 50mm GrW 36 | 41-45 | mortar (12) + 2 asst K98k (8 bombs each) | leGrW 36 crew of 3, withdrawn from front units 1941-43 | offered to 1945 | fine (deliberate [I]) |

### ger2 (`units/ger2/squads.set`, all 44 45)

| card | title | years | mod squad | historical squad | differences | severity |
|---|---|---|---|---|---|---|
| home_guards :4 | Leichte Aufklärung | 44 45 | 3: SL MP40, K98k + PF100 (25%), MG42 | recon patrol | - | fine |
| home_guards2 :6 | Schwere Aufklärung | 44 45 | 6: SL StG, G43 + PF60, K98k + PF100, K98k + PF30, 2 MG42 | recon group with 2 LMG | MG gunners have no assistants | fine |
| smgs :9 | Veteran Sturmjäger squad | 44 45 | 9: SL StG, G43, MP41, StG, 2 PPSh (captured), K98k + PF100, MG42 + asst | 9-man 1944 squad | MP41 (mainly SS/police/export [from memory]); PPSh as MP 717(r) plausible | fine |
| riflemans :11 | Veteran Jäger squad | 44 45 | 9: SL MP40, G43, StG, G43, 2 K98k + PF100, rifle grenadier, MG42 + asst | 9 | matches | fine |
| elites :15 | Crack Jäger squad | 44 45 | 10: SL StG, asst StG, StG, 3 MP41, G43, K98k + PF100, MG42 + asst | 9-10 | 3 MP41 (rare weapon) | wrong weapon (minor) |
| stormtroopers :17 | Elite Jäger squad | 44 45 | 10: SL StG, asst StG + PF100, StG + PF100, 2 MP41 + PF60, 2 K98k with 2 PF100 each, scoped G43, MG34 + asst | 9-10 | 2 MP41; 1 MG for a 10-man elite squad fine | fine |
| elites_para :19 | Elite Fallschirmjäger squad | 44 45 | 10: SL StG, scoped FG42, sniper, 2 rifle grenadiers, FG42, 2 MG42(250) + 2 asst | 1944 FJ, 2 MG42 | matches | fine |
| riflemans2 :37, smgs2 :39 | K98k / MP40 Jäger | 44 45 | single | - | - | fine |
| tankmans :41 | Tank crew | 44 45 | MP40 (96), 4 P38 (32 each) | - | pistol 32 | count off |
| at_rifles :43 | PzB 39 AT-Rifle team | 44 45 | PzB 39 + Hafthohlladung, asst MP40 | PzB 39 gone from AT use by 1944 | obsolete weapon | wrong weapon (minor) |
| at_rifles2 :44 | PzB 784(r) team | 44 45 | captured PTRD (25), asst MP40 | captured PTRD in use | - | fine |
| bazookers :46 | Panzerfaust team | 44 45 | 2 K98k, 2 PF60 each | - | - | fine |
| bazooker3 :47 | Jäger RPzB 54 team | 44 45 | RPzB (7), asst (6) | RPzB 54 from 1944 | - | fine |
| mgs2 :49 | Jäger MG team | 44 45 | MG42 + 2 asst | - | - | fine |
| stormtroopers2 :53 | Elite Jäger Pzfst team | 44 45 | G43 + 2 PF100, K98k + 2 PF100 | - | - | fine |
| stormtroopers3 :55 | Elite Jäger MG team | 44 45 | MG34 + 2 asst | - | - | fine |
| flamers :57, snipers :59, officers_40 :62 | | | flamer + MP40; scoped K98k (60 + 20); P08 (32) | - | officer pistol 32 | fine |
| mg34/42_lafette (vehicles_all.set:26-27) | MG lafette | 44 45 | 2 K98k crew | - | - | fine |
| 5_cm_granatwerfer_36_ger2 (vehicles_all.set:50) | 50mm GrW 36 | 44 45 | mortar (12) + 2 asst (8 each) | out of front-line use by 1944 | late | fine (deliberate [I]) |

### ger_ss (`units/ger/squads_4x.set`)

| card | title | years | mod squad | historical squad | differences | severity |
|---|---|---|---|---|---|---|
| ssvts_44 (squads_44.set:14) | Waffen-SS 'SS-VT' squad 1944 | 44 45 | 9 + broken slot: SL MP41, asst K98k, 5 K98k, ZB30 + asst | "SS-VT" ended 1940; 1944 second-line SS squad 9 | macro slot `1206` (finding 1); title | wrong (data) |
| kosaken_44 :16 | Kosaken squad | 44 45 | 9: 3 PPSh41 (142), 4 Mosin, DP (282) + asst Mosin | Cossack units with Soviet captured arms | SS only from Feb 1945 | fine (title) |
| grenadiers_44 :28 | SS-Grenadier squad 1944 | 44 45 | 9: SL MP40, 2IC K98k + PF30, StG + PF60, 2 G43 + PF60, K98k + PF100, MG42 + asst, rifle grenadier | 9 | matches | fine |
| sturmgrens :30 | SS-Sturmgrenadier squad | 44 45 | 9: SL StG, asst StG, 2 StG, StG + PF60, 2 MP40, G43, scoped G43 | assault squad | fine | fine |
| sturmgrens_heavy :32 | SS-Sturmgrenadier heavy squad | 44 45 | 9: 4 StG, 2 MG42 + 2 asst MP40, scoped G43 | - | fine | fine |
| gebirgs_44 :34 | SS-Gebirgsjäger 'Prinz Eugen' 1944 | 44 45 | 9: SL MAB 38, asst K98k, 2 K98k + PF60, 3 K98k, ZB30 + asst | Prinz Eugen: captured Czech/Italian arms | matches the division's mixed arms | fine |
| gebirgs_cqc_44 :36 | SS-Gebirgsjäger CQC | 44 45 | 9: 7 MAB 38 (2 with PF30), ZB30 + asst | - | 7 SMGs | fine (balance [I]) |
| sturmpios :42 | SS-Pioneer squad | 44 45 | 10: SL StG + 2 Hafthohlladung, 3 sappers K98k, 2 StG with mines, flamer, MG42 + asst, Panzerschreck | pioneer group: 1 LMG, flamethrower | fine | fine |
| pzgrens_44 :58 | SS-Panzergrenadier 1944 | 44 45 | 9: SL StG, 2IC K98k + PF100, StG, G43 + PF60, K98k + PF60, 2 MG42 + 2 asst | (gp) with 2 MG | matches | fine |
| tk_pzgrens_44 :64 | 'Totenkopf' 1944 | 44 45 | 11: SL MP40, asst scoped K98k, StG + PF100, G43, G43 + PF60, K98k + PF100, K98k, 2 MG42(250) + 2 asst | 10-12 | fine | fine |
| lssah_pzgrens_44 :68 | 'LSSAH' 1944 | 44 45 | 12: SL StG, scoped G43, StG + PF100, G43 + PF100, G43 + PF60, 2 MG42(250) + 2 asst, Panzerschreck + asst K98k | 10-12 | Panzerschreck in the squad (company/battalion level hist. [I]) | fine (elite) |
| elites_44 :78 | SS-Fallschirmjäger squad | 44 45 | 12 + broken slot: SL MP40, asst MP40 + PF30, 2 MP40, 4 K98k (120) + PWM, 2 MG34 + 2 asst | SS-Fallschirmjäger-Bataillon 500/600 squads ca. 10-12 | macro slot `607` (finding 1) | wrong (data) |
| ap_miners :85 | SS Combat engineers (AP) | 41-45 | 4 MP40, S-mines, Hafthohlladung, wire | pioneers mostly K98k | Hafthohlladung 1941-42; all MP40 | wrong year |
| at_miners :88 | SS Combat engineers (AT) | 41-45 | 4 MP40, Teller mines, Hafthohlladung | as above | same | wrong year |
| sappers :91 | SS Mine disposal experts | 41-45 | 2 MP40, detector, charges, Hafthohlladung | as above | same | wrong year |
| vehic_supporter :96, tankmans :99, elite_tankmans :102 | crews | 41-45 | K98k; MP40 (96) + 4 P38 (32) | - | pistol 32 | fine |
| ssvts_41 (squads_43.set:5) | Waffen-SS 'SS-VT' 1941 | 41 42 43 | 10: SL MP41, asst K98k, 6 K98k, ZB30 + asst | SS-VT used Czech MG 26(t)/ZB in 1939-41 | name ended 1940; ZB30 kept to 1943 | fine (title) |
| grenadiers_43 (squads_43.set:15) | SS-Grenadier 1943 | 43 | 10: SL MP40, 2IC, 2 G43, 3 K98k, rifle grenadier, MG42 + asst | 10 | G43 early | fine |
| gebirgs_43 (squads_43.set:17) | SS-Gebirgsjäger 1943 | 43 | 11: SL MP40, 4 MP41, 4 K98k, ZB30 + asst | ca. 10-11 | 4 MP41 | fine |
| pzgrens_43 (squads_43.set:33) | SS-Pzgren 1943 | 43 | 10: SL MP40, 2IC, 2 G43, 2 K98k, 2 MG42 + 2 asst | (gp) | fine | fine |
| tk_pzgrens_43 :37 | 'Totenkopf' 1943 | 43 | 11: SL MP40, scoped K98k, 2 G43, 3 K98k, 2 MG42 + 2 asst | 10-12 | fine | fine |
| lssah_pzgrens_43 :41 | 'LSSAH' 1943 | 43 | 11: SL MP40, scoped G43, 2 G43, K98k, 2 MG42 + 2 asst, Panzerschreck + asst | 10-12 | Panzerschreck before late 1943 possible on a 43 card | fine (borderline) |
| grenadiers_42 (squads_42.set:15) | SS-Grenadier 1942 | 42 | 10: SL MP40, 2IC, 5 K98k, rifle grenadier, MG42 + asst | 10 | matches | fine |
| gebirgs_42 :17 | SS-Gebirgsjäger 1942 | 42 | 11 + broken slot: SL MP40, asst MP41, 7 K98k, ZB30 + asst | Prinz Eugen raised 1942 | macro slot `06` (finding 1) | wrong (data) |
| pzgrens_42 :29 | SS-Pzgren 1942 | 42 | 10: SL MP40, 2IC, 2 G41, 2 K98k, 2 MG42 + 2 asst | (gp) | 2 G41 | fine (G41 high) |
| tk_pzgrens_42 :33 / lssah_pzgrens_42 :37 | 'Totenkopf' / 'LSSAH' 1942 | 42 | 11: SL MP40, scoped K98k, 2 G41, 3 K98k, 2 MG42(250) + 2 asst | (gp) | 2 G41 | fine (G41 high) |
| grenadiers_41 (squads_41.set:16) | SS-Grenadier 1941 | 41 | 10: SL MP40, 2IC, G41, 5 K98k, MG34 + asst | 10 | G41; title | wrong weapon (minor) |
| pzgrens_41 :26 | SS-Pzgren 1941 | 41 | 10: SL MP40, 2IC, G41, 3 K98k, 2 MG34 + 2 asst | Schützen group | G41; title | wrong weapon (minor) |
| tk_pzgrens_41 :30 / lssah_pzgrens_41 :34 | 'Totenkopf' / 'LSSAH' 1941 | 41 | 11: SL MP40, scoped K98k, 2 G41, 3 K98k, 2 MG34 + 2 asst | motorized SS | 2 G41 in 1941 | wrong weapon |
| singles :110-123, grenadier_sa_41 (squads_42.set:80) | K98k / G43 / MP40 / StG44 / G41 | as offered | single | - | none carry a Panzerfaust before 44 | fine |
| at_rifles :127 | SS PzB 39 team | 41-45 | PzB 39 + Hafthohlladung, asst MP40 | - | Hafthohlladung 41-42; PzB after 1942 | wrong year |
| bazookers :129, bazooker3 :131 | Panzerschreck / Panzerfaust | 43-45 / 44 45 | RPzB 7 + 5; 2 x 2 PF60 | - | - | fine |
| mg2/mgs2, tk_ and lssah_ MG teams :143-170 | MG34 / MG42 teams | 41-45 / 42-45 | MG + 1-2 asst | - | - | fine |
| flamers :176, snipers :180, sniper3 :181, officers :186-187 | | | as ger | - | officer pistol 32 | fine |
| 5_cm_granatwerfer_36_ss (ger_ss/vehicles_44.set:57) | 50mm GrW 36 | 41-45 | as ger | - | late years | fine (deliberate [I]) |

## Anachronisms (weapon or kit offered before it existed)

DATA = card tags + breed inventory; date = history baseline above.

| item | first in service | cards that offer it earlier | how sure |
|---|---|---|---|
| FG 42 | combat 1943 (Wikipedia "FG 42") | ger elites_42 (squads_42.set:43), elite3_42 (squads_42.set:102) | sure |
| Hafthohlladung | about late 1942 (from memory) | ger at_rifles 40-42; ger_ss at_rifles, ap_miners, at_miners, sappers 41-42 (squads_44.set:85-91, 125-127) | fairly sure |
| Panzerfaust 60 | Sept 1944 | ger riflemans2 39-43 (squads_44.set:111), ger grenadier_sa 43 (:115), [T] 25% per man | sure of date; spawn chance [T] |
| MP 3008, Volkssturmgewehr | Jan-Feb 1945 | ger home_guards tag 44 (squads_44.set:4) | fairly sure |
| Panzerwurfmine | 1943 (from memory) | ger fallschirm_sa_41 in elites_41, elites_42 | medium |
| G41 as a squad weapon | trial batch end 1941, adopted Dec 1942 (Wikipedia "Gewehr 41") | 3 per squad in ger stormtroopers_41, gebirgsjager_41; 2 in ger_ss tk/lssah_pzgrens_41; 1 in elites_41, ger_ss grenadiers_41, pzgrens_41 | sure of date; deliberate [I] |
| Panzerfaust 100 | Nov 1944 | every 1944 card that has `panzerfaust` (44 tag covers Jan-Oct 1944 too) | fine within one 44 tag [I] |
| G43 | Oct 1943 production | all 43 cards (2-4 per squad) | borderline, fine |
| MP 40 | 1940 | 39-tagged cards with MP40 (elite_tankmans, flamers, radioman_mortar) | fine; a 39 tag may not be used in MP |
| PzB 39 (as AT rifle) | obsolete from 1942 | offered to 45 (ger 40-45, ger2 44-45, ger_ss 41-45) | deliberate [I] |
| 50mm leGrW 36 | withdrawn from front units 1941-43 | offered to 45 on all three sides | deliberate [I] |

No MG 42 before 1942 was found: every 1940-41 card uses the MG 34 (`grenadier_mg_39`, `sturmovik6_39`, `fallschirm_mg_39`, ...).
No StG 44 before 1944: 1942 has MKb42(H), 1943 MP43, only on single cards. No Panzerschreck before 1943.

## Ammunition and grenades that differ from standard issue

Standard-issue numbers are in the baselines above. Most of the mod matches them: K98k 60, MP40 192 (6 x 32), StG 180 (6 x 30), pistol 16 (2 x 8).

| what | mod | standard | cards / breeds | note |
|---|---|---|---|---|
| Fallschirmjäger K98k | 120 (riflemen, grenadiers, sniper); MG asst 80 (ger) / 90 (ger_ss) | 60, or FJ bandolier ca. 100-120 (from memory) | ger elites_41-44, elite3, ger2 elites_para, ger_ss elites_44 | looks deliberate (FJ bandolier) [I] |
| FJ G41 | 120 | ca. 60-80 | fallschirm_sa_41 | - |
| G41 | 80 | ca. 60-80 (fed by clips) | all *_sa_41 breeds | fine |
| G43 | 10 loaded + 20 in magazines + 60 loose clips = 90 | rifle + 2 magazines + clips, from memory | every G43 breed | fine |
| G43 sniper | 10 + 60 = 70 | - | ger sniper3, ger_ss sniper3 | fine |
| ost_pzgren_g43scope | 10 + 60 + 20 | - | ger2 stormtroopers | extra 20 `mauser_clip fg` |
| Officer P08 | 32 (`walther_mag`) | 16 | all officer cards | 2 extra magazines; uses P38 magazine item for a P08 |
| Tank crew P38 | 32 | 16 | ger2 tankmans, ger_ss tankmans | balance [I] |
| Tank commander MP40 | 96 (3 magazines) | MP + magazines stowed in the vehicle | tankman2 breeds | fine |
| MG pistol with count form | `walther_mag 16 1` (15-17), `16 2` (14-18) | 16 | ost_mgun (ger2), ger_pzgren_pio_mg, ss_sturmpio_mg | odd counts; [I] typo for a single value |
| LMG squad total | gunner 300 + asst 600 + each rifleman one 50-round drum: ca. 1,150-1,300 per squad | ca. 1,150 + riflemen's share | grenadier and pzgren squads | matches the baseline well |
| MG34 team asst | each asst a 300-round drum load + spare barrel, total 900 | 300 + 600 | ger stormtrooper6_39 (squads_44.set:155) | differs from the MG42 team (600 belt) |
| ZB30 | gunner 300 (15 x 20), asst 280 | magazine-fed, more magazines per team (from memory) | ger_ss SS-VT, Prinz Eugen | fine |
| Panzerschreck | 7 + 3, 7 + 5, 7 + 6, pioneer 5 | ca. 5-10 per team (from memory) | ger/ger2/ger_ss teams | fine |
| PzB 39 | 35 + 10 | ca. 20 at the weapon + loader's | at_rifles | fine |
| 50mm mortar | 12 + 8 + 8 | ca. 30-45 per crew (from memory) | light_mortar cards | fine |
| Hand grenades | 2 stick grenades per man; Volksgrenadier `1.5 0.5` (1 or 2); SL 2 + 2 smoke | 1-2 per man in combat (no fixed issue) | all | fine |
| Bundled charge | `m24x5 -1 2` = ca. 1 in 8 men [T]; `0 1` = 1 in 4 [T] | squad stock | grenadier vs fusilier/pzgren breeds | fine |
| No grenades | MG gunners, Volkssturm, some MG asst (ger grenadier_mg_asst) | - | - | fine |
| Rifle grenades | 6 HE + 1 AP; Volksgren 10 + 5; SS 5 + 2 ap2 | ca. 10 per launcher (from memory) | rifle_grenadier breeds | fine |

## Cards that match the historical squad (no change suggested)

ger: grenadiers_43, grenadiers_44, sturmgrens_44, volksgrens, volksgrens_heavy, fusiliers_44, stormtroopers_44, grenadiers_elite (44),
grenadiers_elite_43, elites_43, elites_44, pzgren_pios; all MG teams, Panzerschreck and Panzerfaust teams, snipers, flamers, smgs2_40,
grenadier_stg, grenadier_stg_42, grenadier_stg_43, grenadier_sa_41.
ger2: riflemans, smgs, elites_para, stormtroopers, home_guards, home_guards2, at_rifles2, bazookers, bazooker3, mgs2, stormtroopers2/3.
ger_ss: grenadiers_42, grenadiers_43, grenadiers_44, pzgrens_43, pzgrens_44, sturmgrens, sturmgrens_heavy, gebirgs_44, sturmpios,
tk_pzgrens_43/44, lssah_pzgrens_44, MG/AT/sniper teams.

## Cards left out

71 `entity/...` cards of ger/ger2/ger_ss (vehicles and guns) are crewed by `vehicle_supporter`, `tankman`, `tankman2`, `vet_tankman`.
Not infantry squads. Seen in passing: `kubel_mgun` and `r12` 'MG-42' cards are offered from 42 (fine); `mg34_lafette` 41-45 (fine).

## ToE text for empty `; ToE:` lines (suggestions; not written into the mod)

File `localization/desc/mod/squad/ger/squad1.inc` (line of the key):
- :19 grenadiers_44(ger): Grenadiergruppe (KStN 131, Nov 1943): 9 men, leader MP 40, deputy and 5 riflemen Kar98k (some G43, Panzerfaust), MG 42 team of 2.
- :22 fusiliers_44(ger): Füsiliergruppe of a division Füsilier battalion 1944: 9 men organised as a Grenadiergruppe, MG 42, Kar98k, G43, StG 44 in some.
- :25 jagers_44(ger): Jägergruppe 1944: 9-10 men, leader MP 40/StG 44, MG 42 team, Kar98k and G43 riflemen, Panzerfaust.
- :31 stormtroopers_44(ger): Panzergrenadiergruppe (gp) 1944: 10-12 men on an SdKfz 251 incl. driver, 2 MG 42, leader MP 40 or StG 44, Kar98k.
- :37 gebirgsjager_44(ger): Gebirgsjägergruppe 1944: 10-11 men, leader MP 40, MG 42 team of 3, Kar98k riflemen, a few StG 44 and G43.
- :40 elites_44(ger): Fallschirmjägergruppe 1944: 9-12 men, 2 MG 42, MP 40, FG 42 and StG 44 in some, Kar98k riflemen.
- :49 grenadiers_43(ger): Grenadiergruppe 1943: 10 men, leader MP 40, deputy and 6 riflemen Kar98k, MG 34/42 team of 3; 9 men from Nov 1943.
- :52 fusiliers_43(ger): Füsiliergruppe 1943 (e.g. Füsilier-Regiment GD): 10 men, MG 42, Kar98k, leader MP 40.
- :55 jagers_43(ger): Jägergruppe 1943 (Jäger division): 10 men, leader MP 40, MG 42 team of 3, Kar98k.
- :58 stormtroopers_43(ger): Panzergrenadiergruppe (gp) 1943: 10-12 men incl. driver, 2 MG 42, leader MP 40, Kar98k.
- :64 gebirgsjager_43(ger): Gebirgsjägergruppe 1943: 10-11 men, leader MP 40, MG 34/42 team of 3, Kar98k.
- :67 elites_43(ger): Fallschirmjägergruppe 1943: 10-12 men, 1-2 MG 42, MP 40, first FG 42, Kar98k.
- :71 grenadiers_42(ger): Schützengruppe 1942 (Grenadier from Oct 1942): 10 men, leader MP 40, MG 34/42 team of 3, 6 Kar98k, rifle grenade cup.
- :74 fusiliers_42(ger): Schützengruppe 1942: 10 men, leader MP 40, MG 34/42 team of 3, 6 Kar98k.
- :77 jagers_42(ger): Jägergruppe 1942 (light divisions renamed Jäger): 10 men, leader MP 40, MG 34/42 team of 3, Kar98k.
- :80 stormtroopers_42(ger): Schützengruppe (gp) 1942 on SdKfz 251: 10-12 men, 2 MG 34/42, leader MP 40, Kar98k.
- :84 gebirgsjager_42(ger): Gebirgsjägergruppe 1942: 10-11 men, leader MP 40, MG 34/42 team of 3, Kar98k.
- :87 elites_42(ger): Fallschirmjägergruppe 1942: 10-12 men, MG 34/42, MP 40 for leaders, Kar98k.
- :91 grenadiers_40(ger): Schützengruppe 1940: 10 men, leader MP 38/40, MG 34 team of 3, deputy and 5 riflemen Kar98k.
- :94 fusiliers_40(ger): Schützengruppe 1940: 10 men, leader MP 38/40, MG 34 team of 3, 6 Kar98k.
- :97 stormtroopers_41(ger): Schützengruppe (gp) 1941 on SdKfz 251: 10-12 men incl. driver, 2 MG 34, leader MP 40, Kar98k.
- :101 gebirgsjager_41(ger): Gebirgsjägergruppe 1941: 10-11 men, leader MP 40, MG 34 team of 3, Kar98k.
- :104 elites_41(ger): Fallschirmjägergruppe 1941 (Crete): 10-12 men, MG 34, MP 40 for leaders, Kar98k, weapons containers dropped separately.

File `localization/desc/mod/squad/ger/squad2.inc`:
- :60 grenadier_stg_43(ger): MP 43 issued for troop trials from mid 1943, 6 magazines of 30 (7.92 kurz).
- :67 grenadier_stg_42(ger): MKb 42(H) in field trials from late 1942, 6 magazines of 30 (7.92 kurz).

File `localization/desc/mod/squad/ger_ss/squad1.inc`:
- :6 ssvts_44(ger_ss): Waffen-SS rifle squad 1944 (second-line): 9 men, leader MP, Kar98k, one LMG (often captured, e.g. MG 26(t)).
- :12 grenadiers_44(ger_ss): SS-Grenadiergruppe 1944: 9 men, leader MP 40/StG 44, MG 42 team of 2, Kar98k, G43, Panzerfaust.
- :21 gebirgs_44(ger_ss): SS-Gebirgsjäger 'Prinz Eugen' 1944: 10-11 men with mixed captured arms (ZB, Beretta MAB 38) and Kar98k.
- :29 pzgrens_44(ger_ss): SS-Panzergrenadiergruppe 1944: 10-12 men, 2 MG 42, leader MP 40/StG 44, Kar98k, G43.
- :33 tk_pzgrens_44(ger_ss): SS-Panzergrenadiergruppe 'Totenkopf' 1944: 10-12 men, 2 MG 42, MP 40/StG 44, Kar98k.
- :36 lssah_pzgrens_44(ger_ss): SS-Panzergrenadiergruppe 'LSSAH' 1944: 10-12 men, 2 MG 42, StG 44, G43, Kar98k; Panzerschreck at company level.
- :59 ssvts_41(ger_ss): SS-Verfügungstruppe rifle squad (to 1940, then SS-Division Reich): 10 men, leader MP, MG 26(t)/ZB, Kar98k.
- :63 grenadiers_43(ger_ss): SS-Grenadiergruppe 1943: 10 men, leader MP 40, MG 42 team, Kar98k, first G43.
- :66 gebirgs_43(ger_ss): SS-Gebirgsjäger 'Prinz Eugen' 1943: 10-11 men, captured Czech LMG (ZB), MP, Kar98k.
- :70 pzgrens_43(ger_ss): SS-Panzergrenadiergruppe 1943: 10-12 men, 2 MG 42, leader MP 40, Kar98k.
- :73 tk_pzgrens_43(ger_ss): SS-Panzergrenadiergruppe 'Totenkopf' 1943: 10-12 men, 2 MG 42, MP 40, Kar98k.
- :76 lssah_pzgrens_43(ger_ss): SS-Panzergrenadiergruppe 'LSSAH' 1943: 10-12 men, 2 MG 42, MP 40, Kar98k, some G43.
- :80 grenadiers_42(ger_ss): SS-Schützengruppe 1942: 10 men, leader MP 40, MG 34/42 team of 3, Kar98k, rifle grenade cup.
- :83 gebirgs_42(ger_ss): SS-Freiwilligen-Gebirgs-Division 'Prinz Eugen' 1942: 10-11 men, captured Czech LMG and rifles, MP.
- :87 pzgrens_42(ger_ss): SS-Schützengruppe (mot) 1942: 10-12 men, 2 MG 34/42, leader MP 40, Kar98k.
- :90 tk_pzgrens_42(ger_ss): SS-Division 'Totenkopf' (mot) 1942: 10-12 men, 2 MG 34/42, MP 40, Kar98k.
- :93 lssah_pzgrens_42(ger_ss): 'LSSAH' (mot) 1942: 10-12 men, 2 MG 34/42, MP 40, Kar98k.
- :97 grenadiers_41(ger_ss): SS-Schützengruppe 1941: 10 men, leader MP 40, MG 34 team of 3, 6 Kar98k.
- :101 pzgrens_41(ger_ss): SS-Schützengruppe (mot) 1941: 10-12 men, 2 MG 34, leader MP 40, Kar98k.
- :104 tk_pzgrens_41(ger_ss): SS-Division 'Totenkopf' (mot) 1941: 10-12 men, MG 34, MP 40, Kar98k.
- :107 lssah_pzgrens_41(ger_ss): 'LSSAH' (mot) 1941: 10-12 men, MG 34, MP 40, Kar98k.

## Questions for the owner

1. Fix the three short macro calls (ssvts_44, elites_44 ger_ss, gebirgs_42)? Yes/no.
2. Should 1942 FG 42 (elites_42, elite3_42) stay? Yes/no.
3. Hafthohlladung on 1940-42 AT/engineer cards: keep, or start those cards at 43?
4. Do MP spawns use exact item counts (`0 1` = never) or the random spread?
5. Rifleman/G43 single cards: Panzerfaust 60 before 1944 intended?
6. Volkssturm MP 3008 / VG on the 44 tag intended?
7. G41 in 1941 squads (up to 3): deliberate semi-auto tier?
8. Fallschirmjäger 120 rifle rounds: meant as the FJ bandolier?
9. `walther_mag 16 1` and `16 2` on three MG breeds: typo for 16?
10. Officers and tank crews with 32 pistol rounds: intended?
