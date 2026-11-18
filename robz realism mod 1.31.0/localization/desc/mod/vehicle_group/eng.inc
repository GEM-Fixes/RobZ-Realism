; desc.lng mod part: desc/squad/* keys of cards that group several entities (vehicles with soldiers, copies of units), side eng
; mod part, buy-list order (units read order); above each key: [new|changed] card, cost, contents, tags, units file:line, notes
; -- button squad1, group squad_33 --
; [new] card "mech_rifles(eng)" cost 208 lvl 5 | soldiers eng_squadleader, eng_squadleader_asst, eng_rifleman_smoke x4, eng_rifle_grenadier, eng_mgun, eng_mgun_asst, eng_rifle_piat | vehicles m3_eng | tags infantry all inf_only 42 43 44 45 | units/eng/squads_42-45.set:15
{"mech_rifles(eng)" "Mechanized Rifle section"}
; -- button squad1, group squad_5 --
; [new] card "paratroopers_drop(eng)" cost 237 lvl 1 | soldiers eng_paratrooper_cpl_smg, eng_paratrooper_sic, eng_paratrooper_bren x3, eng_paratrooper_carbine x2, eng_paratrooper_smg x2, eng_paratrooper_lightmortar | vehicles airborne_spawner | tags infantry all inf_only 40 41 42 43 44 45 only-one | units/eng/squads_42-45.set:29
{"paratroopers_drop(eng)" "Paradropped Paratrooper section"}
; [new] card "stormtroopers_drop(eng)" cost 302 lvl 1 | soldiers eng_sas_cpl, eng_sas_2ic, eng_sas_bran_assist, eng_sas_at_rifle, eng_sas_bren2 x2, eng_sas_bren2_assist x2, eng_sas_rifle1 x2 | vehicles airborne_spawner | tags infantry all inf_only 43 44 45 41 42 only-one | units/eng/squads_42-45.set:31
{"stormtroopers_drop(eng)" "Paradropped SAS section"}
; -- button v1, group b4 --
; [new] card "universal_carrier_seq" cost 125 lvl 1 | soldiers vehicle_supporter x2 | vehicles universal_carrier | tags all 40 41 42 43 44 45 | units/eng/vehicles_43-44.set:8 | copy of universal_carrier (with crew)
{"universal_carrier_seq" "<c(FF5733)>Universal Carrier"}
; [new] card "universal_carrier_seqx2" cost 187 lvl 1 | soldiers vehicle_supporter x4 | vehicles universal_carrier x2 | tags all 40 41 42 43 44 45 | units/eng/vehicles_43-44.set:9
{"universal_carrier_seqx2" "<c(00ff04)>2x Universal Carrier"}
; -- button v2, group c11 --
; [new] card "qf17_towed" cost 685 lvl 1 | soldiers vehicle_supporter x4 | vehicles m3_eng, qf17 | tags all medium 44 45 | units/eng/vehicles_43-44.set:36
{"qf17_towed" "QF 17-pdr w/ M3"}
; -- button v2, group c12 --
; [new] card "3.7_towed" cost 700 lvl 1 | soldiers vehicle_supporter x4 | vehicles m4a3m, vickers | tags heavyaa all medium 43 44 45 | units/eng/vehicles_43-44.set:38
{"3.7_towed" "QF 3.7-Inch w/ M4A3M"}
; -- button v22, group c13 --
; [new] card "25-pdr_towed" cost 485 lvl 1 | soldiers vehicle_supporter x4 | vehicles m3_eng, pdr25 | tags all artillery 43 44 45 | units/eng/vehicles_43-44.set:49
{"25-pdr_towed" "QF 25-pdr w/ M3"}
; -- button v22, group c15 --
; [new] card "bl6_towed" cost 632 lvl 1 | soldiers vehicle_supporter x4 | vehicles m3_eng, bl6 | tags all artillery heavyart heavy 43 44 45 | units/eng/vehicles_43-44.set:51
{"bl6_towed" "BL 6\\26 cwt w/ M3"}
; -- button v22, group c14 --
; [new] card "bl45_towed" cost 725 lvl 1 | soldiers vehicle_supporter x4 | vehicles m4a3m, bl45 | tags all artillery 43 44 45 | units/eng/vehicles_43-44.set:52
{"bl45_towed" "BL 4.5-inch w/ M4A3M"}
; -- button v22, group c155 --
; [new] card "long_tom_towed_eng" cost 1175 lvl 1 | soldiers vehicle_supporter x4 | vehicles m4a3m, longtom_155mm | tags all artillery heavyart heavy 43 44 45 | units/eng/vehicles_43-44.set:53
{"long_tom_towed_eng" "155 mm Gun M1 'Long Tom' w/ M4A3M"}
; -- button v22, group c183 --
; [new] card "bl72_towed" cost 1275 lvl 1 | soldiers vehicle_supporter x4 | vehicles m4a3m, bl72 | tags all artillery heavyart heavy 44 45 | units/eng/vehicles_43-44.set:54
{"bl72_towed" "BL 7.2-inch w/ M4A3M"}
; -- button v22, group c19 --
; [new] card "land_mattress_towed" cost 735 lvl 1 | soldiers vehicle_supporter x4 | vehicles m3_eng, land_mattress | tags all artillery heavyart rocket 44 45 | units/eng/vehicles_43-44.set:59
{"land_mattress_towed" "Land Mattress w/ M3"}
; -- button v3, group d31 --
; [new] card "staghound_seq" cost 250 lvl 1 | soldiers tankman x3, tankman2 | vehicles staghound | tags all 42 43 44 45 | units/eng/vehicles_43-44.set:69 | copy of staghound (with crew)
{"staghound_seq" "<c(FF5733)>Staghound Mk.I"}
; [new] card "staghound_seqx2" cost 365 lvl 1 | soldiers tankman x6, tankman2 x2 | vehicles staghound x2 | tags all 42 43 44 45 | units/eng/vehicles_43-44.set:70
{"staghound_seqx2" "<c(00ff04)>2x Staghound Mk.I"}
; -- button v4, group e2 --
; [new] card "cromwell_mk_iv_seq" cost 342 lvl 1 | soldiers tankman x3, tankman2 | vehicles cromwell_mk_iv | tags all medium 44 45 | units/eng/vehicles_43-44.set:92 | copy of cromwell_mk_iv (with crew)
{"cromwell_mk_iv_seq" "<c(FF5733)>Cruiser Mk.VIII Cromwell IV"}
; [new] card "cromwell_mk_iv_seqx2" cost 513 lvl 1 | soldiers tankman x6, tankman2 x2 | vehicles cromwell_mk_iv x2 | tags all medium 44 45 | units/eng/vehicles_43-44.set:93
{"cromwell_mk_iv_seqx2" "<c(00ff04)>2x Cruiser Mk.VIII Cromwell IV"}
; [new] card "cromwell_mk_vii_seq" cost 430 lvl 1 | soldiers tankman x3, tankman2 | vehicles cromwell_mk_vii | tags all medium 44 45 | units/eng/vehicles_43-44.set:94 | copy of cromwell_mk_vii (with crew)
{"cromwell_mk_vii_seq" "<c(FF5733)>Cruiser Mk.VIII Cromwell VII"}
; [new] card "cromwell_mk_vii_seqx2" cost 645 lvl 1 | soldiers tankman x6, tankman2 x2 | vehicles cromwell_mk_vii x2 | tags all medium 44 45 | units/eng/vehicles_43-44.set:95
{"cromwell_mk_vii_seqx2" "<c(00ff04)>2x Cruiser Mk.VIII Cromwell VII"}
; -- button v22, group c155 --
; [new] card "long_tom(eng)" cost 1000 lvl 1 | soldiers vehicle_supporter x2 | vehicles longtom_155mm | tags all artillery heavyart heavy 43 44 45 | units/eng/vehicles_45.set:54 | renamed from "desc/squad/longtom_155mm(usmc)"; {info longtom_155mm}; also under usa/v22; cards long_tom(eng), longtom_155mm(usa); copy of longtom_155mm (with crew)
{"longtom_155mm" "Longtom 155m Howitzer"}
