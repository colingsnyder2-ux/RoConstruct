// from server: 41% by atomic.potato
extern "C" void __stdcall G1_func_00a404d0();
extern "C" void __stdcall G1_func_0063b8f0(void*);

struct Inner {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3(void*, void*);
};

struct S {
    char pad[0x1c];
    Inner* p;
    void f(void*, void*);
};

void S::f(void* a, void* b)
{
    Inner* esi = p;
    char buf[0x20];
    G1_func_0063b8f0(buf);
    esi->v3(a, b);
    G1_func_00a404d0();
}
