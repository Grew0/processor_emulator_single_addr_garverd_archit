#include "commands.h"

#define OPER(O)                                                                \
    template <>                                                                \
    void Command::Operation<Command::Type::O>(                                 \
        [[maybe_unused]] Word & R0, Word * w, [[maybe_unused]] Word & IR)

OPER(READ) { R0 = *w, ++IR; }

OPER(WRITE) { *w = R0, ++IR; }

OPER(ADD) { R0 += *w, ++IR; }
OPER(SUB) { R0 -= *w, ++IR; }
OPER(MUL) { R0 *= *w, ++IR; }
OPER(DIV) { R0 /= *w, ++IR; }

OPER(CMP) { R0 = R0 > *w ? R0 - *w : 0, ++IR; }

OPER(JMP) { IR = *w; }
OPER(JCP) { IR = R0 > 0 ? (*w) : IR + 1; }

std::ostream &operator<<(std::ostream &out, const Command::Type &command) {
    switch (command) {

#define NAME(comm)                                                             \
    case Command::Type::comm:                                                  \
        return out << #comm;
        APPLY_MACROS_TO_COMMANDS(NAME)
#undef NAME

    default:
        return out << "UNKNOWN";
    }
}

#undef OPER
