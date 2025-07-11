#include <stdio.h>
#include <ncurses.h>
#include "nued.h"

#define PROJECT_NAME "nued"

int main(int argc, char *argv[])
{
    struct Flags flags = parse_args(argc, argv);
    printf("Was help used? %s", flags.help ? "Yes" : "No");
    return 0;
}
