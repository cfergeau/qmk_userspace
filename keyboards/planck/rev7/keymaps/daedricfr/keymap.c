
#include QMK_KEYBOARD_H

#include <stdint.h>

#include "keycodes.h"
#include "version.h"

#include "keymap_french.h"
#include "sendstring_french.h"

enum layers {
    Base,
    Qwerty,
    Dvorak,
    DK,
    Sym,
    Nav,
    NumFn,
    Adjust,
};

enum custom_keycodes {
    _FIRST = SAFE_RANGE,
    CKC_LMOVE_Base,
    CKC_LMOVE_Qwerty,
    CKC_LMOVE_Dvorak,
    CKC_LMOVE_DK,
    CKC_LMOVE_Sym,
    CKC_LMOVE_Nav,
    CKC_LMOVE_NumFn,
    CKC_LMOVE_Adjust,
    Base_EKC_SPC,
    DK_EKC_C,
    DK_EKC_A,
    DK_EKC_S,
    DK_EKC_E,
    Sym_EKC_C,
    Sym_EKC_O,
    Sym_EKC_W,
    Sym_EKC_J,
    Sym_EKC_D,
    Sym_EKC_DK,
    Sym_EKC_Y,
    Sym_EKC_A,
    Sym_EKC_N,
    Sym_EKC_F,
    Sym_EKC_L,
    Sym_EKC_R,
    Sym_EKC_T,
    Sym_EKC_I,
    Sym_EKC_U,
    Sym_EKC_Z,
    Sym_EKC_X,
    Sym_EKC_MNS,
    Sym_EKC_V,
    Sym_EKC_H,
    Sym_EKC_G,
    Sym_EKC_K,
};

#define DK_EKC_Q UP(LATIN_SMALL_LETTER_A_WITH_CIRCUMFLEX, LATIN_CAPITAL_LETTER_A_WITH_CIRCUMFLEX)
#define DK_EKC_O UP(LATIN_SMALL_LIGATURE_OE, LATIN_CAPITAL_LIGATURE_OE)
#define DK_EKC_P UP(LATIN_SMALL_LETTER_O_WITH_CIRCUMFLEX, LATIN_CAPITAL_LETTER_O_WITH_CIRCUMFLEX)
#define DK_EKC_M UM(MICRO_SIGN)
#define DK_EKC_DK UP(COMBINING_DIAERESIS, INVERTED_EXCLAMATION_MARK)
#define DK_EKC_Y UP(LATIN_SMALL_LETTER_U_WITH_CIRCUMFLEX, LATIN_CAPITAL_LETTER_U_WITH_CIRCUMFLEX)
#define DK_EKC_N UP(LATIN_SMALL_LETTER_E_WITH_CIRCUMFLEX, LATIN_CAPITAL_LETTER_E_WITH_CIRCUMFLEX)
#define DK_EKC_F UP(LATIN_SMALL_LETTER_N_WITH_TILDE, LATIN_CAPITAL_LETTER_N_WITH_TILDE)
#define DK_EKC_T UP(LATIN_SMALL_LETTER_I_WITH_CIRCUMFLEX, LATIN_CAPITAL_LETTER_I_WITH_CIRCUMFLEX)
#define DK_EKC_I UP(LATIN_SMALL_LETTER_I_WITH_DIAERESIS, LATIN_CAPITAL_LETTER_I_WITH_DIAERESIS)
#define DK_EKC_U UP(LATIN_SMALL_LETTER_U_WITH_GRAVE, LATIN_CAPITAL_LETTER_U_WITH_GRAVE)
#define DK_EKC_Z UP(LATIN_SMALL_LETTER_AE, LATIN_CAPITAL_LETTER_AE)
#define DK_EKC_X UP(LATIN_SMALL_LETTER_SHARP_S, LATIN_CAPITAL_LETTER_SHARP_S)
#define DK_EKC_MNS UP(NON_BREAKING_HYPHEN, INVERTED_QUESTION_MARK)
#define DK_EKC_V UM(EN_DASH)
#define DK_EKC_B UM(EM_DASH)
#define DK_EKC_COMM UP(MIDDLE_DOT, BULLET)
#define DK_EKC_SPC UM(RIGHT_SINGLE_QUOTATION_MARK)
#define Sym_EKC_Q UP(CIRCUMFLEX_ACCENT, COMBINING_CIRCUMFLEX_ACCENT)

enum unicode_names {
    LATIN_SMALL_LETTER_A_WITH_CIRCUMFLEX,
    LATIN_CAPITAL_LETTER_A_WITH_CIRCUMFLEX,
    CIRCUMFLEX_ACCENT,
    COMBINING_CIRCUMFLEX_ACCENT,
    LATIN_CAPITAL_LETTER_C_WITH_CEDILLA,
    LESS_THAN_OR_EQUAL_TO,
    LATIN_SMALL_LIGATURE_OE,
    LATIN_CAPITAL_LIGATURE_OE,
    GREATER_THAN_OR_EQUAL_TO,
    LATIN_SMALL_LETTER_O_WITH_CIRCUMFLEX,
    LATIN_CAPITAL_LETTER_O_WITH_CIRCUMFLEX,
    PER_MILLE_SIGN,
    COMBINING_RING_ABOVE,
    MICRO_SIGN,
    MULTIPLICATION_SIGN,
    COMBINING_DIAERESIS,
    INVERTED_EXCLAMATION_MARK,
    COMBINING_ACUTE_ACCENT,
    LATIN_SMALL_LETTER_U_WITH_CIRCUMFLEX,
    LATIN_CAPITAL_LETTER_U_WITH_CIRCUMFLEX,
    COMBINING_GRAVE_ACCENT,
    LATIN_CAPITAL_LETTER_A_WITH_GRAVE,
    COMBINING_CARON,
    LATIN_CAPITAL_LETTER_E_WITH_ACUTE,
    LATIN_CAPITAL_LETTER_E_WITH_GRAVE,
    LATIN_SMALL_LETTER_E_WITH_CIRCUMFLEX,
    LATIN_CAPITAL_LETTER_E_WITH_CIRCUMFLEX,
    COMBINING_DOT_ABOVE,
    LATIN_SMALL_LETTER_N_WITH_TILDE,
    LATIN_CAPITAL_LETTER_N_WITH_TILDE,
    NOT_EQUAL_TO,
    COMBINING_LONG_SOLIDUS_OVERLAY,
    PLUS_SIGN_ABOVE_EQUALS_SIGN,
    LATIN_SMALL_LETTER_I_WITH_CIRCUMFLEX,
    LATIN_CAPITAL_LETTER_I_WITH_CIRCUMFLEX,
    COMBINING_MACRON,
    LATIN_SMALL_LETTER_I_WITH_DIAERESIS,
    LATIN_CAPITAL_LETTER_I_WITH_DIAERESIS,
    DIVISION_SIGN,
    LATIN_SMALL_LETTER_U_WITH_GRAVE,
    LATIN_CAPITAL_LETTER_U_WITH_GRAVE,
    COMBINING_DOUBLE_ACUTE_ACCENT,
    LATIN_SMALL_LETTER_AE,
    LATIN_CAPITAL_LETTER_AE,
    COMBINING_TILDE,
    LATIN_SMALL_LETTER_SHARP_S,
    LATIN_CAPITAL_LETTER_SHARP_S,
    COMBINING_COMMA_BELOW,
    NON_BREAKING_HYPHEN,
    INVERTED_QUESTION_MARK,
    COMBINING_OGONEK,
    EN_DASH,
    EM_DASH,
    HORIZONTAL_ELLIPSIS,
    BROKEN_BAR,
    NOT_SIGN,
    COMBINING_TURNED_COMMA_ABOVE,
    MIDDLE_DOT,
    BULLET,
    COMBINING_BREVE,
    EURO_SIGN,
    DOUBLE_LOW_9_QUOTATION_MARK,
    SINGLE_LOW_9_QUOTATION_MARK,
    SUBSCRIPT_ONE,
    SUPERSCRIPT_ONE,
    LEFT_POINTING_DOUBLE_ANGLE_QUOTATION_MARK,
    LEFT_DOUBLE_QUOTATION_MARK,
    LEFT_SINGLE_QUOTATION_MARK,
    SUBSCRIPT_TWO,
    SUPERSCRIPT_TWO,
    RIGHT_POINTING_DOUBLE_ANGLE_QUOTATION_MARK,
    RIGHT_DOUBLE_QUOTATION_MARK,
    RIGHT_SINGLE_QUOTATION_MARK,
    SUBSCRIPT_THREE,
    SUPERSCRIPT_THREE,
    CENT_SIGN,
    SUBSCRIPT_FOUR,
    SUPERSCRIPT_FOUR,
    SUBSCRIPT_FIVE,
    SUPERSCRIPT_FIVE,
    SUBSCRIPT_SIX,
    SUPERSCRIPT_SIX,
    SUBSCRIPT_SEVEN,
    SUPERSCRIPT_SEVEN,
    SUBSCRIPT_EIGHT,
    SUPERSCRIPT_EIGHT,
    PILCROW_SIGN,
    SUBSCRIPT_NINE,
    SUPERSCRIPT_NINE,
    SUBSCRIPT_ZERO,
    SUPERSCRIPT_ZERO,
    NARROW_NO_BREAK_SPACE,
};

const uint32_t PROGMEM unicode_map[] = {
    [LATIN_SMALL_LETTER_A_WITH_CIRCUMFLEX]       = 0x00e2 /* â */,
    [LATIN_CAPITAL_LETTER_A_WITH_CIRCUMFLEX]     = 0x00c2 /* Â */,
    [CIRCUMFLEX_ACCENT]                          = 0x005e /* ^ */,
    [COMBINING_CIRCUMFLEX_ACCENT]                = 0x0302 /* ̂ */,
    [LATIN_CAPITAL_LETTER_C_WITH_CEDILLA]        = 0x00c7 /* Ç */,
    [LESS_THAN_OR_EQUAL_TO]                      = 0x2264 /* ≤ */,
    [LATIN_SMALL_LIGATURE_OE]                    = 0x0153 /* œ */,
    [LATIN_CAPITAL_LIGATURE_OE]                  = 0x0152 /* Œ */,
    [GREATER_THAN_OR_EQUAL_TO]                   = 0x2265 /* ≥ */,
    [LATIN_SMALL_LETTER_O_WITH_CIRCUMFLEX]       = 0x00f4 /* ô */,
    [LATIN_CAPITAL_LETTER_O_WITH_CIRCUMFLEX]     = 0x00d4 /* Ô */,
    [PER_MILLE_SIGN]                             = 0x2030 /* ‰ */,
    [COMBINING_RING_ABOVE]                       = 0x030a /* ̊ */,
    [MICRO_SIGN]                                 = 0x00b5 /* µ */,
    [MULTIPLICATION_SIGN]                        = 0x00d7 /* × */,
    [COMBINING_DIAERESIS]                        = 0x0308 /* ̈ */,
    [INVERTED_EXCLAMATION_MARK]                  = 0x00a1 /* ¡ */,
    [COMBINING_ACUTE_ACCENT]                     = 0x0301 /* ́ */,
    [LATIN_SMALL_LETTER_U_WITH_CIRCUMFLEX]       = 0x00fb /* û */,
    [LATIN_CAPITAL_LETTER_U_WITH_CIRCUMFLEX]     = 0x00db /* Û */,
    [COMBINING_GRAVE_ACCENT]                     = 0x0300 /* ̀ */,
    [LATIN_CAPITAL_LETTER_A_WITH_GRAVE]          = 0x00c0 /* À */,
    [COMBINING_CARON]                            = 0x030c /* ̌ */,
    [LATIN_CAPITAL_LETTER_E_WITH_ACUTE]          = 0x00c9 /* É */,
    [LATIN_CAPITAL_LETTER_E_WITH_GRAVE]          = 0x00c8 /* È */,
    [LATIN_SMALL_LETTER_E_WITH_CIRCUMFLEX]       = 0x00ea /* ê */,
    [LATIN_CAPITAL_LETTER_E_WITH_CIRCUMFLEX]     = 0x00ca /* Ê */,
    [COMBINING_DOT_ABOVE]                        = 0x0307 /* ̇ */,
    [LATIN_SMALL_LETTER_N_WITH_TILDE]            = 0x00f1 /* ñ */,
    [LATIN_CAPITAL_LETTER_N_WITH_TILDE]          = 0x00d1 /* Ñ */,
    [NOT_EQUAL_TO]                               = 0x2260 /* ≠ */,
    [COMBINING_LONG_SOLIDUS_OVERLAY]             = 0x0338 /* ̸ */,
    [PLUS_SIGN_ABOVE_EQUALS_SIGN]                = 0x2a72 /* ⩲ */,
    [LATIN_SMALL_LETTER_I_WITH_CIRCUMFLEX]       = 0x00ee /* î */,
    [LATIN_CAPITAL_LETTER_I_WITH_CIRCUMFLEX]     = 0x00ce /* Î */,
    [COMBINING_MACRON]                           = 0x0304 /* ̄ */,
    [LATIN_SMALL_LETTER_I_WITH_DIAERESIS]        = 0x00ef /* ï */,
    [LATIN_CAPITAL_LETTER_I_WITH_DIAERESIS]      = 0x00cf /* Ï */,
    [DIVISION_SIGN]                              = 0x00f7 /* ÷ */,
    [LATIN_SMALL_LETTER_U_WITH_GRAVE]            = 0x00f9 /* ù */,
    [LATIN_CAPITAL_LETTER_U_WITH_GRAVE]          = 0x00d9 /* Ù */,
    [COMBINING_DOUBLE_ACUTE_ACCENT]              = 0x030b /* ̋ */,
    [LATIN_SMALL_LETTER_AE]                      = 0x00e6 /* æ */,
    [LATIN_CAPITAL_LETTER_AE]                    = 0x00c6 /* Æ */,
    [COMBINING_TILDE]                            = 0x0303 /* ̃ */,
    [LATIN_SMALL_LETTER_SHARP_S]                 = 0x00df /* ß */,
    [LATIN_CAPITAL_LETTER_SHARP_S]               = 0x1e9e /* ẞ */,
    [COMBINING_COMMA_BELOW]                      = 0x0326 /* ̦ */,
    [NON_BREAKING_HYPHEN]                        = 0x2011 /* ‑ */,
    [INVERTED_QUESTION_MARK]                     = 0x00bf /* ¿ */,
    [COMBINING_OGONEK]                           = 0x0328 /* ̨ */,
    [EN_DASH]                                    = 0x2013 /* – */,
    [EM_DASH]                                    = 0x2014 /* — */,
    [HORIZONTAL_ELLIPSIS]                        = 0x2026 /* … */,
    [BROKEN_BAR]                                 = 0x00a6 /* ¦ */,
    [NOT_SIGN]                                   = 0x00ac /* ¬ */,
    [COMBINING_TURNED_COMMA_ABOVE]               = 0x0312 /* ̒ */,
    [MIDDLE_DOT]                                 = 0x00b7 /* · */,
    [BULLET]                                     = 0x2022 /* • */,
    [COMBINING_BREVE]                            = 0x0306 /* ̆ */,
    [EURO_SIGN]                                  = 0x20ac /* € */,
    [DOUBLE_LOW_9_QUOTATION_MARK]                = 0x201e /* „ */,
    [SINGLE_LOW_9_QUOTATION_MARK]                = 0x201a /* ‚ */,
    [SUBSCRIPT_ONE]                              = 0x2081 /* ₁ */,
    [SUPERSCRIPT_ONE]                            = 0x00b9 /* ¹ */,
    [LEFT_POINTING_DOUBLE_ANGLE_QUOTATION_MARK]  = 0x00ab /* « */,
    [LEFT_DOUBLE_QUOTATION_MARK]                 = 0x201c /* “ */,
    [LEFT_SINGLE_QUOTATION_MARK]                 = 0x2018 /* ‘ */,
    [SUBSCRIPT_TWO]                              = 0x2082 /* ₂ */,
    [SUPERSCRIPT_TWO]                            = 0x00b2 /* ² */,
    [RIGHT_POINTING_DOUBLE_ANGLE_QUOTATION_MARK] = 0x00bb /* » */,
    [RIGHT_DOUBLE_QUOTATION_MARK]                = 0x201d /* ” */,
    [RIGHT_SINGLE_QUOTATION_MARK]                = 0x2019 /* ’ */,
    [SUBSCRIPT_THREE]                            = 0x2083 /* ₃ */,
    [SUPERSCRIPT_THREE]                          = 0x00b3 /* ³ */,
    [CENT_SIGN]                                  = 0x00a2 /* ¢ */,
    [SUBSCRIPT_FOUR]                             = 0x2084 /* ₄ */,
    [SUPERSCRIPT_FOUR]                           = 0x2074 /* ⁴ */,
    [SUBSCRIPT_FIVE]                             = 0x2085 /* ₅ */,
    [SUPERSCRIPT_FIVE]                           = 0x2075 /* ⁵ */,
    [SUBSCRIPT_SIX]                              = 0x2086 /* ₆ */,
    [SUPERSCRIPT_SIX]                            = 0x2076 /* ⁶ */,
    [SUBSCRIPT_SEVEN]                            = 0x2087 /* ₇ */,
    [SUPERSCRIPT_SEVEN]                          = 0x2077 /* ⁷ */,
    [SUBSCRIPT_EIGHT]                            = 0x2088 /* ₈ */,
    [SUPERSCRIPT_EIGHT]                          = 0x2078 /* ⁸ */,
    [PILCROW_SIGN]                               = 0x00b6 /* ¶ */,
    [SUBSCRIPT_NINE]                             = 0x2089 /* ₉ */,
    [SUPERSCRIPT_NINE]                           = 0x2079 /* ⁹ */,
    [SUBSCRIPT_ZERO]                             = 0x2080 /* ₀ */,
    [SUPERSCRIPT_ZERO]                           = 0x2070 /* ⁰ */,
    [NARROW_NO_BREAK_SPACE]                      = 0x202f /*   */,
};

const key_override_t Base_EKC_DK   = ko_make_with_layers(MOD_MASK_SHIFT, OSL(DK), KC_EXLM, (1 << Base));
const key_override_t Base_EKC_MNS  = ko_make_with_layers(MOD_MASK_SHIFT, FR_MINS, FR_QUES, (1 << Base));
const key_override_t Base_EKC_COMM = ko_make_with_layers(MOD_MASK_SHIFT, FR_COMM, FR_SCLN, (1 << Base));
const key_override_t DK_EKC_D      = ko_make_with_layers(MOD_MASK_SHIFT, FR_UNDS, FR_UNDS, (1 << DK));
const key_override_t DK_EKC_L      = ko_make_with_layers(MOD_MASK_SHIFT, FR_LPRN, FR_LPRN, (1 << DK));
const key_override_t DK_EKC_R      = ko_make_with_layers(MOD_MASK_SHIFT, FR_RPRN, FR_RPRN, (1 << DK));
const key_override_t Sym_EKC_P     = ko_make_with_layers(MOD_MASK_SHIFT, FR_DLR, FR_DLR, (1 << Sym));
const key_override_t Sym_EKC_M     = ko_make_with_layers(MOD_MASK_SHIFT, FR_AMPR, FR_AMPR, (1 << Sym));
const key_override_t Sym_EKC_S     = ko_make_with_layers(MOD_MASK_SHIFT, FR_LPRN, FR_LPRN, (1 << Sym));
const key_override_t Sym_EKC_E     = ko_make_with_layers(MOD_MASK_SHIFT, FR_RPRN, FR_RPRN, (1 << Sym));
const key_override_t Sym_EKC_B     = ko_make_with_layers(MOD_MASK_SHIFT, FR_HASH, FR_HASH, (1 << Sym));
const key_override_t Sym_EKC_COMM  = ko_make_with_layers(MOD_MASK_SHIFT, FR_COLN, FR_COLN, (1 << Sym));
const key_override_t Sym_EKC_SPC   = ko_make_with_layers(MOD_MASK_SHIFT, KC_SPC, KC_SPC, (1 << Sym));

const key_override_t *key_overrides[] = (const key_override_t *[]){
    &Base_EKC_DK, &Base_EKC_MNS, &Base_EKC_COMM, &DK_EKC_D, &DK_EKC_L, &DK_EKC_R, &Sym_EKC_P, &Sym_EKC_M, &Sym_EKC_S, &Sym_EKC_E, &Sym_EKC_B, &Sym_EKC_COMM, &Sym_EKC_SPC, NULL,
};

const uint16_t PROGMEM keymaps[][MATRIX_ROWS][MATRIX_COLS] = {
    [Base] = LAYOUT(
        // clang-format off

           KC_TAB   ,     FR_Q    ,     FR_C    ,     FR_O    ,     FR_P    ,     FR_W    ,       FR_J    ,     FR_M    ,     FR_D    ,   OSL(DK)   ,     FR_Y    ,   KC_BSPC   ,
           KC_ESC   ,     FR_A    ,     FR_S    ,     FR_E    ,     FR_N    ,     FR_F    ,       FR_L    ,     FR_R    ,     FR_T    ,     FR_I    ,     FR_U    ,   KC_QUOT   ,
          KC_LSFT   ,     FR_Z    ,     FR_X    ,   FR_MINS   ,     FR_V    ,     FR_B    ,      KC_DOT   ,     FR_H    ,     FR_G    ,   FR_COMM   ,     FR_K    ,    KC_ENT   ,
          KC_LCTL   ,   KC_LGUI   ,   KC_LALT   ,   _______   ,  MO(NumFn)  ,   XXXXXXX   ,   Base_EKC_SPC,   MO(Sym)   ,   KC_LEFT   ,   KC_DOWN   ,    KC_UP    ,   KC_RIGHT

        // clang-format on
        ),
    [Qwerty] = LAYOUT(
        // clang-format off

         KC_TAB  ,   KC_Q   ,   KC_W   ,   KC_E   ,   KC_R   ,   KC_T   ,     KC_Y   ,   KC_U   ,   KC_I   ,   KC_O   ,   KC_P   ,  KC_BSPC ,
         KC_ESC  ,   KC_A   ,   KC_S   ,   KC_D   ,   KC_F   ,   KC_G   ,     KC_H   ,   KC_J   ,   KC_K   ,   KC_L   ,  KC_SCLN ,  KC_QUOT ,
         KC_LSFT ,   KC_Z   ,   KC_X   ,   KC_C   ,   KC_V   ,   KC_B   ,     KC_N   ,   KC_M   ,  KC_COMM ,  KC_DOT  ,  KC_SLSH ,  KC_ENT  ,
         KC_LCTL ,  KC_LGUI ,  KC_LALT ,  _______ , MO(NumFn),  XXXXXXX ,    KC_SPC  ,  MO(Sym) ,  OSL(DK) ,  KC_DOWN ,   KC_UP  ,  KC_RCTL

        // clang-format on
        ),
    [Dvorak] = LAYOUT(
        // clang-format off

         KC_TAB  ,  KC_SCLN ,  KC_COMM ,  KC_DOT  ,   KC_P   ,   KC_Y   ,     KC_F   ,   KC_G   ,   KC_C   ,   KC_R   ,   KC_L   ,  KC_BSPC ,
         KC_ESC  ,   KC_A   ,   KC_O   ,   KC_E   ,   KC_U   ,   KC_I   ,     KC_D   ,   KC_H   ,   KC_T   ,   KC_N   ,   KC_S   ,  KC_SLSH ,
         KC_LSFT ,  KC_QUOT ,   KC_Q   ,   KC_J   ,   KC_K   ,   KC_X   ,     KC_B   ,   KC_M   ,   KC_W   ,   KC_V   ,   KC_Z   ,  KC_ENT  ,
         KC_LCTL ,  KC_LGUI ,  KC_LALT ,  _______ , MO(NumFn),  XXXXXXX ,    KC_SPC  ,  MO(Sym) ,  OSL(DK) ,  KC_DOWN ,   KC_UP  ,  KC_RCTL

        // clang-format on
        ),
    [DK] = LAYOUT(
        // clang-format off

          _______  ,  DK_EKC_Q  ,  DK_EKC_C  ,  DK_EKC_O  ,  DK_EKC_P  ,   _______  ,     _______  ,  DK_EKC_M  ,   FR_UNDS  ,  DK_EKC_DK ,  DK_EKC_Y  ,   _______  ,
          _______  ,  DK_EKC_A  ,  DK_EKC_S  ,  DK_EKC_E  ,  DK_EKC_N  ,  DK_EKC_F  ,     FR_LPRN  ,   FR_RPRN  ,  DK_EKC_T  ,  DK_EKC_I  ,  DK_EKC_U  ,   _______  ,
          _______  ,  DK_EKC_Z  ,  DK_EKC_X  , DK_EKC_MNS ,  DK_EKC_V  ,  DK_EKC_B  ,     _______  ,   _______  ,   _______  , DK_EKC_COMM,   _______  ,   _______  ,
          _______  ,   _______  ,   _______  ,   _______  ,   _______  ,   _______  ,   DK_EKC_SPC ,   _______  ,   _______  ,   _______  ,   _______  ,   _______

        // clang-format on
        ),
    [Sym] = LAYOUT(
        // clang-format off

          _______  ,  Sym_EKC_Q ,  Sym_EKC_C ,  Sym_EKC_O ,   FR_DLR   ,  Sym_EKC_W ,    Sym_EKC_J ,   FR_AMPR  ,  Sym_EKC_D , Sym_EKC_DK ,  Sym_EKC_Y ,   _______  ,
          _______  ,  Sym_EKC_A ,   FR_LPRN  ,   FR_RPRN  ,  Sym_EKC_N ,  Sym_EKC_F ,    Sym_EKC_L ,  Sym_EKC_R ,  Sym_EKC_T ,  Sym_EKC_I ,  Sym_EKC_U ,   _______  ,
          _______  ,  Sym_EKC_Z ,  Sym_EKC_X , Sym_EKC_MNS,  Sym_EKC_V ,   FR_HASH  ,     _______  ,  Sym_EKC_H ,  Sym_EKC_G ,   FR_COLN  ,  Sym_EKC_K ,   _______  ,
          _______  ,   _______  ,   _______  ,   _______  ,   _______  ,   _______  ,     KC_SPC   ,   _______  ,   _______  ,   _______  ,   _______  ,   _______

        // clang-format on
        ),
    [Nav] = LAYOUT(
        // clang-format off

         KC_GRV  ,  KC_DLR  ,   KC_7   ,   KC_8   ,   KC_9   ,  XXXXXXX ,    KC_HOME ,  KC_PGDN ,  KC_PGUP ,  KC_END  ,  KC_DEL  ,  KC_BSPC ,
         KC_ESC  ,   KC_0   ,   KC_4   ,   KC_5   ,   KC_6   ,   KC_0   ,    KC_LEFT ,  KC_DOWN ,   KC_UP  ,  KC_RGHT ,  KC_BSPC ,  KC_QUOT ,
         KC_LSFT ,  KC_COMM ,   KC_1   ,   KC_2   ,   KC_3   ,  KC_DOT  ,    KC_HOME ,  KC_PGDN ,  KC_PGUP ,  KC_END  ,  KC_DEL  ,  KC_ENT  ,
         KC_RSFT ,  KC_LCTL ,  KC_LALT ,  KC_LGUI , MO(NumFn),  XXXXXXX ,    KC_SPC  ,  MO(Sym) ,  KC_LEFT ,  KC_DOWN ,   KC_UP  ,  KC_RGHT

        // clang-format on
        ),
    [NumFn] = LAYOUT(
        // clang-format off

        KC_TILD,  KC_1  ,  KC_2  ,  KC_3  ,  KC_4  ,  KC_5  ,    KC_6  ,  KC_7  ,  KC_8  ,  KC_9  ,  KC_0  , KC_BSPC,
        KC_DEL ,  KC_F1 ,  KC_F2 ,  KC_F3 ,  KC_F4 ,  KC_F5 ,    KC_F6 , KC_DOT , KC_COMM, XXXXXXX, KC_DLR , KC_PIPE,
        CW_TOGG,  KC_F7 ,  KC_F8 ,  KC_F9 , KC_F10 , KC_F11 ,   KC_F12 , _______, _______, _______, _______, _______,
        _______, _______, _______, _______, _______, _______,   _______, MO(Sym), KC_MNXT, KC_VOLD, KC_VOLU, KC_MPLY

        // clang-format on
        ),
    [Adjust] = LAYOUT(
        // clang-format off

            _______     ,     QK_BOOT     ,     DB_TOGG     ,     UG_TOGG     ,     UG_NEXT     ,     UG_HUEU     ,       UG_HUED     ,     UG_SATU     ,     UG_SATD     ,     UG_SPDU     ,     UG_SPDD     ,      KC_DEL     ,
            _______     ,      EE_CLR     ,     MU_NEXT     ,      AU_ON      ,      AU_OFF     ,     _______     ,       _______     , CKC_LMOVE_Qwerty,  CKC_LMOVE_Base , CKC_LMOVE_Dvorak,     _______     ,     _______     ,
            _______     ,     AU_PREV     ,     AU_NEXT     ,      MU_ON      ,      MU_OFF     ,     _______     ,       _______     ,     UC_PREV     ,     UC_NEXT     ,     UC_LINX     ,     _______     ,     _______     ,
            _______     ,     _______     ,     _______     ,     _______     ,     _______     ,     _______     ,       _______     ,     _______     ,     _______     ,     _______     ,     _______     ,     _______

        // clang-format on
        ),
};

bool process_record_user(uint16_t keycode, keyrecord_t *record) {
    const bool key_pressed = record->event.pressed;
    const bool shifted     = (get_mods() & MOD_MASK_SHIFT) != 0;
    uint16_t   kc;
    uint8_t    skc_idx;
    switch (keycode) {
        default:
            return true;

        case CKC_LMOVE_Base:
            layer_move(Base);
            return false;
            break;

        case CKC_LMOVE_Qwerty:
            layer_move(Qwerty);
            return false;
            break;

        case CKC_LMOVE_Dvorak:
            layer_move(Dvorak);
            return false;
            break;

        case CKC_LMOVE_DK:
            layer_move(DK);
            return false;
            break;

        case CKC_LMOVE_Sym:
            layer_move(Sym);
            return false;
            break;

        case CKC_LMOVE_Nav:
            layer_move(Nav);
            return false;
            break;

        case CKC_LMOVE_NumFn:
            layer_move(NumFn);
            return false;
            break;

        case CKC_LMOVE_Adjust:
            layer_move(Adjust);
            return false;
            break;

        case Base_EKC_SPC:
            kc      = KC_SPC;
            skc_idx = NARROW_NO_BREAK_SPACE;
            break;

        case DK_EKC_C:
            kc      = FR_CCED;
            skc_idx = LATIN_CAPITAL_LETTER_C_WITH_CEDILLA;
            break;

        case DK_EKC_A:
            kc      = FR_AGRV;
            skc_idx = LATIN_CAPITAL_LETTER_A_WITH_GRAVE;
            break;

        case DK_EKC_S:
            kc      = FR_EACU;
            skc_idx = LATIN_CAPITAL_LETTER_E_WITH_ACUTE;
            break;

        case DK_EKC_E:
            kc      = FR_EGRV;
            skc_idx = LATIN_CAPITAL_LETTER_E_WITH_GRAVE;
            break;

        case Sym_EKC_C:
            kc      = FR_LABK;
            skc_idx = LESS_THAN_OR_EQUAL_TO;
            break;

        case Sym_EKC_O:
            kc      = FR_RABK;
            skc_idx = GREATER_THAN_OR_EQUAL_TO;
            break;

        case Sym_EKC_W:
            kc      = FR_PERC;
            skc_idx = PER_MILLE_SIGN;
            break;

        case Sym_EKC_J:
            kc      = FR_AT;
            skc_idx = COMBINING_RING_ABOVE;
            break;

        case Sym_EKC_D:
            kc      = FR_ASTR;
            skc_idx = MULTIPLICATION_SIGN;
            break;

        case Sym_EKC_DK:
            kc      = FR_QUOT;
            skc_idx = COMBINING_ACUTE_ACCENT;
            break;

        case Sym_EKC_Y:
            kc      = FR_GRV;
            skc_idx = COMBINING_GRAVE_ACCENT;
            break;

        case Sym_EKC_A:
            kc      = FR_LCBR;
            skc_idx = COMBINING_CARON;
            break;

        case Sym_EKC_N:
            kc      = FR_RCBR;
            skc_idx = COMBINING_DOT_ABOVE;
            break;

        case Sym_EKC_F:
            kc      = FR_EQL;
            skc_idx = NOT_EQUAL_TO;
            break;

        case Sym_EKC_L:
            kc      = FR_BSLS;
            skc_idx = COMBINING_LONG_SOLIDUS_OVERLAY;
            break;

        case Sym_EKC_R:
            kc      = FR_PLUS;
            skc_idx = PLUS_SIGN_ABOVE_EQUALS_SIGN;
            break;

        case Sym_EKC_T:
            kc      = FR_MINS;
            skc_idx = COMBINING_MACRON;
            break;

        case Sym_EKC_I:
            kc      = FR_SLSH;
            skc_idx = DIVISION_SIGN;
            break;

        case Sym_EKC_U:
            kc      = FR_DQUO;
            skc_idx = COMBINING_DOUBLE_ACUTE_ACCENT;
            break;

        case Sym_EKC_Z:
            kc      = FR_TILD;
            skc_idx = COMBINING_TILDE;
            break;

        case Sym_EKC_X:
            kc      = FR_LBRC;
            skc_idx = COMBINING_COMMA_BELOW;
            break;

        case Sym_EKC_MNS:
            kc      = FR_RBRC;
            skc_idx = COMBINING_OGONEK;
            break;

        case Sym_EKC_V:
            kc      = FR_UNDS;
            skc_idx = EN_DASH;
            break;

        case Sym_EKC_H:
            kc      = FR_EXLM;
            skc_idx = NOT_SIGN;
            break;

        case Sym_EKC_G:
            kc      = FR_SCLN;
            skc_idx = COMBINING_TURNED_COMMA_ABOVE;
            break;

        case Sym_EKC_K:
            kc      = FR_QUES;
            skc_idx = COMBINING_BREVE;
            break;
    }

    if (shifted) {
        if (key_pressed) {
            uint8_t temp_mod = get_mods();
            clear_mods();
            uint32_t skc = unicodemap_get_code_point(skc_idx);
            register_unicode(skc);
            set_mods(temp_mod);
            return false;
        }
    } else {
        if (key_pressed) {
            register_code16(kc);
        } else {
            unregister_code16(kc);
        }
    }

    return true;
}
