
#include QMK_KEYBOARD_H
#include "frames.h"

static int num_keypresses = 0;
static int current_frame  = 0;

enum layers { _BASE = 0, _NAV, _GAME };

#define BASE DF(_BASE)

#define SE_AA KC_LBRC
#define SE_OSLH KC_SCLN
#define SE_ADIA KC_QUOT
#define SE_LESS KC_NUBS
#define SE_PLUS KC_MINS
#define SE_MINS KC_SLSH
#define SE_APOS KC_NUHS
#define SE_DIAE KC_RBRC
#define SE_ACUT KC_EQL

// clang-format off
const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/*
 *
 * ,-------------------------------------------.      ,------.  ,------.      ,-------------------------------------------.
 * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |------|  |------|      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------|      |------|  |------|      |------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
 * |--------+------+------+------+------+------+------+------|  |------|------+------+------+------+------+------+--------|
 * |        |      |      |      |      |      |      |      |  |      |      |      |      |      |      |      |        |
 * `----------------------+------+------+------+------+------|  |------+------+------+------+------+----------------------'
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        |      |      |      |      |      |  |      |      |      |      |      |
 *                        `----------------------------------'  `----------------------------------'
 */
    [_BASE] = LAYOUT(
      KC_ESC     , KC_1              , KC_2              , KC_3              , KC_4              , KC_5   ,           _______, _______    ,          KC_6   , KC_7              , KC_8              , KC_9              , KC_0                 , KC_BSPC,
      KC_TAB     , KC_Q              , KC_W              , KC_E              , KC_R              , KC_T   ,           _______, _______    ,          KC_Y   , KC_U              , KC_I              , KC_O              , KC_P                 , SE_AA,
      MO(_NAV)   , MT(MOD_LGUI, KC_A), MT(MOD_LALT, KC_S), MT(MOD_LCTL, KC_D), MT(MOD_LSFT, KC_F), KC_G   ,           _______, _______    ,          KC_H   , MT(MOD_RGUI, KC_J), MT(MOD_RALT, KC_K), MT(MOD_RCTL, KC_L), MT(MOD_RSFT, SE_OSLH), LT(_NAV,SE_ADIA),
      SE_LESS    , KC_Z              , KC_X              , KC_C              , KC_V              , KC_B   , _______,  _______, TG(_GAME), _______, KC_N   , KC_M              , _______           , _______           , _______              , _______,
                                                           _______           , _______           , _______, KC_SPC ,  _______, _______    , KC_ENTER, _______, _______           , _______
    ),

    [_NAV] = LAYOUT(
      KC_F1  , KC_F2  , KC_F3  , KC_F4  , KC_F5  , KC_F6           ,          _______, _______,          KC_F7   , KC_F8  , KC_F9     , KC_F10  , KC_F11 , KC_F12,
      RGB_VAD, RGB_VAI, RGB_SPD, RGB_SPI, RGB_TOG, RGB_MODE_FORWARD,          _______, _______,          KC_HOME , KC_PGDN, KC_PAGE_UP, KC_END  , _______, _______,
      _______, _______, _______, _______, _______, _______         ,          _______, _______,          KC_LEFT , KC_DOWN, KC_UP     , KC_RIGHT, _______, _______,
      _______, _______, _______, _______, _______, SE_PLUS         , _______, KC_NO  , KC_NO  , _______, KC_COMMA, KC_DOT , SE_MINS   , SE_APOS , SE_DIAE, SE_ACUT,
                                 _______, _______, _______         , _______, _______, _______, _______, _______ , _______, _______
    ),

    [_GAME] = LAYOUT(
      _______, _______, _______, _______, _______, _______,          _______, _______,          _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______,          _______, _______,          _______, _______, _______, _______, _______, _______,
      _______, KC_A   , KC_S   , KC_D   , KC_F   , _______,          _______, _______,          _______, _______, _______, _______, _______, _______,
      _______, _______, _______, _______, _______, _______, _______, KC_NO  , _______, _______, _______, _______, _______, _______, _______, _______,
                                 _______, _______, _______, _______, _______, _______, _______, _______, _______, _______
    ),
};
// clang-format on

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    if (record->event.pressed) {
        num_keypresses = num_keypresses + 1;
        if (num_keypresses % GROW_RATE == 0) {
            if (current_frame < (ANIM_FRAMES - 1)) {
                current_frame = current_frame + 1;
            } else {
                current_frame = 0;
            }
        }
    }

    return true;
};

void oled_render_layer_state(void) {
    switch (get_highest_layer(layer_state)) {
        case _BASE:
            oled_write_raw_P(base_logo, sizeof(base_logo));
            break;
        case _NAV:
            oled_write_raw_P(sym_logo, sizeof(sym_logo));
            break;
        case _GAME:
            oled_write_raw_P(game_logo, sizeof(game_logo));
            break;
    }
}

void oled_render_animation_phase(void) {
    oled_write_raw_P(plant_anim[current_frame], sizeof(plant_anim[current_frame]));
}

bool oled_task_user(void) {
    bool is_oled_enabled = last_input_activity_elapsed() < 60000;

    if (!is_oled_enabled) {
        oled_off();
        return false;
    } else {
        oled_on();
    }

    if (is_keyboard_master()) {
        oled_render_animation_phase();
    } else {
        oled_render_layer_state();
    }

    return false;
}
