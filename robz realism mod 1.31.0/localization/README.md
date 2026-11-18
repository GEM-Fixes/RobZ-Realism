# Localization layout

The big `.lng` files are split. Each `.lng` here is a thin parent: the `{tags` root, the group skeleton and
`(include "...")` lines. The texts are in `.inc` part files in the folder named after the parent.

```
desc.lng            -> desc/vanilla/...      desc/mod/...
info.lng            -> info/vanilla/...      info/mod/...
mission.lng         -> mission_multi/...     (mission/ holds the per-mission .lng files, loaded as they are)
#dlg_mp.lng         -> dlg_mp/...            same for #dlg_ingame, #dlg_frontend, #tips
_dropped/           keys that nothing in vanilla or the mod uses; no file includes them
```

- `vanilla/` parts: keys whose text is the same as the vanilla game. Do not edit them.
- `mod/` parts: keys the mod changed (first block) and keys the mod added (second block).
- A key the mod changed exists only in the mod part, so no key is defined twice.
- Inside each group the vanilla include comes before the mod include.

## Where a key goes
The file path mirrors the key path.

| key | file |
|---|---|
| `desc/human/mp/<side>/<breed>` | `desc/mod/human/<side>.inc` |
| `desc/squad/<name>(<side>)` | `desc/mod/squad/<side>.inc`; names with no `(side)` -> `squad/vehicles.inc` |
| `desc/entity/<model>` | `desc/mod/entity/<class>.inc` (class = the entity's folder: tank_heavy, cannon, car...; no def -> `misc.inc`) |
| `desc/weapon`, `desc/ammo`, `desc/stuff`, `desc/container` | `desc/mod/weapon.inc`, `ammo.inc`, `stuff.inc`, `container.inc` |
| `info/squad`, `info/entity`, `info/special` | `info/mod/...` the same way |
| `mission/multi/<map>/name` | `mission_multi/mod/multi.inc` |

## Rules for writing groups
1. A parent `.lng` holds no text keys: only `{tags`, groups and includes.
2. A part file is a flat list for one group: `{"key" "text"}`, one per line, no indent.
   A small sub-group (4 keys or fewer) may be written whole inside its parent's part: `{"name"` / its keys / `}`.
3. No group is opened twice. If a group needs a new part, add one include line for it in the parent.
4. Keys in lower case. One key once: a second copy overrides the first and logs `Localization key redefinition`.
5. UTF-8 without BOM, CRLF line ends, no trailing spaces. Comments start with `;` and are ASCII.
6. Part files end in `.inc`, never `.lng`: the game loads every `.lng` under this folder as its own file.
7. Include paths are relative to the file that holds the include line.
8. New text goes in a `mod/` part, under `; new`. To change a vanilla text, move the key from the vanilla part to
   the `; changed from vanilla` block of the mod part.

## Dropped keys
`_dropped/dead-keys.tsv` lists every mod-only key with a verdict (dead / kept / unsure) and the reason.
Only `dead` keys were moved to `_dropped/*.inc`. To bring one back, move its line into the matching `mod/` part.
The ammo, weapon and item verdicts are the least certain. Delete `_dropped/` once you have looked through it.

## Tool
Made with ARSENAL `tools/lngsplit` (`split`, `dead`, `join --compare`). The files before the split are in
`robz realism mod 1.31.0.arsenal-undo/lngsplit-20261118/localization`.
