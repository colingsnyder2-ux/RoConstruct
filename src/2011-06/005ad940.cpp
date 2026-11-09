// from server: 55% by atomic.potato
struct Sub {
    void init(int);
};

struct S {
    char pad0[4];
    Sub sub;
    int f(int, int);
};

extern "C" void __stdcall sub_init(Sub*, int);
extern "C" int __stdcall sub_call(S*, int, int);

int S::f(int a, int b) {
    sub_init(&sub, 1);
    sub_call(this, a, b);
    return a;
}
