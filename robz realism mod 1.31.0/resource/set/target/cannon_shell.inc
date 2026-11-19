{selector
	{type "cannon_shell"}

	{group
		{ignore {class airborne}}
		{select {class human} {weapon "kamikaze"} {in_range 50}}
	}
	{group
		{ignore {class airborne}}
		{select {class human} {weapon "ap"} {in_range 30}}
		{select {class human} {weapon "dynamite"} {in_range 30}}
	}

	{group
		{ignore {class airborne}}
		{select {weapon "flame_thrower_tank"} {in_range 80}}
	}
	{group
		{ignore {class airborne}}
		{select {class tank} {in_range 70}}
	}
	{group
		{ignore {class airborne}}
		{select {class cannon} {in_range 70}}
	}
	{group
		{ignore {class airborne}}
		{select {class light_tank} {in_range 70}}
	}
	{group
		{ignore {class airborne}}
		{select {class armoredcar} {in_range 70}}
	}

	{group
		{ignore {class airborne}}
		{select {class tank}}
		{select {class cannon}}
		{sort time_to_aim}
	}
	{group
		{ignore {class airborne}}
		{select {class light_tank}}
		{select {class armoredcar}}
		{sort time_to_aim}
	}

	{group
		{ignore {class airborne}}
		{select {class car}}
		{sort time_to_aim}
	}

	{group
		{ignore {class airborne}}
		{select {class human} {weapon "at_rifle"} {in_range 130}}
	}

	{group
		{ignore {class airborne}}
		{select {class human} {weapon "rocketlauncher"} {in_range 95}}
	}

	{group
		{ignore {class airborne}}
		{select {class human} {weapon "mgun"}}
		{sort time_to_aim}
	}

	{group
		{ignore {class airborne}}
		{select {class human}}
		{sort time_to_aim}
	}

}
