;= START =====================================


; vision_human: {rules {human}} {mods {stand}}, calls "radius"
;   e.g. ("vision_human")
(define "vision_human"
	("radius" r(110))
	{rules
		{human 1.5
			{firing 1.65
				("firing")
			}
			("vision")
		}
		("cannon")
		("tank")
	}
	{mods
		{stand 1}
	}
)

; vision_humancrew: {rules {human}} {mods {stand}}, calls "radius"
;   e.g. ("vision_humancrew")
(define "vision_humancrew"
	("radius" r(90))
	{rules
		{human 1.5
			{firing 1.60
				("firing")
			}
			("vision")
		}
		("cannon")
		("tank")
	}
	{mods
		{stand 1}
	}
)

; vision_optic: {rules {human}} {mods {stand}}, calls "radius"
;   e.g. ("vision_optic")
(define "vision_optic"
	("radius" r(120))
	{rules
		{human 1.25
			{firing 1.35
				("firing")
			}
			("vision")
		}
		("cannon")
		("tank")
	}
	{mods
		{stand 1}
	}
)
; vision_optic_1x: {rules {human}} {mods {stand}}, calls "radius"
;   e.g. ("vision_optic_1x")
(define "vision_optic_1x"
	("radius" r(120)) ;110
	{rules
		{human 1.25
			{firing 1.35
				("firing")
			}
			("vision")
		}
		("cannon")
		("tank")
	}
	{mods
		{stand 1}
	}
)
; vision_optic_1-9x: {rules {human}} {mods {stand}}, calls "radius"
;   e.g. ("vision_optic_1-9x")
(define "vision_optic_1-9x"
	("radius" r(122)) ;115
	{rules
		{human 1.25
			{firing 1.35
				("firing")
			}
			("vision")
		}
		("cannon")
		("tank")
	}
	{mods
		{stand 1}
	}
)
; vision_optic_2-5x: {rules {human}} {mods {stand}}, calls "radius"
;   e.g. ("vision_optic_2-5x")
(define "vision_optic_2-5x"
	("radius" r(125)) ;125
	{rules
		{human 1.25
			{firing 1.35
				("firing")
			}
			("vision")
		}
		("cannon")
		("tank")
	}
	{mods
		{stand 1}
	}
)
; vision_optic_3x .. vision_optic_6x (4 defines, same shape): {rules {human}} {mods {stand}}, calls "radius"
;   e.g. ("vision_optic_3x")
(define "vision_optic_3x"
	("radius" r(127)) ;135
	{rules
		{human 1.25 ;1.20
			{firing 1.35 ;1.30
				("firing")
			}
			("vision")
		}
		("cannon")
		("tank")
	}
	{mods
		{stand 1}
	}
)

(define "vision_optic_4x"
	("radius" r(130)) ;150
	{rules
		{human 1.25 ;1.10
			{firing 1.35 ;1.20
				("firing")
			}
			("vision")
		}
		("cannon")
		("tank")
	}
	{mods
		{stand 1}
	}
)

(define "vision_optic_5x"
	("radius" r(135)) ;170
	{rules
		{human 1.25 ;1.00
			{firing 1.35 ;1.10
				("firing")
			}
			("vision")
		}
		("cannon")
		("tank")
	}
	{mods
		{stand 1}
	}
)

(define "vision_optic_6x"
	("radius" r(140)) ;190
	{rules
		{human 1.25 ;0.90
			{firing 1.35 ;1.00
				("firing")
			}
			("vision")
		}
		("cannon")
		("tank")
	}
	{mods
		{stand 1}
	}
)

; vision_gunner: {rules {human}} {mods {stand}}, calls "radius"
;   e.g. ("vision_gunner")
(define "vision_gunner"
	("radius" r(90))
	{rules
		{human 1.25
			{firing 1.35
				("firing")
			}
			("vision")
		}
		("cannon")
		("tank")
	}
	{mods
		{stand 1}
	}
)

; vision_turret: {rules {human}} {mods {stand}}, calls "radius"
;   e.g. ("vision_turret")
(define "vision_turret"
	("radius" r(90))
	{rules
		{human 1.25
			{firing 1.35
				("firing")
			}
			("vision")
		}
		("cannon")
		("tank")
	}
	{mods
		{stand 1}
	}
)

; glass: {rules {zero}}, calls "radius"
;   %0 - r() of "radius"
;   e.g. ("glass" args 7)
(define "glass"
	("radius" r(%0))
	{rules
		{zero 0}
	}
)

;= MAP HELPER ====================================

; ultra_vision: {radius} {h_fov} {v_fov} {uncover}
;   range - {uncover}, [?]
;   e.g. ("ultra_vision" range(20))
(define "ultra_vision"
	{radius 20}
	{h_fov 360}
	{v_fov 180}
	{uncover %range}
)
{"start_point"  ("ultra_vision" range(20))}
{"map_point"    ("ultra_vision" range(20))}
{"flag_point"   ("ultra_vision" range(20))}
