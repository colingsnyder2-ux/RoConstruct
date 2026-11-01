// from server: 100% by king_originala
struct Inner {
    char storage[0x7e0];
    Inner();
};

struct S {
    virtual void f();
    int a, b, c, d, e;
    Inner inner;
    int last;
    S();
};

S::S() : a(0), b(0), c(0), d(0), e(0), last(-1) {
}
