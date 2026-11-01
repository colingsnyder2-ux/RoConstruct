// from server: 100% by king_originala
struct Text;

extern void (__thiscall *textConstruct)(Text *, const char *);
extern void (__thiscall *textDestroy)(Text *);

struct Text {
    unsigned char storage[28];

    Text(const char *s) { textConstruct(this, s); }
    ~Text() { textDestroy(this); }
};

struct Base {
    unsigned words[76];

    Base();
    ~Base();
    void setName(const Text &);
};

struct S : Base {
    unsigned value;

    S();
};

S::S()
{
    words[0]  = 0x84984c;
    words[4]  = 0x849840;
    words[5]  = 0x849838;
    words[8]  = 0x849830;
    words[9]  = 0x849820;
    words[17] = 0x849810;
    words[25] = 0x849800;
    words[33] = 0x8497f0;
    words[41] = 0x8497e0;
    words[49] = 0x8497d0;
    value = *reinterpret_cast<const unsigned *>(0x97d3ec);
    Text name("Value");
    setName(name);
}
