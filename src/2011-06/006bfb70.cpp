// from server: 21% by atomic.potato
struct Inner {
    char pad[4];
    void init(int);
};

struct S {
    Inner inner;
    void* f(void*, int);
};

void Inner::init(int) {}

void* S::f(void* a, int b) {
    inner.init(1);
    return a;
}
