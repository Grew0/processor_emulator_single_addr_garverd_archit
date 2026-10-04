#ifndef GDEB_PANES_DISASM_PANE_H
#define GDEB_PANES_DISASM_PANE_H

class SfmlInfo;
class Proc;

class DisasmPane {
  public:
    void Draw(SfmlInfo &sfmlInfo, Proc *proc, int &startX);

  private:
    float scrollY = 0;
};

#endif // GDEB_PANES_DISASM_PANE_H
