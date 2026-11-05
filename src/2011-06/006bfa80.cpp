// from server: 55% by atomic.potato
struct Inner {
    void init(int);
};

struct S {
    char pad0[4];
    Inner inner;
    int f(int, int);
};

extern "C" void __stdcall sub_4c1670(Inner*, int);
extern "C" void __stdcall sub_6be060(S*, int, int);

void Inner::init(int) {}

int S::f(int a, int b) {
    sub_4c1670(&inner, 1);
    sub_6be060(this, a, b);
    return a;
}
