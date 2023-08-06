 /* Copyright 2020 Naoki Katahira
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

#include QMK_KEYBOARD_H
#include <stdio.h>

enum layer_number {
  _BASE = 0,
  _FN,
  _GAME,
  _NONE,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* BASE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |   `  |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |   -  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  TAB |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  | BKSP |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | C/ESC|   A  |   S  |   D  |   F  |   G  |-------|    |-------|   H  |   J  |   K  |   L  |   ;  |   '  |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |  SFT |   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |   \  |
 * `-----------------------------------------/       /     \ SFT  \-----------------------------------------'
 *                   | LGUI |  Alt |  FN  | /Space  /       \Enter \  |  FN  |TOGGLE|      |
 *                   |      |      |      |/       /         \      \ |      | GAME |      |
 *                   `-------------------''-------'           '------''--------------------'
 */
  [_BASE] = LAYOUT(
    KC_GRV,        KC_1,   KC_2,    KC_3,    KC_4,    KC_5,                            KC_6,    KC_7,      KC_8,    KC_9,    KC_0,    KC_MINS,
    KC_TAB,        KC_Q,   KC_W,    KC_E,    KC_R,    KC_T,                            KC_Y,    KC_U,      KC_I,    KC_O,    KC_P,    KC_BSPC,
    CTL_T(KC_ESC), KC_A,   KC_S,    KC_D,    KC_F,    KC_G,                            KC_H,    KC_J,      KC_K,    KC_L,    KC_SCLN, KC_QUOT,
    KC_LSFT,       KC_Z,   KC_X,    KC_C,    KC_V,    KC_B,    KC_LBRC, KC_RBRC,       KC_N,    KC_M,      KC_COMM, KC_DOT,  KC_SLSH, KC_BSLS,
                                    KC_LGUI, KC_LALT, MO(_FN), KC_SPC,  SFT_T(KC_ENT), MO(_FN), TO(_GAME), XXXXXXX
  ),

/* FN
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  F1  |  F2  |  F3  |  F4  |  F5  |  F6  |                    |  F7  |  F8  |  F9  | F10  | F11  | F12  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  TAB |      |VOL UP|      |      |      |                    |  []  |  ()  |  {}  |   -  |   =  |  DEL |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * | C/ESC|      |VOL DN|      |      |      |-------.    ,-------| LEFT | DOWN |   UP |RIGHT |      |   '  |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |  SFT |      |      |      |      |      |-------|    |-------|      |      |      |      |      |   \  |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   | LGUI |  Alt |  FN  | /Shift  /       \Shift \  |  FN  |TOGGLE|      |
 *                   |      |      |      |/       /         \      \ |      | GAME |      |
 *                   `-------------------''-------'           '------''--------------------'
 */
  [_FN] = LAYOUT(
    KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,                     KC_F7,   KC_F8,   KC_F9,   KC_F10,  KC_F11,  KC_F12,
    _______, XXXXXXX, KC_VOLU, XXXXXXX, XXXXXXX, XXXXXXX,                   TD(2),   TD(3),   TD(4),   KC_MINS, KC_EQL,  _______,
    _______, XXXXXXX, KC_VOLD, XXXXXXX, XXXXXXX, XXXXXXX,                   TD(0),   KC_DOWN, KC_UP,   TD(1),   XXXXXXX, _______,
    _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______, _______, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, _______,
                                         _______, _______, _______, _______, _______,  _______, _______, _______
  ),

/* GAME
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |  ESC |   1  |   2  |   3  |   4  |   5  |                    |   6  |   7  |   8  |   9  |   0  |   -  |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  TAB |   Q  |   W  |   E  |   R  |   T  |                    |   Y  |   U  |   I  |   O  |   P  | BKSP |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |  CTL |   A  |   S  |   D  |   F  |   G  |-------|    |-------|   H  |   J  |   K  |   L  |   ;  |   '  |
 * |------+------+------+------+------+------|   [   |    |    ]  |------+------+------+------+------+------|
 * |  SFT |   Z  |   X  |   C  |   V  |   B  |-------|    |-------|   N  |   M  |   ,  |   .  |   /  |   \  |
 * `-----------------------------------------/       /     \ SFT  \-----------------------------------------'
 *                   | LGUI |  Alt |  FN  | /Space  /       \Enter \  |  FN  |      |TOGGLE|
 *                   |      |      |      |/       /         \      \ |      |      | BASE |
 *                   `-------------------''-------'           '------''--------------------'
 */
  [_GAME] = LAYOUT(
    KC_ESC,  _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
    KC_LCTL, _______, _______, _______, _______, _______,                   _______, _______, _______, _______, _______, _______,
    _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______, _______,
                              _______, _______, _______,  _______, _______, _______, XXXXXXX, TO(_BASE)
  ),

/* NONE
 * ,-----------------------------------------.                    ,-----------------------------------------.
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |                    |      |      |      |      |      |      |
 * |------+------+------+------+------+------|                    |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------.    ,-------|      |      |      |      |      |      |
 * |------+------+------+------+------+------|       |    |       |------+------+------+------+------+------|
 * |      |      |      |      |      |      |-------|    |-------|      |      |      |      |      |      |
 * `-----------------------------------------/       /     \      \-----------------------------------------'
 *                   |      |      |      | /       /       \      \  |      |      |      |
 *                   |      |      |      |/       /         \      \ |      |      |      |
 *                   `----------------------------'           '------''--------------------'
 */
  [_NONE] = LAYOUT(
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,                   XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
    XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX,
                               XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX, XXXXXXX
  )
};

void keyboard_post_init_user(void) {
  vial_tap_dance_entry_t td0 = {
    KC_LEFT,
    LCTL(KC_LEFT),
    KC_NO,
    KC_NO,
    TAPPING_TERM
  };
  dynamic_keymap_set_tap_dance(0, &td0);

  vial_tap_dance_entry_t td1 = {
    KC_RGHT,
    LCTL(KC_RGHT),
    KC_NO,
    KC_NO,
    TAPPING_TERM
  };
  dynamic_keymap_set_tap_dance(1, &td1);

  vial_tap_dance_entry_t td2 = {
    KC_LBRC,
    KC_RBRC,
    KC_NO,
    KC_NO,
    TAPPING_TERM
  };
  dynamic_keymap_set_tap_dance(2, &td2);

  vial_tap_dance_entry_t td3 = {
    LSFT(KC_9),
    LSFT(KC_0),
    KC_NO,
    KC_NO,
    TAPPING_TERM
  };
  dynamic_keymap_set_tap_dance(3, &td3);

  vial_tap_dance_entry_t td4 = {
    LSFT(KC_LBRC),
    LSFT(KC_RBRC),
    KC_NO,
    KC_NO,
    TAPPING_TERM
  };
  dynamic_keymap_set_tap_dance(4, &td4);
}


#ifdef OLED_ENABLE

oled_rotation_t oled_init_user(oled_rotation_t rotation) {
  if (!is_keyboard_master())
    return OLED_ROTATION_180;  // flips the display 180 degrees if offhand
  return rotation;
}

layer_state_t layer_state_set_user(layer_state_t state) {
    state = update_tri_layer_state(state, _RAISE, _LOWER, _ADJUST);
    return state;
}

static void render_logo(void) {
	
    static const char PROGMEM logo[] = {
        0x80, 0x81, 0x82, 0x83, 0x84, 0x85, 0x86, 0x87, 0x88, 0x89, 0x8A, 0x8B, 0x8C, 0x8D, 0x8E, 0x8F, 0x90, 0x91, 0x92, 0x93, 0x94,
        0xA0, 0xA1, 0xA2, 0xA3, 0xA4, 0xA5, 0xA6, 0xA7, 0xA8, 0xA9, 0xAA, 0xAB, 0xAC, 0xAD, 0xAE, 0xAF, 0xB0, 0xB1, 0xB2, 0xB3, 0xB4,
        0xC0, 0xC1, 0xC2, 0xC3, 0xC4, 0xC5, 0xC6, 0xC7, 0xC8, 0xC9, 0xCA, 0xCB, 0xCC, 0xCD, 0xCE, 0xCF, 0xD0, 0xD1, 0xD2, 0xD3, 0xD4, 0x00
    };

    oled_write_P(logo, false);
}

char keylog_str[24] = {};
char keylogs_str[21] = {};
int keylogs_str_idx = 0;

char wpm[4];
char layer_misc[7];

const char code_to_name[60] = {
    ' ', ' ', ' ', ' ', 'a', 'b', 'c', 'd', 'e', 'f',
    'g', 'h', 'i', 'j', 'k', 'l', 'm', 'n', 'o', 'p',
    'q', 'r', 's', 't', 'u', 'v', 'w', 'x', 'y', 'z',
    '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
    'R', 'E', 'B', 'T', '_', '-', '=', '[', ']', '\\',
    '#', ';', '\'', '`', ',', '.', '/', ' ', ' ', ' '};

void set_keylog(uint16_t keycode, keyrecord_t *record) {
  char name = ' ';
  if (keycode < 60) {
    name = code_to_name[keycode];
  }

  // update keylog
  snprintf(keylog_str, sizeof(keylog_str), "%dx%d, k%2d : %c",
           record->event.key.row, record->event.key.col,
           keycode, name);

  // update keylogs
  if (keylogs_str_idx == sizeof(keylogs_str) - 1) {
    keylogs_str_idx = 0;
    for (int i = 0; i < sizeof(keylogs_str) - 1; i++) {
      keylogs_str[i] = ' ';
    }
  }

  keylogs_str[keylogs_str_idx] = name;
  keylogs_str_idx++;
}

const char *read_keylog(void) {
  return keylog_str;
}

const char *read_keylogs(void) {
  return keylogs_str;
}

static void render_status(void) {
    oled_write_P(PSTR("layer "), false);

    switch (get_highest_layer(layer_state)) {
        case _QWERTY:
            oled_write_P(PSTR("QWERTY"), false);
            break;
        case _LOWER:
            oled_write_P(PSTR("Lower "), false);
            break;
        case _RAISE:
            oled_write_P(PSTR("Raise "), false);
            break;
        case _ADJUST:
            oled_write_P(PSTR("Adjust"), false);
            break;
        default:
            sprintf(layer_misc, "MO(%01d) ", get_highest_layer(layer_state));
	    oled_write(layer_misc, false);
            break;
    }

    oled_write_P(PSTR("  "), false);
    sprintf(wpm, "%03d", get_current_wpm());
    oled_write(wpm, false);
    oled_write_P(PSTR(" wpm\n"), false);
}

bool oled_task_user(void) {
  if (is_keyboard_master()) {
    render_status();
  } else {
    render_logo();
  }
    return false;
}

#endif // OLED_ENABLE
