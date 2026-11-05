// from server: 38% by colin
struct CXTPToolBar {
    int sub_738406(int*);
    int sub_668F70();
    int sub_668770(int);
    int sub_630238(void*);
    int sub_63022C();
    int sub_41F680();
    int sub_630A1E();
    int func_651A10(int, int);
};

extern "C" {
    void* __stdcall CreateBitmap(int, int, unsigned int, unsigned int, const void*);
    void* __stdcall CreatePatternBrush(void*);
    int __stdcall PatBlt(void*, int, int, int, int, unsigned long);
}

int CXTPToolBar::func_651A10(int a, int b)
{
    unsigned short pattern[8];
    pattern[0] = 0x55;
    pattern[1] = 0xaa;
    pattern[2] = 0x55;
    pattern[3] = 0xaa;
    pattern[4] = 0x55;
    pattern[5] = 0xaa;
    pattern[6] = 0x55;
    pattern[7] = 0xaa;

    void* bmp = CreateBitmap(8, 8, 1, 1, pattern);
    void* brush = CreatePatternBrush(bmp);

    int v1 = sub_738406(&a);
    int v2 = sub_668F70();
    int v3 = sub_668770(0xf);
    int v4 = (*(int (__thiscall**)(int, int))(*(int*)a + 0x34))(a, v3);
    int v5 = sub_668F70();
    int v6 = sub_668770(0x14);
    int v7 = (*(int (__thiscall**)(int, int))(*(int*)a + 0x38))(a, v6);

    int x = *(int*)(b + 4);
    int y = *(int*)(b + 0);
    int w = *(int*)(b + 0xc) - x;
    int h = *(int*)(b + 8) - y;

    PatBlt(*(void**)(a + 4), y, x, h, w, 0xf00021);

    sub_738406(&v1);
    (*(int (__thiscall**)(int, int))(*(int*)a + 0x34))(a, v4);
    (*(int (__thiscall**)(int, int))(*(int*)a + 0x38))(a, v7);

    sub_63022C();
    sub_41F680();
    sub_41F680();
    sub_630A1E();

    return 0;
}
