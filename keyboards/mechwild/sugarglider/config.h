// Copyright 2023 Kyle McCreery
// SPDX-License-Identifier: GPL-2.0-or-later

#pragma once

#define DYNAMIC_KEYMAP_LAYER_COUNT 5

/* Matrix COL and ROW definitions */
#define MATRIX_ROWS 9
#define MATRIX_COLS 6

/* Cirque Touchpad Settings */
#define POINTING_DEVICE_AUTO_MOUSE_ENABLE
#define CIRQUE_PINNACLE_ATTENUATION EXTREG__TRACK_ADCCONFIG__ADC_ATTENUATE_2X

/* Define custom font */
#define OLED_FONT_H "keyboards/mechwild/sugarglider/glcdfont.c"

/* allows the "key" button on the blackpill to toggle caps lock for user testing before soldering */
#define DIP_SWITCH_PINS { A0 }

/* TAPPING_TERM value is used for the CIRQUE_PINNACLE_TAPPING_TERM as well by default
 * defining it this way allows us to easily modify it with DYNAMIC_TAPPING_TERM_ENABLE
 */
#define TAPPING_TERM 200
#define CIRQUE_PINNACLE_TAP_ENABLE
#define POINTING_DEVICE_GESTURES_SCROLL_ENABLE

/* spi config */
#define SPI_DRIVER SPID1
#define SPI_SCK_PIN A5
#define SPI_SCK_PAL_MODE 5
#define SPI_MOSI_PIN A7
#define SPI_MOSI_PAL_MODE 5
#define SPI_MISO_PIN A6
#define SPI_MISO_PAL_MODE 5
#define CIRQUE_PINNACLE_SPI_DIVISOR 8
#define CIRQUE_PINNACLE_SPI_CS_PIN A3

/* Force NKRO */
#define FORCE_NKRO
