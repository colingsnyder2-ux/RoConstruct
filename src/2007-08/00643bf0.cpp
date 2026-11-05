// from server: 100% by colin
struct CXTPCommandBar;

extern "C" CXTPCommandBar* __cdecl sub_643980();

struct CXTPCommandBar {
    virtual int vfunc_0();
    virtual int vfunc_1();
    virtual int vfunc_2();
    virtual int vfunc_3();
    virtual int vfunc_4();
    virtual int vfunc_5();
    virtual int vfunc_6();
    virtual int vfunc_7();
    virtual int vfunc_8();
    virtual int vfunc_9();
    virtual int vfunc_10();
    virtual int vfunc_11();
    virtual int vfunc_12();
    virtual int vfunc_13();
    virtual int vfunc_14();
    virtual int vfunc_15();
    virtual int vfunc_16();
    virtual int vfunc_17();
    virtual int vfunc_18();
    virtual int vfunc_19();
    virtual int vfunc_20();
    virtual int vfunc_21();
    virtual int vfunc_22();
    virtual int vfunc_23();
    virtual int vfunc_24();
    virtual int vfunc_25();
};

int sub_643bf0()
{
    CXTPCommandBar* p = sub_643980();
    if (p == 0)
        return 0;
    return ((int (__thiscall*)(CXTPCommandBar*))(*((int**)p))[25])(p);
}
