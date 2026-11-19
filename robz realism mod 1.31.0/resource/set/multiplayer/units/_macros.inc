;SDL
; buy-list card macros (macrostd buylist): one card per call, one call per line in the units files

; unit_vehicle_supporters: buy card {"%name" ...} (was "vs" 405, "vs_rus41" 49, "vs_eng40" 25, "vs_ita" 6, "vs_bul" 5, "vs_rom" 2, "vs_fin" 1, "vs_hun" 1)
;   side - army side folder: ger, eng, rus, usa, jap, ger_ss, ger2, rus_guard, axis_minor
;   name - card name (the entity of the first vehicle, or the squad name)
;   breed - soldier breed of the crew
;   crew - number of crew soldiers
;   charge - recharge time after buying, s
;   tags - extra tags of the card (years 40..45, all, inf_only ...)
;   group - buy-menu group cell
;   button - buy-menu button (tab)
;   score - score value
;   weight - cw value
;   points - cp value
;   level - unlock level
;   cost - price, points
;   fore - fore value
;   e.g. ("unit_vehicle_supporters" side(axis_minor) name(as423) breed(axm_ita_vehicle_supporter) crew(4) charge(60) tags(all 42 43 44 45) group(b1) button(v1) score(120) weight(0) points(6) level(1) cost(120) fore(-2.0))
(define "unit_vehicle_supporters"
	{"%name"
		{charge %charge}
		{score %score}
		{tags "%tags %side"}
		{group "%group"}
		{button "%button"}
		{cw %weight}
		{cp %points}
		{content "* ( mp/%side/%breed:%crew )"}
		{level %level}
		{cost %cost}
		{fore %fore}
	}
)

; unit_tank: buy card {"%name" ...} (was "v" 361, "v_rus41" 31, "v_hun" 12, "v_vet" 11, "v_ita" 7, "v_rom" 3, "v_fin" 1, "vet_hun" 1)
;   side - army side folder: ger, eng, rus, usa, jap, ger_ss, ger2, rus_guard, axis_minor
;   name - card name (the entity of the first vehicle, or the squad name)
;   breed1 - soldier breed of crew 1
;   breed2 - soldier breed of crew 2
;   crew1 - number of crew 1 soldiers
;   crew2 - number of crew 2 soldiers
;   charge - recharge time after buying, s
;   tags - extra tags of the card (years 40..45, all, inf_only ...)
;   group - buy-menu group cell
;   button - buy-menu button (tab)
;   score - score value
;   weight - cw value
;   points - cp value
;   level - unlock level
;   cost - price, points
;   fore - fore value
;   e.g. ("unit_tank" side(axis_minor) name(m149) breed1(axm_ita_tankman) breed2(axm_ita_tankcommander) crew1(3) crew2(1) charge(60) tags(44 medium) group(c15) button(v2) score(1100) weight(0) points(17) level(1) cost(1100) fore(-20.0))
(define "unit_tank"
	{"%name"
		{charge %charge}
		{score %score}
		{tags "%tags %side"}
		{group "%group"}
		{button "%button"}
		{cw %weight}
		{cp %points}
		{content "* ( mp/%side/%breed1:%crew1 mp/%side/%breed2:%crew2)"}
		{level %level}
		{cost %cost}
		{fore %fore}
	}
)

; squad_1: buy card {"%name(%side)" ...} (was "squad_with1types" 240)
;   side - army side folder: ger, eng, rus, usa, jap, ger_ss, ger2, rus_guard, axis_minor
;   name - card name (the entity of the first vehicle, or the squad name)
;   member1 - squad member 1: breed:count
;   charge - recharge time after buying, s
;   tags - extra tags of the card (years 40..45, all, inf_only ...)
;   group - buy-menu group cell
;   button - buy-menu button (tab)
;   level - unlock level
;   cost - price, points
;   fore - fore value
;   e.g. ("squad_1" side(axis_minor) name(vet_tankcrew) member1(axm_rom_vet_tankcommander_single:1) charge(0) tags(all inf_only 44 45) group(squad_15) button(squad1) level(1) cost(100) fore(0.0))
(define "squad_1"
	{"%name(%side)"
		{charge %charge}
		{content "mp/%side/%member1"}
		{tags "frontline_cp infantry %side %tags"}
		{group "%group"}
		{button "%button"}
		{level %level}
		{cost %cost}
		{fore %fore}
	}
)

; squad_2: buy card {"%name(%side)" ...} (was "squad_with2types" 175)
;   side - army side folder: ger, eng, rus, usa, jap, ger_ss, ger2, rus_guard, axis_minor
;   name - card name (the entity of the first vehicle, or the squad name)
;   member1 - squad member 1: breed:count
;   member2 - squad member 2: breed:count
;   charge - recharge time after buying, s
;   tags - extra tags of the card (years 40..45, all, inf_only ...)
;   group - buy-menu group cell
;   button - buy-menu button (tab)
;   level - unlock level
;   cost - price, points
;   fore - fore value
;   e.g. ("squad_2" side(axis_minor) name(Bulgarian_Infantry) member1(axm_bul_squadleader:1) member2(axm_bul_rifle:7) charge(60) tags(all inf_only 44 45) group(squad_1) button(squad1) level(1) cost(75) fore(0.5))
(define "squad_2"
	{"%name(%side)"
		{charge %charge}
		{content "mp/%side/%member1 mp/%side/%member2"}
		{tags "frontline_cp infantry %side %tags"}
		{group "%group"}
		{button "%button"}
		{level %level}
		{cost %cost}
		{fore %fore}
	}
)

; unit_vehicle_supporters_info_sided: buy card {"%name(%side)" ...} (was "vs_ss" 139)
;   side - army side folder: ger, eng, rus, usa, jap, ger_ss, ger2, rus_guard, axis_minor
;   name - card name (the entity of the first vehicle, or the squad name)
;   vehicle1 - vehicle 1 entity
;   crew - number of crew soldiers
;   charge - recharge time after buying, s
;   tags - extra tags of the card (years 40..45, all, inf_only ...)
;   group - buy-menu group cell
;   button - buy-menu button (tab)
;   level - unlock level
;   cost - price, points
;   fore - fore value
;   e.g. ("unit_vehicle_supporters_info_sided" side(ger_ss) name(r12_34_ss) vehicle1(r12_34) crew(2) charge(0) tags(all 39 40 41 42 43 44 45) group(b1) button(v1) level(1) cost(115) fore(0.0))
(define "unit_vehicle_supporters_info_sided"
	{"%name(%side)"
		{charge %charge}
		{tags "%tags %side"}
		{group "%group"}
		{button "%button"}
		{content "%vehicle1 ( mp/%side/vehicle_supporter:%crew )"}
		{info %vehicle1}
		{level %level}
		{cost %cost}
		{fore %fore}
	}
)

; unit_vehicle_members_sided: buy card {"%name(%side)" ...} (was "v1" 92)
;   side - army side folder: ger, eng, rus, usa, jap, ger_ss, ger2, rus_guard, axis_minor
;   name - card name (the entity of the first vehicle, or the squad name)
;   vehicle1 - vehicle 1 entity
;   member1 - squad member 1: breed:count
;   member2 - squad member 2: breed:count
;   charge - recharge time after buying, s
;   tags - extra tags of the card (years 40..45, all, inf_only ...)
;   group - buy-menu group cell
;   button - buy-menu button (tab)
;   level - unlock level
;   cost - price, points
;   fore - fore value
;   e.g. ("unit_vehicle_members_sided" side(axis_minor) name(hero_vet_td) vehicle1(m9053_vet) member1(axm_ita_vettankman:3) member2(axm_ita_vettankcommander:1) charge(540) tags(all hero 44 45) group(h15) button(hero) level(1) cost(8.0) fore(-1.92))
(define "unit_vehicle_members_sided"
	{"%name(%side)"
		{charge %charge}
		{tags "%tags %side"}
		{group "%group"}
		{button "%button"}
		{content "%vehicle1 ( mp/%side/%member1 mp/%side/%member2 )"}
		{level %level}
		{cost %cost}
		{fore %fore}
	}
)

; unit_tank_info_sided: buy card {"%name(%side)" ...} (was "v_ss" 71)
;   side - army side folder: ger, eng, rus, usa, jap, ger_ss, ger2, rus_guard, axis_minor
;   name - card name (the entity of the first vehicle, or the squad name)
;   vehicle1 - vehicle 1 entity
;   crew1 - number of crew 1 soldiers
;   crew2 - number of crew 2 soldiers
;   charge - recharge time after buying, s
;   tags - extra tags of the card (years 40..45, all, inf_only ...)
;   group - buy-menu group cell
;   button - buy-menu button (tab)
;   level - unlock level
;   cost - price, points
;   fore - fore value
;   e.g. ("unit_tank_info_sided" side(ger_ss) name(pz1b_ss) vehicle1(pz1b) crew1(1) crew2(1) charge(10) tags(all 39 40 41 42 43 44 45) group(d7) button(v3) level(1) cost(195) fore(-31.0))
(define "unit_tank_info_sided"
	{"%name(%side)"
		{charge %charge}
		{tags "%tags %side"}
		{group "%group"}
		{button "%button"}
		{content "%vehicle1 ( mp/%side/tankman:%crew1 mp/%side/tankman2:%crew2 )"}
		{info %vehicle1}
		{level %level}
		{cost %cost}
		{fore %fore}
	}
)

; unit_howitzer_tractor: buy card {"%name" ...} (was "how" 68, "fin_how" 2)
;   side - army side folder: ger, eng, rus, usa, jap, ger_ss, ger2, rus_guard, axis_minor
;   name - card name (the entity of the first vehicle, or the squad name)
;   vehicle1 - vehicle 1 entity
;   vehicle2 - vehicle 2 entity
;   breed1 - soldier breed of crew 1
;   breed2 - soldier breed of crew 2
;   charge - recharge time after buying, s
;   tags - extra tags of the card (years 40..45, all, inf_only ...)
;   group - buy-menu group cell
;   button - buy-menu button (tab)
;   level - unlock level
;   cost - price, points
;   fore - fore value
;   e.g. ("unit_howitzer_tractor" side(axis_minor) name(flak36a_fin) vehicle1(t20) vehicle2(flak36a_fin) breed1(axm_fin_vehicle_supporter) breed2(axm_fin_vehicle_supporter) charge(60) tags(44) group(c90) button(v2) level(1) cost(700) fore(-17.0))
(define "unit_howitzer_tractor"
	{"%name"
		{charge %charge}
		{content "%vehicle1 ( mp/%side/%breed1:2 ) %vehicle2 ( mp/%side/%breed2:2 )"}
		{tags "%side %tags"}
		{group "%group"}
		{button "%button"}
		{level %level}
		{cost %cost}
		{fore %fore}
	}
)

; unit_howitzer: buy card {"%name(%side)" ...} (was "how_y" 69)
;   side - army side folder: ger, eng, rus, usa, jap, ger_ss, ger2, rus_guard, axis_minor
;   name - card name (the entity of the first vehicle, or the squad name)
;   vehicle2 - vehicle 2 entity
;   charge - recharge time after buying, s
;   tags - extra tags of the card (years 40..45, all, inf_only ...)
;   group - buy-menu group cell
;   button - buy-menu button (tab)
;   level - unlock level
;   cost - price, points
;   fore - fore value
;   e.g. ("unit_howitzer" side(eng) name(how_aa) vehicle2(vickers) charge(60) tags(heavyaa medium 40) group(c11) button(v2) level(1) cost(900) fore(-17.0))
(define "unit_howitzer"
	{"%name(%side)"
		{charge %charge}
		{content "%vehicle2 ( mp/%side/vehicle_supporter:2 )"}
		{tags "%side %tags"}
		{group "%group"}
		{button "%button"}
		{level %level}
		{cost %cost}
		{fore %fore}
		{info %vehicle2}
	}
)

; squad_6: buy card {"%name(%side)" ...} (was "squad_with6types" 44)
;   side - army side folder: ger, eng, rus, usa, jap, ger_ss, ger2, rus_guard, axis_minor
;   name - card name (the entity of the first vehicle, or the squad name)
;   member1 - squad member 1: breed:count
;   member2 - squad member 2: breed:count
;   member3 - squad member 3: breed:count
;   member4 - squad member 4: breed:count
;   member5 - squad member 5: breed:count
;   member6 - squad member 6: breed:count
;   charge - recharge time after buying, s
;   tags - extra tags of the card (years 40..45, all, inf_only ...)
;   group - buy-menu group cell
;   button - buy-menu button (tab)
;   level - unlock level
;   cost - price, points
;   fore - fore value
;   e.g. ("squad_6" side(axis_minor) name(fin_pioneer) member1(axm_fin_pio_squadleader:1) member2(axm_fin_pio_mgun:1) member3(axm_fin_pio_rifle_dynamite:1) member4(axm_fin_pio_smg:2) member5(axm_fin_pio_rifle:4) member6(axm_fin_pio_flamer:1) charge(90) tags(all inf_only 44 45) group(squad_3) button(squad1) level(1) cost(220) fore(1.0))
(define "squad_6"
	{"%name(%side)"
		{charge %charge}
		{content "mp/%side/%member1 mp/%side/%member2 mp/%side/%member3 mp/%side/%member4 mp/%side/%member5 mp/%side/%member6"}
		{tags "frontline_cp infantry %side %tags"}
		{group "%group"}
		{button "%button"}
		{level %level}
		{cost %cost}
		{fore %fore}
	}
)

; unit_tank_info: buy card {"%name" ...} (was "v_ss" 38)
;   side - army side folder: ger, eng, rus, usa, jap, ger_ss, ger2, rus_guard, axis_minor
;   name - card name (the entity of the first vehicle, or the squad name)
;   vehicle1 - vehicle 1 entity
;   crew1 - number of crew 1 soldiers
;   crew2 - number of crew 2 soldiers
;   charge - recharge time after buying, s
;   tags - extra tags of the card (years 40..45, all, inf_only ...)
;   group - buy-menu group cell
;   button - buy-menu button (tab)
;   level - unlock level
;   cost - price, points
;   fore - fore value
;   e.g. ("unit_tank_info" side(ger2) name(pz2l_ger2) vehicle1(pz2l) crew1(2) crew2(1) charge(10) tags(all 43 44 45) group(d12) button(v3) level(1) cost(220) fore(-41.0))
(define "unit_tank_info"
	{"%name"
		{charge %charge}
		{tags "%tags %side"}
		{group "%group"}
		{button "%button"}
		{content "%vehicle1 ( mp/%side/tankman:%crew1 mp/%side/tankman2:%crew2 )"}
		{info %vehicle1}
		{level %level}
		{cost %cost}
		{fore %fore}
	}
)

; unit_two_vehicles_members_sided: buy card {"%name(%side)" ...} (was "v2" 30)
;   side - army side folder: ger, eng, rus, usa, jap, ger_ss, ger2, rus_guard, axis_minor
;   name - card name (the entity of the first vehicle, or the squad name)
;   vehicle1 - vehicle 1 entity
;   member1 - squad member 1: breed:count
;   member2 - squad member 2: breed:count
;   charge - recharge time after buying, s
;   tags - extra tags of the card (years 40..45, all, inf_only ...)
;   group - buy-menu group cell
;   button - buy-menu button (tab)
;   level - unlock level
;   cost - price, points
;   fore - fore value
;   e.g. ("unit_two_vehicles_members_sided" side(eng) name(hero7) vehicle1(pdr25_vet) member1(vehicle_supporter:2) member2(tankman2:0) charge(720) tags(hero artillery 40) group(h6) button(hero) level(1) cost(9.0) fore(-0.5))
(define "unit_two_vehicles_members_sided"
	{"%name(%side)"
		{charge %charge}
		{tags "%tags %side"}
		{group "%group"}
		{button "%button"}
		{content "%vehicle1 ( mp/%side/%member1 mp/%side/%member2 ) %vehicle1 ( mp/%side/%member1 mp/%side/%member2 )"}
		{level %level}
		{cost %cost}
		{fore %fore}
	}
)

; squad_5: buy card {"%name(%side)" ...} (was "squad_with5types" 28)
;   side - army side folder: ger, eng, rus, usa, jap, ger_ss, ger2, rus_guard, axis_minor
;   name - card name (the entity of the first vehicle, or the squad name)
;   member1 - squad member 1: breed:count
;   member2 - squad member 2: breed:count
;   member3 - squad member 3: breed:count
;   member4 - squad member 4: breed:count
;   member5 - squad member 5: breed:count
;   charge - recharge time after buying, s
;   tags - extra tags of the card (years 40..45, all, inf_only ...)
;   group - buy-menu group cell
;   button - buy-menu button (tab)
;   level - unlock level
;   cost - price, points
;   fore - fore value
;   e.g. ("squad_5" side(axis_minor) name(fin_kaukopartio) member1(axm_fin_kaukopartio_squadleader:1) member2(axm_fin_kaukopartio_mgun:1) member3(axm_fin_kaukopartio_mgun_assist:1) member4(axm_fin_kaukopartio_smg:2) member5(axm_fin_kaukopartio_rifle:4) charge(60) tags(all inf_only 44 45) group(squad_5) button(squad1) level(1) cost(148) fore(1.0))
(define "squad_5"
	{"%name(%side)"
		{charge %charge}
		{content "mp/%side/%member1 mp/%side/%member2 mp/%side/%member3 mp/%side/%member4 mp/%side/%member5"}
		{tags "frontline_cp infantry %side %tags"}
		{group "%group"}
		{button "%button"}
		{level %level}
		{cost %cost}
		{fore %fore}
	}
)

; squad_7: buy card {"%name(%side)" ...} (was "squad_with7types" 26)
;   side - army side folder: ger, eng, rus, usa, jap, ger_ss, ger2, rus_guard, axis_minor
;   name - card name (the entity of the first vehicle, or the squad name)
;   member1 - squad member 1: breed:count
;   member2 - squad member 2: breed:count
;   member3 - squad member 3: breed:count
;   member4 - squad member 4: breed:count
;   member5 - squad member 5: breed:count
;   member6 - squad member 6: breed:count
;   member7 - squad member 7: breed:count
;   charge - recharge time after buying, s
;   tags - extra tags of the card (years 40..45, all, inf_only ...)
;   group - buy-menu group cell
;   button - buy-menu button (tab)
;   level - unlock level
;   cost - price, points
;   fore - fore value
;   e.g. ("squad_7" side(axis_minor) name(Hungarian_Assualt_Infantry) member1(axm_hun_assualt_squadleader:1) member2(axm_hun_assualt_rifle:2) member3(axm_hun_assualt_smg:4) member4(axm_hun_assualt_mgun:1) member5(axm_hun_assualt_mgun_assist:1) member6(axm_hun_assualt_pzf:1) member7(axm_hun_assualt_flamer:1) charge(60) tags(all inf_only 44 45) group(squad_8) button(squad1) level(1) cost(186) fore(1.0))
(define "squad_7"
	{"%name(%side)"
		{charge %charge}
		{content "mp/%side/%member1 mp/%side/%member2 mp/%side/%member3 mp/%side/%member4 mp/%side/%member5 mp/%side/%member6 mp/%side/%member7"}
		{tags "frontline_cp infantry %side %tags"}
		{group "%group"}
		{button "%button"}
		{level %level}
		{cost %cost}
		{fore %fore}
	}
)

; unit_vehicle_supporters_noinfo_sided: buy card {"%name(%side)" ...} (was "vs_ss_noinfo" 26)
;   side - army side folder: ger, eng, rus, usa, jap, ger_ss, ger2, rus_guard, axis_minor
;   name - card name (the entity of the first vehicle, or the squad name)
;   vehicle1 - vehicle 1 entity
;   crew - number of crew soldiers
;   charge - recharge time after buying, s
;   tags - extra tags of the card (years 40..45, all, inf_only ...)
;   group - buy-menu group cell
;   button - buy-menu button (tab)
;   level - unlock level
;   cost - price, points
;   fore - fore value
;   e.g. ("unit_vehicle_supporters_noinfo_sided" side(ger_ss) name(2cm_flak38_ss) vehicle1(2cm_flak38) crew(2) charge(30) tags(all 39 40 41 42 43 44 45) group(c3) button(v2) level(1) cost(200) fore(-4.0))
(define "unit_vehicle_supporters_noinfo_sided"
	{"%name(%side)"
		{charge %charge}
		{tags "%tags %side"}
		{group "%group"}
		{button "%button"}
		{content "%vehicle1 ( mp/%side/vehicle_supporter:%crew )"}
		{level %level}
		{cost %cost}
		{fore %fore}
	}
)

; squad_3: buy card {"%name(%side)" ...} (was "squad_with3types" 22)
;   side - army side folder: ger, eng, rus, usa, jap, ger_ss, ger2, rus_guard, axis_minor
;   name - card name (the entity of the first vehicle, or the squad name)
;   member1 - squad member 1: breed:count
;   member2 - squad member 2: breed:count
;   member3 - squad member 3: breed:count
;   charge - recharge time after buying, s
;   tags - extra tags of the card (years 40..45, all, inf_only ...)
;   group - buy-menu group cell
;   button - buy-menu button (tab)
;   level - unlock level
;   cost - price, points
;   fore - fore value
;   e.g. ("squad_3" side(axis_minor) name(hungarian_smg_squad) member1(axm_hun_squadleader_smg:1) member2(axm_hun_smg_ppsh:4) member3(axm_hun_smg_danuvia:4) charge(30) tags(all inf_only 44 45) group(squad_2) button(squad1) level(1) cost(84) fore(1.0))
(define "squad_3"
	{"%name(%side)"
		{charge %charge}
		{content "mp/%side/%member1 mp/%side/%member2 mp/%side/%member3"}
		{tags "frontline_cp infantry %side %tags"}
		{group "%group"}
		{button "%button"}
		{level %level}
		{cost %cost}
		{fore %fore}
	}
)

; squad_4: buy card {"%name(%side)" ...} (was "squad_with4types" 21)
;   side - army side folder: ger, eng, rus, usa, jap, ger_ss, ger2, rus_guard, axis_minor
;   name - card name (the entity of the first vehicle, or the squad name)
;   member1 - squad member 1: breed:count
;   member2 - squad member 2: breed:count
;   member3 - squad member 3: breed:count
;   member4 - squad member 4: breed:count
;   charge - recharge time after buying, s
;   tags - extra tags of the card (years 40..45, all, inf_only ...)
;   group - buy-menu group cell
;   button - buy-menu button (tab)
;   level - unlock level
;   cost - price, points
;   fore - fore value
;   e.g. ("squad_4" side(axis_minor) name(romanian_rifle_squad) member1(axm_rom_rifle:7) member2(axm_rom_squadleader:1) member3(axm_rom_mgun:1) member4(axm_rom_mgunassist:1) charge(30) tags(all inf_only 44 45) group(squad_4) button(squad1) level(1) cost(114) fore(1.0))
(define "squad_4"
	{"%name(%side)"
		{charge %charge}
		{content "mp/%side/%member1 mp/%side/%member2 mp/%side/%member3 mp/%side/%member4"}
		{tags "frontline_cp infantry %side %tags"}
		{group "%group"}
		{button "%button"}
		{level %level}
		{cost %cost}
		{fore %fore}
	}
)

; squad_8: buy card {"%name(%side)" ...} (was "squad_with8types" 20)
;   side - army side folder: ger, eng, rus, usa, jap, ger_ss, ger2, rus_guard, axis_minor
;   name - card name (the entity of the first vehicle, or the squad name)
;   member1 - squad member 1: breed:count
;   member2 - squad member 2: breed:count
;   member3 - squad member 3: breed:count
;   member4 - squad member 4: breed:count
;   member5 - squad member 5: breed:count
;   member6 - squad member 6: breed:count
;   member7 - squad member 7: breed:count
;   member8 - squad member 8: breed:count
;   charge - recharge time after buying, s
;   tags - extra tags of the card (years 40..45, all, inf_only ...)
;   group - buy-menu group cell
;   button - buy-menu button (tab)
;   level - unlock level
;   cost - price, points
;   fore - fore value
;   e.g. ("squad_8" side(ger) name(elites_42) member1(fallschirm_sl_40:1) member2(fallschirm_sl_asst_fg_42:1) member3(fallschirm_sniper:1) member4(fallschirm_sa_41:1) member5(fallschirm_rifle_39:1) member6(fallschirm_grenadier:2) member7(fallschirm_mg:2) member8(fallschirm_mg_asst_39:2) charge(360) tags(42) group(squad_5) button(squad1) level(1) cost(337) fore(1.0))
(define "squad_8"
	{"%name(%side)"
		{charge %charge}
		{content "mp/%side/%member1 mp/%side/%member2 mp/%side/%member3 mp/%side/%member4 mp/%side/%member5 mp/%side/%member6 mp/%side/%member7 mp/%side/%member8"}
		{tags "frontline_cp infantry %side %tags"}
		{group "%group"}
		{button "%button"}
		{level %level}
		{cost %cost}
		{fore %fore}
	}
)

; unit_vehicle_supporters_guard_sided: buy card {"%name(%side)" ...} (was "vs_rus_g" 19)
;   side - army side folder: ger, eng, rus, usa, jap, ger_ss, ger2, rus_guard, axis_minor
;   name - card name (the entity of the first vehicle, or the squad name)
;   vehicle1 - vehicle 1 entity
;   crew - number of crew soldiers
;   charge - recharge time after buying, s
;   tags - extra tags of the card (years 40..45, all, inf_only ...)
;   group - buy-menu group cell
;   button - buy-menu button (tab)
;   level - unlock level
;   cost - price, points
;   fore - fore value
;   e.g. ("unit_vehicle_supporters_guard_sided" side(rus_guard) name(m72_guard) vehicle1(m72) crew(2) charge(0) tags(all 43 44 45) group(b1) button(v1) level(1) cost(105) fore(0.0))
(define "unit_vehicle_supporters_guard_sided"
	{"%name(%side)"
		{charge %charge}
		{tags "%tags %side"}
		{group "%group"}
		{button "%button"}
		{content "%vehicle1 ( mp/rus_guard/vehicle_supporter:%crew )"}
		{info %vehicle1}
		{level %level}
		{cost %cost}
		{fore %fore}
	}
)

; unit_vehicle_supporters_info: buy card {"%name" ...} (was "vs_ss" 16, "vs_ger_m" 2)
;   side - army side folder: ger, eng, rus, usa, jap, ger_ss, ger2, rus_guard, axis_minor
;   name - card name (the entity of the first vehicle, or the squad name)
;   vehicle1 - vehicle 1 entity
;   crew - number of crew soldiers
;   charge - recharge time after buying, s
;   tags - extra tags of the card (years 40..45, all, inf_only ...)
;   group - buy-menu group cell
;   button - buy-menu button (tab)
;   level - unlock level
;   cost - price, points
;   fore - fore value
;   e.g. ("unit_vehicle_supporters_info" side(ger) name(sgrw_34_ger) vehicle1(sgrw_34) crew(2) charge(10) tags(all 39 40 41 42 43 44 45 mortar) group(c6) button(v22) level(1) cost(320) fore(-2.0))
(define "unit_vehicle_supporters_info"
	{"%name"
		{charge %charge}
		{tags "%tags %side"}
		{group "%group"}
		{button "%button"}
		{content "%vehicle1 ( mp/%side/vehicle_supporter:%crew )"}
		{info %vehicle1}
		{level %level}
		{cost %cost}
		{fore %fore}
	}
)

; squad_1_x4_sequence: buy card {"%name(%side)" ...} (was "i_seq_with1x4types" 18)
;   side - army side folder: ger, eng, rus, usa, jap, ger_ss, ger2, rus_guard, axis_minor
;   name - card name (the entity of the first vehicle, or the squad name)
;   member1 - squad member 1: breed:count
;   charge - recharge time after buying, s
;   tags - extra tags of the card (years 40..45, all, inf_only ...)
;   group - buy-menu group cell
;   button - buy-menu button (tab)
;   icon - icon index
;   level - unlock level
;   cost - price, points
;   fore - fore value
;   e.g. ("squad_1_x4_sequence" side(axis_minor) name(officer) member1(axm_fin_officer:1) charge(1) tags(all officer inf_only 39 40 41 42 43 44 45) group(squad_16) button(squad2) icon(10002) level(1) cost(0) fore(-599.0))
(define "squad_1_x4_sequence"
	{"%name(%side)"
		{charge %charge}
		{content "mp/%side/%member1 mp/%side/%member1 mp/%side/%member1 mp/%side/%member1"}
		{tags "frontline_cp infantry %side %tags"}
		{group "%group"}
		{button "%button"}
		{level %level}
		{cost %cost}
		{fore %fore}
		{icon %icon}
	}
)

; unit_vehicle_supporters_sequence_sided: buy card {"%name(%side)" ...} (was "vs_seq" 13)
;   side - army side folder: ger, eng, rus, usa, jap, ger_ss, ger2, rus_guard, axis_minor
;   name - card name (the entity of the first vehicle, or the squad name)
;   vehicle1 - vehicle 1 entity
;   crew - number of crew soldiers
;   charge - recharge time after buying, s
;   tags - extra tags of the card (years 40..45, all, inf_only ...)
;   group - buy-menu group cell
;   button - buy-menu button (tab)
;   icon - icon index
;   score - score value
;   weight - cw value
;   points - cp value
;   level - unlock level
;   cost - price, points
;   fore - fore value
;   e.g. ("unit_vehicle_supporters_sequence_sided" side(eng) name(universal_carrier_seq) vehicle1(universal_carrier) crew(2) charge(10) tags(all 40 41 42 43 44 45) group(b4) button(v1) icon(4) score(125) weight(0) points(2.5) level(1) cost(125) fore(-17.0))
(define "unit_vehicle_supporters_sequence_sided"
	{"%name(%side)"
		{charge %charge}
		{score %score}
		{tags "%tags %side"}
		{group "%group"}
		{button "%button"}
		{icon %icon}
		{cw %weight}
		{cp %points}
		{content "%vehicle1 ( mp/%side/vehicle_supporter:%crew )"}
		{level %level}
		{cost %cost}
		{fore %fore}
	}
)

; unit_vehicle_pair_sided: buy card {"%name(%side)" ...} (was "2v" 13)
;   side - army side folder: ger, eng, rus, usa, jap, ger_ss, ger2, rus_guard, axis_minor
;   name - card name (the entity of the first vehicle, or the squad name)
;   vehicle1 - vehicle 1 entity
;   vehicle2 - vehicle 2 entity
;   member1 - squad member 1: breed:count
;   member2 - squad member 2: breed:count
;   charge - recharge time after buying, s
;   tags - extra tags of the card (years 40..45, all, inf_only ...)
;   group - buy-menu group cell
;   button - buy-menu button (tab)
;   level - unlock level
;   cost - price, points
;   fore - fore value
;   e.g. ("unit_vehicle_pair_sided" side(eng) name(hero7) vehicle1(m3_eng) vehicle2(pdr25_vet) member1(vehicle_supporter:2) member2(vehicle_supporter:2) charge(720) tags(all hero artillery 40 41 42 43 44 45) group(h6) button(hero) level(1) cost(3.0) fore(-0.5))
(define "unit_vehicle_pair_sided"
	{"%name(%side)"
		{charge %charge}
		{tags "%tags %side"}
		{group "%group"}
		{button "%button"}
		{content "%vehicle1 ( mp/%side/%member1 ) %vehicle2 ( mp/%side/%member2 )"}
		{level %level}
		{cost %cost}
		{fore %fore}
	}
)

; unit_tank_commander_first: buy card {"%name" ...} (was "v_com" 9, "v_vet_com" 3)
;   side - army side folder: ger, eng, rus, usa, jap, ger_ss, ger2, rus_guard, axis_minor
;   name - card name (the entity of the first vehicle, or the squad name)
;   breed1 - soldier breed of crew 1
;   breed2 - soldier breed of crew 2
;   crew1 - number of crew 1 soldiers
;   crew2 - number of crew 2 soldiers
;   charge - recharge time after buying, s
;   tags - extra tags of the card (years 40..45, all, inf_only ...)
;   group - buy-menu group cell
;   button - buy-menu button (tab)
;   score - score value
;   weight - cw value
;   points - cp value
;   level - unlock level
;   cost - price, points
;   fore - fore value
;   e.g. ("unit_tank_commander_first" side(ger) name(sig33b) breed1(tankman2) breed2(tankman) crew1(4) crew2(1) charge(10) tags(medium 42) group(c17) button(v2) score(725) weight(0) points(20) level(1) cost(725) fore(-69.0))
(define "unit_tank_commander_first"
	{"%name"
		{charge %charge}
		{score %score}
		{tags "%tags %side"}
		{group "%group"}
		{button "%button"}
		{cw %weight}
		{cp %points}
		{content "* ( mp/%side/%breed1:%crew2 mp/%side/%breed2:%crew1)"}
		{level %level}
		{cost %cost}
		{fore %fore}
	}
)

; unit_vehicles_supporters_sequence_sided: buy card {"%name(%side)" ...} (was "vs2_seq" 11)
;   side - army side folder: ger, eng, rus, usa, jap, ger_ss, ger2, rus_guard, axis_minor
;   name - card name (the entity of the first vehicle, or the squad name)
;   vehicle1 - vehicle 1 entity
;   vehicle2 - vehicle 2 entity
;   crew - number of crew soldiers
;   charge - recharge time after buying, s
;   tags - extra tags of the card (years 40..45, all, inf_only ...)
;   group - buy-menu group cell
;   button - buy-menu button (tab)
;   icon - icon index
;   score - score value
;   weight - cw value
;   points - cp value
;   level - unlock level
;   cost - price, points
;   fore - fore value
;   e.g. ("unit_vehicles_supporters_sequence_sided" side(eng) name(universal_carrier_seqx2) vehicle1(universal_carrier) vehicle2(universal_carrier) crew(2) charge(10) tags(all 40 41 42 43 44 45) group(b4) button(v1) icon(4) score(187) weight(0) points(2.5) level(1) cost(187) fore(-17.0))
(define "unit_vehicles_supporters_sequence_sided"
	{"%name(%side)"
		{charge %charge}
		{score %score}
		{tags "%tags %side"}
		{group "%group"}
		{button "%button"}
		{icon %icon}
		{cw %weight}
		{cp %points}
		{content "%vehicle1 ( mp/%side/vehicle_supporter:%crew ) %vehicle2 ( mp/%side/vehicle_supporter:%crew )"}
		{level %level}
		{cost %cost}
		{fore %fore}
	}
)

; unit_tank_sequence: buy card {"%name" ...} (was "v_seq" 6, "v2_seq_ita" 2, "v_seq_ita" 2)
;   side - army side folder: ger, eng, rus, usa, jap, ger_ss, ger2, rus_guard, axis_minor
;   name - card name (the entity of the first vehicle, or the squad name)
;   vehicle1 - vehicle 1 entity
;   breed1 - soldier breed of crew 1
;   breed2 - soldier breed of crew 2
;   crew1 - number of crew 1 soldiers
;   crew2 - number of crew 2 soldiers
;   charge - recharge time after buying, s
;   tags - extra tags of the card (years 40..45, all, inf_only ...)
;   group - buy-menu group cell
;   button - buy-menu button (tab)
;   icon - icon index
;   score - score value
;   weight - cw value
;   points - cp value
;   level - unlock level
;   cost - price, points
;   fore - fore value
;   e.g. ("unit_tank_sequence" side(axis_minor) name(m1139_seq) vehicle1(m1139) breed1(axm_ita_tankman) breed2(axm_ita_tankCommander) crew1(2) crew2(1) charge(10) tags(44 medium) group(e1) button(v4) icon(4) score(260) weight(0) points(10) level(1) cost(260) fore(-48.0))
(define "unit_tank_sequence"
	{"%name"
		{charge %charge}
		{score %score}
		{tags "%tags %side"}
		{group "%group"}
		{button "%button"}
		{icon %icon}
		{cw %weight}
		{cp %points}
		{content "%vehicle1 ( mp/%side/%breed1:%crew1 mp/%side/%breed2:%crew2)"}
		{level %level}
		{cost %cost}
		{fore %fore}
	}
)

; squad_6_sequence: buy card {"%name(%side)" ...} (was "i_seq_with6types" 10)
;   side - army side folder: ger, eng, rus, usa, jap, ger_ss, ger2, rus_guard, axis_minor
;   name - card name (the entity of the first vehicle, or the squad name)
;   member1 - squad member 1: breed:count
;   member2 - squad member 2: breed:count
;   member3 - squad member 3: breed:count
;   member4 - squad member 4: breed:count
;   member5 - squad member 5: breed:count
;   member6 - squad member 6: breed:count
;   charge - recharge time after buying, s
;   tags - extra tags of the card (years 40..45, all, inf_only ...)
;   group - buy-menu group cell
;   button - buy-menu button (tab)
;   icon - icon index
;   level - unlock level
;   cost - price, points
;   fore - fore value
;   e.g. ("squad_6_sequence" side(rus) name(riflemans) member1(rus_squadleader_smg:1) member2(rus_smg:3) member3(rus_rifle_sa:2) member4(rus_rifle:3) member5(rus_mgun:1) member6(rus_mgun_asst:1) charge(0) tags(all inf_only 43 44 45) group(squad_2) button(squad1) icon(8) level(1) cost(142) fore(1.0))
(define "squad_6_sequence"
	{"%name(%side)"
		{charge %charge}
		{content "mp/%side/%member1 mp/%side/%member2 mp/%side/%member3 mp/%side/%member4 mp/%side/%member5 mp/%side/%member6"}
		{tags "frontline_cp infantry %side %tags"}
		{group "%group"}
		{button "%button"}
		{level %level}
		{cost %cost}
		{fore %fore}
		{icon %icon}
	}
)

; unit_tank_sequence_sided: buy card {"%name(%side)" ...} (was "v_seq" 10)
;   side - army side folder: ger, eng, rus, usa, jap, ger_ss, ger2, rus_guard, axis_minor
;   name - card name (the entity of the first vehicle, or the squad name)
;   vehicle1 - vehicle 1 entity
;   crew1 - number of crew 1 soldiers
;   crew2 - number of crew 2 soldiers
;   charge - recharge time after buying, s
;   tags - extra tags of the card (years 40..45, all, inf_only ...)
;   group - buy-menu group cell
;   button - buy-menu button (tab)
;   icon - icon index
;   score - score value
;   weight - cw value
;   points - cp value
;   level - unlock level
;   cost - price, points
;   fore - fore value
;   e.g. ("unit_tank_sequence_sided" side(eng) name(staghound_seq) vehicle1(staghound) crew1(3) crew2(1) charge(10) tags(all 42 43 44 45) group(d31) button(v3) icon(3) score(250) weight(0) points(5) level(1) cost(250) fore(-41.0))
(define "unit_tank_sequence_sided"
	{"%name(%side)"
		{charge %charge}
		{score %score}
		{tags "%tags %side"}
		{group "%group"}
		{button "%button"}
		{icon %icon}
		{cw %weight}
		{cp %points}
		{content "%vehicle1 ( mp/%side/tankman:%crew1 mp/%side/tankman2:%crew2)"}
		{level %level}
		{cost %cost}
		{fore %fore}
	}
)

; unit_tanks_sequence_sided: buy card {"%name(%side)" ...} (was "v2_seq" 8)
;   side - army side folder: ger, eng, rus, usa, jap, ger_ss, ger2, rus_guard, axis_minor
;   name - card name (the entity of the first vehicle, or the squad name)
;   vehicle1 - vehicle 1 entity
;   vehicle2 - vehicle 2 entity
;   crew1 - number of crew 1 soldiers
;   crew2 - number of crew 2 soldiers
;   charge - recharge time after buying, s
;   tags - extra tags of the card (years 40..45, all, inf_only ...)
;   group - buy-menu group cell
;   button - buy-menu button (tab)
;   icon - icon index
;   score - score value
;   weight - cw value
;   points - cp value
;   level - unlock level
;   cost - price, points
;   fore - fore value
;   e.g. ("unit_tanks_sequence_sided" side(eng) name(staghound_seqx2) vehicle1(staghound) vehicle2(staghound) crew1(3) crew2(1) charge(10) tags(all 42 43 44 45) group(d31) button(v3) icon(3) score(365) weight(0) points(5) level(1) cost(365) fore(-41.0))
(define "unit_tanks_sequence_sided"
	{"%name(%side)"
		{charge %charge}
		{score %score}
		{tags "%tags %side"}
		{group "%group"}
		{button "%button"}
		{icon %icon}
		{cw %weight}
		{cp %points}
		{content "%vehicle1 ( mp/%side/tankman:%crew1 mp/%side/tankman2:%crew2) %vehicle2 ( mp/%side/tankman:%crew1 mp/%side/tankman2:%crew2)"}
		{level %level}
		{cost %cost}
		{fore %fore}
	}
)

; unit_infantry_sided: buy card {"%name(%side)" ...} (was "i1" 8)
;   side - army side folder: ger, eng, rus, usa, jap, ger_ss, ger2, rus_guard, axis_minor
;   name - card name (the entity of the first vehicle, or the squad name)
;   member1 - squad member 1: breed:count
;   charge - recharge time after buying, s
;   tags - extra tags of the card (years 40..45, all, inf_only ...)
;   group - buy-menu group cell
;   button - buy-menu button (tab)
;   level - unlock level
;   cost - price, points
;   fore - fore value
;   e.g. ("unit_infantry_sided" side(eng) name(hero_airstrike) member1(eng_radioman_airstrike:1) charge(400) tags(all hero 44 45) group(h1) button(hero) level(1) cost(4.0) fore(-0.5))
(define "unit_infantry_sided"
	{"%name(%side)"
		{charge %charge}
		{tags "%tags %side"}
		{group "%group"}
		{button "%button"}
		{content "mp/%side/%member1"}
		{level %level}
		{cost %cost}
		{fore %fore}
	}
)

; unit_light_mortar: buy card {"%name" ...} (was "light_mortar_ger" 6, "light_mortar_ost" 1)
;   side - army side folder: ger, eng, rus, usa, jap, ger_ss, ger2, rus_guard, axis_minor
;   name - card name (the entity of the first vehicle, or the squad name)
;   breed1 - soldier breed of crew 1
;   breed2 - soldier breed of crew 2
;   charge - recharge time after buying, s
;   tags - extra tags of the card (years 40..45, all, inf_only ...)
;   group - buy-menu group cell
;   button - buy-menu button (tab)
;   level - unlock level
;   cost - price, points
;   fore - fore value
;   e.g. ("unit_light_mortar" side(ger) name(light_mortar_ger) breed1(ger_light_mortar) breed2(ger_light_mortar_assist) charge(10) tags(all 40 mortar) group(c56) button(v2) level(1) cost(150) fore(-2.0))
(define "unit_light_mortar"
	{"%name"
		{charge %charge}
		{tags "%tags %side"}
		{group "%group"}
		{button "%button"}
		{content " mp/%side/%breed1:1 mp/%side/%breed2:2 "}
		{level %level}
		{cost %cost}
		{fore %fore}
	}
)

; squad_6_vehicle: buy card {"%name(%side)" ...} (was "squad_with6types_vehicle" 7)
;   side - army side folder: ger, eng, rus, usa, jap, ger_ss, ger2, rus_guard, axis_minor
;   name - card name (the entity of the first vehicle, or the squad name)
;   vehicle1 - vehicle 1 entity
;   member1 - squad member 1: breed:count
;   member2 - squad member 2: breed:count
;   member3 - squad member 3: breed:count
;   member4 - squad member 4: breed:count
;   member5 - squad member 5: breed:count
;   member6 - squad member 6: breed:count
;   charge - recharge time after buying, s
;   tags - extra tags of the card (years 40..45, all, inf_only ...)
;   group - buy-menu group cell
;   button - buy-menu button (tab)
;   level - unlock level
;   cost - price, points
;   fore - fore value
;   e.g. ("squad_6_vehicle" side(eng) name(paratroopers_drop) vehicle1(airborne_spawner) member1(para_cpl:1) member2(para_2ic:1) member3(para2:3) member4(para4:2) member5(para:2) member6(para_mortar:1) charge(900) tags(all inf_only 40 41 42 43 44 45 only-one) group(squad_5) button(squad1) level(1) cost(370) fore(1.0))
(define "squad_6_vehicle"
	{"%name(%side)"
		{charge %charge}
		{content "%vehicle1 ( mp/%side/%member1 mp/%side/%member2 mp/%side/%member3 mp/%side/%member4 mp/%side/%member5 mp/%side/%member6 )"}
		{tags "frontline_cp infantry %side %tags"}
		{group "%group"}
		{button "%button"}
		{level %level}
		{cost %cost}
		{fore %fore}
	}
)

; squad_3_sequence: buy card {"%name(%side)" ...} (was "i_seq_with3types" 7)
;   side - army side folder: ger, eng, rus, usa, jap, ger_ss, ger2, rus_guard, axis_minor
;   name - card name (the entity of the first vehicle, or the squad name)
;   member1 - squad member 1: breed:count
;   member2 - squad member 2: breed:count
;   member3 - squad member 3: breed:count
;   charge - recharge time after buying, s
;   tags - extra tags of the card (years 40..45, all, inf_only ...)
;   group - buy-menu group cell
;   button - buy-menu button (tab)
;   icon - icon index
;   level - unlock level
;   cost - price, points
;   fore - fore value
;   e.g. ("squad_3_sequence" side(jap) name(riflemans_t96_4) member1(jap_squadleader:1) member2(jap_light_mortar:3) member3(light_mortar_asst:6) charge(0) tags(all inf_only 44 45) group(squad_3) button(squad1) icon(30) level(1) cost(100) fore(1.0))
(define "squad_3_sequence"
	{"%name(%side)"
		{charge %charge}
		{content "mp/%side/%member1 mp/%side/%member2 mp/%side/%member3"}
		{tags "frontline_cp infantry %side %tags"}
		{group "%group"}
		{button "%button"}
		{level %level}
		{cost %cost}
		{fore %fore}
		{icon %icon}
	}
)

; unit_tank_three_crew: buy card {"%name" ...} (was "v3_tank" 6)
;   side - army side folder: ger, eng, rus, usa, jap, ger_ss, ger2, rus_guard, axis_minor
;   name - card name (the entity of the first vehicle, or the squad name)
;   member1 - squad member 1: breed:count
;   member2 - squad member 2: breed:count
;   member3 - squad member 3: breed:count
;   charge - recharge time after buying, s
;   tags - extra tags of the card (years 40..45, all, inf_only ...)
;   group - buy-menu group cell
;   button - buy-menu button (tab)
;   score - score value
;   weight - cw value
;   points - cp value
;   level - unlock level
;   cost - price, points
;   fore - fore value
;   e.g. ("unit_tank_three_crew" side(eng) name(cometa34_elite_gun) member1(tankman2:2) member2(vet_tankman:1) member3(eng_elite_tankman:1) charge(700) tags(all medium 44 45) group(e101) button(v6) score(950) weight(0) points(15) level(1) cost(950) fore(-1.54))
(define "unit_tank_three_crew"
	{"%name"
		{charge %charge}
		{score %score}
		{tags "%tags %side"}
		{group "%group"}
		{button "%button"}
		{cw %weight}
		{cp %points}
		{content "* ( mp/%side/%member3 mp/%side/%member1 mp/%side/%member2)"}
		{level %level}
		{cost %cost}
		{fore %fore}
	}
)

; squad_5_vehicle: buy card {"%name(%side)" ...} (was "squad_with5types_vehicle" 6)
;   side - army side folder: ger, eng, rus, usa, jap, ger_ss, ger2, rus_guard, axis_minor
;   name - card name (the entity of the first vehicle, or the squad name)
;   vehicle1 - vehicle 1 entity
;   member1 - squad member 1: breed:count
;   member2 - squad member 2: breed:count
;   member3 - squad member 3: breed:count
;   member4 - squad member 4: breed:count
;   member5 - squad member 5: breed:count
;   charge - recharge time after buying, s
;   tags - extra tags of the card (years 40..45, all, inf_only ...)
;   group - buy-menu group cell
;   button - buy-menu button (tab)
;   level - unlock level
;   cost - price, points
;   fore - fore value
;   e.g. ("squad_5_vehicle" side(axis_minor) name(Motorized_Hungarian_Rifles) vehicle1(Botond) member1(axm_hun_squadleader_smg:1) member2(axm_hun_rifle:3) member3(axm_hun_smg_danuvia:3) member4(axm_hun_smg_ppsh:1) member5(axm_hun_rifle3:2) charge(60) tags(all inf_only 44 45) group(squad_7) button(squad1) level(1) cost(109) fore(0.0))
(define "squad_5_vehicle"
	{"%name(%side)"
		{charge %charge}
		{content "%vehicle1 ( mp/%side/%member1 mp/%side/%member2 mp/%side/%member3 mp/%side/%member4 mp/%side/%member5 )"}
		{tags "frontline_cp infantry %side %tags"}
		{group "%group"}
		{button "%button"}
		{level %level}
		{cost %cost}
		{fore %fore}
	}
)

; squad_9: buy card {"%name(%side)" ...} (was "squad_with9types" 6)
;   side - army side folder: ger, eng, rus, usa, jap, ger_ss, ger2, rus_guard, axis_minor
;   name - card name (the entity of the first vehicle, or the squad name)
;   member1 - squad member 1: breed:count
;   member2 - squad member 2: breed:count
;   member3 - squad member 3: breed:count
;   member4 - squad member 4: breed:count
;   member5 - squad member 5: breed:count
;   member6 - squad member 6: breed:count
;   member7 - squad member 7: breed:count
;   member8 - squad member 8: breed:count
;   member9 - squad member 9: breed:count
;   charge - recharge time after buying, s
;   tags - extra tags of the card (years 40..45, all, inf_only ...)
;   group - buy-menu group cell
;   button - buy-menu button (tab)
;   level - unlock level
;   cost - price, points
;   fore - fore value
;   e.g. ("squad_9" side(eng) name(pioneers) member1(eng_pioneer_sl:1) member2(eng_pioneer_flamer:1) member3(eng_pioneer_mg:1) member4(eng_pioneer_at:1) member5(eng_pioneer_ap_miner:1) member6(eng_pioneer_at_miner:1) member7(eng_pioneer_1trench:4) member8(eng_pioneer_minedisposal:1) member9(eng_pioneer_3trench:1) charge(0) tags(all inf_only 43 44 45) group(squad_2) button(squad1) level(1) cost(306) fore(1.0))
(define "squad_9"
	{"%name(%side)"
		{charge %charge}
		{content "mp/%side/%member1 mp/%side/%member2 mp/%side/%member3 mp/%side/%member4 mp/%side/%member5 mp/%side/%member6 mp/%side/%member7 mp/%side/%member8 mp/%side/%member9"}
		{tags "frontline_cp infantry %side %tags"}
		{group "%group"}
		{button "%button"}
		{level %level}
		{cost %cost}
		{fore %fore}
	}
)

; squad_8_sequence: buy card {"%name(%side)" ...} (was "i_seq_with8types" 6)
;   side - army side folder: ger, eng, rus, usa, jap, ger_ss, ger2, rus_guard, axis_minor
;   name - card name (the entity of the first vehicle, or the squad name)
;   member1 - squad member 1: breed:count
;   member2 - squad member 2: breed:count
;   member3 - squad member 3: breed:count
;   member4 - squad member 4: breed:count
;   member5 - squad member 5: breed:count
;   member6 - squad member 6: breed:count
;   member7 - squad member 7: breed:count
;   member8 - squad member 8: breed:count
;   charge - recharge time after buying, s
;   tags - extra tags of the card (years 40..45, all, inf_only ...)
;   group - buy-menu group cell
;   button - buy-menu button (tab)
;   icon - icon index
;   level - unlock level
;   cost - price, points
;   fore - fore value
;   e.g. ("squad_8_sequence" side(jap) name(riflemans_t96) member1(jap_squadleader:1) member2(jap_rifle:3) member3(jap_rifleb:4) member4(jap_smgb:2) member5(jap_mgun2:1) member6(mgun2_asst:1) member7(mgun2_ammo:3) member8(jap_rifle_grenadier:1) charge(0) tags(all inf_only 44 45) group(squad_3) button(squad1) icon(30) level(1) cost(163) fore(1.0))
(define "squad_8_sequence"
	{"%name(%side)"
		{charge %charge}
		{content "mp/%side/%member1 mp/%side/%member2 mp/%side/%member3 mp/%side/%member4 mp/%side/%member5 mp/%side/%member6 mp/%side/%member7 mp/%side/%member8"}
		{tags "frontline_cp infantry %side %tags"}
		{group "%group"}
		{button "%button"}
		{level %level}
		{cost %cost}
		{fore %fore}
		{icon %icon}
	}
)

; unit_vehicles1_members1_sided: buy card {"%name(%side)" ...} (was "v31" 6)
;   side - army side folder: ger, eng, rus, usa, jap, ger_ss, ger2, rus_guard, axis_minor
;   name - card name (the entity of the first vehicle, or the squad name)
;   vehicle1 - vehicle 1 entity
;   member - squad member: breed:count
;   charge - recharge time after buying, s
;   tags - extra tags of the card (years 40..45, all, inf_only ...)
;   group - buy-menu group cell
;   button - buy-menu button (tab)
;   level - unlock level
;   cost - price, points
;   fore - fore value
;   e.g. ("unit_vehicles1_members1_sided" side(ger) name(hero3) vehicle1(sdkfz303) member(vehicle_supporter:1) charge(120) tags(all hero 44) group(h1321) button(hero) level(1) cost(2.0) fore(-0.5))
(define "unit_vehicles1_members1_sided"
	{"%name(%side)"
		{charge %charge}
		{tags "%tags %side"}
		{group "%group"}
		{button "%button"}
		{content "%vehicle1 ( mp/%side/%member ) %vehicle1 ( mp/%side/%member ) %vehicle1 ( mp/%side/%member )"}
		{level %level}
		{cost %cost}
		{fore %fore}
	}
)

; unit_tank_info_commander_first_sided: buy card {"%name(%side)" ...} (was "v_ss_com" 6)
;   side - army side folder: ger, eng, rus, usa, jap, ger_ss, ger2, rus_guard, axis_minor
;   name - card name (the entity of the first vehicle, or the squad name)
;   vehicle1 - vehicle 1 entity
;   crew1 - number of crew 1 soldiers
;   crew2 - number of crew 2 soldiers
;   charge - recharge time after buying, s
;   tags - extra tags of the card (years 40..45, all, inf_only ...)
;   group - buy-menu group cell
;   button - buy-menu button (tab)
;   level - unlock level
;   cost - price, points
;   fore - fore value
;   e.g. ("unit_tank_info_commander_first_sided" side(ger_ss) name(stug3g_ss) vehicle1(stug3g) crew1(3) crew2(1) charge(10) tags(medium all 43 44 45) group(f6) button(v5) level(1) cost(675) fore(-69.0))
(define "unit_tank_info_commander_first_sided"
	{"%name(%side)"
		{charge %charge}
		{tags "%tags %side"}
		{group "%group"}
		{button "%button"}
		{content "%vehicle1 ( mp/%side/tankman2:%crew2 mp/%side/tankman:%crew1 )"}
		{info %vehicle1}
		{level %level}
		{cost %cost}
		{fore %fore}
	}
)

; unit_infantry_sided_members2: buy card {"%name(%side)" ...} (was "i2" 6)
;   side - army side folder: ger, eng, rus, usa, jap, ger_ss, ger2, rus_guard, axis_minor
;   name - card name (the entity of the first vehicle, or the squad name)
;   member1 - squad member 1: breed:count
;   member2 - squad member 2: breed:count
;   charge - recharge time after buying, s
;   tags - extra tags of the card (years 40..45, all, inf_only ...)
;   group - buy-menu group cell
;   button - buy-menu button (tab)
;   level - unlock level
;   cost - price, points
;   fore - fore value
;   e.g. ("unit_infantry_sided_members2" side(ger2) name(hero2_ost) member1(ost_panzershreck:2) member2(ost_panzershreckassist:2) charge(120) tags(all 44 45 hero) group(h2) button(hero) level(1) cost(1.0) fore(-0.5))
(define "unit_infantry_sided_members2"
	{"%name(%side)"
		{charge %charge}
		{tags "%tags %side"}
		{group "%group"}
		{button "%button"}
		{content "mp/%side/%member1 mp/%side/%member2"}
		{level %level}
		{cost %cost}
		{fore %fore}
	}
)

; unit_light_mortar_2: buy card {"%name" ...} (was "light_mortar_eng" 5)
;   side - army side folder: ger, eng, rus, usa, jap, ger_ss, ger2, rus_guard, axis_minor
;   name - card name (the entity of the first vehicle, or the squad name)
;   charge - recharge time after buying, s
;   tags - extra tags of the card (years 40..45, all, inf_only ...)
;   group - buy-menu group cell
;   button - buy-menu button (tab)
;   level - unlock level
;   cost - price, points
;   fore - fore value
;   e.g. ("unit_light_mortar_2" side(eng) name(light_mortar_eng) charge(10) tags(all 40 mortar) group(c44) button(v2) level(1) cost(170) fore(-2.0))
(define "unit_light_mortar_2"
	{"%name"
		{charge %charge}
		{tags "%tags %side"}
		{group "%group"}
		{button "%button"}
		{content " mp/%side/eng_light_mortar:1 mp/%side/eng_light_mortar_assist:1 "}
		{level %level}
		{cost %cost}
		{fore %fore}
	}
)

; squad_7_vehicle: buy card {"%name(%side)" ...} (was "squad_with7types_vehicle" 5)
;   side - army side folder: ger, eng, rus, usa, jap, ger_ss, ger2, rus_guard, axis_minor
;   name - card name (the entity of the first vehicle, or the squad name)
;   vehicle1 - vehicle 1 entity
;   member1 - squad member 1: breed:count
;   member2 - squad member 2: breed:count
;   member3 - squad member 3: breed:count
;   member4 - squad member 4: breed:count
;   member5 - squad member 5: breed:count
;   member6 - squad member 6: breed:count
;   member7 - squad member 7: breed:count
;   charge - recharge time after buying, s
;   tags - extra tags of the card (years 40..45, all, inf_only ...)
;   group - buy-menu group cell
;   button - buy-menu button (tab)
;   level - unlock level
;   cost - price, points
;   fore - fore value
;   e.g. ("squad_7_vehicle" side(eng) name(mech_rifles) vehicle1(m3_eng) member1(eng_squadleader:1) member2(eng_squadleader_asst:1) member3(eng_rifleman_smoke:4) member4(eng_rifle_grenadier:1) member5(eng_mgun:1) member6(eng_mgun_asst:1) member7(eng_rifle_piat:1) charge(10) tags(all inf_only 42 43 44 45) group(squad_33) button(squad1) level(5) cost(208) fore(-23.0))
(define "squad_7_vehicle"
	{"%name(%side)"
		{charge %charge}
		{content "%vehicle1 ( mp/%side/%member1 mp/%side/%member2 mp/%side/%member3 mp/%side/%member4 mp/%side/%member5 mp/%side/%member6 mp/%side/%member7 )"}
		{tags "frontline_cp infantry %side %tags"}
		{group "%group"}
		{button "%button"}
		{level %level}
		{cost %cost}
		{fore %fore}
	}
)

; unit_light_mortar_sided: buy card {"%name(%side)" ...} (was "light_mortar_ss" 5)
;   side - army side folder: ger, eng, rus, usa, jap, ger_ss, ger2, rus_guard, axis_minor
;   name - card name (the entity of the first vehicle, or the squad name)
;   charge - recharge time after buying, s
;   tags - extra tags of the card (years 40..45, all, inf_only ...)
;   group - buy-menu group cell
;   button - buy-menu button (tab)
;   level - unlock level
;   cost - price, points
;   fore - fore value
;   e.g. ("unit_light_mortar_sided" side(ger_ss) name(5_cm_granatwerfer_36_ss) charge(10) tags(all 41 mortar) group(c56) button(v2) level(1) cost(150) fore(-2.0))
(define "unit_light_mortar_sided"
	{"%name(%side)"
		{charge %charge}
		{tags "%tags %side"}
		{group "%group"}
		{button "%button"}
		{content " mp/%side/ss_light_mortar:1 mp/%side/ss_light_mortar_assist:2 "}
		{level %level}
		{cost %cost}
		{fore %fore}
	}
)

; unit_vehicles2_members1_sided: buy card {"%name(%side)" ...} (was "v41" 5)
;   side - army side folder: ger, eng, rus, usa, jap, ger_ss, ger2, rus_guard, axis_minor
;   name - card name (the entity of the first vehicle, or the squad name)
;   vehicle1 - vehicle 1 entity
;   vehicle2 - vehicle 2 entity
;   member1 - squad member 1: breed:count
;   charge - recharge time after buying, s
;   tags - extra tags of the card (years 40..45, all, inf_only ...)
;   group - buy-menu group cell
;   button - buy-menu button (tab)
;   level - unlock level
;   cost - price, points
;   fore - fore value
;   e.g. ("unit_vehicles2_members1_sided" side(ger) name(hero_flak18_hero) vehicle1(np_sdkfz8) vehicle2(flak18a) member1(vehicle_supporter:2) charge(600) tags(all hero artillery 44) group(h8) button(hero) level(1) cost(7.0) fore(-0.5))
(define "unit_vehicles2_members1_sided"
	{"%name(%side)"
		{charge %charge}
		{tags "%tags %side"}
		{group "%group"}
		{button "%button"}
		{content "%vehicle1 ( mp/%side/%member1 ) %vehicle1 ( mp/%side/%member1 ) %vehicle2 ( mp/%side/%member1 ) %vehicle2 ( mp/%side/%member1 )"}
		{level %level}
		{cost %cost}
		{fore %fore}
	}
)

; unit_howitzer_tractor_vehicles2: buy card {"%name" ...} (was "ita_how" 3, "hun_how" 1)
;   side - army side folder: ger, eng, rus, usa, jap, ger_ss, ger2, rus_guard, axis_minor
;   name - card name (the entity of the first vehicle, or the squad name)
;   vehicle1 - vehicle 1 entity
;   vehicle2 - vehicle 2 entity
;   breed1 - soldier breed of crew 1
;   breed2 - soldier breed of crew 2
;   charge - recharge time after buying, s
;   tags - extra tags of the card (years 40..45, all, inf_only ...)
;   group - buy-menu group cell
;   button - buy-menu button (tab)
;   level - unlock level
;   cost - price, points
;   fore - fore value
;   e.g. ("unit_howitzer_tractor_vehicles2" side(axis_minor) name(cannone9053) vehicle1(k50_tractor) vehicle2(cannone9053) breed1(axm_ita_vehicle_supporter) breed2(axm_ita_vehicle_supporter) charge(60) tags(44) group(c13) button(v2) level(1) cost(750) fore(-14.0))
(define "unit_howitzer_tractor_vehicles2"
	{"%name"
		{charge %charge}
		{content "%vehicle1 ( mp/%side/%breed1:1 ) %vehicle2 ( mp/%side/%breed2:2 )"}
		{tags "%side %tags"}
		{group "%group"}
		{button "%button"}
		{level %level}
		{cost %cost}
		{fore %fore}
	}
)

; unit_vehicle_supporters_sequence: buy card {"%name" ...} (was "vs2_seq_ita" 1, "vs3_seq_ita" 1, "vs_seq_ita" 1, "vs_seq_rom" 1)
;   side - army side folder: ger, eng, rus, usa, jap, ger_ss, ger2, rus_guard, axis_minor
;   name - card name (the entity of the first vehicle, or the squad name)
;   vehicle1 - vehicle 1 entity
;   breed - soldier breed of the crew
;   crew1 - number of crew 1 soldiers
;   charge - recharge time after buying, s
;   tags - extra tags of the card (years 40..45, all, inf_only ...)
;   group - buy-menu group cell
;   button - buy-menu button (tab)
;   icon - icon index
;   score - score value
;   weight - cw value
;   points - cp value
;   level - unlock level
;   cost - price, points
;   fore - fore value
;   e.g. ("unit_vehicle_supporters_sequence" side(axis_minor) name(Brixia45_seq) vehicle1(brixia45) breed(axm_ita_vehicle_supporter) crew1(2) charge(10) tags(all medium 44 45) group(c6) button(v2) icon(12) score(100) weight(0) points(5) level(1) cost(100) fore(-0.0))
(define "unit_vehicle_supporters_sequence"
	{"%name"
		{charge %charge}
		{score %score}
		{tags "%tags %side"}
		{group "%group"}
		{button "%button"}
		{icon %icon}
		{cw %weight}
		{cp %points}
		{content "%vehicle1 ( mp/%side/%breed:%crew1)"}
		{level %level}
		{cost %cost}
		{fore %fore}
	}
)

; squad_8_vehicle: buy card {"%name(%side)" ...} (was "squad_with8types_vehicle" 4)
;   side - army side folder: ger, eng, rus, usa, jap, ger_ss, ger2, rus_guard, axis_minor
;   name - card name (the entity of the first vehicle, or the squad name)
;   vehicle1 - vehicle 1 entity
;   member1 - squad member 1: breed:count
;   member2 - squad member 2: breed:count
;   member3 - squad member 3: breed:count
;   member4 - squad member 4: breed:count
;   member5 - squad member 5: breed:count
;   member6 - squad member 6: breed:count
;   member7 - squad member 7: breed:count
;   member8 - squad member 8: breed:count
;   charge - recharge time after buying, s
;   tags - extra tags of the card (years 40..45, all, inf_only ...)
;   group - buy-menu group cell
;   button - buy-menu button (tab)
;   level - unlock level
;   cost - price, points
;   fore - fore value
;   e.g. ("squad_8_vehicle" side(ger) name(elites_42_drop) vehicle1(airborne_spawner) member1(fallschirm_sl_40:1) member2(fallschirm_sl_asst_fg_42:1) member3(fallschirm_sniper:1) member4(fallschirm_sa_41:1) member5(fallschirm_rifle_39:1) member6(fallschirm_grenadier:2) member7(fallschirm_mg:2) member8(fallschirm_mg_asst_39:2) charge(900) tags(42 only-one) group(squad_5) button(squad1) level(1) cost(437) fore(1.0))
(define "squad_8_vehicle"
	{"%name(%side)"
		{charge %charge}
		{content "%vehicle1 ( mp/%side/%member1 mp/%side/%member2 mp/%side/%member3 mp/%side/%member4 mp/%side/%member5 mp/%side/%member6 mp/%side/%member7 mp/%side/%member8 )"}
		{tags "frontline_cp infantry %side %tags"}
		{group "%group"}
		{button "%button"}
		{level %level}
		{cost %cost}
		{fore %fore}
	}
)

; unit_vehicles2_members1_sided_2: buy card {"%name(%side)" ...} (was "v331" 4)
;   side - army side folder: ger, eng, rus, usa, jap, ger_ss, ger2, rus_guard, axis_minor
;   name - card name (the entity of the first vehicle, or the squad name)
;   vehicle1 - vehicle 1 entity
;   vehicle2 - vehicle 2 entity
;   member - squad member: breed:count
;   charge - recharge time after buying, s
;   tags - extra tags of the card (years 40..45, all, inf_only ...)
;   group - buy-menu group cell
;   button - buy-menu button (tab)
;   level - unlock level
;   cost - price, points
;   fore - fore value
;   e.g. ("unit_vehicles2_members1_sided_2" side(ger_ss) name(hero_ss_pak40) vehicle1(np_sdkfz8) vehicle2(pak40) member(vehicle_supporter:2) charge(600) tags(all hero 42 43 44 45) group(h11) button(hero) level(1) cost(12.0) fore(-0.5))
(define "unit_vehicles2_members1_sided_2"
	{"%name(%side)"
		{charge %charge}
		{tags "%tags %side"}
		{group "%group"}
		{button "%button"}
		{content "%vehicle1 ( mp/%side/%member ) %vehicle1 ( mp/%side/%member ) %vehicle1 ( mp/%side/%member ) %vehicle2 ( mp/%side/%member ) %vehicle2 ( mp/%side/%member ) %vehicle2 ( mp/%side/%member )"}
		{level %level}
		{cost %cost}
		{fore %fore}
	}
)

; unit_vehicles1_members2_sided: buy card {"%name(%side)" ...} (was "v32" 4)
;   side - army side folder: ger, eng, rus, usa, jap, ger_ss, ger2, rus_guard, axis_minor
;   name - card name (the entity of the first vehicle, or the squad name)
;   vehicle1 - vehicle 1 entity
;   member1 - squad member 1: breed:count
;   member2 - squad member 2: breed:count
;   charge - recharge time after buying, s
;   tags - extra tags of the card (years 40..45, all, inf_only ...)
;   group - buy-menu group cell
;   button - buy-menu button (tab)
;   level - unlock level
;   cost - price, points
;   fore - fore value
;   e.g. ("unit_vehicles1_members2_sided" side(rus) name(hero_t34platoon) vehicle1(t34_2) member1(tankman:3) member2(tankman:1) charge(400) tags(hero 43) group(h9) button(hero) level(1) cost(8.0) fore(-0.5))
(define "unit_vehicles1_members2_sided"
	{"%name(%side)"
		{charge %charge}
		{tags "%tags %side"}
		{group "%group"}
		{button "%button"}
		{content "%vehicle1 ( mp/%side/%member1 mp/%side/%member2 ) %vehicle1 ( mp/%side/%member1 mp/%side/%member2 ) %vehicle1 ( mp/%side/%member1 mp/%side/%member2 )"}
		{level %level}
		{cost %cost}
		{fore %fore}
	}
)

; unit_tank_sided: buy card {"%name(%side)" ...} (was "v_rus_g" 4)
;   side - army side folder: ger, eng, rus, usa, jap, ger_ss, ger2, rus_guard, axis_minor
;   name - card name (the entity of the first vehicle, or the squad name)
;   vehicle1 - vehicle 1 entity
;   crew1 - number of crew 1 soldiers
;   crew2 - number of crew 2 soldiers
;   charge - recharge time after buying, s
;   tags - extra tags of the card (years 40..45, all, inf_only ...)
;   group - buy-menu group cell
;   button - buy-menu button (tab)
;   level - unlock level
;   cost - price, points
;   fore - fore value
;   e.g. ("unit_tank_sided" side(rus_guard) name(t34m_guard) vehicle1(t34m_single) crew1(1) crew2(0) charge(60) tags(all 43 44 45) group(b66) button(v1) level(1) cost(300) fore(-19))
(define "unit_tank_sided"
	{"%name(%side)"
		{charge %charge}
		{tags "%tags %side"}
		{group "%group"}
		{button "%button"}
		{content "%vehicle1 ( mp/rus_guard/tankman:%crew1 mp/rus_guard/tankman2:%crew2 )"}
		{info %vehicle1}
		{level %level}
		{cost %cost}
		{fore %fore}
	}
)

; unit_tank_info_commander_first: buy card {"%name" ...} (was "v_ss_com" 3)
;   side - army side folder: ger, eng, rus, usa, jap, ger_ss, ger2, rus_guard, axis_minor
;   name - card name (the entity of the first vehicle, or the squad name)
;   vehicle1 - vehicle 1 entity
;   crew1 - number of crew 1 soldiers
;   crew2 - number of crew 2 soldiers
;   charge - recharge time after buying, s
;   tags - extra tags of the card (years 40..45, all, inf_only ...)
;   group - buy-menu group cell
;   button - buy-menu button (tab)
;   level - unlock level
;   cost - price, points
;   fore - fore value
;   e.g. ("unit_tank_info_commander_first" side(ger2) name(stug3g_ger2) vehicle1(stug3g_vet) crew1(3) crew2(1) charge(10) tags(medium all 43 44 45) group(f2) button(v5) level(1) cost(750) fore(-94.0))
(define "unit_tank_info_commander_first"
	{"%name"
		{charge %charge}
		{tags "%tags %side"}
		{group "%group"}
		{button "%button"}
		{content "%vehicle1 ( mp/%side/tankman2:%crew2 mp/%side/tankman:%crew1 )"}
		{info %vehicle1}
		{level %level}
		{cost %cost}
		{fore %fore}
	}
)

; unit_vehicle_members: buy card {"%name" ...} (was "v1" 2)
;   side - army side folder: ger, eng, rus, usa, jap, ger_ss, ger2, rus_guard, axis_minor
;   name - card name (the entity of the first vehicle, or the squad name)
;   vehicle1 - vehicle 1 entity
;   member1 - squad member 1: breed:count
;   member2 - squad member 2: breed:count
;   charge - recharge time after buying, s
;   tags - extra tags of the card (years 40..45, all, inf_only ...)
;   group - buy-menu group cell
;   button - buy-menu button (tab)
;   level - unlock level
;   cost - price, points
;   fore - fore value
;   e.g. ("unit_vehicle_members" side(axis_minor) name(karlthor) vehicle1(karlthor) member1(axm_ger_vehicle_supporter:5) member2(axm_ita_tankcommander:0) charge(540) tags(sheavy hero 44) group(h15) button(hero) level(1) cost(12.0) fore(-1.22))
(define "unit_vehicle_members"
	{"%name"
		{charge %charge}
		{tags "%tags %side"}
		{group "%group"}
		{button "%button"}
		{content "%vehicle1 ( mp/%side/%member1 mp/%side/%member2 )"}
		{level %level}
		{cost %cost}
		{fore %fore}
	}
)

; unit_vehicle_supporters_noinfo: buy card {"%name" ...} (was "vs_ss_noinfo" 2)
;   side - army side folder: ger, eng, rus, usa, jap, ger_ss, ger2, rus_guard, axis_minor
;   name - card name (the entity of the first vehicle, or the squad name)
;   vehicle1 - vehicle 1 entity
;   crew - number of crew soldiers
;   charge - recharge time after buying, s
;   tags - extra tags of the card (years 40..45, all, inf_only ...)
;   group - buy-menu group cell
;   button - buy-menu button (tab)
;   level - unlock level
;   cost - price, points
;   fore - fore value
;   e.g. ("unit_vehicle_supporters_noinfo" side(ger2) name(2cm_flak38_ger2) vehicle1(2cm_flak38) crew(2) charge(30) tags(all 44 45) group(c3) button(v2) level(1) cost(200) fore(-2.0))
(define "unit_vehicle_supporters_noinfo"
	{"%name"
		{charge %charge}
		{tags "%tags %side"}
		{group "%group"}
		{button "%button"}
		{content "%vehicle1 ( mp/%side/vehicle_supporter:%crew )"}
		{level %level}
		{cost %cost}
		{fore %fore}
	}
)

; squad_9_vehicle: buy card {"%name(%side)" ...} (was "squad_with9types_vehicle" 2)
;   side - army side folder: ger, eng, rus, usa, jap, ger_ss, ger2, rus_guard, axis_minor
;   name - card name (the entity of the first vehicle, or the squad name)
;   vehicle1 - vehicle 1 entity
;   member1 - squad member 1: breed:count
;   member2 - squad member 2: breed:count
;   member3 - squad member 3: breed:count
;   member4 - squad member 4: breed:count
;   member5 - squad member 5: breed:count
;   member6 - squad member 6: breed:count
;   member7 - squad member 7: breed:count
;   member8 - squad member 8: breed:count
;   member9 - squad member 9: breed:count
;   charge - recharge time after buying, s
;   tags - extra tags of the card (years 40..45, all, inf_only ...)
;   group - buy-menu group cell
;   button - buy-menu button (tab)
;   level - unlock level
;   cost - price, points
;   fore - fore value
;   e.g. ("squad_9_vehicle" side(usa) name(elites_drop) vehicle1(airborne_spawner) member1(usa_elite_sgt:1) member2(usa_82ndairborne_carbine:2) member3(usa_82ndairborne_sniper:1) member4(usa_82ndairborne_rifle:3) member5(usa_elite_grenadier:1) member6(usa_82ndairborne_bar:1) member7(usa_82ndairborne_barassist:1) member8(usa_82ndairborne_mg:1) member9(usa_82ndairborne_mgassist:1) charge(900) tags(all inf_only 42 43 44 45 only-one) group(squad_5) button(squad1) level(1) cost(338) fore(0.0))
(define "squad_9_vehicle"
	{"%name(%side)"
		{charge %charge}
		{content "%vehicle1 ( mp/%side/%member1 mp/%side/%member2 mp/%side/%member3 mp/%side/%member4 mp/%side/%member5 mp/%side/%member6 mp/%side/%member7 mp/%side/%member8 mp/%side/%member9 )"}
		{tags "frontline_cp infantry %side %tags"}
		{group "%group"}
		{button "%button"}
		{level %level}
		{cost %cost}
		{fore %fore}
	}
)

; squad_2_sequence: buy card {"%name(%side)" ...} (was "i_seq_with2types" 2)
;   side - army side folder: ger, eng, rus, usa, jap, ger_ss, ger2, rus_guard, axis_minor
;   name - card name (the entity of the first vehicle, or the squad name)
;   member1 - squad member 1: breed:count
;   member2 - squad member 2: breed:count
;   charge - recharge time after buying, s
;   tags - extra tags of the card (years 40..45, all, inf_only ...)
;   group - buy-menu group cell
;   button - buy-menu button (tab)
;   icon - icon index
;   level - unlock level
;   cost - price, points
;   fore - fore value
;   e.g. ("squad_2_sequence" side(rus) name(at_rifles) member1(rus_at_rifle:1) member2(rus_at_rifleassist:1) charge(0) tags(all inf_only 41 42 43 44 45) group(soldier_4) button(squad2) icon(6) level(1) cost(70) fore(1.0))
(define "squad_2_sequence"
	{"%name(%side)"
		{charge %charge}
		{content "mp/%side/%member1 mp/%side/%member2"}
		{tags "frontline_cp infantry %side %tags"}
		{group "%group"}
		{button "%button"}
		{level %level}
		{cost %cost}
		{fore %fore}
		{icon %icon}
	}
)

; squad_1_sequence: buy card {"%name(%side)" ...} (was "i_seq_with1types" 2)
;   side - army side folder: ger, eng, rus, usa, jap, ger_ss, ger2, rus_guard, axis_minor
;   name - card name (the entity of the first vehicle, or the squad name)
;   member1 - squad member 1: breed:count
;   charge - recharge time after buying, s
;   tags - extra tags of the card (years 40..45, all, inf_only ...)
;   group - buy-menu group cell
;   button - buy-menu button (tab)
;   icon - icon index
;   level - unlock level
;   cost - price, points
;   fore - fore value
;   e.g. ("squad_1_sequence" side(jap) name(type89mortarinf) member1(jap_light_mortar:1) charge(180) tags(all inf_only 42 43 44 45) group(soldier_89) button(squad2) icon(1) level(1) cost(40) fore(1.0))
(define "squad_1_sequence"
	{"%name(%side)"
		{charge %charge}
		{content "mp/%side/%member1"}
		{tags "frontline_cp infantry %side %tags"}
		{group "%group"}
		{button "%button"}
		{level %level}
		{cost %cost}
		{fore %fore}
		{icon %icon}
	}
)

; unit_vehicles3_members1_sided: buy card {"%name(%side)" ...} (was "v51" 2)
;   side - army side folder: ger, eng, rus, usa, jap, ger_ss, ger2, rus_guard, axis_minor
;   name - card name (the entity of the first vehicle, or the squad name)
;   vehicle1 - vehicle 1 entity
;   vehicle2 - vehicle 2 entity
;   vehicle3 - vehicle 3 entity
;   member1 - squad member 1: breed:count
;   charge - recharge time after buying, s
;   tags - extra tags of the card (years 40..45, all, inf_only ...)
;   group - buy-menu group cell
;   button - buy-menu button (tab)
;   level - unlock level
;   cost - price, points
;   fore - fore value
;   e.g. ("unit_vehicles3_members1_sided" side(usa) name(hero10) vehicle1(81mm_brandt_usa) vehicle2(m1_57mm) vehicle3(30_browning_m1919a4) member1(vehicle_supporter:2) charge(450) tags(all 42 hero) group(h7) button(hero) level(1) cost(6.0) fore(-0.5))
(define "unit_vehicles3_members1_sided"
	{"%name(%side)"
		{charge %charge}
		{tags "%tags %side"}
		{group "%group"}
		{button "%button"}
		{content "%vehicle1 ( mp/%side/%member1 ) %vehicle1 ( mp/%side/%member1 ) %vehicle2 ( mp/%side/%member1 ) %vehicle2 ( mp/%side/%member1 ) %vehicle3 ( mp/%side/%member1 )"}
		{level %level}
		{cost %cost}
		{fore %fore}
	}
)

; unit_infantry_sided_members6: buy card {"%name(%side)" ...} (was "i6" 2)
;   side - army side folder: ger, eng, rus, usa, jap, ger_ss, ger2, rus_guard, axis_minor
;   name - card name (the entity of the first vehicle, or the squad name)
;   member1 - squad member 1: breed:count
;   member2 - squad member 2: breed:count
;   member3 - squad member 3: breed:count
;   member4 - squad member 4: breed:count
;   member5 - squad member 5: breed:count
;   member6 - squad member 6: breed:count
;   charge - recharge time after buying, s
;   tags - extra tags of the card (years 40..45, all, inf_only ...)
;   group - buy-menu group cell
;   button - buy-menu button (tab)
;   level - unlock level
;   cost - price, points
;   fore - fore value
;   e.g. ("unit_infantry_sided_members6" side(jap) name(hero_ki-gata_koho) member1(ki_sl:1) member2(ki_sa:1) member3(ki_smoke:4) member4(ki_at_grenade:2) member5(ki_at_stick:2) member6(ki_rifle:5) charge(30) tags(all 44 45 hero) group(h1222) button(hero) level(1) cost(2.0) fore(-2.0))
(define "unit_infantry_sided_members6"
	{"%name(%side)"
		{charge %charge}
		{tags "%tags %side"}
		{group "%group"}
		{button "%button"}
		{content "mp/%side/%member1 mp/%side/%member2 mp/%side/%member3 mp/%side/%member4 mp/%side/%member5 mp/%side/%member6"}
		{level %level}
		{cost %cost}
		{fore %fore}
	}
)

; unit_infantry_sided_members3: buy card {"%name(%side)" ...} (was "i3" 2)
;   side - army side folder: ger, eng, rus, usa, jap, ger_ss, ger2, rus_guard, axis_minor
;   name - card name (the entity of the first vehicle, or the squad name)
;   member1 - squad member 1: breed:count
;   member2 - squad member 2: breed:count
;   member3 - squad member 3: breed:count
;   charge - recharge time after buying, s
;   tags - extra tags of the card (years 40..45, all, inf_only ...)
;   group - buy-menu group cell
;   button - buy-menu button (tab)
;   level - unlock level
;   cost - price, points
;   fore - fore value
;   e.g. ("unit_infantry_sided_members3" side(ger2) name(hero4_ost) member1(ost_straf_ppsh:6) member2(ost_straf_mauzer:18) member3(ost_straf_mp28:6) charge(240) tags(all 44 45 hero) group(h3) button(hero) level(1) cost(2.0) fore(-0.5))
(define "unit_infantry_sided_members3"
	{"%name(%side)"
		{charge %charge}
		{tags "%tags %side"}
		{group "%group"}
		{button "%button"}
		{content "mp/%side/%member1 mp/%side/%member2 mp/%side/%member3"}
		{level %level}
		{cost %cost}
		{fore %fore}
	}
)

; unit_vehicles_supporters_sequence: buy card {"%name" ...} (was "vs2_seq_rom" 1)
;   side - army side folder: ger, eng, rus, usa, jap, ger_ss, ger2, rus_guard, axis_minor
;   name - card name (the entity of the first vehicle, or the squad name)
;   vehicle1 - vehicle 1 entity
;   vehicle2 - vehicle 2 entity
;   crew1 - number of crew 1 soldiers
;   charge - recharge time after buying, s
;   tags - extra tags of the card (years 40..45, all, inf_only ...)
;   group - buy-menu group cell
;   button - buy-menu button (tab)
;   icon - icon index
;   score - score value
;   weight - cw value
;   points - cp value
;   level - unlock level
;   cost - price, points
;   fore - fore value
;   e.g. ("unit_vehicles_supporters_sequence" side(axis_minor) name(resita_seqx2) vehicle1(resita) vehicle2(resita) crew1(2) charge(10) tags(all medium 44 45) group(c10) button(v2) icon(345) score(500) weight(0) points(10) level(1) cost(500) fore(-38.0))
(define "unit_vehicles_supporters_sequence"
	{"%name"
		{charge %charge}
		{score %score}
		{tags "%tags %side"}
		{group "%group"}
		{button "%button"}
		{icon %icon}
		{cw %weight}
		{cp %points}
		{content "%vehicle1 ( mp/%side/axm_rom_vehicle_supporter:%crew1) %vehicle2 ( mp/%side/axm_rom_vehicle_supporter:%crew1)"}
		{level %level}
		{cost %cost}
		{fore %fore}
	}
)

; unit_vehicle_pair: buy card {"%name" ...} (was "2v" 1)
;   side - army side folder: ger, eng, rus, usa, jap, ger_ss, ger2, rus_guard, axis_minor
;   name - card name (the entity of the first vehicle, or the squad name)
;   vehicle1 - vehicle 1 entity
;   vehicle2 - vehicle 2 entity
;   member1 - squad member 1: breed:count
;   member2 - squad member 2: breed:count
;   charge - recharge time after buying, s
;   tags - extra tags of the card (years 40..45, all, inf_only ...)
;   group - buy-menu group cell
;   button - buy-menu button (tab)
;   level - unlock level
;   cost - price, points
;   fore - fore value
;   e.g. ("unit_vehicle_pair" side(ger) name(pak38_elite) vehicle1(pak38_elite) vehicle2(ammo_box_ger_art) member1(elite_vehicle_supporter:2) member2(vehicle_supporter:2) charge(200) tags(all hero 41 42 43 44) group(pak38_elite) button(hero) level(1) cost(3.0) fore(-0.5))
(define "unit_vehicle_pair"
	{"%name"
		{charge %charge}
		{tags "%tags %side"}
		{group "%group"}
		{button "%button"}
		{content "%vehicle1 ( mp/%side/%member1 ) %vehicle2 ( mp/%side/%member2 )"}
		{level %level}
		{cost %cost}
		{fore %fore}
	}
)

; squad_10_vehicle: buy card {"%name(%side)" ...} (was "squad_with10types_vehicle" 1)
;   side - army side folder: ger, eng, rus, usa, jap, ger_ss, ger2, rus_guard, axis_minor
;   name - card name (the entity of the first vehicle, or the squad name)
;   vehicle1 - vehicle 1 entity
;   member01 - squad member 01: breed:count
;   member02 - squad member 02: breed:count
;   member03 - squad member 03: breed:count
;   member04 - squad member 04: breed:count
;   member05 - squad member 05: breed:count
;   member06 - squad member 06: breed:count
;   member07 - squad member 07: breed:count
;   member08 - squad member 08: breed:count
;   member09 - squad member 09: breed:count
;   member10 - squad member 10: breed:count
;   charge - recharge time after buying, s
;   tags - extra tags of the card (years 40..45, all, inf_only ...)
;   group - buy-menu group cell
;   button - buy-menu button (tab)
;   level - unlock level
;   cost - price, points
;   fore - fore value
;   e.g. ("squad_10_vehicle" side(ger_ss) name(lssah_mech) vehicle1(np_sdkfz251_1_late) member01(vehicle_supporter:1) member02(ss_lssah_pzgren_sl_asst_sa:1) member03(ss_lssah_pzgren_sl_stg:1) member04(ss_lssah_pzgren_pzfst_stg:1) member05(ss_lssah_pzgren_pzfst:1) member06(ss_lssah_pzgren_pzfst60_sa:1) member07(ss_lssah_pzgren_mg:2) member08(ss_lssah_pzgren_mg_asst:2) member09(ss_lssah_pzgren_at:1) member10(ss_lssah_pzgren_at2:1) charge(60) tags(all inf_only 44 45) group(squad_5) button(squad1) level(1) cost(391) fore(1.0))
(define "squad_10_vehicle"
	{"%name(%side)"
		{charge %charge}
		{content "%vehicle1 ( mp/%side/%member01 mp/%side/%member02 mp/%side/%member03 mp/%side/%member04 mp/%side/%member05 mp/%side/%member06 mp/%side/%member07 mp/%side/%member08 mp/%side/%member09 mp/%side/%member10 )"}
		{tags "frontline_cp infantry %side %tags"}
		{group "%group"}
		{button "%button"}
		{level %level}
		{cost %cost}
		{fore %fore}
	}
)

; squad_14: buy card {"%name(%side)" ...} (was "squad_with14types" 1)
;   side - army side folder: ger, eng, rus, usa, jap, ger_ss, ger2, rus_guard, axis_minor
;   name - card name (the entity of the first vehicle, or the squad name)
;   member01 - squad member 01: breed:count
;   member02 - squad member 02: breed:count
;   member03 - squad member 03: breed:count
;   member04 - squad member 04: breed:count
;   member05 - squad member 05: breed:count
;   member06 - squad member 06: breed:count
;   member07 - squad member 07: breed:count
;   member08 - squad member 08: breed:count
;   member09 - squad member 09: breed:count
;   member10 - squad member 10: breed:count
;   member11 - squad member 11: breed:count
;   member12 - squad member 12: breed:count
;   member13 - squad member 13: breed:count
;   member14 - squad member 14: breed:count
;   charge - recharge time after buying, s
;   tags - extra tags of the card (years 40..45, all, inf_only ...)
;   group - buy-menu group cell
;   button - buy-menu button (tab)
;   level - unlock level
;   cost - price, points
;   fore - fore value
;   e.g. ("squad_14" side(ger) name(hero_ger_volks) member01(ger_volksgren_sl_stg:2) member02(ger_volksgren_sl_smg:1) member03(ger_volksgren_sl_asst:3) member04(ger_volksgren_stg44:5) member05(ger_volksgren_pzfst2:2) member06(ger_volksgren_smg:1) member07(ger_volksgren_sa:3) member08(ger_volksgren_rifle:6) member09(ger_volksgren_mg:2) member10(ger_volksgren_mg_asst:1) member11(ger_volksgren_mg_asst3:1) member12(ger_volksgren_grenadier:3) member13(volksgren_at:1) member14(volksgren_at2:1) charge(200) tags(all hero 44 45) group(h22) button(hero) level(1) cost(3) fore(-0.5))
(define "squad_14"
	{"%name(%side)"
		{charge %charge}
		{content "mp/%side/%member01 mp/%side/%member02 mp/%side/%member03 mp/%side/%member04 mp/%side/%member05 mp/%side/%member06 mp/%side/%member07 mp/%side/%member08 mp/%side/%member09 mp/%side/%member10 mp/%side/%member11 mp/%side/%member12 mp/%side/%member13 mp/%side/%member14"}
		{tags "frontline_cp infantry %side %tags"}
		{group "%group"}
		{button "%button"}
		{level %level}
		{cost %cost}
		{fore %fore}
	}
)

; unit_tanks_sequence_commander_first_sided: buy card {"%name(%side)" ...} (was "v2_seq_com" 1)
;   side - army side folder: ger, eng, rus, usa, jap, ger_ss, ger2, rus_guard, axis_minor
;   name - card name (the entity of the first vehicle, or the squad name)
;   vehicle1 - vehicle 1 entity
;   vehicle2 - vehicle 2 entity
;   crew1 - number of crew 1 soldiers
;   crew2 - number of crew 2 soldiers
;   charge - recharge time after buying, s
;   tags - extra tags of the card (years 40..45, all, inf_only ...)
;   group - buy-menu group cell
;   button - buy-menu button (tab)
;   icon - icon index
;   score - score value
;   weight - cw value
;   points - cp value
;   level - unlock level
;   cost - price, points
;   fore - fore value
;   e.g. ("unit_tanks_sequence_commander_first_sided" side(ger) name(stug3g_seqx2) vehicle1(stug3g) vehicle2(stug3g) crew1(3) crew2(1) charge(10) tags(medium 44) group(f6) button(v5) icon(1) score(825) weight(0) points(15) level(1) cost(825) fore(-94.0))
(define "unit_tanks_sequence_commander_first_sided"
	{"%name(%side)"
		{charge %charge}
		{score %score}
		{tags "%tags %side"}
		{group "%group"}
		{button "%button"}
		{icon %icon}
		{cw %weight}
		{cp %points}
		{content "%vehicle1 ( mp/%side/tankman2:%crew2 mp/%side/tankman:%crew1) %vehicle2 ( mp/%side/tankman2:%crew2 mp/%side/tankman:%crew1)"}
		{level %level}
		{cost %cost}
		{fore %fore}
	}
)

; unit_tank_sequence_commander_first_sided: buy card {"%name(%side)" ...} (was "v_seq_com" 1)
;   side - army side folder: ger, eng, rus, usa, jap, ger_ss, ger2, rus_guard, axis_minor
;   name - card name (the entity of the first vehicle, or the squad name)
;   vehicle1 - vehicle 1 entity
;   crew1 - number of crew 1 soldiers
;   crew2 - number of crew 2 soldiers
;   charge - recharge time after buying, s
;   tags - extra tags of the card (years 40..45, all, inf_only ...)
;   group - buy-menu group cell
;   button - buy-menu button (tab)
;   icon - icon index
;   score - score value
;   weight - cw value
;   points - cp value
;   level - unlock level
;   cost - price, points
;   fore - fore value
;   e.g. ("unit_tank_sequence_commander_first_sided" side(ger) name(stug3g_seq) vehicle1(stug3g) crew1(3) crew2(1) charge(10) tags(medium 44) group(f6) button(v5) icon(1) score(550) weight(0) points(15) level(1) cost(550) fore(-94.0))
(define "unit_tank_sequence_commander_first_sided"
	{"%name(%side)"
		{charge %charge}
		{score %score}
		{tags "%tags %side"}
		{group "%group"}
		{button "%button"}
		{icon %icon}
		{cw %weight}
		{cp %points}
		{content "%vehicle1 ( mp/%side/tankman2:%crew2 mp/%side/tankman:%crew1)"}
		{level %level}
		{cost %cost}
		{fore %fore}
	}
)

; unit_vehicles4_members12_sided: buy card {"%name(%side)" ...} (was "4_diff_vehicle_2_unique_inf_per" 1)
;   side - army side folder: ger, eng, rus, usa, jap, ger_ss, ger2, rus_guard, axis_minor
;   name - card name (the entity of the first vehicle, or the squad name)
;   vehicle1 - vehicle 1 entity
;   vehicle2 - vehicle 2 entity
;   vehicle3 - vehicle 3 entity
;   vehicle4 - vehicle 4 entity
;   member01 - squad member 01: breed:count
;   member02 - squad member 02: breed:count
;   member03 - squad member 03: breed:count
;   member04 - squad member 04: breed:count
;   member05 - squad member 05: breed:count
;   member06 - squad member 06: breed:count
;   member07 - squad member 07: breed:count
;   member08 - squad member 08: breed:count
;   member09 - squad member 09: breed:count
;   member10 - squad member 10: breed:count
;   member11 - squad member 11: breed:count
;   member12 - squad member 12: breed:count
;   charge - recharge time after buying, s
;   tags - extra tags of the card (years 40..45, all, inf_only ...)
;   group - buy-menu group cell
;   button - buy-menu button (tab)
;   level - unlock level
;   cost - price, points
;   fore - fore value
;   e.g. ("unit_vehicles4_members12_sided" side(usa) name(hero8) vehicle1(m4a3e2_jumbo_76_vet) vehicle2(np_willys50) vehicle3(np_willys50) vehicle4(np_willysat) member01(vet_tankman2:1) member02(elite_101st_para3_asst:1) member03(vet_tankman:4) member04(vehicle_supporter:2) member05(vehicle_supporter:0) member06(vehicle_supporter:0) member07(vehicle_supporter:2) member08(vehicle_supporter:0) member09(vehicle_supporter:0) member10(vehicle_supporter:2) member11(vehicle_supporter:0) member12(vehicle_supporter:0) charge(750) tags(all 45 hero) group(h10) button(hero) level(1) cost(10.0) fore(-1.0))
(define "unit_vehicles4_members12_sided"
	{"%name(%side)"
		{charge %charge}
		{tags "%tags %side"}
		{group "%group"}
		{button "%button"}
		{content "%vehicle1 ( mp/%side/%member01 mp/%side/%member02 mp/%side/%member03 ) %vehicle2 ( mp/%side/%member04 mp/%side/%member05 mp/%side/%member06 ) %vehicle3 ( mp/%side/%member07 mp/%side/%member08 mp/%side/%member09 ) %vehicle4 ( mp/%side/%member10 mp/%side/%member11 mp/%side/%member12 )"}
		{level %level}
		{cost %cost}
		{fore %fore}
	}
)

; unit_vehicles3_members1_sided_2: buy card {"%name(%side)" ...} (was "v221" 1)
;   side - army side folder: ger, eng, rus, usa, jap, ger_ss, ger2, rus_guard, axis_minor
;   name - card name (the entity of the first vehicle, or the squad name)
;   vehicle1 - vehicle 1 entity
;   vehicle2 - vehicle 2 entity
;   vehicle3 - vehicle 3 entity
;   member1 - squad member 1: breed:count
;   charge - recharge time after buying, s
;   tags - extra tags of the card (years 40..45, all, inf_only ...)
;   group - buy-menu group cell
;   button - buy-menu button (tab)
;   level - unlock level
;   cost - price, points
;   fore - fore value
;   e.g. ("unit_vehicles3_members1_sided_2" side(axis_minor) name(hero_guard_the_flanks) vehicle1(Resita) vehicle2(bredasafat77_stan) vehicle3(sgrw_42) member1(axm_rom_vehicle_supporter:2) charge(540) tags(all hero 44 45) group(h15) button(hero) level(1) cost(10.0) fore(-0.111))
(define "unit_vehicles3_members1_sided_2"
	{"%name(%side)"
		{charge %charge}
		{tags "%tags %side"}
		{group "%group"}
		{button "%button"}
		{content "%vehicle1 ( mp/%side/%member1 ) %vehicle1 ( mp/%side/%member1 ) %vehicle2 ( mp/%side/%member1 ) %vehicle2 ( mp/%side/%member1 ) %vehicle3 ( mp/%side/%member1)"}
		{level %level}
		{cost %cost}
		{fore %fore}
	}
)

; unit_vehicles3_members1_sided_3: buy card {"%name(%side)" ...} (was "v1111" 1)
;   side - army side folder: ger, eng, rus, usa, jap, ger_ss, ger2, rus_guard, axis_minor
;   name - card name (the entity of the first vehicle, or the squad name)
;   vehicle1 - vehicle 1 entity
;   vehicle2 - vehicle 2 entity
;   vehicle3 - vehicle 3 entity
;   member1 - squad member 1: breed:count
;   charge - recharge time after buying, s
;   tags - extra tags of the card (years 40..45, all, inf_only ...)
;   group - buy-menu group cell
;   button - buy-menu button (tab)
;   level - unlock level
;   cost - price, points
;   fore - fore value
;   e.g. ("unit_vehicles3_members1_sided_3" side(usa) name(hero_log) vehicle1(gmc_art) vehicle2(gmc_inf) vehicle3(ammo_box_us_special) member1(vehicle_supporter:2) charge(180) tags(all 42 43 44 45 hero) group(h1) button(hero) level(1) cost(1.0) fore(-0.5))
(define "unit_vehicles3_members1_sided_3"
	{"%name(%side)"
		{charge %charge}
		{tags "%tags %side"}
		{group "%group"}
		{button "%button"}
		{content "%vehicle1 ( mp/%side/%member1 ) %vehicle2 ( mp/%side/%member1) %vehicle3 ( mp/%side/%member1 )"}
		{level %level}
		{cost %cost}
		{fore %fore}
	}
)

; unit_vehicle_members_sided_vehicles1_members1: buy card {"%name(%side)" ...} (was "v0" 1)
;   side - army side folder: ger, eng, rus, usa, jap, ger_ss, ger2, rus_guard, axis_minor
;   name - card name (the entity of the first vehicle, or the squad name)
;   vehicle1 - vehicle 1 entity
;   member1 - squad member 1: breed:count
;   charge - recharge time after buying, s
;   tags - extra tags of the card (years 40..45, all, inf_only ...)
;   group - buy-menu group cell
;   button - buy-menu button (tab)
;   level - unlock level
;   cost - price, points
;   fore - fore value
;   e.g. ("unit_vehicle_members_sided_vehicles1_members1" side(usa) name(hero1) vehicle1(m8_howitzer) member1(elite:2) charge(120) tags(all 42 hero) group(h1) button(hero) level(1) cost(2.0) fore(-0.5))
(define "unit_vehicle_members_sided_vehicles1_members1"
	{"%name(%side)"
		{charge %charge}
		{tags "%tags %side"}
		{group "%group"}
		{button "%button"}
		{content "%vehicle1 ( mp/%side/%member1 )"}
		{level %level}
		{cost %cost}
		{fore %fore}
	}
)

; unit_vehicles1_members4_sided: buy card {"%name(%side)" ...} (was "bers_mot" 1)
;   side - army side folder: ger, eng, rus, usa, jap, ger_ss, ger2, rus_guard, axis_minor
;   name - card name (the entity of the first vehicle, or the squad name)
;   vehicle1 - vehicle 1 entity
;   member1 - squad member 1: breed:count
;   member2 - squad member 2: breed:count
;   member3 - squad member 3: breed:count
;   member4 - squad member 4: breed:count
;   charge - recharge time after buying, s
;   tags - extra tags of the card (years 40..45, all, inf_only ...)
;   group - buy-menu group cell
;   button - buy-menu button (tab)
;   level - unlock level
;   cost - price, points
;   fore - fore value
;   e.g. ("unit_vehicles1_members4_sided" side(axis_minor) name(bersaglieri_motorcycle) vehicle1(guzzi-sa500) member1(axm_ita_bersaglieri_rifle) member2(axm_ita_bersaglieri_smg:2) member3(axm_ita_bersaglieri_mgun) member4(axm_ita_bersaglieri_mgun_assist) charge(60) tags(all hero 44 45) group(squad_mot) button(squad1) level(1) cost(215) fore(0.0))
(define "unit_vehicles1_members4_sided"
	{"%name(%side)"
		{charge %charge}
		{tags "%tags %side"}
		{group "%group"}
		{button "%button"}
		{content "%vehicle1 ( mp/%side/%member1 mp/%side/%member1 ) %vehicle1 ( mp/%side/%member1 ) %vehicle1 ( mp/%side/%member2 ) %vehicle1 ( mp/%side/%member4 ) %vehicle1 ( mp/%side/%member4 ) %vehicle1 ( mp/%side/%member2  ) %vehicle1 ( mp/%side/%member3 mp/%side/%member4"}
		{level %level}
		{cost %cost}
		{fore %fore}
	}
)

; unit_vehicles3_members2_sided: buy card {"%name(%side)" ...} (was "v32_eng" 1)
;   side - army side folder: ger, eng, rus, usa, jap, ger_ss, ger2, rus_guard, axis_minor
;   name - card name (the entity of the first vehicle, or the squad name)
;   vehicle1 - vehicle 1 entity
;   vehicle2 - vehicle 2 entity
;   vehicle3 - vehicle 3 entity
;   member1 - squad member 1: breed:count
;   member2 - squad member 2: breed:count
;   charge - recharge time after buying, s
;   tags - extra tags of the card (years 40..45, all, inf_only ...)
;   group - buy-menu group cell
;   button - buy-menu button (tab)
;   level - unlock level
;   cost - price, points
;   fore - fore value
;   e.g. ("unit_vehicles3_members2_sided" side(eng) name(hero_churchill) vehicle1(churchill_mk_vii) vehicle2(churchill_mk_vii) vehicle3(churchill_mk_v_cs) member1(tankman:3) member2(vet_tankman2:1) charge(700) tags(all 44 45 hero) group(h10) button(hero) level(1) cost(10.0) fore(-0.90))
(define "unit_vehicles3_members2_sided"
	{"%name(%side)"
		{charge %charge}
		{tags "%tags %side"}
		{group "%group"}
		{button "%button"}
		{content "%vehicle1 ( mp/%side/%member1 mp/%side/%member2 ) %vehicle2 ( mp/%side/%member1 mp/%side/%member2 ) %vehicle3 ( mp/%side/%member1 mp/%side/%member2 )"}
		{level %level}
		{cost %cost}
		{fore %fore}
	}
)

; unit_vehicle_pair_sided_vehicles2_members2: buy card {"%name(%side)" ...} (was "22v" 1)
;   side - army side folder: ger, eng, rus, usa, jap, ger_ss, ger2, rus_guard, axis_minor
;   name - card name (the entity of the first vehicle, or the squad name)
;   vehicle1 - vehicle 1 entity
;   vehicle2 - vehicle 2 entity
;   member1 - squad member 1: breed:count
;   member2 - squad member 2: breed:count
;   charge - recharge time after buying, s
;   tags - extra tags of the card (years 40..45, all, inf_only ...)
;   group - buy-menu group cell
;   button - buy-menu button (tab)
;   level - unlock level
;   cost - price, points
;   fore - fore value
;   e.g. ("unit_vehicle_pair_sided_vehicles2_members2" side(rus) name(hero_stalins_gamble) vehicle1(t60) vehicle2(t70) member1(tankman:1) member2(tankman2:1) charge(360) tags(all hero 44 45) group(h1416) button(hero) level(1) cost(4.0) fore(0.0))
(define "unit_vehicle_pair_sided_vehicles2_members2"
	{"%name(%side)"
		{charge %charge}
		{tags "%tags %side"}
		{group "%group"}
		{button "%button"}
		{content "%vehicle1 ( mp/%side/%member1 mp/%side/%member2 ) %vehicle2 ( mp/%side/%member1 mp/%side/%member2 )"}
		{level %level}
		{cost %cost}
		{fore %fore}
	}
)

; unit_vehicles1_members3_sided: buy card {"%name(%side)" ...} (was "v23" 1)
;   side - army side folder: ger, eng, rus, usa, jap, ger_ss, ger2, rus_guard, axis_minor
;   name - card name (the entity of the first vehicle, or the squad name)
;   vehicle1 - vehicle 1 entity
;   member1 - squad member 1: breed:count
;   member2 - squad member 2: breed:count
;   member3 - squad member 3: breed:count
;   charge - recharge time after buying, s
;   tags - extra tags of the card (years 40..45, all, inf_only ...)
;   group - buy-menu group cell
;   button - buy-menu button (tab)
;   level - unlock level
;   cost - price, points
;   fore - fore value
;   e.g. ("unit_vehicles1_members3_sided" side(rus) name(hero7) vehicle1(ot34_2) member1(tankman:3) member2(tankman:1) member3(rus_shock_smg:4) charge(750) tags(all hero 44 45 flamethrower) group(h7) button(hero) level(1) cost(5.0) fore(0))
(define "unit_vehicles1_members3_sided"
	{"%name(%side)"
		{charge %charge}
		{tags "%tags %side"}
		{group "%group"}
		{button "%button"}
		{content "%vehicle1 ( mp/%side/%member1 mp/%side/%member2 mp/%side/%member3 ) %vehicle1 ( mp/%side/%member1 mp/%side/%member2 mp/%side/%member3 )"}
		{level %level}
		{cost %cost}
		{fore %fore}
	}
)

; unit_vehicles1_members3_sided_2: buy card {"%name(%side)" ...} (was "v3" 1)
;   side - army side folder: ger, eng, rus, usa, jap, ger_ss, ger2, rus_guard, axis_minor
;   name - card name (the entity of the first vehicle, or the squad name)
;   vehicle1 - vehicle 1 entity
;   member1 - squad member 1: breed:count
;   member2 - squad member 2: breed:count
;   member3 - squad member 3: breed:count
;   charge - recharge time after buying, s
;   tags - extra tags of the card (years 40..45, all, inf_only ...)
;   group - buy-menu group cell
;   button - buy-menu button (tab)
;   level - unlock level
;   cost - price, points
;   fore - fore value
;   e.g. ("unit_vehicles1_members3_sided_2" side(ger2) name(hero8_ost) vehicle1(t34_3_ger2) member1(tankman:3) member2(tankman2:1) member3(ost_rifle:4) charge(600) tags(all 44 45 hero) group(h9) button(hero) level(1) cost(4.0) fore(-1.0))
(define "unit_vehicles1_members3_sided_2"
	{"%name(%side)"
		{charge %charge}
		{tags "%tags %side"}
		{group "%group"}
		{button "%button"}
		{content "%vehicle1 ( mp/%side/%member1 mp/%side/%member2 mp/%side/%member3 )"}
		{level %level}
		{cost %cost}
		{fore %fore}
	}
)

; unit_vehicles1_members4_sided_2: buy card {"%name(%side)" ...} (was "v24" 1)
;   side - army side folder: ger, eng, rus, usa, jap, ger_ss, ger2, rus_guard, axis_minor
;   name - card name (the entity of the first vehicle, or the squad name)
;   vehicle1 - vehicle 1 entity
;   member1 - squad member 1: breed:count
;   member2 - squad member 2: breed:count
;   member3 - squad member 3: breed:count
;   member4 - squad member 4: breed:count
;   charge - recharge time after buying, s
;   tags - extra tags of the card (years 40..45, all, inf_only ...)
;   group - buy-menu group cell
;   button - buy-menu button (tab)
;   level - unlock level
;   cost - price, points
;   fore - fore value
;   e.g. ("unit_vehicles1_members4_sided_2" side(ger2) name(hero5_ost) vehicle1(sdkfz250_11) member1(ost_pzgren_sg44_pzfuast:2) member2(ost_pzgren_g43_pzfaust:2) member3(ost_pzgren_smg_pzfaust:1) member4(ost_pzgren_mg34:1) charge(180) tags(all 44 45 hero) group(h6) button(hero) level(1) cost(3.0) fore(-0.5))
(define "unit_vehicles1_members4_sided_2"
	{"%name(%side)"
		{charge %charge}
		{tags "%tags %side"}
		{group "%group"}
		{button "%button"}
		{content "%vehicle1 ( mp/%side/%member1 mp/%side/%member2 mp/%side/%member3 mp/%side/%member4 ) %vehicle1 ( mp/%side/%member1 mp/%side/%member2 mp/%side/%member3 mp/%side/%member4 )"}
		{level %level}
		{cost %cost}
		{fore %fore}
	}
)

; unit_vehicles1_members8_sided: buy card {"%name(%side)" ...} (was "v28" 1)
;   side - army side folder: ger, eng, rus, usa, jap, ger_ss, ger2, rus_guard, axis_minor
;   name - card name (the entity of the first vehicle, or the squad name)
;   vehicle1 - vehicle 1 entity
;   member1 - squad member 1: breed:count
;   member2 - squad member 2: breed:count
;   member3 - squad member 3: breed:count
;   member4 - squad member 4: breed:count
;   member5 - squad member 5: breed:count
;   member6 - squad member 6: breed:count
;   member7 - squad member 7: breed:count
;   member8 - squad member 8: breed:count
;   charge - recharge time after buying, s
;   tags - extra tags of the card (years 40..45, all, inf_only ...)
;   group - buy-menu group cell
;   button - buy-menu button (tab)
;   level - unlock level
;   cost - price, points
;   fore - fore value
;   e.g. ("unit_vehicles1_members8_sided" side(usa) name(hero_raiders) vehicle1(lvt4) member1(tankman:3) member2(tankman2:1) member3(usa_raiderchad:1) member4(usa_raider:3) member5(usa_raidergren:1) member6(usa_raiderbar:3) member7(usa_raiderasst:3) member8(usa_raiderdemo:1) charge(700) tags(all 44 45 hero) group(h5516) button(hero) level(1) cost(7.0) fore(0.0))
(define "unit_vehicles1_members8_sided"
	{"%name(%side)"
		{charge %charge}
		{tags "%tags %side"}
		{group "%group"}
		{button "%button"}
		{content "%vehicle1 ( mp/%side/%member1 mp/%side/%member2 mp/%side/%member3 mp/%side/%member4 mp/%side/%member5 mp/%side/%member6 mp/%side/%member7 mp/%side/%member8 ) %vehicle1 ( mp/%side/%member1 mp/%side/%member2 mp/%side/%member3 mp/%side/%member4 mp/%side/%member5 mp/%side/%member6 mp/%side/%member7 mp/%side/%member8 )"}
		{level %level}
		{cost %cost}
		{fore %fore}
	}
)

; unit_vehicles1_members9_sided: buy card {"%name(%side)" ...} (was "v9" 1)
;   side - army side folder: ger, eng, rus, usa, jap, ger_ss, ger2, rus_guard, axis_minor
;   name - card name (the entity of the first vehicle, or the squad name)
;   vehicle1 - vehicle 1 entity
;   member1 - squad member 1: breed:count
;   member2 - squad member 2: breed:count
;   member3 - squad member 3: breed:count
;   member4 - squad member 4: breed:count
;   member5 - squad member 5: breed:count
;   member6 - squad member 6: breed:count
;   member7 - squad member 7: breed:count
;   member8 - squad member 8: breed:count
;   member9 - squad member 9: breed:count
;   charge - recharge time after buying, s
;   tags - extra tags of the card (years 40..45, all, inf_only ...)
;   group - buy-menu group cell
;   button - buy-menu button (tab)
;   level - unlock level
;   cost - price, points
;   fore - fore value
;   e.g. ("unit_vehicles1_members9_sided" side(ger_ss) name(hero_ss_das_reich) vehicle1(np_sdkfz251_1_late) member1(dr_pzgren_sl:1) member2(dr_pzgren_sl_asst:1) member3(dr_pzgren_pzfst_stg:1) member4(dr_pzgren_sa:1) member5(dr_pzgren_pzfst60_sa:1) member6(dr_pzgren_pzfst:1) member7(dr_pzgren_rifle:1) member8(dr_pzgren_mg:2) member9(dr_pzgren_mg_asst:2) charge(480) tags(all hero 44 45) group(h99) button(hero) level(1) cost(3.0) fore(0.0))
(define "unit_vehicles1_members9_sided"
	{"%name(%side)"
		{charge %charge}
		{tags "%tags %side"}
		{group "%group"}
		{button "%button"}
		{content "%vehicle1 ( mp/%side/%member1 mp/%side/%member2 mp/%side/%member3 mp/%side/%member4 mp/%side/%member5 mp/%side/%member6 mp/%side/%member7 mp/%side/%member8 mp/%side/%member9 )"}
		{level %level}
		{cost %cost}
		{fore %fore}
	}
)

; unit_vehicles2_members2_sided: buy card {"%name(%side)" ...} (was "v232" 1)
;   side - army side folder: ger, eng, rus, usa, jap, ger_ss, ger2, rus_guard, axis_minor
;   name - card name (the entity of the first vehicle, or the squad name)
;   vehicle1 - vehicle 1 entity
;   vehicle2 - vehicle 2 entity
;   member1 - squad member 1: breed:count
;   member2 - squad member 2: breed:count
;   charge - recharge time after buying, s
;   tags - extra tags of the card (years 40..45, all, inf_only ...)
;   group - buy-menu group cell
;   button - buy-menu button (tab)
;   level - unlock level
;   cost - price, points
;   fore - fore value
;   e.g. ("unit_vehicles2_members2_sided" side(axis_minor) name(hero_recon_in_force) vehicle1(csaba39m) vehicle2(csaba40m) member1(axm_hun_tankman:3) member2(axm_hun_tankcommander:1) charge(320) tags(all hero 44 45) group(h15) button(hero) level(1) cost(3.0) fore(-0.125))
(define "unit_vehicles2_members2_sided"
	{"%name(%side)"
		{charge %charge}
		{tags "%tags %side"}
		{group "%group"}
		{button "%button"}
		{content "%vehicle1 ( mp/%side/%member1 mp/%side/%member2)  %vehicle1 ( mp/%side/%member1 mp/%side/%member2)  %vehicle2 ( mp/%side/%member1 mp/%side/%member2)  "}
		{level %level}
		{cost %cost}
		{fore %fore}
	}
)

; unit_vehicles2_members6_sided: buy card {"%name(%side)" ...} (was "v236" 1)
;   side - army side folder: ger, eng, rus, usa, jap, ger_ss, ger2, rus_guard, axis_minor
;   name - card name (the entity of the first vehicle, or the squad name)
;   vehicle1 - vehicle 1 entity
;   vehicle2 - vehicle 2 entity
;   member1 - squad member 1: breed:count
;   member2 - squad member 2: breed:count
;   member3 - squad member 3: breed:count
;   member4 - squad member 4: breed:count
;   member5 - squad member 5: breed:count
;   member6 - squad member 6: breed:count
;   charge - recharge time after buying, s
;   tags - extra tags of the card (years 40..45, all, inf_only ...)
;   group - buy-menu group cell
;   button - buy-menu button (tab)
;   level - unlock level
;   cost - price, points
;   fore - fore value
;   e.g. ("unit_vehicles2_members6_sided" side(axis_minor) name(hero_hungarian_mobile_unit) vehicle1(turan3) vehicle2(botond) member1(axm_hun_tankman:4) member2(axm_hun_tankcommander:1) member3(axm_hun_assualt_rifle:4) member4(axm_hun_assualt_pzf:3) member5(axm_hun_assualt_squadleader:1) member6(axm_hun_assualt_mgun:2) charge(180) tags(all hero 44 45) group(h15) button(hero) level(1) cost(12.0) fore(-3.65))
(define "unit_vehicles2_members6_sided"
	{"%name(%side)"
		{charge %charge}
		{tags "%tags %side"}
		{group "%group"}
		{button "%button"}
		{content "%vehicle1 ( mp/%side/%member1 mp/%side/%member2)  %vehicle1 ( mp/%side/%member1 mp/%side/%member2) %vehicle2 (  mp/%side/%member3 mp/%side/%member4 mp/%side/%member5 mp/%side/%member6)   %vehicle2 ( mp/%side/%member3 mp/%side/%member4 mp/%side/%member5 mp/%side/%member6) "}
		{level %level}
		{cost %cost}
		{fore %fore}
	}
)

; unit_vehicles1_crews3_sided: buy card {"%name(%side)" ...} (was "vb3" 1)
;   side - army side folder: ger, eng, rus, usa, jap, ger_ss, ger2, rus_guard, axis_minor
;   name - card name (the entity of the first vehicle, or the squad name)
;   vehicle1 - vehicle 1 entity
;   crew1 - number of crew 1 soldiers
;   crew2 - number of crew 2 soldiers
;   crew3 - number of crew 3 soldiers
;   charge - recharge time after buying, s
;   tags - extra tags of the card (years 40..45, all, inf_only ...)
;   group - buy-menu group cell
;   button - buy-menu button (tab)
;   level - unlock level
;   cost - price, points
;   fore - fore value
;   e.g. ("unit_vehicles1_crews3_sided" side(ger2) name(storm_mech_ost) vehicle1(sdkfz250_1) crew1(3) crew2(1) crew3(2) charge(1) tags(all 44 45 inf_only) group(squad_7) button(squad1) level(12) cost(182) fore(-159.0))
(define "unit_vehicles1_crews3_sided"
	{"%name(%side)"
		{charge %charge}
		{tags "%tags %side"}
		{group "%group"}
		{button "%button"}
		{content "%vehicle1 ( mp/%side/ost_jager_sa:%crew1 mp/%side/ost_jager_stg:%crew2 mp/%side/ost_jager_smg:%crew3)"}
		{level %level}
		{cost %cost}
		{fore %fore}
	}
)

; unit_vehicles1_crews2_sided: buy card {"%name(%side)" ...} (was "v5-tank" 1)
;   side - army side folder: ger, eng, rus, usa, jap, ger_ss, ger2, rus_guard, axis_minor
;   name - card name (the entity of the first vehicle, or the squad name)
;   vehicle1 - vehicle 1 entity
;   crew1 - number of crew 1 soldiers
;   crew2 - number of crew 2 soldiers
;   charge - recharge time after buying, s
;   tags - extra tags of the card (years 40..45, all, inf_only ...)
;   group - buy-menu group cell
;   button - buy-menu button (tab)
;   level - unlock level
;   cost - price, points
;   fore - fore value
;   e.g. ("unit_vehicles1_crews2_sided" side(jap) name(hero6) vehicle1(chi-he) crew1(3) crew2(1) charge(400) tags(all hero 43 44 45) group(h7) button(hero) level(1) cost(5.0) fore(-1))
(define "unit_vehicles1_crews2_sided"
	{"%name(%side)"
		{charge %charge}
		{tags "%tags %side"}
		{group "%group"}
		{button "%button"}
		{content "%vehicle1 ( mp/%side/tankman:%crew1 mp/%side/tankman2:%crew2 ) %vehicle1 ( mp/%side/tankman:%crew1 mp/%side/tankman2:%crew2 ) %vehicle1 ( mp/%side/tankman:%crew1 mp/%side/tankman2:%crew2 ) %vehicle1 ( mp/%side/tankman:%crew1 mp/%side/tankman2:%crew2 ) %vehicle1 ( mp/%side/tankman:%crew1 mp/%side/tankman2:%crew2 )"}
		{level %level}
		{cost %cost}
		{fore %fore}
	}
)

; unit_vehicles2_crews2_sided: buy card {"%name(%side)" ...} (was "v5_3-2-tank" 1)
;   side - army side folder: ger, eng, rus, usa, jap, ger_ss, ger2, rus_guard, axis_minor
;   name - card name (the entity of the first vehicle, or the squad name)
;   vehicle1 - vehicle 1 entity
;   vehicle2 - vehicle 2 entity
;   crew1 - number of crew 1 soldiers
;   crew2 - number of crew 2 soldiers
;   charge - recharge time after buying, s
;   tags - extra tags of the card (years 40..45, all, inf_only ...)
;   group - buy-menu group cell
;   button - buy-menu button (tab)
;   level - unlock level
;   cost - price, points
;   fore - fore value
;   e.g. ("unit_vehicles2_crews2_sided" side(usa) name(hero7) vehicle1(m4a3_75) vehicle2(m4a3e8) crew1(4) crew2(1) charge(900) tags(all 44 45 hero) group(h8) button(hero) level(1) cost(7.0) fore(-0.5))
(define "unit_vehicles2_crews2_sided"
	{"%name(%side)"
		{charge %charge}
		{tags "%tags %side"}
		{group "%group"}
		{button "%button"}
		{content "%vehicle1 ( mp/%side/tankman:%crew1 mp/%side/tankman2:%crew2 ) %vehicle1 ( mp/%side/tankman:%crew1 mp/%side/tankman2:%crew2 ) %vehicle1 ( mp/%side/tankman:%crew1 mp/%side/tankman2:%crew2 ) %vehicle2 ( mp/%side/tankman:%crew1 mp/%side/tankman2:%crew2 ) %vehicle2 ( mp/%side/tankman:%crew1 mp/%side/tankman2:%crew2 )"}
		{level %level}
		{cost %cost}
		{fore %fore}
	}
)

; unit_vehicles1_crews3_sided_2: buy card {"%name(%side)" ...} (was "vb3_usa" 1)
;   side - army side folder: ger, eng, rus, usa, jap, ger_ss, ger2, rus_guard, axis_minor
;   name - card name (the entity of the first vehicle, or the squad name)
;   vehicle1 - vehicle 1 entity
;   crew1 - number of crew 1 soldiers
;   crew2 - number of crew 2 soldiers
;   crew3 - number of crew 3 soldiers
;   charge - recharge time after buying, s
;   tags - extra tags of the card (years 40..45, all, inf_only ...)
;   group - buy-menu group cell
;   button - buy-menu button (tab)
;   level - unlock level
;   cost - price, points
;   fore - fore value
;   e.g. ("unit_vehicles1_crews3_sided_2" side(usa) name(storm_mech) vehicle1(m3_usa) crew1(6) crew2(2) crew3(2) charge(380) tags(all inf_only 42 43 44 45) group(squad_5) button(squad1) level(1) cost(414) fore(1.0))
(define "unit_vehicles1_crews3_sided_2"
	{"%name(%side)"
		{charge %charge}
		{tags "%tags %side"}
		{group "%group"}
		{button "%button"}
		{content "%vehicle1 ( mp/%side/usa_ranger_springfield:%crew1 mp/%side/usa_ranger_barassist:%crew2 mp/%side/usa_ranger_bar:%crew3)"}
		{level %level}
		{cost %cost}
		{fore %fore}
	}
)

; unit_vehicles1_members6_sided: buy card {"%name(%side)" ...} (was "guard_mech" 1)
;   side - army side folder: ger, eng, rus, usa, jap, ger_ss, ger2, rus_guard, axis_minor
;   name - card name (the entity of the first vehicle, or the squad name)
;   vehicle1 - vehicle 1 entity
;   member1 - squad member 1: breed:count
;   member2 - squad member 2: breed:count
;   member3 - squad member 3: breed:count
;   member4 - squad member 4: breed:count
;   member5 - squad member 5: breed:count
;   member6 - squad member 6: breed:count
;   charge - recharge time after buying, s
;   tags - extra tags of the card (years 40..45, all, inf_only ...)
;   group - buy-menu group cell
;   button - buy-menu button (tab)
;   level - unlock level
;   cost - price, points
;   fore - fore value
;   e.g. ("unit_vehicles1_members6_sided" side(rus_guard) name(hero_guard_mech) vehicle1(m3_rus) member1(guard_sl:1) member2(guard_smg:2) member3(guard_smg2:1) member4(guard_sa:1) member5(guard_mg:2) member6(guard_mg_asst:2) charge(270) tags(all hero 44 45) group(h4) button(hero) level(1) cost(5.0) fore(-0.5))
(define "unit_vehicles1_members6_sided"
	{"%name(%side)"
		{charge %charge}
		{tags "%tags %side"}
		{group "%group"}
		{button "%button"}
		{content "%vehicle1 ( mp/%side/vehicle_supporter:1 mp/%side/%member1 mp/%side/%member2 mp/%side/%member3 mp/%side/%member4 mp/%side/%member5 mp/%side/%member6) %vehicle1 ( mp/%side/vehicle_supporter:1 mp/%side/%member1 mp/%side/%member2 mp/%side/%member3 mp/%side/%member4 mp/%side/%member5 mp/%side/%member6)"}
		{level %level}
		{cost %cost}
		{fore %fore}
	}
)

; unit_vehicle_supporters_guard_noinfo_sided: buy card {"%name(%side)" ...} (was "vs_rus_g_noinfo" 1)
;   side - army side folder: ger, eng, rus, usa, jap, ger_ss, ger2, rus_guard, axis_minor
;   name - card name (the entity of the first vehicle, or the squad name)
;   vehicle1 - vehicle 1 entity
;   crew - number of crew soldiers
;   charge - recharge time after buying, s
;   tags - extra tags of the card (years 40..45, all, inf_only ...)
;   group - buy-menu group cell
;   button - buy-menu button (tab)
;   level - unlock level
;   cost - price, points
;   fore - fore value
;   e.g. ("unit_vehicle_supporters_guard_noinfo_sided" side(rus_guard) name(203b4_guard) vehicle1(203b4) crew(2) charge(60) tags(all artillery heavyart heavy 43 44 45) group(c17) button(v22) level(1) cost(1300) fore(-19.0))
(define "unit_vehicle_supporters_guard_noinfo_sided"
	{"%name(%side)"
		{charge %charge}
		{tags "%tags %side"}
		{group "%group"}
		{button "%button"}
		{content "%vehicle1 ( mp/rus_guard/vehicle_supporter:%crew )"}
		{level %level}
		{cost %cost}
		{fore %fore}
	}
)

; unit_infantry_sided_members8: buy card {"%name(%side)" ...} (was "i8" 1)
;   side - army side folder: ger, eng, rus, usa, jap, ger_ss, ger2, rus_guard, axis_minor
;   name - card name (the entity of the first vehicle, or the squad name)
;   member1 - squad member 1: breed:count
;   member2 - squad member 2: breed:count
;   member3 - squad member 3: breed:count
;   member4 - squad member 4: breed:count
;   member5 - squad member 5: breed:count
;   member6 - squad member 6: breed:count
;   member7 - squad member 7: breed:count
;   member8 - squad member 8: breed:count
;   charge - recharge time after buying, s
;   tags - extra tags of the card (years 40..45, all, inf_only ...)
;   group - buy-menu group cell
;   button - buy-menu button (tab)
;   level - unlock level
;   cost - price, points
;   fore - fore value
;   e.g. ("unit_infantry_sided_members8" side(eng) name(hero3) member1(eng_anzac_sl:1) member2(eng_anzac_mg:2) member3(eng_anzac_mg_assist:2) member4(eng_anzac_smg:2) member5(eng_anzac_rifle:1) member6(eng_anzac_at_rifle:1) member7(eng_anzac_rifle_grenadier:1) member8(eng_anzac_smg_thompson:2) charge(90) tags(all hero 44 45) group(h10) button(hero) level(1) cost(2.0) fore(-0.5))
(define "unit_infantry_sided_members8"
	{"%name(%side)"
		{charge %charge}
		{tags "%tags %side"}
		{group "%group"}
		{button "%button"}
		{content "mp/%side/%member1 mp/%side/%member2 mp/%side/%member3 mp/%side/%member4 mp/%side/%member5 mp/%side/%member6 mp/%side/%member7 mp/%side/%member8"}
		{level %level}
		{cost %cost}
		{fore %fore}
	}
)
