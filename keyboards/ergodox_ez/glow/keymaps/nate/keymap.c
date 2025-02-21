#include QMK_KEYBOARD_H
#include "version.h"

#define CTL_ESC MT(MOD_RCTL, KC_ESCAPE)
#define CTL_ENT MT(MOD_LCTL, KC_ENTER)
#define SFT_SPC MT(MOD_LSFT, KC_SPACE)
#define CTRL_QUOTE MT(MOD_RCTL, KC_QUOTE)
#define ALT_ENT MT(MOD_LALT, KC_ENTER)
#define ALT_BSP MT(MOD_LALT, KC_BSPC)
#define CTL_DEL MT(MOD_LCTL, KC_DELETE)
#define CTL_QUO MT(MOD_RCTL, KC_QUOT)
#define SFT_BSP MT(MOD_LSFT, KC_BSPC)
#define GUI_DEL MT(MOD_LGUI, KC_DELETE)
#define GUI_MNS MT(MOD_LGUI, KC_MINS)
#define ALT_EQL MT(MOD_LALT, KC_EQL)
#define ALT_MINS MT(MOD_LALT, KC_MINS)
#define GUI_EQL MT(MOD_LGUI, KC_EQL)
#define ALT_TAB MT(MOD_LALT, KC_TAB)
#define L1_MINS LT(1, KC_MINS)


enum layers {
    BASE,  // default layer
    SYMB,  // symbols
    MDIA,  // media keys
};

enum custom_keycodes {
    VRSN = SAFE_RANGE,
};

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [0] = LAYOUT_ergodox_pretty(
    KC_GRV , KC_1   , KC_2   , KC_3   , KC_4   , KC_5   , _______, _______, KC_6   , KC_7   , KC_8   , KC_9   , KC_0   , KC_BSPC,
    ALT_TAB , KC_Q   , KC_W   , KC_E   , KC_R   , KC_T   , KC_LBRC, KC_RBRC, KC_Y   , KC_U   , KC_I   , KC_O   , KC_P   , KC_BSLS,
    CTL_ESC, KC_A   , KC_S   , KC_D   , KC_F   , KC_G   ,                   KC_H   , KC_J   , KC_K   , KC_L   , KC_SCLN, KC_QUOT,
    KC_LSFT, KC_Z   , KC_X   , KC_C   , KC_V   , KC_B   , KC_SPC , KC_BSPC, KC_N   , KC_M   , KC_COMM, KC_DOT , KC_SLSH, KC_RSFT,
    RM_TOGG, _______, KC_LCTL, ALT_BSP, GUI_DEL,                                     MO(1)  , MOD_LALT,_______, _______, _______,
                                                 _______, _______, _______, _______,
																								          _______, _______,
                                        SFT_SPC, CTL_ENT, MO(2)  , _______, ALT_ENT, KC_SPACE
  ),
	// Symbols
  [1] = LAYOUT_ergodox_pretty(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, KC_LPRN, KC_RPRN, KC_DQUO, KC_QUOT, KC_GRV , _______, _______, _______, KC_DQUO, KC_UP  , _______, _______, _______,
    _______, KC_LBRC, KC_RBRC, KC_MINS, KC_EQL , _______,                   KC_BSPC, KC_LEFT, KC_DOWN, KC_RGHT, KC_ENT , _______,
    _______, KC_LCBR, KC_RCBR, KC_UNDS, KC_PLUS, _______, _______, _______, _______, _______, KC_LT  , KC_GT  , _______, _______,
    _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______,
                                                 _______, _______, _______, _______,
                                                          _______, _______,
                                        _______, _______, _______, _______, _______, _______
  ),
	// One-handed typing
 [2] = LAYOUT_ergodox_pretty(
    _______, KC_0   , KC_9   , KC_8   , KC_7   , KC_6   , _______, _______, _______, _______, _______, _______, _______, _______,
    _______, KC_P   , KC_O   , KC_I   , KC_U   , KC_Y   , _______, _______, _______, _______, _______, _______, _______, _______,
    _______, KC_SCLN, KC_L   , KC_K   , KC_J   , KC_H   ,                   _______, _______, _______, _______, _______, _______,
    _______, KC_SLSH, KC_DOT , KC_COMM, KC_M   , KC_N   , _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______,
                                                 _______, _______, _______, _______,
                                                          _______, _______,
                                        _______, _______, _______, _______, _______, _______
 ),
 // Arrows
 [3] = LAYOUT_ergodox_pretty(
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, KC_UP  , _______, _______, _______,
    _______, _______, _______, _______, _______, _______,                   _______, KC_LEFT, KC_DOWN, KC_RGHT, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______,                                     _______, _______, _______, _______, _______,
                                                 _______, _______, _______, _______,
                                                          _______, _______,
                                        _______, _______, _______, _______, _______, _______
 ),
};
// clang-format on

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        switch (keycode) {
            case VRSN:
                SEND_STRING(QMK_KEYBOARD "/" QMK_KEYMAP " @ " QMK_VERSION);
                return false;
        }
    }
    return true;
}

// Runs just one time when the keyboard initializes.
void keyboard_post_init_user(void) {
#ifdef RGBLIGHT_COLOR_LAYER_0
    rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
};

// Runs whenever there is a layer state change.
layer_state_t layer_state_set_user(layer_state_t state) {
    ergodox_board_led_off();
    ergodox_right_led_1_off();
    ergodox_right_led_2_off();
    ergodox_right_led_3_off();

    uint8_t layer = get_highest_layer(state);
    switch (layer) {
        case 0:
#ifdef RGBLIGHT_COLOR_LAYER_0
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_0);
#endif
            break;
        case 1:
            ergodox_right_led_1_on();
#ifdef RGBLIGHT_COLOR_LAYER_1
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_1);
#endif
            break;
        case 2:
            ergodox_right_led_2_on();
#ifdef RGBLIGHT_COLOR_LAYER_2
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_2);
#endif
            break;
        case 3:
            ergodox_right_led_3_on();
#ifdef RGBLIGHT_COLOR_LAYER_3
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_3);
#endif
            break;
        case 4:
            ergodox_right_led_1_on();
            ergodox_right_led_2_on();
#ifdef RGBLIGHT_COLOR_LAYER_4
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_4);
#endif
            break;
        case 5:
            ergodox_right_led_1_on();
            ergodox_right_led_3_on();
#ifdef RGBLIGHT_COLOR_LAYER_5
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_5);
#endif
            break;
        case 6:
            ergodox_right_led_2_on();
            ergodox_right_led_3_on();
#ifdef RGBLIGHT_COLOR_LAYER_6
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_6);
#endif
            break;
        case 7:
            ergodox_right_led_1_on();
            ergodox_right_led_2_on();
            ergodox_right_led_3_on();
#ifdef RGBLIGHT_COLOR_LAYER_7
            rgblight_setrgb(RGBLIGHT_COLOR_LAYER_7);
#endif
            break;
        default:
            break;
    }

    return state;
};

bool get_hold_on_other_key_press(uint16_t keycode, keyrecord_t *record) {
  switch (keycode) {
  // Immediately select the hold action when another key is pressed.
	case L1_MINS:
  case GUI_DEL:
  case ALT_BSP:
  case SFT_BSP:
  case CTL_DEL:
  case ALT_ENT:
  case CTL_ESC:
  case CTL_ENT:
  case SFT_SPC:
    return true;
  // Do not select the hold action when another key is pressed.
  default:
    return false;
  }
}
