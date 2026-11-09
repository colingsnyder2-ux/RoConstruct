// from server: 100% by king_originala
struct S {
    volatile unsigned int data[82];
    void initialize(int argument);
    S* construct(int argument);
};

S* S::construct(int argument)
{
    initialize(argument);
    data[0x000 / 4] = 0x0084718c;
    data[0x010 / 4] = 0x0084717c;
    data[0x014 / 4] = 0x00847174;
    data[0x020 / 4] = 0x0084716c;
    data[0x024 / 4] = 0x0084715c;
    data[0x044 / 4] = 0x0084714c;
    data[0x064 / 4] = 0x0084713c;
    data[0x084 / 4] = 0x0084712c;
    data[0x0a4 / 4] = 0x0084711c;
    data[0x0c4 / 4] = 0x0084710c;
    data[0x130 / 4] = 0x008470f0;
    data[0x138 / 4] = 0x008470e4;
    return this;
}
