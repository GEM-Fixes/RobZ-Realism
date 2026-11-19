{on blast_hit
	{if volume "body"
		{if hit_side front
			{if tagged "10_dam_b_body_front"
				{tags add "10_dam_b"}
				{tags remove "10_dam_b_body_front"}
			else tagged "9_dam_b_body_front"
				{tags add "9_dam_b"}
				{tags remove "9_dam_b_body_front"}
			else tagged "8_dam_b_body_front"
				{tags add "8_dam_b"}
				{tags remove "8_dam_b_body_front"}
			else tagged "7_dam_b_body_front"
				{tags add "7_dam_b"}
				{tags remove "7_dam_b_body_front"}
			else tagged "6_dam_b_body_front"
				{tags add "6_dam_b"}
				{tags remove "6_dam_b_body_front"}
			else tagged "5_dam_b_body_front"
				{tags add "5_dam_b"}
				{tags remove "5_dam_b_body_front"}
			else tagged "4_dam_b_body_front"
				{tags add "4_dam_b"}
				{tags remove "4_dam_b_body_front"}
			else tagged "3_dam_b_body_front"
				{tags add "3_dam_b"}
				{tags remove "3_dam_b_body_front"}
			else tagged "2_dam_b_body_front"
				{tags add "2_dam_b"}
				{tags remove "2_dam_b_body_front"}
			else tagged "1_dam_b_body_front"
				{tags add "1_dam_b"}
				{tags remove "1_dam_b_body_front"}
			}
			{if not tagged "blasted_body_front"
				{tags add "blasted_body_front"}
				{if min_energy 24 ;203 direct hit
					{if tagged "armored_car"
						{delay 0.01
							("delay_tag" a(cumulative_damage_blast_to_armor))
						}
					else "light_tank"
						{delay 0.01
							("delay_tag" a(cumulative_damage_blast_to_armor))
						}
					else "medium_tank"
						{delay 0.01
							("delay_tag" a(cumulative_damage_blast_to_armor))
						}
					else "heavy_tank"
						{if not tagged "6_dam_b"
							{tags add "6_dam_b"}
						else tagged "6_dam_b"
							{tags add "6_dam_b_2"}
						}
						{delay 0.01
							("delay_tag" a(damage_counter_blast_add6))
						}
					}
				else min_energy 14 ;155 direct hit
					{if tagged "armored_car"
						{delay 0.01
							("delay_tag" a(cumulative_damage_blast_to_armor))
						}
					else "light_tank"
						{delay 0.01
							("delay_tag" a(cumulative_damage_blast_to_armor))
						}
					else "medium_tank"
						{if not tagged "6_dam_b"
							{tags add "6_dam_b"}
						else tagged "6_dam_b"
							{tags add "6_dam_b_2"}
						}
						{delay 0.01
							("delay_tag" a(damage_counter_blast_add6))
						}
					else "heavy_tank"
						{if not tagged "4_dam_b"
							{tags add "4_dam_b"}
						else tagged "4_dam_b"
							{tags add "4_dam_b_2"}
						}
						{delay 0.01
							("delay_tag" a(damage_counter_blast_add4))
						}
					}
				else min_energy 8.5 ;122
					{if tagged "armored_car"
						{delay 0.01
							("delay_tag" a(cumulative_damage_blast_to_armor))
						}
					else "light_tank"
						{delay 0.01
							("delay_tag" a(cumulative_damage_blast_to_armor))
						}
					else "medium_tank"
						{if not tagged "5_dam_b"
							{tags add "5_dam_b"}
						else tagged "5_dam_b"
							{tags add "5_dam_b_2"}
						}
						{delay 0.01
							("delay_tag" a(damage_counter_blast_add5))
						}
					else "heavy_tank"
						{if not tagged "3_dam_b"
							{tags add "3_dam_b"}
						else tagged "3_dam_b"
							{tags add "3_dam_b_2"}
						}
						{delay 0.01
							("delay_tag" a(damage_counter_blast_add3))
						}
					}
				else min_energy 7.5 ;85
					{if tagged "armored_car"
						{delay 0.01
							("delay_tag" a(cumulative_damage_blast_to_armor))
						}
					else "light_tank"
						{if not tagged "9_dam_b"
							{tags add "9_dam_b"}
						else tagged "9_dam_b"
							{tags add "9_dam_b_2"}
						}
						{delay 0.01
							("delay_tag" a(damage_counter_blast_add9))
						}
					else "medium_tank"
						{if not tagged "4_dam_b"
							{tags add "4_dam_b"}
						else tagged "4_dam_b"
							{tags add "4_dam_b_2"}
						}
						{delay 0.01
							("delay_tag" a(damage_counter_blast_add4))
						}
					else "heavy_tank"
						{if not tagged "1_dam_b"
							{tags add "1_dam_b"}
						else tagged "1_dam_b"
							{tags add "1_dam_b_2"}
						}
						{delay 0.01
							("delay_tag" a(damage_counter_blast_add1))
						}
					}
				else min_energy 5 ;75
					{if tagged "armored_car"
						{if not tagged "6_dam_b"
							{tags add "6_dam_b"}
						else tagged "6_dam_b"
							{tags add "6_dam_b_2"}
						}
						{delay 0.01
							("delay_tag" a(damage_counter_blast_add6))
						}
					else "light_tank"
						{if not tagged "4_dam_b"
							{tags add "4_dam_b"}
						else tagged "4_dam_b"
							{tags add "4_dam_b_2"}
						}
						{delay 0.01
							("delay_tag" a(damage_counter_blast_add4))
						}
					else "medium_tank"
						{if not tagged "2_dam_b"
							{tags add "2_dam_b"}
						else tagged "2_dam_b"
							{tags add "2_dam_b_2"}
						}
						{delay 0.01
							("delay_tag" a(damage_counter_blast_add2))
						}
					else "heavy_tank"
						{if not tagged "1_dam_b"
							{tags add "1_dam_b"}
						else tagged "1_dam_b"
							{tags add "1_dam_b_2"}
						}
						{delay 0.01
							("delay_tag" a(damage_counter_blast_add1))
						}
					}
				else min_energy 4 ;50mm
					{if tagged "armored_car"
						{if not tagged "3_dam_b"
							{tags add "3_dam_b"}
						else tagged "3_dam_b"
							{tags add "3_dam_b_2"}
						}
						{delay 0.01
							("delay_tag" a(damage_counter_blast_add3))
						}
					else "light_tank"
						{if not tagged "1_dam_b"
							{tags add "1_dam_b"}
						else tagged "1_dam_b"
							{tags add "1_dam_b_2"}
						}
						{delay 0.01
							("delay_tag" a(damage_counter_blast_add1))
						}
					else "medium_tank"
					else "heavy_tank"
					}
				else
					;{damage_report "body" "<c(FF1F00)>Test<c(FFFFFF)>"}
				}
			}
		}
		{if hit_side back
			{if tagged "10_dam_b_body_back"
				{tags add "10_dam_b"}
				{tags remove "10_dam_b_body_back"}
			else tagged "9_dam_b_body_back"
				{tags add "9_dam_b"}
				{tags remove "9_dam_b_body_back"}
			else tagged "8_dam_b_body_back"
				{tags add "8_dam_b"}
				{tags remove "8_dam_b_body_back"}
			else tagged "7_dam_b_body_back"
				{tags add "7_dam_b"}
				{tags remove "7_dam_b_body_back"}
			else tagged "6_dam_b_body_back"
				{tags add "6_dam_b"}
				{tags remove "6_dam_b_body_back"}
			else tagged "5_dam_b_body_back"
				{tags add "5_dam_b"}
				{tags remove "5_dam_b_body_back"}
			else tagged "4_dam_b_body_back"
				{tags add "4_dam_b"}
				{tags remove "4_dam_b_body_back"}
			else tagged "3_dam_b_body_back"
				{tags add "3_dam_b"}
				{tags remove "3_dam_b_body_back"}
			else tagged "2_dam_b_body_back"
				{tags add "2_dam_b"}
				{tags remove "2_dam_b_body_back"}
			else tagged "1_dam_b_body_back"
				{tags add "1_dam_b"}
				{tags remove "1_dam_b_body_back"}
			}
			{if not tagged "blasted_body_back"
				{tags add "blasted_body_back"}
				{if min_energy 24 ;203 direct hit
					{if tagged "armored_car"
						{delay 0.01
							("delay_tag" a(cumulative_damage_blast_to_armor))
						}
					else "light_tank"
						{delay 0.01
							("delay_tag" a(cumulative_damage_blast_to_armor))
						}
					else "medium_tank"
						{delay 0.01
							("delay_tag" a(cumulative_damage_blast_to_armor))
						}
					else "heavy_tank"
						{delay 0.01
							("delay_tag" a(cumulative_damage_blast_to_armor))
						}
					}
				else min_energy 14 ;155 direct hit
					{if tagged "armored_car"
						{delay 0.01
							("delay_tag" a(cumulative_damage_blast_to_armor))
						}
					else "light_tank"
						{delay 0.01
							("delay_tag" a(cumulative_damage_blast_to_armor))
						}
					else "medium_tank"
						{delay 0.01
							("delay_tag" a(cumulative_damage_blast_to_armor))
						}
					else "heavy_tank"
						{if not tagged "6_dam_b"
							{tags add "6_dam_b"}
						else tagged "6_dam_b"
							{tags add "6_dam_b_2"}
						}
						{delay 0.01
							("delay_tag" a(damage_counter_blast_add6))
						}
					}
				else min_energy 8.5 ;122
					{if tagged "armored_car"
						{delay 0.01
							("delay_tag" a(cumulative_damage_blast_to_armor))
						}
					else "light_tank"
						{delay 0.01
							("delay_tag" a(cumulative_damage_blast_to_armor))
						}
					else "medium_tank"
						{if not tagged "8_dam_b"
							{tags add "8_dam_b"}
						else tagged "8_dam_b"
							{tags add "8_dam_b_2"}
						}
						{delay 0.01
							("delay_tag" a(damage_counter_blast_add8))
						}
					else "heavy_tank"
						{if not tagged "4_dam_b"
							{tags add "4_dam_b"}
						else tagged "4_dam_b"
							{tags add "4_dam_b_2"}
						}
						{delay 0.01
							("delay_tag" a(damage_counter_blast_add4))
						}
					}
				else min_energy 7.5 ;85
					{if tagged "armored_car"
						{delay 0.01
							("delay_tag" a(cumulative_damage_blast_to_armor))
						}
					else "light_tank"
						{delay 0.01
							("delay_tag" a(cumulative_damage_blast_to_armor))
						}
					else "medium_tank"
						{if not tagged "6_dam_b"
							{tags add "6_dam_b"}
						else tagged "6_dam_b"
							{tags add "6_dam_b_2"}
						}
						{delay 0.01
							("delay_tag" a(damage_counter_blast_add6))
						}
					else "heavy_tank"
						{if not tagged "2_dam_b"
							{tags add "2_dam_b"}
						else tagged "2_dam_b"
							{tags add "2_dam_b_2"}
						}
						{delay 0.01
							("delay_tag" a(damage_counter_blast_add2))
						}
					}
				else min_energy 5 ;75
					{if tagged "armored_car"
						{if not tagged "10_dam_b"
							{tags add "10_dam_b"}
						else tagged "10_dam_b"
							{tags add "10_dam_b_2"}
						}
						{delay 0.01
							("delay_tag" a(damage_counter_blast_add10))
						}
					else "light_tank"
						{if not tagged "8_dam_b"
							{tags add "8_dam_b"}
						else tagged "8_dam_b"
							{tags add "8_dam_b_2"}
						}
						{delay 0.01
							("delay_tag" a(damage_counter_blast_add8))
						}
					else "medium_tank"
						{if not tagged "4_dam_b"
							{tags add "4_dam_b"}
						else tagged "4_dam_b"
							{tags add "4_dam_b_2"}
						}
						{delay 0.01
							("delay_tag" a(damage_counter_blast_add4))
						}
					else "heavy_tank"
						{if not tagged "1_dam_b"
							{tags add "1_dam_b"}
						else tagged "1_dam_b"
							{tags add "1_dam_b_2"}
						}
						{delay 0.01
							("delay_tag" a(damage_counter_blast_add1))
						}
					}
				else min_energy 4 ;50mm
					{if tagged "armored_car"
						{if not tagged "5_dam_b"
							{tags add "5_dam_b"}
						else tagged "5_dam_b"
							{tags add "5_dam_b_2"}
						}
						{delay 0.01
							("delay_tag" a(damage_counter_blast_add5))
						}
					else "light_tank"
						{if not tagged "2_dam_b"
							{tags add "2_dam_b"}
						else tagged "2_dam_b"
							{tags add "2_dam_b_2"}
						}
						{delay 0.01
							("delay_tag" a(damage_counter_blast_add2))
						}
					else "medium_tank"
					else "heavy_tank"
					}
				else
					;{damage_report "body" "<c(FF1F00)>Test<c(FFFFFF)>"}
				}
			}
		}
		{if hit_side left
			{if tagged "10_dam_b_body_left"
				{tags add "10_dam_b"}
				{tags remove "10_dam_b_body_left"}
			else tagged "9_dam_b_body_left"
				{tags add "9_dam_b"}
				{tags remove "9_dam_b_body_left"}
			else tagged "8_dam_b_body_left"
				{tags add "8_dam_b"}
				{tags remove "8_dam_b_body_left"}
			else tagged "7_dam_b_body_left"
				{tags add "7_dam_b"}
				{tags remove "7_dam_b_body_left"}
			else tagged "6_dam_b_body_left"
				{tags add "6_dam_b"}
				{tags remove "6_dam_b_body_left"}
			else tagged "5_dam_b_body_left"
				{tags add "5_dam_b"}
				{tags remove "5_dam_b_body_left"}
			else tagged "4_dam_b_body_left"
				{tags add "4_dam_b"}
				{tags remove "4_dam_b_body_left"}
			else tagged "3_dam_b_body_left"
				{tags add "3_dam_b"}
				{tags remove "3_dam_b_body_left"}
			else tagged "2_dam_b_body_left"
				{tags add "2_dam_b"}
				{tags remove "2_dam_b_body_left"}
			else tagged "1_dam_b_body_left"
				{tags add "1_dam_b"}
				{tags remove "1_dam_b_body_left"}
			}
			{if not tagged "blasted_body_left"
				{tags add "blasted_body_left"}
				{if min_energy 24 ;203 direct hit
					{if tagged "armored_car"
						{delay 0.01
							("delay_tag" a(cumulative_damage_blast_to_armor))
						}
					else "light_tank"
						{delay 0.01
							("delay_tag" a(cumulative_damage_blast_to_armor))
						}
					else "medium_tank"
						{delay 0.01
							("delay_tag" a(cumulative_damage_blast_to_armor))
						}
					else "heavy_tank"
						{if not tagged "10_dam_b"
							{tags add "10_dam_b"}
						else tagged "10_dam_b"
							{tags add "10_dam_b_2"}
						}
						{delay 0.01
							("delay_tag" a(damage_counter_blast_add10))
						}
					}
				else min_energy 14 ;155 direct hit
					{if tagged "armored_car"
						{delay 0.01
							("delay_tag" a(cumulative_damage_blast_to_armor))
						}
					else "light_tank"
						{delay 0.01
							("delay_tag" a(cumulative_damage_blast_to_armor))
						}
					else "medium_tank"
						{if not tagged "10_dam_b"
							{tags add "10_dam_b"}
						else tagged "10_dam_b"
							{tags add "10_dam_b_2"}
						}
						{delay 0.01
							("delay_tag" a(damage_counter_blast_add10))
						}
					else "heavy_tank"
						{if not tagged "5_dam_b"
							{tags add "5_dam_b"}
						else tagged "5_dam_b"
							{tags add "5_dam_b_2"}
						}
						{delay 0.01
							("delay_tag" a(damage_counter_blast_add5))
						}
					}
				else min_energy 8.5 ;122
					{if tagged "armored_car"
						{delay 0.01
							("delay_tag" a(cumulative_damage_blast_to_armor))
						}
					else "light_tank"
						{delay 0.01
							("delay_tag" a(cumulative_damage_blast_to_armor))
						}
					else "medium_tank"
						{if not tagged "5_dam_b"
							{tags add "5_dam_b"}
						else tagged "5_dam_b"
							{tags add "5_dam_b_2"}
						}
						{delay 0.01
							("delay_tag" a(damage_counter_blast_add5))
						}
					else "heavy_tank"
						{if not tagged "4_dam_b"
							{tags add "4_dam_b"}
						else tagged "4_dam_b"
							{tags add "4_dam_b_2"}
						}
						{delay 0.01
							("delay_tag" a(damage_counter_blast_add4))
						}
					}
				else min_energy 7.5 ;85
					{if tagged "armored_car"
						{delay 0.01
							("delay_tag" a(cumulative_damage_blast_to_armor))
						}
					else "light_tank"
						{if not tagged "10_dam_b"
							{tags add "10_dam_b"}
						else tagged "10_dam_b"
							{tags add "10_dam_b_2"}
						}
						{delay 0.01
							("delay_tag" a(damage_counter_blast_add10))
						}
					else "medium_tank"
						{if not tagged "3_dam_b"
							{tags add "3_dam_b"}
						else tagged "3_dam_b"
							{tags add "3_dam_b_2"}
						}
						{delay 0.01
							("delay_tag" a(damage_counter_blast_add3))
						}
					else "heavy_tank"
						{if not tagged "2_dam_b"
							{tags add "2_dam_b"}
						else tagged "2_dam_b"
							{tags add "2_dam_b_2"}
						}
						{delay 0.01
							("delay_tag" a(damage_counter_blast_add2))
						}
					}
				else min_energy 5 ;75
					{if tagged "armored_car"
						{if not tagged "10_dam_b"
							{tags add "10_dam_b"}
						else tagged "10_dam_b"
							{tags add "10_dam_b_2"}
						}
						{delay 0.01
							("delay_tag" a(damage_counter_blast_add10))
						}
					else "light_tank"
						{if not tagged "5_dam_b"
							{tags add "5_dam_b"}
						else tagged "5_dam_b"
							{tags add "5_dam_b_2"}
						}
						{delay 0.01
							("delay_tag" a(damage_counter_blast_add5))
						}
					else "medium_tank"
						{if not tagged "2_dam_b"
							{tags add "2_dam_b"}
						else tagged "2_dam_b"
							{tags add "2_dam_b_2"}
						}
						{delay 0.01
							("delay_tag" a(damage_counter_blast_add2))
						}
					else "heavy_tank"
						{if not tagged "1_dam_b"
							{tags add "1_dam_b"}
						else tagged "1_dam_b"
							{tags add "1_dam_b_2"}
						}
						{delay 0.01
							("delay_tag" a(damage_counter_blast_add1))
						}
					}
				else min_energy 4 ;50mm
					{if tagged "armored_car"
						{if not tagged "4_dam_b"
							{tags add "4_dam_b"}
						else tagged "4_dam_b"
							{tags add "4_dam_b_2"}
						}
						{delay 0.01
							("delay_tag" a(damage_counter_blast_add4))
						}
					else "light_tank"
						{if not tagged "1_dam_b"
							{tags add "1_dam_b"}
						else tagged "1_dam_b"
							{tags add "1_dam_b_2"}
						}
						{delay 0.01
							("delay_tag" a(damage_counter_blast_add1))
						}
					else "medium_tank"
					else "heavy_tank"
					}
				else
					;{damage_report "body" "<c(FF1F00)>Test<c(FFFFFF)>"}
				}
			}
		}
		{if hit_side right
			{if tagged "10_dam_b_body_right"
				{tags add "10_dam_b"}
				{tags remove "10_dam_b_body_right"}
			else tagged "9_dam_b_body_right"
				{tags add "9_dam_b"}
				{tags remove "9_dam_b_body_right"}
			else tagged "8_dam_b_body_right"
				{tags add "8_dam_b"}
				{tags remove "8_dam_b_body_right"}
			else tagged "7_dam_b_body_right"
				{tags add "7_dam_b"}
				{tags remove "7_dam_b_body_right"}
			else tagged "6_dam_b_body_right"
				{tags add "6_dam_b"}
				{tags remove "6_dam_b_body_right"}
			else tagged "5_dam_b_body_right"
				{tags add "5_dam_b"}
				{tags remove "5_dam_b_body_right"}
			else tagged "4_dam_b_body_right"
				{tags add "4_dam_b"}
				{tags remove "4_dam_b_body_right"}
			else tagged "3_dam_b_body_right"
				{tags add "3_dam_b"}
				{tags remove "3_dam_b_body_right"}
			else tagged "2_dam_b_body_right"
				{tags add "2_dam_b"}
				{tags remove "2_dam_b_body_right"}
			else tagged "1_dam_b_body_right"
				{tags add "1_dam_b"}
				{tags remove "1_dam_b_body_right"}
			}
			{if not tagged "blasted_body_right"
				{tags add "blasted_body_right"}
				{if min_energy 24 ;203 direct hit
					{if tagged "armored_car"
						{delay 0.01
							("delay_tag" a(cumulative_damage_blast_to_armor))
						}
					else "light_tank"
						{delay 0.01
							("delay_tag" a(cumulative_damage_blast_to_armor))
						}
					else "medium_tank"
						{delay 0.01
							("delay_tag" a(cumulative_damage_blast_to_armor))
						}
					else "heavy_tank"
						{if not tagged "10_dam_b"
							{tags add "10_dam_b"}
						else tagged "10_dam_b"
							{tags add "10_dam_b_2"}
						}
						{delay 0.01
							("delay_tag" a(damage_counter_blast_add10))
						}
					}
				else min_energy 14 ;155 direct hit
					{if tagged "armored_car"
						{delay 0.01
							("delay_tag" a(cumulative_damage_blast_to_armor))
						}
					else "light_tank"
						{delay 0.01
							("delay_tag" a(cumulative_damage_blast_to_armor))
						}
					else "medium_tank"
						{if not tagged "10_dam_b"
							{tags add "10_dam_b"}
						else tagged "10_dam_b"
							{tags add "10_dam_b_2"}
						}
						{delay 0.01
							("delay_tag" a(damage_counter_blast_add10))
						}
					else "heavy_tank"
						{if not tagged "5_dam_b"
							{tags add "5_dam_b"}
						else tagged "5_dam_b"
							{tags add "5_dam_b_2"}
						}
						{delay 0.01
							("delay_tag" a(damage_counter_blast_add5))
						}
					}
				else min_energy 8.5 ;122
					{if tagged "armored_car"
						{delay 0.01
							("delay_tag" a(cumulative_damage_blast_to_armor))
						}
					else "light_tank"
						{delay 0.01
							("delay_tag" a(cumulative_damage_blast_to_armor))
						}
					else "medium_tank"
						{if not tagged "5_dam_b"
							{tags add "5_dam_b"}
						else tagged "5_dam_b"
							{tags add "5_dam_b_2"}
						}
						{delay 0.01
							("delay_tag" a(damage_counter_blast_add5))
						}
					else "heavy_tank"
						{if not tagged "4_dam_b"
							{tags add "4_dam_b"}
						else tagged "4_dam_b"
							{tags add "4_dam_b_2"}
						}
						{delay 0.01
							("delay_tag" a(damage_counter_blast_add4))
						}
					}
				else min_energy 7.5 ;85
					{if tagged "armored_car"
						{delay 0.01
							("delay_tag" a(cumulative_damage_blast_to_armor))
						}
					else "light_tank"
						{if not tagged "10_dam_b"
							{tags add "10_dam_b"}
						else tagged "10_dam_b"
							{tags add "10_dam_b_2"}
						}
						{delay 0.01
							("delay_tag" a(damage_counter_blast_add10))
						}
					else "medium_tank"
						{if not tagged "3_dam_b"
							{tags add "3_dam_b"}
						else tagged "3_dam_b"
							{tags add "3_dam_b_2"}
						}
						{delay 0.01
							("delay_tag" a(damage_counter_blast_add3))
						}
					else "heavy_tank"
						{if not tagged "2_dam_b"
							{tags add "2_dam_b"}
						else tagged "2_dam_b"
							{tags add "2_dam_b_2"}
						}
						{delay 0.01
							("delay_tag" a(damage_counter_blast_add2))
						}
					}
				else min_energy 5 ;75
					{if tagged "armored_car"
						{if not tagged "10_dam_b"
							{tags add "10_dam_b"}
						else tagged "10_dam_b"
							{tags add "10_dam_b_2"}
						}
						{delay 0.01
							("delay_tag" a(damage_counter_blast_add10))
						}
					else "light_tank"
						{if not tagged "5_dam_b"
							{tags add "5_dam_b"}
						else tagged "5_dam_b"
							{tags add "5_dam_b_2"}
						}
						{delay 0.01
							("delay_tag" a(damage_counter_blast_add5))
						}
					else "medium_tank"
						{if not tagged "2_dam_b"
							{tags add "2_dam_b"}
						else tagged "2_dam_b"
							{tags add "2_dam_b_2"}
						}
						{delay 0.01
							("delay_tag" a(damage_counter_blast_add2))
						}
					else "heavy_tank"
						{if not tagged "1_dam_b"
							{tags add "1_dam_b"}
						else tagged "1_dam_b"
							{tags add "1_dam_b_2"}
						}
						{delay 0.01
							("delay_tag" a(damage_counter_blast_add1))
						}
					}
				else min_energy 4 ;50mm
					{if tagged "armored_car"
						{if not tagged "4_dam_b"
							{tags add "4_dam_b"}
						else tagged "4_dam_b"
							{tags add "4_dam_b_2"}
						}
						{delay 0.01
							("delay_tag" a(damage_counter_blast_add4))
						}
					else "light_tank"
						{if not tagged "1_dam_b"
							{tags add "1_dam_b"}
						else tagged "1_dam_b"
							{tags add "1_dam_b_2"}
						}
						{delay 0.01
							("delay_tag" a(damage_counter_blast_add1))
						}
					else "medium_tank"
					else "heavy_tank"
					}
				else
					;{damage_report "body" "<c(FF1F00)>Test<c(FFFFFF)>"}
				}
			}
		}
		{if hit_side top
			{if tagged "10_dam_b_body_top"
				{tags add "10_dam_b"}
				{tags remove "10_dam_b_body_top"}
			else tagged "9_dam_b_body_top"
				{tags add "9_dam_b"}
				{tags remove "9_dam_b_body_top"}
			else tagged "8_dam_b_body_top"
				{tags add "8_dam_b"}
				{tags remove "8_dam_b_body_top"}
			else tagged "7_dam_b_body_top"
				{tags add "7_dam_b"}
				{tags remove "7_dam_b_body_top"}
			else tagged "6_dam_b_body_top"
				{tags add "6_dam_b"}
				{tags remove "6_dam_b_body_top"}
			else tagged "5_dam_b_body_top"
				{tags add "5_dam_b"}
				{tags remove "5_dam_b_body_top"}
			else tagged "4_dam_b_body_top"
				{tags add "4_dam_b"}
				{tags remove "4_dam_b_body_top"}
			else tagged "3_dam_b_body_top"
				{tags add "3_dam_b"}
				{tags remove "3_dam_b_body_top"}
			else tagged "2_dam_b_body_top"
				{tags add "2_dam_b"}
				{tags remove "2_dam_b_body_top"}
			else tagged "1_dam_b_body_top"
				{tags add "1_dam_b"}
				{tags remove "1_dam_b_body_top"}
			}
			{if not tagged "blasted_body_top"
				{tags add "blasted_body_top"}
				{if min_energy 24 ;203 direct hit
					{if tagged "armored_car"
						{delay 0.01
							("delay_tag" a(cumulative_damage_blast_to_armor))
						}
					else "light_tank"
						{delay 0.01
							("delay_tag" a(cumulative_damage_blast_to_armor))
						}
					else "medium_tank"
						{delay 0.01
							("delay_tag" a(cumulative_damage_blast_to_armor))
						}
					else "heavy_tank"
						{delay 0.01
							("delay_tag" a(cumulative_damage_blast_to_armor))
						}
					}
				else min_energy 14 ;155 direct hit
					{if tagged "armored_car"
						{delay 0.01
							("delay_tag" a(cumulative_damage_blast_to_armor))
						}
					else "light_tank"
						{delay 0.01
							("delay_tag" a(cumulative_damage_blast_to_armor))
						}
					else "medium_tank"
						{delay 0.01
							("delay_tag" a(cumulative_damage_blast_to_armor))
						}
					else "heavy_tank"
						{if not tagged "6_dam_b"
							{tags add "6_dam_b"}
						else tagged "6_dam_b"
							{tags add "6_dam_b_2"}
						}
						{delay 0.01
							("delay_tag" a(damage_counter_blast_add6))
						}
					}
				else min_energy 8.5 ;122
					{if tagged "armored_car"
						{delay 0.01
							("delay_tag" a(cumulative_damage_blast_to_armor))
						}
					else "light_tank"
						{delay 0.01
							("delay_tag" a(cumulative_damage_blast_to_armor))
						}
					else "medium_tank"
						{if not tagged "8_dam_b"
							{tags add "8_dam_b"}
						else tagged "8_dam_b"
							{tags add "8_dam_b_2"}
						}
						{delay 0.01
							("delay_tag" a(damage_counter_blast_add8))
						}
					else "heavy_tank"
						{if not tagged "4_dam_b"
							{tags add "4_dam_b"}
						else tagged "4_dam_b"
							{tags add "4_dam_b_2"}
						}
						{delay 0.01
							("delay_tag" a(damage_counter_blast_add4))
						}
					}
				else min_energy 7.5 ;85
					{if tagged "armored_car"
						{delay 0.01
							("delay_tag" a(cumulative_damage_blast_to_armor))
						}
					else "light_tank"
						{delay 0.01
							("delay_tag" a(cumulative_damage_blast_to_armor))
						}
					else "medium_tank"
						{if not tagged "6_dam_b"
							{tags add "6_dam_b"}
						else tagged "6_dam_b"
							{tags add "6_dam_b_2"}
						}
						{delay 0.01
							("delay_tag" a(damage_counter_blast_add6))
						}
					else "heavy_tank"
						{if not tagged "2_dam_b"
							{tags add "2_dam_b"}
						else tagged "2_dam_b"
							{tags add "2_dam_b_2"}
						}
						{delay 0.01
							("delay_tag" a(damage_counter_blast_add2))
						}
					}
				else min_energy 5 ;75
					{if tagged "armored_car"
						{if not tagged "10_dam_b"
							{tags add "10_dam_b"}
						else tagged "10_dam_b"
							{tags add "10_dam_b_2"}
						}
						{delay 0.01
							("delay_tag" a(damage_counter_blast_add10))
						}
					else "light_tank"
						{if not tagged "8_dam_b"
							{tags add "8_dam_b"}
						else tagged "8_dam_b"
							{tags add "8_dam_b_2"}
						}
						{delay 0.01
							("delay_tag" a(damage_counter_blast_add8))
						}
					else "medium_tank"
						{if not tagged "4_dam_b"
							{tags add "4_dam_b"}
						else tagged "4_dam_b"
							{tags add "4_dam_b_2"}
						}
						{delay 0.01
							("delay_tag" a(damage_counter_blast_add4))
						}
					else "heavy_tank"
						{if not tagged "1_dam_b"
							{tags add "1_dam_b"}
						else tagged "1_dam_b"
							{tags add "1_dam_b_2"}
						}
						{delay 0.01
							("delay_tag" a(damage_counter_blast_add1))
						}
					}
				else min_energy 4 ;50mm
					{if tagged "armored_car"
						{if not tagged "5_dam_b"
							{tags add "5_dam_b"}
						else tagged "5_dam_b"
							{tags add "5_dam_b_2"}
						}
						{delay 0.01
							("delay_tag" a(damage_counter_blast_add5))
						}
					else "light_tank"
						{if not tagged "2_dam_b"
							{tags add "2_dam_b"}
						else tagged "2_dam_b"
							{tags add "2_dam_b_2"}
						}
						{delay 0.01
							("delay_tag" a(damage_counter_blast_add2))
						}
					else "medium_tank"
					else "heavy_tank"
					}
				else
					;{damage_report "body" "<c(FF1F00)>Test<c(FFFFFF)>"}
				}
			}
		}
	}
	{if volume "turret"
		{if hit_side front
		{if tagged "10_dam_b_turret_front"
				{tags add "10_dam_b"}
				{tags remove "10_dam_b_turret_front"}
			else tagged "9_dam_b_turret_front"
				{tags add "9_dam_b"}
				{tags remove "9_dam_b_turret_front"}
			else tagged "8_dam_b_turret_front"
				{tags add "8_dam_b"}
				{tags remove "8_dam_b_turret_front"}
			else tagged "7_dam_b_turret_front"
				{tags add "7_dam_b"}
				{tags remove "7_dam_b_turret_front"}
			else tagged "6_dam_b_turret_front"
				{tags add "6_dam_b"}
				{tags remove "6_dam_b_turret_front"}
			else tagged "5_dam_b_turret_front"
				{tags add "5_dam_b"}
				{tags remove "5_dam_b_turret_front"}
			else tagged "4_dam_b_turret_front"
				{tags add "4_dam_b"}
				{tags remove "4_dam_b_turret_front"}
			else tagged "3_dam_b_turret_front"
				{tags add "3_dam_b"}
				{tags remove "3_dam_b_turret_front"}
			else tagged "2_dam_b_turret_front"
				{tags add "2_dam_b"}
				{tags remove "2_dam_b_turret_front"}
			else tagged "1_dam_b_turret_front"
				{tags add "1_dam_b"}
				{tags remove "1_dam_b_turret_front"}
			}
			{if not tagged "blasted_turret_front"
				{tags add "blasted_turret_front"}
				{if min_energy 24 ;203 direct hit
					{if tagged "armored_car"
						{delay 0.01
							("delay_tag" a(cumulative_damage_blast_to_armor))
						}
					else "light_tank"
						{delay 0.01
							("delay_tag" a(cumulative_damage_blast_to_armor))
						}
					else "medium_tank"
						{delay 0.01
							("delay_tag" a(cumulative_damage_blast_to_armor))
						}
					else "heavy_tank"
						{if not tagged "6_dam_b"
							{tags add "6_dam_b"}
						else tagged "6_dam_b"
							{tags add "6_dam_b_2"}
						}
						{delay 0.01
							("delay_tag" a(damage_counter_blast_add6))
						}
					}
				else min_energy 14 ;155 direct hit
					{if tagged "armored_car"
						{delay 0.01
							("delay_tag" a(cumulative_damage_blast_to_armor))
						}
					else "light_tank"
						{delay 0.01
							("delay_tag" a(cumulative_damage_blast_to_armor))
						}
					else "medium_tank"
						{if not tagged "6_dam_b"
							{tags add "6_dam_b"}
						else tagged "6_dam_b"
							{tags add "6_dam_b_2"}
						}
						{delay 0.01
							("delay_tag" a(damage_counter_blast_add6))
						}
					else "heavy_tank"
						{if not tagged "4_dam_b"
							{tags add "4_dam_b"}
						else tagged "4_dam_b"
							{tags add "4_dam_b_2"}
						}
						{delay 0.01
							("delay_tag" a(damage_counter_blast_add4))
						}
					}
				else min_energy 8.5 ;122
					{if tagged "armored_car"
						{delay 0.01
							("delay_tag" a(cumulative_damage_blast_to_armor))
						}
					else "light_tank"
						{delay 0.01
							("delay_tag" a(cumulative_damage_blast_to_armor))
						}
					else "medium_tank"
						{if not tagged "5_dam_b"
							{tags add "5_dam_b"}
						else tagged "5_dam_b"
							{tags add "5_dam_b_2"}
						}
						{delay 0.01
							("delay_tag" a(damage_counter_blast_add5))
						}
					else "heavy_tank"
						{if not tagged "3_dam_b"
							{tags add "3_dam_b"}
						else tagged "3_dam_b"
							{tags add "3_dam_b_2"}
						}
						{delay 0.01
							("delay_tag" a(damage_counter_blast_add3))
						}
					}
				else min_energy 7.5 ;85
					{if tagged "armored_car"
						{delay 0.01
							("delay_tag" a(cumulative_damage_blast_to_armor))
						}
					else "light_tank"
						{if not tagged "9_dam_b"
							{tags add "9_dam_b"}
						else tagged "9_dam_b"
							{tags add "9_dam_b_2"}
						}
						{delay 0.01
							("delay_tag" a(damage_counter_blast_add9))
						}
					else "medium_tank"
						{if not tagged "4_dam_b"
							{tags add "4_dam_b"}
						else tagged "4_dam_b"
							{tags add "4_dam_b_2"}
						}
						{delay 0.01
							("delay_tag" a(damage_counter_blast_add4))
						}
					else "heavy_tank"
						{if not tagged "1_dam_b"
							{tags add "1_dam_b"}
						else tagged "1_dam_b"
							{tags add "1_dam_b_2"}
						}
						{delay 0.01
							("delay_tag" a(damage_counter_blast_add1))
						}
					}
				else min_energy 5 ;75
					{if tagged "armored_car"
						{if not tagged "6_dam_b"
							{tags add "6_dam_b"}
						else tagged "6_dam_b"
							{tags add "6_dam_b_2"}
						}
						{delay 0.01
							("delay_tag" a(damage_counter_blast_add6))
						}
					else "light_tank"
						{if not tagged "4_dam_b"
							{tags add "4_dam_b"}
						else tagged "4_dam_b"
							{tags add "4_dam_b_2"}
						}
						{delay 0.01
							("delay_tag" a(damage_counter_blast_add4))
						}
					else "medium_tank"
						{if not tagged "2_dam_b"
							{tags add "2_dam_b"}
						else tagged "2_dam_b"
							{tags add "2_dam_b_2"}
						}
						{delay 0.01
							("delay_tag" a(damage_counter_blast_add2))
						}
					else "heavy_tank"
						{if not tagged "1_dam_b"
							{tags add "1_dam_b"}
						else tagged "1_dam_b"
							{tags add "1_dam_b_2"}
						}
						{delay 0.01
							("delay_tag" a(damage_counter_blast_add1))
						}
					}
				else min_energy 4 ;50mm
					{if tagged "armored_car"
						{if not tagged "3_dam_b"
							{tags add "3_dam_b"}
						else tagged "3_dam_b"
							{tags add "3_dam_b_2"}
						}
						{delay 0.01
							("delay_tag" a(damage_counter_blast_add3))
						}
					else "light_tank"
						{if not tagged "1_dam_b"
							{tags add "1_dam_b"}
						else tagged "1_dam_b"
							{tags add "1_dam_b_2"}
						}
						{delay 0.01
							("delay_tag" a(damage_counter_blast_add1))
						}
					else "medium_tank"
					else "heavy_tank"
					}
				else
					;{damage_report "turret" "<c(FF1F00)>Test<c(FFFFFF)>"}
				}
			}
		}
		{if hit_side back
			{if tagged "10_dam_b_turret_back"
				{tags add "10_dam_b"}
				{tags remove "10_dam_b_turret_back"}
			else tagged "9_dam_b_turret_back"
				{tags add "9_dam_b"}
				{tags remove "9_dam_b_turret_back"}
			else tagged "8_dam_b_turret_back"
				{tags add "8_dam_b"}
				{tags remove "8_dam_b_turret_back"}
			else tagged "7_dam_b_turret_back"
				{tags add "7_dam_b"}
				{tags remove "7_dam_b_turret_back"}
			else tagged "6_dam_b_turret_back"
				{tags add "6_dam_b"}
				{tags remove "6_dam_b_turret_back"}
			else tagged "5_dam_b_turret_back"
				{tags add "5_dam_b"}
				{tags remove "5_dam_b_turret_back"}
			else tagged "4_dam_b_turret_back"
				{tags add "4_dam_b"}
				{tags remove "4_dam_b_turret_back"}
			else tagged "3_dam_b_turret_back"
				{tags add "3_dam_b"}
				{tags remove "3_dam_b_turret_back"}
			else tagged "2_dam_b_turret_back"
				{tags add "2_dam_b"}
				{tags remove "2_dam_b_turret_back"}
			else tagged "1_dam_b_turret_back"
				{tags add "1_dam_b"}
				{tags remove "1_dam_b_turret_back"}
			}
			{if not tagged "blasted_turret_back"
				{tags add "blasted_turret_back"}
				{if min_energy 24 ;203 direct hit
					{if tagged "armored_car"
						{delay 0.01
							("delay_tag" a(cumulative_damage_blast_to_armor))
						}
					else "light_tank"
						{delay 0.01
							("delay_tag" a(cumulative_damage_blast_to_armor))
						}
					else "medium_tank"
						{delay 0.01
							("delay_tag" a(cumulative_damage_blast_to_armor))
						}
					else "heavy_tank"
						{delay 0.01
							("delay_tag" a(cumulative_damage_blast_to_armor))
						}
					}
				else min_energy 14 ;155 direct hit
					{if tagged "armored_car"
						{delay 0.01
							("delay_tag" a(cumulative_damage_blast_to_armor))
						}
					else "light_tank"
						{delay 0.01
							("delay_tag" a(cumulative_damage_blast_to_armor))
						}
					else "medium_tank"
						{delay 0.01
							("delay_tag" a(cumulative_damage_blast_to_armor))
						}
					else "heavy_tank"
						{if not tagged "6_dam_b"
							{tags add "6_dam_b"}
						else tagged "6_dam_b"
							{tags add "6_dam_b_2"}
						}
						{delay 0.01
							("delay_tag" a(damage_counter_blast_add6))
						}
					}
				else min_energy 8.5 ;122
					{if tagged "armored_car"
						{delay 0.01
							("delay_tag" a(cumulative_damage_blast_to_armor))
						}
					else "light_tank"
						{delay 0.01
							("delay_tag" a(cumulative_damage_blast_to_armor))
						}
					else "medium_tank"
						{if not tagged "8_dam_b"
							{tags add "8_dam_b"}
						else tagged "8_dam_b"
							{tags add "8_dam_b_2"}
						}
						{delay 0.01
							("delay_tag" a(damage_counter_blast_add8))
						}
					else "heavy_tank"
						{if not tagged "4_dam_b"
							{tags add "4_dam_b"}
						else tagged "4_dam_b"
							{tags add "4_dam_b_2"}
						}
						{delay 0.01
							("delay_tag" a(damage_counter_blast_add4))
						}
					}
				else min_energy 7.5 ;85
					{if tagged "armored_car"
						{delay 0.01
							("delay_tag" a(cumulative_damage_blast_to_armor))
						}
					else "light_tank"
						{delay 0.01
							("delay_tag" a(cumulative_damage_blast_to_armor))
						}
					else "medium_tank"
						{if not tagged "6_dam_b"
							{tags add "6_dam_b"}
						else tagged "6_dam_b"
							{tags add "6_dam_b_2"}
						}
						{delay 0.01
							("delay_tag" a(damage_counter_blast_add6))
						}
					else "heavy_tank"
						{if not tagged "2_dam_b"
							{tags add "2_dam_b"}
						else tagged "2_dam_b"
							{tags add "2_dam_b_2"}
						}
						{delay 0.01
							("delay_tag" a(damage_counter_blast_add2))
						}
					}
				else min_energy 5 ;75
					{if tagged "armored_car"
						{if not tagged "10_dam_b"
							{tags add "10_dam_b"}
						else tagged "10_dam_b"
							{tags add "10_dam_b_2"}
						}
						{delay 0.01
							("delay_tag" a(damage_counter_blast_add10))
						}
					else "light_tank"
						{if not tagged "8_dam_b"
							{tags add "8_dam_b"}
						else tagged "8_dam_b"
							{tags add "8_dam_b_2"}
						}
						{delay 0.01
							("delay_tag" a(damage_counter_blast_add8))
						}
					else "medium_tank"
						{if not tagged "4_dam_b"
							{tags add "4_dam_b"}
						else tagged "4_dam_b"
							{tags add "4_dam_b_2"}
						}
						{delay 0.01
							("delay_tag" a(damage_counter_blast_add4))
						}
					else "heavy_tank"
						{if not tagged "1_dam_b"
							{tags add "1_dam_b"}
						else tagged "1_dam_b"
							{tags add "1_dam_b_2"}
						}
						{delay 0.01
							("delay_tag" a(damage_counter_blast_add1))
						}
					}
				else min_energy 4 ;50mm
					{if tagged "armored_car"
						{if not tagged "5_dam_b"
							{tags add "5_dam_b"}
						else tagged "5_dam_b"
							{tags add "5_dam_b_2"}
						}
						{delay 0.01
							("delay_tag" a(damage_counter_blast_add5))
						}
					else "light_tank"
						{if not tagged "2_dam_b"
							{tags add "2_dam_b"}
						else tagged "2_dam_b"
							{tags add "2_dam_b_2"}
						}
						{delay 0.01
							("delay_tag" a(damage_counter_blast_add2))
						}
					else "medium_tank"
					else "heavy_tank"
					}
				else
					;{damage_report "turret" "<c(FF1F00)>Test<c(FFFFFF)>"}
				}
			}
		}
		{if hit_side left
			{if tagged "10_dam_b_turret_left"
				{tags add "10_dam_b"}
				{tags remove "10_dam_b_turret_left"}
			else tagged "9_dam_b_turret_left"
				{tags add "9_dam_b"}
				{tags remove "9_dam_b_turret_left"}
			else tagged "8_dam_b_turret_left"
				{tags add "8_dam_b"}
				{tags remove "8_dam_b_turret_left"}
			else tagged "7_dam_b_turret_left"
				{tags add "7_dam_b"}
				{tags remove "7_dam_b_turret_left"}
			else tagged "6_dam_b_turret_left"
				{tags add "6_dam_b"}
				{tags remove "6_dam_b_turret_left"}
			else tagged "5_dam_b_turret_left"
				{tags add "5_dam_b"}
				{tags remove "5_dam_b_turret_left"}
			else tagged "4_dam_b_turret_left"
				{tags add "4_dam_b"}
				{tags remove "4_dam_b_turret_left"}
			else tagged "3_dam_b_turret_left"
				{tags add "3_dam_b"}
				{tags remove "3_dam_b_turret_left"}
			else tagged "2_dam_b_turret_left"
				{tags add "2_dam_b"}
				{tags remove "2_dam_b_turret_left"}
			else tagged "1_dam_b_turret_left"
				{tags add "1_dam_b"}
				{tags remove "1_dam_b_turret_left"}
			}
			{if not tagged "blasted_turret_left"
				{tags add "blasted_turret_left"}
				{if min_energy 24 ;203 direct hit
					{if tagged "armored_car"
						{delay 0.01
							("delay_tag" a(cumulative_damage_blast_to_armor))
						}
					else "light_tank"
						{delay 0.01
							("delay_tag" a(cumulative_damage_blast_to_armor))
						}
					else "medium_tank"
						{delay 0.01
							("delay_tag" a(cumulative_damage_blast_to_armor))
						}
					else "heavy_tank"
						{if not tagged "10_dam_b"
							{tags add "10_dam_b"}
						else tagged "10_dam_b"
							{tags add "10_dam_b_2"}
						}
						{delay 0.01
							("delay_tag" a(damage_counter_blast_add10))
						}
					}
				else min_energy 14 ;155 direct hit
					{if tagged "armored_car"
						{delay 0.01
							("delay_tag" a(cumulative_damage_blast_to_armor))
						}
					else "light_tank"
						{delay 0.01
							("delay_tag" a(cumulative_damage_blast_to_armor))
						}
					else "medium_tank"
						{if not tagged "10_dam_b"
							{tags add "10_dam_b"}
						else tagged "10_dam_b"
							{tags add "10_dam_b_2"}
						}
						{delay 0.01
							("delay_tag" a(damage_counter_blast_add10))
						}
					else "heavy_tank"
						{if not tagged "5_dam_b"
							{tags add "5_dam_b"}
						else tagged "5_dam_b"
							{tags add "5_dam_b_2"}
						}
						{delay 0.01
							("delay_tag" a(damage_counter_blast_add5))
						}
					}
				else min_energy 8.5 ;122
					{if tagged "armored_car"
						{delay 0.01
							("delay_tag" a(cumulative_damage_blast_to_armor))
						}
					else "light_tank"
						{delay 0.01
							("delay_tag" a(cumulative_damage_blast_to_armor))
						}
					else "medium_tank"
						{if not tagged "5_dam_b"
							{tags add "5_dam_b"}
						else tagged "5_dam_b"
							{tags add "5_dam_b_2"}
						}
						{delay 0.01
							("delay_tag" a(damage_counter_blast_add5))
						}
					else "heavy_tank"
						{if not tagged "4_dam_b"
							{tags add "4_dam_b"}
						else tagged "4_dam_b"
							{tags add "4_dam_b_2"}
						}
						{delay 0.01
							("delay_tag" a(damage_counter_blast_add4))
						}
					}
				else min_energy 7.5 ;85
					{if tagged "armored_car"
						{delay 0.01
							("delay_tag" a(cumulative_damage_blast_to_armor))
						}
					else "light_tank"
						{if not tagged "10_dam_b"
							{tags add "10_dam_b"}
						else tagged "10_dam_b"
							{tags add "10_dam_b_2"}
						}
						{delay 0.01
							("delay_tag" a(damage_counter_blast_add10))
						}
					else "medium_tank"
						{if not tagged "3_dam_b"
							{tags add "3_dam_b"}
						else tagged "3_dam_b"
							{tags add "3_dam_b_2"}
						}
						{delay 0.01
							("delay_tag" a(damage_counter_blast_add3))
						}
					else "heavy_tank"
						{if not tagged "2_dam_b"
							{tags add "2_dam_b"}
						else tagged "2_dam_b"
							{tags add "2_dam_b_2"}
						}
						{delay 0.01
							("delay_tag" a(damage_counter_blast_add2))
						}
					}
				else min_energy 5 ;75
					{if tagged "armored_car"
						{if not tagged "10_dam_b"
							{tags add "10_dam_b"}
						else tagged "10_dam_b"
							{tags add "10_dam_b_2"}
						}
						{delay 0.01
							("delay_tag" a(damage_counter_blast_add10))
						}
					else "light_tank"
						{if not tagged "5_dam_b"
							{tags add "5_dam_b"}
						else tagged "5_dam_b"
							{tags add "5_dam_b_2"}
						}
						{delay 0.01
							("delay_tag" a(damage_counter_blast_add5))
						}
					else "medium_tank"
						{if not tagged "2_dam_b"
							{tags add "2_dam_b"}
						else tagged "2_dam_b"
							{tags add "2_dam_b_2"}
						}
						{delay 0.01
							("delay_tag" a(damage_counter_blast_add2))
						}
					else "heavy_tank"
						{if not tagged "1_dam_b"
							{tags add "1_dam_b"}
						else tagged "1_dam_b"
							{tags add "1_dam_b_2"}
						}
						{delay 0.01
							("delay_tag" a(damage_counter_blast_add1))
						}
					}
				else min_energy 4 ;50mm
					{if tagged "armored_car"
						{if not tagged "4_dam_b"
							{tags add "4_dam_b"}
						else tagged "4_dam_b"
							{tags add "4_dam_b_2"}
						}
						{delay 0.01
							("delay_tag" a(damage_counter_blast_add4))
						}
					else "light_tank"
						{if not tagged "1_dam_b"
							{tags add "1_dam_b"}
						else tagged "1_dam_b"
							{tags add "1_dam_b_2"}
						}
						{delay 0.01
							("delay_tag" a(damage_counter_blast_add1))
						}
					else "medium_tank"
					else "heavy_tank"
					}
				else
					;{damage_report "turret" "<c(FF1F00)>Test<c(FFFFFF)>"}
				}
			}
		}
		{if hit_side right
			{if tagged "10_dam_b_turret_right"
				{tags add "10_dam_b"}
				{tags remove "10_dam_b_turret_right"}
			else tagged "9_dam_b_turret_right"
				{tags add "9_dam_b"}
				{tags remove "9_dam_b_turret_right"}
			else tagged "8_dam_b_turret_right"
				{tags add "8_dam_b"}
				{tags remove "8_dam_b_turret_right"}
			else tagged "7_dam_b_turret_right"
				{tags add "7_dam_b"}
				{tags remove "7_dam_b_turret_right"}
			else tagged "6_dam_b_turret_right"
				{tags add "6_dam_b"}
				{tags remove "6_dam_b_turret_right"}
			else tagged "5_dam_b_turret_right"
				{tags add "5_dam_b"}
				{tags remove "5_dam_b_turret_right"}
			else tagged "4_dam_b_turret_right"
				{tags add "4_dam_b"}
				{tags remove "4_dam_b_turret_right"}
			else tagged "3_dam_b_turret_right"
				{tags add "3_dam_b"}
				{tags remove "3_dam_b_turret_right"}
			else tagged "2_dam_b_turret_right"
				{tags add "2_dam_b"}
				{tags remove "2_dam_b_turret_right"}
			else tagged "1_dam_b_turret_right"
				{tags add "1_dam_b"}
				{tags remove "1_dam_b_turret_right"}
			}
			{if not tagged "blasted_turret_right"
				{tags add "blasted_turret_right"}
				{if min_energy 24 ;203 direct hit
					{if tagged "armored_car"
						{delay 0.01
							("delay_tag" a(cumulative_damage_blast_to_armor))
						}
					else "light_tank"
						{delay 0.01
							("delay_tag" a(cumulative_damage_blast_to_armor))
						}
					else "medium_tank"
						{delay 0.01
							("delay_tag" a(cumulative_damage_blast_to_armor))
						}
					else "heavy_tank"
						{if not tagged "10_dam_b"
							{tags add "10_dam_b"}
						else tagged "10_dam_b"
							{tags add "10_dam_b_2"}
						}
						{delay 0.01
							("delay_tag" a(damage_counter_blast_add10))
						}
					}
				else min_energy 14 ;155 direct hit
					{if tagged "armored_car"
						{delay 0.01
							("delay_tag" a(cumulative_damage_blast_to_armor))
						}
					else "light_tank"
						{delay 0.01
							("delay_tag" a(cumulative_damage_blast_to_armor))
						}
					else "medium_tank"
						{if not tagged "10_dam_b"
							{tags add "10_dam_b"}
						else tagged "10_dam_b"
							{tags add "10_dam_b_2"}
						}
						{delay 0.01
							("delay_tag" a(damage_counter_blast_add10))
						}
					else "heavy_tank"
						{if not tagged "5_dam_b"
							{tags add "5_dam_b"}
						else tagged "5_dam_b"
							{tags add "5_dam_b_2"}
						}
						{delay 0.01
							("delay_tag" a(damage_counter_blast_add5))
						}
					}
				else min_energy 8.5 ;122
					{if tagged "armored_car"
						{delay 0.01
							("delay_tag" a(cumulative_damage_blast_to_armor))
						}
					else "light_tank"
						{delay 0.01
							("delay_tag" a(cumulative_damage_blast_to_armor))
						}
					else "medium_tank"
						{if not tagged "5_dam_b"
							{tags add "5_dam_b"}
						else tagged "5_dam_b"
							{tags add "5_dam_b_2"}
						}
						{delay 0.01
							("delay_tag" a(damage_counter_blast_add5))
						}
					else "heavy_tank"
						{if not tagged "4_dam_b"
							{tags add "4_dam_b"}
						else tagged "4_dam_b"
							{tags add "4_dam_b_2"}
						}
						{delay 0.01
							("delay_tag" a(damage_counter_blast_add4))
						}
					}
				else min_energy 7.5 ;85
					{if tagged "armored_car"
						{delay 0.01
							("delay_tag" a(cumulative_damage_blast_to_armor))
						}
					else "light_tank"
						{if not tagged "10_dam_b"
							{tags add "10_dam_b"}
						else tagged "10_dam_b"
							{tags add "10_dam_b_2"}
						}
						{delay 0.01
							("delay_tag" a(damage_counter_blast_add10))
						}
					else "medium_tank"
						{if not tagged "3_dam_b"
							{tags add "3_dam_b"}
						else tagged "3_dam_b"
							{tags add "3_dam_b_2"}
						}
						{delay 0.01
							("delay_tag" a(damage_counter_blast_add3))
						}
					else "heavy_tank"
						{if not tagged "2_dam_b"
							{tags add "2_dam_b"}
						else tagged "2_dam_b"
							{tags add "2_dam_b_2"}
						}
						{delay 0.01
							("delay_tag" a(damage_counter_blast_add2))
						}
					}
				else min_energy 5 ;75
					{if tagged "armored_car"
						{if not tagged "10_dam_b"
							{tags add "10_dam_b"}
						else tagged "10_dam_b"
							{tags add "10_dam_b_2"}
						}
						{delay 0.01
							("delay_tag" a(damage_counter_blast_add10))
						}
					else "light_tank"
						{if not tagged "5_dam_b"
							{tags add "5_dam_b"}
						else tagged "5_dam_b"
							{tags add "5_dam_b_2"}
						}
						{delay 0.01
							("delay_tag" a(damage_counter_blast_add5))
						}
					else "medium_tank"
						{if not tagged "2_dam_b"
							{tags add "2_dam_b"}
						else tagged "2_dam_b"
							{tags add "2_dam_b_2"}
						}
						{delay 0.01
							("delay_tag" a(damage_counter_blast_add2))
						}
					else "heavy_tank"
						{if not tagged "1_dam_b"
							{tags add "1_dam_b"}
						else tagged "1_dam_b"
							{tags add "1_dam_b_2"}
						}
						{delay 0.01
							("delay_tag" a(damage_counter_blast_add1))
						}
					}
				else min_energy 4 ;50mm
					{if tagged "armored_car"
						{if not tagged "4_dam_b"
							{tags add "4_dam_b"}
						else tagged "4_dam_b"
							{tags add "4_dam_b_2"}
						}
						{delay 0.01
							("delay_tag" a(damage_counter_blast_add4))
						}
					else "light_tank"
						{if not tagged "1_dam_b"
							{tags add "1_dam_b"}
						else tagged "1_dam_b"
							{tags add "1_dam_b_2"}
						}
						{delay 0.01
							("delay_tag" a(damage_counter_blast_add1))
						}
					else "medium_tank"
					else "heavy_tank"
					}
				else
					;{damage_report "turret" "<c(FF1F00)>Test<c(FFFFFF)>"}
				}
			}
		}
		{if hit_side top
			{if tagged "10_dam_b_turret_top"
				{tags add "10_dam_b"}
				{tags remove "10_dam_b_turret_top"}
			else tagged "9_dam_b_turret_top"
				{tags add "9_dam_b"}
				{tags remove "9_dam_b_turret_top"}
			else tagged "8_dam_b_turret_top"
				{tags add "8_dam_b"}
				{tags remove "8_dam_b_turret_top"}
			else tagged "7_dam_b_turret_top"
				{tags add "7_dam_b"}
				{tags remove "7_dam_b_turret_top"}
			else tagged "6_dam_b_turret_top"
				{tags add "6_dam_b"}
				{tags remove "6_dam_b_turret_top"}
			else tagged "5_dam_b_turret_top"
				{tags add "5_dam_b"}
				{tags remove "5_dam_b_turret_top"}
			else tagged "4_dam_b_turret_top"
				{tags add "4_dam_b"}
				{tags remove "4_dam_b_turret_top"}
			else tagged "3_dam_b_turret_top"
				{tags add "3_dam_b"}
				{tags remove "3_dam_b_turret_top"}
			else tagged "2_dam_b_turret_top"
				{tags add "2_dam_b"}
				{tags remove "2_dam_b_turret_top"}
			else tagged "1_dam_b_turret_top"
				{tags add "1_dam_b"}
				{tags remove "1_dam_b_turret_top"}
			}
			{if not tagged "blasted_turret_top"
				{tags add "blasted_turret_top"}
				{if min_energy 24 ;203 direct hit
					{if tagged "armored_car"
						{delay 0.01
							("delay_tag" a(cumulative_damage_blast_to_armor))
						}
					else "light_tank"
						{delay 0.01
							("delay_tag" a(cumulative_damage_blast_to_armor))
						}
					else "medium_tank"
						{delay 0.01
							("delay_tag" a(cumulative_damage_blast_to_armor))
						}
					else "heavy_tank"
						{delay 0.01
							("delay_tag" a(cumulative_damage_blast_to_armor))
						}
					}
				else min_energy 14 ;155 direct hit
					{if tagged "armored_car"
						{delay 0.01
							("delay_tag" a(cumulative_damage_blast_to_armor))
						}
					else "light_tank"
						{delay 0.01
							("delay_tag" a(cumulative_damage_blast_to_armor))
						}
					else "medium_tank"
						{delay 0.01
							("delay_tag" a(cumulative_damage_blast_to_armor))
						}
					else "heavy_tank"
						{if not tagged "6_dam_b"
							{tags add "6_dam_b"}
						else tagged "6_dam_b"
							{tags add "6_dam_b_2"}
						}
						{delay 0.01
							("delay_tag" a(damage_counter_blast_add6))
						}
					}
				else min_energy 8.5 ;122
					{if tagged "armored_car"
						{delay 0.01
							("delay_tag" a(cumulative_damage_blast_to_armor))
						}
					else "light_tank"
						{delay 0.01
							("delay_tag" a(cumulative_damage_blast_to_armor))
						}
					else "medium_tank"
						{if not tagged "8_dam_b"
							{tags add "8_dam_b"}
						else tagged "8_dam_b"
							{tags add "8_dam_b_2"}
						}
						{delay 0.01
							("delay_tag" a(damage_counter_blast_add8))
						}
					else "heavy_tank"
						{if not tagged "4_dam_b"
							{tags add "4_dam_b"}
						else tagged "4_dam_b"
							{tags add "4_dam_b_2"}
						}
						{delay 0.01
							("delay_tag" a(damage_counter_blast_add4))
						}
					}
				else min_energy 7.5 ;85
					{if tagged "armored_car"
						{delay 0.01
							("delay_tag" a(cumulative_damage_blast_to_armor))
						}
					else "light_tank"
						{delay 0.01
							("delay_tag" a(cumulative_damage_blast_to_armor))
						}
					else "medium_tank"
						{if not tagged "6_dam_b"
							{tags add "6_dam_b"}
						else tagged "6_dam_b"
							{tags add "6_dam_b_2"}
						}
						{delay 0.01
							("delay_tag" a(damage_counter_blast_add6))
						}
					else "heavy_tank"
						{if not tagged "2_dam_b"
							{tags add "2_dam_b"}
						else tagged "2_dam_b"
							{tags add "2_dam_b_2"}
						}
						{delay 0.01
							("delay_tag" a(damage_counter_blast_add2))
						}
					}
				else min_energy 5 ;75
					{if tagged "armored_car"
						{if not tagged "10_dam_b"
							{tags add "10_dam_b"}
						else tagged "10_dam_b"
							{tags add "10_dam_b_2"}
						}
						{delay 0.01
							("delay_tag" a(damage_counter_blast_add10))
						}
					else "light_tank"
						{if not tagged "8_dam_b"
							{tags add "8_dam_b"}
						else tagged "8_dam_b"
							{tags add "8_dam_b_2"}
						}
						{delay 0.01
							("delay_tag" a(damage_counter_blast_add8))
						}
					else "medium_tank"
						{if not tagged "4_dam_b"
							{tags add "4_dam_b"}
						else tagged "4_dam_b"
							{tags add "4_dam_b_2"}
						}
						{delay 0.01
							("delay_tag" a(damage_counter_blast_add4))
						}
					else "heavy_tank"
						{if not tagged "1_dam_b"
							{tags add "1_dam_b"}
						else tagged "1_dam_b"
							{tags add "1_dam_b_2"}
						}
						{delay 0.01
							("delay_tag" a(damage_counter_blast_add1))
						}
					}
				else min_energy 4 ;50mm
					{if tagged "armored_car"
						{if not tagged "5_dam_b"
							{tags add "5_dam_b"}
						else tagged "5_dam_b"
							{tags add "5_dam_b_2"}
						}
						{delay 0.01
							("delay_tag" a(damage_counter_blast_add5))
						}
					else "light_tank"
						{if not tagged "2_dam_b"
							{tags add "2_dam_b"}
						else tagged "2_dam_b"
							{tags add "2_dam_b_2"}
						}
						{delay 0.01
							("delay_tag" a(damage_counter_blast_add2))
						}
					else "medium_tank"
					else "heavy_tank"
					}
				else
					;{damage_report "turret" "<c(FF1F00)>Test<c(FFFFFF)>"}
				}
			}
		}
	}
	{if volume "engine"
		{if hit_side front
			{if tagged "10_dam_b_engine_front"
				{tags add "10_dam_b"}
				{tags remove "10_dam_b_engine_front"}
			else tagged "9_dam_b_engine_front"
				{tags add "9_dam_b"}
				{tags remove "9_dam_b_engine_front"}
			else tagged "8_dam_b_engine_front"
				{tags add "8_dam_b"}
				{tags remove "8_dam_b_engine_front"}
			else tagged "7_dam_b_engine_front"
				{tags add "7_dam_b"}
				{tags remove "7_dam_b_engine_front"}
			else tagged "6_dam_b_engine_front"
				{tags add "6_dam_b"}
				{tags remove "6_dam_b_engine_front"}
			else tagged "5_dam_b_engine_front"
				{tags add "5_dam_b"}
				{tags remove "5_dam_b_engine_front"}
			else tagged "4_dam_b_engine_front"
				{tags add "4_dam_b"}
				{tags remove "4_dam_b_engine_front"}
			else tagged "3_dam_b_engine_front"
				{tags add "3_dam_b"}
				{tags remove "3_dam_b_engine_front"}
			else tagged "2_dam_b_engine_front"
				{tags add "2_dam_b"}
				{tags remove "2_dam_b_engine_front"}
			else tagged "1_dam_b_engine_front"
				{tags add "1_dam_b"}
				{tags remove "1_dam_b_engine_front"}
			}
			{if not tagged "blasted_engine_front"
				{tags add "blasted_engine_front"}
				{if min_energy 24 ;203 direct hit
					{if tagged "armored_car"
						{delay 0.01
							("delay_tag" a(cumulative_damage_blast_to_armor))
						}
					else "light_tank"
						{delay 0.01
							("delay_tag" a(cumulative_damage_blast_to_armor))
						}
					else "medium_tank"
						{delay 0.01
							("delay_tag" a(cumulative_damage_blast_to_armor))
						}
					else "heavy_tank"
						{if not tagged "6_dam_b"
							{tags add "6_dam_b"}
						else tagged "6_dam_b"
							{tags add "6_dam_b_2"}
						}
						{delay 0.01
							("delay_tag" a(damage_counter_blast_add6))
						}
					}
				else min_energy 14 ;155 direct hit
					{if tagged "armored_car"
						{delay 0.01
							("delay_tag" a(cumulative_damage_blast_to_armor))
						}
					else "light_tank"
						{delay 0.01
							("delay_tag" a(cumulative_damage_blast_to_armor))
						}
					else "medium_tank"
						{if not tagged "6_dam_b"
							{tags add "6_dam_b"}
						else tagged "6_dam_b"
							{tags add "6_dam_b_2"}
						}
						{delay 0.01
							("delay_tag" a(damage_counter_blast_add6))
						}
					else "heavy_tank"
						{if not tagged "4_dam_b"
							{tags add "4_dam_b"}
						else tagged "4_dam_b"
							{tags add "4_dam_b_2"}
						}
						{delay 0.01
							("delay_tag" a(damage_counter_blast_add4))
						}
					}
				else min_energy 8.5 ;122
					{if tagged "armored_car"
						{delay 0.01
							("delay_tag" a(cumulative_damage_blast_to_armor))
						}
					else "light_tank"
						{delay 0.01
							("delay_tag" a(cumulative_damage_blast_to_armor))
						}
					else "medium_tank"
						{if not tagged "5_dam_b"
							{tags add "5_dam_b"}
						else tagged "5_dam_b"
							{tags add "5_dam_b_2"}
						}
						{delay 0.01
							("delay_tag" a(damage_counter_blast_add5))
						}
					else "heavy_tank"
						{if not tagged "3_dam_b"
							{tags add "3_dam_b"}
						else tagged "3_dam_b"
							{tags add "3_dam_b_2"}
						}
						{delay 0.01
							("delay_tag" a(damage_counter_blast_add3))
						}
					}
				else min_energy 7.5 ;85
					{if tagged "armored_car"
						{delay 0.01
							("delay_tag" a(cumulative_damage_blast_to_armor))
						}
					else "light_tank"
						{if not tagged "9_dam_b"
							{tags add "9_dam_b"}
						else tagged "9_dam_b"
							{tags add "9_dam_b_2"}
						}
						{delay 0.01
							("delay_tag" a(damage_counter_blast_add9))
						}
					else "medium_tank"
						{if not tagged "4_dam_b"
							{tags add "4_dam_b"}
						else tagged "4_dam_b"
							{tags add "4_dam_b_2"}
						}
						{delay 0.01
							("delay_tag" a(damage_counter_blast_add4))
						}
					else "heavy_tank"
						{if not tagged "1_dam_b"
							{tags add "1_dam_b"}
						else tagged "1_dam_b"
							{tags add "1_dam_b_2"}
						}
						{delay 0.01
							("delay_tag" a(damage_counter_blast_add1))
						}
					}
				else min_energy 5 ;75
					{if tagged "armored_car"
						{if not tagged "6_dam_b"
							{tags add "6_dam_b"}
						else tagged "6_dam_b"
							{tags add "6_dam_b_2"}
						}
						{delay 0.01
							("delay_tag" a(damage_counter_blast_add6))
						}
					else "light_tank"
						{if not tagged "4_dam_b"
							{tags add "4_dam_b"}
						else tagged "4_dam_b"
							{tags add "4_dam_b_2"}
						}
						{delay 0.01
							("delay_tag" a(damage_counter_blast_add4))
						}
					else "medium_tank"
						{if not tagged "2_dam_b"
							{tags add "2_dam_b"}
						else tagged "2_dam_b"
							{tags add "2_dam_b_2"}
						}
						{delay 0.01
							("delay_tag" a(damage_counter_blast_add2))
						}
					else "heavy_tank"
						{if not tagged "1_dam_b"
							{tags add "1_dam_b"}
						else tagged "1_dam_b"
							{tags add "1_dam_b_2"}
						}
						{delay 0.01
							("delay_tag" a(damage_counter_blast_add1))
						}
					}
				else min_energy 4 ;50mm
					{if tagged "armored_car"
						{if not tagged "3_dam_b"
							{tags add "3_dam_b"}
						else tagged "3_dam_b"
							{tags add "3_dam_b_2"}
						}
						{delay 0.01
							("delay_tag" a(damage_counter_blast_add3))
						}
					else "light_tank"
						{if not tagged "1_dam_b"
							{tags add "1_dam_b"}
						else tagged "1_dam_b"
							{tags add "1_dam_b_2"}
						}
						{delay 0.01
							("delay_tag" a(damage_counter_blast_add1))
						}
					else "medium_tank"
					else "heavy_tank"
					}
				else
					;{damage_report "engine" "<c(FF1F00)>Test<c(FFFFFF)>"}
				}
			}
		}
		{if hit_side back
			{if tagged "10_dam_b_engine_back"
				{tags add "10_dam_b"}
				{tags remove "10_dam_b_engine_back"}
			else tagged "9_dam_b_engine_back"
				{tags add "9_dam_b"}
				{tags remove "9_dam_b_engine_back"}
			else tagged "8_dam_b_engine_back"
				{tags add "8_dam_b"}
				{tags remove "8_dam_b_engine_back"}
			else tagged "7_dam_b_engine_back"
				{tags add "7_dam_b"}
				{tags remove "7_dam_b_engine_back"}
			else tagged "6_dam_b_engine_back"
				{tags add "6_dam_b"}
				{tags remove "6_dam_b_engine_back"}
			else tagged "5_dam_b_engine_back"
				{tags add "5_dam_b"}
				{tags remove "5_dam_b_engine_back"}
			else tagged "4_dam_b_engine_back"
				{tags add "4_dam_b"}
				{tags remove "4_dam_b_engine_back"}
			else tagged "3_dam_b_engine_back"
				{tags add "3_dam_b"}
				{tags remove "3_dam_b_engine_back"}
			else tagged "2_dam_b_engine_back"
				{tags add "2_dam_b"}
				{tags remove "2_dam_b_engine_back"}
			else tagged "1_dam_b_engine_back"
				{tags add "1_dam_b"}
				{tags remove "1_dam_b_engine_back"}
			}
			{if not tagged "blasted_engine_back"
				{tags add "blasted_engine_back"}
				{if min_energy 24 ;203 direct hit
					{if tagged "armored_car"
						{delay 0.01
							("delay_tag" a(cumulative_damage_blast_to_armor))
						}
					else "light_tank"
						{delay 0.01
							("delay_tag" a(cumulative_damage_blast_to_armor))
						}
					else "medium_tank"
						{delay 0.01
							("delay_tag" a(cumulative_damage_blast_to_armor))
						}
					else "heavy_tank"
						{delay 0.01
							("delay_tag" a(cumulative_damage_blast_to_armor))
						}
					}
				else min_energy 14 ;155 direct hit
					{if tagged "armored_car"
						{delay 0.01
							("delay_tag" a(cumulative_damage_blast_to_armor))
						}
					else "light_tank"
						{delay 0.01
							("delay_tag" a(cumulative_damage_blast_to_armor))
						}
					else "medium_tank"
						{delay 0.01
							("delay_tag" a(cumulative_damage_blast_to_armor))
						}
					else "heavy_tank"
						{if not tagged "6_dam_b"
							{tags add "6_dam_b"}
						else tagged "6_dam_b"
							{tags add "6_dam_b_2"}
						}
						{delay 0.01
							("delay_tag" a(damage_counter_blast_add6))
						}
					}
				else min_energy 8.5 ;122
					{if tagged "armored_car"
						{delay 0.01
							("delay_tag" a(cumulative_damage_blast_to_armor))
						}
					else "light_tank"
						{delay 0.01
							("delay_tag" a(cumulative_damage_blast_to_armor))
						}
					else "medium_tank"
						{if not tagged "8_dam_b"
							{tags add "8_dam_b"}
						else tagged "8_dam_b"
							{tags add "8_dam_b_2"}
						}
						{delay 0.01
							("delay_tag" a(damage_counter_blast_add8))
						}
					else "heavy_tank"
						{if not tagged "4_dam_b"
							{tags add "4_dam_b"}
						else tagged "4_dam_b"
							{tags add "4_dam_b_2"}
						}
						{delay 0.01
							("delay_tag" a(damage_counter_blast_add4))
						}
					}
				else min_energy 7.5 ;85
					{if tagged "armored_car"
						{delay 0.01
							("delay_tag" a(cumulative_damage_blast_to_armor))
						}
					else "light_tank"
						{delay 0.01
							("delay_tag" a(cumulative_damage_blast_to_armor))
						}
					else "medium_tank"
						{if not tagged "6_dam_b"
							{tags add "6_dam_b"}
						else tagged "6_dam_b"
							{tags add "6_dam_b_2"}
						}
						{delay 0.01
							("delay_tag" a(damage_counter_blast_add6))
						}
					else "heavy_tank"
						{if not tagged "2_dam_b"
							{tags add "2_dam_b"}
						else tagged "2_dam_b"
							{tags add "2_dam_b_2"}
						}
						{delay 0.01
							("delay_tag" a(damage_counter_blast_add2))
						}
					}
				else min_energy 5 ;75
					{if tagged "armored_car"
						{if not tagged "10_dam_b"
							{tags add "10_dam_b"}
						else tagged "10_dam_b"
							{tags add "10_dam_b_2"}
						}
						{delay 0.01
							("delay_tag" a(damage_counter_blast_add10))
						}
					else "light_tank"
						{if not tagged "8_dam_b"
							{tags add "8_dam_b"}
						else tagged "8_dam_b"
							{tags add "8_dam_b_2"}
						}
						{delay 0.01
							("delay_tag" a(damage_counter_blast_add8))
						}
					else "medium_tank"
						{if not tagged "4_dam_b"
							{tags add "4_dam_b"}
						else tagged "4_dam_b"
							{tags add "4_dam_b_2"}
						}
						{delay 0.01
							("delay_tag" a(damage_counter_blast_add4))
						}
					else "heavy_tank"
						{if not tagged "1_dam_b"
							{tags add "1_dam_b"}
						else tagged "1_dam_b"
							{tags add "1_dam_b_2"}
						}
						{delay 0.01
							("delay_tag" a(damage_counter_blast_add1))
						}
					}
				else min_energy 4 ;50mm
					{if tagged "armored_car"
						{if not tagged "5_dam_b"
							{tags add "5_dam_b"}
						else tagged "5_dam_b"
							{tags add "5_dam_b_2"}
						}
						{delay 0.01
							("delay_tag" a(damage_counter_blast_add5))
						}
					else "light_tank"
						{if not tagged "2_dam_b"
							{tags add "2_dam_b"}
						else tagged "2_dam_b"
							{tags add "2_dam_b_2"}
						}
						{delay 0.01
							("delay_tag" a(damage_counter_blast_add2))
						}
					else "medium_tank"
					else "heavy_tank"
					}
				else
					;{damage_report "engine" "<c(FF1F00)>Test<c(FFFFFF)>"}
				}
			}
		}
		{if hit_side left
			{if tagged "10_dam_b_engine_left"
				{tags add "10_dam_b"}
				{tags remove "10_dam_b_engine_left"}
			else tagged "9_dam_b_engine_left"
				{tags add "9_dam_b"}
				{tags remove "9_dam_b_engine_left"}
			else tagged "8_dam_b_engine_left"
				{tags add "8_dam_b"}
				{tags remove "8_dam_b_engine_left"}
			else tagged "7_dam_b_engine_left"
				{tags add "7_dam_b"}
				{tags remove "7_dam_b_engine_left"}
			else tagged "6_dam_b_engine_left"
				{tags add "6_dam_b"}
				{tags remove "6_dam_b_engine_left"}
			else tagged "5_dam_b_engine_left"
				{tags add "5_dam_b"}
				{tags remove "5_dam_b_engine_left"}
			else tagged "4_dam_b_engine_left"
				{tags add "4_dam_b"}
				{tags remove "4_dam_b_engine_left"}
			else tagged "3_dam_b_engine_left"
				{tags add "3_dam_b"}
				{tags remove "3_dam_b_engine_left"}
			else tagged "2_dam_b_engine_left"
				{tags add "2_dam_b"}
				{tags remove "2_dam_b_engine_left"}
			else tagged "1_dam_b_engine_left"
				{tags add "1_dam_b"}
				{tags remove "1_dam_b_engine_left"}
			}
			{if not tagged "blasted_engine_left"
				{tags add "blasted_engine_left"}
				{if min_energy 24 ;203 direct hit
					{if tagged "armored_car"
						{delay 0.01
							("delay_tag" a(cumulative_damage_blast_to_armor))
						}
					else "light_tank"
						{delay 0.01
							("delay_tag" a(cumulative_damage_blast_to_armor))
						}
					else "medium_tank"
						{delay 0.01
							("delay_tag" a(cumulative_damage_blast_to_armor))
						}
					else "heavy_tank"
						{if not tagged "10_dam_b"
							{tags add "10_dam_b"}
						else tagged "10_dam_b"
							{tags add "10_dam_b_2"}
						}
						{delay 0.01
							("delay_tag" a(damage_counter_blast_add10))
						}
					}
				else min_energy 14 ;155 direct hit
					{if tagged "armored_car"
						{delay 0.01
							("delay_tag" a(cumulative_damage_blast_to_armor))
						}
					else "light_tank"
						{delay 0.01
							("delay_tag" a(cumulative_damage_blast_to_armor))
						}
					else "medium_tank"
						{if not tagged "10_dam_b"
							{tags add "10_dam_b"}
						else tagged "10_dam_b"
							{tags add "10_dam_b_2"}
						}
						{delay 0.01
							("delay_tag" a(damage_counter_blast_add10))
						}
					else "heavy_tank"
						{if not tagged "5_dam_b"
							{tags add "5_dam_b"}
						else tagged "5_dam_b"
							{tags add "5_dam_b_2"}
						}
						{delay 0.01
							("delay_tag" a(damage_counter_blast_add5))
						}
					}
				else min_energy 8.5 ;122
					{if tagged "armored_car"
						{delay 0.01
							("delay_tag" a(cumulative_damage_blast_to_armor))
						}
					else "light_tank"
						{delay 0.01
							("delay_tag" a(cumulative_damage_blast_to_armor))
						}
					else "medium_tank"
						{if not tagged "5_dam_b"
							{tags add "5_dam_b"}
						else tagged "5_dam_b"
							{tags add "5_dam_b_2"}
						}
						{delay 0.01
							("delay_tag" a(damage_counter_blast_add5))
						}
					else "heavy_tank"
						{if not tagged "4_dam_b"
							{tags add "4_dam_b"}
						else tagged "4_dam_b"
							{tags add "4_dam_b_2"}
						}
						{delay 0.01
							("delay_tag" a(damage_counter_blast_add4))
						}
					}
				else min_energy 7.5 ;85
					{if tagged "armored_car"
						{delay 0.01
							("delay_tag" a(cumulative_damage_blast_to_armor))
						}
					else "light_tank"
						{if not tagged "10_dam_b"
							{tags add "10_dam_b"}
						else tagged "10_dam_b"
							{tags add "10_dam_b_2"}
						}
						{delay 0.01
							("delay_tag" a(damage_counter_blast_add10))
						}
					else "medium_tank"
						{if not tagged "3_dam_b"
							{tags add "3_dam_b"}
						else tagged "3_dam_b"
							{tags add "3_dam_b_2"}
						}
						{delay 0.01
							("delay_tag" a(damage_counter_blast_add3))
						}
					else "heavy_tank"
						{if not tagged "2_dam_b"
							{tags add "2_dam_b"}
						else tagged "2_dam_b"
							{tags add "2_dam_b_2"}
						}
						{delay 0.01
							("delay_tag" a(damage_counter_blast_add2))
						}
					}
				else min_energy 5 ;75
					{if tagged "armored_car"
						{if not tagged "10_dam_b"
							{tags add "10_dam_b"}
						else tagged "10_dam_b"
							{tags add "10_dam_b_2"}
						}
						{delay 0.01
							("delay_tag" a(damage_counter_blast_add10))
						}
					else "light_tank"
						{if not tagged "5_dam_b"
							{tags add "5_dam_b"}
						else tagged "5_dam_b"
							{tags add "5_dam_b_2"}
						}
						{delay 0.01
							("delay_tag" a(damage_counter_blast_add5))
						}
					else "medium_tank"
						{if not tagged "2_dam_b"
							{tags add "2_dam_b"}
						else tagged "2_dam_b"
							{tags add "2_dam_b_2"}
						}
						{delay 0.01
							("delay_tag" a(damage_counter_blast_add2))
						}
					else "heavy_tank"
						{if not tagged "1_dam_b"
							{tags add "1_dam_b"}
						else tagged "1_dam_b"
							{tags add "1_dam_b_2"}
						}
						{delay 0.01
							("delay_tag" a(damage_counter_blast_add1))
						}
					}
				else min_energy 4 ;50mm
					{if tagged "armored_car"
						{if not tagged "4_dam_b"
							{tags add "4_dam_b"}
						else tagged "4_dam_b"
							{tags add "4_dam_b_2"}
						}
						{delay 0.01
							("delay_tag" a(damage_counter_blast_add4))
						}
					else "light_tank"
						{if not tagged "1_dam_b"
							{tags add "1_dam_b"}
						else tagged "1_dam_b"
							{tags add "1_dam_b_2"}
						}
						{delay 0.01
							("delay_tag" a(damage_counter_blast_add1))
						}
					else "medium_tank"
					else "heavy_tank"
					}
				else
					;{damage_report "engine" "<c(FF1F00)>Test<c(FFFFFF)>"}
				}
			}
		}
		{if hit_side right
			{if tagged "10_dam_b_engine_right"
				{tags add "10_dam_b"}
				{tags remove "10_dam_b_engine_right"}
			else tagged "9_dam_b_engine_right"
				{tags add "9_dam_b"}
				{tags remove "9_dam_b_engine_right"}
			else tagged "8_dam_b_engine_right"
				{tags add "8_dam_b"}
				{tags remove "8_dam_b_engine_right"}
			else tagged "7_dam_b_engine_right"
				{tags add "7_dam_b"}
				{tags remove "7_dam_b_engine_right"}
			else tagged "6_dam_b_engine_right"
				{tags add "6_dam_b"}
				{tags remove "6_dam_b_engine_right"}
			else tagged "5_dam_b_engine_right"
				{tags add "5_dam_b"}
				{tags remove "5_dam_b_engine_right"}
			else tagged "4_dam_b_engine_right"
				{tags add "4_dam_b"}
				{tags remove "4_dam_b_engine_right"}
			else tagged "3_dam_b_engine_right"
				{tags add "3_dam_b"}
				{tags remove "3_dam_b_engine_right"}
			else tagged "2_dam_b_engine_right"
				{tags add "2_dam_b"}
				{tags remove "2_dam_b_engine_right"}
			else tagged "1_dam_b_engine_right"
				{tags add "1_dam_b"}
				{tags remove "1_dam_b_engine_right"}
			}
			{if not tagged "blasted_engine_right"
				{tags add "blasted_engine_right"}
				{if min_energy 24 ;203 direct hit
					{if tagged "armored_car"
						{delay 0.01
							("delay_tag" a(cumulative_damage_blast_to_armor))
						}
					else "light_tank"
						{delay 0.01
							("delay_tag" a(cumulative_damage_blast_to_armor))
						}
					else "medium_tank"
						{delay 0.01
							("delay_tag" a(cumulative_damage_blast_to_armor))
						}
					else "heavy_tank"
						{if not tagged "10_dam_b"
							{tags add "10_dam_b"}
						else tagged "10_dam_b"
							{tags add "10_dam_b_2"}
						}
						{delay 0.01
							("delay_tag" a(damage_counter_blast_add10))
						}
					}
				else min_energy 14 ;155 direct hit
					{if tagged "armored_car"
						{delay 0.01
							("delay_tag" a(cumulative_damage_blast_to_armor))
						}
					else "light_tank"
						{delay 0.01
							("delay_tag" a(cumulative_damage_blast_to_armor))
						}
					else "medium_tank"
						{if not tagged "10_dam_b"
							{tags add "10_dam_b"}
						else tagged "10_dam_b"
							{tags add "10_dam_b_2"}
						}
						{delay 0.01
							("delay_tag" a(damage_counter_blast_add10))
						}
					else "heavy_tank"
						{if not tagged "5_dam_b"
							{tags add "5_dam_b"}
						else tagged "5_dam_b"
							{tags add "5_dam_b_2"}
						}
						{delay 0.01
							("delay_tag" a(damage_counter_blast_add5))
						}
					}
				else min_energy 8.5 ;122
					{if tagged "armored_car"
						{delay 0.01
							("delay_tag" a(cumulative_damage_blast_to_armor))
						}
					else "light_tank"
						{delay 0.01
							("delay_tag" a(cumulative_damage_blast_to_armor))
						}
					else "medium_tank"
						{if not tagged "5_dam_b"
							{tags add "5_dam_b"}
						else tagged "5_dam_b"
							{tags add "5_dam_b_2"}
						}
						{delay 0.01
							("delay_tag" a(damage_counter_blast_add5))
						}
					else "heavy_tank"
						{if not tagged "4_dam_b"
							{tags add "4_dam_b"}
						else tagged "4_dam_b"
							{tags add "4_dam_b_2"}
						}
						{delay 0.01
							("delay_tag" a(damage_counter_blast_add4))
						}
					}
				else min_energy 7.5 ;85
					{if tagged "armored_car"
						{delay 0.01
							("delay_tag" a(cumulative_damage_blast_to_armor))
						}
					else "light_tank"
						{if not tagged "10_dam_b"
							{tags add "10_dam_b"}
						else tagged "10_dam_b"
							{tags add "10_dam_b_2"}
						}
						{delay 0.01
							("delay_tag" a(damage_counter_blast_add10))
						}
					else "medium_tank"
						{if not tagged "3_dam_b"
							{tags add "3_dam_b"}
						else tagged "3_dam_b"
							{tags add "3_dam_b_2"}
						}
						{delay 0.01
							("delay_tag" a(damage_counter_blast_add3))
						}
					else "heavy_tank"
						{if not tagged "2_dam_b"
							{tags add "2_dam_b"}
						else tagged "2_dam_b"
							{tags add "2_dam_b_2"}
						}
						{delay 0.01
							("delay_tag" a(damage_counter_blast_add2))
						}
					}
				else min_energy 5 ;75
					{if tagged "armored_car"
						{if not tagged "10_dam_b"
							{tags add "10_dam_b"}
						else tagged "10_dam_b"
							{tags add "10_dam_b_2"}
						}
						{delay 0.01
							("delay_tag" a(damage_counter_blast_add10))
						}
					else "light_tank"
						{if not tagged "5_dam_b"
							{tags add "5_dam_b"}
						else tagged "5_dam_b"
							{tags add "5_dam_b_2"}
						}
						{delay 0.01
							("delay_tag" a(damage_counter_blast_add5))
						}
					else "medium_tank"
						{if not tagged "2_dam_b"
							{tags add "2_dam_b"}
						else tagged "2_dam_b"
							{tags add "2_dam_b_2"}
						}
						{delay 0.01
							("delay_tag" a(damage_counter_blast_add2))
						}
					else "heavy_tank"
						{if not tagged "1_dam_b"
							{tags add "1_dam_b"}
						else tagged "1_dam_b"
							{tags add "1_dam_b_2"}
						}
						{delay 0.01
							("delay_tag" a(damage_counter_blast_add1))
						}
					}
				else min_energy 4 ;50mm
					{if tagged "armored_car"
						{if not tagged "4_dam_b"
							{tags add "4_dam_b"}
						else tagged "4_dam_b"
							{tags add "4_dam_b_2"}
						}
						{delay 0.01
							("delay_tag" a(damage_counter_blast_add4))
						}
					else "light_tank"
						{if not tagged "1_dam_b"
							{tags add "1_dam_b"}
						else tagged "1_dam_b"
							{tags add "1_dam_b_2"}
						}
						{delay 0.01
							("delay_tag" a(damage_counter_blast_add1))
						}
					else "medium_tank"
					else "heavy_tank"
					}
				else
					;{damage_report "engine" "<c(FF1F00)>Test<c(FFFFFF)>"}
				}
			}
		}
		{if hit_side top
			{if tagged "10_dam_b_engine_top"
				{tags add "10_dam_b"}
				{tags remove "10_dam_b_engine_top"}
			else tagged "9_dam_b_engine_top"
				{tags add "9_dam_b"}
				{tags remove "9_dam_b_engine_top"}
			else tagged "8_dam_b_engine_top"
				{tags add "8_dam_b"}
				{tags remove "8_dam_b_engine_top"}
			else tagged "7_dam_b_engine_top"
				{tags add "7_dam_b"}
				{tags remove "7_dam_b_engine_top"}
			else tagged "6_dam_b_engine_top"
				{tags add "6_dam_b"}
				{tags remove "6_dam_b_engine_top"}
			else tagged "5_dam_b_engine_top"
				{tags add "5_dam_b"}
				{tags remove "5_dam_b_engine_top"}
			else tagged "4_dam_b_engine_top"
				{tags add "4_dam_b"}
				{tags remove "4_dam_b_engine_top"}
			else tagged "3_dam_b_engine_top"
				{tags add "3_dam_b"}
				{tags remove "3_dam_b_engine_top"}
			else tagged "2_dam_b_engine_top"
				{tags add "2_dam_b"}
				{tags remove "2_dam_b_engine_top"}
			else tagged "1_dam_b_engine_top"
				{tags add "1_dam_b"}
				{tags remove "1_dam_b_engine_top"}
			}
			{if not tagged "blasted_engine_top"
				{tags add "blasted_engine_top"}
				{if min_energy 24 ;203 direct hit
					{if tagged "armored_car"
						{delay 0.01
							("delay_tag" a(cumulative_damage_blast_to_armor))
						}
					else "light_tank"
						{delay 0.01
							("delay_tag" a(cumulative_damage_blast_to_armor))
						}
					else "medium_tank"
						{delay 0.01
							("delay_tag" a(cumulative_damage_blast_to_armor))
						}
					else "heavy_tank"
						{delay 0.01
							("delay_tag" a(cumulative_damage_blast_to_armor))
						}
					}
				else min_energy 14 ;155 direct hit
					{if tagged "armored_car"
						{delay 0.01
							("delay_tag" a(cumulative_damage_blast_to_armor))
						}
					else "light_tank"
						{delay 0.01
							("delay_tag" a(cumulative_damage_blast_to_armor))
						}
					else "medium_tank"
						{delay 0.01
							("delay_tag" a(cumulative_damage_blast_to_armor))
						}
					else "heavy_tank"
						{if not tagged "6_dam_b"
							{tags add "6_dam_b"}
						else tagged "6_dam_b"
							{tags add "6_dam_b_2"}
						}
						{delay 0.01
							("delay_tag" a(damage_counter_blast_add6))
						}
					}
				else min_energy 8.5 ;122
					{if tagged "armored_car"
						{delay 0.01
							("delay_tag" a(cumulative_damage_blast_to_armor))
						}
					else "light_tank"
						{delay 0.01
							("delay_tag" a(cumulative_damage_blast_to_armor))
						}
					else "medium_tank"
						{if not tagged "8_dam_b"
							{tags add "8_dam_b"}
						else tagged "8_dam_b"
							{tags add "8_dam_b_2"}
						}
						{delay 0.01
							("delay_tag" a(damage_counter_blast_add8))
						}
					else "heavy_tank"
						{if not tagged "4_dam_b"
							{tags add "4_dam_b"}
						else tagged "4_dam_b"
							{tags add "4_dam_b_2"}
						}
						{delay 0.01
							("delay_tag" a(damage_counter_blast_add4))
						}
					}
				else min_energy 7.5 ;85
					{if tagged "armored_car"
						{delay 0.01
							("delay_tag" a(cumulative_damage_blast_to_armor))
						}
					else "light_tank"
						{delay 0.01
							("delay_tag" a(cumulative_damage_blast_to_armor))
						}
					else "medium_tank"
						{if not tagged "6_dam_b"
							{tags add "6_dam_b"}
						else tagged "6_dam_b"
							{tags add "6_dam_b_2"}
						}
						{delay 0.01
							("delay_tag" a(damage_counter_blast_add6))
						}
					else "heavy_tank"
						{if not tagged "2_dam_b"
							{tags add "2_dam_b"}
						else tagged "2_dam_b"
							{tags add "2_dam_b_2"}
						}
						{delay 0.01
							("delay_tag" a(damage_counter_blast_add2))
						}
					}
				else min_energy 5 ;75
					{if tagged "armored_car"
						{if not tagged "10_dam_b"
							{tags add "10_dam_b"}
						else tagged "10_dam_b"
							{tags add "10_dam_b_2"}
						}
						{delay 0.01
							("delay_tag" a(damage_counter_blast_add10))
						}
					else "light_tank"
						{if not tagged "8_dam_b"
							{tags add "8_dam_b"}
						else tagged "8_dam_b"
							{tags add "8_dam_b_2"}
						}
						{delay 0.01
							("delay_tag" a(damage_counter_blast_add8))
						}
					else "medium_tank"
						{if not tagged "4_dam_b"
							{tags add "4_dam_b"}
						else tagged "4_dam_b"
							{tags add "4_dam_b_2"}
						}
						{delay 0.01
							("delay_tag" a(damage_counter_blast_add4))
						}
					else "heavy_tank"
						{if not tagged "1_dam_b"
							{tags add "1_dam_b"}
						else tagged "1_dam_b"
							{tags add "1_dam_b_2"}
						}
						{delay 0.01
							("delay_tag" a(damage_counter_blast_add1))
						}
					}
				else min_energy 4 ;50mm
					{if tagged "armored_car"
						{if not tagged "5_dam_b"
							{tags add "5_dam_b"}
						else tagged "5_dam_b"
							{tags add "5_dam_b_2"}
						}
						{delay 0.01
							("delay_tag" a(damage_counter_blast_add5))
						}
					else "light_tank"
						{if not tagged "2_dam_b"
							{tags add "2_dam_b"}
						else tagged "2_dam_b"
							{tags add "2_dam_b_2"}
						}
						{delay 0.01
							("delay_tag" a(damage_counter_blast_add2))
						}
					else "medium_tank"
					else "heavy_tank"
					}
				else
					;{damage_report "engine" "<c(FF1F00)>Test<c(FFFFFF)>"}
				}
			}
		}
	}
}


