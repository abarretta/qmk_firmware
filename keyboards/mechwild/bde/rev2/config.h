/*
Copyright 2022 Kyle McCreery
<<<<<<< HEAD
=======

>>>>>>> mechwild/bbs
This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.
<<<<<<< HEAD
=======

>>>>>>> mechwild/bbs
This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.
<<<<<<< HEAD
=======

>>>>>>> mechwild/bbs
You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once

<<<<<<< HEAD
#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0x6D77 // mw = "MechWild"
#define PRODUCT_ID      0x170A
#define DEVICE_VER      0x0101
#define MANUFACTURER    MechWild
#define PRODUCT         BDE Rev2

<<<<<<< HEAD
#define STACK_SPLIT

/* Key matrix size */
#define MATRIX_ROWS 6
//#define MATRIX_ROWS 12
=======
/* Key matrix size */
#define MATRIX_ROWS 6
>>>>>>> mechwild/bbs
#define MATRIX_COLS 7

/* Key matrix pins */
#define MATRIX_ROW_PINS { C6, D7, B4, D4, E6, B2 }
#define MATRIX_COL_PINS { B3, B1, F7, F6, F5, F4, B5 }
#define UNUSED_PINS

<<<<<<< HEAD
/* Split Pin Definition, comment out if not being used in split mode*/
//#define SOFT_SERIAL_PIN D2

/* Encoder pins, Only set if not being used in split mode */
#ifndef SOFT_SERIAL_PIN

=======
/* Encoder pins */
>>>>>>> mechwild/bbs
#define ENCODERS_PAD_A { D3 }
#define ENCODERS_PAD_B { D2 }

/* Encoder resolution */
#define ENCODER_RESOLUTION 4
#define TAP_CODE_DELAY 10
<<<<<<< HEAD
#else
/* Use I2C or Serial, not both */
#define USE_SERIAL
// #define USE_I2C

/* Select hand configuration */
#define MASTER_LEFT
// #define MASTER_RIGHT
// #define EE_HANDS

#endif
=======
>>>>>>> mechwild/bbs

/* COL2ROW, ROW2COL */
#define DIODE_DIRECTION COL2ROW

#define OLED_FONT_H "keyboards/mechwild/bde/lib/rev2.c"

#define RGB_DI_PIN B6
#ifdef RGB_DI_PIN
#    define RGBLED_NUM 8
#    define RGBLIGHT_HUE_STEP 8
#    define RGBLIGHT_SAT_STEP 8
#    define RGBLIGHT_VAL_STEP 8
#    define RGBLIGHT_LIMIT_VAL 255 /* The maximum brightness level */
#    define RGBLIGHT_SLEEP  /* If defined, the RGB lighting will be switched off when the host goes to sleep */
/*== Chosen enabled animations ==*/
#    define RGBLIGHT_EFFECT_RAINBOW_SWIRL
#endif

/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */
#define DEBOUNCE 5

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE

/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE
<<<<<<< HEAD

/* disable these deprecated features by default */
#define NO_ACTION_MACRO
#define NO_ACTION_FUNCTION
=======
>>>>>>> mechwild/bbs
=======
#define OLED_FONT_H "keyboards/mechwild/bde/lib/rev2.c"
>>>>>>> a5e7390419a23c6db9cb62810f8ff1645d20b6a3
