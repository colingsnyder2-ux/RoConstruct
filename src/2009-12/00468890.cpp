// from server: 14% by atomic.potato
struct CRobloxWnd {
    char pad0[0x20];
    void* field20;
    char pad24[0xdc - 0x24];
    unsigned char fieldDC;
    char padDD[0x100 - 0xDD];

    void func();
};

struct Inner {
    char pad0[0x18];
    int field18;
    char pad1c[0x18];
    int field34;
    char pad38[0x18];
    int field50;
    char pad54[0x18];
    int field6c;
    char pad70[0x18];
    int field88;
};

extern "C" int __stdcall GetClientRect(void*, void*);
extern "C" void __stdcall sub_7f46d6(void*, void*);
extern "C" void __stdcall sub_4d9540(void*, void*);
extern "C" void __stdcall sub_4618f0(void*);
extern "C" void __stdcall sub_463760(void*, void*);

extern int g_b12570;

void CRobloxWnd::func()
{
    char buf[0x100];
    Inner inner;
    void* rect[4];

    sub_4618f0(&inner);

    unsigned char b = fieldDC;
    int v = (b != 0) ? 8 : 0;

    inner.field18 = 0;
    inner.field34 = 8;
    inner.field50 = 8;
    inner.field6c = 0;
    inner.field88 = g_b12570;

    sub_7f46d6(&inner, this);

    GetClientRect(field20, rect);

    sub_4d9540(&inner, rect[0]);

    sub_463760(this, 0);
}
