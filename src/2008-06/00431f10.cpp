// from server: 100% by king_originala
struct Owned {
    ~Owned();
};

struct Handle {
    void *value;

    Handle() : value(0) {}
    Handle(const Handle &other) : value(other.value) {}
    ~Handle() {}
};

struct SettingValue {
    void apply(int);
};

struct Settings {
    int prefix;
    SettingValue value;
    char data[0x57];

    Settings(int, Handle, const char *);
    ~Settings();
    int available();
};

extern int (__thiscall *getHandle)(void *, int);

struct CDataModelPropGrid {
    char padding[0xF4];
    Owned *owned;
    unsigned char flagF8;
    unsigned char flagF9;
    char paddingFA[10];
    unsigned char flag104;
    char padding105[3];
    int handle;

    void reset(int);
    void configure(Settings *, int);
    void complete();
    void f();
};

void CDataModelPropGrid::f()
{
    Owned *old = owned;
    owned = 0;
    if (old)
        delete old;

    if (flagF8) {
        reset(0);
        flagF9 = 1;
    } else {
        flagF9 = 0;
    }

    if (!flag104) {
        Settings settings(0, Handle(), "IDE\0Settings");
        if (settings.available()) {
            configure(&settings, 1);
            settings.value.apply(getHandle(&handle, 1));
        }
    }

    complete();
}
