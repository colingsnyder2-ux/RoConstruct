// from server: 100% by colin
struct CXTPToolBar {
    virtual int vfunc_0000();
    virtual int vfunc_0004();
    virtual int vfunc_0008();
    virtual int vfunc_000c();
    virtual int vfunc_0010();
    virtual int vfunc_0014();
    virtual int vfunc_0018();
    virtual int vfunc_001c();
    virtual int vfunc_0020();
    virtual int vfunc_0024();
    virtual int vfunc_0028();
    virtual int vfunc_002c();
    virtual int vfunc_0030();
    virtual int vfunc_0034();
    virtual int vfunc_0038();
    virtual int vfunc_003c();
    virtual int vfunc_0040();
    virtual int vfunc_0044();
    virtual int vfunc_0048();
    virtual int vfunc_004c();
    virtual int vfunc_0050();
    virtual int vfunc_0054();
    virtual int vfunc_0058();
    virtual int vfunc_005c();
    virtual int vfunc_0060();
    virtual int vfunc_0064();
    virtual int vfunc_0068();
    virtual int vfunc_006c();
    virtual int vfunc_0070();
    virtual int vfunc_0074();
    virtual int vfunc_0078();
    virtual int vfunc_007c();
    virtual int vfunc_0080();
    virtual int vfunc_0084();
    virtual int vfunc_0088();
    virtual int vfunc_008c();
    virtual int vfunc_0090();
    virtual int vfunc_0094();
    virtual int vfunc_0098();
    virtual int vfunc_009c();
    virtual int vfunc_00a0();
    virtual int vfunc_00a4();
    virtual int vfunc_00a8();
    virtual int vfunc_00ac();
    virtual int vfunc_00b0();
    virtual int vfunc_00b4();
    virtual int vfunc_00b8();
    virtual int vfunc_00bc();
    virtual int vfunc_00c0();
    virtual int vfunc_00c4();
    virtual int vfunc_00c8();
    virtual int vfunc_00cc();
    virtual int vfunc_00d0();
    virtual int vfunc_00d4();
    virtual int vfunc_00d8();
    virtual int vfunc_00dc();
    virtual int vfunc_00e0();
    virtual int vfunc_00e4();
    virtual int vfunc_00e8();
    virtual int vfunc_00ec();
    virtual int vfunc_00f0();
    virtual int vfunc_00f4();
    virtual int vfunc_00f8();
    virtual int vfunc_00fc();
    virtual int vfunc_0100();
    virtual int vfunc_0104();
    virtual int vfunc_0108();
    virtual int vfunc_010c();
    virtual int vfunc_0110();
    virtual int vfunc_0114();
    virtual int vfunc_0118();
    virtual int vfunc_011c();
    virtual int vfunc_0120();
    virtual int vfunc_0124();
    virtual int vfunc_0128();
    virtual int vfunc_012c();
    virtual int vfunc_0130();
    virtual int vfunc_0134();
    virtual int vfunc_0138();
    virtual int vfunc_013c();
    virtual int vfunc_0140();
    virtual int vfunc_0144();
    virtual int vfunc_0148();
    virtual int vfunc_014c();
    virtual int vfunc_0150();
    virtual int vfunc_0154();
    virtual int vfunc_0158();
    virtual int vfunc_015c();
    virtual int vfunc_0160();
    virtual int vfunc_0164();
    virtual int vfunc_0168();
    virtual int vfunc_016c();
    virtual int vfunc_0170();
    virtual int vfunc_0174();
    virtual int vfunc_0178();
    int field_0xf8;
    int method_0064f050();
};

extern int __fastcall func_0067be70(int);

int CXTPToolBar::method_0064f050()
{
    if (vfunc_0178() == 0)
        return 0;
    int* p = *(int**)((char*)this + 0xf8);
    if (p[0x3c / 4] != 0)
    {
        if (func_0067be70(*(int*)((char*)this + 0xf8)) == 0)
            return 0;
    }
    return 1;
}
