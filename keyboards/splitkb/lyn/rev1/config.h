/*
Copyright 2021 Thomas Baart <thomas@splitkb.com>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#pragma once


/* USB Device descriptor parameter */
#define VENDOR_ID       0xFEED
#define PRODUCT_ID      0xF001 // TODO: Unique-ify
#define DEVICE_VER      0x0001
#define MANUFACTURER    splitkb
#define PRODUCT         Lyn
#define DESCRIPTION     Rhythm Game Controller

#define MATRIX_ROWS 4
#define MATRIX_COLS 5

#define DIRECT_PINS       { \
    { NO_PIN, F1,     F4,     NO_PIN, NO_PIN }, \
    { F7,     F6,     F5,     F0,     D2     } \
}
#define DIRECT_PINS_RIGHT { \
    { NO_PIN, NO_PIN, F0,     B0,    NO_PIN }, \
    { D5,     F1,     B1,     B2,    B3     } \
}

// wiring
#define UNUSED_PINS

#define ENCODERS_PAD_A { D6 }
#define ENCODERS_PAD_B { D7 }
#define ENCODERS_PAD_A_RIGHT { D7 }
#define ENCODERS_PAD_B_RIGHT { D6 }

/* Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed */
#define DEBOUNCE 5

/*
 * Split Keyboard specific options, make sure you have 'SPLIT_KEYBOARD = yes' in your rules.mk, and define SOFT_SERIAL_PIN.
 */
#define SOFT_SERIAL_PIN D0

#define RGBLIGHT_SPLIT
#define RGB_DI_PIN D3
#define RGBLED_SPLIT { 3, 3 }
#define RGBLED_NUM 6

/* Mechanical locking support. Use KC_LCAP, KC_LNUM or KC_LSCR instead in keymap */
#define LOCKING_SUPPORT_ENABLE
/* Locking resynchronize hack */
#define LOCKING_RESYNC_ENABLE
