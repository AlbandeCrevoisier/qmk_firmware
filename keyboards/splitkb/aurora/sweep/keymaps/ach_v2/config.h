/* Copyright 2022 splitkb.com <support@splitkb.com>
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

// Not yet available in `keymap.json` format
#ifdef MOUSEKEY_ENABLE
     // The default is 100
#    define MOUSEKEY_WHEEL_INTERVAL 100
     // The default is 40
#    define MOUSEKEY_WHEEL_TIME_TO_MAX 40
     // The default is 8
#    define MOUSEKEY_MOVE_DELTA 4
#endif

#define ENCODER_RESOLUTION 1
