/* Copyright 2024 Glorious, LLC
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

#include "quantum.h"
#include QMK_KEYBOARD_H

/*
 * ┌───┐┌───┬───┬───┬───┐┌───┬───┬───┬───┐┌───┬───┬───┬───┐    ┌───┐
 * │Esc││F1 │F2 │F3 │F4 ││F5 │F6 │F7 │F8 ││F9 │F10│F11│F12│    │Mut│
 * └───┘└───┴───┴───┴───┘└───┴───┴───┴───┘└───┴───┴───┴───┘    └───┘
 * ┌───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───┬───────┬───┐
 * │ ` │ 1 │ 2 │ 3 │ 4 │ 5 │ 6 │ 7 │ 8 │ 9 │ 0 │ - │ = │ Backsp│Del│
 * ├───┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─────┼───┤
 * │ Tab │ Q │ W │ E │ R │ T │ Y │ U │ I │ O │ P │ [ │ ] │     │PgU│
 * ├─────┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┬──┴┐ Ent├───┤
 * │ Caps │ A │ S │ D │ F │ G │ H │ J │ K │ L │ ; │ ' │ # │    │PgD│
 * ├────┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴─┬─┴───┴┬───┼───┤
 * │Shft│ \ │ Z │ X │ C │ V │ B │ N │ M │ , │ . │ / │Shift │ ↑ │End│
 * ├────┼───┴┬──┴─┬─┴───┴───┴───┴───┴───┴──┬┴───┼───┴┬─┬───┼───┼───┤
 * │Ctrl│Gui │Alt │         Space          │Alt │ Fn │ │ ← │ ↓ │ → │
 * └────┴────┴────┴────────────────────────┴────┴────┘ └───┴───┴───┘
 */

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
enum custom_layers {
    _BL,   // Base Layer
    _FL,   // Function Layer
    _CL,   // Custom Layer
};
#ifdef VIA_OPENRGB_HYBRID
enum ORGB_SWITCH{
    ORGB = SAFE_RANGE,
    };
#endif

#ifdef VIA_OPENRGB_HYBRID
     bool is_orgb_mode = true; //Default value of the hybrid switch mode
     #ifdef RGB_MATRIX_ENABLE
     #    include "hybrid_switch_animation.h"
     #endif
#endif


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    /* Base Layer (Default Layer) */
    [_BL] = LAYOUT(
        KC_ESC,   KC_F1,   KC_F2,   KC_F3,  KC_F4,  KC_F5,  KC_F6,  KC_F7,  KC_F8,   KC_F9,   KC_F10,   KC_F11,   KC_F12,             KC_MUTE,
        KC_GRV,   KC_1,    KC_2,    KC_3,   KC_4,   KC_5,   KC_6,   KC_7,   KC_8,    KC_9,    KC_0,     KC_MINS,  KC_EQL,   KC_BSPC,  KC_DEL,
        KC_TAB,   KC_Q,    KC_W,    KC_E,   KC_R,   KC_T,   KC_Y,   KC_U,   KC_I,    KC_O,    KC_P,     KC_LBRC,  KC_RBRC,            KC_PGUP,
        KC_CAPS,  KC_A,    KC_S,    KC_D,   KC_F,   KC_G,   KC_H,   KC_J,   KC_K,    KC_L,    KC_SCLN,  KC_QUOT,  KC_NUHS,  KC_ENT,   KC_PGDN,
        KC_LSFT,  KC_NUBS, KC_Z,    KC_X,   KC_C,   KC_V,   KC_B,   KC_N,   KC_M,    KC_COMM, KC_DOT,   KC_SLSH,  KC_RSFT,  KC_UP,    KC_END,
        KC_LCTL,  KC_LWIN, KC_LALT,                         KC_SPC,                  KC_RALT, MO(_FL),            KC_LEFT,  KC_DOWN,  KC_RGHT
    ),
 
    /* Function Layer */
    [_FL] = LAYOUT(
        _______, KC_MYCM, KC_WHOM, KC_CALC, KC_MSEL, KC_MPRV, KC_MNXT, KC_MPLY, KC_MSTP, KC_MUTE, KC_VOLD, KC_VOLU, KC_PSCR,           _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, ORGB, _______, _______, _______, _______,           _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______,
        _______, _______, RGB_SAD, RGB_SAI, RGB_SPD, RGB_SPI, _______, _______, _______, _______, _______, _______, _______,  RGB_VAI, _______,
        _______, GU_TOGG, _______,                            _______,                   _______, _______,          RGB_RMOD, RGB_VAD, RGB_MOD
    ),
 
    /* Custom Layer */
    [_CL] = LAYOUT(
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,           _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,           _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______,
        _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,  _______, _______,
        _______, _______, _______,                            _______,                   _______, _______,          _______,  _______, _______
    ),
};

#if defined(ENCODER_MAP_ENABLE)
const uint16_t PROGMEM encoder_map[][NUM_ENCODERS][NUM_DIRECTIONS] = {
    [_BL] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [_FL] = { ENCODER_CCW_CW(KC_VOLD, KC_VOLU)},
    [_CL] = { ENCODER_CCW_CW(_______, _______)},
};
#endif // ENCODER_MAP_ENABLE

bool process_record_user(uint16_t keycode, keyrecord_t *record)
{
    switch (keycode) {
        case ORGB:
        #ifdef VIA_OPENRGB_HYBRID
            if (record->event.pressed) {
                is_orgb_mode = !is_orgb_mode;
            #ifdef RGB_MATRIX_ENABLE
                    switch_animation_start(is_orgb_mode);
            #endif
            }
        #endif
        default:
            return true; // Process all other keycodes normally
    }
}
