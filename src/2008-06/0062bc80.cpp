// from server: 100% by king_originala
struct S
{
    unsigned int data[257];
    void base(int);
    S* f(int);
};

S* S::f(int initialize)
{
    volatile int state = 0;

    if (initialize)
    {
        data[0x134 / 4] = 0x849e6c;
        data[0x400 / 4] = 0x846144;
    }

    base(0);

    unsigned int* table = (unsigned int*)data[0x134 / 4];

    data[0] = 0x84601c;
    data[0x10 / 4] = 0x846010;
    data[0x14 / 4] = 0x846008;
    data[0x20 / 4] = 0x846000;
    data[0x24 / 4] = 0x845ff0;
    data[0x44 / 4] = 0x845fe0;
    data[0x64 / 4] = 0x845fd0;
    data[0x84 / 4] = 0x845fc0;
    data[0xa4 / 4] = 0x845fb0;
    data[0xc4 / 4] = 0x845fa0;
    data[0x130 / 4] = 0x845f94;
    data[0x1a0 / 4] = 0x845f84;
    data[0x1c0 / 4] = 0x845f78;
    data[0x1cc / 4] = 0x845f60;

    *(unsigned int*)((char*)this + 0x134 + table[1]) = 0x845f54;
    *(unsigned int*)((char*)this + 0x134 +
        ((unsigned int*)data[0x134 / 4])[2]) = 0x845f4c;
    *(unsigned int*)((char*)this + 0x134 +
        ((unsigned int*)data[0x134 / 4])[3]) = 0x845f30;

    unsigned int offset = ((unsigned int*)data[0x134 / 4])[1];
    *(unsigned int*)((char*)this + 0x130 + offset) = offset - 0x2b8;

    offset = ((unsigned int*)data[0x134 / 4])[2];
    *(unsigned int*)((char*)this + 0x130 + offset) = offset - 0x2c0;

    offset = ((unsigned int*)data[0x134 / 4])[3];
    *(unsigned int*)((char*)this + 0x130 + offset) = offset - 0x2c8;

    return this;
}
