; desc.lng mod part: desc/entity/* keys of vehicle/gun cards, side rus_guard, button v2 "Support weapons"
; mod part, buy-list order (units read order); above each key: [new|changed] card, cost, contents, tags, units file:line, notes
; -- group c101 --
; [new] card "m42_guard" cost 225 lvl 1 | soldiers vehicle_supporter x2 | tags all 43 44 45 | units/rus_guard/vehicles_43-45.set:30
{"m42_guard" "M-42 [Guards]"}
; -- group c10 --
; [new] card "zis3_guard" cost 305 lvl 1 | soldiers vehicle_supporter x2 | tags artillery all 43 44 45 | units/rus_guard/vehicles_43-45.set:33 | cards zis3_guard, zis3_towed_guard
{"zis3_guard" "ZiS-3 [Veteran]"}
; -- group c12 --
; [new] card "np_52k_43_towed_guard" cost 650 lvl 1 | soldiers vehicle_supporter x4 | vehicles t34m, np_52k_43_guard | tags medium 43 44 45 | units/rus_guard/vehicles_43-45.set:38 | in {content} of card "np_52k_43_towed_guard"
{"np_52k_43_guard" "52-K [Guards]"}
; -- group c13 --
; [new] card "bs3_towed_guard" cost 1000 lvl 1 | soldiers vehicle_supporter x4 | vehicles t34m, bs3_guard | tags all heavy 44 45 | units/rus_guard/vehicles_43-45.set:39 | in {content} of card "bs3_towed_guard"
{"bs3_guard" "BS-3 [Guards]"}
; -- group c20 --
; [new] card "isu152_guard" cost 1000 lvl 1 | soldiers tankman x4, tankman2 | tags artillery all heavy 43 44 45 | units/rus_guard/vehicles_43-45.set:45
{"isu152_guard" "ISU-152 [Veteran]"}
