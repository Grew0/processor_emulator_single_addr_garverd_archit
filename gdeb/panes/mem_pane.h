#ifndef GDEB_PANES_MEM_PANE_H
#define GDEB_PANES_MEM_PANE_H

class SfmlInfo;
class Proc;

class MemPane {
  public:
    void Draw(SfmlInfo &sfmlInfo, Proc *proc, int &startX);

  private:
    float scrollY = 0;
};

#endif // GDEB_PANES_MEM_PANE_H
