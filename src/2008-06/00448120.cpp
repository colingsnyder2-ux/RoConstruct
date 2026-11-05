// from server: 100% by king_originala
struct String;
extern void (__thiscall *stringConstruct)(String*, const char*);
extern void (__thiscall *stringDestroy)(String*);

struct String {
    char storage[28];
    String(const char* text) { stringConstruct(this, text); }
    ~String() { stringDestroy(this); }
};

extern String __cdecl format(const char*, ...);

struct Exception {
    char storage[40];
    Exception(const String&);
    Exception(const Exception&);
    ~Exception();
};

struct Base {
    unsigned long storage[75];
    Base();
    ~Base();
    void setValue(const String&);
};

struct S : Base {
    S();
};

extern S* singleton;
extern unsigned char table0[], table10[], table14[], table20[], table24[];
extern unsigned char table44[], table64[], table84[], tableA4[], tableC4[];

S::S()
{
    storage[0] = reinterpret_cast<unsigned long>(table0);
    storage[4] = reinterpret_cast<unsigned long>(table10);
    storage[5] = reinterpret_cast<unsigned long>(table14);
    storage[8] = reinterpret_cast<unsigned long>(table20);
    storage[9] = reinterpret_cast<unsigned long>(table24);
    storage[17] = reinterpret_cast<unsigned long>(table44);
    storage[25] = reinterpret_cast<unsigned long>(table64);
    storage[33] = reinterpret_cast<unsigned long>(table84);
    storage[41] = reinterpret_cast<unsigned long>(tableA4);
    storage[49] = reinterpret_cast<unsigned long>(tableC4);

    setValue(String("RenderSettings"));

    if (singleton)
        throw Exception(format("singleton %s already exists", "RenderSettings"));

    singleton = this;
}
