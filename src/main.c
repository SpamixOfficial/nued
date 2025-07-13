#include <ncurses.h>
#include <stdio.h>

#include "argparser.h"
#include "nued.h"
#include "input.h"

void ncurses_init() {
    initscr();
    start_color();
    noecho();
    raw();
    keypad(stdscr, true);

    // init colors
    init_pair(DefaultColorPairN, DefaultColorPairColors);
    init_pair(ErrColorPairN, ErrorColorPairColors);
    init_pair(WarningColorPairN, WarningColorPairColors);
}


int main(int argc, char* argv[]) {
    Flags flags = parse_args(argc, argv);
    if (flags.help) {
        return 0;
    }
    int ch;
    ncurses_init();

    AppState app = {};

    getmaxyx(stdscr, app.max_y, app.max_x);

    while (input_handler(&app, getch()) != -1) {
        getyx(stdscr, app.y, app.x);
        refresh();
    }

    endwin();

    return 0;
}
