#include QMK_KEYBOARD_H

#define FN2_CAPS    LT(2, KC_CAPS)

enum sofle_layers {
    /* _M_XYZ = Mac Os, _W_XYZ = Win/Linux */
    _QWERTY,
    _COLEMAK,
    _LOWER
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
                /*
                * COLEMAK
                * ,-----------------------------------------.                    ,-----------------------------------------.
                * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
                * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
                * | ESC  |   Q  |   W  |   F  |   P  |   G  |                    |   J  |   L  |   U  |   Y  |   ;  | Bspc |
                * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
                * | TAB  |   A  |   R  |   S  |   T  |   D  |-------.    ,-------|   H  |   N  |   E  |   I  |   O  |  '   |
                * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
                * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   K  |   M  |   ,  |   .  |   /  |RShift|
                * `-----------------------------------------/       /     \      \-----------------------------------------'
                *            | LGUI | LAlt | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR | RAlt | RGUI |
                *            |      |      |      |      |/       /         \      \ |      |      |      |      |
                *            `----------------------------------'           '------''---------------------------'
                */
    [_COLEMAK] = LAYOUT(
        KC_ESC,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                        KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,
        KC_GRV,    KC_Q,    KC_W,    KC_F,    KC_P,    KC_B,                        KC_J,    KC_L,    KC_U,    KC_Y,    KC_SCLN, KC_BSLS,
        FN2_CAPS,  KC_A,    KC_R,    KC_S,    KC_T,    KC_G,                        KC_H,    KC_N,    KC_E,    KC_I,    KC_O,    KC_QUOT,
        KC_LSFT,   KC_Z,    KC_X,    KC_C,    KC_D,    KC_V,    KC_F9,      TG(1),  KC_K,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                            KC_UP,   KC_DOWN, KC_LCTRL,KC_TAB,  KC_SPC,     KC_ENT, KC_BSPC, KC_LALT, KC_LEFT, KC_RGHT
    ),

                /*
                * QWERTY
                * ,-----------------------------------------.                    ,-----------------------------------------.
                * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
                * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
                * | ESC  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  | Bspc |
                * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
                * | Tab  |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
                * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
                * |LShift|   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |RShift|
                * `-----------------------------------------/       /     \      \-----------------------------------------'
                *            | LGUI | LAlt | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR | RAlt | RGUI |
                *            |      |      |      |      |/       /         \      \ |      |      |      |      |
                *            `----------------------------------'           '------''---------------------------'
                */
    [_QWERTY] = LAYOUT(
        KC_ESC,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,                        KC_6,    KC_7,    KC_8,    KC_9,    KC_0,    KC_DEL,
        KC_GRV,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,                        KC_Y,    KC_U,    KC_I,    KC_O,    KC_P,    KC_BSLS,
        FN2_CAPS,  KC_A,    KC_S,    KC_D,    KC_F,    KC_G,                        KC_H,    KC_J,    KC_K,    KC_L,    KC_SCLN, KC_QUOT,
        KC_LSFT,   KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_F9,      KC_TRNS,KC_N,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH, KC_RSFT,
                            KC_UP,   KC_DOWN, KC_LCTRL,KC_TAB,  KC_SPC,     KC_ENT, KC_BSPC, KC_LALT, KC_LEFT, KC_RGHT
    ),

                /* LOWER
                * ,-----------------------------------------.                    ,-----------------------------------------.
                * |      |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  | F10  | F11  |
                * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
                * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  | F12  |
                * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
                * | Tab  |   !  |   @  |   #  |   $  |   %  |-------.    ,-------|   ^  |   &  |   *  |   (  |   )  |   |  |
                * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
                * | Shift|  =   |  -   |  +   |   {  |   }  |-------|    |-------|   [  |   ]  |   ;  |   :  |   \  | Shift|
                * `-----------------------------------------/       /     \      \-----------------------------------------'
                *            | LGUI | LAlt | LCTR |LOWER | /Enter  /       \Space \  |RAISE | RCTR | RAlt | RGUI |
                *            |      |      |      |      |/       /         \      \ |      |      |      |      |
                *            `----------------------------------'           '------''---------------------------'
                */
    [_LOWER] = LAYOUT(
        KC_F1,    KC_F2,    KC_F3,    KC_F4,    KC_F5,    KC_F6,                           KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,    KC_F12
        KC_TRNS,  KC_TRNS,  RGB_TOG,  RGB_HUI,  RGB_SAI,  RGB_VAI,                         KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS,
        KC_TRNS,  KC_TRNS,  RGB_MOD,  RGB_HUD,  RGB_SAD,  RGB_VAD,                         KC_TRNS, KC_MINS, KC_EQL,  KC_LBRC, KC_RBRC,   KC_TNRS,
        KC_TRNS,  KC_TRNS,  RGB_RMOD, KC_TRNS,  KC_TRNS,  KC_TRNS,  RESET,      _______,   KC_TRNS, KC_UNDS, KC_PLUS, KC_LCBR, KC_RCBR,   KC_TRNS,
                            KC_PGUP,  KC_PGDN,  KC_RCTRL, KC_TRNS,  KC_TRNS,    KC_TRNS,   KC_RALT, KC_TRNS, KC_TRNS, KC_TRNS
    )
};

#ifdef OLED_ENABLE

static void render_logo(void) {
    static const char PROGMEM qmk_logo[] = {
        0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
        0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
        0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0
    };

    oled_write_P(qmk_logo, false);
}

static void print_status_narrow(void) {

    oled_write_P(PSTR("\n\n"), false);
    switch (get_highest_layer(default_layer_state)) {
        case _QWERTY:
            oled_write_ln_P(PSTR("Qwrty"), false);
            break;
        case _COLEMAK:
            oled_write_ln_P(PSTR("Colemak"), false);
            break;
        default:
            oled_write_P(PSTR("Undef"), false);
    }
    oled_write_P(PSTR("\n\n"), false);
    oled_write_P(PSTR("\n\n"), false);
    led_t led_usb_state = host_keyboard_led_state();
    oled_write_ln_P(PSTR("CAPS"), led_usb_state.caps_lock);
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master()) {
        return OLED_ROTATION_270;
    }
    return rotation;
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        print_status_narrow();
    } else {
        render_logo();
    }
    return false;
}

#endif


