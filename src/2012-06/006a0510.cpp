// from server: 41% by atomic.potato
extern "C" void* __cdecl func_004287b0(int);
extern "C" void __cdecl func_00428700(void*);
extern "C" void __cdecl func_0069e580(void*, void*, void*);
extern "C" void __cdecl func_0069fe30(void*, void*);

struct S {
    void f(void* a, void* b);
};

void S::f(void* a, void* b)
{
    void* p = func_004287b0(0x38);
    if (p) {
        func_0069e580(p, a, this);
        *(int*)p = 0xb93fbc;
        *(int*)((char*)p + 8) = 0xb93fb4;
    } else {
        p = 0;
    }
    func_0069fe30(this, p);
    *(void**)b = p;
    if (p) {
        func_00428700((char*)p + 5);
    }
}
