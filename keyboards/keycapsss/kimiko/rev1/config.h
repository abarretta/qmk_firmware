/* Copyright 2020 @ben_roe (keycapsss.com)
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

#pragma once

/* SK6812 RGB LED */
#define RGB_DI_PIN D3

#ifdef RGBLIGHT_ENABLE
#   define RGBLED_NUM 60  // Total number of LEDs
#   define RGBLED_SPLIT { 30, 30 } // LEDs per side
#   define RGBLIGHT_SPLIT
#endif

// Limit the power draw
#ifdef IOS_DEVICE_ENABLE
  #define RGBLIGHT_LIMIT_VAL 40
#else
  #define RGBLIGHT_LIMIT_VAL 80
#endif

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE
/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE
