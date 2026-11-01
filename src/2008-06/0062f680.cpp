// from server: 100% by king_originala
struct S {
    unsigned long words[79];
    void base(int arg);
    S* f(int arg);
};

S* S::f(int arg)
{
    base(arg);
    words[0]  = 0x00846cdc;
    words[4]  = 0x00846ccc;
    words[5]  = 0x00846cc4;
    words[8]  = 0x00846cbc;
    words[9]  = 0x00846cac;
    words[17] = 0x00846c9c;
    words[25] = 0x00846c8c;
    words[33] = 0x00846c7c;
    words[41] = 0x00846c6c;
    words[49] = 0x00846c5c;
    words[76] = 0x00846c40;
    words[78] = 0x00846c34;
    return this;
}
