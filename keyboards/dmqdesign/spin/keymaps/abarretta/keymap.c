/* Copyright 2019-2020 DMQ Design
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

enum layers {
    _NUMPAD,
    _FROW,
    _MACRO
};

enum custom_keycodes {
    HELLO_WORLD = SAFE_RANGE,
};

//The below layers are intentionally empty in order to give a good starting point for how to configure multiple layers.
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [_NUMPAD] = LAYOUT(/* Base */
                KC_P7,   KC_P8, KC_P9, TO(_NUMPAD),
                KC_P4,   KC_P5, KC_P6, TO(_FROW),
                KC_P1,   KC_P2, KC_P3, TO(_MACRO),
                KC_BSPC, KC_P0, KC_ENTER
                ),

    [_FROW] = LAYOUT(/* Base */
                KC_F10, KC_F11, KC_F12, KC_TRNS,
                KC_F7,  KC_F8,  KC_F9,  KC_TRNS,
                KC_F4,  KC_F5,  KC_F6,  KC_TRNS,
                KC_F1,  KC_F2,  KC_F3
                ),

    [_MACRO] = LAYOUT(/* Base */
                KC_MPRV, KC_MPLY, KC_MNXT, KC_TRNS,
                KC_NUM,  RESET,   KC_NO,   KC_TRNS,
                KC_F16,  KC_F17,  KC_F18,  KC_TRNS,
                KC_F13,  KC_F14,  KC_F15
                )
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case HELLO_WORLD:
            if (record->event.pressed) {
                SEND_STRING("0111");
            }
            break;
    }

    return true;
};

#ifdef ENCODER_ENABLE
bool is_alt_tab_active = false;
uint16_t alt_tab_timer = 0;

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) { /* First encoder */
        switch (get_highest_layer(layer_state)) {     //break each encoder update into a switch statement for the current layer
            case _NUMPAD:
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
                break;
            case _FROW:
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
                break;
            case _MACRO:
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
                break;
        }
    } else if (index == 1) { /* Second encoder */
        switch (get_highest_layer(layer_state)) {
            case _NUMPAD:
                if (clockwise) {
                    tap_code(KC_PGDN);
                } else {
                    tap_code(KC_PGUP);
                }
                break;
            case _FROW:
                if (clockwise) {
                    tap_code(KC_PGDN);
                } else {
                    tap_code(KC_PGUP);
                }
                break;
            case _MACRO:
                if (clockwise) {
                    tap_code(KC_PGDN);
                } else {
                    tap_code(KC_PGUP);
                }
                break;
        }
    } else if (index == 2) { /* Third encoder */
        switch (get_highest_layer(layer_state)) {
            case _NUMPAD:
                if (clockwise) {
                    tap_code(KC_HOME);
                } else {
                    tap_code(KC_END);
                }
                break;
            case _FROW:
                if (clockwise) {
                    tap_code(KC_HOME);
                } else {
                    tap_code(KC_END);
                }
                break;
            case _MACRO:
                if (clockwise) {
                    tap_code(KC_HOME);
                } else {
                    tap_code(KC_END);
                }
                break;
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
#endif

layer_state_t layer_state_set_user(layer_state_t state) { //This will run every time the layer is updated
    switch (get_highest_layer(state)) {
        case _NUMPAD:
            setrgb(RGB_BLUE,&led[0]); //Set the top LED to white for the bottom layer
            setrgb(RGB_RED, &led[1]);
            setrgb(RGB_RED, &led[2]);
            break;
        case _FROW:
            setrgb(RGB_RED, &led[0]); //Set the middle LED to white for the middle layer
            setrgb(RGB_BLUE,&led[1]);
            setrgb(RGB_RED, &led[2]);
            break;
        case _MACRO:
            setrgb(RGB_RED, &led[0]);
            setrgb(RGB_RED, &led[1]);
            setrgb(RGB_BLUE,&led[2]); //Set the bottom LED to white for the top layer
            break;
    }
    rgblight_set();
    return state;
}

#ifdef OLED_ENABLE

static const char *ANIMATION_NAMES[] = {
	"unknown",
	"static",
	"breathing I",
	"breathing II",
	"breathing III",
	"breathing IV",
	"rainbow mood I",
	"rainbow mood II",
	"rainbow mood III",
	"rainbow swirl I",
	"rainbow swirl II",
	"rainbow swirl III",
	"rainbow swirl IV",
	"rainbow swirl V",
	"rainbow swirl VI",
	"snake I",
	"snake II",
	"snake III",
	"snake IV",
	"snake V",
	"snake VI",
	"knight I",
	"knight II",
	"knight III",
	"christmas",
	"static gradient I",
	"static gradient II",
	"static gradient III",
	"static gradient IV",
	"static gradient V",
	"static gradient VI",
	"static gradient VII",
	"static gradient VIII",
	"static gradient IX",
	"static gradient X",
	"rgb test",
	"alternating",
	"twinkle I",
	"twinkle II",
	"twinkle III",
	"twinkle IV",
	"twinkle V",
	"twinkle VI"
};

void rgblight_get_mode_name(uint8_t mode, size_t bufsize, char *buf) {
    snprintf(buf, bufsize, "%-25s", ANIMATION_NAMES[mode]);
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
#ifdef LEFT_HAND
    return OLED_ROTATION_180;
#else
    return OLED_ROTATION_0;
#endif
}

bool oled_task_user(void) {
    // Host Keyboard Layer Status
    oled_write_P(PSTR("Layer: "), false);

    switch (get_highest_layer(layer_state)) {
        case _NUMPAD:
            oled_write_P(PSTR("Numpad\n"), false);
            break;
        case _FROW:
            oled_write_P(PSTR("RGB\n"), false);
            break;
        case _MACRO:
            oled_write_P(PSTR("Macro\n"), false);
            break;
        default:
            // Or use the write_ln shortcut over adding '\n' to the end of your string
            oled_write_ln_P(PSTR("Undefined"), false);
    }

    static char rgb_mode_name[30];
    rgblight_get_mode_name(rgblight_get_mode(), sizeof(rgb_mode_name), rgb_mode_name);

    oled_write_P(PSTR("Mode: "), false);
    oled_write_ln(rgb_mode_name, false);
    return false;
}
#endif
