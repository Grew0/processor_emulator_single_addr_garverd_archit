#ifndef VALUE_TYPE_H
#define VALUE_TYPE_H

#include "constants.h"
#include <ostream>

enum struct ValueType : Word {
    Register = 0x0,
    Number = 0x1,
    MemUnitR = 0x2,
    MemUnitN = 0x3,
    LAST = MemUnitN,
};
static_assert(static_cast<Word>(ValueType::LAST) < CONSTANTS::LAST_VALUE_TYPE);

inline std::ostream &operator<<(std::ostream &out, const ValueType &vt) {
    switch (vt) {
    case (ValueType::Register):
        return out << "REG";
    case (ValueType::Number):
        return out << "Num";
    case (ValueType::MemUnitN):
        return out << "MUN";
    case (ValueType::MemUnitR):
        return out << "MUR";
    }
    return out << "unknown";
}

#endif // VALUE_TYPE_H
