#include "gdeb/debbuger.h"
#include "gdeb/panes/line_drawer.h"
#include "proc/proc.h"

void RegistersPane::Draw(SfmlInfo &sfmlInfo, Proc *proc, int &startX) {
    auto *reg = proc->ReadRegisters();
    LineDrawer ld(sfmlInfo, 0);
    for (size_t i = 0; i < CONSTANTS::LAST_REGISTER; ++i) {
        std::stringstream ss;
        ss << "R" << i << ": " << reg[i];
        std::string s = ss.str();
        auto IR = proc->GetIR();
        auto instr = proc->ReadInstructions();
        bool hilight = false;
        if (IR < instr.size()) {
            auto o = instr[IR];
            if (o.valType == ValueType::Register ||
                o.valType == ValueType::MemUnitR) {
                if (o.value >= CONSTANTS::LAST_REGISTER) {
                    hilight = true;
                } else {
                    hilight = (i == o.value);
                }
            }
            if (i == 0 && o.command != Command::Type::JMP) {
                hilight = true;
            }
        } else {
            hilight = true;
        }
        ld.DrawText(s, i, startX, hilight);
    }
    startX += ld.mxX;
}
