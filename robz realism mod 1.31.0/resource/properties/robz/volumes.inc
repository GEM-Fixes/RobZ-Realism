; robz shared macros (macrostd share): one define per name, included where the copies were
; defines: volume

; volume: {Volume {thickness} {tags} {able}}
;   %0 - value in {Volume}
;   e.g. ("volume" args "body")
(define "volume"
	{Volume %0 {thickness 20} {tags "body"} {able {contact 0} {obstacle 1}}}
)
; vol_plate_hit: armor plate that takes touch, bullet and blast hits
;   name - volume name in the model (text, without quotes)
;   mm - armor thickness, mm
;   e.g. ("vol_plate_hit" name(body) mm(10))
(define "vol_plate_hit"
	{Volume "%name" {thickness %mm} {able {touch} {bullet} {blast}}}
)

; vol_body_visible: plate tagged body, visible
;   name - volume name in the model (text, without quotes)
;   mm - armor thickness, mm
;   e.g. ("vol_body_visible" name(body) mm(10))
(define "vol_body_visible"
	{Volume "%name" {Tags "body"} {Thickness %mm} {able {visible 1}}}
)

; vol_body_plate_lower: armor plate of the body component (tags + component "body"), key written volume
;   name - volume name in the model (text, without quotes)
;   mm - armor thickness, mm
;   e.g. ("vol_body_plate_lower" name(body) mm(10))
(define "vol_body_plate_lower"
	{volume "%name" {tags "body"} {component "body"} {thickness %mm}}
)

; vol_body_fire: plate tagged body + fire
;   name - volume name in the model (text, without quotes)
;   mm - armor thickness, mm
;   e.g. ("vol_body_fire" name(body) mm(10))
(define "vol_body_fire"
	{Volume "%name" {Tags "body" "fire"} {Thickness %mm}}
)

; vol_body_tagged: plate tagged body
;   name - volume name in the model (text, without quotes)
;   mm - armor thickness, mm
;   e.g. ("vol_body_tagged" name(body) mm(10))
(define "vol_body_tagged"
	{Volume "%name" {Tags "body"} {Thickness %mm}}
)

; vol_body_part_lower: volume of the body component without thickness, key written volume
;   name - volume name in the model (text, without quotes)
;   e.g. ("vol_body_part_lower" name(body))
(define "vol_body_part_lower"
	{volume "%name" {tags "body"} {component "body"}}
)

; vol_body_plate: armor plate of the body component (tags + component "body")
;   name - volume name in the model (text, without quotes)
;   mm - armor thickness, mm
;   e.g. ("vol_body_plate" name(body) mm(10))
(define "vol_body_plate"
	{Volume "%name" {tags "body"} {component "body"} {thickness %mm}}
)

; vol_turret_part: volume of the turret component without thickness
;   name - volume name in the model (text, without quotes)
;   e.g. ("vol_turret_part" name(body))
(define "vol_turret_part"
	{Volume "%name" {tags "turret"} {component "turret"}}
)

; vol_turret_hole_only: turret volume whose only ability is hole
;   name - volume name in the model (text, without quotes)
;   e.g. ("vol_turret_hole_only" name(body))
(define "vol_turret_hole_only"
	{Volume "%name" {able clear {hole}} {component "turret"}}
)

; vol_body_hole_only: body volume whose only ability is hole
;   name - volume name in the model (text, without quotes)
;   e.g. ("vol_body_hole_only" name(body))
(define "vol_body_hole_only"
	{Volume "%name" {able clear {hole}} {component "body"}}
)

; vol_body_no_obstacle: plate tagged body that is no obstacle
;   name - volume name in the model (text, without quotes)
;   mm - armor thickness, mm
;   e.g. ("vol_body_no_obstacle" name(body) mm(10))
(define "vol_body_no_obstacle"
	{Volume "%name" {Tags "body"} {Thickness %mm} {able {obstacle 0}}}
)

; vol_body_part: volume of the body component without thickness
;   name - volume name in the model (text, without quotes)
;   e.g. ("vol_body_part" name(body))
(define "vol_body_part"
	{Volume "%name" {tags "body"} {component "body"}}
)

; vol_invisible: volume that is not visible
;   name - volume name in the model (text, without quotes)
;   e.g. ("vol_invisible" name(body))
(define "vol_invisible"
	{Volume "%name" {able {visible 0}}}
)

; vol_body_fire_hidden: volume tagged body + fire without thickness, not visible and no obstacle
;   name - volume name in the model (text, without quotes)
;   e.g. ("vol_body_fire_hidden" name(body))
(define "vol_body_fire_hidden"
	{Volume "%name" {Tags "body" "fire"} {able {visible 0} {obstacle 0}}}
)

; vol_gun_part: volume of the gun component without thickness
;   name - volume name in the model (text, without quotes)
;   e.g. ("vol_gun_part" name(body))
(define "vol_gun_part"
	{Volume "%name" {tags "gun"} {component "gun"}}
)

; vol_body_hidden: plate tagged body, not visible and no obstacle
;   name - volume name in the model (text, without quotes)
;   mm - armor thickness, mm
;   e.g. ("vol_body_hidden" name(body) mm(10))
(define "vol_body_hidden"
	{Volume "%name" {Tags "body"} {Thickness %mm} {able {visible 0} {obstacle 0}}}
)

; vol_body_fire_no_obstacle: plate tagged body + fire that is no obstacle
;   name - volume name in the model (text, without quotes)
;   mm - armor thickness, mm
;   e.g. ("vol_body_fire_no_obstacle" name(body) mm(10))
(define "vol_body_fire_no_obstacle"
	{Volume "%name" {Tags "body" "fire"} {Thickness %mm} {able {obstacle 0}}}
)

; vol_body_plate_component_first: armor plate of the body component, key written volume, component before tags
;   name - volume name in the model (text, without quotes)
;   mm - armor thickness, mm
;   e.g. ("vol_body_plate_component_first" name(body) mm(10))
(define "vol_body_plate_component_first"
	{volume "%name" {component "body"} {tags "body"} {thickness %mm}}
)

; vol_body_plate_no_obstacle_blast: body component plate that is no obstacle and takes no blast
;   name - volume name in the model (text, without quotes)
;   mm - armor thickness, mm
;   e.g. ("vol_body_plate_no_obstacle_blast" name(body) mm(10))
(define "vol_body_plate_no_obstacle_blast"
	{Volume "%name" {tags "body"} {able {obstacle 0} {blast 0}} {thickness %mm} {component "body"}}
)

; vol_sticky_grenade_target: sticky_body volume a thrown grenade sticks to (tag grenade_fg_target, contact + touch only)
;   name - volume name in the model (text, without quotes)
;   e.g. ("vol_sticky_grenade_target" name(body))
(define "vol_sticky_grenade_target"
	{volume "%name" {tags "grenade_fg_target"} {able clear {contact} {touch}} {component "sticky_body"}}
)

; vol_turret_part_component_first: volume of the turret component without thickness, key written volume, component before tags
;   name - volume name in the model (text, without quotes)
;   e.g. ("vol_turret_part_component_first" name(body))
(define "vol_turret_part_component_first"
	{volume "%name" {component "turret"} {tags "turret"}}
)

; vol_body_part_component_first: volume of the body component without thickness, key written volume, component before tags
;   name - volume name in the model (text, without quotes)
;   e.g. ("vol_body_part_component_first" name(body))
(define "vol_body_part_component_first"
	{volume "%name" {component "body"} {tags "body"}}
)

