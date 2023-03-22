#include QMK_KEYBOARD_H
#include "keymap_german.h"

enum sofle_layers {
    /* _M_XYZ = Mac Os, _W_XYZ = Win/Linux */
    _QWERTZ,
    _M3,
    _M4
};

enum custom_keycodes {
    KC_QWERTZ = SAFE_RANGE,
    KC_M3,
    KC_M4,
    KC_PRVWD,
    KC_NXTWD,
    KC_LSTRT,
    KC_LEND,
    KC_DLINE
};


const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * QWERTY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  ß   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  |   Q  |   W  |   E  |   R  |   T  |                    |   Z  |   U  |   I  |   O  |   P  |  Ü   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | M3   |   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   Ö  | Ä/M3 |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |LShift|   Y  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   -  |RShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt |  M4  | STRG | /Enter  /       \Enter \  |STRG  |  M4  | RAlt | RGUI |
 *            |      |      | Space| Space|/       /         \      \ |Space | Space|      |      |
 *            `----------------------------------'           '------''---------------------------'
 */

[_QWERTZ] = LAYOUT(
  KC_ESC,   KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,    KC_8,    KC_9,    KC_0,  DE_SS,
  KC_TAB,   KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                      DE_Z,    KC_U,    KC_I,    KC_O,    KC_P,  DE_UE,
  MO(_M3),  KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                      KC_H,    KC_J,    KC_K,    KC_L,   DE_OE,  LT(_M3,DE_AE),
  KC_LSFT,  DE_Y,   KC_X,    KC_C,    KC_V,    KC_B, XXXXXXX,     XXXXXXX,KC_N,    KC_M, KC_COMM,  KC_DOT, DE_MINS,  KC_RSFT,
                 KC_LGUI,KC_LALT,LT(_M4,KC_SPC), LCTL_T(KC_SPC), KC_ENT,      KC_ENT, RCTL_T(KC_SPC), LT(_M4,KC_SPC), KC_RALT, KC_RGUI
),
/* SYMBOL (Symbol layer - NEO layer 3)
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |   1  |   ²  |   ³  |   >  |   <  |                    |   €  |  F7  |   ,  |   ‘  |      |   ´  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |   §  |   _  |   [  |   ]  |   ^  |                    |   !  |   <  |   >  |   =  |   &  |   f  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |   \  |   /  |   {  |   }  |   *  |-------.    ,-------|   ?  |   (  |   )  |   -  |   :  |   @  |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * |      |   #  |   $  |   |  |   ~  |   `  |-------|    |-------|   +  |   %  |   "  |   '  |   ;  |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt |  M4  | STRG | /Enter  /       \Enter \  |Space |  M4  | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_M3] = LAYOUT(
  //,-----------------------------------------------------------.                       ,-----------------------------------------------------------.
    _______,KC_1, ALGR(KC_2),ALGR(KC_3),LSFT(KC_NUBS),KC_NUBS,                          ALGR(KC_E), KC_F7,   KC_COMM, LSFT(KC_NUHS),KC_QUOT,  DE_ACUT,
  //|---------+---------+---------+---------+---------+---------|                       |---------+---------+---------+---------+---------+---------|
    _______, LSFT(KC_3),LSFT(KC_SLSH),ALGR(KC_8),ALGR(KC_9),KC_GRV,                     LSFT(KC_1),    KC_NUBS, LSFT(KC_NUBS), LSFT(KC_0), LSFT(KC_6), KC_F,
  //|---------+---------+---------+---------+---------+---------|                       |---------+---------+---------+---------+---------+---------|
    _______, ALGR(KC_MINS),LSFT(KC_7),ALGR(KC_7),ALGR(KC_0),LSFT(KC_RBRC),              LSFT(DE_SS), LSFT(KC_8), LSFT(KC_9), KC_SLSH, LSFT(KC_DOT), DE_AT,
  //|---------+---------+---------+---------+---------+---------|  =====  |   |  =====  |---------+---------+---------+---------+---------+---------|
    _______, KC_NUHS,LSFT(KC_4),ALGR(KC_NUBS),DE_TILD,DE_GRV,_______, _______,DE_PLUS, LSFT(KC_5),LSFT(KC_2), LSFT(KC_NUHS), LSFT(KC_COMM), _______,
  //|---------+---------+---------+---------+---------+---------|  =====  |   |  =====  |---------+---------+---------+---------+---------+---------|
                         _______,   _______,  _______,  _______,  _______,      _______,  _______,  _______,  _______,  _______
  //                    \---------+---------+---------+---------+---------|   |---------+---------+---------+---------+---------/
),
/* M4 (Numpad & Navigation layer - NEO layer 4)
 * ,----------------------------------------.                    ,-----------------------------------------.
 * |  F12 |  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  |  F10 | F11  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      | PGUP | BSPC |  UP  |  DEL | PGDN |                    |      |   7  |   8  |   9  |   +  | PAST |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      | HOME | LEFT | DOWN | RIGHT|  END |-------.    ,-------|      |   4  |   5  |   6  |  Del | Bspc |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |  ESC |  TAB |  INS | ENTER| CTL-Z|-------|    |-------|      |   1  |   2  |   3  |   ,  |      |
 * `-----------------------------------------/      /      \      \-----------------------------------------'
 *            | LGUI | LAlt |  M4  | STRG | /Enter  /       \Enter \  |Space |  M4  | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_M4] = LAYOUT(
  //,-----------------------------------------------------------.                       ,-----------------------------------------------------------.
    KC_F12,   KC_F1,    KC_F2,    KC_F3,     KC_F4,   KC_F5,                             KC_F6,   KC_F7,   KC_F8,   KC_F9, KC_F10, KC_F11,
  //|---------+---------+---------+---------+---------+---------|                       |---------+---------+---------+---------+---------+---------|
     _______,  KC_PGUP,  KC_BSPC,  KC_UP,    KC_DEL,   KC_PGDN,                          KC_HASH, KC_P7,   KC_P8,   KC_P9, KC_PPLS, KC_PAST,
  //|---------+---------+---------+---------+---------+---------|                       |---------+---------+---------+---------+---------+---------|
     _______,  KC_HOME,  KC_LEFT,  KC_DOWN,  KC_RIGHT, KC_END,                           KC_AMPR,  KC_P4,  KC_P5,   KC_P6, KC_PCMM, KC_PDOT,
  //|---------+---------+---------+---------+---------+---------|  =====  |   |  =====  |---------+---------+---------+---------+---------+---------|
     _______,  KC_ESC,  KC_TAB,   KC_INS,   KC_ENT,   LCTL(KC_Z),_______,     _______,  LSFT(KC_DOT), KC_P1,KC_P2, KC_P3,LSFT(KC_COMM),_______,
  //|---------+---------+---------+---------+---------+---------|  =====  |   |  =====  |---------+---------+---------+---------+---------+---------|
                         _______,   _______,  _______,  _______,  _______,     _______,  _______,  KC_P0,    KC_PDOT,  KC_DOT
  //                    \---------+---------+---------+---------+---------|   |---------+---------+---------+---------+---------/
)};

#ifdef OLED_ENABLE

static void render_logo(void) {
    static const char PROGMEM qmk_logo[] = {
        0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8a,0x8b,0x8c,0x8d,0x8e,0x8f,0x90,0x91,0x92,0x93,0x94,
        0xa0,0xa1,0xa2,0xa3,0xa4,0xa5,0xa6,0xa7,0xa8,0xa9,0xaa,0xab,0xac,0xad,0xae,0xaf,0xb0,0xb1,0xb2,0xb3,0xb4,
        0xc0,0xc1,0xc2,0xc3,0xc4,0xc5,0xc6,0xc7,0xc8,0xc9,0xca,0xcb,0xcc,0xcd,0xce,0xcf,0xd0,0xd1,0xd2,0xd3,0xd4,0
    };

    oled_write_P(qmk_logo, false);
}

static void print_status_narrow(void) {
    // Print current mode
    oled_write_P(PSTR("\n\n"), false);
    oled_write_ln_P(PSTR("MODE"), false);
    oled_write_ln_P(PSTR(""), false);
    if (keymap_config.swap_lctl_lgui) {
        oled_write_ln_P(PSTR("MAC"), false);
    } else {
        oled_write_ln_P(PSTR("WIN"), false);
    }

    switch (get_highest_layer(default_layer_state)) {
        case _QWERTZ:
            oled_write_ln_P(PSTR("Qwrt"), false);
            break;
        case _M3:
            oled_write_ln_P(PSTR("M3"), false);
            break;
        case _M4:
            oled_write_ln_P(PSTR("M4"), false);
            break;
        default:
            oled_write_P(PSTR("Undef"), false);
    }
    oled_write_P(PSTR("\n\n"), false);
    // Print current layer
    oled_write_ln_P(PSTR("LAYER"), false);
    switch (get_highest_layer(layer_state)) {
        case _QWERTZ:
            oled_write_P(PSTR("Base\n"), false);
            break;
        case _M3:
            oled_write_P(PSTR("M3"), false);
            break;
        case _M4:
            oled_write_P(PSTR("M4"), false);
            break;
        default:
            oled_write_ln_P(PSTR("Undef"), false);
    }
    oled_write_P(PSTR("\n\n"), false);
    led_t led_usb_state = host_keyboard_led_state();
    oled_write_ln_P(PSTR("CPSLK"), led_usb_state.caps_lock);
}

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
    if (is_keyboard_master()) {
        return OLED_ROTATION_270;
    }
    return rotation;
}

bool oled_task_user(void) {
    if (is_keyboard_master()) {
        print_status_narrow();
    } else {
        render_logo();
    }
    return false;
}

#endif

/*layer_state_t layer_state_set_user(layer_state_t state) {
    return update_tri_layer_state(state, _QWERTZ, _M3, _M4);
}*/

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_QWERTZ:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERTZ);
            }
            return false;
        case KC_M3:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_M3);
            }
            return false;
        case KC_M4:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_M4);
            }
            return false;            
        case KC_PRVWD:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    register_mods(mod_config(MOD_LALT));
                    register_code(KC_LEFT);
                } else {
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_LEFT);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LALT));
                    unregister_code(KC_LEFT);
                } else {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_LEFT);
                }
            }
            break;
        case KC_NXTWD:
             if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    register_mods(mod_config(MOD_LALT));
                    register_code(KC_RIGHT);
                } else {
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_RIGHT);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LALT));
                    unregister_code(KC_RIGHT);
                } else {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_RIGHT);
                }
            }
            break;
        case KC_LSTRT:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                     //CMD-arrow on Mac, but we have CTL and GUI swapped
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_LEFT);
                } else {
                    register_code(KC_HOME);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_LEFT);
                } else {
                    unregister_code(KC_HOME);
                }
            }
            break;
        case KC_LEND:
            if (record->event.pressed) {
                if (keymap_config.swap_lctl_lgui) {
                    //CMD-arrow on Mac, but we have CTL and GUI swapped
                    register_mods(mod_config(MOD_LCTL));
                    register_code(KC_RIGHT);
                } else {
                    register_code(KC_END);
                }
            } else {
                if (keymap_config.swap_lctl_lgui) {
                    unregister_mods(mod_config(MOD_LCTL));
                    unregister_code(KC_RIGHT);
                } else {
                    unregister_code(KC_END);
                }
            }
            break;
        case KC_DLINE:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_BSPC);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_BSPC);
            }
            break;
        case KC_COPY:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_C);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_C);
            }
            return false;
        case KC_PASTE:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_V);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_V);
            }
            return false;
        case KC_CUT:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_X);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_X);
            }
            return false;
            break;
        case KC_UNDO:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_LCTL));
                register_code(KC_Z);
            } else {
                unregister_mods(mod_config(MOD_LCTL));
                unregister_code(KC_Z);
            }
            return false;
    }
    return true;
}

#ifdef ENCODER_ENABLE

bool encoder_update_user(uint8_t index, bool clockwise) {
    if (index == 0) {
        if (clockwise) {
            tap_code(KC_VOLU);
        } else {
            tap_code(KC_VOLD);
        }
    } else if (index == 1) {
        if (clockwise) {
            tap_code(KC_PGDN);
        } else {
            tap_code(KC_PGUP);
        }
    }
    return true;
}

#endif
