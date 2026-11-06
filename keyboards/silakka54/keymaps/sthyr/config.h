// Ajustes traducidos desde "QMK Settings" de Vial.
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

// Tap-hold (home row mods, Ctrl y teclas de capa en los pulgares)
#define TAPPING_TERM 200
#define PERMISSIVE_HOLD   // mod + tecla tocada y soltada dentro del mod = hold
#define CHORDAL_HOLD      // los mods solo se activan con la mano contraria
                          // (los pulgares están exentos: chordal_hold_layout en keymap.c)
#define FLOW_TAP_TERM 150 // al escribir rápido, las teclas tap-hold se resuelven como tap

// Caps Word: se activa manteniendo los dos Shift a la vez (S + E)
#define BOTH_SHIFTS_TURNS_ON_CAPS_WORD

// NKRO activado por defecto (en Vial estaba activo en "Magic")
#define NKRO_DEFAULT_ON true

// Teclas de mouse (valores de Vial)
#define MOUSEKEY_DELAY             10
#define MOUSEKEY_INTERVAL          20
#define MOUSEKEY_MOVE_DELTA        6
#define MOUSEKEY_MAX_SPEED         8
#define MOUSEKEY_TIME_TO_MAX       30
#define MOUSEKEY_WHEEL_DELAY       10
#define MOUSEKEY_WHEEL_INTERVAL    80
#define MOUSEKEY_WHEEL_MAX_SPEED   8
#define MOUSEKEY_WHEEL_TIME_TO_MAX 40
