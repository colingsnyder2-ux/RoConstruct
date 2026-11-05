// from server: 100% by king_originala
struct Control {
    int query(int direct);
};

struct Command {
    virtual void enable(int enabled);
};

typedef bool (__thiscall *Predicate)(void *);
extern Predicate predicate;

struct View {
    char padding[0x58];
    Control control;
    void update(Command *command);
};

void View::update(Command *command)
{
    command->enable(control.query(1) && !predicate((void *)0x00932fb8));
}
