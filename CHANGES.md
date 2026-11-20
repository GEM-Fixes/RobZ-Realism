Last updated: 2026-11-19

This file is a short summary of all work on RobZ Realism 1.31.0 since the import of the original mod; it is kept up to date with every change to the mod.

# RobZ Realism 1.31.0: changes

Baseline: the imported mod (git "Start (part N/28)"). Covered: 2026-11-16 to 2026-11-19, up to commit 2566d233a, plus the not yet committed work of 2026-11-19 evening (small shovel for every breed, 60 mm call-in price).
Every balance and gameplay value is listed in BALANCE.md. Nothing has been tested in the game yet.

## Veteran and elite vehicles and cannons (2026-11-19)
- 16 veteran and elite tanks and cannons now follow the owner's rules: faster reload, start and turn, better gears, turret speeds.
- 13 gun files changed and 3 new vet / elite guns were added.
- Elite cannons have their own, harder-to-see vision terms and turn macros.

## Sniper rifles (2026-11-19)
- mosin_s bolt cycle 2.8 s -> 1.4 s.
- m1903a4_vet is now built on the real Springfield instead of a generic pattern (it had the Mosin model and no sound).

## Price model, small shovels and the 60 mm call-in (2026-11-19)
- A price model file and price comment lines were added for the price calculator. The game does not read the model file.
- Owner rules in the model: throwable CP a fifth of before, small shovel free, Panzerfaust charged by the chance of carrying it, Panzerfaust 100 in the high tier, fg42_sc an auto rifle, m3_carbine a special carbine. The 60 mm call-in keeps CP 5 (the earlier change to 2 is withdrawn).
- Every priced breed now carries exactly one small shovel: 800 breeds got one, and two Sturmgrenadier breeds that listed it twice now carry one. The shovel is free, so no price changed.
- One real price change: the 60 mm mortar call-in radioman (usa_devil_brigade_radio) now costs 20 MP instead of 75, as on the owner's sheet.
- Hero (SP) cards no longer get a computed MP comment line.

## Soldier breeds (2026-11-18 / 2026-11-19)
- All MP breeds (about 1200) were remapped to the owner's rules: skills, health and stamina by role and level, crew ladders, charge troops, leaders and assistants.
- 1159 breeds changed values. A second pass levelled squads, moved tank gun skill to crews, set stamina regeneration and split the Kaukopartio flamer.
- Kit bugs were fixed: wrong pistol ammo, wrong rifle on a Japanese MG assistant, odd ammo counts.
- Grenade items now use one naming form ("grenade X").

## Bug fixes in cards, vehicles and props (2026-11-17 / 2026-11-18)
- Squad cards: broken members removed, wrong breed names fixed, Japanese 1944-45 rifle squads use the Type 99 MG team.
- Price rows: two breeds that had no price got one; bogus rows removed.
- Vehicles: Fiat 35 trucks and crate8 supply boxes now resupply; wrong MG ammo and grenade names in some vehicle boxes fixed; Nimrod driver boarding fixed.
- 23 jungle and palm trees got their missing include back.
- Game presets: the super_persh unit limit now uses the right separator.
- SDK auto fixes changed the ricochet tables of ground, ice and water and the environment of three maps.

## Cleanup and file structure (2026-11-17 to 2026-11-19, no value change)
- Text files were reformatted and repeated blocks moved into shared macros (breeds, kits, guns, volumes, squad cards).
- Vet and elite guns now inherit from their base gun with `{from}`.
- Squad cards got unique names with the side in brackets; the bot scripts follow the new names.
- Each step was checked against a full macro expansion: no value changed.

## Localization (2026-11-16 to 2026-11-18)
- README added. Localization files split into smaller files and many texts fixed.
- Some card titles fixed, for example "Guards Bazooka team".

## Open
- Nothing is verified in the game yet.
- Some effects are not determined (ricochet tables, map look, unit limit, two old prices, bolt tags). See BALANCE.md, "Not determined".
- One paratrooper breed (usa_elite_101st_para4) has a full kit, so its new shovel may be dropped in the game; this needs a test.
- The 60 mm call-in radioman still has CP 2 in the game, while the model says 5.
