#!/usr/bin/env python3
"""Prepara el JSON de `qmk c2json --no-cpp` para keymap-drawer.

- Reemplaza los nombres de capa (_BASE, _NAV...) por su número.
- Expande los #define de keymap.c que son teclas de capa (SPC_NAV ->
  LT(_NAV, KC_SPC)...), para que se dibujen como tecla + capa al mantener.
Los alias ES_*, K_* y HM_* se dejan tal cual: sus leyendas están en
keymap_drawer.yaml.
"""
import json, re, sys

keymap_c, keymap_json = sys.argv[1], sys.argv[2]
src = open(keymap_c, encoding="utf-8").read()

enum = re.search(r"enum\s+layers\s*\{([^}]*)\}", src)
layers = [n.strip() for n in enum.group(1).split(",") if n.strip()] if enum else []

defines = {}
for name, value in re.findall(r"^#define\s+(\w+)\s+(.+?)\s*(?://.*)?$", src, re.M):
    if re.search(r"(^|\W)LT\(", value):
        defines[name] = value

def fix(kc):
    kc = defines.get(kc, kc)
    for i, name in enumerate(layers):
        kc = re.sub(rf"\b{name}\b", str(i), kc)
    return kc.replace(" ", "")

data = json.load(open(keymap_json, encoding="utf-8"))
data["layers"] = [[fix(k) for k in layer] for layer in data["layers"]]
json.dump(data, sys.stdout, indent=1, ensure_ascii=False)
