// from server: 75% by atomic.potato
extern "C" int __cdecl sub_007f3c38(int);
extern "C" int __cdecl sub_007fe4e0(int);
extern "C" int __cdecl sub_00811a40(int, int, int, int);
extern "C" int __cdecl sub_00804560(int, int);
extern "C" int __cdecl sub_008045e0(int, int);
extern "C" int __cdecl sub_008104b0(void);
extern "C" int (__stdcall *g_0098b20c)(int);

struct Global
{
    char padding[0x144];
    int value;
};

extern Global *g_00b9ada4;

struct CIDEBrowserView
{
    char padding0[0x20];
    int field20;
    char padding1[0x114];
    int field138;
    char padding2[0x100];
    int f(int);
};

int CIDEBrowserView::f(int arg)
{
    int r = sub_007f3c38(arg);
    if (r == -1)
        return r;

    char* edi = (char*)this + 0x100;
    sub_00811a40((int)edi, 0x50010010, (int)this, 0xe800);

    int v;
    if (this)
        v = field20;
    else
        v = 0;
    field138 = v;

    if (g_00b9ada4 == 0)
    {
        sub_007fe4e0(0);
        if (g_00b9ada4 == 0)
            goto skip;
    }
    g_0098b20c((int)&g_00b9ada4->value);

    if (g_00b9ada4 == 0)
        sub_007fe4e0(0);
    sub_00804560((int)edi, (int)g_00b9ada4);

skip:
    sub_008104b0();
    g_0098b20c((int)(char*)0 + 4);
    sub_008104b0();
    sub_008045e0((int)edi, 0);
    (*(int (__thiscall**)(int, int, int))(*(int*)edi + 0x154))((int)edi, 0x93, 0);
    return 0;
}
