; robz shared macros (macrostd share): one define per name, included where the copies were
; defines: crew_human_2, crew_human_link_bone, crew_human_no_linkbone, crew_human_no_targetable, crew_human_no_turnoff,
;   crew_human_open_for_crush_two_doors, crew_human_two_doors, crew_human_visible_placer, crew_human_visor, crew_human_visor_main

; crew_human_2: {placer {place}} {boarder {door} {link}}
;   place - value in {place}
;   group - value in {group}
;   bone - value in {linkbone}
;   door - value in {door}
;   animation - value in {anm}
;   e.g. ("crew_human_2" place(driver) door(emit1) group(crew) bone(driver) animation(driver))
(define "crew_human_2"
	{placer
		{place "%place" {group "%group"}  {linkbone "%bone"} {turnoff {sensor} {shadow}} }
	}
	{boarder
		{door "%door"}
		{link "%door" "%place" {anm "%animation"} {forward putoff} {reverse puton}}
	}
)

; crew_human_link_bone: {boarder {door} {link}} {placer {place}}
;   door - value in {door}
;   place - value in {link}
;   visor - value in {visor}
;   e.g. ("crew_human_link_bone" place(gunner) door(emit2) visor(main))
(define "crew_human_link_bone"
	{boarder
		{door "%door"}
		{link "%door" "%place" {anm "%place"} {forward putoff} {reverse puton}}
	}
	{placer
		{place "%place"	{LinkBone "%place"}	{visor "%visor"} {turnoff {sensor} {shadow}}}
	}
)

; crew_human_no_linkbone: {placer {place}} {boarder {door} {link}}
;   place - value in {place}
;   group - value in {group}
;   door - value in {door}
;   animation - value in {anm}
;   e.g. ("crew_human_no_linkbone" place(driver) door(emit1) group(crew) animation(driver))
(define "crew_human_no_linkbone"
	{placer
		{place "%place" {group "%group"}}
	}
	{boarder
		{door "%door"}
		{link "%door" "%place" {anm "%animation"} {forward putoff} {reverse puton}}
	}
)

; crew_human_no_targetable: {placer {place}} {boarder {door} {link}}
;   place - value in {place}
;   group - value in {group}
;   bone - value in {linkbone}
;   door - value in {door}
;   animation - value in {anm}
;   e.g. ("crew_human_no_targetable" place(driver) door(emit1) bone(driver) animation(driver) group(crew))
(define "crew_human_no_targetable"
	{placer
		{place "%place" {group "%group"} {linkbone "%bone"} {turnoff {sensor} {shadow}}}
	}
	{boarder
		{door "%door"}
		{link "%door" "%place" {anm "%animation"} {forward putoff} {reverse puton}}
	}
)

; crew_human_no_turnoff: {placer {place}} {boarder {door} {link}}
;   place - value in {place}
;   group - value in {group}
;   bone - value in {linkbone}
;   door - value in {door}
;   animation - value in {anm}
;   e.g. ("crew_human_no_turnoff" place(driver) bone(human1) door(human1) animation(1))
(define "crew_human_no_turnoff"
	{placer
		{place "%place" {group "%group"} {linkbone "%bone"}}
	}
	{boarder
		{door "%door"}
		{link "%door" "%place" {anm "%animation"} {forward putoff} {reverse puton}}
	}
)

; crew_human_open_for_crush_two_doors: {placer {place}} {boarder {door} {link}}
;   place - value in {place}
;   door1 - value in {door}
;   door2 - value in {door}
;   e.g. ("crew_human_open_for_crush_two_doors" place(charger) door1(emit3))
(define "crew_human_open_for_crush_two_doors"
	{placer
		{place "%place" {group "crew"} {linkbone "%place"} {turnoff {sensor} {shadow}} {openForCrush}}
	}
	{boarder
		{door "%door1"}
		{door "%door2"}
		{link "%door1" "%place" {anm "%place"} {forward putoff} {reverse puton}}
		{link "%door2" "%place" {anm "%place"} {forward putoff} {reverse puton}}

	}
)

; crew_human_two_doors: {placer {place}} {boarder {door} {link}}
;   place - value in {place}
;   door1 - value in {door}
;   door2 - value in {door}
;   e.g. ("crew_human_two_doors" place(driver) door1(emit1))
(define "crew_human_two_doors"
	{placer
		{place "%place" {group "crew"} {linkbone "%place"} {turnoff {sensor} {shadow}}}
	}
	{boarder
		{door "%door1"}
		{door "%door2"}
		{link "%door1" "%place" {anm "%place"} {forward putoff} {reverse puton}}
		{link "%door2" "%place" {anm "%place"} {forward putoff} {reverse puton}}
	}
)

; crew_human_visible_placer: {placer {place}} {boarder {door} {link}}
;   place - value in {place}
;   group - value in {group}
;   visor - value in {visor}
;   door - value in {door}
;   animation - value in {anm}
;   e.g. ("crew_human_visible_placer" place(gunner) door(emit2) group(crew) animation(gunner) visor(main))
(define "crew_human_visible_placer"
	{placer
		{place "%place" {group "%group"} {linkbone "%place"} {visor "%visor"}}
	}
	{boarder
		{door "%door"}
		{link "%door" "%place" {anm "%animation"} {forward putoff} {reverse puton}}
	}
)

; crew_human_visor: {placer {place}} {boarder {door} {link}}
;   place - value in {place}
;   group - value in {group}
;   visor - value in {visor}
;   door - value in {door}
;   animation - value in {anm}
;   e.g. ("crew_human_visor" place(charger) door(emit1) group(crew) animation(charger) visor(main))
(define "crew_human_visor"
	{placer
		{place "%place" {group "%group"} {visor "%visor"}}
	}
	{boarder
		{door "%door"}
		{link "%door" "%place" {anm "%animation"} {forward putoff} {reverse puton}}
	}
)

; crew_human_visor_main: {placer {place}} {boarder {door} {link}}
;   place - value in {place}
;   door1 - value in {door}
;   door2 - value in {door}
;   e.g. ("crew_human_visor_main" place(charger) door1(emit1) door2(emit2))
(define "crew_human_visor_main"
	{placer
		{place "%place"
			{group "crew"}
			{linkbone "%place"}
			{turnoff {sensor} {shadow}}
			{visor "main"}
		}
	}
	{boarder
		{door "%door1"}
		{door "%door2"}
		{link "%door1" "%place" {anm "%place"} {forward putoff} {reverse puton}}
		{link "%door2" "%place" {anm "%place"} {forward putoff} {reverse puton}}
	}
)
