// from server: 100% by king_originala
struct String;
typedef void (__thiscall *StringCtor)(String *, const char *);
typedef void (__thiscall *StringDtor)(String *);

extern StringCtor constructString;
extern StringDtor destroyString;

struct String {
    unsigned char data[28];

    String(const char *s) { constructString(this, s); }
    ~String() { destroyString(this); }
};

extern String __cdecl format(const char *, ...);

struct Error {
    unsigned char data[40];

    Error(const String &);
    Error(const Error &);
    ~Error();
};

struct Base {
    unsigned long slots[76];

    Base();
    ~Base();
    void setName(const String &);
};

struct S : Base {
    S();
};

extern S *singleton;

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

extern const char authoring[];
extern const char duplicateFormat[];

S::S() : Base()
{
    slots[0]  = reinterpret_cast<unsigned long>(table0);
    slots[4]  = reinterpret_cast<unsigned long>(table10);
    slots[5]  = reinterpret_cast<unsigned long>(table14);
    slots[8]  = reinterpret_cast<unsigned long>(table20);
    slots[9]  = reinterpret_cast<unsigned long>(table24);
    slots[17] = reinterpret_cast<unsigned long>(table44);
    slots[25] = reinterpret_cast<unsigned long>(table64);
    slots[33] = reinterpret_cast<unsigned long>(table84);
    slots[41] = reinterpret_cast<unsigned long>(tableA4);
    slots[49] = reinterpret_cast<unsigned long>(tableC4);

    setName(String(authoring));

    if (singleton)
        throw Error(format(duplicateFormat, authoring));

    singleton = this;
}
