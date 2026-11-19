(include "/properties/armoredcar.ext")
(include "/properties/selection/vehicle.inc"  scale(1.0))
{Extension "m3.mdl"}
{extension "crew.ext"}
{props "vehicle" "armored_car" "tank" "turret" "wheeled_6" "explosion_throw_crew" "vision_vehicle_medium" "switch_mgun"}

{extender "enumerator"}
(include "/properties/resupply_generic.inc")
("halftrack_ammo_us_inf")
; --- Godny hitbox armor (ported from GodnyMod: m3_usa.def) ---
{volume "sticky"
	{tags "grenade_fg_target"}
	{able clear {contact} {touch}}
	{component "sticky_body"}
}
{volume "body"		;рама
	{tags "body"}
	{component "body"}
	{thickness 6.35}
}
{volume "body1"	;передн€€ часть корпуса - отделение управлени€
	{component "body"}
	{tags "body"}
	{able {holed}}
	{thickness 6.35
		{front	12.7}
		;	{rear	6.35}
		;	{top	6.35}
		;	{bottom	6.35}
		{right	0.1}	;внутренн€€ стенка
	}
}
{volume "body2"		;задн€€ часть корпуса - десантное
	{tags "body"}
	{component "body"}
	{able {holed}}
	{thickness 6.35
		{front	0.1}	;внутренн€€ стенка
	;	{rear	6.35}
	;	{top	6.35}
	;	{bottom	6.35}
	}
}
{volume "body3"		;моторное
	{tags "body"}
	{component "body"}
	{thickness 6.35
		{front	12.7}
	;	{rear	6.35}
	;	{top	6.35}
	;	{bottom	6.35}
	}
}
{volume "body4"		;нижн€€ задн€€ часть корпуса (хвостик)
	{tags "body"}
	{component "body"}
	{thickness 6.35
		;	{front	6.35}
		;	{rear	6.35}
		{top	0.1}	;внутренн€€ стенка
	;	{bottom	6.35}
	}
}
{volume "body5"		;пулеметный бортик
	{tags "body"}
	{component "body"}
	{able {holed}}
	{thickness 6.35
		;	{front	6.35}
		;	{rear	6.35}
		;	{top	6.35}
		{bottom	0.1}	;внутренн€€ стенка
	}
}
{Volume "hole_bod"
	{able clear {hole}}
	{component "body"}
}
{volume "engine"
	{thickness 10}
}
{volume "roll"
	{thickness 15}
}
{volume "inventory"	;права€ боеукладка
	{thickness 0.1
		{left	5}
	}
}
{volume "inventory1"	;лева€ боеукладка
	{thickness 0.1
		{right	5}
	}
}
; --- end Godny hitbox armor ---
{component "sticky_body"}

{volume "body6"
	{tags "body"}
	{component "body"}
	{thickness 15}
}
{volume "body7"
	{tags "body"}
	{component "body"}
	{thickness 15}
}
{Volume "fuel"
	{thickness 1}
}

("armor_light_btr" args 1.0)

("wheel" args "wheelright1")
("wheel" args "wheelleft1")
("tracks")

{extender "inventory"
	{weapon "mgun"
		{mask "weapon mgun"}
	}
	{Box
		{item "n73at" "grenade" 10}
		{item "m61" "grenade" 25}
		{item "smoke" "grenade" 10}
		{item "bandage" 10}
		{item "dynamite"}
		{item "browning" filling "ammo hmgun ap" 100 {user "mgun"}}
		{item "springfield_belt ammo" 2500}
		{item "ammo hmgun ap" 1000}
		{item "weapon bazooka"}
		{item "ammo bazooka" 4}

	}
}

{Weaponry
	{place "mgun"
		{type "mgun_main"}
		{LinkBone "mgun"}
		{LinkAnimation "off"}
		{charger "gunner"}
		("abm_mgun_heavy_v2")
		{basic}
	}
}

{sensor
	{visor "main"
		{bone "mgun"}
	}
}

{Chassis
	{Locomotion ("locomotion")
		{MaxSpeed 35}
		{maxSpeedAtMaxTurn 6}
		{StartTime	30}
		{Gears  0.1 0.2 0.3 1}
		{RearGears 0.25}
	}
	{FuelBag
		{volume 230 }
		{rate	11 }
		{remain 230 }
		{fuel "fuel"}
	}
	{speed
		{Normal  35}
		{Slow  35}
	}
	; left track must be first
	("tank_trace" fx("tracks_sm") step(0.3) len(0.4) boneleft("wheell4") boneright("wheelr4"))
	("car_trace" fx("tracewheel01") step(0.09) wheell("wlf") wheelr("wrf") bonel("FXtraceL1") boner("FXtraceR1"))
}
{mass 7000}
{bone "mgun_rot"
	{speed 0.005}
}

