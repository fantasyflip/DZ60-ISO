# AGENTS.md

## Repo Scope

- This repository is a small, standalone QMK firmware snapshot for a DZ60 ISO layout, not a full `qmk_firmware` checkout.
- Primary edit surfaces:
  - `keymap.c` for layout behavior, custom keycodes, macros, and text helpers.
  - `rules.mk` for QMK feature flags and bootloader settings.
  - `config.h` for hardware, matrix, RGB, backlight, and USB descriptors.

## Working Rules

- Prefer the smallest possible change in `keymap.c` or `rules.mk` when the request is about behavior.
- Treat `config.h` as hardware-specific. Do not change matrix pins, diode direction, RGB pin, backlight pin, or USB identifiers unless the user explicitly asks for a hardware/config migration.
- Keep the German keymap/send-string context intact unless the user asks to change locale behavior.
- The includes in `keymap.c` reference a user-local QMK checkout under `/Users/philipp/qmk_firmware/...`. If portability is part of the task, convert those includes to the appropriate QMK-relative includes instead of adding more machine-specific paths.

## Validation

- There are no in-repo tests or CI checks.
- All code or configuration changes in this repository must be validated by running `./scripts/qmk_compile.sh` from the repo root.
- Validate firmware changes from a real QMK checkout that contains this keymap, using one of the standard QMK commands:
  - `qmk compile -kb dz60 -km <keymap_name>`
  - `make dz60:<keymap_name>`
- If flashing is requested, `rules.mk` specifies the `atmel-dfu` bootloader, so use the corresponding QMK flash flow from the full QMK environment.

## Practical Notes

- `keymap.c` contains custom text-conversion helpers and macro behavior; preserve existing behavior unless the task requires refactoring it.
- Some macros are host-OS specific, including Windows-oriented send-string shortcuts. Check the surrounding macro behavior before changing shortcut sequences.
- When a request depends on QMK internals that are not present in this repository, call that out and work from the nearest standard QMK behavior rather than inventing local abstractions.
