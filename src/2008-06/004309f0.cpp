// from server: 100% by king_originala
struct Value {
    int value;
    Value(int);
    Value(const Value &);
};

__forceinline Value::Value(int n) : value(n) {}

struct Selection {
    char storage[0x58];
    void select(int);
};

struct Settings {
    int header;
    Selection selection;
    Settings(int, Value, const char *);
    ~Settings();
    int available();
};

struct Item {
    char storage[0x30];
};

extern int (__thiscall *itemOperation)(Item *, int);

struct Panel {
    char storage[0x14C];
    void clear();
};

struct Control {
    char storage[0x15C];
    void reset(int);
};

struct Auxiliary {
    void reset(int);
};

struct CommandBars {
    void update();
};

struct S {
    typedef void (__thiscall *VirtualOperation)(S *, int);

    VirtualOperation *vtable;
    char padding04[0xE8];
    CommandBars *commandBars;
    char paddingF0[0x14];
    unsigned char initialized;
    char padding105[3];
    Item item;
    Panel panel;
    Control control;
    Auxiliary auxiliary;

    void apply(Settings *, int);
    void f();
};

void S::f()
{
    if (!initialized) {
        Settings settings(0, Value(0), "IDE");
        if (settings.available()) {
            apply(&settings, 1);
            settings.selection.select(itemOperation(&item, 1));
        }
        auxiliary.reset(0);
        control.reset(0);
        commandBars->update();
        panel.clear();
        vtable[0x56](this, 1);
        initialized = 1;
    }
}
