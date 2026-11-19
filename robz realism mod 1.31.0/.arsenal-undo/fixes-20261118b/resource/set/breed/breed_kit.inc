; breed_kit.inc: weapon and grenade loads of the soldier breeds, by class across all factions (written by macrostd step kit).
;   Included from breed_macros.inc, so every breed that includes that file can call these. A macro exists for every load
;   used 4+ times (all factions together):
;   <class>_<weapon>: the weapon filled plus its standard ammo line (the load most breeds give it).
;   <class>_<weapon>_<rounds>: another load of that weapon used 4+ times (non-standard load; _<ammo>_<rounds> when the
;   ammo differs). kit_<class>: the same two lines for any load used less (a rare deviation shows as a kit_ call).
;   <kind>_<item>_x<count>: one grenade-type item line (kind at = at_grenade). Lines a breed has besides these stay literal
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
	{item "ammo ppsh_mag" 210}
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

; ==== grenades: frag ====
;   macro                  item               count    uses  factions
;   frag_m24_x2            "grenade m24"      2        244   axis_minor ger ger2 ger_ss
;   frag_m61_x2            "grenade m61"      2        100   usa
;   frag_f1_x2             "grenade f1"       2        97    rus rus_guard
;   frag_mk1_x2            "grenade mk1"      2        72    eng
;   frag_type97_x2         "grenade type97"   2        43    jap
;   frag_m39_x2            "grenade m39"      2        42    ger ger2 ger_ss
;   frag_type97_x4         "grenade type97"   4        22    jap
;   frag_f1_x1             "grenade f1"       1        13    rus rus_guard
;   frag_m24               "grenade m24"      -        13    axis_minor ger
;   frag_satchel_x1        "grenade satchel"  1        13    rus rus_guard usa
;   frag_type97_x1         "grenade type97"   1        13    jap
;   frag_kasapanos_2kg_x1  "kasapanos_2kg"    1        13    axis_minor
;   frag_mk1_x1            "grenade mk1"      1        12    eng
;   frag_f1_x1p5_0p5       "grenade f1"       1.5 0.5  6     rus
;   frag_m24_x1            "grenade m24"      1        6     axis_minor ger_ss
;   frag_type97_x3         "grenade type97"   3        6     jap
;   frag_m24_grenade_x2    "m24 grenade"      2        6     axis_minor ger
;   frag_f1_x3             "grenade f1"       3        5     axis_minor
;   frag_satchel_x3        "grenade satchel"  3        5     rus rus_guard usa
;   frag_type99_x1         "grenade type99"   1        5     jap
;   frag_m24_grenade       "m24 grenade"      -        5     axis_minor ger
;   frag_type97            "grenade type97"   -        4     jap

; frag_m24_x2: item "grenade m24", count 2 (frag, 244 uses)
;   e.g. ("frag_m24_x2")
(define "frag_m24_x2"
	{item "grenade m24" 2}
)

; frag_m61_x2: item "grenade m61", count 2 (frag, 100 uses)
;   e.g. ("frag_m61_x2")
(define "frag_m61_x2"
	{item "grenade m61" 2}
)

; frag_f1_x2: item "grenade f1", count 2 (frag, 97 uses)
;   e.g. ("frag_f1_x2")
(define "frag_f1_x2"
	{item "grenade f1" 2}
)

; frag_mk1_x2: item "grenade mk1", count 2 (frag, 72 uses)
;   e.g. ("frag_mk1_x2")
(define "frag_mk1_x2"
	{item "grenade mk1" 2}
)

; frag_type97_x2: item "grenade type97", count 2 (frag, 43 uses)
;   e.g. ("frag_type97_x2")
(define "frag_type97_x2"
	{item "grenade type97" 2}
)

; frag_m39_x2: item "grenade m39", count 2 (frag, 42 uses)
;   e.g. ("frag_m39_x2")
(define "frag_m39_x2"
	{item "grenade m39" 2}
)

; frag_type97_x4: item "grenade type97", count 4 (frag, 22 uses, not the most used count of this item)
;   e.g. ("frag_type97_x4")
(define "frag_type97_x4"
	{item "grenade type97" 4}
)

; frag_f1_x1: item "grenade f1", count 1 (frag, 13 uses, not the most used count of this item)
;   e.g. ("frag_f1_x1")
(define "frag_f1_x1"
	{item "grenade f1" 1}
)

; frag_m24: item "grenade m24", no count (frag, 13 uses, not the most used count of this item)
;   e.g. ("frag_m24")
(define "frag_m24"
	{item "grenade m24"}
)

; frag_satchel_x1: item "grenade satchel", count 1 (frag, 13 uses)
;   e.g. ("frag_satchel_x1")
(define "frag_satchel_x1"
	{item "grenade satchel" 1}
)

; frag_type97_x1: item "grenade type97", count 1 (frag, 13 uses, not the most used count of this item)
;   e.g. ("frag_type97_x1")
(define "frag_type97_x1"
	{item "grenade type97" 1}
)

; frag_kasapanos_2kg_x1: item "kasapanos_2kg", count 1 (frag, 13 uses)
;   e.g. ("frag_kasapanos_2kg_x1")
(define "frag_kasapanos_2kg_x1"
	{item "kasapanos_2kg" 1}
)

; frag_mk1_x1: item "grenade mk1", count 1 (frag, 12 uses, not the most used count of this item)
;   e.g. ("frag_mk1_x1")
(define "frag_mk1_x1"
	{item "grenade mk1" 1}
)

; frag_f1_x1p5_0p5: item "grenade f1", count 1.5 0.5 (frag, 6 uses, not the most used count of this item)
;   e.g. ("frag_f1_x1p5_0p5")
(define "frag_f1_x1p5_0p5"
	{item "grenade f1" 1.5 0.5}
)

; frag_m24_x1: item "grenade m24", count 1 (frag, 6 uses, not the most used count of this item)
;   e.g. ("frag_m24_x1")
(define "frag_m24_x1"
	{item "grenade m24" 1}
)

; frag_type97_x3: item "grenade type97", count 3 (frag, 6 uses, not the most used count of this item)
;   e.g. ("frag_type97_x3")
(define "frag_type97_x3"
	{item "grenade type97" 3}
)

; frag_m24_grenade_x2: item "m24 grenade", count 2 (frag, 6 uses)
;   e.g. ("frag_m24_grenade_x2")
(define "frag_m24_grenade_x2"
	{item "m24 grenade" 2}
)

; frag_f1_x3: item "grenade f1", count 3 (frag, 5 uses, not the most used count of this item)
;   e.g. ("frag_f1_x3")
(define "frag_f1_x3"
	{item "grenade f1" 3}
)

; frag_satchel_x3: item "grenade satchel", count 3 (frag, 5 uses, not the most used count of this item)
;   e.g. ("frag_satchel_x3")
(define "frag_satchel_x3"
	{item "grenade satchel" 3}
)

; frag_type99_x1: item "grenade type99", count 1 (frag, 5 uses)
;   e.g. ("frag_type99_x1")
(define "frag_type99_x1"
	{item "grenade type99" 1}
)

; frag_m24_grenade: item "m24 grenade", no count (frag, 5 uses, not the most used count of this item)
;   e.g. ("frag_m24_grenade")
(define "frag_m24_grenade"
	{item "m24 grenade"}
)

; frag_type97: item "grenade type97", no count (frag, 4 uses, not the most used count of this item)
;   e.g. ("frag_type97")
(define "frag_type97"
	{item "grenade type97"}
)

; ==== grenades: at ====
;   macro                             item                  count  uses  factions
;   at_grenade_m24x5_x0_1             "grenade m24x5"       0 1    57    ger ger2
;   at_grenade_type3at_a_x1           "grenade type3at_a"   1      52    jap
;   at_grenade_n73at_x1               "grenade n73at"       1      48    eng
;   at_grenade_m24x5                  "grenade m24x5"       -      46    ger ger2 ger_ss
;   at_grenade_hohlladung             "hohlladung grenade"  -      36    axis_minor ger ger2 ger_ss
;   at_grenade_m24x5_xm1_2            "grenade m24x5"       -1 2   33    ger ger_ss
;   at_grenade_m24x5_grenade          "m24x5 grenade"       -      22    axis_minor ger_ss
;   at_grenade_rpg40_x1               "grenade rpg40"       1      20    rus rus_guard
;   at_grenade_type3at_a_x2           "grenade type3at_a"   2      20    jap
;   at_grenade_rpg43_x1               "grenade rpg43"       1      18    rus rus_guard
;   at_grenade_m24x5_x1               "grenade m24x5"       1      16    axis_minor ger ger2 ger_ss
;   at_grenade_pwm1                   "grenade pwm1"        -      15    ger ger2 ger_ss
;   at_grenade_rpg40_x0_1             "grenade rpg40"       0 1    11    rus rus_guard
;   at_grenade_n73at                  "grenade n73at"       -      10    eng
;   at_grenade_rg42x3_x1              "rg42x3 grenade"      1      9     rus
;   at_grenade_hohlladung_x1          "hohlladung grenade"  1      7     ger_ss
;   at_grenade_kasapanos_4kg_x1       "kasapanos_4kg"       1      7     axis_minor
;   at_grenade_grenade_hohlladung_x1  "grenade hohlladung"  1      6     ger_ss
;   at_grenade_rpg43_x0_1             "grenade rpg43"       0 1    5     rus_guard
;   at_grenade_grenade_hohlladung     "grenade hohlladung"  -      4     ger

; at_grenade_m24x5_x0_1: item "grenade m24x5", count 0 1 (at, 57 uses)
;   e.g. ("at_grenade_m24x5_x0_1")
(define "at_grenade_m24x5_x0_1"
	{item "grenade m24x5" 0 1}
)

; at_grenade_type3at_a_x1: item "grenade type3at_a", count 1 (at, 52 uses)
;   e.g. ("at_grenade_type3at_a_x1")
(define "at_grenade_type3at_a_x1"
	{item "grenade type3at_a" 1}
)

; at_grenade_n73at_x1: item "grenade n73at", count 1 (at, 48 uses)
;   e.g. ("at_grenade_n73at_x1")
(define "at_grenade_n73at_x1"
	{item "grenade n73at" 1}
)

; at_grenade_m24x5: item "grenade m24x5", no count (at, 46 uses, not the most used count of this item)
;   e.g. ("at_grenade_m24x5")
(define "at_grenade_m24x5"
	{item "grenade m24x5"}
)

; at_grenade_hohlladung: item "hohlladung grenade", no count (at, 36 uses)
;   e.g. ("at_grenade_hohlladung")
(define "at_grenade_hohlladung"
	{item "hohlladung grenade"}
)

; at_grenade_m24x5_xm1_2: item "grenade m24x5", count -1 2 (at, 33 uses, not the most used count of this item)
;   e.g. ("at_grenade_m24x5_xm1_2")
(define "at_grenade_m24x5_xm1_2"
	{item "grenade m24x5" -1 2}
)

; at_grenade_m24x5_grenade: item "m24x5 grenade", no count (at, 22 uses)
;   e.g. ("at_grenade_m24x5_grenade")
(define "at_grenade_m24x5_grenade"
	{item "m24x5 grenade"}
)

; at_grenade_rpg40_x1: item "grenade rpg40", count 1 (at, 20 uses)
;   e.g. ("at_grenade_rpg40_x1")
(define "at_grenade_rpg40_x1"
	{item "grenade rpg40" 1}
)

; at_grenade_type3at_a_x2: item "grenade type3at_a", count 2 (at, 20 uses, not the most used count of this item)
;   e.g. ("at_grenade_type3at_a_x2")
(define "at_grenade_type3at_a_x2"
	{item "grenade type3at_a" 2}
)

; at_grenade_rpg43_x1: item "grenade rpg43", count 1 (at, 18 uses)
;   e.g. ("at_grenade_rpg43_x1")
(define "at_grenade_rpg43_x1"
	{item "grenade rpg43" 1}
)

; at_grenade_m24x5_x1: item "grenade m24x5", count 1 (at, 16 uses, not the most used count of this item)
;   e.g. ("at_grenade_m24x5_x1")
(define "at_grenade_m24x5_x1"
	{item "grenade m24x5" 1}
)

; at_grenade_pwm1: item "grenade pwm1", no count (at, 15 uses)
;   e.g. ("at_grenade_pwm1")
(define "at_grenade_pwm1"
	{item "grenade pwm1"}
)

; at_grenade_rpg40_x0_1: item "grenade rpg40", count 0 1 (at, 11 uses, not the most used count of this item)
;   e.g. ("at_grenade_rpg40_x0_1")
(define "at_grenade_rpg40_x0_1"
	{item "grenade rpg40" 0 1}
)

; at_grenade_n73at: item "grenade n73at", no count (at, 10 uses, not the most used count of this item)
;   e.g. ("at_grenade_n73at")
(define "at_grenade_n73at"
	{item "grenade n73at"}
)

; at_grenade_rg42x3_x1: item "rg42x3 grenade", count 1 (at, 9 uses)
;   e.g. ("at_grenade_rg42x3_x1")
(define "at_grenade_rg42x3_x1"
	{item "rg42x3 grenade" 1}
)

; at_grenade_hohlladung_x1: item "hohlladung grenade", count 1 (at, 7 uses, not the most used count of this item)
;   e.g. ("at_grenade_hohlladung_x1")
(define "at_grenade_hohlladung_x1"
	{item "hohlladung grenade" 1}
)

; at_grenade_kasapanos_4kg_x1: item "kasapanos_4kg", count 1 (at, 7 uses)
;   e.g. ("at_grenade_kasapanos_4kg_x1")
(define "at_grenade_kasapanos_4kg_x1"
	{item "kasapanos_4kg" 1}
)

; at_grenade_grenade_hohlladung_x1: item "grenade hohlladung", count 1 (at, 6 uses)
;   e.g. ("at_grenade_grenade_hohlladung_x1")
(define "at_grenade_grenade_hohlladung_x1"
	{item "grenade hohlladung" 1}
)

; at_grenade_rpg43_x0_1: item "grenade rpg43", count 0 1 (at, 5 uses, not the most used count of this item)
;   e.g. ("at_grenade_rpg43_x0_1")
(define "at_grenade_rpg43_x0_1"
	{item "grenade rpg43" 0 1}
)

; at_grenade_grenade_hohlladung: item "grenade hohlladung", no count (at, 4 uses, not the most used count of this item)
;   e.g. ("at_grenade_grenade_hohlladung")
(define "at_grenade_grenade_hohlladung"
	{item "grenade hohlladung"}
)

; ==== grenades: smoke ====
;   macro                         item                                 count     uses  factions
;   smoke_x1                      "smoke grenade"                      1         166   axis_minor eng ger ger2 ger_ss jap rus rus_guard usa
;   smoke_x2                      "smoke grenade"                      2         110   axis_minor eng ger ger2 ger_ss jap rus usa
;   smoke_m15_x0p5_0p5            "m15_smoke grenade"                  0.5 0.5   43    usa
;   smoke_x1p5_0p5                "smoke grenade"                      1.5 0.5   38    usa
;   smoke_grenade                 "smoke grenade"                      -         19    ger ger_ss rus usa
;   smoke_n77_x1                  "n77_smoke grenade"                  1         18    eng
;   smoke_n77_x0p5_1              "n77_smoke grenade"                  0.5 1     13    eng
;   smoke_grenade_smoke_x2        "grenade smoke"                      2         12    eng rus rus_guard
;   smoke_n77_x0_1                "n77_smoke grenade"                  0 1       10    eng
;   smoke_n77_x0p25_1             "n77_smoke grenade"                  0.25 1    9     eng
;   smoke_x0_1                    "smoke grenade"                      0 1       7     ger jap
;   smoke_paradrop_ammo_heavy_x5  "smoke_paradrop_ammo_heavy grenade"  5         6     eng ger ger_ss jap rus usa
;   smoke_m15_x0p25_0p5           "m15_smoke grenade"                  0.25 0.5  5     usa
;   smoke_ccm34smoke_x2           "ccm34smoke"                         2         4     axis_minor

; smoke_x1: item "smoke grenade", count 1 (smoke, 166 uses)
;   e.g. ("smoke_x1")
(define "smoke_x1"
	{item "smoke grenade" 1}
)

; smoke_x2: item "smoke grenade", count 2 (smoke, 110 uses, not the most used count of this item)
;   e.g. ("smoke_x2")
(define "smoke_x2"
	{item "smoke grenade" 2}
)

; smoke_m15_x0p5_0p5: item "m15_smoke grenade", count 0.5 0.5 (smoke, 43 uses)
;   e.g. ("smoke_m15_x0p5_0p5")
(define "smoke_m15_x0p5_0p5"
	{item "m15_smoke grenade" 0.5 0.5}
)

; smoke_x1p5_0p5: item "smoke grenade", count 1.5 0.5 (smoke, 38 uses, not the most used count of this item)
;   e.g. ("smoke_x1p5_0p5")
(define "smoke_x1p5_0p5"
	{item "smoke grenade" 1.5 0.5}
)

; smoke_grenade: item "smoke grenade", no count (smoke, 19 uses, not the most used count of this item)
;   e.g. ("smoke_grenade")
(define "smoke_grenade"
	{item "smoke grenade"}
)

; smoke_n77_x1: item "n77_smoke grenade", count 1 (smoke, 18 uses)
;   e.g. ("smoke_n77_x1")
(define "smoke_n77_x1"
	{item "n77_smoke grenade" 1}
)

; smoke_n77_x0p5_1: item "n77_smoke grenade", count 0.5 1 (smoke, 13 uses, not the most used count of this item)
;   e.g. ("smoke_n77_x0p5_1")
(define "smoke_n77_x0p5_1"
	{item "n77_smoke grenade" 0.5 1}
)

; smoke_grenade_smoke_x2: item "grenade smoke", count 2 (smoke, 12 uses)
;   e.g. ("smoke_grenade_smoke_x2")
(define "smoke_grenade_smoke_x2"
	{item "grenade smoke" 2}
)

; smoke_n77_x0_1: item "n77_smoke grenade", count 0 1 (smoke, 10 uses, not the most used count of this item)
;   e.g. ("smoke_n77_x0_1")
(define "smoke_n77_x0_1"
	{item "n77_smoke grenade" 0 1}
)

; smoke_n77_x0p25_1: item "n77_smoke grenade", count 0.25 1 (smoke, 9 uses, not the most used count of this item)
;   e.g. ("smoke_n77_x0p25_1")
(define "smoke_n77_x0p25_1"
	{item "n77_smoke grenade" 0.25 1}
)

; smoke_x0_1: item "smoke grenade", count 0 1 (smoke, 7 uses, not the most used count of this item)
;   e.g. ("smoke_x0_1")
(define "smoke_x0_1"
	{item "smoke grenade" 0 1}
)

; smoke_paradrop_ammo_heavy_x5: item "smoke_paradrop_ammo_heavy grenade", count 5 (smoke, 6 uses)
;   e.g. ("smoke_paradrop_ammo_heavy_x5")
(define "smoke_paradrop_ammo_heavy_x5"
	{item "smoke_paradrop_ammo_heavy grenade" 5}
)

; smoke_m15_x0p25_0p5: item "m15_smoke grenade", count 0.25 0.5 (smoke, 5 uses, not the most used count of this item)
;   e.g. ("smoke_m15_x0p25_0p5")
(define "smoke_m15_x0p25_0p5"
	{item "m15_smoke grenade" 0.25 0.5}
)

; smoke_ccm34smoke_x2: item "ccm34smoke", count 2 (smoke, 4 uses)
;   e.g. ("smoke_ccm34smoke_x2")
(define "smoke_ccm34smoke_x2"
	{item "ccm34smoke" 2}
)

; ==== grenades: fire ====
;   macro                      item                       count  uses  factions
;   fire_molotov_coctail_x0_1  "grenade molotov_coctail"  0 1    51    rus rus_guard

; fire_molotov_coctail_x0_1: item "grenade molotov_coctail", count 0 1 (fire, 51 uses)
;   e.g. ("fire_molotov_coctail_x0_1")
(define "fire_molotov_coctail_x0_1"
	{item "grenade molotov_coctail" 0 1}
)

; ==== grenades: mine ====
;   macro                   item                  count  uses  factions
;   mine_antipersonnel_x5   "mine antipersonnel"  5      18    jap
;   mine_antipersonnel_x2   "mine antipersonnel"  2      17    jap
;   mine_antitank_x1        "mine antitank"       1      15    eng rus rus_guard
;   mine_antitank_x7        "mine antitank"       7      9     eng ger ger2 ger_ss jap rus usa
;   mine_antipersonnel_x15  "mine antipersonnel"  15     6     axis_minor eng jap rus usa
;   mine_antipersonnel_x4   "mine antipersonnel"  4      6     jap rus rus_guard usa
;   mine_antitank_x4        "mine antitank"       4      6     axis_minor ger ger_ss rus rus_guard
;   mine_antitank_x2        "mine antitank"       2      5     eng ger ger_ss
;   mine_antitank_x8        "mine antitank"       8      5     eng jap rus rus_guard usa

; mine_antipersonnel_x5: item "mine antipersonnel", count 5 (mine, 18 uses)
;   e.g. ("mine_antipersonnel_x5")
(define "mine_antipersonnel_x5"
	{item "mine antipersonnel" 5}
)

; mine_antipersonnel_x2: item "mine antipersonnel", count 2 (mine, 17 uses, not the most used count of this item)
;   e.g. ("mine_antipersonnel_x2")
(define "mine_antipersonnel_x2"
	{item "mine antipersonnel" 2}
)

; mine_antitank_x1: item "mine antitank", count 1 (mine, 15 uses)
;   e.g. ("mine_antitank_x1")
(define "mine_antitank_x1"
	{item "mine antitank" 1}
)

; mine_antitank_x7: item "mine antitank", count 7 (mine, 9 uses, not the most used count of this item)
;   e.g. ("mine_antitank_x7")
(define "mine_antitank_x7"
	{item "mine antitank" 7}
)

; mine_antipersonnel_x15: item "mine antipersonnel", count 15 (mine, 6 uses, not the most used count of this item)
;   e.g. ("mine_antipersonnel_x15")
(define "mine_antipersonnel_x15"
	{item "mine antipersonnel" 15}
)

; mine_antipersonnel_x4: item "mine antipersonnel", count 4 (mine, 6 uses, not the most used count of this item)
;   e.g. ("mine_antipersonnel_x4")
(define "mine_antipersonnel_x4"
	{item "mine antipersonnel" 4}
)

; mine_antitank_x4: item "mine antitank", count 4 (mine, 6 uses, not the most used count of this item)
;   e.g. ("mine_antitank_x4")
(define "mine_antitank_x4"
	{item "mine antitank" 4}
)

; mine_antitank_x2: item "mine antitank", count 2 (mine, 5 uses, not the most used count of this item)
;   e.g. ("mine_antitank_x2")
(define "mine_antitank_x2"
	{item "mine antitank" 2}
)

; mine_antitank_x8: item "mine antitank", count 8 (mine, 5 uses, not the most used count of this item)
;   e.g. ("mine_antitank_x8")
(define "mine_antitank_x8"
	{item "mine antitank" 8}
)

; ==== grenades: explosive ====
;   macro                         item               count  uses  factions
;   explosive_dynamite_x1         "dynamite"         1      26    axis_minor eng jap usa
;   explosive_dynamite_x2         "dynamite"         2      13    axis_minor eng jap rus usa
;   explosive_dynamite            "dynamite"         -      12    axis_minor ger usa
;   explosive_dynamite_ladung_x2  "dynamite_ladung"  2      11    ger ger2 ger_ss

; explosive_dynamite_x1: item "dynamite", count 1 (explosive, 26 uses)
;   e.g. ("explosive_dynamite_x1")
(define "explosive_dynamite_x1"
	{item "dynamite" 1}
)

; explosive_dynamite_x2: item "dynamite", count 2 (explosive, 13 uses, not the most used count of this item)
;   e.g. ("explosive_dynamite_x2")
(define "explosive_dynamite_x2"
	{item "dynamite" 2}
)

; explosive_dynamite: item "dynamite", no count (explosive, 12 uses, not the most used count of this item)
;   e.g. ("explosive_dynamite")
(define "explosive_dynamite"
	{item "dynamite"}
)

; explosive_dynamite_ladung_x2: item "dynamite_ladung", count 2 (explosive, 11 uses)
;   e.g. ("explosive_dynamite_ladung_x2")
(define "explosive_dynamite_ladung_x2"
	{item "dynamite_ladung" 2}
)
