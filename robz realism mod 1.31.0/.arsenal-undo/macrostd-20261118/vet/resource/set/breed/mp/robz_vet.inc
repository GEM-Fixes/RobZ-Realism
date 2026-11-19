; robz shared macros (macrostd share): one define per name, included where the copies were
; defines: veterancy_1, veterancy_1_lvl2, veterancy_1_lvl3, veterancy_elite, veterancy_lvl2, veterancy_lvl5, veterancy_tankcrew,
;   veterancy_tankcrew_lvl3

; veterancy_1: {"lvl_1"} {"lvl_2"} {"lvl_3"} {"lvl_4"} {"lvl_5"} {"lvl_1"} +4 more, per mod "mp"
;   e.g. ("veterancy_1")
(define "veterancy_1"
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

; veterancy_1_lvl2: {"lvl_1"} {"lvl_2"} {"lvl_3"} {"lvl_4"} {"lvl_5"}
;   e.g. ("veterancy_1_lvl2")
(define "veterancy_1_lvl2"
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

; veterancy_1_lvl3: {"lvl_1"} {"lvl_2"} {"lvl_3"} {"lvl_4"} {"lvl_5"}
;   e.g. ("veterancy_1_lvl3")
(define "veterancy_1_lvl3"
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

; veterancy_elite: {"lvl_1"} {"lvl_2"} {"lvl_3"} {"lvl_4"} {"lvl_5"} {"lvl_1"} +4 more, per mod "mp"
;   e.g. ("veterancy_elite")
(define "veterancy_elite"
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

; veterancy_lvl2: {"lvl_1"} {"lvl_2"} {"lvl_3"} {"lvl_4"} {"lvl_5"}
;   e.g. ("veterancy_lvl2")
(define "veterancy_lvl2"   ;;;veterancy requirements reduced by how many kills are already required to be vet 2
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

; veterancy_lvl5: {"lvl_1"} {"lvl_2"} {"lvl_3"} {"lvl_4"} {"lvl_5"}
;   e.g. ("veterancy_lvl5")
(define "veterancy_lvl5"
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

; veterancy_tankcrew: {"lvl_1"} {"lvl_2"} {"lvl_3"} {"lvl_4"} {"lvl_5"} {"lvl_1"} +4 more, per mod "mp"
;   e.g. ("veterancy_tankcrew")
(define "veterancy_tankcrew"
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

; veterancy_tankcrew_lvl3: {"lvl_1"} {"lvl_2"} {"lvl_3"} {"lvl_4"} {"lvl_5"} {"lvl_1"} +4 more, per mod "mp"
;   e.g. ("veterancy_tankcrew_lvl3")
(define "veterancy_tankcrew_lvl3"
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
