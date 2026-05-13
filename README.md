# DZ60-ISO

Firmware for a DZ60 PCB for a custom build keyboard, ISO layout.

## Layer Keys

The firmware adds three unlabeled layer keys on the bottom-right of the board:

| Layer    | Where to find it on the base layer                         | Behavior                                          |
| -------- | ---------------------------------------------------------- | ------------------------------------------------- |
| `Fn`     | Bottom row, directly right of Right Alt                    | Hold for layer 1 or tap 3 times to lock/unlock it |
| `Macro`  | Bottom row, directly left of Right Ctrl                    | Hold for layer 2 or tap 3 times to lock/unlock it |
| `Adjust` | On the `Fn` layer, bottom row, directly left of Right Ctrl | Hold for layer 3 or tap 3 times to lock/unlock it |

## Fn Layer

| Shortcut                                 | Feature                 |
| ---------------------------------------- | ----------------------- |
| `Fn + 1` to `Fn + 0`, `Fn + ß`, `Fn + ´` | `F1` to `F12`           |
| `Fn + Backspace`                         | `Delete`                |
| `Fn + Q`, `Fn + W`, `Fn + E`             | `Home`, `Up`, `End`     |
| `Fn + A`, `Fn + S`, `Fn + D`             | `Left`, `Down`, `Right` |
| `Fn + +`                                 | Keypad `+`              |

## Macro Layer

| Shortcut                   | Feature                                | Notes                                                                             |
| -------------------------- | -------------------------------------- | --------------------------------------------------------------------------------- |
| `Macro + 1` to `Macro + 6` | Media controls                         | Volume down, previous track, play/pause, next track, volume up, mute              |
| `Macro + S`                | Open Spotify                           | Windows-only; uses `Win+R` and the Start Menu shortcut path                       |
| `Macro + Ü`                | Create a new virtual desktop           | Windows-only                                                                      |
| `Macro + Ö`                | Switch to the previous virtual desktop | Windows-only                                                                      |
| `Macro + Ä`                | Close the current virtual desktop      | Windows-only                                                                      |
| `Macro + #`                | Switch to the next virtual desktop     | Windows-only                                                                      |
| `Macro + Left Shift`       | Toggle taunt text mode                 | Alternates upper/lower case while typing; tap again to turn it off                |
| `Macro + X`                | Toggle hex text mode                   | Replaces typed letters and digits with ASCII hex and prefixes each line with `0x` |
| `Macro + B`                | Type the binary form of `b`            | Sends `01100010`                                                                  |
| `Macro + M`                | Open the keymap repository link        | Windows-only                                                                      |
| `Macro + Left GUI`         | Set RGB to rainbow cycle               | Immediate effect                                                                  |
| `Macro + Space`            | Toggle wide text mode                  | Inserts spaces between letters; typed spaces become double spaces                 |

## Adjust Layer

| Shortcut                   | Feature                   | Notes                                 |
| -------------------------- | ------------------------- | ------------------------------------- |
| `Adjust + Q`               | Toggle RGB underglow      |                                       |
| `Adjust + W`               | Cycle RGB mode            |                                       |
| `Adjust + E`, `Adjust + R` | RGB hue up/down           |                                       |
| `Adjust + T`, `Adjust + Z` | RGB saturation up/down    |                                       |
| `Adjust + U`, `Adjust + I` | RGB brightness up/down    |                                       |
| `Adjust + A`               | Toggle backlight          |                                       |
| `Adjust + S`               | Cycle backlight level     |                                       |
| `Adjust + D`, `Adjust + F` | Backlight brighter/dimmer |                                       |
| `Adjust + <`               | Set RGB to rainbow cycle  | Same preset as `Macro + Left GUI`     |
| `Adjust + Y`               | Set RGB to twinkle mode   | Uses a cyan/blue color preset         |
| `Adjust + B`               | Enter bootloader          | Use this before flashing new firmware |

## Automatic Visual Feedback

| Trigger                                      | Feedback                                             |
| -------------------------------------------- | ---------------------------------------------------- |
| `Fn` layer active                            | Bottom underglow lights up cyan                      |
| `Macro` layer active                         | Bottom underglow lights up green                     |
| `Adjust` layer active                        | Bottom underglow lights up yellow                    |
| Caps Lock active                             | Leftmost and rightmost LEDs turn red                 |
| Pressing an unmapped key on a non-base layer | Bottom underglow turns red until the key is released |
