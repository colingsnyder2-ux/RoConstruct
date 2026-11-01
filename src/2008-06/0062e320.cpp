// from server: 100% by king_originala
struct S {
    volatile unsigned int data[82];

    void initialize(int argument);
    S* construct(int argument);
};

S* S::construct(int argument)
{
    initialize(argument);
    data[0x134 / 4] = 0xffffffff;
    data[0x130 / 4] = 0x0083d1f4;
    data[0x13c / 4] = 0;
    data[0x000 / 4] = 0x00846bec;
    data[0x010 / 4] = 0x00846be0;
    data[0x014 / 4] = 0x00846bd8;
    data[0x020 / 4] = 0x00846bd0;
    data[0x024 / 4] = 0x00846bc0;
    data[0x044 / 4] = 0x00846bb0;
    data[0x064 / 4] = 0x00846ba0;
    data[0x084 / 4] = 0x00846b90;
    data[0x0a4 / 4] = 0x00846b80;
    data[0x0c4 / 4] = 0x00846b70;
    data[0x130 / 4] = 0x00846b54;
    data[0x138 / 4] = 0x00846b48;
    data[0x140 / 4] = 0;
    data[0x144 / 4] = 0;
    return this;
}
