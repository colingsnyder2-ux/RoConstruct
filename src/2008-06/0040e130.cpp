// from server: 100% by king_originala
struct P {};

extern bool (__thiscall *check)(P*);

struct Command;
struct CommandTable {
    void (__thiscall *setEnabled)(Command*, int);
};

struct Command {
    CommandTable* table;
};

struct CBrowserView {
    char padding[0x2cc];
    P p;

    void update(Command*);
};

void CBrowserView::update(Command* command)
{
    CommandTable* table = command->table;
    bool result = check(&p);
    table->setEnabled(command, !result);
}
