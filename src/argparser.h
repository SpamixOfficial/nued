#pragma once
#include <stdbool.h>

#define PROJECT_NAME "nued"
typedef struct
{
    bool help;
} Flags;

Flags parse_args(int argc, char *argv[]);
