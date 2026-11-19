; robz shared macros (macrostd share): one define per name, included where the copies were
; defines: volume

; volume: {Volume {thickness} {tags} {able}}
;   %0 - value in {Volume}
;   e.g. ("volume" args "body")
(define "volume"
	{Volume %0 {thickness 20} {tags "body"} {able {contact 0} {obstacle 1}}}
)
