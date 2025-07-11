#include <stdio.h>
#include <ncurses.h>
#include "argparser.h"

int main(int argc, char *argv[])
{
    struct Flags flags = parse_args(argc, argv);
    printf("Was help used? %s", flags.help ? "Yes" : "No");
    return 0;
}
