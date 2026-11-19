; breed_macros.inc: shared perk and veterancy blocks of the soldier breeds (set/breed/**/*.set, written by macrostd step breed).
;   A breed that calls one of these macros includes this file first: (include "/set/breed/breed_macros.inc").
;   Perks a macro does not hold (tankgun, stealth, telescope, ...) stay literal lines next to the calls, in the breed's order.
(include "/set/breed/breed_kit.inc")

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

; breed_vet: the {veterancy} block of a breed. It includes veterancy_generic.inc from the CALLING breed's folder
;   (each side has its own; it pulls in /set/breed/mp/robz_vet.inc) and calls the score table vet_<table>.
;   table - which score table, the word after "vet_":
;     standard, standard_start2, standard_start3, elite, elite_start2, start5, crew,
;     crew_start3 (every side)
;     ss_start1 (ger_ss only)
;     ss_start3 (ger_ss only)
;     standard_old (unused) (axis_minor, ger, ger_ss, jap only)
;     numbers, breeds per table and rank effects: top of set/breed/mp/robz_vet.inc
;   e.g. ("breed_vet" table(standard))
(define "breed_vet"
	{veterancy
		(include "veterancy_generic.inc")
		("vet_%table")
	}
)
