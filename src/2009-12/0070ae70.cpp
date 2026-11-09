// from server: 32% by atomic.potato
struct Inner {
    void f(int);
};

struct S {
    char pad[0x34];
    Inner* p;
    void f(int, int);
};

void S::f(int a, int b) {
    if (a) {
        p->f(b);
    } else {
        p->f(b);
    }
}
