;SDL
(include "/properties/moto.ext")
(include "/properties/selection/vehicle.inc"  scale(0.7))
{props "explosion_throw_crew" "turn_over" "vision_vehicle_minimum"}
{able "emit_on_attack"}
(mod "mp"
	{able "-emit_on_attack"}
)
{collider "tank.light"}
{PatherId "vehicle.small"}

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
	{Box
		;{item "ammo 6x52" 144}
	}
}
{mass 200}
{Chassis
	{Locomotion ("locomotion")
		{MaxSpeed	49	}
				(mod "mp"
					{maxspeed   45}
				)			;    ᨬ  쭠  ᪮    , kmph
	  	{maxSpeedAtMaxTurn 17}	
		{StartTime	10	}		;  ६  ࠧ            . ᪮      0, seconds
		{BrakeTime	2	}		;  ६   ମ            . ᪮       0, seconds
		{StopTime	4	}		;  ६    ⠭       ᫥  ⪫ 祭        ⥫        . ᪮       0, seconds
		{TurnRadius	3	}		;    . ࠤ    ࠧ    , meter
		{Gears		0.35 0.5 0.7 1.0} ;   ।         -     ஡     ।  
		{RearGears	0.33 0.5}	;   ।         -     ஡     ।  
		{SteerOn	30}			; ᪮                 ,  ࠤ ᮢ   ᥪ㭤 
		{SteerOff	40}         ; ᪮                       .    ﭨ ,  ࠤ ᮢ   ᥪ㭤 
		{SplineRadius 2}		;   ࠭ 祭   ࠤ              ᯫ     ,    ஢
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

 	
{Extension "guzzi-sa500.mdl"}
	{bone "gun_rot"
		{limits -45 35}
	}