# RobZ Realism 1.31.0: macrostd owner cases

Mod: `E:\RobZ Realism\robz realism mod 1.31.0`. Tool: `tools/macrostd`. Undo copies: `<mod>/.arsenal-undo/`.
Every step applied so far left the expanded data identical (verify PASS, all roots SAME).
None of the cases below has been applied. Each one needs a yes or no from you.

## Applied (2026-11-18)
- Defect fixes (`fixes-20261118/`): fiat35 includes, the vanilla `para_ammo` / `truck_ammo` / `truck_ammo_art` defines,
  7 `b(hero)))` cards, 23 jungle trees, the guzzi shadow include, `human_full_test.inc`, the `150mm_stuh43` and `37mm_l40` guns.
- fmt (3,085 files), indent (1,782), dead (29 macros in 7 files), names (19 renames in 2 files).
- share (305 files: 136 other bodies renamed by what they add, e.g. `crew_human_visor`; 35 names moved to
  `properties/robz/{crew,armor,weapon,interaction,vehicle,volumes}.inc` and `set/breed/mp/robz_vet.inc`),
  params (38 parameters in 25 defines), buylist (2,335 cards to one-line `unit_*` / `squad_*` calls, macros in
  `set/multiplayer/units/_macros.inc`), breed (1,190 files, `set/breed/breed_macros.inc`), guns (171 files),
  samedef (399 defs share a `_body.inc`), volumes (3,006 literal volumes to `vol_*` calls), header (861 define headers),
  index (`MACROS.md` at the mod root). Each verified PASS on the live mod.
- Undo one step: `node tools/macrostd/macrostd.js undo "<mod>" --step <step>` (latest step first).

## Breed round 2 (2026-11-18): equipment, perk tiers, veterancy. Applied, verify PASS after each
- vet: tables renamed (`vet_standard` 713 breeds, `vet_elite` 188, `vet_crew` 117, `vet_start5` 65, `vet_standard_start3` 33,
  `vet_standard_start2` 26, `vet_elite_start2` 18, `vet_ss_start3` 18, `vet_ss_start1` 7, `vet_crew_start3` 2); breeds read
  `("breed_vet" table(elite))`; `veterancy_1` kept as an alias for 141 vanilla breeds; the explanation is the header of
  `set/breed/mp/robz_vet.inc`.
- kit (`set/breed/breed_kit.inc`): weapon + ammo as class-led macros across factions (`rifle_mauzer`, `smg_mp40`; a second load
  used 4+ times `smg_mp40_96`; rarer loads `("kit_rifle" gun() ammo() rounds())`), grenades by kind (`frag_`, `at_grenade_`,
  `smoke_`, `fire_`, `mine_`, `explosive_`). 67 weapon, 6 generic, 70 grenade macros.
- tiers (`set/breed/breed_tiers.inc`): 34 body, 23 drive, 85 skills tiers at 4+ uses across factions. Names live in the `NAMES`
  map at the top of `tools/macrostd/steps/tiers.js`; change a line and re-run the step to rename a tier.
- Not run in the game after this round [T].

### Out of line with the macros: `plan/reports/robz-breed-outline.tsv` (629 rows: file, line, what, nearest, difference)
- Equipment 279: rifle 82, smg 71, pistol 26, mine 21, frag 18, mgun 17, at 17, AT grenade 12, fire 5, smoke 4, mortar 4,
  explosive 2. Mostly a load used under 4 times (count differs from the standard) or a weapon with no standard.
- Perk sets 329: body 13 by value, 4 by text only, 1 far; drive 18 by value; skills 160 by one value, 94 by two, 39 far.
- Veterancy 21: numbers that break their base table, `(mod "mp")` numbers that differ, breeds on a table that does not fit
  their name [I], 2 literal blocks.

### Cases from this round
23. 21 weapons are followed by ammo they cannot load (luger / valter + `ammo 9x19`, flare guns + SMG magazines). Q: fix?
24. `type97rifle` has no stuff file in the mod or vanilla (the game log warns `No Stuff found for tags 'type97rifle'`). Q: which
    weapon is meant?
25. 128 filled weapons have no ammo line (mostly panzerfausts, balloons; also 8 panzershreck, 5 m3a, 4 mp40). Q: add ammo to the last three?
26. 18 tier twins hold the same numbers written differently (quoted vs bare vision, `1` vs `1.0`), e.g. `body_regular` /
    `body_regular_bare`. Q: make the text the same so each pair becomes one tier (no change in game, text changes)?
27. 98 tiers have a value name, no rank word (e.g. `skills_4_4_2_3_2_4`); "veteran" (200/150) and `tankman2` = commander are
    guesses from file names. Q: give names?
28. Start-rank tables off their base: `vet_standard_start2` 120/192 (expected 108/180), `vet_standard_start3` 72/144 (60/132),
    `vet_crew_start3` 96/204 (300/600; these are elite minus 216), `vet_ss_start1`, `vet_ss_start3`. Q: correct them?
29. 34 breeds with elite / veteran crew names use `vet_standard` (jap 12, usa 11, rus 7, ger_ss 2, axis_minor 2) [I]. Q: intended?
30. `eng_rifleman_smoke.set` and `ss_at_miner.set` carry literal veterancy 2/5/9/14/20 (vanilla-like). Q: move to a table?
31. `vet_standard_old` is unused (4 sides); 6 used tables have no `(mod "mp")` set. Q: remove the first, leave the second?

## In-game boot (2026-11-18) [V for the load only]
- `mowas_2_ed.exe -game multi/1v1_gazala:combat`, base = the owner's `mods/robz realism mod 1.31.0` (+ `_fixed`), test = a copy of
  the changed mod in `mods/robz_macrostd_test`. Both reach the mission (control panel lines), no Exception block.
- bootcheck: 0 new error lines, 0 new warning lines against the base. The same warnings appear at new line numbers
  (`/set/breed/mp/jap/mgun3_ammo.set` 47 → 18), which shows the changed files were the ones read.
- Not covered [T]: the release `mowas_2.exe`, the multiplayer lobby and buy menus (the buy-list cards), buying and using a unit.
- The editor build rewrote `options.set` on exit (dropped `ui_scale_*` and the chat wheel block); restored from a backup.
- Logs: `E:\arsenal-tmp\robz-macrostd\boot\`.

## Cases

### Indent
1. `set/interaction_entity/tank/general_scripts_defines.inc:819` has unbalanced brackets, so it was not re-indented.
   Q: should the bracket be fixed by hand, or the file left as it is?

### Breeds
2. `mp/usa/usa_nightfighter_carbine.set`: stealth and telescope sit inside the speed block, unlike every other breed.
   Q: move them out (a value change), or leave them?
3. Breeds with literal lines the breed macros do not cover were left as they are. Q: list them in full?

### Guns
4. The `speed` parameter keeps its name in macros that vanilla files call (PORT-55). Q: OK to keep it?

### Identical defs
5. 13 groups of identical defs span more than one folder, so no shared `_body.inc` was written for them.
   Q: put the shared body in one of the folders (a cross-folder include), or leave them?

### Buy lists
6. 27 `vs_rus_g` and 26 `v_rus_g` cards have no `v1`, so they hold a literal `%v1`. All are in
   `rus_guard/vehicles_43.set`, which nothing loads. Q: fix, delete the file's cards, or leave?
7. 31 `i_seq_with3types` hero_banzai cards pass only `c1`, so `%c2` turns into `<charge>2`. Q: add the missing values?
8. 11 `squad_with4..7types(_vehicle)` cards miss their last member. Q: same.
9. 4 `vs_seq` / `vs2_seq` cards have no `cw`, so the card reads `{cw 10w}`. Q: same.
10. 3 `v1` cards have no `n2`, one `i2` card is incomplete, and `v229` has `%9`. Q: same.
11. `i5` `hero_otsu-gata_koho` passes `n2` twice with different values. Q: which value is meant?
12. 77 old card macros are no longer called. Most live in `vehicles.set` and `squads.set`, which overwrite vanilla paths,
    so they were kept. Q: remove the ones no vanilla file calls?

### One body per name (share, params)
18. 12 names keep several bodies because live vanilla files call them: crew_human, crew_2_human, crew_inside,
    armor_light/medium/heavy, locomotion, abm_mgun, abm_zenite, abm_howitzer, burst_long, cut_piece.
    Q: give the mod's own bodies distinct names anyway (the mod files only)?
19. `restore_ik_time`: sharing it would give `marder_3h.def` a second body (RestoreIKTime 4 → 10). Q: which value is right?
20. 31 renamed bodies are never called. Q: comment them out (step dead)?
21. 8 parameters (armor_medium_advanced, delay_tag, wavemode_41..45) are passed short where the macro wants the long
    name, so the value is glued onto the name today. Q: fix the calls (a value change)?
22. Comments inside the removed copies are gone; the shared copy keeps the first copy's comments
    (e.g. the km/h and deg/s notes of `car.ext` accuracy_by_motion). They are in the undo folder. Q: restore any?

### From the plan
13. Two armor sources in 345 vehicles (`armor_*` settings and per-volume thickness). Q: keep which one?
14. Near-duplicate bodies (crew 15, `armor_light` 8, `locomotion` 6, `cut_part` 6). Q: merge under one name with parameters?
15. Veteran guns (`*_vet`) repeat the full table. Q: write them as base plus the change?
16. Named constants as no-argument macros (use inside a value is untested). Q: try it?
17. 9 `veterancy_generic.inc.bak` and 65 `*_old` / `*_test` files. Q: delete them (not done by the tool)?
