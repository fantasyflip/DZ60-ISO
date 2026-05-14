#!/usr/bin/env bash

set -euo pipefail

repo_root="$(cd "$(dirname "${BASH_SOURCE[0]}")/.." && pwd)"
env_file="$repo_root/.env"

if [[ ! -f "$env_file" ]]; then
  echo "Missing $env_file" >&2
  exit 1
fi

set -a
source "$env_file"
set +a

if [[ -z "${QMK_KEYMAP_DIR:-}" ]]; then
  echo "QMK_KEYMAP_DIR is not set in $env_file" >&2
  exit 1
fi

login_shell="${SHELL:-/bin/zsh}"

if ! "$login_shell" -lic 'command -v qmk >/dev/null 2>&1 && qmk --version >/dev/null 2>&1'; then
  echo "qmk CLI not available from login shell $login_shell" >&2
  exit 1
fi

mkdir -p "$QMK_KEYMAP_DIR"

files=(README.md config.h keymap.c rules.mk)

for file in "${files[@]}"; do
  cp "$repo_root/$file" "$QMK_KEYMAP_DIR/$file"
done

echo "Synced ${#files[@]} files to $QMK_KEYMAP_DIR"
echo "Running: qmk compile -kb dz60 -km fantasyflip"

"$login_shell" -lic "qmk compile -kb dz60 -km fantasyflip"