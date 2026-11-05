// from server: 0% by atomic.potato
extern "C" void __stdcall func_007f90e0(int, const char*, const char*, int, int, int, int);
extern "C" void __stdcall func_0040ddc0(void*);
extern "C" void __stdcall func_007736f0(void*);
extern "C" void __stdcall func_006d7db0(void*);
extern "C" void __stdcall func_006d92c0();

struct S {
    char pad[0x14];
    int f(int, int, int, int, int, int, int, int, int, int);
};

int S::f(int, int, int, int, int, int, int, int, int, int)
{
    return 0;
}
