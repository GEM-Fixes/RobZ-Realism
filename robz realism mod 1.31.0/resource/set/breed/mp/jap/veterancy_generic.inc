; veterancy_generic.inc (jap): includes /set/breed/mp/robz_vet.inc (shared tables), plus 1 own table below.
;   Keep it under this name: breed_vet and this folder's vanilla breeds include it from the breed's folder.
(include "/set/breed/mp/robz_vet.inc")


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
