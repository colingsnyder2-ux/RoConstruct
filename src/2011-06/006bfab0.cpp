// from server: 55% by atomic.potato
struct Inner {
    char pad[4];
    void init(int);
};

struct S {
    Inner inner;
    int method(int, int);
};

extern "C" void __stdcall sub_4c1670(Inner*, int);

void Inner::init(int) {
    sub_4c1670(this, 1);
}

extern "C" int __stdcall sub_6be130(S*, int, int);

int S::method(int a, int b) {
    inner.init(0);
    sub_6be130(this, a, b);
    return a;
}
