; desc.lng mod part: desc/squad/* keys of cards that group several entities (vehicles with soldiers, copies of units), side ger_ss
; mod part, buy-list order (units read order); above each key: [new|changed] card, cost, contents, tags, units file:line, notes
; -- button squad1, group squad_55 --
; [new] card "pzgren_mech(ger_ss)" cost 272 lvl 1 | soldiers vehicle_supporter x2, ss_pzgren_sl_stg, ss_pzgren_sl_asst_pzfst, ss_pzgren_stg, ss_pzgren_pzfst_sa, ss_pzgren_pzfst, ss_pzgren_mg x2, ss_pzgren_mg_asst x2 | vehicles np_sdkfz251_1_late | tags infantry all inf_only 44 45 | units/ger/squads_44.set:60
{"pzgren_mech(ger_ss)" "Mechanized Panzergrenadier squad"}
; -- button squad1, group squad_5 --
; [new] card "lssah_mech(ger_ss)" cost 391 lvl 1 | soldiers vehicle_supporter, ss_lssah_pzgren_sl_asst_sa, ss_lssah_pzgren_sl_stg, ss_lssah_pzgren_pzfst_stg, ss_lssah_pzgren_pzfst, ss_lssah_pzgren_pzfst60_sa, ss_lssah_pzgren_mg x2, ss_lssah_pzgren_mg_asst x2, ss_lssah_pzgren_at, ss_lssah_pzgren_at2 | vehicles np_sdkfz251_1_late | tags infantry all inf_only 44 45 | units/ger/squads_44.set:70
{"lssah_mech(ger_ss)" "Mechanized Elite SS-Panzergrenadier squad 'LSSAH'"}
; -- button squad1, group squad_6 --
; [new] card "elites_44_drop(ger_ss)" cost 296 lvl 1 | soldiers ss_fallschirm_sl, ss_fallschirm_sl_asst_smg, ss_fallschirm_smg x2, ss_fallschirm_rifle x4, ss_fallschirm_mg x2, ss_fallschirm_mg_asst x2, 9007 | vehicles airborne_spawner | tags infantry all inf_only 44 45 only-one | units/ger/squads_44.set:79
{"elites_44_drop(ger_ss)" "Paradropped SS-Fallschirmjäger squad"}
; -- button v2, group c1 --
; [new] card "zb53_stan_seq(ger_ss)" cost 130 lvl 1 | soldiers vehicle_supporter x2 | vehicles zb53_stan | tags all 39 40 41 42 43 44 45 | units/ger_ss/vehicles_44.set:25 | copy of zb53_stan (with crew)
{"zb53_stan_seq(ger_ss)" "<c(FF5733)>ZB 53 HMG"}
; [new] card "zb53_stan_seqx2(ger_ss)" cost 195 lvl 1 | soldiers vehicle_supporter x4 | vehicles zb53_stan x2 | tags all 39 40 41 42 43 44 45 | units/ger_ss/vehicles_44.set:26
{"zb53_stan_seqx2(ger_ss)" "<c(00ff04)>2x ZB 53 HMG"}
; -- button v2, group c2 --
; [new] card "mg42_lafette_ssx2(ger_ss)" cost 240 lvl 1 | soldiers vehicle_supporter x4 | vehicles mg42_lafette_ss x2 | tags all 42 43 44 45 | units/ger_ss/vehicles_44.set:29
{"mg42_lafette_ssx2(ger_ss)" "<c(00ff04)>2x MG42 lafette"}
; -- button v2, group c3 --
; [new] card "2cm_flak38_ss(ger_ss)" cost 200 lvl 1 | soldiers vehicle_supporter x2 | vehicles 2cm_flak38 | tags all 39 40 41 42 43 44 45 | units/ger_ss/vehicles_44.set:31 | copy of 2cm_flak38 (with crew)
{"2cm_flak38_ss(ger_ss)" "20mm FlaK 38"}
; -- button v2, group c4 --
; [new] card "2cm_flakvierling38_ss(ger_ss)" cost 250 lvl 1 | soldiers vehicle_supporter x4 | vehicles 2cm_flakvierling38 | tags all 39 40 41 42 43 44 45 | units/ger_ss/vehicles_44.set:32 | copy of 2cm_flakvierling38 (with crew)
{"2cm_flakvierling38_ss(ger_ss)" "20mm Flakvierling 38"}
; [new] card "2cm_flakvierling38_towed_ss" cost 325 lvl 1 | soldiers vehicle_supporter x4 | vehicles sdkfz251_1_late, 2cm_flakvierling38 | tags 44 | units/ger_ss/vehicles_44.set:33
{"2cm_flakvierling38_towed_ss" "2cm Flakvierling 38 w/ Sd.Kfz. 251"}
; -- button v2, group c5 --
; [new] card "37mm_flak_36_ss(ger_ss)" cost 250 lvl 1 | soldiers vehicle_supporter x2 | vehicles 37mm_flak_36 | tags all 39 40 41 42 43 44 45 | units/ger_ss/vehicles_44.set:34 | copy of 37mm_flak_36 (with crew)
{"37mm_flak_36_ss(ger_ss)" "37mm FlaK 36"}
; [new] card "37mm_flak_36_towed_ss" cost 325 lvl 1 | soldiers vehicle_supporter x4 | vehicles sdkfz251_1_late, 37mm_flak_36 | tags 44 | units/ger_ss/vehicles_44.set:35
{"37mm_flak_36_towed_ss" "3.7cm Flak 36 w/ Sd.Kfz. 251"}
; -- button v2, group c10 --
; [new] card "np_pak40_ssx2(ger_ss)" cost 600 lvl 1 | soldiers vehicle_supporter x4 | vehicles np_pak40 x2 | tags all 44 45 | units/ger_ss/vehicles_44.set:40
{"np_pak40_ssx2(ger_ss)" "<c(00ff04)>2x 75mm PaK 40"}
; [new] card "np_pak40_towed_ss" cost 475 lvl 1 | soldiers vehicle_supporter x4 | vehicles sdkfz251_1_late, np_pak40 | tags medium 44 | units/ger_ss/vehicles_44.set:41
{"np_pak40_towed_ss" "PaK 40 w/ d.Kfz. 251"}
; -- button v2, group c11 --
; [new] card "pak44_towed_ss" cost 1040 lvl 1 | soldiers vehicle_supporter x4 | vehicles np_sdkfz8, pak44 | tags artillery all heavy 44 45 | units/ger_ss/vehicles_44.set:43
{"pak44_towed_ss" "PaK 44 w/ Sd.Kfz. 8"}
; -- button v2, group c12 --
; [new] card "flak36a_towed_ss" cost 700 lvl 1 | soldiers vehicle_supporter x4 | vehicles np_sdkfz8, flak36a | tags artillery all medium 39 40 41 42 43 44 45 | units/ger_ss/vehicles_44.set:45
{"flak36a_towed_ss" "88mm FlaK 36 w/ Sd.Kfz. 8"}
; -- button v2, group c13 --
; [new] card "75mm_leig18_ss(ger_ss)" cost 310 lvl 1 | soldiers vehicle_supporter x2 | vehicles 75mm_leig18 | tags artillery all 40 41 42 43 44 45 | units/ger_ss/vehicles_44.set:47 | copy of 75mm_leig18 (with crew)
{"75mm_leig18_ss(ger_ss)" "75mm LeIG 18"}
; -- button v2, group c133 --
; [new] card "15_cm_sig33_ss(ger_ss)" cost 750 lvl 1 | soldiers vehicle_supporter x2 | vehicles 15_cm_sig33 | tags artillery all 39 40 41 42 43 44 45 | units/ger_ss/vehicles_44.set:49 | copy of 15_cm_sig33 (with crew)
{"15_cm_sig33_ss(ger_ss)" "150mm SIG 33"}
; [new] card "15_cm_sig33_towed_ss" cost 840 lvl 1 | soldiers vehicle_supporter x4 | vehicles np_sdkfz8, 15_cm_sig33 | tags artillery 44 | units/ger_ss/vehicles_44.set:50
{"15_cm_sig33_towed_ss" "15cm sIG 33 w/ Sd.Kfz. 8"}
; -- button v22, group cc1 --
; [new] card "flak18a_towed_ss" cost 790 lvl 1 | soldiers vehicle_supporter x4 | vehicles np_sdkfz8, flak18a | tags all artillery 39 40 41 42 43 44 45 | units/ger_ss/vehicles_44.set:63
{"flak18a_towed_ss" "88mm FlaK 18 w/ Sd.Kfz. 8"}
; -- button v22, group cc2 --
; [new] card "lefh18_ss(ger_ss)" cost 400 lvl 1 | soldiers vehicle_supporter x2 | vehicles lefh18 | tags artillery 44 | units/ger_ss/vehicles_44.set:65 | copy of lefh18 (with crew)
{"lefh18_ss(ger_ss)" "10.5 cm leFH 18 M"}
; [new] card "lefh18_towed_ss" cost 490 lvl 1 | soldiers vehicle_supporter x4 | vehicles np_sdkfz8, lefh18 | tags all artillery 39 40 41 42 43 44 45 | units/ger_ss/vehicles_44.set:66
{"lefh18_towed_ss" "10.5 cm leFH 18 M w/ Sd.Kfz. 8"}
; -- button v22, group cc3 --
; [new] card "sfh18_towed_ss" cost 750 lvl 1 | soldiers vehicle_supporter x4 | vehicles np_sdkfz8, sfh18 | tags all artillery heavyart heavy 39 40 41 42 43 44 45 | units/ger_ss/vehicles_44.set:68
{"sfh18_towed_ss" "15 cm sFH 18 w/ Sd.Kfz. 8"}
; -- button v22, group cc4 --
; [new] card "morser18_ss" cost 1240 lvl 1 | soldiers vehicle_supporter x4 | vehicles np_sdkfz8, morser18 | tags all artillery heavyart heavy 39 40 41 42 43 44 45 | units/ger_ss/vehicles_44.set:70
{"morser18_ss" "21 cm Morser 18 w/ Sd.Kfz. 8"}
; -- button v22, group cc5 --
; [new] card "nebelwerfer41_towed_ss" cost 525 lvl 1 | soldiers vehicle_supporter x4 | vehicles sdkfz251_1_late, nebelwerfer41 | tags artillery rocket 44 | units/ger_ss/vehicles_44.set:80
{"nebelwerfer41_towed_ss" "15 cm Nebelwerfer 41 w/ Sd.Kfz. 251"}
; -- button v22, group cc6 --
; [new] card "nebelwerfer42_towed_ss" cost 1375 lvl 1 | soldiers vehicle_supporter x4 | vehicles sdkfz251_1_late, nebelwerfer42 | tags artillery heavyart rocket 44 | units/ger_ss/vehicles_44.set:85
{"nebelwerfer42_towed_ss" "28/32 cm Nebelwerfer 41 w/ Sd.Kfz. 251"}
