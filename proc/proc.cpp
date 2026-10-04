#include "proc.h"

void Proc::ExecuteAll() {
    while (true) {
        ExecuteOne();
        if (instr[IR].command == Command::Type::JMP &&
            instr[IR].valType == ValueType::Number && instr[IR].value == IR) {
            // INF LOOP FOUND - TERMINATE PROG
            break;
        }
    }
}

void Proc::ExecuteOne() {
    Operation o = instr[IR];
    Word *v = ReadValue(o);
    ExecuteCommand(o.command, v);
}

Word *Proc::ReadValue(Operation o) {
    switch (o.valType) {
    case ValueType::Register:
        assert(o.value < CONSTANTS::LAST_REGISTER);
        return &R[o.value];
    case ValueType::Number:
        tmp = o.value;
        return &tmp;
    case ValueType::MemUnitN:
        return &mem[o.value];
    case ValueType::MemUnitR:
        assert(o.value < CONSTANTS::LAST_REGISTER);
        return &mem[R[o.value]];
    default:
        abort();
    }
}

void Proc::ExecuteCommand(Command::Type command, Word *value) {
    switch (command) {
#define CASE_COMMAND(COMMAND)                                                  \
    case Command::Type::COMMAND:                                               \
        Command::Operation<Command::Type::COMMAND>(R[0], value, IR);           \
        break;
        APPLY_MACROS_TO_COMMANDS(CASE_COMMAND)
#undef CASE_COMMAND
    default:
        abort();
    }
}
