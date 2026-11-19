; veterancy_generic.inc (ger_ss): includes /set/breed/mp/robz_vet.inc (shared tables), plus 3 own tables below.
;   Keep it under this name: breed_vet include it from the breed's folder.
(include "/set/breed/mp/robz_vet.inc")
; vet_ss: score table of 7 breeds
;   breeds per side: ger_ss 7
;   soldier starts at rank 1
;   matches no base table
;   vet_elite minus 60 would be 0/72/156/252/360 from rank 1, this has 0/84/180/288/384
;   no (mod "mp") set: the same numbers in every game
;   e.g. ("vet_ss")   from a breed: ("breed_vet" table(ss) start(1))
(define "vet_ss"
	{"lvl_1" 0
	}
	{"lvl_2" 84
	}
	{"lvl_3" 180
	}
	{"lvl_4" 288
	}
	{"lvl_5" 384
	}
)
; vet_from3_ss: score table of 18 breeds
;   breeds per side: ger_ss 18
;   soldier starts at rank 3
;   matches no base table
;   vet_elite minus 216 would be 0/96/204 from rank 3, this has 0/108/180
;   no (mod "mp") set: the same numbers in every game
;   e.g. ("vet_from3_ss")   from a breed: ("breed_vet" table(ss) start(3))
(define "vet_from3_ss"
	{"lvl_1" -1
	}
	{"lvl_2" -1
	}
	{"lvl_3" 0
	}
	{"lvl_4" 108
	}
	{"lvl_5" 180
	}
)

; vet_standard_old: score table no breed uses
;   older numbers
;   its (mod "mp") set equals vet_standard
;   (mod "mp") set: 24/60/108/168/240, differs from the outer 48/96/288/576/960
;   e.g. ("vet_standard_old")   from a breed: ("breed_vet" table(standard_old) start(1))
(define "vet_standard_old"
	{"lvl_1" 48
	}
	{"lvl_2" 96
	}
	{"lvl_3" 288
	}
	{"lvl_4" 576
	}
	{"lvl_5" 960
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

; ---- unused macros (macrostd): defined, never called ----
; (define "veterancy_lvl4"   ;;;veterancy requirements reduced by how many kills are already required to be vet 4
; 	{"lvl_1" -1
; 	}
; 	{"lvl_2" -1
; 	}
; 	{"lvl_3" -1
; 	}
; 	{"lvl_4" 0
; 	}
; 	{"lvl_5" 108
; 	}
; )
