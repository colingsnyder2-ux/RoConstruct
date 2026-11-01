// from server: 100% by king_originala
struct S {
    unsigned int words[84];
    int* table;

    void f();
    void finish();
};

void S::f()
{
    int* initialTable = table;
    words[0]  = 0x834cfc;
    words[4]  = 0x834cec;
    words[5]  = 0x834ce4;
    words[8]  = 0x834cdc;
    words[9]  = 0x834ccc;
    words[17] = 0x834cbc;
    words[25] = 0x834cac;
    words[33] = 0x834c9c;
    words[41] = 0x834c8c;
    words[49] = 0x834c7c;
    words[76] = 0x834c74;
    words[80] = 0x834c5c;

    *(unsigned int*)((char*)this + 0x150 + initialTable[1]) = 0x834c54;
    *(unsigned int*)((char*)this + 0x150 + table[2]) = 0x834c38;

    int offset = table[1];
    *(int*)((char*)this + 0x14c + offset) = offset - 0x78;

    offset = table[2];
    *(int*)((char*)this + 0x14c + offset) = offset - 0x80;

    finish();
}
