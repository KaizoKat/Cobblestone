#pragma once
#define vck_UNKNOWN            -1

/* virtual cobblestone keycodes, from glfw3.h*/
#define vck_SPACE              32
#define vck_APOSTROPHE         39  /* ' */
#define vck_COMMA              44  /* , */
#define vck_MINUS              45  /* - */
#define vck_PERIOD             46  /* . */
#define vck_SLASH              47  /* / */
#define vck_0                  48
#define vck_1                  49
#define vck_2                  50
#define vck_3                  51
#define vck_4                  52
#define vck_5                  53
#define vck_6                  54
#define vck_7                  55
#define vck_8                  56
#define vck_9                  57
#define vck_SEMICOLON          59  /* ; */
#define vck_EQUAL              61  /* = */
#define vck_A                  65
#define vck_B                  66
#define vck_C                  67
#define vck_D                  68
#define vck_E                  69
#define vck_F                  70
#define vck_G                  71
#define vck_H                  72
#define vck_I                  73
#define vck_J                  74
#define vck_K                  75
#define vck_L                  76
#define vck_M                  77
#define vck_N                  78
#define vck_O                  79
#define vck_P                  80
#define vck_Q                  81
#define vck_R                  82
#define vck_S                  83
#define vck_T                  84
#define vck_U                  85
#define vck_V                  86
#define vck_W                  87
#define vck_X                  88
#define vck_Y                  89
#define vck_Z                  90
#define vck_LEFT_BRACKET       91  /* [ */
#define vck_BACKSLASH          92  /* \ */
#define vck_RIGHT_BRACKET      93  /* ] */
#define vck_GRAVE_ACCENT       96  /* ` */
#define vck_WORLD_1            161 /* non-US #1 */
#define vck_WORLD_2            162 /* non-US #2 */

/* Function keys */
#define vck_ESCAPE             256
#define vck_ENTER              257
#define vck_TAB                258
#define vck_BACKSPACE          259
#define vck_INSERT             260
#define vck_DELETE             261
#define vck_RIGHT              262
#define vck_LEFT               263
#define vck_DOWN               264
#define vck_UP                 265
#define vck_PAGE_UP            266
#define vck_PAGE_DOWN          267
#define vck_HOME               268
#define vck_END                269
#define vck_CAPS_LOCK          280
#define vck_SCROLL_LOCK        281
#define vck_NUM_LOCK           282
#define vck_PRINT_SCREEN       283
#define vck_PAUSE              284
#define vck_F1                 290
#define vck_F2                 291
#define vck_F3                 292
#define vck_F4                 293
#define vck_F5                 294
#define vck_F6                 295
#define vck_F7                 296
#define vck_F8                 297
#define vck_F9                 298
#define vck_F10                299
#define vck_F11                300
#define vck_F12                301
#define vck_F13                302
#define vck_F14                303
#define vck_F15                304
#define vck_F16                305
#define vck_F17                306
#define vck_F18                307
#define vck_F19                308
#define vck_F20                309
#define vck_F21                310
#define vck_F22                311
#define vck_F23                312
#define vck_F24                313
#define vck_F25                314
#define vck_KP_0               320
#define vck_KP_1               321
#define vck_KP_2               322
#define vck_KP_3               323
#define vck_KP_4               324
#define vck_KP_5               325
#define vck_KP_6               326
#define vck_KP_7               327
#define vck_KP_8               328
#define vck_KP_9               329
#define vck_KP_DECIMAL         330
#define vck_KP_DIVIDE          331
#define vck_KP_MULTIPLY        332
#define vck_KP_SUBTRACT        333
#define vck_KP_ADD             334
#define vck_KP_ENTER           335
#define vck_KP_EQUAL           336
#define vck_LEFT_SHIFT         340
#define vck_LEFT_CONTROL       341
#define vck_LEFT_ALT           342
#define vck_LEFT_SUPER         343
#define vck_RIGHT_SHIFT        344
#define vck_RIGHT_CONTROL      345
#define vck_RIGHT_ALT          346
#define vck_RIGHT_SUPER        347
#define vck_MENU               348

/* vurtual cobblestone keycode mods, from glfw3.h */
#define vckm_SHIFT           0x0001
#define vckm_CONTROL         0x0002
#define vckm_ALT             0x0004
#define vckm_SUPER           0x0008
#define vckm_CAPS_LOCK       0x0010
#define vckm_NUM_LOCK        0x0020