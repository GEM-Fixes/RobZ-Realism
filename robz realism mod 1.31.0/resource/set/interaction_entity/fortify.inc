{"trench"
	(include "fortify/damage_counter_fortify.inc")
	(include "fortify/combat_capable_check_fortify.inc")
	{on blast_hit
		{if tagged "trench_weak"
			{if min_energy 5  ;75
				{call "break"}
				else min_energy 4 ;50mm
				{if not tagged "blasted"
					{tags add "blasted"}
					{if not tagged "6_dam"
						{tags add "6_dam"}
						{call "6_dam_add"}
						else
						{tags add "6_2_dam"}
						{call "6_dam_add"}
					}
				}
			}
			else
			{if not tagged "blasted"
				{tags add "blasted"}
				{if min_energy 24 ;203 direct hit
					{call "break"}
					else min_energy 14 ;155 direct hit
					{if not tagged "8_dam"
						{tags add "8_dam"}
						{call "8_dam_add"}
						else
						{tags add "8_2_dam"}
						{call "8_dam_add"}
					}
					else min_energy 8.5 ;122
					{if not tagged "6_dam"
						{tags add "6_dam"}
						{call "6_dam_add"}
						else
						{tags add "6_2_dam"}
						{call "6_dam_add"}
					}
					else min_energy 7.5 ;85
					{if not tagged "4_dam"
						{tags add "4_dam"}
						{call "4_dam_add"}
						else
						{tags add "4_2_dam"}
						{call "4_dam_add"}
					}
					else min_energy 5 ;75
					{if not tagged "3_dam"
						{tags add "3_dam"}
						{call "3_dam_add"}
						else
						{tags add "3_2_dam"}
						{call "3_dam_add"}
					}
					else min_energy 4 ;50mm
					{if not tagged "1_dam"
						{tags add "1_dam"}
						{call "1_dam_add"}
						else
						{tags add "1_2_dam"}
						{call "1_dam_add"}
					}
				}
			}
		}
		{delay 0.3
			{tags remove "blasted"}
		}
	}

	;
	{on "break"
		{if not "broken"
			{set "broken" 1}
			{tags add "crushed"}
			{call "disable_volumes"}
			{if not "sliced"
				{set "sliced" 1}
				{delay_ex 0
					{set_skeleton "_x"}
					{call "update_fx"}
					{set "first_stage" 1}
					{set "last_stage" 1}
					{call "effects"}
					{ani_play "crush"}
					{delay 0.1
						{update_visibility_patch}
					}
					{call "cut_pieces"}
				}
			}
		}
	}
}

{"trench_weak"
	{on spawn
		{tags add "trench_weak"}
	}
}
