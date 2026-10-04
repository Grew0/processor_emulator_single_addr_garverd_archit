#ifndef COMMANDS_H
#define COMMANDS_H

#include "constants.h"
#include <ostream>

struct Command {
    enum struct Type : Word {
        READ = 0x0,
        WRITE = 0x1,

        ADD = 0x2,
        SUB = 0x3,
        MUL = 0x4,
        DIV = 0x5,

        CMP = 0x6,
        JMP = 0x7,
        JCP = 0x8,

        LAST = DIV,

    };

#define APPLY_MACROS_TO_COMMANDS(MACROS)                                       \
    MACROS(READ)                                                               \
    MACROS(WRITE)                                                              \
                                                                               \
    MACROS(ADD)                                                                \
    MACROS(SUB)                                                                \
    MACROS(MUL)                                                                \
    MACROS(DIV)                                                                \
                                                                               \
    MACROS(CMP)                                                                \
    MACROS(JMP)                                                                \
    MACROS(JCP)

    template <Type T> static void Operation(Word &R0, Word *val, Word &IR);
};

std::ostream &operator<<(std::ostream &out, const Command::Type &command);

#define DECLARATE_COMMAND(TYPE)                                                \
    template <>                                                                \
    void Command::Operation<Command::Type::TYPE>(Word & R0, Word * val,        \
                                                 Word & IR);
APPLY_MACROS_TO_COMMANDS(DECLARATE_COMMAND);
#undef DECLARATE_COMMAND

static_assert(static_cast<Word>(Command::Type::LAST) < CONSTANTS::LAST_COMMAND);

#endif // COMMANDS_H
