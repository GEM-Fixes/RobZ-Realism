;SDL
game_entity
{props "trench"}
{obstacleid "trench_wall"}
{collider "construction"}
{NoCastShadows}
{extender "land_patch"
	{AlignEnabled 1}
	{AlignStacked 0}
	{AlignVolumes 1}
	{TerrainType "road" "bridge"}
}
(include "/properties/robz/volumes.inc")
; boneLand: {bone {parameters}}
;   %0 - {bone}, [?]
;   e.g. ("boneLand"  args "trench_ground")
(define "boneLand"
	{bone %0 {parameters "Ground;Land;Align;"}}
)
; boneAlign: {bone {parameters}}
;   %0 - {bone}, [?]
;   e.g. ("boneAlign" args "trench_wood")
(define "boneAlign"
	{bone %0 {parameters "Align;"}}
)
