; breed_macros.inc: shared perk and veterancy blocks of the soldier breeds (set/breed/**/*.set, written by macrostd step breed).
;   A breed that calls one of these macros includes this file first: (include "/set/breed/breed_macros.inc").
;   Perks a macro does not hold (tankgun, stealth, telescope, ...) stay literal lines next to the calls, in the breed's order.
(include "/set/breed/breed_kit.inc")
(include "/set/breed/breed_soldier.inc")

; breed_body: the body perks health, health_regeneration, stamina, stamina_regeneration, vision, speed (in this order)
;   health - "health" perk, percent of the base with a % sign
;   regen_health - "health_regeneration" perk, percent with a % sign
;   stamina - "stamina" perk, percent with a % sign
;   regen_stamina - "stamina_regeneration" perk, percent with a % sign
;   vision - "vision" perk, vision preset name as the breed writes it (quoted "mp_soldier" or bare mp_soldier)
;   speed - "speed" perk, move speed factor (1 = normal)
;   e.g. ("breed_body" health(150%) regen_health(100%) stamina(100%) regen_stamina(100%) vision("mp_soldier") speed(0.9))
(define "breed_body"
	{"health" "%health"}
	{"health_regeneration" "%regen_health"}
	{"stamina" "%stamina"}
	{"stamina_regeneration" "%regen_stamina"}
	{"vision" %vision}
	{"speed" %speed}
)

; breed_drive: the crew perks tank, vehicle, cannon (in this order)
;   tank - "tank" perk, tank driving and crew skill factor
;   vehicle - "vehicle" perk, soft vehicle driving skill factor
;   cannon - "cannon" perk, gun crew skill factor
;   e.g. ("breed_drive" tank(0.75) vehicle(1) cannon(0.8))
(define "breed_drive"
	{"tank" %tank}
	{"vehicle" %vehicle}
	{"cannon" %cannon}
)

; breed_skills: the weapon skill perks pistol, smg, mgun, rifle, rocketlauncher, melee as lvl_<n> (in this order)
;   pistol - "pistol" skill level number (4 = lvl_4)
;   smg - "smg" skill level number
;   mgun - "mgun" skill level number
;   rifle - "rifle" skill level number
;   rocket - "rocketlauncher" skill level number
;   melee - "melee" skill level number
;   e.g. ("breed_skills" pistol(4) smg(4) mgun(2) rifle(3) rocket(2) melee(4))
(define "breed_skills"
	{"pistol" lvl_%pistol}
	{"smg" lvl_%smg}
	{"mgun" lvl_%mgun}
	{"rifle" lvl_%rifle}
	{"rocketlauncher" lvl_%rocket}
	{"melee" lvl_%melee}
)

; breed_vet: the soldier's veterancy: which score table, and the rank he starts at
;   table - standard (soldiers up to level 5), elite (level 6 and 7), crew (vehicle and gun crews), ss (ger_ss only)
;   start - rank he has when bought: 1 = none yet (the plain table), 2, 3, or 5 (top rank from the start)
;   tables that exist: standard 1 2 3 5, elite 1 2 5, crew 1 3, ss 1 3. Any other pair is an undefined macro (fatal).
;   numbers and rank effects: top of set/breed/mp/robz_vet.inc
;   e.g. ("breed_vet" table(standard) start(1))    ("breed_vet" table(elite) start(2))
(define "breed_vet"
	{veterancy
		(include "veterancy_generic.inc")
		("vet_start_%start" table(%table))
	}
)

; perks_sniper: the three sniper perks
;   e.g. ("perks_sniper")
(define "perks_sniper"
	{"stealth"}
	{"telescope"}
	{"aimedshot"}
)

; perks_officer: the officer's field glass (every breed that has it also has vision "mp_officer")
;   e.g. ("perks_officer")
(define "perks_officer"
	{"field_glass"}
)

; breed_look: how the soldier looks and what the buy menu shows
;   skin - model skin (entity/humanskin)
;   portrait - face picture
;   icon - class icon over his head and in the squad list
;   priority - icon_priority: with several classes in one squad the highest number gives the squad its icon
;   nation - nationality (voice, names)
;   e.g. ("breed_look" skin(ger-para-rfl) portrait(ger_elite1) icon(elite) priority(4) nation(ger))
(define "breed_look"
	{skin "%skin"}
	{portrait "%portrait"}
	{icon "%icon"}
	{icon_priority %priority}
	{nationality %nation}
)

; breed_armor: he wears a helmet only
;   head - helmet item
;   e.g. ("breed_armor" head(helmet_ger_m40))
(define "breed_armor"
	{armors
		{head "%head"}
	}
)

; breed_armor_vest: helmet plus something on the body (vest, ammo pouches)
;   vest - body item
;   head - helmet item
;   e.g. ("breed_armor_vest" vest(ammo_ger3) head(waffen_helmet_camo))
(define "breed_armor_vest"
	{armors
		{body "%vest"}
		{head "%head"}
	}
)
