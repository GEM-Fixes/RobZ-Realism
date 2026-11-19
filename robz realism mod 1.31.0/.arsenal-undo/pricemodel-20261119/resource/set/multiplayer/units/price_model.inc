; price_model.inc: price model of the pricecalc tool (tools/pricecalc). INCLUDED BY NOTHING: no game exe reads it.
;   The retail 32-bit exe only reads the plain numbers the tool writes (level_N defines in soldiers.set, cost(N) on the cards).
;   This file is the tool's only model (and input for a later as64 engine function). Edit it by hand; `seed` never overwrites
;   it without --force, and `seed --merge` only adds newly found items (as undetermined). Values -1 = not in the sheet.
;
; Blocks (all inside {price_model ...}):
;   {source ...}            where the numbers came from (sheet files), for the record
;   {rounding {mp S} {cp S} {cost S}}   results are rounded to a multiple of S (cost 1 = whole MP points, as cost(N) needs)
;   {veterancy {apply_skill_bonus 0|1} {max_skill N} {stat_bonus 0|1}}
;                           effective skill = breed weapon skill + "weapon_skill" of the START rank (set/ability/veterancy.set, read
;                           from the mod, never hard-coded). Start rank = highest rank whose score is <= 0 in the breed's veterancy
;                           table (breed_vet start(N)). stat_bonus 1: the start rank's health/stamina bonus is added before {stat} weights.
;   {main_priority "class" ...}   which weapon group decides a soldier's class when he carries several (first found wins)
;   {skill_from_item 1}     the skill perk follows the main weapon's stuff folder (smg/rifle/mgun/pistol/bazooka/ptr) over the class {skill}
;   {weapon_group "id" {label} {skill "perk"} [{addon 1}] {tier "id" {label} {mp m1..m10} {cp c1..c10} {items ...}} ...}
;                           MP (score) and CP by effective skill level 1..10. {addon 1}: priced on top of the main weapon (panzerfaust).
;                           {sole 1}: a breed carrying an item of this group is priced ONLY by that item's tier (mp and cp of
;                           level 1; no skill table, no other kit, no veterancy, no stats). Owner rule: radiomen = their call-in item.
;   {special "id" {label} {mp M} {cp C} {cw W} [{card_mp N}] {breeds "side/breed" ...}}   fixed-price breeds (officers): own
;                           stats, not priced from the weapon tables. Seeded from the mod's rows with a negative CP (level_0_v2 /
;                           level_1_v2). {card_mp N}: the MP one such breed adds to a card sum (default M).
;                           tier "undetermined" {as "medium"}: items whose tier the sheet does not give; priced as the named tier
;                           until the owner moves them (finding TIER_UNDETERMINED). One item per line, `; comment` allowed.
;                           {tier "high" ... {when_carried "launcher" "ammo" ...}}: that launcher is priced in this tier when the
;                           breed also carries one of the ammo names (owner rule: rifle-grenade launchers by their load)
;   {throwable_score {groups ...} [{mode "armor"}] {energy} {penetration} {fire_radius} {range} {fuse} {cuts ...}}   computed hand-grenade tier
;   {throwable_price {mp_per_tier P} {cp_per_tier Q}}   per throwable carried: MP += P x tier x expected count, CP += Q x tier x count
;   {alias "model name" "spelling" ...}   other spellings of one item (same stuff file); unknown spellings that resolve to
;                           the same stuff file as a model item are matched too
;   {group "id" {label} {price P} {items ...}}                          flat equipment group: P MP per item carried
;   {group "id" {label} {tier "low" {price P} {items ...}} ... {tier "undetermined" {price 0} {items ...}}}
;                           tiered equipment group: quality steps inside one function (e.g. frag grenade: egg / stick / heavy)
;                           kit MP = sum over carried items of price x expected count ({item "x" centre spread} counts
;                           round(centre + uniform(-spread, spread)), never below 0)
;   {stat "name" {weight W} {base B} [{map "value" n ...}]}   extras MP = sum of W x (final stat - B); 0 = not priced
;                           stats: health stamina speed (perk factors, 2 = 200%), sight (vision preset via map), stealth (1 if the perk),
;                           avoidance, rocket (rocketlauncher skill), tankgun, at_rifle (skill levels)
;   {fixed_cp "label" {match "regex"} {single X} {not_single Y}}   support breeds with a fixed CP (sheet singles table);
;                           first match on the breed name wins; a breed name ending _single takes {single}
;   {weapon_group ... {cw_as "group" "tier"}}   CW of this group = the CP curve of that tier at the same level (mod: snipers = smg medium)
;   {cw_factor F}           cw = cp x F (the mod keeps cw = cp except deliberate overrides)
;   {squad ...}             card rules:
;     {addon "id" {price P} {match "regex" ...}}   transport add-on: a card whose only vehicle matches pays P on top of its members
;     {single "id" {classes "c" ...} [{min_level N}] {mult M}}   one soldier, no vehicle: member MP x M; first matching rule wins
;     {sequence "id" [{sides "s" ...}] [{cards "regex"}] {percent p1 p2 ...}}   sequence family: a sequence = the cards of one
;                           file with the same side and {icon N} that use a *seq* macro, in file order (buy 1, 2, ...) [I]. Buy k
;                           costs (its members' MP x factor) x p_k / 100; past the list the last p repeats. First family whose
;                           sides and card-name regex match wins. (Old form {sequence v1 v2 ...} = one family for every card.)
;     {modifier {side "s"} {card "name"} {factor F}}   per-card factor from the sheet panels (Other Modifier column)
;   cost = round((sum of member MP x count + add-on) x mult x factor, rounding cost). Vehicle and gun cards: hand-priced.
;   [I] in an item comment = put there by a guess (name / stuff folder / fuzzy sheet match): check it.
{price_model
	{version 1}
	{source "MP_1.30.8.tsv" "CP_1.30.8.tsv"}
	{rounding {mp 0.01} {cp 0.01} {cost 1}}
	{veterancy {apply_skill_bonus 1} {max_skill 10} {stat_bonus 1}}
	{main_priority "radio" "snipers" "flame" "at_rifles" "at" "mg" "light_mortar" "rifle_grenades" "auto_rifle" "carbines" "smg" "rifles" "pistol"}
	{skill_from_item 1}
	{cw_factor 1}

	; ---- weapon groups (sheet MP / CP tables; Items column -> tiers) ----
	{weapon_group "radio" {label "Radio"} {skill "rifle"} {sole 1}
		{tier "60" {label "call-in 60 [I] sheet Radio row 1 = calibre, row 2 = MP; cp = sheet singles Radio"}
			{mp 20 20 20 20 20 20 20 20 20 20}
			{cp 5 5 5 5 5 5 5 5 5 5}
			{items
				"mortar_60_flaregun"	; [I] call-in flare gun, calibre 60 in the name -> sheet Radio 60
			}
		}
		{tier "81" {label "call-in 81 [I] sheet Radio row 1 = calibre, row 2 = MP; cp = sheet singles Radio"}
			{mp 200 200 200 200 200 200 200 200 200 200}
			{cp 5 5 5 5 5 5 5 5 5 5}
			{items
				"airstrike_rp3_flaregun"	; owner rule: airstrike_rp3_flaregun = radio 81
				"mortar_flaergun"	; owner rule: mortar_flaergun = radio 81
			}
		}
		{tier "105" {label "call-in 105 [I] sheet Radio row 1 = calibre, row 2 = MP; cp = sheet singles Radio"}
			{mp 450 450 450 450 450 450 450 450 450 450}
			{cp 5 5 5 5 5 5 5 5 5 5}
			{items
				"artillery_105_flaregun"	; [I] call-in flare gun, calibre 105 in the name -> sheet Radio 105
			}
		}
		{tier "155" {label "call-in 155 [I] sheet Radio row 1 = calibre, row 2 = MP; cp = sheet singles Radio"}
			{mp 550 550 550 550 550 550 550 550 550 550}
			{cp 5 5 5 5 5 5 5 5 5 5}
			{items
				"artillery_155_flaregun"	; [I] call-in flare gun, calibre 155 in the name -> sheet Radio 155
			}
		}
		{tier "240" {label "call-in 240 [I] sheet Radio row 1 = calibre, row 2 = MP; cp = sheet singles Radio"}
			{mp 700 700 700 700 700 700 700 700 700 700}
			{cp 5 5 5 5 5 5 5 5 5 5}
			{items
				"artillery_240_flaregun"	; [I] call-in flare gun, calibre 240 in the name -> sheet Radio 240
			}
		}
		{tier "undetermined" {as "81"}
			{items
			}
		}
	}
	{weapon_group "snipers" {label "snipers"} {skill "rifle"} {cw_as "smg" "medium"}
		{tier "medium" {label "medium"}
			{mp 30 30 50 55 60 70 72.5 75 77.5 80}
			{cp 0.58 0.7 1.11 1.56 2.05 2.77 3.34 3.93 4.55 5.19}
			{items
				"carcano_m91_scoped"	; [I] stuff rifle/sniper/carcano_m91_scoped; the only tier of the sheet class
				"em2"	; [I] stuff rifle/sniper/em2; the only tier of the sheet class
				"em2_vet"	; [I] stuff rifle/sniper/em2_vet; the only tier of the sheet class
				"fg42_sc"	; [I] stuff rifle/fg42_sc (scoped name); the only tier of the sheet class
				"g43_scope"	; [I] stuff rifle/g43_scope (scoped name); the only tier of the sheet class
				"m1903a4"	; [I] stuff rifle/sniper/m1903a4; the only tier of the sheet class
				"m3_carbine"	; [I] stuff rifle/sniper/m3_carbine; the only tier of the sheet class
				"mauzer_s"	; [I] stuff rifle/sniper/mauzer_s; the only tier of the sheet class
				"mauzer_s_vet"	; [I] stuff rifle/sniper/mauzer_s_vet; the only tier of the sheet class
				"mosin_s"	; [I] stuff rifle/sniper/mosin_s; the only tier of the sheet class
				"mosin_s_elite"	; [I] stuff rifle/sniper/mosin_s_elite; the only tier of the sheet class
				"mosin_s_fin"	; [I] stuff rifle/sniper/mosin_s_fin; the only tier of the sheet class
				"mosin_s_vet"	; [I] stuff rifle/sniper/mosin_s_vet; the only tier of the sheet class
				"svt40_s"	; [I] stuff rifle/svt40_s (scoped name); the only tier of the sheet class
				"svt40_s_vet"	; [I] stuff rifle/svt40_s_vet (scoped name); the only tier of the sheet class
				"type97sniper"	; [I] stuff rifle/sniper/type97sniper; the only tier of the sheet class
				"type99sniper"	; [I] stuff rifle/sniper/type99sniper; the only tier of the sheet class
			}
		}
		{tier "undetermined" {as "medium"}
			{items
			}
		}
	}
	{weapon_group "flame" {label "Flame"} {skill "rifle"}
		{tier "medium" {label "medium"}
			{mp 40 -1 -1 -1 -1 -1 -1 -1 -1 -1}
			{cp 1.44 1.44 1.44 1.44 1.44 1.93 2.44 2.97 3.52 4.09}
			{items
				"flame_thrower"	; [I] stuff flame/flame_thrower; the only tier of the sheet class
				"flame_thrower_g"	; [I] stuff flame/flame_thrower_g; the only tier of the sheet class
			}
		}
		{tier "undetermined" {as "medium"}
			{items
			}
		}
	}
	{weapon_group "at_rifles" {label "AT Rifles"} {skill "at_rifle"}
		{tier "low" {label "low"}
			{mp 24 27 30 33 36 39 42 45 48 51}
			{cp 0.4 0.4 0.58 0.97 1.44 1.93 2.44 2.97 3.52 4.09}
			{items
				"boyes"	; [I] sheet at_rifles low "boys"
			}
		}
		{tier "medium" {label "medium"}
			{mp 35 40 45 50 55 60 65 70 75 80}
			{cp 0.4 0.4 0.58 0.97 1.44 1.93 2.44 2.97 3.52 4.09}
			{items
				"ptrd"	; [I] sheet at_rifles medium "ptrd"
				"pzb39"	; [I] sheet at_rifles medium "pzb"
				"type_97_antitank"	; [I] sheet at_rifles medium "Type 97"
			}
		}
		{tier "high" {label "high (ptrs)"}
			{mp 40 45 55 60 70 75 80 85 90 95}
			{cp 0.4 0.4 0.58 0.97 1.44 1.93 2.44 2.97 3.52 4.09}
			{items
				"ptrs"	; [I] sheet at_rifles high "ptrs"
			}
		}
		{tier "undetermined" {as "medium"}
			{items
			}
		}
	}
	{weapon_group "at" {label "AT"} {skill "rocketlauncher"}
		{tier "low" {label "low"}
			{mp 14 17 20 23 25.5 28 30.5 33 35.5 38}
			{cp 0.4 0.4 0.6 0.97 1.34 1.73 2.14 2.55 2.97 3.4}
			{items
				"weapon bazooka"	; [I] sheet at low "m1 bazooka"
			}
		}
		{tier "medium" {label "medium"}
			{mp 20 25 30 35 37.5 40 42.5 45 47.5 50}
			{cp 0.4 0.4 0.6 0.97 1.34 1.73 2.14 2.55 2.97 3.4}
			{items
				"weapon bazooka_m9"	; [I] sheet at medium "m9 bazooka"
				"weapon m18recoilless"	; [I] sheet at medium "m18"
				"weapon weapon type_4at"	; [I] sheet at medium "type 4 rocket"
			}
		}
		{tier "high" {label "high"}
			{mp 35 40 45 50 52.5 55 57.5 60 62.5 65}
			{cp 0.4 0.4 0.68 1.09 1.54 2 2.49 2.99 3.51 4.04}
			{items
				"weapon panzershreck"	; [I] sheet at high "panzershreck"
				"weapon piatrocket"	; [I] sheet at high "piat"
			}
		}
		{tier "undetermined" {as "medium"}
			{items
			}
		}
	}
	{weapon_group "mg" {label "Machine Guns"} {skill "mgun"}
		{tier "low" {label "low"}
			{mp 15 20 30 35 40 42.5 45 47.5 50 52.5}
			{cp 0.58 0.7 1.11 1.56 2.05 2.56 3.09 3.64 4.22 4.81}
			{items
				"breda_30"	; [I] sheet mg low "breda30"
				"bren"	; [I] sheet mg low "bren"
				"dp"	; [I] sheet mg low "dp27"
				"lsm26"	; owner rule: lsm26 = mg low
				"solothurn_31m"	; [I] sheet mg low "solothurn 31m"
				"type11_mg"	; [I] sheet mg low "type11"
				"type96_mg"	; owner rule: type96_mg = mg low
				"type99_mg"	; [I] sheet mg low "type 99"
				"type99rifle_bayonet_melee"	; [I] sheet mg low "type 99"
				"zb30"	; [I] sheet mg low "zb30"
				"zb_30lmg"	; [I] sheet mg low "zb30"
				"zb_vz26"	; [I] sheet mg low "zb26"
			}
		}
		{tier "medium" {label "medium"}
			{mp 20 25 35 45 50 52.5 55 57.5 60 62.5}
			{cp 0.58 0.82 1.24 1.72 2.23 2.77 3.34 3.93 4.55 5.19}
			{items
				"browning_m19a6"	; [I] sheet mg medium "m1919a6"
				"dt"	; [I] sheet mg medium "dt"
				"mg34"	; [I] sheet mg medium "mg34"
				"type99_mg_scoped"	; [I] sheet mg medium "type 99 scoped"
			}
		}
		{tier "high" {label "high"}
			{mp 25 35 40 55 60 62.5 65 67.5 70 72.5}
			{cp 0.58 0.87 1.32 1.81 2.34 2.91 3.51 4.14 4.8 5.47}
			{items
				"mg42_inf"	; [I] sheet mg high "mg42"
				"mg42_inf_250"	; [I] sheet mg high "mg42"
			}
		}
		{tier "undetermined" {as "medium"}
			{items
			}
		}
	}
	{weapon_group "light_mortar" {label "light mortar"} {skill "rifle"}
		{tier "medium" {label "medium"}
			{mp 34 34 40 43 46 49 51 54 57 60}
			{cp 0.4 0.4 0.58 0.97 1.44 1.93 2.44 2.97 3.52 4.09}
			{items
				"mortar_legrw_36"	; owner rule: mortar_legrw_36 = light_mortar medium
				"mortar_mkvii"	; owner rule: mortar_mkvii = light_mortar medium
			}
		}
		{tier "smoke_only" {label "smoke only"}
			{mp 17 17 20 22 23 25 25 25 25 25}
			{cp 0.4 0.4 0.6 0.97 1.34 1.73 2.14 2.55 2.97 3.4}
			{items
			}
		}
		{tier "undetermined" {as "medium"}
			{items
			}
		}
	}
	{weapon_group "rifle_grenades" {label "Rifle Grenades"} {skill "rifle"}
		{tier "medium" {label "medium"}
			{mp 10 10 20 25 30 35 40 45 50 55}
			{cp 0.4 0.4 0.58 0.97 1.44 2.77 3.34 3.93 4.55 5.19}
			{items
				"garand_grenade"	; owner rule: rifle grenade launcher = medium unless {when_carried} (stuff rifle/garand_grenade)
				"k98_gewehrgranat"	; owner rule: rifle grenade launcher = medium unless {when_carried} (stuff rifle/k98_gewehrgranat)
				"type89_grenadelauncher"	; owner rule: rifle grenade launcher = medium unless {when_carried} (stuff rifle/type89_grenadelauncher)
			}
		}
		{tier "low_jap" {label "Low (jap)"}
			{mp -1 -1 10 15 20 25 30 -1 -1 -1}
			{cp -1 -1 10 0.97 1.44 1.93 2.44 2.97 3.52 4.09}
			{items
			}
		}
		{tier "high" {label "[I] not in the sheet: copy of medium until the owner sets it"}
			{mp 10 10 20 25 30 35 40 45 50 55}
			{cp 0.4 0.4 0.58 0.97 1.44 2.77 3.34 3.93 4.55 5.19}
			{when_carried "garand_grenade" "m1garand_grenade wp"}	; owner rule: WP rifle grenade
			{when_carried "k98_gewehrgranat" "k98_grenade ap2"}	; highest penetration in stuff k98_gewehrgranat projectileDamageTable: ap2=130 ap3=90 ap=70
			{items
			}
		}
		{tier "undetermined" {as "medium"}
			{items
			}
		}
	}
	{weapon_group "auto_rifle" {label "Auto rifle"} {skill "rifle"}
		{tier "medium" {label "medium"}
			{mp -1 -1 20 24 28 32 36 40 44 48}
			{cp 0.58 0.7 1.11 1.56 2.05 2.56 3.09 3.64 4.22 4.81}
			{items
				"bar_rifle"	; [I] stuff rifle/bar_rifle (automatic rifle (BAR / FG42 / Johnson LMG)); the only tier of the sheet class
				"fg42_rifle"	; [I] stuff rifle/fg42_rifle (automatic rifle (BAR / FG42 / Johnson LMG)); the only tier of the sheet class
			}
		}
		{tier "undetermined" {as "medium"}
			{items
			}
		}
	}
	{weapon_group "carbines" {label "Carbines"} {skill "rifle"}
		{tier "low" {label "Low"}
			{mp 10 10 12 14 16 18 20 22 24 26}
			{cp 0.4 0.4 0.68 1.09 1.54 2 2.49 2.99 3.51 4.04}
			{items
				"m1_carbine"	; [I] sheet carbines low "m1 carbine"
				"m1a1_carbine"	; [I] sheet carbines low "m1 carbine"
				"type44_carbine"	; [I] sheet carbines low "type 44"
				"vsg"	; [I] sheet carbines low "volksgewher"
			}
		}
		{tier "medium" {label "Medium"}
			{mp 11 11 14 16 18 20 22 24 26 28}
			{cp 0.4 0.4 0.68 1.09 1.54 2 2.49 2.99 3.51 4.04}
			{items
				"m2_carbine"	; [I] sheet carbines medium "m2 carbine"
			}
		}
		{tier "high" {label "High"}
			{mp 12 12 16 18 20 22 24 26 28 30}
			{cp 0.58 0.7 1.11 1.56 2.05 2.56 3.09 3.64 4.22 4.81}
			{items
				"mkb42"	; [I] sheet carbines high "stg"
				"mp43"	; [I] sheet carbines high "stg"
				"sg44"	; [I] sheet carbines high "stg"
			}
		}
		{tier "undetermined" {as "medium"}
			{items
			}
		}
	}
	{weapon_group "smg" {label "SMG"} {skill "smg"}
		{tier "low" {label "low"}
			{mp 7 8 11 11 12 13 14 15 16 17}
			{cp 0.4 0.4 0.58 0.97 1.44 1.93 2.44 2.97 3.52 4.09}
			{items
				"mp3008"	; [I] sheet smg low "mp3008"
				"sten_mk2"	; [I] sheet smg low "sten"
				"sten_v"	; [I] sheet smg low "sten"
				"sten_v_silencer"	; [I] sheet smg low "sten"
				"type100_44"	; [I] sheet smg low "type 100"
				"type100_44_bayonet"	; [I] sheet smg low "type 100"
				"type100smg"	; [I] sheet smg low "type 100"
				"type100smg_bayonet"	; [I] sheet smg low "type 100"
			}
		}
		{tier "medium" {label "medium"}
			{mp 7 9 12 12 14 16 18 20 22 24}
			{cp 0.4 0.4 0.58 0.97 1.44 1.93 2.44 2.97 3.52 4.09}
			{items
				"m12_shotgun"	; [I] sheet smg medium "m12 shotgun"
				"m3a"	; owner rule: m3a = smg medium
				"m50reising"	; [I] sheet smg medium "m50 reising"
				"mp28"	; [I] sheet smg medium "mp28"
				"mp38"	; owner rule: mp38 = smg medium
				"mp40"	; [I] sheet smg medium "mp40"
				"mp41"	; [I] sheet smg medium "mp41"
				"orita"	; owner rule: orita = smg medium
				"owen_gun"	; [I] sheet smg medium "owen"
				"ppsh"	; [I] sheet smg medium "ppsh"
				"ppsh41"	; [I] sheet smg medium "ppsh"
				"thompson"	; owner rule: thompson = smg medium
				"type2smg"	; [I] sheet smg medium "type 2"
			}
		}
		{tier "high" {label "high"}
			{mp 7 10 13 13 15 17 19 21 23 25}
			{cp 0.4 0.4 0.58 0.97 1.44 1.93 2.44 2.97 3.52 4.09}
			{items
				"danuvia_39m"	; [I] sheet smg high "danuavia"
				"danuvia_43m"	; [I] sheet smg high "danuavia"
				"mab_38a"	; [I] sheet smg high "mab38"
				"pps43"	; [I] sheet smg high "pps43"
				"suomi_m31"	; [I] sheet smg high "suomi"
				"suomi_m31r"	; [I] sheet smg high "suomi"
				"thompson_50"	; [I] sheet smg high "thompson 50"
			}
		}
		{tier "undetermined" {as "medium"}
			{items
			}
		}
	}
	{weapon_group "rifles" {label "Rifles"} {skill "rifle"}
		{tier "low" {label "low"}
			{mp 7 8 9 9 10 11 12 13 14 15}
			{cp 0.4 0.4 0.6 0.97 1.34 1.73 2.14 2.55 2.97 3.4}
			{items
				"carcano_m91"	; [I] sheet rifles low "carcanno"
				"feg_35m"	; [I] sheet rifles low "feg"
				"feg_43m"	; [I] sheet rifles low "feg"
				"m1903"	; [I] sheet rifles low "springfield"
				"m38_carcano"	; [I] sheet rifles low "carcanno"
				"m9138_carcano"	; [I] sheet rifles low "carcanno"
				"mannlicher_m1895"	; [I] sheet rifles low "manlicher"
				"mauzer"	; [I] sheet rifles low "kar98"
				"mosin"	; [I] sheet rifles low "mosin"
				"mosin_fin"	; [I] sheet rifles low "mosin"
				"type2rifle"	; [I] sheet rifles low "TERA"
				"type38rifle"	; [I] sheet rifles low "type 38"
				"type38rifle_bayonet"	; [I] sheet rifles low "type 38"
				"type99rifle"	; [I] sheet rifles low "type 99"
				"type99rifle_at"	; [I] sheet rifles low "type 99"
				"type99rifle_bayonet"	; [I] sheet rifles low "type 99"
				"zb_24rifle"	; [I] sheet rifles low "zb24"
			}
		}
		{tier "medium" {label "medium(lee enfeild)"}
			{mp 10 11 13 13 15 18 21 22 23 24}
			{cp 0.4 0.4 0.6 0.97 1.34 1.73 2.14 2.55 2.97 3.4}
			{items
				"de_lisle"	; owner rule: de_lisle = rifles medium
				"em3"	; [I] sheet rifles medium "lee enfield"
				"em3_mark1"	; [I] sheet rifles medium "lee enfield"
			}
		}
		{tier "high" {label "high (semi auto)"}
			{mp 9 9 13 13 15 18 21 22 23 24}
			{cp 0.4 0.4 0.68 1.09 1.54 2 2.49 2.99 3.51 4.04}
			{items
				"g41"	; [I] sheet rifles high "g41"
				"g43"	; [I] sheet rifles high "g43"
				"garand"	; [I] sheet rifles high "m1 garand"
				"johnson"	; [I] sheet rifles high "johnson"
				"johnson_m1941_rifle"	; [I] sheet rifles high "johnson"
				"scottix"	; owner rule: scottix = rifles high
				"svt40"	; [I] sheet rifles high "svt"
				"type_4_rifle"	; [I] sheet rifles high "type4"
			}
		}
		{tier "vet" {label "vet rifles"}
			{mp -1 -1 -1 -1 14 16 18 20 22 24}
			{cp -1 -1 -1 -1 1.54 2 2.49 2.99 3.51 4.04}
			{items
				"em3_vet"	; [I] sheet rifles medium "lee enfield", name ends _vet -> vet rifles
				"mauzer_vet"	; [I] sheet rifles low "kar98", name ends _vet -> vet rifles
				"mosin_vet"	; [I] sheet rifles low "mosin", name ends _vet -> vet rifles
			}
		}
		{tier "undetermined" {as "medium"}
			{items
			}
		}
	}
	{weapon_group "pistol" {label "pistol (not in the sheet)"} {skill "pistol"}
		{tier "flat" {label "owner rule: pistols have no tiers; not in the sheet (0 until set)"}
			{mp 0 0 0 0 0 0 0 0 0 0}
			{cp 0 0 0 0 0 0 0 0 0 0}
			{items
				"beretta_m1934"	; owner rule: pistols have no tiers (stuff pistol/beretta_m1934)
				"bodeo_m1889"	; owner rule: pistols have no tiers (stuff pistol/bodeo_m1889)
				"colt"	; owner rule: pistols have no tiers (stuff pistol/colt)
				"frommer_37m"	; owner rule: pistols have no tiers (stuff pistol/frommer_37m)
				"glisenti"	; owner rule: pistols have no tiers (stuff pistol/glisenti)
				"luger"	; owner rule: pistols have no tiers (stuff pistol/luger)
				"nagan"	; owner rule: pistols have no tiers (stuff pistol/nagan)
				"nambu"	; owner rule: pistols have no tiers (stuff pistol/nambu)
				"steyer_pistol_1912"	; owner rule: pistols have no tiers (stuff pistol/steyer_pistol_1912)
				"tt"	; owner rule: pistols have no tiers (stuff pistol/tt)
				"valter"	; owner rule: pistols have no tiers (stuff pistol/valter)
				"webley"	; owner rule: pistols have no tiers (stuff pistol/webley)
			}
		}
	}
	{weapon_group "pzf" {label "pzf"} {skill "rocketlauncher"} {addon 1}
		{tier "low" {label "Low"}
			{mp 3 6 7 8 8 8 8 8 8 8}
			{cp 0.4 0.4 0.7 1.14 1.61 2.11 2.63 3.17 3.73 4.3}
			{items
				"faustpatrone_30 weapon"	; [I] sheet pzf low "faust"
				"panzerfaust weapon"	; owner rule: panzerfaust = pzf low
				"panzerfaust_30 weapon"	; [I] sheet pzf low "faust"
			}
		}
		{tier "medium" {label "Medium"}
			{mp 4 7 8 9 10 10 10 10 10 10}
			{cp 0.4 0.4 0.7 1.14 1.61 2.11 2.63 3.17 3.73 4.3}
			{items
				"panzerfaust_60 weapon"	; [I] sheet pzf medium "60"
			}
		}
		{tier "high" {label "High"}
			{mp 5 9 11 13 15 15 15 15 15 15}
			{cp 0.4 0.4 0.7 1.14 1.61 2.11 2.63 3.17 3.73 4.3}
			{items
			}
		}
		{tier "undetermined" {as "medium"}
			{items
			}
		}
	}

	; ---- equipment groups (one function each; tiers = quality steps; price in MP per item) ----
	{group "frag_grenade" {label "hand frag grenade"} {price 0}
		{items
			"breda35"	; [I] stuff grenade/01 grenade_ap/breda35.grenade
			"grenade f1"	; [I] stuff grenade/01 grenade_ap/f1.grenade
			"grenade hungarian_36m"	; [I] stuff grenade/01 grenade_ap/hungarian_36m.grenade
			"grenade hungarian_42m"	; [I] stuff grenade/01 grenade_ap/hungarian_42m.grenade
			"grenade m24"	; [I] stuff grenade/01 grenade_ap/m24.grenade
			"grenade m39"	; [I] stuff grenade/01 grenade_ap/m39.grenade
			"grenade m61"	; [I] stuff grenade/01 grenade_ap/m61.grenade
			"grenade mk1"	; [I] stuff grenade/01 grenade_ap/mk1.grenade
			"grenade oto_mod35"	; [I] stuff grenade/01 grenade_ap/oto_mod35.grenade
			"grenade type97"	; [I] stuff grenade/01 grenade_ap/type97.grenade
			"grenade type99"	; [I] stuff grenade/01 grenade_ap/type99.grenade
		}
	}
	{group "at_grenade" {label "anti-tank hand grenade"} {price 0}
		{items
			"breda42at"	; [I] stuff grenade/02 grenade_at/breda42at.grenade
			"grenade hohlladung"	; [I] stuff grenade/02 grenade_at/hohlladung.grenade
			"grenade n73at"	; [I] stuff grenade/02 grenade_at/n73at.grenade
			"grenade pwm1"	; [I] stuff grenade/02 grenade_at/pwm1.grenade
			"grenade rpg40"	; [I] stuff grenade/02 grenade_at/rpg40.grenade
			"grenade rpg43"	; [I] stuff grenade/02 grenade_at/rpg43.grenade
			"grenade type3at_a"	; [I] stuff grenade/02 grenade_at/type3at_a.grenade
			"grenade type99at"	; [I] stuff grenade/02 grenade_at/type99at.grenade
		}
	}
	{group "bundle_charge" {label "bundle / satchel charge"} {price 0}
		{items
			"grenade m24x5"	; [I] stuff grenade/02 grenade_at/m24x5.grenade
			"grenade rg42x3"	; [I] stuff grenade/02 grenade_at/rg42x3.grenade
			"grenade satchel"	; [I] stuff grenade/01 grenade_ap/satchel.grenade
			"kasapanos_2kg"	; [I] stuff grenade/kasapanos_2kg.grenade
			"kasapanos_4kg"	; [I] stuff grenade/kasapanos_4kg.grenade
		}
	}
	{group "smoke_grenade" {label "smoke grenade"} {price 0}
		{items
			"grenade ccm34smoke"	; [I] stuff grenade/00 grenade_smoke/ccm34smoke.grenade
			"grenade m15_smoke"	; [I] stuff grenade/00 grenade_smoke/m15_smoke.grenade
			"grenade n77_smoke"	; [I] stuff grenade/00 grenade_smoke/n77_smoke.grenade
			"grenade smoke"	; [I] stuff grenade/00 grenade_smoke/smoke.grenade
			"grenade smoke_paradrop_ammo"	; [I] stuff grenade/00 grenade_smoke/smoke_paradrop_ammo.grenade
			"grenade smoke_paradrop_ammo_heavy"	; [I] stuff grenade/00 grenade_smoke/smoke_paradrop_ammo_heavy.grenade
			"smoke_candle"	; [I] stuff grenade/00 grenade_smoke/smoke_candle.grenade
		}
	}
	{group "incendiary" {label "incendiary (molotov, flame grenade)"} {price 0}
		{items
			"grenade molotov_coctail"	; [I] stuff grenade/02 grenade_at/molotov_coctail.grenade
			"oto42flam"	; [I] stuff grenade/02 grenade_at/oto42flam.grenade
		}
	}
	{group "ap_mine" {label "anti-personnel mine"} {price 0}
		{items
			"mine antipersonnel"	; [I] stuff explosive/antipersonnel.mine
			"mine s_mine"	; [I] stuff explosive/s_mine.antipersonnel.mine
		}
	}
	{group "at_mine" {label "anti-tank mine"} {price 0}
		{items
			"mine antitank"	; [I] stuff explosive/antitank.mine
		}
	}
	{group "demolition_charge" {label "demolition charge (dynamite, ladung)"} {price 0}
		{items
			"dynamite"	; [I] stuff explosive/dynamite
			"dynamite_ladung"	; [I] stuff explosive/dynamite_ladung
		}
	}
	{group "cumulative_charge" {label "shaped charge"} {price 0}
		{items
		}
	}
	{group "rifle_grenade_frag" {label "rifle grenade, frag"} {price 0}
		{items
			"ammo rifle_grenade"	; [I] stuff ammo/rifle_grenade.ammo
			"k98_grenade fg"	; [I] stuff ammo/k98_grenade.fg.ammo
			"m1garand_grenade fg"	; [I] stuff ammo/m1garand_grenade.fg.ammo
		}
	}
	{group "rifle_grenade_at" {label "rifle grenade, anti-tank (AP)"} {price 0}
		{items
			"ammo rifle_grenade_at"	; [I] stuff ammo/rifle_grenade_at.ammo
			"k98_grenade ap"	; [I] stuff ammo/k98_grenade.ap.ammo
			"k98_grenade ap2"	; [I] stuff ammo/k98_grenade.ap2.ammo
			"k98_grenade ap3"	; [I] stuff ammo/k98_grenade.ap3.ammo
			"m1garand_grenade ap"	; [I] stuff ammo/m1garand_grenade.ap.ammo
		}
	}
	{group "rifle_grenade_wp" {label "rifle grenade, white phosphorus"} {price 0}
		{items
			"m1garand_grenade wp"	; [I] stuff ammo/m1garand_grenade.wp.ammo
		}
	}
	{group "rifle_grenade_smoke" {label "rifle grenade, smoke"} {price 0}
		{items
		}
	}
	{group "ammo_ptr" {label "AT rifle ammunition"} {price 0}
		{items
			"ammo ptr"	; [I] stuff ammo/ptr.ammo
			"ammo ptr fg"	; [I] stuff ammo/ptr.fg.ammo
		}
	}
	{group "ammo_small_arms" {label "small-arms ammunition (magazines, clips, belts)"} {price 0}
		{items
			"ammo 10x20"	; [I] stuff ammo/10x20.ammo
			"ammo 6x52"	; [I] stuff ammo/6x52.ammo
			"ammo 7x51"	; [I] stuff ammo/7x51.ammo
			"ammo 7x53"	; [I] stuff ammo/7x53.ammo
			"ammo 7x57"	; [I] stuff ammo/7x57.ammo
			"ammo 8x50"	; [I] stuff ammo/8x50.ammo
			"ammo 8x56"	; [I] stuff ammo/8x56.ammo
			"ammo 9x17"	; [I] stuff ammo/9x17.ammo
			"ammo 9x19"	; [I] stuff ammo/9x19.ammo
			"ammo 9x19c"	; [I] stuff ammo/9x19c.ammo
			"ammo 9x25"	; [I] stuff ammo/9x25.ammo
			"ammo arisaka6-5_clip"	; [I] stuff ammo/magazines/arisaka6-5_clip.ammo
			"ammo arisaka7-7_clip"	; [I] stuff ammo/magazines/arisaka7-7_clip.ammo
			"ammo bar_mag"	; [I] stuff ammo/magazines/bar_mag.ammo
			"ammo breda_mag"	; [I] stuff ammo/magazines/breda_mag.ammo
			"ammo bren_mag"	; [I] stuff ammo/magazines/bren_mag.ammo
			"ammo british303_clip"	; [I] stuff ammo/magazines/british303_clip.ammo
			"ammo colt_mag"	; [I] stuff ammo/magazines/colt_mag.ammo
			"ammo dp27_mag"	; [I] stuff ammo/magazines/dp27_mag.ammo
			"ammo dt29_mag"	; [I] stuff ammo/magazines/dt29_mag.ammo
			"ammo fg42_mag"	; [I] stuff ammo/magazines/fg42_mag.ammo
			"ammo g43_mag"	; [I] stuff ammo/magazines/g43_mag.mauser.ammo
			"ammo garand_clip"	; [I] stuff ammo/magazines/garand_clip.ammo
			"ammo lsm26_mag"	; [I] stuff ammo/magazines/lsm26_mag.ammo
			"ammo m1941lmg_mag"	; [I] stuff ammo/magazines/m1941lmg_mag.ammo
			"ammo m1carbine_mag"	; [I] stuff ammo/magazines/m1carbine_mag.ammo
			"ammo m2carbine_mag"	; [I] stuff ammo/magazines/m2carbine_mag.ammo
			"ammo m3a_mag"	; [I] stuff ammo/magazines/m3a_mag.ammo
			"ammo m50reising_mag"	; [I] stuff ammo/magazines/m50reising_mag.ammo
			"ammo mab_38a_mag"	; [I] stuff ammo/magazines/mab_38a_mag.ammo
			"ammo mauser_clip"	; [I] stuff ammo/magazines/mauser_clip.mauser.mauser_rifle.ammo
			"ammo mauser_clip fg"	; [I] stuff ammo/magazines/mauser_clip.mauser.mauser_rifle.fg.ammo
			"ammo mauser_rifle mauser"	; [I] no stuff file found; group by name
			"ammo mg_mauser belt"	; [I] stuff ammo/magazines/mg_mauser.belt.ammo
			"ammo mg_mauser drum"	; [I] stuff ammo/magazines/mg_mauser.drum.ammo
			"ammo mosin_clip"	; [I] stuff ammo/magazines/mosin_clip.mosin54r.mosin_rifle.ammo
			"ammo mosin_clip fg"	; [I] stuff ammo/magazines/mosin_clip.mosin54r.mosin_rifle.fg.ammo
			"ammo mp28_mag"	; [I] stuff ammo/magazines/mp28_mag.ammo
			"ammo mp40_mag"	; [I] stuff ammo/magazines/mp40_mag.ammo
			"ammo nagant_clip"	; [I] stuff ammo/magazines/nagant_clip.ammo
			"ammo nambu_mag"	; [I] stuff ammo/magazines/nambu_mag.ammo
			"ammo owen_mag"	; [I] stuff ammo/magazines/owen_mag.ammo
			"ammo pps43_mag"	; [I] stuff ammo/magazines/pps43_mag.ammo
			"ammo ppsh41_mag"	; [I] stuff ammo/magazines/ppsh41_mag.ammo
			"ammo ppsh_mag"	; [I] stuff ammo/magazines/ppsh_mag.ppsh_ammo.ammo
			"ammo rifle"	; [I] stuff ammo/rifle.ammo
			"ammo shotgun"	; [I] stuff ammo/shotgun.ammo
			"ammo solothurn31m_mag"	; [I] stuff ammo/magazines/solothurn31m_mag.ammo
			"ammo springfield_belt"	; [I] stuff ammo/magazines/springfield_belt.ammo
			"ammo springfield_clip"	; [I] stuff ammo/magazines/springfield_clip.ammo
			"ammo sten_mag"	; [I] stuff ammo/magazines/sten_mag.ammo
			"ammo stg44_mag"	; [I] stuff ammo/magazines/stg44_mag.ammo
			"ammo svt40_mag"	; [I] stuff ammo/magazines/svt40_mag.mosin54r.ammo
			"ammo thompson_m1a1_mag"	; [I] stuff ammo/magazines/thompson_m1a1_mag.ammo
			"ammo tt_mag"	; [I] stuff ammo/magazines/tt_mag.ammo
			"ammo type100_mag"	; [I] stuff ammo/magazines/type100_mag.ammo
			"ammo type2_mag"	; [I] stuff ammo/magazines/type2_mag.ammo
			"ammo type96_mag"	; [I] stuff ammo/magazines/type96_mag.ammo
			"ammo type99_mag"	; [I] stuff ammo/magazines/type99_mag.ammo
			"ammo walther_mag"	; [I] stuff ammo/magazines/walther_mag.ammo
			"ammo webley_clip"	; [I] stuff ammo/magazines/webley_clip.ammo
			"ammo zb30_mag"	; [I] stuff ammo/magazines/zb30_mag.ammo
			"ammo zb_vz26_mag"	; [I] stuff ammo/magazines/zb_vz26_mag.ammo
			"thompson_drum"	; [I] stuff ammo/magazines/thompson_drum.ammo
		}
	}
	{group "call_in" {label "flare gun / call-in item"} {price 0}
		{items
		}
	}
	{group "call_in_ammo" {label "flare / call-in ammunition"} {price 0}
		{items
			"ammo airstrike_rp3_flare"	; [I] stuff ammo/airstrike_rp3_flare.ammo
			"ammo artillery_105_flare"	; [I] stuff ammo/artillery_105_flare.ammo
			"ammo artillery_155_flare"	; [I] stuff ammo/artillery_155_flare.ammo
			"ammo artillery_240_flare"	; [I] stuff ammo/artillery_240_flare.ammo
			"ammo mortar_60_flare"	; [I] stuff ammo/mortar_60_flare.ammo
			"ammo mortar_flaer"	; [I] stuff ammo/mortar_flaer.ammo
		}
	}
	{group "bandage" {label "bandage"} {price 0}
		{items
			"bandage"	; [I] stuff med/bandage
		}
	}
	{group "medkit" {label "medkit"} {price 0}
		{items
		}
	}
	{group "morphine" {label "morphine"} {price 0}
		{items
		}
	}
	{group "binocular" {label "binocular"} {price 0}
		{items
			"binocular"	; [I] stuff special/binocular
		}
	}
	{group "shovel" {label "shovel / spade"} {price 8}	; [I] sheet "Shovel" 8
		{items
			"small_inf_shovel"	; [I] no stuff file found; group by name
			"small_shovel"	; [I] stuff special/small_shovel
			"spider_hole_spade"	; [I] stuff special/spider_hole_spade
			"trench_spade"	; [I] stuff special/trench_spade
			"tunnel_spade"	; [I] stuff special/tunnel_spade
		}
	}
	{group "sandbag_kit" {label "sandbag kit"} {price 0}
		{items
			"sandbag_kit"	; [I] stuff special/sandbag_kit
		}
	}
	{group "barbwire_kit" {label "barbed wire kit"} {price 0}
		{items
			"barbwire_kit"	; [I] stuff special/barbwire_kit
		}
	}
	{group "hedgehog_kit" {label "tank hedgehog kit"} {price 0}
		{items
			"hedgehog_kit"	; [I] stuff special/hedgehog_kit
		}
	}
	{group "mine_detector" {label "mine detector"} {price 0}
		{items
			"mine_detector"	; [I] stuff special/mine_detector
		}
	}
	{group "repair_kit" {label "repair kit"} {price 0}
		{items
			"repair_kit"	; [I] stuff special/repair_kit
		}
	}
	{group "wirecutters" {label "wire cutters"} {price 0}
		{items
		}
	}
	{group "camouflage" {label "camouflage (plant, tree)"} {price 0}
		{items
			"plant"	; [I] stuff special/plant
			"tree"	; [I] stuff special/tree
		}
	}
	{group "backpack" {label "backpack, roll, barrel case (carried kit)"} {price 0}
		{items
			"barrel_case"	; [I] stuff body/barrel_case
			"ita_pack1"	; [I] stuff packs/ita_pack1
			"mg_backpack"	; [I] stuff packs/mg_backpack
			"ru_backpack_meshok"	; [I] stuff body/ru_backpack_meshok
			"ru_backpack_meshok2"	; [I] stuff body/ru_backpack_meshok2
			"ru_roll"	; [I] stuff body/ru_roll
		}
	}
	{group "melee" {label "knife / melee item"} {price 0}
		{items
			"knife_fin"	; [I] no stuff file found; group by name
			"knife_ger"	; [I] stuff melee/knife_ger
			"knife_japan"	; [I] stuff melee/knife_japan
			"knife_rus"	; [I] stuff melee/knife_rus
			"knife_union"	; [I] stuff melee/knife_union
		}
	}
	{group "ammo_box" {label "ammo box"} {price 0}
		{items
			"ammo_box_inf_fin"	; [I] no stuff file found; group by name
		}
	}
	{group "fuel" {label "fuel can"} {price 0}
		{items
		}
	}
	{group "flame_fuel" {label "flamethrower fuel tank"} {price 0}
		{items
			"balloon"	; [I] stuff flame/balloon
			"balloon_g"	; [I] stuff flame/balloon_g
		}
	}
	{group "helmet" {label "helmet (armour, head)"} {price 0}
		{items
			"helmet1_bul"	; [I] armour slot head
			"helmet1_hun"	; [I] armour slot head
			"helmet1_rus"	; [I] armour slot head
			"helmet1_usa"	; [I] armour slot head
			"helmet2_eng"	; [I] armour slot head
			"helmet2_usa"	; [I] armour slot head
			"helmet4_usa"	; [I] armour slot head
			"helmet_eng_mk3c"	; [I] armour slot head
			"helmet_eng_para_camo"	; [I] armour slot head
			"helmet_fin_m16"	; [I] armour slot head
			"helmet_fin_m38"	; [I] armour slot head
			"helmet_ger_m38_cover"	; [I] armour slot head
			"helmet_ger_m40"	; [I] armour slot head
			"helmet_ger_m40_camo"	; [I] armour slot head
			"helmet_ger_m40_camo_foliage"	; [I] armour slot head
			"helmet_ger_m40_fge"	; [I] armour slot head
			"helmet_ger_m40_grass"	; [I] armour slot head
			"helmet_ger_m40_ss"	; [I] armour slot head
			"helmet_heer_camo"	; [I] armour slot head
			"helmet_ita_m33_alpini"	; [I] armour slot head
			"helmet_ita_m33_bersaglieri"	; [I] armour slot head
			"helmet_ita_m33_clean"	; [I] armour slot head
			"helmet_ita_para"	; [I] armour slot head
			"helmet_ita_tank"	; [I] armour slot head
			"helmet_japmc"	; [I] armour slot head
			"helmet_japmc6"	; [I] armour slot head
			"helmet_japmc8"	; [I] armour slot head
			"helmet_japmc9"	; [I] armour slot head
			"helmet_marine_usa"	; [I] armour slot head
			"helmet_novice"	; [I] armour slot head
			"helmet_rus_para_goggles"	; [I] armour slot head
			"helmet_rus_ssh40_cover_camo"	; [I] armour slot head
			"helmet_sniper_fin"	; [I] armour slot head
			"helmet_usa_para"	; [I] armour slot head
			"helmet_usa_para_nco"	; [I] armour slot head
			"helmet_usa_ranger"	; [I] armour slot head
			"helmet_usa_ranger_nco"	; [I] armour slot head
			"jap_army_helmet11"	; [I] armour slot head
			"jap_army_helmet1_hatimaki"	; [I] armour slot head
			"jap_army_helmet2"	; [I] armour slot head
			"jap_army_helmet2_net"	; [I] armour slot head
			"jap_army_helmet3"	; [I] armour slot head
			"jap_army_helmet4"	; [I] armour slot head
			"jap_army_helmet5"	; [I] armour slot head
			"jap_army_helmet6"	; [I] armour slot head
			"jap_army_helmet6_hatimaki"	; [I] armour slot head
			"jap_army_helmet7"	; [I] armour slot head
			"jap_army_helmet8"	; [I] armour slot head
			"jap_army_helmet9"	; [I] armour slot head
			"jap_army_helmet_para"	; [I] armour slot head
			"tankhelmet_jap_old"	; [I] armour slot head
			"tankhelmet_rus"	; [I] armour slot head
			"tankhelmet_usa"	; [I] armour slot head
			"waffen_helmet_camo"	; [I] armour slot head
			"waffen_helmet_lssah"	; [I] armour slot head
			"waffen_helmet_pe"	; [I] armour slot head
			"waffen_helmet_totenkopf"	; [I] armour slot head
		}
	}
	{group "cap" {label "field cap (head, no armour)"} {price 0}
		{items
			"8_kaska_soldat_ruminia"	; [I] armour slot head
			"9_beret_tankist_ruminia"	; [I] armour slot head
			"beret_eng1"	; [I] armour slot head
			"beret_eng_comm"	; [I] armour slot head
			"beret_eng_para"	; [I] armour slot head
			"beret_eng_sas"	; [I] armour slot head
			"cap1_rus"	; [I] armour slot head
			"cap1_usa"	; [I] armour slot head
			"cap2_rus"	; [I] armour slot head
			"cap3_rus"	; [I] armour slot head
			"cap_eng_com"	; [I] armour slot head
			"cap_eng_off"	; [I] armour slot head
			"cap_eng_radiohead"	; [I] armour slot head
			"cap_eng_tamoshanter"	; [I] armour slot head
			"cap_fin_m36"	; [I] armour slot head
			"cap_fin_m36_officer"	; [I] armour slot head
			"cap_fin_m36_tank"	; [I] armour slot head
			"cap_fin_m36_tank_officer"	; [I] armour slot head
			"cap_fin_officer"	; [I] armour slot head
			"cap_ger_off"	; [I] armour slot head
			"cap_rus_partisan"	; [I] armour slot head
			"cap_rus_partisan2"	; [I] armour slot head
			"fieldcap1_rus"	; [I] armour slot head
			"fieldcap3_hun"	; [I] armour slot head
			"fieldcap_eng"	; [I] armour slot head
			"fieldcap_ger"	; [I] armour slot head
			"fieldcap_ger_geb"	; [I] armour slot head
			"fieldcap_ger_heer"	; [I] armour slot head
			"fieldcap_hun"	; [I] armour slot head
			"fieldcap_rus"	; [I] armour slot head
			"hachimaki_1"	; [I] armour slot head
			"japarmy_cap_hohei2"	; [I] armour slot head
			"japarmy_cap_igcap1"	; [I] armour slot head
			"japarmy_officer_cap1"	; [I] armour slot head
			"radioman_hat"	; [I] armour slot head
			"rw_cap"	; [I] armour slot head
			"tank_cap1_ger"	; [I] armour slot head
			"tank_cap2_ger"	; [I] armour slot head
			"tank_cap2_ss"	; [I] armour slot head
			"usmc-cap1"	; [I] armour slot head
			"waffen_fieldcap"	; [I] armour slot head
			"waffen_fieldcap_camo"	; [I] armour slot head
			"waffen_fieldcap_totenkopf"	; [I] armour slot head
		}
	}
	{group "vest" {label "body armour / vest / pouches (armour, body)"} {price 0}
		{items
			"ammo_ger2"	; [I] armour slot body
			"ammo_ger3"	; [I] armour slot body
			"ammo_rus"	; [I] armour slot body
			"ammo_us"	; [I] armour slot body
			"ammo_us2"	; [I] armour slot body
			"body_armor"	; [I] armour slot body
			"garpun"	; [I] armour slot body
			"jelet_mac_gop_dark"	; [I] stuff body/jelet_mac_gop_dark
			"kamikaze_bomb"	; [I] armour slot body
			"mgun_ammo"	; [I] armour slot body
			"mochila_urss"	; [I] armour slot body
			"sovet-mesh"	; [I] armour slot body
			"sovet_ammo1"	; [I] armour slot body
			"soviet_pack"	; [I] armour slot body
			"us_haversack_shovel"	; [I] armour slot body
			"us_marine_haversack"	; [I] armour slot body
		}
	}
	{group "dummy_weapon" {label "dummy weapon (breed priced by unit function: {special} blocks)"} {price 0}
		{items
			"lunge_mine"	; owner: dummy weapon (lunge_mine), breeds priced by {special}
			"throwable_gun"	; owner: dummy weapon (kamikaze), breeds priced by {special}
		}
	}
	{group "ammo_mortar50" {label "ammunition: mortar50"} {price 0}
		{items
			"ammo 5cm_grenade fg"	; [I] stuff reactive/5cm_grenade.fg.ammo
			"ammo mortar50 eng fg"	; [I] stuff reactive/mortar50/mortar50.eng.fg.ammo
			"ammo mortar50 eng sm"	; [I] stuff reactive/mortar50/mortar50.eng.sm.ammo
			"ammo mortar50 eng wp"	; [I] stuff reactive/mortar50/mortar50.eng.wp.ammo
			"ammo mortar50 ger fg"	; [I] stuff reactive/mortar50/mortar50.ger.fg.ammo
		}
	}
	{group "ammo_bazooka" {label "ammunition: bazooka"} {price 0}
		{items
			"ammo bazooka"	; [I] stuff bazooka/bazooka.ammo
			"ammo bazooka wp"	; [I] stuff bazooka/bazooka.wp.ammo
		}
	}
	{group "ammo_m18recoilless" {label "ammunition: m18recoilless"} {price 0}
		{items
			"ammo m18recoilless"	; [I] stuff bazooka/m18recoilless.ammo
			"ammo m18recoilless fg"	; [I] stuff bazooka/m18recoilless.fg.ammo
			"ammo m18recoilless wp"	; [I] stuff bazooka/m18recoilless.wp.ammo
		}
	}
	{group "ammo_panzershreck" {label "ammunition: panzershreck"} {price 0}
		{items
			"ammo panzershreck"	; [I] stuff bazooka/panzershreck.ammo
		}
	}
	{group "ammo_piatrocket" {label "ammunition: piatrocket"} {price 0}
		{items
			"ammo piatrocket"	; [I] stuff bazooka/piatrocket.ammo
		}
	}
	{group "ammo_type_4" {label "ammunition: type 4"} {price 0}
		{items
			"ammo type_4"	; [I] stuff bazooka/type_4.ammo
		}
	}

	; ---- stat weights (0 = the sheet prices nothing for it) ----
	{stat "health" {weight 0} {base 1}}
	{stat "stamina" {weight 0} {base 1}}
	{stat "speed" {weight 0} {base 0.9}}
	{stat "sight" {weight 0} {base 0} {map "mp_soldier" 0 "mp_officer" 1 "mp_sniper" 2}}
	{stat "stealth" {weight 0} {base 0}}
	{stat "avoidance" {weight 0} {base 0}}
	{stat "rocket" {weight 0} {base 1}}
	{stat "tankgun" {weight 0} {base 0}}
	{stat "at_rifle" {weight 0} {base 0}}

	; ---- fixed-price breeds (own stats, not the weapon tables) [I] seeded from the mod's negative-CP rows ----
	{special "officer_1000" {label "officer [I] mod rows level_0_v2"} {mp 1000} {cp -10} {cw 100} {card_mp 0}	; [I] all 18 cards made only of these breeds cost 0 in the mod
		{breeds
			"axis_minor/axm_fin_officer"
			"ger/ger_officer"
			"eng/eng_officer"
			"ger_ss/ss_officer"
			"ger2/ost_officer"
			"jap/jap_officer"
			"rus/rus_officer"
			"rus_guard/guard_officer"
			"usa/usa_officer"
		}
	}
	{special "officer_1500" {label "officer [I] mod rows level_1_v2"} {mp 1500} {cp -15} {cw 100}
		{breeds
			"ger2/ost_officer2"
		}
	}
	{special "officer_1500_cw150" {label "officer [I] mod rows level_136_v2"} {mp 1500} {cp -15} {cw 150}
		{breeds
			"jap/super_officer"
		}
	}
	{special "kamikaze_6" {label "kamikaze (dummy weapon 'throwable_gun') [I] mod rows level_11_v2"} {mp 6} {cp 0.25} {cw 0.25}
		{breeds
			"jap/jap_charger_throwgun"
		}
	}
	{special "lunge_mine_6" {label "lunge_mine (dummy weapon 'lunge_mine') [I] mod rows level_11_v2"} {mp 6} {cp 0.25} {cw 0.25}
		{breeds
			"jap/jap_kamikaze"
		}
	}
	{special "lunge_mine_10" {label "lunge_mine (dummy weapon 'lunge_mine') [I] mod rows level_55"} {mp 10} {cp 1.34} {cw 1.34}
		{breeds
			"jap/ki_at_stick"
		}
	}

	; ---- hand grenades / throwables: tier computed from the stuff file (owner rule) [I] weights and cut points proposed, owner tunes ----
	;   score = energy x (sum of {damage [add] blastwave {energy}} kg) + penetration x ({damage cumulative {damage}})
	;         + fire_radius x ({damage fire {radius}}) + range x ({throw {range}}) + fuse x ({special {PrepareTime}} with {mode detonate}; impact = 0)
	;   tier = 1 + number of cut points <= score.  MP += mp_per_tier x tier x expected count, CP += cp_per_tier x tier x count (CW follows CP)
	{throwable_score {groups "frag_grenade" "smoke_grenade" "incendiary"} {energy 5} {penetration 0.1} {fire_radius 1} {range 0.2} {fuse -0.5} {cuts 10 20 40 80}}
	; anti-tank grenades and charges (owner rule): ranked by the armour they defeat, score = max(energy x strongest single blast layer, penetration x cumulative damage)
	;   energy 5 = the engine multiplies blast energy by 5 against armour (g_energyperblastwave). cuts 30 60 100 [I]: tier 1 light armour, 2 light tanks, 3 medium tanks, 4 heavy tanks
	{throwable_score {groups "at_grenade" "bundle_charge"} {mode "armor"} {energy 5} {penetration 1} {cuts 30 60 100}}
	{throwable_price {mp_per_tier 0.05} {cp_per_tier 0.05}}	; owner rule: 0.05 per tier per throwable, on MP and on CP

	; ---- spellings of one item (same stuff file): {alias "model name" "other spelling" ...} ----
	{alias "ammo bar_mag" "bar_mag ammo"}
	{alias "ammo breda_mag" "breda_mag"}
	{alias "ammo garand_clip" "garand_clip ammo"}
	{alias "ammo lsm26_mag" "lsm26_mag"}
	{alias "ammo m3a_mag" "m3a_mag ammo"}
	{alias "ammo springfield_belt" "springfield_belt ammo"}

	; ---- fixed CP of support breeds (sheet singles / not singles) [I] name patterns ----
	{fixed_cp "elite vehicle support" {match "elite_vehicle_supporter"} {single 0.5} {not_single 0}}
	{fixed_cp "elite tankcommander" {match "elite_tank_?commander"} {single 2} {not_single 0}}
	{fixed_cp "vet tankcommander" {match "vet_tank_?commander"} {single 2} {not_single 0}}
	{fixed_cp "vehicle support" {match "(^|_)vehicle_supporter"} {single 0.2} {not_single 0}}
	{fixed_cp "elite tankman" {match "elite_tankman"} {single 0.5} {not_single 0}}
	{fixed_cp "tankcommander" {match "tank_?commander"} {single 2} {not_single 0}}
	{fixed_cp "vet tankman" {match "vet_tankman"} {single 0.5} {not_single 0}}
	{fixed_cp "tankman" {match "tankman"} {single 0.5} {not_single 0}}
	{fixed_cp "miner" {match "(^|_)(ap_|at_)?miner"} {single 0.5} {not_single 0}}
	{fixed_cp "radio" {match "radio"} {single 5} {not_single 0}}

	{squad
		{addon "halftrack" {price 58} {match "halftrack" "^m3" "^m5" "m3a1" "m5a1" "m16"}}	; sheet "M5/3 Halftrack Cost" [I] vehicle name patterns
		{addon "251" {price 50} {match "251" "sdkfz_?251" "sd_kfz_251"}}	; sheet "Sdfkz 251" [I] vehicle name patterns
		{addon "truck" {price 16} {match "truck" "opel" "blitz" "gaz" "zis" "studebaker" "bedford" "gmc" "isuzu" "dodge"}}	; sheet "Truck" [I] vehicle name patterns
		{addon "para" {price 50} {match "airborne" "para" "spawner"}}	; sheet "Para" [I] vehicle name patterns
		{single "at_launcher" {classes "at"} {mult 2}}
		{single "sniper_flame_at_rifle" {classes "snipers" "flame" "at_rifles"} {mult 1.5}}
		{single "elite" {classes "*"} {min_level 6} {mult 1.3}}	; [I] elite = breed skill level 6+
		{single "regular" {classes "*"} {mult 1.15}}
		{sequence "infantry" {percent 100 90 90 80 70}}	; [I] sheet "Sov Inf Seq" 100. ,90. 90. 80. 70, applied to every sequence card until split per family
		{modifier {side "rus"} {card "partisans"} {factor 0.88}}
		{modifier {side "rus"} {card "smg squad"} {factor 0.88}}
		{modifier {side "rus"} {card "sapper squad"} {factor 1.2}}
		{modifier {side "rus"} {card "rifle squad"} {factor 0.88}}
		{modifier {side "rus"} {card "assualt rifle"} {factor 0.88}}
		{modifier {side "rus_guard"} {card "sapper"} {factor 1.2}}
		{modifier {side "jap"} {card "knee mortar seq"} {factor 0.5}}
		{modifier {side "ger2"} {card "elite jager"} {factor 0.9}}
		{modifier {side "ger2"} {card "elite fallschirm"} {factor 0.9}}
		{modifier {side "ger2"} {card "mech gebirgs"} {factor 0.9}}
	}
}
