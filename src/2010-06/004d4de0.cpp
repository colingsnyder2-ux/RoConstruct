// from server: 14% by atomic.potato
struct S {
    int f(int, int);
};

int S::f(int a, int b) {
    if (!a) {
        goto L1;
    }
    int c = *(int*)(a + 0x38);
    a -= 0x1c;
    int d = b;
    c += a;
    goto L0;
L1:
    int e = *(int*)(a + 0x38);
    a = 0;
    int f = b;
    e += a;
L0:
    return 0;
}
