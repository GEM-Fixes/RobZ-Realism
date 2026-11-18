; info.lng mod part: info/squad/* keys of infantry cards, side rus_guard, button squad2 "Specialized soldiers"
; mod part, buy-list order (units read order); above each key: [new|changed] card, cost, contents, tags, units file:line, notes
; -- group soldier_1 --
; [new] card "riflemans2(rus_guard)" cost 16 lvl 1 | soldiers guard_rifle | tags infantry all inf_only 39 40 41 42 43 44 45 | units/rus_guard/squads_43-45.set:56
{"riflemans2(rus_guard)" "A single skill 5 rifleman. Weapons:1x Mosin Nagant 1891/30 Rifle. Throwables:2x F1 Grenade 1x Incendiary Mixture. Consumables:5x First Aid Kit. Extra:1x DP-27 LMG Magazine"}
; -- group soldier_sa --
; [new] card "rifle_sa(rus_guard)" cost 17 lvl 1 | soldiers guard_sa | tags infantry all inf_only 40 41 42 43 44 45 | units/rus_guard/squads_43-45.set:58
{"rifle_sa(rus_guard)" "A single skill 5 rifleman. Weapons:1x SVT-40 Rifle. Throwables:2x F1 Grenade 1x Incendiary Mixture. Consumables:5x First Aid Kit. Extra:1x DP-27 LMG Magazine"}
; -- group soldier_2 --
; [new] card "smg(rus_guard)" cost 16 lvl 1 | soldiers guard_smg | tags infantry all inf_only 41 42 43 44 45 | units/rus_guard/squads_43-45.set:61
{"smg(rus_guard)" "A single skill 5 SMG soldier. Weapons:1x PPSh-41. Throwables:2x F1 Grenade 1x Smoke Grenade. Consumables:5x First Aid kit."}
; -- group soldier_4 --
; [new] card "at_rifles(rus_guard)" cost 123 lvl 1 | soldiers guard_at_rifle, guard_at_rifleassist | tags infantry all inf_only 41 42 43 44 45 | units/rus_guard/squads_43-45.set:67
{"at_rifles(rus_guard)" "The PTRS-AT Rifle Team is a 2-man skill 5 team, capable of engaging light armoured vehicles. The PTRS-41 Anti Tank Rifle is useful for disabling or destroying light skinned vehicles. It can kill crew members and destroy vehicles. It has a maximum range of 120 meters. Weapons:1x PTRS-41 AT Rifle 1x PPSh-41 SMG. Throwables:2x F1 AP Grenade 2x RPG-43 AT Grenade 1x Smoke Grenad. Extra:x45 rounds of PTRS-41 ammunition"}
; -- group soldier_5 --
; [new] card "bazookers(rus_guard)" cost 75 lvl 1 | soldiers guard_bazooker, guard_bazookerassist | tags infantry all inf_only 42 43 44 45 | units/rus_guard/squads_43-45.set:69
{"bazookers(rus_guard)" "The Guards Bazooka Team is a 2-man skill 5 team, capable of engaging light and medium armoured vehicles. The M1A1 Bazooka fires a 60mm high-explosive anti-tank rockets, capable of penetrating and most medium armoured vehicles. It has a maximum range of 75 metersWeapons:1x M1A1 Bazooka1x PPSh-41 SMG. Throwables:2x F1 AP Grenade 2x RPG-43 AT Grenade 1x Smoke Grenade. Consumables:6x First Aid Kit. Extra:x11 rounds of M6A1 60mm HEAT rockets. This squad has a 5 minute timer between spawns."}
; -- group soldier_55 --
; [new] card "bazookers_piat(rus_guard)" cost 129 lvl 1 | soldiers guard_piat, guard_piatassist | tags infantry all inf_only 43 44 45 | units/rus_guard/squads_43-45.set:70
{"bazookers_piat(rus_guard)" "The Guards Piat Team is a 2-man skill 5 team, capable of engaging light, medium, and heavy armoured vehicles. The PIAT Mk. I fires a 38mm high-explosive anti-tank projectile, capable of penetrating most heavy armoured vehicles. It has a maximum range of 70 meters. The PIAT fires its projectile in an upward arc, similar to a mortar. Weapons:1x PIAT Mk. I1x PPSh-41 SMG. Throwables:2x F1 AP Grenade 2x RPG-43 AT Grenade 1x Smoke Grenade. Consumables:6x First Aid Kit. Extra:x11 rounds of PIAT projectiles. This squad has a 5 minute timer between spawns."}
; -- group soldier_6 --
; [new] card "mgs2(rus_guard)" cost 62 lvl 1 | soldiers guard_mg, guard_mg_asst | tags infantry all inf_only 43 44 45 | units/rus_guard/squads_43-45.set:74
{"mgs2(rus_guard)" "The Guards DP-27 Team is a 2-man skill 5 team, a machine gunner and ammo bearer.This team is useful for setting up a hasty machine gun position. Weapons:1x DP-27 LMg 1x Mosin Nagant 1891/30 Rifle. Throwables:2x F1 AP Grenade. Deployables:1x Shovel/bags."}
; -- group soldier_9 --
; [new] card "snipers(rus_guard)" cost 210 lvl 1 | soldiers guard_sniper_mosin x2 | tags infantry all sniper inf_only 39 40 41 42 43 44 45 | units/rus_guard/squads_43-45.set:78
{"snipers(rus_guard)" "The Guards Mosin Sniper Team is a 2-man skill 6 team, consisting of two veteran snipers.This team is useful for engaging enemy infantry at long range. Weapons:2x Mosin Nagant 1891/30 w/ PU Scope. Consumables:10x First Aid Kit. Deployables:6x Camouflage kit."}
; [new] card "snipers3(rus_guard)" cost 210 lvl 1 | soldiers guard_sniper_svtscope x2 | tags infantry all sniper inf_only 40 41 42 43 44 45 | units/rus_guard/squads_43-45.set:79
{"snipers3(rus_guard)" "The Guards SVT-40 Sniper Team is a 2-man skill 6 team, consisting of two veteran snipers.This team is useful for engaging enemy infantry at long range, at a higher rate of fire than a Mosin Nagant. Weapons:2x SVT-40 w/ PU Scope. Consumables:10x First Aid Kit. Deployables:6x Camouflage kit."}
; -- group soldier_10 --
; [new] card "officers(rus_guard)" cost 0 lvl 1 | soldiers guard_officer x4 | tags infantry all officer inf_only 39 40 41 42 43 44 45 | units/rus_guard/squads_43-45.set:81
{"officers(rus_guard)" "The Guards Officer is a single command unit, capable of observing enemy positions with binoculars, calling in airborne supply drops, increasing the maximum available Command Points, and improving the regeneration of MP Points gained from downed units.A maximum of 3 officers can be purchased. Weapons:1x TT-33 Pistol. Throwables:5x Signal Grenade  - Heavy Ammo Paradrop. Extra:1x Binocular."}
