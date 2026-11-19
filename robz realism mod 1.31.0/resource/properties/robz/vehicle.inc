; robz shared macros (macrostd share): one define per name, included where the copies were
; defines: tank_trace_track

; tank_trace_track: {Track "left" {Tracer} {TextureScroller}} {Track "right" {Tracer} {TextureScroller}}
;   fx - value in {View}
;   boneleft - value in {Bone}
;   step - value in {Step}
;   len - value in {Length}
;   boneright - value in {Bone}
;   e.g. ("tank_trace_track" fx("tracks_mid") step(0.52) len(1.0) boneleft("FXtraceL2") boneright("FXtraceR2"))
(define "tank_trace_track"
	{Track "left"
		{Tracer
			{View %fx} ; "tracks"
			{Bone %boneleft}
			{Step %step}			; 0.7 meters
		}
		{TextureScroller
			{Bone "TrackL"}
			{Length %len}		; 0.6 meters per animation
		}
	}
	{Track "right"
		{Tracer
			{View %fx}
			{Bone %boneright}
			{Step %step}			; in meters
		}
		{TextureScroller
			{Bone "TrackR"}
			{Length %len}		; meters per animation
		}
	}
)
