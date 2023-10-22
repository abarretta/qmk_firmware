// Copyright 2023 Kyle McCreery
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

#define FN_CAPS     LT(1, KC_CAPS)
#define FN_QUOT     LT(1, KC_QUOT)

// Defines names for use in layer keycodes and the keymap
enum layer_names {
    _QWERTY,
	_LOWER
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_QWERTY] = LAYOUT(
    QK_GESC, KC_Q,  KC_W,   KC_F,     KC_P,    KC_B,    KC_NO,                   KC_J,   KC_L,     KC_U,    KC_Y,   KC_SCLN, KC_DEL,
    FN_CAPS, KC_A,  KC_R,   KC_S,     KC_T,    KC_G,    KC_NO,  KC_NO,           KC_M,   KC_N,     KC_E,    KC_I,   KC_O,    FN_QUOT,
    KC_LSFT, KC_Z,  KC_X,   KC_C,     KC_D,    KC_V,    KC_NO,                   KC_K,   KC_H,     KC_COMM, KC_DOT, KC_SLSH, KC_RSFT,
                    KC_NO,  KC_LCTL,  KC_TAB,  KC_SPC,  KC_MS_BTN1,  KC_F9,  KC_MS_BTN2,   KC_ENT, KC_BSPC,  KC_LALT, KC_NO
  ),
  [_LOWER] = LAYOUT(
    KC_NO,  KC_1,   KC_2,   KC_3,     KC_4,    KC_5,    KC_NO,                   KC_NO,   KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT, KC_NO,
    KC_NO,  KC_6,   KC_7,   KC_8,     KC_9,    KC_0,    KC_NO,  KC_NO,           KC_NO,   KC_MINS, KC_EQL,  KC_LBRC, KC_LCBR, KC_NO,
    KC_NUM, KC_SCRL,  KC_NO,  KC_NO,    KC_NO,   KC_NO,   KC_NO,                   KC_NO,   KC_UNDS, KC_PLUS, KC_RBRC, KC_RCBR, KC_NO,
                    QK_BOOT,  KC_RCTL,  KC_NO,   KC_LGUI, KC_NO,  KC_NO,  KC_NO,   KC_RGUI, KC_NO,   KC_RALT, KC_NO
  )
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][4][2] = {
    [_QWERTY] = { ENCODER_CCW_CW(KC_PGUP, KC_PGDN), ENCODER_CCW_CW(KC_F8, KC_F7),  ENCODER_CCW_CW(KC_HOME, KC_END),  ENCODER_CCW_CW(KC_HOME, KC_END)  },
    [_LOWER] =  { ENCODER_CCW_CW(KC_PGUP, KC_PGDN), ENCODER_CCW_CW(KC_LEFT, KC_RIGHT), ENCODER_CCW_CW(KC_HOME, KC_END),   ENCODER_CCW_CW(KC_HOME, KC_END)    }
};
#endif
