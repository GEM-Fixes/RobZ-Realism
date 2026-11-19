; custom_44_45: {common {unitset} {commandPoints} {unitLimits} {chargeFactors} ..} {bots}
;   cp - text in {commandPoints}
;   start - {start}, [?]
;   finish - {finish}, [?]
;   e.g. ("custom_44_45"    start(200) finish(7000) cp(120))
(define "custom_44_45"
	{common
		{unitset
			{value "44|45|sf"}
		}
		{commandPoints "*=%cp"}
		{unitLimits "flamethrower=3;officer=2;super_officer=1;sniper_h_g=10;sniper_h_ss=20;sp=1;heavyaa=2;only-one=1;super_persh=1"};
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
; custom_wavemode_44_45: {common {unitset} {commandPoints} {unitLimits} {chargeFactors} ..} {bots}
;   cp - text in {commandPoints}
;   start - {start}, [?]
;   period - {period}, s
;   e.g. ("custom_wavemode_44_45"  start(500) period(%period) cp(%cp))
(define "custom_wavemode_44_45"
	{common
		{unitset
			{value "44|45|sf"}
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
	{"c:custom_120_44-45"
		{gameMode "custom"}
		{unitMode "44-45"}
		{specMode "cp_120"}
		{apply "units_44-45"}
		("custom_44_45" 			start(200) finish(7000) cp(120))
	}
	;-------------------------
	; wavemode_44_45: {"c:custom_500_%cp_wave_44-45%period"} {"c:custom_1000_%cp_wave_44-45%period"} {"c:custom_1500_%cp_wave_44-45%period"} {"c:custom_2000_%cp_wave_44-45%period"} {"c:custom_3000_%cp_wave_44-45%period"}
	;   cp_wave_44 - block name
	;   period - block name, text in {unitMode}, {period}, s via "custom_wavemode_44_45"
	;   cp - text in {specMode}, text in {commandPoints} via "custom_wavemode_44_45"
	;   e.g. ("wavemode_44_45" period(%period) cp(100))
	(define "wavemode_44_45"
		{"c:custom_500_%cp_wave_44-45%period"
			{gameMode "custom_wavemode_500"}
			{unitMode "44-45%period"}
			{specMode "cp_%cp"}
			{apply "units_44-45"}
			("custom_wavemode_44_45"  start(500) period(%period) cp(%cp))
		}
		{"c:custom_1000_%cp_wave_44-45%period"
			{gameMode "custom_wavemode_1000"}
			{unitMode "44-45%period"}
			{specMode "cp_%cp"}
			{apply "units_44-45"}
			("custom_wavemode_44_45"  start(1000) period(%period) cp(%cp))
		}
		{"c:custom_1500_%cp_wave_44-45%period"
			{gameMode "custom_wavemode_1500"}
			{unitMode "44-45%period"}
			{specMode "cp_%cp"}
			{apply "units_44-45"}
			("custom_wavemode_44_45"  start(1500) period(%period) cp(%cp))
		}
		{"c:custom_2000_%cp_wave_44-45%period"
			{gameMode "custom_wavemode_2000"}
			{unitMode "44-45%period"}
			{specMode "cp_%cp"}
			{apply "units_44-45"}
			("custom_wavemode_44_45"  start(2000) period(%period) cp(%cp))
		}
		{"c:custom_3000_%cp_wave_44-45%period"
			{gameMode "custom_wavemode_3000"}
			{unitMode "44-45%period"}
			{specMode "cp_%cp"}
			{apply "units_44-45"}
			("custom_wavemode_44_45"  start(3000) period(%period) cp(%cp))
		}
	)
	; wavemode_total44_45: calls "wavemode_44_45"
	;   period - block name via "wavemode_44_45", text in {unitMode} via "wavemode_44_45", {period}, s via "wavemode_44_45"
	;   e.g. ("wavemode_total44_45" period(180))
	(define "wavemode_total44_45"
		("wavemode_44_45" period(%period) cp(100))
		("wavemode_44_45" period(%period) cp(200))
	)
	("wavemode_total44_45" period(180))
	("wavemode_total44_45" period(300))
	("wavemode_total44_45" period(420))
	("wavemode_total44_45" period(600))
}

