; info.lng mod part: info/squad/* keys of cards that group several entities (vehicles with soldiers, copies of units), side ger
; mod part, buy-list order (units read order); above each key: [new|changed] card, cost, contents, tags, units file:line, notes
; -- button squad1, group squad_22 --
; [new] card "sturmgrens_44_mech(ger)" cost 223 lvl 1 | soldiers vehicle_supporter x2, ger_squadleader_sg44, ger_sturmgren_sl_asst, ger_sturmgren_sg44 x4, ger_sturmgren_sg44_pzfst x2 | vehicles np_sdkfz251_1_late | tags infantry all inf_only 44 45 | units/ger/squads_44.set:22
{"sturmgrens_44_mech(ger)" "Mechanized Sturmgrenadier assault squad of 8 in a SdKfz 251/1 halftrack that carries an MG42, an MG34 and extra infantry supplies."}
; -- button squad1, group squad_34 --
; [new] card "pzgren_mech(ger)" cost 276 lvl 1 | soldiers vehicle_supporter, ger_pzgren_sl, ger_pzgren2ic, ger_pzgren_stg_panzerfaust, ger_pzgren_g43, ger_pzgren_smg_panzerfaust, ger_pzgren_mg42 x2, ger_pzgren_mg42assist x2 | vehicles np_sdkfz251_1_late | tags infantry all inf_only 44 45 | units/ger/squads_44.set:50
{"pzgren_mech(ger)" "Mechanized Panzergrenadier squad of 9 in a SdKfz 251/1 halftrack that carries an MG42, an MG34 and extra infantry supplies."}
; -- button squad1, group squad_5 --
; [new] card "elites_44_drop(ger)" cost 423 lvl 1 | soldiers ger_fallschirm_sl, ger_fallschirm_sl_asst_fg_44, ger_fallschirm_sniper, ger_fallschirm_grenadier x2, ger_fallschirm_pzfst_stg, ger_fallschirm_mg x2, ger_fallschirm_mg_asst x2 | vehicles airborne_spawner | tags infantry all inf_only 44 45 only-one | units/ger/squads_44.set:81
{"elites_44_drop(ger)" "Elite 10-man Fallschirmjager squad dropped by parachute, with 2 MG42s, 2 FG42s, 3 K98s, a K98 sniper rifle, an StG44, an MP40 and 2 Panzerfausts."}
; -- button v22, group c6 --
; [new] card "sgrw_34_ger" cost 320 lvl 1 | soldiers vehicle_supporter x2 | vehicles sgrw_34 | tags all 39 40 41 42 43 44 45 mortar | units/ger/vehicles_44.set:64 | {info sgrw_34}; also under ger_ss/v22, ger_ss/v2, axis_minor/v2, ger/v2; cards sgrw_34_ger, sgrw_34_ss(ger_ss), sgrw_34; copy of sgrw_34 (with crew)
{"sgrw_34" "81mm mortar team for indirect fire with HE, smoke, WP and illumination rounds, resupplied from an infantry ammo crate. Screens pushes and breaks entrenched infantry; vulnerable if exposed."}
; -- button v22, group c7 --
; [new] card "sgrw_42_ger" cost 670 lvl 1 | soldiers vehicle_supporter x2 | vehicles sgrw_42 | tags all 42 43 44 45 mortar | units/ger/vehicles_44.set:65 | {info sgrw_42}; also under ger_ss/v22, ger_ss/v2, axis_minor/v2, ger/v2; cards sgrw_42_ger, sgrw_42_ss(ger_ss), sgrw_42; copy of sgrw_42 (with crew)
{"sgrw_42" "120mm heavy mortar with long reach for HE, smoke, WP and illumination fire, resupplied from a heavy artillery ammo crate. Anchors area denial and suppression; protect it from counter-fire."}
