// from server: 100% by king_originala
struct S {
    unsigned char data[0x304];
    void base(int);
    S* initialize(int);
};

S* S::initialize(int complete)
{
    volatile int state = 0;

    if (complete) {
        *(unsigned long*)(data + 0x134) = 0x831e28;
        *(unsigned long*)(data + 0x300) = 0x846144;
    }

    base(0);

    int* table = *(int**)(data + 0x134);

    *(unsigned long*)(data + 0x000) = 0x8337d4;
    *(unsigned long*)(data + 0x010) = 0x8337c4;
    *(unsigned long*)(data + 0x014) = 0x8337bc;
    *(unsigned long*)(data + 0x020) = 0x8337b4;
    *(unsigned long*)(data + 0x024) = 0x8337a4;
    *(unsigned long*)(data + 0x044) = 0x833794;
    *(unsigned long*)(data + 0x064) = 0x833784;
    *(unsigned long*)(data + 0x084) = 0x833774;
    *(unsigned long*)(data + 0x0a4) = 0x833764;
    *(unsigned long*)(data + 0x0c4) = 0x833754;
    *(unsigned long*)(data + 0x130) = 0x833748;
    *(unsigned long*)(data + 0x1a0) = 0x833730;
    *(unsigned long*)(data + 0x288) = 0x833718;

    *(unsigned long*)(data + 0x134 + table[1]) = 0x83370c;

    table = *(int**)(data + 0x134);
    *(unsigned long*)(data + 0x134 + table[2]) = 0x833704;

    table = *(int**)(data + 0x134);
    *(unsigned long*)(data + 0x134 + table[3]) = 0x8336e8;

    table = *(int**)(data + 0x134);
    int offset = table[1];
    *(int*)(data + 0x130 + offset) = offset - 0x1b8;

    table = *(int**)(data + 0x134);
    offset = table[2];
    *(int*)(data + 0x130 + offset) = offset - 0x1c0;

    table = *(int**)(data + 0x134);
    offset = table[3];
    *(int*)(data + 0x130 + offset) = offset - 0x1c8;

    return this;
}
