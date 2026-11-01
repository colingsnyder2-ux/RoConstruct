// from server: 100% by king_originala
struct String;
extern String * (__thiscall *string_copy)(String *, const String &);

struct String
{
    char storage[28];
    String(const String &);
};

inline String::String(const String &other)
{
    string_copy(this, other);
}

struct Base
{
    unsigned long table0;
    char pad04[12];
    unsigned long table10;
    unsigned long table14;
    char pad18[8];
    unsigned long table20;
    unsigned long table24;
    char pad28[28];
    unsigned long table44;
    char pad48[28];
    unsigned long table64;
    char pad68[28];
    unsigned long table84;
    char pad88[28];
    unsigned long tableA4;
    char padA8[28];
    unsigned long tableC4;
    char padC8[104];
    unsigned long table130;
    char pad134[84];

    Base(int, int);
    ~Base();
};

struct S : Base
{
    String value;
    S(int, const String &);
};

S::S(int argument, const String &text)
    : Base(argument, argument),
      value((table0   = 0x84becc,
             table10  = 0x84bebc,
             table14  = 0x84beb4,
             table20  = 0x84beac,
             table24  = 0x84be9c,
             table44  = 0x84be8c,
             table64  = 0x84be7c,
             table84  = 0x84be6c,
             tableA4  = 0x84be5c,
             tableC4  = 0x84be4c,
             table130 = 0x84be44,
             text))
{
}
