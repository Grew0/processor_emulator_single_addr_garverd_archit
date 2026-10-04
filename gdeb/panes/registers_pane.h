#ifndef GDEB_PANES_REGISTERS_PANE_H
#define GDEB_PANES_REGISTERS_PANE_H

class SfmlInfo;
class Proc;

class RegistersPane {
  public:
    void Draw(SfmlInfo &sfmlInfo, Proc *proc, int &startX);
};

#endif // GDEB_PANES_REGISTERS_PANE_H
