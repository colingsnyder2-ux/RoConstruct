// from server: 37% by atomic.potato
struct S {
    int f(int, int);
};

int S::f(int a1, int a2) {
    int v1 = a1;
    if (!v1) {
        int v2 = a2;
        int v3 = *(int*)(v1 + 0x24);
        v1 = 0;
        int v4 = v2;
        v3 += v1;
        goto loc_4db059;
    }
    int v5 = a2;
    int v6 = *(int*)(v1 + 0x24);
    v1 += -0x1c;
    int v7 = v5;
    v6 += v1;
    loc_4db045:
    int (*func)(int, int) = (int (*)(int, int))0x4d8fd0;
    func(v7, v6);
    return 8;
loc_4db059:
    int (*func2)(int, int) = (int (*)(int, int))0x4d8fd0;
    func2(a2, *(int*)(a1 + 0x24));
    return 8;
}
