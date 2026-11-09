// from server: 100% by king_originala
struct String;
extern String* (__thiscall *stringConstruct)(String*, const char*);
extern void (__thiscall *stringDestroy)(String*);

extern const char table00[];
extern const char table10[];
extern const char table14[];
extern const char table20[];
extern const char table24[];
extern const char table44[];
extern const char table64[];
extern const char table84[];
extern const char tableA4[];
extern const char tableC4[];
extern const char table130[];

struct String {
    char storage[28];
    String(const char*);
    ~String();
};

inline String::String(const char* text)
{
    stringConstruct(this, text);
}

inline String::~String()
{
    stringDestroy(this);
}

struct Base {
    char storage[0x134];
    Base();
    ~Base();
};

struct S : Base {
    volatile unsigned int kind;
    S();
    void setValue(const String&);
};

S::S()
{
    volatile unsigned int* p =
        reinterpret_cast<volatile unsigned int*>(this);
    p[0x00 / 4] = reinterpret_cast<unsigned int>(table00);
    p[0x10 / 4] = reinterpret_cast<unsigned int>(table10);
    p[0x14 / 4] = reinterpret_cast<unsigned int>(table14);
    p[0x20 / 4] = reinterpret_cast<unsigned int>(table20);
    p[0x24 / 4] = reinterpret_cast<unsigned int>(table24);
    p[0x44 / 4] = reinterpret_cast<unsigned int>(table44);
    p[0x64 / 4] = reinterpret_cast<unsigned int>(table64);
    p[0x84 / 4] = reinterpret_cast<unsigned int>(table84);
    p[0xa4 / 4] = reinterpret_cast<unsigned int>(tableA4);
    p[0xc4 / 4] = reinterpret_cast<unsigned int>(tableC4);
    p[0x130 / 4] = reinterpret_cast<unsigned int>(table130);
    kind = 0xe2;
    String name("Skin");
    setValue(name);
}
