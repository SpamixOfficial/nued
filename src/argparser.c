#include "argparser.h"

#include <ncurses.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// 9 = "\t"*2 + "-"*3 + char + "," + " " + "\n"
#define calc_hline_len(loption, help) (9 + strlen(loption) + strlen(help))

static inline void fatal_error(const char *error) {
    fputs(error, stderr);
    exit(1);
}

struct Command {
    char s;
    char *l;
    char *help;
} const commands[] = {{'h', "help", "Print this output!"}};

void help(char *pname, bool help) {
    if (!help) {
        return;
    };

    size_t c_len = sizeof(commands) / sizeof(struct Command);
    // should be enough!
    char *option_string = calloc(2048, sizeof(char));
    char *shortcommands_string = calloc(c_len, sizeof(char));

    for (unsigned long i = 0; i < c_len; i++) {
        // Create new option_string line
        char* tmp_optstr;
        if (0 > asprintf(&tmp_optstr, "%s  -%c, --%s\t%s\n", option_string, commands[i].s, commands[i].l, commands[i].help))
            fatal_error(
                "error: couldn't asprintf from variable \"option_string\"\n");

        free(option_string);
        option_string = tmp_optstr;

        // add shortcommand
        *(shortcommands_string + i) = commands[i].s;
    }
    printf("usage: %s [-%s] FILE\n%s", pname, shortcommands_string, option_string);
    free(shortcommands_string);
    free(option_string);
}

void argv_to_flags(struct Flags *flags, char *argv[]) {}

struct Flags parse_args(int argc, char *argv[]) {
    struct Flags flags = {false};
    char *pname = argv[0];

    if (argc == 1) {
        flags.help = true;
        goto SKIP_CHECKS_HELP;
    }

    argv_to_flags(&flags, argv);

SKIP_CHECKS_HELP:
    help(pname, flags.help);
    return flags;
}
