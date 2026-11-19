;SDL
(include "/properties/moto.ext")
;(include "/properties/shadow/moto.inc"  scX(0.5) scY(0.6) psfX(-7) psfY(0))
(include "/properties/selection/vehicle.inc"  scale(0.7))
{props "explosion_throw_crew" "turn_over" "vision_lev01"}
{able "emit_on_attack"}
(mod "mp"
	{able "-emit_on_attack"}
)
{patherId "moto"}

{sensor
	{Visor "main"
		{vision "vehicle_main"}
		{bone "visor1"}
	}
	{Visor "crew"
		{vision "moto_crew"}
		{bone "visor2"}
	}
	(mod "mp"
         {visor "view-around"
                {vision "moto_around"}
                {bone "basis"}
         }
    )
}

{Placer
	{place "driver" {Group "driver"} {LinkBone "driver"} {visor "main"} {turnoff {sensor}{shadow}}}
	;{place "gunner" {Group "driver"} {LinkBone "gunner"}	{visor "crew"} {turnoff {sensor}{shadow}}}
	{place "passenger" {Group "driver"} {LinkBone "passenger"} {turnoff {sensor}{shadow}}}
}
{boarder
	{door "emit1"}
	{door "emit2"}
	{door "emit3"}

	{anm "driver" {forward  {end "seat_driver_moto"}}}
	{anm "gunner" {forward  {end "seat_gunner_moto"}}}
	{anm "passenger" {forward  {end "seat_passenger"}}}

	{link "emit1" "driver"    {anm "driver"} {forward putoff} {reverse puton}}
	{link "emit2" "passenger" {anm "passenger"} {forward putoff} {reverse puton}}
	{link "emit3" "gunner"	  {anm "gunner"} {forward putoff} {reverse puton}}
}

("wheel" args "wheel1")
("wheel" args "wheel2")
("wheel" args "wheel3")

{extender "inventory"
	{weapon "carcano_m1891cavalry"
		;{mask "weapon carcano_m1891cavalry"}
	}
	{Box
		{item  "ammo rifle" 144 }
	}
}
{mass 200}
{Chassis
	{Locomotion ("locomotion")
		{MaxSpeed	49	}
				(mod "mp"
					{maxspeed   45}
				)			; максимальная скорость, kmph
	  	{maxSpeedAtMaxTurn 17}	
		{StartTime	10	}		; время разгона до макс. скорости с 0, seconds
		{BrakeTime	2	}		; время торможения с макс. скорости до 0, seconds
		{StopTime	4	}		; время остановки после отключения двигателя с макс. скорости до 0, seconds
		{TurnRadius	3	}		; мин. радиус разворота, meter
		{Gears		0.35 0.5 0.7 1.0} ; передаточные коэф-ты коробки передач
		{RearGears	0.33 0.5}	; передаточные коэф-ты коробки передач
		{SteerOn	30}			; скорость поворота колес, градусов в секунду
		{SteerOff	40}         ; скорость возврата колес в исх. состояние, градусов в секунду
		{SplineRadius 2}		; ограничение радиуса поворота на сплайнах, метров
	}	
	{FuelBag
		{volume 50 }	; liters
		{rate	10 }   	; liters per kilometer
		{remain 50 }
		{fuel "fuel"}
	}
	{speed
		{Slow	7	}	; km/h
	}
}

{Weaponry
	{place "mgun"
		{LinkBone "mgun"}
		{LinkAnimation "off"}
		{charger "gunner"}
	}
}  	
{Extension "guzzi-sa500.mdl"}
	{bone "gun_rot"
		{limits -45 35}
	}