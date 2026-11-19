{on "1_dam_add"
	{tags remove "0_dam"}
	{if tagged	"1_2_dam"
		{tags remove "1_dam 1_2_dam"}
		{tags add "2_dam"}
	else tagged "2_dam"
		{tags remove "1_dam 2_dam"}
		{tags add "3_dam"}
	else tagged "3_dam"
		{tags remove "1_dam 3_dam"}
		{tags add "4_dam"}
	else tagged "4_dam"
		{tags remove "1_dam 4_dam"}
		{tags add "5_dam"}
	else tagged "5_dam"
		{tags remove "1_dam 5_dam"}
		{tags add "6_dam"}
	else tagged "6_dam"
		{tags remove "1_dam 6_dam"}
		{tags add "7_dam"}
	else tagged "7_dam"
		{tags remove "1_dam 7_dam"}
		{tags add "8_dam"}
	else tagged "8_dam"
		{tags remove "1_dam 8_dam"}
		{tags add "9_dam"}
	else tagged "9_dam"
		{tags remove "1_dam 9_dam"}
		{tags add "10_dam"}
	else tagged "10_dam"
		{tags remove "1_dam 10_dam"}
		{tags add "11_dam"}
	else tagged "11_dam"
		{tags remove "1_dam 11_dam"}
		{tags add "12_dam"}
	else tagged "12_dam"
		{tags remove "1_dam 12_dam"}
		{tags add "13_dam"}
	else tagged "13_dam"
		{tags remove "1_dam 13_dam"}
		{tags add "14_dam"}
	else tagged "14_dam"
		{tags remove "1_dam 14_dam"}
		{tags add "15_dam"}
	else tagged "15_dam"
		{tags remove "1_dam 15_dam"}
		{tags add "16_dam"}
	else tagged "16_dam"
		{tags remove "1_dam 16_dam"}
		{tags add "17_dam"}
	else tagged "17_dam"
		{tags remove "1_dam 17_dam"}
		{tags add "18_dam"}
	else tagged "18_dam"
		{tags remove "1_dam 18_dam"}
		{tags add "19_dam"}
	else tagged "19_dam"
		{tags remove "1_dam 19_dam"}
		{tags add "20_dam"}
	else tagged "20_dam"
		{tags remove "1_dam 20_dam"}
		{tags add "21_dam"}
	else tagged "21_dam"
		{tags remove "1_dam 21_dam"}
		{tags add "22_dam"}
	else tagged "22_dam"
		{tags remove "1_dam 22_dam"}
		{tags add "23_dam"}
	else tagged "23_dam"
		{tags remove "1_dam 23_dam"}
		{tags add "24_dam"}
	else tagged "24_dam"
		{tags remove "1_dam 24_dam"}
		{tags add "25_dam"}
	else tagged "25_dam"
		{tags remove "1_dam 25_dam"}
		{tags add "26_dam"}
	else tagged "26_dam"
		{tags remove "1_dam 26_dam"}
		{tags add "27_dam"}
	else tagged "27_dam"
		{tags remove "1_dam 27_dam"}
		{tags add "28_dam"}
	else tagged "28_dam"
		{tags remove "1_dam 28_dam"}
		{tags add "29_dam"}
	else tagged "29_dam"
		{tags remove "1_dam 29_dam"}
		{tags add "30_dam"}
	else
		{damage_report "penetration" "<c(FF1F00)>ERROR 3: Report<c(FFFFFF)>"}
	}
	{call "combat_capable_check"}
}


{on "2_dam_add"
	{tags remove "0_dam"}
	{if tagged	"1_dam"
		{tags remove "1_dam 2_dam"}
		{tags add "3_dam"}
	else tagged	"2_2_dam"
		{tags remove "2_dam 2_2_dam"}
		{tags add "4_dam"}
	else tagged "3_dam"
		{tags remove "2_dam 3_dam"}
		{tags add "5_dam"}
	else tagged "4_dam"
		{tags remove "2_dam 4_dam"}
		{tags add "6_dam"}
	else tagged "5_dam"
		{tags remove "2_dam 5_dam"}
		{tags add "7_dam"}
	else tagged "6_dam"
		{tags remove "2_dam 6_dam"}
		{tags add "8_dam"}
	else tagged "7_dam"
		{tags remove "2_dam 7_dam"}
		{tags add "9_dam"}
	else tagged "8_dam"
		{tags remove "2_dam 8_dam"}
		{tags add "10_dam"}
	else tagged "9_dam"
		{tags remove "2_dam 9_dam"}
		{tags add "11_dam"}
	else tagged "10_dam"
		{tags remove "2_dam 10_dam"}
		{tags add "12_dam"}
	else tagged "11_dam"
		{tags remove "2_dam 11_dam"}
		{tags add "13_dam"}
	else tagged "12_dam"
		{tags remove "2_dam 12_dam"}
		{tags add "14_dam"}
	else tagged "13_dam"
		{tags remove "2_dam 13_dam"}
		{tags add "15_dam"}
	else tagged "14_dam"
		{tags remove "2_dam 14_dam"}
		{tags add "16_dam"}
	else tagged "15_dam"
		{tags remove "2_dam 15_dam"}
		{tags add "17_dam"}
	else tagged "16_dam"
		{tags remove "2_dam 16_dam"}
		{tags add "18_dam"}
	else tagged "17_dam"
		{tags remove "2_dam 17_dam"}
		{tags add "19_dam"}
	else tagged "18_dam"
		{tags remove "2_dam 18_dam"}
		{tags add "20_dam"}
	else tagged "19_dam"
		{tags remove "2_dam 19_dam"}
		{tags add "21_dam"}
	else tagged "20_dam"
		{tags remove "2_dam 20_dam"}
		{tags add "22_dam"}
	else tagged "21_dam"
		{tags remove "2_dam 21_dam"}
		{tags add "23_dam"}
	else tagged "22_dam"
		{tags remove "2_dam 22_dam"}
		{tags add "24_dam"}
	else tagged "23_dam"
		{tags remove "2_dam 23_dam"}
		{tags add "25_dam"}
	else tagged "24_dam"
		{tags remove "2_dam 24_dam"}
		{tags add "26_dam"}
	else tagged "25_dam"
		{tags remove "2_dam 25_dam"}
		{tags add "27_dam"}
	else tagged "26_dam"
		{tags remove "2_dam 26_dam"}
		{tags add "28_dam"}
	else tagged "27_dam"
		{tags remove "2_dam 27_dam"}
		{tags add "29_dam"}
	else tagged "28_dam"
		{tags remove "2_dam 28_dam"}
		{tags add "30_dam"}
	else tagged "29_dam"
		{tags remove "2_dam 29_dam"}
		{tags add "31_dam"}
	else
		{damage_report "penetration" "<c(FF1F00)>ERROR 3: Report<c(FFFFFF)>"}
	}
	{call "combat_capable_check"}
}

{on "3_dam_add"
	{tags remove "0_dam"}
	{if tagged "1_dam"
		{tags remove "3_dam 1_dam"}
		{tags add "4_dam"}
	else tagged "2_dam"
		{tags remove "3_dam 2_dam"}
		{tags add "5_dam"}
	else tagged "3_2_dam"
		{tags remove "3_dam 3_2_dam"}
		{tags add "6_dam"}
	else tagged "4_dam"
		{tags remove "3_dam 4_dam"}
		{tags add "7_dam"}
	else tagged "5_dam"
		{tags remove "3_dam 5_dam"}
		{tags add "8_dam"}
	else tagged "6_dam"
		{tags remove "3_dam 6_dam"}
		{tags add "9_dam"}
	else tagged "7_dam"
		{tags remove "3_dam 7_dam"}
		{tags add "10_dam"}
	else tagged "8_dam"
		{tags remove "3_dam 8_dam"}
		{tags add "11_dam"}
	else tagged "9_dam"
		{tags remove "3_dam 9_dam"}
		{tags add "12_dam"}
	else tagged "10_dam"
		{tags remove "3_dam 10_dam"}
		{tags add "13_dam"}
	else tagged "11_dam"
		{tags remove "3_dam 11_dam"}
		{tags add "14_dam"}
	else tagged "12_dam"
		{tags remove "3_dam 12_dam"}
		{tags add "15_dam"}
	else tagged "13_dam"
		{tags remove "3_dam 13_dam"}
		{tags add "16_dam"}
	else tagged "14_dam"
		{tags remove "3_dam 14_dam"}
		{tags add "17_dam"}
	else tagged "15_dam"
		{tags remove "3_dam 15_dam"}
		{tags add "18_dam"}
	else tagged "16_dam"
		{tags remove "3_dam 16_dam"}
		{tags add "19_dam"}
	else tagged "17_dam"
		{tags remove "3_dam 17_dam"}
		{tags add "20_dam"}
	else tagged "18_dam"
		{tags remove "3_dam 18_dam"}
		{tags add "21_dam"}
	else tagged "19_dam"
		{tags remove "3_dam 19_dam"}
		{tags add "22_dam"}
	else tagged "20_dam"
		{tags remove "3_dam 20_dam"}
		{tags add "23_dam"}
	else tagged "21_dam"
		{tags remove "3_dam 21_dam"}
		{tags add "24_dam"}
	else tagged "22_dam"
		{tags remove "3_dam 22_dam"}
		{tags add "25_dam"}
	else tagged "23_dam"
		{tags remove "3_dam 23_dam"}
		{tags add "26_dam"}
	else tagged "24_dam"
		{tags remove "3_dam 24_dam"}
		{tags add "27_dam"}
	else tagged "25_dam"
		{tags remove "3_dam 25_dam"}
		{tags add "28_dam"}
	else tagged "26_dam"
		{tags remove "3_dam 26_dam"}
		{tags add "29_dam"}
	else tagged "27_dam"
		{tags remove "3_dam 27_dam"}
		{tags add "30_dam"}
	else
		{damage_report "penetration" "<c(FF1F00)>ERROR 3: Report<c(FFFFFF)>"}
	}
	{call "combat_capable_check"}
}

{on "4_dam_add"
	{tags remove "0_dam"}
	{if tagged "1_dam"
		{tags remove "4_dam 1_dam"}
		{tags add "5_dam"}
	else tagged "2_dam"
		{tags remove "4_dam 2_dam"}
		{tags add "6_dam"}
	else tagged "3_dam"
		{tags remove "4_dam 3_dam"}
		{tags add "7_dam"}
	else tagged "4_2_dam"
		{tags remove "4_dam 4_2_dam"}
		{tags add "8_dam"}
	else tagged "5_dam"
		{tags remove "4_dam 5_dam"}
		{tags add "9_dam"}
	else tagged "6_dam"
		{tags remove "4_dam 6_dam"}
		{tags add "10_dam"}
	else tagged "7_dam"
		{tags remove "4_dam 7_dam"}
		{tags add "11_dam"}
	else tagged "8_dam"
		{tags remove "4_dam 8_dam"}
		{tags add "12_dam"}
	else tagged "9_dam"
		{tags remove "4_dam 9_dam"}
		{tags add "13_dam"}
	else tagged "10_dam"
		{tags remove "4_dam 10_dam"}
		{tags add "14_dam"}
	else tagged "11_dam"
		{tags remove "4_dam 11_dam"}
		{tags add "15_dam"}
	else tagged "12_dam"
		{tags remove "4_dam 12_dam"}
		{tags add "16_dam"}
	else tagged "13_dam"
		{tags remove "4_dam 13_dam"}
		{tags add "17_dam"}
	else tagged "14_dam"
		{tags remove "4_dam 14_dam"}
		{tags add "18_dam"}
	else tagged "15_dam"
		{tags remove "4_dam 15_dam"}
		{tags add "19_dam"}
	else tagged "16_dam"
		{tags remove "4_dam 16_dam"}
		{tags add "20_dam"}
	else tagged "17_dam"
		{tags remove "4_dam 17_dam"}
		{tags add "21_dam"}
	else tagged "18_dam"
		{tags remove "4_dam 18_dam"}
		{tags add "22_dam"}
	else tagged "19_dam"
		{tags remove "4_dam 19_dam"}
		{tags add "23_dam"}
	else tagged "20_dam"
		{tags remove "4_dam 20_dam"}
		{tags add "24_dam"}
	else tagged "21_dam"
		{tags remove "4_dam 21_dam"}
		{tags add "25_dam"}
	else tagged "22_dam"
		{tags remove "4_dam 22_dam"}
		{tags add "26_dam"}
	else tagged "23_dam"
		{tags remove "4_dam 23_dam"}
		{tags add "27_dam"}
	else tagged "24_dam"
		{tags remove "4_dam 24_dam"}
		{tags add "28_dam"}
	else tagged "25_dam"
		{tags remove "4_dam 25_dam"}
		{tags add "29_dam"}
	else tagged "26_dam"
		{tags remove "4_dam 26_dam"}
		{tags add "30_dam"}
	else
		{damage_report "penetration" "<c(FF1F00)>ERROR 3: Report<c(FFFFFF)>"}
	}
	{call "combat_capable_check"}
}

{on "5_dam_add"
	{tags remove "0_dam"}
	{if tagged "1_dam"
		{tags remove "5_dam 1_dam"}
		{tags add "6_dam"}
	else tagged "2_dam"
		{tags remove "5_dam 2_dam"}
		{tags add "7_dam"}
	else tagged "3_dam"
		{tags remove "5_dam 3_dam"}
		{tags add "8_dam"}
	else tagged "4_dam"
		{tags remove "5_dam 4_dam"}
		{tags add "9_dam"}
	else tagged "5_2_dam"
		{tags remove "5_dam 5_2_dam"}
		{tags add "10_dam"}
	else tagged "6_dam"
		{tags remove "5_dam 6_dam"}
		{tags add "11_dam"}
	else tagged "7_dam"
		{tags remove "5_dam 7_dam"}
		{tags add "12_dam"}
	else tagged "8_dam"
		{tags remove "5_dam 8_dam"}
		{tags add "13_dam"}
	else tagged "9_dam"
		{tags remove "5_dam 9_dam"}
		{tags add "14_dam"}
	else tagged "10_dam"
		{tags remove "5_dam 10_dam"}
		{tags add "15_dam"}
	else tagged "11_dam"
		{tags remove "5_dam 11_dam"}
		{tags add "16_dam"}
	else tagged "12_dam"
		{tags remove "5_dam 12_dam"}
		{tags add "17_dam"}
	else tagged "13_dam"
		{tags remove "5_dam 13_dam"}
		{tags add "18_dam"}
	else tagged "14_dam"
		{tags remove "5_dam 14_dam"}
		{tags add "19_dam"}
	else tagged "15_dam"
		{tags remove "5_dam 15_dam"}
		{tags add "20_dam"}
	else tagged "16_dam"
		{tags remove "5_dam 16_dam"}
		{tags add "21_dam"}
	else tagged "17_dam"
		{tags remove "5_dam 17_dam"}
		{tags add "22_dam"}
	else tagged "18_dam"
		{tags remove "5_dam 18_dam"}
		{tags add "23_dam"}
	else tagged "19_dam"
		{tags remove "5_dam 19_dam"}
		{tags add "24_dam"}
	else tagged "20_dam"
		{tags remove "5_dam 20_dam"}
		{tags add "25_dam"}
	else tagged "21_dam"
		{tags remove "5_dam 21_dam"}
		{tags add "26_dam"}
	else tagged "22_dam"
		{tags remove "5_dam 22_dam"}
		{tags add "27_dam"}
	else tagged "23_dam"
		{tags remove "5_dam 23_dam"}
		{tags add "28_dam"}
	else tagged "24_dam"
		{tags remove "5_dam 24_dam"}
		{tags add "29_dam"}
	else tagged "25_dam"
		{tags remove "5_dam 25_dam"}
		{tags add "30_dam"}
	else
		{damage_report "penetration" "<c(FF1F00)>ERROR 3: Report<c(FFFFFF)>"}
	}
	{call "combat_capable_check"}
}

{on "6_dam_add"
	{tags remove "0_dam"}
	{if tagged "1_dam"
		{tags remove "6_dam 1_dam"}
		{tags add "7_dam"}
	else tagged "2_dam"
		{tags remove "6_dam 2_dam"}
		{tags add "8_dam"}
	else tagged "3_dam"
		{tags remove "6_dam 3_dam"}
		{tags add "9_dam"}
	else tagged "4_dam"
		{tags remove "6_dam 4_dam"}
		{tags add "10_dam"}
	else tagged "5_dam"
		{tags remove "6_dam 5_dam"}
		{tags add "11_dam"}
	else tagged "6_2_dam"
		{tags remove "6_dam 6_2_dam"}
		{tags add "12_dam"}
	else tagged "7_dam"
		{tags remove "6_dam 7_dam"}
		{tags add "13_dam"}
	else tagged "8_dam"
		{tags remove "6_dam 8_dam"}
		{tags add "14_dam"}
	else tagged "9_dam"
		{tags remove "6_dam 9_dam"}
		{tags add "15_dam"}
	else tagged "10_dam"
		{tags remove "6_dam 10_dam"}
		{tags add "16_dam"}
	else tagged "11_dam"
		{tags remove "6_dam 11_dam"}
		{tags add "17_dam"}
	else tagged "12_dam"
		{tags remove "6_dam 12_dam"}
		{tags add "18_dam"}
	else tagged "13_dam"
		{tags remove "6_dam 13_dam"}
		{tags add "19_dam"}
	else tagged "14_dam"
		{tags remove "6_dam 14_dam"}
		{tags add "20_dam"}
	else tagged "15_dam"
		{tags remove "6_dam 15_dam"}
		{tags add "21_dam"}
	else tagged "16_dam"
		{tags remove "6_dam 16_dam"}
		{tags add "22_dam"}
	else tagged "17_dam"
		{tags remove "6_dam 17_dam"}
		{tags add "23_dam"}
	else tagged "18_dam"
		{tags remove "6_dam 18_dam"}
		{tags add "24_dam"}
	else tagged "19_dam"
		{tags remove "6_dam 19_dam"}
		{tags add "25_dam"}
	else tagged "20_dam"
		{tags remove "6_dam 20_dam"}
		{tags add "26_dam"}
	else tagged "21_dam"
		{tags remove "6_dam 21_dam"}
		{tags add "27_dam"}
	else tagged "22_dam"
		{tags remove "6_dam 22_dam"}
		{tags add "28_dam"}
	else tagged "23_dam"
		{tags remove "6_dam 23_dam"}
		{tags add "29_dam"}
	else tagged "24_dam"
		{tags remove "6_dam 24_dam"}
		{tags add "30_dam"}
	else
		{damage_report "penetration" "<c(FF1F00)>ERROR 3: Report<c(FFFFFF)>"}
	}
	{call "combat_capable_check"}
}

{on "7_dam_add"
	{tags remove "0_dam"}
	{if tagged "1_dam"
		{tags remove "7_dam 1_dam"}
		{tags add "8_dam"}
	else tagged "2_dam"
		{tags remove "7_dam 2_dam"}
		{tags add "9_dam"}
	else tagged "3_dam"
		{tags remove "7_dam 3_dam"}
		{tags add "10_dam"}
	else tagged "4_dam"
		{tags remove "7_dam 4_dam"}
		{tags add "11_dam"}
	else tagged "5_dam"
		{tags remove "7_dam 5_dam"}
		{tags add "12_dam"}
	else tagged "6_dam"
		{tags remove "7_dam 6_dam"}
		{tags add "13_dam"}
	else tagged "7_2_dam"
		{tags remove "7_dam 7_2_dam"}
		{tags add "14_dam"}
	else tagged "8_dam"
		{tags remove "7_dam 8_dam"}
		{tags add "15_dam"}
	else tagged "9_dam"
		{tags remove "7_dam 9_dam"}
		{tags add "16_dam"}
	else tagged "10_dam"
		{tags remove "7_dam 10_dam"}
		{tags add "17_dam"}
	else tagged "11_dam"
		{tags remove "7_dam 11_dam"}
		{tags add "18_dam"}
	else tagged "12_dam"
		{tags remove "7_dam 12_dam"}
		{tags add "19_dam"}
	else tagged "13_dam"
		{tags remove "7_dam 13_dam"}
		{tags add "20_dam"}
	else tagged "14_dam"
		{tags remove "7_dam 14_dam"}
		{tags add "21_dam"}
	else tagged "15_dam"
		{tags remove "7_dam 15_dam"}
		{tags add "22_dam"}
	else tagged "16_dam"
		{tags remove "7_dam 16_dam"}
		{tags add "23_dam"}
	else tagged "17_dam"
		{tags remove "7_dam 17_dam"}
		{tags add "24_dam"}
	else tagged "18_dam"
		{tags remove "7_dam 18_dam"}
		{tags add "25_dam"}
	else tagged "19_dam"
		{tags remove "7_dam 19_dam"}
		{tags add "26_dam"}
	else tagged "20_dam"
		{tags remove "7_dam 20_dam"}
		{tags add "27_dam"}
	else tagged "21_dam"
		{tags remove "7_dam 21_dam"}
		{tags add "28_dam"}
	else tagged "22_dam"
		{tags remove "7_dam 22_dam"}
		{tags add "29_dam"}
	else tagged "23_dam"
		{tags remove "7_dam 23_dam"}
		{tags add "30_dam"}
	else
		{damage_report "penetration" "<c(FF1F00)>ERROR 3: Report<c(FFFFFF)>"}
	}
	{call "combat_capable_check"}
}

{on "8_dam_add"
	{tags remove "0_dam"}
	{if tagged "1_dam"
		{tags remove "8_dam 1_dam"}
		{tags add "9_dam"}
	else tagged "2_dam"
		{tags remove "8_dam 2_dam"}
		{tags add "10_dam"}
	else tagged "3_dam"
		{tags remove "8_dam 3_dam"}
		{tags add "11_dam"}
	else tagged "4_dam"
		{tags remove "8_dam 4_dam"}
		{tags add "12_dam"}
	else tagged "5_dam"
		{tags remove "8_dam 5_dam"}
		{tags add "13_dam"}
	else tagged "6_dam"
		{tags remove "8_dam 6_dam"}
		{tags add "14_dam"}
	else tagged "7_dam"
		{tags remove "8_dam 7_dam"}
		{tags add "15_dam"}
	else tagged "8_2_dam"
		{tags remove "8_dam 8_2_dam"}
		{tags add "16_dam"}
	else tagged "9_dam"
		{tags remove "8_dam 9_dam"}
		{tags add "17_dam"}
	else tagged "10_dam"
		{tags remove "8_dam 10_dam"}
		{tags add "18_dam"}
	else tagged "11_dam"
		{tags remove "8_dam 11_dam"}
		{tags add "19_dam"}
	else tagged "12_dam"
		{tags remove "8_dam 12_dam"}
		{tags add "20_dam"}
	else tagged "13_dam"
		{tags remove "8_dam 13_dam"}
		{tags add "21_dam"}
	else tagged "14_dam"
		{tags remove "8_dam 14_dam"}
		{tags add "22_dam"}
	else tagged "15_dam"
		{tags remove "8_dam 15_dam"}
		{tags add "23_dam"}
	else tagged "16_dam"
		{tags remove "8_dam 16_dam"}
		{tags add "24_dam"}
	else tagged "17_dam"
		{tags remove "8_dam 17_dam"}
		{tags add "25_dam"}
	else tagged "18_dam"
		{tags remove "8_dam 18_dam"}
		{tags add "26_dam"}
	else tagged "19_dam"
		{tags remove "8_dam 19_dam"}
		{tags add "27_dam"}
	else tagged "20_dam"
		{tags remove "8_dam 20_dam"}
		{tags add "28_dam"}
	else tagged "21_dam"
		{tags remove "8_dam 21_dam"}
		{tags add "29_dam"}
	else tagged "22_dam"
		{tags remove "8_dam 22_dam"}
		{tags add "30_dam"}
	else
		{damage_report "penetration" "<c(FF1F00)>ERROR 3: Report<c(FFFFFF)>"}
	}
	{call "combat_capable_check"}
}

{on "9_dam_add"
	{tags remove "0_dam"}
	{if tagged "1_dam"
		{tags remove "9_dam 1_dam"}
		{tags add "10_dam"}
	else tagged "2_dam"
		{tags remove "9_dam 2_dam"}
		{tags add "11_dam"}
	else tagged "3_dam"
		{tags remove "9_dam 3_dam"}
		{tags add "12_dam"}
	else tagged "4_dam"
		{tags remove "9_dam 4_dam"}
		{tags add "13_dam"}
	else tagged "5_dam"
		{tags remove "9_dam 5_dam"}
		{tags add "14_dam"}
	else tagged "6_dam"
		{tags remove "9_dam 6_dam"}
		{tags add "15_dam"}
	else tagged "7_dam"
		{tags remove "9_dam 7_dam"}
		{tags add "16_dam"}
	else tagged "8_dam"
		{tags remove "9_dam 8_dam"}
		{tags add "17_dam"}
	else tagged "9_2_dam"
		{tags remove "9_dam 9_2_dam"}
		{tags add "18_dam"}
	else tagged "10_dam"
		{tags remove "9_dam 10_dam"}
		{tags add "19_dam"}
	else tagged "11_dam"
		{tags remove "9_dam 11_dam"}
		{tags add "20_dam"}
	else tagged "12_dam"
		{tags remove "9_dam 12_dam"}
		{tags add "21_dam"}
	else tagged "13_dam"
		{tags remove "9_dam 13_dam"}
		{tags add "22_dam"}
	else tagged "14_dam"
		{tags remove "9_dam 14_dam"}
		{tags add "23_dam"}
	else tagged "15_dam"
		{tags remove "9_dam 15_dam"}
		{tags add "24_dam"}
	else tagged "16_dam"
		{tags remove "9_dam 16_dam"}
		{tags add "25_dam"}
	else tagged "17_dam"
		{tags remove "9_dam 17_dam"}
		{tags add "26_dam"}
	else tagged "18_dam"
		{tags remove "9_dam 18_dam"}
		{tags add "27_dam"}
	else tagged "19_dam"
		{tags remove "9_dam 19_dam"}
		{tags add "28_dam"}
	else tagged "20_dam"
		{tags remove "9_dam 20_dam"}
		{tags add "29_dam"}
	else tagged "21_dam"
		{tags remove "9_dam 21_dam"}
		{tags add "30_dam"}
	else
		{damage_report "penetration" "<c(FF1F00)>ERROR 3: Report<c(FFFFFF)>"}
	}
	{call "combat_capable_check"}
}

{on "10_dam_add"
	{tags remove "0_dam"}
	{if tagged "1_dam"
		{tags remove "10_dam 1_dam"}
		{tags add "11_dam"}
	else tagged "2_dam"
		{tags remove "10_dam 2_dam"}
		{tags add "12_dam"}
	else tagged "3_dam"
		{tags remove "10_dam 3_dam"}
		{tags add "13_dam"}
	else tagged "4_dam"
		{tags remove "10_dam 4_dam"}
		{tags add "14_dam"}
	else tagged "5_dam"
		{tags remove "10_dam 5_dam"}
		{tags add "15_dam"}
	else tagged "6_dam"
		{tags remove "10_dam 6_dam"}
		{tags add "16_dam"}
	else tagged "7_dam"
		{tags remove "10_dam 7_dam"}
		{tags add "17_dam"}
	else tagged "8_dam"
		{tags remove "10_dam 8_dam"}
		{tags add "18_dam"}
	else tagged "9_dam"
		{tags remove "10_dam 9_dam"}
		{tags add "19_dam"}
	else tagged "10_2_dam"
		{tags remove "10_dam 10_2_dam"}
		{tags add "20_dam"}
	else tagged "11_dam"
		{tags remove "10_dam 11_dam"}
		{tags add "21_dam"}
	else tagged "12_dam"
		{tags remove "10_dam 12_dam"}
		{tags add "22_dam"}
	else tagged "13_dam"
		{tags remove "10_dam 13_dam"}
		{tags add "23_dam"}
	else tagged "14_dam"
		{tags remove "10_dam 14_dam"}
		{tags add "24_dam"}
	else tagged "15_dam"
		{tags remove "10_dam 15_dam"}
		{tags add "25_dam"}
	else tagged "16_dam"
		{tags remove "10_dam 16_dam"}
		{tags add "26_dam"}
	else tagged "17_dam"
		{tags remove "10_dam 17_dam"}
		{tags add "27_dam"}
	else tagged "18_dam"
		{tags remove "10_dam 18_dam"}
		{tags add "28_dam"}
	else tagged "19_dam"
		{tags remove "10_dam 19_dam"}
		{tags add "29_dam"}
	else tagged "20_dam"
		{tags remove "10_dam 20_dam"}
		{tags add "30_dam"}
	else
		{damage_report "penetration" "<c(FF1F00)>ERROR 3: Report<c(FFFFFF)>"}
	}
	{call "combat_capable_check"}
}

