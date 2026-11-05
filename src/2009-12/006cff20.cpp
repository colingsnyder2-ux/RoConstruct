// from server: 30% by atomic.potato
struct S_func_006cff20 {
    void* f(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10);
};

extern "C" void* __stdcall sub_006ccf50(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10);
extern "C" void* __stdcall sub_0064ed50(int a1, int a2);
extern "C" void __stdcall sub_00409630(void* a1, void* a2);
extern "C" void __stdcall sub_007f385a(void* a1);

void* S_func_006cff20::f(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10)
{
    void* v = sub_006ccf50(a1, a2, a3, a4, a5, a6, a7, a8, a9, a10);
    void* r = sub_0064ed50(a1, a2);
    sub_00409630(this, r);
    sub_007f385a(v);
    *(void**)this = (void*)0x9d7c30;
    return this;
}
