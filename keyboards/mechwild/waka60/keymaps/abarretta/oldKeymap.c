/* Copyright 2021 Kyle McCreery
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

 #include QMK_KEYBOARD_H

#define FN1_CAPS    LT(2, KC_CAPS)

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _COLEMAK,
    _QWERTY,
	_FN1,
	_FN2
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_COLEMAK] = LAYOUT(
    KC_ESC,     KC_1,    KC_2,    KC_3,    KC_4,    KC_5,             KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,
    KC_GRV,     KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,             KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSLS,
    FN1_CAPS,   KC_A,    KC_R,    KC_S,    KC_T,    KC_G,             KC_M,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT,
    KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,   TG(1),    KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
    KC_LCTL,    MO(3),   KC_LGUI, KC_LALT, KC_TAB,  KC_SPC, KC_LOCK,  KC_ENT,  KC_BSPC, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT
    ),
    [_QWERTY] = LAYOUT(
    KC_TRNS,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,             KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_TRNS,
    KC_TRNS,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,             KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_TRNS,
    FN1_CAPS,   KC_A,    KC_S,    KC_D,    KC_F,    KC_G,             KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_TRNS,
    KC_TRNS,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,   KC_TRNS,  KC_N,    KC_M,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    ),
    [_FN1] = LAYOUT(
    KC_F1,      KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,            KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
    KC_TRNS,    AU_TOG,  RGB_TOG, RGB_HUI, RGB_SAI, RGB_VAI,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS,    MU_TOG,  RGB_MOD, RGB_HUD, RGB_SAD, RGB_VAD,          KC_HOME, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_PGUP,
    KC_TRNS,    MU_MOD,  RGB_RMOD,KC_TRNS, KC_TRNS, KC_TRNS, RESET,   KC_END,  KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_PGDN,
    KC_RCTL,    KC_TRNS, KC_RGUI, KC_RALT, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MPRV, KC_MPLY, KC_MNXT
    ),
    [_FN2] = LAYOUT(
    KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,          KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS
    )
};
