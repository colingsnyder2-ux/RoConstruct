// from server: 100% by king_originala
struct String;
extern void (__thiscall *stringConstruct)(String *, const char *);
extern void (__thiscall *stringDestroy)(String *);

struct String {
    unsigned char data[28];
    String(const char *);
    ~String();
};

inline String::String(const char *s) {
    stringConstruct(this, s);
}

inline String::~String() {
    stringDestroy(this);
}

struct Base {
    unsigned char data[0x12f];
    Base();
    ~Base();
    void setName(const String &);
};

struct Tool {
    Tool();
    ~Tool();
    unsigned char data[4];
};

struct Setup {
    Setup(void *);
};

inline Setup::Setup(void *p) {
    unsigned char *b = static_cast<unsigned char *>(p);
    *reinterpret_cast<unsigned long *>(b) = 0x8461ec;
    *reinterpret_cast<unsigned long *>(b + 0x10) = 0x8461dc;
    *reinterpret_cast<unsigned long *>(b + 0x14) = 0x8461d4;
    *reinterpret_cast<unsigned long *>(b + 0x20) = 0x8461cc;
    *reinterpret_cast<unsigned long *>(b + 0x24) = 0x8461bc;
    *reinterpret_cast<unsigned long *>(b + 0x44) = 0x8461ac;
    *reinterpret_cast<unsigned long *>(b + 0x64) = 0x84619c;
    *reinterpret_cast<unsigned long *>(b + 0x84) = 0x84618c;
    *reinterpret_cast<unsigned long *>(b + 0xa4) = 0x84617c;
    *reinterpret_cast<unsigned long *>(b + 0xc4) = 0x84616c;
}

struct Service {
    virtual void slot0() = 0;
    virtual void slot1() = 0;
    virtual void slot2() = 0;
    virtual void registerStand(void *, const bool *) = 0;
};

extern Service *service;

struct FlagStand : Base {
    Setup setup;
    Tool tool;
    FlagStand();
};

FlagStand::FlagStand() : Base(), setup(this), tool() {
    {
        String name(reinterpret_cast<const char *>(0x845f18));
        setName(name);
    }
    bool enabled = false;
    service->registerStand(reinterpret_cast<unsigned char *>(this) + 0x14,
                           &enabled);
}
