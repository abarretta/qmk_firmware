<<<<<<< HEAD
#include QMK_KEYBOARD_H

#ifdef PROTOCOL_LUFA
  #include "lufa.h"
  #include "split_util.h"
#endif
#ifdef SSD1306OLED
  #include "ssd1306.h"
#endif

extern uint8_t is_master;

enum layer_number {
  _CLMK_DH = 0,
  _QWERTY,
  _LOWER,
  _RAISE,
  _ADJUST,
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define HY_ESC HYPR_T(KC_ESC)
#define ADJ_BK LT(_ADJUST, KC_BSPC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
=======
/* Copyright 2020 Stephen J. Bush
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
#include "muppetjones.h"
#include "features/bongo_cat.h"
#define LAYOUT_wrapper(...) LAYOUT(__VA_ARGS__)

/*
 *  qmk compile -kb lily58/rev1 -km muppetjones
 */

// GACS (Lower)
#define HR_LBRC LCTL_T(KC_LBRC)
#define HR_RBRC LSFT_T(KC_RBRC)

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    // clang-format off
>>>>>>> a5e7390419a23c6db9cb62810f8ff1645d20b6a3

/* Colemak DH
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  | BADJ |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   F  |   P  |   B  |                    |   J  |   L  |   U  |   Y  |   ;  | Bksp |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Esc  |   A  |   R  |   S  |   T  |   G  |-------.    ,-------|   M  |   N  |   E  |   I  |   O  |  '   |
 * |------+------+------+------+------+------| Raise |    | Lower |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   D  |   V  |-------|    |-------|   K  |   H  |   ,  |   .  |   /  |Enter |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | Alt  | LGUI |LOWER | /Space  /       \Space \  |RAISE | Ctrl | RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
<<<<<<< HEAD
[_CLMK_DH] = LAYOUT( \
  KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                     KC_6,    KC_7,    KC_8,    KC_9,   KC_0,    KC_BSPC, \
  KC_TAB,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                     KC_J,    KC_L,    KC_U,    KC_Y,   KC_SCLN, KC_BSPC, \
  HY_ESC,  KC_A,    KC_R,    KC_S,    KC_T,    KC_G,                     KC_M,    KC_N,    KC_E,    KC_I,   KC_O,    KC_QUOT, \
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,   RAISE,   LOWER,   KC_K,    KC_H,    KC_COMM, KC_DOT, KC_SLSH, KC_SFTENT, \
                             KC_LALT, KC_LGUI, LOWER,  KC_SPC,  KC_SPC,  RAISE,   KC_LCTL, KC_RGUI \
=======
[_CLMK_DH] = LAYOUT_wrapper(
    KC_GRV,  KC_1,    KC_2,    KC_3,    KC_4,    KC_CAPS,                   __BLANK____________________________________, KC_BSPC,
    KC_CAPS, __COLEMAK_MOD_DH_L1________________________,                   __COLEMAK_MOD_DH_R1_W_QUOT_________________, KC_BSPC,
    HY_ESC,  __COLEMAK_MOD_DH_L2_W_GACS_________________,                   __COLEMAK_MOD_DH_R2_W_SCAG_________________, KC_QUOT,
    TD_LAYR, __COLEMAK_MOD_DH_L3_W_SFTV_________________, KC_CAPS, KC_TAB,  __COLEMAK_MOD_DH_R3________________________, SC_SENT,
                                XXXXXXX, XXXXXXX, HY_ESC, LOW_ENT, NAV_SPC, HY_BSPC, XXXXXXX, XXXXXXX
>>>>>>> a5e7390419a23c6db9cb62810f8ff1645d20b6a3
),

/* QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |  -   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LCTRL |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP| RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
<<<<<<< HEAD
 [_QWERTY] = LAYOUT( \
  KC_ESC,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_GRV, \
  KC_TAB,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_MINS, \
  KC_LCTRL, KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                     KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT, \
  KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, KC_LBRC,  KC_RBRC,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,  KC_RSFT, \
                        KC_LALT, KC_LGUI, MO(_LOWER), KC_SPC, KC_ENT, MO(_RAISE), KC_BSPC, KC_RGUI \
),
=======
[_QWERTY] = LAYOUT_wrapper(
    _______, __BLANK____________________________________,                   __BLANK____________________________________, _______,
    _______, __QWERTY_L1________________________________,                   __QWERTY_R1________________________________, _______,
    _______, __QWERTY_L2________________________________,                   __QWERTY_R2________________________________, _______,
    _______, __QWERTY_L3________________________________, _______, _______, __QWERTY_R3________________________________, _______,
                               _______, _______, _______, _______, _______, _______, _______, _______
),
[_MOUSE] = LAYOUT_wrapper(
    _______, __BLANK____________________________________,                   __BLANK____________________________________, _______,
    _______, __BLANK____________________________________,                   __BLANK____________________________________, _______,
    _______, __BLANK____________________________________,                   __BLANK____________________________________, _______,
    _______, __BLANK____________________________________, _______, _______, __BLANK____________________________________, _______,
                               KC_BTN1, __BLANK____________________________________, _______, KC_BTN2
),

>>>>>>> a5e7390419a23c6db9cb62810f8ff1645d20b6a3
/* LOWER
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |   `  |      | Mute | Vol- | Vol+ |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |   ~  |      |      |   `  |      |   (  |                    |   )  |   7  |   8  |   9  |   \  | Bksp |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
<<<<<<< HEAD
 * |      |   %  |   ^  |   _  |   -  |   {  |-------.    ,-------|   }  |   4  |   5  |   6  |   *  |   `   |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |   @  |   +  |   =  |   [  |-------|    |-------|   ]  |   1  |   2  |   3  |   |  |Enter |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      |      |LOWER | /Space  /       \Enter \  |   0  |   .  |   =  |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_LOWER] = LAYOUT( \
  KC_GRV , XXXXXXX, XXXXXXX, KC_BRID, KC_BRIU, XXXXXXX,                   XXXXXXX, XXXXXXX, KC_MUTE, KC_VOLD, KC_VOLU, _______, \
  KC_TILD, XXXXXXX, XXXXXXX, KC_GRV,  XXXXXXX, KC_LPRN,                   KC_RPRN, KC_7,    KC_8,    KC_9,    KC_BSLS, _______, \
  _______, KC_PERC, KC_CIRC, KC_UNDS, KC_MINS, KC_LCBR,                   KC_RCBR, KC_4,    KC_5,    KC_6,    KC_ASTR, KC_GRV, \
  _______, XXXXXXX, XXXXXXX, KC_PLUS, KC_EQL,  KC_LBRC, _______, _______, KC_RBRC, KC_1,    KC_2,    KC_3,    KC_PIPE, _______, \
                             _______, _______, _______, _______, KC_ENT,  KC_0,    KC_DOT,  KC_EQL \
),
/* RAISE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |MS_A_2|MS_W_L|MS_W_D|MS_W_U|MS_W_R|MS_W_U|                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |MS_A_1| MS_L | MS_D | MS_U | MS_R |MS_W_D|-------.    ,-------|      | Left | Down |  Up  |Right |      |
 * |------+------+------+------+------+------|MS_W_L |    |MS_W_R |------+------+------+------+------+------|
 * |MS_A_0|      |      |      |      |      |-------|    |-------|      |      |      |      |      |      |
=======
 * |      | GUI  | ALT  |   _  |   -  |   {  |-------.    ,-------|   }  |   4  |   5  |   6  |   *  |  `   |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |   +  |   =  |   [  |-------|    |-------|   ]  |   1  |   2  |   3  |   |  |Enter |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      |      |LOWER | /       /       \      \  |   0  |   .  |   =  |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
[_LOWER] = LAYOUT_wrapper(
    _______, __BLANK____________________________________,                   __BLANK____________________________________, _______,
    _______, __SYMBOLS_L1_______________________________,                   __NUMPAD_R1________________________________, _______,
    _______, __SYMBOLS_L2_______________________________,                   __NUMPAD_R2________________________________, KC_COMM,
    _______, __SYMBOLS_L3_______________________________, _______, _______, __NUMPAD_R3________________________________, KC_DOT,
                               _______, _______, _______, _______, KC_SPC,  KC_0,    KC_DOT,  _______
),
/* RAISE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |MS_A_0|MS_A_1|MS_A_2|      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |MS_W_U|                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      | GUI  | ALT  | CTL  | SFT  |MS_W_D|-------.    ,-------|      | Left | Down |  Up  |Right |      |
 * |------+------+------+------+------+------|MS_W_L |    |MS_W_R |------+------+------+------+------+------|
 * |      | MS_L | MS_D | MS_U | MS_R |      |-------|    |-------|      |MS_W_L|MS_W_D|MS_W_U|MS_W_R|      |
>>>>>>> a5e7390419a23c6db9cb62810f8ff1645d20b6a3
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      |      | MS_2 | / MS_1  /       \      \  |RAISE |      |      |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 // */

<<<<<<< HEAD
[_RAISE] = LAYOUT( \
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  _______, \
  _______, KC_WH_L, KC_WH_D, KC_WH_U, KC_WH_R, KC_WH_U,                     XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  _______, \
  _______, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R, KC_WH_D,                     XXXXXXX, KC_LEFT, KC_DOWN, KC_UP,   KC_RIGHT, _______, \
  _______, KC_ACL0, KC_ACL1, KC_ACL2, XXXXXXX, XXXXXXX,  KC_WH_L, KC_WH_R,  XXXXXXX, KC_HOME, KC_END,  KC_PGUP, KC_PGDN,  _______, \
                             _______, _______, KC_BTN2,  KC_BTN1, _______,  _______, _______, _______ \
),
=======
[_RAISE] = LAYOUT_wrapper(
    _______, __BLANK____________________________________,                   __BLANK____________________________________, _______,
    _______, __SYMBOLS_L1_______________________________,                   __NAV_R1___________________________________, _______,
    _______, __SYMBOLS_L2_______________________________,                   __NAV_R2___________________________________, _______,
    _______, __SYMBOLS_L3_______________________________, _______, _______, __NAV_R3___________________________________, _______,
                               _______, _______, _______, _______, _______, _______, _______, _______
),
[_NAV] = LAYOUT_wrapper(
    _______, __BLANK____________________________________,                   __BLANK____________________________________, _______,
    _______, __VIM_L1___________________________________,                   __NAV_R1___________________________________, _______,
    _______, __BLANK_W_GACS_____________________________,                   __NAV_R2___________________________________, _______,
    _______, __BLANK____________________________________, _______, _______, __NAV_R3___________________________________, _______,
                               _______, _______, _______, _______, _______, _______, _______, _______
),

>>>>>>> a5e7390419a23c6db9cb62810f8ff1645d20b6a3
/* ADJUST
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      | Reset|      |      |      |      |                    | Reset|      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|      |      |RGB ON| HUE+ | SAT+ | VAL+ |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      | MODE | HUE- | SAT- | VAL- |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LAlt | LGUI |LOWER | /Space  /       \Enter \  |RAISE |BackSP| RGUI |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
<<<<<<< HEAD
  [_ADJUST] = LAYOUT( \
  XXXXXXX, RESET,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   RESET,   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, _CLMK_DH,_QWERTY, XXXXXXX, XXXXXXX, XXXXXXX, \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,\
                             _______, _______, _______, _______, _______,  _______, _______, _______ \
  )
};

// Setting ADJUST layer RGB back to default
// void update_tri_layer_RGB(uint8_t layer1, uint8_t layer2, uint8_t layer3) {
//   if (IS_LAYER_ON(layer1) && IS_LAYER_ON(layer2)) {
//     layer_on(layer3);
//   } else {
//     layer_off(layer3);
//   }
// }

//SSD1306 OLED update loop, make sure to enable OLED_DRIVER_ENABLE=yes in rules.mk
#ifdef OLED_DRIVER_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master())
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  return rotation;
}

// When you add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state(void);
const char *read_logo(void);
const char *wpm_state(void);
void render_bongo_cat(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);

// const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);

void oled_task_user(void) {
  if (is_keyboard_master()) {
    // If you want to change the display of OLED, you need to change here
    oled_write_ln(read_layer_state(), false);
    oled_write_ln(read_keylog(), false);
    oled_write_ln(read_keylogs(), false);
    //oled_write_ln(read_mode_icon(keymap_config.swap_lalt_lgui), false);
    //oled_write_ln(read_host_led_state(), false);
    //oled_write_ln(read_timelog(), false);
  } else {
    render_bongo_cat();
    oled_set_cursor(0,6);
    oled_write(wpm_state(), false);
    // oled_write(read_logo(), false);
  }
}
#endif // OLED_DRIVER_ENABLE

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  if (record->event.pressed) {
#ifdef OLED_DRIVER_ENABLE
    set_keylog(keycode, record);
#endif
    // set_timelog();
  }
  return true;
}

=======
[_ADJUST] = LAYOUT_wrapper(
    _______, __BLANK____________________________________,                   _______, CLMK_DH, QWERTY,  _______, _______, _______,
    QK_BOOT, __ADJUST_L1________________________________,                   __MEDIA_R1_________________________________, _______,
    _______, __ADJUST_L2________________________________,                   __MEDIA_R2_________________________________, _______,
    _______, __ADJUST_L3________________________________, _______, _______, __MEDIA_R3_________________________________, _______,
                               _______, _______, _______, _______, _______, _______, _______, _______
)

    // clang-format on
};

// SSD1306 OLED update loop, make sure to enable OLED_DRIVER_ENABLE=yes in rules.mk
#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (!is_keyboard_master()) return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
    return rotation;
}

// When you add source files to SRC in rules.mk, you can use functions.
const char *read_layer_state_user(void);
void        set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);

char layer_state_str[24];

const char *read_layer_state_user(void) {
    // NOTE;
    switch (get_highest_layer(layer_state)) {
        case _CLMK_DH:
            return "Layer: Colemak";
            break;
        case _QWERTY:
            return "Layer: QWERTY ";
            break;
        case _MOUSE:
            return "Layer: Mouse  ";
            break;
        case _LOWER:
            return "Layer: Lower  ";
            break;
        case _RAISE:
            return "Layer: Raise  ";
            break;
        case _NAV:
            return "Layer: Nav    ";
            break;
        case _ADJUST:
            return "Layer: Adjust ";
            break;
        default:
            break;
    }

    char *layer_state_str = "Layer: Und-  ";
    layer_state_str[10]   = '0' + layer_state % 10;
    return layer_state_str;
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        // If you want to change the display of OLED, you need to change here
        oled_write_ln(read_layer_state_user(), false);
        oled_write_ln(read_keylog(), false);
        oled_write_ln(read_keylogs(), false);
    } else {
        render_bongo_cat();
        oled_set_cursor(0, 6);
        oled_write_P(PSTR("WPM:  "), false);
        oled_write(get_u8_str(get_current_wpm(), ' '), false);
    }
    return false;
}
#endif  // OLED_DRIVER_ENABLE

bool process_record_keymap(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
#ifdef OLED_ENABLE
        set_keylog(keycode, record);
#endif
        // set_timelog();
    }

    // Regular user keycode case statement
    switch (keycode) {
        default:
            return true;
    }

    return true;
}
>>>>>>> a5e7390419a23c6db9cb62810f8ff1645d20b6a3
