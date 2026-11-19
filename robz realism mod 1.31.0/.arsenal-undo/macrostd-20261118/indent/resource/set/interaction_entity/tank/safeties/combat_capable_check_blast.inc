	{if tagged "10_dam_b"
		{if tagged "blasted_body_front"
			{damage_report "body" "<c(FF1F00)>Body Front Severe Total Damage - Early Bailing<c(FFFFFF)>"}
			{tags remove "10_dam_b"}
			{tags add "10_dam_b_body_front"}
		else tagged "blasted_body_back"
			{damage_report "body" "<c(FF1F00)>Body Back Severe Total Damage - Early Bailing<c(FFFFFF)>"}
			{tags remove "10_dam_b"}
			{tags add "10_dam_b_body_back"}
		else tagged "blasted_body_left"
			{damage_report "body" "<c(FF1F00)>Body Left Severe Total Damage - Early Bailing<c(FFFFFF)>"}
			{tags remove "10_dam_b"}
			{tags add "10_dam_b_body_left"}
		else tagged "blasted_body_right"
			{damage_report "body" "<c(FF1F00)>Body Right Severe Total Damage - Early Bailing<c(FFFFFF)>"}
			{tags remove "10_dam_b"}
			{tags add "10_dam_b_body_right"}
		else tagged "blasted_body_top"
			{damage_report "body" "<c(FF1F00)>Body Top Severe Total Damage - Early Bailing<c(FFFFFF)>"}
			{tags remove "10_dam_b"}
			{tags add "10_dam_b_body_top"}
		else tagged "blasted_turret_front"
			{damage_report "body" "<c(FF1F00)>Turret Front Severe Total Damage - Early Bailing<c(FFFFFF)>"}
			{tags remove "10_dam_b"}
			{tags add "10_dam_b_turret_front"}
		else tagged "blasted_turret_back"
			{damage_report "body" "<c(FF1F00)>Turret Back Severe Total Damage - Early Bailing<c(FFFFFF)>"}
			{tags remove "10_dam_b"}
			{tags add "10_dam_b_turret_back"}
		else tagged "blasted_turret_left"
			{damage_report "body" "<c(FF1F00)>Turret Left Severe Total Damage - Early Bailing<c(FFFFFF)>"}
			{tags remove "10_dam_b"}
			{tags add "10_dam_b_turret_left"}
		else tagged "blasted_turret_right"
			{damage_report "body" "<c(FF1F00)>Turret Right Severe Total Damage - Early Bailing<c(FFFFFF)>"}
			{tags remove "10_dam_b"}
			{tags add "10_dam_b_turret_right"}
		else tagged "blasted_turret_top"
			{damage_report "body" "<c(FF1F00)>Turret Top Severe Total Damage - Early Bailing<c(FFFFFF)>"}
			{tags remove "10_dam_b"}
			{tags add "10_dam_b_turret_top"}
		else tagged "blasted_engine_front"
			{damage_report "body" "<c(FF1F00)>Engine Front Severe Total Damage - Early Bailing<c(FFFFFF)>"}
			{tags remove "10_dam_b"}
			{tags add "10_dam_b_engine_front"}
		else tagged "blasted_engine_back"
			{damage_report "body" "<c(FF1F00)>Engine Back Severe Total Damage - Early Bailing<c(FFFFFF)>"}
			{tags remove "10_dam_b"}
			{tags add "10_dam_b_engine_back"}
		else tagged "blasted_engine_left"
			{damage_report "body" "<c(FF1F00)>Engine Left Severe Total Damage - Early Bailing<c(FFFFFF)>"}
			{tags remove "10_dam_b"}
			{tags add "10_dam_b_engine_left"}
		else tagged "blasted_engine_right"
			{damage_report "body" "<c(FF1F00)>Engine Right Severe Total Damage - Early Bailing<c(FFFFFF)>"}
			{tags remove "10_dam_b"}
			{tags add "10_dam_b_engine_right"}
		else tagged "blasted_engine_top"
			{damage_report "body" "<c(FF1F00)>Engine Top Severe Total Damage - Early Bailing<c(FFFFFF)>"}
			{tags remove "10_dam_b"}
			{tags add "10_dam_b_engine_top"}
		}
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
	else tagged "9_dam_b"
		{if tagged "blasted_body_front"
			{damage_report "body" "<c(FF1F00)>Body Front 90% Degraded From Total Damage<c(FFFFFF)>"}
			{tags remove "9_dam_b"}
			{tags add "9_dam_b_body_front"}
		else tagged "blasted_body_back"
			{damage_report "body" "<c(FF1F00)>Body Back 90% Degraded From Total Damage<c(FFFFFF)>"}
			{tags remove "9_dam_b"}
			{tags add "9_dam_b_body_back"}
		else tagged "blasted_body_left"
			{damage_report "body" "<c(FF1F00)>Body Left 90% Degraded From Total Damage<c(FFFFFF)>"}
			{tags remove "9_dam_b"}
			{tags add "9_dam_b_body_left"}
		else tagged "blasted_body_right"
			{damage_report "body" "<c(FF1F00)>Body Right 90% Degraded From Total Damage<c(FFFFFF)>"}
			{tags remove "9_dam_b"}
			{tags add "9_dam_b_body_right"}
		else tagged "blasted_body_top"
			{damage_report "body" "<c(FF1F00)>Body Top 90% Degraded From Total Damage<c(FFFFFF)>"}
			{tags remove "9_dam_b"}
			{tags add "9_dam_b_body_top"}
		else tagged "blasted_turret_front"
			{damage_report "body" "<c(FF1F00)>Turret Front 90% Degraded From Total Damage<c(FFFFFF)>"}
			{tags remove "9_dam_b"}
			{tags add "9_dam_b_turret_front"}
		else tagged "blasted_turret_back"
			{damage_report "body" "<c(FF1F00)>Turret Back 90% Degraded From Total Damage<c(FFFFFF)>"}
			{tags remove "9_dam_b"}
			{tags add "9_dam_b_turret_back"}
		else tagged "blasted_turret_left"
			{damage_report "body" "<c(FF1F00)>Turret Left 90% Degraded From Total Damage<c(FFFFFF)>"}
			{tags remove "9_dam_b"}
			{tags add "9_dam_b_turret_left"}
		else tagged "blasted_turret_right"
			{damage_report "body" "<c(FF1F00)>Turret Right 90% Degraded From Total Damage<c(FFFFFF)>"}
			{tags remove "9_dam_b"}
			{tags add "9_dam_b_turret_right"}
		else tagged "blasted_turret_top"
			{damage_report "body" "<c(FF1F00)>Turret Top 90% Degraded From Total Damage<c(FFFFFF)>"}
			{tags remove "9_dam_b"}
			{tags add "9_dam_b_turret_top"}
		else tagged "blasted_engine_front"
			{damage_report "body" "<c(FF1F00)>Engine Front 90% Degraded From Total Damage<c(FFFFFF)>"}
			{tags remove "9_dam_b"}
			{tags add "9_dam_b_engine_front"}
		else tagged "blasted_engine_back"
			{damage_report "body" "<c(FF1F00)>Engine Back 90% Degraded From Total Damage<c(FFFFFF)>"}
			{tags remove "9_dam_b"}
			{tags add "9_dam_b_engine_back"}
		else tagged "blasted_engine_left"
			{damage_report "body" "<c(FF1F00)>Engine Left 90% Degraded From Total Damage<c(FFFFFF)>"}
			{tags remove "9_dam_b"}
			{tags add "9_dam_b_engine_left"}
		else tagged "blasted_engine_right"
			{damage_report "body" "<c(FF1F00)>Engine Right 90% Degraded From Total Damage<c(FFFFFF)>"}
			{tags remove "9_dam_b"}
			{tags add "9_dam_b_engine_right"}
		else tagged "blasted_engine_top"
			{damage_report "body" "<c(FF1F00)>Engine Top 90% Degraded From Total Damage<c(FFFFFF)>"}
			{tags remove "9_dam_b"}
			{tags add "9_dam_b_engine_top"}
		}
	else tagged "8_dam_b"
		{if tagged "blasted_body_front"
			{damage_report "body" "<c(FF1F00)>Body Front 80% Degraded From Total Damage<c(FFFFFF)>"}
			{tags remove "8_dam_b"}
			{tags add "8_dam_b_body_front"}
		else tagged "blasted_body_back"
			{damage_report "body" "<c(FF1F00)>Body Back 80% Degraded From Total Damage<c(FFFFFF)>"}
			{tags remove "8_dam_b"}
			{tags add "8_dam_b_body_back"}
		else tagged "blasted_body_left"
			{damage_report "body" "<c(FF1F00)>Body Left 80% Degraded From Total Damage<c(FFFFFF)>"}
			{tags remove "8_dam_b"}
			{tags add "8_dam_b_body_left"}
		else tagged "blasted_body_right"
			{damage_report "body" "<c(FF1F00)>Body Right 80% Degraded From Total Damage<c(FFFFFF)>"}
			{tags remove "8_dam_b"}
			{tags add "8_dam_b_body_right"}
		else tagged "blasted_body_top"
			{damage_report "body" "<c(FF1F00)>Body Top 80% Degraded From Total Damage<c(FFFFFF)>"}
			{tags remove "8_dam_b"}
			{tags add "8_dam_b_body_top"}
		else tagged "blasted_turret_front"
			{damage_report "body" "<c(FF1F00)>Turret Front 80% Degraded From Total Damage<c(FFFFFF)>"}
			{tags remove "8_dam_b"}
			{tags add "8_dam_b_turret_front"}
		else tagged "blasted_turret_back"
			{damage_report "body" "<c(FF1F00)>Turret Back 80% Degraded From Total Damage<c(FFFFFF)>"}
			{tags remove "8_dam_b"}
			{tags add "8_dam_b_turret_back"}
		else tagged "blasted_turret_left"
			{damage_report "body" "<c(FF1F00)>Turret Left 80% Degraded From Total Damage<c(FFFFFF)>"}
			{tags remove "8_dam_b"}
			{tags add "8_dam_b_turret_left"}
		else tagged "blasted_turret_right"
			{damage_report "body" "<c(FF1F00)>Turret Right 80% Degraded From Total Damage<c(FFFFFF)>"}
			{tags remove "8_dam_b"}
			{tags add "8_dam_b_turret_right"}
		else tagged "blasted_turret_top"
			{damage_report "body" "<c(FF1F00)>Turret Top 80% Degraded From Total Damage<c(FFFFFF)>"}
			{tags remove "8_dam_b"}
			{tags add "8_dam_b_turret_top"}
		else tagged "blasted_engine_front"
			{damage_report "body" "<c(FF1F00)>Engine Front 80% Degraded From Total Damage<c(FFFFFF)>"}
			{tags remove "8_dam_b"}
			{tags add "8_dam_b_engine_front"}
		else tagged "blasted_engine_back"
			{damage_report "body" "<c(FF1F00)>Engine Back 80% Degraded From Total Damage<c(FFFFFF)>"}
			{tags remove "8_dam_b"}
			{tags add "8_dam_b_engine_back"}
		else tagged "blasted_engine_left"
			{damage_report "body" "<c(FF1F00)>Engine Left 80% Degraded From Total Damage<c(FFFFFF)>"}
			{tags remove "8_dam_b"}
			{tags add "8_dam_b_engine_left"}
		else tagged "blasted_engine_right"
			{damage_report "body" "<c(FF1F00)>Engine Right 80% Degraded From Total Damage<c(FFFFFF)>"}
			{tags remove "8_dam_b"}
			{tags add "8_dam_b_engine_right"}
		else tagged "blasted_engine_top"
			{damage_report "body" "<c(FF1F00)>Engine Top 80% Degraded From Total Damage<c(FFFFFF)>"}
			{tags remove "8_dam_b"}
			{tags add "8_dam_b_engine_top"}
		}
	else tagged "7_dam_b"
		{if tagged "blasted_body_front"
			{damage_report "body" "<c(FF1F00)>Body Front 70% Degraded From Total Damage<c(FFFFFF)>"}
			{tags remove "7_dam_b"}
			{tags add "7_dam_b_body_front"}
		else tagged "blasted_body_back"
			{damage_report "body" "<c(FF1F00)>Body Back 70% Degraded From Total Damage<c(FFFFFF)>"}
			{tags remove "7_dam_b"}
			{tags add "7_dam_b_body_back"}
		else tagged "blasted_body_left"
			{damage_report "body" "<c(FF1F00)>Body Left 70% Degraded From Total Damage<c(FFFFFF)>"}
			{tags remove "7_dam_b"}
			{tags add "7_dam_b_body_left"}
		else tagged "blasted_body_right"
			{damage_report "body" "<c(FF1F00)>Body Right 70% Degraded From Total Damage<c(FFFFFF)>"}
			{tags remove "7_dam_b"}
			{tags add "7_dam_b_body_right"}
		else tagged "blasted_body_top"
			{damage_report "body" "<c(FF1F00)>Body Top 70% Degraded From Total Damage<c(FFFFFF)>"}
			{tags remove "7_dam_b"}
			{tags add "7_dam_b_body_top"}
		else tagged "blasted_turret_front"
			{damage_report "body" "<c(FF1F00)>Turret Front 70% Degraded From Total Damage<c(FFFFFF)>"}
			{tags remove "7_dam_b"}
			{tags add "7_dam_b_turret_front"}
		else tagged "blasted_turret_back"
			{damage_report "body" "<c(FF1F00)>Turret Back 70% Degraded From Total Damage<c(FFFFFF)>"}
			{tags remove "7_dam_b"}
			{tags add "7_dam_b_turret_back"}
		else tagged "blasted_turret_left"
			{damage_report "body" "<c(FF1F00)>Turret Left 70% Degraded From Total Damage<c(FFFFFF)>"}
			{tags remove "7_dam_b"}
			{tags add "7_dam_b_turret_left"}
		else tagged "blasted_turret_right"
			{damage_report "body" "<c(FF1F00)>Turret Right 70% Degraded From Total Damage<c(FFFFFF)>"}
			{tags remove "7_dam_b"}
			{tags add "7_dam_b_turret_right"}
		else tagged "blasted_turret_top"
			{damage_report "body" "<c(FF1F00)>Turret Top 70% Degraded From Total Damage<c(FFFFFF)>"}
			{tags remove "7_dam_b"}
			{tags add "7_dam_b_turret_top"}
		else tagged "blasted_engine_front"
			{damage_report "body" "<c(FF1F00)>Engine Front 70% Degraded From Total Damage<c(FFFFFF)>"}
			{tags remove "7_dam_b"}
			{tags add "7_dam_b_engine_front"}
		else tagged "blasted_engine_back"
			{damage_report "body" "<c(FF1F00)>Engine Back 70% Degraded From Total Damage<c(FFFFFF)>"}
			{tags remove "7_dam_b"}
			{tags add "7_dam_b_engine_back"}
		else tagged "blasted_engine_left"
			{damage_report "body" "<c(FF1F00)>Engine Left 70% Degraded From Total Damage<c(FFFFFF)>"}
			{tags remove "7_dam_b"}
			{tags add "7_dam_b_engine_left"}
		else tagged "blasted_engine_right"
			{damage_report "body" "<c(FF1F00)>Engine Right 70% Degraded From Total Damage<c(FFFFFF)>"}
			{tags remove "7_dam_b"}
			{tags add "7_dam_b_engine_right"}
		else tagged "blasted_engine_top"
			{damage_report "body" "<c(FF1F00)>Engine Top 70% Degraded From Total Damage<c(FFFFFF)>"}
			{tags remove "7_dam_b"}
			{tags add "7_dam_b_engine_top"}
		}
	else tagged "6_dam_b"
		{if tagged "blasted_body_front"
			{damage_report "body" "<c(FF1F00)>Body Front 60% Degraded From Total Damage<c(FFFFFF)>"}
			{tags remove "6_dam_b"}
			{tags add "6_dam_b_body_front"}
		else tagged "blasted_body_back"
			{damage_report "body" "<c(FF1F00)>Body Back 60% Degraded From Total Damage<c(FFFFFF)>"}
			{tags remove "6_dam_b"}
			{tags add "6_dam_b_body_back"}
		else tagged "blasted_body_left"
			{damage_report "body" "<c(FF1F00)>Body Left 60% Degraded From Total Damage<c(FFFFFF)>"}
			{tags remove "6_dam_b"}
			{tags add "6_dam_b_body_left"}
		else tagged "blasted_body_right"
			{damage_report "body" "<c(FF1F00)>Body Right 60% Degraded From Total Damage<c(FFFFFF)>"}
			{tags remove "6_dam_b"}
			{tags add "6_dam_b_body_right"}
		else tagged "blasted_body_top"
			{damage_report "body" "<c(FF1F00)>Body Top 60% Degraded From Total Damage<c(FFFFFF)>"}
			{tags remove "6_dam_b"}
			{tags add "6_dam_b_body_top"}
		else tagged "blasted_turret_front"
			{damage_report "body" "<c(FF1F00)>Turret Front 60% Degraded From Total Damage<c(FFFFFF)>"}
			{tags remove "6_dam_b"}
			{tags add "6_dam_b_turret_front"}
		else tagged "blasted_turret_back"
			{damage_report "body" "<c(FF1F00)>Turret Back 60% Degraded From Total Damage<c(FFFFFF)>"}
			{tags remove "6_dam_b"}
			{tags add "6_dam_b_turret_back"}
		else tagged "blasted_turret_left"
			{damage_report "body" "<c(FF1F00)>Turret Left 60% Degraded From Total Damage<c(FFFFFF)>"}
			{tags remove "6_dam_b"}
			{tags add "6_dam_b_turret_left"}
		else tagged "blasted_turret_right"
			{damage_report "body" "<c(FF1F00)>Turret Right 60% Degraded From Total Damage<c(FFFFFF)>"}
			{tags remove "6_dam_b"}
			{tags add "6_dam_b_turret_right"}
		else tagged "blasted_turret_top"
			{damage_report "body" "<c(FF1F00)>Turret Top 60% Degraded From Total Damage<c(FFFFFF)>"}
			{tags remove "6_dam_b"}
			{tags add "6_dam_b_turret_top"}
		else tagged "blasted_engine_front"
			{damage_report "body" "<c(FF1F00)>Engine Front 60% Degraded From Total Damage<c(FFFFFF)>"}
			{tags remove "6_dam_b"}
			{tags add "6_dam_b_engine_front"}
		else tagged "blasted_engine_back"
			{damage_report "body" "<c(FF1F00)>Engine Back 60% Degraded From Total Damage<c(FFFFFF)>"}
			{tags remove "6_dam_b"}
			{tags add "6_dam_b_engine_back"}
		else tagged "blasted_engine_left"
			{damage_report "body" "<c(FF1F00)>Engine Left 60% Degraded From Total Damage<c(FFFFFF)>"}
			{tags remove "6_dam_b"}
			{tags add "6_dam_b_engine_left"}
		else tagged "blasted_engine_right"
			{damage_report "body" "<c(FF1F00)>Engine Right 60% Degraded From Total Damage<c(FFFFFF)>"}
			{tags remove "6_dam_b"}
			{tags add "6_dam_b_engine_right"}
		else tagged "blasted_engine_top"
			{damage_report "body" "<c(FF1F00)>Engine Top 60% Degraded From Total Damage<c(FFFFFF)>"}
			{tags remove "6_dam_b"}
			{tags add "6_dam_b_engine_top"}
		}
	else tagged "5_dam_b"
		{if tagged "blasted_body_front"
			{damage_report "body" "<c(FF1F00)>Body Front 50% Degraded From Total Damage<c(FFFFFF)>"}
			{tags remove "5_dam_b"}
			{tags add "5_dam_b_body_front"}
		else tagged "blasted_body_back"
			{damage_report "body" "<c(FF1F00)>Body Back 50% Degraded From Total Damage<c(FFFFFF)>"}
			{tags remove "5_dam_b"}
			{tags add "5_dam_b_body_back"}
		else tagged "blasted_body_left"
			{damage_report "body" "<c(FF1F00)>Body Left 50% Degraded From Total Damage<c(FFFFFF)>"}
			{tags remove "5_dam_b"}
			{tags add "5_dam_b_body_left"}
		else tagged "blasted_body_right"
			{damage_report "body" "<c(FF1F00)>Body Right 50% Degraded From Total Damage<c(FFFFFF)>"}
			{tags remove "5_dam_b"}
			{tags add "5_dam_b_body_right"}
		else tagged "blasted_body_top"
			{damage_report "body" "<c(FF1F00)>Body Top 50% Degraded From Total Damage<c(FFFFFF)>"}
			{tags remove "5_dam_b"}
			{tags add "5_dam_b_body_top"}
		else tagged "blasted_turret_front"
			{damage_report "body" "<c(FF1F00)>Turret Front 50% Degraded From Total Damage<c(FFFFFF)>"}
			{tags remove "5_dam_b"}
			{tags add "5_dam_b_turret_front"}
		else tagged "blasted_turret_back"
			{damage_report "body" "<c(FF1F00)>Turret Back 50% Degraded From Total Damage<c(FFFFFF)>"}
			{tags remove "5_dam_b"}
			{tags add "5_dam_b_turret_back"}
		else tagged "blasted_turret_left"
			{damage_report "body" "<c(FF1F00)>Turret Left 50% Degraded From Total Damage<c(FFFFFF)>"}
			{tags remove "5_dam_b"}
			{tags add "5_dam_b_turret_left"}
		else tagged "blasted_turret_right"
			{damage_report "body" "<c(FF1F00)>Turret Right 50% Degraded From Total Damage<c(FFFFFF)>"}
			{tags remove "5_dam_b"}
			{tags add "5_dam_b_turret_right"}
		else tagged "blasted_turret_top"
			{damage_report "body" "<c(FF1F00)>Turret Top 50% Degraded From Total Damage<c(FFFFFF)>"}
			{tags remove "5_dam_b"}
			{tags add "5_dam_b_turret_top"}
		else tagged "blasted_engine_front"
			{damage_report "body" "<c(FF1F00)>Engine Front 50% Degraded From Total Damage<c(FFFFFF)>"}
			{tags remove "5_dam_b"}
			{tags add "5_dam_b_engine_front"}
		else tagged "blasted_engine_back"
			{damage_report "body" "<c(FF1F00)>Engine Back 50% Degraded From Total Damage<c(FFFFFF)>"}
			{tags remove "5_dam_b"}
			{tags add "5_dam_b_engine_back"}
		else tagged "blasted_engine_left"
			{damage_report "body" "<c(FF1F00)>Engine Left 50% Degraded From Total Damage<c(FFFFFF)>"}
			{tags remove "5_dam_b"}
			{tags add "5_dam_b_engine_left"}
		else tagged "blasted_engine_right"
			{damage_report "body" "<c(FF1F00)>Engine Right 50% Degraded From Total Damage<c(FFFFFF)>"}
			{tags remove "5_dam_b"}
			{tags add "5_dam_b_engine_right"}
		else tagged "blasted_engine_top"
			{damage_report "body" "<c(FF1F00)>Engine Top 50% Degraded From Total Damage<c(FFFFFF)>"}
			{tags remove "5_dam_b"}
			{tags add "5_dam_b_engine_top"}
		}
	else tagged "4_dam_b"
		{if tagged "blasted_body_front"
			{damage_report "body" "<c(FF1F00)>Body Front 40% Degraded From Total Damage<c(FFFFFF)>"}
			{tags remove "4_dam_b"}
			{tags add "4_dam_b_body_front"}
		else tagged "blasted_body_back"
			{damage_report "body" "<c(FF1F00)>Body Back 40% Degraded From Total Damage<c(FFFFFF)>"}
			{tags remove "4_dam_b"}
			{tags add "4_dam_b_body_back"}
		else tagged "blasted_body_left"
			{damage_report "body" "<c(FF1F00)>Body Left 40% Degraded From Total Damage<c(FFFFFF)>"}
			{tags remove "4_dam_b"}
			{tags add "4_dam_b_body_left"}
		else tagged "blasted_body_right"
			{damage_report "body" "<c(FF1F00)>Body Right 40% Degraded From Total Damage<c(FFFFFF)>"}
			{tags remove "4_dam_b"}
			{tags add "4_dam_b_body_right"}
		else tagged "blasted_body_top"
			{damage_report "body" "<c(FF1F00)>Body Top 40% Degraded From Total Damage<c(FFFFFF)>"}
			{tags remove "4_dam_b"}
			{tags add "4_dam_b_body_top"}
		else tagged "blasted_turret_front"
			{damage_report "body" "<c(FF1F00)>Turret Front 40% Degraded From Total Damage<c(FFFFFF)>"}
			{tags remove "4_dam_b"}
			{tags add "4_dam_b_turret_front"}
		else tagged "blasted_turret_back"
			{damage_report "body" "<c(FF1F00)>Turret Back 40% Degraded From Total Damage<c(FFFFFF)>"}
			{tags remove "4_dam_b"}
			{tags add "4_dam_b_turret_back"}
		else tagged "blasted_turret_left"
			{damage_report "body" "<c(FF1F00)>Turret Left 40% Degraded From Total Damage<c(FFFFFF)>"}
			{tags remove "4_dam_b"}
			{tags add "4_dam_b_turret_left"}
		else tagged "blasted_turret_right"
			{damage_report "body" "<c(FF1F00)>Turret Right 40% Degraded From Total Damage<c(FFFFFF)>"}
			{tags remove "4_dam_b"}
			{tags add "4_dam_b_turret_right"}
		else tagged "blasted_turret_top"
			{damage_report "body" "<c(FF1F00)>Turret Top 40% Degraded From Total Damage<c(FFFFFF)>"}
			{tags remove "4_dam_b"}
			{tags add "4_dam_b_turret_top"}
		else tagged "blasted_engine_front"
			{damage_report "body" "<c(FF1F00)>Engine Front 40% Degraded From Total Damage<c(FFFFFF)>"}
			{tags remove "4_dam_b"}
			{tags add "4_dam_b_engine_front"}
		else tagged "blasted_engine_back"
			{damage_report "body" "<c(FF1F00)>Engine Back 40% Degraded From Total Damage<c(FFFFFF)>"}
			{tags remove "4_dam_b"}
			{tags add "4_dam_b_engine_back"}
		else tagged "blasted_engine_left"
			{damage_report "body" "<c(FF1F00)>Engine Left 40% Degraded From Total Damage<c(FFFFFF)>"}
			{tags remove "4_dam_b"}
			{tags add "4_dam_b_engine_left"}
		else tagged "blasted_engine_right"
			{damage_report "body" "<c(FF1F00)>Engine Right 40% Degraded From Total Damage<c(FFFFFF)>"}
			{tags remove "4_dam_b"}
			{tags add "4_dam_b_engine_right"}
		else tagged "blasted_engine_top"
			{damage_report "body" "<c(FF1F00)>Engine Top 40% Degraded From Total Damage<c(FFFFFF)>"}
			{tags remove "4_dam_b"}
			{tags add "4_dam_b_engine_top"}
		}
	else tagged "3_dam_b"
		{if tagged "blasted_body_front"
			{damage_report "body" "<c(FF1F00)>Body Front 30% Degraded From Total Damage<c(FFFFFF)>"}
			{tags remove "3_dam_b"}
			{tags add "3_dam_b_body_front"}
		else tagged "blasted_body_back"
			{damage_report "body" "<c(FF1F00)>Body Back 30% Degraded From Total Damage<c(FFFFFF)>"}
			{tags remove "3_dam_b"}
			{tags add "3_dam_b_body_back"}
		else tagged "blasted_body_left"
			{damage_report "body" "<c(FF1F00)>Body Left 30% Degraded From Total Damage<c(FFFFFF)>"}
			{tags remove "3_dam_b"}
			{tags add "3_dam_b_body_left"}
		else tagged "blasted_body_right"
			{damage_report "body" "<c(FF1F00)>Body Right 30% Degraded From Total Damage<c(FFFFFF)>"}
			{tags remove "3_dam_b"}
			{tags add "3_dam_b_body_right"}
		else tagged "blasted_body_top"
			{damage_report "body" "<c(FF1F00)>Body Top 30% Degraded From Total Damage<c(FFFFFF)>"}
			{tags remove "3_dam_b"}
			{tags add "3_dam_b_body_top"}
		else tagged "blasted_turret_front"
			{damage_report "body" "<c(FF1F00)>Turret Front 30% Degraded From Total Damage<c(FFFFFF)>"}
			{tags remove "3_dam_b"}
			{tags add "3_dam_b_turret_front"}
		else tagged "blasted_turret_back"
			{damage_report "body" "<c(FF1F00)>Turret Back 30% Degraded From Total Damage<c(FFFFFF)>"}
			{tags remove "3_dam_b"}
			{tags add "3_dam_b_turret_back"}
		else tagged "blasted_turret_left"
			{damage_report "body" "<c(FF1F00)>Turret Left 30% Degraded From Total Damage<c(FFFFFF)>"}
			{tags remove "3_dam_b"}
			{tags add "3_dam_b_turret_left"}
		else tagged "blasted_turret_right"
			{damage_report "body" "<c(FF1F00)>Turret Right 30% Degraded From Total Damage<c(FFFFFF)>"}
			{tags remove "3_dam_b"}
			{tags add "3_dam_b_turret_right"}
		else tagged "blasted_turret_top"
			{damage_report "body" "<c(FF1F00)>Turret Top 30% Degraded From Total Damage<c(FFFFFF)>"}
			{tags remove "3_dam_b"}
			{tags add "3_dam_b_turret_top"}
		else tagged "blasted_engine_front"
			{damage_report "body" "<c(FF1F00)>Engine Front 30% Degraded From Total Damage<c(FFFFFF)>"}
			{tags remove "3_dam_b"}
			{tags add "3_dam_b_engine_front"}
		else tagged "blasted_engine_back"
			{damage_report "body" "<c(FF1F00)>Engine Back 30% Degraded From Total Damage<c(FFFFFF)>"}
			{tags remove "3_dam_b"}
			{tags add "3_dam_b_engine_back"}
		else tagged "blasted_engine_left"
			{damage_report "body" "<c(FF1F00)>Engine Left 30% Degraded From Total Damage<c(FFFFFF)>"}
			{tags remove "3_dam_b"}
			{tags add "3_dam_b_engine_left"}
		else tagged "blasted_engine_right"
			{damage_report "body" "<c(FF1F00)>Engine Right 30% Degraded From Total Damage<c(FFFFFF)>"}
			{tags remove "3_dam_b"}
			{tags add "3_dam_b_engine_right"}
		else tagged "blasted_engine_top"
			{damage_report "body" "<c(FF1F00)>Engine Top 30% Degraded From Total Damage<c(FFFFFF)>"}
			{tags remove "3_dam_b"}
			{tags add "3_dam_b_engine_top"}
		}
	else tagged "2_dam_b"
		{if tagged "blasted_body_front"
			{damage_report "body" "<c(FF1F00)>Body Front 20% Degraded From Total Damage<c(FFFFFF)>"}
			{tags remove "2_dam_b"}
			{tags add "2_dam_b_body_front"}
		else tagged "blasted_body_back"
			{damage_report "body" "<c(FF1F00)>Body Back 20% Degraded From Total Damage<c(FFFFFF)>"}
			{tags remove "2_dam_b"}
			{tags add "2_dam_b_body_back"}
		else tagged "blasted_body_left"
			{damage_report "body" "<c(FF1F00)>Body Left 20% Degraded From Total Damage<c(FFFFFF)>"}
			{tags remove "2_dam_b"}
			{tags add "2_dam_b_body_left"}
		else tagged "blasted_body_right"
			{damage_report "body" "<c(FF1F00)>Body Right 20% Degraded From Total Damage<c(FFFFFF)>"}
			{tags remove "2_dam_b"}
			{tags add "2_dam_b_body_right"}
		else tagged "blasted_body_top"
			{damage_report "body" "<c(FF1F00)>Body Top 20% Degraded From Total Damage<c(FFFFFF)>"}
			{tags remove "2_dam_b"}
			{tags add "2_dam_b_body_top"}
		else tagged "blasted_turret_front"
			{damage_report "body" "<c(FF1F00)>Turret Front 20% Degraded From Total Damage<c(FFFFFF)>"}
			{tags remove "2_dam_b"}
			{tags add "2_dam_b_turret_front"}
		else tagged "blasted_turret_back"
			{damage_report "body" "<c(FF1F00)>Turret Back 20% Degraded From Total Damage<c(FFFFFF)>"}
			{tags remove "2_dam_b"}
			{tags add "2_dam_b_turret_back"}
		else tagged "blasted_turret_left"
			{damage_report "body" "<c(FF1F00)>Turret Left 20% Degraded From Total Damage<c(FFFFFF)>"}
			{tags remove "2_dam_b"}
			{tags add "2_dam_b_turret_left"}
		else tagged "blasted_turret_right"
			{damage_report "body" "<c(FF1F00)>Turret Right 20% Degraded From Total Damage<c(FFFFFF)>"}
			{tags remove "2_dam_b"}
			{tags add "2_dam_b_turret_right"}
		else tagged "blasted_turret_top"
			{damage_report "body" "<c(FF1F00)>Turret Top 20% Degraded From Total Damage<c(FFFFFF)>"}
			{tags remove "2_dam_b"}
			{tags add "2_dam_b_turret_top"}
		else tagged "blasted_engine_front"
			{damage_report "body" "<c(FF1F00)>Engine Front 20% Degraded From Total Damage<c(FFFFFF)>"}
			{tags remove "2_dam_b"}
			{tags add "2_dam_b_engine_front"}
		else tagged "blasted_engine_back"
			{damage_report "body" "<c(FF1F00)>Engine Back 20% Degraded From Total Damage<c(FFFFFF)>"}
			{tags remove "2_dam_b"}
			{tags add "2_dam_b_engine_back"}
		else tagged "blasted_engine_left"
			{damage_report "body" "<c(FF1F00)>Engine Left 20% Degraded From Total Damage<c(FFFFFF)>"}
			{tags remove "2_dam_b"}
			{tags add "2_dam_b_engine_left"}
		else tagged "blasted_engine_right"
			{damage_report "body" "<c(FF1F00)>Engine Right 20% Degraded From Total Damage<c(FFFFFF)>"}
			{tags remove "2_dam_b"}
			{tags add "2_dam_b_engine_right"}
		else tagged "blasted_engine_top"
			{damage_report "body" "<c(FF1F00)>Engine Top 20% Degraded From Total Damage<c(FFFFFF)>"}
			{tags remove "2_dam_b"}
			{tags add "2_dam_b_engine_top"}
		}
	else tagged "1_dam_b"
		{if tagged "blasted_body_front"
			{damage_report "body" "<c(FF1F00)>Body Front 10% Degraded From Total Damage<c(FFFFFF)>"}
			{tags remove "1_dam_b"}
			{tags add "1_dam_b_body_front"}
		else tagged "blasted_body_back"
			{damage_report "body" "<c(FF1F00)>Body Back 10% Degraded From Total Damage<c(FFFFFF)>"}
			{tags remove "1_dam_b"}
			{tags add "1_dam_b_body_back"}
		else tagged "blasted_body_left"
			{damage_report "body" "<c(FF1F00)>Body Left 10% Degraded From Total Damage<c(FFFFFF)>"}
			{tags remove "1_dam_b"}
			{tags add "1_dam_b_body_left"}
		else tagged "blasted_body_right"
			{damage_report "body" "<c(FF1F00)>Body Right 10% Degraded From Total Damage<c(FFFFFF)>"}
			{tags remove "1_dam_b"}
			{tags add "1_dam_b_body_right"}
		else tagged "blasted_body_top"
			{damage_report "body" "<c(FF1F00)>Body Top 10% Degraded From Total Damage<c(FFFFFF)>"}
			{tags remove "1_dam_b"}
			{tags add "1_dam_b_body_top"}
		else tagged "blasted_turret_front"
			{damage_report "body" "<c(FF1F00)>Turret Front 10% Degraded From Total Damage<c(FFFFFF)>"}
			{tags remove "1_dam_b"}
			{tags add "1_dam_b_turret_front"}
		else tagged "blasted_turret_back"
			{damage_report "body" "<c(FF1F00)>Turret Back 10% Degraded From Total Damage<c(FFFFFF)>"}
			{tags remove "1_dam_b"}
			{tags add "1_dam_b_turret_back"}
		else tagged "blasted_turret_left"
			{damage_report "body" "<c(FF1F00)>Turret Left 10% Degraded From Total Damage<c(FFFFFF)>"}
			{tags remove "1_dam_b"}
			{tags add "1_dam_b_turret_left"}
		else tagged "blasted_turret_right"
			{damage_report "body" "<c(FF1F00)>Turret Right 10% Degraded From Total Damage<c(FFFFFF)>"}
			{tags remove "1_dam_b"}
			{tags add "1_dam_b_turret_right"}
		else tagged "blasted_turret_top"
			{damage_report "body" "<c(FF1F00)>Turret Top 10% Degraded From Total Damage<c(FFFFFF)>"}
			{tags remove "1_dam_b"}
			{tags add "1_dam_b_turret_top"}
		else tagged "blasted_engine_front"
			{damage_report "body" "<c(FF1F00)>Engine Front 10% Degraded From Total Damage<c(FFFFFF)>"}
			{tags remove "1_dam_b"}
			{tags add "1_dam_b_engine_front"}
		else tagged "blasted_engine_back"
			{damage_report "body" "<c(FF1F00)>Engine Back 10% Degraded From Total Damage<c(FFFFFF)>"}
			{tags remove "1_dam_b"}
			{tags add "1_dam_b_engine_back"}
		else tagged "blasted_engine_left"
			{damage_report "body" "<c(FF1F00)>Engine Left 10% Degraded From Total Damage<c(FFFFFF)>"}
			{tags remove "1_dam_b"}
			{tags add "1_dam_b_engine_left"}
		else tagged "blasted_engine_right"
			{damage_report "body" "<c(FF1F00)>Engine Right 10% Degraded From Total Damage<c(FFFFFF)>"}
			{tags remove "1_dam_b"}
			{tags add "1_dam_b_engine_right"}
		else tagged "blasted_engine_top"
			{damage_report "body" "<c(FF1F00)>Engine Top 10% Degraded From Total Damage<c(FFFFFF)>"}
			{tags remove "1_dam_b"}
			{tags add "1_dam_b_engine_top"}
		}
	else tagged "0_dam_b"
		{damage_report "body" "<c(FF1F00)>Body Front No Sustained Damage<c(FFFFFF)>"}
	else tagged "11_dam_b"
		{delay 0.1
			("delay_tag" a(cumulative_damage_blast_to_armor))
 	 	}
	else tagged "12_dam_b"
		{delay 0.1
 	 	 	 ("delay_tag" a(cumulative_damage_blast_to_armor))
 	 	}
	else tagged "13_dam_b"
		{delay 0.1
 	 	 	 ("delay_tag" a(cumulative_damage_blast_to_armor))
 	 	}
	else tagged "14_dam_b"
		{delay 0.1
 	 	 	 ("delay_tag" a(cumulative_damage_blast_to_armor))
 	 	}
	else tagged "15_dam_b"
		{delay 0.1
 	 	 	 ("delay_tag" a(cumulative_damage_blast_to_armor))
 	 	}
	else tagged "16_dam_b"
		{delay 0.1
 	 	 	 ("delay_tag" a(cumulative_damage_blast_to_armor))
 	 	}
	else tagged "17_dam_b"
		{delay 0.1
 	 	 	 ("delay_tag" a(cumulative_damage_blast_to_armor))
 	 	}
	else tagged "18_dam_b"
		{delay 0.1
 	 	 	 ("delay_tag" a(cumulative_damage_blast_to_armor))
 	 	}
	else tagged "19_dam_b"
		{delay 0.1
 	 	 	 ("delay_tag" a(cumulative_damage_blast_to_armor))
 	 	}
	else tagged "20_dam_b"
		{delay 0.1
 	 	 	 ("delay_tag" a(cumulative_damage_blast_to_armor))
 	 	}
	else tagged "21_dam_b"
		{delay 0.1
 	 	 	 ("delay_tag" a(cumulative_damage_blast_to_armor))
 	 	}
	else tagged "22_dam_b"
		{delay 0.1
 	 	 	 ("delay_tag" a(cumulative_damage_blast_to_armor))
 	 	}
	else
		{damage_report "body" "<c(FF1F00)>ERROR 1: Report<c(FFFFFF)>"}
	}
	{delay 0.2
		{tags remove "blasted_body_front blasted_body_back blasted_body_left blasted_body_right blasted_body_top blasted_turret_front blasted_turret_back blasted_turret_left blasted_turret_right blasted_turret_top blasted_engine_front blasted_engine_back blasted_engine_left blasted_engine_right blasted_engine_top"}
	}
