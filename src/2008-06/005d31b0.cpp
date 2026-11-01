// from server: 100% by king_originala
int __cdecl getName();

struct Flag {
    volatile int value;
    Flag() : value(0) {}
    ~Flag() {}
};

struct Base {
    int data[257];
    Base(int);
    ~Base();
};

struct S : Base {
    S(int);
};

S::S(int complete)
    : Base((Flag(), complete
        ? (data[0x134 / 4] = 0x849e6c,
           data[0x400 / 4] = 0x846144, 0)
        : 0))
{
    data[0x1c / 4] = getName();

    data[0x000 / 4] = 0x83bf7c;
    data[0x010 / 4] = 0x83bf70;
    data[0x014 / 4] = 0x83bf68;
    data[0x020 / 4] = 0x83bf60;
    data[0x024 / 4] = 0x83bf50;
    data[0x044 / 4] = 0x83bf40;
    data[0x064 / 4] = 0x83bf30;
    data[0x084 / 4] = 0x83bf20;
    data[0x0a4 / 4] = 0x83bf10;
    data[0x0c4 / 4] = 0x83bf00;
    data[0x130 / 4] = 0x83bef4;
    data[0x1a0 / 4] = 0x83bee4;
    data[0x1c0 / 4] = 0x83bed8;
    data[0x1cc / 4] = 0x83bec0;

    *(int *)((char *)this + 0x134 +
        ((int *)data[0x134 / 4])[1]) = 0x83beb4;
    *(int *)((char *)this + 0x134 +
        ((int *)data[0x134 / 4])[2]) = 0x83beac;
    *(int *)((char *)this + 0x134 +
        ((int *)data[0x134 / 4])[3]) = 0x83be90;

    int offset = ((int *)data[0x134 / 4])[1];
    *(int *)((char *)this + 0x130 + offset) = offset - 0x2b8;

    offset = ((int *)data[0x134 / 4])[2];
    *(int *)((char *)this + 0x130 + offset) = offset - 0x2c0;

    offset = ((int *)data[0x134 / 4])[3];
    *(int *)((char *)this + 0x130 + offset) = offset - 0x2c8;
}
