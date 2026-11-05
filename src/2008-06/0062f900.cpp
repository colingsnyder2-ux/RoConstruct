// from server: 100% by colin
struct S {
    unsigned long data[79];
    void __thiscall initialize(int);
    S* __thiscall f(int);
};

S* S::f(int arg)
{
    initialize(arg);
    data[0] = 0x0084727c;
    data[4] = 0x0084726c;
    data[5] = 0x00847264;
    data[8] = 0x0084725c;
    data[9] = 0x0084724c;
    data[17] = 0x0084723c;
    data[25] = 0x0084722c;
    data[33] = 0x0084721c;
    data[41] = 0x0084720c;
    data[49] = 0x008471fc;
    data[76] = 0x008471e0;
    data[78] = 0x008471d4;
    return this;
}
