; robz_vet.inc: veterancy score tables of the soldier breeds, one define per table, shared by all sides
;   Each side's veterancy_generic.inc includes this file. A breed picks its table with
;   ("breed_vet" table(<word>)) from set/breed/breed_macros.inc, which expands to
;   {veterancy (include "veterancy_generic.inc") ("vet_<word>")}.
;
; How veterancy works (modweb/humans/veterancy.md):
;   A soldier has 5 ranks, lvl_1 .. lvl_5. A table gives the score each rank needs.
;   A rank is active when the soldier's score >= its number. Only the highest rank reached
;   applies; the ranks do not add up.
;   The score rises with kills (the amount per kill comes from the unit card score) and with
;   healing as a medic (+0.5 per patient) [I].
;   -1 = always reached, 0 = reached at once (the score starts at 0). A table that starts with
;   -1 .. 0 makes the soldier START at the rank that holds the 0; its later numbers are then the
;   base table minus what that rank needed (each table below says where this holds).
;   Numbers outside (mod "mp" ...) are read in every game. Numbers inside (mod "mp" ...) are
;   read in addition when a multiplayer mission loads (the engine sets the SDL mod "mp").
;   Where both sets are equal this changes nothing; how two different numbers for one rank
;   combine is not verified [I].
;
; Tables: score for lvl_1..lvl_5, (mod "mp") set, breeds using it
;   vet_standard          24   60  108  168  240   mp same    713 breeds
;   vet_from2_standard   -1    0   48  120  192   no mp set   26 breeds
;   vet_from3_standard   -1   -1    0   72  144   no mp set   33 breeds
;   vet_elite             60  132  216  312  420   mp same    188 breeds
;   vet_from2_elite      -1    0   84  180  288   no mp set   18 breeds
;   vet_from5            -1   -1   -1   -1    0   no mp set   65 breeds
;   vet_crew             600  900 1200 1500 1800   mp same    117 breeds
;   vet_from3_crew       -1   -1    0   96  204   mp -1/-1/0/180/360   2 breeds
;   vet_ss          0   84  180  288  384   no mp set   7 breeds (ger_ss only)
;   vet_from3_ss         -1   -1    0  108  180   no mp set   18 breeds (ger_ss only)
;   vet_standard_old      48   96  288  576  960   mp 24/60/108/168/240   unused (axis_minor, ger, ger_ss, jap only)
;   veterancy_1 = vet_standard, kept for vanilla breeds the mod does not replace
;
; Rank effects: set/ability/veterancy.set (change them there). Fractions added to the base
;   (0.10 = +10%); reload = share of the reload time saved; w_skill = levels added to every
;   weapon skill. hp_regen = health_regeneration, st_regen = stamina_regeneration.
;   rank   health  hp_regen  stamina  st_regen  tank  vehicle  cannon  reload  w_skill
;   lvl_1    0.10      0.05     0.10      0.10  0.05     0.05    0.05    0.05        1
;   lvl_2    0.20      0.10     0.15      0.20  0.10     0.10    0.10    0.10        1
;   lvl_3    0.30      0.15     0.20      0.30  0.15     0.15    0.15    0.15        2
;   lvl_4    0.40      0.20     0.25      0.40  0.20     0.20    0.20    0.20        2
;   lvl_5    0.50      0.25     0.30      0.50  0.25     0.25    0.25    0.25        3

; ---- start rank: ("breed_vet" table(T) start(N)) calls vet_start_N, which picks the table ----
;   start(1) -> vet_<table>          the plain table
;   start(2) -> vet_from2_<table>    rank 2 from the start (standard, elite)
;   start(3) -> vet_from3_<table>    rank 3 from the start (standard, crew; ss in ger_ss)
;   start(5) -> vet_from5            top rank from the start; the table word is not used
;   table - standard, elite, crew or ss
;   e.g. ("vet_start_2" table(elite))
(define "vet_start_1" ("vet_%table"))
(define "vet_start_2" ("vet_from2_%table"))
(define "vet_start_3" ("vet_from3_%table"))
(define "vet_start_5" ("vet_from5"))

; vet_standard: score table of 713 breeds
;   breeds per side: axis_minor 75, eng 74, ger 140, ger2 25, ger_ss 112, jap 103, rus 90, rus_guard 6, usa 88
;   base table
;   (mod "mp") set: the same numbers
;   e.g. ("vet_standard")   from a breed: ("breed_vet" table(standard) start(1))
(define "vet_standard"
	{"lvl_1" 24
	}
	{"lvl_2" 60
	}
	{"lvl_3" 108
	}
	{"lvl_4" 168
	}
	{"lvl_5" 240
	}
	(mod "mp"
		{"lvl_1" 24
		}
		{"lvl_2" 60
		}
		{"lvl_3" 108
		}
		{"lvl_4" 168
		}
		{"lvl_5" 240
		}
	)
)

; veterancy_1: old name of vet_standard, kept for vanilla breeds the mod does not replace (they call it)
;   e.g. ("veterancy_1")
(define "veterancy_1" ("vet_standard"))

; vet_from2_standard: score table of 26 breeds
;   breeds per side: ger2 13, ger_ss 13
;   vet_standard, soldier starts at rank 2
;   vet_standard minus 60 would be 0/48/108/180 from rank 2, this has 0/48/120/192
;   no (mod "mp") set: the same numbers in every game
;   e.g. ("vet_from2_standard")   from a breed: ("breed_vet" table(standard) start(2))
(define "vet_from2_standard"
	{"lvl_1" -1
	}
	{"lvl_2" 0
	}
	{"lvl_3" 48
	}
	{"lvl_4" 120
	}
	{"lvl_5" 192
	}
)

; vet_from3_standard: score table of 33 breeds
;   breeds per side: rus_guard 33
;   vet_standard, soldier starts at rank 3
;   vet_standard minus 108 would be 0/60/132 from rank 3, this has 0/72/144
;   no (mod "mp") set: the same numbers in every game
;   e.g. ("vet_from3_standard")   from a breed: ("breed_vet" table(standard) start(3))
(define "vet_from3_standard"
	{"lvl_1" -1
	}
	{"lvl_2" -1
	}
	{"lvl_3" 0
	}
	{"lvl_4" 72
	}
	{"lvl_5" 144
	}
)

; vet_elite: score table of 188 breeds
;   breeds per side: eng 42, ger 43, ger2 1, ger_ss 6, jap 34, rus 6, usa 56
;   base table
;   (mod "mp") set: the same numbers
;   e.g. ("vet_elite")   from a breed: ("breed_vet" table(elite) start(1))
(define "vet_elite"
	{"lvl_1" 60
	}
	{"lvl_2" 132
	}
	{"lvl_3" 216
	}
	{"lvl_4" 312
	}
	{"lvl_5" 420
	}
	(mod "mp"
		{"lvl_1" 60
		}
		{"lvl_2" 132
		}
		{"lvl_3" 216
		}
		{"lvl_4" 312
		}
		{"lvl_5" 420
		}
	)
)

; vet_from2_elite: score table of 18 breeds
;   breeds per side: ger2 18
;   vet_elite, soldier starts at rank 2
;   numbers = vet_elite minus 132
;   no (mod "mp") set: the same numbers in every game
;   e.g. ("vet_from2_elite")   from a breed: ("breed_vet" table(elite) start(2))
(define "vet_from2_elite"   ;;;veterancy requirements reduced by how many kills are already required to be vet 2
	{"lvl_1" -1
	}
	{"lvl_2" 0
	}
	{"lvl_3" 84
	}
	{"lvl_4" 180
	}
	{"lvl_5" 288
	}
)

; vet_from5: score table of 65 breeds
;   breeds per side: axis_minor 1, ger 14, ger2 7, ger_ss 24, rus_guard 19
;   every rank reached at once: the soldier starts at rank 5 (the same for any base table)
;   no (mod "mp") set: the same numbers in every game
;   e.g. ("vet_from5")   from a breed: ("breed_vet" table(standard) start(5))
(define "vet_from5"
	{"lvl_1" -1
	}
	{"lvl_2" -1
	}
	{"lvl_3" -1
	}
	{"lvl_4" -1
	}
	{"lvl_5" 0
	}
)

; vet_crew: score table of 117 breeds
;   breeds per side: axis_minor 27, eng 12, ger 17, ger2 8, ger_ss 10, jap 7, rus 14, rus_guard 11, usa 11
;   base table
;   (mod "mp") set: the same numbers
;   e.g. ("vet_crew")   from a breed: ("breed_vet" table(crew) start(1))
(define "vet_crew"
	{"lvl_1" 600
	}
	{"lvl_2" 900
	}
	{"lvl_3" 1200
	}
	{"lvl_4" 1500
	}
	{"lvl_5" 1800
	}
	(mod "mp"
		{"lvl_1" 600
		}
		{"lvl_2" 900
		}
		{"lvl_3" 1200
		}
		{"lvl_4" 1500
		}
		{"lvl_5" 1800
		}
	)
)

; vet_from3_crew: score table of 2 breeds
;   breeds per side: rus_guard 2
;   vet_crew, soldier starts at rank 3
;   numbers = vet_elite minus 216, not vet_crew
;   vet_crew minus 1200 would be 0/300/600 from rank 3, this has 0/96/204
;   (mod "mp") set: -1/-1/0/180/360, differs from the outer -1/-1/0/96/204
;   e.g. ("vet_from3_crew")   from a breed: ("breed_vet" table(crew) start(3))
(define "vet_from3_crew"
	{"lvl_1" -1
	}
	{"lvl_2" -1
	}
	{"lvl_3" 0
	}
	{"lvl_4" 96
	}
	{"lvl_5" 204
	}
	(mod "mp"
		{"lvl_1" -1
		}
		{"lvl_2" -1
		}
		{"lvl_3" 0
		}
		{"lvl_4" 180
		}
		{"lvl_5" 360
		}
	)
)
