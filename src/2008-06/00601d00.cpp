// from server: 100% by king_originala
struct S {
    unsigned int words[77];
    void init(int a, int b);
    S* f(int a, int b);
};

S* S::f(int a, int b)
{
    init(a, b);
    words[0]  = 0x0084232c;
    words[4]  = 0x0084231c;
    words[5]  = 0x00842314;
    words[8]  = 0x0084230c;
    words[9]  = 0x008422fc;
    words[17] = 0x008422ec;
    words[25] = 0x008422dc;
    words[33] = 0x008422cc;
    words[41] = 0x008422bc;
    words[49] = 0x008422ac;
    words[76] = 0x008422a4;
    return this;
}
