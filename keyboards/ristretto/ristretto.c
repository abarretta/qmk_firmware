/* Copyright 2021 Brandon Lewis
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

#include "ristretto.h"

enum layers {
	_BASE,
	_NUM,
	_MIA,
	_ADJUST
};

bool is_alt_tab_active = false;
uint16_t alt_tab_timer = 0;

bool encoder_update_kb(uint8_t index, bool clockwise) {

    /*if (!encoder_update_user(index, clockwise)) { return false; }
	if(index == 0) {
		if (clockwise) {
			tap_code(KC_VOLD);
		} else {
			tap_code(KC_VOLU);
			}
		}
        */
    if (!is_alt_tab_active) {
        is_alt_tab_active = true;
        register_code(KC_LALT);
    }
    if (!clockwise) {
        alt_tab_timer = timer_read();
        tap_code16(KC_TAB);
    } else {
        alt_tab_timer = timer_read();
        tap_code16(S(KC_TAB));
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

#ifdef OLED_DRIVER_ENABLE
const char *wpm_state(void);
void set_keylog(uint16_t keycode, keyrecord_t *recod);
const char *read_keylog(void);
const char *read_keylogs(void);

// oled_rotation_t oled_init_user(oled_rotation_t rotation) {
// 	return OLED_ROTATION_270;
// }

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
#ifdef OLED_DRIVER_ENABLE
    set_keylog(keycode, record);
#endif
    // set_timelog();
  }
  return true;
}

void oled_task_user(void) {
    led_t led_state = host_keyboard_led_state();
    oled_write_ln_P(led_state.caps_lock ? PSTR("CAPS") : PSTR("    "), false);
    oled_write_ln(wpm_state(), false);
    oled_write_ln(" ", false);
    oled_write_ln(read_keylogs(), false);
}
// __attribute__((weak)) void oled_task_user(void) {
// 	oled_write_P(PSTR("\n\n"), false);
// 	switch (get_highest_layer(layer_state)) {
// 		case _BASE:
// 			oled_write_P(PSTR("BASE\n"), false);
// 			break;
// 		case _NUM:
// 			oled_write_P(PSTR("NUM\n"), false);
// 			break;
// 		case _MIA:
// 			oled_write_P(PSTR("MIA\n"), false);
// 			break;
// 		case _ADJUST:
// 			oled_write_P(PSTR("ADJ\n"), false);
// 			break;
// 	}
//     oled_write_ln_P(PSTR(""), false);
//     // Host Keyboard LED Status
//     led_t led_state = host_keyboard_led_state();
//     oled_write_ln_P(led_state.caps_lock ? PSTR("CAP ") : PSTR("    "), false);
// }

#endif
