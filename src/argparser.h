#include <stdbool.h>
#pragma once

#define PROJECT_NAME "nued"
struct Flags
{
    bool help;
};

struct Flags parse_args(int argc, char *argv[]);
