# RobZ Realism 1.31.0: Soviet infantry (rus, rus_guard) against historical TO&E

Read-only job: nothing in the mod was changed. Mod root `E:\RobZ Realism\robz realism mod 1.31.0` (= `<mod>`).
Inputs: `E:\arsenal-tmp\robz-toe\cards.tsv`, `breeds.tsv`, breed files `<mod>\resource\set\breed\mp\<side>\*.set`,
card files `<mod>\resource\set\multiplayer\units\...`, `<mod>\tings to do.txt`.

Short names used below:
- R41 = `units\rus\squads_41-42.set`, R43 = `units\rus\squads_43-45.set`, G43 = `units\rus_guard\squads_43-45.set` (all under `<mod>\resource\set\multiplayer\`).
- Tags: [D] = the mod's data shows it (certain). [I] = inferred. [H] = history fact, with source type and confidence.

## 0. How the offered years work (read first)

- [D] Year sets: `units\units_41.set:18` and `units_42.set:21` include R41. `units_43.set:21,23`, `units_44-45.set:29,31`, `units_45.set:23,25` include R43 and G43. There is no units_39/40 file.
- [I] So a card is offered only in the years of the units file that loads it, further limited by its tags. A tag of 39, 40 or 42 on an R43/G43 card, or 43-45 on an R41 card, does nothing. "Eff." in the tables is that intersection. I did not check this in game: [T].
- [D] R41 and R43 use the same card names (riflemans2, rifle_sa, smgs2, at_rifles, bazookers, elite3, flamers, snipers, snipers3, officers, radioman_mortar, ap_miners, at_miners, sappers, tankmans, elite_tankmans) with **different breeds**. cards.tsv keeps only one row per name: it shows the R43 breeds with the R41 tags (e.g. `riflemans2(rus)` = rus_rifle, tags 39-45). I used the units files for both versions.
- [D] Also not in cards.tsv: R43 `smgs_mot` :14, `riflemans_rifle_mot` :33, `shock_assault_mech` :39, `paras_drop` :52, `ap_miners` :56, `at_miners` :58, `sappers` :60, `tankmans` :66. The paras row in cards.tsv has a stray soldier `3607`: a parse artifact of `c(360)` at R43:51. The real squad is 11 men.

## 1. Ammunition and grenade key (from `breed\breed_kit.inc`, `stuff\smg|mgun|rifle`)

[D] A kit is the loaded weapon plus the spare rounds in the breed. Counts are rounds.
| kit | weapon (stuff file, capacity) | total carried |
|---|---|---|
| rifle_mosin / rifle_mosin_vet | Mosin 91/30 (`stuff\rifle\mosin`, 5) | 5 + 60 = **65** |
| kit_rifle 30 / 40 (partisan, militia) | Mosin | 35 / 45 |
| rifle_svt40 | SVT-40 (`stuff\rifle\svt40`, 10) | 10 + 20 SVT + 60 `mosin_clip` = 90 if the SVT can load the clip ammo [I, not checked] |
| smg_ppsh | PPSh-41 drum (`stuff\smg\ppsh`, 71) | 71 + 142 = **213 = 3 drums** |
| smg_ppsh_213 | PPSh-41 drum | 284 = 4 drums |
| kit_smg 71 (partisan) | PPSh-41 drum | 142 = 2 drums |
| smg_ppsh41 | PPSh-41 box (`stuff\smg\ppsh41`, 35) | 35 + 105 = 140 = 4 boxes |
| smg_ppsh41_210 | PPSh-41 box | 245 = 7 boxes |
| smg_pps43 / smg_pps43_105 | PPS-43 (`stuff\smg\pps43`, 35) | 245 = 7 mags / 140 = 4 mags |
| dp gunner / assistant / each rifleman | DP-27 (`stuff\mgun\dp`, 47) | 282 = 6 pans / 141 = 3 pans / 47 = 1 pan |
| dt gunner / assistant / rifleman | DT (`stuff\mgun\dt`, 60) | 300 = 5 discs / 240 or 180 / 60 |

- [D] Grenades: the only frag grenade any Soviet breed carries is the F-1. Others carried: RPG-40, RPG-43, an RG-42 x3 AT bundle (`rg42x3`), molotov, smoke, satchel. The mod's `stuff\grenade` folder has no RGD-33 and no single RG-42 or RPG-6 (`stuff\grenade\01 grenade_ap`, `02 grenade_at`).
- [D] Count forms `0 1` (molotov, rpg40, rpg43) and `1.5 0.5` (F-1) are used widely. Their meaning is not verified. I read `0 1` as "0 or 1, random" and `1.5 0.5` as "1 or 2" [I].

## 2. Historical baseline used

The confidence of each item is given in its line.
- [H] Rifle division shtat 04/400 (5 Apr 1941). The squad was 11 men: commander, DP-27 crew of 2, riflemen, with the SVT-40 meant to replace much of the Mosin. Source: reference works on Red Army organisation, from memory, not verified. The exact SMG count per squad is uncertain (few or none at squad level).
- [H] Reduced shtats 04/600 (Jul 1941) and 04/750 (Dec 1941) kept a squad of about 11 on paper, with fewer SVTs and fewer automatic weapons. From memory, not verified.
- [H] Shtat 04/550 (Dec 1942): **9-man squads**. Source: battleorder.org "USSR Rifle Company 1943" (web, checked). PPSh-41 for the leader, one DP-27 crew, the rest Mosin: from the brief and memory, not verified.
- [H] Early 1944: one rifle platoon per company became an SMG platoon. Source: battleorder.org "USSR Rifle Company 1944" (web, checked).
- [H] Adoption dates, from memory, fairly sure: SVT-40 Apr 1940; PTRD and PTRS Aug 1941 (PTRS in quantity in 1942); PPSh-41 mass production late 1941; its 35-round box magazine from 1942; PPS-43 1943 (PPS-42 at Leningrad in 1942); SG-43 May 1943; RPG-43 spring 1943 (at Kursk); RPG-6 late 1943; RG-42 1942; SN-42 body armour adopted 1942 and issued to the ShISBr assault engineer brigades from May 1943; PU sniper scope 1942 (PE before that).
- [H] Lend-lease to the USSR, from memory, unverified: a few thousand M1/M1A1 bazookas from 1943 that saw little front use; about 1,000 PIATs in 1944.
- [H] Panzerfaust 30 (klein) first issued Aug 1943. From memory, fairly sure.
- [H] Standard issue per man, from memory, unverified. Rifleman about 100-120 rounds. PPSh: 2 drums, or 6 boxes of 35 later. PPS-43: 6 magazines. Rifleman: 2 hand grenades (RGD-33 in 1941-42, F-1, RG-42 from 1942-43).

## 3. Per-card table

Severity: wrong year / wrong weapon / count off / fine. Ranked inside each group: most likely mistakes first.

### 3a. rus, 1941-42 cards (R41, loaded only in units_41 and units_42)
| card (R41 line) | title | eff. years | mod squad [D] | historical [H] | differences | severity |
|---|---|---|---|---|---|---|
| conscripts :7 | Reservists | 41 42 | 10: 6 Mosin (45 rds, molotov 0-1), 4 PPSh drum (213). No grenades, no LMG | Opolchenie or reservist squad: rifles (many old or foreign), no SMG, maybe 1 LMG | 40% PPSh in 1941 militia; no frag grenades | wrong weapon |
| home_guards_41 :5 | Partisan 1941 | 41 | 10: 5 Mosin (35), 2 PPSh drum (142), 2 MP38 (128), 1 captured MG34 drum | 1941 partisans: rifles, very few SMGs, captured arms only from late 1941 | 2 PPSh in 1941 and 4 SMGs + MG34 in 1941 are high | wrong year |
| riflemans_41 :14 | Rifle squad 1941 | 41 | 11: SL Mosin (RPG-40, smoke), 6 Mosin, 2 PPSh drum, DP + asst Mosin | 04/400: 11, DP crew, many SVT-40, SMG few | no SVT at all; 2 PPSh-41 (PPD-40 fits 1941; `stuff\smg\ppd40` exists); RGD-33 missing | wrong weapon |
| elite_tankmans :54 | Veteran tank crew | 41 42 | 5: vet_tankman2 + 4 vet_tankman, PPSh **box** (140-245), F-1 x2 | crew sidearms TT/Nagant, PPSh drum in tank | box magazine in 1941 | wrong year |
| tankmans :52 | Tank crew | 41 42 | 5: tankman2_41 PPSh box (140), 4 Nagant | as above | box magazine in 1941 | wrong year |
| ap_miners :42 / at_miners :44 / sappers :46 | Miners / Sappers | 41 42 | 4 or 2 men, PPSh box (140), mines, mine detector, dynamite | sapper: rifles in 1941, PPSh from 1942 | PPSh box in 1941 | wrong year |
| smg3 :19 | Shock Troops | 42 | 8: 7 PPSh box (245), 1 flamethrower (80 fuel), all with **SN-42 body armour** (`breed\mp\rus\smg3.set` `{body body_armor}`) | ShISBr assault engineer squads with SN-42: from May 1943 | 1942 is early for SN-42 shock troops | wrong year |
| bazookers :70 | Bazooka team | 42 | M1 bazooka + PPSh asst, 7+3 rockets | no bazookas in Soviet service in 1942 | lend-lease weapon a year early | wrong year |
| riflemans_42 :15 | Rifle squad 1942 | 42 | 9: SL Mosin, 3 Mosin, 3 PPSh drum, DP + asst | 1942: 9-11 men, DP crew, PPSh for the leader (04/550 from Dec 1942) | leader has a rifle, while 3 riflemen have the PPSh; no SVT | count off |
| home_guards_42 :6 | Partisan 1942 | 42 | 9: 3 Mosin, 3 PPSh drum, 2 MP38, 1 MG34 | 1942 partisans: rifles, more SMGs, captured MG | plausible | fine |
| elites_40 :23 | Marine squad 1940 | 41 | 11: 6 Mosin, 3 SVT, DP (6 pans) + asst; F-1 x2, RPG-40 | naval infantry 1941: Mosin + many SVT, DP | fits; title says 1940 but the card is offered only in 41 | fine |
| elites_42 :24 | Marine squad 1942 | 42 | 9: 4 Mosin, 3 SVT, DP + asst; F-1 x2, RG-42 bundle | 1942 naval rifle squad 9-11 | fits | fine |
| elite3_40 :79 / elite3 :80 | Marine DP-27 MG team | 41 / 42 | DP + 2 Mosin | DP crew 2-3 | fits | fine |
| riflemans2 :60 | Mosin Rifleman | 41 42 | rifle_41: Mosin 65, 1 DP pan, F-1 1, molotov 0-1 | rifleman | ammo low (see section 5) | count off |
| rifle_sa :62 | SVT-40 Rifleman | 41 42 | SVT | SVT-40 common in 1941 | fits | fine |
| smgs2 :64 | PPSh-41 SMG | 41 42 | PPSh drum 213 | PPSh from late 1941 | fits in late 1941 | fine |
| at_rifles :68 | PTRD AT-Rifle team | 41 42 | PTRD 26 rds; asst PPSh drum, 10 PTR rds, F-1 x2, RPG-40 | PTRD crew of 2, assistant with a rifle | asst with PPSh is generous [I balance] | fine |
| mgs2_41 :76 | DP-27 Machine Gun team | 41 42 | **1 man**: DP 6 pans | DP crew of 2 | one man on a card named "team" | count off |
| flamers :94 | Flamethrower team | 41 42 | ROKS + asst PPSh 284 | ROKS-2 operator; flamethrower companies | fits | fine |
| snipers :96 / snipers3 :97 | Sniper teams | 41 42 | 2 Mosin snipers 125 rds / 2 SVT snipers | Mosin PE/PU, SVT-40 sniper | fits | fine |
| officers :99, radioman_mortar :103 | Officer / Radioman | 41 42 | TT + binoculars / PPSh drum + flare | | fits | fine |

### 3b. rus, 1943-45 cards (R43, loaded in units_43, units_44-45 and units_45)
| card (R43 line) | title | eff. years | mod squad [D] | historical [H] | differences | severity |
|---|---|---|---|---|---|---|
| paras :51 (+ paras_drop :52) | Paratrooper squad | 44 45 | 11: SL PPS-43 (140), 2 PPS-43 (140), 2 SVT, 2 Mosin, **2 DT** (5 discs) + 2 asst; F-1 x2, RPG-43, smoke | 1944-45 Guards airborne divisions fought as rifle divisions: 9-man squads, DP-27 | DT instead of DP; 2 LMGs; 11 men | wrong weapon |
| home_guards :4 | Partisan Regular squad | 43 44 45 | 11: 3 Mosin (35), 4 PPSh drum (142), 2 MP38, 1 AT man with Kar98k (35) + **Panzerfaust 30**, 1 MG34 | captured Pzf only from late 1943 | Pzf in 1943 early (fine 44-45); partisan rifle ammo 35 | wrong year (43 only) |
| bazookers :87 | Bazooka team | 43 44 45 | bazooka 10 rockets + PPSh asst 4 rockets | a few thousand lend-lease bazookas, little use | plausible but rare | fine (rare) |
| riflemans :20 (+v2-v5 :21-24) | Rifle squad | 43 44 45 | 11: SL **PPS-43** (245, F-1 x2, RPG-40, smoke), 3 PPSh drum, 2 SVT, 3 Mosin, DP + asst | 04/550: 9 men, PPSh leader, DP, Mosin | 11 vs 9; PPS-43 for a line squad leader (mostly PPSh); matches owner note `tings to do.txt:415` "4smg,2auto,4mosin" | count off (deliberate [I]) |
| riflemans_rifle :27 (+v2-v5, _mot :33) | Assault Rifle squad | 43 44 45 | 11: SL PPS-43, 1 PPSh, 1 SVT, 6 Mosin, DP + asst | same as above | closest to the 04/550 mix, but 11 men; "Assault" title for the most rifle-heavy squad | count off |
| smgs :8 (+v2-v5, _mot :14) | SMG Squad | 43 44 45 | 10: SL PPS-43, 1 PPS-43, 8 PPSh drum; F-1 1-2, molotov/RPG-40 0-1 | SMG company squad, tank riders: all PPSh | fits | fine |
| shock_assault :37 (+_mech :39) | Shock assault squad | 43 44 45 | 9: SL PPSh drum, 3 PPSh box (245), 2 PPSh drum, 2 PPS-43, 1 ROKS; SN-42 armour; F-1 x2, RPG-40, molotov, smoke | ShISBr assault squad, SN-42, SMG-heavy, ROKS from attached flame units | fits 1943+ | fine |
| shock :41 | Shock rifle squad | 43 44 45 | 9: SL Mosin, 2 PPSh, 2 SVT, 2 Mosin, DP + asst; SN-42 | ShISBr mostly SMG | rifle-heavy for an armoured shock squad | fine |
| elites :45 | Marine squad | 43 44 45 | 11: 6 Mosin, 3 SVT, DP + asst; RG-42 bundle | naval rifle brigade, 9-man squads from 1943, more PPSh | no SMG in a 1943-45 marine squad | count off |
| bsf_marines :47 | BSF Marine squad | 43 44 45 | 11: 4 Mosin, 3 SVT, 2 DP + 2 asst | Black Sea Fleet naval infantry | 2 DP plausible, no SMG | fine |
| sapper_squad :16 | Sapper squad | 43 44 45 | 9: SL PPS-43, 1 PPS-43, 2 PPSh, 5 Mosin; mines, satchels, detector, sandbags; no body armour | sapper squad, mostly rifles | fits; not ShISBr, so no SN-42 is right | fine |
| ap_miners :56 / at_miners :58 / sappers :60 | Miners / Sappers | 43 44 45 | PPSh box, mines | | fits | fine |
| mgs2 :91 | DP-27 Machine Gun team | 43 44 45 | DP (6 pans) + asst Mosin (3 pans) | DP crew 2 | fits | fine |
| elite3 :95 | Marine DP-27 MG team | 43 44 45 | DP + 2 Mosin | | fits | fine |
| at_rifles :84 / at_riflesv2 :85 | PTRD AT-Rifle team | 43 44 45 | PTRD 26 rds + asst PPSh drum, 10 rds | | asst PPSh [I balance] | fine |
| riflemans2 :76 / rifle_sa :78 / smgs2 :80 | single men | 43 44 45 | Mosin / SVT / PPSh drum | | | fine |
| flamers :99 / snipers :101 / snipers3 :102 | | 43 44 45 | ROKS + asst / Mosin PU 125 / SVT sniper | SVT sniper production ended 1942, still in use | | fine |
| tankmans :66 / elite_tankmans :68 / officers, radioman | | 43 44 45 | PPSh box / Nagant / TT | | | fine |

### 3c. rus_guard (G43, loaded in units_43, units_44-45 and units_45)
| card (G43 line) | title | eff. years | mod squad [D] | historical [H] | differences | severity |
|---|---|---|---|---|---|---|
| bazookers :69 | **PIAT team** | 43 44 45 | guard_bazooker: `weapon bazooka` + 7 bazooka rockets (`breed\mp\rus_guard\guard_bazooker.set:19,22`), asst PPSh + 3 | | title says PIAT, weapon is a bazooka | wrong weapon (label) |
| bazookers_piat :70 | Guards PIAT infantry | 43 44 45 | PIAT + 7, asst 3 | PIATs reached the USSR in 1944 | 1943 early | wrong year (43) |
| elite_guards_shock :32 | Elite Guards shock rifle squad | 43 44 45 | 11: SL SVT, 2 PPS-43, 2 SVT, 2 Mosin, DT + asst, **captured MG34** (300 per man) + asst; SN-42; RPG-43 | ShISBr, DP | DT and MG34 instead of DP; plausible for elite or captured weapons [I] | wrong weapon (mild) |
| elite_guards :26 | Elite Guards rifle squad | 44 45 | 10: SL PPSh box 245, 3 PPS-43, 2 SVT, **DT** + asst, 3 Mosin; RPG-43 0.25-1 | Guards rifle squad: DP (2 per brief) | DT instead of DP; 1 LMG | wrong weapon |
| specialinf_rifle :12 | Guards Rifle squad | 44 45 | 11: SL PPSh box, 1 PPS-43, 2 SVT, DP + asst, 5 Mosin | Guards squad 9, 2 DP (brief; unverified) | 1 DP; owner note `tings to do.txt:415` says 3 PPS-43 + 4 Mosin; data has 1 PPS-43 + 5 Mosin (+ asst) | count off |
| specialinf_smg :10 | Guards SMG squad | 43 44 45 | 10: SL PPSh box 245, 6 PPSh box, 3 PPS-43; F-1 x2 | SMG squad all SMG | owner note `tings to do.txt:416` "5 PPSh41 + ldr, 5 PPS-43" (11); data 1+6+3 = 10 | count off (vs owner note) |
| specialinf :14 | Guards Assault Rifle squad | 44 45 | 11: SL PPSh box, 1 PPSh box, 2 PPS-43, 3 SVT, DP + asst, 2 Mosin | | 3 SVT of 11 is high for 1944-45 | count off (mild) |
| guards_shock_assault :18 | Guards shock SMG squad | 43 44 45 | 11: SL PPS-43, 4 PPSh drum 284, 5 PPS-43, ROKS; SN-42 | ShISBr | fits | fine |
| guards_shock :20 | Guards shock rifle squad | 43 44 45 | 11: SL SVT, 2 PPS-43, 2 SVT, 2 Mosin, 2 DP + 2 asst; SN-42 | | fits | fine |
| elite_guards_smg :24 / elite_guards_shock_assault :30 | Elite SMG squads | 43 44 45 | 10-11, PPSh box/drum + PPS-43, RPG-43, SN-42 on the shock one | | fits | fine |
| recons :4 | Recon Squad | 43 44 45 | 6: SL PPS-43 (140), 1 PPS-43, 3 PPSh drum, 1 Mosin; F-1 1, no knife or kit | razvedchiki: SMG-heavy, knives, more grenades | matches owner note `tings to do.txt:278`; ammo light (PPS 4 mags) | fine |
| sapper_squad :6 | Guards Sapper squad | 43 44 45 | 8: SL PPS-43, 1 PPS-43, 1 PPSh, 5 Mosin; mines, satchels | | fits | fine |
| smg2 :63 | Guards PPS-43 SMG | 43 44 45 | PPS-43 245 | | tags 41 42 are inert | fine (tag noise) |
| at_rifles :67 | Guards PTRS AT-rifle | 43 44 45 | PTRS 40 rds + asst PPSh, RPG-43 | | tags 41 42 inert | fine |
| mgs2, riflemans2, rifle_sa, smg, snipers, snipers3, officers, ap/at_miners, tankmans | | 43 44 45 | DP crew / Mosin / SVT / PPSh box / Mosin PU, SVT-S / TT / PPS-43 crew | | | fine |

## 4. Anachronisms

Most likely mistakes first.
1. [D] R41 `bazookers` :70 offers an M1 bazooka in **1942** (tag 42, units_42). [H] There were none in Soviet service then. Wrong year.
2. [D] R41 `smg3` :19 "Shock Troops", 1942: SN-42 armour (`smg3.set`, `flamer3.set` `{body body_armor}`) + PPSh box. [H] ShISBr with SN-42 from May 1943. Early.
3. [D] PPSh-41 **box** magazine in 1941 (`ppsh41`, 35 rds): R41 `tankmans` :52 (tankman2_41), `elite_tankmans` :54 (vet_tankman x4, vet_tankman2), `ap_miners` :42, `at_miners` :44, `sappers` :46 (saper). [H] Box magazine from 1942. Early in 41; fine in 42.
4. [D] PPSh-41 (drum) in mass in 1941: `conscripts` :7 (4 of 10), `riflemans_41` :14 (2), `home_guards_41` :5 (2). [H] Scarce before 1942. `stuff\smg\ppd40` exists in the mod and fits 1941. The tank and single-SMG cards for late 1941 are fine.
5. [D] R43 `home_guards` :4 offers a Panzerfaust 30 to partisans in **1943**. [H] Issued Aug 1943, captures later. Early only for 43.
6. [D] G43 `bazookers_piat` :70 PIAT in **1943**. [H] PIATs reached the USSR in 1944. Early only for 43.
7. [D] Tag noise with no effect [I]: G43 `smg2` "Guards PPS-43 SMG" :63 (tags 41 42), G43 shock squads with PPS-43/RPG-43 (tags 42), G43 `at_rifles` with RPG-43 (41 42), R43 shock squads (42). These files load only in 43+, so nothing is offered early. The tags mislead anyone who reads them, and they would fire if the files were ever included in units_41/42.
8. Checked and not found: PPS-43, SG-43, RPG-6 and RPG-43 before 1943. No Soviet breed carries SG-43, RPG-6, Maxim or DShK as infantry. [D] SG-43, RPG-6, RGD-33 and single RG-42 do not exist in `stuff\`. The Maxim 1910/30 and DShK exist only as crewed entity cards (cards.tsv `maxim_1910_30` 41-43, `dshk_zenit`).
9. [D] SVT share after 1942: rifle squads 2 of 11 (`riflemans`), Guards assault 3 of 11 (`specialinf`), paras 2 of 11, marines 3 of 11. [H] Production fell from 1942 but the SVT stayed in use, more with naval infantry. Mildly high for 1944-45; probably deliberate [I].

## 5. Ammunition and grenades off the standard issue

[D] counts are from section 1. [H] Standards are from memory, unverified.
- **Riflemen are short**: every Mosin breed has 65 rds (`rifle_mosin` macro): rus_rifle, rifle_41, guard_rifle, marines, mg assistants. Partisans have 35, militia 45. Against about 100-120 issue that is roughly half. [I] Possibly offset by the DP pan (47) every rifleman carries for the squad gun, or meant to force resupply from crates (`ammo_box_rus_inf`).
- **DP ammo is high**: in the rifle squad (`riflemans`) the gunner has 6 pans and the assistant 3. Five riflemen with 1 pan each make **14 pans (658 rds)** per DP. [H] A squad DP had roughly 4-12 pans at squad level (low confidence). [I] Balance or sustained-fire intent.
- **PPSh drum**: 3 drums (213) on most PPSh men, 4 drums (284) on flamer assistants and Guards shock SMG men. [H] Standard 2 drums. +1 or +2.
- **PPSh box**: `smg_ppsh41` gives 4 boxes (140), short of the 6 standard. `smg_ppsh41_210` gives 7 (245), one over. Breeds with 4: miners, sappers, tank crews. Breeds with 7: rus_shock_smg, smg3, guard_sl, guard_smg, guard_elite_guard_*.
- **PPS-43**: 7 mags (245) on most breeds, +1 over 6. Recon and paras have 4 (140), -2.
- **Grenades**: rifleman `rus_rifle` has 1 F-1 + molotov 0-1. SMG men have F-1 "1.5 0.5" + molotov 0-1 + RPG-40 0-1. [H] Standard 2 per man. Line riflemen get about half; Guards, shock, marine and para men get 2 F-1, which fits. No RGD-33 exists, so the 1941-42 squads show only F-1. [H] The RGD-33 was the main frag grenade in 1941. Wrong weapon type for 41-42, forced by the missing item.
- **Smoke grenades** on leaders, AT and bazooka assistants, shock men. [H] Soviet hand smoke was rare at squad level. [I] Balance.
- **PTRD 26 rds + 10 on the assistant**: PTRS 40 + 10. [H] Crew load about 40-50+, low confidence.
- **Snipers**: Mosin 125 rds, SVT 30 + 100 clip. Generous but plausible.

## 6. Cards that match well
R41 `home_guards_42`, `elites_40` (title year aside), `elites_42`, `elite3_40`/`elite3`, `rifle_sa`, `smgs2`, `at_rifles`, `flamers`, `snipers`, `snipers3`, `officers`, `radioman_mortar`.
R43 `smgs` (+v2-v5, _mot), `shock_assault`, `shock`, `bsf_marines`, `sapper_squad`, miners/sappers, `mgs2`, `elite3`, `at_rifles`, singles, `flamers`, `snipers`, crews.
G43 `guards_shock_assault`, `guards_shock`, `elite_guards_smg`, `elite_guards_shock_assault`, `recons`, `sapper_squad`, `smg2`, `at_rifles`, `mgs2`, singles, snipers, officers, crews.

## 7. Suggested text for the empty `; ToE:` lines

[D] File `<mod>\localization\desc\mod\squad\rus\squad1.inc`; rus_guard has none. Not written into the mod. Years and shtats are from memory, unverified.
| card (line of `; ToE:`) | suggested line |
|---|---|
| home_guards_41 (:58) | `; ToE: partisan detachment 1941, no fixed shtat: Mosin rifles, very few SMGs (PPD), captured MP 38/40 and MG 34 from late 1941; F-1/RGD-33 and molotovs` |
| home_guards_42 (:61) | `; ToE: partisan group 1942 (supplied by TsShPD from May 1942): Mosin rifles, rising share of PPSh-41 and captured MP 40, one DP-27 or captured MG 34` |
| riflemans_41 (:68) | `; ToE: rifle squad, shtat 04/400 (Apr 1941): 11 men: commander, DP-27 crew of 2, 8 riflemen with Mosin 91/30 and SVT-40, SMGs (PPD-40) rare` |
| riflemans_42 (:71) | `; ToE: rifle squad 1942 (04/750 then 04/550, Dec 1942): 9-11 men: commander (PPSh-41 from late 1942), DP-27 crew of 2, Mosin riflemen, 1-2 PPSh-41` |
| elites_40 (:77) | `; ToE: naval infantry rifle squad 1941 (sailors sent ashore): about 11 men, Mosin 91/30 and many SVT-40, one DP-27, F-1 and RPG-40` |
| elites_42 (:80) | `; ToE: naval rifle brigade squad 1942: 9-11 men, Mosin and SVT-40, one DP-27, some PPSh-41; F-1, RG-42, RPG-40` |

## 8. Not checked
- Whether tags further filter cards inside a units file (how 44 differs from 45) and whether duplicate card names across R41 and R43 collide: [T] in game.
- Whether the SVT can load `ammo mosin_clip`, and what the `0 1` and `1.5 0.5` count forms do.
- The exact 04/400 squad table and Guards squad DP count: only secondary web sources were found. Sources: battleorder.org "USSR Rifle Company 1943" and "USSR Rifle Company 1944"; operationbarbarossa.net "Sov FILARM TOE R Units" (PDF, not opened).
- Entity (vehicle crew) cards: crews only, not reviewed beyond weapon year.

## Questions for the owner
1. Are the 39/40/42 tags on R43/G43 cards (and 43-45 on R41) meant to do anything? Should they be trimmed?
2. G43 `bazookers` "PIAT team" carries a bazooka: is the title or the weapon wrong?
3. Is the 11-man 1943-45 rifle squad deliberate over the 9-man 04/550?
4. Guards SMG and Guards rifle squads differ from your note at `tings to do.txt:415-416`: which is current?
5. Is 65 rounds per rifleman a balance choice?
6. Swap the 1941 PPSh (conscripts, riflemans_41, partisans 41) for the PPD-40 you already have?
7. Add SVT-40s to `riflemans_41`?
8. Is the 1942 bazooka card (R41 :70) intended?
9. Should `smg3` Shock Troops (SN-42) start in 1943 rather than 1942?
10. DT on paras and elite Guards instead of DP: deliberate (60-round pan)?
