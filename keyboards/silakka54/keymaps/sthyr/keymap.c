// Keymap Silakka54 de Sthyr, traducido desde Vial (vial.vil).
// Distribución del sistema: español latinoamericano. Los alias ES_* vienen de
// keymap_spanish_latin_america.h y muestran el carácter que produce cada tecla.
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#include "keymap_spanish_latin_america.h"

enum layers {
    _BASE, _NAV, _NUM, _SYM, _MOUSE, _GAME
};

// Home row mods
#define HM_A    LGUI_T(KC_A)     // A al tocar, Super al mantener
#define HM_R   LALT_T(KC_R)     // R al tocar, Alt al mantener
#define HM_S    LSFT_T(KC_S)     // S al tocar, Shift al mantener
#define HM_G    MEH_T(KC_G)      // G al tocar, Meh (Ctrl+Shift+Alt) al mantener
#define HM_E    RSFT_T(KC_E)     // E al tocar, Shift al mantener
#define HM_I    LALT_T(KC_I)     // I al tocar, Alt al mantener
#define HM_O    RGUI_T(KC_O)     // O al tocar, Super al mantener
#define M_NUM   LT(_NUM, KC_M)   // M al tocar, Números al mantener
#define T_MOU   LT(_MOUSE, KC_T) // T al tocar, Mouse al mantener

// Pulgares: tecla al tocar, capa (o Ctrl) al mantener
#define SPC_NAV LT(_NAV, KC_SPC)
#define TAB_CTL LCTL_T(KC_TAB)   // Tab al tocar, Ctrl al mantener
#define ENT_SYM LT(_SYM, KC_ENT)

// Tecla \ de un teclado US. En Linux equivale a la tecla ISO que usa ES_RCBR,
// así que con distribución latinoamericana da los mismos símbolos.
#define K_RCBR  KC_BSLS          // }
#define K_RBRC  S(KC_BSLS)       // ]
#define K_GRV   RALT(KC_BSLS)    // `

enum custom_keycodes {
    M_ACUTE = SAFE_RANGE, // Macro 0 de Vial: escribe una tilde suelta (´)
    M_CIRC,               // ^ suelto (en latam ^ es tecla muerta)
    M_GRV,                // ` suelto (en latam ` es tecla muerta)
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // Base: Colemak-DH con home row mods
    [_BASE] = LAYOUT(
        ES_MINS,   ES_AT,     ES_IEXL,   ES_EXLM,   ES_IQUE,   ES_QUES,       XXXXXXX,   ES_QUOT,   ES_DQUO,   KC_APP,    XXXXXXX,   KC_PSCR,
        KC_ESC,    KC_Q,      KC_W,      KC_F,      KC_P,      KC_B,          KC_J,      KC_L,      KC_U,      KC_Y,      ES_NTIL,   KC_DEL,
        TG(_GAME), HM_A,      HM_R,      HM_S,      T_MOU,     HM_G,          M_NUM,     KC_N,      HM_E,      HM_I,      HM_O,      ES_SCLN,
        KC_CAPS,   KC_Z,      KC_X,      KC_C,      KC_D,      KC_V,          KC_K,      KC_H,      KC_COMM,   KC_DOT,    ES_MINS,   ES_ACUT,
                                         KC_ESC,    SPC_NAV,   TAB_CTL,       ENT_SYM,   KC_BSPC,   KC_DEL
    ),
    // Navegación (mantener Espacio): F1-F12, flechas y bootloader
    [_NAV] = LAYOUT(
        _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, QK_BOOT,
        _______, KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,       _______, KC_HOME, KC_PGDN, KC_PGUP, KC_END,  _______,
        _______, KC_F6,   KC_LALT, KC_LSFT, KC_LCTL, KC_F7,       _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, _______,
        _______, KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,      _______, _______, _______, _______, _______, _______,
                                   _______, _______, _______,     _______, _______, _______
    ),
    // Números (mantener M)
    [_NUM] = LAYOUT(
        KC_NUM,  _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______,
        _______, _______, KC_7,    KC_8,    KC_9,    KC_PEQL,     _______, _______, _______, _______, _______, _______,
        _______, KC_PAST, KC_4,    KC_5,    KC_6,    KC_PPLS,     _______, _______, _______, _______, _______, _______,
        _______, KC_PSLS, KC_1,    KC_2,    KC_3,    KC_PMNS,     _______, _______, _______, _______, _______, _______,
                                   KC_COMM, KC_0,    KC_DOT,      _______, _______, _______
    ),
    // Símbolos (mantener Enter)
    [_SYM] = LAYOUT(
        _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______,
        _______, ES_AT,   ES_IQUE, ES_QUES, ES_LCBR, K_RCBR,      M_ACUTE, ES_DLR,  ES_PERC, ES_AMPR, M_CIRC,  _______,
        _______, ES_TILD, ES_IEXL, ES_EXLM, ES_LPRN, ES_RPRN,     KC_PPLS, KC_PAST, ES_LABK, ES_RABK, ES_NUMB, KC_RALT,
        _______, ES_DQUO, ES_QUOT, ES_EQL,  ES_LBRC, K_RBRC,      KC_PMNS, KC_PSLS, ES_PIPE, ES_BSLS, M_GRV,   _______,
                                   _______, ES_MINS, ES_UNDS,     _______, _______, _______
    ),
    // Mouse y multimedia (mantener T, o combo H + , para fijarla)
    [_MOUSE] = LAYOUT(
        _______,   _______,   _______,   _______,   _______,   _______,       _______,   _______,   _______,   _______,   _______,   _______,
        _______,   _______,   _______,   _______,   KC_MPLY,   KC_VOLU,       MS_BTN5,   MS_WHLL,   MS_WHLD,   MS_WHLU,   MS_WHLR,   _______,
        _______,   _______,   KC_MUTE,   KC_MSTP,   _______,   KC_VOLD,       MS_BTN4,   MS_LEFT,   MS_DOWN,   MS_UP,     MS_RGHT,   _______,
        _______,   _______,   _______,   MS_ACL0,   MS_ACL1,   MS_ACL2,       _______,   _______,   _______,   _______,   _______,   _______,
                                         _______,   _______,   _______,       MS_BTN1,   MS_BTN2,   MS_BTN3
    ),
    // Juegos (TG desde la base)
    [_GAME] = LAYOUT(
        _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______,
        _______, KC_1,    KC_2,    KC_0,    KC_RGHT, _______,     _______, _______, _______, _______, _______, _______,
        _______, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_LSFT,     _______, _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,     _______, _______, _______, _______, _______, _______,
                                   _______, KC_SPC,  KC_TAB,      _______, _______, _______
    )
};

// Chordal Hold: mano de cada tecla. '*' = exenta: los pulgares (Ctrl y capas)
// se pueden combinar con teclas de la misma mano (C-x, Espacio+F1, Enter+$...).
const char chordal_hold_layout[MATRIX_ROWS][MATRIX_COLS] PROGMEM = LAYOUT(
    'L', 'L', 'L', 'L', 'L', 'L',     'R', 'R', 'R', 'R', 'R', 'R',
    'L', 'L', 'L', 'L', 'L', 'L',     'R', 'R', 'R', 'R', 'R', 'R',
    'L', 'L', 'L', 'L', 'L', 'L',     'R', 'R', 'R', 'R', 'R', 'R',
    'L', 'L', 'L', 'L', 'L', 'L',     'R', 'R', 'R', 'R', 'R', 'R',
                   '*', '*', '*',     '*', '*', '*'
);

// Combos: dos teclas a la vez producen otra (para no usar el meñique)
const uint16_t PROGMEM combo_esc[]  = {KC_W, KC_F, COMBO_END};
const uint16_t PROGMEM combo_acut[]  = {KC_COMM, KC_DOT, COMBO_END};
const uint16_t PROGMEM combo_mouse[] = {KC_H, KC_COMM, COMBO_END};
combo_t key_combos[] = {
    COMBO(combo_esc,   KC_ESC),     // W + F -> Esc
    COMBO(combo_acut,  ES_ACUT),    // , + . -> ´ (tecla muerta)
    COMBO(combo_mouse, TG(_MOUSE)), // H + , -> activar/desactivar Mouse
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case M_ACUTE:
            if (record->event.pressed) {
                tap_code(ES_ACUT); // tecla muerta ´
                tap_code(KC_SPC);  // + espacio = ´ suelta
            }
            return false;
        case M_CIRC:
            if (record->event.pressed) {
                tap_code16(ES_CIRC); // tecla muerta ^
                tap_code(KC_SPC);    // + espacio = ^ suelto
            }
            return false;
        case M_GRV:
            if (record->event.pressed) {
                tap_code16(K_GRV);   // tecla muerta `
                tap_code(KC_SPC);    // + espacio = ` suelto
            }
            return false;
    }
    return true;
}
