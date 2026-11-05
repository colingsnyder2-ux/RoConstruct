// from server: 100% by king_originala
struct String;

extern "C" {
extern void (__thiscall *string_construct)(String *, const char *);
extern void (__thiscall *string_destroy)(String *);
}

struct String {
    unsigned char storage[28];
    String(const char *text) { string_construct(this, text); }
    ~String() { string_destroy(this); }
};

struct Base {
    unsigned int words[76];
    unsigned char enabled;
    unsigned char flag1;
    unsigned char flag2;
    unsigned char flag3;
    int mode;

    Base();
    ~Base();
    void setName(const String &name);
};

struct S : Base {
    S();
};

S::S()
{
    words[0] = 0x82e6e4;
    words[4] = 0x82e6d8;
    words[5] = 0x82e6d0;
    words[8] = 0x82e6c8;
    words[9] = 0x82e6b8;
    words[17] = 0x82e6a8;
    words[25] = 0x82e698;
    words[33] = 0x82e688;
    words[41] = 0x82e678;
    words[49] = 0x82e668;
    enabled = 1;
    flag1 = 0;
    flag3 = 0;
    mode = 1;
    String name("Diagnostics");
    setName(name);
}
