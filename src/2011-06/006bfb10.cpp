// from server: 57% by atomic.potato
struct Inner {
    char pad[4];
    void method(int, int);
};

struct S {
    Inner inner;
    int f(int, int);
};

extern "C" void __stdcall sub_4c1670(void*, int);

int S::f(int a, int b)
{
    sub_4c1670(&inner, 1);
    inner.method(a, b);
    return a;
}
