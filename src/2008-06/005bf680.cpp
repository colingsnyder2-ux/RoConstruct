// from server: 100% by king_originala
struct String;
extern String* (__thiscall *stringConstruct)(String*, const char*);
extern void (__thiscall *stringDestroy)(String*);

struct String
{
    char storage[28];
    String(const char*);
    ~String();
};

__forceinline String::String(const char* text)
{
    stringConstruct(this, text);
}

__forceinline String::~String()
{
    stringDestroy(this);
}

struct Base
{
    unsigned long data[76];
    Base();
    ~Base();
    void setValue(const String&);
};

struct S : Base
{
    int first;
    int second;
    bool enabled;
    bool flag1;
    bool flag2;
    S();
};

S::S()
{
    data[0] = 0x838774;
    data[4] = 0x838768;
    data[5] = 0x838760;
    data[8] = 0x838758;
    data[9] = 0x838748;
    data[17] = 0x838738;
    data[25] = 0x838728;
    data[33] = 0x838718;
    data[41] = 0x838708;
    data[49] = 0x8386f8;
    first = 50;
    second = 5;
    enabled = true;
    flag1 = false;
    flag2 = false;
    String text((const char*)0x8387b4);
    setValue(text);
}
