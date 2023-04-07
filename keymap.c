/*
Copyright 2019 @foostan
Copyright 2020 Drashna Jaelre <@drashna>

This program is free software: you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation, either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program.  If not, see <http://www.gnu.org/licenses/>.
*/

#include QMK_KEYBOARD_H
#include <stdio.h>

// Use friendly name for the layers
#define _CANARY 0
#define _EXT  1
#define _SYM  2
#define _NUM  3

// Saner keycode names for Extend
#define OSM_LALT OSM(MOD_LALT)
#define OSM_LGUI OSM(MOD_LGUI)
#define OSM_LSFT OSM(MOD_LSFT)
#define OSM_LCTL OSM(MOD_LCTL)
#define OSM_RALT OSM(MOD_RALT)

#define ALT_LEFT LALT(KC_LEFT)
#define ALT_RIGHT LALT(KC_RIGHT)

#define ZOOM_LESS LCTL(KC_MINS)
#define ZOOM_MORE LCTL(KC_EQL)


enum custom_keycodes {
    // :::: Layers ::::
    CANARY = SAFE_RANGE,
    EXT,
    SYM,
    NUM,

    // :::: Custom keycodes ::::
    C_UPDIR,
};


// :::: Macros ::::
bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    switch (keycode) {

    // Macro for ../ in the Symbols layer
    case C_UPDIR:
        if (record->event.pressed) {
            // When key is pressed
            SEND_STRING("../");
        } else {
            // When key is released
        }
        break;
    }

    return true;
};




const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
  [_CANARY] = LAYOUT_split_3x6_3(
    // ╭──────────┬──────────┬──────────┬──────────┬──────────┬──────────╮                              ╭──────────┬──────────┬──────────┬──────────┬──────────┬──────────╮
    // ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤                              ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
          KC_ESC    ,KC_W      ,KC_L      ,KC_Y      ,KC_P      ,KC_B      ,                               KC_Z      ,KC_F      ,KC_O      ,KC_U      ,KC_QUOT   ,KC_BSPC   ,
    // ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤                              ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
           KC_TAB   ,KC_C      ,KC_R      ,KC_S      ,KC_T      ,KC_G      ,                               KC_M      ,KC_N      ,KC_E      ,KC_I      ,KC_A      ,KC_BSLS    ,
    // ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼                              ┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
          KC_LGUI   ,KC_Q      ,KC_J      ,KC_V      ,KC_D      ,KC_K      ,                               KC_X      ,KC_H      ,KC_SLSH   ,KC_COMM   ,KC_DOT ,   KC_SCLN     ,
    // ╰──────────┴──────────┴──────────┴──────────┼──────────┼──────────┼──────────┤        ├──────────┼──────────┼──────────┼──────────┴──────────┴──────────┴──────────╯
                                                        KC_MEH  ,MO(_EXT)  ,KC_SPC    ,       SFT_T(KC_ENT), MO(_SYM), MO(_CANARY)
                                                // ╰──────────┴──────────┴──────────╯        ╰──────────┴──────────┴──────────╯
    ),



  [_EXT] = LAYOUT_split_3x6_3(
    // ╭──────────┬──────────┬──────────┬──────────┬──────────┬──────────╮                              ╭──────────┬──────────┬──────────┬──────────┬──────────┬──────────╮
    // ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤                              ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
        KC_TRNS   ,KC_ESC    ,ALT_LEFT  ,LCTL(KC_F),ALT_RIGHT ,KC_INS    ,                               KC_PGUP   ,KC_HOME      ,KC_UP     ,KC_END , KC_CAPS   ,KC_TRNS   ,
    // ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤                              ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
        KC_TRNS,    OSM_LALT  ,OSM_LGUI  ,OSM_LSFT  ,OSM_LCTL  ,OSM_RALT  ,                               KC_PGDN   ,KC_LEFT   ,KC_DOWN   ,KC_RGHT   ,KC_DEL    ,KC_TRNS   ,
    // ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────╮        ╭──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
        KC_TRNS   ,LCTL(KC_Z),LCTL(KC_X),LCTL(KC_C),KC_TAB    ,LCTL(KC_V),                               KC_ENT    ,KC_BSPC   ,KC_NO     ,KC_APP    ,KC_PSCR   ,KC_TRNS   ,
    // ╰──────────┴──────────┴──────────┴──────────┼──────────┼──────────┼──────────┤        ├──────────┼──────────┼──────────┼──────────┴──────────┴──────────┴──────────╯
                                                    KC_TRNS   ,KC_TRNS   ,KC_TRNS   ,         KC_TRNS    ,MO(_NUM)  ,KC_TRNS
                                                // ╰──────────┴──────────┴──────────╯        ╰──────────┴──────────┴──────────╯
    ),


  [_SYM] = LAYOUT_split_3x6_3(
    // ╭──────────┬──────────┬──────────┬──────────┬──────────┬──────────╮                              ╭──────────┬──────────┬──────────┬──────────┬──────────┬──────────╮
    // ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤                              ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
        KC_TRNS   ,KC_DLR    ,KC_LCBR   ,KC_RCBR   ,KC_ASTR   ,KC_CIRC   ,                               KC_PERC   ,KC_AT     ,KC_LT     ,KC_GT     ,C_UPDIR,   KC_TRNS   ,
    // ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤                              ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
        KC_TRNS   ,KC_SLSH   ,KC_LPRN   ,KC_RPRN   ,KC_UNDS   ,KC_AMPR   ,                               KC_HASH   ,KC_EQL    ,KC_MINS   ,KC_COLN   ,KC_EXLM   ,KC_TRNS   ,
    // ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────╮        ╭──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
        KC_TRNS   ,KC_TILD   ,KC_LBRC   ,KC_RBRC   ,KC_SCLN   ,KC_PIPE   ,                               KC_GRV    ,KC_DQUO   ,KC_PLUS   ,KC_BSLS   ,KC_QUES   ,KC_TRNS   ,
    // ╰──────────┴──────────┴──────────┴──────────┼──────────┼──────────┼──────────┤        ├──────────┼──────────┼──────────┼──────────┴──────────┴──────────┴──────────╯
                                                    KC_TRNS   ,MO(_NUM)  ,KC_TRNS   ,         KC_TRNS   ,KC_TRNS   ,KC_TRNS
                                                // ╰──────────┴──────────┴──────────╯        ╰──────────┴──────────┴──────────╯
    ),



  [_NUM] = LAYOUT_split_3x6_3(
    // ╭──────────┬──────────┬──────────┬──────────┬──────────┬──────────╮                              ╭──────────┬──────────┬──────────┬──────────┬──────────┬──────────╮
    // ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤                              ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
        KC_TRNS   ,KC_COMM   ,KC_1      ,KC_2      ,KC_3      ,KC_NO     ,                               KC_NO     ,KC_F1     ,KC_F2     ,KC_F3     ,KC_F10    ,KC_TRNS   ,
    // ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤                              ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
        KC_TRNS   ,KC_0      ,KC_4      ,KC_5      ,KC_6      ,KC_NO     ,                               KC_NO     ,KC_F4     ,KC_F5     ,KC_F6     ,KC_F11    ,KC_TRNS   ,
    // ├──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────╮        ╭──────────┼──────────┼──────────┼──────────┼──────────┼──────────┼──────────┤
        KC_TRNS   ,KC_DOT    ,KC_7      ,KC_8      ,KC_9      ,KC_NO     ,                               KC_NO     ,KC_F7     ,KC_F8     ,KC_F9     ,KC_F12    ,KC_TRNS   ,
    // ╰──────────┴──────────┴──────────┴──────────┼──────────┼──────────┼──────────┤        ├──────────┼──────────┼──────────┼──────────┴──────────┴──────────┴──────────╯
                                                    KC_TRNS   ,KC_TRNS   ,KC_TRNS   ,         KC_TRNS   ,KC_TRNS   ,KC_TRNS
                                                // ╰──────────┴──────────┴──────────╯        ╰──────────┴──────────┴──────────╯
    )


};
