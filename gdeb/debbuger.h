#ifndef GDEB_DEBBUGER_H
#define GDEB_DEBBUGER_H

#include "panes/disasm_pane.h"
#include "panes/mem_pane.h"
#include "panes/registers_pane.h"

class Proc;

// Graphical debbuger
class GDeb {
  public:
    GDeb(Proc *proc) : proc(proc) { assert(proc != nullptr); }
    void Start();

  private:
    DisasmPane disasmPane;
    RegistersPane registersPane;
    MemPane memPane;
    Proc *proc;
};

#endif // GDEB_DEBBUGER_H
