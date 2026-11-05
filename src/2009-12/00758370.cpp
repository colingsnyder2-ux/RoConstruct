// from server: 62% by atomic.potato
extern "C" void* __cdecl func_007f3860(unsigned int);
extern "C" void __cdecl func_007f385a(void*);

struct S {
    void* f(void** out, void* a, void* b, void* c);
};

void* S::f(void** out, void* a, void* b, void* c)
{
    void* p = func_007f3860(0x10);
    if (p) {
        *(void**)p = (void*)0x9e57e4;
        *(void**)((char*)p + 4) = a;
        *(void**)((char*)p + 8) = b;
        *(void**)((char*)p + 12) = c;
    } else {
        p = 0;
    }
    *out = p;
    func_007f385a(0);
    return out;
}
