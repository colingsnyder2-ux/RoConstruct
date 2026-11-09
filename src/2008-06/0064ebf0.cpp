// from server: 100% by king_originala
struct String;
extern void (__thiscall *string_construct)(String *);
extern void (__thiscall *string_destroy)(String *);
extern const float initialX;
extern const float initialY;

struct String
{
    char storage[28];
    String(int);
    ~String();
};

inline String::String(int)
{
    string_construct(this);
}

inline String::~String()
{
    string_destroy(this);
}

struct ChatEnter
{
    unsigned int words[83];
    ChatEnter(unsigned int);
    ~ChatEnter();
    ChatEnter *construct(unsigned int);
};

inline ChatEnter::ChatEnter(unsigned int value)
{
    construct(value);
}

struct S : ChatEnter
{
    String value;
    S(unsigned int, const String &);
    int installTables();
    void setValue(const String &);
};

__forceinline int S::installTables()
{
    words[0] = 0x84b5f4;
    words[4] = 0x84b5e4;
    words[5] = 0x84b5dc;
    words[8] = 0x84b5d4;
    words[9] = 0x84b5c4;
    words[17] = 0x84b5b4;
    words[25] = 0x84b5a4;
    words[33] = 0x84b594;
    words[41] = 0x84b584;
    words[49] = 0x84b574;
    words[76] = 0x84b56c;
    return 0;
}

S::S(unsigned int argument, const String &text)
    : ChatEnter(argument), value(installTables())
{
    setValue(text);
    *reinterpret_cast<float *>(&words[79]) = initialX;
    *reinterpret_cast<float *>(&words[80]) = initialY;
}
