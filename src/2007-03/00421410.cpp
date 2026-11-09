// from server: 100% by tester
struct InnerVtbl {
    char pad[0x18];
    void (__stdcall *fn)(void*);
};

struct Inner {
    InnerVtbl* vtbl;
};

struct Outer {
    char pad0[0x30];
    Inner* m_inner;
};

void __stdcall func(Outer* p, int* out)
{
    p->m_inner->vtbl->fn(p);
    *out = 0;
}