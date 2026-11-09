// from server: 54% by colin
struct CObjectBrowser {
    char pad0[0x54];
    int field54;
    char pad58[0x118];
    int field170;
    int method(int);
};

extern "C" int __stdcall sub_630646(int);
extern "C" int __stdcall sub_6305B0(int, int, int);
extern "C" int __stdcall sub_630652(int, int, int);

int CObjectBrowser::method(int arg) {
    int result = sub_630646(arg);
    if (result == -1)
        return 0;

    int* p58 = (int*)((char*)this + 0x58);
    int vtbl140 = *(int*)(*(int*)p58 + 0x140);
    int r = ((int (__stdcall*)(int, int, int, int, int, int))vtbl140)((int)p58, (int)this, 1, 2, 0x50000000, 0xe900);
    if (r == 0)
        return -1;

    int vtbl1c8 = *(int*)(*(int*)p58 + 0x1c8);
    ((int (__stdcall*)(int, int))vtbl1c8)((int)p58, 4);

    int local[6];
    local[0] = 0;
    local[0] = this->field54;
    local[1] = 0;
    local[2] = 0;
    local[3] = 0;
    local[4] = 0;

    int vtbl144 = *(int*)(*(int*)p58 + 0x144);
    r = ((int (__stdcall*)(int, int, int, int, int, int, int))vtbl144)((int)p58, 0, 0, 0x78c314, 0xc8, 0x258, (int)local);
    if (r == 0)
        return -1;

    int* p170 = (int*)((char*)this + 0x170);
    int saved170 = *p170;
    int r2 = sub_6305B0((int)p58, 0, 1);
    int vtbl140b = *(int*)(saved170 + 0x140);
    r = ((int (__stdcall*)(int, int, int, int, int, int))vtbl140b)((int)p170, (int)p58, 2, 1, 0x50800000, r2);
    if (r == 0)
        return -1;

    int vtbl144b = *(int*)(*p170 + 0x144);
    r = ((int (__stdcall*)(int, int, int, int, int, int, int))vtbl144b)((int)p170, 0, 0, 0x78c34c, 0x12c, 0xc8, (int)local);
    if (r == 0)
        return -1;

    int vtbl144c = *(int*)(*p170 + 0x144);
    r = ((int (__stdcall*)(int, int, int, int, int, int, int))vtbl144c)((int)p170, 1, 0, 0x78c2f8, 0x64, 0xbe, (int)local);
    if (r == 0)
        return -1;

    int a = sub_630652((int)p58, 0, 0);
    int b = sub_630652((int)p170, 0, 0);
    int c = sub_630652((int)p170, 1, 0);

    *(int*)(a + 0xa8) = b;
    *(int*)(a + 0xac) = c;
    *(int*)(b + 0xb0) = c;

    return 0;
}
