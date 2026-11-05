// from server: 100% by king_originala
struct S {
    unsigned int data[78];
    void reset();
    void finish();
};

void S::reset()
{
    data[0]  = 0x0082336C;
    data[4]  = 0x00823360;
    data[5]  = 0x00823358;
    data[8]  = 0x00823350;
    data[9]  = 0x00823340;
    data[17] = 0x00823330;
    data[25] = 0x00823320;
    data[33] = 0x00823310;
    data[41] = 0x00823300;
    data[49] = 0x008232F0;
    data[76] = 0x008232C0;
    data[77] = 0x008232B4;
    finish();
}
