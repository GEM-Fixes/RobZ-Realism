{on "cumulative_damage_knockout"
	{damage_report "penetration" "<c(FF1F00)>Knocked Out From Total Damage<c(FFFFFF)>"}
	{reset_manual_control}
	{able select 0}
	{able repaired 0}
	{call "notify_break"}
	{tags add "destroyed"}
	{delay 3 1
		{call "engine stop view"}
		{crew_emit}
		{delay 2
			{crew_emit}
		}
		{delay 4
			{crew_emit}
		}
		{delay 6
			{crew_emit}
		}
	}
}


{on "combat_capable_check"
	{if tagged "10_dam"
		{damage_report "penetration" "<c(FF1F00)>Near Ineffective From Total Damage - Early Bailing<c(FFFFFF)>"}
		{crew_emit}
		{delay 2
			{crew_emit}
		}
		{delay 4
			{crew_emit}
		}
		{delay 6
			{crew_emit}
		}
	else tagged "9_dam"
		{damage_report "penetration" "<c(FF1F00)>90% Degraded From Total Damage<c(FFFFFF)>"}
	else tagged "8_dam"
		{damage_report "penetration" "<c(FF1F00)>80% Degraded From Total Damage<c(FFFFFF)>"}
	else tagged "7_dam"
		{damage_report "penetration" "<c(FF1F00)>70% Degraded From Total Damage<c(FFFFFF)>"}
	else tagged "6_dam"
		{damage_report "penetration" "<c(FF1F00)>60% Degraded From Total Damage<c(FFFFFF)>"}
	else tagged "5_dam"
		{damage_report "penetration" "<c(FF1F00)>50% Degraded From Total Damage<c(FFFFFF)>"}
	else tagged "4_dam"
		{damage_report "penetration" "<c(FF1F00)>40% Degraded From Total Damage<c(FFFFFF)>"}
	else tagged "3_dam"
		{damage_report "penetration" "<c(FF1F00)>30% Degraded From Total Damage<c(FFFFFF)>"}
	else tagged "2_dam"
		{damage_report "penetration" "<c(FF1F00)>20% Degraded From Total Damage<c(FFFFFF)>"}
	else tagged "1_dam"
		{damage_report "penetration" "<c(FF1F00)>10% Degraded From Total Damage<c(FFFFFF)>"}
	else tagged "0_dam"
		{damage_report "penetration" "<c(FF1F00)>No Sustained Damage<c(FFFFFF)>"}
	else tagged "11_dam"
		{call "cumulative_damage_knockout"}
	else tagged "12_dam"
		{call "cumulative_damage_knockout"}
	else tagged "13_dam"
		{call "cumulative_damage_knockout"}
	else tagged "14_dam"
		{call "cumulative_damage_knockout"}
	else tagged "15_dam"
		{call "cumulative_damage_knockout"}
	else tagged "16_dam"
		{call "cumulative_damage_knockout"}
	else tagged "17_dam"
		{call "cumulative_damage_knockout"}
	else tagged "18_dam"
		{call "cumulative_damage_knockout"}
	else tagged "19_dam"
		{call "cumulative_damage_knockout"}
	else tagged "20_dam"
		{call "cumulative_damage_knockout"}
	else tagged "21_dam"
		{call "cumulative_damage_knockout"}
	else tagged "22_dam"
		{call "cumulative_damage_knockout"}
	else tagged "23_dam"
		{call "cumulative_damage_knockout"}
	else tagged "24_dam"
		{call "cumulative_damage_knockout"}
	else tagged "25_dam"
		{call "cumulative_damage_knockout"}
	else tagged "26_dam"
		{call "cumulative_damage_knockout"}
	else tagged "27_dam"
		{call "cumulative_damage_knockout"}
	else tagged "28_dam"
		{call "cumulative_damage_knockout"}
	else tagged "29_dam"
		{call "cumulative_damage_knockout"}
	else tagged "30_dam"
		{call "cumulative_damage_knockout"}
	else	
		{damage_report "penetration" "<c(FF1F00)>ERROR 1: Report<c(FFFFFF)>"}
	}
	{delay 0.25
		{tags remove "pierced_cumulative"}
	}
}