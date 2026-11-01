// from server: 100% by king_originala
struct String {
    unsigned char data[28];
    String(const char*);
    ~String();
};

extern void (__thiscall *stringConstruct)(String*, const char*);
extern void (__thiscall *stringDestroy)(String*);

inline String::String(const char* text)
{
    stringConstruct(this, text);
}

inline String::~String()
{
    stringDestroy(this);
}

struct Base {
    unsigned int data[0x134 / 4];

    Base();
    ~Base();
    void setName(const String&);
};

struct Service : Base {
    Service();
};

Service::Service()
{
    data[0x00 / 4] = 0x83b454;
    data[0x10 / 4] = 0x83b448;
    data[0x14 / 4] = 0x83b440;
    data[0x20 / 4] = 0x83b438;
    data[0x24 / 4] = 0x83b428;
    data[0x44 / 4] = 0x83b418;
    data[0x64 / 4] = 0x83b408;
    data[0x84 / 4] = 0x83b3f8;
    data[0xa4 / 4] = 0x83b3e8;
    data[0xc4 / 4] = 0x83b3d8;
    data[0x130 / 4] = 0x83b3d0;

    String name("StarterPack");
    setName(name);
}
