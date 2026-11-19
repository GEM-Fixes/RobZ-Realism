; breed_kit.inc: weapon and grenade loads of the soldier breeds, by class across all factions (written by macrostd step kit).
;   Included from breed_macros.inc, so every breed that includes that file can call these. A macro exists for every load
;   used 4+ times (all factions together):
;   <class>_<weapon>: the weapon filled plus its standard ammo line (the load most breeds give it).
;   <class>_<weapon>_<rounds>: another load of that weapon used 4+ times (non-standard load; _<ammo>_<rounds> when the
;   ammo differs). kit_<class>: the same two lines for any load used less (a rare deviation shows as a kit_ call).
;   Grenades, mines and explosives: ("give" ...), ("give_chance" ...), ("give_1_or_2" ...) at the end of this file. Lines a breed has besides these stay literal
;   in the breed's order.

; ==== pistol ====
;   macro               weapon       ammo         rounds  uses  factions                    note
;   pistol_valter       valter       walther_mag  16      57    ger ger2 ger_ss             standard
;   pistol_valter_32    valter       walther_mag  32      16    axis_minor ger ger2 ger_ss  non-standard load, standard is 16
;   pistol_colt         colt         colt_mag     14      12    usa                         standard
;   pistol_colt_21      colt         colt_mag     21      6     usa                         non-standard load, standard is 14
;   pistol_frommer_37m  frommer_37m  9x17         35      6     axis_minor                  standard
;   pistol_luger        luger        walther_mag  32      6     axis_minor ger ger2 ger_ss  standard
;   pistol_webley       webley       webley_clip  36      6     eng                         standard
;   pistol_nagan        nagan        nagant_clip  28      5     rus rus_guard               standard
;   kit_pistol: 18 other loads (8 weapons)

; pistol_valter: item "valter" filled + 16 "ammo walther_mag" (standard, 57 uses)
;   e.g. ("pistol_valter")
(define "pistol_valter"
	{item "valter" filled}
	{item "ammo walther_mag" 16}
)

; pistol_valter_32: item "valter" filled + 32 "ammo walther_mag" (non-standard load, standard is 16, 16 uses)
;   e.g. ("pistol_valter_32")
(define "pistol_valter_32"
	{item "valter" filled}
	{item "ammo walther_mag" 32}
)

; pistol_colt: item "colt" filled + 14 "ammo colt_mag" (standard, 12 uses)
;   e.g. ("pistol_colt")
(define "pistol_colt"
	{item "colt" filled}
	{item "ammo colt_mag" 14}
)

; pistol_colt_21: item "colt" filled + 21 "ammo colt_mag" (non-standard load, standard is 14, 6 uses)
;   e.g. ("pistol_colt_21")
(define "pistol_colt_21"
	{item "colt" filled}
	{item "ammo colt_mag" 21}
)

; pistol_frommer_37m: item "frommer_37m" filled + 35 "ammo 9x17" (standard, 6 uses)
;   e.g. ("pistol_frommer_37m")
(define "pistol_frommer_37m"
	{item "frommer_37m" filled}
	{item "ammo 9x17" 35}
)

; pistol_luger: item "luger" filled + 32 "ammo walther_mag" (standard, 6 uses)
;   e.g. ("pistol_luger")
(define "pistol_luger"
	{item "luger" filled}
	{item "ammo walther_mag" 32}
)

; pistol_webley: item "webley" filled + 36 "ammo webley_clip" (standard, 6 uses)
;   e.g. ("pistol_webley")
(define "pistol_webley"
	{item "webley" filled}
	{item "ammo webley_clip" 36}
)

; pistol_nagan: item "nagan" filled + 28 "ammo nagant_clip" (standard, 5 uses)
;   e.g. ("pistol_nagan")
(define "pistol_nagan"
	{item "nagan" filled}
	{item "ammo nagant_clip" 28}
)

; kit_pistol: a pistol weapon filled + one ammo line, for loads used under 4 times
;   gun - weapon item name as in {item "<gun>" filled}
;   ammo - ammo item name after "ammo " (may contain spaces)
;   rounds - ammo count
;   e.g. ("kit_pistol" gun(beretta_m1934) ammo(9x17) rounds(35))
(define "kit_pistol"
	{item "%gun" filled}
	{item "ammo %ammo" %rounds}
)

; ==== smg ====
;   macro                   weapon              ammo               rounds  uses  factions                    note
;   smg_mp40                mp40                mp40_mag           192     73    axis_minor ger ger2 ger_ss  standard
;   smg_mp40_96             mp40                mp40_mag           96      14    ger ger2 ger_ss             non-standard load, standard is 192
;   smg_sg44                sg44                stg44_mag          180     47    ger ger2 ger_ss             standard
;   smg_sten_mk2            sten_mk2            sten_mag           128     28    eng                         standard
;   smg_type100smg          type100smg          type100_mag        180     25    jap                         standard
;   smg_sten_v              sten_v              sten_mag           224     20    eng                         standard
;   smg_sten_v_128          sten_v              sten_mag           128     4     eng                         non-standard load, standard is 224
;   smg_ppsh                ppsh                ppsh_mag           142     18    ger2 rus rus_guard          standard
;   smg_ppsh_213            ppsh                ppsh_mag           213     5     ger2 rus rus_guard          non-standard load, standard is 142
;   smg_ppsh41              ppsh41              ppsh41_mag         105     16    rus rus_guard               standard
;   smg_ppsh41_210          ppsh41              ppsh41_mag         210     6     rus rus_guard               non-standard load, standard is 105
;   smg_pps43               pps43               pps43_mag          210     14    rus rus_guard               standard
;   smg_pps43_105           pps43               pps43_mag          105     4     rus rus_guard               non-standard load, standard is 210
;   smg_thompson            thompson            thompson_m1a1_mag  150     13    usa                         standard
;   smg_m3a                 m3a                 m3a_mag            192     8     usa                         standard
;   smg_m3a_96              m3a                 m3a_mag            96      5     usa                         non-standard load, standard is 192
;   smg_mp41                mp41                mp40_mag           192     7     ger2 ger_ss                 standard
;   smg_suomi_m31           suomi_m31           ppsh_mag           210     7     axis_minor                  standard
;   smg_type100smg_bayonet  type100smg_bayonet  type100_mag        180     7     jap                         standard
;   smg_orita               orita               9x19               128     6     axis_minor                  standard
;   smg_orita_64            orita               9x19               64      4     axis_minor                  non-standard load, standard is 128
;   smg_m50reising          m50reising          m50reising_mag     150     4     usa                         standard
;   smg_mab_38a             mab_38a             mab_38a_mag        200     4     ger_ss                      standard
;   smg_type2smg            type2smg            type2_mag          200     4     jap                         standard
;   kit_smg: 46 other loads (19 weapons)

; smg_mp40: item "mp40" filled + 192 "ammo mp40_mag" (standard, 73 uses)
;   e.g. ("smg_mp40")
(define "smg_mp40"
	{item "mp40" filled}
	{item "ammo mp40_mag" 192}
)

; smg_mp40_96: item "mp40" filled + 96 "ammo mp40_mag" (non-standard load, standard is 192, 14 uses)
;   e.g. ("smg_mp40_96")
(define "smg_mp40_96"
	{item "mp40" filled}
	{item "ammo mp40_mag" 96}
)

; smg_sg44: item "sg44" filled + 180 "ammo stg44_mag" (standard, 47 uses)
;   e.g. ("smg_sg44")
(define "smg_sg44"
	{item "sg44" filled}
	{item "ammo stg44_mag" 180}
)

; smg_sten_mk2: item "sten_mk2" filled + 128 "ammo sten_mag" (standard, 28 uses)
;   e.g. ("smg_sten_mk2")
(define "smg_sten_mk2"
	{item "sten_mk2" filled}
	{item "ammo sten_mag" 128}
)

; smg_type100smg: item "type100smg" filled + 180 "ammo type100_mag" (standard, 25 uses)
;   e.g. ("smg_type100smg")
(define "smg_type100smg"
	{item "type100smg" filled}
	{item "ammo type100_mag" 180}
)

; smg_sten_v: item "sten_v" filled + 224 "ammo sten_mag" (standard, 20 uses)
;   e.g. ("smg_sten_v")
(define "smg_sten_v"
	{item "sten_v" filled}
	{item "ammo sten_mag" 224}
)

; smg_sten_v_128: item "sten_v" filled + 128 "ammo sten_mag" (non-standard load, standard is 224, 4 uses)
;   e.g. ("smg_sten_v_128")
(define "smg_sten_v_128"
	{item "sten_v" filled}
	{item "ammo sten_mag" 128}
)

; smg_ppsh: item "ppsh" filled + 142 "ammo ppsh_mag" (standard, 18 uses)
;   e.g. ("smg_ppsh")
(define "smg_ppsh"
	{item "ppsh" filled}
	{item "ammo ppsh_mag" 142}
)

; smg_ppsh_213: item "ppsh" filled + 213 "ammo ppsh_mag" (non-standard load, standard is 142, 5 uses)
;   e.g. ("smg_ppsh_213")
(define "smg_ppsh_213"
	{item "ppsh" filled}
	{item "ammo ppsh_mag" 213}
)

; smg_ppsh41: item "ppsh41" filled + 105 "ammo ppsh41_mag" (standard, 16 uses)
;   e.g. ("smg_ppsh41")
(define "smg_ppsh41"
	{item "ppsh41" filled}
	{item "ammo ppsh41_mag" 105}
)

; smg_ppsh41_210: item "ppsh41" filled + 210 "ammo ppsh41_mag" (non-standard load, standard is 105, 6 uses)
;   e.g. ("smg_ppsh41_210")
(define "smg_ppsh41_210"
	{item "ppsh41" filled}
	{item "ammo ppsh41_mag" 210}
)

; smg_pps43: item "pps43" filled + 210 "ammo pps43_mag" (standard, 14 uses)
;   e.g. ("smg_pps43")
(define "smg_pps43"
	{item "pps43" filled}
	{item "ammo pps43_mag" 210}
)

; smg_pps43_105: item "pps43" filled + 105 "ammo pps43_mag" (non-standard load, standard is 210, 4 uses)
;   e.g. ("smg_pps43_105")
(define "smg_pps43_105"
	{item "pps43" filled}
	{item "ammo pps43_mag" 105}
)

; smg_thompson: item "thompson" filled + 150 "ammo thompson_m1a1_mag" (standard, 13 uses)
;   e.g. ("smg_thompson")
(define "smg_thompson"
	{item "thompson" filled}
	{item "ammo thompson_m1a1_mag" 150}
)

; smg_m3a: item "m3a" filled + 192 "ammo m3a_mag" (standard, 8 uses)
;   e.g. ("smg_m3a")
(define "smg_m3a"
	{item "m3a" filled}
	{item "ammo m3a_mag" 192}
)

; smg_m3a_96: item "m3a" filled + 96 "ammo m3a_mag" (non-standard load, standard is 192, 5 uses)
;   e.g. ("smg_m3a_96")
(define "smg_m3a_96"
	{item "m3a" filled}
	{item "ammo m3a_mag" 96}
)

; smg_mp41: item "mp41" filled + 192 "ammo mp40_mag" (standard, 7 uses)
;   e.g. ("smg_mp41")
(define "smg_mp41"
	{item "mp41" filled}
	{item "ammo mp40_mag" 192}
)

; smg_suomi_m31: item "suomi_m31" filled + 210 "ammo ppsh_mag" (standard, 7 uses)
;   e.g. ("smg_suomi_m31")
(define "smg_suomi_m31"
	{item "suomi_m31" filled}
	{item "ammo ppsh_mag" 213}
)

; smg_type100smg_bayonet: item "type100smg_bayonet" filled + 180 "ammo type100_mag" (standard, 7 uses)
;   e.g. ("smg_type100smg_bayonet")
(define "smg_type100smg_bayonet"
	{item "type100smg_bayonet" filled}
	{item "ammo type100_mag" 180}
)

; smg_orita: item "orita" filled + 128 "ammo 9x19" (standard, 6 uses)
;   e.g. ("smg_orita")
(define "smg_orita"
	{item "orita" filled}
	{item "ammo 9x19" 128}
)

; smg_orita_64: item "orita" filled + 64 "ammo 9x19" (non-standard load, standard is 128, 4 uses)
;   e.g. ("smg_orita_64")
(define "smg_orita_64"
	{item "orita" filled}
	{item "ammo 9x19" 64}
)

; smg_m50reising: item "m50reising" filled + 150 "ammo m50reising_mag" (standard, 4 uses)
;   e.g. ("smg_m50reising")
(define "smg_m50reising"
	{item "m50reising" filled}
	{item "ammo m50reising_mag" 150}
)

; smg_mab_38a: item "mab_38a" filled + 200 "ammo mab_38a_mag" (standard, 4 uses)
;   e.g. ("smg_mab_38a")
(define "smg_mab_38a"
	{item "mab_38a" filled}
	{item "ammo mab_38a_mag" 200}
)

; smg_type2smg: item "type2smg" filled + 200 "ammo type2_mag" (standard, 4 uses)
;   e.g. ("smg_type2smg")
(define "smg_type2smg"
	{item "type2smg" filled}
	{item "ammo type2_mag" 200}
)

; kit_smg: a smg weapon filled + one ammo line, for loads used under 4 times
;   gun - weapon item name as in {item "<gun>" filled}
;   ammo - ammo item name after "ammo " (may contain spaces)
;   rounds - ammo count
;   e.g. ("kit_smg" gun(mp40) ammo(mp40_mag) rounds(120))
(define "kit_smg"
	{item "%gun" filled}
	{item "ammo %ammo" %rounds}
)

; ==== rifle ====
;   macro                      weapon               ammo              rounds  uses  factions                    note
;   rifle_mauzer               mauzer               mauser_clip       60      106   axis_minor ger ger2 ger_ss  standard
;   rifle_mauzer_80            mauzer               mauser_clip       80      4     ger                         non-standard load, standard is 60
;   rifle_garand               garand               garand_clip       80      51    usa                         standard
;   rifle_mosin                mosin                mosin_clip        60      30    ger_ss rus rus_guard        standard
;   rifle_em3                  em3                  british303_clip   50      28    eng                         standard
;   rifle_type99rifle          type99rifle          arisaka7-7_clip   60      23    jap                         standard
;   rifle_mauzer_vet           mauzer_vet           mauser_clip       60      20    ger ger2 ger_ss             standard
;   rifle_mauzer_vet_120       mauzer_vet           mauser_clip       120     7     ger ger2 ger_ss             non-standard load, standard is 60
;   rifle_svt40                svt40                svt40_mag         20      14    rus rus_guard               standard
;   rifle_bar_rifle            bar_rifle            bar_mag           240     12    usa                         standard
;   rifle_m1_carbine           m1_carbine           m1carbine_mag     90      12    usa                         standard
;   rifle_mosin_vet            mosin_vet            mosin_clip        60      11    rus rus_guard               standard
;   rifle_g41                  g41                  mauser_clip       80      10    ger ger_ss                  standard
;   rifle_m1a1_carbine         m1a1_carbine         m1carbine_mag     90      9     usa                         standard
;   rifle_type38rifle_bayonet  type38rifle_bayonet  arisaka6-5_clip   60      9     jap                         standard
;   rifle_mauzer_s             mauzer_s             mauser_clip       60      8     ger ger_ss                  standard
;   rifle_type44_carbine       type44_carbine       arisaka6-5_clip   60      8     jap                         standard
;   rifle_fg42_rifle           fg42_rifle           fg42_mag          160     7     ger ger2                    standard
;   rifle_mosin_fin            mosin_fin            7x53              120     7     axis_minor                  standard
;   rifle_type2rifle           type2rifle           arisaka7-7_clip   100     6     jap                         standard
;   rifle_type38rifle          type38rifle          arisaka6-5_clip   60      6     jap                         standard
;   rifle_type99rifle_bayonet  type99rifle_bayonet  arisaka7-7_clip   60      6     jap                         standard
;   rifle_em3_vet              em3_vet              british303_clip   100     5     eng                         standard
;   rifle_mauzer_s_vet         mauzer_s_vet         mauser_clip       60      5     ger ger2 ger_ss             standard
;   rifle_johnson_m1941_rifle  johnson_m1941_rifle  m1941lmg_mag      240     4     usa                         standard
;   rifle_m1903a4              m1903a4              springfield_clip  100     4     usa                         standard
;   kit_rifle: 76 other loads (40 weapons)

; rifle_mauzer: item "mauzer" filled + 60 "ammo mauser_clip" (standard, 106 uses)
;   e.g. ("rifle_mauzer")
(define "rifle_mauzer"
	{item "mauzer" filled}
	{item "ammo mauser_clip" 60}
)

; rifle_mauzer_80: item "mauzer" filled + 80 "ammo mauser_clip" (non-standard load, standard is 60, 4 uses)
;   e.g. ("rifle_mauzer_80")
(define "rifle_mauzer_80"
	{item "mauzer" filled}
	{item "ammo mauser_clip" 80}
)

; rifle_garand: item "garand" filled + 80 "ammo garand_clip" (standard, 51 uses)
;   e.g. ("rifle_garand")
(define "rifle_garand"
	{item "garand" filled}
	{item "ammo garand_clip" 80}
)

; rifle_mosin: item "mosin" filled + 60 "ammo mosin_clip" (standard, 30 uses)
;   e.g. ("rifle_mosin")
(define "rifle_mosin"
	{item "mosin" filled}
	{item "ammo mosin_clip" 60}
)

; rifle_em3: item "em3" filled + 50 "ammo british303_clip" (standard, 28 uses)
;   e.g. ("rifle_em3")
(define "rifle_em3"
	{item "em3" filled}
	{item "ammo british303_clip" 50}
)

; rifle_type99rifle: item "type99rifle" filled + 60 "ammo arisaka7-7_clip" (standard, 23 uses)
;   e.g. ("rifle_type99rifle")
(define "rifle_type99rifle"
	{item "type99rifle" filled}
	{item "ammo arisaka7-7_clip" 60}
)

; rifle_mauzer_vet: item "mauzer_vet" filled + 60 "ammo mauser_clip" (standard, 20 uses)
;   e.g. ("rifle_mauzer_vet")
(define "rifle_mauzer_vet"
	{item "mauzer_vet" filled}
	{item "ammo mauser_clip" 60}
)

; rifle_mauzer_vet_120: item "mauzer_vet" filled + 120 "ammo mauser_clip" (non-standard load, standard is 60, 7 uses)
;   e.g. ("rifle_mauzer_vet_120")
(define "rifle_mauzer_vet_120"
	{item "mauzer_vet" filled}
	{item "ammo mauser_clip" 120}
)

; rifle_svt40: item "svt40" filled + 20 "ammo svt40_mag" (standard, 14 uses)
;   e.g. ("rifle_svt40")
(define "rifle_svt40"
	{item "svt40" filled}
	{item "ammo svt40_mag" 20}
)

; rifle_bar_rifle: item "bar_rifle" filled + 240 "ammo bar_mag" (standard, 12 uses)
;   e.g. ("rifle_bar_rifle")
(define "rifle_bar_rifle"
	{item "bar_rifle" filled}
	{item "ammo bar_mag" 240}
)

; rifle_m1_carbine: item "m1_carbine" filled + 90 "ammo m1carbine_mag" (standard, 12 uses)
;   e.g. ("rifle_m1_carbine")
(define "rifle_m1_carbine"
	{item "m1_carbine" filled}
	{item "ammo m1carbine_mag" 90}
)

; rifle_mosin_vet: item "mosin_vet" filled + 60 "ammo mosin_clip" (standard, 11 uses)
;   e.g. ("rifle_mosin_vet")
(define "rifle_mosin_vet"
	{item "mosin_vet" filled}
	{item "ammo mosin_clip" 60}
)

; rifle_g41: item "g41" filled + 80 "ammo mauser_clip" (standard, 10 uses)
;   e.g. ("rifle_g41")
(define "rifle_g41"
	{item "g41" filled}
	{item "ammo mauser_clip" 80}
)

; rifle_m1a1_carbine: item "m1a1_carbine" filled + 90 "ammo m1carbine_mag" (standard, 9 uses)
;   e.g. ("rifle_m1a1_carbine")
(define "rifle_m1a1_carbine"
	{item "m1a1_carbine" filled}
	{item "ammo m1carbine_mag" 90}
)

; rifle_type38rifle_bayonet: item "type38rifle_bayonet" filled + 60 "ammo arisaka6-5_clip" (standard, 9 uses)
;   e.g. ("rifle_type38rifle_bayonet")
(define "rifle_type38rifle_bayonet"
	{item "type38rifle_bayonet" filled}
	{item "ammo arisaka6-5_clip" 60}
)

; rifle_mauzer_s: item "mauzer_s" filled + 60 "ammo mauser_clip" (standard, 8 uses)
;   e.g. ("rifle_mauzer_s")
(define "rifle_mauzer_s"
	{item "mauzer_s" filled}
	{item "ammo mauser_clip" 60}
)

; rifle_type44_carbine: item "type44_carbine" filled + 60 "ammo arisaka6-5_clip" (standard, 8 uses)
;   e.g. ("rifle_type44_carbine")
(define "rifle_type44_carbine"
	{item "type44_carbine" filled}
	{item "ammo arisaka6-5_clip" 60}
)

; rifle_fg42_rifle: item "fg42_rifle" filled + 160 "ammo fg42_mag" (standard, 7 uses)
;   e.g. ("rifle_fg42_rifle")
(define "rifle_fg42_rifle"
	{item "fg42_rifle" filled}
	{item "ammo fg42_mag" 160}
)

; rifle_mosin_fin: item "mosin_fin" filled + 120 "ammo 7x53" (standard, 7 uses)
;   e.g. ("rifle_mosin_fin")
(define "rifle_mosin_fin"
	{item "mosin_fin" filled}
	{item "ammo 7x53" 120}
)

; rifle_type2rifle: item "type2rifle" filled + 100 "ammo arisaka7-7_clip" (standard, 6 uses)
;   e.g. ("rifle_type2rifle")
(define "rifle_type2rifle"
	{item "type2rifle" filled}
	{item "ammo arisaka7-7_clip" 100}
)

; rifle_type38rifle: item "type38rifle" filled + 60 "ammo arisaka6-5_clip" (standard, 6 uses)
;   e.g. ("rifle_type38rifle")
(define "rifle_type38rifle"
	{item "type38rifle" filled}
	{item "ammo arisaka6-5_clip" 60}
)

; rifle_type99rifle_bayonet: item "type99rifle_bayonet" filled + 60 "ammo arisaka7-7_clip" (standard, 6 uses)
;   e.g. ("rifle_type99rifle_bayonet")
(define "rifle_type99rifle_bayonet"
	{item "type99rifle_bayonet" filled}
	{item "ammo arisaka7-7_clip" 60}
)

; rifle_em3_vet: item "em3_vet" filled + 100 "ammo british303_clip" (standard, 5 uses)
;   e.g. ("rifle_em3_vet")
(define "rifle_em3_vet"
	{item "em3_vet" filled}
	{item "ammo british303_clip" 100}
)

; rifle_mauzer_s_vet: item "mauzer_s_vet" filled + 60 "ammo mauser_clip" (standard, 5 uses)
;   e.g. ("rifle_mauzer_s_vet")
(define "rifle_mauzer_s_vet"
	{item "mauzer_s_vet" filled}
	{item "ammo mauser_clip" 60}
)

; rifle_johnson_m1941_rifle: item "johnson_m1941_rifle" filled + 240 "ammo m1941lmg_mag" (standard, 4 uses)
;   e.g. ("rifle_johnson_m1941_rifle")
(define "rifle_johnson_m1941_rifle"
	{item "johnson_m1941_rifle" filled}
	{item "ammo m1941lmg_mag" 240}
)

; rifle_m1903a4: item "m1903a4" filled + 100 "ammo springfield_clip" (standard, 4 uses)
;   e.g. ("rifle_m1903a4")
(define "rifle_m1903a4"
	{item "m1903a4" filled}
	{item "ammo springfield_clip" 100}
)

; kit_rifle: a rifle weapon filled + one ammo line, for loads used under 4 times
;   gun - weapon item name as in {item "<gun>" filled}
;   ammo - ammo item name after "ammo " (may contain spaces)
;   rounds - ammo count
;   e.g. ("kit_rifle" gun(mauzer) ammo(mauser_rifle mauser) rounds(120))
(define "kit_rifle"
	{item "%gun" filled}
	{item "ammo %ammo" %rounds}
)

; ==== mgun ====
;   macro                weapon          ammo              rounds  uses  factions                   note
;   mgun_mg34            mg34            mg_mauser drum    300     19    ger ger2 ger_ss rus_guard  standard
;   mgun_mg42_inf        mg42_inf        mg_mauser drum    300     19    ger ger2 ger_ss            standard
;   mgun_bren            bren            bren_mag          224     15    eng                        standard
;   mgun_mg42_inf_250    mg42_inf_250    mg_mauser belt    300     12    ger ger2 ger_ss            standard
;   mgun_type99_mg       type99_mg       type99_mag        180     10    jap                        standard
;   mgun_browning_m19a6  browning_m19a6  springfield_belt  250     6     usa                        standard
;   mgun_zb30            zb30            zb30_mag          300     4     ger_ss                     standard
;   kit_mgun: 17 other loads (10 weapons)

; mgun_mg34: item "mg34" filled + 300 "ammo mg_mauser drum" (standard, 19 uses)
;   e.g. ("mgun_mg34")
(define "mgun_mg34"
	{item "mg34" filled}
	{item "ammo mg_mauser drum" 300}
)

; mgun_mg42_inf: item "mg42_inf" filled + 300 "ammo mg_mauser drum" (standard, 19 uses)
;   e.g. ("mgun_mg42_inf")
(define "mgun_mg42_inf"
	{item "mg42_inf" filled}
	{item "ammo mg_mauser drum" 300}
)

; mgun_bren: item "bren" filled + 224 "ammo bren_mag" (standard, 15 uses)
;   e.g. ("mgun_bren")
(define "mgun_bren"
	{item "bren" filled}
	{item "ammo bren_mag" 224}
)

; mgun_mg42_inf_250: item "mg42_inf_250" filled + 300 "ammo mg_mauser belt" (standard, 12 uses)
;   e.g. ("mgun_mg42_inf_250")
(define "mgun_mg42_inf_250"
	{item "mg42_inf_250" filled}
	{item "ammo mg_mauser belt" 300}
)

; mgun_type99_mg: item "type99_mg" filled + 180 "ammo type99_mag" (standard, 10 uses)
;   e.g. ("mgun_type99_mg")
(define "mgun_type99_mg"
	{item "type99_mg" filled}
	{item "ammo type99_mag" 180}
)

; mgun_browning_m19a6: item "browning_m19a6" filled + 250 "ammo springfield_belt" (standard, 6 uses)
;   e.g. ("mgun_browning_m19a6")
(define "mgun_browning_m19a6"
	{item "browning_m19a6" filled}
	{item "ammo springfield_belt" 250}
)

; mgun_zb30: item "zb30" filled + 300 "ammo zb30_mag" (standard, 4 uses)
;   e.g. ("mgun_zb30")
(define "mgun_zb30"
	{item "zb30" filled}
	{item "ammo zb30_mag" 300}
)

; kit_mgun: a mgun weapon filled + one ammo line, for loads used under 4 times
;   gun - weapon item name as in {item "<gun>" filled}
;   ammo - ammo item name after "ammo " (may contain spaces)
;   rounds - ammo count
;   e.g. ("kit_mgun" gun(zb_vz26) ammo(zb_vz26_mag) rounds(120))
(define "kit_mgun"
	{item "%gun" filled}
	{item "ammo %ammo" %rounds}
)

; ==== at ====
;   macro            weapon                  ammo          rounds  uses  factions  note
;   at_type_4at      weapon weapon type_4at  type_4        5       5     jap       standard
;   at_panzershreck  weapon panzershreck     panzershreck  7       4     ger_ss    standard
;   kit_at: 7 other loads (4 weapons)

; at_type_4at: item "weapon weapon type_4at" filled + 5 "ammo type_4" (standard, 5 uses)
;   e.g. ("at_type_4at")
(define "at_type_4at"
	{item "weapon weapon type_4at" filled}
	{item "ammo type_4" 5}
)

; at_panzershreck: item "weapon panzershreck" filled + 7 "ammo panzershreck" (standard, 4 uses)
;   e.g. ("at_panzershreck")
(define "at_panzershreck"
	{item "weapon panzershreck" filled}
	{item "ammo panzershreck" 7}
)

; kit_at: a at weapon filled + one ammo line, for loads used under 4 times
;   gun - weapon item name as in {item "<gun>" filled}
;   ammo - ammo item name after "ammo " (may contain spaces)
;   rounds - ammo count
;   e.g. ("kit_at" gun(boyes) ammo(ptr) rounds(50))
(define "kit_at"
	{item "%gun" filled}
	{item "ammo %ammo" %rounds}
)

; ==== mortar ====
;   kit_mortar: 4 other loads (2 weapons)

; kit_mortar: a mortar weapon filled + one ammo line, for loads used under 4 times
;   gun - weapon item name as in {item "<gun>" filled}
;   ammo - ammo item name after "ammo " (may contain spaces)
;   rounds - ammo count
;   e.g. ("kit_mortar" gun(mortar_mkvii) ammo(mortar50 eng fg) rounds(6))
(define "kit_mortar"
	{item "%gun" filled}
	{item "ammo %ammo" %rounds}
)

; ==== items by count or by chance (grenades, mines, explosives) ====
;   ("give" item(grenade m24) count(2))                 always 2
;   ("give_chance" item(grenade m24x5) chance(25))      one, with that chance in percent; otherwise none
;   ("give_1_or_2" item(smoke grenade))                 one, and a 50% chance of a second
;   item = the item's tag words as the game looks them up, e.g. grenade f1, smoke grenade, hohlladung grenade.
;   chance is one of: 12 (12.5%), 25, 37 (37.5%), 50. The game has no chance field; it draws the amount as
;   whole number of (centre + a random part within +/- spread + 0.5), so each chance is a fixed centre and spread:
;     chance  written as     how it comes out
;     12      -1 2           1 in 12.5% of soldiers (kept as the mod had it)
;     25      0 1            1 in 25%
;     37      0.25 1         1 in 37.5%
;     50      0.5 0.5        1 in 50%
;     1 or 2  1.5 0.5        1 in 50%, 2 in 50%

; give: a fixed number of one item
;   item - tag words of the item
;   count - how many
;   e.g. ("give" item(grenade m24) count(2))
(define "give"
	{item "%item" %count}
)

; give_chance: one of an item with a chance, otherwise none
;   item - tag words of the item
;   chance - 12, 25, 37 or 50 (percent; 12 = 12.5, 37 = 37.5)
;   e.g. ("give_chance" item(grenade m24x5) chance(25))
(define "give_chance"
	("give_chance_%chance" item(%item))
)

; give_chance_12: 12.5% chance of one (called by give_chance)
;   item - tag words of the item
;   e.g. ("give_chance_12" item(grenade m24x5))
(define "give_chance_12"
	{item "%item" -1 2}
)

; give_chance_25: 25% chance of one (called by give_chance)
;   item - tag words of the item
;   e.g. ("give_chance_25" item(grenade m24x5))
(define "give_chance_25"
	{item "%item" 0 1}
)

; give_chance_37: 37.5% chance of one (called by give_chance)
;   item - tag words of the item
;   e.g. ("give_chance_37" item(grenade m24x5))
(define "give_chance_37"
	{item "%item" 0.25 1}
)

; give_chance_50: 50% chance of one (called by give_chance)
;   item - tag words of the item
;   e.g. ("give_chance_50" item(grenade m24x5))
(define "give_chance_50"
	{item "%item" 0.5 0.5}
)

; give_1_or_2: one of an item, and a 50% chance of a second
;   item - tag words of the item
;   e.g. ("give_1_or_2" item(smoke grenade))
(define "give_1_or_2"
	{item "%item" 1.5 0.5}
)
