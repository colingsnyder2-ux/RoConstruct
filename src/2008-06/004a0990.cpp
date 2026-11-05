// from server: 100% by king_originala
typedef unsigned long DWORD;

extern void (__thiscall *stringConstruct)(void *, const char *);
extern void (__thiscall *stringDestroy)(void *);

struct String
{
    char storage[28];
    __forceinline String(const char *);
    __forceinline ~String();
};

__forceinline String::String(const char *text)
{
    stringConstruct(this, text);
}

__forceinline String::~String()
{
    stringDestroy(this);
}

struct Base
{
    DWORD words[82];
    Base();
    ~Base();
    void setName(const String &);
};

struct S : Base
{
    S();
};

S::S()
{
    words[0] = 0x00822f4c;
    words[4] = 0x00822f40;
    words[5] = 0x00822f38;
    words[8] = 0x00822f30;
    words[9] = 0x00822f20;
    words[17] = 0x00822f10;
    words[25] = 0x00822f00;
    words[33] = 0x00822ef0;
    words[41] = 0x00822ee0;
    words[49] = 0x00822ed0;
    words[76] = 0x00822ea0;
    words[77] = 0x00822e94;
    words[81] = 0x00822e88;

    String name("NetworkClient");
    setName(name);
}
