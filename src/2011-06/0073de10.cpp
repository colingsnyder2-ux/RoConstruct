// from server: 47% by atomic.potato
struct S {
    int f(int, int);
};
int S::f(int a, int b) {
    if (!a) {
        int c = b;
        int d = *(int*)(*(int*)(c + 0x24));
        return 0;
    }
    int e = a - 0x1c;
    int f = b;
    int g = *(int*)(*(int*)(f + 0x24));
    return e + g;
}
