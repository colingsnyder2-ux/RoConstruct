// from server: 100% by king_originala
typedef unsigned long DWORD;

struct Control {
    char padding[32];
    DWORD handle;

    DWORD safeHandle() const {
        DWORD result = reinterpret_cast<DWORD>(this);
        if (this)
            result = handle;
        return result;
    }
};

#define SLOT(n) virtual void slot##n();
#define TEN(n) \
    SLOT(n##0) SLOT(n##1) SLOT(n##2) SLOT(n##3) SLOT(n##4) \
    SLOT(n##5) SLOT(n##6) SLOT(n##7) SLOT(n##8) SLOT(n##9)

struct View {
    TEN(0)
    TEN(1)
    TEN(2)
    TEN(3)
    TEN(4)
    TEN(5)
    TEN(6)
    TEN(7)
    TEN(8)
    TEN(9)
    TEN(10)
    TEN(11)
    TEN(12)
    SLOT(130)
    SLOT(131)
    SLOT(132)
    SLOT(133)
    SLOT(134)
    SLOT(135)
    SLOT(136)
    virtual void onChange();
    virtual void onKillFocus();
    virtual void onSetFocus();

    char padding[84];
    Control control;

    int fallback(DWORD command, DWORD source);
    int command(DWORD command, DWORD source);
};

#undef TEN
#undef SLOT

int View::command(DWORD command, DWORD source)
{
    if (source == control.safeHandle()) {
        switch (command >> 16) {
        case 0x100:
            onSetFocus();
            break;
        case 0x200:
            onKillFocus();
            break;
        case 0x300:
            onChange();
            break;
        }
        return 1;
    }
    return fallback(command, source);
}
