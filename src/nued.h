#ifndef NUED_HEADER
#define NUED_HEADER

struct Flags
{
    bool help;
};

struct Flags parse_args(int argc, char *argv[]);
#endif
