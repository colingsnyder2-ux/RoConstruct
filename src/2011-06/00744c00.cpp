// from server: 39% by atomic.potato
struct S {
    int f(int, int);
};

int S::f(int a1, int a2) {
    if (!a1) {
        goto label1;
    }
    int v2 = a2;
    int v3 = *(int*)(a1 + 0x24);
    a1 -= 0x1c;
    label1:
    int v4 = a2;
    int v5 = *(int*)(a1 + 0x24);
    a1 = 0;
    return (int)(*(int (*)(int, int))(0x7443c0))(v5, v4);
}
