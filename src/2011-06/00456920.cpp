// from server: 42% by atomic.potato
struct VCRenderSettingsItem_EnumPropDescriptor
{
    char pad0[0x1c];
    int field1c;
    int field20;
    int field24;
    int f(int, int, int, int, int, int, int);
};

extern "C" void* __stdcall sub_401610(int, int);
extern "C" void* __stdcall sub_455c00();
extern "C" void* __stdcall sub_4545a0();
extern "C" void* __stdcall sub_5e4090(void*, void*, int, int, int, int);
extern "C" void* __stdcall sub_451f00(void*, int, int);
extern "C" void __stdcall sub_80a058(void*);

int VCRenderSettingsItem_EnumPropDescriptor::f(int a1, int a2, int a3, int a4, int a5, int a6, int a7)
{
    sub_401610(0xcb31c0, 0x455c60);
    void* p1 = sub_455c00();
    void* p2 = sub_4545a0();
    sub_5e4090(p2, p1, a1, a2, a3, a4);
    field1c = (int)p1;
    void* p3 = sub_451f00(&a5, a6, a7);
    int v = *(int*)p3;
    *(int*)p3 = 0;
    field20 = v;
    if (a5)
        sub_80a058((void*)a5);
    sub_401610(0xcb31c0, 0x455c60);
    void* p4 = sub_455c00();
    field24 = (int)p4;
    return (int)this;
}
