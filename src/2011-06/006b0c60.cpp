// from server: 43% by atomic.potato
struct Inner {
    char pad[4];
    void init(int);
};

struct S {
    char pad0[4];
    Inner inner;
    S* method(int, int);
};

extern "C" void __stdcall sub_004c1670(Inner*, int);
extern "C" S* __stdcall sub_006b0100(S*, int, int);

S* S::method(int a, int b)
{
    inner.init(0);
    sub_004c1670(&inner, 1);
    return sub_006b0100(this, a, b);
}
