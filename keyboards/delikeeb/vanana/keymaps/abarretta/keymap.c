/* Copyright 2020 noclew
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

#define FN1_CAPS    LT(1, KC_CAPS)

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _BASE,
    _LOWER,
    _RAISE,
    _ADJUST
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* BASE
     * -------------------------------------------               -------------------------------------------
     * | Esc  |   1  |   2  |   3  |   4  |   5  |               |   6  |   7  |   8  |   9  |   0  | Del  |
     * -------------------------------------------               -------------------------------------------
     * | Grv  |   Q  |   W  |   F  |   P  |   B  |               |   J  |   L  |   U  |   Y  |   ;  |   \  |
     * -------------------------------------------   ---------  --------------------------------------------
     * | CAPS |   A  |   R  |   S  |   T  |   G  |   |  F9   |   |   M  |   N  |   E  |   I  |   O  |  '   |
     * -------------------------------------------   ---------   -------------------------------------------
     * | Shift|   Z  |   X  |   C  |   D  |   V  |   | Mute  |   |   K  |   H  |   ,  |   .  |   /  |Sft(cap)|
     * -------------------------------------------   ---------   -------------------------------------------
     *        |  Up  | Down | Ctrl |  Tab | Space|               | Enter | BSPC | Alt | Left | Right|
     *        ------------------------------------               ------------------------------------
     */

    [_BASE] = LAYOUT(
    KC_ESC,  KC_1,   KC_2,   KC_3,     KC_4,   KC_5,             KC_6,   KC_7,    KC_8,   KC_9,    KC_0,   KC_DEL,
    KC_GRV,  KC_Q,   KC_W,   KC_F,     KC_P,   KC_B,             KC_J,   KC_L,    KC_U,   KC_Y,    KC_SCLN,KC_BSLS,
    FN1_CAPS,KC_A,   KC_R,   KC_S,     KC_T,   KC_G,   KC_F9,    KC_M,   KC_N,    KC_E,   KC_I,    KC_O,   KC_QUOT,
    KC_LSFT, KC_Z,   KC_X,   KC_C,     KC_D,   KC_V,   KC_LOCK,  KC_K,   KC_H,    KC_COMM,KC_DOT,  KC_SLSH,KC_RSFT,
             KC_UP,  KC_DOWN,KC_LCTRL, KC_TAB, KC_SPC,           KC_ENT, KC_BSPC, KC_LALT,KC_LEFT, KC_RGHT
    ),

    [_LOWER] = LAYOUT(
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,             KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,           KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  RESET,   KC_TRNS, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC, KC_TRNS,
    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,  KC_TRNS, KC_TRNS, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR, KC_TRNS,
             KC_PGUP, KC_PGDN, KC_RCTL, KC_LGUI, KC_TRNS,           KC_TRNS, KC_RGUI, KC_RALT, KC_HOME, KC_END
    ),
};

bool is_alt_tab_active = false;
uint16_t alt_tab_timer = 0;

bool encoder_update_kb(uint8_t index, bool clockwise) {
    if( index == 0 ) {
        if (!is_alt_tab_active) {
            is_alt_tab_active = true;
            register_code(KC_LALT);
        }
        if (clockwise) {
            alt_tab_timer = timer_read();
            tap_code16(KC_TAB);
        } else {
            alt_tab_timer = timer_read();
            tap_code16(S(KC_TAB));
        }
    } else if ( index == 1 ) {
        if ( clockwise ) {
            tap_code(KC_F8);
        } else {
            tap_code(KC_F7);
        }
    }

    return true;
}

void matrix_scan_user(void) {
  if (is_alt_tab_active) {
    if (timer_elapsed(alt_tab_timer) > 1250) {
      unregister_code(KC_LALT);
      is_alt_tab_active = false;
    }
  }
}

