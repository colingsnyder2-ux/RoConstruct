// from server: 100% by king_originala
typedef void (__thiscall *StringConstruct)(void *, const char *);
typedef void (__thiscall *StringDestroy)(void *);

extern StringConstruct const constructString;
extern StringDestroy const destroyString;

extern const char table0[], table10[], table14[], table20[], table24[];
extern const char table44[], table64[], table84[], tableA4[], tableC4[];
extern const char table130[];

struct String {
    char storage[28];
    String(const char *);
    ~String();
};

inline String::String(const char *text)
{
    constructString(this, text);
}

inline String::~String()
{
    destroyString(this);
}

struct Base {
    unsigned long storage[77];
    Base();
    ~Base();
    void setName(const String &);
};

struct S : Base {
    S();
};

S::S()
{
    storage[0]  = reinterpret_cast<unsigned long>(table0);
    storage[4]  = reinterpret_cast<unsigned long>(table10);
    storage[5]  = reinterpret_cast<unsigned long>(table14);
    storage[8]  = reinterpret_cast<unsigned long>(table20);
    storage[9]  = reinterpret_cast<unsigned long>(table24);
    storage[17] = reinterpret_cast<unsigned long>(table44);
    storage[25] = reinterpret_cast<unsigned long>(table64);
    storage[33] = reinterpret_cast<unsigned long>(table84);
    storage[41] = reinterpret_cast<unsigned long>(tableA4);
    storage[49] = reinterpret_cast<unsigned long>(tableC4);
    storage[76] = reinterpret_cast<unsigned long>(table130);
    setName(String("MotorFeature"));
}
