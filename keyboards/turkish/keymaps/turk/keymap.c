// Copyright 2022 beekeeb
// SPDX-License-Identifier: GPL-2.0-or-later

#include QMK_KEYBOARD_H
#define _COLEMAK 0
#define _NUMBER 1
#define _NAV 2
#define _MOUSE 3

enum custom_keycodes {
    CTL_TAB=SAFE_RANGE,
    CSA_H,
    ALT_F4,
    CSA_B,
    GUI_X_I,
    ALT_SFT_TAB,
    TD_AB,
    TD_CP,
    CT_CLN,
};

typedef struct {
    uint16_t tap;
    uint16_t hold;
    uint16_t held;
} tap_dance_tap_hold_t;

 void tap_dance_tap_hold_finished(tap_dance_state_t *state, void *user_data) {
     tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)user_data;

     if (state->pressed) {
         if (state->count == 1
 #ifndef PERMISSIVE_HOLD
             && !state->interrupted
 #endif
         ) {
             register_code16(tap_hold->hold);
             tap_hold->held = tap_hold->hold;
         } else {
             register_code16(tap_hold->tap);
             tap_hold->held = tap_hold->tap;
         }
     }
 }

 void tap_dance_tap_hold_reset(tap_dance_state_t *state, void *user_data) {
     tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)user_data;

     if (tap_hold->held) {
         unregister_code16(tap_hold->held);
         tap_hold->held = 0;
     }
 }

 #define ACTION_TAP_DANCE_TAP_HOLD(tap, hold)\
     { .fn = {NULL, tap_dance_tap_hold_finished, tap_dance_tap_hold_reset}, .user_data = (void *)&((tap_dance_tap_hold_t){tap, hold, 0}), }

 // Tap Dance definitions
 tap_dance_action_t tap_dance_actions[] = {
     [CT_CLN] = ACTION_TAP_DANCE_TAP_HOLD(KC_COLN, KC_SCLN),
     [TD_AB] = ACTION_TAP_DANCE_DOUBLE(KC_A,KC_B),
     [TD_CP] = ACTION_TAP_DANCE_DOUBLE(KC_C, KC_P),
 };

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
 tap_dance_action_t *action;

    switch (keycode) {

        case TD(TD_AB):  // list all tap dance keycodes with tap-hold configurations
            action = &tap_dance_actions[QK_TAP_DANCE_GET_INDEX(keycode)];
            if (!record->event.pressed && action->state.count && !action->state.finished) {
                tap_dance_tap_hold_t *tap_hold = (tap_dance_tap_hold_t *)action->user_data;
                tap_code16(tap_hold->tap);
            }
        break;

    case CTL_TAB:
        if (record->event.pressed) {
            SEND_STRING(SS_DOWN(X_LCTL) SS_TAP(X_TAB) SS_UP(X_LCTL));
        }
        break;

    case ALT_SFT_TAB:
        if (record->event.pressed) {
            SEND_STRING(SS_DOWN(X_LALT) SS_DOWN(X_LSFT) SS_TAP(X_TAB) SS_UP(X_LALT) SS_UP(X_LSFT) );
        } else {
        }
        break;

    case GUI_X_I:
        if (record->event.pressed) {
            SEND_STRING(SS_LGUI("x") SS_DELAY(117) "i");
        } else {
        }
        break;

    case CSA_B:
        if (record->event.pressed) {
            SEND_STRING(SS_DOWN(X_LCTL) SS_DOWN(X_LSFT) SS_LALT("b") SS_UP(X_LCTL) SS_UP(X_LSFT) );
        } else {
        }
        break;

    case ALT_F4:
        if (record->event.pressed) {
            SEND_STRING(SS_LALT("F4"));
        } else {
        }
        break;

    case CSA_H:
        if (record->event.pressed) {
            SEND_STRING(SS_DOWN(X_LCTL) SS_DOWN(X_LSFT) SS_LALT("h") SS_UP(X_LCTL) SS_UP(X_LSFT) );
        } else {
        }
        break;
        }
    return true;
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
     /*
      * ┌───┬───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┬───┐
      * │   │ QescW │ F │ P │   │       │   │ L │ U │ Ydel: │   │
      * ├───┼───┼───┼─V─┼─G─┼───┤       ├───┼─K─┼─M─┼───┼───┼───┤
      * │   │ AtabR │ S │ T │   │       │   │ N │ E │ I │ O │   │
      * ├───┼───┼───┼───┼─B─┼───┤       ├───┼─J─┼───┼───┼───┼───┤
      * │   │ ZguiX │ C │ D │   │       │   │ H │ , │ .ent/ │   │
      * └───┴───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┴───┘
      *               ┌───┐                   ┌───┐
      *               │TAB├───┐           ┌───┤Bsp│
      *               └───┤NUM├───┐   ┌───┤NAV├───┘
      *                   └───┤Alt│   │Spc├───┘
      *                       └───┘   └───┘
      */
    [_COLEMAK]=  LAYOUT_split_3x6_3(
        KC_NO, KC_Q,     KC_W,    KC_F,    KC_P,    KC_NO,                               KC_NO,    KC_L,    KC_U,    KC_Y,LSFT(KC_SCLN),  KC_NO,
        KC_NO,  KC_A,    KC_R,CTL_T(KC_S),SFT_T(KC_T),TD(TD_AB),                             KC_NO,    RSFT_T(KC_N),  RCTL_T(KC_E),LALT_T(KC_I),KC_O, KC_NO,
        KC_NO,  KC_Z,    KC_X,    KC_C,    KC_D,   KC_A,                               KC_NO,    KC_H,    KC_COMM, KC_DOT,  KC_SLSH,  KC_NO,
                                           KC_TAB, MO(_NUMBER), KC_LALT,            KC_SPC,  MO(_NAV),  KC_BSPC
    ),
     /*
      * ┌───┬───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┬───┐
      * │   │F6 │F7 │F9 │F10│   │       │   │F11│F12│F4 │F5 │   │
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │   │ 6 │ 7 │ 9 │ 0 │   │       │   │ 1 │ 2 │ 4 │ 5 │   │
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │   │HOM│END│ ` │ { │   │       │   │ [ │ ~ │ ; │ \ │   │
      * └───┴───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┴───┘
      *               ┌───┐                   ┌───┐
      *               │   ├───┐           ┌───┤ ' │
      *               └───┤   ├───┐   ┌───┤ = ├───┘
      *                   └───┤   │   │ - ├───┘
      *                       └───┘   └───┘
      */
    [_NUMBER] = LAYOUT_split_3x6_3(
        KC_NO,  KC_F11,   KC_F12,   KC_F2,   KC_F4,   KC_NO,                  KC_NO,   KC_F7,   KC_F8,   KC_F9,   KC_F10,   KC_NO,
        KC_NO,  KC_6,     KC_7,     KC_9,    KC_0,KC_8 ,                 KC_3 ,   KC_1,    KC_2,    KC_4,    KC_5,     KC_NO,
        KC_NO,  KC_HOME,  KC_END,   KC_GRAVE,LSFT(KC_LBRC), KC_NO,                  KC_NO,   KC_LBRC, LSFT(KC_GRAVE), KC_SCLN,  KC_PIPE,    KC_NO,
                                    KC_NO,   KC_NO,   KC_NO,                  KC_MINUS,KC_EQUAL,KC_QUOTE
    ),
     /*
      * ┌───┬───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┬───┐
      * │   │M6 │MUT│VLD│VLU│   │       │   │B_B│M3 │B_F│M5 │   │
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │   │   │   │   │   │   │       │   │M1 │UP │M2 │BRT│   │
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │   │   │   │   │   │   │       │   │LFT│DWN│RHT│   │   │
      * └───┴───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┴───┘
      *               ┌───┐                   ┌───┐
      *               │   ├───┐           ┌───┤   │
      *               └───┤   ├───┐   ┌───┤   ├───┘
      *                   └───┤   │   │   ├───┘
      *                       └───┘   └───┘
      */
    [_NAV] = LAYOUT_split_3x6_3(
        KC_NO,KC_F11,KC_KB_MUTE,KC_KB_VOLUME_DOWN,KC_KB_VOLUME_UP,KC_NO,                  KC_NO,   KC_WFWD,   ALT_F4,   KC_WWW_BACK,KC_W,   KC_NO,
        KC_NO,  KC_A,    KC_S,    KC_D,    KC_F,    KC_NO,                                KC_NO, ALT_SFT_TAB,    KC_UP,CTL_TAB,    KC_SCLN,    KC_NO,
        KC_NO,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_NO,                                KC_NO,    KC_LEFT,KC_DOWN, KC_RIGHT,  CSA_B,    KC_NO,
                                         KC_NO, KC_NO, KC_NO,                  KC_NO, KC_NO,KC_NO
    ),
     /*
      * ┌───┬───┬───┬───┬───┬───┐       ┌───┬───┬───┬───┬───┬───┐
      * │   │M6 │MUT│V_D│V_U│   │       │   │B_B│M3 │B_F│PRS│   │
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │   │ P │ Q │ W │ E │   │       │   │M1 │MSU│M2 │MWU│   │
      * ├───┼───┼───┼───┼───┼───┤       ├───┼───┼───┼───┼───┼───┤
      * │   │ O │ A │ S │ D │   │       │   │MSL│MSD│MSR│MWD│   │
      * └───┴───┴───┴───┴───┴───┘       └───┴───┴───┴───┴───┴───┘
      *               ┌───┐                   ┌───┐
      *               │   ├───┐           ┌───┤MS3│
      *               └───┤   ├───┐   ┌───┤MS2├───┘
      *                   └───┤   │   │MS1├───┘
      *                       └───┘   └───┘
      */
    [_MOUSE] = LAYOUT_split_3x6_3(
        KC_NO,  KC_F11,   KC_F12,   KC_F2,   KC_F4,   KC_NO,                               KC_NO,   KC_WFWD,   ALT_F4,   KC_WBAK, GUI_X_I,   KC_NO,
        KC_NO,  KC_A,    KC_S,    KC_D,    KC_F,    KC_NO,                                KC_NO,    KC_J,    KC_MS_UP,    KC_L,    KC_WH_U,    KC_NO,
        KC_NO,  KC_Z,    KC_X,    KC_C,    KC_V,    KC_NO,                            KC_NO,    KC_MS_LEFT,  KC_MS_DOWN, KC_MS_RIGHT,  KC_WH_D,    KC_NO,
                                           KC_NO,   KC_NO, KC_NO,            KC_MS_BTN1,  KC_MS_BTN2,  KC_MS_BTN3
    )
};

//make this an array of objects
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
//make a for loop for objects
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






