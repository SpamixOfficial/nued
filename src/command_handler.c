#include <stdio.h>
#include <stdbool.h>
#include <ncurses.h>
#include "nued.h"


void print_help(bool help)
{
    printf("Hiiii");
}

struct Flags parse_args(int argc, char *argv[])
{
    struct Flags flags;
    flags.help = argc == 1;

    if (flags.help)
    {
        goto SKIP_CHECKS;
    }

SKIP_CHECKS:
    print_help(flags.help);
    return flags;
}