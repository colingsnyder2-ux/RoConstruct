// from server: 100% by tester
struct CXTPPropertyGridItemEnum {
    virtual void vfunc_00();
    virtual void vfunc_04();
    virtual void vfunc_08();
    virtual void vfunc_0c();
    virtual void vfunc_10();
    virtual void vfunc_14();
    virtual void vfunc_18();
    virtual void vfunc_1c();
    virtual void vfunc_20();
    virtual void vfunc_24();
    virtual void vfunc_28();
    virtual void vfunc_2c();
    virtual void vfunc_30();
    virtual void vfunc_34();
    virtual void vfunc_38();
    virtual void vfunc_3c();
    virtual void vfunc_40();
    virtual void vfunc_44();
    virtual void vfunc_48();
    virtual void vfunc_4c();
    virtual void vfunc_50();
    virtual void vfunc_54();
    virtual void vfunc_58();
    virtual void vfunc_5c();
    virtual void vfunc_60();
    virtual void vfunc_64();
    virtual void vfunc_68();
    virtual void vfunc_6c();
    virtual void vfunc_70();
    virtual void vfunc_74();
    virtual void vfunc_78();
    virtual void vfunc_7c();
    virtual void vfunc_80();
    virtual void vfunc_84();
    virtual void vfunc_88();
    virtual void vfunc_8c();
    virtual void vfunc_90();
    virtual void vfunc_94();
    virtual void vfunc_98();
    virtual void vfunc_9c();
    virtual void vfunc_a0();
    virtual void vfunc_a4();
    virtual void vfunc_a8();
    virtual void vfunc_ac();
    virtual void vfunc_b0();
    virtual void vfunc_b4();
    virtual void vfunc_b8();
    virtual void vfunc_bc();
    virtual void vfunc_c0();
    virtual void vfunc_c4();
    virtual void vfunc_c8();
    virtual void vfunc_cc();
    virtual void vfunc_d0();
    virtual void vfunc_d4();
    virtual void vfunc_d8();
    virtual void vfunc_dc();
    virtual void vfunc_e0();
    virtual void vfunc_e4();
    virtual void vfunc_e8(int);
    char pad_0004[264];
    int m_100;
    int* m_104;
    void f();
};

void CXTPPropertyGridItemEnum::f()
{
    int* p = m_104;
    if (p != 0) {
        int v = *p;
        if (v != m_100) {
            vfunc_e8(v);
        }
    }
}
