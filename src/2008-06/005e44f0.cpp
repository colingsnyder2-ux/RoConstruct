// from server: 100% by king_originala
struct String;

extern void (__thiscall *string_construct)(String *, const char *);
extern void (__thiscall *string_destroy)(String *);

struct String
{
    char storage[28];
    String(const char *);
    ~String();
};

__forceinline String::String(const char *text)
{
    string_construct(this, text);
}

__forceinline String::~String()
{
    string_destroy(this);
}

struct Base
{
    unsigned long words[77];

    Base(int);
    ~Base();
    void setName(const String &);
};

struct S : Base
{
    S(int);
};

S::S(int argument) : Base(argument)
{
    words[0]  = 0x0083f16c;
    words[4]  = 0x0083f160;
    words[5]  = 0x0083f158;
    words[8]  = 0x0083f150;
    words[9]  = 0x0083f140;
    words[17] = 0x0083f130;
    words[25] = 0x0083f120;
    words[33] = 0x0083f110;
    words[41] = 0x0083f100;
    words[49] = 0x0083f0f0;
    words[76] = 0x0083f0d8;

    setName(String("Snap"));
}
