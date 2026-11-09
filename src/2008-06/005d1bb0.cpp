// from server: 100% by king_originala
struct S {
    void f();
    void cleanup();
};

void S::f() {
    char *p = (char *)this;
    int *table = *(int **)(p + 0x134);

    *(int *)(p + 0x000) = 0x83bb3c;
    *(int *)(p + 0x010) = 0x83bb2c;
    *(int *)(p + 0x014) = 0x83bb24;
    *(int *)(p + 0x020) = 0x83bb1c;
    *(int *)(p + 0x024) = 0x83bb0c;
    *(int *)(p + 0x044) = 0x83bafc;
    *(int *)(p + 0x064) = 0x83baec;
    *(int *)(p + 0x084) = 0x83badc;
    *(int *)(p + 0x0a4) = 0x83bacc;
    *(int *)(p + 0x0c4) = 0x83babc;
    *(int *)(p + 0x130) = 0x83bab0;
    *(int *)(p + 0x1a0) = 0x83baa0;
    *(int *)(p + 0x1c0) = 0x83ba94;
    *(int *)(p + 0x1cc) = 0x83ba7c;

    *(int *)(p + table[1] + 0x134) = 0x83ba70;
    table = *(int **)(p + 0x134);
    *(int *)(p + table[2] + 0x134) = 0x83ba68;
    table = *(int **)(p + 0x134);
    *(int *)(p + table[3] + 0x134) = 0x83ba4c;

    table = *(int **)(p + 0x134);
    int offset = table[1];
    *(int *)(p + offset + 0x130) = offset - 0x2b8;
    table = *(int **)(p + 0x134);
    offset = table[2];
    *(int *)(p + offset + 0x130) = offset - 0x2c0;
    table = *(int **)(p + 0x134);
    offset = table[3];
    *(int *)(p + offset + 0x130) = offset - 0x2c8;

    cleanup();
}
