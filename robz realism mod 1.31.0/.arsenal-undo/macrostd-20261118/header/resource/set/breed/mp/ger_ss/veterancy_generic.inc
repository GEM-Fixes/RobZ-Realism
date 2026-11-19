(include "/set/breed/mp/robz_vet.inc")
(define "veterancy_lvl1"   ;;;veterancy requirements reduced by how many kills are already required to be vet 2
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
(define "veterancy_lvl3"   ;;;veterancy requirements reduced by how many kills are already required to be vet 2
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

(define "veterancy_1_old"
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
