// from server: 100% by king_originala
struct S
{
    unsigned int words[78];
    void base_init(int value, int flag);
    S* func_00599020(int value, int flag);
};

S* S::func_00599020(int value, int flag)
{
    if (flag)
        words[77] = 0x00830fac;

    base_init(value, 0);

    int* table = reinterpret_cast<int*>(words[77]);
    words[0] = 0x00832ac4;
    words[4] = 0x00832ab8;
    words[5] = 0x00832ab0;
    words[8] = 0x00832aa8;
    words[9] = 0x00832a98;
    words[17] = 0x00832a88;
    words[25] = 0x00832a78;
    words[33] = 0x00832a68;
    words[41] = 0x00832a58;
    words[49] = 0x00832a48;
    words[76] = 0x00832a3c;

    *reinterpret_cast<unsigned int*>(
        reinterpret_cast<char*>(this) + 0x134 + table[1]) = 0x00832a30;

    table = reinterpret_cast<int*>(words[77]);
    *reinterpret_cast<unsigned int*>(
        reinterpret_cast<char*>(this) + 0x134 + table[2]) = 0x00832a28;

    return this;
}
