; robz shared macros (macrostd share): one define per name, included where the copies were
; defines: contact_part, health_damage, terrain_fx_human, try_get_off

; contact_part: {if {if}}
;   e - text it is pasted into
;   v - value in {if}
;   ud - value in {if}
;   d - value in {if}
;   e.g. ("contact_part" e("big part") v(3) ud(20) d(120))
(define "contact_part"
	else effector %e
	{if contact_velocity %v
		{if difficulty "easy"
			{if user_control
				("health_damage" c(%ud))
				else
				("health_damage" c(%d))
			}
			else
			("health_damage" c(%d))
		}

		("health_damage" c(%d))
	}

)

; health_damage: {health_damage_count {effects}}
;   c - value in {health_damage_count}
;   e.g. ("health_damage" c(10))
(define "health_damage"
	{health_damage_count %c
		{effects "" "hit" "damage" "die" "die"}
	}
)

; terrain_fx_human: {on {if}} {on {view}}
;   %0 - value in {on}
;   %1 - value in {view}
;   1_time_short - value in {view}
;   e.g. ("terrain_fx_human" args "mud" mud)
(define "terrain_fx_human"
	{on terrain_fx %0 enter
		{if not swimming
			{view start "on_%1"}
			{view start "on_%1_time_short"}
			{delay 0.1
				{view pause "on_%1_time_short"}
			}
		}
	}
	{on terrain_fx %0 leave
		{view pause "on_%1"}
	}
)

; try_get_off: {delay {get_off}}
;   %0 - value in {delay}
;   e.g. ("try_get_off" args 1.0)
(define "try_get_off"
	{delay %0 0.5
		{get_off}
	}
)
