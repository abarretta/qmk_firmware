// Copyright 2022 Kyle McCreery (@kylemccreery)
// SPDX-License-Identifier: GPL-2.0-or-later

#include "bbs.h"

#ifdef DIP_SWITCH_ENABLE
bool dip_switch_update_kb(uint8_t index, bool active) { 
    if (!dip_switch_update_user(index, active)) { return false; }
    switch (index) {
        case 0:
<<<<<<< HEAD
            if(active) { tap_code(KC_CLCK); }
=======
            if(active) { tap_code(KC_CAPS_LOCK); }
>>>>>>> a5e7390419a23c6db9cb62810f8ff1645d20b6a3
            break;
        break;
    }
    return true;
}
#endif

<<<<<<< HEAD
void eeconfig_init_kb() {
=======
void eeconfig_init_kb(void) {
>>>>>>> a5e7390419a23c6db9cb62810f8ff1645d20b6a3
    steno_set_mode(STENO_MODE_GEMINI); // or STENO_MODE_BOLT
    eeconfig_init_user();
}