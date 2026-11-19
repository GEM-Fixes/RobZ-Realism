; robz shared macros (macrostd share): one define per name, included where the copies were
; defines: abm_low, abm_tulip, abm_zenite_v2, accuracy_by_motion, armor_engine

; abm_low: calls "accuracy_by_motion"
;   e.g. ("abm_low")
(define "abm_low"
	("accuracy_by_motion"
		max_linear(14) accuracy_by_linear(0.2)
		max_angular(4) accuracy_by_angular(0.6)
		disorder_time(1.2) order_time(2)
	)
)

; abm_tulip: calls "accuracy_by_motion"
;   e.g. ("abm_tulip")
(define "abm_tulip"
	("accuracy_by_motion"
		max_linear(5) accuracy_by_linear(0.2)
		max_angular(2) accuracy_by_angular(0.3)
		disorder_time(0.5) order_time(6.0)
	)
)

; abm_zenite_v2: calls "accuracy_by_motion"
;   e.g. ("abm_zenite_v2")
(define "abm_zenite_v2"
	("accuracy_by_motion"
		max_linear(10) accuracy_by_linear(0.5)
		max_angular(4) accuracy_by_angular(0.8)
		disorder_time(1.2) order_time(1.4)
	)
)

; accuracy_by_motion: {AccuracyByMotion {MaxLinearSpeed} {ByLinearSpeed} {MaxAngularSpeed} {ByAngularSpeed} ..}
;   max_linear - value in {MaxLinearSpeed}
;   accuracy_by_linear - value in {ByLinearSpeed}
;   max_angular - value in {MaxAngularSpeed}
;   accuracy_by_angular - value in {ByAngularSpeed}
;   disorder_time - value in {DisorderTime}
;   order_time - value in {OrderTime}
;   e.g. ("accuracy_by_motion" max_linear(10.00) accuracy_by_linear(0.60) max_angular(15.00) accuracy_by_angular(0.70) disorder_time(0.50) order_time(1.00) )
(define "accuracy_by_motion" ;  spreading depending on the speed of "body", "gun" volumes
	{AccuracyByMotion
		{MaxLinearSpeed %max_linear}               ;km/h
		{ByLinearSpeed %accuracy_by_linear}
		{MaxAngularSpeed %max_angular}             ;deg/s
		{ByAngularSpeed %accuracy_by_angular}
		{DisorderTime %disorder_time}              ;s
		{OrderTime %order_time}                    ;s
	}
)

; armor_engine: {armor {setting}}
;   t - value in {thickness}
;   e.g. ("armor_engine" t(1))
(define "armor_engine"
	{armor
		{setting "engine"
			{thickness %t}
			{volumes "engine*"}
		}
	}
)
