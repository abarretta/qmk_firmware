// Copyright 2022 Kyle McCreery (@kylemccreery)
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

<<<<<<< HEAD
#include "config_common.h"

/* USB Device descriptor parameter */
#define VENDOR_ID       0x6D77 // mw = "MechWild"
#define PRODUCT_ID      0x170E
#define DEVICE_VER      0x0001
#define MANUFACTURER    MechWild
#define PRODUCT         BB Steno

/* key matrix size */
#define MATRIX_ROWS 5
#define MATRIX_COLS 6
=======
>>>>>>> a5e7390419a23c6db9cb62810f8ff1645d20b6a3

/* allows the "key" button on the blackpill to toggle caps lock for user testing before soldering */
#define DIP_SWITCH_PINS { A0 }

<<<<<<< HEAD
/* status light pins using the on board LED for the blackpill */
#define LED_CAPS_LOCK_PIN C13
#define LED_PIN_ON_STATE 0

=======
>>>>>>> a5e7390419a23c6db9cb62810f8ff1645d20b6a3
/*
 * Keyboard Matrix Assignments
 *
 * Change this to how you wired your keyboard
 * COLS: AVR pins used for columns, left to right
 * ROWS: AVR pins used for rows, top to bottom
 * DIODE_DIRECTION: COL2ROW = COL = Anode (+), ROW = Cathode (-, marked on diode)
 *                  ROW2COL = ROW = Anode (+), COL = Cathode (-, marked on diode)
 *
 */
#define MATRIX_ROW_PINS { B12, B10, B13, B1, B14 }
#define MATRIX_COL_PINS { B0, A7, A6, A5, A4, A3 }
<<<<<<< HEAD
#define UNUSED_PINS
=======
>>>>>>> a5e7390419a23c6db9cb62810f8ff1645d20b6a3

/* COL2ROW, ROW2COL */
#define DIODE_DIRECTION COL2ROW

<<<<<<< HEAD
/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */
#define DEBOUNCE 5

=======
>>>>>>> a5e7390419a23c6db9cb62810f8ff1645d20b6a3
/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE
/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE

<<<<<<< HEAD
/* If defined, GRAVE_ESC will always act as ESC when CTRL is held.
 * This is useful for the Windows task manager shortcut (ctrl+shift+esc).
 */
//#define GRAVE_ESC_CTRL_OVERRIDE

/*
 * Force NKRO
 *
 * Force NKRO (nKey Rollover) to be enabled by default, regardless of the saved
 * state in the bootmagic EEPROM settings. (Note that NKRO must be enabled in the
 * makefile for this to work.)
 *
 * If forced on, NKRO can be disabled via magic key (default = LShift+RShift+N)
 * until the next keyboard reset.
 *
 * NKRO may prevent your keystrokes from being detected in the BIOS, but it is
 * fully operational during normal computer usage.
 *
 * For a less heavy-handed approach, enable NKRO via magic key (LShift+RShift+N)
 * or via bootmagic (hold SPACE+N while plugging in the keyboard). Once set by
 * bootmagic, NKRO mode will always be enabled until it is toggled again during a
 * power-up.
 *
 */
=======
>>>>>>> a5e7390419a23c6db9cb62810f8ff1645d20b6a3
#define FORCE_NKRO

/*
 * Feature disable options
 *  These options are also useful to firmware size reduction.
 */

/* disable debug print */
//#define NO_DEBUG

/* disable print */
//#define NO_PRINT

/* disable action features */
//#define NO_ACTION_LAYER
//#define NO_ACTION_TAPPING
//#define NO_ACTION_ONESHOT
<<<<<<< HEAD


/* Bootmagic Lite key configuration */
//#define BOOTMAGIC_LITE_ROW 0
//#define BOOTMAGIC_LITE_COLUMN 0
=======
>>>>>>> a5e7390419a23c6db9cb62810f8ff1645d20b6a3
