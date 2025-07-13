#include <ncurses.h>

#include "nued.h"

#define ctrl(x) ((x) & 0x1f)

void backspace_handler(int* x, int* y, int max_x, int max_y) {
    if (*x == 0 && *y != 0) {
        // get end of row above
        move((*y)--, max_x);
        while ((inch() & A_CHARTEXT) == ' ' && max_x != 0) move(*y, --max_x);
        *x = max_x == 0 && (inch() & A_CHARTEXT) == ' ' ? max_x : max_x + 1;
    } else if (*x)
        (*x)--;
    mvaddch(*y, *x, ' ');
    move(*y, *x);
}

void arrow_handler(int arrow, int* x, int* y) {
    // up and down keys
    if (arrow - 0402 <= 1)
        *y += arrow == KEY_DOWN ? 1 : -1;
    else
        *x += arrow == KEY_RIGHT ? 1 : -1;
    
    move(*y, *x);
}

// Returns -1 if exit is desired, else 0
int input_handler(struct AppState* app, int ch) {
    switch (ch) {
        case ctrl('x'):
            return -1;
        case KEY_BACKSPACE:
            backspace_handler(&app->x, &app->y, app->max_x, app->max_y);
            break;
        case KEY_LEFT:
        case KEY_RIGHT:
        case KEY_UP:
        case KEY_DOWN:
            arrow_handler(ch, &app->x, &app->y);
            break;
        default:
            printw("%c", ch);
    };

    return 0;
}
