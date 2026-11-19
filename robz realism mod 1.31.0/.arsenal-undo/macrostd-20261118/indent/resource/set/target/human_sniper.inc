{selector
	{unit "human" "sniper"}

;IMMEDIATE THREATS TO UNIT OR ALLIES

	{group
		{ignore {class airborne}}
		{select {weapon "kamikaze"} {in_range 10}}
	}
	{group
		{ignore {class airborne}}
		{select {weapon "kamikaze"} {in_range 20}}
	}

	{group
		{ignore {class airborne}}
		{select {in_range 10} {attacking}}
	}
	{group
		{ignore {class airborne}}
		{select {in_range 10} {threating}}
	}
	{group
		{ignore {class airborne}}
		{select {in_range 10}}
	}

	{group
		{ignore {class airborne}}
		{select {in_range 20} {attacking}}
	}
	{group
		{ignore {class airborne}}
		{select {in_range 20} {threating}}
	}
	{group
		{ignore {class airborne}}
		{select {in_range 20}}
	}

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
		{select {weapon "grenade"} {attacking} {in_range 35}}
	}
	{group
		{ignore {class airborne}}
		{select {weapon "grenade"} {threating} {in_range 35}}
	}
	{group
		{ignore {class airborne}}
		{select {weapon "grenade"} {in_range 35}}
	}

	{group
		{ignore {class airborne}}
		{select {weapon "flame_thrower"} {attacking} {in_range 60}}
	}
	{group
		{ignore {class airborne}}
		{select {weapon "flame_thrower"} {threating} {in_range 60}}
	}
	{group
		{ignore {class airborne}}
		{select {weapon "flame_thrower"} {in_range 60}}
	}

	{group
		{ignore {class airborne}}
		{select {in_range 35} {attacking}}
	}
	{group
		{ignore {class airborne}}
		{select {in_range 35} {threating}}
	}
	{group
		{ignore {class airborne}}
		{select {in_range 35}}
	}

;PRIORITY TARGETS MEDIUM RANGE

	{group
		{ignore {class airborne}}
		{select {class human} {weapon "field_glass"} {in_range 60}}
	}
	{group
		{ignore {class airborne}}
		{select {class human} {weapon "sniper"} {attacking} {in_range 60}}
	}
	{group
		{ignore {class airborne}}
		{select {class human} {weapon "sniper"} {threating} {in_range 60}}
	}
	{group
		{ignore {class airborne}}
		{select {class human} {weapon "sniper"} {in_range 60}}
	}
	{group
		{ignore {class airborne}}
		{select {class human} {weapon "mgun"} {attacking} {in_range 60}}
	}
	{group
		{ignore {class airborne}}
		{select {class human} {weapon "mgun"} {threating} {in_range 60}}
	}
	{group
		{ignore {class airborne}}
		{select {class human} {weapon "mgun"} {in_range 60}}
	}
	{group
		{ignore {class airborne}}
		{select {class human} {weapon "at_rifle"} {attacking} {in_range 60}}
	}
	{group
		{ignore {class airborne}}
		{select {class human} {weapon "at_rifle"} {threating} {in_range 60}}
	}
	{group
		{ignore {class airborne}}
		{select {class human} {weapon "at_rifle"} {in_range 60}}
	}
	{group
		{ignore {class airborne}}
		{select {class human} {weapon "rocketlauncher"} {attacking} {in_range 60}}
	}
	{group
		{ignore {class airborne}}
		{select {class human} {weapon "rocketlauncher"} {threating} {in_range 60}}
	}
	{group
		{ignore {class airborne}}
		{select {class human} {weapon "rocketlauncher"} {in_range 60}}
	}

;PRIORITY TARGETS LONG RANGE

	{group
		{ignore {class airborne}}
		{select {class human} {weapon "field_glass"} {in_range 100}}
	}
	{group
		{ignore {class airborne}}
		{select {class human} {weapon "sniper"} {attacking} {in_range 100}}
	}
	{group
		{ignore {class airborne}}
		{select {class human} {weapon "sniper"} {threating} {in_range 100}}
	}
	{group
		{ignore {class airborne}}
		{select {class human} {weapon "sniper"} {in_range 100}}
	}
	{group
		{ignore {class airborne}}
		{select {class human} {weapon "mgun"} {attacking} {in_range 100}}
	}
	{group
		{ignore {class airborne}}
		{select {class human} {weapon "mgun"} {threating} {in_range 100}}
	}
	{group
		{ignore {class airborne}}
		{select {class human} {weapon "mgun"} {in_range 100}}
	}
	{group
		{ignore {class airborne}}
		{select {class human} {weapon "at_rifle"} {attacking} {in_range 80}}
	}
	{group
		{ignore {class airborne}}
		{select {class human} {weapon "at_rifle"} {threating} {in_range 80}}
	}
	{group
		{ignore {class airborne}}
		{select {class human} {weapon "at_rifle"} {in_range 80}}
	}
	{group
		{ignore {class airborne}}
		{select {class human} {weapon "rocketlauncher"} {attacking} {in_range 80}}
	}
	{group
		{ignore {class airborne}}
		{select {class human} {weapon "rocketlauncher"} {threating} {in_range 80}}
	}
	{group
		{ignore {class airborne}}
		{select {class human} {weapon "rocketlauncher"} {in_range 80}}
	}

	{group
		{ignore {class airborne}}
		{select {class human} {weapon "mgun"} {attacking} {in_range 120}}
	}
	{group
		{ignore {class airborne}}
		{select {class human} {weapon "mgun"} {threating} {in_range 120}}
	}
	{group
		{ignore {class airborne}}
		{select {class human} {weapon "mgun"} {in_range 120}}
	}

	{group
		{ignore {class airborne}}
		{select {class human} {weapon "at_rifle"} {in_range 100}}
	}
	{group
		{ignore {class airborne}}
		{select {class human} {weapon "rocketlauncher"} {attacking} {in_range 100}}
	}
	{group
		{ignore {class airborne}}
		{select {class human} {weapon "rocketlauncher"} {threating} {in_range 100}}
	}
	{group
		{ignore {class airborne}}
		{select {class human} {weapon "rocketlauncher"} {in_range 100}}
	}
	{group
		{ignore {class airborne}}
		{select {class human} {weapon "sniper"} {attacking} {in_range 150}}
	}
	{group
		{ignore {class airborne}}
		{select {class human} {weapon "sniper"} {threating} {in_range 150}}
	}
	{group
		{ignore {class airborne}}
		{select {class human} {weapon "sniper"} {in_range 150}}
	}
	{group
		{ignore {class airborne}}
		{select {class human} {weapon "mgun"} {attacking} {in_range 150}}
	}
	{group
		{ignore {class airborne}}
		{select {class human} {weapon "mgun"} {threating} {in_range 150}}
	}
	{group
		{ignore {class airborne}}
		{select {class human} {weapon "mgun"} {in_range 150}}
	}

	{group
		{ignore {class airborne}}
		{select {class human}}
		{select {class cannon}}
		{select {class car}}
	}


}
