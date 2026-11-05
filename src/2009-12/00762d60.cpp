// from server: 40% by atomic.potato
extern "C" void* __cdecl func_007f3860(unsigned int);
extern "C" void __fastcall func_00762080(void*, void*, void*);
extern "C" void __fastcall func_00762650(void*, void*);

struct S {
    void f(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12, int a13, int a14, int a15, int a16, int a17, int a18, int a19, int a20, int a21, int a22, int a23, int a24, void** out);
};

void S::f(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12, int a13, int a14, int a15, int a16, int a17, int a18, int a19, int a20, int a21, int a22, int a23, int a24, void** out)
{
    void* p = func_007f3860(0x58);
    if (p != 0) {
        *(int*)p = a1;
        func_00762080((char*)p + 8, &a2, 0);
    } else {
        p = 0;
    }
    *out = p;
    func_00762650(&a2, 0);
}
