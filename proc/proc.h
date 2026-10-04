#ifndef PROC_H
#define PROC_H

#pragma once

#include "operation.h"
#include <span>

// Proccessor emulator
struct Proc {
  public:
    using Instructions = std::span<Operation>;
    using Memory = std::span<Word>;
    using Register = Word;

    void SetUpInstructions(Instructions instr) { this->instr = instr; }
    void SetUpMemory(Memory mem) { this->mem = mem; }

    void ExecuteAll();
    void ExecuteOne();

    const Memory &ReadMemory() { return mem; }
    const Instructions &ReadInstructions() { return instr; }
    Word GetIR() const { return IR; }
    const Register *ReadRegisters() { return R; }

  private:
    Word *ReadValue(Operation o);
    void ExecuteCommand(Command::Type command, Word *value);

    Word IR = 0;
    Memory mem;
    Instructions instr;
    Register R[CONSTANTS::LAST_REGISTER]{0};
    Word tmp;
};

#endif // PROC_H
