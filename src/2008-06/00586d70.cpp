// from server: 100% by king_originala
struct String {
    char storage[28];
    String(const char *);
    ~String();
};

extern void (__thiscall *constructString)(String *, const char *);
extern void (__thiscall *destroyString)(String *);

inline String::String(const char *text)
{
    constructString(this, text);
}

inline String::~String()
{
    destroyString(this);
}

extern unsigned long table0[];
extern unsigned long table10[];
extern unsigned long table14[];
extern unsigned long table20[];
extern unsigned long table24[];
extern unsigned long table44[];
extern unsigned long table64[];
extern unsigned long table84[];
extern unsigned long tableA4[];
extern unsigned long tableC4[];

struct Script {
    unsigned long data[0x110 / 4];
    String value;

    Script();
    ~Script();
    void setValue(const String &);
};

struct LocalScript : Script {
    LocalScript();
};

LocalScript::LocalScript()
{
    data[0] = reinterpret_cast<unsigned long>(table0);
    data[0x10 / 4] = reinterpret_cast<unsigned long>(table10);
    data[0x14 / 4] = reinterpret_cast<unsigned long>(table14);
    data[0x20 / 4] = reinterpret_cast<unsigned long>(table20);
    data[0x24 / 4] = reinterpret_cast<unsigned long>(table24);
    data[0x44 / 4] = reinterpret_cast<unsigned long>(table44);
    data[0x64 / 4] = reinterpret_cast<unsigned long>(table64);
    data[0x84 / 4] = reinterpret_cast<unsigned long>(table84);
    data[0xa4 / 4] = reinterpret_cast<unsigned long>(tableA4);
    data[0xc4 / 4] = reinterpret_cast<unsigned long>(tableC4);

    String name("LocalScript");
    setValue(name);
}
