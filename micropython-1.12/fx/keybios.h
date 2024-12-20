/*****************************************************************/
/*                                                               */
/*   CASIO fx-9860G SDK Library                                  */
/*                                                               */
/*   File name : keybios.h                                       */
/*                                                               */
/*   Copyright (c) 2006 CASIO COMPUTER CO., LTD.                 */
/*                                                               */
/*****************************************************************/
#ifndef __KEYBIOS_H__
#define __KEYBIOS_H__

#ifdef __cplusplus
extern "C" {
#endif

// Defines

// Character codes
#define KEY_CHAR_0          0x30
#define KEY_CHAR_1          0x31
#define KEY_CHAR_2          0x32
#define KEY_CHAR_3          0x33
#define KEY_CHAR_4          0x34
#define KEY_CHAR_5          0x35
#define KEY_CHAR_6          0x36
#define KEY_CHAR_7          0x37
#define KEY_CHAR_8          0x38
#define KEY_CHAR_9          0x39
#define KEY_CHAR_DP         0x2e
#define KEY_CHAR_EXP        0x0f
#define KEY_CHAR_PMINUS     0x87
#define KEY_CHAR_PLUS       0x89
#define KEY_CHAR_MINUS      0x99
#define KEY_CHAR_MULT       0xa9
#define KEY_CHAR_DIV        0xb9
#define KEY_CHAR_FRAC       0xbb
#define KEY_CHAR_LPAR       0x28
#define KEY_CHAR_RPAR       0x29
#define KEY_CHAR_COMMA      0x2c
#define KEY_CHAR_STORE      0x0e
#define KEY_CHAR_LOG        0x95
#define KEY_CHAR_LN         0x85
#define KEY_CHAR_SIN        0x81
#define KEY_CHAR_COS        0x82
#define KEY_CHAR_TAN        0x83
#define KEY_CHAR_SQUARE     0x8b
#define KEY_CHAR_POW        0xa8
#define KEY_CHAR_IMGNRY     0x7f50
#define KEY_CHAR_LIST       0x7f51
#define KEY_CHAR_MAT        0x7f40
#define KEY_CHAR_EQUAL      0x3d
#define KEY_CHAR_PI         0xd0
#define KEY_CHAR_ANS        0xc0
#define KEY_CHAR_LBRCKT     0x5b
#define KEY_CHAR_RBRCKT     0x5d
#define KEY_CHAR_LBRACE     0x7b
#define KEY_CHAR_RBRACE     0x7d
#define KEY_CHAR_CR         0x0d
#define KEY_CHAR_CUBEROOT   0x96
#define KEY_CHAR_RECIP      0x9b
#define KEY_CHAR_ANGLE      0x7f54
#define KEY_CHAR_EXPN10     0xb5
#define KEY_CHAR_EXPN       0xa5
#define KEY_CHAR_ASIN       0x91
#define KEY_CHAR_ACOS       0x92
#define KEY_CHAR_ATAN       0x93
#define KEY_CHAR_ROOT       0x86
#define KEY_CHAR_POWROOT    0xb8
#define KEY_CHAR_SPACE      0x20
#define KEY_CHAR_DQUATE     0x22
#define KEY_CHAR_VALR       0xcd
#define KEY_CHAR_THETA      0xce
#define KEY_CHAR_A          0x41
#define KEY_CHAR_B          0x42
#define KEY_CHAR_C          0x43
#define KEY_CHAR_D          0x44
#define KEY_CHAR_E          0x45
#define KEY_CHAR_F          0x46
#define KEY_CHAR_G          0x47
#define KEY_CHAR_H          0x48
#define KEY_CHAR_I          0x49
#define KEY_CHAR_J          0x4a
#define KEY_CHAR_K          0x4b
#define KEY_CHAR_L          0x4c
#define KEY_CHAR_M          0x4d
#define KEY_CHAR_N          0x4e
#define KEY_CHAR_O          0x4f
#define KEY_CHAR_P          0x50
#define KEY_CHAR_Q          0x51
#define KEY_CHAR_R          0x52
#define KEY_CHAR_S          0x53
#define KEY_CHAR_T          0x54
#define KEY_CHAR_U          0x55
#define KEY_CHAR_V          0x56
#define KEY_CHAR_W          0x57
#define KEY_CHAR_X          0x58
#define KEY_CHAR_Y          0x59
#define KEY_CHAR_Z          0x5a


// Control codes
#define KEY_CTRL_NOP        0
#define KEY_CTRL_EXE        30004
#define KEY_CTRL_DEL        30025
#define KEY_CTRL_AC         30015
#define KEY_CTRL_FD         30046
#define KEY_CTRL_UNDO	    30045	
#define KEY_CTRL_XTT        30001
#define KEY_CTRL_EXIT       30002
#define KEY_CTRL_SHIFT      30006
#define KEY_CTRL_ALPHA      30007
#define KEY_CTRL_OPTN       30008
#define KEY_CTRL_VARS       30016
#define KEY_CTRL_UP         30018
#define KEY_CTRL_DOWN       30023
#define KEY_CTRL_LEFT       30020
#define KEY_CTRL_RIGHT      30021
#define KEY_SHIFT_LEFT 30062 // FXCG key, not present here
#define KEY_SHIFT_RIGHT 30063
#define KEY_CTRL_F1         30009
#define KEY_CTRL_F2         30010
#define KEY_CTRL_F3         30011
#define KEY_CTRL_F4         30012
#define KEY_CTRL_F5         30013
#define KEY_CTRL_F6         30014
#define KEY_CTRL_F7         30915
#define KEY_CTRL_F8         30916
#define KEY_CTRL_F9         30917
#define KEY_CTRL_F10         30918
#define KEY_CTRL_F11         30919
#define KEY_CTRL_F12         30920
#define KEY_CTRL_F13         30921
#define KEY_CTRL_F14         30922
#define KEY_CTRL_F15         30923
#define KEY_CTRL_F16         30924
#define KEY_CTRL_F17         30925
#define KEY_CTRL_F18         30926
#define KEY_CTRL_F19         30927
#define KEY_CTRL_F20         30928
#define KEY_CTRL_CATALOG    30100
#define KEY_CTRL_FORMAT     30101 // FXCG key
#define KEY_CTRL_CAPTURE    30055
#define KEY_CTRL_CLIP       30050
#define KEY_CTRL_PASTE      30036
#define KEY_CTRL_INS        30033
#define KEY_CTRL_MIXEDFRAC  30054
#define KEY_CTRL_FRACCNVRT  30026
#define KEY_CTRL_QUIT       30029
#define KEY_CTRL_PRGM       30028
#define KEY_CTRL_SETUP      30037
#define KEY_CTRL_PAGEUP     30052
#define KEY_CTRL_PAGEDOWN   30053
#define KEY_CTRL_MENU       30003
#define	KEY_CTRL_RESERVE1	30060
#define	KEY_CTRL_RESERVE2	30061
#define	KEY_CTRL_RESERVE3	30062


// in Bkey_GetKeyWait function
#define KEYWAIT_HALTON_TIMEROFF     0
#define KEYWAIT_HALTOFF_TIMEROFF    1
#define KEYWAIT_HALTON_TIMERON      2

#define KEYREP_NOEVENT              0
#define KEYREP_KEYEVENT             1
#define KEYREP_TIMEREVENT           2

# ifdef __cplusplus
}
# endif

#endif
