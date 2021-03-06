#include "lets_split.h"
#include "action_layer.h"
#include "eeconfig.h"

extern keymap_config_t keymap_config;

// Each layer gets a name for readability, which is then used in the keymap matrix below.
// The underscores don't mean anything - you can have a layer called STUFF or any other name.
// Layer names don't all need to be of the same length, obviously, and you can also skip them
// entirely and just use numbers.
#define _QWERTY 0
#define _LOWER  1
#define _RAISE  2
#define _ADJUST 16

enum custom_keycodes {
  QWERTY = SAFE_RANGE,
  LOWER,
  RAISE,
  ADJUST
};

// Fillers to make layering more clear
#define _______ KC_TRNS
#define XXXXXXX KC_NO

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {

/* qwerty
* ,-----------------------------------------------------------------------------------.
* | tab  |   q  |   w  |   e  |   r  |   t  |   y  |   u  |   i  |   o  |   p  | bksp |
* |------+------+------+------+------+------|------+------+------+------+------+------|
* | ctrl |   a  |   s  |   d  |   f  |   g  |   h  |   j  |   k  |   l  |  ;:  |enter |
* |------+------+------+------+------+------|------+------+------+------+------+------|
* |shift |   z  |   x  |   c  |   v  |   b  |   n  |   m  |  ,<  |  .>  |  /?  |  -_   |
* |------+------+------+------+------+------|------+------+------+------+------+------|
* |lower |ctrl  | alt  | gui  | eisu |space | Esc  | kana | Left | Down | Up   |Right |
* `-----------------------------------------------------------------------------------'
*/
[_QWERTY] = KEYMAP( \
  KC_TAB,  KC_Q,    KC_W,    KC_E,    KC_R,     KC_T,    KC_Y,    KC_U,     KC_I,    KC_O,    KC_P,    KC_BSPC, \
  KC_LCTL, KC_A,    KC_S,    KC_D,    KC_F,     KC_G,    KC_H,    KC_J,     KC_K,    KC_L,    KC_SCLN, KC_ENT, \
  KC_LSFT, KC_Z,    KC_X,    KC_C,    KC_V,     KC_B,    KC_N,    KC_M,     KC_COMM, KC_DOT,  KC_SLSH, KC_MINS , \
  LOWER,   KC_LCTL, KC_LALT, KC_LGUI, KC_LANG2, KC_SPC,  KC_ESC,  KC_LANG1, KC_LEFT, KC_DOWN, KC_UP  , KC_RIGHT  \
),

/* lower
* ,-----------------------------------------------------------------------------------,
* | tab  |   1  |   2  |   3  |   4  |   5  |   6  |   7  |   8  |   9  |   0  | bksp |
* |------+------+------+------+------+------|------+------+------+------+------+------|
* | ctrl |   !  |   "  |   #  |   $  |   %  |   &  |   '  |   (  |   )  |  [{  |enter |
* |------+------+------+------+------+------|------+------+------+------+------+------|
* |shift |   ~  |   `  |   |  |   \  |  -   |  +   |  *   |  ^   |      |  ]}  |      |
* |------+------+------+------+------+------|------+------+------+------+------+------|
* |      |      |      |      |      |      |      |      | next | vol- | vol+ | play |
* `-----------------------------------------------------------------------------------'
*/
[_LOWER] = KEYMAP( \
KC_TAB,  KC_1,    KC_2,    KC_3,    KC_4,     KC_5,    KC_6,    KC_7,     KC_8,    KC_9,    KC_0,    _______, \
KC_LCTL, KC_EXLM, KC_QUOT, KC_HASH, KC_DLR,   KC_PERC, KC_AMPR, KC_QUOT,  KC_LPRN, KC_RPRN, KC_LBRC, _______, \
KC_LSFT, KC_TILD, KC_GRV,  KC_PIPE, KC_BSLS,  KC_MINS, KC_PLUS, KC_ASTR,  KC_CIRC, KC_EQL,  KC_RBRC, _______, \
_______, _______, _______, _______, _______,  _______, _______, _______,  KC_MNXT,  KC_VOLD, KC_VOLU, KC_MPLY  \
),

/* Raise
* ,-----------------------------------------, ,-----------------------------------------.
* |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  | |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
* |------+------+------+------+------+------| |------+------+------+------+------+------|
* |      |      |      |      |      |      | |      |      |      |      |      |      |
* |------+------+------+------+------+------| |------+------+------+------+------+------|
* |      |      |      |      |      |      | |      |      |      |      |      |      |
* |------+------+------+------+------+------| |------+------+------+------+------+------|
* |Reset |      |      |      |      |      | |      |      |      |      |      |Reset |
* `-----------------------------------------' `-----------------------------------------'
*/

[_RAISE] = KEYMAP( \
KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  \
_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
RESET,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RESET    \
),

/* Adjust
* ,-----------------------------------------, ,-----------------------------------------.
* |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  | |  F7  |  F8  |  F9  |  F10 |  F11 |  F12 |
* |------+------+------+------+------+------| |------+------+------+------+------+------|
* |      |      |      |      |      |      | |      |      |      |      |      |      |
* |------+------+------+------+------+------| |------+------+------+------+------+------|
* |      |      |      |      |      |      | |      |      |      |      |      |      |
* |------+------+------+------+------+------| |------+------+------+------+------+------|
* |Reset |      |      |      |      |      | |      |      |      |      |      |Reset |
* `-----------------------------------------' `-----------------------------------------'
*/

[_ADJUST] = KEYMAP( \
KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,  \
_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
_______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, \
RESET,   _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, RESET    \
)
};

#ifdef AUDIO_ENABLE
float tone_qwerty[][2]     = SONG(QWERTY_SOUND);
float tone_dvorak[][2]     = SONG(DVORAK_SOUND);
float tone_colemak[][2]    = SONG(COLEMAK_SOUND);
#endif

void persistent_default_layer_set(uint16_t default_layer) {
  eeconfig_update_default_layer(default_layer);
  default_layer_set(default_layer);
}

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
  bool return_value = false;
  switch (keycode) {
    case QWERTY:
      if (record->event.pressed) {
        #ifdef AUDIO_ENABLE
          PLAY_SONG(tone_qwerty);
        #endif
        persistent_default_layer_set(1UL<<_QWERTY);
      }
      break;

    case LOWER:
      if (record->event.pressed) {
        layer_on(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_LOWER);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      break;

    case RAISE:
      if (record->event.pressed) {
        layer_on(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      } else {
        layer_off(_RAISE);
        update_tri_layer(_LOWER, _RAISE, _ADJUST);
      }
      break;

    default:
      return_value = true;
  }
  return return_value;
}
