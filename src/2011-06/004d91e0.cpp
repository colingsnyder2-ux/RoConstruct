// from server: 53% by atomic.potato
struct Inner {
    char pad[4];
    void method(int);
};

struct S {
    Inner inner;
    int f(int, int);
};

extern "C" void __stdcall sub_4c1670(Inner*, int);

void Inner::method(int)
{
    sub_4c1670(this, 0);
}

extern "C" void __stdcall sub_4d7be0(S*, int, int);

int S::f(int a, int b)
{
    inner.method(1);
    sub_4d7be0(this, a, b);
    return a;
}
