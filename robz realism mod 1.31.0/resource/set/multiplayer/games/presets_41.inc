; 41 preset - same settings as the 1944-1945 preset, units limited to 41
(define "custom_41"
	{common
		{unitset
			{value "41"}
		}
		{commandPoints "*=%cp"}
		{unitLimits "flamethrower=3;officer=2;super_officer=1;sniper_h_g=10;sniper_h_ss=20;sp=1;heavyaa=2;only-one=1,super_persh=1"};
		{chargeFactors
			{value "*=1"}
		}
		{budgets
			{vehicle
				{mode "custom"}
				{resource 
					{start 		%start}
					{finish 	%finish}
					{growTime	2600}		; in seconds
					{growTable 	"0.65 0.65 0.65 0.70 0.70 0.70 0.75 0.75 0.75 0.80 0.80 0.80 0.80 0.80 0.80 0.85 0.85 0.85 0.90 0.90 0.90 0.90 0.90 0.90 1.00"}
					{payback
						{cp 		"0	30	40 	50	70	80	90"}  
						{restore 	"2.25	1.875	0.75	0.50	0.40	0.30	0.20"}
					}
					{limitmin	1000}
					{limitmax	50000}
					{speedset 	"2500 3000 3500 4000 4500 5000 6000 8000 10000 20000 50000"}
				} 
				{buttons "squad1 squad2 v1 v2 v22 v3 v4 v5 v6 v7 v8 v9 v10 v11 v12 sf"}
			}
			{hero
				{resource 
					{start 		20}
				} 
				{buttons "hero"}
				{tag "special"}
			}
		} 
	}
	{bots
		(include "bots_generic.inc")
	}
)
(define "custom_wavemode_41"
	{common
		{unitset
			{value "41"}
		}
		{commandPoints "*=%cp"}
		{unitLimits "flamethrower=3;officer=3;sniper_h_g=2;sniper_h_ss=4;heavyaa=2;only-one=1"}
		{chargeFactors
			{value "hero=1;*=0"}
		}
		{budgets
			{vehicle
				{mode "with_update"}
				{resource 
					{start 		%start}
					{finish 	10000}
					{speed 		500}
					{period 	%period}
					{limitmin	100}
					{limitmax	10000}
					{speedset 	"250 500 750 1000 1500 2000 2500 3000 4000 5000 7500 10000"}
				} 
				{buttons "squad1 squad2 v1 v2 v22 v3 v4 v5 v6 sf"}
			}
			{hero
				{resource 
					{start 		20}
				} 
				{buttons "hero"}
				{tag "special"}
			}
		} 
	}
	{bots
		(include "bots_generic.inc")
	}
)
{presets
	{"c:custom_120_41"
		{gameMode "custom"}
		{unitMode "41"}
		{specMode "cp_120"}
		{apply "units_41"}
		("custom_41" 			start(200) finish(7000) cp(120))
	}
;-------------------------
(define "wavemode_41"
	{"c:custom_500_%cp_wave_41%period"
		{gameMode "custom_wavemode_500"}
		{unitMode "41%period"}
		{specMode "cp_%cp"}
		{apply "units_41"}
		("custom_wavemode_41"  start(500) period(%period) cp(%cp)) 
	}
	{"c:custom_1000_%cp_wave_41%period"
		{gameMode "custom_wavemode_1000"}
		{unitMode "41%period"}
		{specMode "cp_%cp"}
		{apply "units_41"}
		("custom_wavemode_41"  start(1000) period(%period) cp(%cp)) 
	}
	{"c:custom_1500_%cp_wave_41%period"
		{gameMode "custom_wavemode_1500"}
		{unitMode "41%period"}
		{specMode "cp_%cp"}
		{apply "units_41"}
		("custom_wavemode_41"  start(1500) period(%period) cp(%cp)) 
	}
	{"c:custom_2000_%cp_wave_41%period"
		{gameMode "custom_wavemode_2000"}
		{unitMode "41%period"}
		{specMode "cp_%cp"}
		{apply "units_41"}
		("custom_wavemode_41"  start(2000) period(%period) cp(%cp))
	}
	{"c:custom_3000_%cp_wave_41%period"
		{gameMode "custom_wavemode_3000"}
		{unitMode "41%period"}
		{specMode "cp_%cp"}
		{apply "units_41"}
		("custom_wavemode_41"  start(3000) period(%period) cp(%cp))
	}
)
(define "wavemode_total41"
	("wavemode_41" period(%period) cp(100))
	("wavemode_41" period(%period) cp(200))
)
	("wavemode_total41" period(180))
	("wavemode_total41" period(300))
	("wavemode_total41" period(420))
	("wavemode_total41" period(600))
}

