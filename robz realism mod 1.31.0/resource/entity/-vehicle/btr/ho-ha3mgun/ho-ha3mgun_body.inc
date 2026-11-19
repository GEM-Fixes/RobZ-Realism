(include "/properties/robz/volumes.inc")
(include "/properties/armoredcar.ext")
(include "/properties/selection/vehicle.inc"  scale(1.0))
{Extension "ho-ha3mgun.mdl"}
{extension "crew.ext"}
{props "vehicle" "armored_car" "tank" "turret" "wheeled_6" "explosion_throw_crew" "vision_vehicle_medium" "switch_mgun"}
{targetSelector "tank"}

{extender "enumerator"}
(include "/properties/resupply_generic.inc")
("halftrack_ammo_jap_inf")
; --- Godny hitbox armor (ported from GodnyMod: ho-ha3mgun.def) ---
{volume "sticky"	;как я понял, нужно этот волум на дно класть, чтобы гранаты не отскакивали от этого волума и не проваливались через дно
	{tags "grenade_fg_target"}
	{able clear {contact} {touch}}
	{component "sticky_body"}
}
{volume "body"	;днище корпуса
	{tags "body"}
	{component "body"}
	{thickness 8}
}
{volume "body1"	;кабина, передняя часть
	{tags "body"}
	{component "body"}
	{thickness 8
		{front	12}
		;	{rear	8}
		{top	6}
		{bottom	6}
	}
}
{volume "body2"	;кабина, лоб корпуса
	{tags "body"}
	{component "body"}
	{able {holed}}
	{thickness 8
		{front	12}
		;	{rear	8}
		{top	6}
		{bottom	6}
		{right	0.1}	;внутренняя стенка
	}
}
{volume "body3"	;моторное верх
	{tags "body"}
	{component "body"}
	{thickness 8
		{front	12}
		;	{rear	8}
		{top	8} 	;гласис
		{bottom	6}
	}
}
{volume "body4"	;моторное низ
	{tags "body"}
	{component "body"}
	{thickness 8
		{front	12}
		;	{rear	8}
		{top	6}
		{bottom	6}
	}
}
{volume "body5"	;десантное
	{tags "body"}
	{component "body"}
	{able {holed}}
	{thickness 8
		;	{front	8}
		;	{rear	8}
		{top	6}
		{bottom	6}
	}
}
{volume "engine"
	{thickness 10}
}
{Volume "fuel"
	{thickness 1}
}
{volume "door3"
	{tags "door3"}
	{component "door3"}
	{thickness 8}
}
{volume "door4"
	{tags "door4"}
	{component "door4"}
	{thickness 8}
}
{volume "doorleft"
	{tags "doorl"}
	{component "doorl"}
	{thickness 6
		{left	8}
	}
}
{volume "doorright"
	{tags "doorr"}
	{component "doorr"}
	{thickness 6
		{right	8}
	}
}
("vol_body_hole_only" name(hole_bod))
; --- end Godny hitbox armor ---
{volume "cabin"
	{tags "cabin"}
	{component "cabin"}
	{thickness 15}
}
{volume "door"
	{tags "door"}
	{component "door"}
	{thickness 15}
}
{volume "cargo"
	{tags "cargo"}
	{component "cargo"}
	{thickness 15}
}
("armor_light_btr" args 1.0)



{sensor
	{visor "main" {bone "visor1"} {vision "vehicle_main"}}
	{visor "gunner1" {bone "mgun1"}}
	{visor "gunner2" {bone "mgun2"}}
	{visor "gunner3" {bone "mgun3"}}
	{visor "view-around"
		{vision "none"}
		{bone "basis"}
	}
}
{placer
	{place "driver" {visor "main"}}
	{place "gunner1" {useVision} {visor "gunner1"}}
	{place "gunner2" {useVision} {visor "gunner2"}}
	{place "gunner3" {useVision} {visor "gunner3"}}
}


("wheel" args "wheelright1")
("wheel" args "wheelleft1")
("tracks")

{extender "inventory"
	{weapon "mgun"
		{mask clear}
	}
	{weapon "mgun1"
		{mask "weapon mgun"}
	}
	{box
		{item "type3at_a" "grenade" 10}
		{item "type99" "grenade" 25}
		{item "smoke" "grenade" 10}
		{item "bandage" 10}
		{item "dynamite"}
		{item "type99_mg" filled {user "mgun1"}}
		{item "type99_mag" "ammo" 2400}
	}
}
{Weaponry
	{place "mgun1"
		{type "mgun_main"}
		{LinkBone "mgun1"}
		{LinkAnimation "off"}
		{gunner "gunner1"}
		{charger "gunner1"}
		{foresight "foresight4"}
		("abm_mgun")
		{basic}
	}
	{place "mgun2"
		{type "mgun_right"}
		{LinkBone "mgun2"}
		{LinkAnimation "off"}
		{weapon "type99_mg" filled}
		{gunner "gunner2"}
		{charger "gunner2"}
		{foresight "foresight5"}
		("abm_mgun")
		{basic}
	}
	{place "mgun3"
		{type "mgun_left"}
		{LinkBone "mgun3"}
		{LinkAnimation "off"}
		{weapon "type99_mg" filled}
		{gunner "gunner3"}
		{charger "gunner3"}
		{foresight "foresight6"}
		("abm_mgun")
		{basic}
	}

}

(include "/properties/robz/vehicle.inc")

{Chassis
	; left track must be first
	("tank_trace_track" fx("tracks_mid") step(0.52) len(1.0) boneleft("FXtraceL2") boneright("FXtraceR2"))
	("car_trace" fx("tracewheel02") step(0.09) wheell("wlf") wheelr("wrf") bonel("FXtraceL1") boner("FXtraceR1"))
	{Locomotion ("locomotion")
		{MaxSpeed	35}
		{maxSpeedAtMaxTurn 6}
		{StartTime	30}
		{BrakeTime	1.5}
		{StopTime	2.5}
		{TurnRadius	8}
		{Gears  0.1 0.2 0.3 1}
		{RearGears  0.25}

	}
	{speed
		{Normal  35}
		{Slow  35}
	}
	{FuelBag
		{volume 200 }
		{rate	10 }
		{remain 200 }
		{fuel "fuel"}
	}
}

{mass 8200}
