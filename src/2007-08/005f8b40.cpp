// from server: 100% by colin
struct SignalDesc {
    SignalDesc* construct(int);
    void* vtbl0;
    void* vtbl4;
    char pad8[8];
    void* vtbl10;
    void* vtbl14;
    char pad18[0x14];
    void* vtbl2c;
    char pad30[0x14];
    void* vtbl44;
    char pad48[0x14];
    void* vtbl5c;
    char pad60[0x14];
    void* vtbl74;
    char pad78[0x14];
    void* vtbl8c;
};

struct Base {
    void sub_5426B0(int);
};

SignalDesc* SignalDesc::construct(int a)
{
    ((Base*)this)->sub_5426B0(a);
    vtbl0 = (void*)0x7c1b3c;
    vtbl4 = (void*)0x7c1b34;
    vtbl10 = (void*)0x7c1b2c;
    vtbl14 = (void*)0x7c1b1c;
    vtbl2c = (void*)0x7c1b0c;
    vtbl44 = (void*)0x7c1afc;
    vtbl5c = (void*)0x7c1aec;
    vtbl74 = (void*)0x7c1adc;
    vtbl8c = (void*)0x7c1acc;
    return this;
}
