# RobZ Realism 1.31.0: veteran guns as "base gun + what changes"

Mod: `E:\RobZ Realism\robz realism mod 1.31.0`, files under `resource/set/stuff/**` only. Date 2026-11-19. Nothing committed.
Undo copies (one per changed file, same relative path): `<mod>/.arsenal-undo/vetguns-20261119/`.
Scripts: `E:\arsenal-tmp\vetguns\` (`convert.js` dry run / `--apply`, `verify.js` before/after check, `sim.js` resolver, `rules.js` survey).

## What a veteran gun changes

64 veteran guns (`*_vet`, `*_veteran`, `*_vet.weapon`). Compared with the base gun's effective values (resolved, see below) [V by resolver, T in game]:

| family | veteran change |
|---|---|
| tank and AT guns, direct fire (45 to 128 mm) | reload (`rechargeTime`) x0.85 (some x0.80: pak40, 50mm pak38, zis2, zis3, 52k, flak36, pak44; m42 x0.80; kwk42/mk4/m3_m36 8 s from 9.5); range +10 m (pak44, d10c, a19s, d25, kwk43, pak43 keep 250/260); a vet accuracy macro (`accuracy_*_vet`, `*_210m` etc.); the `damage_170`/`damage_215` tables re-written to the new max range |
| howitzers, indirect (`_art` pattern: m2a1, longtom, m114, m12, m115) | reload and recovery x0.60 to x0.80 (m2a1 x0.80, longtom/m114/m12 x0.69, m115 x0.60); a `range_*_us_vet` macro: better zeroing and spread power; longtom +30 m range |
| howitzers, direct fire `_2` variants (m2a1_2, longtom_2, m114_2, m12_2, m115_2) | reload x0.60 only |
| artillery `_2` (zis3_2, flak36_2, m3_m36_2, ml20a_2, oqfmk2) | reload and recovery x0.80 / x0.85 / x0.84 / x0.85 / x0.60 |
| mortars and rocket launchers (12cm sgrw42, 8cm sgrw34, bm37, pm38) | reload x0.60 only |
| MG on optic mount (mg42_mount_optic) | reload x0.75, `mg_zeroing_vet` |
| bolt rifles (em3, mauzer, mosin) | bolt cycle (`recoveryTime`) x0.75, faster bolt animation tag |
| sniper rifles (em2, mauzer_s, mosin_s, svt40_s, m1903a4) | recovery x0.75 (mosin_s 2.80 -> 1.05 s), range 140 -> 150 m, shorter aim `PrepareTime` |

Rule in one line: veteran = faster reload (x0.85 tank/AT, x0.60 to x0.80 artillery and mortars, x0.75 bolt), and for direct-fire guns +10 m range with a better accuracy curve. Not one fixed factor: x0.80, x0.84, x0.85 and x0.60 all occur.

## How it is expressed

`{from "<base>"}` plus only the lines that change the result. The engine reads a `{from}` stuff as a copy of the base, then reads the child's lines on top (`game/entity/eStuffs.cpp` ReadStuff, `eStuff*::CopyFrom`) [V code, limits SDL-49]. The mod already used this for 30 of the 64 vets and for about 1000 other stuff files.

Merge rules that decided which lines can go (from the engine source, `eStuffWeapon.cpp`, `eStuffWeaponBullet.cpp`, `eModifier.cpp`) [I: reconstructed source, not run]:
- a `{parameters "x"}` block of the child edits the base's block of the same ammo (it is not replaced); only the keys written change.
- a top-level `range`, `rechargeTime`, `curve`, `spreading`, damage key etc. also overwrites that key in every existing `{parameters}` block when the value changes. So order matters, and some lines must be repeated after the base.
- the folder's `.presets` runs again for every file, also a `{from}` file: `gun/.presets` starts with `{curve "gun_std"}`, which resets the curve of the base and all its ammo blocks. That is why some vet files still repeat a line that equals the base (for example `("range_grazing_howitzer")` and the accuracy macro in `155mm_m12_2_vet`): without it the curve would fall back to `gun_std`.
- `{tag}` adds to the base's tags (does not replace); `{special}` merges per key; `desc` and `throw_off_always` are not copied by `{from}`.

Proof per gun: `sim.js` resolves a stuff file to its full effective set (macros expanded with the repo's `sdlx`, `.presets` included, `{from}` chain followed, the rules above, mods off and `mp` on). A line was dropped only when the result stayed identical, and identical under three readings of the "top-level key reaches the ammo blocks" rule (group copy as in the source, per field, only blocks still holding the old default), so the result does not depend on that detail. Unmodelled keys are kept as an ordered list, so they can never be dropped silently.

## Result

| status | count | guns |
|---|---|---|
| converted | 43 | gun: 100mm_d10c, 105mm_m2a1, 105mm_m2a1_2, 122mm_a19s, 122mm_d25, 128mm_pak44, 149mm_obice, 152mm_ml20a, 155mm_longtom, 155mm_longtom_2, 155mm_m114, 155mm_m114_2, 155mm_m12, 155mm_m12_2, 203mm_m115, 203mm_m115_2, 45mm_20k, 50mm_pak38, 75mm_kwk40(l48), 75mm_kwk40, 75mm_pak39, 75mm_pak40, 75mm_stuk40, 75mm_stuk42, 76mm_m1a2, 85mm_zis53, 88mm_flak36, 88mm_flak36_2, 88mm_kwk36_veteran, 88mm_kwk43, 88mm_pak43, 90mm_m3, 90mm_m3_m36, 90mm_m3_m36_2; mgun/mg42_mount_optic; reactive/12cm_sgrw42, 8cm_sgrw34, bm37, pm38 (`.weapon`, were full `{weapon_bullet}` copies, now 2 lines); rifle/svt40_s, sniper/em2, mauzer_s, mosin_s |
| already minimal, untouched | 13 | 105mm_stuh42, 152mm_ml20a_2, 45mm_m42, 57mm_zis2, 75mm_kwk42_veteran, 76mm_f34, 76mm_mk4, 76mm_zis3, 76mm_zis3_2, 88mm_oqfmk2, em3, mauzer, mosin (already `{from "<base>"}`; for 45mm_m42, kwk42_veteran and zis3 only blank lines could go, so they were left as they are) |
| left unchanged | 8 | see below |

Note: a few converted files keep the same line count (`75mm_stuk42_vet`, `76mm_m1a2_vet`): only the `{from}` target moved from the grandparent (`75mm_kwk42`, `76mm_m5`) to the base gun, every line in them is a real difference.

Left unchanged, with reason:
- `75mm_41m_vet`: not a variant of `75mm_41m`; a different gun table (medium gun range, other speeds, `damage` a..e tables, `cu` ammo, no howitzer range). Base + vet lines is not identical.
- `75mm_43m_vet`: base + all vet lines differs in `wp`/`fg` gravity (1.5 vs 10): the base's later accuracy macro changes defaults that flow into the ammo blocks in another order. Would need extra non-obvious lines.
- `90mm_m90_53_vet`: built on `88mm_kwk43`, base `90mm_m90_53` on `pattern gun`; different speeds, damage, calibre, reload sound.
- `85mm_52k_vet`, `85mm_d5s_vet`, `85mm_d5t_vet`: already `{from "85mm_zis53_vet"}` + 1 line (vet of the parent family); d5s/d5t have no base file in the mod. Already compact.
- `76mm_zis5_vet`: base `76mm_zis5` exists only in the game (`{from "76mm_f34"}` with no lines), so the current `{from "76mm_f34"}` form already is base + diff; not tied to a vanilla file.
- `rifle/sniper/m1903a4_vet`: see findings: it is not the M1903A4.

## Checks

- `verify.js` (own resolver): all 1356 mod stuff files, before (undo copies) vs after, 3 rule readings x 2 mod states: same 8112, diff 0; 24 resolutions fail the same way on both sides (4 bombing `.ammo` files whose `{from "air_bomb"}` matches 3 file names in the resolver, untouched). Negative control (one vet value changed): 6 diffs reported.
- macrostd verify last line: `MACRO_UNDEFINED 151, IDENT_SPLIT 3, ARITH_BAD 2, UNREPLACED_PARAM 2, NUMBER_GLUED 2, PAREN_STRAY 1, TAG_SWALLOWS 1, INT_RANGE 1` (unchanged). The 43 changed files show as DIFF (24 at `from`, 7 `from/parameters`, 5 `from/range`, 3 `from/special/mode`, 4 `weapon_bullet`): the tool compares tokens and does not resolve `{from}`. No other stuff file shows DIFF; the rest of the 1236 DIFF is other work.
- No stuff file has a `{tag}` word equal to a new `{from}` target (SDL-64 shadowing); every target resolves to exactly one file name (SDL-57).
- Files CRLF, latin1, tabs, written in place.

## Findings (not changed: value-identical was required)

- `rifle/sniper/m1903a4_vet` is `{from "pattern sniper_rifle"}` without the M1903A4 lines: it has the pattern's `entity "mosin"`, `filling "ammo rifle"`, speed 150 instead of `m1903a4`, `ammo springfield_clip`, 855, and no fire sound. Likely a mod bug [I]; fix would be `{from "m1903a4"}` + the vet lines (changes values, needs the owner's word) [T].
- Rifle vets carry both bolt tags: base `bolt_r140` (or r100/r280) and vet `bolt_r105`/`r075`, because `{tag}` adds. Was so before this change. Which animation class wins with two tags is [T]; `{tag "-bolt_r140 bolt_r105"}` would make it clean.
- `149mm_obice_vet` is identical to `149mm_obice` (no veteran change at all), now `{from "149mm_obice"}` with no lines [V resolver].

## Not tested in the game [T]

Nothing was loaded in the game. That the converted vets load, show and fire the same in game is [T]; it rests on the engine read rules above, which are [V] in code for `{from}`/`.presets` (eStuffs.cpp) and [I] for the ammo-block propagation (checked under three readings). Quick in-game check: spawn a veteran tank (for example a Pz IV with `75mm_kwk40_vet`) and a howitzer (`155mm_m12_2_vet`), compare reload time, aim range and the ammo cursor with the previous build; game.log must show no `pattern not found`.
