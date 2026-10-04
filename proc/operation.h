#ifndef OPERATION_H
#define OPERATION_H

#include "commands.h"
#include "constants.h"
#include "value_type.h"

struct Operation {
    union {
        struct {
            Word value : CONSTANTS::VALUE_WIDTH;
            ValueType valType : CONSTANTS::VALUE_TYPE_WIDTH;
            Command::Type command : CONSTANTS::COMMAND_WIDTH;
        };

        Word raw;
        // Structure MUST BE
        // | COMMAND |  VT   | VALUE  |
        // | 4 bit   | 2 bit | 26 bit | = 32 bits in total
    };
    Operation() : raw(0) {}
    Operation(Word raw) : raw(raw) {}
    Operation(Word value, ValueType valType, Command::Type command)
        : value(value), valType(valType), command(command) {}
};

static_assert(sizeof(Operation) == sizeof(Word));

#endif // OPERATION_H
