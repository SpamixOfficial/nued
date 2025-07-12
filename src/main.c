#include <stdio.h>
#include <ncurses.h>
#include "argparser.h"

int main(int argc, char *argv[])
{
    struct Flags flags = parse_args(argc, argv);
    printf("flags.help: %s", flags.help ? "true" : "false");
    return 0;
}
