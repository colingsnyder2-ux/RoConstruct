// from server: 55% by atomic.potato
struct Inner {
    char pad[4];
    void method(int);
};

struct S {
    char pad0[4];
    Inner inner;
    void* method2(int, int);
};

extern "C" void __stdcall sub_4c1670(Inner*, int);
extern "C" void __stdcall sub_4d7cb0(S*, int, int);

void Inner::method(int)
{
    sub_4c1670(this, 1);
}

void* S::method2(int a, int b)
{
    inner.method(0);
    sub_4d7cb0(this, a, b);
    return (void*)a;
}
