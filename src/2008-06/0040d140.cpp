// from server: 100% by king_originala
struct S {
    unsigned char storage[0x132];
    void initialize();
    S();
};

S::S()
{
    initialize();
    *(unsigned int*)(storage + 0x00) = 0x0080bbd4;
    *(unsigned int*)(storage + 0x10) = 0x0080bbc8;
    *(unsigned int*)(storage + 0x14) = 0x0080bbc0;
    *(unsigned int*)(storage + 0x20) = 0x0080bbb8;
    *(unsigned int*)(storage + 0x24) = 0x0080bba8;
    *(unsigned int*)(storage + 0x44) = 0x0080bb98;
    *(unsigned int*)(storage + 0x64) = 0x0080bb88;
    *(unsigned int*)(storage + 0x84) = 0x0080bb78;
    *(unsigned int*)(storage + 0xa4) = 0x0080bb68;
    *(unsigned int*)(storage + 0xc4) = 0x0080bb58;
    storage[0x130] = 0;
    storage[0x131] = 1;
}
