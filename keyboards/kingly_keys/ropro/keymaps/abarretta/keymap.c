/* Copyright 2019 Garret G. (TheRoyalSweatshirt)
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
#define FN_CAPS    LT(1, KC_CAPS)
enum layer_names {
    _BASE,
    _FN1
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

  /* BASE
   *        ,-----------------------------------------------------------------------------------.
   *        |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |  F7  |  F8  |  F9  |  F10  | F11 |  F12 |
   *        |------+------+------+------+------+-------------+------+------+------+------+------|
   *        | Esc  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | DEL  |
   *        |+------+------+------+------+-----+------+------+------+------+------+------+------|
   *  RotEn |  `   |   Q  |   W  |   F  |   P  |   B  |   J  |   L  |   U  |   Y  |   ;  |  \   |
   * ,------+------+------+------+------+------+------+------+------+------+------+------+------|
   * | Cut  | CAPS |   A  |   R  |   S  |   T  |   G  |   M  |   N  |   E  |   I  |   O  |  "   |
   * |------+------+------+------+------+------+-------------+------+------+------+------+------|
   * | Copy | Shift|   Z  |   X  |   C  |   D  |   V  |   K  |   H  |   ,  |   .  |   /  |Shift |
   * |------+------+------+------+------+------+------+------+------+------+------+------+------|
   * | Paste| Ctrl | Raise| GUI  | ALT  |  TAB |SPACE |Enter | Bspc | Left | Down |  Up  |Right |
   * `------------------------------------------------------------------------------------------'
   */
  	[_BASE] = LAYOUT(
                KC_F1,      KC_F2,    KC_F3,  KC_F4,  KC_F5,  KC_F6,  KC_F7,  KC_F8,  KC_F9,  KC_F10, KC_F11, KC_F12,
                KC_ESC,     KC_1,     KC_2,   KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,   KC_9,   KC_0,   KC_DEL,
    KC_NO,      KC_GRV,     KC_Q,     KC_W,   KC_F,   KC_P,   KC_B,   KC_J,   KC_L,   KC_U,   KC_Y,   KC_SCLN,KC_BSPC,
    KC_F13,     KC_BSLS,    KC_A,     KC_R,   KC_S,   KC_T,   KC_G,   KC_M,   KC_N,   KC_E,   KC_I,   KC_O,   KC_QUOT,
    KC_F14,     KC_LSFT,    KC_Z,     KC_X,   KC_C,   KC_D,   KC_V,   KC_K,   KC_H,   KC_COMM,KC_DOT, KC_SLSH,KC_RSFT,
    KC_F15,     KC_LCTL,    KC_LGUI,  FN_CAPS,KC_LALT,KC_SPC, KC_TAB, KC_ENT, KC_BSPC,KC_LEFT,KC_DOWN,KC_UP,  KC_RGHT
    ),
    [_FN1] = LAYOUT(
                KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,
                KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,
    KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,
    KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,  KC_NO,  KC_HOME,KC_MINS,KC_EQL, KC_LBRC,KC_RBRC,KC_PGUP,
    KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,      KC_NO,  KC_NO,  KC_END, KC_UNDS,KC_PLUS,KC_LCBR,KC_RCBR,KC_PGDN,
    KC_NO,      KC_RCTL,    KC_TRNS,    KC_RGUI,    KC_RALT,    KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO,  KC_NO
  ),
};

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_PGDN);
        } else {
            tap_code(KC_PGUP);
        }
    }
    return true;
}
