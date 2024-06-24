/* Copyright 2023 splitkb.com <support@splitkb.com>
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

// Myriad boilerplate
#undef MYRIAD_ENABLE

// Debounce reduces chatter (unintended double-presses) - set 0 if debouncing is not needed
#define DEBOUNCE 5

#undef RGB_MATRIX_TIMEOUT
#define RGB_MATRIX_TIMEOUT 180000

#undef TAPPING_TERM
#define TAPPING_TERM 195

#define LAYER_STATE_8BIT

// Sets the default brightness value
#define RGB_MATRIX_DEFAULT_VAL 50

// Sets the default animation speed
#define RGB_MATRIX_DEFAULT_SPD 10

#define SPLIT_LAYER_STATE_ENABLE
