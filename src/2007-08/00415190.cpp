// from server: 100% by colin
struct S {
    int f(int, const int* a);
};

int S::f(int, const int* a) {
    extern int g0;
    extern int g1;
    extern int g2;
    extern int g3;
    int r;
    if (a[0] == g0 && a[1] == g1 && a[2] == g2 && a[3] == g3)
        r = 1;
    else
        r = 0;
    return !r;
}
