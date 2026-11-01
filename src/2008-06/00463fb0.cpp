// from server: 100% by king_originala
struct Command {
    virtual void set(int value);
};

struct Control {
    int current(int direct);
    int line(int position, int direct);
    int state(int line, int direct);
};

struct CScriptEditor {
    int* f();
    void update(Command* command);
};

void CScriptEditor::update(Command* command)
{
    Control* control = reinterpret_cast<Control*>(f());
    int position = control->current(1);
    int line = control->line(position, 1);
    int state = control->state(line, 1);
    command->set(state & 1);
}
