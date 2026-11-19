# RobZ Realism 1.31.0: US and British/Commonwealth infantry against historical TO&E

Read-only job. Mod = `E:\RobZ Realism\robz realism mod 1.31.0` (below `<mod>`). Nothing in the mod was changed.
Scratch: `E:\arsenal-tmp\robz-toe\toe-usa-eng\` (expand.js, exp2.js: each card expanded to men + inventory from breeds.tsv).

Legend. DATA = read from mod files (certain). [I] = my inference. HIST = history fact, with how sure I am:
(sure) = standard reference knowledge, (web) = checked on the web this session (source named at the end), (mem) = from memory, unverified.
Severity: **wrong year** / **wrong weapon** / **count off** / **fine**.

## 0. How the years really work (DATA; read this first)

- Year presets load different unit files. `<mod>\resource\set\multiplayer\games\presets_4x.inc` set `unitset` 41, 42, 43, 44, 45, "44|45|sf"
  and apply `units\units_41.set` .. `units_45.set`:
  - 1941: `units_41.set:15` loads `eng\squads_40-41.set` only. **No US side in 1941.**
  - 1942: `units_42.set:10,17` loads `usa\squads_42.set` and `eng\squads_42-45.set`.
  - 1943, 1944, 1945: `usa\squads_43-45.set` and `eng\squads_42-45.set`.
  - No preset uses 39 or 40. Tags 39 and 40 never show a card.
- So the effective years of a card = its tags AND the years its file is loaded. Examples: every US card tagged 39-41 is never shown in 39-41;
  `riflemans_can(eng)` in squads_42-45 tagged 40-45 shows only 42-45 (the 1941 copy comes from squads_40-41.set).
- **cards.tsv is not a full picture** of these two sides: it keeps one row per card name, takes the soldiers of one file and merges the
  tags of all files (SAS section shows "43 44 45 41 42"). It has no row for the whole US 1942 roster (`usa\squads_42.set`, 22 cards
  with different breeds) and no row for the eng 1941 copies (`eng\squads_40-41.set`). I expanded those files myself (exp42.txt).
- The armored squad row in cards.tsv lists a soldier `04`: a parse artifact of the macro `squad_with4types` (`usa\squads_43-45.set:4`);
  the squad is 12 men.
- Entity cards (entity/usa, entity/eng: guns, mortars, vehicles) are crewed by `vehicle_supporter`/tankmen, not by TO&E teams;
  no hero card of these sides is a soldier. They are out of scope except the 2-inch mortar card (it has its own two breeds).

Weapon names checked in `<mod>\localization\desc\mod\weapon\common\*.inc`, `desc\vanilla\weapon.inc`, `desc\mod\stuff\grenade.inc`:
em3 = **Lee-Enfield No.1 Mk III*** (not No.4; the brief's note is wrong for this mod), em3_vet = same [Veteran], em3_mark1 = No.1 Mk III* with
cup discharger, em2 = No.1 Mk III* (T) sniper, sten_mk2 = Sten Mk II, sten_v = Sten Mk V, sten_v_silencer = "Sten Mk VI w/ Suppressor",
de_lisle = De Lisle carbine, boyes = Boys .55, piatrocket = PIAT, mortar_mkvii = 2-inch Mk II, garand = M1, garand_grenade = M1 + launcher
(M7 [I]), bar_rifle = BAR (20-rd mag), browning_m19a6 = M1919A6, thompson = Thompson M1A1 (30-rd), m3a = M3 grease gun, m1_carbine/m1a1_carbine
= M1 / M1A1 carbine (15-rd), m2_carbine = M2 carbine (30-rd), m1903 = M1903A3, m1903a4 = M1903A4 sniper, johnson = M1941 rifle,
johnson_m1941_rifle = Johnson LMG, m50reising = Reising, m12_shotgun = Winchester M12, bazooka = "Bazooka M1A1", bazooka_m9 = "Bazooka M9A1",
m18recoilless = M18 57mm RR. Grenades: "grenade m61" = "Mk2 grenade", "grenade mk1" = "Mills bomb No.36", n73at = No.73 AT,
n77_smoke = No.77 WP, m15_smoke = M15 WP, "smoke grenade" = generic smoke. No No.4 rifle, no No.82 Gammon bomb, no No.75 Hawkins exists in the mod.
Ammo numbers below are rounds in the pack, the loaded magazine comes on top (`breed_kit.inc`: e.g. rifle_garand = garand filled + 80).

## 1. Ranked findings (most likely mistakes first)

1. **Thompson cards hold Stens (wrong weapon + wrong year).** `eng\squads_40-41.set:5` "Assault section w/ Thompsons" (1941): 4x smg2_40 with
   Sten Mk II; `:46` "Thompson SMG" (1941): smg_40 with Sten Mk II (breed `mp\eng\smg2_40.set`, `smg_40.set`). HIST (sure): Sten Mk I first
   issued mid/late 1941 in small numbers, Mk II from 1942; 1940-41 British SMG = Thompson M1928. All 1941 eng breeds with sten_mk2
   (at_rifle team, flamer2, ap/at miners, sappers, vehicle_supporter_40, tankman2) share this.
2. **Sten Mk V / Mk VI / De Lisle in 1941-43.** HIST (web): Sten Mk V first issued Feb 1944; Mk VI (suppressed) 1944; De Lisle 1943-44, very few.
   DATA: elites_40 Commando section (1941 from squads_40-41:15, 1942 from squads_42-45:19): Sten V, 3x Sten VI suppressed, 4x De Lisle.
   Paratrooper section 1941-43 (squads_40-41:19, squads_42-45:25): all Stens are Mk V. SAS section 1941 (squads_40-41:20): Sten V.
   Every rifle/assault section leader (eng_squadleader, eng_squadleader2) carries Sten V in 1942-43 (squads_42-45:4,11,12).
3. **PIAT before 1943.** HIST (sure): PIAT first used Tunisia/Sicily 1943. DATA: Rifle section (squads_42-45:11, tags 42-45) has eng_rifle_piat
   in 1942 (`weapon piatrocket 0.2 1` = a count form, meaning not verified; if it is a chance, ~20% of men get one [I]); SAS PIAT team
   (squads_42-45:63, tags 42-45) in 1942; SAS section 1941 (squads_40-41:20, sturmovik3 PIAT + 5 rockets); mech_rifles (squads_42-45:15) 1942.
4. **US late-war weapons in the 1942 roster (`usa\squads_42.set`).** HIST: M1919A6 first combat Salerno Sept 1943, general issue 1944 (web);
   M9 bazooka standardized late 1943, M9A1 1944 (mem); M3 grease gun standardized Dec 1942, issued 1943-44 (sure); M1903A4 adopted Jan 1943 (mem).
   DATA 1942: mg2 ":75" card titled "M1919A6" (single mgun2 with A6); Airborne squad ":18" has M1919A6 + M1903A4; Ranger squad ":28" and Ranger
   bazooka team ":70" have bazooka_m9 (M9A1); grease gun on ap_miner, at_miner, saper, tankman2, flamer2 and three radiomen (":40-105").
5. **M2 carbine in 1943-44.** HIST (web): M2 standardized Oct 1944, first real use Okinawa April 1945, very little WWII combat.
   DATA: Ranger Assault squad (`usa\squads_43-45.set:40`, 43-45) 2x usa_ranger_carbine, Ranger BAR fire team (`:100`, 43-45) 2x, both M2 + 180 rds.
6. **M18 57mm recoilless in 1944.** HIST (sure): first combat Operation Varsity, March 1945 (17th Airborne). DATA: 101st Airborne squad
   (`usa\squads_43-45.set:29`, tags 44 45) usa_elite_101st_para4 with M18 + 8+3+1 rounds. The Ranger M18 team (`:86`) is tagged 45 only: fine.
7. **US 1942 "Armored rifle squad" is a 5-Thompson squad.** DATA: the card key `smgs(usa)` is titled "Armored rifle squad"
   (`desc\mod\squad\usa\squad1.inc`), but in 1942 the same key is loaded from `usa\squads_42.set:5` = squadleader2 + 6x rifle2 + 5x smg2
   (Thompsons). [I] old 1.28.6 "assault squad" kept under a title made for the 1943-45 roster. Not a US TO&E type.
8. **Marines with M1 Garands in 1942.** HIST (sure): 1st Marine Division landed on Guadalcanal (Aug 1942) with M1903 Springfields; Marines
   converted to M1 during 1942-43. DATA: Marine squad 1942 (`usa\squads_42.set:14`): 10x elite5 with Garand; BAR team ":79" Garand.
9. **Boys AT rifle in 1944-45.** HIST (sure): replaced by PIAT in 1943. DATA: Boys AT-Rifle team (squads_42-45:59, tags 39-45) shows 1942-45; SAS
   section (squads_42-45:27, 43-45) has eng_sas_at_rifle with Boys + 15 rds. Paramarine Boys man (usa_paramarine_boys, 43-44) is fine (Marines did use some Boys 1942-43, mem).
10. **No.4 rifle missing.** HIST (sure): No.4 Mk I was the main rifle of 21st Army Group 1944-45 (Italy stayed mixed). DATA: every British
    rifleman 1941-45 has em3 = No.1 Mk III*; sniper em2/em2_vet = No.1 Mk III* (T) where No.4 (T) was the 1942+ sniper rifle. No No.4 model exists in the mod.
11. **Flamethrowers too early.** British flamer team shown 1941-45 (squads_40-41:66, squads_42-45:79). HIST (mem): the portable "Lifebuoy" was
    first used in 1944; earlier British flamers (Harvey) were cart-mounted. US flamer team 1942 (squads_42:94): M1 first used Jan 1943 Guadalcanal (mem) - borderline.
12. **No.77 WP and No.73 AT grenades.** No.77 is given to 1941 leaders (squads_40-41:5,9) [I: 1943 intro, unverified on the web - only "recently
    introduced" in a 1944 context]. No.73 (HIST web: issued 1940, withdrawn within a year, reissued 1943 for demolition) is carried by nearly
    every British leader and many men 1941-45, as an AT grenade.
13. **No Gammon bomb / Hawkins.** HIST (sure): No.82 Gammon used by British and US paras 1943-45; No.75 Hawkins 1942-45 mine/grenade. Not in the mod.
14. **US BAR count deliberate.** "Rifle Squad w/2x BARs" and 2 BAR in Ranger/101st cards go beyond the Army 1-BAR T/O; `tings to do.txt:250-262`
    plans "3x 12man squads, ... 2 BAR" - the owner's choice. Marked count off but deliberate.
15. **Dead card: a 0 count.** `usa\squads_43-45.set:14` mech_armor_rifles has `member5(usa_armor_mgun:0)` - one BAR (member4) plus a zero entry. Harmless? [I], check.

## 2. Per-card table: British / Commonwealth (eng)

Years = years the card can really be bought (see section 0). Men in the order of the card. Ammo = rounds in pack (+ loaded mag).

| card | title | years | mod squad (DATA) | historical squad (HIST) | differences | severity |
|---|---|---|---|---|---|---|
| riflemans_40 (40-41:9) | Rifle section | 41 | Cpl rifle; 8 rifle (50 rds, 2 Bren mags, 1 Mills); Bren (8 mags) = 10 | 1940-41 section, 10 men (sure): Cpl (rifle or Thompson), L/Cpl, Bren No.1, No.2, 6 riflemen, all No.1 Mk III | no Bren No.2 (one more rifle instead); leader No.77 + No.73 | fine |
| smgs_40 (40-41:5) | Assault section w/ Thompsons | 41 | Cpl with cup discharger + 25 rifle grenades, **no .303**; 5 rifle; 4 **Sten Mk II** = 10 | not a TO&E type; 1941 SMG = Thompson M1928 | Stens in place of Thompsons; 25 rifle grenades, no rifle ammo on Cpl | wrong weapon |
| riflemans_can (40-41:10 / 42-45:10) | Canadian Rifle section | 41-45 | 41: Cpl, 8 rifle, Bren; 42-45: Cpl, 7 rifle, Bren, No.2 (8 mags + 6) = 10 | Canadian = British section (sure) | Cpl rifle in 1944 (Sten usual); No.1 rifle in 1944 (No.4 usual) | fine |
| riflemans_scot (40-41:11 / 42-45:13) | Highlanders Rifle section | 41-45 | same as Canadian | British section | as Canadian | fine |
| riflemans (42-45:11) | Rifle section | 42-45 | Cpl Sten V (7 mags); L/Cpl rifle; 4 rifle (60 rds, 2 Bren mags); rifle grenadier (6 grenades); Bren; No.2; PIAT man (count form 0.2 1) = 10 | 1943-44 section, 10 (sure): Cpl Sten, L/Cpl, Bren 1+2, 6 riflemen; PIAT and 2-inch at platoon HQ | Sten V 42-43; PIAT 42; PIAT inside section | wrong year |
| riflemans_at (42-45:12) | Rifle section w/ PIAT | 43-45 | Cpl Sten V; L/Cpl; 5 rifle; PIAT gunner with Sten II (7+3 rockets); Bren; No.2 = 10 | as above, PIAT attached from platoon HQ | Sten V in 43 | wrong year (43 only) |
| smgs (42-45:4) | Assault section | 42-45 | Cpl Sten V; L/Cpl; 3 rifle; 3 Sten II; Bren; No.2 = 10 | no such TO&E; a section with extra Stens is plausible 1943-45 | Sten V 42-43 | wrong year (42-43) |
| mech_rifles (42-45:15) | (same men as riflemans + M5/M3 halftrack m3_eng) | 42-45 | as Rifle section | motor battalion section rode carriers/halftracks (mem) | PIAT 42, Sten V 42-43 | wrong year |
| pioneers (42-45:6) | Pioneer section | 43-45 | Sgt rifle; flamer; Bren; rifle+PIAT; AP miner (31 AP mines); AT miner (8); 4 trench men (2 satchel, 2 AT mines); mine-clearer (detector); 1 more = 12 | RE field company section ~1 Sgt + ~15 sappers, rifles + Bren (mem) | flamethrower in 43 (Lifebuoy 1944); 31 mines on one man | count off |
| elites_40 (40-41:15 / 42-45:19) | Commando section | 41-42 | Cpl Sten V (4 mags); 3 Sten VI suppressed; 4 De Lisle (70 rds); 2 Bren = 10 | 1941-42 Commando subsection ~10-12: Thompsons, rifles, 1 Bren (mem) | Sten V/VI and De Lisle 2-3 years early; 2 Brens | wrong year |
| elites (42-45:21) | Commando section | 43-45 | Cpl + Sgt Sten V (4 mags); 2 Sten V; 2 rifle; 2 Bren; 2 No.2 = 10 | 1943: Thompsons and rifles, 1 Bren; 1944: Sten/Thompson, rifles, 1-2 Bren (mem) | Sten V in 43; 2 Brens | wrong year (43) |
| elite3 (40-41:58 / 42-45:71) | Commando Bren MG team | 41-45 | Bren; 2 rifle [vet] = 3 | Bren group | - | fine |
| paratroopers (40-41:19 / 42-45:25) | Paratrooper section | 41-45 | Cpl + 2ic Sten V (7 mags); **3 Bren**; 2 rifle (100 rds, 4 Bren mags); 2 Sten V; 2-inch man (8 smoke only) = 10 | 1944 para section, 10 (mem): Cpl Sten, L/Cpl, Bren group (1 Bren), riflemen; 2-inch at platoon HQ; Para Regt from 1942 | 3 Brens; Sten V 41-43; British para sections did not exist as such in 1941 | wrong year |
| stormtroopers (40-41:20) | SAS section | 41 | Cpl Sten V; Sten V; Bren (+dynamite); Sten V+PIAT; Sten V+Boys; Bren; 4 rifle [vet] = 10 | 1941 L Detachment SAS: raids on foot/trucks, Thompsons, rifles, Lewis/Vickers K (mem) | Sten V, PIAT in 1941 | wrong year |
| stormtroopers (42-45:27) | SAS section | 43-45 | Cpl + 2ic Sten V; PIAT man Sten V; Boys man Sten V; 2 Bren; 2 No.2; 2 rifle (+dynamite) = 10 | SAS 1943-45 no fixed section; jeeps with Vickers K, Brens, Stens (mem) | Boys in 43-45; Sten V in 43; card absent in 1942 (gap) | wrong weapon |
| stormtrooper5 (42-45:63) | SAS PIAT team | 42-45 | PIAT (5+3) + 2 Sten V | - | PIAT and Sten V in 42 | wrong year (42) |
| stormtrooper6 (40-41:62 / 42-45:75) | SAS Bren MG team | 41-45 | Bren; 2 rifle (100 rds, 6 Bren mags each) | - | - | fine |
| at_rifles (40-41:50 / 42-45:59) | Boys AT-Rifle team | 41-45 | Boys (25-50 rds) + Sten II (+10) | Boys at platoon HQ 1939-42 (sure) | Sten II in 41; offered 44-45 | wrong year (41 Sten, 44-45 Boys) |
| bazookers (42-45:61) | PIAT team | 43-45 | PIAT + Sten II, 7 rockets; No.2 Sten II, 3 rockets | PIAT team of platoon HQ 1943-45; No.2 with rifle (mem) | - | fine |
| mgs2_40 (40-41:54) | Bren Gun team | 41 | Bren gunner alone (8 mags) | Bren No.1 + No.2 | 1 man | fine |
| mgs2 (42-45:67) | Bren Gun team | 42-45 | Bren (8 mags) + No.2 rifle (6 mags) | Bren group | - | fine |
| light_mortar_eng (vehicles_40..45) | 2-inch Mortar Mk.II | 41-45 | No.1 mortar, 6 HE (+loaded) 8 smoke 2 WP; No.2 rifle, 3 HE 5 smoke 2 WP | 2-inch, platoon HQ, 2 men (sure) | - | fine |
| flamers (40-41:66 / 42-45:79) | Flamethrower team | 41-45 | flamer + Sten II | Lifebuoy 1944 (mem) | 41-43 too early; Sten II in 41 | wrong year |
| snipers (40-41:68 / 42-45:81) | SMLE Sniper | 41-45 | No.1 Mk III* (T), 50 / 100 rds | No.4 (T) from 1942 (mem) | rifle model 43-45 | wrong weapon (minor) |
| riflemans2_40 (40-41:44) | SMLE Rifleman | 41 | rifle 50, 2 Bren mags, 1 Mills | - | - | fine |
| riflemans2 (42-45:53) | SMLE Rifleman | 42-45 | rifle 60, 2 Bren mags, Mills (no count), No.73, No.77 (0 1) | - | No.1 in 44-45 | fine |
| smgs2_40 (40-41:46) | Thompson SMG | 41 | **Sten Mk II** (4 mags) | Thompson M1928 | title vs weapon | wrong weapon |
| smgs2 (42-45:55) | Sten Mk.II SMG | 42-45 | Sten II (4 mags), 2 Mills, smoke | - | - | fine |
| officers / officers_40 | Officer | 41-45 | Webley | Webley/Enfield No.2 | - | fine |
| vehic_supporter_40 / vehic_supporter, tankmans | Support / tank crew | 41-45 | Sten II, Webley | - | Sten II in 41 | wrong year (41, minor) |

## 3. Per-card table: United States (usa)

1942 rows come from `usa\squads_42.set` (line given as 42:N); 1943-45 rows from `usa\squads_43-45.set` (43:N).

| card | title | years | mod squad (DATA) | historical squad (HIST) | differences | severity |
|---|---|---|---|---|---|---|
| riflemans 42:9 | Rifle Squad | 42 | Sgt Thompson (5 mags); 10 M1 (80, 2 Mk2); BAR (12 mags) = 12 | T/O 7-17 (1942-43): 12 men, 1 BAR, 1 M1903 with M1 launcher, rest M1 (sure) | Thompson not in T/O (mem: some issued); no M1903 grenadier | fine |
| riflemans_bar 42:10 | Rifle Squad w/2x BARs | 42 | Sgt Thompson; 9 M1; 2 BAR = 12 | 1 BAR | 2 BARs (owner plan) | count off (deliberate) |
| smgs 42:5 | "Armored rifle squad" | 42 | Sgt Thompson; 6 M1; **5 Thompson** = 12 | no such TO&E; 1942 armored infantry squad 12 men, M1, 1 LMG on halftrack (mem) | 5 SMGs, no automatic rifle, title wrong for this roster | wrong weapon |
| specialinf 42:14 | US Marine squad | 42 | Sgt Thompson; 10 **M1**; 1 BAR = 12 | D-series 1942: ~12 men, **M1903**, 1 BAR, some Thompsons (web: D-series to mid 1943) | Garand in 1942 | wrong weapon |
| elites 42:18 (+elites_drop :19) | Airborne squad | 42 | Sgt Thompson; 3 M1A1 carbine; M1903A4; 5 M1; BAR; **M1919A6** = 12 | 1942 parachute rifle squad ~12, M1, carbines, 1 LMG M1919A4 (mem) | M1919A6 (1943-44), M1903A4 (1943); BAR not in T/O | wrong year |
| paramarines 42:23 | Paramarine squad | 42 | Sgt + 1 Reising; 3 Johnson rifle; 5 M1; 2 Johnson LMG = 12 | Paramarines 1942: Reising, Johnson rifle and LMG (sure) | M1 for 5 men in 1942 | fine (minor) |
| stormtroopers 42:28 | Ranger squad | 42 | Sgt + 1 M1 carbine; 2 BAR; **M9A1 bazooka**; 5 M1 = 10 | 1st Ranger Bn 1942 (Dieppe, Torch): M1/M1903, BAR, Thompsons (mem) | M9A1 bazooka 1942; carbines early | wrong year |
| devils_brigade 42:32 | Devil's Brigade squad | 42 | Sgt Thompson; 3 demo; radio; 2 grenadier; Johnson LMG; 4 M1; all Colt = 12 | 1st SSF formed July 1942, first combat Aug 1943 (sure); Johnson LMG + Colt correct | 1942 = training only | wrong year (42) |
| riflemans2 / rifle3 / smgs2 42:58-62 | M1 / M1 Carbine / Thompson | 42 | M1 80; carbine 90; Thompson 150 | - | Thompson M1A1 adopted Oct 1942 (mem) | fine |
| shotguns 42:66 | Marine Shotgunner | 42 | 2 men M12, 90 shells | shotguns issued unofficially/for guards (mem) | - | fine |
| bazookers 42:68 | Bazooka team | 42 | gunner M1 + bazooka, 7+3 rockets | M1 bazooka from Nov 1942 (sure) | named "M1A1" (mid-1943) | fine (label) |
| stormtrooper5 42:70 | Ranger Bazooka team | 42 | **M9A1** + 2 M1 carbines | M1 bazooka | M9A1 2 years early | wrong year |
| mgs2 42:74 | B.A.R. team | 42 | 1 BAR man | - | - | fine |
| mg2 42:75 | 30.cal M1919A6 MG team | 42 | 1 man M1919A6, 250 | M1919A4 tripod team 1942 | A6 in 1942 | wrong year |
| elite6 / elite3 / elite3b / paramarine3 / stormtrooper6 42:79-90 | fire teams | 42 | BAR/A6/Johnson + 1 rifle | - | elite3b A6 in 42; stormtrooper6b Garand carries 250 belt with no MG in team | wrong year (elite3b) |
| flamers 42:94 | Flamethrower team | 42 | flamer + **M3 grease gun** | M1 flamethrower, first use Jan 1943 (mem) | M3 SMG 1942 | wrong year |
| snipers 42:96 | M1903A4 marksman | 42 | M1903A4, 100 | M1903A4 adopted Jan 1943 (mem) | 1942 | wrong year (minor) |
| ap/at_miners, sappers 42:40-44 | engineers | 42 | 4 / 4 / 2 men with **M3** | engineers with M1/M1903 | M3 in 1942 | wrong year |
| radioman_* 42:103-105, 43:118-121 | Radioman call-ins | 42-45 | M3 + flare gun | game mechanic | M3 in 1942 | wrong year (42) |
| smgs 43:4 | Armored rifle squad | 43-45 | Sgt M1; 10 M1 (80, **1** Mk2); 1 grenadier = 12 | T/O&E 7-27 1943-44: 12 incl. driver, M1 + carbine, M1919A4 on halftrack, bazooka in vehicle, BAR added 1944 (mem) | no automatic weapon at all | wrong weapon |
| mech_armor_rifles 43:14 | (halftrack M3) | 43-45 | 7 M1, Sgt, grenadier, 1 BAR (+ a `:0` member) = 10 + vehicle | as above | close | fine |
| riflemans 43:8 | Rifle Squad | 43-45 | Sgt Thompson; 7 M1; grenadier M1+launcher (5 frag, 1 AT); BAR; BAR asst; M1 + bazooka (count form 0.25 1) = 12 | T/O 7-17 (1943/44): Sgt, asst, BAR team of 3, 7 riflemen; M1903 grenadier then M7 on M1 (1944) (sure) | Thompson for Sgt; bazooka man in place of ammo bearer (bazookas were company HQ) | count off (minor) |
| riflemans_bar 43:10 | Rifle Squad w/2x BARs | 43-45 | Sgt Thompson; 4 M1; 2 grenadier; 2 BAR; 2 asst; bazooka man = 12 | 1 BAR | 2 BARs + bazooka | count off (deliberate) |
| riflemans_assault 43:12 | Assault Rifle squad | 43-45 | Sgt Thompson; 5 M1; 3 grenadier; BAR; asst; bazooka = 12 | no TO&E type | 3 launchers | count off |
| engineers 43:16 | Combat engineer squad | 43-45 | Sgt; 2 grenadier; bazooka man (4+1); flamer; 4 sappers (satchels, mines); 3 more = 12 | engineer combat squad T/O 5-16/5-17: 12 men, M1/M1903, carbine (mem) | flamer and bazooka are pool weapons, fine for game | fine |
| specialinf 43:20 | US Marine squad | 43-45 | Sgt Thompson; 4 M1 (+dynamite); grenadier; 3 BAR; 3 asst; 1 shotgun = 13 | F-series (1944): 13 = Sgt + 3 fire teams (leader M1+launcher, BAR, asst, rifleman) (web); E-series (1943): 2 BAR (web) | 3 BAR in 1943; shotgun replaces a rifleman; Sgt Thompson (carbine usual 1944, mem) | count off (43), fine (44-45) |
| elites 43:24 (+elites_drop :25) | Airborne squad | 43-45 | Sgt Thompson; 2 M1A1 carbine; M1903A4; 3 M1; grenadier; BAR + asst; M1919A6 + asst (600) = 12 | 1944 parachute rifle squad 12: M1, carbines, 1 M1919A4 LMG, no BAR in T/O (mem) | A6 in 43; BAR | wrong year (43) |
| elites_101st 43:29 | 101st Airborne squad | 44-45 | Sgt Thompson; carbine; 2 M1; grenadier; 2 BAR + 2 asst; A6 + asst; **M18 RR** = 12 | as above | M18 in 44; 2 BAR + A6 + M18 = heavy | wrong year (44) |
| paramarines 43:34 | Paramarine squad | 43-44 | Sgt + 1 Reising; Johnson rifle; 3 M1; grenadier; 2 Johnson LMG + 2 asst; Boys = 12 | Paramarines to Feb 1944 (sure) | 44 after disbandment (minor) | fine |
| stormtroopers 43:39 | Ranger squad | 43-45 | Sgt carbine; carbine; 2 BAR + 2 asst; M9A1 bazooka; 2 M1; grenadier; 2 M1903A3 = 12 | Ranger bn 1944: assault sections ~11-12, M1, BAR, M1903 sniper, bazooka per platoon (mem) | M9A1 in 43 | wrong year (43) |
| stormtroopers_assault 43:40 | Ranger Assault squad | 43-45 | Sgt M1 carbine; **2 M2 carbine**; BAR; 5 M1; grenadier; A6 + asst = 12 | as above | M2 carbine 43-44; A6 in 43 | wrong year |
| stormtroopers_heavy 43:41 | Ranger Heavy squad | 43-45 | Sgt + 2 carbine; 2 BAR; 2 M9A1; 2 M1; grenadier; M1903A3; M1903A4 = 12 | as above | M9A1 in 43 | wrong year (43) |
| storm_mech 43:49 | (Ranger halftrack) | 43-45 | M3 halftrack + 6 springfield-named carbine men, 2 BAR asst, 2 BAR | - | - | fine |
| devils_brigade 43:45 | Devil's Brigade squad | 43-44 | as 1942 | 1st SSF Aug 1943 - Dec 1944 (sure) | - | fine |
| riflemans2 / rifle3 / smgs2 / shotguns 43:73-81 | singles | 43-45 | M1; M1 carbine; Thompson; M12 | - | - | fine |
| bazookers 43:83 | Bazooka team | 43-45 | M1A1 bazooka 7+3 | M1A1 1943-44, M9 1944 | M1A1 kept in 45 (M9/M9A1 usual) | fine (minor) |
| stormtrooper5 43:85 | Ranger Bazooka team | 43-45 | M9A1 + 2 M1 carbines | - | M9A1 in 43 | wrong year (43) |
| stormtrooper_at 43:86 | Ranger M18 team | 45 | M1903A3 + M18 (8+3+1) | M18 March 1945 (sure); Ranger use unknown | - | fine |
| mgs2 43:90 | B.A.R. team | 43-45 | BAR; asst (12 mags); rifleman = 3 | BAR team of 3 (sure) | - | fine |
| mg2 43:91 | M1919A6 MG team | 43-45 | A6 (250); asst M1 (500 belt); rifleman | LMG squad of weapons platoon used A4 1943, A6 1944-45 | A6 in 43 | wrong year (43, minor) |
| elite3 / elite6 43:94-96 | Airborne / Marine BAR team | 43-45 | BAR + asst + 1-2 M1 | Marine fire team of 4 (F-series) | - | fine |
| elite3b / elite_101st_para3b 43:102-106 | Airborne A6 MG team | 43-45 / 44-45 | A6 (250) + asst (600) + 1 | para LMG M1919A4 (A6 late 1944) | A6 in 43 | wrong year (43) |
| elite_101st_para3 43:98 | 101st BAR team | 44-45 | BAR + asst + carbine | - | - | fine |
| stormtrooper6 43:100 | Ranger BAR fire team | 43-45 | BAR + asst + **2 M2 carbine** | - | M2 43-44 | wrong year |
| paramarine3 43:104 | Paramarine Johnson LMG team | 43-44 | Johnson LMG + asst + 2 M1 | - | - | fine |
| flamers 43:110 | Flamethrower team | 43-45 | flamer + M3 | M1A1 1943, M2 1944 | M3 SMG in 43 borderline | fine |
| snipers 43:112 | M1903A4 marksman | 43-45 | M1903A4, 100 | - | - | fine |
| officers, vehic_supporter, elite_tankmans | crew / officer | 42-45 | Colt; M1 carbine; M3 | - | M3 on 1942 tankman2 | wrong year (42, minor) |

## 4. Anachronisms (by weapon; years = years the card can be bought)

| weapon | earliest real issue (HIST) | mod cards that have it earlier | file:line |
|---|---|---|---|
| Sten Mk II | late 1941/1942 (sure) | all 1941 eng Sten users; "Thompson" titled cards | eng\squads_40-41.set:5,30-38,46,50,66 |
| Sten Mk V | Feb 1944 (web) | Commando 41-43, Paras 41-43, SAS 41/43, section leaders 42-43 | 40-41:15,19,20; 42-45:4,11,12,15,19,21,25,27,63 |
| Sten Mk VI suppressed | 1944 (mem) | Commando 41-42 | 40-41:15; 42-45:19 |
| De Lisle | 1943-44, ~130 made (mem) | Commando 41-42 | 40-41:15; 42-45:19 |
| PIAT | 1943 (sure) | SAS 41; Rifle section, mech_rifles, SAS PIAT team 42 | 40-41:20; 42-45:11,15,63 |
| Boys | obsolete 1943 (sure) | AT team 44-45, SAS section 43-45 | 42-45:27,59 |
| No.77 WP | 1943 [I, unverified] | 1941 leaders | 40-41:5,9 |
| Lifebuoy flamer | 1944 (mem) | flamer team 41-43, pioneers 43 | 40-41:66; 42-45:6,79 |
| M3 grease gun | issued 1943-44 (sure) | 1942 miners, sappers, flamer2, tankman2, radiomen | usa\squads_42.set:40-105 |
| M1919A6 | first combat Sept 1943, issue 1944 (web) | mg2, Airborne 1942; Airborne/Ranger/MG teams 1943 | 42:18,75,82; 43:24,40,91,102 |
| M1903A4 | Jan 1943 (mem) | 1942 sniper, 1942 airborne | 42:18,96 |
| M9/M9A1 bazooka | M9 late 1943, M9A1 1944 (mem) | Ranger cards 1942-43 | 42:28,70; 43:39,41,85 |
| M2 carbine | Oct 1944 std, combat Apr 1945 (web) | Ranger Assault, Ranger BAR team 1943-44 | 43:40,100 |
| M18 57mm RR | March 1945 (sure) | 101st squad 1944 | 43:29 |
| M1 Garand for USMC | 1942-43 conversion (sure) | Marine squad and team 1942 | 42:14,79 |
| M7 launcher on M1 | 1943-44 (mem) | all US garand_grenade grenadiers 1943 | 43:8-45 |
| No.1 Mk III* rifle | replaced by No.4 in NW Europe 1944 (sure) | all British cards 1944-45 (wrong weapon, not year) | all eng breeds |

## 5. Ammunition and grenades off the standard issue

Standard used (HIST): US rifleman 80 rds belt (+ 1-2 bandoleers of 48 in combat), BAR 12-13 mags of 20, Thompson 5 mags of 30 (web: battleorder
"US ammo load"); British rifleman 50 rds + 2 Bren mags (sure), Sten 5-8 mags of 32 (task brief), Mk II / No.36 grenades 1-2 per man.

Matches (DATA, `breed_kit.inc`): Garand 80 (rifle_garand :340), BAR 240 = 12 mags + 1 loaded (:389), asst BAR +240, Thompson 150 = 5 (:209),
M1 carbine 90 = 6 mags, Bren gunner 224 = 8 mags, No.2 168 = 6 mags, British rifleman 50 + 56 (2 Bren mags) (rifle_em3 :354), Sten V 224 = 7 (:153),
US Mk2 2 per man, British Mills 1 per rifleman. These are fine.

Off:
- Sten Mk II 128 = 4 mags + 1 loaded (`smg_sten_mk2` :139, every Sten II user) and Commando Sten V 128 (`smg_sten_v_128`): at or under the low
  end of 5-8. count off (minor).
- Assault section leader 1941 (`mp\eng\squadleader2_40.set`): cup discharger + **25 rifle grenades and no .303**. count off; [I] probably a
  copy of a grenadier kit.
- eng_rifleman_smoke (`mp\eng\eng_rifleman_smoke.set`, kit_rifle): 60 rds, and `grenade mk1` / `sandbag_kit` / `grenade n73at` with **no count**
  (the engine default is not verified) - check if these men really get a Mills grenade.
- Armored riflemen (`usa_armor_rifle`): `grenade m61 1` - 1 grenade, half of the other US riflemen. count off (minor).
- US smoke counts `1.5 0.5`, `0.25 0.5`, British `0 1`, `0.25 1`, `0.5 1`: count forms, meaning not verified; if they are mean/spread or a chance
  [I], US riflemen get WP smoke only sometimes, which fits (M15 WP was not per-rifleman issue).
- No.73 AT grenade on most British leaders and many men 1941-45 (e.g. `eng_squadleader`, all commandos, SAS, paras): withdrawn 1941, back
  1943 for demolition (web). Probably meant as the generic AT grenade [I]. count off.
- Pioneer AP miner `eng_pioneer_ap_miner`: 31 AP mines on one man (`mine antipersonnel 31`). count off; [I] game balance (one mine layer per card).
- 101st/82nd MG assistants 600 rds of belt, MG team asst 500, Ranger MG asst 250: wide spread for the same job. [I] balance per card cost.
- Paratrooper riflemen 100 .303 + 4 Bren mags: higher than line infantry, fits airborne loads (mem). fine.
- British grenade gap: no Gammon bomb (No.82) for paras/commandos 1943-45 and no Hawkins (No.75). US paras also used Gammons (mem).
- US grenadiers: 5 frag + 1 AT + WP (count form) rifle grenades. HIST (mem): grenadier carried ~6-10 M9A1 AT grenades plus a few frag/smoke;
  the mod leans on frag. count off (minor).

## 6. Cards that match well (fine)

eng: Rifle section 1941, Canadian and Highlanders Rifle sections, Bren Gun teams, Commando Bren team, SAS Bren team, PIAT team (43-45),
2-inch mortar, SMLE rifleman (41), Sten Mk II SMG (42-45), officers.
usa: Rifle Squad 1942, Combat engineer squad, Paramarine squad and Johnson team, Devil's Brigade (43-44), mech_armor_rifles, B.A.R. team,
101st BAR team, Marine and Airborne BAR teams, Ranger M18 team (45), bazooka team (43-45), M1903A4 marksman (43-45), singles (M1, carbine,
Thompson, shotgun), Marine squad 1944-45 (F-series size and 3 BARs match).

## 7. ToE lines

DATA: `<mod>\localization\desc\mod\squad\usa\*.inc` and `...\eng\*.inc` have **no `; ToE:` line at all** (grep count 0 in squad1, squad2, v22);
only `squad\ger\*.inc` has them (56). So there is no empty line to fill. If the owner wants to add them in the ger style (`; ToE:` above the
card key), one-line texts (not written into the mod):

| card key | suggested `; ToE:` text |
|---|---|
| riflemans(usa) | US Army rifle squad, T/O 7-17 (1943-44): 12 men - SSgt, Sgt, BAR team of 3, 7 riflemen (M1; one with M7 launcher) |
| riflemans_bar(usa) | Field variant of T/O 7-17 with a second BAR (not authorized; seen late 1944-45) |
| riflemans_assault(usa) | Rifle squad reinforced with rifle grenadiers for assault (field variant of T/O 7-17) |
| smgs(usa) | Armored infantry squad, T/O&E 7-27 (1943-44): 12 men with M3 halftrack, M1 rifles, .30 LMG and bazooka in the vehicle |
| engineers(usa) | Engineer combat squad (T/O 5-16, 1943-44): 12 men, M1 rifles, demolitions, mine detectors, flamethrower and bazooka from platoon pool |
| specialinf(usa) | USMC rifle squad, F-series (May 1944): 13 men - squad leader + 3 fire teams of 4 (leader, BAR, asst BAR, rifleman) |
| elites(usa) | Parachute rifle squad, T/O 7-32 (1944): 12 men, M1 rifles and M1A1 carbines, one .30 LMG |
| elites_101st(usa) | 101st Airborne parachute rifle squad 1944-45: 12 men, M1/M1A1, one .30 LMG; extra BARs gathered in the field |
| paramarines(usa) | USMC parachute battalion squad 1942-43: Reising SMGs, Johnson rifles and Johnson LMGs |
| stormtroopers(usa) | Ranger assault section (Ranger Inf Bn T/O 7-87, 1944): ~11 men, M1, BAR, M1903 sniper |
| stormtroopers_assault(usa) | Ranger assault section with an attached .30 LMG team |
| stormtroopers_heavy(usa) | Ranger section reinforced with bazookas and a sniper from the company HQ |
| devils_brigade(usa) | 1st Special Service Force section (1943-44): M1 rifles, Johnson LMG, every man a Colt pistol |
| riflemans(eng) | British infantry section (War Establishment 1943-44): 10 men - Cpl (Sten), L/Cpl, Bren group of 3, 6 riflemen |
| riflemans_at(eng) | Rifle section with the platoon PIAT attached (PIAT from 1943) |
| smgs(eng) | Rifle section with extra Sten guns for close assault (field variant) |
| riflemans_40(eng) | British infantry section 1940-41: 10 men - Cpl, L/Cpl, Bren No.1 and No.2, 6 riflemen with No.1 Mk III rifles |
| smgs_40(eng) | Rifle section with Thompson M1928 SMGs, 1940-41 (field variant) |
| riflemans_can(eng) | Canadian infantry section: British war establishment, 10 men with Bren group |
| riflemans_scot(eng) | Highland regiment infantry section: British war establishment, 10 men with Bren group |
| pioneers(eng) | Royal Engineers field company section: NCO + sappers, rifles, Bren, mines and demolitions |
| elites(eng) | Army Commando subsection (1943-45): ~10-12 men, Thompson/Sten, rifles, Bren |
| elites_40(eng) | Army Commando subsection (1940-42): ~10-12 men, Thompsons, rifles, one Bren |
| paratroopers(eng) | Parachute Regiment section (1943-45): 10 men - Cpl (Sten), Bren group, riflemen |
| stormtroopers(eng) | SAS patrol: no fixed establishment; Bren, Sten, rifles, explosives |
| light_mortar_eng | Platoon 2-inch mortar detachment: 2 men, HE and smoke |
| at_rifles(eng) | Platoon HQ anti-tank rifle team, Boys .55 (1937-43) |
| bazookers(eng) | Platoon HQ PIAT team (1943-45): 2 men |

## 8. What I could not check

- Count forms (`0.25 1`, `1.5 0.5`, `0 1`) and items without a count: meaning not verified, I did not rely on them except where flagged.
- Exact WWII US/USMC T/O numbers beyond the battleorder.org pages; British War Establishment numbers are from memory. Marked (mem).
- Whether `member5(usa_armor_mgun:0)` (`usa\squads_43-45.set:14`) breaks anything; no game start.
- The `_drop` (paradrop) and `squad_*_vehicle` cards carry the same men as their base card; not listed one by one.

## Questions for the owner

1. "Assault section w/ Thompsons" and "Thompson SMG" (1941) carry Sten Mk II: meant to be Thompsons?
2. Should Sten Mk V be limited to 1944-45 (Commando/Para/SAS/leaders 1941-43 currently have it)?
3. Should the PIAT leave the 1942 Rifle section and SAS PIAT team?
4. US 1942 roster: keep M1919A6, M9A1, M1903A4 and grease guns, or swap to A4, M1 bazooka, M1903, Thompson?
5. 1942 "Armored rifle squad" key loads a 5-Thompson squad: rename or rebuild?
6. 1942 Marines: Springfields instead of Garands?
7. M2 carbines for Rangers 1943-44: move to 1945 or replace with M1?
8. Is the M18 on the 101st squad meant for 1945 only?
9. Add a No.4 rifle (and No.4 (T)) for 1944-45 British?
10. Is the 2-BAR US squad a firm design choice (`tings to do.txt:250-262`)?

Sources (web, this session): battleorder.org "USMC rifle company 1943" and "1944" (https://www.battleorder.org/usmc-rifle-co-1943,
https://www.battleorder.org/usmc-rifle-co-1944), battleorder.org "US ammo load WW2" (https://www.battleorder.org/post/us-ammo-load-ww2),
quartermastersection.com "M1919A6" (https://www.quartermastersection.com/american/infantry-weapons/146/M1919A6), Wikipedia "No. 73 grenade"
(https://en.wikipedia.org/wiki/No._73_grenade), unitedtaskforce.net "Sten Mk V" (https://unitedtaskforce.net/operations/quartermaster/LIB_Sten_Mk5),
Shooting Illustrated "The M2 Carbine" (https://www.shootingillustrated.com/articles/2020/11/1/the-m2-carbine).
