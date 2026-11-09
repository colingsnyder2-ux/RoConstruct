// from server: 100% by king_originala
struct Rect {
    int left, top, right, bottom;
};

struct Context {
    int unused;
    void* dc;
};

struct Theme {
    int available();
    int draw(void*, int, int, const Rect*, const Rect*);
};

struct ThemeInfo {
    int unused;
    int kind;
    char padding[12];
    Theme theme;
};

struct I_func_00714140 {
    char pad[324];
    int m_x;
};

struct S_func_00714140 {
    char pad[176];
    I_func_00714140* m_p;
    int f();
};

extern "C" {
    extern int (__stdcall *DrawFrameControl)(void*, Rect*, unsigned int, unsigned int);
}

#define V(N) virtual void v##N();

struct XBoolItem {
    V(0) V(1) V(2) V(3) V(4) V(5) V(6) V(7)
    V(8) V(9) V(10) V(11) V(12) V(13) V(14) V(15)
    V(16) V(17) V(18) V(19) V(20) V(21)
    virtual int checked();
    V(23) V(24) V(25) V(26) V(27) V(28) V(29) V(30)
    V(31) V(32) V(33) V(34) V(35) V(36) V(37) V(38)
    V(39) V(40) V(41) V(42) V(43) V(44) V(45) V(46)
    V(47) V(48) V(49) V(50) V(51) V(52) V(53) V(54)
    V(55) V(56) V(57)
    virtual int hot();
    V(59) V(60) V(61) V(62) V(63)
    virtual bool disabled();

    char pad0[184];
    S_func_00714140* provider;
    char pad1[92];
    int enabled;

    int draw(Context*, int, int, int, int);
};

#undef V

int XBoolItem::draw(Context* context, int x, int top, int unused, int bottom)
{
    if (!enabled)
        return 0;

    Rect rect;
    rect.left = x - 1;
    int center = (top + bottom) / 2;
    rect.top = center - 6;
    rect.right = x + 12;
    rect.bottom = center + 7;

    ThemeInfo* info = reinterpret_cast<ThemeInfo*>(provider->f());
    if (info->kind == 1 && info->theme.available()) {
        int state;
        if (checked()) {
            if (disabled())
                state = 12;
            else
                state = (hot() != 0 ? 4 : 0) + 4;
        } else {
            if (disabled())
                state = 9;
            else
                state = (hot() != 0 ? 4 : 0) + 1;
        }
        void* dc = context;
        if (context)
            dc = context->dc;
        info->theme.draw(dc, 3, state, &rect, 0);
        return 1;
    }

    unsigned int hotFlags = hot() != 0 ? 0x400 : 0;
    unsigned int flags = checked() != 0 ? 0x100 : 0;
    flags |= hotFlags;
    DrawFrameControl(context->dc, &rect, 4, flags);
    return 1;
}
