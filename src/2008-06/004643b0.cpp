// from server: 100% by colin
struct Text;

extern void (__cdecl *formatText)(Text*, unsigned int, ...);

struct Text {
    char* data;
    __declspec(dllimport) Text();
    __declspec(dllimport) ~Text() throw();
    __declspec(dllimport) const char* get() const;
};







struct Control {
    int query(int);
    int column(int, int);
    int line(int, int);
};

struct Target;

struct TargetTable {
    void (__thiscall *slot0)(Target*);
    void (__thiscall *slot1)(Target*);
    void (__thiscall *slot2)(Target*);
    void (__thiscall *setText)(Target*, const char*);
};

struct Target {
    TargetTable* table;
};

struct S {
    int* f();
    void update(Target*);
};

void S::update(Target* target)
{
    Control* control = reinterpret_cast<Control*>(f());
    int position = control->query(1);
    int column = control->column(position, 1);
    int line = control->line(position, 1);
    Text text;
    formatText(&text, 199, column, line, position);
    TargetTable* table = target->table;
    const char* value = text.get();
    table->setText(target, value);
}
