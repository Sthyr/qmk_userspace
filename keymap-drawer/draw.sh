#!/usr/bin/env bash
# Genera la imagen del layout del keymap sthyr (Silakka54) con keymap-drawer.
# Uso: ./draw.sh            -> crea img/sthyr.svg
set -euo pipefail

KB=silakka54
KM=sthyr
DIR="$(cd "$(dirname "$0")" && pwd)"
USERSPACE="$(cd "$DIR/.." && pwd)"
KEYMAP_C="$USERSPACE/keyboards/$KB/keymaps/$KM/keymap.c"
QMK_HOME="${QMK_HOME:-$HOME/qmk_firmware}"
INFO_JSON="$QMK_HOME/keyboards/$KB/keyboard.json"
TMP="$(mktemp -d)"
trap 'rm -rf "$TMP"' EXIT

mkdir -p "$DIR/img"
qmk c2json -q --no-cpp -kb "$KB" -km "$KM" "$KEYMAP_C" -o "$TMP/raw.json"
python3 "$DIR/keymap_prep.py" "$KEYMAP_C" "$TMP/raw.json" > "$TMP/keymap.json"
keymap -c "$DIR/keymap_drawer.yaml" parse -q "$TMP/keymap.json" -c 12 \
    -l Base Navegación Números Símbolos Mouse Juegos > "$DIR/$KM.yaml"
# keymap-drawer no lee los combos de keymap.c: se agregan a mano.
# p = posiciones en el orden de LAYOUT (W=14, F=15, H=43, ","=44, "."=45).
cat >> "$DIR/$KM.yaml" <<'EOF'
combos:
  - {p: [14, 15], k: Esc, l: [Base]}
  - {p: [44, 45], k: ´, l: [Base]}
  - {p: [43, 44], k: Mouse, l: [Base, Mouse]}
EOF
keymap -c "$DIR/keymap_drawer.yaml" draw -j "$INFO_JSON" "$DIR/$KM.yaml" > "$DIR/img/$KM.svg"
echo "Imagen generada: $DIR/img/$KM.svg"
