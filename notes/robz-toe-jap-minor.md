# RobZ Realism 1.31.0: Japanese and minor Axis infantry against historical ToE

Read-only job. Nothing in the mod, the game or the repo was changed. Mod = `E:\RobZ Realism\robz realism mod 1.31.0` (<mod>).
Data: `E:\arsenal-tmp\robz-toe\cards.tsv`, `breeds.tsv`, breed files `<mod>\resource\set\breed\mp\<side>\`, card files
`<mod>\resource\set\multiplayer\units\jap\squads_42-43.set` (J42), `...\jap\squads_44-45.set` (J44), `...\axis_minor\squads.set` (AXM),
weapon files `<mod>\resource\set\stuff\...`, names from `<mod>\localization\desc`.

## 0. How to read this

- Ammunition in the mod = the weapon "filled" (one magazine/clip in the gun) + the count in the breed (breed_kit.inc:144-148:
  `{item "type100smg" filled}` + `{item "ammo type100_mag" 180}`). "65 rds" = 5 in the rifle + 60 carried.
- Years: a Japanese card is only in the game list that includes its file (units_42.set:19 and units_43.set:19 load J42,
  units_44-45.set:26 and units_45.set:21 load J44). Japan has no infantry in 41 (units_41.set loads only jap vehicles).
  Year tags 39/40/41 on Japanese cards therefore never show [V by include list; filtering by `{unitset {value "42"}}`
  presets_42.inc:9-10 read as "only cards tagged 42" = I].
- AXM is included in units_41/42/43/44-45/45, but every AXM infantry card except officers and the vehicle supporter is tagged
  `44 45` only (AXM:8-89). So in 41-43 games the minor Axis side has no infantry squads [I, from the tag filter above].
- History confidence: [H1] = documented in a known reference (named); [H2] = widely repeated, from memory, fairly sure;
  [H3] = from memory, unverified / poorly documented. Japanese and minor-nation squad ToE is thinly documented in English.
- Count forms like `smoke grenade 0 1` are the mod's own; meaning not verified, not relied on.

History base used (short):
- Japan rifle (LMG) squad: ~13 men: leader, LMG group (gunner, assistant, ammunition bearers), ~8-9 riflemen; platoon =
  3 LMG squads + 1 grenade discharger squad (3, later often 4, Type 89) [H2; the source to check is TM-E 30-480
  "Handbook on Japanese Military Forces", 1 Oct 1944, infantry chapter, which also says the Army was replacing 6.5 mm squad
  weapons (Type 38, Type 11, Type 96) with 7.7 mm (Type 99 rifle and LMG), whole units on Attu armed with Type 99 = H1].
  Rifleman 120 rds (2 front pouches of 30, rear pouch of 60) [H2], 2 hand grenades [H2-H3].
- Type 100 SMG: early model ~1,000 made 1942-43 (about 200 converted to folding-stock paratrooper guns); 1944 model ~7,000-8,000
  from Jan 1944 [H1: Wikipedia "Type 100 submachine gun", Forgotten Weapons "Type 100/44 (Late Pattern)"; totals disputed].
- Type 2 TERA paratrooper rifle: adopted May 1943, Nagoya 1943-45, ~19,000-21,500 [H1: Wikipedia "TERA rifle"].
- "Type 2 SMG": experimental Nambu design, ~120-200 made, not a service weapon [H2-H3; sources disagree on the name].
- Type 4 70 mm AT rocket launcher: designed 1944, ~3,500 made, used in 1945, mostly home-defence [H1: Wikipedia
  "Type 4 70 mm AT rocket launcher"; no 1944 field use known].
- Type 3 AT grenade (hand-thrown HEAT): 1943 adoption (Type 3 = 2603), issue 1944-45 [H2]. Lunge mine: 1944-45 [H2].
  Type 99 hako-bakurai magnetic mine: 1939 [H2]. Type 97 AT rifle: 1937, ~1,100 made, 59 kg [H2].
- Italy: platoon 1940-41 = 2 squads of ~18-20 men each with a Breda 30 group; the Breda 30 was later 2 per squad [H3:
  conflicting, wargame lists and Wikipedia "Breda 30"]. Carcano 6.5 mm M91 and 7.35 mm M38 both in use, 7.35 mm withdrawn
  from 1940 [H2]. MAB 38A rare in line units before 1943 [H2]. Italian Royal Army on the Axis side ends Sept 1943; 1944-45 =
  RSI only [H1].
- Hungary: Danuvia 39M ~8,000-13,300 made from 1941/42, 43M ~5,000 [H1: Wikipedia "Danuvia 43M", Forgotten Weapons; figures
  disagree]; issued to paratroops, assault and motorised units, not line rifle squads [H2]. Fought on the Axis side to May 1945.
- Romania: Orita M1941 in service 1943, ~6,000 made by Oct 1943 [H1: Wikipedia "Orița M1941"]. Romania changed sides 23 Aug 1944.
- Bulgaria: changed sides Sept 1944 [H1]. Main rifle Mannlicher M95 [H2]; ZB vz.26/30 LMGs [H2]; German deliveries 1943-44 [H3].
- Finland: armistice 19 Sept 1944, then fought Germany (Lapland) [H1]. Suomi KP/-31 drum 70 rds [H2]. LS/26 20-rd magazine [H2].
  Boys AT rifles bought 1939-40 [H2]. Panzerfaust/Panzerschreck delivered summer 1944 [H2].

## 1. Ranked findings (most likely mistakes first)

| # | finding | where | kind |
|---|---------|-------|------|
| 1 | Cards titled "w/Type 99 LMG" field a **Type 96** gunner: `jap_mgun2` = `type96_mg` (breeds.tsv). Identical squad to the "w/Type 96 LMG" cards | J44:21-23 | data mistake, wrong weapon |
| 2 | Japanese 42-43 "Takasago unit Type 99 MG team" uses breed `elite_rifle2` x3, which has **no breed file** in `breed\mp\jap\` (only `elite_takasago_rifle2.set`) | J42:79 | data mistake (card spawns 1 man or fails, I) |
| 3 | AXM card `Bersaglieri_Mot` uses `axm_bersaglieri_mgun:2`; no such breed (file is `axm_ita_bersaglieri_mgun.set`). Card not in cards.tsv | AXM:31 | data mistake |
| 4 | Type 4 70 mm rocket launcher in **1942-43** cards: `elite_ig4` (Imperial Guard 42) and `sturmovik3` (SNLF 42) carry `type_4at` | J42:19, J42:30 | wrong year (2-3 years early) |
| 5 | Type 3 AT grenade (`type3at_a`) on most 1942-43 Japanese breeds (squadleader, smg, elites, sturmovik, at_rifle, smg2...) | J42 all squads | wrong year (1942) |
| 6 | Minor Axis infantry offered only in **1944-45**, while the side is loaded in 41-43 lists. Romania, Bulgaria, Finland were not Axis in 1945; Italian Alpini/Bersaglieri as Royal Army ended 1943 | AXM:8-89 tags | wrong year (likely a tag choice, I) |
| 7 | Type 4 RL cards and breeds tagged 44 (`bazookers`, `stormtrooper5`, IG and SNLF 44 squads) | J44:30,44,82,84 | wrong year (1944, launcher is 1945) |
| 8 | Type 11 LMG assistant `jap_mg3_asst` carries a 7.7 mm Type 99 rifle + 200 rds 7.7: cannot feed a 6.5 mm Type 11 | J44:89 | wrong weapon (calibre) |
| 9 | Japanese regular section mixes 7.7 mm (3 Type 99 + grenadier) and 6.5 mm (4 Type 38 + LMG team) riflemen; the 7.7 men carry `type99_mag` 30 for a gun that is a Type 96 | J44:14-23 | wrong weapon mix |
| 10 | "Type 2 SMG" single card (42-45): an experimental gun (~120-200 made). Owner's note "type2 smg to jap elites? no, too rare" (`tings to do.txt`:118) | J44:69, J42:58 | wrong weapon (deliberate?) |
| 11 | Japanese rifleman 65 rds instead of 120 | all Japanese rifle breeds | count off |
| 12 | Type 100 SMG density: 2-11 SMGs per Japanese squad incl. regular sections; historically ~1,000 early guns in all | J42, J44 | weapon mix (balance, I) |
| 13 | Italian paratroopers: 6 x Scotti Model X semi-auto rifles (`scottix`, a rare air force rifle) | axm_ita_paratrooper_rifle | wrong weapon (H3) |
| 14 | Teishin 42 squad: TERA Type 2 rifles in 1942 (adopted May 1943) | J42:25 | wrong year (1942) |
| 15 | Squads are 15 men for Japan (owner's note "JAPAN squad size 15", `tings to do.txt`:841) vs ~13 historical | J42, J44 | count off (deliberate) |

## 2. Japan: card table

Abbreviations: T38 = Type 38 6.5 mm rifle (bayonet variant = `_bayonet`), T99r = Type 99 7.7 mm rifle, T100 = Type 100 SMG early,
T100-44 = 1944 model, T96/T99/T11 = LMGs, T89 = grenade discharger, T44c = Type 44 carbine, T3AT = Type 3 AT grenade,
T4RL = Type 4 70 mm rocket launcher, g97/g99 = Type 97/99 grenade. Ammo is per man incl. the loaded clip.

| card (file:line) | title | years | mod squad | historical squad (confidence) | differences | severity |
|---|---|---|---|---|---|---|
| riflemans_t96, _2, _3 (J44:14-16) | Regular section w/Type 96 LMG | 44-45 | 16: leader T100 (210, 2 g97, 2 T3AT); 3 T99r (65 + 30 LMG rds, 1 g97, 2 AP mines); 4 T38 (65 + 30); 2 T100-44 (210, 2 g97, 1 T3AT); T96 gunner (210); asst T38 (+30); 3 ammo bearers T38 (+120 each); rifle grenadier T99r + Type 2 launcher, 6 HEAT | 13: leader, T96 or T99 LMG team (gunner, asst, 2 bearers), ~8 riflemen, 1-2 with rifle grenade launcher; one calibre per squad (H2) | +3 men; 2 SMG + SMG leader; 6.5/7.7 mixed; 65 rds vs 120; 1 grenade vs 2; 2 AP mines each | count off, weapon mix |
| riflemans, _2, _3 (J44:21-23) | Regular section w/Type 99 LMG | 44-45 | identical to the t96 cards: gunner `jap_mgun2` = **Type 96** | 13 with T99 LMG and T99 rifles (H2) | wrong LMG; same extras as above | wrong weapon |
| riflemans_t96_4, riflemans_4 (J44:17,24) | Section w/Type 89 Dischargers | 44-45 | 10: leader T100 (210); 3 T89 gunners (T44c 65, 8 shells); 6 asst (T44c 65, 16 shells). 120 shells | ~13: leader, 3-4 T89 each with gunner + 2-3 asst/bearers, rifles (H2-H3) | 3 men short; carbines plausible; leader SMG; both cards identical (t96_4 uses `light_mortar_asst`, _4 `jap_light_mortar_asst` = same file content) | count off (minor) |
| riflemans_t96_42 (J42:13) | Regular section w/Type 96 LMG | 42-43 | 15: leader T100 (2 T3AT); 4 T99r (+30 LMG); 7 T38 (+30); 2 T100 (T3AT); T96 gunner 210; no asst | 13 with team of 3-4 (H2) | no LMG assistant/bearers; 2 SMG; T3AT in 1942 | wrong year (T3AT), count off |
| riflemans_42 (J42:15) | Regular section w/Type 99 LMG | 42-43 | as above with T99 gunner (`mgun`) | 13 (H2) | as above; LMG right | wrong year (T3AT) |
| smgs (J44:10) | Assault section | 44-45 | 15: leader T100 bay. (4 g97, T3AT); 3 T99r bay.; 1 T38 bay.; 4 T100 bay.; 6 T100-44 bay. (2 g97, T3AT) = 11 SMG | no SMG-based squad in the Army ToE (H2) | 11 SMGs; no LMG | weapon mix (balance, I) |
| smgs_42 (J42:9) | Assault section | 42-43 | 15: leader T100; 1 T99r; 3 T38; 10 T100 | as above | 11 early T100 = 1% of all ~1,000 early guns per squad | weapon mix, wrong year (T3AT) |
| home_guards (J44:4) | Gun Banzai chargers | 44-45 | 15: 8 T38 bay. (65, 1 g99, knife); 4 T100 bay.; 3 T100-44 bay. | charge by a normal rifle squad/company, rifles + bayonets (H2) | 7 SMG | weapon mix (balance, I) |
| home_guards_42 (J42:5) | Banzai chargers | 42-43 | 15: 8 T38 bay.; 7 T100 bay. | as above | 7 early T100 | weapon mix |
| home_guards_throwgun (J44:6) | Melee/Grenade Banzai chargers | 44-45 | 15 x `throwable_gun` (dummy grenade) + T99r bayonet melee | no ToE equivalent | game mechanic | fine (deliberate) |
| elites_ig (J44:30) | Imperial Guard section | 44-45 | 15: 7 T99r (65, 4 g97, 2 T3AT, 5 AP mines); 2 `jap_kanoeShidan_type38rifle` (file content = T99r, despite name); 2 T99 LMG (210); 2 T100-44; 1 T100 + T4RL (5 rockets); 1 T99r | Guards divisions used normal Army ToE (H2) | 2 LMG; SMGs; T4RL in 1944; breed named type38 holds a T99r (`jap_kanoeShidan_type38rifle.set`) | wrong year (T4RL 44), weapon mix |
| elites_ig_42 (J42:19) | Imperial Guard section | 42-43 | 15: 4 T99r; 6 T38; 2 T99 LMG; 2 T100; 1 T100 + **T4RL** | Army ToE (H2) | T4RL 2-3 years early; T3AT 1942 | wrong year |
| elites_takasago (J44:34) | Takasago section | 44-45 | 15 stealth: 2 T38 bay.; 6 T99r bay.; 5 T100-44 bay. (4 g97, 2 dynamite); 2 T99 LMG | Takasago Volunteers: small units attached to Army formations, rifles, bayonets, own long knives; no special ToE (H3) | 5 SMG, 2 LMG; giyu knives shown as knife_japan | weapon mix (balance, I) |
| elites_42_takasago (J42:23) | Takasago section | 42-43 | 15: 4 T38; 4 T99r; 5 T100; 2 T99 LMG | as above (H3) | 5 early T100; T3AT 1942 | weapon mix, wrong year |
| elites (J44:36) | Teishin Paratrooper section | 44-45 | 15: 8 TERA (105 rds, 2 g97, T3AT); 2 T99 LMG (270); 3 T100-44 (270); T97 AT rifle + asst (T99r) | Teishin squad ~10-12: rifles/TERA, T100 (folding stock), 1 LMG, grenade launcher; no T97 ATR (59 kg) (H3) | T97 ATR in an airborne squad; T100-44 is not the paratrooper model; 2 LMG | wrong weapon (ATR), weapon mix |
| elites_42 (J42:25) | Teishin Paratrooper section | 42-43 | 15: 9 TERA; 2 T99 LMG; 4 T100 (270) | Palembang Feb 1942: T38/T44 carbines, T100 paratroop guns, weapons in containers (H3) | TERA adopted May 1943 (H1); T3AT 1942 | wrong year |
| stormtroopers (J44:44) | SNLF Paratroopers section | 44-45 | 11: T100-44 (4 g99, 2 T3AT); 2 T99 LMG; 2 T100 + T4RL; 5 T99r (185 rds); asst T99r (185) | SNLF paratroop units (Yokosuka 1st/3rd SNLF) jumped in 1942 only; later SNLF = garrison/ground units, Army-like squads (H2) | "paratroopers" in 1944-45; T4RL in 1944 | wrong year |
| stormtroopers_42 (J42:30) | SNLF Paratroopers section | 42-43 | 15: 4 T100 (4 g99); 2 T99 LMG; 1 T100 + **T4RL**; 5 T99r; 3 T38 (+90 LMG rds) | SNLF paratroopers Menado/Kupang 1942: rifles, few SMGs (H3) | T4RL 1942; T3AT | wrong year |
| riflemans2b (J44:64, J42:54) | Type 38 Rifleman | 42-45 | 1 T38 (65 + 30 LMG rds, 1 g97, 2 AP mines) | rifleman 120 rds, 2 grenades (H2) | 65 vs 120 rds | count off |
| riflemans2 (J44:65, J42:55) | Type 99 Rifleman | 42-45 | 1 T99r (same kit) | T99 from 1939, mixed issue (H1 TM-E 30-480) | 65 vs 120 | count off |
| smgs2 (J44:67, J42:57) | Type 100 SMG | 42-45 | 1 T100 210 rds, 2 g97, T3AT | rare early gun (H1) | T3AT on the 42-43 breed `smg` | wrong year (42) |
| smgs2b (J44:68) | Type 100-44 SMG | 44-45 | 1 T100-44 210 rds | 1944 model from Jan 1944 (H1) | none | fine |
| smg3 (J44:69, J42:58) | Type 2 SMG | 42-45 | 1 "Type 2 SMG" 250 rds (50-rd mag) | experimental, ~120-200 (H2-H3) | not a service weapon | wrong weapon |
| type89mortarinf, x2 (J44:73-74, J42:62) | Type 89 Mortar team | 42-45 | 1 or 2 T89 men, T44c, 8 shells | T89 from 1929, 1 man can operate (H2) | single man w/o asst | fine |
| kamikaze (J44:76) | Kamikaze infantry | 42-45 (J44 only in 44-45) | 2 x lunge mine | lunge mine 1944-45 (H2) | none in 44-45 | fine |
| kamikaze 42 (J42:63, not in cards.tsv) | Kamikaze infantry | 42-43 | 2 x T100 (90 rds) + `type99at` magnetic mine | T99 magnetic mine 1939 (H2) | none | fine |
| at_rifles (J44:80) | Type 97 Auto-Cannon team | 44-45 | T97 ATR (40 rds AP+HE) + T100; asst T100 + 20 rds | T97 crew 4-11 men incl. bearers (H3) | 2 men; crew carry SMGs | count off (balance) |
| at_rifles 42 (J42:67) | Type 97 AT rifle team | 42-43 | T97 + 25 rds, T100, T3AT; asst T100, T3AT | as above | T3AT 1942 | wrong year (minor) |
| bazookers (J44:82) | Type 4 AT Launcher team | 44-45 | 2 x T4RL (8 rds each), T100 | 1945 only (H1) | 1944 tag | wrong year |
| stormtrooper5 (J44:84) | SNLF Type 4 AT team | 44-45 | T4RL + 7, asst 3 rockets | as above | 1944 tag | wrong year |
| teishin_at_rifles (J44:86) | Teishin AT rifles | 44-45 (tags 41-45) | T97 ATR + 3 asst (T99r) | no ATR in paratroop units (H3) | airborne ATR | wrong weapon (H3) |
| mg3 (J44:89) | Type 11 Machine gunner | 44-45 | T11 gunner 185 rds (5-rd clips, correct hopper feed); asst **T99r 7.7 + 205 rds** | T11 crew with 6.5 mm T38 (H2) | asst calibre wrong | wrong weapon |
| mg3 42 (J42:71) | Type 11 | 42-43 | T11 gunner only | T11 still in use 1942 (H2) | none | fine |
| mgs2 (J44:90, J42:73) | Type 99 Machine gunner | 42-45 | T99 gunner 210; asst T99r + 240 LMG rds (44 card) | T99 LMG 1939+ (H1) | none | fine |
| mg2 (J42:72) | Type 96 Machine gunner | 42-43 (J42 only) | T96 gunner 210 | T96 from 1936 (H2) | none; no 44-45 card besides the squads | fine |
| elite_ig2 (J44:94) | Imperial guard Type 99 MG team | 44-45 | T99 LMG + 3 T99r (4 g97, 2 T3AT, 5 mines) | Army LMG team (H2) | none serious | fine |
| elite3 (J44:96) | Takasago Type 99 MG team | 44-45 | T99 LMG + 2 T38 bay. (6.5 mm, cannot feed 7.7 LMG) | as above | calibre mix | wrong weapon (minor) |
| elite3 42 (J42:79) | Takasago Type 99 MG team | 42-43 | `elite_takasago_lmg` + `elite_rifle2` x3 (no breed file) | | missing breed | data mistake |
| stormtrooper6 (J44:100) | SNLF Type 99 MG team | 44-45 | T99 LMG (210, 1 dynamite) + 3 T99r (185) | (H2) | none | fine |
| flamers (J44:104) | Flamethrower team | 44-45 | Type 93/100 flamer + asst T100 | flamethrowers with engineer units (H2) | asst SMG | fine |
| snipers2 (J44:106) | Type 97 Sniper | 44-45 | T97 sniper 6.5, 105 rds | 1937+ (H2) | none | fine |
| snipers (J44:107) | Type 99 Sniper | 44-45 | T99 sniper 7.7, 105 rds | 1942+ (H2) | none (J42 version 65 rds) | fine |
| officers, officers_40 (J44:109-110) | Officer | all | Nambu, 32+8 rds, binocular | officer pistol + sword (H2) | no sword (game) | fine |
| vehic_supporter (J44:56) | Support crew | all | 2 x T44 carbine | | | fine |

Out of cards.tsv but in J44: `elites_drop` (J44:38, airborne spawn of the Teishin squad, same findings) and ap/at miners,
sappers (T100 SMGs, 6 men with 15 AP mines each).

## 3. Minor Axis: card table

Nation from breed prefix: axm_ita Italy, axm_hun Hungary, axm_rom Romania, axm_bul Bulgaria, axm_fin Finland.
All tagged 44-45 except officers (39-45) and vehicle supporter (42-45).

| card (AXM:line) | title | nation | mod squad | historical squad (confidence) | differences | severity |
|---|---|---|---|---|---|---|
| Bulgarian_Infantry (8) | Bulgarian Infantry | BUL | 8: leader MP40 (160, 2 M24 bundles, smoke); 7 Kar98k (`mauzer`, 125 rds, 1 M24) | section ~10-12 with 1 ZB vz.26/30 LMG, Mannlicher M95 rifles, some Mauser (H3) | no LMG; Kar98k instead of M95 (the mod's own miners carry M95); 1945 tag (Bulgaria Allied from Sept 1944) | wrong weapon, wrong year |
| hungarian_smg_squad (10) | Hungarian SMG Squad | HUN | 9: leader 43M (200, 4 x 42M); 4 PPSh (311, 2 x 36M, molotov); 4 39M (200) | no all-SMG squad; 39M/43M with paratroop, assault, motorised units; captured PPSh used (H2-H3) | all SMG | weapon mix (balance, I) |
| romanian_rifle_squad (12) | Romanian Rifle Squad | ROM | 10: leader Orita (160); 7 ZB vz.24 (125, 2 M24 + bundle, shovel); ZB30 gunner 270; asst ZB24 + 240 LMG rds | grupa ~10-12: ZB vz.24 rifles, 1 ZB30, leader rifle or Orita late (H3) | Orita fine 1943+ (H1); German M24 grenades (Romania had own types, H3); 1945 tag | wrong year (45) |
| fin_pioneer (14) | finnish pioneers | FIN | 10: leader Suomi (281, kasapanos 2 kg); LS/26 gunner (340, Luger); rifle M/27 + dynamite; 2 Suomi; 4 M/27 (125, 1 M24, spades); flamer M/40 (Luger) | pioneer squad ~10, rifles + 1-2 SMG + LMG, charges (H3) | M/27 instead of M/39 (main rifle 1944, H2); pistols for LMG/flamer fine | fine (minor), 1945 tag |
| fin_kaukopartio (18) | Kaukopartio | FIN | 9: leader Suomi; LS/26 (340); asst M/27 + 320 LS rds; 2 Suomi (284); 4 M/27 (125, 2 M24, M24 bundle, 2+4 kg charges, dynamite, molotov, 3 AP mines) | long-range patrols 5-15 men, SMG-heavy, light kit, few LMGs (H3) | heavy explosive load; LS/26 heavy for LRRP | weapon mix (minor) |
| Sissi (23) | Sissi | FIN | 9: leader Suomi; LS/26; asst M/27 + 300; 2 Suomi; 4 M/27 (1 M24) | sissi battalions: light infantry, Suomi + rifles (H3) | asst carries 300 LS rds vs 320 elsewhere | fine |
| Hungarian_Assualt_Infantry (25) | Hungarian Assualt Infantry | HUN | 11: leader 39M (230, 3 F1); 2 43M rifle 7.92 (195, F1, 36M, molotov); 4 39M (230, 3 F1); Solothurn 31M (270); asst 35M 8x56 (325) + 120 LMG; Panzerfaust 60 x2 + 39M; flamer | raj ~12: 35M/43M rifles, 1 31M LMG, 1-2 SMG; assault (rohamutász) units more SMG (H3) | Soviet F1 grenades as standard issue (H3); 31M mag 30 in mod vs 25 historical (H2); Panzerfaust 60 fine late 44 | weapon mix (minor) |
| Alpini (27) | Alpini | ITA | 13: 4 M91/38 7.35 (166, 1 Breda 35); 2 MAB (200, OTO 42 incendiary); Breda 30 (340, Beretta 34); asst M91/38 + 160; 3 M91 6.5 (166); leader MAB (200, 3 OTO 35); sniper M91 scoped + Beretta (160!) | Alpini squad as infantry ~18-20 with 1-2 Breda 30, M91 6.5 (H3); 7.35 withdrawn 1940-41 (H2); RSI Alpini (Monterosa) 1944-45 (H1) | mixed 6.5 / 7.35 calibre; scoped Carcano rare (H3); Royal Alpini on the Axis side end 1943 | wrong year, weapon mix |
| Bersaglieri (21) | Bersaglieri | ITA | 11: 4 M91 6.5 (246, 1 Breda 35); 2 MAB (280, Breda 42 AT, 2 smoke); Breda 30 (180 + 160 asst); asst M91; 3 M38 7.35 (246); **no leader** | as infantry (H3) | no leader; 6.5/7.35 mix; 240 Carcano rds vs ~72-96 (H3) | count off, weapon mix |
| Paracadutisti (34) | Paracadutisti | ITA | 12: leader MAB (280, 3 Breda 35, 2 OTO 42, 4 smoke); 6 **Scotti Model X** (246); 2 MAB; 2 Breda 30 (260); asst Scotti + 240 LMG | Folgore/Nembo squad ~10-12: Carcano M91 carbines (folding bayonet), 1 Breda 30, 1-2 MAB (H3) | Scotti semi-auto instead of Carcano; 2 LMG | wrong weapon |
| tankcrew (36) | Tank crew | HUN | 4 Frommer 37M (43 rds) + commander 39M (120) | | | fine |
| vet_tankcrew (38) | Veteran tank crew | ROM | 1 Orita (96) | | | fine |
| sappers (40) | sappers | ROM | 2 Orita, dynamite, mine detector | | | fine |
| vehic_supporter (42) | Vehicle Supporter | BUL | 2 Kar98k (65) | | | fine |
| carcano (50) | Carcano | ITA | 1 M91 (246) | | 246 rds high | count off |
| zb_24rifle (52) | zb 24rifle | ROM | 1 ZB vz.24 (125) | | | fine |
| orita (54) | Orita | ROM | 1 Orita (160) | 1943+ (H1) | | fine |
| suomi_m31 (56) | Suomi m31 | FIN | 1 Suomi (284 = 71 + 213) | drum 70 (H2) | 213 vs 210 on other Suomi breeds (3 stray rds) | fine |
| danuvia (58) | Danuvia SMG | HUN | 1 39M (230) | | | fine |
| AP_Miners / AT_Miners (60-61) | AP / AT miners | BUL | 4 M95 (125 / 30) + 15 AP or 4 AT mines | | M95 correct here | fine |
| solothurn_31m (65) | Solothurn 31m | HUN | 31M + asst 35M | 31M = MG 30 licence, 8x56R (H2) | 30-rd mag vs 25 (H2) | count off (minor) |
| zb_vz26 (66) | zb_vz26 | BUL | gunner 140 rds + Walther; asst Kar98k + 120 LMG | (H3) | 260 LMG rds total, low | count off |
| breda30_alpini / _bers / _para (68-72) | Breda 30 teams | ITA | gunner + asst, 340-500 rds | Breda 30 20-rd fixed magazine, charger-fed (H2) | | fine |
| Boys_AT_Rifle (74) | Boys AT rifle | FIN | Boys + 55 rds; asst Suomi + 50 | Finland bought Boys 1939-40 (H2) | obsolete vs 1944 armour | fine |
| pzb_at_Rifle (76) | pzb AT rifle | BUL | PzB 39 + 35; asst MP40 + 10 + Hohlladung | (H3) | | fine |
| panzerfaust (81) | panzerfaust | HUN | 2 x 39M + 2 Pzf 60 each | Pzf to Hungary 1944 (H2) | | fine |
| panzershreck (83) | panzershreck | ROM | RPzB + 5, Walther; asst Orita + 5 | some RPzB to Romania 1944 (H3) | | fine (44 only) |
| Radioman (85) | Radioman | BUL | MP40 + flare gun | | | fine |
| flamers (87) | flamers | FIN | flamer + Kaukopartio rifleman | Finnish M/40 flamer (H3) | | fine |
| finnish_sniper (89) | finnish sniper | FIN | M/27 scoped (`mosin_s_fin` "M/27PH"), 125 rds | Finnish snipers often used iron sights; scoped M/27 few (H3) | | fine |
| officer, officers_40 (93-94) | officers | FIN | Luger + 32 | | | fine |

Not in cards.tsv: `Motorized_Hungarian_Rifles` (AXM:16, Botond truck, 35M rifles 245 rds, 43M 325 rds), `bersaglieri_motorcycle`
(AXM:29, tag hero), `Bersaglieri_Mot` (AXM:31, missing breed, see finding 3).
Entity cards in cards.tsv for both sides are vehicle crews only (tankmen, vehicle supporters); no infantry content.

## 4. Anachronisms (year)

Certain in the data; history confidence noted.
1. Type 4 70 mm RL in 1942-43: `elite_ig4.set` (J42:19), `sturmovik3.set` (J42:30). Launcher designed 1944, used 1945 [H1].
2. Type 4 RL in 1944: `bazookers` J44:82, `stormtrooper5` J44:84, `jap_kanoeshidan_at` in elites_ig J44:30, `jap_snlf_at` x2 in
   stormtroopers J44:44. 1945-only is the likely fix: tag 45 [H1 for 1945 use; no 1944 use known].
3. Type 3 AT grenade in 1942-43 breeds: squadleader, squadleader2, smg, smg2, elite*, elite_ig*, elite_takasago_*, sturmovik*,
   at_rifle, at_rifle2, flamer2, smg3. Adoption 1943, issue mostly 1944-45 [H2]. 1943 is borderline, 1942 is not.
4. TERA Type 2 rifle in elites_42 (J42:25, J42:26 drop): adopted May 1943 [H1]; 1942 games early.
5. Type 100 early SMG in 1942 in large numbers (smgs_42 10, home_guards_42 7, Teishin/SNLF 4 each): production of the early run
   ~1,000 in 1942-43 [H1]; existence fine, quantity not.
6. Minor Axis 1945: Romania (Allied from Aug 1944), Bulgaria (Sept 1944), Finland (armistice Sept 1944) cards in 45 games;
   Royal Italian Army squads (Alpini, Bersaglieri) in 44-45 where only RSI units existed [H1]. Hungary 44-45 fine.
7. Minor Axis absent 41-43 (tags 44 45 only while the side is loaded in units_41/42/43): the period of their main fighting
   (Italy Russia 1941-43, Romania Stalingrad 1942, Finland Continuation War 1941-44) has no minor Axis infantry [I].
8. Not anachronisms (checked): lunge mine (J44 only), Type 100-44 (44-45 only), Orita (44-45; 1943+), Panzerfaust/Panzerschreck
   (44), MAB 38A (44-45, RSI common), Type 99 sniper (J42/J44, 1942+), 43M Danuvia and FEG 43M (44-45).

## 5. Ammunition and grenades off the standard issue

| item | mod | standard | confidence | note |
|---|---|---|---|---|
| Japanese rifleman (T38/T99r) | 65 rds (5 + 60), +30 LMG rds | 120 (30 + 30 front, 60 rear) | H2 | half; jap_snlf_rifle_type99 185 and jap_mg3_asst 205 are the exceptions |
| Japanese grenades | 1 g97 per rifleman, 2 per SMG man, 4 leader/elite | 2 per man (Type 91/97/99) | H2-H3 | rifleman short by 1 |
| Japanese AP mines | 2 per rifleman, 5 per elite | not standard rifleman kit | H3 | game feature (I) |
| Type 96/99 LMG section load | gunner 210 + asst 30 + bearers 3 x 120 + riflemen 4 x 30 = 720 rds of 6.5 mm | ~? | H3 | the 4 x 30 rds of 7.7 mm on Type 99 riflemen fit no gun in the squad (gun is a Type 96) |
| Type 11 LMG | 185 rds 6.5 in clips | hopper of 6 clips (30) | H2 | correct feed; asst ammo wrong calibre |
| Type 89 section | 120 shells (3 x 8 + 6 x 16) | bearers ~8 shells each? | H3 | plausible |
| Type 100 SMG | 210 (7 mags) | not documented | H3 | |
| Carcano 6.5 (Bersaglieri, paras, single card) | 246 rds | ~72-96 (two pouches, 6-rd clips) | H3 | Alpini 166; 6-rd clip modelled right (`filling 6`) |
| Breda 30 | 20-rd fixed mag, 340-500 per team | charger-fed 20 (H2) | | fine |
| Suomi KP/-31 | 71-rd drum, 281-284 per man | 70-rd drum; ~3-4 drums | H2 | 213 vs 210 inconsistency (axm_fin_kaukopartio_smg, axm_fin_at_rifleassist) |
| LS/26 | 20-rd mag, 340 gunner + 300-320 asst | 20-rd magazine | H2 | fine |
| Solothurn 31M | 30-rd mag | 25-rd mag (MG 30) | H2 | `stuff\mgun\solothurn_31m` filling 30 |
| ZB vz.26 (BUL) | 260 per team | ~1,000+ per LMG in squad | H3 | low |
| Danuvia 39M/43M | 40-rd mag, 200-230 | 40-rd (H2) | | fine |
| Orita | 32-rd mag | 32 (H2) | | fine |
| Italian grenades | Breda 35 / OTO 35, Breda 42 AT, OTO 42 incendiary, CCM 34 smoke | OTO / Breda / SRCM Mod.35 standard (H2); Mod.42 types unverified (H3) | | no SRCM 35 used anywhere |
| Hungarian grenades | 36M, 42M, Soviet F1 (assault squad 3 each) | 36M Vécsey standard (H2); F1 not standard (H3) | | |
| Finnish grenades | German M24 + bundle, kasapanos 2/4 kg | Finnish M/32 stick, M/41 egg, kasapanos (H2) | | stick grenade stands in for the Finnish one (fine as model) |
| Romanian grenades | German M24 | Romanian own types + some German (H3) | | |

## 6. Cards that match (fine)

Japan: smgs2b, type89mortarinf (x1, x2), kamikaze (both eras), mg3 42, mgs2, mg2, elite_ig2, stormtrooper6, flamers, snipers2,
snipers, officers, officers_40, vehic_supporter, home_guards_throwgun (deliberate mechanic).
Minor Axis: tankcrew, vet_tankcrew, sappers, vehic_supporter, zb_24rifle, orita, suomi_m31, danuvia, AP/AT miners,
breda30 teams, Boys_AT_Rifle, pzb_at_Rifle, panzerfaust, panzershreck, Radioman, flamers, finnish_sniper, officers, Sissi.

## 7. Likely deliberate (balance or owner choice) [I]

- 15-man Japanese squads: owner note "JAPAN / squad size 15" (`tings to do.txt`:840-841).
- SMG-heavy Japanese squads (Assault, Banzai, Takasago) and the Hungarian SMG squad: a role card per faction, as in other sides.
- Japanese 65-round riflemen: may be to push melee/banzai play; the same 60 + clip pattern is used on all `rifle_type38*` macros
  (breed_kit.inc).
- Type 2 SMG single card: the owner rejected it for elites as "too rare" (`tings to do.txt`:118) but kept a single card.
- Minor Axis only in 44-45: may be to pair them with the 44-45 German lists; it leaves 41-43 without minor Axis infantry.

## 8. ToE text proposals

No file in `<mod>\localization\desc\mod\squad\jap\*.inc` or `...\axis_minor\*.inc` has a `; ToE:` line (grep count 0 in all four
files; the ger files have them, e.g. ger\squad1.inc:18). So there is no empty ToE line to fill. If the owner adds the line as in
ger, these one-liners fit (confidence in brackets; not written into the mod):

| card | proposed `; ToE:` text |
|---|---|
| riflemans_t96* / riflemans_t96_42 | IJA rifle squad (c.1940-45): 13 men, leader, Type 96 LMG team of 4, 8 riflemen with Type 38, 120 rds and 2 grenades each (TM-E 30-480, unverified detail) |
| riflemans* / riflemans_42 | IJA rifle squad converted to 7.7 mm: 13 men, leader, Type 99 LMG team of 4, 8 Type 99 rifles, 1-2 rifle grenade launchers (TM-E 30-480) |
| riflemans_t96_4, riflemans_4 | IJA grenade discharger squad: 13 men, leader, 3 (later 4) Type 89 dischargers each with gunner and ammo bearers, rifles (from memory) |
| smgs, smgs_42 | No IJA ToE: game assault squad; Type 100 SMGs were few (about 1,000 early, 7,500 1944 model) |
| home_guards*, home_guards_throwgun | No ToE: banzai charges were made by ordinary rifle squads with rifle and bayonet |
| elites_ig, elites_ig_42 | Imperial Guards Division: standard IJA rifle squad (13 men, 1 LMG); no separate ToE known |
| elites_takasago, elites_42_takasago | Takasago Volunteers: Taiwanese aboriginal units attached to Army formations, rifles and long knives; no fixed squad ToE known |
| elites, elites_42 | Teishin (Army paratroop) squad c.1942-44: about 10-12 men, carbines then Type 2 TERA (1943+), Type 100 paratrooper SMGs, 1 LMG (from memory, unverified) |
| stormtroopers, stormtroopers_42 | SNLF paratroop company (Yokosuka 1st/3rd SNLF, 1942): rifles, few SMGs, LMG per squad; later SNLF fought as ground infantry (from memory) |
| Bulgarian_Infantry | Bulgarian rifle section c.1944: about 10-12 men, 1 ZB vz.26/30 LMG, Mannlicher M95 and Mauser rifles (from memory, unverified) |
| hungarian_smg_squad | No standard ToE: 39M/43M SMGs went to assault, paratroop and motorised units; captured PPSh also used |
| romanian_rifle_squad | Romanian infantry grupa c.1943-44: about 10-12 men, ZB30 LMG, ZB vz.24 rifles, Orita SMG from 1943 (from memory) |
| Hungarian_Assualt_Infantry | Hungarian rifle squad (raj) c.1944: about 12 men, 31M Solothurn LMG, 35M/43M rifles, a few 39M SMGs, Panzerfaust from 1944 (from memory) |
| Alpini | Alpini rifle squad c.1941-43: about 18-20 men with 1-2 Breda 30 and Carcano M91; 1944-45 only RSI Monterosa division (from memory) |
| Bersaglieri | Bersaglieri squad: as line infantry, Carcano M91/M38, 1-2 Breda 30, MAB 38A from 1942-43 (from memory) |
| Paracadutisti | Folgore/Nembo para squad c.1942: about 10-12 men, Carcano M91 carbines, 1 Breda 30, some MAB 38A (from memory) |
| fin_pioneer | Finnish pioneer squad: about 10 men, rifles, Suomi SMGs, LS/26, kasapanos charges, flamethrower M/40 (from memory) |
| fin_kaukopartio | Finnish long-range patrol (kaukopartio): 5-15 men, Suomi SMGs and rifles, explosives, no fixed ToE |
| Sissi | Finnish sissi (light infantry) squad: rifles, Suomi SMGs, LS/26 or captured DP (from memory) |

## 9. Not checked

- Exact squad ToE documents for Japan (TM-E 30-480 chapter not read; web search only gave the handbook's existence and the
  6.5 -> 7.7 mm conversion), Italy (1940 vs 1942 tables conflict), Hungary, Romania, Bulgaria, Finland: all [H3] above unless marked.
- Whether the game really filters cards by year tag the way read here (presets `{unitset {value "42"}}`); no game run.
- What happens in game with the missing breeds `elite_rifle2` and `axm_bersaglieri_mgun` (no log read).
- Italian Mod.42 grenades (Breda 42 AT, OTO 42 incendiary): not verified to exist.

## Questions for the owner

1. "w/Type 99 LMG" cards use `jap_mgun2` (Type 96): meant `jap_mgun`?
2. `elite_rifle2` in squads_42-43.set:79: meant `elite_takasago_rifle2`?
3. `axm_bersaglieri_mgun` in axis_minor squads.set:31: meant `axm_ita_bersaglieri_mgun`?
4. Type 4 RL: move to 45 only and remove from the 42-43 IG/SNLF squads?
5. Type 3 AT grenade on 1942-43 breeds: keep for balance or drop for 42?
6. Minor Axis infantry only in 44-45: deliberate, or should Italy/Romania/Finland get 41-43 tags?
7. Romania, Bulgaria, Finland in 45 games: acceptable?
8. Japanese riflemen 65 rounds: deliberate (vs 120)?
9. Italian paratroopers with Scotti Model X: wanted, or Carcano M91 carbine?
10. Should Japanese sections keep one calibre (Type 38 with Type 96, Type 99 with Type 99)?

Sources from web search: [TM-E 30-480 Handbook on Japanese Military Forces (ibiblio)](https://www.ibiblio.org/hyperwar/Japan/IJA/HB/),
[Lone Sentry Japanese squad weapons](https://lonesentry.com/articles/jp_squadweap/index.html),
[Wikipedia: Type 100 submachine gun](https://en.wikipedia.org/wiki/Type_100_submachine_gun),
[Forgotten Weapons: Type 100/44](https://www.forgottenweapons.com/type-100-44-late-pattern-japanese-smg/),
[Wikipedia: TERA rifle](https://en.wikipedia.org/wiki/TERA_rifle),
[Wikipedia: Type 4 70 mm AT rocket launcher](https://en.wikipedia.org/wiki/Type_4_70_mm_AT_rocket_launcher),
[Wikipedia: Breda 30](https://en.wikipedia.org/wiki/Breda_30),
[Wikipedia: Danuvia 43M](https://en.wikipedia.com/wiki/Danuvia_43M),
[Wikipedia: Orița M1941](https://en.wikipedia.org/wiki/Ori%C8%9Ba_M1941).
