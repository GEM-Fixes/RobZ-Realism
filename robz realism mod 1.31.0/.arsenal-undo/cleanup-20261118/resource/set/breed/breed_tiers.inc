; breed_tiers.inc: named tiers of the soldier breeds' perk sets (written by macrostd step tiers). Each tier is one call of
;   breed_body / breed_drive / breed_skills with fixed values; a breed writes ("body_regular") instead of the full call.
;   A set used by fewer than 4 breeds keeps its explicit breed_* call in the breed (the exceptions). Included from
;   breed_macros.inc, so a breed that includes breed_macros.inc sees every tier. Rename a tier: edit its line in the NAMES map
;   of tools/macrostd/steps/tiers.js and re-run the step (it renames the calls in the breeds too).
;
; body tiers, breed_body: body perks (health, health_regeneration, stamina, stamina_regeneration, vision, speed); weakest first, strongest last
;   tier                      values                                                                                              breeds  sides  typical users (breed file class: count)
;   body_ger_volkssturm       health(100%) regen_health(100%) stamina(75%) regen_stamina(100%) vision("mp_soldier") speed(0.8)    4       1      volkssturm_rifle_faustpatrone 1, volkssturm_rifle_panzerfaust 1, volkssturm_smg_faustpatrone 1, volkssturm_smg_panzerfaust 1
;   body_militia              health(100%) regen_health(100%) stamina(75%) regen_stamina(100%) vision("mp_soldier") speed(0.9)    25      2      volksgren_mg 4, home_guard 3, volksgren_pzfst 2, conscript_rifle 1
;   body_crew                 health(100%) regen_health(100%) stamina(100%) regen_stamina(100%) vision("mp_soldier") speed(0.8)   21      7      tankman 16, tankcommander 2, vehicle_supporter 2, vettankman 1
;   body_crew_bare            health(100%) regen_health(100%) stamina(100%) regen_stamina(100%) vision(mp_soldier) speed(0.8)     17      7      tankman 17
;   body_h100_s100            health(100%) regen_health(100%) stamina(100%) regen_stamina(100%) vision("mp_soldier") speed(0.9)   16      2      ssvt_mg 4, kosaken_mg 2, kosaken_sl 2, ssvt_rifle 2
;   body_crew_commander       health(150%) regen_health(100%) stamina(100%) regen_stamina(100%) vision("mp_soldier") speed(0.8)   21      6      tankman 17, tankcommander 3, vettankcommander 1
;   body_crew_commander_bare  health(150%) regen_health(100%) stamina(100%) regen_stamina(100%) vision(mp_soldier) speed(0.8)     20      7      tankman 15, tankcommander 4, tank_commander 1
;   body_regular              health(150%) regen_health(100%) stamina(100%) regen_stamina(100%) vision("mp_soldier") speed(0.9)   346     9      vehicle_supporter 27, mgun 26, rifle 23, smg 23
;   body_regular_bare         health(150%) regen_health(100%) stamina(100%) regen_stamina(100%) vision(mp_soldier) speed(0.9)     36      8      ap_miner 8, at_miner 8, flamer 6, mgun 3
;   body_ger_ss_ssvt_sl       health(150%) regen_health(100%) stamina(125%) regen_stamina(100%) vision("mp_soldier") speed(0.9)   4       1      ssvt_sl 4
;   body_squadleader          health(200%) regen_health(100%) stamina(100%) regen_stamina(100%) vision("mp_soldier") speed(0.9)   73      9      squadleader 17, mg 4, smg 4, tankman 4
;   body_h200_s125            health(200%) regen_health(100%) stamina(125%) regen_stamina(100%) vision("mp_soldier") speed(0.9)   35      2      grenadier_mg 6, grenadier_sa 4, grenadier_sl 4, grenadier_pzfst 2
;   body_veteran              health(200%) regen_health(100%) stamina(150%) regen_stamina(100%) vision("mp_soldier") speed(0.9)   187     6      elite 8, sturmovik 8, pzgren_mg 7, jager_mg 6
;   body_veteran_bare         health(200%) regen_health(100%) stamina(150%) regen_stamina(100%) vision(mp_soldier) speed(0.9)     5       2      lssah_pzgren_at 4, raidergren 1
;   body_axis_minor_assault   health(200%) regen_health(100%) stamina(200%) regen_stamina(100%) vision("mp_soldier") speed(0.9)   6       1      assualt_mgun 2, assualt_flamer 1, assualt_pzf 1, assualt_rifle 1
;   body_h250_s100            health(250%) regen_health(100%) stamina(100%) regen_stamina(100%) vision("mp_soldier") speed(0.9)   4       3      saper 2, pio_flamer 1, smg 1
;   body_officer_s100         health(250%) regen_health(100%) stamina(100%) regen_stamina(100%) vision("mp_officer") speed(1.0)   4       3      officer 2, oficer 2
;   body_h250_s150            health(250%) regen_health(100%) stamina(150%) regen_stamina(100%) vision("mp_soldier") speed(0.9)   39      4      shock_mg 6, shock_smg 4, elite 3, shock_flame 2
;   body_usa_raider           health(250%) regen_health(100%) stamina(150%) regen_stamina(100%) vision(mp_soldier) speed(0.9)     6       1      nightfighter_leader 1, raider 1, raiderasst 1, raiderbar 1
;   body_officer              health(250%) regen_health(100%) stamina(150%) regen_stamina(100%) vision("mp_officer") speed(1.0)   5       5      oficer 4, officer 1
;   body_officer_bare         health(250%) regen_health(100%) stamina(150%) regen_stamina(100%) vision(mp_officer) speed(1)       5       4      officer 4, super_officer 1
;   body_eng_anzac            health(250%) regen_health(100%) stamina(200%) regen_stamina(100%) vision("mp_soldier") speed(0.9)   8       1      anzac_mg 2, anzac_at_rifle 1, anzac_rifle 1, anzac_rifle_grenadier 1
;   body_jap_charger          health(250%) regen_health(100%) stamina(200%) regen_stamina(125%) vision("mp_soldier") speed(0.95)  6       1      charger_rifle 2, charger_smg_type 2, charger_smg 1, charger_throwgun 1
;   body_h300_s150            health(300%) regen_health(100%) stamina(150%) regen_stamina(100%) vision("mp_soldier") speed(0.9)   29      2      ig 9, ig_light_mortar 2, sgt 2, ig2_scoped 1
;   body_eng_h350_s150        health(350%) regen_health(100%) stamina(150%) regen_stamina(100%) vision("mp_soldier") speed(0.9)   13      1      elite 4, commando_bren 2, commando_carbine 1, commando_cpl_smg 1
;   body_sniper               health(350%) regen_health(100%) stamina(150%) regen_stamina(100%) vision("mp_sniper") speed(1.0)    25      9      sniper 14, sniper_mosin 2, alpini_sniper 1, g43scope_sniper 1
;   body_h350_s200            health(350%) regen_health(100%) stamina(200%) regen_stamina(100%) vision("mp_soldier") speed(0.9)   49      3      paramarine 7, sturmovik 7, bsf_marine 3, devil_brigade_demo 2
;   body_sniper_s200          health(350%) regen_health(100%) stamina(200%) regen_stamina(100%) vision("mp_sniper") speed(1.0)    5       3      sniper 3, sniper2_early 1, sniper_vet 1
;   body_jap_takasago         health(350%) regen_health(100%) stamina(225%) regen_stamina(125%) vision("mp_soldier") speed(0.9)   10      1      takasago_rifle 4, takasago_lmg 2, takasago_mgun 2, takasago_smg 2
;   body_elite                health(400%) regen_health(100%) stamina(200%) regen_stamina(100%) vision("mp_soldier") speed(0.9)   72      4      sturmovik 12, 101st_para 6, elite 4, para 3
;   body_elite_bare           health(400%) regen_health(100%) stamina(200%) regen_stamina(100%) vision(mp_soldier) speed(0.9)     41      3      fallschirm_mg 10, fallschirm_grenadier 4, fallschirm_sl_asst_fg 4, fallschirm_fg 3
;   body_crew_elite           health(400%) regen_health(100%) stamina(200%) regen_stamina(100%) vision("mp_officer") speed(1)     6       2      tankman 4, tankcommander 2
;   body_ger2_pzgren          health(400%) regen_health(100%) stamina(225%) regen_stamina(125%) vision("mp_soldier") speed(1)     10      1      pzgren_g43_pzfaust 1, pzgren_g43scope 1, pzgren_mg 1, pzgren_mgassist 1
;   body_ger_gebirgsjager     health(400%) regen_health(100%) stamina(225%) regen_stamina(125%) vision(mp_soldier) speed(1)       16      1      gebirgsjager_mg 5, gebirgsjager_sa 2, gebirgsjager_smg 2, gebirgsjager_pzfst_sa 1
;
; drive tiers, breed_drive: crew perks (tank, vehicle, cannon); weakest first, strongest last
;   tier                    values                                 breeds  sides  typical users (breed file class: count)
;   drive_militia           tank(0.75) vehicle(0.8) cannon(0.8)    13      2      home_guard 3, home_guard_mg 1, partisan_at 1, partisan_mg 1
;   drive_regular           tank(0.75) vehicle(1) cannon(0.8)      370     7      flamer 14, at_rifle 13, grenadier_mg 12, mgun 12
;   drive_veteran           tank(0.85) vehicle(1) cannon(0.9)      225     7      elite 11, saper 9, sapper_rifle 9, squadleader 8
;   drive_t08_v1_c1         tank(0.8) vehicle(1) cannon(1)         12      2      ap_miner 2, at_miner 2, flamer 2, mg 2
;   drive_t08_v10_c10       tank(0.8) vehicle(1.0) cannon(1.0)     161     3      mgun 17, rifle 13, smg 12, squadleader 11
;   drive_ger2_t10_v10_c08  tank(1.0) vehicle(1.0) cannon(0.8)     4       1      tankman 4
;   drive_support           tank(0.85) vehicle(1) cannon(1.0)      12      3      vehicle_supporter 11, support 1
;   drive_t085_v10_c10      tank(0.85) vehicle(1.0) cannon(1.0)    5       2      vehicle_supporter 5
;   drive_t09_v10_c10       tank(0.9) vehicle(1.0) cannon(1.0)     79      4      ig 9, elite 8, anzac_mg 2, charger_rifle 2
;   drive_crew              tank(1) vehicle(1) cannon(0.9)         8       3      tankman 8
;   drive_t10_v10_c09       tank(1.0) vehicle(1.0) cannon(0.9)     5       3      tankman 4, vettankman 1
;   drive_t085_v105_c105    tank(0.85) vehicle(1.05) cannon(1.05)  4       2      vehicle_supporter 3, support 1
;   drive_elite             tank(0.95) vehicle(1) cannon(1)        118     4      fallschirm_mg 10, paramarine 7, sturmovik 7, 101st_para 6
;   drive_t1_v1_c1          tank(1) vehicle(1) cannon(1)           10      3      tankman 4, officer 2, sniper_type 2, sniper 1
;   drive_t10_v10_c10       tank(1.0) vehicle(1.0) cannon(1.0)     90      5      sturmovik 12, vehicle_supporter 8, sniper 4, takasago_rifle 4
;   drive_crew_commander    tank(1.1) vehicle(1) cannon(0.95)      8       3      tankcommander 4, tankman 3, tank_commander 1
;   drive_t11_v10_c095      tank(1.1) vehicle(1.0) cannon(0.95)    7       3      tankman 5, tankcommander 1, vettankcommander 1
;   drive_t110_v110_c105    tank(1.10) vehicle(1.10) cannon(1.05)  4       2      tankman 4
;   drive_crew_elite        tank(1.15) vehicle(1.15) cannon(1.0)   11      4      tankman 7, tankcommander 2, vehicle_supporter 2
;   drive_t115_v115_c105    tank(1.15) vehicle(1.15) cannon(1.05)  4       3      tankman 4
;   drive_t115_v115_c11     tank(1.15) vehicle(1.15) cannon(1.1)   6       2      tankman 6
;   drive_t120_v120_c10     tank(1.20) vehicle(1.20) cannon(1.0)   7       3      tankman 5, tankcommander 2
;   drive_t12_v12_c11       tank(1.2) vehicle(1.2) cannon(1.1)     7       4      tankman 5, tankcommander 2
;
; skills tiers, breed_skills: weapon skill levels (pistol, smg, mgun, rifle, rocketlauncher, melee); weakest first, strongest last
;   tier                           values                                                breeds  sides  typical users (breed file class: count)
;   skills_rus_militia             pistol(1) smg(1) mgun(1) rifle(1) rocket(1) melee(2)  11      1      home_guard 3, conscript_rifle 1, conscript_smg 1, home_guard_mg 1
;   skills_ger_volkssturm          pistol(1) smg(1) mgun(1) rifle(1) rocket(2) melee(2)  4       1      volkssturm_rifle_faustpatrone 1, volkssturm_rifle_panzerfaust 1, volkssturm_smg_faustpatrone 1, volkssturm_smg_panzerfaust 1
;   skills_jap_charger             pistol(1) smg(1) mgun(1) rifle(1) rocket(1) melee(4)  6       1      charger_rifle 2, charger_smg_type 2, charger_smg 1, charger_throwgun 1
;   skills_1_1_1_2_2_2             pistol(1) smg(1) mgun(1) rifle(2) rocket(2) melee(2)  4       2      ssvt_pzfst 1, volksgren_grenadier 1, volksgren_pzfst 1, volksgren_rifle 1
;   skills_jap_1_1_3_1_1_2         pistol(1) smg(1) mgun(3) rifle(1) rocket(1) melee(2)  7       1      mgun 6, otsu_mg 1
;   skills_2_1_1_2_1_2             pistol(2) smg(1) mgun(1) rifle(2) rocket(1) melee(2)  6       3      rifle 6
;   skills_ger_ss_2_1_2_1_1_2      pistol(2) smg(1) mgun(2) rifle(1) rocket(1) melee(2)  4       1      ssvt_mg 4
;   skills_2_2_1_1_1_2             pistol(2) smg(2) mgun(1) rifle(1) rocket(1) melee(2)  28      4      ap_miner 5, at_miner 5, saper 4, flamer 3
;   skills_2_1_1_3_1_2             pistol(2) smg(1) mgun(1) rifle(3) rocket(1) melee(2)  17      3      rifle 6, light_mortar 3, mgun 3, rifle_sa 2
;   skills_rus_2_2_1_2_1_2         pistol(2) smg(2) mgun(1) rifle(2) rocket(1) melee(2)  4       1      flamer 3, flamerassist 1
;   skills_2_2_2_1_1_2             pistol(2) smg(2) mgun(2) rifle(1) rocket(1) melee(2)  6       3      tankman 5, vehicle_supporter 1
;   skills_2_3_1_1_1_2             pistol(2) smg(3) mgun(1) rifle(1) rocket(1) melee(2)  9       2      smg 7, smg_danuvia 1, smgb 1
;   skills_2_1_1_3_1_3             pistol(2) smg(1) mgun(1) rifle(3) rocket(1) melee(3)  6       2      rifle 3, sa 2, recon_rifle 1
;   skills_2_1_1_3_2_2             pistol(2) smg(1) mgun(1) rifle(3) rocket(2) melee(2)  9       2      sapper_rifle 9
;   skills_2_2_1_1_3_2             pistol(2) smg(2) mgun(1) rifle(1) rocket(3) melee(2)  9       3      bazooker 4, bazookerassist 2, piat 1, piatassist 1
;   skills_2_2_1_3_1_2             pistol(2) smg(2) mgun(1) rifle(3) rocket(1) melee(2)  12      4      at_rifle 8, at_rifleassist 4
;   skills_2_3_1_1_1_3             pistol(2) smg(3) mgun(1) rifle(1) rocket(1) melee(3)  10      2      smg 8, recon_smg 2
;   skills_2_3_1_1_2_2             pistol(2) smg(3) mgun(1) rifle(1) rocket(2) melee(2)  4       2      sapper_smg 4
;   skills_2_1_3_3_1_2             pistol(2) smg(1) mgun(3) rifle(3) rocket(1) melee(2)  7       2      mgun 4, mg 2, mgunassist 1
;   skills_2_2_1_4_1_2             pistol(2) smg(2) mgun(1) rifle(4) rocket(1) melee(2)  4       2      miner_ap 1, miner_at 1, sniper_mosin 1, sniper_svtscope 1
;   skills_axis_minor_2_2_4_1_1_2  pistol(2) smg(2) mgun(4) rifle(1) rocket(1) melee(2)  4       1      tankcommander 1, tankman 1, vettankcommander 1, vettankman 1
;   skills_2_3_2_2_1_2             pistol(2) smg(3) mgun(2) rifle(2) rocket(1) melee(2)  4       2      ap_miner 2, kosaken_sl 2
;   skills_2_1_3_3_1_3             pistol(2) smg(1) mgun(3) rifle(3) rocket(1) melee(3)  5       2      mg 4, mgun 1
;   skills_sniper_r5               pistol(2) smg(2) mgun(1) rifle(5) rocket(1) melee(2)  9       3      sniper 5, sniper_type 2, sniper_mosin 1, sniper_svtscoped 1
;   skills_2_2_2_3_1_3             pistol(2) smg(2) mgun(2) rifle(3) rocket(1) melee(3)  21      3      rifle 8, engineer 4, at_rifle 2, armor_rifle 1
;   skills_2_2_3_2_1_3             pistol(2) smg(2) mgun(3) rifle(2) rocket(1) melee(3)  4       2      mgun 3, mg_canada 1
;   skills_2_3_2_2_1_3             pistol(2) smg(3) mgun(2) rifle(2) rocket(1) melee(3)  24      3      saper 7, smg 5, at_miner 4, flamer 4
;   skills_2_2_3_2_2_3             pistol(2) smg(2) mgun(3) rifle(2) rocket(2) melee(3)  6       3      vehicle_supporter 6
;   skills_2_2_3_3_1_3             pistol(2) smg(2) mgun(3) rifle(3) rocket(1) melee(3)  9       3      mgun 6, armor_mgun 1, fallschirm_mg 1, mg_assist_canada 1
;   skills_3_3_2_2_1_3             pistol(3) smg(3) mgun(2) rifle(2) rocket(1) melee(3)  11      2      flamer 3, tankman 3, radioman_mortar 2, engineer_flamer 1
;   skills_usa_2_2_2_3_4_3         pistol(2) smg(2) mgun(2) rifle(3) rocket(4) melee(3)  6       1      bazooker 3, bazookerassist 1, engineer_at 1, rifle_at 1
;   skills_2_2_2_4_2_4             pistol(2) smg(2) mgun(2) rifle(4) rocket(2) melee(4)  7       2      pioneer_1trench 1, pioneer_3trench 1, pioneer_ap_miner 1, pioneer_at_miner 1
;   skills_support                 pistol(2) smg(2) mgun(4) rifle(2) rocket(2) melee(4)  10      2      vehicle_supporter 9, support 1
;   skills_3_2_2_4_2_3             pistol(3) smg(2) mgun(2) rifle(4) rocket(2) melee(3)  8       3      shock_rifle 3, shock_sa 3, otsu_sa 1, otsu_sl 1
;   skills_3_2_4_2_2_3             pistol(3) smg(2) mgun(4) rifle(2) rocket(2) melee(3)  4       2      shock_mg 4
;   skills_3_4_2_2_2_3             pistol(3) smg(4) mgun(2) rifle(2) rocket(2) melee(3)  14      2      shock_smg 7, shock_flame 3, shock_sl_smg 3, smg 1
;   skills_3_2_4_4_2_3             pistol(3) smg(2) mgun(4) rifle(4) rocket(2) melee(3)  4       2      shock_mg 4
;   skills_3_3_3_3_3_3             pistol(3) smg(3) mgun(3) rifle(3) rocket(3) melee(3)  5       3      officer 2, fallschirm_mg 1, fallschirm_sl_asst_smg 1, super_officer 1
;   skills_3_3_3_4_2_4             pistol(3) smg(3) mgun(3) rifle(4) rocket(2) melee(4)  5       2      sniper 2, armor_squadleader 1, engineer_squadleader 1, squadleader 1
;   skills_3_3_3_4_3_3             pistol(3) smg(3) mgun(3) rifle(4) rocket(3) melee(3)  13      3      elite 5, marine_rifle 2, anzac_at_rifle 1, anzac_rifle 1
;   skills_3_3_4_3_3_3             pistol(3) smg(3) mgun(4) rifle(3) rocket(3) melee(3)  4       2      elite 2, anzac_mg 1, marine_mg 1
;   skills_4_3_2_4_2_4             pistol(4) smg(3) mgun(2) rifle(4) rocket(2) melee(4)  12      3      grenadier_sa 3, grenadier_rifle 2, grenadier_rifle_grenadier 2, pzgren_pio 2
;   skills_4_4_2_3_2_4             pistol(4) smg(4) mgun(2) rifle(3) rocket(2) melee(4)  47      4      flamer 7, tankman 6, ap_miner 5, at_miner 5
;   skills_3_3_4_4_3_3             pistol(3) smg(3) mgun(4) rifle(4) rocket(3) melee(3)  6       3      anzac_mg 1, elite 1, marine_bar 1, marine_barassist 1
;   skills_3_3_5_3_2_4             pistol(3) smg(3) mgun(5) rifle(3) rocket(2) melee(4)  4       2      vehicle_supporter 3, support 1
;   skills_4_3_2_5_2_4             pistol(4) smg(3) mgun(2) rifle(5) rocket(2) melee(4)  6       3      light_mortar 6
;   skills_4_3_4_3_2_4             pistol(4) smg(3) mgun(4) rifle(3) rocket(2) melee(4)  7       3      grenadier_mg 4, mgun 1, pzgren_pio_mg 1, sturmpio_mg 1
;   skills_4_4_1_5_2_4             pistol(4) smg(4) mgun(1) rifle(5) rocket(2) melee(4)  7       4      at_rifle 6, at_rifle_ptrd 1
;   skills_4_3_2_4_4_4             pistol(4) smg(3) mgun(2) rifle(4) rocket(4) melee(4)  5       2      grenadier_pzfst 1, pzgren_pio 1, pzgren_pio_at 1, sturmpio 1
;   skills_sniper_r6               pistol(4) smg(3) mgun(2) rifle(6) rocket(2) melee(4)  8       2      sniper 4, g43scope_sniper 1, sniper_g 1, sniper_mauser 1
;   skills_4_3_4_4_2_4             pistol(4) smg(3) mgun(4) rifle(4) rocket(2) melee(4)  5       3      grenadier_mg 2, mgun 1, pzgren_pio_mg 1, sturmpio_mg 1
;   skills_4_4_2_5_2_4             pistol(4) smg(4) mgun(2) rifle(5) rocket(2) melee(4)  6       4      at_rifle 3, at_rifleassist 3
;   skills_4_4_4_3_2_4             pistol(4) smg(4) mgun(4) rifle(3) rocket(2) melee(4)  6       2      tankcommander 4, tank_commander 1, tankman 1
;   skills_jap_3_3_3_5_3_5         pistol(3) smg(3) mgun(3) rifle(5) rocket(3) melee(5)  12      1      ig 5, ig_light_mortar 2, kanoe_shidan_type 1, kanoeshidan_type38rifle 1
;   skills_4_3_2_4_5_4             pistol(4) smg(3) mgun(2) rifle(4) rocket(5) melee(4)  8       2      bazooker 2, panzerfaust 2, panzerschreck 1, panzerschreckassist 1
;   skills_4_3_2_5_3_5             pistol(4) smg(3) mgun(2) rifle(5) rocket(3) melee(5)  10      2      jager_sa 4, fusilier_sa 3, fusilier_pzfst_sa 1, fusilier_rifle 1
;   skills_4_5_2_3_3_5             pistol(4) smg(5) mgun(2) rifle(3) rocket(3) melee(5)  7       2      jager_smg 3, jager_stg 2, fusilier_smg 1, fusilier_stg 1
;   skills_ger_ss_4_3_3_5_4_4      pistol(4) smg(3) mgun(3) rifle(5) rocket(4) melee(4)  31      1      grenadier_sa 4, tk_pzgren_sa 3, dr_pzgren_sa 2, gebirgs_rifle 2
;   skills_ger_ss_4_3_5_3_4_4      pistol(4) smg(3) mgun(5) rifle(3) rocket(4) melee(4)  10      1      grenadier_mg 4, pzgren_mg 3, gebirgs_mg 2, sturmgren_mg 1
;   skills_ger_ss_4_5_3_3_4_4      pistol(4) smg(5) mgun(3) rifle(3) rocket(4) melee(4)  19      1      gebirgs_smg 2, grenadier_sl 2, grenadier_smg 2, grenadier_stg 2
;   skills_4_5_3_4_2_5             pistol(4) smg(5) mgun(3) rifle(4) rocket(2) melee(5)  4       3      squadleader 2, pzgren_pio_sl 1, sturmpio_sl 1
;   skills_ger_4_3_3_5_4_5         pistol(4) smg(3) mgun(3) rifle(5) rocket(4) melee(5)  5       1      gd_pzgren_sa_scope 2, gd_pzgren_rifle 1, gd_pzgren_sa 1, gd_pzgren_sl 1
;   skills_ger_ss_4_3_3_5_5_4      pistol(4) smg(3) mgun(3) rifle(5) rocket(5) melee(4)  11      1      grenadier_pzfst 2, lssah_pzgren_at 2, dr_pzgren_pzfst 1, dr_pzgren_pzfst60_sa 1
;   skills_ger_ss_4_3_4_5_4_4      pistol(4) smg(3) mgun(4) rifle(5) rocket(4) melee(4)  4       1      pzgren_sa 2, pzgren_rifle 1, pzgren_sl 1
;   skills_4_3_5_5_2_5             pistol(4) smg(3) mgun(5) rifle(5) rocket(2) melee(5)  5       2      jager_mg 3, fusilier_mg 2
;   skills_4_4_4_4_4_4             pistol(4) smg(4) mgun(4) rifle(4) rocket(4) melee(4)  7       2      assualt_mgun 2, assualt_flamer 1, assualt_pzf 1, assualt_rifle 1
;   skills_4_5_6_3_2_4             pistol(4) smg(5) mgun(6) rifle(3) rocket(2) melee(4)  6       3      tankman 4, tankcommander 2
;   skills_5_3_5_4_2_5             pistol(5) smg(3) mgun(5) rifle(4) rocket(2) melee(5)  6       2      fusilier_mg 3, jager_mg 3
;   skills_5_5_3_4_2_5             pistol(5) smg(5) mgun(3) rifle(4) rocket(2) melee(5)  5       2      squadleader 3, squadleader_mp 1, squadleader_sg 1
;   skills_ger_ss_4_3_5_5_4_4      pistol(4) smg(3) mgun(5) rifle(5) rocket(4) melee(4)  21      1      lssah_pzgren_mg 6, tk_pzgren_mg 6, dr_pzgren_mg 3, gebirgs_mg 2
;   skills_usa_4_4_4_5_4_4         pistol(4) smg(4) mgun(4) rifle(5) rocket(4) melee(4)  9       1      82ndairborne_carbine 1, 82ndairborne_rifle 1, 82ndairborne_sniper 1, elite 1
;   skills_4_5_4_4_4_4             pistol(4) smg(5) mgun(4) rifle(4) rocket(4) melee(4)  8       2      gebirgs_sl 4, assualt_squadleader 1, gebirgs_sl_asst_k 1, lssah_pzgren_sl_smg 1
;   skills_ger_4_3_5_5_4_5         pistol(4) smg(3) mgun(5) rifle(5) rocket(4) melee(5)  4       1      gd_pzgren_mg 4
;   skills_usa_4_4_5_5_4_4         pistol(4) smg(4) mgun(5) rifle(5) rocket(4) melee(4)  6       1      elite 2, 82ndairborne_bar 1, 82ndairborne_barassist 1, 82ndairborne_mg 1
;   skills_ger_5_4_4_5_4_5         pistol(5) smg(4) mgun(4) rifle(5) rocket(4) melee(5)  10      1      sturmovik 3, fusilier_sl 2, pzgren_g 2, pzgren2ic 1
;   skills_ger_5_4_5_4_4_5         pistol(5) smg(4) mgun(5) rifle(4) rocket(4) melee(5)  5       1      pzgren_mg 2, sturmovik 2, pzgren_mg34assist 1
;   skills_squadleader             pistol(5) smg(5) mgun(4) rifle(5) rocket(4) melee(5)  10      3      jager_sl_stg 4, fusilier_sl 2, jager_sl_smg 2, squadleader_scot 2
;   skills_ger_5_5_4_4_6_5         pistol(5) smg(5) mgun(4) rifle(4) rocket(6) melee(5)  4       1      sturmovik 2, pzgren_mp 1, pzgren_panzershreck 1
;   skills_jap_6_4_4_6_4_6         pistol(6) smg(4) mgun(4) rifle(6) rocket(4) melee(6)  5       1      takasago_rifle 4, takasago_mgun 1
;   skills_5_5_5_6_5_5             pistol(5) smg(5) mgun(5) rifle(6) rocket(5) melee(5)  22      2      sturmovik 4, bsf_marine 2, paramarine 2, paramarineb 2
;   skills_usa_5_6_5_5_5_5         pistol(5) smg(6) mgun(5) rifle(5) rocket(5) melee(5)  4       1      paramarine 2, paramarine_sgt 2
;   skills_5_5_6_6_5_5             pistol(5) smg(5) mgun(6) rifle(6) rocket(5) melee(5)  10      2      paramarine 3, ranger_bar 2, sturmovik 2, bsf_marine_mg 1
;   skills_jap_5_5_5_7_5_7         pistol(5) smg(5) mgun(5) rifle(7) rocket(5) melee(7)  4       1      mgun 1, snlf_mg 1, snlf_rifle_type 1, teishin_type2rifle_apminer 1
;   skills_elite_6                 pistol(6) smg(6) mgun(6) rifle(6) rocket(6) melee(6)  33      3      elite 4, para 3, commando_bren 2, devil_brigade_demo 2
;   skills_elite_7                 pistol(7) smg(7) mgun(7) rifle(7) rocket(7) melee(7)  115     6      sturmovik 12, fallschirm_mg 10, gebirgsjager_mg 5, elite 4

; body_ger_volkssturm: breed_body tier, health 100%, regen_health 100%, stamina 75%, regen_stamina 100%, vision "mp_soldier", speed 0.8
;   e.g. ("body_ger_volkssturm")
(define "body_ger_volkssturm"
	("breed_body" health(100%) regen_health(100%) stamina(75%) regen_stamina(100%) vision("mp_soldier") speed(0.8))
)

; body_militia: breed_body tier, health 100%, regen_health 100%, stamina 75%, regen_stamina 100%, vision "mp_soldier", speed 0.9
;   e.g. ("body_militia")
(define "body_militia"
	("breed_body" health(100%) regen_health(100%) stamina(75%) regen_stamina(100%) vision("mp_soldier") speed(0.9))
)

; body_crew: breed_body tier, health 100%, regen_health 100%, stamina 100%, regen_stamina 100%, vision "mp_soldier", speed 0.8
;   e.g. ("body_crew")
(define "body_crew"
	("breed_body" health(100%) regen_health(100%) stamina(100%) regen_stamina(100%) vision("mp_soldier") speed(0.8))
)

; body_crew_bare: breed_body tier, health 100%, regen_health 100%, stamina 100%, regen_stamina 100%, vision mp_soldier, speed 0.8
;   e.g. ("body_crew_bare")
(define "body_crew_bare"
	("breed_body" health(100%) regen_health(100%) stamina(100%) regen_stamina(100%) vision(mp_soldier) speed(0.8))
)

; body_h100_s100: breed_body tier, health 100%, regen_health 100%, stamina 100%, regen_stamina 100%, vision "mp_soldier", speed 0.9
;   e.g. ("body_h100_s100")
(define "body_h100_s100"
	("breed_body" health(100%) regen_health(100%) stamina(100%) regen_stamina(100%) vision("mp_soldier") speed(0.9))
)

; body_crew_commander: breed_body tier, health 150%, regen_health 100%, stamina 100%, regen_stamina 100%, vision "mp_soldier", speed 0.8
;   e.g. ("body_crew_commander")
(define "body_crew_commander"
	("breed_body" health(150%) regen_health(100%) stamina(100%) regen_stamina(100%) vision("mp_soldier") speed(0.8))
)

; body_crew_commander_bare: breed_body tier, health 150%, regen_health 100%, stamina 100%, regen_stamina 100%, vision mp_soldier, speed 0.8
;   e.g. ("body_crew_commander_bare")
(define "body_crew_commander_bare"
	("breed_body" health(150%) regen_health(100%) stamina(100%) regen_stamina(100%) vision(mp_soldier) speed(0.8))
)

; body_regular: breed_body tier, health 150%, regen_health 100%, stamina 100%, regen_stamina 100%, vision "mp_soldier", speed 0.9
;   e.g. ("body_regular")
(define "body_regular"
	("breed_body" health(150%) regen_health(100%) stamina(100%) regen_stamina(100%) vision("mp_soldier") speed(0.9))
)

; body_regular_bare: breed_body tier, health 150%, regen_health 100%, stamina 100%, regen_stamina 100%, vision mp_soldier, speed 0.9
;   e.g. ("body_regular_bare")
(define "body_regular_bare"
	("breed_body" health(150%) regen_health(100%) stamina(100%) regen_stamina(100%) vision(mp_soldier) speed(0.9))
)

; body_ger_ss_ssvt_sl: breed_body tier, health 150%, regen_health 100%, stamina 125%, regen_stamina 100%, vision "mp_soldier", speed 0.9
;   e.g. ("body_ger_ss_ssvt_sl")
(define "body_ger_ss_ssvt_sl"
	("breed_body" health(150%) regen_health(100%) stamina(125%) regen_stamina(100%) vision("mp_soldier") speed(0.9))
)

; body_squadleader: breed_body tier, health 200%, regen_health 100%, stamina 100%, regen_stamina 100%, vision "mp_soldier", speed 0.9
;   e.g. ("body_squadleader")
(define "body_squadleader"
	("breed_body" health(200%) regen_health(100%) stamina(100%) regen_stamina(100%) vision("mp_soldier") speed(0.9))
)

; body_h200_s125: breed_body tier, health 200%, regen_health 100%, stamina 125%, regen_stamina 100%, vision "mp_soldier", speed 0.9
;   e.g. ("body_h200_s125")
(define "body_h200_s125"
	("breed_body" health(200%) regen_health(100%) stamina(125%) regen_stamina(100%) vision("mp_soldier") speed(0.9))
)

; body_veteran: breed_body tier, health 200%, regen_health 100%, stamina 150%, regen_stamina 100%, vision "mp_soldier", speed 0.9
;   e.g. ("body_veteran")
(define "body_veteran"
	("breed_body" health(200%) regen_health(100%) stamina(150%) regen_stamina(100%) vision("mp_soldier") speed(0.9))
)

; body_veteran_bare: breed_body tier, health 200%, regen_health 100%, stamina 150%, regen_stamina 100%, vision mp_soldier, speed 0.9
;   e.g. ("body_veteran_bare")
(define "body_veteran_bare"
	("breed_body" health(200%) regen_health(100%) stamina(150%) regen_stamina(100%) vision(mp_soldier) speed(0.9))
)

; body_axis_minor_assault: breed_body tier, health 200%, regen_health 100%, stamina 200%, regen_stamina 100%, vision "mp_soldier", speed 0.9
;   e.g. ("body_axis_minor_assault")
(define "body_axis_minor_assault"
	("breed_body" health(200%) regen_health(100%) stamina(200%) regen_stamina(100%) vision("mp_soldier") speed(0.9))
)

; body_h250_s100: breed_body tier, health 250%, regen_health 100%, stamina 100%, regen_stamina 100%, vision "mp_soldier", speed 0.9
;   e.g. ("body_h250_s100")
(define "body_h250_s100"
	("breed_body" health(250%) regen_health(100%) stamina(100%) regen_stamina(100%) vision("mp_soldier") speed(0.9))
)

; body_officer_s100: breed_body tier, health 250%, regen_health 100%, stamina 100%, regen_stamina 100%, vision "mp_officer", speed 1.0
;   e.g. ("body_officer_s100")
(define "body_officer_s100"
	("breed_body" health(250%) regen_health(100%) stamina(100%) regen_stamina(100%) vision("mp_officer") speed(1.0))
)

; body_h250_s150: breed_body tier, health 250%, regen_health 100%, stamina 150%, regen_stamina 100%, vision "mp_soldier", speed 0.9
;   e.g. ("body_h250_s150")
(define "body_h250_s150"
	("breed_body" health(250%) regen_health(100%) stamina(150%) regen_stamina(100%) vision("mp_soldier") speed(0.9))
)

; body_usa_raider: breed_body tier, health 250%, regen_health 100%, stamina 150%, regen_stamina 100%, vision mp_soldier, speed 0.9
;   e.g. ("body_usa_raider")
(define "body_usa_raider"
	("breed_body" health(250%) regen_health(100%) stamina(150%) regen_stamina(100%) vision(mp_soldier) speed(0.9))
)

; body_officer: breed_body tier, health 250%, regen_health 100%, stamina 150%, regen_stamina 100%, vision "mp_officer", speed 1.0
;   e.g. ("body_officer")
(define "body_officer"
	("breed_body" health(250%) regen_health(100%) stamina(150%) regen_stamina(100%) vision("mp_officer") speed(1.0))
)

; body_officer_bare: breed_body tier, health 250%, regen_health 100%, stamina 150%, regen_stamina 100%, vision mp_officer, speed 1
;   e.g. ("body_officer_bare")
(define "body_officer_bare"
	("breed_body" health(250%) regen_health(100%) stamina(150%) regen_stamina(100%) vision(mp_officer) speed(1))
)

; body_eng_anzac: breed_body tier, health 250%, regen_health 100%, stamina 200%, regen_stamina 100%, vision "mp_soldier", speed 0.9
;   e.g. ("body_eng_anzac")
(define "body_eng_anzac"
	("breed_body" health(250%) regen_health(100%) stamina(200%) regen_stamina(100%) vision("mp_soldier") speed(0.9))
)

; body_jap_charger: breed_body tier, health 250%, regen_health 100%, stamina 200%, regen_stamina 125%, vision "mp_soldier", speed 0.95
;   e.g. ("body_jap_charger")
(define "body_jap_charger"
	("breed_body" health(250%) regen_health(100%) stamina(200%) regen_stamina(125%) vision("mp_soldier") speed(0.95))
)

; body_h300_s150: breed_body tier, health 300%, regen_health 100%, stamina 150%, regen_stamina 100%, vision "mp_soldier", speed 0.9
;   e.g. ("body_h300_s150")
(define "body_h300_s150"
	("breed_body" health(300%) regen_health(100%) stamina(150%) regen_stamina(100%) vision("mp_soldier") speed(0.9))
)

; body_eng_h350_s150: breed_body tier, health 350%, regen_health 100%, stamina 150%, regen_stamina 100%, vision "mp_soldier", speed 0.9
;   e.g. ("body_eng_h350_s150")
(define "body_eng_h350_s150"
	("breed_body" health(350%) regen_health(100%) stamina(150%) regen_stamina(100%) vision("mp_soldier") speed(0.9))
)

; body_sniper: breed_body tier, health 350%, regen_health 100%, stamina 150%, regen_stamina 100%, vision "mp_sniper", speed 1.0
;   e.g. ("body_sniper")
(define "body_sniper"
	("breed_body" health(350%) regen_health(100%) stamina(150%) regen_stamina(100%) vision("mp_sniper") speed(1.0))
)

; body_h350_s200: breed_body tier, health 350%, regen_health 100%, stamina 200%, regen_stamina 100%, vision "mp_soldier", speed 0.9
;   e.g. ("body_h350_s200")
(define "body_h350_s200"
	("breed_body" health(350%) regen_health(100%) stamina(200%) regen_stamina(100%) vision("mp_soldier") speed(0.9))
)

; body_sniper_s200: breed_body tier, health 350%, regen_health 100%, stamina 200%, regen_stamina 100%, vision "mp_sniper", speed 1.0
;   e.g. ("body_sniper_s200")
(define "body_sniper_s200"
	("breed_body" health(350%) regen_health(100%) stamina(200%) regen_stamina(100%) vision("mp_sniper") speed(1.0))
)

; body_jap_takasago: breed_body tier, health 350%, regen_health 100%, stamina 225%, regen_stamina 125%, vision "mp_soldier", speed 0.9
;   e.g. ("body_jap_takasago")
(define "body_jap_takasago"
	("breed_body" health(350%) regen_health(100%) stamina(225%) regen_stamina(125%) vision("mp_soldier") speed(0.9))
)

; body_elite: breed_body tier, health 400%, regen_health 100%, stamina 200%, regen_stamina 100%, vision "mp_soldier", speed 0.9
;   e.g. ("body_elite")
(define "body_elite"
	("breed_body" health(400%) regen_health(100%) stamina(200%) regen_stamina(100%) vision("mp_soldier") speed(0.9))
)

; body_elite_bare: breed_body tier, health 400%, regen_health 100%, stamina 200%, regen_stamina 100%, vision mp_soldier, speed 0.9
;   e.g. ("body_elite_bare")
(define "body_elite_bare"
	("breed_body" health(400%) regen_health(100%) stamina(200%) regen_stamina(100%) vision(mp_soldier) speed(0.9))
)

; body_crew_elite: breed_body tier, health 400%, regen_health 100%, stamina 200%, regen_stamina 100%, vision "mp_officer", speed 1
;   e.g. ("body_crew_elite")
(define "body_crew_elite"
	("breed_body" health(400%) regen_health(100%) stamina(200%) regen_stamina(100%) vision("mp_officer") speed(1))
)

; body_ger2_pzgren: breed_body tier, health 400%, regen_health 100%, stamina 225%, regen_stamina 125%, vision "mp_soldier", speed 1
;   e.g. ("body_ger2_pzgren")
(define "body_ger2_pzgren"
	("breed_body" health(400%) regen_health(100%) stamina(225%) regen_stamina(125%) vision("mp_soldier") speed(1))
)

; body_ger_gebirgsjager: breed_body tier, health 400%, regen_health 100%, stamina 225%, regen_stamina 125%, vision mp_soldier, speed 1
;   e.g. ("body_ger_gebirgsjager")
(define "body_ger_gebirgsjager"
	("breed_body" health(400%) regen_health(100%) stamina(225%) regen_stamina(125%) vision(mp_soldier) speed(1))
)

; drive_militia: breed_drive tier, tank 0.75, vehicle 0.8, cannon 0.8
;   e.g. ("drive_militia")
(define "drive_militia"
	("breed_drive" tank(0.75) vehicle(0.8) cannon(0.8))
)

; drive_regular: breed_drive tier, tank 0.75, vehicle 1, cannon 0.8
;   e.g. ("drive_regular")
(define "drive_regular"
	("breed_drive" tank(0.75) vehicle(1) cannon(0.8))
)

; drive_veteran: breed_drive tier, tank 0.85, vehicle 1, cannon 0.9
;   e.g. ("drive_veteran")
(define "drive_veteran"
	("breed_drive" tank(0.85) vehicle(1) cannon(0.9))
)

; drive_t08_v1_c1: breed_drive tier, tank 0.8, vehicle 1, cannon 1
;   e.g. ("drive_t08_v1_c1")
(define "drive_t08_v1_c1"
	("breed_drive" tank(0.8) vehicle(1) cannon(1))
)

; drive_t08_v10_c10: breed_drive tier, tank 0.8, vehicle 1.0, cannon 1.0
;   e.g. ("drive_t08_v10_c10")
(define "drive_t08_v10_c10"
	("breed_drive" tank(0.8) vehicle(1.0) cannon(1.0))
)

; drive_ger2_t10_v10_c08: breed_drive tier, tank 1.0, vehicle 1.0, cannon 0.8
;   e.g. ("drive_ger2_t10_v10_c08")
(define "drive_ger2_t10_v10_c08"
	("breed_drive" tank(1.0) vehicle(1.0) cannon(0.8))
)

; drive_support: breed_drive tier, tank 0.85, vehicle 1, cannon 1.0
;   e.g. ("drive_support")
(define "drive_support"
	("breed_drive" tank(0.85) vehicle(1) cannon(1.0))
)

; drive_t085_v10_c10: breed_drive tier, tank 0.85, vehicle 1.0, cannon 1.0
;   e.g. ("drive_t085_v10_c10")
(define "drive_t085_v10_c10"
	("breed_drive" tank(0.85) vehicle(1.0) cannon(1.0))
)

; drive_t09_v10_c10: breed_drive tier, tank 0.9, vehicle 1.0, cannon 1.0
;   e.g. ("drive_t09_v10_c10")
(define "drive_t09_v10_c10"
	("breed_drive" tank(0.9) vehicle(1.0) cannon(1.0))
)

; drive_crew: breed_drive tier, tank 1, vehicle 1, cannon 0.9
;   e.g. ("drive_crew")
(define "drive_crew"
	("breed_drive" tank(1) vehicle(1) cannon(0.9))
)

; drive_t10_v10_c09: breed_drive tier, tank 1.0, vehicle 1.0, cannon 0.9
;   e.g. ("drive_t10_v10_c09")
(define "drive_t10_v10_c09"
	("breed_drive" tank(1.0) vehicle(1.0) cannon(0.9))
)

; drive_t085_v105_c105: breed_drive tier, tank 0.85, vehicle 1.05, cannon 1.05
;   e.g. ("drive_t085_v105_c105")
(define "drive_t085_v105_c105"
	("breed_drive" tank(0.85) vehicle(1.05) cannon(1.05))
)

; drive_elite: breed_drive tier, tank 0.95, vehicle 1, cannon 1
;   e.g. ("drive_elite")
(define "drive_elite"
	("breed_drive" tank(0.95) vehicle(1) cannon(1))
)

; drive_t1_v1_c1: breed_drive tier, tank 1, vehicle 1, cannon 1
;   e.g. ("drive_t1_v1_c1")
(define "drive_t1_v1_c1"
	("breed_drive" tank(1) vehicle(1) cannon(1))
)

; drive_t10_v10_c10: breed_drive tier, tank 1.0, vehicle 1.0, cannon 1.0
;   e.g. ("drive_t10_v10_c10")
(define "drive_t10_v10_c10"
	("breed_drive" tank(1.0) vehicle(1.0) cannon(1.0))
)

; drive_crew_commander: breed_drive tier, tank 1.1, vehicle 1, cannon 0.95
;   e.g. ("drive_crew_commander")
(define "drive_crew_commander"
	("breed_drive" tank(1.1) vehicle(1) cannon(0.95))
)

; drive_t11_v10_c095: breed_drive tier, tank 1.1, vehicle 1.0, cannon 0.95
;   e.g. ("drive_t11_v10_c095")
(define "drive_t11_v10_c095"
	("breed_drive" tank(1.1) vehicle(1.0) cannon(0.95))
)

; drive_t110_v110_c105: breed_drive tier, tank 1.10, vehicle 1.10, cannon 1.05
;   e.g. ("drive_t110_v110_c105")
(define "drive_t110_v110_c105"
	("breed_drive" tank(1.10) vehicle(1.10) cannon(1.05))
)

; drive_crew_elite: breed_drive tier, tank 1.15, vehicle 1.15, cannon 1.0
;   e.g. ("drive_crew_elite")
(define "drive_crew_elite"
	("breed_drive" tank(1.15) vehicle(1.15) cannon(1.0))
)

; drive_t115_v115_c105: breed_drive tier, tank 1.15, vehicle 1.15, cannon 1.05
;   e.g. ("drive_t115_v115_c105")
(define "drive_t115_v115_c105"
	("breed_drive" tank(1.15) vehicle(1.15) cannon(1.05))
)

; drive_t115_v115_c11: breed_drive tier, tank 1.15, vehicle 1.15, cannon 1.1
;   e.g. ("drive_t115_v115_c11")
(define "drive_t115_v115_c11"
	("breed_drive" tank(1.15) vehicle(1.15) cannon(1.1))
)

; drive_t120_v120_c10: breed_drive tier, tank 1.20, vehicle 1.20, cannon 1.0
;   e.g. ("drive_t120_v120_c10")
(define "drive_t120_v120_c10"
	("breed_drive" tank(1.20) vehicle(1.20) cannon(1.0))
)

; drive_t12_v12_c11: breed_drive tier, tank 1.2, vehicle 1.2, cannon 1.1
;   e.g. ("drive_t12_v12_c11")
(define "drive_t12_v12_c11"
	("breed_drive" tank(1.2) vehicle(1.2) cannon(1.1))
)

; skills_rus_militia: breed_skills tier, pistol 1, smg 1, mgun 1, rifle 1, rocket 1, melee 2
;   e.g. ("skills_rus_militia")
(define "skills_rus_militia"
	("breed_skills" pistol(1) smg(1) mgun(1) rifle(1) rocket(1) melee(2))
)

; skills_ger_volkssturm: breed_skills tier, pistol 1, smg 1, mgun 1, rifle 1, rocket 2, melee 2
;   e.g. ("skills_ger_volkssturm")
(define "skills_ger_volkssturm"
	("breed_skills" pistol(1) smg(1) mgun(1) rifle(1) rocket(2) melee(2))
)

; skills_jap_charger: breed_skills tier, pistol 1, smg 1, mgun 1, rifle 1, rocket 1, melee 4
;   e.g. ("skills_jap_charger")
(define "skills_jap_charger"
	("breed_skills" pistol(1) smg(1) mgun(1) rifle(1) rocket(1) melee(4))
)

; skills_1_1_1_2_2_2: breed_skills tier, pistol 1, smg 1, mgun 1, rifle 2, rocket 2, melee 2
;   e.g. ("skills_1_1_1_2_2_2")
(define "skills_1_1_1_2_2_2"
	("breed_skills" pistol(1) smg(1) mgun(1) rifle(2) rocket(2) melee(2))
)

; skills_jap_1_1_3_1_1_2: breed_skills tier, pistol 1, smg 1, mgun 3, rifle 1, rocket 1, melee 2
;   e.g. ("skills_jap_1_1_3_1_1_2")
(define "skills_jap_1_1_3_1_1_2"
	("breed_skills" pistol(1) smg(1) mgun(3) rifle(1) rocket(1) melee(2))
)

; skills_2_1_1_2_1_2: breed_skills tier, pistol 2, smg 1, mgun 1, rifle 2, rocket 1, melee 2
;   e.g. ("skills_2_1_1_2_1_2")
(define "skills_2_1_1_2_1_2"
	("breed_skills" pistol(2) smg(1) mgun(1) rifle(2) rocket(1) melee(2))
)

; skills_ger_ss_2_1_2_1_1_2: breed_skills tier, pistol 2, smg 1, mgun 2, rifle 1, rocket 1, melee 2
;   e.g. ("skills_ger_ss_2_1_2_1_1_2")
(define "skills_ger_ss_2_1_2_1_1_2"
	("breed_skills" pistol(2) smg(1) mgun(2) rifle(1) rocket(1) melee(2))
)

; skills_2_2_1_1_1_2: breed_skills tier, pistol 2, smg 2, mgun 1, rifle 1, rocket 1, melee 2
;   e.g. ("skills_2_2_1_1_1_2")
(define "skills_2_2_1_1_1_2"
	("breed_skills" pistol(2) smg(2) mgun(1) rifle(1) rocket(1) melee(2))
)

; skills_2_1_1_3_1_2: breed_skills tier, pistol 2, smg 1, mgun 1, rifle 3, rocket 1, melee 2
;   e.g. ("skills_2_1_1_3_1_2")
(define "skills_2_1_1_3_1_2"
	("breed_skills" pistol(2) smg(1) mgun(1) rifle(3) rocket(1) melee(2))
)

; skills_rus_2_2_1_2_1_2: breed_skills tier, pistol 2, smg 2, mgun 1, rifle 2, rocket 1, melee 2
;   e.g. ("skills_rus_2_2_1_2_1_2")
(define "skills_rus_2_2_1_2_1_2"
	("breed_skills" pistol(2) smg(2) mgun(1) rifle(2) rocket(1) melee(2))
)

; skills_2_2_2_1_1_2: breed_skills tier, pistol 2, smg 2, mgun 2, rifle 1, rocket 1, melee 2
;   e.g. ("skills_2_2_2_1_1_2")
(define "skills_2_2_2_1_1_2"
	("breed_skills" pistol(2) smg(2) mgun(2) rifle(1) rocket(1) melee(2))
)

; skills_2_3_1_1_1_2: breed_skills tier, pistol 2, smg 3, mgun 1, rifle 1, rocket 1, melee 2
;   e.g. ("skills_2_3_1_1_1_2")
(define "skills_2_3_1_1_1_2"
	("breed_skills" pistol(2) smg(3) mgun(1) rifle(1) rocket(1) melee(2))
)

; skills_2_1_1_3_1_3: breed_skills tier, pistol 2, smg 1, mgun 1, rifle 3, rocket 1, melee 3
;   e.g. ("skills_2_1_1_3_1_3")
(define "skills_2_1_1_3_1_3"
	("breed_skills" pistol(2) smg(1) mgun(1) rifle(3) rocket(1) melee(3))
)

; skills_2_1_1_3_2_2: breed_skills tier, pistol 2, smg 1, mgun 1, rifle 3, rocket 2, melee 2
;   e.g. ("skills_2_1_1_3_2_2")
(define "skills_2_1_1_3_2_2"
	("breed_skills" pistol(2) smg(1) mgun(1) rifle(3) rocket(2) melee(2))
)

; skills_2_2_1_1_3_2: breed_skills tier, pistol 2, smg 2, mgun 1, rifle 1, rocket 3, melee 2
;   e.g. ("skills_2_2_1_1_3_2")
(define "skills_2_2_1_1_3_2"
	("breed_skills" pistol(2) smg(2) mgun(1) rifle(1) rocket(3) melee(2))
)

; skills_2_2_1_3_1_2: breed_skills tier, pistol 2, smg 2, mgun 1, rifle 3, rocket 1, melee 2
;   e.g. ("skills_2_2_1_3_1_2")
(define "skills_2_2_1_3_1_2"
	("breed_skills" pistol(2) smg(2) mgun(1) rifle(3) rocket(1) melee(2))
)

; skills_2_3_1_1_1_3: breed_skills tier, pistol 2, smg 3, mgun 1, rifle 1, rocket 1, melee 3
;   e.g. ("skills_2_3_1_1_1_3")
(define "skills_2_3_1_1_1_3"
	("breed_skills" pistol(2) smg(3) mgun(1) rifle(1) rocket(1) melee(3))
)

; skills_2_3_1_1_2_2: breed_skills tier, pistol 2, smg 3, mgun 1, rifle 1, rocket 2, melee 2
;   e.g. ("skills_2_3_1_1_2_2")
(define "skills_2_3_1_1_2_2"
	("breed_skills" pistol(2) smg(3) mgun(1) rifle(1) rocket(2) melee(2))
)

; skills_2_1_3_3_1_2: breed_skills tier, pistol 2, smg 1, mgun 3, rifle 3, rocket 1, melee 2
;   e.g. ("skills_2_1_3_3_1_2")
(define "skills_2_1_3_3_1_2"
	("breed_skills" pistol(2) smg(1) mgun(3) rifle(3) rocket(1) melee(2))
)

; skills_2_2_1_4_1_2: breed_skills tier, pistol 2, smg 2, mgun 1, rifle 4, rocket 1, melee 2
;   e.g. ("skills_2_2_1_4_1_2")
(define "skills_2_2_1_4_1_2"
	("breed_skills" pistol(2) smg(2) mgun(1) rifle(4) rocket(1) melee(2))
)

; skills_axis_minor_2_2_4_1_1_2: breed_skills tier, pistol 2, smg 2, mgun 4, rifle 1, rocket 1, melee 2
;   e.g. ("skills_axis_minor_2_2_4_1_1_2")
(define "skills_axis_minor_2_2_4_1_1_2"
	("breed_skills" pistol(2) smg(2) mgun(4) rifle(1) rocket(1) melee(2))
)

; skills_2_3_2_2_1_2: breed_skills tier, pistol 2, smg 3, mgun 2, rifle 2, rocket 1, melee 2
;   e.g. ("skills_2_3_2_2_1_2")
(define "skills_2_3_2_2_1_2"
	("breed_skills" pistol(2) smg(3) mgun(2) rifle(2) rocket(1) melee(2))
)

; skills_2_1_3_3_1_3: breed_skills tier, pistol 2, smg 1, mgun 3, rifle 3, rocket 1, melee 3
;   e.g. ("skills_2_1_3_3_1_3")
(define "skills_2_1_3_3_1_3"
	("breed_skills" pistol(2) smg(1) mgun(3) rifle(3) rocket(1) melee(3))
)

; skills_sniper_r5: breed_skills tier, pistol 2, smg 2, mgun 1, rifle 5, rocket 1, melee 2
;   e.g. ("skills_sniper_r5")
(define "skills_sniper_r5"
	("breed_skills" pistol(2) smg(2) mgun(1) rifle(5) rocket(1) melee(2))
)

; skills_2_2_2_3_1_3: breed_skills tier, pistol 2, smg 2, mgun 2, rifle 3, rocket 1, melee 3
;   e.g. ("skills_2_2_2_3_1_3")
(define "skills_2_2_2_3_1_3"
	("breed_skills" pistol(2) smg(2) mgun(2) rifle(3) rocket(1) melee(3))
)

; skills_2_2_3_2_1_3: breed_skills tier, pistol 2, smg 2, mgun 3, rifle 2, rocket 1, melee 3
;   e.g. ("skills_2_2_3_2_1_3")
(define "skills_2_2_3_2_1_3"
	("breed_skills" pistol(2) smg(2) mgun(3) rifle(2) rocket(1) melee(3))
)

; skills_2_3_2_2_1_3: breed_skills tier, pistol 2, smg 3, mgun 2, rifle 2, rocket 1, melee 3
;   e.g. ("skills_2_3_2_2_1_3")
(define "skills_2_3_2_2_1_3"
	("breed_skills" pistol(2) smg(3) mgun(2) rifle(2) rocket(1) melee(3))
)

; skills_2_2_3_2_2_3: breed_skills tier, pistol 2, smg 2, mgun 3, rifle 2, rocket 2, melee 3
;   e.g. ("skills_2_2_3_2_2_3")
(define "skills_2_2_3_2_2_3"
	("breed_skills" pistol(2) smg(2) mgun(3) rifle(2) rocket(2) melee(3))
)

; skills_2_2_3_3_1_3: breed_skills tier, pistol 2, smg 2, mgun 3, rifle 3, rocket 1, melee 3
;   e.g. ("skills_2_2_3_3_1_3")
(define "skills_2_2_3_3_1_3"
	("breed_skills" pistol(2) smg(2) mgun(3) rifle(3) rocket(1) melee(3))
)

; skills_3_3_2_2_1_3: breed_skills tier, pistol 3, smg 3, mgun 2, rifle 2, rocket 1, melee 3
;   e.g. ("skills_3_3_2_2_1_3")
(define "skills_3_3_2_2_1_3"
	("breed_skills" pistol(3) smg(3) mgun(2) rifle(2) rocket(1) melee(3))
)

; skills_usa_2_2_2_3_4_3: breed_skills tier, pistol 2, smg 2, mgun 2, rifle 3, rocket 4, melee 3
;   e.g. ("skills_usa_2_2_2_3_4_3")
(define "skills_usa_2_2_2_3_4_3"
	("breed_skills" pistol(2) smg(2) mgun(2) rifle(3) rocket(4) melee(3))
)

; skills_2_2_2_4_2_4: breed_skills tier, pistol 2, smg 2, mgun 2, rifle 4, rocket 2, melee 4
;   e.g. ("skills_2_2_2_4_2_4")
(define "skills_2_2_2_4_2_4"
	("breed_skills" pistol(2) smg(2) mgun(2) rifle(4) rocket(2) melee(4))
)

; skills_support: breed_skills tier, pistol 2, smg 2, mgun 4, rifle 2, rocket 2, melee 4
;   e.g. ("skills_support")
(define "skills_support"
	("breed_skills" pistol(2) smg(2) mgun(4) rifle(2) rocket(2) melee(4))
)

; skills_3_2_2_4_2_3: breed_skills tier, pistol 3, smg 2, mgun 2, rifle 4, rocket 2, melee 3
;   e.g. ("skills_3_2_2_4_2_3")
(define "skills_3_2_2_4_2_3"
	("breed_skills" pistol(3) smg(2) mgun(2) rifle(4) rocket(2) melee(3))
)

; skills_3_2_4_2_2_3: breed_skills tier, pistol 3, smg 2, mgun 4, rifle 2, rocket 2, melee 3
;   e.g. ("skills_3_2_4_2_2_3")
(define "skills_3_2_4_2_2_3"
	("breed_skills" pistol(3) smg(2) mgun(4) rifle(2) rocket(2) melee(3))
)

; skills_3_4_2_2_2_3: breed_skills tier, pistol 3, smg 4, mgun 2, rifle 2, rocket 2, melee 3
;   e.g. ("skills_3_4_2_2_2_3")
(define "skills_3_4_2_2_2_3"
	("breed_skills" pistol(3) smg(4) mgun(2) rifle(2) rocket(2) melee(3))
)

; skills_3_2_4_4_2_3: breed_skills tier, pistol 3, smg 2, mgun 4, rifle 4, rocket 2, melee 3
;   e.g. ("skills_3_2_4_4_2_3")
(define "skills_3_2_4_4_2_3"
	("breed_skills" pistol(3) smg(2) mgun(4) rifle(4) rocket(2) melee(3))
)

; skills_3_3_3_3_3_3: breed_skills tier, pistol 3, smg 3, mgun 3, rifle 3, rocket 3, melee 3
;   e.g. ("skills_3_3_3_3_3_3")
(define "skills_3_3_3_3_3_3"
	("breed_skills" pistol(3) smg(3) mgun(3) rifle(3) rocket(3) melee(3))
)

; skills_3_3_3_4_2_4: breed_skills tier, pistol 3, smg 3, mgun 3, rifle 4, rocket 2, melee 4
;   e.g. ("skills_3_3_3_4_2_4")
(define "skills_3_3_3_4_2_4"
	("breed_skills" pistol(3) smg(3) mgun(3) rifle(4) rocket(2) melee(4))
)

; skills_3_3_3_4_3_3: breed_skills tier, pistol 3, smg 3, mgun 3, rifle 4, rocket 3, melee 3
;   e.g. ("skills_3_3_3_4_3_3")
(define "skills_3_3_3_4_3_3"
	("breed_skills" pistol(3) smg(3) mgun(3) rifle(4) rocket(3) melee(3))
)

; skills_3_3_4_3_3_3: breed_skills tier, pistol 3, smg 3, mgun 4, rifle 3, rocket 3, melee 3
;   e.g. ("skills_3_3_4_3_3_3")
(define "skills_3_3_4_3_3_3"
	("breed_skills" pistol(3) smg(3) mgun(4) rifle(3) rocket(3) melee(3))
)

; skills_4_3_2_4_2_4: breed_skills tier, pistol 4, smg 3, mgun 2, rifle 4, rocket 2, melee 4
;   e.g. ("skills_4_3_2_4_2_4")
(define "skills_4_3_2_4_2_4"
	("breed_skills" pistol(4) smg(3) mgun(2) rifle(4) rocket(2) melee(4))
)

; skills_4_4_2_3_2_4: breed_skills tier, pistol 4, smg 4, mgun 2, rifle 3, rocket 2, melee 4
;   e.g. ("skills_4_4_2_3_2_4")
(define "skills_4_4_2_3_2_4"
	("breed_skills" pistol(4) smg(4) mgun(2) rifle(3) rocket(2) melee(4))
)

; skills_3_3_4_4_3_3: breed_skills tier, pistol 3, smg 3, mgun 4, rifle 4, rocket 3, melee 3
;   e.g. ("skills_3_3_4_4_3_3")
(define "skills_3_3_4_4_3_3"
	("breed_skills" pistol(3) smg(3) mgun(4) rifle(4) rocket(3) melee(3))
)

; skills_3_3_5_3_2_4: breed_skills tier, pistol 3, smg 3, mgun 5, rifle 3, rocket 2, melee 4
;   e.g. ("skills_3_3_5_3_2_4")
(define "skills_3_3_5_3_2_4"
	("breed_skills" pistol(3) smg(3) mgun(5) rifle(3) rocket(2) melee(4))
)

; skills_4_3_2_5_2_4: breed_skills tier, pistol 4, smg 3, mgun 2, rifle 5, rocket 2, melee 4
;   e.g. ("skills_4_3_2_5_2_4")
(define "skills_4_3_2_5_2_4"
	("breed_skills" pistol(4) smg(3) mgun(2) rifle(5) rocket(2) melee(4))
)

; skills_4_3_4_3_2_4: breed_skills tier, pistol 4, smg 3, mgun 4, rifle 3, rocket 2, melee 4
;   e.g. ("skills_4_3_4_3_2_4")
(define "skills_4_3_4_3_2_4"
	("breed_skills" pistol(4) smg(3) mgun(4) rifle(3) rocket(2) melee(4))
)

; skills_4_4_1_5_2_4: breed_skills tier, pistol 4, smg 4, mgun 1, rifle 5, rocket 2, melee 4
;   e.g. ("skills_4_4_1_5_2_4")
(define "skills_4_4_1_5_2_4"
	("breed_skills" pistol(4) smg(4) mgun(1) rifle(5) rocket(2) melee(4))
)

; skills_4_3_2_4_4_4: breed_skills tier, pistol 4, smg 3, mgun 2, rifle 4, rocket 4, melee 4
;   e.g. ("skills_4_3_2_4_4_4")
(define "skills_4_3_2_4_4_4"
	("breed_skills" pistol(4) smg(3) mgun(2) rifle(4) rocket(4) melee(4))
)

; skills_sniper_r6: breed_skills tier, pistol 4, smg 3, mgun 2, rifle 6, rocket 2, melee 4
;   e.g. ("skills_sniper_r6")
(define "skills_sniper_r6"
	("breed_skills" pistol(4) smg(3) mgun(2) rifle(6) rocket(2) melee(4))
)

; skills_4_3_4_4_2_4: breed_skills tier, pistol 4, smg 3, mgun 4, rifle 4, rocket 2, melee 4
;   e.g. ("skills_4_3_4_4_2_4")
(define "skills_4_3_4_4_2_4"
	("breed_skills" pistol(4) smg(3) mgun(4) rifle(4) rocket(2) melee(4))
)

; skills_4_4_2_5_2_4: breed_skills tier, pistol 4, smg 4, mgun 2, rifle 5, rocket 2, melee 4
;   e.g. ("skills_4_4_2_5_2_4")
(define "skills_4_4_2_5_2_4"
	("breed_skills" pistol(4) smg(4) mgun(2) rifle(5) rocket(2) melee(4))
)

; skills_4_4_4_3_2_4: breed_skills tier, pistol 4, smg 4, mgun 4, rifle 3, rocket 2, melee 4
;   e.g. ("skills_4_4_4_3_2_4")
(define "skills_4_4_4_3_2_4"
	("breed_skills" pistol(4) smg(4) mgun(4) rifle(3) rocket(2) melee(4))
)

; skills_jap_3_3_3_5_3_5: breed_skills tier, pistol 3, smg 3, mgun 3, rifle 5, rocket 3, melee 5
;   e.g. ("skills_jap_3_3_3_5_3_5")
(define "skills_jap_3_3_3_5_3_5"
	("breed_skills" pistol(3) smg(3) mgun(3) rifle(5) rocket(3) melee(5))
)

; skills_4_3_2_4_5_4: breed_skills tier, pistol 4, smg 3, mgun 2, rifle 4, rocket 5, melee 4
;   e.g. ("skills_4_3_2_4_5_4")
(define "skills_4_3_2_4_5_4"
	("breed_skills" pistol(4) smg(3) mgun(2) rifle(4) rocket(5) melee(4))
)

; skills_4_3_2_5_3_5: breed_skills tier, pistol 4, smg 3, mgun 2, rifle 5, rocket 3, melee 5
;   e.g. ("skills_4_3_2_5_3_5")
(define "skills_4_3_2_5_3_5"
	("breed_skills" pistol(4) smg(3) mgun(2) rifle(5) rocket(3) melee(5))
)

; skills_4_5_2_3_3_5: breed_skills tier, pistol 4, smg 5, mgun 2, rifle 3, rocket 3, melee 5
;   e.g. ("skills_4_5_2_3_3_5")
(define "skills_4_5_2_3_3_5"
	("breed_skills" pistol(4) smg(5) mgun(2) rifle(3) rocket(3) melee(5))
)

; skills_ger_ss_4_3_3_5_4_4: breed_skills tier, pistol 4, smg 3, mgun 3, rifle 5, rocket 4, melee 4
;   e.g. ("skills_ger_ss_4_3_3_5_4_4")
(define "skills_ger_ss_4_3_3_5_4_4"
	("breed_skills" pistol(4) smg(3) mgun(3) rifle(5) rocket(4) melee(4))
)

; skills_ger_ss_4_3_5_3_4_4: breed_skills tier, pistol 4, smg 3, mgun 5, rifle 3, rocket 4, melee 4
;   e.g. ("skills_ger_ss_4_3_5_3_4_4")
(define "skills_ger_ss_4_3_5_3_4_4"
	("breed_skills" pistol(4) smg(3) mgun(5) rifle(3) rocket(4) melee(4))
)

; skills_ger_ss_4_5_3_3_4_4: breed_skills tier, pistol 4, smg 5, mgun 3, rifle 3, rocket 4, melee 4
;   e.g. ("skills_ger_ss_4_5_3_3_4_4")
(define "skills_ger_ss_4_5_3_3_4_4"
	("breed_skills" pistol(4) smg(5) mgun(3) rifle(3) rocket(4) melee(4))
)

; skills_4_5_3_4_2_5: breed_skills tier, pistol 4, smg 5, mgun 3, rifle 4, rocket 2, melee 5
;   e.g. ("skills_4_5_3_4_2_5")
(define "skills_4_5_3_4_2_5"
	("breed_skills" pistol(4) smg(5) mgun(3) rifle(4) rocket(2) melee(5))
)

; skills_ger_4_3_3_5_4_5: breed_skills tier, pistol 4, smg 3, mgun 3, rifle 5, rocket 4, melee 5
;   e.g. ("skills_ger_4_3_3_5_4_5")
(define "skills_ger_4_3_3_5_4_5"
	("breed_skills" pistol(4) smg(3) mgun(3) rifle(5) rocket(4) melee(5))
)

; skills_ger_ss_4_3_3_5_5_4: breed_skills tier, pistol 4, smg 3, mgun 3, rifle 5, rocket 5, melee 4
;   e.g. ("skills_ger_ss_4_3_3_5_5_4")
(define "skills_ger_ss_4_3_3_5_5_4"
	("breed_skills" pistol(4) smg(3) mgun(3) rifle(5) rocket(5) melee(4))
)

; skills_ger_ss_4_3_4_5_4_4: breed_skills tier, pistol 4, smg 3, mgun 4, rifle 5, rocket 4, melee 4
;   e.g. ("skills_ger_ss_4_3_4_5_4_4")
(define "skills_ger_ss_4_3_4_5_4_4"
	("breed_skills" pistol(4) smg(3) mgun(4) rifle(5) rocket(4) melee(4))
)

; skills_4_3_5_5_2_5: breed_skills tier, pistol 4, smg 3, mgun 5, rifle 5, rocket 2, melee 5
;   e.g. ("skills_4_3_5_5_2_5")
(define "skills_4_3_5_5_2_5"
	("breed_skills" pistol(4) smg(3) mgun(5) rifle(5) rocket(2) melee(5))
)

; skills_4_4_4_4_4_4: breed_skills tier, pistol 4, smg 4, mgun 4, rifle 4, rocket 4, melee 4
;   e.g. ("skills_4_4_4_4_4_4")
(define "skills_4_4_4_4_4_4"
	("breed_skills" pistol(4) smg(4) mgun(4) rifle(4) rocket(4) melee(4))
)

; skills_4_5_6_3_2_4: breed_skills tier, pistol 4, smg 5, mgun 6, rifle 3, rocket 2, melee 4
;   e.g. ("skills_4_5_6_3_2_4")
(define "skills_4_5_6_3_2_4"
	("breed_skills" pistol(4) smg(5) mgun(6) rifle(3) rocket(2) melee(4))
)

; skills_5_3_5_4_2_5: breed_skills tier, pistol 5, smg 3, mgun 5, rifle 4, rocket 2, melee 5
;   e.g. ("skills_5_3_5_4_2_5")
(define "skills_5_3_5_4_2_5"
	("breed_skills" pistol(5) smg(3) mgun(5) rifle(4) rocket(2) melee(5))
)

; skills_5_5_3_4_2_5: breed_skills tier, pistol 5, smg 5, mgun 3, rifle 4, rocket 2, melee 5
;   e.g. ("skills_5_5_3_4_2_5")
(define "skills_5_5_3_4_2_5"
	("breed_skills" pistol(5) smg(5) mgun(3) rifle(4) rocket(2) melee(5))
)

; skills_ger_ss_4_3_5_5_4_4: breed_skills tier, pistol 4, smg 3, mgun 5, rifle 5, rocket 4, melee 4
;   e.g. ("skills_ger_ss_4_3_5_5_4_4")
(define "skills_ger_ss_4_3_5_5_4_4"
	("breed_skills" pistol(4) smg(3) mgun(5) rifle(5) rocket(4) melee(4))
)

; skills_usa_4_4_4_5_4_4: breed_skills tier, pistol 4, smg 4, mgun 4, rifle 5, rocket 4, melee 4
;   e.g. ("skills_usa_4_4_4_5_4_4")
(define "skills_usa_4_4_4_5_4_4"
	("breed_skills" pistol(4) smg(4) mgun(4) rifle(5) rocket(4) melee(4))
)

; skills_4_5_4_4_4_4: breed_skills tier, pistol 4, smg 5, mgun 4, rifle 4, rocket 4, melee 4
;   e.g. ("skills_4_5_4_4_4_4")
(define "skills_4_5_4_4_4_4"
	("breed_skills" pistol(4) smg(5) mgun(4) rifle(4) rocket(4) melee(4))
)

; skills_ger_4_3_5_5_4_5: breed_skills tier, pistol 4, smg 3, mgun 5, rifle 5, rocket 4, melee 5
;   e.g. ("skills_ger_4_3_5_5_4_5")
(define "skills_ger_4_3_5_5_4_5"
	("breed_skills" pistol(4) smg(3) mgun(5) rifle(5) rocket(4) melee(5))
)

; skills_usa_4_4_5_5_4_4: breed_skills tier, pistol 4, smg 4, mgun 5, rifle 5, rocket 4, melee 4
;   e.g. ("skills_usa_4_4_5_5_4_4")
(define "skills_usa_4_4_5_5_4_4"
	("breed_skills" pistol(4) smg(4) mgun(5) rifle(5) rocket(4) melee(4))
)

; skills_ger_5_4_4_5_4_5: breed_skills tier, pistol 5, smg 4, mgun 4, rifle 5, rocket 4, melee 5
;   e.g. ("skills_ger_5_4_4_5_4_5")
(define "skills_ger_5_4_4_5_4_5"
	("breed_skills" pistol(5) smg(4) mgun(4) rifle(5) rocket(4) melee(5))
)

; skills_ger_5_4_5_4_4_5: breed_skills tier, pistol 5, smg 4, mgun 5, rifle 4, rocket 4, melee 5
;   e.g. ("skills_ger_5_4_5_4_4_5")
(define "skills_ger_5_4_5_4_4_5"
	("breed_skills" pistol(5) smg(4) mgun(5) rifle(4) rocket(4) melee(5))
)

; skills_squadleader: breed_skills tier, pistol 5, smg 5, mgun 4, rifle 5, rocket 4, melee 5
;   e.g. ("skills_squadleader")
(define "skills_squadleader"
	("breed_skills" pistol(5) smg(5) mgun(4) rifle(5) rocket(4) melee(5))
)

; skills_ger_5_5_4_4_6_5: breed_skills tier, pistol 5, smg 5, mgun 4, rifle 4, rocket 6, melee 5
;   e.g. ("skills_ger_5_5_4_4_6_5")
(define "skills_ger_5_5_4_4_6_5"
	("breed_skills" pistol(5) smg(5) mgun(4) rifle(4) rocket(6) melee(5))
)

; skills_jap_6_4_4_6_4_6: breed_skills tier, pistol 6, smg 4, mgun 4, rifle 6, rocket 4, melee 6
;   e.g. ("skills_jap_6_4_4_6_4_6")
(define "skills_jap_6_4_4_6_4_6"
	("breed_skills" pistol(6) smg(4) mgun(4) rifle(6) rocket(4) melee(6))
)

; skills_5_5_5_6_5_5: breed_skills tier, pistol 5, smg 5, mgun 5, rifle 6, rocket 5, melee 5
;   e.g. ("skills_5_5_5_6_5_5")
(define "skills_5_5_5_6_5_5"
	("breed_skills" pistol(5) smg(5) mgun(5) rifle(6) rocket(5) melee(5))
)

; skills_usa_5_6_5_5_5_5: breed_skills tier, pistol 5, smg 6, mgun 5, rifle 5, rocket 5, melee 5
;   e.g. ("skills_usa_5_6_5_5_5_5")
(define "skills_usa_5_6_5_5_5_5"
	("breed_skills" pistol(5) smg(6) mgun(5) rifle(5) rocket(5) melee(5))
)

; skills_5_5_6_6_5_5: breed_skills tier, pistol 5, smg 5, mgun 6, rifle 6, rocket 5, melee 5
;   e.g. ("skills_5_5_6_6_5_5")
(define "skills_5_5_6_6_5_5"
	("breed_skills" pistol(5) smg(5) mgun(6) rifle(6) rocket(5) melee(5))
)

; skills_jap_5_5_5_7_5_7: breed_skills tier, pistol 5, smg 5, mgun 5, rifle 7, rocket 5, melee 7
;   e.g. ("skills_jap_5_5_5_7_5_7")
(define "skills_jap_5_5_5_7_5_7"
	("breed_skills" pistol(5) smg(5) mgun(5) rifle(7) rocket(5) melee(7))
)

; skills_elite_6: breed_skills tier, pistol 6, smg 6, mgun 6, rifle 6, rocket 6, melee 6
;   e.g. ("skills_elite_6")
(define "skills_elite_6"
	("breed_skills" pistol(6) smg(6) mgun(6) rifle(6) rocket(6) melee(6))
)

; skills_elite_7: breed_skills tier, pistol 7, smg 7, mgun 7, rifle 7, rocket 7, melee 7
;   e.g. ("skills_elite_7")
(define "skills_elite_7"
	("breed_skills" pistol(7) smg(7) mgun(7) rifle(7) rocket(7) melee(7))
)
