// from server: 25% by atomic.potato
extern "C" void* __cdecl func_0098211a(unsigned int);
extern "C" void __cdecl func_0068ad50(void*);
extern "C" void __cdecl func_00402f40(void*, void*, void*);

struct S {
    void __cdecl f(void* a);
};

void S::f(void* a)
{
    void* p = func_0098211a(0x180);
    void* q = 0;
    if (p) {
        func_0068ad50(p);
        q = p;
    }
    func_00402f40(this, q, a);
}
