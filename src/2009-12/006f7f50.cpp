// from server: 35% by atomic.potato
extern "C" void* __cdecl func_006f4f70(int, int, int, int, int, int, int, int);
extern "C" void* __cdecl func_00650bf0(int, int);
extern "C" void __cdecl func_00409630(void*, void*);
extern "C" void __cdecl func_007f385a(void*);

struct S {
    void f(int, int, int, int, int, int, int, int);
};

void S::f(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8)
{
    void* p = func_006f4f70(a1, a2, a3, a4, a5, a6, a7, a8);
    void* q = func_00650bf0(a1, a2);
    func_00409630(this, q);
    func_007f385a(p);
    *(void**)this = (void*)0x9dc9ec;
}
