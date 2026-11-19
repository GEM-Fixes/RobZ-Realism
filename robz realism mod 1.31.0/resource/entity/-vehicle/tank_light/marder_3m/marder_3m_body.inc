(include "/properties/robz/volumes.inc")
(include "/properties/tank.ext")
(include "/properties/selection/vehicle.inc"  scale(1.0))
{props "light" "-turret" "opened" "vision_vehicle_medium" "muzzle_medium_sides"}
{extension "crew.ext"}

("vol_body_part_lower" name(body1))
("vol_body_part_lower" name(body2))
("vol_body_part_lower" name(body3))
("vol_body_part_lower" name(body4))
("vol_body_part_lower" name(body5))
("vol_body_part_lower" name(body6))
("vol_body_part_lower" name(body7))
("vol_body_part_lower" name(body8))
("vol_body_part_lower" name(body9))
("vol_body_part_lower" name(body10))


("armor_medium_custom" turret(11 11 0 0) body(50 15 15 10))
("armor_engine"  t(10))
("ger_5x8_sight")

{sensor
	{visor "main"
		{bone "visor1"}
	}
}
{extender "inventory"
	{box
		{item "ammo bullet75 gerp apcbc" 14}
		{item "ammo bullet75 gerp fg" 8}
		{item "ammo bullet75 gerp apcr" 2}
		{item "ammo bullet75 gerp heatc" 3}
		{item "mg42_inf" filled}
		{item "ammo mg_mauser belt" 600}
	}
}
{Weaponry
	("restore_ik_time")
	{place "gun"
		{RestoreIKAfterAim}
		{weapon "75mm_pak40" filling "ammo bullet75 gerp apcbc" 1}
		("abm_medium")
	}
}

("tracks")

{Extension "marder_2.mdl"}
{mass 10500}
{Chassis
	("tank_trace" fx("tracks_mid") step(0.56) len(0.3))
	{Locomotion ("locomotion")
		{maxspeed   24}
		{maxSpeedAtMaxTurn 5}
		{StartTime  25}
		{TurnStart  1.7}
		{TurnTime   15}
		{TurnRadius 10}
		{TurnStop   0.9}
		{BrakeTime  1}
		{StopTime   2}
		{Gears   0.1 0.2 0.3 1}
		{RearGears  0.3}
	}
	{FuelBag
		{volume 220 }
		{rate	14 }
		{remain 220 }
		{fuel "fuel"}
	}
	{speed
		{Normal  18}
	}
	{DisableMoveWhileFiring}
}
{bone "turret"
	{speed 0.002}
}
{bone "gun_rot"
	{speed 0.002}
}
