// from server: 100% by colin
// roc 2007-08 00552c70  size: 59 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00552c70

extern "C" void __cdecl sub_54c5c0();
extern "C" void __cdecl sub_62fc62(void*);

extern void* g_77e4dc;
extern void* g_77e4e0;
extern void (__cdecl *g_77e4e4)(void*);

struct S {
    S* f(int);
};

S* S::f(int a) {
    sub_54c5c0();
    void** p = (void**)((char*)this + 0x14);
    *p = g_77e4dc;
    *p = g_77e4e0;
    g_77e4e4(p);
    if (a & 1) {
        sub_62fc62(this);
    }
    return this;
}
