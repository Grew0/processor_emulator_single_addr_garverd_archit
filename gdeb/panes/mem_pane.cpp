#include "gdeb/panes/mem_pane.h"
#include "gdeb/panes/line_drawer.h"
#include "gdeb/sfml_info.h"
#include "proc/constants.h"
#include "proc/proc.h"

void MemPane::Draw(SfmlInfo &sfmlInfo, Proc *proc, int &startX) {

    auto *reg = proc->ReadRegisters();
    auto &mem = proc->ReadMemory();
    auto &instr = proc->ReadInstructions();
    auto IR = proc->GetIR();

    bool hilightAlways = false;
    size_t hilightLine = std::numeric_limits<size_t>::max();

    if (IR >= instr.size()) {
        hilightAlways = true;
    } else {
        auto ins = instr[IR];
        if (ins.valType == ValueType::MemUnitN) {
            hilightLine = ins.value;
        } else if (ins.valType == ValueType::MemUnitR) {
            if (ins.value >= CONSTANTS::LAST_REGISTER) {
                hilightAlways = true;
            } else {
                hilightLine = reg[ins.value];
            }
        }
    }
    if (hilightLine >= mem.size() &&
        hilightLine != std::numeric_limits<size_t>::max()) {
        hilightAlways = true;
    }

    LineDrawer ld(sfmlInfo, 0);
    for (size_t i = 0; i < mem.size(); ++i) {
        std::stringstream ss;
        ss << "[" << i << "]: " << mem[i];
        std::string s = ss.str();
        ld.DrawText(s, i, startX, hilightAlways | (hilightLine == i));
    }
    startX += ld.mxX;
}
