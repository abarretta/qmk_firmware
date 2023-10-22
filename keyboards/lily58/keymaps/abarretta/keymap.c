#include QMK_KEYBOARD_H

#ifdef PROTOCOL_LUFA
 #include "lufa.h"
 #include "split_util.h"
#endif
#ifdef SSD1306OLED
 #include "ssd1306.h"
#endif

enum layer_number {
  _MODDH = 0,
  _COLEMAK,
  _QWERTY,
  _LOWER,
  _RAISE,
  _ADJUST,
};

#define LOWER MO(_LOWER)
#define RAISE MO(_RAISE)
#define ADJUST MO(_ADJUST)
#define COLEMAK _COLEMAK
#define QWERTY _QWERTY

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* ModDH
 * .-----------------------------------------.                    .-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  Del |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |   `  |   Q  |   W  |   F  |   P  |   B  |                    |   J  |   L  |   U  |   Y  |   ;  |BackSP|
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |   \  |   A  |   R  |   S  |   T  |   G  |-------.    ,-------|   M  |   N  |   E  |   I  |   O  |  '   |
 * |------+------+------+------+------+------|  LOW  |    | RAISE |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   D  |   V  |-------|    |-------|   K  |   H  |   ,  |   .  |   /  |RShift|
 * '-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LCTRL| LALT |Space | /  TAB  /       \BackSP\  |Enter | Caps | LGUI |
 *                   '----------------------------'          '------''--------------------'
 */

 [_MODDH] = LAYOUT( \
  KC_ESC,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,       KC_DEL, \
  KC_GRV,   KC_Q,   KC_W,    KC_F,    KC_P,    KC_B,                     KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN,    KC_BSPC, \
  KC_BSLS,  KC_A,   KC_R,    KC_S,    KC_T,    KC_G,                     KC_M,    KC_N,    KC_E,    KC_I,    KC_O,       KC_QUOT, \
  KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_D,    KC_V, LOWER,  RAISE,  KC_K,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH,  KC_RSFT, \
                        KC_LCTL, KC_LALT, KC_SPC, KC_TAB, KC_BSPC, KC_ENT, KC_CAPS, KC_LGUI \
),

/* COLEMAK
 * .-----------------------------------------.                    .-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  Del |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |   `  |   Q  |   W  |   F  |   P  |   B  |                    |   J  |   L  |   U  |   Y  |   ;  |BackSP|
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |   \  |   A  |   R  |   S  |   T  |   G  |-------.    ,-------|   M  |   N  |   E  |   I  |   O  |  '   |
 * |------+------+------+------+------+------|  LOW  |    | RAISE |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   D  |   V  |-------|    |-------|   K  |   H  |   ,  |   .  |   /  |RShift|
 * '-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LCTRL| LALT |Space | /  TAB  /       \BackSP\  |Enter | Caps | LGUI |
 *                   '----------------------------'          '------''--------------------'
 */

 [_COLEMAK] = LAYOUT( \
  KC_ESC,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,       KC_DEL, \
  KC_GRV,   KC_Q,   KC_W,    KC_F,    KC_P,    KC_G,                     KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN,    KC_BSPC, \
  KC_BSLS,  KC_A,   KC_R,    KC_S,    KC_T,    KC_D,                     KC_H,    KC_N,    KC_E,    KC_I,    KC_O,       KC_QUOT, \
  KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, LOWER,  RAISE,  KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,  KC_RSFT, \
                        KC_LCTL, KC_LALT, KC_SPC, KC_TAB, KC_BSPC, KC_ENT, KC_CAPS, KC_LGUI \
),

/* QWERTY
 * .-----------------------------------------.                    .-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  Del |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |   `  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  |BackSP|
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |   \  |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------|  LOW  |    | RAISE |------+------+------+------+------+------|
 * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
 * '-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LCTRL| LALT |Space | /  TAB  /       \BackSP\  |Enter | Caps | LGUI |
 *                   '----------------------------'          '------''--------------------'
 */

 [_QWERTY] = LAYOUT( \
  KC_ESC,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                     KC_6,    KC_7,    KC_8,    KC_9,    KC_0,       KC_DEL, \
  KC_GRV,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                     KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSPC, \
  KC_BSLS,  KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                     KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN,       KC_QUOT, \
  KC_LSFT,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B, LOWER,  RAISE,  KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,  KC_RSFT, \
                        KC_LCTL, KC_LALT, KC_SPC, KC_TAB, KC_BSPC, KC_ENT, KC_CAPS, KC_LGUI \
),

/* LOWER
 * .-----------------------------------------.                    .-----------------------------------------.
 * |  ESC |  1   |   2  |  3   |   4  |  5   |                    |   6  |   7  |  8   |  9   |  0   |  Del |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  `   |  Q   |   W  |   E  |   R  |  T   |                    |   Y  |   U  |  I   |  O   |  P   |BackSP|
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  \   |  A   |   S  |  D   |  F   |  G   |-------.    ,-------|   H  |   J  |   K  |  L   |  ;   |   '  |
 * |------+------+------+------+------+------|  LOW  |    | RAISE |------+------+------+------+------+------|
 * |LShift|  Z   |   X  |  C   |  V   |  B   |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
 * '-----------------------------------------/      /      \      \-----------------------------------------'
 *                   | LCTRL| LALT |Space | / Tab  /        \Enter \  |Enter | Caps | RGUI |
 *                   '--------------------''------'          '------''---------------------'
 */
 [_LOWER] = LAYOUT( \
  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,                      KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,\
  KC_TILD,  KC_EXLM,  KC_AT,    KC_HASH,  KC_DLR,   KC_PERC,                    KC_CIRC,  KC_AMPR,  KC_ASTR,  KC_LPRN,  KC_RPRN,  KC_BSPC,\
  KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,                      KC_NO,    KC_UNDS,  KC_PLUS,  KC_LCBR,  KC_RCBR,  KC_PIPE,\
  KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,  KC_TRNS,   ADJUST, KC_NO,    KC_NO,    KC_NO,    KC_HOME,  KC_END,   KC_NO,\
                          KC_MPRV,  KC_MPLY,  KC_MNXT,      XXXXXXX,    KC_LEFT,    KC_DOWN,  KC_UP,  KC_RGHT\

),
/* RAISE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |                    |  F7  |  F8  |  F9  | F10  | F11  | F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |   -  |   _  |   =  |   +  |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |   [  |   ]  |   {  |   }  |      |-------.    ,-------|      |      |      |      |      |      |
 * |------+------+------+------+------+------| Adjust|    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      |      |      | /       /       \      \  |      |      |      |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */

[_RAISE] = LAYOUT( \
  KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,                      KC_F7,    KC_F8,    KC_F9,    KC_F10,   KC_F11,   KC_F12,\
  KC_TILD,  KC_EXLM,  KC_AT,    KC_HASH,  KC_DLR,   KC_PERC,                    KC_CIRC,  KC_AMPR,  KC_ASTR,  KC_LPRN,  KC_RPRN,  KC_BSPC,\
  KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,                      KC_NO,    KC_MINS,  KC_EQL,   KC_LBRC,  KC_RBRC,  KC_BSLS,\
  KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,    KC_NO,  ADJUST,   KC_TRNS,  KC_NO,    KC_NO,    KC_NO,    KC_PGUP,  KC_PGDN,  KC_NO,\
                          KC_LEFT,    KC_DOWN,  KC_UP,      KC_RGHT,  XXXXXXX,      KC_MPRV,  KC_MPLY,  KC_MNXT\
),
/* ADJUST
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
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
  [_ADJUST] = LAYOUT( \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, \
  XXXXXXX, XXXXXXX, XXXXXXX, DEBUG, RESET, XXXXXXX,                   XXXXXXX, DF(_MODDH), DF(_QWERTY), DF(_COLEMAK), XXXXXXX, XXXXXXX, \
  XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,\
                             XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,  XXXXXXX, XXXXXXX, XXXXXXX \
  )
};

//SSD1306 OLED update loop, make sure to enable OLED_DRIVER_ENABLE=yes in rules.mk
#ifdef OLED_DRIVER_ENABLE

/*
oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (is_keyboard_master())
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  return rotation;
}
*/

// When you add source files to SRC in rules.mk, you can use functions.
//const char *read_layer_state(void);
const char *wpm_state(void);
void render_caktus(void);
void set_keylog(uint16_t keycode, keyrecord_t *record);
const char *read_keylog(void);
const char *read_keylogs(void);


/*
static void render_cactus(void){
  static const char PROGMEM cactaur[] = {
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x60, 0x60, 0x60, 0xe0, 0xe0, 0xb0, 0xb0, 0xf0, 0x50, 0xd0, 0xd0, 0xf0,
0xf8, 0xb8, 0xb8, 0x38, 0x28, 0x28, 0x38, 0x38, 0x18, 0x18, 0x18, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0x80, 0xc0, 0xc0, 0xc0, 0xc0, 0xc0,
0xc0, 0xc0, 0x40, 0x40, 0xc0, 0xc0, 0xc0, 0xc0, 0x80, 0x80, 0x80, 0xa0, 0xa0, 0xa0, 0x10, 0x10,
0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x60, 0xe0, 0xe0, 0xe0, 0xe0, 0xa0, 0xb0, 0xf0, 0xf0, 0xf0, 0xf0, 0xf0,
0x50, 0x58, 0x78, 0x78, 0x78, 0x78, 0x78, 0x28, 0x2c, 0x3c, 0x3c, 0x7c, 0x6c, 0xfc, 0xfc, 0xdc,
0xfc, 0xb8, 0xf8, 0xf8, 0x70, 0x30, 0xa0, 0xe0, 0xc0, 0xc0, 0xe0, 0x60, 0x60, 0x60, 0xe0, 0xe0,
0xf0, 0xf0, 0xb0, 0xb0, 0xf0, 0xf0, 0xf0, 0xf8, 0xf8, 0xd9, 0xd9, 0xfb, 0xfb, 0x7b, 0x7e, 0xff,
0xad, 0xad, 0x3d, 0x3d, 0xbd, 0xbe, 0x9e, 0x96, 0x96, 0x9e, 0x9e, 0xde, 0xdf, 0xcb, 0xcb, 0xcb,
0x4f, 0x4f, 0xef, 0xef, 0xfd, 0xfd, 0xf9, 0xb9, 0xb1, 0xf1, 0xf1, 0xfc, 0xcc, 0xcf, 0xcf, 0xcb,
0xcb, 0x4f, 0x4f, 0x7f, 0x7f, 0x6f, 0x6d, 0x7d, 0x3f, 0x3f, 0x3f, 0x3f, 0x37, 0x36, 0x1e, 0x1f,
0x1f, 0x0e, 0x04, 0x00, 0x00, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x40, 0xc0, 0xc0, 0xe0, 0xe0, 0xe0, 0xa0,
0x21, 0xa1, 0xe3, 0xf3, 0xf7, 0xf6, 0xde, 0xcf, 0xeb, 0xeb, 0x7f, 0x7f, 0x7f, 0x6f, 0x6f, 0x6d,
0x7d, 0x3f, 0x3f, 0x3f, 0x37, 0x37, 0x36, 0x1e, 0x1f, 0x1f, 0x1f, 0x1b, 0x1b, 0x1b, 0x1f, 0x0f,
0x0f, 0x0f, 0x0d, 0x0d, 0x0d, 0x0f, 0x07, 0x07, 0x07, 0x06, 0x06, 0xc6, 0xc7, 0x43, 0x43, 0xc3,
0xc7, 0xe5, 0xed, 0xed, 0xaf, 0xbb, 0xff, 0xf7, 0x77, 0x7f, 0x6c, 0x5c, 0x5c, 0x78, 0x78, 0x30,
0x30, 0x20, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01, 0x01, 0x03, 0x03,
0x03, 0x07, 0x06, 0x0f, 0x0f, 0x1d, 0x1f, 0x1b, 0x1f, 0x17, 0x1f, 0x1f, 0x0e, 0x1e, 0x1c, 0x1c,
0x0c, 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
  };

  oled_write_raw_P(cactaur, sizeof(cactaur));
}

*/

// const char *read_mode_icon(bool swap);
// const char *read_host_led_state(void);
// void set_timelog(void);
// const char *read_timelog(void);

void oled_task_user(void) {
  if (is_keyboard_master()) {
    // If you want to change the display of OLED, you need to change here
    //oled_write_ln(read_layer_state(), false);
    //oled_write_ln(read_keylog(), false);

    //render_caktus();
    oled_write_ln(wpm_state(), false);
    oled_write_ln(" ", false);
    oled_write_ln(read_keylogs(), false);

    //oled_write_ln(read_mode_icon(keymap_config.swap_lalt_lgui), false);
    //oled_write_ln(read_host_led_state(), false);
    //oled_write_ln(read_timelog(), false);
  } else {
    render_caktus();
    //oled_set_cursor(0,6);
    //oled_write(wpm_state(), false);
    //oled_write(read_logo(), false);
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
