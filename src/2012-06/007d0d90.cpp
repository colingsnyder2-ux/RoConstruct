// from server: 100% by Intel
extern "C" int __cdecl sub_798700(int);

struct VCharacterAppearance {
    char pad[0x34];
    int field_38;

    virtual void vfunc_0();
    virtual void vfunc_1();
    virtual void vfunc_2();
    virtual void vfunc_3();
    virtual void vfunc_4();
    virtual void vfunc_5();
    virtual void vfunc_6();
    virtual void vfunc_7();
    virtual void vfunc_8();
    virtual void vfunc_9();
    virtual void vfunc_10();
    virtual void vfunc_11();
    virtual void vfunc_12();
    virtual void vfunc_13();
    virtual void vfunc_14();
    virtual void vfunc_15();
    virtual void vfunc_16();
    virtual void vfunc_17();
    virtual void vfunc_18();
    virtual void vfunc_19();
    virtual void vfunc_20();
    virtual void vfunc_21();
    virtual void vfunc_22(int);

    void sub_7D0D90();
};

void VCharacterAppearance::sub_7D0D90() {
    int value = sub_798700(this->field_38);
    if (value) {
        this->vfunc_22(value);
    }
}
