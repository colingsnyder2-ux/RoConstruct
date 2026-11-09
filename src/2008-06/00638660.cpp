// from server: 100% by king_originala
struct String
{
    char storage[28];

    __forceinline String(const char*);
    __forceinline ~String();
};

typedef void (__thiscall *StringConstruct)(String*, const char*);
typedef void (__thiscall *StringDestroy)(String*);

extern StringConstruct stringConstruct;
extern StringDestroy stringDestroy;

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
    unsigned long storage[76];

    Base();
    ~Base();
    void setName(const String&);
};

struct S : Base
{
    float x;
    float y;
    float z;

    S();
};

S::S() : Base()
{
    storage[0] = 0x84960c;
    storage[4] = 0x849600;
    storage[5] = 0x8495f8;
    storage[8] = 0x8495f0;
    storage[9] = 0x8495e0;
    storage[17] = 0x8495d0;
    storage[25] = 0x8495c0;
    storage[33] = 0x8495b0;
    storage[41] = 0x8495a0;
    storage[49] = 0x849590;

    x = *reinterpret_cast<const float*>(0x9611c0);
    y = *reinterpret_cast<const float*>(0x9611c4);
    z = *reinterpret_cast<const float*>(0x9611c8);

    String name(reinterpret_cast<const char*>(0x818478));
    setName(name);
}
