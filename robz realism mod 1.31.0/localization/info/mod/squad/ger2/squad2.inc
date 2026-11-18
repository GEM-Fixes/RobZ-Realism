; info.lng mod part: info/squad/* keys of infantry cards, side ger2, button squad2 "Specialized soldiers"
; mod part, buy-list order (units read order); above each key: [new|changed] card, cost, contents, tags, units file:line, notes
; -- group soldier_1 --
; [new] card "riflemans2(ger2)" cost 16 lvl 1 | soldiers ost_rifle_single | tags infantry all 44 45 inf_only single | units/ger2/squads.set:37
{"riflemans2(ger2)" "A single infantryman armed with a bolt-action K98 rifle and sandbags."}
; -- group soldier_2 --
; [new] card "smgs2(ger2)" cost 16 lvl 1 | soldiers ost_smg | tags infantry all 44 45 inf_only single | units/ger2/squads.set:39
{"smgs2(ger2)" "A single infantryman armed with an MP-40 submachine gun and AT grenades."}
; -- group soldier_3 --
; [new] card "tankmans(ger2)" cost 125 lvl 1 | soldiers ost_tankman2, ost_tankman x4 | tags infantry all 44 45 inf_only tankmans | units/ger2/squads.set:41
{"tankmans(ger2)" "Lightly armed tank crew of 5 for manning armored vehicles and field guns and replacing losses. They are not suited for infantry combat and can't capture points."}
; -- group soldier_4 --
; [new] card "at_rifles(ger2)" cost 104 lvl 1 | soldiers ost_at_rifle, ost_at_rifleassist | tags infantry all 44 45 inf_only | units/ger2/squads.set:43
{"at_rifles(ger2)" "Two-man anti-tank rifle team for lightly armored vehicles. The high velocity rifle packs a punch but cannot handle heavier vehicles and may need several shots on light ones."}
; -- group soldier_5 --
; [new] card "bazookers(ger2)" cost 78 lvl 1 | soldiers ost_panzerfaust x2 | tags infantry all 44 45 inf_only | units/ger2/squads.set:46
{"bazookers(ger2)" "Two-man anti-tank team with shaped-charge rockets that can destroy even the heaviest tanks at close range if it finds a weak spot. Armored skirts greatly reduce their effect."}
; -- group soldier_8 --
; [new] card "flamers(ger2)" cost 81 lvl 3 | soldiers ost_flamer, ost_flamerassist | tags infantry all 44 45 flamer inf_only | units/ger2/squads.set:57
{"flamers(ger2)" "Two-man flamethrower team, deadly at close range and able to set buildings and cover ablaze to drive out the enemy. The volatile fuel tank can kill the carrier if hit."}
; -- group soldier_9 --
; [new] card "snipers(ger2)" cost 109 lvl 8 | soldiers ost_sniper | tags infantry all 44 45 sniper_only inf_only | units/ger2/squads.set:59
{"snipers(ger2)" "Well-trained marksman with a scoped rifle who kills infantry at long range and relies on stealth. Use him on officers and other key targets first."}
; -- group soldier_10 --
; [new] card "officers(ger2)" cost 0 lvl 1 | soldiers ost_officer x4 | tags infantry all officer inf_only 39 40 41 42 43 44 45 | units/ger2/squads.set:61
{"officers(ger2)" "Experienced field officer who spots enemy units through the fog of war and reduces your current CP by 17. He comes with 2 jaegers armed with StG44s as bodyguards."}
