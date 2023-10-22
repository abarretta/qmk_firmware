/* Copyright 2020 null-ll
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
#include "basketweave.h"

enum layer_number {
    _COLEMAK,
    _QWERTY,
    _LOWER
};

enum basketweave_keycodes {
    COLEMAK = SAFE_RANGE,
    QWERTY,
    LOWER
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/*
*,--------------------------------------------------------------------------------------------------------------------------------
*| ESC |  `  |  1  |  2  |  3  |  4  |  5  |  6  |         |  7  |  8  |  9  |  0  |  -  |  =  | BSPC|
*|-----+-----+-----+-----+-----+-----+-----------'   .-----|-----+-----+-----+-----+-----+-----+-----|  ,------,
*| INS | TAB |  Q  |  W  |  F  |  P  |  B  |         |  J  |  L  |  U  |  Y  |  ;  |  [  |  ]  |  \  |  |Rotary|
*|-----+-----+-----+-----+-----+-----+-----|         '-----+-----+-----+-----+-----+-----+-----|-----|  '------'
*| DEL | CAP |  A  |  R  |  S  |  T  |  G  |               |  M  |  N  |  E  |  I  |  O  |  '  | ENT |
*'-----+-----+-----+-----+-----+-----+-----|               |-----+-----+-----+-----+-----+-----+-----|
*      |LSHFT|  Z  |  X  |  C  |  D  |  V  |               |  V  |  K  |  H  |  ,  |  .  |  /  |RSHFT|        ,----,
*      |-----+-----+-----+-----+-----+-----|               |-----+-----+-----+-----+-----+-----+-----|   ,----| Up |-----,
*      |RCTRL|XXXXX| LALT|   SPACE   |  FN |               |     ENTER       | DEL |XXXXX|   LGUI    |   |Left|Down|Right|
*      '-----------------------------------'               '-----------------------------------------'   '---------------'
*/
[_COLEMAK] = LAYOUT_default(  /* base */
    KC_ESC, KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,
    KC_MPRV,  KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,    KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN,    KC_LBRC, KC_RBRC, KC_BSLS, KC_MPLY,
    KC_MNXT,  KC_CAPS, KC_A,    KC_R,    KC_S,    KC_T,    KC_G,    KC_M,    KC_N,    KC_E,    KC_I,    KC_O, KC_QUOT, KC_ENT,
            KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    KC_V,    KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_UP,
            KC_LCTL, KC_LALT,          KC_SPC,           MO(_LOWER),            KC_ENT,           KC_DEL, KC_LGUI,          KC_LEFT, KC_DOWN, KC_RIGHT
),

/*
*,--------------------------------------------------------------------------------------------------------------------------------
*| ESC |  `  |  1  |  2  |  3  |  4  |  5  |  6  |         |  7  |  8  |  9  |  0  |  -  |  =  | BSPC|
*|-----+-----+-----+-----+-----+-----+-----------'   .-----|-----+-----+-----+-----+-----+-----+-----|  ,------,
*| INS | TAB |  Q  |  W  |  E  |  R  |  T  |         |  Y  |  U  |  I  |  O  |  P  |  [  |  ]  |  \  |  |Rotary|
*|-----+-----+-----+-----+-----+-----+-----|         '-----+-----+-----+-----+-----+-----+-----|-----|  '------'
*| DEL | CAP |  A  |  S  |  D  |  F  |  G  |               |  H  |  J  |  K  |  L  |  ;  |  '  |ENTER|
*'-----+-----+-----+-----+-----+-----+-----|               |-----+-----+-----+-----+-----+-----+-----|
*      |LSHFT|  Z  |  X  |  C  |  V  |  B  |               |  B  |  N  |  M  |  ,  |  .  |  /  |RSHFT|        ,----,
*      |-----+-----+-----+-----+-----+-----|               |-----+-----+-----+-----+-----+-----+-----|   ,----| Up |-----,
*      |RCTRL|XXXXX| LALT|   SPACE   |  FN |               |     ENTER       | DEL |XXXXX|   LGUI    |   |Left|Down|Right|
*      '-----------------------------------'               '-----------------------------------------'   '---------------'
*/
  [_QWERTY] = LAYOUT_default(
    KC_ESC, KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_MINS, KC_EQL,  KC_BSPC,
    KC_MPRV,  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_LBRC, KC_RBRC, KC_BSLS, KC_MPLY,
    KC_MNXT,  KC_CAPS, KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, KC_ENT,
            KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_B,    KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT, KC_UP,
            KC_LCTL, KC_LALT,          KC_SPC,           MO(_LOWER),            KC_ENT,           KC_DEL, KC_LGUI,          KC_LEFT, KC_DOWN, KC_RIGHT
),

 /*
*,--------------------------------------------------------------------------------------------------------------------------------
*| ESC |  `  | F1  | F2  | F3  | F4  | F5  | F6  |         |  F7 |  F8 |  F9 | F10 | F11 | F12 | BSPC|
*|-----+-----+-----+-----+-----+-----+-----------'   .-----|-----+-----+-----+-----+-----+-----+-----|  ,------,
*| INS | TAB |     |     |     |     |     |         |     |     |     |     |     |  [  |  ]  |  \  |  |Rotary|
*|-----+-----+-----+-----+-----+-----+-----|         '-----+-----+-----+-----+-----+-----+-----|-----|  '------'
*| DEL | CAP |     |     |     |     |     |               |     | COL | QWR |     |     |  '  |ENTER|
*'-----+-----+-----+-----+-----+-----+-----|               |-----+-----+-----+-----+-----+-----+-----|
*      |LSHFT|     |     |     |     |     |               |     |     |     |  ,  |  .  |  /  |RSHFT|        ,----,
*      |-----+-----+-----+-----+-----+-----|               |-----+-----+-----+-----+-----+-----+-----|   ,----| Up |-----,
*      |RCTRL|XXXXX| LALT|   SPACE   |  FN |               |     BACKSPACE   | DEL |XXXXX|   RGUI    |   |Left|Down|Right|
*      '-----------------------------------'               '-----------------------------------------'   '---------------'
*/

 [_LOWER] = LAYOUT_default(
 KC_ESC, KC_GRV,  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,    KC_F7,    KC_F8,    KC_F9,    KC_F10,    KC_F11, KC_F12,  KC_BSPC,
      KC_MPRV,  KC_TAB,  KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_LBRC, KC_RBRC, KC_BSLS, KC_MPLY,
      KC_MNXT,  KC_CAPS, KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    COLEMAK,     QWERTY,    KC_TRNS,    KC_TRNS,  KC_QUOT, KC_ENT,
               KC_LSFT, KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,    KC_TRNS,  KC_SLSH, KC_RSFT, KC_UP,
               KC_LCTL, KC_LALT,          KC_SPC,           _______,            KC_BSPC,           KC_DEL, KC_RGUI,          KC_LEFT, KC_DOWN, KC_RIGHT
    
 )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case COLEMAK:
         if (record->event.pressed) {
             set_single_persistent_default_layer(_COLEMAK);
         }
         return false;
         break;
        case QWERTY:
         if (record->event.pressed) {
             set_single_persistent_default_layer(_QWERTY);
         }
         return false;
         break;
    }
    return true;
};

void encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_VOLD);
        } else {
            tap_code(KC_VOLU);
        }
    }
}
