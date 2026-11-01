// from server: 100% by king_originala
struct S {
    unsigned int data[257];
    void base(int);
    S* initialize(int);
};

S* S::initialize(int complete)
{
    volatile int state = 0;
    if (complete) {
        data[0x134 / 4] = 0x849e6c;
        data[0x400 / 4] = 0x846144;
    }

    base(0);

    int* table = (int*)data[0x134 / 4];
    data[0] = 0x83bb3c;
    data[0x10 / 4] = 0x83bb2c;
    data[0x14 / 4] = 0x83bb24;
    data[0x20 / 4] = 0x83bb1c;
    data[0x24 / 4] = 0x83bb0c;
    data[0x44 / 4] = 0x83bafc;
    data[0x64 / 4] = 0x83baec;
    data[0x84 / 4] = 0x83badc;
    data[0xa4 / 4] = 0x83bacc;
    data[0xc4 / 4] = 0x83babc;
    data[0x130 / 4] = 0x83bab0;
    data[0x1a0 / 4] = 0x83baa0;
    data[0x1c0 / 4] = 0x83ba94;
    data[0x1cc / 4] = 0x83ba7c;

    *(unsigned int*)((char*)this + 0x134 + table[1]) = 0x83ba70;
    *(unsigned int*)((char*)this + 0x134 +
        ((int*)data[0x134 / 4])[2]) = 0x83ba68;
    *(unsigned int*)((char*)this + 0x134 +
        ((int*)data[0x134 / 4])[3]) = 0x83ba4c;

    int offset = ((int*)data[0x134 / 4])[1];
    *(int*)((char*)this + 0x130 + offset) = offset - 0x2b8;
    offset = ((int*)data[0x134 / 4])[2];
    *(int*)((char*)this + 0x130 + offset) = offset - 0x2c0;
    offset = ((int*)data[0x134 / 4])[3];
    *(int*)((char*)this + 0x130 + offset) = offset - 0x2c8;

    return this;
}
