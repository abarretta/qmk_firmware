#pragma once

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE

/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

#define RGB_DI_PIN E6
#ifdef RGB_DI_PIN
#define RGBLED_NUM 1
#define RGBLIGHT_SLEEP
#endif
