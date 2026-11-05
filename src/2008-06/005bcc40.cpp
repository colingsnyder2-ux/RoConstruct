// from server: 100% by king_originala
struct String;
extern void (__thiscall *stringConstruct)(String*, const char*);
extern void (__thiscall *stringDestroy)(String*);

struct String {
    char storage[28];
    String(const char* text) { stringConstruct(this, text); }
    ~String() { stringDestroy(this); }
};

struct Base {
    unsigned int words[0x158 / 4];

    Base();
    ~Base();
    void setName(const String&);
    void bindInteger(const char*, unsigned int*);
    void bindValue(const char*, unsigned int*);
};

struct Item : Base {
    void* source;
    unsigned int current;
    unsigned int unused;
    unsigned int sounds;
    unsigned int unusedSounds;

    Item(void*);
};

Item::Item(void* argument)
{
    words[0x00 / 4] = 0x838054;
    words[0x10 / 4] = 0x838044;
    words[0x14 / 4] = 0x83803c;
    words[0x20 / 4] = 0x838034;
    words[0x24 / 4] = 0x838024;
    words[0x44 / 4] = 0x838014;
    words[0x64 / 4] = 0x838004;
    words[0x84 / 4] = 0x837ff4;
    words[0xa4 / 4] = 0x837fe4;
    words[0xc4 / 4] = 0x837fd4;

    source = argument;
    current = 0;
    unused = 0;

    {
        String name((const char*)0x818748);
        setName(name);
    }

    bindInteger((const char*)0x837fc8, &current);
    bindInteger((const char*)0x837fc4, &unused);
    bindValue((const char*)0x837fb8, &sounds);
    bindValue((const char*)0x837fac, &unusedSounds);
}
