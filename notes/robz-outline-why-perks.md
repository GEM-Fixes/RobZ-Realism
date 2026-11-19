# RobZ Realism 1.31.0: why the perk rows are out of line (tiers + vet)

Read-only study of the `tiers` (329) and `vet` (21) rows of `plan/reports/robz-breed-outline.tsv`.
Nothing in the mod, the game or the repo was changed. Scratch work: `E:\arsenal-tmp\robz-toe\perks\` (an.js, classify.js, ladder.js, cards.js).

Mod root below = `E:\RobZ Realism\robz realism mod 1.31.0\resource\set\`.
Breed sets: `breed/mp/<side>/<breed>.set`. Line numbers in the tables are the set line from the outline tsv.

Inputs:
- tier macro table: `breed/breed_tiers.inc` lines 9-156 (comment table, name + values + user count)
- veterancy tables: `breed/mp/robz_vet.inc`, `breed/mp/<side>/veterancy_generic.inc`
- breed and card extract: `E:\arsenal-tmp\robz-toe\breeds.tsv` (1,189 rows), `cards.tsv`
- weapon class = the `stuff/<dir>` the weapon file sits in (rifle, smg, mgun, pistol, bazooka...)
- owner notes: `E:\RobZ Realism\...\tings to do.txt` (cited by line)

Tags: [D] data shows it. [I] inference. History = from memory, unverified, no source document.

## How to read this

- Each `tiers` row got ONE primary class. A row can fit more than one; the first rule that matched wins.
  Order: text-only, manual verdict (M1-M3), no card (L), crew (C1/C2), hero/officer (H), role (R1), leader (R2), other ladder (R3).
- The main cause behind almost all rows [D]: a tier macro exists only when 4+ breeds share a set (`breed_tiers.inc` header).
  Squads build their own small ladders (base + role bump + leader bump). Those sets have 1-3 users, so they keep the explicit call.
  So "out of line" mostly means "a squad's own ladder", not "wrong".
- Squad design seen in the data [D]:
  - one base vector per squad
  - +1/+2 on the skill of the weapon the man carries (rifle, smg, mgun, rocket)
  - MG assistants mirror the gunner's mgun level
  - leader and 2IC get higher pistol/smg
  - BAR men get mgun +1 (`stuff/rifle/bar_rifle`, tag assaultrifle)
  - light mortar men use rifle skill (tier skills_4_3_2_5_2_4)
  - tank commander gets mgun +1 over his crew
- The owner's notes set squad skill by name [D] (`tings to do.txt` 724-774).
  - Examples: SS-VT skill 2, SS Grenadiers skill 5, Totenkopf skill 6, LSSAH skill 7, Fusilier/Jaeger skill 5, GD skill 6.
  - The ladders match these notes. That makes R1/R2/R3 deliberate.

## Summary

| class | meaning | count | confidence it is a mistake | confidence in the reason |
|---|---|---|---|---|
| M1 | likely mistake: skill vs weapon or sibling clearly off | 3 | high | high |
| M2 | likely mistake: sibling / squad mates differ with no reason found | 11 | medium | medium |
| M3 | inconsistency inside one squad or one family | 18 | low | medium |
| VET-A | vet start-rank table arithmetic off its base | 5 tables (13 rows) | high (start2/3), medium (ss) | high |
| VET-L | literal vet block 2/5/9/14/20 (12x fast) | 2 breeds | medium-high | medium |
| L | leftover: no card uses the breed | 75 | none in game (unused) | high [D] |
| C1 | crew skills: commander mgun +1, side crew sets | 30 | low | high |
| C2 | crew drive: per-side crew ladder | 7 | low | medium |
| H | hero / officer / radioman special body or skills | 24 | low | high |
| R2 | squad leader / 2IC bump | 39 | very low | high |
| R1 | role specialization: raised skill = carried weapon | 64 | very low | high [D] |
| R3 | squad ladder variant, under the 4-user threshold | 54 | low | medium [I] |
| T | text-only difference ("mp_sniper" vs mp_sniper, 1 vs 1.0) | 4 | none | certain |
| VET-O | vet_standard_old: mp block differs from outer, table unused | 1 row |  none (unused) | high |
| VET-N | elite/crew name on a table that does not fit the name (outline flag) | 5 rows, 34 breeds | mostly false positive | medium |

Tested explanations, with the result:
- role specialization: the largest real cause. In R1 the raised skill is in the carried weapon's skill set for all 64 rows [D].
- side-wide convention: crew commander mgun +1 (all sides) [D]. rus_guard crews on body_regular with high pistol/smg [D]. eng crew cannon 0.8 (side-only, see M2).
- year variant: the 1941/1944 copies (`_41`, `_44`, ssvt vs ss_ssvt) mostly equal their twin. Differences are listed in M3 [D].
- quality variant: the elite/vet names mostly sit on the right body/skills. Exceptions are in VET-N and the ladder section.
- copy-paste drift: the 3 M1 rows and most M2 rows look like a line copied from a sibling with a different weapon [I].
- text only: 4 rows [D].
- leftover: 75 rows; no card in `units/*` uses the breed [D].
- in-squad inconsistency: M3 plus the card list below.

## Per class (mistakes first)


### M1: Likely mistake, high confidence (3)

| side/breed | set line | kind | value | nearest tier | why |
|---|---|---|---|---|---|
| axis_minor/axm_fin_sissi_mgun_vision | 14 | skills | 1_1_7_3_1_2 | skills_2_1_1_3_1_2 | hero copy of axm_fin_sissi_mgun (157612) has 117312: smg 1 vs 5, rifle 3 vs 6, same LS-26 + Luger. Every other *_vision copy has the same skills as its plain breed |
| ger_ss/ss_pzgren_sl_stg | 15 | skills | 4_5_4_3_5_4 | skills_ger_ss_4_5_3_3_4_4 | rocket 5 but carries no rocket weapon (StG, AT grenade bundle only); twin ss_pzgren_stg has rocket 4. Copy of a Panzerfaust line |
| ger/ger_pzgren_smg_panzerfaust | 15 | skills | 5_4_4_5_5_5 | skills_ger_5_4_4_5_4_5 | carries MP40 (smg) but has smg 4 rifle 5, the rifleman pattern; its StG twin ger_pzgren_stg_panzerfaust has smg 5 rifle 4. Copy of a rifle+Panzerfaust line |

### M2: Likely mistake, medium confidence (11)

| side/breed | set line | kind | value | nearest tier | why |
|---|---|---|---|---|---|
| eng/tankman | 13 | drive | tank 1 vs 0.75 | drive_regular | British crew tank 1 vehicle 1 cannon 0.8; eng_tankman_single / eng_tankman2_single (single-crew cards) have cannon 1.0 (drive_t1_v1_c1); every other side's crew has cannon >= 0.9 |
| eng/tankman2 | 13 | drive | tank 1 vs 0.75 | drive_regular | commander on the same drive as the crew (cannon 0.8); other sides give the commander more |
| eng/vet_tankman | 13 | drive | tank 1 vs 0.75 | drive_regular | named vet but plain crew drive (tank 1 vehicle 1 cannon 0.8) and the skills of tankman2; owner note "vet tank crew is now only commander" (tings to do.txt:152) explains the drop, the name is a leftover |
| ger/ger_volksgren_sa | 14 | skills | 1_1_1_2_1_2 | skills_rus_militia | G43 + panzerfaust_60 "0 1", rocket 1; the squad rifle tier skills_1_1_1_2_2_2 has rocket 2 |
| ger/ger_volksgren_smg | 14 | skills | 1_2_1_1_1_2 | skills_2_2_1_1_1_2 | carries panzerfaust_30 "0 1" but rocket 1 (see ger_volksgren_stg44) |
| ger/ger_volksgren_stg44 | 14 | skills | 1_2_1_1_1_2 | skills_2_2_1_1_1_2 | carries panzerfaust_60 "0 1" but rocket 1; ger_volksgren_pzfst2 (same StG, panzerfaust "0 1") has rocket 2, ger_volksgren_pzfst rocket 2 |
| jap/jap_kanoeshidan_rifle_apminer | 14 | skills | 4_4_4_5_4_6 | skills_usa_4_4_4_5_4_4 | 4_4_4_5_4_6 while the rest of the Imperial Guard ladder is 3_3_3_5_3_5 (jap_kanoeshidan_type99rifle, same rifle and mines, same card elites_ig); x7 in elites_ig, x3 in elite_ig2 |
| jap/ki_rifle | 14 | skills | 3_3_3_5_3_3 | skills_3_3_3_4_3_3 | melee 3; card mates ki_at_grenade / ki_at_stick (same body, same rifle) are 3_3_3_5_3_5 with melee 5 |
| jap/ki_smoke | 14 | skills | 3_3_3_5_3_3 | skills_3_3_3_4_3_3 | melee 3, same as ki_rifle; card mates have melee 5 |
| usa/usa_radioman_105 | 14 | skills | 6_3_2_2_1_3 | skills_2_3_2_2_1_3 | pistol 6; sibling usa_radioman_155 (same body, same M3 + flare gun) has pistol 3 (skills_3_3_2_2_1_3). The flare guns are in stuff/pistol, so pistol skill likely aims the call-in flare [I] |
| usa/usa_radioman_240 | 14 | skills | 6_3_2_2_1_3 | skills_2_3_2_2_1_3 | pistol 6, see usa_radioman_105; 155 has pistol 3 |

### M3: In-squad inconsistency, low confidence (18)

| side/breed | set line | kind | value | nearest tier | why |
|---|---|---|---|---|---|
| axis_minor/axm_bul_radioman | 12 | body | health 300% vs 150% | body_regular | health 300% on a radioman (Radioman $200); other sides' radiomen are on body_regular(_bare) 150% |
| axis_minor/axm_fin_sissi_mgun_assist | 14 | skills | 1_1_7_7_1_2 | skills_rus_militia | smg 1 while every other Sissi except the MG gunner has smg 5; the hero copy has the same 117712, so it may be meant |
| axis_minor/axm_fin_sissi_squadleader_vision | 12 | body | vision "mp_officer" vs "mp_soldier", speed 1.1 vs 0.9 | body_squadleader | the regular Sissi card (squads.set:23) uses the hero SL axm_fin_sissi_squadleader_vision (officer vision, speed 1.1); the plain axm_fin_sissi_squadleader exists but no card uses it |
| axis_minor/axm_ita_alpini_rifle | 14 | skills | 2_1_3_4_1_2 | skills_2_1_3_3_1_2 | same role (Carcano + Breda 35 grenades) as axm_ita_alpini_rifle2 but smg 1 vs 3 and body_squadleader vs body_regular; Alpini card has 7 different skill sets for 11 men |
| axis_minor/axm_ita_alpini_rifle2 | 14 | skills | 2_3_3_4_1_2 | skills_2_3_1_1_1_2 | see axm_ita_alpini_rifle |
| axis_minor/axm_ita_bersaglieri_mgun | 14 | skills | 1_4_5_4_1_2 | skills_rus_militia | pistol 1 although he carries a pistol; squad has pistol 2 |
| axis_minor/axm_ita_bersaglieri_mgun_assist | 14 | skills | 1_3_5_5_1_2 | skills_ger_ss_4_3_5_5_4_4 | pistol 1, smg 3 while the squad has pistol 2, smg 4-5 (gunner also pistol 1) |
| ger_ss/ss_ssvt_sl | 14 | skills | 2_3_2_2_2_2 | skills_2_3_2_2_1_2 | rocket 2 with no rocket weapon (MP41 only); squad rocket 1. Copied in ssvt_sl (1941) |
| ger_ss/ss_ssvt_sl_asst | 14 | skills | 2_2_1_3_2_2 | skills_2_2_1_3_1_2 | rocket 2 with no rocket weapon; squad rocket 1 |
| ger_ss/ssvt_sl | 14 | skills | 2_3_2_2_2_2 | skills_2_3_2_2_1_2 | same as ss_ssvt_sl |
| ger_ss/ssvt_sl_asst | 14 | skills | 2_2_1_3_2_2 | skills_2_2_1_3_1_2 | same as ss_ssvt_sl_asst |
| ger/ger_grenadier_ober_44 | 14 | skills | 5_4_4_5_3_5 | skills_ger_5_4_4_5_4_5 | rocket 3 although this 1944 copy carries a panzerfaust_60; squad pzfst men have rocket 4 |
| ger/ger_officer | 13 | body | stamina 100% vs 150% | body_officer_bare | stamina 100% while the other officer bodies use 150%; ger_officer skills 5_5_5_5_5_5 vs eng/usa officers 5_5_4_4_3_4 |
| ger/grenadier_ober | 14 | skills | 5_4_4_5_3_5 | skills_ger_5_4_4_5_4_5 | 2IC on 5_4_4_5_x_5 with rocket 3 while the rest of the squad has rocket 4 |
| rus_guard/guard_elite_guard_sl | 15 | skills | 2_3_2_3_2_3 | skills_2_3_2_2_1_3 | same values as guard_sl |
| rus_guard/guard_sl | 15 | skills | 2_3_2_3_2_3 | skills_2_3_2_2_1_3 | rifle 3, rocket 3 with PPSh only; guard ladder rifle 1 (smg men), rocket 1 |
| rus/flamer3 | 15 | skills | 2_3_1_3_1_3 | skills_2_3_1_1_1_3 | flamer on 2_3_1_3_1_3 (rifle 3 with no rifle); rus flamer tier is 2_2_1_2_1_2, card mates smg3 are 3_4_2_2_2_3 |
| rus/mgun_41 | 15 | skills | 1_1_2_1_1_2 | skills_rus_militia | pistol 1 while the 1941 ladder (rifle_41, smg_41, mgun_asst_41) has pistol 2 |

### L: Leftover: no card uses the breed (75)

| side/breed | line | kind | value / diff | nearest tier | up | weapons | cards |
|---|---|---|---|---|---|---|---|
| axis_minor/axm_bul_officer | 14 | body | health 300% vs 250% | body_officer_s100 |  | pistol | - |
| axis_minor/axm_fin_sissi_squadleader | 14 | skills | 3_7_5_5_3_2 | skills_jap_3_3_3_5_3_5 | smg+mgun | smg | - |
| axis_minor/axm_hun_elite_tankcommander | 15 | skills | 6_2_1_1_1_2 | skills_2_2_1_1_1_2 | pistol | pistol | - |
| axis_minor/axm_rom_elite_vehicle_supporter | 14 | skills | 5_5_5_5_2_4 | skills_5_5_5_6_5_5 |  | smg | - |
| eng/at_rifle | 14 | skills | 2_3_2_4_2_3 | skills_2_3_2_2_1_3 | rifle+rocket | rifle+smg | - |
| eng/elite_tankman2 | 13 | drive | cannon 1 vs 1.1 | drive_t12_v12_c11 |  | smg | - |
| eng/elite_tankman2 | 14 | skills | 4_4_7_2_1_3 | skills_2_3_2_2_1_3 | pistol+smg+mgun | smg | - |
| eng/mgun_scot | 14 | skills | 3_3_5_3_2_5 | skills_3_3_5_3_2_4 | melee | mgun | - |
| eng/rifle_scot | 14 | skills | 3_3_3_5_2_5 | skills_jap_3_3_3_5_3_5 |  | rifle | - |
| eng/sniper | 16 | skills | 3_3_3_6_2_4 | skills_3_3_3_4_2_4 | rifle | rifle | - |
| eng/squadleader_can | 14 | skills | 3_4_2_3_2_4 | skills_4_4_2_3_2_4 |  | rifle | - |
| eng/vet_tankman2 | 14 | skills | 3_3_4_2_1_3 | skills_3_3_2_2_1_3 | mgun | smg | - |
| ger_ss/bazooker | 14 | skills | 6_3_3_5_6_5 | skills_jap_3_3_3_5_3_5 | pistol+rocket | rocket+pistol | - |
| ger_ss/bazooker2 | 14 | skills | 5_3_3_6_6_5 | skills_5_5_5_6_5_5 | rocket | rifle | - |
| ger_ss/dr_pzgren_pzfst_stg | 15 | skills | 4_5_3_3_5_4 | skills_ger_ss_4_5_3_3_4_4 | rocket | smg+rocket | - |
| ger_ss/elite_tankman | 13 | drive | cannon 1.05 vs 1.1 | drive_t12_v12_c11 |  | pistol | - |
| ger_ss/elite_tankman | 14 | skills | 7_5_6_4_1_6 | skills_elite_6 | pistol | pistol | - |
| ger_ss/elite_tankman2 | 13 | drive | tank 1.25 vs 1.2, vehicle 1.25 vs 1.2 | drive_t12_v12_c11 |  | smg | - |
| ger_ss/elite_tankman2 | 14 | skills | 6_7_7_4_1_6 | skills_elite_7 |  | smg | - |
| ger_ss/tankman | 14 | skills | 5_4_3_3_1_5 | skills_ger_5_4_4_5_4_5 |  | pistol | - |
| ger_ss/tankman2 | 14 | skills | 5_5_5_3_1_5 | skills_5_5_5_6_5_5 |  | smg | - |
| ger2/ost_elite_tankman | 14 | skills | 5_5_5_3_2_4 | skills_4_5_6_3_2_4 | pistol | pistol | - |
| ger2/ost_elite_tankman2 | 14 | skills | 4_5_7_3_2_4 | skills_4_5_6_3_2_4 | mgun | smg | - |
| ger2/ost_support | 14 | skills | 3_3_6_4_2_4 | skills_3_3_3_4_2_4 | mgun | rifle | - |
| ger/elite_tankman | 14 | skills | 5_5_5_3_2_4 | skills_4_5_6_3_2_4 | pistol | pistol | - |
| ger/elite_tankman2 | 14 | skills | 4_5_7_3_2_4 | skills_4_5_6_3_2_4 | mgun | smg | - |
| ger/elite_vehicle_supporter | 14 | skills | 5_5_5_5_2_4 | skills_5_5_5_6_5_5 |  | rifle | - |
| ger/ger_elite_tankman | 14 | skills | 5_5_5_3_2_4 | skills_4_5_6_3_2_4 | pistol | pistol | - |
| ger/ger_elite_tankman2 | 14 | skills | 4_5_7_3_2_4 | skills_4_5_6_3_2_4 | mgun | smg | - |
| ger/ger_pzgren_panzerfaust | 15 | skills | 5_5_4_4_5_5 | skills_ger_5_5_4_4_6_5 |  | rifle+rocket | - |
| ger/ger_tankman_single | 14 | skills | 5_4_3_3_1_5 | skills_ger_5_4_4_5_4_5 |  | pistol | - |
| ger/ger_tankman2_single | 14 | skills | 5_5_5_3_1_5 | skills_5_5_5_6_5_5 |  | smg | - |
| ger/vet_tankman | 14 | skills | 5_5_4_3_2_4 | skills_4_3_4_3_2_4 | pistol+smg | pistol | - |
| ger/vet_vehicle_supporter | 14 | skills | 3_3_6_4_2_4 | skills_3_3_3_4_2_4 | mgun | rifle | - |
| jap/elite_ig1h_asst | 14 | skills | 3_3_5_5_3_5 | skills_jap_3_3_3_5_3_5 | mgun | rifle+mgun | - |
| jap/elite_ig2_scoped | 14 | skills | 3_3_5_3_3_5 | skills_jap_3_3_3_5_3_5 | mgun | mgun | - |
| jap/elite_ig3b_type2 | 14 | skills | 3_5_3_3_3_5 | skills_jap_3_3_3_5_3_5 | smg | smg | - |
| jap/elite_ig4_type2 | 14 | skills | 3_5_3_3_5_5 | skills_5_5_5_6_5_5 |  | smg | - |
| jap/elite_takasago_mgun_asst | 15 | skills | 6_4_6_6_4_6 | skills_jap_6_4_4_6_4_6 | mgun | rifle+mgun | - |
| jap/elite_vehicle_supporter | 14 | skills | 2_2_5_5_1_2 | skills_sniper_r5 | mgun | rifle | - |
| jap/jap_tankman_single | 13 | drive | vehicle 1.1 vs 1, cannon 1.1 vs 0.95 | drive_crew_commander |  | pistol | - |
| jap/jap_tankman2_single | 13 | drive | cannon 1.15 vs 1.0 | drive_crew_elite |  | smg | - |
| jap/jap_tankman2_single | 14 | skills | 2_2_3_1_1_2 | skills_2_2_1_1_1_2 | mgun | smg | - |
| jap/kamikaze | 14 | body | health 300% vs 250%, speed 1.0 vs 0.95 | body_jap_charger |  | smg | - |
| rus_guard/elite_tankman | 14 | skills | 3_3_5_3_3_3 | skills_3_3_3_3_3_3 | mgun | smg | - |
| rus_guard/elite_tankman2 | 14 | skills | 4_5_7_3_3_4 | skills_ger_ss_4_5_3_3_4_4 | mgun | smg | - |
| rus_guard/guard_elite_tankcommander | 14 | skills | 4_5_7_3_3_4 | skills_ger_ss_4_5_3_3_4_4 | mgun | smg | - |
| rus_guard/guard_elite_tankman | 14 | skills | 3_3_5_3_3_3 | skills_3_3_3_3_3_3 | mgun | smg | - |
| rus_guard/vet_tankman | 14 | skills | 5_5_5_5_5_5 | skills_5_5_5_6_5_5 |  | smg | - |
| rus/rus_elite_tankcommander | 14 | skills | 4_5_7_3_3_4 | skills_ger_ss_4_5_3_3_4_4 | mgun | smg | - |
| rus/rus_elite_tankman | 14 | skills | 3_3_5_3_3_3 | skills_3_3_3_3_3_3 | mgun | smg | - |
| rus/rus_tankman_single | 13 | drive | tank 1.1 vs 0.85, vehicle 1.1 vs 1 | drive_veteran |  | pistol | - |
| rus/rus_tankman_single | 14 | skills | 3_3_2_1_1_2 | skills_3_3_2_2_1_3 |  | pistol | - |
| rus/rus_tankman2_single | 13 | drive | tank 1.2 vs 1.1, vehicle 1.1 vs 1 | drive_crew_commander |  | smg | - |
| rus/rus_tankman2_single | 14 | skills | 3_3_3_1_1_2 | skills_2_3_1_1_1_2 | pistol+mgun | smg | - |
| rus/rus_vetsniper | 16 | skills | 4_4_4_6_4_4 | skills_usa_4_4_4_5_4_4 | rifle | rifle | - |
| rus/sniper2 | 16 | skills | 4_4_4_6_4_4 | skills_usa_4_4_4_5_4_4 | rifle | rifle | - |
| rus/vet_tankman | 14 | skills | 5_5_5_5_5_5 | skills_5_5_5_6_5_5 |  | smg | - |
| rus/vet_tankman2 | 14 | skills | 4_4_5_1_1_2 | skills_2_2_1_1_1_2 | pistol+smg+mgun | smg | - |
| usa/elite_sgt | 14 | skills | 4_6_4_4_4_4 | skills_4_5_4_4_4_4 | smg | smg | - |
| usa/elite_tankman | 14 | skills | 4_4_5_3_3_3 | skills_4_4_2_3_2_4 | mgun+rocket | pistol | - |
| usa/elite_tankman2 | 14 | skills | 4_4_7_3_3_3 | skills_4_4_2_3_2_4 | mgun+rocket | smg | - |
| usa/elite4_sgt | 14 | skills | 3_5_3_3_3_3 | skills_3_3_3_3_3_3 | smg | smg | - |
| usa/squadleader | 14 | skills | 3_4_3_3_2_4 | skills_4_4_2_3_2_4 | mgun | smg | - |
| usa/squadleader2 | 14 | skills | 3_4_3_3_2_4 | skills_4_4_2_3_2_4 | mgun | smg | - |
| usa/sturmovik5 | 15 | skills | 5_5_5_6_6_5 | skills_5_5_5_6_5_5 | rocket | rocket+rifle | - |
| usa/usa_raiderbar | 15 | skills | 4_4_1_5_4_4 | skills_usa_4_4_4_5_4_4 |  | rifle | - |
| usa/usa_raiderchad | 15 | skills | 4_6_4_5_4_4 | skills_usa_4_4_4_5_4_4 | smg | smg | - |
| usa/usa_raiderdemo | 15 | skills | 4_5_4_5_4_4 | skills_usa_4_4_4_5_4_4 | smg | smg | - |
| usa/usa_raidergren | 15 | skills | 3_3_3_5_3_3 | skills_3_3_3_4_3_3 | rifle | rifle | - |
| usa/usa_tankman_single | 14 | skills | 3_3_2_2_2_3 | skills_3_4_2_2_2_3 |  | pistol | - |
| usa/usa_tankman2_single | 14 | skills | 3_3_3_2_2_3 | skills_3_4_2_2_2_3 | mgun | smg | - |
| usa/vet_tankman | 14 | skills | 3_3_3_2_2_3 | skills_3_4_2_2_2_3 | mgun | pistol | - |
| usa/vet_tankman2 | 13 | drive | tank 1.3 vs 1.2, cannon 1.15 vs 1.1 | drive_t12_v12_c11 |  | smg | - |
| usa/vet_tankman2 | 14 | skills | 3_3_5_2_2_3 | skills_3_4_2_2_2_3 | mgun | smg | - |

### C1: Crew skills: side convention / commander bump (30)

| side/breed | line | kind | value / diff | nearest tier | up | weapons | cards |
|---|---|---|---|---|---|---|---|
| axis_minor/axm_hun_vet_tankcommander | 15 | skills | 6_2_4_1_1_2 | skills_axis_minor_2_2_4_1_1_2 | pistol | pistol | turan3_vet |
| eng/elite_tankman | 14 | skills | 4_4_5_2_1_3 | skills_2_3_2_2_1_3 | pistol+smg+mgun | pistol | cometa34_elite_gun, achilles_elite_gun, m4a4_firefly_elite_gun |
| eng/eng_vet_tankman2_single | 14 | skills | 3_3_4_2_1_3 | skills_3_3_2_2_1_3 | mgun | smg | elite_tankmans(eng) |
| eng/tankman2 | 14 | skills | 3_3_3_2_1_3 | skills_3_3_2_2_1_3 | mgun | smg | humber, staghound_mk3, m3stuart_eng +29 |
| eng/vehicle_supporter | 14 | skills | 3_2_4_2_1_4 | skills_support | pistol | smg | m3_eng_single, churchill_kangaroo, bedford_art +14 |
| eng/vehicle_supporter_40 | 14 | skills | 3_2_3_2_1_3 | skills_2_2_3_2_1_3 | pistol | smg | vehic_supporter_40(eng) |
| eng/vehicle_supporter_single | 14 | skills | 3_2_4_2_1_4 | skills_support | pistol | smg | vehic_supporter(eng) |
| eng/vet_tankman | 14 | skills | 3_3_3_2_1_3 | skills_3_3_2_2_1_3 | mgun | smg | cometa34_elite_gun, achilles_elite_gun, m4a4_firefly_elite_gun |
| ger_ss/ss_tankman | 14 | skills | 5_4_3_3_1_5 | skills_ger_5_4_4_5_4_5 |  | pistol | tankmans(ger_ss) |
| ger_ss/ss_tankman2 | 14 | skills | 5_5_5_3_1_5 | skills_5_5_5_6_5_5 |  | smg | tankmans(ger_ss) |
| ger_ss/ss_vet_tankman2 | 14 | skills | 5_5_6_3_1_5 | skills_5_5_6_6_5_5 |  | smg | elite_tankmans(ger_ss) |
| ger_ss/vet_tankman | 14 | skills | 5_4_5_3_1_5 | skills_ger_5_4_5_4_4_5 |  | pistol | pz4h_vet, stug3g_vet, jagdpanzer_iv_vet +1 |
| ger_ss/vet_tankman2 | 14 | skills | 5_5_6_3_1_5 | skills_5_5_6_6_5_5 |  | smg | pz4h_vet, stug3g_vet, jagdpanzer_iv_vet +1 |
| ger2/ost_tankman | 14 | skills | 5_5_4_3_2_4 | skills_4_3_4_3_2_4 | pistol+smg | pistol | tankmans(ger2) |
| ger2/tankman | 14 | skills | 5_5_4_3_2_4 | skills_4_3_4_3_2_4 | pistol+smg | pistol | stuh42_vet, ostwind_ger2, t34_2_ger +7 |
| ger2/vehicle_supporter | 14 | skills | 3_3_6_4_2_4 | skills_3_3_3_4_2_4 | mgun | rifle | r12_ger2, sdkfz250_1_single, pak38_ger2 +5 |
| ger/ger_vet_tankman2_single | 14 | skills | 5_5_6_3_1_5 | skills_5_5_6_6_5_5 |  | smg | elite_tankmans(ger) |
| jap/tankman2 | 14 | skills | 2_2_3_1_1_2 | skills_2_2_1_1_1_2 | mgun | smg | ss-ki_single, chi-ha57, chi-ha47 |
| jap/vehicle_supporter | 14 | skills | 2_2_3_2_1_2 | skills_rus_2_2_1_2_1_2 | mgun | rifle | ho-ha3mgun_single, isuzutx40art, ammo_box_jap_inf +4 |
| jap/vehicle_supporter_single | 14 | skills | 2_2_3_2_1_2 | skills_rus_2_2_1_2_1_2 | mgun | rifle | vehic_supporter(jap) |
| rus_guard/rus_guard_tankman_single | 14 | skills | 5_5_3_2_2_5 | skills_5_5_3_4_2_5 |  | pistol | tankmans(rus_guard) |
| rus_guard/rus_guard_tankman2_single | 14 | skills | 5_5_5_5_4_5 | skills_squadleader | mgun | smg | tankmans(rus_guard) |
| rus_guard/tankman | 14 | skills | 5_5_3_2_2_5 | skills_5_5_3_4_2_5 |  | pistol | isu152_guard, t70_guard, m4a2 +11 |
| rus_guard/tankman2 | 14 | skills | 5_5_5_5_4_5 | skills_squadleader | mgun | smg | isu152_guard, t70_guard, m4a2 +11 |
| rus/rus_vet_tankman2_single | 14 | skills | 4_4_5_1_1_2 | skills_2_2_1_1_1_2 | pistol+smg+mgun | smg | elite_tankmans(rus) |
| rus/tankman | 14 | skills | 3_3_2_1_1_2 | skills_3_3_2_2_1_3 |  | pistol | t34m_single, su152, bt5 +9 |
| rus/tankman2 | 14 | skills | 3_3_3_1_1_2 | skills_2_3_1_1_1_2 | pistol+mgun | smg | t34m_single, su152, bt5 +9 |
| usa/tankman | 14 | skills | 3_3_2_2_2_3 | skills_3_4_2_2_2_3 |  | pistol | m4a3m_eng_single, np_t19, m12gmc +8 |
| usa/tankman2 | 14 | skills | 3_3_3_2_2_3 | skills_3_4_2_2_2_3 | mgun | smg | m4a3m_eng_single, np_t19, m12gmc +8 |
| usa/usa_vet_tankman2_single | 14 | skills | 3_3_5_2_2_3 | skills_3_4_2_2_2_3 | mgun | smg | elite_tankmans(usa) |

### C2: Crew drive: per-side crew ladder (7)

| side/breed | line | kind | value / diff | nearest tier | up | weapons | cards |
|---|---|---|---|---|---|---|---|
| jap/tankman | 13 | drive | vehicle 1.1 vs 1, cannon 1.1 vs 0.95 | drive_crew_commander |  | pistol | ss-ki_single, chi-ha57, chi-ha47 |
| jap/tankman2 | 13 | drive | cannon 1.15 vs 1.0 | drive_crew_elite |  | smg | ss-ki_single, chi-ha57, chi-ha47 |
| rus_guard/rus_guard_tankman2_single | 13 | drive | tank 1.1 vs 0.95 | drive_elite |  | smg | tankmans(rus_guard) |
| rus_guard/tankman2 | 13 | drive | tank 1.1 vs 0.95 | drive_elite |  | smg | isu152_guard, t70_guard, m4a2 +11 |
| rus/tankman | 13 | drive | tank 1.1 vs 0.85, vehicle 1.1 vs 1 | drive_veteran |  | pistol | t34m_single, su152, bt5 +9 |
| rus/tankman2 | 13 | drive | tank 1.2 vs 1.1, vehicle 1.1 vs 1 | drive_crew_commander |  | smg | t34m_single, su152, bt5 +9 |
| usa/usa_vet_tankman2_single | 13 | drive | tank 1.3 vs 1.2, cannon 1.15 vs 1.1 | drive_t12_v12_c11 |  | smg | elite_tankmans(usa) |

### H: Hero, officer, radioman: special body or skills by design (24)

| side/breed | line | kind | value / diff | nearest tier | up | weapons | cards |
|---|---|---|---|---|---|---|---|
| axis_minor/axm_fin_elite_sniper | 16 | skills | 2_2_2_7_2_4 | skills_2_2_2_4_2_4 | rifle | rifle | hero_white_death(axis_minor) |
| axis_minor/axm_fin_officer | 13 | body | health 300% vs 250% | body_officer_s100 |  | pistol | officer(axis_minor), officers_40(axis_minor) |
| axis_minor/axm_fin_sissi_mgun_assist_vision | 12 | body | vision "mp_officer" vs "mp_soldier", speed 1.1 vs 0.9 | body_squadleader |  | rifle+mgun | hero_sissisp(axis_minor) |
| axis_minor/axm_fin_sissi_mgun_assist_vision | 14 | skills | 1_1_7_7_1_2 | skills_rus_militia | mgun+rifle | rifle+mgun | hero_sissisp(axis_minor) |
| axis_minor/axm_fin_sissi_mgun_vision | 12 | body | vision "mp_officer" vs "mp_soldier", speed 1.1 vs 0.9 | body_squadleader |  | mgun+pistol | hero_sissisp(axis_minor) |
| axis_minor/axm_fin_sissi_rifle_vision | 12 | body | vision "mp_officer" vs "mp_soldier", speed 1.1 vs 0.9 | body_regular |  | rifle | hero_sissisp(axis_minor) |
| axis_minor/axm_fin_sissi_rifle_vision | 14 | skills | 1_5_5_7_1_2 | skills_rus_militia | smg+mgun+rifle | rifle | hero_sissisp(axis_minor) |
| axis_minor/axm_fin_sissi_smg_vision | 12 | body | vision "mp_officer" vs "mp_soldier", speed 1.1 vs 0.9 | body_regular |  | smg | hero_sissisp(axis_minor) |
| axis_minor/axm_fin_sissi_smg_vision | 14 | skills | 2_7_5_5_3_2 | skills_2_2_1_1_3_2 | smg+mgun+rifle | smg | hero_sissisp(axis_minor) |
| eng/eng_anzac_sl | 14 | skills | 3_5_3_3_3_3 | skills_3_3_3_3_3_3 | smg | smg | hero3(eng) |
| eng/eng_anzac_smg | 14 | skills | 3_4_3_3_3_3 | skills_3_3_3_3_3_3 | smg | smg | hero3(eng) |
| eng/eng_anzac_smg_thompson | 14 | skills | 3_4_3_3_3_3 | skills_3_3_3_3_3_3 | smg | smg | hero3(eng) |
| eng/eng_officer | 16 | skills | 5_5_4_4_3_4 | skills_4_5_4_4_4_4 | pistol | pistol | officers_40(eng) |
| ger2/ost_officer2 | 13 | body | health 500% vs 400%, speed 1.0 vs 1 (text only) | body_crew_elite |  | smg | hero1_ost(ger2) |
| ger2/ost_straf_mauzer | 14 | skills | 1_1_1_1_1_1 | skills_rus_militia |  | rifle+rocket | hero4_ost(ger2) |
| ger2/ost_straf_mp28 | 14 | skills | 1_1_1_1_1_1 | skills_rus_militia |  | smg | hero4_ost(ger2) |
| ger2/ost_straf_ppsh | 14 | skills | 1_1_1_1_1_1 | skills_rus_militia |  | smg | hero4_ost(ger2) |
| ger/ger_officer | 16 | skills | 5_5_5_5_5_5 | skills_5_5_5_6_5_5 |  | pistol | officers_40(ger) |
| jap/ki_sa | 14 | skills | 4_4_4_6_4_6 | skills_jap_6_4_4_6_4_6 |  | rifle | hero_ki-gata_koho(jap) |
| jap/ki_sl | 14 | skills | 4_4_4_6_4_6 | skills_jap_6_4_4_6_4_6 |  | rifle | hero_ki-gata_koho(jap) |
| jap/otsu_mg_ammo | 14 | skills | 1_1_1_3_1_2 | skills_2_1_1_3_1_2 |  | rifle+mgun | hero_otsu-gata_koho(jap) |
| jap/otsu_mg_asst | 14 | skills | 1_1_3_3_1_2 | skills_jap_1_1_3_1_1_2 | rifle | rifle+mgun | hero_otsu-gata_koho(jap) |
| jap/otsu_rifle | 14 | skills | 1_1_1_3_1_2 | skills_2_1_1_3_1_2 |  | rifle | hero_otsu-gata_koho(jap) |
| usa/usa_officer | 16 | skills | 5_5_4_4_3_4 | skills_4_5_4_4_4_4 | pistol | pistol | officers_40(usa) |

### R2: Squad ladder: leader / 2IC bump (39)

| side/breed | line | kind | value / diff | nearest tier | up | weapons | cards |
|---|---|---|---|---|---|---|---|
| axis_minor/axm_bul_squadleader | 14 | skills | 3_4_2_3_1_2 | skills_4_4_2_3_2_4 |  | smg | Bulgarian_Infantry(axis_minor) |
| axis_minor/axm_fin_kaukopartio_squadleader | 14 | skills | 3_7_5_5_3_3 | skills_3_3_3_4_3_3 | smg+mgun+rifle | smg | fin_kaukopartio(axis_minor) |
| axis_minor/axm_fin_pio_squadleader | 14 | skills | 1_5_1_4_1_2 | skills_rus_militia | smg+rifle | smg | fin_pioneer(axis_minor) |
| axis_minor/axm_fin_sissi_squadleader_vision | 14 | skills | 3_7_5_5_3_2 | skills_jap_3_3_3_5_3_5 | smg+mgun | smg | hero_sissisp(axis_minor), Sissi(axis_minor) |
| axis_minor/axm_hun_squadleader_smg | 14 | skills | 3_3_2_3_1_2 | skills_3_3_2_2_1_3 | rifle | smg | hungarian_smg_squad(axis_minor) |
| axis_minor/axm_ita_alpini_squadleader | 14 | skills | 3_5_2_3_1_2 | skills_2_2_2_3_1_3 | pistol+smg | smg | Alpini(axis_minor) |
| axis_minor/axm_ita_paratrooper_squadleader | 15 | skills | 3_7_4_7_3_3 | skills_3_3_4_4_3_3 | smg+rifle | smg | Paracadutisti(axis_minor) |
| axis_minor/axm_rom_squadleader | 14 | skills | 3_4_2_4_1_2 | skills_3_4_2_2_2_3 | rifle | smg | romanian_rifle_squad(axis_minor) |
| eng/eng_pioneer_sl | 14 | skills | 3_3_3_4_3_4 | skills_3_3_3_4_3_3 | melee | rifle | pioneers(eng) |
| eng/eng_squadleader_asst | 14 | skills | 4_4_3_5_2_5 | skills_4_4_1_5_2_4 | mgun+melee | rifle+mgun | smgs(eng), riflemans(eng), riflemans_at(eng) |
| eng/eng_squadleader_can | 14 | skills | 3_4_2_3_2_4 | skills_4_4_2_3_2_4 |  | rifle | riflemans_can(eng) |
| eng/squadleader_40 | 14 | skills | 3_4_2_3_2_4 | skills_4_4_2_3_2_4 |  | rifle | riflemans_40(eng) |
| ger_ss/pzgren_sl_smg | 15 | skills | 4_5_4_3_4_4 | skills_ger_ss_4_5_3_3_4_4 | mgun | smg | pzgrens_43(ger_ss), pzgrens_42(ger_ss), pzgrens_41(ger_ss) |
| ger_ss/ss_kosaken_mg_asst | 15 | skills | 1_1_2_2_1_1 | skills_2_3_2_2_1_3 |  | rifle+mgun | kosaken_44(ger_ss) |
| ger2/ost_recon_sl | 14 | skills | 4_4_3_3_2_4 | skills_4_4_2_3_2_4 | mgun | smg | home_guards(ger2) |
| ger2/ost_recon_sl_stg | 14 | skills | 4_4_3_3_2_4 | skills_4_4_2_3_2_4 | mgun | smg | home_guards2(ger2) |
| ger/gd_pzgren_sl_smg | 15 | skills | 4_5_3_3_4_5 | skills_ger_ss_4_5_3_3_4_4 | melee | smg | grenadiers_elite_43(ger) |
| ger/ger_gd_pzgren_sl_asst_stg | 15 | skills | 4_5_3_3_5_5 | skills_ger_ss_4_5_3_3_4_4 | rocket+melee | smg+rocket+mgun | grenadiers_elite(ger) |
| ger/ger_gd_pzgren_sl_stg | 15 | skills | 4_5_3_3_4_5 | skills_ger_ss_4_5_3_3_4_4 | melee | smg | grenadiers_elite(ger) |
| ger/ger_pzgren_sl | 14 | skills | 5_5_4_4_4_5 | skills_squadleader |  | smg | stormtroopers_44(ger) |
| ger/ger_volksgren_mg_asst2 | 14 | skills | 1_2_2_1_1_2 | skills_2_2_2_1_1_2 |  | smg+mgun | volksgrens_heavy(ger) |
| ger/ger_volksgren_sl_asst | 14 | skills | 1_3_1_2_1_3 | skills_2_3_2_2_1_3 |  | smg+rocket+mgun | volksgrens(ger), volksgrens_sturm(ger), volksgrens_heavy(ger) |
| ger/ger_volksgren_sl_smg | 14 | skills | 1_3_1_2_1_3 | skills_2_3_2_2_1_3 |  | smg | volksgrens(ger) |
| ger/ger_volksgren_sl_stg | 14 | skills | 1_3_1_2_1_3 | skills_2_3_2_2_1_3 |  | smg | volksgrens_sturm(ger), volksgrens_heavy(ger) |
| ger/sturmovik_sl_40 | 14 | skills | 5_5_4_4_4_5 | skills_squadleader |  | smg | stormtroopers_43(ger), stormtroopers_42(ger), stormtroopers_41(ger) |
| jap/jap_squadleader | 14 | skills | 4_4_3_4_1_3 | skills_3_3_3_4_3_3 | pistol+smg | smg | riflemans_t96(jap), riflemans_t96_2(jap), riflemans_t96_3(jap) +5 |
| jap/jap_squadleader2 | 14 | skills | 3_4_2_3_1_2 | skills_4_4_2_3_2_4 |  | smg | smgs(jap) |
| jap/squadleader | 14 | skills | 4_4_3_4_1_3 | skills_3_3_3_4_3_3 | pistol+smg | smg | riflemans_t96_42(jap), riflemans_42(jap) |
| jap/squadleader2 | 14 | skills | 3_3_2_3_1_2 | skills_3_3_2_2_1_3 | rifle | smg | smgs_42(jap) |
| rus_guard/guard_elite_guards_shock_sl | 15 | skills | 4_3_3_4_3_4 | skills_ger_ss_4_3_3_5_4_4 |  | rifle | elite_guards_shock(rus_guard) |
| rus_guard/guard_recon_sl | 15 | skills | 3_4_2_2_2_4 | skills_3_4_2_2_2_3 | melee | smg | hero_guard_recon(rus_guard), recons(rus_guard) |
| rus_guard/guard_sapper_sl | 15 | skills | 2_4_2_2_2_3 | skills_3_4_2_2_2_3 |  | smg | sapper_squad(rus_guard) |
| rus_guard/guards_shock_sl | 15 | skills | 4_3_3_4_3_4 | skills_ger_ss_4_3_3_5_4_4 |  | rifle | guards_shock(rus_guard) |
| rus/rus_sapper_sl | 15 | skills | 2_4_2_2_2_3 | skills_3_4_2_2_2_3 |  | smg | sapper_squad(rus) |
| rus/rus_shock_sl | 15 | skills | 4_3_3_4_3_4 | skills_ger_ss_4_3_3_5_4_4 |  | rifle | shock(rus) |
| rus/rus_squadleader_smg | 14 | skills | 4_4_3_4_2_3 | skills_4_5_3_4_2_5 |  | smg | hero5(rus), riflemans(rus), riflemansv2(rus) +8 |
| rus/rus_squadleader2_43 | 14 | skills | 4_4_3_4_2_3 | skills_4_5_3_4_2_5 |  | smg | smgs(rus), smgsv2(rus), smgsv3(rus) +2 |
| usa/usa_nightfighter_leader | 15 | skills | 4_6_4_5_4_4 | skills_usa_4_4_4_5_4_4 | smg | rifle | hero_usa_m3_carbine(usa) |
| usa/usa_squadleader | 14 | skills | 3_4_3_3_2_4 | skills_4_4_2_3_2_4 | mgun | smg | hero_usa_rifles(usa), riflemans(usa), riflemans_bar(usa) +1 |

### R1: Role specialization: raised skill = carried weapon (64)

| side/breed | line | kind | value / diff | nearest tier | up | weapons | cards |
|---|---|---|---|---|---|---|---|
| axis_minor/axm_bul_mgun_assist | 14 | skills | 1_1_3_2_1_2 | skills_jap_1_1_3_1_1_2 | rifle | rifle+mgun | zb_vz26(axis_minor) |
| axis_minor/axm_fin_kaukopartio_mgun | 14 | skills | 3_3_6_4_3_3 | skills_3_3_3_4_3_3 | mgun | mgun | fin_kaukopartio(axis_minor) |
| axis_minor/axm_fin_kaukopartio_mgun_assist | 14 | skills | 3_3_6_6_3_3 | skills_3_3_3_4_3_3 | mgun+rifle | rifle+mgun | fin_kaukopartio(axis_minor) |
| axis_minor/axm_fin_kaukopartio_rifle | 14 | skills | 3_3_3_6_3_3 | skills_3_3_3_4_3_3 | rifle | rifle | fin_kaukopartio(axis_minor), flamers(axis_minor) |
| axis_minor/axm_fin_pio_rifle | 14 | skills | 1_1_1_4_1_2 | skills_rus_militia | rifle | rifle | fin_pioneer(axis_minor) |
| axis_minor/axm_fin_pio_rifle_dynamite | 14 | skills | 1_1_1_4_1_2 | skills_rus_militia | rifle | rifle | fin_pioneer(axis_minor) |
| axis_minor/axm_fin_pio_smg | 14 | skills | 1_4_1_1_1_2 | skills_rus_militia | smg | smg | fin_pioneer(axis_minor) |
| axis_minor/axm_ita_alpini_mgun | 14 | skills | 1_1_4_3_1_2 | skills_2_1_1_3_1_2 | mgun | mgun+pistol | Alpini(axis_minor), breda30_alpini(axis_minor) |
| axis_minor/axm_ita_alpini_mgun_assist | 14 | skills | 2_3_4_4_1_2 | skills_2_3_1_1_1_2 | mgun+rifle | rifle+mgun | Alpini(axis_minor), breda30_alpini(axis_minor) |
| axis_minor/axm_ita_alpini_smg | 14 | skills | 2_4_2_3_1_2 | skills_2_2_2_3_1_3 | smg | smg | Alpini(axis_minor) |
| axis_minor/axm_ita_paratrooper_mgun_assist | 15 | skills | 3_3_7_7_3_3 | skills_3_3_3_4_3_3 | mgun+rifle | rifle+mgun | Paracadutisti(axis_minor), breda30_para(axis_minor) |
| axis_minor/axm_rom_bazooker | 14 | skills | 3_2_1_1_3_2 | skills_2_2_1_1_3_2 | pistol | rocket+pistol | panzershreck(axis_minor) |
| axis_minor/axm_rom_bazooker_assist | 14 | skills | 3_2_1_1_3_2 | skills_2_2_1_1_3_2 | pistol | smg+pistol+mgun | panzershreck(axis_minor) |
| eng/eng_bazooker | 14 | skills | 2_3_2_2_4_3 | skills_2_3_2_2_1_3 | rocket | rocket+smg | riflemans_at(eng), bazookers(eng) |
| eng/eng_mgun_asst | 14 | skills | 2_2_4_4_1_4 | skills_support | rifle | rifle+mgun | smgs(eng), riflemans(eng), riflemans_at(eng) +1 |
| eng/eng_pioneer_at | 14 | skills | 2_2_2_4_4_4 | skills_2_2_2_4_2_4 | rocket | rifle+rocket | pioneers(eng) |
| eng/eng_rifle_piat | 14 | skills | 2_2_2_4_4_4 | skills_2_2_2_4_2_4 | rocket | rifle+rocket | riflemans(eng) |
| eng/eng_smg | 14 | skills | 2_4_2_2_1_3 | skills_2_3_2_2_1_3 | smg | smg | smgs(eng) |
| eng/eng_smg_wp | 14 | skills | 2_4_2_2_1_3 | skills_2_3_2_2_1_3 | smg | smg | smgs2(eng) |
| eng/eng_sniper | 16 | skills | 3_3_3_6_2_4 | skills_3_3_3_4_2_4 | rifle | rifle | snipers(eng) |
| ger_ss/lssah_pzgren_at | 14 | skills | 5_3_3_5_5_4 | skills_ger_ss_4_3_3_5_5_4 | pistol | rocket+pistol | lssah_pzgrens_43(ger_ss) |
| ger_ss/ss_kosaken_rifle | 15 | skills | 1_1_1_2_1_1 | skills_rus_militia | rifle | rifle | kosaken_44(ger_ss) |
| ger_ss/ss_lssah_pzgren_at | 14 | skills | 5_3_3_5_5_4 | skills_ger_ss_4_3_3_5_5_4 | pistol | rocket+pistol | lssah_pzgrens_44(ger_ss) |
| ger_ss/ss_lssah_pzgren_pzfst_stg | 14 | skills | 4_5_3_3_5_4 | skills_ger_ss_4_5_3_3_4_4 | rocket | smg+rocket | lssah_pzgrens_44(ger_ss) |
| ger_ss/ss_panzerfaust | 14 | skills | 4_3_2_5_6_4 | skills_4_3_2_5_2_4 | rocket | rifle+rocket | bazooker3(ger_ss) |
| ger_ss/ss_panzershreck | 14 | skills | 6_3_3_5_6_5 | skills_jap_3_3_3_5_3_5 | pistol+rocket | rocket+pistol | bazookers(ger_ss) |
| ger_ss/ss_pzgren_sl_asst_pzfst | 15 | skills | 4_3_4_5_5_4 | skills_ger_ss_4_3_3_5_5_4 | mgun | rifle+rocket+mgun | pzgrens_44(ger_ss) |
| ger_ss/ss_ssvt_rifle | 15 | skills | 1_1_1_2_1_2 | skills_rus_militia | rifle | rifle | ssvts_44(ger_ss) |
| ger_ss/ss_sturmgren_mg_asst | 14 | skills | 4_5_5_3_4_4 | skills_ger_ss_4_5_3_3_4_4 | mgun | smg+mgun | sturmgrens_heavy(ger_ss) |
| ger_ss/ss_tk_pzgren_pzfst_stg | 15 | skills | 4_5_3_3_5_4 | skills_ger_ss_4_5_3_3_4_4 | rocket | smg+rocket | tk_pzgrens_44(ger_ss) |
| ger_ss/ssvt_rifle | 15 | skills | 1_1_1_2_1_2 | skills_rus_militia | rifle | rifle | ssvts_41(ger_ss) |
| ger2/ost_jager_pzfst | 15 | skills | 4_3_2_5_5_5 | skills_4_3_2_5_3_5 | rocket | rifle+rocket | elites(ger2) |
| ger/ger_fusilier_pzfst | 15 | skills | 4_3_2_5_5_5 | skills_4_3_2_5_3_5 | rocket | rifle+rocket | fusiliers_44(ger) |
| ger/ger_jager_pzfst | 15 | skills | 4_3_2_5_5_5 | skills_4_3_2_5_3_5 | rocket | rifle+rocket | jagers_44(ger) |
| ger/ger_pzgren_mg42assist | 14 | skills | 5_4_5_5_4_5 | skills_ger_5_4_4_5_4_5 | mgun | rifle+mgun | stormtroopers_44(ger), stormtrooper6(ger) |
| ger/ger_sturmgren_sg44_pzfst | 14 | skills | 4_4_2_3_4_4 | skills_4_4_2_3_2_4 | rocket | smg+rocket | sturmgrens_44(ger) |
| ger/ger_sturmgren_sl_asst | 14 | skills | 4_5_2_3_2_4 | skills_4_4_2_3_2_4 | smg | smg+rocket+mgun | sturmgrens_44(ger) |
| ger/ger_volksgren_mg_asst | 14 | skills | 1_1_2_2_1_2 | skills_rus_militia | mgun+rifle | rifle+mgun | volksgrens(ger) |
| ger/ger_volksgren_mg_asst3 | 14 | skills | 1_1_2_2_1_2 | skills_rus_militia | mgun+rifle | rifle+mgun | volksgrens_heavy(ger) |
| ger/ger_volksgren_pzfst2 | 15 | skills | 1_2_1_1_2_2 | skills_ger_volkssturm | smg | smg+rocket | volksgrens_sturm(ger), volksgrens_heavy(ger) |
| jap/elite_ig2 | 14 | skills | 3_3_5_3_3_5 | skills_jap_3_3_3_5_3_5 | mgun | mgun | elites_ig_42(jap) |
| jap/elite_ig3 | 14 | skills | 3_5_3_3_3_5 | skills_jap_3_3_3_5_3_5 | smg | smg | elites_ig_42(jap) |
| jap/elite_takasago_lmg | 15 | skills | 6_4_6_4_4_6 | skills_jap_6_4_4_6_4_6 | mgun | mgun | elites_42_takasago(jap) |
| jap/elite_takasago_smg | 15 | skills | 6_6_4_4_4_6 | skills_jap_6_4_4_6_4_6 | smg | smg | elites_42_takasago(jap) |
| jap/jap_elite_takasago_lmg | 15 | skills | 6_4_6_4_4_6 | skills_jap_6_4_4_6_4_6 | mgun | mgun | elites_takasago(jap), elite3(jap) |
| jap/jap_elite_takasago_smg2 | 15 | skills | 6_6_4_4_4_6 | skills_jap_6_4_4_6_4_6 | smg | smg | elites_takasago(jap) |
| jap/jap_kanoeshidan_mg | 14 | skills | 3_3_5_3_3_5 | skills_jap_3_3_3_5_3_5 | mgun | mgun | hero_jap_guard(jap), elites_ig(jap), elite_ig2(jap) |
| jap/jap_kanoeshidan_type100_44 | 14 | skills | 3_5_3_3_3_5 | skills_jap_3_3_3_5_3_5 | smg | smg | hero_jap_guard(jap), elites_ig(jap) |
| jap/jap_teishin_mg | 14 | skills | 5_5_7_7_5_7 | skills_jap_5_5_5_7_5_7 | mgun | mgun | elites(jap) |
| rus/mgun_asst_41 | 15 | skills | 2_1_2_2_1_2 | skills_2_1_1_2_1_2 | mgun | rifle+mgun | riflemans_41(rus), riflemans_42(rus) |
| rus/squadleader_41 | 14 | skills | 3_3_2_3_1_2 | skills_3_3_2_2_1_3 | rifle | rifle | riflemans_41(rus), riflemans_42(rus) |
| usa/usa_elite_101st_para | 14 | skills | 6_6_6_7_6_6 | skills_elite_6 | rifle | rifle | elites_101st(usa), elite_101st_para3(usa), elite_101st_para3b(usa) |
| usa/usa_elite_101st_para_grenadier | 14 | skills | 6_6_6_7_6_6 | skills_elite_6 | rifle | rifle | elites_101st(usa) |
| usa/usa_elite_101st_para_sgt | 14 | skills | 6_7_6_6_6_6 | skills_elite_6 | smg | smg | elites_101st(usa) |
| usa/usa_elite_101st_para3 | 14 | skills | 6_6_7_7_6_6 | skills_elite_6 | mgun+rifle | rifle+mgun | elites_101st(usa), elite_101st_para3(usa) |
| usa/usa_elite_101st_para3_asst | 14 | skills | 6_6_7_7_6_6 | skills_elite_6 | mgun+rifle | rifle+mgun | elites_101st(usa), elite_101st_para3(usa) |
| usa/usa_elite_101st_para3b | 14 | skills | 6_6_7_6_6_6 | skills_elite_6 | mgun | mgun+rifle | elites_101st(usa), elite_101st_para3b(usa) |
| usa/usa_elite_101st_para3b_asst | 14 | skills | 6_6_7_7_6_6 | skills_elite_6 | mgun+rifle | rifle+mgun | elites_101st(usa), elite_101st_para3b(usa) |
| usa/usa_elite_101st_para4 | 15 | skills | 6_6_6_7_7_6 | skills_elite_6 | rifle+rocket | rifle+rocket | elites_101st(usa) |
| usa/usa_elite_101st_parab | 14 | skills | 6_6_6_7_6_6 | skills_elite_6 | rifle | rifle | elites_101st(usa) |
| usa/usa_elite_sgt | 14 | skills | 4_6_4_4_4_4 | skills_4_5_4_4_4_4 | smg | smg | elites(usa) |
| usa/usa_marine_sgt | 14 | skills | 3_5_3_3_3_3 | skills_3_3_3_3_3_3 | smg | smg | specialinf(usa) |
| usa/usa_ranger_bazooka | 15 | skills | 5_5_5_6_6_5 | skills_5_5_5_6_5_5 | rocket | rocket+rifle | stormtroopers(usa), stormtroopers_heavy(usa), stormtrooper5(usa) |
| usa/usa_ranger_recoiless | 14 | skills | 5_5_5_6_6_5 | skills_5_5_5_6_5_5 | rocket | rifle+rocket | stormtrooper_at(usa) |

### R3: Squad ladder variant (small set, under the 4-user macro threshold) (54)

| side/breed | line | kind | value / diff | nearest tier | up | weapons | cards |
|---|---|---|---|---|---|---|---|
| axis_minor/axm_bul_mgun | 14 | skills | 1_1_3_2_1_2 | skills_jap_1_1_3_1_1_2 | rifle | mgun+pistol | zb_vz26(axis_minor) |
| axis_minor/axm_fin_kaukopartio_smg | 14 | skills | 3_6_5_5_3_3 | skills_3_3_3_4_3_3 | smg+mgun+rifle | smg | fin_kaukopartio(axis_minor), suomi_m31(axis_minor) |
| axis_minor/axm_fin_pio_flamer | 15 | skills | 2_3_2_4_1_2 | skills_2_3_2_2_1_2 | rifle | flame+pistol | fin_pioneer(axis_minor), flamers(axis_minor) |
| axis_minor/axm_fin_pio_mgun | 14 | skills | 1_3_4_4_1_2 | skills_rus_militia | smg+mgun+rifle | mgun+pistol | fin_pioneer(axis_minor) |
| axis_minor/axm_fin_sissi_mgun | 14 | skills | 1_5_7_6_1_2 | skills_rus_militia | smg+mgun+rifle | mgun+pistol | Sissi(axis_minor) |
| axis_minor/axm_fin_sissi_rifle | 14 | skills | 1_5_5_7_1_2 | skills_rus_militia | smg+mgun+rifle | rifle | Sissi(axis_minor) |
| axis_minor/axm_fin_sissi_smg | 14 | skills | 2_7_5_5_3_2 | skills_2_2_1_1_3_2 | smg+mgun+rifle | smg | Sissi(axis_minor) |
| axis_minor/axm_ita_alpini_sniper | 17 | skills | 2_2_4_5_1_2 | skills_sniper_r5 | mgun | rifle+pistol | Alpini(axis_minor) |
| axis_minor/axm_ita_bersaglieri_rifle | 14 | skills | 2_4_4_5_1_2 | skills_sniper_r5 | smg+mgun | rifle | Bersaglieri(axis_minor), carcano(axis_minor) |
| axis_minor/axm_ita_bersaglieri_rifle2 | 14 | skills | 2_4_4_5_1_2 | skills_sniper_r5 | smg+mgun | rifle | Bersaglieri(axis_minor) |
| axis_minor/axm_ita_bersaglieri_smg | 14 | skills | 2_5_3_4_1_2 | skills_2_1_3_3_1_2 | smg+rifle | smg | Bersaglieri(axis_minor) |
| axis_minor/axm_ita_paratrooper_mgun | 15 | skills | 3_3_7_7_3_3 | skills_3_3_3_4_3_3 | mgun+rifle | mgun | Paracadutisti(axis_minor), breda30_para(axis_minor) |
| axis_minor/axm_ita_paratrooper_rifle | 15 | skills | 3_3_5_7_3_3 | skills_3_3_3_4_3_3 | mgun+rifle | rifle | Paracadutisti(axis_minor) |
| axis_minor/axm_ita_paratrooper_smg | 15 | skills | 3_7_4_5_3_3 | skills_3_3_4_4_3_3 | smg+rifle | smg | Paracadutisti(axis_minor) |
| axis_minor/axm_rom_minedisposal | 15 | skills | 4_3_1_1_1_2 | skills_2_3_1_1_1_2 | pistol | smg | sappers(axis_minor) |
| eng/eng_at_rifle | 14 | skills | 2_3_2_4_2_3 | skills_2_3_2_2_1_3 | rifle+rocket | rifle | at_rifles(eng) |
| eng/eng_bazooker_assist | 14 | skills | 2_3_2_2_4_3 | skills_2_3_2_2_1_3 | rocket | smg+mgun | bazookers(eng) |
| eng/eng_light_mortar | 14 | skills | 2_2_2_5_1_4 | skills_2_2_2_3_1_3 | rifle+melee | rocket+rifle | light_mortar_eng |
| eng/eng_light_mortar_assist | 14 | skills | 2_2_2_5_1_4 | skills_2_2_2_3_1_3 | rifle+melee | rifle+mgun | light_mortar_eng |
| eng/eng_mgun | 14 | skills | 2_2_4_2_1_4 | skills_support |  | mgun | smgs(eng), riflemans(eng), riflemans_at(eng) +1 |
| eng/eng_mgun_assist_scot | 14 | skills | 3_3_5_5_2_5 | skills_4_3_5_5_2_5 |  | rifle+mgun | riflemans_scot(eng) |
| eng/eng_mgun_scot | 14 | skills | 3_3_5_3_2_5 | skills_3_3_5_3_2_4 | melee | mgun | riflemans_scot(eng) |
| eng/eng_pioneer_mg | 14 | skills | 2_2_4_3_2_4 | skills_support | rifle | mgun | pioneers(eng) |
| eng/eng_rifle_grenadier | 14 | skills | 2_2_2_4_1_4 | skills_2_2_2_4_2_4 |  | rifle | riflemans(eng) |
| eng/eng_rifle_scot | 14 | skills | 3_3_3_5_2_5 | skills_jap_3_3_3_5_3_5 |  | rifle | riflemans_scot(eng) |
| eng/eng_rifleman | 14 | skills | 2_2_2_4_1_4 | skills_2_2_2_4_2_4 |  | rifle | smgs(eng) |
| eng/eng_rifleman_smoke | 14 | skills | 2_2_2_4_1_4 | skills_2_2_2_4_2_4 |  | rifle | riflemans(eng), riflemans_at(eng), riflemans2(eng) |
| ger_ss/ss_kosaken_mg | 15 | skills | 1_1_2_2_1_1 | skills_2_3_2_2_1_3 |  | mgun | kosaken_44(ger_ss) |
| ger_ss/ss_kosaken_smg | 15 | skills | 1_2_1_1_1_1 | skills_2_2_1_1_1_2 |  | smg | kosaken_44(ger_ss) |
| ger_ss/ss_panzershreckassist | 14 | skills | 5_3_3_6_6_5 | skills_5_5_5_6_5_5 | rocket | rifle+mgun | bazookers(ger_ss) |
| ger_ss/ss_pzgren_pzfst | 15 | skills | 4_3_4_5_5_4 | skills_ger_ss_4_3_3_5_5_4 | mgun | rifle+rocket | pzgrens_44(ger_ss) |
| ger_ss/ss_pzgren_pzfst_sa | 15 | skills | 4_3_4_5_5_4 | skills_ger_ss_4_3_3_5_5_4 | mgun | rifle+rocket | pzgrens_44(ger_ss) |
| ger_ss/ss_pzgren_stg | 15 | skills | 4_5_4_3_4_4 | skills_ger_ss_4_5_3_3_4_4 | mgun | smg | pzgrens_44(ger_ss) |
| ger2/ost_recon_mg | 14 | skills | 3_2_3_3_2_3 | skills_2_2_3_3_1_3 | pistol+rocket | mgun+pistol | home_guards(ger2), home_guards2(ger2) |
| ger2/ost_recon_pzfst | 14 | skills | 3_2_2_3_3_3 | skills_2_2_2_3_1_3 | pistol+rocket | rifle+rocket | home_guards(ger2), home_guards2(ger2) |
| ger2/ost_recon_rifle | 14 | skills | 3_2_2_3_2_3 | skills_3_2_2_4_2_3 |  | rifle+rocket | home_guards2(ger2) |
| ger2/ost_recon_sa | 14 | skills | 3_2_2_3_2_3 | skills_3_2_2_4_2_3 |  | rifle+rocket | home_guards2(ger2) |
| ger2/ost_rifle_grenadier | 14 | skills | 4_3_3_4_2_4 | skills_4_3_2_4_2_4 | mgun | rifle | riflemans(ger2) |
| ger2/ost_rifle_pzfst | 14 | skills | 4_3_3_4_4_4 | skills_ger_ss_4_3_3_5_4_4 |  | rifle+rocket | smgs(ger2), riflemans(ger2) |
| ger2/ost_rifle_single | 14 | skills | 4_3_3_4_2_4 | skills_4_3_2_4_2_4 | mgun | rifle | riflemans2(ger2) |
| ger2/ost_rifle2 | 14 | skills | 4_3_3_4_2_4 | skills_4_3_2_4_2_4 | mgun | rifle+rocket | riflemans(ger2) |
| ger2/ost_sniper | 16 | skills | 4_4_3_7_3_5 | skills_jap_3_3_3_5_3_5 | pistol+smg+rifle | rifle | snipers(ger2) |
| ger/ger_gd_pzgren_pzfst_sa | 15 | skills | 4_3_3_5_5_5 | skills_ger_ss_4_3_3_5_5_4 | melee | rifle+rocket | grenadiers_elite(ger) |
| ger/ger_gd_pzgren_pzfst_stg | 15 | skills | 4_5_3_3_5_5 | skills_ger_ss_4_5_3_3_4_4 | rocket+melee | smg+rocket | grenadiers_elite(ger) |
| ger/ger_pzgren_stg_panzerfaust | 15 | skills | 5_5_4_4_5_5 | skills_ger_5_5_4_4_6_5 |  | smg+rocket | stormtroopers_44(ger) |
| ger/ger_volksgren_mg | 14 | skills | 2_1_2_1_2_2 | skills_ger_ss_2_1_2_1_1_2 | rocket | mgun+pistol | volksgrens(ger), volksgrens_heavy(ger) |
| ger/sturmovik6b | 14 | skills | 5_4_5_5_4_5 | skills_ger_5_4_4_5_4_5 | mgun | rifle | stormtroopers_43(ger), stormtroopers_42(ger), stormtroopers_41(ger) |
| jap/elite_ig4 | 14 | skills | 3_5_3_3_5_5 | skills_5_5_5_6_5_5 |  | smg | elites_ig_42(jap) |
| jap/jap_kamikaze | 13 | body | no tier within 2 values (nearest body_elite, 3 values differ) | body_elite |  | rocket | hero2(jap), kamikaze(jap) |
| jap/jap_kanoeshidan_at | 14 | skills | 3_5_3_3_5_5 | skills_5_5_5_6_5_5 |  | smg | hero_jap_guard(jap), elites_ig(jap) |
| jap/jap_teishin_type100_44_apminer | 14 | skills | 5_7_5_5_5_7 | skills_usa_5_6_5_5_5_5 | smg+melee | smg | elites(jap) |
| rus_guard/guard_elite_guard_sl | 13 | body | stamina 125% vs 150% | body_h250_s150 |  | smg | elite_guards_smg(rus_guard), elite_guards(rus_guard) |
| rus_guard/guard_sl | 13 | body | stamina 125% vs 150% | body_h250_s150 |  | smg | specialinf_smg(rus_guard), specialinf_rifle(rus_guard), specialinf(rus_guard) |
| rus/rus_bsf_marine3 | 15 | skills | 5_5_6_5_5_5 | skills_5_5_6_6_5_5 |  | mgun | bsf_marines(rus) |

### T: Text-only difference (4)

| side/breed | line | kind | value / diff | nearest tier | up | weapons | cards |
|---|---|---|---|---|---|---|---|
| eng/eng_sniper | 12 | body | vision mp_sniper vs "mp_sniper", speed 1 vs 1.0 (text only, same numbe | body_sniper |  | rifle | snipers(eng) |
| jap/jap_sniper_type97 | 12 | body | vision mp_sniper vs "mp_sniper", speed 1 vs 1.0 (text only, same numbe | body_sniper |  | rifle | snipers2(jap) |
| jap/jap_sniper_type99 | 12 | body | vision mp_sniper vs "mp_sniper", speed 1 vs 1.0 (text only, same numbe | body_sniper |  | rifle | snipers(jap) |
| usa/usa_ranger_recoiless | 12 | body | vision mp_soldier vs "mp_soldier" (text only, same number) | body_h350_s200 |  | rifle+rocket | stormtrooper_at(usa) |

## Inconsistency inside one squad (cards)

Skill vectors are pistol/smg/mgun/rifle/rocket/melee. Weapon letters: R rifle, M smg, G mgun, P pistol, K rocket, S sniper.
Source: `units/<side>/*` cards via `cards.tsv`, breeds via `breeds.tsv`. [D] unless tagged.

| card (side) | cost | what is uneven | likely mistake? |
|---|---|---|---|
| elites_ig (jap) "Imperial Guard section" | $252 | apminer x7 444546 vs type99rifle / type38rifle 333535, same rifle, same body | yes [I]: the apminer line is one step up on every skill |
| elites (jap) "Teishin Paratrooper section" | $254 | type2rifle x6 and type97_atr(_asst) on skills_elite_7 777777; apminer, mg, smg men on a 5_5_5_7_5_7 base; the atr pair are on vet_standard, the rest on vet_elite | maybe: the 777777 men look like a tier swap; atr pair vet_standard looks copied from a non-elite AT-rifle line [I] |
| hero_ki-gata_koho (jap) | $2 hero | ki_rifle x5, ki_smoke x4 melee 3; ki_at_grenade / ki_at_stick melee 5; ki_sl / ki_sa 444646 | yes for melee [I] |
| Sissi (axis_minor) `units/axis_minor/squads.set:23` | $159 | SL is the hero copy `_vision` (officer vision, speed 1.1); mgun_assist smg 1 while the rest smg 5-7 | SL swap: likely; smg 1: unclear (hero copy has it too) |
| Alpini (axis_minor) | $215 | 7 skill sets for 11 men; rifle x4 213412 body_squadleader vs rifle2 x3 233412 body_regular, same Carcano | maybe: rifle (x4) looks like it got the SL body [I] |
| Bersaglieri (axis_minor) | $158 | MG gunner and assistant pistol 1, rest pistol 2; assistant smg 3 vs 4-5 | low |
| Kaukopartio (axis_minor) | $148 | smg men 365533 and SL 375533 have mgun/rifle 5, riflemen 333633 rifle 6 but mgun 3 | low: the riflemen have rifle 6, so it mostly fits role; only mgun 3 vs 5 is uneven [I] |
| Paracadutisti (axis_minor) | $311 | riflemen 335733 body_h250_s150; others body_veteran 200/150; mgun 7 on rifle and MG men | low: loose ladder, body swap may be meant |
| ssvts_41 / ssvts_44 (ger_ss) | $133 / $85 | sl and sl_asst rocket 2 with no rocket weapon; squad rocket 1 | low |
| volksgrens* (ger) | $110-134 | stg44, smg, sa men carry a panzerfaust ("0 1") with rocket 1; pzfst men rocket 2 | medium [I], depends on what "0 1" means |
| Panzergrenadier squads (ger) incl. stormtroopers_41/42/43 | $217-225 | grenadier_ober / ger_grenadier_ober_44 rocket 3, squad rocket 4; the 44 copy has a panzerfaust_60 | low-medium |
| riflemans / riflemans_at / riflemans2 (eng) | $163 / $184 / $17 | eng_rifleman_smoke (x4, x5, x1) uses a literal vet block 2/5/9/14/20, rest of the section vet_standard | yes, see VET-L |
| Guards squads (rus_guard) using guard_sl / guard_elite_guard_sl | $143-259 | SL 232323: rifle 3 and rocket 3 with only a PPSh; guards rifle 1, rocket 1 | low |
| ger2 rifle squads using ost_sl_asst | - | riflemen mgun 3, ost_sl_asst (432424) mgun 2 | very low |

## Veterancy

Rules from `breed/mp/robz_vet.inc` header lines 1-40 [D]:
- 5 ranks. A rank is reached when score >= its number. -1 = always reached, 0 = reached at once.
- A start-rank table should equal its base table minus the score of the start rank.
- Only the highest rank counts. w_skill per rank: lvl1 +1, lvl2 +1, lvl3 +2, lvl4 +2, lvl5 +3.

Base tables:
- vet_standard 24/60/108/168/240
- vet_elite 60/132/216/312/420
- vet_crew 600/900/1200/1500/1800

### VET-A: start-rank arithmetic (ranked, likely mistake first)

| table | file:line | has | base minus start | expected | users | verdict |
|---|---|---|---|---|---|---|
| vet_standard_start2 | `breed/mp/robz_vet.inc:34` | -1/0/48/120/192 | standard - 60 | -1/0/48/108/180 | 26 breeds | lvl3 right, lvl4/5 are 12 high: minus 48 was used for lvl4/5. Intended 108/180 [I] |
| vet_standard_start3 | `robz_vet.inc:49` | -1/-1/0/72/144 | standard - 108 | -1/-1/0/60/132 | 33 breeds | equals start2 minus 48, so it carries the same 12-point error. Intended 60/132 [I] |
| vet_crew_start3 | `robz_vet.inc:148` | outer -1/-1/0/96/204; mp -1/-1/0/180/360 | crew - 1200 | 300/600 | 2 breeds: rus_guard vehicle_supporter, vehicle_supporter_single | outer 96/204 = elite - 216 (an elite start3 line pasted in); mp 180/360 fits no base. Intended 300/600 [I]. Result: these 2 men reach lvl5 at 204 points vs 600 for crew |
| vet_ss_start1 | `breed/mp/ger_ss/veterancy_generic.inc:4` | 0/84/180/288/384 | elite - 60 | 0/72/156/252/360 | 7 breeds | lvl2-4 are vet_elite_start2's numbers moved down one rank; lvl5 384 is new. Intended elite - 60 [I]. Effect: ranks 2-5 come 12-36 points late |
| vet_ss_start3 | `ger_ss/veterancy_generic.inc:18` | -1/-1/0/108/180 | elite - 216 | 96/204 | 18 breeds | 108/180 = standard - 60, the correct start2 numbers. Either the author meant a standard base (then 60/132) or an elite base (96/204); it fits neither [I] |
| vet_elite_start2 | `robz_vet.inc` | -1/0/84/180/288 | elite - 132 | same | 18 breeds | correct |

Size of the effect [D]: 12 points is about one fifth of a lvl1-lvl2 step in vet_standard. Small in play, but it is a pattern error.
- Outline file:line for all 13 VET-A rows: see `robz-breed-outline.tsv` step `vet`.

### VET-L: literal veterancy blocks (likely mistake)

| breed | file:line | block | users | why it looks wrong |
|---|---|---|---|---|
| eng/eng_rifleman_smoke | `breed/mp/eng/eng_rifleman_smoke.set:16` | 2/5/9/14/20 | riflemans x4 ($163), riflemans_at x5 ($184), riflemans2 x1 ($17) | lvl5 at 20 points vs 240 in vet_standard, about 12x faster; every squad mate is on vet_standard. The set also uses drive_t08_v1_c1 |
| ger_ss/ss_at_miner | `breed/mp/ger_ss/ss_at_miner.set:16` | 2/5/9/14/20 | at_miners x4 ($150) | same block; the other SS engineers use breed_vet tables |

- Both look like an old explicit block left in when the rest moved to breed_vet [I].
- The eng rifle section is the most common eng squad. Its riflemen should reach lvl5 (w_skill +3) almost at once in play [I].
- Not checked in game. The rank effect values for lvl4/5 are in `set/ability/veterancy.set`.

### VET-O: vet_standard_old

- `breed/mp/robz_vet.inc` header line 31 and `breed/mp/axis_minor/veterancy_generic.inc:6`.
- Outer 48/96/288/576/960; mp block 24/60/108/168/240 (= vet_standard).
- No breed uses it [D]. Leftover, harmless.
- How outer and mp numbers combine when both exist is not verified (header says so too).

### VET-N: name says elite/vet/crew, table says standard

Checked against body tier, skills tier and $/man (infantry cards, not hero) [D from `perks/ladder.txt`].
Side means for comparison:
- jap standard: health 208, skill mean 2.30, $18.0/man. jap elite: 386, 6.23, $23.4.
- rus standard: 179, 2.35, $20.3. rus elite: 400, 7.0, $22.2.
- usa elite: 364, 5.61, $27.2.

| breeds | body | skills mean | $/man | verdict |
|---|---|---|---|---|
| jap elite_ig1, ig1b, ig2, ig3, ig4 (card elites_ig_42) | body_h300_s150 | 3.67-4.0 | $16.7 | mid tier between jap standard and elite. vet_standard is defensible; the name means Imperial Guard, not the elite table |
| jap elite_ig1h* , ig1_ammo, ig2_scoped, ig3b_type2, ig4_type2 | - | - | no infantry card (ig1h in hero_jap_guard $3) | leftovers |
| rus elite, elite2, elite2_40, elite3, elite3_40, elite_40, elite_mg_asst (cards elites_40 / elites_42) | body_veteran 200/150 | 3.17-3.33 | $15.1-18.7 | "veteran" squad on standard, fits the ladder. OK |
| usa usa_elite_grenadier, usa_elite_sgt (card elites(usa)) | 250/150, 300/150 | 4.17-4.33 | $24.0 | off the ladder: costs more per man than the Rangers ($22.4, vet_elite, body 350-400, skills 5.3) for less [I] |
| usa elite, elite3, elite3b, elite4_sgt, elite5, elite6, eliteb, elitec, elite_sgt | - | - | no card | leftovers |
| ger_ss elite_tankman, elite_tankman2 | crew | 7_5_6_4_1_6, 6_7_7_4_1_6; drive 1.2/1.2/1.05, 1.25/1.25/1.1 | no card | leftovers; crew name on vet_standard does not matter while unused |
| axis_minor axm_ita_vettankcommander, axm_ita_vettankman | crew | - | no card | leftovers |
| ger ger_sniper_vet, rus rus_vetsniper; ger_ss ss_vet_sniper | sniper | - | no card / hero_ss_sniper $1 | leftovers or hero |

Conclusion: the name check is mostly a false positive. One real outlier: the usa `elites` card.

## Do the tiers form one ladder?

Method: 818 infantry breeds that sit in a priced infantry card (no hero, no officer card).
- quality = health, skill mean, vet rank
- cost = card cost / men

Spearman rank correlation [D, `perks/ladder.js`]:

| pair | rho |
|---|---|
| health ~ skill mean | 0.64 |
| skill mean ~ $/man | 0.44 |
| health ~ $/man | 0.32 |
| vet rank ~ skill mean | 0.29 |
| vet rank ~ $/man | 0.27 |

Reading:
- Body and skills form a ladder (0.64) [D].
- Cost follows the weapon more than the man [D]: AT rifles, flamers, PIATs, bazooka teams, radiomen ($200-250/man) are weak men in expensive cards.
- Vet is the weak leg. ger2, ger_ss and rus_guard show elite status through start-rank tables, not skills [D]:
  - ger2 elite_start2: health 306, skills 5.61
  - ger_ss start5: health 213, skills 3.94
  - rus_guard standard_start3: health 203, skills 2.18
- Adding the start-rank w_skill (start2 +1, start3 +2, start5 +3) puts these sides back on the ladder [I].
- rus_guard elite guards are the exception: body 200, skills ~1.8-2.5, start5 (+3). Their effective skill (~5) is close to the others, but their base skills are the lowest of any "elite" card [D].

Furthest off the ladder [D, `perks/ladder.txt`]:

| direction | breeds | numbers |
|---|---|---|
| too good for cost | jap teishin type2rifle, teishin_mg (elites $254) | skills 6-7, body 400, $16.9/man |
| too good for cost | jap elite_takasago rifle2 / smg2 (elites_takasago $238) | skills 5, body 350/225, $15.9/man |
| too good for cost | usa_squadleader, usa_rifle_grenadier (riflemans*, $11.2/man) | body 200 / 150, skills 3.2 / 2.2 at the lowest $/man of any side |
| too dear for quality | radiomen (ger_radioman_mortar $250/man, usa radiomen) | body_regular, skills ~3 |
| too dear for quality | eng_bazooker(_assist) $40-61/man, axm_fin_at_rifle(assist) $33, axm_bul_at_rifle $50.5, eng/rus vet_tankman2_single $100 | weak body, skills 1.8-3.3 |
| body far above skills | axm_bul_radioman (300%), jap_kamikaze (300%, stamina 200%), jap chargers, snipers, rus_guard elite guards | health rank >> skill rank |
| skills far above body | Sissi smg / rifle, crew breeds, ss_panzerfaust, Scots (eng_rifle_scot 333525 on body_regular) | skill rank >> health rank |

The teishin and usa rifle cases are the clearest ladder breaks. The weapon-cost cases are design (the card prices the weapon) [I].

## What I could not check

- Nothing was run in game. All effects are from data and the robz_vet.inc header.
- The grenade/faust count form "0 1" (Volksgren panzerfausts): whether the man starts with the faust. The M2 Volksgren verdict depends on it.
- How outer and (mod "mp") veterancy numbers combine (vet_crew_start3, vet_standard_old).
- Whether the call-in flare gun (stuff/pistol) uses pistol skill (usa radioman pistol 6).
- Whether bar_rifle (stuff/rifle, tag assaultrifle) uses rifle or mgun skill. BAR men get mgun +1 in the data.
- `breeds.tsv` row usa_nightfighter_carbine is malformed (its vet column holds perk text). That breed was left out of the ladder.
- Card elites_ig names jap_kanoeshidan_type38rifle; the file is `jap_kanoeShidan_type38rifle.set` (case only). Fine if the game's file lookup ignores case [I].
- Year/history reasons (why a 1941 squad differs from its 1944 copy) were not checked against any source.

## Questions for the owner

1. ger_pzgren_smg_panzerfaust has smg 4 / rifle 5 with an MP40: swap to smg 5 / rifle 4 like the StG twin?
2. ss_pzgren_sl_stg rocket 5 with no rocket weapon: meant, or copy of a faust line?
3. axm_fin_sissi_mgun_vision skills 117312 vs plain 157612: should the hero copy match?
4. vet_standard_start2/start3 lvl4/5 are 12 points high: intended 108/180 and 60/132?
5. vet_ss_start1 and vet_ss_start3: what base did you mean, elite or standard?
6. vet_crew_start3 (2 rus_guard supporters) reaches lvl5 at 204: meant, or crew-based 300/600?
7. eng_rifleman_smoke and ss_at_miner literal vet 2/5/9/14/20: leftover, or on purpose?
8. jap_kanoeshidan_rifle_apminer 444546 vs IG 333535: meant as better men?
9. usa radiomen 105/240 pistol 6 vs 155 pistol 3: meant (better flare aim)?
10. British crew cannon 0.8 (others 0.9+): side flavour or mistake?
