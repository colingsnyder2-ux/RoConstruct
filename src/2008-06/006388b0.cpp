// from server: 100% by king_originala
struct String;
typedef void (__thiscall *StringConstructor)(String *, const char *);
typedef void (__thiscall *StringDestructor)(String *);

extern StringConstructor stringConstructor;
extern StringDestructor stringDestructor;

struct String
{
    unsigned char storage[28];

    String(const char *text);
    ~String();
};

__forceinline String::String(const char *text)
{
    stringConstructor(this, text);
}

__forceinline String::~String()
{
    stringDestructor(this);
}

struct Base
{
    unsigned char storage[0x130];

    Base();
    ~Base();
    void setName(const String &name);
};

struct S : Base
{
    float x;
    float y;
    float z;

    S();
};

S::S()
{
    unsigned int *p = reinterpret_cast<unsigned int *>(this);
    p[0x00 / 4] = 0x84978c;
    p[0x10 / 4] = 0x849780;
    p[0x14 / 4] = 0x849778;
    p[0x20 / 4] = 0x849770;
    p[0x24 / 4] = 0x849760;
    p[0x44 / 4] = 0x849750;
    p[0x64 / 4] = 0x849740;
    p[0x84 / 4] = 0x849730;
    p[0xa4 / 4] = 0x849720;
    p[0xc4 / 4] = 0x849710;

    x = *reinterpret_cast<const float *>(0x97d320);
    y = *reinterpret_cast<const float *>(0x97d324);
    z = *reinterpret_cast<const float *>(0x97d328);

    String name(reinterpret_cast<const char *>(0x818478));
    setName(name);
}
