// from server: 100% by king_originala
struct S {
    unsigned long data[50];

    void initialize(int arg);
    S* construct(int arg);
};

S* S::construct(int arg)
{
    initialize(arg);
    data[0]  = 0x00823764;
    data[4]  = 0x00823754;
    data[5]  = 0x0082374C;
    data[8]  = 0x00823744;
    data[9]  = 0x00823734;
    data[17] = 0x00823724;
    data[25] = 0x00823714;
    data[33] = 0x00823704;
    data[41] = 0x008236F4;
    data[49] = 0x008236E4;
    return this;
}
