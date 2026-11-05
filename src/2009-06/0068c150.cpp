// from server: 48% by why2
struct S {
    void f(int, int);
};

void S::f(int a, int b) {
    int* p = (int*)a;
    void (*fn)(int) = (void (*)(int))p[0];
    int ctx = p[1] + p[2];
    fn(b);
}
