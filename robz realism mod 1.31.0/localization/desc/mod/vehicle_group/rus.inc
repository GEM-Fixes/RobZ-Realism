; desc.lng mod part: desc/squad/* keys of cards that group several entities (vehicles with soldiers, copies of units), side rus
; mod part, buy-list order (units read order); above each key: [new|changed] card, cost, contents, tags, units file:line, notes
; -- button squad1, group squad_2 --
; [new] card "smgs_mot(rus)" cost 137 lvl 1 | soldiers rus_squadleader2_43, rus_smg2_43, rus_smg2 x8, 604 | vehicles zis5 | tags infantry all inf_only 43 44 45 | units/rus/squads_43-45.set:14
{"smgs_mot(rus)" "Motorized SMG Squad"}
; [new] card "riflemans_rifle_mot(rus)" cost 167 lvl 1 | soldiers rus_squadleader_smg, rus_smg, rus_rifle_sa, rus_rifle x6, rus_mgun, rus_mgun_asst, 607 | vehicles zis5 | tags infantry all inf_only 43 44 45 | units/rus/squads_43-45.set:33
{"riflemans_rifle_mot(rus)" "Motorized Rifle Squad"}
; -- button squad1, group squad_3 --
; [new] card "shock_assault_mech(rus)" cost 196 lvl 1 | soldiers rus_shock_sl_smg, rus_shock_smg x3, rus_shock_smg2 x2, rus_shock_smg3 x2, rus_shock_flame, 606 | vehicles m3 | tags infantry all inf_only 42 43 44 45 | units/rus/squads_43-45.set:39
{"shock_assault_mech(rus)" "Mechanized Shock SMG"}
; -- button squad1, group squad_55 --
; [new] card "paras_drop(rus)" cost 316 lvl 1 | soldiers rus_para_sl, rus_para_smg3 x2, rus_para_sa x2, rus_para_rifle x2, rus_para_mg x2, rus_para_mg_asst x2, 9007 | vehicles airborne_spawner | tags infantry all inf_only 44 45 only-one | units/rus/squads_43-45.set:52
{"paras_drop(rus)" "Paradropped Paratrooper squad"}
; -- button v2, group c3 --
; [new] card "maxim_1910_30_seq(rus)" cost 120 lvl 1 | soldiers vehicle_supporter x2 | vehicles maxim_1910_30 | tags all 44 45 | units/rus/vehicles_44-45.set:28 | copy of maxim_1910_30 (with crew)
{"maxim_1910_30_seq(rus)" "<c(FF5733)>Maxim 1910 HMG"}
; [new] card "maxim_1910_30_seqx2(rus)" cost 180 lvl 1 | soldiers vehicle_supporter x4 | vehicles maxim_1910_30 x2 | tags all 44 45 | units/rus/vehicles_44-45.set:29
{"maxim_1910_30_seqx2(rus)" "<c(00ff04)>2x Maxim 1910 HMG"}
; -- button v2, group c10 --
; [new] card "zis3_seq(rus)" cost 255 lvl 1 | soldiers vehicle_supporter x2 | vehicles zis3 | tags artillery all 44 45 | units/rus/vehicles_44-45.set:37 | copy of zis3 (with crew)
{"zis3_seq(rus)" "<c(FF5733)>ZiS-3"}
; [new] card "zis3_seqx2(rus)" cost 382 lvl 1 | soldiers vehicle_supporter x4 | vehicles zis3 x2 | tags artillery all 44 45 | units/rus/vehicles_44-45.set:38
{"zis3_seqx2(rus)" "<c(00ff04)>2x ZiS-3"}
; [new] card "zis3_towed" cost 352 lvl 1 | soldiers vehicle_supporter x4 | vehicles m3_rus, zis3 | tags artillery all 43 44 45 | units/rus/vehicles_44-45.set:39
{"zis3_towed" "ZiS 3 w/ M3"}
; -- button v2, group c11 --
; [new] card "zis2_towed" cost 422 lvl 1 | soldiers vehicle_supporter x4 | vehicles m3_rus, zis2 | tags all medium 44 45 | units/rus/vehicles_44-45.set:42
{"zis2_towed" "ZiS 2 w/ M3"}
; -- button v2, group c12 --
; [new] card "np_52k_43_towed" cost 550 lvl 1 | soldiers vehicle_supporter x4 | vehicles t34m, np_52k_43 | tags medium 43 44 45 | units/rus/vehicles_44-45.set:44
{"np_52k_43_towed" "52k w/ T34M"}
; -- button v2, group c13 --
; [new] card "bs3_towed" cost 875 lvl 1 | soldiers vehicle_supporter x4 | vehicles t34m, bs3 | tags all heavy 44 45 | units/rus/vehicles_44-45.set:45
{"bs3_towed" "BS3 w/ T34M"}
; -- button v22, group c7 --
; [new] card "bm_37_seq(rus)" cost 350 lvl 1 | soldiers vehicle_supporter x2 | vehicles bm_37 | tags all 44 45 mortar | units/rus/vehicles_44-45.set:54 | copy of bm_37 (with crew)
{"bm_37_seq(rus)" "<c(FF5733)>BM-37 82mm mortar"}
; [new] card "bm_37_seqx2(rus)" cost 525 lvl 1 | soldiers vehicle_supporter x4 | vehicles bm_37 x2 | tags all 44 45 mortar | units/rus/vehicles_44-45.set:55
{"bm_37_seqx2(rus)" "<c(00ff04)>2x BM-37 82mm mortar"}
; -- button v22, group c15 --
; [new] card "m30_1938_towed" cost 597 lvl 1 | soldiers vehicle_supporter x4 | vehicles m3_rus, m30_1938 | tags artillery 43 44 45 | units/rus/vehicles_44-45.set:60
{"m30_1938_towed" "M30 M1938 w/ M3"}
; -- button v22, group c16 --
; [new] card "d1_towed" cost 875 lvl 1 | soldiers vehicle_supporter x4 | vehicles t34m, d1 | tags artillery heavyart heavy 43 44 45 | units/rus/vehicles_44-45.set:62
{"d1_towed" "D1 w/ T34M"}
; -- button v22, group c22 --
; [new] card "np_ml20_towed" cost 1025 lvl 1 | soldiers vehicle_supporter x4 | vehicles t34m, np_ml20 | tags artillery heavyart heavy 43 44 45 | units/rus/vehicles_44-45.set:64
{"np_ml20_towed" "ML20 w/ T34M"}
; -- button v4, group e4 --
; [new] card "t34_2_seq(rus)" cost 350 lvl 1 | soldiers tankman x3, tankman2 | vehicles t34_2 | tags all medium 44 45 | units/rus/vehicles_44-45.set:92 | copy of t34_2 (with crew)
{"t34_2_seq(rus)" "<c(FF5733)>T-34-76 1943"}
; [new] card "t34_2_seqx2(rus)" cost 525 lvl 1 | soldiers tankman x6, tankman2 x2 | vehicles t34_2 x2 | tags all medium 44 45 | units/rus/vehicles_44-45.set:93
{"t34_2_seqx2(rus)" "<c(00ff04)>T-34-76 1943"}
; -- button v4, group e6 --
; [new] card "t34_3_seq(rus)" cost 625 lvl 1 | soldiers tankman x3, tankman2 | vehicles t34_3 | tags all medium 44 45 | units/rus/vehicles_44-45.set:99 | copy of t34_3 (with crew)
{"t34_3_seq(rus)" "<c(FF5733)>T-34-85 1944"}
; [new] card "t34_3_seqx2(rus)" cost 937 lvl 1 | soldiers tankman x6, tankman2 x2 | vehicles t34_3 x2 | tags all medium 44 45 | units/rus/vehicles_44-45.set:100
{"t34_3_seqx2(rus)" "<c(00ff04)>2x T-34-85 1944"}
