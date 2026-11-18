# Weapon stat colours: the scale from lowest to highest

The weapon names in `desc/weapon` carry a stat block. Each value is coloured as a rating in 7 steps:

| step | colour | tag |
|---|---|---|
| 1 lowest | red | `<c(ff0000)>` |
| 2 | red-orange | `<c(ff5a00)>` |
| 3 | orange | `<c(ffaf00)>` |
| 4 | yellow | `<c(ffe100)>` |
| 5 | yellow-green | `<c(c3ff00)>` |
| 6 | light green | `<c(78ff02)>` |
| 7 highest | green | `<c(00ff04)>` |

Labels are white (`<c(ffffff)>`). Muzzle velocity is never coloured.

A weapon is rated inside its own type, and penetration inside its own ammo type: a range that is green for a tank gun
is red for a howitzer, and 133 mm is rated against other shells of the same kind. Where a value has two numbers
(`122 - 91 mm`, near and far), the first number is rated.

How the steps were made: the mod's texts used three colours (red, orange, green). For each type the limits between
those three were measured from its own texts. Red was then divided into steps 1-2, orange into 3-5 and green into 6-7,
by the values that type really has. Reloading time and Barrage had no rating (always orange): they are now spread
evenly from their lowest to their highest value, reloading time reversed because shorter is better.

To rate a new weapon: find its type below, find the stat, take the step whose values are nearest to the new value.

## Which type a weapon is

| type | how to tell |
|---|---|
| Direct-fire gun | has a Penetration line, no Barrage, no Cycling rate (tank and anti-tank guns) |
| Automatic gun | has a Cycling rate line (20mm FlaK 38, 40mm Bofors) |
| Indirect gun | has a Barrage line (howitzers, field guns firing barrages) |
| Mortar or rocket | in `weapon/<nation>/reactive.inc`, no Barrage |
| Support gun | gun with neither Penetration nor Barrage |

## Direct-fire gun

### Range (m) - 171 texts

Low below 190, high from 220 (the author's red/orange/green limits for this type, 14 old colour(s) did not fit); each part divided by its own values.

| step | colour | values | texts |
|---|---|---|---|
| 1 | red `ff0000` | 150, 160 | 5 |
| 2 | red-orange `ff5a00` | 170, 180 | 36 |
| 3 | orange `ffaf00` | 190 | 25 |
| 4 | yellow `ffe100` | 200 | 27 |
| 5 | yellow-green `c3ff00` | 210 | 18 |
| 6 | light green `78ff02` | 220, 230, 240 | 35 |
| 7 | green `00ff04` | 250, 260 | 25 |

### Penetration (mm) - 21 texts

Low below 90, high from 151 (not rated by the author; limits of the other penetration lines); each part divided by its own values.

| step | colour | values | texts |
|---|---|---|---|
| 1 | red `ff0000` | 9 to 27 | 8 |
| 2 | red-orange `ff5a00` | 31 to 86 | 9 |
| 3 | orange `ffaf00` | 101 | 1 |
| 4 | yellow `ffe100` | - | 0 |
| 5 | yellow-green `c3ff00` | 116 | 3 |
| 6 | light green `78ff02` | - | 0 |
| 7 | green `00ff04` | - | 0 |

### Penetration AP (mm) - 10 texts

Low below 90, high from 151 (the author's red/orange/green limits for this type, 1 old colour(s) did not fit); each part divided by its own values.

| step | colour | values | texts |
|---|---|---|---|
| 1 | red `ff0000` | 44, 65 | 4 |
| 2 | red-orange `ff5a00` | 70, 78 | 4 |
| 3 | orange `ffaf00` | 103 | 1 |
| 4 | yellow `ffe100` | - | 0 |
| 5 | yellow-green `c3ff00` | 125 | 1 |
| 6 | light green `78ff02` | - | 0 |
| 7 | green `00ff04` | - | 0 |

### Penetration APBC (mm) - 6 texts

Low below 90, high from 151 (the author's red/orange/green limits for this type); each part divided by its own values.

| step | colour | values | texts |
|---|---|---|---|
| 1 | red `ff0000` | - | 0 |
| 2 | red-orange `ff5a00` | - | 0 |
| 3 | orange `ffaf00` | - | 0 |
| 4 | yellow `ffe100` | 133 | 2 |
| 5 | yellow-green `c3ff00` | - | 0 |
| 6 | light green `78ff02` | 170 | 2 |
| 7 | green `00ff04` | 198 | 2 |

### Penetration APC (mm) - 13 texts

Low below 90, high from 151 (the author's red/orange/green limits for this type); each part divided by its own values.

| step | colour | values | texts |
|---|---|---|---|
| 1 | red `ff0000` | 52, 74 | 5 |
| 2 | red-orange `ff5a00` | 78 | 2 |
| 3 | orange `ffaf00` | - | 0 |
| 4 | yellow `ffe100` | 97 | 4 |
| 5 | yellow-green `c3ff00` | - | 0 |
| 6 | light green `78ff02` | 206 | 1 |
| 7 | green `00ff04` | 261 | 1 |

### Penetration APCBC (mm) - 63 texts

Low below 90, high from 151 (the author's red/orange/green limits for this type); each part divided by its own values.

| step | colour | values | texts |
|---|---|---|---|
| 1 | red `ff0000` | 68, 73 | 3 |
| 2 | red-orange `ff5a00` | 88 | 3 |
| 3 | orange `ffaf00` | 95, 110, 115 | 4 |
| 4 | yellow `ffe100` | 122, 133, 135 | 15 |
| 5 | yellow-green `c3ff00` | 146, 147 | 4 |
| 6 | light green `78ff02` | 151 to 174 | 19 |
| 7 | green `00ff04` | 187, 216, 236, 269 | 15 |

### Penetration APHE (mm) - 9 texts

Low below 86, high from 151 (the author's red/orange/green limits for this type); each part divided by its own values.

| step | colour | values | texts |
|---|---|---|---|
| 1 | red `ff0000` | 26 | 1 |
| 2 | red-orange `ff5a00` | - | 0 |
| 3 | orange `ffaf00` | 86 | 1 |
| 4 | yellow `ffe100` | 101 | 2 |
| 5 | yellow-green `c3ff00` | 137 | 3 |
| 6 | light green `78ff02` | 157 | 1 |
| 7 | green `00ff04` | 233 | 1 |

### Penetration APHEBC (mm) - 33 texts

Low below 90, high from 151 (the author's red/orange/green limits for this type); each part divided by its own values.

| step | colour | values | texts |
|---|---|---|---|
| 1 | red `ff0000` | 62, 73 | 5 |
| 2 | red-orange `ff5a00` | 74 | 2 |
| 3 | orange `ffaf00` | 91, 92 | 6 |
| 4 | yellow `ffe100` | 121, 140 | 6 |
| 5 | yellow-green `c3ff00` | 142 | 7 |
| 6 | light green `78ff02` | 206 | 5 |
| 7 | green `00ff04` | 241 | 2 |

### Penetration HEAT (mm) - 15 texts

Low below 90, high from none (the author's red/orange/green limits for this type, 2 old colour(s) did not fit); each part divided by its own values.

| step | colour | values | texts |
|---|---|---|---|
| 1 | red `ff0000` | 52 | 1 |
| 2 | red-orange `ff5a00` | - | 0 |
| 3 | orange `ffaf00` | 91, 100, 110 | 5 |
| 4 | yellow `ffe100` | 115, 120 | 6 |
| 5 | yellow-green `c3ff00` | 140, 185 | 3 |
| 6 | light green `78ff02` | - | 0 |
| 7 | green `00ff04` | - | 0 |

### Reloading time (s) - 19 texts

Shorter is better; values spread evenly over the 7 steps.

| step | colour | values | texts |
|---|---|---|---|
| 1 | red `ff0000` | 10 | 2 |
| 2 | red-orange `ff5a00` | 7, 8 | 6 |
| 3 | orange `ffaf00` | 6.5 | 1 |
| 4 | yellow `ffe100` | 5.8, 6.2 | 2 |
| 5 | yellow-green `c3ff00` | 5 | 3 |
| 6 | light green `78ff02` | 3.5, 4 | 4 |
| 7 | green `00ff04` | 3 | 1 |

### Accuracy - 150 texts

Word.

| step | colour | values | texts |
|---|---|---|---|
| 1 | red `ff0000` | Very low | 19 |
| 2 | red-orange `ff5a00` | Low | 33 |
| 3 | orange `ffaf00` | Medium | 21 |
| 4 | yellow `ffe100` | High | 20 |
| 5 | yellow-green `c3ff00` | Very high | 28 |
| 6 | light green `78ff02` | Extremely high | 10 |
| 7 | green `00ff04` | Maximum | 19 |


## Automatic gun

### Range (m) - 15 texts

Low below 0, high from 170 (the author's red/orange/green limits for this type, 1 old colour(s) did not fit); each part divided by its own values.

| step | colour | values | texts |
|---|---|---|---|
| 1 | red `ff0000` | - | 0 |
| 2 | red-orange `ff5a00` | - | 0 |
| 3 | orange `ffaf00` | - | 0 |
| 4 | yellow `ffe100` | 160 | 8 |
| 5 | yellow-green `c3ff00` | - | 0 |
| 6 | light green `78ff02` | - | 0 |
| 7 | green `00ff04` | 170 | 7 |

### Penetration AP (mm) - 15 texts

Low below 40, high from 60 (the author's red/orange/green limits for this type, 1 old colour(s) did not fit); each part divided by its own values.

| step | colour | values | texts |
|---|---|---|---|
| 1 | red `ff0000` | 27 | 1 |
| 2 | red-orange `ff5a00` | - | 0 |
| 3 | orange `ffaf00` | 40, 45 | 3 |
| 4 | yellow `ffe100` | 46 | 5 |
| 5 | yellow-green `c3ff00` | 58 | 1 |
| 6 | light green `78ff02` | 60, 65 | 3 |
| 7 | green `00ff04` | 76 | 2 |

### Cycling rate (rpm) - 15 texts

Low below 201, high from 400 (the author's red/orange/green limits for this type); each part divided by its own values.

| step | colour | values | texts |
|---|---|---|---|
| 1 | red `ff0000` | 170 | 1 |
| 2 | red-orange `ff5a00` | 200 | 2 |
| 3 | orange `ffaf00` | 250 | 2 |
| 4 | yellow `ffe100` | 280 | 1 |
| 5 | yellow-green `c3ff00` | 300 | 1 |
| 6 | light green `78ff02` | 400, 450, 700 | 5 |
| 7 | green `00ff04` | 900, 1800 | 3 |


## Indirect gun

### Range (m) - 52 texts

Low below 400, high from 500 (the author's red/orange/green limits for this type, 1 old colour(s) did not fit); each part divided by its own values.

| step | colour | values | texts |
|---|---|---|---|
| 1 | red `ff0000` | 250 to 310 | 8 |
| 2 | red-orange `ff5a00` | 340 to 390 | 10 |
| 3 | orange `ffaf00` | 400, 410 | 4 |
| 4 | yellow `ffe100` | 440, 450 | 6 |
| 5 | yellow-green `c3ff00` | 490 | 4 |
| 6 | light green `78ff02` | 500, 560, 580, 600 | 14 |
| 7 | green `00ff04` | 650, 670, 760, 800 | 6 |

### Barrage (shells) - 52 texts

More shells is better; values spread evenly over the 7 steps.

| step | colour | values | texts |
|---|---|---|---|
| 1 | red `ff0000` | 1 | 7 |
| 2 | red-orange `ff5a00` | - | 0 |
| 3 | orange `ffaf00` | 3 | 20 |
| 4 | yellow `ffe100` | - | 0 |
| 5 | yellow-green `c3ff00` | 4 | 8 |
| 6 | light green `78ff02` | - | 0 |
| 7 | green `00ff04` | 6 | 17 |

### Accuracy - 52 texts

Word.

| step | colour | values | texts |
|---|---|---|---|
| 1 | red `ff0000` | Very low | 17 |
| 2 | red-orange `ff5a00` | Low | 35 |
| 3 | orange `ffaf00` | - | 0 |
| 4 | yellow `ffe100` | - | 0 |
| 5 | yellow-green `c3ff00` | - | 0 |
| 6 | light green `78ff02` | - | 0 |
| 7 | green `00ff04` | - | 0 |


## Mortar or rocket

### Range (m) - 18 texts

Low below 180, high from 270 (the author's red/orange/green limits for this type, 1 old colour(s) did not fit); each part divided by its own values.

| step | colour | values | texts |
|---|---|---|---|
| 1 | red `ff0000` | 130 | 2 |
| 2 | red-orange `ff5a00` | - | 0 |
| 3 | orange `ffaf00` | 180, 245 | 2 |
| 4 | yellow `ffe100` | 255, 260 | 3 |
| 5 | yellow-green `c3ff00` | 265 | 3 |
| 6 | light green `78ff02` | 270, 275, 280 | 3 |
| 7 | green `00ff04` | 300, 310 | 5 |

### Rate of fire (rounds per minute) - 16 texts

Low below 9, high from 11 (the author's red/orange/green limits for this type, 2 old colour(s) did not fit); each part divided by its own values.

| step | colour | values | texts |
|---|---|---|---|
| 1 | red `ff0000` | 7 | 2 |
| 2 | red-orange `ff5a00` | 8 | 2 |
| 3 | orange `ffaf00` | - | 0 |
| 4 | yellow `ffe100` | 9 | 5 |
| 5 | yellow-green `c3ff00` | - | 0 |
| 6 | light green `78ff02` | 11, 12 | 4 |
| 7 | green `00ff04` | 15 | 3 |

### Accuracy - 2 texts

Word.

| step | colour | values | texts |
|---|---|---|---|
| 1 | red `ff0000` | - | 0 |
| 2 | red-orange `ff5a00` | Low | 2 |
| 3 | orange `ffaf00` | - | 0 |
| 4 | yellow `ffe100` | - | 0 |
| 5 | yellow-green `c3ff00` | - | 0 |
| 6 | light green `78ff02` | - | 0 |
| 7 | green `00ff04` | - | 0 |


## Support gun

### Range (m) - 28 texts

Low below 190, high from none (the author's red/orange/green limits for this type, 2 old colour(s) did not fit); each part divided by its own values.

| step | colour | values | texts |
|---|---|---|---|
| 1 | red `ff0000` | 80 | 1 |
| 2 | red-orange `ff5a00` | 180 | 5 |
| 3 | orange `ffaf00` | 190, 200, 210 | 15 |
| 4 | yellow `ffe100` | 250, 320, 350 | 4 |
| 5 | yellow-green `c3ff00` | 710, 760 | 3 |
| 6 | light green `78ff02` | - | 0 |
| 7 | green `00ff04` | - | 0 |

### Reloading time (s) - 4 texts

Shorter is better; values spread evenly over the 7 steps.

| step | colour | values | texts |
|---|---|---|---|
| 1 | red `ff0000` | 90 | 1 |
| 2 | red-orange `ff5a00` | - | 0 |
| 3 | orange `ffaf00` | 30 | 1 |
| 4 | yellow `ffe100` | - | 0 |
| 5 | yellow-green `c3ff00` | 8 | 1 |
| 6 | light green `78ff02` | - | 0 |
| 7 | green `00ff04` | 5 | 1 |

### Accuracy - 21 texts

Word.

| step | colour | values | texts |
|---|---|---|---|
| 1 | red `ff0000` | Very low | 4 |
| 2 | red-orange `ff5a00` | Low | 17 |
| 3 | orange `ffaf00` | - | 0 |
| 4 | yellow `ffe100` | - | 0 |
| 5 | yellow-green `c3ff00` | - | 0 |
| 6 | light green `78ff02` | - | 0 |
| 7 | green `00ff04` | - | 0 |


## Other (other)

### Range (m) - 5 texts

Low below 70, high from 70 (the author's red/orange/green limits for this type, 2 old colour(s) did not fit); each part divided by its own values.

| step | colour | values | texts |
|---|---|---|---|
| 1 | red `ff0000` | - | 0 |
| 2 | red-orange `ff5a00` | - | 0 |
| 3 | orange `ffaf00` | - | 0 |
| 4 | yellow `ffe100` | - | 0 |
| 5 | yellow-green `c3ff00` | - | 0 |
| 6 | light green `78ff02` | 70, 180 | 4 |
| 7 | green `00ff04` | 400 | 1 |

### Reloading time (s) - 1 texts

Shorter is better; values spread evenly over the 7 steps (scale of all reloading times, this type has too few).

| step | colour | values | texts |
|---|---|---|---|
| 1 | red `ff0000` | - | 0 |
| 2 | red-orange `ff5a00` | 12 | 1 |
| 3 | orange `ffaf00` | - | 0 |
| 4 | yellow `ffe100` | - | 0 |
| 5 | yellow-green `c3ff00` | - | 0 |
| 6 | light green `78ff02` | - | 0 |
| 7 | green `00ff04` | - | 0 |

## Order and wording of a block

`Name<c(ffffff)>\n Range - <c(colour)>160 m<c(ffffff)>\n Penetration AP - <c(colour)>46 - 11 mm<c(ffffff)>\n Muzzle velocity - 780 m/s\n Cycling rate - <c(colour)>450 rpm`

Order: Range, Penetration, Barrage, Rate of fire, Reloading time, Cycling rate, Muzzle velocity, Accuracy.
Units: `m`, `mm`, `shells` (`1 shell`), `rounds per minute`, `s`, `rpm`, `m/s`, one space between number and unit.

## Not rated

Too few texts of the kind to make a scale; their colours are as the author wrote them:

- Direct-fire gun | Penetration APCRN (1)
- Other (flame) | Range (1)
- Other (rifle) | Range (1)
- Other (rifle) | Rate of fire (1)
