// from server: 100% by king_originala
struct Name;
extern const Name& __cdecl getLocalScope();
extern const float initialValue;

extern const char table0[], table10[], table14[], table20[];
extern const char table24[], table44[], table64[], table84[];
extern const char tableA4[], tableC4[], table130[];

typedef void (__thiscall *StringDefaultCtor)(void*);
typedef void (__thiscall *StringTextCtor)(void*, const char*);
typedef void (__thiscall *StringDtor)(void*);

extern StringDefaultCtor stringDefaultCtor;
extern StringTextCtor stringTextCtor;
extern StringDtor stringDtor;

struct String
{
    unsigned char storage[28];
    String();
    String(const char*);
    ~String();
};

inline String::String()
{
    stringDefaultCtor(this);
}

inline String::String(const char* text)
{
    stringTextCtor(this, text);
}

inline String::~String()
{
    stringDtor(this);
}

struct Guid
{
    String value;
    const Name* scope;
    Guid(int);
    ~Guid();
};

inline Guid::Guid(int) : value(), scope(&getLocalScope())
{
}

inline Guid::~Guid()
{
}

struct Base
{
    unsigned int words[81];
    Base();
    ~Base();
    void setName(const String&);
};

struct Decal : Base
{
    Guid guid;
    float transparency;
    float value;
    Decal();
};

Decal::Decal()
    : Base(),
      guid((
          words[0] = (unsigned int)table0,
          words[4] = (unsigned int)table10,
          words[5] = (unsigned int)table14,
          words[8] = (unsigned int)table20,
          words[9] = (unsigned int)table24,
          words[17] = (unsigned int)table44,
          words[25] = (unsigned int)table64,
          words[33] = (unsigned int)table84,
          words[41] = (unsigned int)tableA4,
          words[49] = (unsigned int)tableC4,
          words[76] = (unsigned int)table130,
          0)),
      transparency(0.0f),
      value(initialValue)
{
    String name("Decal");
    setName(name);
}
