// from server: 100% by king_originala
struct Exposer
{
    unsigned long data[78];
    void reset();
    void finish();
};

void Exposer::reset()
{
    data[0]  = 0x00822e44;
    data[4]  = 0x00822e38;
    data[5]  = 0x00822e30;
    data[8]  = 0x00822e28;
    data[9]  = 0x00822e18;
    data[17] = 0x00822e08;
    data[25] = 0x00822df8;
    data[33] = 0x00822de8;
    data[41] = 0x00822dd8;
    data[49] = 0x00822dc8;
    data[76] = 0x00822d98;
    data[77] = 0x00822d8c;
    finish();
}
