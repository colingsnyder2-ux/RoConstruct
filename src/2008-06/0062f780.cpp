// from server: 100% by king_originala
struct S {
    unsigned int words[79];
    void base(int arg);
    S* f(int arg);
};

S* S::f(int arg)
{
    base(arg);
    words[0] = 0x0084709c;
    words[4] = 0x0084708c;
    words[5] = 0x00847084;
    words[8] = 0x0084707c;
    words[9] = 0x0084706c;
    words[17] = 0x0084705c;
    words[25] = 0x0084704c;
    words[33] = 0x0084703c;
    words[41] = 0x0084702c;
    words[49] = 0x0084701c;
    words[76] = 0x00847000;
    words[78] = 0x00846ff4;
    return this;
}
