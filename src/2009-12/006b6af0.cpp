// from server: 37% by atomic.potato
extern "C" void __cdecl func_007f385a(void*);
extern "C" void* __cdecl func_006b4a40(int, int, int, int, int, int, int, int);
extern "C" void* __cdecl func_006b67e0(int, int);

struct T {
    void __thiscall method(void*);
};

extern "C" void __cdecl func_00442310(void*, void*);

struct S {
    void f(int, int, int, int, int, int, int, int);
};

void S::f(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8)
{
    void* p = func_006b4a40(a1, a2, a3, a4, a5, a6, a7, a8);
    int v = *(int*)p;
    *(int*)p = 0;
    void* q = func_006b67e0(a1, a2);
    func_00442310(this, q);
    func_007f385a((void*)a8);
    *(int*)this = 0x9d5f6c;
}
