// from server: 100% by king_originala
struct String;
extern String* (__thiscall *stringConstruct)(String*, const char*);
extern void (__thiscall *stringDestroy)(String*);

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
    Base();
    ~Base();
};

struct Member {
    Member();
    ~Member();
};

struct Registry {
    virtual void slot0();
    virtual void slot1();
    virtual void slot2();
    virtual void registerValue(unsigned int*, bool*);
};

extern Registry* registry;

struct S : Base {
    unsigned int table0;
    char padding04[12];
    unsigned int table10;
    unsigned int table14;
    char padding18[8];
    unsigned int table20;
    unsigned int table24;
    char padding28[28];
    unsigned int table44;
    char padding48[28];
    unsigned int table64;
    char padding68[28];
    unsigned int table84;
    char padding88[28];
    unsigned int tableA4;
    char paddingA8[28];
    unsigned int tableC4;
    char paddingC8[104];
    Member member;

    S();
    void setValue(const String&);
};

S::S()
    : Base(),
      table0(0x83bd2c),
      table10(0x83bd1c),
      table14(0x83bd14),
      table20(0x83bd0c),
      table24(0x83bcfc),
      table44(0x83bcec),
      table64(0x83bcdc),
      table84(0x83bccc),
      tableA4(0x83bcbc),
      tableC4(0x83bcac),
      member()
{
    {
        String name((const char*)0x83ba38);
        setValue(name);
    }

    bool enabled = false;
    registry->registerValue(&table14, &enabled);
}
