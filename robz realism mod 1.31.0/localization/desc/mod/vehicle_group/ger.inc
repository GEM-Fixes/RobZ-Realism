; desc.lng mod part: desc/squad/* keys of cards that group several entities (vehicles with soldiers, copies of units), side ger
; mod part, buy-list order (units read order); above each key: [new|changed] card, cost, contents, tags, units file:line, notes
; -- button squad1, group squad_22 --
; [new] card "sturmgrens_44_mech(ger)" cost 223 lvl 1 | soldiers vehicle_supporter x2, ger_squadleader_sg44, ger_sturmgren_sl_asst, ger_sturmgren_sg44 x4, ger_sturmgren_sg44_pzfst x2 | vehicles np_sdkfz251_1_late | tags infantry all inf_only 44 45 | units/ger/squads_44.set:22
{"sturmgrens_44_mech(ger)" "Mechanized Sturmgrenadier squad"}
; -- button squad1, group squad_34 --
; [new] card "pzgren_mech(ger)" cost 276 lvl 1 | soldiers vehicle_supporter, ger_pzgren_sl, ger_pzgren2ic, ger_pzgren_stg_panzerfaust, ger_pzgren_g43, ger_pzgren_smg_panzerfaust, ger_pzgren_mg42 x2, ger_pzgren_mg42assist x2 | vehicles np_sdkfz251_1_late | tags infantry all inf_only 44 45 | units/ger/squads_44.set:50
{"pzgren_mech(ger)" "Mechanized Panzergrenadier squad"}
; -- button squad1, group squad_5 --
; [new] card "elites_44_drop(ger)" cost 423 lvl 1 | soldiers ger_fallschirm_sl, ger_fallschirm_sl_asst_fg_44, ger_fallschirm_sniper, ger_fallschirm_grenadier x2, ger_fallschirm_pzfst_stg, ger_fallschirm_mg x2, ger_fallschirm_mg_asst x2 | vehicles airborne_spawner | tags infantry all inf_only 44 45 only-one | units/ger/squads_44.set:81
{"elites_44_drop(ger)" "Paradropped Fallschirmjäger squad"}
; -- button v2, group c1 --
; [new] card "mg34_lafette_seq" cost 130 lvl 1 | soldiers vehicle_supporter x2 | vehicles mg34_lafette | tags 44 | units/ger/vehicles_44.set:25 | copy of mg34_lafette (with crew)
{"mg34_lafette_seq" "<c(FF5733)>MG34 lafette"}
; [new] card "mg34_lafette_seqx2" cost 195 lvl 1 | soldiers vehicle_supporter x4 | vehicles mg34_lafette x2 | tags 44 | units/ger/vehicles_44.set:26
{"mg34_lafette_seqx2" "<c(00ff04)>2x MG34 lafette"}
; -- button v2, group c2 --
; [new] card "mg42_lafette_seq" cost 150 lvl 1 | soldiers vehicle_supporter x2 | vehicles mg42_lafette | tags 44 | units/ger/vehicles_44.set:28 | copy of mg42_lafette (with crew)
{"mg42_lafette_seq" "<c(FF5733)>MG42 lafette"}
; [new] card "mg42_lafette_seqx2" cost 225 lvl 1 | soldiers vehicle_supporter x4 | vehicles mg42_lafette x2 | tags 44 | units/ger/vehicles_44.set:29
{"mg42_lafette_seqx2" "<c(00ff04)>2x MG42 lafette"}
; -- button v2, group c4 --
; [new] card "2cm_flakvierling38_towed" cost 325 lvl 1 | soldiers vehicle_supporter x4 | vehicles sdkfz251_1_late, 2cm_flakvierling38 | tags 44 | units/ger/vehicles_44.set:35
{"2cm_flakvierling38_towed" "2cm Flakvierling 38 w/ Sd.Kfz. 251"}
; -- button v2, group c5 --
; [new] card "37mm_flak_36_towed" cost 325 lvl 1 | soldiers vehicle_supporter x4 | vehicles sdkfz251_1_late, 37mm_flak_36 | tags 44 | units/ger/vehicles_44.set:38
{"37mm_flak_36_towed" "3.7cm Flak 36 w/ Sd.Kfz. 251"}
; -- button v2, group c10 --
; [new] card "np_pak40_seq" cost 400 lvl 1 | soldiers vehicle_supporter x2 | vehicles np_pak40 | tags medium 44 | units/ger/vehicles_44.set:42 | copy of np_pak40 (with crew)
{"np_pak40_seq" "<c(FF5733)>75mm PaK 40"}
; [new] card "np_pak40_seqx2" cost 600 lvl 1 | soldiers vehicle_supporter x4 | vehicles np_pak40 x2 | tags medium 44 | units/ger/vehicles_44.set:43
{"np_pak40_seqx2" "<c(00ff04)>2x 75mm PaK 40"}
; [new] card "np_pak40_towed" cost 475 lvl 1 | soldiers vehicle_supporter x4 | vehicles sdkfz251_1_late, np_pak40 | tags medium 44 | units/ger/vehicles_44.set:44
{"np_pak40_towed" "PaK 40 w/ Sd.Kfz. 251"}
; -- button v2, group c11 --
; [new] card "pak43_towed" cost 940 lvl 1 | soldiers vehicle_supporter x4 | vehicles np_sdkfz8, pak43 | tags heavy 44 | units/ger/vehicles_44.set:46
{"pak43_towed" "PaK 43 w/ Sd.Kfz. 8"}
; -- button v2, group c12 --
; [new] card "flak36a_towed" cost 700 lvl 1 | soldiers vehicle_supporter x4 | vehicles np_sdkfz8, flak36a | tags medium artillery 44 | units/ger/vehicles_44.set:48
{"flak36a_towed" "88mm FlaK 36 w/ Sd.Kfz. 8"}
; -- button v2, group c13 --
; [new] card "75mm_leig18_seq" cost 310 lvl 1 | soldiers vehicle_supporter x2 | vehicles 75mm_leig18 | tags artillery 44 | units/ger/vehicles_44.set:50 | copy of 75mm_leig18 (with crew)
{"75mm_leig18_seq" "<c(FF5733)>75mm LeIG 18"}
; [new] card "75mm_leig18_seq2" cost 210 lvl 1 | soldiers vehicle_supporter x2 | vehicles 75mm_leig18 | tags artillery 44 | units/ger/vehicles_44.set:51 | copy of 75mm_leig18 (with crew)
{"75mm_leig18_seq2" "<c(00ff04)>2x75mm LeIG 18"}
; -- button v2, group c133 --
; [new] card "15_cm_sig33_towed" cost 840 lvl 1 | soldiers vehicle_supporter x4 | vehicles np_sdkfz8, 15_cm_sig33 | tags artillery 44 | units/ger/vehicles_44.set:54
{"15_cm_sig33_towed" "15cm sIG 33 w/ Sd.Kfz. 8"}
; -- button v22, group cc2 --
; [new] card "lefh18_towed" cost 490 lvl 1 | soldiers vehicle_supporter x4 | vehicles np_sdkfz8, lefh18 | tags artillery 44 | units/ger/vehicles_44.set:70
{"lefh18_towed" "10.5 cm leFH 18 M w/ Sd.Kfz. 8"}
; -- button v22, group cc3 --
; [new] card "sfh18_towed" cost 750 lvl 1 | soldiers vehicle_supporter x4 | vehicles np_sdkfz8, sfh18 | tags artillery heavyart heavy 44 | units/ger/vehicles_44.set:72
{"sfh18_towed" "15 cm sFH 18 w/ Sd.Kfz. 8"}
; -- button v22, group cc4 --
; [new] card "morser18" cost 1240 lvl 1 | soldiers vehicle_supporter x4 | vehicles np_sdkfz8, morser18 | tags artillery heavyart heavy 44 | units/ger/vehicles_44.set:74 | card is "morser18" (bare name; engine looks up info/squad/morser18); also under ger_ss/v22; cards morser18, morser18(ger), morser18(ger_ss)
{"morser18(ger_ss)" "210mm Morser 18"}
; [new] card "morser18" cost 1240 lvl 1 | soldiers vehicle_supporter x4 | vehicles np_sdkfz8, morser18 | tags artillery heavyart heavy 44 | units/ger/vehicles_44.set:74 | also under ger_ss/v22; cards morser18, morser18(ger), morser18(ger_ss)
{"morser18" "21 cm Morser 18 w/ Sd.Kfz. 8"}
; -- button v22, group cc5 --
; [new] card "nebelwerfer41_towed" cost 525 lvl 1 | soldiers vehicle_supporter x4 | vehicles sdkfz251_1_late, nebelwerfer41 | tags artillery rocket 44 | units/ger/vehicles_44.set:81
{"nebelwerfer41_towed" "15 cm Nebelwerfer 41 w/ Sd.Kfz. 251"}
; -- button v22, group cc6 --
; [new] card "nebelwerfer42_towed" cost 1375 lvl 1 | soldiers vehicle_supporter x4 | vehicles sdkfz251_1_late, nebelwerfer42 | tags artillery heavyart rocket 44 | units/ger/vehicles_44.set:84
{"nebelwerfer42_towed" "28/32 cm Nebelwerfer 41 w/ Sd.Kfz. 251"}
; -- button v4, group e14 --
; [new] card "pz4h_seq" cost 500 lvl 1 | soldiers tankman x4, tankman2 | vehicles pz4h | tags all 44 45 medium | units/ger/vehicles_44.set:116 | copy of pz4h (with crew)
{"pz4h_seq" "<c(FF5733)>Pz IV Ausf. H"}
; [new] card "pz4h_seqx2" cost 400 lvl 1 | soldiers tankman x4, tankman2 | vehicles pz4h | tags all medium 44 45 | units/ger/vehicles_44.set:117 | copy of pz4h (with crew)
{"pz4h_seqx2" "<c(00ff04)> Pz IV Ausf. H"}
; -- button v5, group f6 --
; [new] card "stug3g_seq" cost 550 lvl 1 | soldiers tankman2, tankman x3 | vehicles stug3g | tags medium 44 | units/ger/vehicles_44.set:133 | copy of stug3g (with crew)
{"stug3g_seq" "<c(FF5733)>StuG III Ausf. G"}
; [new] card "stug3g_seqx2" cost 825 lvl 1 | soldiers tankman2 x2, tankman x6 | vehicles stug3g x2 | tags medium 44 | units/ger/vehicles_44.set:134
{"stug3g_seqx2" "<c(00ff04)>2x StuG III Ausf. G"}
; -- button squad1, group squad_5 --
; [new] card "elites_43_drop(ger)" cost 439 lvl 1 | soldiers fallschirm_sl_40, fallschirm_sl_asst_fg_43, fallschirm_sniper, fallschirm_fg_43, fallschirm_sa, fallschirm_grenadier x2, fallschirm_mg x2, fallschirm_mg_asst x2 | vehicles airborne_spawner | tags infantry 43 only-one | units/ger/squads_43.set:49
{"elites_43_drop(ger)" "Paradropped Fallschirmjäger squad"}
; [new] card "elites_42_drop(ger)" cost 437 lvl 1 | soldiers fallschirm_sl_40, fallschirm_sl_asst_fg_42, fallschirm_sniper, fallschirm_sa_41, fallschirm_rifle_39, fallschirm_grenadier x2, fallschirm_mg x2, fallschirm_mg_asst_39 x2 | vehicles airborne_spawner | tags infantry 42 only-one | units/ger/squads_42.set:45
{"elites_42_drop(ger)" "Paradropped Fallschirmjäger squad"}
; [new] card "elites_41_drop(ger)" cost 417 lvl 1 | soldiers fallschirm_sl_40, fallschirm_sl_asst_smg, fallschirm_sniper, fallschirm_sa_41, fallschirm_rifle_39 x3, fallschirm_mg_39 x2, fallschirm_mg_asst_39 x2 | vehicles airborne_spawner | tags infantry 41 only-one | units/ger/squads_41.set:42
{"elites_41_drop(ger)" "Paradropped Fallschirmjäger squad"}
