; info.lng mod part: info/entity/* keys of vehicle/gun cards, side eng, button v22 "Artillery"
; mod part, buy-list order (units read order); above each key: [new|changed] card, cost, contents, tags, units file:line, notes
; -- group c5 --
; [new] card "ml_3_inch_mk_ii" cost 340 lvl 1 | soldiers vehicle_supporter x2 | tags all 43 44 45 mortar 42 41 | units/eng/vehicles_43-44.set:43 | also under eng/v2
{"ml_3_inch_mk_ii" "The Ordnance ML 3-inch is a British 81.2 mm infantry mortar, successor to the Stokes mortar. Its early range was poor next to German mortars, but wartime improvements made it effective."}
; -- group c16 --
; [new] card "gun_carrier_3_inch" cost 490 lvl 1 | soldiers vehicle_supporter x4 | tags all 43 44 45 mortar 42 41 | units/eng/vehicles_43-44.set:46
{"gun_carrier_3_inch" "A 3-inch mortar mounted in a Universal Carrier."}
; -- group c18 --
; [changed] card "m7_eng" cost 920 lvl 1 | soldiers tankman x3, tankman2 | tags all artillery 43 44 45 42 | units/eng/vehicles_43-44.set:56
{"m7_eng" "The Priest is a 105mm self-propelled howitzer for infantry support on an M3 medium tank chassis, with a large-calibre AA machine gun. Thick armor protects it, but the open turret exposes the crew."}
; -- group c14 --
; [new] card "bl45(eng)" cost 650 lvl 1 | soldiers vehicle_supporter x2 | vehicles bl45 | tags all artillery 43 44 45 42 41 | units/eng/vehicles_45.set:52 | {info bl45}; copy of bl45 (with crew)
{"bl45" "The BL 4.5 inch medium gun had nothing in common with the QF 4.5 inch Howitzer or the QF 4.5 inch AA gun."}
; -- group c155 --
; [new] card "long_tom(eng)" cost 1000 lvl 1 | soldiers vehicle_supporter x2 | vehicles longtom_155mm | tags all artillery heavyart heavy 43 44 45 | units/eng/vehicles_45.set:54 | {info longtom_155mm}; also under usa/v22; cards long_tom(eng), longtom_155mm(usa); copy of longtom_155mm (with crew)
{"longtom_155mm" "The Long Tom, adopted in 1938 as the 155mm gun M1 on Carriage M1, is a US heavy gun developed to replace foreign designs such as the French 155 mm GPF."}
; -- group c183 --
; [new] card "bl72(eng)" cost 1100 lvl 1 | soldiers vehicle_supporter x2 | vehicles bl72 | tags all artillery heavyart heavy 44 45 | units/eng/vehicles_45.set:55 | {info bl72}; copy of bl72 (with crew)
{"bl72" "This British heavy howitzer is a BL 8-inch howitzer relined to a smaller calibre, with new ammunition for longer range. Its destructive power is unrivalled, so use it wisely and aim well."}
