// from server: 40% by atomic.potato
extern "C" void __stdcall G1_func_007f385a(void*);
extern "C" void* __stdcall G1_func_0062ca90(void*, void*, void*, void*, void*, void*, void*);
extern "C" void* __stdcall G1_func_0062f2d0(void*, void*);
extern "C" void __stdcall G1_func_00442310(void*, void*);

struct S {
    void* f(void*, void*, void*, void*, void*, void*, void*);
};

void* S::f(void* a1, void* a2, void* a3, void* a4, void* a5, void* a6, void* a7)
{
    void* p = G1_func_0062ca90(a1, a2, a3, a4, a5, a6, a7);
    void* v = *(void**)p;
    *(void**)p = 0;
    void* r = G1_func_0062f2d0(a4, a5);
    G1_func_00442310(this, r);
    G1_func_007f385a(a6);
    *(void**)this = (void*)0x9cb25c;
    return this;
}
