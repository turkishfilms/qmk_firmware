// Copyright 2022 beekeeb
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#define _COLEMAK 0
#define _NUMBER 1
#define _NAV 2
#define _MOUSE 3

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
     /*
      * ┌───┬───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┬───┐
      * │Tab│ Q │ W │ E │ R │ T │       │ Y │ U │ I │ O │ P │Bsp│
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │Ctl│ A │ S │ D │ F │ G │       │ H │ J │ K │ L │ ; │ ' │
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │Sft│ Z │ X │ C │ V │ B │       │ N │ M │ , │ . │ / │Sft│
      * └───┴───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┴───┘
      *               ┌───┐                   ┌───┐
      *               │GUI├───┐           ┌───┤Alt│
      *               └───┤Bsp├───┐   ┌───┤Ent├───┘
      *                   └───┤   │   │   ├───┘
      *                       └───┘   └───┘
      */
    [_COLEMAK]=  LAYOUT_split_3x6_3(
        KC_NO,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_NO,                               KC_NO,    KC_L,    KC_U,    KC_Y,LSFT(KC_SCLN),  KC_NO,
        KC_NO,  KC_A,    KC_R,CTL_T(KC_S),SFT_T(KC_T),KC_NO,                             KC_NO,    RSFT_T(KC_N),  RCTL_T(KC_E),KC_I,KC_O, KC_NO,
        KC_NO,  KC_Z,    KC_X,    KC_C,    KC_D,    KC_NO,                               KC_NO,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH,  KC_NO,
                                           KC_TAB, MO(_NUMBER), KC_LALT,            KC_SPC,  MO(_NAV),  KC_BSPC
    ),
    [_NUMBER] = LAYOUT_split_3x6_3(
        KC_NO,  KC_F11,   KC_F12,   KC_F2,   KC_F4,   KC_NO,                               KC_NO,   KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_NO,
        KC_NO,  KC_1,     KC_2,     KC_3,    KC_4,MO(_MOUSE),                               KC_NO,   KC_5,    KC_6,    KC_9,    KC_0,     KC_NO,
        KC_NO,  KC_HOME,    KC_END,    KC_GRAVE,    KC_LBRC,    KC_NO,                  KC_NO,    KC_RBRC,   LSFT(KC_GRAVE), KC_SCLN,  KC_PIPE,    KC_NO,
                                            KC_NO, KC_NO,KC_NO,          KC_MINUS,  KC_EQUAL,  KC_QUOTE
    ),
    [_NAV] = LAYOUT_split_3x6_3(
        KC_NO,KC_F11,KC_KB_MUTE,KC_KB_VOLUME_DOWN,KC_KB_VOLUME_UP,KC_NO,                  KC_NO,   KC_WFWD,   KC_F8,   KC_WBAK,   KC_F10,   KC_NO,
        KC_NO,  KC_A,    KC_S,    KC_D,    KC_F,    KC_NO,                                KC_NO,    KC_J,    KC_UP,    KC_L,    KC_SCLN,    KC_NO,
        KC_NO,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_NO,                                KC_NO,    KC_LEFT,KC_DOWN, KC_RIGHT,  KC_SLSH,    KC_NO,
                                             KC_NO, KC_NO, KC_NO,                  KC_NO, KC_NO,KC_NO
    ),
    [_MOUSE] = LAYOUT_split_3x6_3(
        KC_NO,  KC_F11,   KC_F12,   KC_F2,   KC_F4,   KC_NO,                               KC_NO,   KC_O,    KC_WFWD,   KC_F8,   KC_WBAK,   KC_NO,
        KC_NO,  KC_A,    KC_S,    KC_D,    KC_F,    KC_NO,                                KC_NO,    KC_J,    KC_MS_UP,    KC_L,    KC_WH_U,    KC_NO,
        KC_NO,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_NO,                                KC_NO,    KC_MS_LEFT,  KC_MS_DOWN, KC_MS_RIGHT,  KC_WH_D,    KC_NO,
                                           KC_NO,   KC_NO, KC_NO,            KC_MS_BTN1,  KC_MS_BTN2,  KC_MS_BTN3
    )
};


const uint16_t PROGMEM _MS23_NOMS[] = {KC_MS_BTN2 ,KC_MS_BTN3, COMBO_END};
const uint16_t PROGMEM _YSCLN_DEL[] = {KC_Y ,LSFT(KC_SCLN), COMBO_END};
const uint16_t PROGMEM _DOTSLSH_ENTER[] = {KC_DOT ,KC_SLSH, COMBO_END};
const uint16_t PROGMEM _RTHUMB_MS[] = {MO(_NAV) ,KC_BSPC, COMBO_END};
const uint16_t PROGMEM _UE_M[] = {KC_U ,RCTL_T(KC_E), COMBO_END};
const uint16_t PROGMEM _NH_J[] = {RSFT_T(KC_N) ,KC_H, COMBO_END};
const uint16_t PROGMEM _LN_K[] = {KC_L ,RSFT_T(KC_N), COMBO_END};
const uint16_t PROGMEM _TD_B[] = {SFT_T(KC_T) ,KC_D, COMBO_END};
const uint16_t PROGMEM _PT_G[] = {KC_P ,SFT_T(KC_T), COMBO_END};
const uint16_t PROGMEM _FS_V[] = {KC_F ,CTL_T(KC_S), COMBO_END};
const uint16_t PROGMEM _AR_TAB[] ={KC_A ,KC_R, COMBO_END};
const uint16_t PROGMEM _QW_ESC[] = {KC_Q, KC_W, COMBO_END};
const uint16_t PROGMEM _ZX_GUI[] = {KC_Z, KC_X, COMBO_END};
combo_t key_combos[] = {
    COMBO(_MS23_NOMS, TO(_COLEMAK)),
    COMBO(_YSCLN_DEL, KC_DEL),
    COMBO(_DOTSLSH_ENTER, KC_ENTER),
    COMBO(_RTHUMB_MS, TO(_MOUSE)),
    COMBO(_UE_M, KC_M),
    COMBO(_NH_J, KC_J),
    COMBO(_LN_K, KC_K),
    COMBO(_TD_B, KC_B),
    COMBO(_PT_G, KC_G),
    COMBO(_FS_V, KC_V),
    COMBO(_AR_TAB, KC_TAB),
    COMBO(_QW_ESC, KC_ESC),
    COMBO(_ZX_GUI, KC_LGUI), // keycodes with modifiers are possible too!
};








