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

// Defines names for use in layer keycodes and the keymap

enum layer_names {
  _BASE,
  _FROW,
  _FN1
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base */
    [_BASE] = LAYOUT(
                    KC_MPRV, KC_MPLY, KC_MNXT,  KC_MUTE,
				    KC_NLCK, KC_PSLS, KC_PAST,  KC_PMNS,
                    KC_P7,   KC_P8,   KC_P9,    KC_PPLS,
        TG(_FROW),  KC_P4,   KC_P5,   KC_P6,    KC_PPLS,
        KC_F13,     KC_P1,   KC_P2,   KC_P3,    KC_PENT,
        KC_F14,     KC_P0,   KC_P0,   KC_PDOT,  KC_PENT,

                  _______, _______, _______

    ),
    [_FROW] = LAYOUT(
                    KC_TRNS,  KC_TRNS,  KC_TRNS,  KC_TRNS,
                    KC_F10,   KC_F11,   KC_F12,   KC_TRNS,
                    KC_F7,    KC_F8,    KC_F9,    KC_TRNS,
        KC_TRNS,    KC_F4,    KC_F5,    KC_F6,    KC_TRNS,
        KC_TRNS,    KC_F1,    KC_F2,    KC_F3,    MO(_FN1),
        KC_TRNS,    KC_TRNS,  KC_TRNS,  KC_TRNS,  MO(_FN1),

                 _______, _______, _______

    ),
    [_FN1] = LAYOUT(
                 KC_TRNS,  KC_TRNS, KC_TRNS, RESET,
                 KC_TRNS,  KC_TRNS, KC_TRNS, KC_TRNS,
                 RGB_HUD,  RGB_SPI, RGB_HUI, KC_TRNS,
        KC_TRNS, RGB_RMOD, RGB_TOG, RGB_MOD, KC_TRNS,
        KC_TRNS, RGB_VAD,  RGB_SPD, RGB_VAI, KC_TRNS,
        KC_TRNS, RGB_SAD,  RGB_SAD, RGB_SAI, KC_TRNS,

                 _______, _______, _______

    ),
};

#ifdef ENCODER_ENABLE

bool is_alt_tab_active = false;
uint16_t alt_tab_timer = 0;

bool encoder_update_user(uint8_t index, bool clockwise) {
    switch (index) {
        case 0:
        /*this is backwards*/
            if (clockwise) {
                tap_code(KC_VOLD);
            } else {
                tap_code(KC_VOLU);
            }
        break;
		case 1:
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

#ifdef OLED_ENABLE
	oled_rotation_t oled_init_user(oled_rotation_t rotation) {
		return OLED_ROTATION_270;       // flips the display 270 degrees
	}

	static void render_logo(void) {     // Render MechWild "MW" Logo
		static const char PROGMEM logo_1[] = {0x8A, 0x8B, 0x8C, 0x8D, 0x00};
		static const char PROGMEM logo_2[] = {0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0x00};
		static const char PROGMEM logo_3[] = {0xCA, 0xCB, 0xCC, 0xCD, 0x00};
		static const char PROGMEM logo_4[] = {0x20, 0x8E, 0x8F, 0x90, 0x00};
		oled_set_cursor(0,0);
		oled_write_P(logo_1, false);
		oled_set_cursor(0,1);
		oled_write_P(logo_2, false);
		oled_set_cursor(0,2);
		oled_write_P(logo_3, false);
		oled_set_cursor(0,3);
		oled_write_P(logo_4, false);
	}

	bool oled_task_user(void) {
		render_logo();
		oled_set_cursor(0,6);

		oled_write_ln_P(PSTR("Layer"), false);

    switch (get_highest_layer(layer_state)) {
        case _BASE:
            oled_write_ln_P(PSTR("Base"), false);
            break;
        case _FROW:
            oled_write_ln_P(PSTR("FROW"), false);
            break;
        case _FN1:
            oled_write_ln_P(PSTR("FN 1"), false);
            break;
        default:
            oled_write_ln_P(PSTR("Undef"), false);
    }
	oled_write_ln_P(PSTR(""), false);
    // Host Keyboard LED Status
    led_t led_state = host_keyboard_led_state();
    oled_write_ln_P(led_state.num_lock ? PSTR("NUM ") : PSTR("    "), false);
    oled_write_ln_P(led_state.caps_lock ? PSTR("CAP ") : PSTR("    "), false);
    oled_write_ln_P(led_state.scroll_lock ? PSTR("SCR ") : PSTR("    "), false);
    return false;
	}
#endif
