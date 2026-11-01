// from server: 100% by king_originala
struct Buttons;
typedef void (__thiscall *ButtonMethod)(Buttons *, const char *, int, int);

struct Buttons {
    ButtonMethod *table;
};

struct Primary {
    virtual ~Primary();
    char padding[28];
};

struct Secondary {
    virtual ~Secondary();
    char padding0[160];
    Buttons *buttons;
    char padding1[68];
};

struct Tertiary {
    virtual ~Tertiary();
};

struct Base : Primary, Secondary, Tertiary {
    Base(int, int);
    virtual ~Base();
    int getFlags();
    void setFlags(int);
};

struct ScriptItem : Base {
    ScriptItem(int, int);
    virtual ~ScriptItem();
};

ScriptItem::ScriptItem(int a, int b) : Base(a, b)
{
    setFlags(getFlags() | 4);
    buttons->table[22](buttons, "Browse...", 0, 0xe101);
    buttons->table[22](buttons, "Clear", 1, 0xe120);
}
