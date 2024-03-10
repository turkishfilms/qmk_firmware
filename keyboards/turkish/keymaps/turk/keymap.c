// Copyright 2022 beekeeb
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H

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
    [1]=  LAYOUT_split_3x6_3(
        KC_NO,  KC_Q,    KC_W,    KC_F,    KC_P,    KC_NO,                               KC_NO,    KC_L,    KC_U,    KC_Y,    KC_SCLN,  KC_NO,
        KC_NO,  KC_A,    KC_R,    KC_S,    KC_T,    KC_NO,                               KC_NO,    KC_N,    KC_E,    KC_I,    KC_O,     KC_NO,
        KC_NO,  KC_Z,    KC_X,    KC_C,    KC_D,    KC_NO,                               KC_NO,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH,  KC_NO,
                                           KC_TAB, MO(2), KC_ALT,            KC_SPC,  MO(3),  KC_BSPC
    ),
    [2] = LAYOUT_split_3x6_3(
        KC_NO,  KC_F11,   KC_F12,   KC_F2,   KC_F4,   KC_NO,                               KC_NO,   KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_NO,
        KC_NO,  KC_1,    KC_2,    KC_3,    KC_4,    KC_NO,                                KC_NO,    KC_5,    KC_6,    KC_9,    KC_0,    KC_NO,
        KC_NO,  KC_HOME,    KC_END,    KC_GRAVE,    KC_LBRC,    KC_NO,                                KC_NO,    KC_RBRC,    KC_COMM, KC_DOT,  KC_SLSH,    KC_NO,
                                            KC_LGUI, KC_BSPC, KC_SPC,           KC_SPC,  KC_ENT,  KC_RALT
    ),
    [3] = LAYOUT_split_3x6_3(
        KC_NO,  KC_F11,   KC_F12,   KC_F2,   KC_F4,   KC_NO,                               KC_NO,   KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_NO,
        KC_NO,  KC_A,    KC_S,    KC_D,    KC_F,    KC_NO,                                KC_NO,    KC_J,    KC_K,    KC_L,    KC_SCLN,    KC_NO,
        KC_NO,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_NO,                                KC_NO,    KC_M,    KC_COMM, KC_DOT,  KC_SLSH,    KC_NO,
                                            KC_LGUI, KC_BSPC, KC_SPC,           KC_SPC,  KC_ENT,  KC_RALT
    ),

};
