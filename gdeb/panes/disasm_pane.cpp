#include "gdeb/debbuger.h"
#include "gdeb/panes/line_drawer.h"
#include "gdeb/sfml_info.h"
#include "proc/proc.h"
#include <iostream>
#include <sstream>

void DisasmPane::Draw(SfmlInfo &sfmlInfo, Proc *proc, int &startX) {

    scrollY -= 10 * (sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::J) -
                     sf::Keyboard::isKeyPressed(sf::Keyboard::Scan::K));
    auto instr = proc->ReadInstructions();
    LineDrawer ld(sfmlInfo, scrollY);
    for (size_t i = 0; i < instr.size(); ++i) {
        std::stringstream ss;
        ss << std::left << std::setw(3) << i << " " << std::setw(5)
           << instr[i].command << " ";
        switch (instr[i].valType) {
        case ValueType::Register:
            ss << "R" << instr[i].value;
            break;
        case ValueType::Number:
            ss << instr[i].value;
            break;
        case ValueType::MemUnitN:
            ss << "[" << instr[i].value << "]";
            break;
        case ValueType::MemUnitR:
            ss << "[R" << instr[i].value << "]";
            break;
        };
        std::string s = ss.str();
        ld.DrawText(s, i, startX, i == proc->GetIR());
    }

    sf::RectangleShape border(sf::Vector2f(2, 1000));
    border.setFillColor(sf::Color::Black);
    border.setPosition({2.f * ld.txt.getCharacterSize(), 0});
    sfmlInfo.win->draw(border);
    border.setPosition({5.57f * ld.txt.getCharacterSize(), 0});
    sfmlInfo.win->draw(border);
    startX += ld.mxX;
}
