// from server: 100% by colin
struct String {
    const char* c_str() const;
};

extern const char* (__thiscall* string_c_str)(const String*);

inline const char* String::c_str() const
{
    return string_c_str(this);
}

struct Name {
    char pad[4];
    String text;
};

struct Item {
    virtual ~Item();
    virtual bool value();
    Name* name;
};

struct Primary {
    virtual ~Primary();
    char pad[0x1c];
};

struct Secondary {
    virtual ~Secondary();
};

struct Base : Primary, Secondary {
    char pad0[0xd8];
    int flag;
    char pad1[0x20];

    Base(const char*, int, int);
    virtual ~Base();
    void SetValue(int);
};

struct Helper {
    virtual ~Helper();
    char pad[0x1c];

    Helper(Item*, int);
};

struct S : Base, Helper {
    Item* item;

    S(Item*, int);
    virtual ~S();
};

static Name* nameOf(Item* p)
{
    return p->name;
}

S::S(Item* p, int n)
    : Base(nameOf(p)->text.c_str(), 0, 0),
      Helper(p, n)
{
    flag = 1;
    item = p;
    SetValue(p->value());
}
