// from server: 100% by king_originala
struct S {
    int words[116];
    void reset();
    void finish();
};

void S::reset()
{
    int* table = *(int**)&words[77];

    words[0]   = 0x84601c;
    words[4]   = 0x846010;
    words[5]   = 0x846008;
    words[8]   = 0x846000;
    words[9]   = 0x845ff0;
    words[17]  = 0x845fe0;
    words[25]  = 0x845fd0;
    words[33]  = 0x845fc0;
    words[41]  = 0x845fb0;
    words[49]  = 0x845fa0;
    words[76]  = 0x845f94;
    words[104] = 0x845f84;
    words[112] = 0x845f78;
    words[115] = 0x845f60;

    *(int*)((char*)this + 0x134 + table[1]) = 0x845f54;
    table = *(int**)&words[77];
    *(int*)((char*)this + 0x134 + table[2]) = 0x845f4c;
    table = *(int**)&words[77];
    *(int*)((char*)this + 0x134 + table[3]) = 0x845f30;

    table = *(int**)&words[77];
    int offset = table[1];
    *(int*)((char*)this + 0x130 + offset) = offset - 0x2b8;

    table = *(int**)&words[77];
    offset = table[2];
    *(int*)((char*)this + 0x130 + offset) = offset - 0x2c0;

    table = *(int**)&words[77];
    offset = table[3];
    *(int*)((char*)this + 0x130 + offset) = offset - 0x2c8;

    finish();
}
