(include "/properties/tank.ext")
(include "/properties/selection/vehicle.inc"  scale(1.2))
{props "medium" "mine_exploder" "vision_vehicle_high" "tractor" "heavy tow"}
{tag "heavy_tow"}
{extender "enumerator"}

("armor_medium" turret(0) body(45 45 45 20))
("armor_engine"  t(45 45 45 20))
("rus_2-5x_sight")

; --- Godny hitbox armor (ported from GodnyMod: t34m.def) ---
{volume "body1"	;нижн€€ часть корпуса
	{component "body"}
	{tags "body"}
	{thickness 45
		{front	45}
		{rear	45}
		{top	16}
		{bottom	20}
	}
}
{volume "body2"	;верхн€€ часть корпуса
	{component "body"}
	{tags "body"}
	{thickness 45
		{front	45}
		{rear	45}
		{top	16}
		{bottom	20}
	}
}
{volume "body3"	;моторное верх
	{tags "body"}
	{component "body"}
	{thickness 45
		{front	45}
		{rear	45}
		{top	10}	;мто
		{bottom	20}
	}
}
{volume "engine"
	{thickness 10}
}
{volume "roller"
	{thickness 150}
}
; --- end Godny hitbox armor ---
{boarder
	{anm "left"
		{forward	{begin	"board_SdKfz-232_left"}}
		{reverse 	{end	"emit_tank_2_hold"}}
	}
	{anm "right"
		{forward	{begin	"board_SdKfz-232_right"}}
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
("crew_human" place(driver)	door1(emit1) door2(emit2) visor(driver))
("seat_human" place(seat1) bone(seat01) door(emit3)  animation(armor1))
("seat_human" place(seat2) bone(seat02) door(emit4)  animation(armor))
("seat_human" place(seat3) bone(seat03) door(emit5)  animation(armor))
("seat_human" place(seat4) bone(seat04) door(emit6)  animation(armor1))

{extender "inventory"
	{box
		{item "ammo dt29_mag" 2400}
		{item "dynamite" 2}
	}
}
{Weaponry
	{place "mgun1"
		{type "mgun_hull"}
		{weapon "dt" filled}
		{foresight "foresight4"}
		{gunner "driver"}
		{charger "driver"}
		("abm_mgun")
	}
}

{mass 25500}
{Chassis
	("tank_trace" fx("tracks_mid") step(0.52) len(0.28))
	{Locomotion ("locomotion")
		{maxspeed   36}
		{maxSpeedAtMaxTurn 5}
		{StartTime	       30}
		{TurnTime	        15}
		{TurnStart        1.5}
		{BrakeTime        4}
		{StopTime         1.5}
		{TurnRadius         8}
		{TurnStop         0.7}
		{Gears      0.1 0.25 0.35 1.0}
		{RearGears       0.27}
	}
	{FuelBag
		{volume 790 }
		{rate	23 }
		{remain 790 }
		{fuel "fuel"}
	}
	{speed
		{Normal  36}
		{Slow  36}
	}
}

{Extension "t34m.mdl"}

