// from server: 47% by atomic.potato
struct S {
    int f(int, int);
};

extern "C" int __stdcall call_6d9840(int, int);

int S::f(int a, int b) {
    if (!a) {
        goto L1;
    }
    int c = *(int*)(a + 36);
    a -= 28;
    int d = b;
    c += a;
    call_6d9840(d, c);
    return 0;
L1:
    int e = b;
    int f = *(int*)(a + 36);
    a = 0;
    f += a;
    call_6d9840(e, f);
    return 0;
}
