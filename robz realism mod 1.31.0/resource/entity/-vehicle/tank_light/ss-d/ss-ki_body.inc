(include "/properties/robz/volumes.inc")
(include "/properties/tank.ext")
(include "/properties/selection/vehicle.inc"  scale(1.2))
{props "medium" "tractor" "heavy tow" "ss-d" "mine_exploder" "vision_vehicle_medium" "flamer_tank"}
{targetSelector "tank_bullet"}
{targetClass "tank" "bullet"}
{patherId "tank.light"}
{tag "heavy_tow"}
{extender "enumerator"}

; --- Godny hitbox armor (ported from GodnyMod: ss-d.def) ---
{volume "body"	;нижн€€ часть корпуса
	{tags "body"}
	{component "body"}
	{thickness 25
		;	{front	25}
		;	{rear	25}
		{top	10}
		{bottom	10}
	}
}
{volume "body1"	;верхн€€ передн€€ часть корпуса
	{tags "body"}
	{component "body"}
	{thickness 25
		;	{front	25}
		;	{rear	25}
		{top	10}
		{bottom	10}
	}
}
{volume "body2"	;верхн€€ задн€€ часть корпуса
	{tags "body"}
	{component "body"}
	{thickness 25
		;	{front	25}
		;	{rear	25}
		{top	10}
		{bottom	10}
	}
}
{volume "body3"	;лева€ консоль
	{tags "body"}
	{component "body"}
	{thickness 25
		;	{front	25}
		;	{rear	25}
		{top	10}
		{bottom	10}
	}
}
{volume "body4"	;права€ консоль
	{tags "body"}
	{component "body"}
	{thickness 25
		;	{front	25}
		;	{rear	25}
		{top	10}
		{bottom	10}
	}
}
{volume "body5"	;задн€€ часть корпуса
	{tags "body"}
	{component "body"}
	{thickness 25
		;	{front	25}
		;	{rear	25}
		{top	10}
		{bottom	10}
	}
}
{Volume "engine"
	{thickness 10}
}
{volume "fork"
	{able clear {bullet} {select} {contact_ground} {touch} {contact}}
	{thickness 800}
}
{volume "fork1"
	{able clear {bullet} {select} {contact_ground} {touch} {contact}}
	{thickness 800}
}
; --- end Godny hitbox armor ---
("vol_body_part_lower" name(body6))
("armor_spa_light" armor(25 15))
("shield" args 10)

{extender "inventory"
	{box
		{item "tank_balloon" filled}
		{item "ammo type97_mag" 1600}
	}
}

("crew_4_human")

{boarder
	{anm "left"
		{forward	{begin	"board_tank_left"} {end "seat_armor"}}
		{reverse 	{end	"emit_tank_1"}}
	}
	{anm "right"
		{forward	{begin	"board_tank_right"} {end "pose_mgun_pz6"}}
		{reverse 	{end	"emit_tank_2_hold"}}
	}
	{anm "armor"
		{forward	{begin	"board_HighArmor"} 	{end "pose_seat_armor_1"}}
		{reverse 	{end	"emit_tank_2"}}
	}
	{anm "armor1"
		{forward	{begin	"board_HighArmor"} {end "pose_seat_armor_1"}}
		{reverse 	{end	"emit_body"}}
	}
}
("seat_human" place(seat1) bone(seat01) door(emit3)  animation(armor1))
("seat_human" place(seat2) bone(seat02) door(emit4)  animation(armor))
("seat_human" place(seat3) bone(seat03) door(emit5)  animation(armor))
("seat_human" place(seat4) bone(seat04) door(emit6)  animation(armor1))

{Weaponry
	{place "flamer1"
		{type "secondary_flamer"}
		{weapon "flame_thrower_ssd" filled}
		{foresight "foresight9"}
		{gunner "commander"}
		{charger "commander"}
		{basic}
	}
	{place "flamer2"
		{type "secondary_flamer"}
		{weapon "flame_thrower_ssd" filled}
		{foresight "foresight10"}
		{gunner "gunner"}
		{charger "gunner"}
		{basic}
	}
	{place "flamer5"
		{type "secondary_flamer"}
		{weapon "flame_thrower_ssd" filled}
		{foresight "foresight11"}
		{gunner "charger"}
		{charger "charger"}
		{basic}
	}
	{place "mgun"
		{type "mgun_hull"}
		{weapon "type97_mg" filled}
		{foresight "foresight3"}
		{gunner "commander"}
		{charger "commander"}
		("abm_mgun")
		{basic}
	}
	{place "mgun1"
		{type "mgun_right"}
		{weapon "type97_mg" filled}
		{foresight "foresight4"}
		{gunner "gunner"}
		{charger "gunner"}
		("abm_mgun")
	}
}

{mass 23000}
{Chassis
	("tank_trace" fx("tracks_mid") step(0.52) len(0.2))
	{Locomotion ("locomotion")
		{maxspeed   18}
		{maxSpeedAtMaxTurn 6}
		{StartTime  15}
		{TurnTime   15}
		{TurnStart  2}
		{TurnRadius 8}
		{TurnStop   1}
		{BrakeTime  1.5}
		{StopTime   2.5}
		{Gears   0.4 1}
		{RearGears  0.3}
	}
	{FuelBag
		{volume 390 }
		{rate	 20 }
		{remain 390 }
		{fuel "fuel"}
	}
	{speed
		{Normal  18}
		{Slow  18}
	}
}
{Extension "ss-d.mdl"}
