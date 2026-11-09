// from server: 100% by why2
struct S {
    int f();
};

int S::f() {
    extern int g_0xa42ccc;
    if (g_0xa42ccc == 0) {
        g_0xa42ccc = *(int*)this;
    }
    return g_0xa42ccc;
}
