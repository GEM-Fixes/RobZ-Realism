; robz shared macros (macrostd share): one define per name, included where the copies were
; defines: accuracy_boost, fg_medium_v3, fg_minimum, fg_v3, recoveryTime, speed

; accuracy_boost: {ZeroingAccuracy}
;   e.g. ("accuracy_boost")
(define "accuracy_boost"
	{ZeroingAccuracy 0.9 0.8}
)

; fg_medium_v3: {damage} x3
;   %0 - value in {energy}
;   e.g. ("fg_medium_v3" args 8.1)
(define "fg_medium_v3"
	; anti-tank
	{damage blastwave
		{energy (* %0 1.15)}
		{area 0.4 0.5}
	}
	; anti-personel
	{damage add blastwave
		{energy 1.5}
		{area (* 0.7 (+ %0 5)) (* 1.1 (+ %0 5))}
	}
	{damage add blastwave
		{energy 0.1}
		{area (* 1.3 (+ %0 5)) (* 1.3 (+ %0 5))}
	}
)

; fg_minimum: {damage} x3
;   %0 - value in {energy}
;   e.g. ("fg_minimum" args 3.5)
(define "fg_minimum"
	; anti-tank
	{damage blastwave
		{energy (* %0 1.15)}
		{area 0.1 0.2}
	}
	; anti-personel
	{damage add blastwave
		{energy 1.2}
		{area (* 0.5 (+ %0 5)) (* 0.9 (+ %0 5))}
	}
	{damage add blastwave
		{energy 0.1}
		{area (* 1.1 (+ %0 5)) (* 1.1 (+ %0 5))}
	}
)

; fg_v3: {damage} x3
;   %0 - value in {energy}
;   e.g. ("fg_v3" args 5.7)
(define "fg_v3"
	; anti-tank
	{damage blastwave
		{energy (* %0 1.15)}
		{area 0.4 0.5}
	}
	; anti-personel
	{damage add blastwave
		{energy 1.2}
		{area (* 0.5 (+ %0 5)) (* 0.9 (+ %0 5))}
	}
	{damage add blastwave
		{energy 0.1}
		{area (* 1.1 (+ %0 5)) (* 1.1 (+ %0 5))}
	}
)

; recoveryTime: {recoveryTime}
;   r - value in {recoveryTime}
;   e.g. ("recoveryTime" r(50))
(define "recoveryTime"
	{recoveryTime (/ 60 %r)}
)

; speed: {speed}
;   s - value in {speed}
;   e.g. ("speed" s(30))
(define "speed"
	{speed (* 1.0 %s)}
)
