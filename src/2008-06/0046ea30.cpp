// from server: 100% by king_originala
struct String {
    char storage[28];
    String();
    String(const char *);
    ~String();
};

extern void (__thiscall *stringDefaultConstructor)(String *);
extern void (__thiscall *stringTextConstructor)(String *, const char *);
extern void (__thiscall *stringDestructor)(String *);

__forceinline String::String()
{
    stringDefaultConstructor(this);
}

__forceinline String::String(const char *value)
{
    stringTextConstructor(this, value);
}

__forceinline String::~String()
{
    stringDestructor(this);
}

const char initialText[11] = {
    0, 0, '\xf1', '\x68', '\xe3', '\x88',
    '\xb5', '\xf8', '\xe4', '\x3e', '\x41'
};

struct Base {
    virtual ~Base();
};

struct LuaObjectWriter : Base {
    void *output;
    int count;
    int index;
    double values[12];
    String text;

    LuaObjectWriter(void *);
    virtual ~LuaObjectWriter();
};

LuaObjectWriter::LuaObjectWriter(void *destination)
    : output(destination), text()
{
    values[0] = 0.0;
    values[1] = 0.0;
    values[2] = 0.0;
    values[3] = 0.0;
    count = 0;
    values[4] = 0.0;
    index = 0;
    values[5] = 0.0;
    values[6] = 0.0;
    values[7] = 0.0;
    values[8] = 0.0;
    values[9] = 0.0;
    values[10] = 0.0;
    values[11] = 0.0;
    String temporary(initialText);
}
