#include QMK_KEYBOARD_H

extern rgblight_config_t rgblight_config;
extern keymap_config_t keymap_config;

#define _BASE 0
#define _FROW 1
#define _ADJ 2

enum custom_keycodes {
    BASE = SAFE_RANGE,
    FROW,
    ADJ,
};

#define BASE TO(0)
#define FROW TO(1)
#define ADJ TO(2)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

    /* BASE */
	[_BASE]= LAYOUT(
	    KC_PSLS, KC_PAST, KC_PMNS, FROW,
		KC_P7, KC_P8, KC_P9, KC_NO,
		KC_P4, KC_P5, KC_P6, KC_PPLS,
		KC_P1, KC_P2, KC_P3, KC_NO,
		KC_P0, KC_PDOT, KC_PDOT, KC_PENT),

    /* FROW */
    [_FROW]=LAYOUT(
        KC_F10, KC_F11, KC_F12, ADJ,
		KC_F7, KC_F8, KC_F9, KC_NO,
		KC_F4, KC_F5, KC_F6, KC_NO,
		KC_F1, KC_F2, KC_F3, KC_NO,
		KC_NO, KC_NO, KC_NO, KC_NO),

    /* ADJ */
	[_ADJ]= LAYOUT(
		RGB_TOG, RGB_MOD, KC_TRNS, BASE,
        RGB_HUI, RGB_SAI, RGB_VAI, RESET,
        RGB_HUD, RGB_SAD, RGB_VAD, RESET,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
		KC_TRNS, KC_TRNS, KC_TRNS, KC_NLCK)
};

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

void matrix_init_user(void) {
  rgblight_enable();
}

void matrix_scan_user(void) {
  #ifdef RGBLIGHT_ENABLE

  static uint8_t old_layer = 255;
  uint8_t new_layer = biton32(layer_state);

  // Color of the Icons. https://docs.qmk.fm/#/feature_rgblight?id=colors
  if (old_layer != new_layer) {
    switch (new_layer) {
    case _BASE:
        rgblight_sethsv(201, 255, 255); //purple
        break;
    case _FROW:
        rgblight_sethsv(169, 255, 255); //blue
        break;
    case _ADJ:
        rgblight_sethsv(85, 255, 255); //green
        break;
    default: //  for any other layers, or the default layer
        rgblight_sethsv(201, 255, 255); //purple
        break;
    }
    old_layer = new_layer;
  }
  #endif
}







