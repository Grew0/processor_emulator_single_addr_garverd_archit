#ifndef CONSTANTS_H
#define CONSTANTS_H

#include <cstdint>

using Word = uint32_t;

enum CONSTANTS : Word {
    BITS_IN_BYTE = 8,
    COMMAND_WIDTH = 4,
    REGISTER_WIDT = 3,
    VALUE_TYPE_WIDTH = 2,

    VALUE_WIDTH =
        sizeof(Word) * BITS_IN_BYTE - COMMAND_WIDTH - VALUE_TYPE_WIDTH,

    LAST_COMMAND = (1 << COMMAND_WIDTH),
    LAST_REGISTER = (1 << REGISTER_WIDT),
    LAST_VALUE_TYPE = (1 << VALUE_TYPE_WIDTH),
};
static_assert(CONSTANTS::REGISTER_WIDT <= CONSTANTS::VALUE_WIDTH);

#endif // CONSTANTS_H
