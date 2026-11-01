// from server: 100% by king_originala
struct S {
    unsigned int words[77];
    int* table;

    void reset();
    void finish();
};

void S::reset()
{
    int* t = table;
    words[0]  = 0x00832ac4;
    words[4]  = 0x00832ab8;
    words[5]  = 0x00832ab0;
    words[8]  = 0x00832aa8;
    words[9]  = 0x00832a98;
    words[17] = 0x00832a88;
    words[25] = 0x00832a78;
    words[33] = 0x00832a68;
    words[41] = 0x00832a58;
    words[49] = 0x00832a48;
    words[76] = 0x00832a3c;

    *(unsigned int*)((char*)this + 0x134 + t[1]) = 0x00832a30;
    *(unsigned int*)((char*)this + 0x134 + table[2]) = 0x00832a28;
    finish();
}
