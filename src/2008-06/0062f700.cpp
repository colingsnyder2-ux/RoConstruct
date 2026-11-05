// from server: 100% by king_originala
struct S {
    unsigned int words[79];
    void __thiscall initialize(int arg);
    S* __thiscall f(int arg);
};

S* S::f(int arg)
{
    initialize(arg);
    words[0]  = 0x00846fac;
    words[4]  = 0x00846f9c;
    words[5]  = 0x00846f94;
    words[8]  = 0x00846f8c;
    words[9]  = 0x00846f7c;
    words[17] = 0x00846f6c;
    words[25] = 0x00846f5c;
    words[33] = 0x00846f4c;
    words[41] = 0x00846f3c;
    words[49] = 0x00846f2c;
    words[76] = 0x00846f10;
    words[78] = 0x00846f04;
    return this;
}
