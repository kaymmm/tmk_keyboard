/*
 * kaymmm's custom Planck keyboard layout
 * Built with a Mac in mind, hence some of the macros
 */

#include "keymap_common.h"
/* might need this again if I revert to using the clear_keyboard->pause->bootloader_jump sequence instead of RESET
#include <util/delay.h> */
#include "bootloader.h"

/* Credit where it's due:
 * /u/jackhumbert for everything: https://github.com/jackhumbert/tmk_keyboard/
 * everyone who contributed their layouts to jack for inclusion in his repo
 * /u/totallymonkey for the defines: https://gist.github.com/totallymonkey/dd55da942622dad19b6b
 */

/* Planck keymap definition macro for the 'grid' layout:
 * ,-----------------------------------------------------------------------------------------------------------.
 * |        |        |        |        |        |        |        |        |        |        |        |        |
 * |-----------------------------------------------------------------------------------------------------------|
 * |        |        |        |        |        |        |        |        |        |        |        |        |
 * |-----------------------------------------------------------------------------------------------------------|
 * |        |        |        |        |        |        |        |        |        |        |        |        |
 * |-----------------------------------------------------------------------------------------------------------|
 * |        |        |        |        |        |        |        |        |        |        |        |        |
 * `-----------------------------------------------------------------------------------------------------------'
 */


#define BASE_LAYER 0
#define LOWER_LAYER 1
#define UPPER_LAYER 2
#define NUMPAD_LAYER 3
#define MISC_LAYER 4

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
/* BASE_LAYER: qwerty
 *
 *  ,-----------------------------------------------------------------------------------------------------------.
 *  |  `     |  q     |  w     |  e     |  r     |  t     |  y     |  u     |  i     |  o     |  p     |  BS    |
 *  |-----------------------------------------------------------------------------------------------------------|
 *  |  Tab   |  a     |  s     |  d     |  f     |  g     |  h     |  j     |  k     |  l     |  ;     |  Ret   |
 *  |-----------------------------------------------------------------------------------------------------------|
 *  |  Shift |  z     |  x     |  c     |  v     |  b     |  n     |  m     |  ,     |  .     |  /     |  Shift |
 *  |-----------------------------------------------------------------------------------------------------------|
 *  |  Ctrl  |  Alt   |  FN3   |  Meta  |  Space |  Lower |  Upper |  Space |  Left  |  Down  |  Up    |  Right |
 *  `-----------------------------------------------------------------------------------------------------------'
 */
[BASE_LAYER] = {
    {  KC_GRV,    KC_Q,    KC_W,    KC_E,    KC_R,    KC_T,    KC_Y,    KC_U,    KC_I,    KC_O,    KC_P, KC_BSPC},
    {  KC_TAB,    KC_A,    KC_S,    KC_D,    KC_F,    KC_G,    KC_H,    KC_J,    KC_K,    KC_L, KC_SCLN,  KC_ENT},
    { KC_LSFT,    KC_Z,    KC_X,    KC_C,    KC_V,    KC_B,    KC_N,    KC_M, KC_COMM,  KC_DOT, KC_SLSH, KC_RSFT},
    { KC_LCTL, KC_LALT,  KC_FN3, KC_LGUI,  KC_SPC,  KC_FN1,  KC_FN2,  KC_SPC, KC_LEFT, KC_DOWN,   KC_UP, KC_RGHT}
},

/* LOWER_LAYER/FN1: numbers, symbols, media keys
 *  ,_______________________________________________________________________________________________________________.
 *  |        |   a    |    s   |    d   |    f   |    g   |    h   |     j    |     k    |    l   |   ;    |        |
 *  +---------------------------------------------------------------------------------------------------------------+
 *  |    `   |   1    |   2    |   3    |   4    |   5    |   6    |    7     |    8     |   9    |   0    |    -   |
 *  |---------------------------------------------------------------------------------------------------------------|
 *  |        |  M-P/P |   M<-  |   M->  |########|########|   Del  |     {    |     }    |########|    '   |    =   |
 *  |---------------------------------------------------------------------------------------------------------------|
 *  |        |   Vx   |   V-   |   V+   |########|########|########|     [    |     ]    |########|    \   |        |
 *  |---------------------------------------------------------------------------------------------------------------|
 *  |        |        |        |        |        |        |        |          |    Home  |  PgDn  |  PgUp  |   End  |
 *  `---------------------------------------------------------------------------------------------------------------'
 */
[LOWER_LAYER] = {
    {  KC_GRV,    KC_1,    KC_2,    KC_3,    KC_4,    KC_5,    KC_6,      KC_7,      KC_8,    KC_9,    KC_0, KC_MINS},
    { KC_TRNS, KC_MPLY, KC_MPRV, KC_MNXT,   KC_NO,   KC_NO,  KC_DEL,S(KC_LBRC),S(KC_RBRC),   KC_NO, KC_QUOT,  KC_EQL},
    { KC_TRNS, KC_MUTE, KC_VOLD, KC_VOLU,   KC_NO,   KC_NO,   KC_NO,   KC_LBRC,   KC_RBRC,   KC_NO, KC_BSLS, KC_TRNS},
    { KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_TRNS,   KC_HOME, KC_PGDN, KC_PGUP,  KC_END}
},

/* UPPER_LAYER/FN2: Symbols, F-keys, Specials
 *   M-\: 1pass
 *   M-Tab: App switcher (fwd)
 *   M-Grv: App switcher (back)
 *   MAS-\: Alfred finder selection (*Need to map in Alfred)
 *
 *  ,__________________________________________________________________________________________________________________________.
 *  |        |   a    |    s   |    d   |    f   |    g   |    h   |     j      |     k      |    l       |   ;    |           |
 *  +--------------------------------------------------------------------------------------------------------------------------+
 *  |  ESC   |  !     |  @     |  #     |  $     |  %     |  ^     |  &         |  *         |  (         |        |  +        |
 *  |--------------------------------------------------------------------------------------------------------------------------|
 *  |        |  Login |  Email |########|########|########|########|  M-Tab     |  M-Grv     |  M-\       |  MAS-\ |  Del      |
 *  |--------------------------------------------------------------------------------------------------------------------------|
 *  |  F1    |  F2    |  F3    |  F4    |  F5    |  F6    |  F7    |  F8        |  F9        |  F10       |  F11   |  F12      |
 *  |--------------------------------------------------------------------------------------------------------------------------|
 *  |  Boot  |  Debug |        |        |        |        |        |            |            |            |        |           |
 *  `--------------------------------------------------------------------------------------------------------------------------'
 */
[UPPER_LAYER] = {
    {  KC_ESC, S(KC_1), S(KC_2), S(KC_3), S(KC_4), S(KC_5), S(KC_6),     S(KC_7),     S(KC_8),      S(KC_9), S(KC_0),S(KC_MINS)},
    { KC_TRNS, KC_FN20, KC_FN21,   KC_NO,   KC_NO,   KC_NO,   KC_NO,LGUI(KC_TAB),LGUI(KC_GRV),LGUI(KC_BSLS), KC_FN10,    KC_DEL},
    {   KC_F1,   KC_F2,   KC_F3,   KC_F4,   KC_F5,   KC_F6,   KC_F7,       KC_F8,       KC_F9,       KC_F10,  KC_F11,    KC_F12},
    {   RESET,   DEBUG, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,     KC_TRNS,     KC_TRNS,      KC_TRNS, KC_TRNS,   KC_TRNS}
},

/* NUMPAD_LAYER/FN3
 * arrows are ESDF, not WASD, for homerow finger placement
 *
 *  ,___________________________________________________________________________________________________________.
 *  |        |   a    |    s   |    d   |    f   |    g   |    h   |    j   |    k   |    l   |   ;    |        |
 *  +-----------------------------------------------------------------------------------------------------------+
 *  |        |########|########|    Up  |########|########|    P/  |    P7  |    P8  |    P9  |    P-  |    P*  |
 *  |-----------------------------------------------------------------------------------------------------------|
 *  |        |########|   Left |   Down |   Right|########|########|    P4  |    P5  |    P6  |    P+  |    =   |
 *  |-----------------------------------------------------------------------------------------------------------|
 *  |  F13   |   F14  |   F15  |   F16  |   F17  |   F18  |########|    P1  |    P2  |    P3  |   PEnt |        |
 *  |-----------------------------------------------------------------------------------------------------------|
 *  |        |        |        |        |        |        |        |    P0  |    ,   |    P.  |   PEnt |        |
 *  `-----------------------------------------------------------------------------------------------------------'
 */
[NUMPAD_LAYER] = {
    { KC_TRNS,   KC_NO,   KC_NO,   KC_UP,   KC_NO,   KC_NO, KC_PSLS,   KC_P7,   KC_P8,   KC_P9, KC_PMNS, KC_PAST},
    { KC_TRNS,   KC_NO, KC_LEFT, KC_DOWN, KC_RGHT,   KC_NO,   KC_NO,   KC_P4,   KC_P5,   KC_P6, KC_PPLS,  KC_EQL},
    {  KC_F13,  KC_F14,  KC_F15,  KC_F16,  KC_F17,  KC_F18,   KC_NO,   KC_P1,   KC_P2,   KC_P3, KC_PENT, KC_TRNS},
    { KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS, KC_TRNS,   KC_P0, KC_COMM, KC_PDOT, KC_PENT, KC_TRNS}
}};

enum macro_id {
    M_LOGIN,
    M_PASSWORD,
    M_EMAIL,
    M_BOOTLOADER
};


const uint16_t PROGMEM fn_actions[] = {
    [0]  = ACTION_DEFAULT_LAYER_SET(BASE_LAYER), // doesn't do anything
    [1]  = ACTION_LAYER_MOMENTARY(LOWER_LAYER),
    [2]  = ACTION_LAYER_MOMENTARY(UPPER_LAYER),
    [3]  = ACTION_LAYER_TOGGLE(NUMPAD_LAYER),
    [4]  = ACTION_LAYER_MOMENTARY(MISC_LAYER),
    [5]  = 0, // Future use
    [6]  = 0, // Future use
    [7]  = 0, // Future use
    [8]  = 0, // Future use
    [9]  = 0, // Future use

    // Meta modifiers
    [10] = ACTION_MODS_KEY(MOD_LGUI | MOD_LALT | MOD_LSFT, KC_BSLS),
    [11] = 0, // Future use
    [12] = 0, // Future use
    [13] = 0, // Future use
    [14] = 0, // Future use
    [15] = 0, // Future use
    [16] = 0, // Future use
    [17] = 0, // Future use
    [18] = 0, // Future use
    [19] = 0, // Future use

    // Special Macros
    [20] = ACTION_MACRO(M_LOGIN),
    [21] = ACTION_MACRO(M_EMAIL),
    [22] = ACTION_FUNCTION_TAP(M_BOOTLOADER)

};

const macro_t *action_get_macro(keyrecord_t *record, uint8_t id, uint8_t opt)
{
    switch(id) {
        case M_LOGIN:
            return ( record->event.pressed ?
                MACRO( I(0), T(K), T(M), T(I), T(Y), T(A), T(K), T(E), END ) :
                MACRO_NONE );
        case M_EMAIL:
            return ( record->event.pressed ?
                MACRO( I(0), T(K), T(E), T(I), T(T), T(H), T(DOT), T(M), T(I), T(Y), T(A), T(K), T(E), D(LSFT), T(2), U(LSFT), T(G), T(M), T(A), T(I), T(L), T(DOT), T(C), T(O), T(M), END ) :
                MACRO_NONE );
    }
    return MACRO_NONE;
};

/* to be removed once I determine the RESET KC is working correctly
void action_function(keyrecord_t *record, uint8_t id, uint8_t opt) {
    if (id == M_BOOTLOADER && record->tap.count > 1 ) {
        clear_keyboard();
         delay_ms(250);
        bootloader_jump();
    }
}
*/
