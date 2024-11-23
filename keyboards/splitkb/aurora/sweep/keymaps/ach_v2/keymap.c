#include QMK_KEYBOARD_H

enum layers {
	_BASE,
	_FN,
	_NAV,
	_SC,
    _SC_FN,
    _SC_CTRL,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
	[_BASE] = LAYOUT(KC_Q, KC_W, KC_E, KC_R,    KC_T,    KC_Y,   KC_U, KC_I,    KC_O,   KC_P,
                     KC_A, KC_S, KC_D, KC_F,    KC_G,    KC_H,   KC_J, KC_K,    KC_L,   KC_SCLN,
                     KC_Z, KC_X, KC_C, KC_V,    KC_B,    KC_N,   KC_M, KC_COMM, KC_DOT, KC_SLSH,
                                       DF(_SC), MO(_FN), KC_SPC, KC_TRNS),

	[_FN] = LAYOUT(KC_1,   KC_2,          KC_3,          KC_4,    KC_5,    KC_6,    KC_7,          KC_8,   KC_9,    KC_0,
                   KC_EQL, OSM(MOD_LCTL), OSM(MOD_LALT), KC_BSPC, KC_CAPS, MS_BTN2, OSM(MOD_RGUI), KC_ENT, KC_BSLS, KC_MINS,
                   KC_GRV, KC_RCTL,       MO(_NAV),      KC_TAB,  MS_BTN3, MS_BTN1, KC_QUOT,       KC_ESC, KC_LBRC, KC_RBRC,
                                                         KC_TRNS, KC_TRNS, KC_LSFT, KC_TRNS),

    [_NAV] = LAYOUT(KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_MS_L, KC_MS_D, KC_MS_U, KC_MS_R,
                    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_LEFT, KC_DOWN, KC_UP,   KC_RGHT,
                    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_F11, KC_TRNS, KC_TRNS,
                                               KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

	[_SC] = LAYOUT(KC_Q,                   KC_W, KC_E, KC_R,    KC_T,    KC_Y,   KC_U, KC_I,    KC_O,   KC_P,
                   KC_A,                   KC_S, KC_D, KC_F,    KC_G,    KC_H,   KC_J, KC_K,    KC_L,   KC_SCLN,
                   LM(_SC_CTRL, MOD_LCTL), KC_X, KC_C, KC_V,    KC_B,    KC_N,   KC_M, KC_COMM, KC_DOT, KC_SLSH,
                                                    KC_TRNS, MO(_SC_FN), KC_SPC, DF(_BASE)),

	[_SC_FN] = LAYOUT(KC_1,   KC_2,    KC_3,    KC_4,    KC_5,    KC_6,    KC_7,          KC_8,   KC_9,    KC_0,
                      KC_EQL, KC_J,    KC_LALT, KC_BSPC, KC_CAPS, MS_BTN2, OSM(MOD_RGUI), KC_ENT, KC_BSLS, KC_MINS,
                      KC_GRV, KC_RCTL, KC_Z,    KC_TAB,  KC_7,    MS_BTN1, KC_QUOT,       KC_ESC, KC_LBRC, KC_RBRC,
                                                KC_TRNS, KC_TRNS, KC_LSFT, KC_TRNS),

    [_SC_CTRL] = LAYOUT(KC_TRNS, KC_2,    KC_3,    KC_Q,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                        KC_TRNS, KC_J,    KC_LALT, KC_W,    KC_A,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                        KC_TRNS, KC_RCTL, KC_Z,    KC_E,    KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,
                                                   KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS),

};

#ifdef ENCODER_ENABLE
bool
encoder_update_user(uint8_t index, bool clockwise)
{
    // 0 and 1 are left-half encoders
    // 2 and 3 are right-half encoders
    switch(index) {
    case 0:
        if (clockwise)
            IS_LAYER_ON(_BASE) ? tap_code(MS_LEFT) : tap_code(MS_WHLL);
        else
            IS_LAYER_ON(_BASE) ? tap_code(MS_RGHT) : tap_code(MS_WHLR);
        break;
    case 2:
        if (clockwise)
            IS_LAYER_ON(_BASE) ? tap_code(MS_UP)   : tap_code(MS_WHLU);
        else
            IS_LAYER_ON(_BASE) ? tap_code(MS_DOWN) : tap_code(MS_WHLD);
        break;
    }
    return false;
}
#endif
