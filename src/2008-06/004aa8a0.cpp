// from server: 100% by king_originala
struct String;
extern void (__thiscall *constructString)(String*, const char*);
extern void (__thiscall *destroyString)(String*);

struct String {
    char storage[28];
    String(const char* text) { constructString(this, text); }
    ~String() { destroyString(this); }
};

extern String __cdecl formatString(const char*, ...);

struct Exception {
    char storage[40];
    Exception(const String&);
    Exception(const Exception&);
    ~Exception();
};

struct Base {
    unsigned long table00;
    char padding04[12];
    unsigned long table10;
    unsigned long table14;
    char padding18[8];
    unsigned long table20;
    unsigned long table24;
    char padding28[28];
    unsigned long table44;
    char padding48[28];
    unsigned long table64;
    char padding68[28];
    unsigned long table84;
    char padding88[28];
    unsigned long tableA4;
    char paddingA8[28];
    unsigned long tableC4;

    Base();
    ~Base();
    void setValue(const String&);
};

struct S : Base {
    S();
};

extern S* singleton;

S::S()
{
    table00 = 0x824074;
    table10 = 0x824068;
    table14 = 0x824060;
    table20 = 0x824058;
    table24 = 0x824048;
    table44 = 0x824038;
    table64 = 0x824028;
    table84 = 0x824018;
    tableA4 = 0x824008;
    tableC4 = 0x823ff8;

    {
        String name("NetworkSettings");
        setValue(name);
    }

    if (singleton)
        throw Exception(formatString("singleton %s already exists",
                                     "NetworkSettings"));

    singleton = this;
}
