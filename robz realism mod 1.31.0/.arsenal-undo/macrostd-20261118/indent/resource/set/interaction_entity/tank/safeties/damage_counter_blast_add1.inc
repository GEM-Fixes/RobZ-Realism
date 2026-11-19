	{tags remove "0_dam_b"}
	{if tagged	"1_dam_b_2"
		{tags remove "1_dam_b 1_dam_b_2"}
		{tags add "2_dam_b"}
	else tagged "2_dam_b"
		{tags remove "1_dam_b 2_dam_b"}
		{tags add "3_dam_b"}
	else tagged "3_dam_b"
		{tags remove "1_dam_b 3_dam_b_b"}
		{tags add "4_dam_b"}
	else tagged "4_dam_b"
		{tags remove "1_dam_b 4_dam_b"}
		{tags add "5_dam_b"}
	else tagged "5_dam_b"
		{tags remove "1_dam_b 5_dam_b"}
		{tags add "6_dam_b"}
	else tagged "6_dam_b"
		{tags remove "1_dam_b 6_dam_b"}
		{tags add "7_dam_b"}
	else tagged "7_dam_b"
		{tags remove "1_dam_b 7_dam_b"}
		{tags add "8_dam_b"}
	else tagged "8_dam_b"
		{tags remove "1_dam_b 8_dam_b"}
		{tags add "9_dam_b"}
	else tagged "9_dam_b"
		{tags remove "1_dam_b 9_dam_b"}
		{tags add "10_dam_b"}
	else tagged "10_dam_b"
		{tags remove "1_dam_b 10_dam_b"}
		{tags add "11_dam_b"}
	else tagged "11_dam_b"
		{tags remove "1_dam_b 11_dam_b"}
		{tags add "12_dam_b"}
	else
		{damage_report "body" "<c(FF1F00)>ERROR 3: Report<c(FFFFFF)>"}
	}
	{delay 0.01
		("delay_tag" a(combat_capable_check_blast))
	}
