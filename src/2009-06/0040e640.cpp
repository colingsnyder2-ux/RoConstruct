// from server: 100% by why2
struct S {
    int f(int* p);
};

int S::f(int* p) {
    p[4] = p[2];
    return 0;
}
