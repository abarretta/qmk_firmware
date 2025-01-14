// Copyright 2022 Aidan Smith (@Aidan-OS)
// SPDX-License-Identifier: GPL-2.0-or-later
#include "quantum.h"

enum keyboard_layers {
	_MAIN,
	_RIGHT,
	_LEFT,
	_TAB,
};

#ifdef OLED_ENABLE
//static void render_logo(void) {
//    static const char PROGMEM raw_logo[] = {
//        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,192,224,224,240,240,248,248,248,252,252,252,252,252,252,252,252,252,252,252,252,252,252,252,252,252,252,252,248,248,248,240,240,224,224,192,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,224,224,224,192,  0,  0,  0,  0, 96,240,240, 96,  0,  0,  0,  0,  0,  0,240,240,240,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
//        0,  0,  0,  0,  0,  0,  0,128,192,224,240,248,252,254,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255, 15,  7,  7,  7, 15,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,254,252,248,240,224,192,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,240,254,255,127,115,127,127,255,252,224,  0,255,255,255,254, 48,254,254,255,199,135,255,255,255,  0,224,247,255,191,191,255,255,254,  0,254,255,255,255,  7,255,255,254,240,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 
//        0,  0,  0,  0,192,248,254,255,255,255,255,255,255,255,255,255,127, 31, 15,  7,  3,  1,192,224,240,251,255,255,255,255,255,  0,  0,  0,  0,  0,255,255,255,255,255,255,241,225,192,  1,  3,  7, 15, 31,127,255,255,255,255,255,255,255,255,255,254,248,192,  0,  0,  0,  0,  0,  0,  0,  0,  0,  3,  3,  3,128,128,128,128,  0,  1,  3,  3,  1,  1,  3,  3,  1,  0,  0,  1,  1,  3,  3,  3,  3,129,192,128,  1,  3,  3,  3,  3,  1,  1,  0,129,195,195,193,  0,  1,  3,  3,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 
//        0,  0,  0,  0,255,255,255,255,255,255,255,255,255,255,255,  7,  0,  0,  0,240,252,255,255,255,255,255,255,255,255,255,255,255,254,252,254,255,255,255,255,255,255,255,255,255,255,255,252,240,  0,  0,  0,  7,255,255,255,255,255,255,255,255,255,255,255,  0,  0,  0,  0,  0,  0,  0,  0,  0, 12, 63, 63,127,123,243,247,231,193,  0,252,252,252, 28, 60,252,252,252, 28,252,252,248,224,  0,255,255,255,  0,255,255,255,255, 28, 28,  0,255,255,255,255, 28,252,252,248,240,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 
//        0,  0,  0,  0,255,255,255,255,255,255,255,255,255,255,255,240,  0,  0,  0,  7, 31,127,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,255,127, 31,  7,  0,  0,  0,240,255,255,255,255,255,255,255,255,255,255,255,  0,  0,  0,  0,  0,  0,  0,  0,  0,  6,  7, 15, 15, 14, 15,  7,  7,  3,  0, 15, 15, 15,  0,  0, 15, 15, 15,  0,  7, 15, 15,  7,  0, 15, 15, 15,  0,  1,  7,  7, 15, 14, 14,  6,  7,  7,  7,  7,  0,  7,  7,  7,  7,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 
//        0,  0,  0,  0,  1, 15, 63,255,255,255,255,255,255,255,255,255,255,254,248,240,224,192,128,129,  3,  7, 15, 15, 31, 31, 31, 63, 63, 63, 63, 63, 31, 31, 31, 15, 15,  7,  3,129,128,192,224,240,248,254,255,255,255,255,255,255,255,255,255,255, 63, 15,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,192,224,224,224,252,254,254,  0,  0,128,192,224,224,224,224,192,128, 96,224,224,224,  0,  0,224,224,224,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 
//        0,  0,  0,  0,  0,  0,  0,  0,  1,  3,  7, 15, 31, 63,127,255,255,255,255,255,255,255,255,255,255,254,254,254,254,254,252,252,252,252,252,252,252,254,254,254,254,254,255,255,255,255,255,255,255,255,255,255,127, 63, 31, 15,  7,  3,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 56,120,120, 48, 31, 63, 63,120,112,127,127, 63,  0,  6, 31, 63, 63,127,119,119, 63, 55,  0,  3, 15, 63,127,127, 63, 15,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 
//        0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  1,  3,  3,  7,  7, 15, 15, 15, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 31, 15, 15, 15,  7,  7,  3,  3,  1,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,
//    };
//    oled_write_raw_P(raw_logo, sizeof(raw_logo));
//}

static void render_mochi(void)
{
	static const char PROGMEM mochi_logo[] = {
        0,  0,  0,  0,  0,224,240,240,240,192,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,224,240,240,240,224,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,252,252,252,252,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,120,248,248,112,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,128,192,224,240,240,240,224,  0,  0,  0,  0,  0,  0,128,192,224,240,240,240,240,240,240,224,224,192,  0,  0,  0,  0,  0,
        0,  0,  0,  0,224,255,255,255, 15, 63,255,254,248,224,  0,  0,  0,  0,224,248,254,255, 31, 31,255,255,255,128,  0,  0,  0,128,224,240,248,252, 60, 28, 28, 30, 28, 60,124,248,248,240,192,  0,  0,  0,128,224,240,248,252, 60, 60, 28, 30, 28, 28, 60, 28,  0,  0,  0,255,255,255,255, 28, 28, 28, 28, 60,124,252,248,240,192,  0,  0,  0,  0,252,252,252,252,  0,  0,  0,  0,  0,192,224,248,252, 63, 31,  7,  3,255,255,255,255,  0,  0,  0,  0,224,254,255,255, 15,  1,  0,  0,  0,  0,  1, 15,255,255,255,248,  0,  0,  0, 
        0,  0,  0,  0,255,255,255,255,  0,  0,  0,  3, 15, 63,255,252,252,255, 63, 15,  3,  0,  0,  0,255,255,255,255,  0,  0,  0, 63,255,255,255,224,128,  0,  0,  0,  0,128,192,255,255,255,127,  4,  0,  0, 63,255,255,255,224,128,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,255,255,255,255,  0,  0,  0,  0,  0,  0,255,255,255,255,  0,  0,  0,  0,255,255,255,255,  0,  0,  0, 60, 63, 63, 63, 61, 60, 60, 60, 60, 60,255,255,255,255, 60, 60,  0,  0,  7,127,255,255,248,128,  0,  0,  0,  0,128,240,255,255,127, 31,  0,  0,  0, 
        0,  0,  0,  0, 15, 15, 15,  7,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  7, 15, 15, 15,  0,  0,  0,  0,  0,  1,  3,  7,  7, 15, 15, 15, 15, 15,  7,  7,  3,  1,  0,  0,  0,  0,  0,  0,  3,  3,  7,  7, 15, 15, 15, 15, 15, 15,  7,  0,  0,  0, 15, 15, 15,  7,  0,  0,  0,  0,  0,  0,  7, 15, 15, 15,  0,  0,  0,  0, 15, 15, 15,  7,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0,  0, 15, 15, 15,  7,  0,  0,  0,  0,  0,  0,  1,  3,  7,  7, 15, 15, 15, 15,  7,  7,  3,  1,  0,  0,  0,  0,  0,
    };
	
	oled_write_raw_P(mochi_logo, sizeof(mochi_logo));
}


oled_rotation_t oled_init_kb(oled_rotation_t rotation) {
       return OLED_ROTATION_180;  // flips the display 180 degrees
}
bool oled_task_kb(void) {
    if (!oled_task_user()) {
        return false;
    }
	render_mochi();
	oled_set_cursor(0, 4);
	oled_write_P(PSTR("Layer: "), false);
	
	switch(get_highest_layer(layer_state))
	{
		case _MAIN:
			oled_write_ln_P(PSTR("Main"), false);
			break;
		case _LEFT:
			oled_write_ln_P(PSTR("Left"), false);
			break;
		case _RIGHT:
			oled_write_ln_P(PSTR("Right"), false);
			break;
		case _TAB:
			oled_write_ln_P(PSTR("Tab"), false);
			break;
	}
	
	//render_logo();
	return(true);
}
#endif

#ifdef ENCODER_ENABLE
bool encoder_update_kb(uint8_t index, bool clockwise) {
   if (!encoder_update_user(index, clockwise)) {
       return false;
   }
   // Volume control
   if (clockwise) {
   	tap_code(KC_VOLU);
   } else {
   	tap_code(KC_VOLD);
   }
   return true;
}
#endif