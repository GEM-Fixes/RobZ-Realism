; info.lng mod part: info/entity/* keys of vehicle/gun cards, side ger, button v2 "Support weapons"
; mod part, buy-list order (units read order); above each key: [new|changed] card, cost, contents, tags, units file:line, notes
; -- group c3 --
; [new] card "2cm_flak38" cost 200 lvl 1 | soldiers vehicle_supporter x2 | tags 44 45 43 42 41 | units/ger/vehicles_44.set:32
{"2cm_flak38" "The FlaK 38 was a light anti-aircraft gun used by Germany. It was the most numerous German artillery piece produced during the war. It was used against infantry and light targets with devastating effectiveness, however it lacked the fire rate and the explosive payload to effectively use against aircraft."}
; -- group c4 --
; [new] card "2cm_flakvierling38" cost 250 lvl 1 | soldiers vehicle_supporter x4 | tags 44 45 43 42 41 | units/ger/vehicles_44.set:34
{"2cm_flakvierling38" "This weapon combines four FlaK 38s on a quad mount. While not particularly effective against armoured vehicles, it is an effective weapon against aircraft and soft ground targets. However, due to its rapid fire rate, it consumes ammunition at a rapid pace."}
; -- group c5 --
; [new] card "37mm_flak_36" cost 250 lvl 1 | soldiers vehicle_supporter x2 | tags 44 45 43 42 41 | units/ger/vehicles_44.set:37
{"37mm_flak_36" "The 37mm FlaK 36 was the solution to the ever-increasing speeds of fighters and ground-attack aircraft. It fired a payload eight times larger than the 20mm FlaK 38, making it way more effective against high-flying aircraft and armoured targets."}
; -- group c133 --
; [new] card "15_cm_sig33" cost 750 lvl 1 | soldiers vehicle_supporter x2 | tags artillery 44 45 43 42 41 | units/ger/vehicles_44.set:53
{"15_cm_sig33" "The 150mm sIG 33 was a \"heavy infantry gun\" used by the German army. No one is sure what they were thinking when they classified this 2-ton monstrosity as an infantry gun but nonetheless, its explosive payload can demolish groups of infantry, emplacements and basically destroy any armoured vehicle. Beware of counter-artillery fire and stray Staghounds."}
; -- group c14 --
; [new] card "stuh42" cost 600 lvl 1 | soldiers tankman x4, tankman2 | tags medium 44 45 43 | units/ger/vehicles_44.set:56 | also under ger_ss/v2; cards stuh42, stuh42_ss
{"stuh42" "In 1942, a variant of the StuG III Ausf. F was designed with a 105 mm (4.1 in) howitzer instead of the 7.5 cm StuK 40 L/43 cannon. These new vehicles, designated StuH 42 (Sturmhaubitze 42, Sd.Kfz 142/2), were designed to provide infantry support with the increased number of StuG III Ausf. F/8 and Ausf. Gs being used in the anti-tank role. The StuH 42 mounts a LeFH 18 howitzer on a StuG III chassis. This vehicle is suitable for both demolishing fortifications, laying down a smoke shield, limited anti-tank work and wasting HEAT on half-tracks. To add to the fun, the vehicle has a sub-standard reload time so using it as a tank destroyer is utterly fruitless and has a very limited range so using it as an artillery piece is not advised either."}
; -- group c17 --
; [new] card "sig33b" cost 850 lvl 1 | soldiers tankman2, tankman x4 | tags medium 44 43 42 | units/ger/vehicles_44.set:57
{"sig33b" "The StuIG 33B answers the question \"What if we strapped an infantry gun on a tank chassis?\". Its explosive power is good against fortifications, enemy tanks, large groups of infantry or practically any target as long as you can keep resupplying it with ammunition."}
; -- group c15 --
; [new] card "brummbar_early" cost 1050 lvl 1 | soldiers tankman x3, tankman2 | tags medium 44 45 43 | units/ger/vehicles_44.set:58 | also under ger_ss/v2; cards brummbar_early, brummbar_ss
{"brummbar_early" "The Sturmpanzer IV (nicknamed Stupa) was a German armoured infantry support gun based on the Panzer IV chassis. It carried a StuH43 gun, a derivative of the sIG 33 for demolition work. It was in all ways an upgrade to the StuIG 33B - even better explosive power, capable of blowing even the heaviest enemy tanks up and a strong, 100mm sloped frontal armour in a fixed superstructure. It can be used in a slight arc, shooting at enemies which can't shoot back at you."}
; -- group c1 --
; [new] card "mg34_lafette" cost 150 lvl 1 | soldiers vehicle_supporter x2 | tags 45 43 42 41 | units/vehicles_x.set:38 | also under ger_ss/v2; cards mg34_lafette, mg34_lafette_ss
{"mg34_lafette" "A MG 34 on a tripod mount."}
; -- group c13 --
; [new] card "75mm_leig18" cost 320 lvl 1 | soldiers vehicle_supporter x2 | tags artillery 45 43 42 41 | units/vehicles_x.set:40
{"75mm_leig18" "The 75mm  leIG 18 was an infantry support gun of the Wehrmacht used during World War II. It was used for infantry support and attacking emplacements. It has a mediocre HEAT round used for anti-tank defense."}
; -- group c11 --
; [new] card "pak43" cost 850 lvl 1 | soldiers vehicle_supporter x2 | tags heavy 45 43 | units/vehicles_x.set:198 | also under ger_ss/v2; cards pak43, pak43_ss
{"pak43" "The 88mm PaK 43 is an 88mm anti-tank gun developed to penetrate the heaviest of Allied tanks, including the American M26 Pershing, British Churchill Mk. VIII and the Soviet IS-2. A highly effective weapon, it is easily considered one of the best anti-tank weapons our superior German engineers have created so far!"}
; [new] card "pak44" cost 950 lvl 1 | soldiers vehicle_supporter x2 | tags artillery heavy 45 | units/vehicles_x.set:199 | also under ger_ss/v2; cards pak44, pak44_ss
{"pak44" "The 88mm PaK 44 is a 128mm anti-tank and anti-everything gun conceived from encountering the Russian 122mm cannons. Originally it was supposed to be a field gun but with the encountering of heavy Russian armour its role was expanded to an anti-tank role. Most copies were assembled with stolen French and Russian carriages using superior German engineering. Its weight of 11 tons made it unsuitable for towing so the crew just usually fled upon the enemy approaching."}
; -- group c12 --
; [new] card "how_aa(ger)" cost 700 lvl 1 | soldiers vehicle_supporter x2 | vehicles flak36a | tags medium 45 43 | units/ger/vehicles_45.set:55 | {info flak36a}; also under ger_ss/v2; cards how_aa(ger), how_aa(ger_ss), how_aa_2(ger); copy of flak36a (with crew)
{"flak36a" "The 88mm FlaK 36 was an anti-aircraft and anti-tank gun, mounted on a gun carriage that enabled it to fire in all directions. Widespread production started in 1933, and it soon proved to be the best anti-aircraft weapon available when Germany intervened during the Spanish Civil War. It also turned out to be an excellent anti-tank weapon, as its high muzzle velocity and large calibre gave it the power and range to take out enemy armour. The success of this weapon lead to many variants and it was one of the most recognizable German weapons throughout the war. This variant has APCBC, HE, APCR and HEAT ammo available."}
