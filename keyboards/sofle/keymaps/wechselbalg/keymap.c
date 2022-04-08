
 /* Copyright 2021 Dane Evans
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
  // SOFLE RGB
#include <stdio.h>

#include QMK_KEYBOARD_H

#define INDICATOR_BRIGHTNESS 30

#define HSV_OVERRIDE_HELP(h, s, v, Override) h, s , Override
#define HSV_OVERRIDE(hsv, Override) HSV_OVERRIDE_HELP(hsv,Override)

// Light combinations
#define SET_INDICATORS(hsv) \
	{0, 1, HSV_OVERRIDE_HELP(hsv, INDICATOR_BRIGHTNESS)}, \
    {35+0, 1, hsv}
#define SET_UNDERGLOW(hsv) \
	{1, 6, hsv}, \
    {35+1, 6,hsv}
#define SET_GAMING(hsv)     \
	{35+15, 5, hsv},\
	  {35+22, 3, hsv},\
	  {35+27, 3, hsv}
#define SET_NUMROW(hsv) \
	{10, 2, hsv}, \
		{20, 2, hsv}, \
		{30, 2, hsv}, \
	  {35+ 10, 2, hsv}, \
	  {35+ 20, 2, hsv}, \
	  {35+ 30, 2, hsv}
#define SET_INNER_COL(hsv)	\
	{33, 4, hsv}, \
	  {35+ 33, 4, hsv}

#define SET_OUTER_COL(hsv) \
	{7, 4, hsv}, \
	  {35+ 7, 4, hsv}
#define SET_THUMB_CLUSTER(hsv) 	\
	{25, 2, hsv}, \
	  {35+ 25, 2, hsv}
#define SET_LAYER_ID(hsv) 	\
	{0, 1, HSV_OVERRIDE_HELP(hsv, INDICATOR_BRIGHTNESS)}, \
    {35+0, 1, HSV_OVERRIDE_HELP(hsv, INDICATOR_BRIGHTNESS)}, \
		{1, 6, hsv}, \
    {35+1, 6, hsv}, \
		{7, 4, hsv}, \
	  {35+ 7, 4, hsv}, \
		{25, 2, hsv}, \
	  {35+ 25, 2, hsv}


enum sofle_layers {
    _DEFAULTS = 0,
    _QWERT = 0,
    _NEO,
    _KOY,
    _VOU,
    _VOUX,
    _COLEMAK,
	  _COLEMAKDH,
    _SYMBOL,
    _NUMB,
    _GAMING,
    _ADJUST,
    _SWITCH
};

enum custom_keycodes {
    KC_QWERT = SAFE_RANGE,
    KC_COLEMAK,
	  KC_COLEMAKDH,
    KC_NEO,
    KC_KOY,
    KC_VOU,
    KC_VOUX,
    KC_NUMB,
    KC_SYMBOL,
    KC_GAMING,
    KC_ADJUST,
    KC_D_MUTE
};

// Tap Dance declarations
enum {
    MED_SCR,
    PG_UP,
    PG_DN,
    DEL_INS,
    ESC_PIPE,
    APP_END,
    GUI_HOM
};

// Tap Dance definitions
qk_tap_dance_action_t tap_dance_actions[] = {
    [MED_SCR] = ACTION_TAP_DANCE_DOUBLE(KC_MPLY, KC_MUTE),
    [PG_DN] = ACTION_TAP_DANCE_DOUBLE(KC_DOWN, KC_PGDN),
    [PG_UP] = ACTION_TAP_DANCE_DOUBLE(KC_UP, KC_PGUP),
    [DEL_INS] = ACTION_TAP_DANCE_DOUBLE(KC_DEL, KC_INS),
    //[ESC_PIPE] = ACTION_TAP_DANCE_DOUBLE(KC_ESC, KC_GRV),
    [ESC_PIPE] = ACTION_TAP_DANCE_DOUBLE(KC_ESC, EE_CLR),
    [APP_END] = ACTION_TAP_DANCE_DOUBLE(KC_APP, KC_END),
    [GUI_HOM] = ACTION_TAP_DANCE_DOUBLE(KC_LGUI, KC_HOME)
};

#define CK_ESC TD(ESC_PIPE)
#define CK_LSFT MT(MOD_LSFT, KC_NUBS)
#define CK_LALT MT(MOD_LALT, KC_LGUI)
#define CK_LSPC MT(MOD_LSFT, KC_SPC)
#define CK_LCTNU MT(MOD_LCTL, KC_NUHS)
#define CK_RCTNU MT(MOD_RCTL, KC_QUOT)

// SYMBOL-LAYER (Neo Layer 3)
#define CK_YSYM LT(_SYMBOL, KC_Y)
#define CK_ZSYM LT(_SYMBOL, KC_Z)
#define CK_FSYM LT(_SYMBOL, KC_F)
#define CK_SSYM LT(_SYMBOL, KC_MINS)
#define CK_dotSYM LT(_SYMBOL, KC_DOT)
#define CK_atSYM LT(_SYMBOL, ALGR(KC_Q))
#define CK_AESYM LT(_SYMBOL, KC_AE)

// NUMBLOCK/NAV-LAYER (Neo Layer 4)
#define CK_UENUM LT(_NUMB, KC_UE)
#define CK_ZNUM LT(_NUMB, KC_Z)
#define CK_YNUM LT(_NUMB, KC_Y)
#define CK_XNUM LT(_NUMB, KC_X)
#define CK_escNUM LT(_NUMB, KC_ESC)
#define CK_DELINS TD(DEL_INS)
#define CK_RENT MT(MOD_RSFT, KC_ENT)
#define CK_RALT MT(MOD_RALT, KC_APP)
#define CK_RSFT MT(MOD_RSFT, KC_NUHS)
#define CK_ALF4 LALT(KC_F4)
#define KC_AE KC_QUOT
#define KC_OE KC_SCLN
#define KC_UE KC_LBRC

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 * QWERT
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | TAB  |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  | Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LShift|   A  |   S  |   D  |   F  |   G  |-------.    ,-------|   H  |   J  |   K  |   L  |   ;  |  '   |
 * |------+------+------+------+------+------| MUTE  |    |DISCORD|------+------+------+------+------+------|
 * | LCTR |   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |LShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | Bspc | WIN  |SYMBOL | Enter| /Space  /       \Enter \  |SPACE |NUMB | RCTR | RAlt |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
  [_QWERT] = LAYOUT(
  //,------------------------------------------------.                    ,---------------------------------------------------.
  CK_ESC,   KC_1,   KC_2,    KC_3,    KC_4,     KC_5,                      KC_6,    KC_7,   KC_8,    KC_9,    KC_0,    KC_MINS,
  //|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|
  KC_TAB,    KC_Q,    KC_W,   KC_E,    KC_R,    KC_T,                      KC_Y,    KC_U,   KC_I,    KC_O,    KC_P,    KC_LBRC,
  //|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|
  TT(_SYMBOL),KC_A,   KC_S,    KC_D,    KC_F,   KC_G,                      KC_H,    KC_J,   KC_K,    KC_L,    KC_OE,  CK_AESYM,
  //|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|
   CK_LSFT, CK_ZNUM,   KC_X,    KC_C,    KC_V,  KC_B, KC_MUTE,  KC_D_MUTE,KC_N,     KC_M,  KC_COMM, KC_DOT,  KC_SLSH, CK_RSFT,
  //|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|
              TD(GUI_HOM), CK_LALT,CK_DELINS, KC_LCTL, CK_LSPC,  CK_RENT,TT(_NUMB), KC_BSPC, KC_RALT,TD(APP_END)
  //            \--------+--------+--------+---------+-------|   |--------+---------+--------+---------+-------/
),

/*
 * COLEMAK
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | TAB  |   Q  |   W  |   F  |   P  |   G  |                    |   J  |   L  |   U  |   Y  |   ;  | Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LShift|   A  |   R  |   S  |   T  |   D  |-------.    ,-------|   H  |   N  |   E  |   I  |   O  |  '   |
 * |------+------+------+------+------+------|  MUTE |    |DISCORD|------+------+------+------+------+------|
 * | LCTR |   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   K  |   M  |   ,  |   .  |   /  |LShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | Bspc | WIN  |SYMBOL | Enter| /Space  /       \Enter \  |SPACE |NUMB | RCTR | RAlt |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_COLEMAK] = LAYOUT(
  //,------------------------------------------------.                    ,---------------------------------------------------.
  _______,  KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,     KC_7,   KC_8,   KC_9,    KC_0,    _______,
  //|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|
  _______,  KC_Q,   KC_W,    KC_F,    KC_P,    KC_G,                      KC_J,    KC_L,   KC_U,    KC_Y,    KC_SCLN, _______,
  //|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|
  _______,  KC_A,   KC_R,    KC_S,    KC_T,    KC_D,                      KC_H,    KC_N,   KC_E,    KC_I,    KC_O,    _______,
  //|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|
  _______,  KC_Z,   KC_X,    KC_C,    KC_V,    KC_B,  _______,    _______,KC_K,    KC_M,   KC_COMM, KC_DOT,  KC_SLSH, _______,
  //|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|
                 _______, _______, _______, _______,  _______,    _______, _______,  _______, _______, _______
  //            \--------+--------+--------+---------+-------|   |--------+---------+--------+---------+-------/
),

/*
 * COLEMAK-DH
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | TAB  |   Q  |   W  |   F  |   P  |   B  |                    |   J  |   L  |   U  |   Y  |   ;  | Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LShift|   A  |   R  |   S  |   T  |   G  |-------.    ,-------|   M  |   N  |   E  |   I  |   O  |  '   |
 * |------+------+------+------+------+------|  MUTE |    |DISCORD|------+------+------+------+------+------|
 * | LCTR |   Z  |   X  |   C  |   D  |   V  |-------|    |-------|   K  |   H  |   ,  |   .  |   /  |LShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | Bspc | WIN  |SYMBOL | Enter| /Space  /       \Enter \  |SPACE |NUMB | RCTR | RAlt |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_COLEMAKDH] = LAYOUT(
  //,------------------------------------------------.                    ,---------------------------------------------------.
  _______,  KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                      LT(_SWITCH,KC_6),    KC_7,   KC_8,    KC_9,    KC_0,    _______,
  //|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|
  _______,  KC_Q,   KC_W,    KC_F,    KC_P,    KC_B,                      KC_J,    KC_L,   KC_U,    KC_Y,    KC_SCLN, _______,
  //|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|
  _______,  KC_A,   KC_R,    KC_S,    KC_T,    KC_G,                      KC_M,    KC_N,   KC_E,    KC_I,    KC_O,    _______,
  //|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|
  _______,  KC_Z,   KC_X,    KC_C,    KC_D,    KC_V,  _______,    _______,KC_K,    KC_H,   KC_COMM, KC_DOT, KC_SLSH, _______,
  //|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|
                 _______,_______,_______,_______, _______,   _______,_______, _______,_______, _______
  //            \--------+--------+--------+---------+-------|   |--------+---------+--------+---------+-------/
),

/*
 * NEO
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | TAB  |   Q  |   W  |   F  |   P  |   B  |                    |   J  |   L  |   U  |   Y  |   ;  | Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LShift|   A  |   R  |   S  |   T  |   G  |-------.    ,-------|   M  |   N  |   E  |   I  |   O  |  '   |
 * |------+------+------+------+------+------|  MUTE |    |DISCORD|------+------+------+------+------+------|
 * | LCTR |   Z  |   X  |   C  |   D  |   V  |-------|    |-------|   K  |   H  |   ,  |   .  |   /  |LShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | Bspc | WIN  |SYMBOL | Enter| /Space  /       \Enter \  |SPACE |NUMB | RCTR | RAlt |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_NEO] = LAYOUT(
  //,------------------------------------------------.                    ,---------------------------------------------------.
  _______,  KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,   KC_8,    KC_9,    KC_0,    _______,
  //|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|
  _______, KC_X,    KC_V,    KC_L,     KC_C, KC_W,                         KC_K, KC_H,  KC_G,    KC_F,   KC_Q, KC_MINS,
  //|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|
  _______, KC_U,    KC_I,    KC_A,     KC_E, KC_O,                         KC_S, KC_N,  KC_R,    KC_T,   KC_D, CK_ZSYM,
  //|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|
  _______, CK_UENUM,KC_OE,   KC_AE,    KC_P, KC_Z, _______,     _______,  KC_B, KC_M,  KC_COMM, KC_DOT, KC_J, _______,
  //|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|
                 _______,_______,_______,_______, _______,   _______,_______, _______,_______, _______
  //            \--------+--------+--------+---------+-------|   |--------+---------+--------+---------+-------/
),

/*
 * KOY
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | TAB  |   Q  |   W  |   F  |   P  |   B  |                    |   J  |   L  |   U  |   Y  |   ;  | Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LShift|   A  |   R  |   S  |   T  |   G  |-------.    ,-------|   M  |   N  |   E  |   I  |   O  |  '   |
 * |------+------+------+------+------+------|  MUTE |    |DISCORD|------+------+------+------+------+------|
 * | LCTR |   Z  |   X  |   C  |   D  |   V  |-------|    |-------|   K  |   H  |   ,  |   .  |   /  |LShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | Bspc | WIN  |SYMBOL | Enter| /Space  /       \Enter \  |SPACE |NUMB | RCTR | RAlt |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_KOY] = LAYOUT(
  //,------------------------------------------------.                    ,---------------------------------------------------.
  _______,  KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,   KC_8,    KC_9,    KC_0,    _______,
  //|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|
  _______, KC_K,    KC_DOT, KC_O,  KC_COMM, KC_Y,                         KC_V, KC_G,    KC_C,    KC_L,  KC_MINS, KC_Z,
  //|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|
  _______, KC_H,    KC_A,   KC_E,  KC_I,    KC_U,                         KC_D, KC_T,    KC_R,    KC_N,  KC_S,    CK_FSYM,
  //|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|
  _______, CK_XNUM, KC_Q,   KC_AE, KC_UE,   KC_OE, _______,      _______, KC_B, KC_P,    KC_W,    KC_M,  KC_J,    _______,
  //|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|
                 _______,_______,_______,_______, _______,       _______,_______, _______,_______, _______
  //            \--------+--------+--------+---------+-------|   |--------+---------+--------+---------+-------/
),

/*
 * VOU
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | TAB  |   Q  |   W  |   F  |   P  |   B  |                    |   J  |   L  |   U  |   Y  |   ;  | Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LShift|   A  |   R  |   S  |   T  |   G  |-------.    ,-------|   M  |   N  |   E  |   I  |   O  |  '   |
 * |------+------+------+------+------+------|  MUTE |    |DISCORD|------+------+------+------+------+------|
 * | LCTR |   Z  |   X  |   C  |   D  |   V  |-------|    |-------|   K  |   H  |   ,  |   .  |   /  |LShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | Bspc | WIN  |SYMBOL | Enter| /Space  /       \Enter \  |SPACE |NUMB | RCTR | RAlt |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_VOU] = LAYOUT(
  //,------------------------------------------------.                    ,---------------------------------------------------.
  _______,  KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,   KC_8,    KC_9,    KC_0,    KC_SLSH,
  //|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|
  _______, KC_V,    KC_DOT, KC_O,    KC_U,   KC_AE,                        KC_Q,    KC_G,    KC_L,    KC_H,  KC_F,   KC_J,
  //|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|
  _______, KC_C,    KC_A,   KC_E,    KC_I,   KC_Z,                         KC_B,    KC_T,    KC_R,    KC_N,  KC_S,   CK_SSYM,
  //|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|
  _______, CK_YNUM, KC_X,   KC_COMM, KC_UE,  KC_OE,   _______,    _______, KC_P,    KC_D,    KC_W,    KC_M,  KC_K,   _______,
  //|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|
                    _______,_______,_______,_______, _______,     _______,_______, _______,_______, _______
  //            \--------+--------+--------+---------+-------|   |--------+---------+--------+---------+-------/
),

/*
 * VOUX
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | ESC  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |  `   |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | TAB  |   Q  |   W  |   F  |   P  |   B  |                    |   J  |   L  |   U  |   Y  |   ;  | Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |LShift|   A  |   R  |   S  |   T  |   G  |-------.    ,-------|   M  |   N  |   E  |   I  |   O  |  '   |
 * |------+------+------+------+------+------|  MUTE |    |DISCORD|------+------+------+------+------+------|
 * | LCTR |   Z  |   X  |   C  |   D  |   V  |-------|    |-------|   K  |   H  |   ,  |   .  |   /  |LShift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | Bspc | WIN  |SYMBOL | Enter| /Space  /       \Enter \  |SPACE |NUMB | RCTR | RAlt |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_VOUX] = LAYOUT(
  //,------------------------------------------------.                    ,---------------------------------------------------.
    _______,  KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                      KC_6,    KC_7,   KC_8,    KC_9,    KC_0,   KC_SLSH,
  //|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|
    _______, KC_V,    KC_DOT, KC_O,    KC_U,   KC_AE,                      KC_P,    KC_G,    KC_L,    KC_H,   KC_F,   KC_J,
  //|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|
    _______, KC_C,    KC_A,   KC_E,    KC_I,   KC_Z,                         KC_B,    KC_T,    KC_R,    KC_N,   KC_S,   CK_SSYM,
  //|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|
    _______, CK_YNUM, KC_X,   KC_COMM, KC_UE,  KC_OE, _______,    _______, KC_Q,    KC_D,    KC_W,    KC_M,  KC_K,   _______,
  //|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|
                    _______,_______,_______,_______, _______,        _______,_______, _______,_______, _______
  //            \--------+--------+--------+---------+-------|   |--------+---------+--------+---------+-------/
),

/* SYMBOL
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | trans|  F1  |  F2  |  F3  |  F4  |  F5  |                    |  F6  |  F7  |  F8  |  F9  | F10  | F11  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  `   |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  | F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | trans|   !  |   @  |   #  |   $  |   %  |-------.    ,-------|   ^  |   &  |   *  |   (  |   )  |   |  |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * | trans|  =   |  -   |  +   |   {  |   }  |-------|    |-------|   [  |   ]  |   ;  |   :  |   \  | Shift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | Bspc | WIN  |SYMBOL | Enter| /Space  /       \Enter \  |SPACE |NUMB | RCTR | RAlt |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_SYMBOL] = LAYOUT(
  //,------------------------------------------------.                    ,---------------------------------------------------.
  _______,  KC_F1,  KC_F2,   KC_F3,   KC_F4,   KC_F5,                     KC_F6,   KC_F7,   KC_F8,   KC_F9,  KC_F10,  KC_F11,
  //|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|
  _______, LSFT(KC_3),LSFT(KC_SLSH),ALGR(KC_8),ALGR(KC_9),KC_GRV,        LSFT(KC_1),    KC_NUBS, LSFT(KC_NUBS), LSFT(KC_0), LSFT(KC_6), KC_F12,
  //|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|
  _______, ALGR(KC_MINS),LSFT(KC_7),ALGR(KC_7),ALGR(KC_0),LSFT(KC_RBRC), LSFT(KC_MINS), LSFT(KC_8), LSFT(KC_9), KC_SLSH, LSFT(KC_DOT), CK_atSYM,
  //|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|
  _______, KC_NUHS,LSFT(KC_4),ALGR(KC_NUBS), ALGR(KC_RBRC), ALGR(KC_E),_______,       _______,KC_RBRC, LSFT(KC_5),LSFT(KC_2), LSFT(KC_NUHS), LSFT(KC_COMM), _______,
  //|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|
                 _______, _______, _______, _______, _______,     _______,  _______, _______,  _______,  _______
  //            \--------+--------+--------+---------+-------|   |--------+---------+--------+---------+-------/
),
/* NUMB
 * ,----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Esc  | Ins  | Pscr | Menu |      |      |                    |      | PWrd |  Up  | NWrd | DLine| Bspc |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | Tab  | LAt  | LCtl |LShift|      | Caps |-------.    ,-------|      | Left | Down | Rigth|  Del | Bspc |
 * |------+------+------+------+------+------|  MUTE  |    |       |------+------+------+------+------+------|
 * |Shift | Undo |  Cut | Copy | Paste|      |-------|    |-------|      | LStr |      | LEnd |      | Shift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |SYMBOL | /Enter  /       \Space \  |NUMB | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_NUMB] = LAYOUT(
  //,------------------------------------------------.                    ,---------------------------------------------------.
  TG(_NUMB), KC_F1,   KC_F2,   KC_F3,   KC_F4,    KC_F5,                   KC_CIRC,      KC_TAB,  KC_PSLS, KC_PAST, KC_PMNS, KC_PSLS,
  //|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|
  _______, KC_PGUP, KC_BSPC, KC_UP,   KC_DEL,   KC_PGDN,                   KC_HASH,      KC_P7,   KC_P8,   KC_P9, KC_PPLS, KC_PAST,
  //|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|
  _______, KC_HOME, KC_LEFT, KC_DOWN, KC_RIGHT, KC_END,                   KC_AMPR,      KC_P4,   KC_P5,   KC_P6, KC_COMM, CK_dotSYM,
  //|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|
  _______, CK_escNUM,  KC_TAB,  KC_INS,  KC_ENT,   LCTL(KC_Z), _______,       _______, LSFT(KC_DOT), KC_P1,  KC_P2,   KC_P3, LSFT(KC_COMM), _______,
  //|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|
                 _______, _______, _______, _______, _______,     _______, _______, KC_P0,  KC_PDOT,  KC_BSPC
  //            \--------+--------+--------+---------+-------|   |--------+---------+--------+---------+-------/
),

/* GAMING
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * | trans|      |      |      |      |      |                    |      |NumLck|      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  `   |      |      |      |      |      |                    |   ^  |   7  |   8  |   9  |   *  |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | trans|      |      |      |      |      |-------.    ,-------|   -  |   4  |   5  |   6  |      |   |  |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * | trans|      |      |      |      |      |-------|    |-------|   +  |   1  |   2  |   3  |   \  | Shift|
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | Bspc | WIN  |SYMBOL | Enter| /Space  /       \Enter \  |SPACE | 0    |  .   | RAlt |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
[_GAMING] = LAYOUT(
  //,------------------------------------------------.                    ,---------------------------------------------------.
  KC_ESC, KC_1,  KC_2,   KC_3,     KC_4,    KC_5,                           KC_6, KC_7,    KC_8,    KC_9,   KC_0,    KC_MINS,
  //|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|
 _______, KC_T,  KC_Q,   KC_W,     KC_E,    KC_R,                           KC_Y, KC_U,    KC_I,    KC_O,   KC_P,    KC_LBRC,
  //|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|
  KC_G, KC_LSFT,  KC_A,   KC_S,     KC_D,    KC_F,                          KC_H, KC_J,    KC_K,    KC_L,   KC_SCLN, CK_atSYM,
  //|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|
  KC_LSFT, KC_Z,  KC_X,   KC_B,     KC_V,    KC_C,  _______,       _______,  KC_N, KC_M,    KC_COMM, KC_DOT, KC_SLSH, CK_RSFT,
  //|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|
                    _______, _______, KC_LCTL, KC_SPC, KC_SPC,   _______, _______,  KC_P0,   KC_PDOT, _______
  //            \--------+--------+--------+---------+-------|   |--------+---------+--------+---------+-------/
),

/* ADJUST
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | RESET|      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |RGB_TOG|hue^ |sat ^ | bri ^|      |COLEMAK|-------.   ,-------|desk <|      |      |desk >|      |      |
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * | mode | hue dn|sat d|bri dn|      |QWERT|-------|    |-------|      | PREV | PLAY | NEXT |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | LGUI | LAlt | LCTR |SYMBOL | /Enter  /       \Space \  |NUMB | RCTR | RAlt | RGUI |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
  [_ADJUST] = LAYOUT(
  //,------------------------------------------------.                    ,---------------------------------------------------.
  EEP_RST, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, DF(_QWERT),                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, NK_TOGG,
  //|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|
  RESET,KC_QWERT,KC_COLEMAK,KC_NEO,KC_KOY,DF(_GAMING),                   KC_VOU, LCTL(KC_V), XXXXXXX, RGUI(KC_L), XXXXXXX, XXXXXXX,
  //|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|
  RGB_TOG, RGB_HUI,RGB_SAI, RGB_VAI, KC_COLEMAKDH,KC_VOUX,             C(G(KC_LEFT)),KC_NO,KC_NO,C(G(KC_RGHT)),XXXXXXX, CK_AESYM,
  //|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|
  RGB_MOD, RGB_HUD,RGB_SAD, RGB_VAD, XXXXXXX,KC_QWERT,XXXXXXX,   XXXXXXX, XXXXXXX, KC_MPRV, KC_MPLY, KC_MNXT, XXXXXXX, XXXXXXX,
  //|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|
            _______, CK_LALT, CK_DELINS, TT(_SYMBOL), CK_LSPC,     CK_RENT, TT(_NUMB), TT(_SYMBOL), KC_RALT, _______
    //            \--------+--------+--------+---------+-------|   |--------+---------+--------+---------+-------/
),

/* SWITCH
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | qwer | cole |col_dh| low  | NUMB| adj  |                     |GAMING|      |      |      |      |RESET |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|      |      |      |      |      |EEP_RST|
 * |------+------+------+------+------+------|  MUTE |    |       |------+------+------+------+------+------|
 * | SLEEP|      |      |      |      |      |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *            | Bspc | WIN  |SYMBOL | Enter| /Space  /       \Enter \  |SPACE | 0    |  .   | RAlt |
 *            |      |      |      |      |/       /         \      \ |      |      |      |      |
 *            `----------------------------------'           '------''---------------------------'
 */
  // layer switcher
[_SWITCH] = LAYOUT(
  //,------------------------------------------------.                    ,---------------------------------------------------.
  _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,XXXXXXX, XXXXXXX,
  //|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|
  TO(0),   TO(1),   TO(2),   TO(3),   TO(4),   TO(5),                      TO(6),   KC_NO,   KC_NO,   KC_NO,   KC_NO,   RESET,
  //|------+-------+--------+--------+--------+------|                   |--------+-------+--------+--------+--------+---------|
  KC_NO,   KC_NO, KC_BRIU,   KC_NO,   KC_NO,   KC_NO,                      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   EEP_RST,
  //|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|
  KC_SYSTEM_SLEEP,KC_NO,KC_NO,KC_NO,  KC_NO,   KC_NO, KC_NO,      KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO,
  //|------+-------+--------+--------+--------+------|  ===  |   |  ===  |--------+-------+--------+--------+--------+---------|
                  KC_NO,    KC_NO,   KC_NO,   KC_NO,   KC_NO,     KC_NO,   KC_NO,   KC_NO,   KC_NO,   KC_NO
  //            \--------+--------+--------+---------+-------|   |--------+---------+--------+---------+-------/

	),
};

#ifdef RGBLIGHT_ENABLE
char layer_state_str[70];
// Now define the array of layers. Later layers take precedence

// QWERT,
// Light on inner column and underglow
const rgblight_segment_t PROGMEM layer_qwert_lights[] = RGBLIGHT_LAYER_SEGMENTS(
  SET_LAYER_ID(HSV_RED)

);
const rgblight_segment_t PROGMEM layer_colemakdh_lights[] = RGBLIGHT_LAYER_SEGMENTS(
  SET_LAYER_ID(HSV_PINK)
);

// _NUMB,
// Light on outer column and underglow
const rgblight_segment_t PROGMEM layer_numb_lights[] = RGBLIGHT_LAYER_SEGMENTS(
	SET_LAYER_ID(HSV_TEAL)

);
// _SYMBOL,
// Light on inner column and underglow
const rgblight_segment_t PROGMEM layer_symbol_lights[] = RGBLIGHT_LAYER_SEGMENTS(
	SET_LAYER_ID(HSV_BLUE)

    );
// _COMMAND,
// Light on inner column and underglow
const rgblight_segment_t PROGMEM layer_command_lights[] = RGBLIGHT_LAYER_SEGMENTS(
  SET_LAYER_ID(HSV_PURPLE)
);

//_GAMING
const rgblight_segment_t PROGMEM layer_gaming_lights[] = RGBLIGHT_LAYER_SEGMENTS(
	SET_INDICATORS(HSV_ORANGE),
    SET_UNDERGLOW(HSV_ORANGE),
	SET_GAMING(HSV_BLUE),
    {7, 4, HSV_ORANGE},
    {25, 2, HSV_ORANGE},
    {35+6, 4, HSV_ORANGE},
    {35+25, 2, HSV_ORANGE}
    );
// _SWITCHER   // light up top row
const rgblight_segment_t PROGMEM layer_switcher_lights[] = RGBLIGHT_LAYER_SEGMENTS(
	SET_LAYER_ID(HSV_GREEN),
	SET_NUMROW(HSV_GREEN)
);

const rgblight_segment_t* const PROGMEM my_rgb_layers[] = RGBLIGHT_LAYERS_LIST(

    layer_qwert_lights,
	layer_numb_lights,// overrides layer 1
	layer_symbol_lights,
    layer_command_lights,
	layer_gaming_lights,
	layer_switcher_lights,  // Overrides other layers
	layer_colemakdh_lights
);

layer_state_t layer_state_set_user(layer_state_t state) {
    state = update_tri_layer_state(state, _SYMBOL, _NUMB, _ADJUST);
	rgblight_set_layer_state(0, layer_state_cmp(state, _DEFAULTS) && layer_state_cmp(default_layer_state,_QWERT));
	rgblight_set_layer_state(7, layer_state_cmp(state, _DEFAULTS) && layer_state_cmp(default_layer_state,_COLEMAKDH));


	rgblight_set_layer_state(1, layer_state_cmp(state, _SYMBOL));
	rgblight_set_layer_state(2, layer_state_cmp(state, _NUMB));
	rgblight_set_layer_state(3, layer_state_cmp(state, _ADJUST));
	rgblight_set_layer_state(4, layer_state_cmp(state, _GAMING));
	rgblight_set_layer_state(5, layer_state_cmp(state, _SWITCH));

    return state;
}
void keyboard_post_init_user(void) {
    // Enable the LED layers
    rgblight_layers = my_rgb_layers;

	rgblight_mode(10);// haven't found a way to set this in a more useful way

}
#endif

#ifdef OLED_ENABLE

static void render_logo(void) {
    static const char PROGMEM qmk_logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0xB4,
        0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0x00
    };

    oled_write_P(qmk_logo, false);
}

static void print_status_narrow(void) {
    // Print current mode
    oled_write_P(PSTR("\n\n"), false);
    oled_write_ln_P(PSTR("Dane\nEvans"), false);

    oled_write_ln_P(PSTR(""), false);

	//snprintf(layer_state_str, sizeof(layer_state_str), "Layer: Undef-%ld", layer_state)


    switch (get_highest_layer(default_layer_state)) {
        case _QWERT:
            oled_write_ln_P(PSTR("Qwrt"), false);
            break;
        case _COLEMAK:
            oled_write_ln_P(PSTR("Clmk"), false);
            break;
        case _COLEMAKDH:
            oled_write_ln_P(PSTR("CmkDH"), false);
            break;

        default:
            oled_write_ln_P(PSTR("Undef"), false);
    }
    oled_write_P(PSTR("\n\n"), false);
    // Print current layer
    oled_write_ln_P(PSTR("LAYER"), false);
    switch (get_highest_layer(layer_state)) {
        case _COLEMAK:
        case _QWERT:
        case _COLEMAKDH:
            oled_write_P(PSTR("Base\n"), false);
            break;
        case _NUMB:
            oled_write_P(PSTR("NUMB"), false);
            break;
        case _SYMBOL:
            oled_write_P(PSTR("SYMB"), false);
            break;
        case _ADJUST:
            oled_write_P(PSTR("Adj\n"), false);
            break;
        case _GAMING:
            oled_write_P(PSTR("Nump\n"), false);
            break;
        case _SWITCH:
            oled_write_P(PSTR("Swit\n"), false);
            break;
        default:
            oled_write_ln_P(PSTR("Undef"), false);
    }
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

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {
        case KC_QWERT:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_QWERT);
            }
            return false;
        case KC_COLEMAK:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_COLEMAK);
            }
            return false;
        case KC_COLEMAKDH:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_COLEMAKDH);
            }
            return false;
        case KC_NEO:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_NEO);
            }
            return false;
        case KC_KOY:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_KOY);
            }
            return false;
        case KC_VOU:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_VOU);
            }
            return false;
        case KC_VOUX:
            if (record->event.pressed) {
                set_single_persistent_default_layer(_VOUX);
            }
            return false;
        case KC_SYMBOL:
            if (record->event.pressed) {
                layer_on(_SYMBOL);
                update_tri_layer(_SYMBOL, _NUMB, _ADJUST);
            } else {
                layer_off(_SYMBOL);
                update_tri_layer(_SYMBOL, _NUMB, _ADJUST);
            }
            return false;
        case KC_NUMB:
            if (record->event.pressed) {
                layer_on(_NUMB);
                update_tri_layer(_SYMBOL, _NUMB, _ADJUST);
            } else {
                layer_off(_NUMB);
                update_tri_layer(_SYMBOL, _NUMB, _ADJUST);
            }
            return false;
        case KC_ADJUST:
            if (record->event.pressed) {
                layer_on(_ADJUST);
            } else {
                layer_off(_ADJUST);
            }
            return false;
        case KC_D_MUTE:
            if (record->event.pressed) {
                register_mods(mod_config(MOD_MEH));
                register_code(KC_UP);
            } else {
                unregister_mods(mod_config(MOD_MEH));
                unregister_code(KC_UP);
            }
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
			switch (get_highest_layer(layer_state)) {
				case _COLEMAK:
				case _QWERT:
				case _COLEMAKDH:
					if (clockwise) {
						tap_code(KC_PGDOWN);
					} else {
						tap_code(KC_PGUP);
					}
				break;
			case _NUMB:
			case _SYMBOL:
					if (clockwise) {
						tap_code(KC_DOWN);
					} else {
						tap_code(KC_UP);
					}
				break;
			default:
					if (clockwise) {
						tap_code(KC_WH_D);
					} else {
						tap_code(KC_WH_U);
					}
				break;
		}
    }
    return true;
}

#endif
