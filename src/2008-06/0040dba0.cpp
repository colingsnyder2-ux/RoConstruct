// from server: 100% by king_originala
struct S {
    unsigned long data[86];
    S* base_init();
    S* init();
};

S* S::init()
{
    base_init();
    data[0] = 0x0080cda4;
    data[4] = 0x0080cd98;
    data[5] = 0x0080cd90;
    data[8] = 0x0080cd88;
    data[9] = 0x0080cd78;
    data[17] = 0x0080cd68;
    data[25] = 0x0080cd58;
    data[33] = 0x0080cd48;
    data[41] = 0x0080cd38;
    data[49] = 0x0080cd28;
    data[84] = 0xffffffffUL;
    data[85] = 0;
    return this;
}
