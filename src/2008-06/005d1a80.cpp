// from server: 100% by king_originala
struct String;

typedef void (__thiscall *StringConstructor)(String *, const char *);
typedef void (__thiscall *StringDestructor)(String *);

extern StringConstructor const stringConstructor;
extern StringDestructor const stringDestructor;

struct String
{
    unsigned char data[28];
    String(const char *);
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
    unsigned int data[91];

    Base();
    ~Base();
    void setName(const String &);
};

struct S : Base
{
    S();
};

S::S() : Base()
{
    data[0] = 0x83b9bc;
    data[4] = 0x83b9ac;
    data[5] = 0x83b9a4;
    data[8] = 0x83b99c;
    data[9] = 0x83b98c;
    data[17] = 0x83b97c;
    data[25] = 0x83b96c;
    data[33] = 0x83b95c;
    data[41] = 0x83b94c;
    data[49] = 0x83b93c;
    data[76] = 0x83b934;
    data[90] = 0x83b924;

    String name(reinterpret_cast<const char *>(0x83ba20));
    setName(name);
}
