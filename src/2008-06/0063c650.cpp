// from server: 100% by king_originala
struct S {
    unsigned char data[0x404];
    void base_0059d4d0(int);
    S* func_0063c650(int);
};

S* S::func_0063c650(int initialize)
{
    volatile int state = 0;

    if (initialize) {
        *(int*)(data + 0x134) = 0x849e6c;
        *(int*)(data + 0x400) = 0x846144;
    }

    base_0059d4d0(0);

    int* table = *(int**)(data + 0x134);
    *(int*)(data + 0x000) = 0x849c8c;
    *(int*)(data + 0x010) = 0x849c7c;
    *(int*)(data + 0x014) = 0x849c74;
    *(int*)(data + 0x020) = 0x849c6c;
    *(int*)(data + 0x024) = 0x849c5c;
    *(int*)(data + 0x044) = 0x849c4c;
    *(int*)(data + 0x064) = 0x849c3c;
    *(int*)(data + 0x084) = 0x849c2c;
    *(int*)(data + 0x0a4) = 0x849c1c;
    *(int*)(data + 0x0c4) = 0x849c0c;
    *(int*)(data + 0x130) = 0x849c00;
    *(int*)(data + 0x1a0) = 0x849bf0;
    *(int*)(data + 0x1c0) = 0x849be4;
    *(int*)(data + 0x1cc) = 0x849bcc;

    *(int*)(data + table[1] + 0x134) = 0x849bc0;
    *(int*)(data + (*(int**)(data + 0x134))[2] + 0x134) = 0x849bb8;
    *(int*)(data + (*(int**)(data + 0x134))[3] + 0x134) = 0x849b9c;

    int offset = (*(int**)(data + 0x134))[1];
    *(int*)(data + offset + 0x130) = offset - 0x2b8;
    offset = (*(int**)(data + 0x134))[2];
    *(int*)(data + offset + 0x130) = offset - 0x2c0;
    offset = (*(int**)(data + 0x134))[3];
    *(int*)(data + offset + 0x130) = offset - 0x2c8;

    return this;
}
