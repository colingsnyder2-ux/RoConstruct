// from server: 100% by king_originala
typedef void (__thiscall *StringConstruct)(void *, const char *);
typedef void (__thiscall *StringDestroy)(void *);

extern StringConstruct constructString;
extern StringDestroy destroyString;

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
extern unsigned long table130[];

struct String {
    unsigned char storage[28];
    String(const char *);
    ~String();
};

__forceinline String::String(const char *text)
{
    constructString(this, text);
}

__forceinline String::~String()
{
    destroyString(this);
}

struct Base {
    unsigned long slots[104];
    Base();
    ~Base();
    void setName(const String &);
};

struct S : Base {
    unsigned long value;
    unsigned char enabled;
    S();
};

S::S() : Base()
{
    slots[0] = (unsigned long)table0;
    slots[4] = (unsigned long)table10;
    slots[5] = (unsigned long)table14;
    slots[8] = (unsigned long)table20;
    slots[9] = (unsigned long)table24;
    slots[17] = (unsigned long)table44;
    slots[25] = (unsigned long)table64;
    slots[33] = (unsigned long)table84;
    slots[41] = (unsigned long)tableA4;
    slots[49] = (unsigned long)tableC4;
    slots[76] = (unsigned long)table130;
    value = 0;
    enabled = 0;
    setName(String("HopperBin"));
}
