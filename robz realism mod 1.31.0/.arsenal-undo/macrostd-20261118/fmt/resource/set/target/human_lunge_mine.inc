{selector
	{unit "human" "lunge_mine"}

;IMMEDIATE THREATS TO UNIT OR ALLIES
	
	{group
		{ignore {class airborne}}
		{select {weapon "flame_thrower_tank"} {attacking} {in_range 30}}
	}
	{group
		{ignore {class airborne}}
		{select {weapon "flame_thrower_tank"} {threating} {in_range 30}}
	}
	{group
		{ignore {class airborne}}
		{select {weapon "flame_thrower_tank"} {in_range 30}}
	}
	
	{group
		{ignore {class airborne}}
		{select {weapon "flame_thrower_tank"} {attacking} {in_range 50}}
	}
	{group
		{ignore {class airborne}}
		{select {weapon "flame_thrower_tank"} {threating} {in_range 50}}
	}
	{group
		{ignore {class airborne}}
		{select {weapon "flame_thrower_tank"} {in_range 50}}
	}
	
	{group
		{ignore {class airborne}}
		{select {class tank} {attacking} {in_range 30}}
	}
	{group
		{ignore {class airborne}}
		{select {class light_tank} {attacking} {in_range 30}}
	}
	{group
		{ignore {class airborne}}
		{select {class armoredcar} {attacking} {in_range 30}}
	}
	{group
		{ignore {class airborne}}
		{select {class tank} {threating} {in_range 30}}
	}
	{group
		{ignore {class airborne}}
		{select {class light_tank} {threating} {in_range 30}}
	}
	{group
		{ignore {class airborne}}
		{select {class armoredcar} {threating} {in_range 30}}
	}
	{group
		{ignore {class airborne}}
		{select {class tank} {in_range 30}}
	}
	{group
		{ignore {class airborne}}
		{select {class light_tank} {in_range 30}}
	}
	{group
		{ignore {class airborne}}
		{select {class armoredcar} {in_range 30}}
	}
	
	{group
		{ignore {class airborne}}
		{select {class tank} {attacking} {in_range 50}}
	}
	{group
		{ignore {class airborne}}
		{select {class light_tank} {attacking} {in_range 50}}
	}
	{group
		{ignore {class airborne}}
		{select {class armoredcar} {attacking} {in_range 50}}
	}
	{group
		{ignore {class airborne}}
		{select {class tank} {threating} {in_range 50}}
	}
	{group
		{ignore {class airborne}}
		{select {class light_tank} {threating} {in_range 50}}
	}
	{group
		{ignore {class airborne}}
		{select {class armoredcar} {threating} {in_range 50}}
	}
	{group
		{ignore {class airborne}}
		{select {class tank} {in_range 50}}
	}
	{group
		{ignore {class airborne}}
		{select {class light_tank} {in_range 50}}
	}
	{group
		{ignore {class airborne}}
		{select {class armoredcar} {in_range 50}}
	}
	
;SOON THREATS TO UNIT OR ALLIES	
	
	{group
		{ignore {class airborne}}
		{select {weapon "flame_thrower_tank"} {attacking} {in_range 85}}
	}
	{group
		{ignore {class airborne}}
		{select {weapon "flame_thrower_tank"} {threating} {in_range 85}}
	}
	{group
		{ignore {class airborne}}
		{select {weapon "flame_thrower_tank"} {in_range 85}}
	}
	
	{group
		{ignore {class airborne}}
		{select {class tank} {attacking} {in_range 95}}
	}
	{group
		{ignore {class airborne}}
		{select {class light_tank} {attacking} {in_range 95}}
	}
	{group
		{ignore {class airborne}}
		{select {class armoredcar} {attacking} {in_range 95}}
	}
	{group
		{ignore {class airborne}}
		{select {class tank} {threating} {in_range 95}}
	}
	{group
		{ignore {class airborne}}
		{select {class light_tank} {threating} {in_range 95}}
	}
	{group
		{ignore {class airborne}}
		{select {class armoredcar} {threating} {in_range 95}}
	}
	{group
		{ignore {class airborne}}
		{select {class tank} {in_range 95}}
	}
	{group
		{ignore {class airborne}}
		{select {class light_tank} {in_range 95}}
	}
	{group
		{ignore {class airborne}}
		{select {class armoredcar} {in_range 95}}
	}
	
	{group
		{ignore {class airborne}}
		{select {class cannon} {attacking} {in_range 30}}
	}
	{group
		{ignore {class airborne}}
		{select {class car} {attacking} {in_range 30}}
		{select {class cannon} {attacking} {in_range 40}}
	}
	{group
		{ignore {class airborne}}
		{select {class car} {attacking} {in_range 40}}
		{select {class cannon} {attacking} {in_range 50}}
	}
	{group
		{ignore {class airborne}}
		{select {class car} {attacking} {in_range 50}}
		{select {class cannon} {attacking} {in_range 60}}
	}
	{group
		{ignore {class airborne}}
		{select {class car} {attacking} {in_range 60}}
		{select {class cannon} {attacking} {in_range 70}}		
	}
	
	{group
		{ignore {class airborne}}
		{select {class cannon} {threating} {in_range 30}}
	}
	{group
		{ignore {class airborne}}
		{select {class car} {threating} {in_range 30}}
		{select {class cannon} {threating} {in_range 40}}
	}
	{group
		{ignore {class airborne}}
		{select {class car} {threating} {in_range 40}}
		{select {class cannon} {threating} {in_range 50}}
	}
	{group
		{ignore {class airborne}}
		{select {class car} {threating} {in_range 50}}
		{select {class cannon} {threating} {in_range 60}}
	}
	{group
		{ignore {class airborne}}
		{select {class car} {threating} {in_range 60}}
		{select {class cannon} {threating} {in_range 70}}		
	}
	
	{group
		{ignore {class airborne}}
		{select {class cannon} {in_range 30}}
	}
	{group
		{ignore {class airborne}}
		{select {class car} {in_range 30}}
		{select {class cannon} {in_range 40}}
	}
	{group
		{ignore {class airborne}}
		{select {class car} {in_range 40}}
		{select {class cannon} {in_range 50}}
	}
	{group
		{ignore {class airborne}}
		{select {class car} {in_range 50}}
		{select {class cannon} {in_range 60}}
	}
	{group
		{ignore {class airborne}}
		{select {class car} {in_range 60}}
		{select {class cannon} {in_range 70}}		
	}
	
	{group
		{ignore {class airborne}}
		{select {class tank} {attacking} {in_range 80}}
	}
	{group
		{ignore {class airborne}}
		{select {class light_tank} {attacking} {in_range 80}}
	}
	{group
		{ignore {class airborne}}
		{select {class armoredcar} {attacking} {in_range 80}}
	}
	{group
		{ignore {class airborne}}
		{select {class tank} {threating} {in_range 80}}
	}
	{group
		{ignore {class airborne}}
		{select {class light_tank} {threating} {in_range 80}}
	}
	{group
		{ignore {class airborne}}
		{select {class armoredcar} {threating} {in_range 80}}
	}
	{group
		{ignore {class airborne}}
		{select {class tank} {in_range 80}}
	}
	{group
		{ignore {class airborne}}
		{select {class light_tank} {in_range 80}}
	}
	{group
		{ignore {class airborne}}
		{select {class armoredcar} {in_range 80}}
	}

;PRIORITY TARGETS LONG RANGE
	
	{group
		{ignore {class airborne}}
		{select {class car} {attacking} {in_range 70}}
		{select {class cannon} {attacking} {in_range 80}}
	}
	{group
		{ignore {class airborne}}
		{select {class car} {attacking} {in_range 80}}
		{select {class cannon} {attacking} {in_range 90}}
	}
	
	{group
		{ignore {class airborne}}
		{select {class car} {threating} {in_range 70}}
		{select {class cannon} {threating} {in_range 80}}
	}
	{group
		{ignore {class airborne}}
		{select {class car} {threating} {in_range 80}}
		{select {class cannon} {threating} {in_range 90}}
	}
	{group
		{ignore {class airborne}}
		{select {class car} {in_range 70}}
		{select {class cannon} {in_range 80}}
	}
	{group
		{ignore {class airborne}}
		{select {class car} {in_range 80}}
		{select {class cannon} {in_range 90}}
	}
	
	
	{group
		{ignore {class airborne}}
		{select {class tank}}
		{select {class light_tank}}
		{select {class armoredcar}}
		{select {class cannon}}
		{select {class car}}
	}
}