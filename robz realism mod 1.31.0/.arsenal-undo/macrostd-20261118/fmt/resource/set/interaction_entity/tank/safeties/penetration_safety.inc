{on pierce
	{if stuff "bullet"
		{if volume "body"
			{if not tagged "1_dam"
				{tags add "1_dam"}
				{call "1_dam_add"}
			else 
				{tags add "1_2_dam"}
				{call "1_dam_add"}
			}
		}
		{if volume "turret"
			{if not tagged "1_dam"
				{tags add "1_dam"}
				{call "1_dam_add"}
			else 
				{tags add "1_2_dam"}
				{call "1_dam_add"}
			}
		}
		{if volume "engine"
			{if not tagged "1_dam"
				{tags add "1_dam"}
				{call "1_dam_add"}
			else 
				{tags add "1_2_dam"}
				{call "1_dam_add"}
			}
		}
	else stuff "ptr"
		{if volume "body"
			{if not tagged "2_dam"
				{tags add "2_dam"}
				{call "2_dam_add"}
			else 
				{tags add "2_2_dam"}
				{call "2_dam_add"}
			}
		}
		{if volume "turret"
			{if not tagged "2_dam"
				{tags add "2_dam"}
				{call "2_dam_add"}
			else 
				{tags add "2_2_dam"}
				{call "2_dam_add"}
			}
		}
		{if volume "engine"
			{if not tagged "2_dam"
				{tags add "2_dam"}
				{call "2_dam_add"}
			else 
				{tags add "2_2_dam"}
				{call "2_dam_add"}
			}
		}
	else stuff "20mm"
		{if volume "body"
			{if not tagged "2_dam"
				{tags add "2_dam"}
				{call "2_dam_add"}
			else 
				{tags add "2_2_dam"}
				{call "2_dam_add"}
			}
		}
		{if volume "turret"
			{if not tagged "2_dam"
				{tags add "2_dam"}
				{call "2_dam_add"}
			else 
				{tags add "2_2_dam"}
				{call "2_dam_add"}
			}
		}
		{if volume "engine"
			{if not tagged "2_dam"
				{tags add "2_dam"}
				{call "2_dam_add"}
			else 
				{tags add "2_2_dam"}
				{call "2_dam_add"}
			}
		}
	else stuff "shell_minimum"
		{if volume "body"
			{if not tagged "3_dam"
				{tags add "3_dam"}
				{call "3_dam_add"}
			else 
				{tags add "3_2_dam"}
				{call "3_dam_add"}
			}
		}
		{if volume "turret"
			{if not tagged "3_dam"
				{tags add "3_dam"}
				{call "3_dam_add"}
			else 
				{tags add "3_2_dam"}
				{call "3_dam_add"}
			}
		}
		{if volume "engine"
			{if not tagged "3_dam"
				{tags add "3_dam"}
				{call "3_dam_add"}
			else 
				{tags add "3_2_dam"}
				{call "3_dam_add"}
			}
		}
	else stuff "shell_small_no_filler"
		{if volume "body"
			{if not tagged "3_dam"
				{tags add "3_dam"}
				{call "3_dam_add"}
			else 
				{tags add "3_2_dam"}
				{call "3_dam_add"}
			}
		}
		{if volume "turret"
			{if not tagged "3_dam"
				{tags add "3_dam"}
				{call "3_dam_add"}
			else 
				{tags add "3_2_dam"}
				{call "3_dam_add"}
			}
		}
		{if volume "engine"
			{if not tagged "3_dam"
				{tags add "3_dam"}
				{call "3_dam_add"}
			else 
				{tags add "3_2_dam"}
				{call "3_dam_add"}
			}
		}
	else stuff "shell_small_apcr"
		{if volume "body"
			{if not tagged "3_dam"
				{tags add "3_dam"}
				{call "3_dam_add"}
			else 
				{tags add "3_2_dam"}
				{call "3_dam_add"}
			}
		}
		{if volume "turret"
			{if not tagged "3_dam"
				{tags add "3_dam"}
				{call "3_dam_add"}
			else 
				{tags add "3_2_dam"}
				{call "3_dam_add"}
			}
		}
		{if volume "engine"
			{if not tagged "3_dam"
				{tags add "3_dam"}
				{call "3_dam_add"}
			else 
				{tags add "3_2_dam"}
				{call "3_dam_add"}
			}
		}
	else stuff "shell_small"
		{if volume "body"
			{if not tagged "4_dam"
				{tags add "4_dam"}
				{call "4_dam_add"}
			else 
				{tags add "4_2_dam"}
				{call "4_dam_add"}
			}
		}
		{if volume "turret"
			{if not tagged "4_dam"
				{tags add "4_dam"}
				{call "4_dam_add"}
			else 
				{tags add "4_2_dam"}
				{call "4_dam_add"}
			}
		}
		{if volume "engine"
			{if not tagged "4_dam"
				{tags add "4_dam"}
				{call "4_dam_add"}
			else 
				{tags add "4_2_dam"}
				{call "4_dam_add"}
			}
		}
	else stuff "shell_medium_no_filler"
		{if volume "body"
			{if not tagged "4_dam"
				{tags add "4_dam"}
				{call "4_dam_add"}
			else 
				{tags add "4_2_dam"}
				{call "4_dam_add"}
			}
		}
		{if volume "turret"
			{if not tagged "4_dam"
				{tags add "4_dam"}
				{call "4_dam_add"}
			else 
				{tags add "4_2_dam"}
				{call "4_dam_add"}
			}
		}
		{if volume "engine"
			{if not tagged "4_dam"
				{tags add "4_dam"}
				{call "4_dam_add"}
			else 
				{tags add "4_2_dam"}
				{call "4_dam_add"}
			}
		}
	else stuff "shell_medium_apcr"
		{if volume "body"
			{if not tagged "3_dam"
				{tags add "3_dam"}
				{call "3_dam_add"}
			else 
				{tags add "3_2_dam"}
				{call "3_dam_add"}
			}
		}
		{if volume "turret"
			{if not tagged "3_dam"
				{tags add "3_dam"}
				{call "3_dam_add"}
			else 
				{tags add "3_2_dam"}
				{call "3_dam_add"}
			}
		}
		{if volume "engine"
			{if not tagged "3_dam"
				{tags add "3_dam"}
				{call "3_dam_add"}
			else 
				{tags add "3_2_dam"}
				{call "3_dam_add"}
			}
		}
	else stuff "shell_medium"
		{if volume "body"
			{if not tagged "5_dam"
				{tags add "5_dam"}
				{call "5_dam_add"}
			else 
				{tags add "5_2_dam"}
				{call "5_dam_add"}
			}
		}
		{if volume "turret"
			{if not tagged "5_dam"
				{tags add "5_dam"}
				{call "5_dam_add"}
			else 
				{tags add "5_2_dam"}
				{call "5_dam_add"}
			}
		}
		{if volume "engine"
			{if not tagged "5_dam"
				{tags add "5_dam"}
				{call "5_dam_add"}
			else 
				{tags add "5_2_dam"}
				{call "5_dam_add"}
			}
		}
	else stuff "heat_small"
		{if volume "body"
			{if not tagged "4_dam"
				{tags add "4_dam"}
				{call "4_dam_add"}
			else 
				{tags add "4_2_dam"}
				{call "4_dam_add"}
			}
		}
		{if volume "turret"
			{if not tagged "4_dam"
				{tags add "4_dam"}
				{call "4_dam_add"}
			else 
				{tags add "4_2_dam"}
				{call "4_dam_add"}
			}
		}
		{if volume "engine"
			{if not tagged "4_dam"
				{tags add "4_dam"}
				{call "4_dam_add"}
			else 
				{tags add "4_2_dam"}
				{call "4_dam_add"}
			}
		}
	else stuff "shell_big_apcr"
		{if volume "body"
			{if not tagged "4_dam"
				{tags add "4_dam"}
				{call "4_dam_add"}
			else 
				{tags add "4_2_dam"}
				{call "4_dam_add"}
			}
		}
		{if volume "turret"
			{if not tagged "4_dam"
				{tags add "4_dam"}
				{call "4_dam_add"}
			else 
				{tags add "4_2_dam"}
				{call "4_dam_add"}
			}
		}
		{if volume "engine"
			{if not tagged "4_dam"
				{tags add "4_dam"}
				{call "4_dam_add"}
			else 
				{tags add "4_2_dam"}
				{call "4_dam_add"}
			}
		}
	else stuff "shell_big"
		{if volume "body"
			{if not tagged "7_dam"
				{tags add "7_dam"}
				{call "7_dam_add"}
			else 
				{tags add "7_2_dam"}
				{call "7_dam_add"}
			}
		}
		{if volume "turret"
			{if not tagged "7_dam"
				{tags add "7_dam"}
				{call "7_dam_add"}
			else 
				{tags add "7_2_dam"}
				{call "7_dam_add"}
			}
		}
		{if volume "engine"
			{if not tagged "7_dam"
				{tags add "7_dam"}
				{call "7_dam_add"}
			else 
				{tags add "7_2_dam"}
				{call "7_dam_add"}
			}
		}
	else stuff "heat_medium"
		{if volume "body"
			{if not tagged "6_dam"
				{tags add "6_dam"}
				{call "6_dam_add"}
			else 
				{tags add "6_2_dam"}
				{call "6_dam_add"}
			}
		}
		{if volume "turret"
			{if not tagged "6_dam"
				{tags add "6_dam"}
				{call "6_dam_add"}
			else 
				{tags add "6_2_dam"}
				{call "6_dam_add"}
			}
		}
		{if volume "engine"
			{if not tagged "6_dam"
				{tags add "6_dam"}
				{call "6_dam_add"}
			else 
				{tags add "6_2_dam"}
				{call "6_dam_add"}
			}
		}
	else stuff "shell_verybig"
		{if volume "body"
			{if not tagged "9_dam"
				{tags add "9_dam"}
				{call "9_dam_add"}
			else 
				{tags add "9_2_dam"}
				{call "9_dam_add"}
			}
		}
		{if volume "turret"
			{if not tagged "9_dam"
				{tags add "9_dam"}
				{call "9_dam_add"}
			else 
				{tags add "9_2_dam"}
				{call "9_dam_add"}
			}
		}
		{if volume "engine"
			{if not tagged "9_dam"
				{tags add "9_dam"}
				{call "9_dam_add"}
			else 
				{tags add "9_2_dam"}
				{call "9_dam_add"}
			}
		}
	else stuff "heat_big"
		{if volume "body"
			{if not tagged "8_dam"
				{tags add "8_dam"}
				{call "8_dam_add"}
			else 
				{tags add "8_2_dam"}
				{call "8_dam_add"}
			}
		}
		{if volume "turret"
			{if not tagged "8_dam"
				{tags add "8_dam"}
				{call "8_dam_add"}
			else 
				{tags add "8_2_dam"}
				{call "8_dam_add"}
			}
		}
		{if volume "engine"
			{if not tagged "8_dam"
				{tags add "8_dam"}
				{call "8_dam_add"}
			else 
				{tags add "8_2_dam"}
				{call "8_dam_add"}
			}
		}
	else stuff "shell_maximum"
		{if volume "body"
			{if not tagged "10_dam"
				{tags add "10_dam"}
				{call "10_dam_add"}
			else 
				{tags add "10_2_dam"}
				{call "10_dam_add"}
			}
		}
		{if volume "turret"
			{if not tagged "10_dam"
				{tags add "10_dam"}
				{call "10_dam_add"}
			else 
				{tags add "10_2_dam"}
				{call "10_dam_add"}
			}
		}
		{if volume "engine"
			{if not tagged "10_dam"
				{tags add "10_dam"}
				{call "10_dam_add"}
			else 
				{tags add "10_2_dam"}
				{call "10_dam_add"}
			}
		}
	else stuff "cumulative_charge"
		{if volume "body"
			{if not tagged "6_dam"
				{tags add "6_dam"}
				{call "6_dam_add"}
			else 
				{tags add "6_2_dam"}
				{call "6_dam_add"}
			}
		}
		{if volume "turret"
			{if not tagged "6_dam"
				{tags add "6_dam"}
				{call "6_dam_add"}
			else 
				{tags add "6_2_dam"}
				{call "6_dam_add"}
			}
		}
		{if volume "engine"
			{if not tagged "6_dam"
				{tags add "6_dam"}
				{call "6_dam_add"}
			else 
				{tags add "6_2_dam"}
				{call "6_dam_add"}
			}
		}
	else stuff "cumulative_tiny"
		{if volume "body"
			{if not tagged "2_dam"
				{tags add "2_dam"}
				{call "2_dam_add"}
			else 
				{tags add "2_2_dam"}
				{call "2_dam_add"}
			}
		}
		{if volume "turret"
			{if not tagged "2_dam"
				{tags add "2_dam"}
				{call "2_dam_add"}
			else 
				{tags add "2_2_dam"}
				{call "2_dam_add"}
			}
		}
		{if volume "engine"
			{if not tagged "2_dam"
				{tags add "2_dam"}
				{call "2_dam_add"}
			else 
				{tags add "2_2_dam"}
				{call "2_dam_add"}
			}
		}
	else stuff "cumulative_small"
		{if volume "body"
			{if not tagged "4_dam"
				{tags add "4_dam"}
				{call "4_dam_add"}
			else 
				{tags add "4_2_dam"}
				{call "4_dam_add"}
			}
		}
		{if volume "turret"
			{if not tagged "4_dam"
				{tags add "4_dam"}
				{call "4_dam_add"}
			else 
				{tags add "4_2_dam"}
				{call "4_dam_add"}
			}
		}
		{if volume "engine"
			{if not tagged "4_dam"
				{tags add "4_dam"}
				{call "4_dam_add"}
			else 
				{tags add "4_2_dam"}
				{call "4_dam_add"}
			}
		}
	else stuff "cumulative"
		{if volume "body"
			{if not tagged "6_dam"
				{tags add "6_dam"}
				{call "6_dam_add"}
			else 
				{tags add "6_2_dam"}
				{call "6_dam_add"}
			}
		}
		{if volume "turret"
			{if not tagged "6_dam"
				{tags add "6_dam"}
				{call "6_dam_add"}
			else 
				{tags add "6_2_dam"}
				{call "6_dam_add"}
			}
		}
		{if volume "engine"
			{if not tagged "6_dam"
				{tags add "6_dam"}
				{call "6_dam_add"}
			else 
				{tags add "6_2_dam"}
				{call "6_dam_add"}
			}
		}
	else stuff "cumulative_big"
		{if volume "body"
			{if not tagged "8_dam"
				{tags add "8_dam"}
				{call "8_dam_add"}
			else 
				{tags add "8_2_dam"}
				{call "8_dam_add"}
			}
		}
		{if volume "turret"
			{if not tagged "8_dam"
				{tags add "8_dam"}
				{call "8_dam_add"}
			else 
				{tags add "8_2_dam"}
				{call "8_dam_add"}
			}
		}
		{if volume "engine"
			{if not tagged "8_dam"
				{tags add "8_dam"}
				{call "8_dam_add"}
			else 
				{tags add "8_2_dam"}
				{call "8_dam_add"}
			}
		}
	else
		{damage_report "penetration" "<c(FF1F00)>ERROR 2: Report<c(FFFFFF)>"}
	}
	{tags add "pierced_cumulative"}
}