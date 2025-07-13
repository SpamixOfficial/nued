#pragma once
#include <ncurses.h>


// Color pair definitions
#define DefaultColorPairN 1
#define DefaultColorPairColors COLOR_WHITE, COLOR_BLACK
#define DefaultColorPair COLOR_PAIR(DefaultColorPairN)

#define ErrColorPairN 3
#define ErrorColorPairColors COLOR_RED, COLOR_BLACK
#define ErrColorPair COLOR_PAIR(ErrColorPairN)

#define WarningColorPairN 4
#define WarningColorPairColors COLOR_YELLOW, COLOR_BLACK
#define WarningColorPair COLOR_PAR(WarningColorPairN)


typedef struct {
    int x,y, max_x, max_y;
} AppState;