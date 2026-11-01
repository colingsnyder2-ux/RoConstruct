// from server: 100% by king_originala
struct Base
{
    volatile unsigned long words[79];
    Base();
};

struct S : Base
{
    volatile float first;
    volatile float second;
    S(float, float);
};

S::S(float a, float b)
{
    words[0] = 0x0084204c;
    words[4] = 0x0084203c;
    words[5] = 0x00842034;
    words[8] = 0x0084202c;
    words[9] = 0x0084201c;
    words[17] = 0x0084200c;
    words[25] = 0x00841ffc;
    words[33] = 0x00841fec;
    words[41] = 0x00841fdc;
    words[49] = 0x00841fcc;
    words[76] = 0x00841fc4;
    first = a;
    second = b;
}
