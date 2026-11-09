// from server: 42% by atomic.potato
struct S {
    int f(int, int);
};

int S::f(int a, int b) {
    if (!a) {
        goto L1;
    }
    int c = *(int*)(a + 0x24);
    a -= 0x1c;
    int d = b;
    c += a;
    ((void(__stdcall*)(int, int))0x7445f0)(c, d);
    return 8;
L1:
    int e = *(int*)(a + 0x24);
    a = 0;
    int f = b;
    e += a;
    ((void(__stdcall*)(int, int))0x7445f0)(e, f);
    return 8;
}
