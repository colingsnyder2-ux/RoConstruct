// from server: 100% by king_originala
struct S {
    unsigned char data[0x1d8];
    void base(int);
    S* f(int);
};

S* S::f(int initialize)
{
    volatile int state = 0;

    if (initialize) {
        *reinterpret_cast<unsigned long*>(data + 0x150) = 0x834eb4;
        *reinterpret_cast<unsigned long*>(data + 0x1d4) = 0x846144;
    }

    base(0);

    int* table = *reinterpret_cast<int**>(data + 0x150);

    *reinterpret_cast<unsigned long*>(data) = 0x834cfc;
    *reinterpret_cast<unsigned long*>(data + 0x10) = 0x834cec;
    *reinterpret_cast<unsigned long*>(data + 0x14) = 0x834ce4;
    *reinterpret_cast<unsigned long*>(data + 0x20) = 0x834cdc;
    *reinterpret_cast<unsigned long*>(data + 0x24) = 0x834ccc;
    *reinterpret_cast<unsigned long*>(data + 0x44) = 0x834cbc;
    *reinterpret_cast<unsigned long*>(data + 0x64) = 0x834cac;
    *reinterpret_cast<unsigned long*>(data + 0x84) = 0x834c9c;
    *reinterpret_cast<unsigned long*>(data + 0xa4) = 0x834c8c;
    *reinterpret_cast<unsigned long*>(data + 0xc4) = 0x834c7c;
    *reinterpret_cast<unsigned long*>(data + 0x130) = 0x834c74;
    *reinterpret_cast<unsigned long*>(data + 0x140) = 0x834c5c;

    *reinterpret_cast<unsigned long*>(data + 0x150 + table[1]) = 0x834c54;
    table = *reinterpret_cast<int**>(data + 0x150);
    *reinterpret_cast<unsigned long*>(data + 0x150 + table[2]) = 0x834c38;

    table = *reinterpret_cast<int**>(data + 0x150);
    int offset = table[1];
    *reinterpret_cast<int*>(data + 0x14c + offset) = offset - 0x78;

    table = *reinterpret_cast<int**>(data + 0x150);
    offset = table[2];
    *reinterpret_cast<int*>(data + 0x14c + offset) = offset - 0x80;

    return this;
}
