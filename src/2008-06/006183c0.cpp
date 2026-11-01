// from server: 100% by king_originala
struct S {
    unsigned int data[112];
    int* table;
    void f();
    void finish();
};

void S::f()
{
    int* t = table;
    data[0x00 / 4] = 0x843d4c;
    data[0x10 / 4] = 0x843d3c;
    data[0x14 / 4] = 0x843d34;
    data[0x20 / 4] = 0x843d2c;
    data[0x24 / 4] = 0x843d1c;
    data[0x44 / 4] = 0x843d0c;
    data[0x64 / 4] = 0x843cfc;
    data[0x84 / 4] = 0x843cec;
    data[0xa4 / 4] = 0x843cdc;
    data[0xc4 / 4] = 0x843ccc;
    data[0x130 / 4] = 0x843cc4;
    data[0x1a0 / 4] = 0x843cbc;
    data[0x1b0 / 4] = 0x843ca4;
    *reinterpret_cast<unsigned int*>(
        reinterpret_cast<char*>(this) + 0x1c0 + t[1]) = 0x843c9c;
    int offset = table[1];
    *reinterpret_cast<int*>(
        reinterpret_cast<char*>(this) + 0x1bc + offset) = offset - 0xac;
    finish();
}
