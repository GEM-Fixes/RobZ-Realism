; desc.lng mod part: desc/entity/* keys of vehicle/gun cards, side usa, button v22 "Artillery"
; mod part, buy-list order (units read order); above each key: [new|changed] card, cost, contents, tags, units file:line, notes
; -- group c14 --
; [new] card "60mm_brandt_usa" cost 220 lvl 1 | soldiers vehicle_supporter | tags all 42 43 44 45 mortar | units/usa/vehicles_43-45.set:49 | also under usa/v2
{"60mm_brandt_usa" "M2 60mm mortar"}
; -- group c18 --
; [new] card "4_2_inch_mortar_m_2" cost 600 lvl 1 | soldiers vehicle_supporter x2 | tags all 43 44 45 mortar | units/usa/vehicles_43-45.set:51
{"4_2_inch_mortar_m_2" "M2 4.2-inch Mortar"}
; -- group c12 --
; [new] card "m4halftrack" cost 535 lvl 1 | soldiers vehicle_supporter x5 | tags all 42 43 44 45 mortar | units/usa/vehicles_43-45.set:53
{"m4halftrack" "M4 mortar carrier"}
; -- group c13 --
; [new] card "np_t19" cost 720 lvl 1 | soldiers tankman x5, tankman2 | tags all 42 43 44 45 artillery | units/usa/vehicles_43-45.set:57
{"np_t19" "T19 105mm HMC"}
; -- group c9 --
; [changed] card "m114_towed" cost 895 lvl 1 | soldiers vehicle_supporter x4 | vehicles m4a3m, m114 | tags all 42 43 44 45 artillery heavyart | units/usa/vehicles_43-45.set:60 | in {content} of card "m114_towed"; also under eng/v2, eng/v22; cards m114_towed, longtom_155mm_towed, m115_towed, m114_vet_towed +6
{"m4a3m" "M4A3M"}
; -- group c15 --
; [changed] card "m12gmc" cost 1350 lvl 1 | soldiers tankman x3, tankman2 | tags all 42 43 44 45 artillery heavyart heavy | units/usa/vehicles_43-45.set:61
{"m12gmc" "155mm Gun Motor Carriage M12"}
; -- group c88 --
; [new] card "m2a1l_vet" cost 765 lvl 1 | soldiers vehicle_supporter x2 | tags all 42 43 44 45 artillery | units/usa/vehicles_43-45.set:66 | cards m2a1l_vet, m2a1l_vet_towed
{"m2a1l_vet" "M2A1 L [Veteran]"}
; -- group c99 --
; [new] card "m114_vet_towed" cost 1295 lvl 1 | soldiers vehicle_supporter x4 | vehicles m4a3m, m114_vet | tags all 42 43 44 45 artillery heavyart | units/usa/vehicles_43-45.set:69 | in {content} of card "m114_vet_towed"
{"m114_vet" "M114 [Veteran]"}
; -- group c100 --
; [new] card "longtom_155mm_vet_towed" cost 1495 lvl 1 | soldiers vehicle_supporter x4 | vehicles m4a3m, longtom_155mm_vet | tags all 42 43 44 45 artillery heavyart | units/usa/vehicles_43-45.set:71 | in {content} of card "longtom_155mm_vet_towed"
{"longtom_155mm_vet" "Long tom [Veteran]"}
; -- group c111 --
; [new] card "m115_vet_towed" cost 1595 lvl 1 | soldiers vehicle_supporter x4 | vehicles m4a3m, m115_vet | tags all 42 43 44 45 artillery heavyart | units/usa/vehicles_43-45.set:73 | in {content} of card "m115_vet_towed"
{"m115_vet" "M115 203mm howitzer [Veteran]"}
; -- group c11 --
; [new] card "m115(usa)" cost 990 lvl 1 | soldiers vehicle_supporter x2 | vehicles m115 | tags all 42 artillery heavyart | units/usa/vehicles_42.set:44 | {info m115}; cards m115(usa), m115_towed; copy of m115 (with crew)
{"m115" "M115 203mm howitzer"}
