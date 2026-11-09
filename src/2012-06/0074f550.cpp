// from server: 26% by tester
struct S_func_0074f550 {
    char pad[8];
    bool f(int, int, int, int, int, int, int, int, int);
};

extern "C" {
    void __stdcall EnterCriticalSection(void*);
    void __stdcall LeaveCriticalSection(void*);
    void __stdcall sub_972df0();
    void __stdcall sub_972af0();
    void __stdcall sub_74e630();
    void __stdcall sub_b2263c();
    void __stdcall sub_b221b8();
    void __stdcall sub_b221b4();
}

extern void* dword_e357b0;
extern void* dword_e357b4;
extern float flt_b5abb8;
extern char str_bab9f4[];

bool S_func_0074f550::f(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9)
{
    bool result = false;
    if (dword_e357b0 != 0) {
        void* esi = dword_e357b4;
        EnterCriticalSection(&dword_e357b4);
        sub_972df0();
        sub_972af0();
        sub_b2263c();
        LeaveCriticalSection(&dword_e357b4);
    }
    sub_74e630();
    return result;
}
