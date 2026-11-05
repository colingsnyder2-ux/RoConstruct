// from server: 52% by atomic.potato
extern "C" void* __cdecl func_007f3860(unsigned int);
extern "C" void __cdecl func_007f385a(void*);

struct S {
    void* __cdecl f(void* a, void* b, void* c);
};

void* S::f(void* a, void* b, void* c)
{
    void* p = func_007f3860(0x10);
    if (p) {
        *(void**)p = (void*)0x9e5554;
        *(void**)((char*)p + 4) = a;
        *(void**)((char*)p + 8) = b;
        *(void**)((char*)p + 12) = c;
    } else {
        p = 0;
    }
    *(void**)this = p;
    func_007f385a(0);
    return this;
}
