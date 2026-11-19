; breed_soldier.inc: one call sets an infantry soldier's health, stamina, crew skills and weapon skills from his LEVEL.
;   A breed writes ("soldier_<main>_<level>" rocket(N) body(line|hardy)), e.g. ("soldier_rifle_5" rocket(1) body(line)).
;   main  = class of the weapon he carries: rifle, smg, mgun, pistol (a bazooka / Panzerschreck / PIAT man uses rifle)
;   level = 1 (militia) to 7 (elite) = his skill with that weapon. Everyone in a squad has the same level;
;           the squad leader and assistant leader are one level higher; an MG / AT / ammo assistant has the
;           same call as the man he assists.
;   rocket = rocketlauncher skill: his level if he carries a rocket weapon; level minus 1 for German and Hungarian
;           soldiers of 1944-45 who are not assistants; 1 for everyone else.
;   body  = line, or hardy for the health bump of the SS (ger_ss) and Japan (jap).
;
;   level  health line / hardy   stamina   speed   tank  vehicle  cannon
;   1      100% / 150%         75%       0.9     0.75  1        0.8
;   2      150% / 200%         100%      0.9     0.75  1        0.8
;   3      150% / 200%         100%      0.9     0.75  1        0.8
;   4      150% / 200%         100%      0.9     0.75  1        0.8
;   5      200% / 300%         150%      0.9     0.85  1        0.9
;   6      350% / 400%         200%      0.9     0.95  1        1
;   7      400% / 450%         200%      0.9     0.95  1        1
;
;   skills per level, as pistol smg mgun rifle melee (rocket comes from the call)
;   level  main rifle   main smg    main mgun   main pistol
;   1      1 1 1 1 2   1 1 1 1 2   1 1 1 1 2   1 1 1 1 2   
;   2      1 1 1 2 2   2 2 1 1 2   2 1 2 1 2   2 2 2 2 2   
;   3      2 2 2 3 3   2 3 2 2 3   2 2 3 2 3   3 3 3 3 3   
;   4      4 3 2 4 4   4 4 2 3 4   4 3 4 3 4   4 4 4 4 4   
;   5      4 3 3 5 4   4 5 3 3 4   4 3 5 3 4   5 5 5 5 5   
;   6      5 5 5 6 5   5 6 5 5 5   5 5 6 5 5   6 5 5 5 5   
;   7      6 6 6 7 6   6 7 6 6 6   6 6 7 6 6   7 6 6 6 6   
;
;   A soldier with his own vision (officer, sniper) or stamina regeneration writes the three parts himself:
;     ("breed_body" ...his values...)  ("drive_level_5")  ("skills_rifle_5" rocket(1))
;   Tank crews, vehicle supporters, kamikaze / lunge mine / AT stick men and banzai chargers are not on this table.
;   Included from breed_macros.inc. Written by E:/arsenal-tmp/robz-toe/apply/soldier-remap.js; change a number here to rebalance a level.

; body_level_1_line: health 100%, stamina 75%, speed 0.9
(define "body_level_1_line"
	("breed_body" health(100%) regen_health(100%) stamina(75%) regen_stamina(100%) vision("mp_soldier") speed(0.9))
)

; body_level_1_hardy: health 150%, stamina 75%, speed 0.9
(define "body_level_1_hardy"
	("breed_body" health(150%) regen_health(100%) stamina(75%) regen_stamina(100%) vision("mp_soldier") speed(0.9))
)

; body_level_2_line: health 150%, stamina 100%, speed 0.9
(define "body_level_2_line"
	("breed_body" health(150%) regen_health(100%) stamina(100%) regen_stamina(100%) vision("mp_soldier") speed(0.9))
)

; body_level_2_hardy: health 200%, stamina 100%, speed 0.9
(define "body_level_2_hardy"
	("breed_body" health(200%) regen_health(100%) stamina(100%) regen_stamina(100%) vision("mp_soldier") speed(0.9))
)

; body_level_3_line: health 150%, stamina 100%, speed 0.9
(define "body_level_3_line"
	("breed_body" health(150%) regen_health(100%) stamina(100%) regen_stamina(100%) vision("mp_soldier") speed(0.9))
)

; body_level_3_hardy: health 200%, stamina 100%, speed 0.9
(define "body_level_3_hardy"
	("breed_body" health(200%) regen_health(100%) stamina(100%) regen_stamina(100%) vision("mp_soldier") speed(0.9))
)

; body_level_4_line: health 150%, stamina 100%, speed 0.9
(define "body_level_4_line"
	("breed_body" health(150%) regen_health(100%) stamina(100%) regen_stamina(100%) vision("mp_soldier") speed(0.9))
)

; body_level_4_hardy: health 200%, stamina 100%, speed 0.9
(define "body_level_4_hardy"
	("breed_body" health(200%) regen_health(100%) stamina(100%) regen_stamina(100%) vision("mp_soldier") speed(0.9))
)

; body_level_5_line: health 200%, stamina 150%, speed 0.9
(define "body_level_5_line"
	("breed_body" health(200%) regen_health(100%) stamina(150%) regen_stamina(100%) vision("mp_soldier") speed(0.9))
)

; body_level_5_hardy: health 300%, stamina 150%, speed 0.9
(define "body_level_5_hardy"
	("breed_body" health(300%) regen_health(100%) stamina(150%) regen_stamina(100%) vision("mp_soldier") speed(0.9))
)

; body_level_6_line: health 350%, stamina 200%, speed 0.9
(define "body_level_6_line"
	("breed_body" health(350%) regen_health(100%) stamina(200%) regen_stamina(100%) vision("mp_soldier") speed(0.9))
)

; body_level_6_hardy: health 400%, stamina 200%, speed 0.9
(define "body_level_6_hardy"
	("breed_body" health(400%) regen_health(100%) stamina(200%) regen_stamina(100%) vision("mp_soldier") speed(0.9))
)

; body_level_7_line: health 400%, stamina 200%, speed 0.9
(define "body_level_7_line"
	("breed_body" health(400%) regen_health(100%) stamina(200%) regen_stamina(100%) vision("mp_soldier") speed(0.9))
)

; body_level_7_hardy: health 450%, stamina 200%, speed 0.9
(define "body_level_7_hardy"
	("breed_body" health(450%) regen_health(100%) stamina(200%) regen_stamina(100%) vision("mp_soldier") speed(0.9))
)

; drive_level_1: infantry crew skills of level 1
(define "drive_level_1"
	("breed_drive" tank(0.75) vehicle(1) cannon(0.8))
)

; drive_level_2: infantry crew skills of level 2
(define "drive_level_2"
	("breed_drive" tank(0.75) vehicle(1) cannon(0.8))
)

; drive_level_3: infantry crew skills of level 3
(define "drive_level_3"
	("breed_drive" tank(0.75) vehicle(1) cannon(0.8))
)

; drive_level_4: infantry crew skills of level 4
(define "drive_level_4"
	("breed_drive" tank(0.75) vehicle(1) cannon(0.8))
)

; drive_level_5: infantry crew skills of level 5
(define "drive_level_5"
	("breed_drive" tank(0.85) vehicle(1) cannon(0.9))
)

; drive_level_6: infantry crew skills of level 6
(define "drive_level_6"
	("breed_drive" tank(0.95) vehicle(1) cannon(1))
)

; drive_level_7: infantry crew skills of level 7
(define "drive_level_7"
	("breed_drive" tank(0.95) vehicle(1) cannon(1))
)

; skills_rifle_1: weapon skills of a level 1 soldier whose main weapon is a rifle
;   rocket - rocketlauncher skill level number
;   e.g. ("skills_rifle_1" rocket(1))
(define "skills_rifle_1"
	("breed_skills" pistol(1) smg(1) mgun(1) rifle(1) rocket(%rocket) melee(2))
)

; skills_rifle_2: weapon skills of a level 2 soldier whose main weapon is a rifle
;   rocket - rocketlauncher skill level number
;   e.g. ("skills_rifle_2" rocket(1))
(define "skills_rifle_2"
	("breed_skills" pistol(1) smg(1) mgun(1) rifle(2) rocket(%rocket) melee(2))
)

; skills_rifle_3: weapon skills of a level 3 soldier whose main weapon is a rifle
;   rocket - rocketlauncher skill level number
;   e.g. ("skills_rifle_3" rocket(1))
(define "skills_rifle_3"
	("breed_skills" pistol(2) smg(2) mgun(2) rifle(3) rocket(%rocket) melee(3))
)

; skills_rifle_4: weapon skills of a level 4 soldier whose main weapon is a rifle
;   rocket - rocketlauncher skill level number
;   e.g. ("skills_rifle_4" rocket(1))
(define "skills_rifle_4"
	("breed_skills" pistol(4) smg(3) mgun(2) rifle(4) rocket(%rocket) melee(4))
)

; skills_rifle_5: weapon skills of a level 5 soldier whose main weapon is a rifle
;   rocket - rocketlauncher skill level number
;   e.g. ("skills_rifle_5" rocket(1))
(define "skills_rifle_5"
	("breed_skills" pistol(4) smg(3) mgun(3) rifle(5) rocket(%rocket) melee(4))
)

; skills_rifle_6: weapon skills of a level 6 soldier whose main weapon is a rifle
;   rocket - rocketlauncher skill level number
;   e.g. ("skills_rifle_6" rocket(1))
(define "skills_rifle_6"
	("breed_skills" pistol(5) smg(5) mgun(5) rifle(6) rocket(%rocket) melee(5))
)

; skills_rifle_7: weapon skills of a level 7 soldier whose main weapon is a rifle
;   rocket - rocketlauncher skill level number
;   e.g. ("skills_rifle_7" rocket(1))
(define "skills_rifle_7"
	("breed_skills" pistol(6) smg(6) mgun(6) rifle(7) rocket(%rocket) melee(6))
)

; skills_smg_1: weapon skills of a level 1 soldier whose main weapon is a smg
;   rocket - rocketlauncher skill level number
;   e.g. ("skills_smg_1" rocket(1))
(define "skills_smg_1"
	("breed_skills" pistol(1) smg(1) mgun(1) rifle(1) rocket(%rocket) melee(2))
)

; skills_smg_2: weapon skills of a level 2 soldier whose main weapon is a smg
;   rocket - rocketlauncher skill level number
;   e.g. ("skills_smg_2" rocket(1))
(define "skills_smg_2"
	("breed_skills" pistol(2) smg(2) mgun(1) rifle(1) rocket(%rocket) melee(2))
)

; skills_smg_3: weapon skills of a level 3 soldier whose main weapon is a smg
;   rocket - rocketlauncher skill level number
;   e.g. ("skills_smg_3" rocket(1))
(define "skills_smg_3"
	("breed_skills" pistol(2) smg(3) mgun(2) rifle(2) rocket(%rocket) melee(3))
)

; skills_smg_4: weapon skills of a level 4 soldier whose main weapon is a smg
;   rocket - rocketlauncher skill level number
;   e.g. ("skills_smg_4" rocket(1))
(define "skills_smg_4"
	("breed_skills" pistol(4) smg(4) mgun(2) rifle(3) rocket(%rocket) melee(4))
)

; skills_smg_5: weapon skills of a level 5 soldier whose main weapon is a smg
;   rocket - rocketlauncher skill level number
;   e.g. ("skills_smg_5" rocket(1))
(define "skills_smg_5"
	("breed_skills" pistol(4) smg(5) mgun(3) rifle(3) rocket(%rocket) melee(4))
)

; skills_smg_6: weapon skills of a level 6 soldier whose main weapon is a smg
;   rocket - rocketlauncher skill level number
;   e.g. ("skills_smg_6" rocket(1))
(define "skills_smg_6"
	("breed_skills" pistol(5) smg(6) mgun(5) rifle(5) rocket(%rocket) melee(5))
)

; skills_smg_7: weapon skills of a level 7 soldier whose main weapon is a smg
;   rocket - rocketlauncher skill level number
;   e.g. ("skills_smg_7" rocket(1))
(define "skills_smg_7"
	("breed_skills" pistol(6) smg(7) mgun(6) rifle(6) rocket(%rocket) melee(6))
)

; skills_mgun_1: weapon skills of a level 1 soldier whose main weapon is a mgun
;   rocket - rocketlauncher skill level number
;   e.g. ("skills_mgun_1" rocket(1))
(define "skills_mgun_1"
	("breed_skills" pistol(1) smg(1) mgun(1) rifle(1) rocket(%rocket) melee(2))
)

; skills_mgun_2: weapon skills of a level 2 soldier whose main weapon is a mgun
;   rocket - rocketlauncher skill level number
;   e.g. ("skills_mgun_2" rocket(1))
(define "skills_mgun_2"
	("breed_skills" pistol(2) smg(1) mgun(2) rifle(1) rocket(%rocket) melee(2))
)

; skills_mgun_3: weapon skills of a level 3 soldier whose main weapon is a mgun
;   rocket - rocketlauncher skill level number
;   e.g. ("skills_mgun_3" rocket(1))
(define "skills_mgun_3"
	("breed_skills" pistol(2) smg(2) mgun(3) rifle(2) rocket(%rocket) melee(3))
)

; skills_mgun_4: weapon skills of a level 4 soldier whose main weapon is a mgun
;   rocket - rocketlauncher skill level number
;   e.g. ("skills_mgun_4" rocket(1))
(define "skills_mgun_4"
	("breed_skills" pistol(4) smg(3) mgun(4) rifle(3) rocket(%rocket) melee(4))
)

; skills_mgun_5: weapon skills of a level 5 soldier whose main weapon is a mgun
;   rocket - rocketlauncher skill level number
;   e.g. ("skills_mgun_5" rocket(1))
(define "skills_mgun_5"
	("breed_skills" pistol(4) smg(3) mgun(5) rifle(3) rocket(%rocket) melee(4))
)

; skills_mgun_6: weapon skills of a level 6 soldier whose main weapon is a mgun
;   rocket - rocketlauncher skill level number
;   e.g. ("skills_mgun_6" rocket(1))
(define "skills_mgun_6"
	("breed_skills" pistol(5) smg(5) mgun(6) rifle(5) rocket(%rocket) melee(5))
)

; skills_mgun_7: weapon skills of a level 7 soldier whose main weapon is a mgun
;   rocket - rocketlauncher skill level number
;   e.g. ("skills_mgun_7" rocket(1))
(define "skills_mgun_7"
	("breed_skills" pistol(6) smg(6) mgun(7) rifle(6) rocket(%rocket) melee(6))
)

; skills_pistol_1: weapon skills of a level 1 soldier whose main weapon is a pistol
;   rocket - rocketlauncher skill level number
;   e.g. ("skills_pistol_1" rocket(1))
(define "skills_pistol_1"
	("breed_skills" pistol(1) smg(1) mgun(1) rifle(1) rocket(%rocket) melee(2))
)

; skills_pistol_2: weapon skills of a level 2 soldier whose main weapon is a pistol
;   rocket - rocketlauncher skill level number
;   e.g. ("skills_pistol_2" rocket(1))
(define "skills_pistol_2"
	("breed_skills" pistol(2) smg(2) mgun(2) rifle(2) rocket(%rocket) melee(2))
)

; skills_pistol_3: weapon skills of a level 3 soldier whose main weapon is a pistol
;   rocket - rocketlauncher skill level number
;   e.g. ("skills_pistol_3" rocket(1))
(define "skills_pistol_3"
	("breed_skills" pistol(3) smg(3) mgun(3) rifle(3) rocket(%rocket) melee(3))
)

; skills_pistol_4: weapon skills of a level 4 soldier whose main weapon is a pistol
;   rocket - rocketlauncher skill level number
;   e.g. ("skills_pistol_4" rocket(1))
(define "skills_pistol_4"
	("breed_skills" pistol(4) smg(4) mgun(4) rifle(4) rocket(%rocket) melee(4))
)

; skills_pistol_5: weapon skills of a level 5 soldier whose main weapon is a pistol
;   rocket - rocketlauncher skill level number
;   e.g. ("skills_pistol_5" rocket(1))
(define "skills_pistol_5"
	("breed_skills" pistol(5) smg(5) mgun(5) rifle(5) rocket(%rocket) melee(5))
)

; skills_pistol_6: weapon skills of a level 6 soldier whose main weapon is a pistol
;   rocket - rocketlauncher skill level number
;   e.g. ("skills_pistol_6" rocket(1))
(define "skills_pistol_6"
	("breed_skills" pistol(6) smg(5) mgun(5) rifle(5) rocket(%rocket) melee(5))
)

; skills_pistol_7: weapon skills of a level 7 soldier whose main weapon is a pistol
;   rocket - rocketlauncher skill level number
;   e.g. ("skills_pistol_7" rocket(1))
(define "skills_pistol_7"
	("breed_skills" pistol(7) smg(6) mgun(6) rifle(6) rocket(%rocket) melee(6))
)

; soldier_rifle_1: level 1 soldier, main weapon rifle
;   rocket - rocketlauncher skill level number
;   body - line or hardy (health row)
;   e.g. ("soldier_rifle_1" rocket(1) body(line))
(define "soldier_rifle_1"
	("body_level_1_%body")
	("drive_level_1")
	("skills_rifle_1" rocket(%rocket))
)

; soldier_rifle_2: level 2 soldier, main weapon rifle
;   rocket - rocketlauncher skill level number
;   body - line or hardy (health row)
;   e.g. ("soldier_rifle_2" rocket(1) body(line))
(define "soldier_rifle_2"
	("body_level_2_%body")
	("drive_level_2")
	("skills_rifle_2" rocket(%rocket))
)

; soldier_rifle_3: level 3 soldier, main weapon rifle
;   rocket - rocketlauncher skill level number
;   body - line or hardy (health row)
;   e.g. ("soldier_rifle_3" rocket(1) body(line))
(define "soldier_rifle_3"
	("body_level_3_%body")
	("drive_level_3")
	("skills_rifle_3" rocket(%rocket))
)

; soldier_rifle_4: level 4 soldier, main weapon rifle
;   rocket - rocketlauncher skill level number
;   body - line or hardy (health row)
;   e.g. ("soldier_rifle_4" rocket(1) body(line))
(define "soldier_rifle_4"
	("body_level_4_%body")
	("drive_level_4")
	("skills_rifle_4" rocket(%rocket))
)

; soldier_rifle_5: level 5 soldier, main weapon rifle
;   rocket - rocketlauncher skill level number
;   body - line or hardy (health row)
;   e.g. ("soldier_rifle_5" rocket(1) body(line))
(define "soldier_rifle_5"
	("body_level_5_%body")
	("drive_level_5")
	("skills_rifle_5" rocket(%rocket))
)

; soldier_rifle_6: level 6 soldier, main weapon rifle
;   rocket - rocketlauncher skill level number
;   body - line or hardy (health row)
;   e.g. ("soldier_rifle_6" rocket(1) body(line))
(define "soldier_rifle_6"
	("body_level_6_%body")
	("drive_level_6")
	("skills_rifle_6" rocket(%rocket))
)

; soldier_rifle_7: level 7 soldier, main weapon rifle
;   rocket - rocketlauncher skill level number
;   body - line or hardy (health row)
;   e.g. ("soldier_rifle_7" rocket(1) body(line))
(define "soldier_rifle_7"
	("body_level_7_%body")
	("drive_level_7")
	("skills_rifle_7" rocket(%rocket))
)

; soldier_smg_1: level 1 soldier, main weapon smg
;   rocket - rocketlauncher skill level number
;   body - line or hardy (health row)
;   e.g. ("soldier_smg_1" rocket(1) body(line))
(define "soldier_smg_1"
	("body_level_1_%body")
	("drive_level_1")
	("skills_smg_1" rocket(%rocket))
)

; soldier_smg_2: level 2 soldier, main weapon smg
;   rocket - rocketlauncher skill level number
;   body - line or hardy (health row)
;   e.g. ("soldier_smg_2" rocket(1) body(line))
(define "soldier_smg_2"
	("body_level_2_%body")
	("drive_level_2")
	("skills_smg_2" rocket(%rocket))
)

; soldier_smg_3: level 3 soldier, main weapon smg
;   rocket - rocketlauncher skill level number
;   body - line or hardy (health row)
;   e.g. ("soldier_smg_3" rocket(1) body(line))
(define "soldier_smg_3"
	("body_level_3_%body")
	("drive_level_3")
	("skills_smg_3" rocket(%rocket))
)

; soldier_smg_4: level 4 soldier, main weapon smg
;   rocket - rocketlauncher skill level number
;   body - line or hardy (health row)
;   e.g. ("soldier_smg_4" rocket(1) body(line))
(define "soldier_smg_4"
	("body_level_4_%body")
	("drive_level_4")
	("skills_smg_4" rocket(%rocket))
)

; soldier_smg_5: level 5 soldier, main weapon smg
;   rocket - rocketlauncher skill level number
;   body - line or hardy (health row)
;   e.g. ("soldier_smg_5" rocket(1) body(line))
(define "soldier_smg_5"
	("body_level_5_%body")
	("drive_level_5")
	("skills_smg_5" rocket(%rocket))
)

; soldier_smg_6: level 6 soldier, main weapon smg
;   rocket - rocketlauncher skill level number
;   body - line or hardy (health row)
;   e.g. ("soldier_smg_6" rocket(1) body(line))
(define "soldier_smg_6"
	("body_level_6_%body")
	("drive_level_6")
	("skills_smg_6" rocket(%rocket))
)

; soldier_smg_7: level 7 soldier, main weapon smg
;   rocket - rocketlauncher skill level number
;   body - line or hardy (health row)
;   e.g. ("soldier_smg_7" rocket(1) body(line))
(define "soldier_smg_7"
	("body_level_7_%body")
	("drive_level_7")
	("skills_smg_7" rocket(%rocket))
)

; soldier_mgun_1: level 1 soldier, main weapon mgun
;   rocket - rocketlauncher skill level number
;   body - line or hardy (health row)
;   e.g. ("soldier_mgun_1" rocket(1) body(line))
(define "soldier_mgun_1"
	("body_level_1_%body")
	("drive_level_1")
	("skills_mgun_1" rocket(%rocket))
)

; soldier_mgun_2: level 2 soldier, main weapon mgun
;   rocket - rocketlauncher skill level number
;   body - line or hardy (health row)
;   e.g. ("soldier_mgun_2" rocket(1) body(line))
(define "soldier_mgun_2"
	("body_level_2_%body")
	("drive_level_2")
	("skills_mgun_2" rocket(%rocket))
)

; soldier_mgun_3: level 3 soldier, main weapon mgun
;   rocket - rocketlauncher skill level number
;   body - line or hardy (health row)
;   e.g. ("soldier_mgun_3" rocket(1) body(line))
(define "soldier_mgun_3"
	("body_level_3_%body")
	("drive_level_3")
	("skills_mgun_3" rocket(%rocket))
)

; soldier_mgun_4: level 4 soldier, main weapon mgun
;   rocket - rocketlauncher skill level number
;   body - line or hardy (health row)
;   e.g. ("soldier_mgun_4" rocket(1) body(line))
(define "soldier_mgun_4"
	("body_level_4_%body")
	("drive_level_4")
	("skills_mgun_4" rocket(%rocket))
)

; soldier_mgun_5: level 5 soldier, main weapon mgun
;   rocket - rocketlauncher skill level number
;   body - line or hardy (health row)
;   e.g. ("soldier_mgun_5" rocket(1) body(line))
(define "soldier_mgun_5"
	("body_level_5_%body")
	("drive_level_5")
	("skills_mgun_5" rocket(%rocket))
)

; soldier_mgun_6: level 6 soldier, main weapon mgun
;   rocket - rocketlauncher skill level number
;   body - line or hardy (health row)
;   e.g. ("soldier_mgun_6" rocket(1) body(line))
(define "soldier_mgun_6"
	("body_level_6_%body")
	("drive_level_6")
	("skills_mgun_6" rocket(%rocket))
)

; soldier_mgun_7: level 7 soldier, main weapon mgun
;   rocket - rocketlauncher skill level number
;   body - line or hardy (health row)
;   e.g. ("soldier_mgun_7" rocket(1) body(line))
(define "soldier_mgun_7"
	("body_level_7_%body")
	("drive_level_7")
	("skills_mgun_7" rocket(%rocket))
)

; soldier_pistol_1: level 1 soldier, main weapon pistol
;   rocket - rocketlauncher skill level number
;   body - line or hardy (health row)
;   e.g. ("soldier_pistol_1" rocket(1) body(line))
(define "soldier_pistol_1"
	("body_level_1_%body")
	("drive_level_1")
	("skills_pistol_1" rocket(%rocket))
)

; soldier_pistol_2: level 2 soldier, main weapon pistol
;   rocket - rocketlauncher skill level number
;   body - line or hardy (health row)
;   e.g. ("soldier_pistol_2" rocket(1) body(line))
(define "soldier_pistol_2"
	("body_level_2_%body")
	("drive_level_2")
	("skills_pistol_2" rocket(%rocket))
)

; soldier_pistol_3: level 3 soldier, main weapon pistol
;   rocket - rocketlauncher skill level number
;   body - line or hardy (health row)
;   e.g. ("soldier_pistol_3" rocket(1) body(line))
(define "soldier_pistol_3"
	("body_level_3_%body")
	("drive_level_3")
	("skills_pistol_3" rocket(%rocket))
)

; soldier_pistol_4: level 4 soldier, main weapon pistol
;   rocket - rocketlauncher skill level number
;   body - line or hardy (health row)
;   e.g. ("soldier_pistol_4" rocket(1) body(line))
(define "soldier_pistol_4"
	("body_level_4_%body")
	("drive_level_4")
	("skills_pistol_4" rocket(%rocket))
)

; soldier_pistol_5: level 5 soldier, main weapon pistol
;   rocket - rocketlauncher skill level number
;   body - line or hardy (health row)
;   e.g. ("soldier_pistol_5" rocket(1) body(line))
(define "soldier_pistol_5"
	("body_level_5_%body")
	("drive_level_5")
	("skills_pistol_5" rocket(%rocket))
)

; soldier_pistol_6: level 6 soldier, main weapon pistol
;   rocket - rocketlauncher skill level number
;   body - line or hardy (health row)
;   e.g. ("soldier_pistol_6" rocket(1) body(line))
(define "soldier_pistol_6"
	("body_level_6_%body")
	("drive_level_6")
	("skills_pistol_6" rocket(%rocket))
)

; soldier_pistol_7: level 7 soldier, main weapon pistol
;   rocket - rocketlauncher skill level number
;   body - line or hardy (health row)
;   e.g. ("soldier_pistol_7" rocket(1) body(line))
(define "soldier_pistol_7"
	("body_level_7_%body")
	("drive_level_7")
	("skills_pistol_7" rocket(%rocket))
)
