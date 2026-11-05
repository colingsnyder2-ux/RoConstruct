// from server: 32% by atomic.potato
extern "C" void __cdecl func_00982114(int);
extern "C" void __cdecl func_00972290(int, int);
extern "C" void* __cdecl func_007d4fa0(int, int, int, int, int);
extern "C" void* __cdecl func_00782f30(int, int);
extern "C" void __cdecl func_0040cf10();

struct S {
    void f(int, int, int, int, int, int, int, int, int, int);
};

void S::f(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10)
{
    void* p = func_007d4fa0(a1, a2, a3, a4, a5);
    int v = *(int*)p;
    *(int*)p = 0;
    void* q = func_00782f30(a6, a7);
    func_0040cf10();
    func_00982114(a8);
    *(int*)this = 0xbc0da0;
    if (*(char*)0xe580b3 != 0) {
        if (!((bool(__thiscall*)(int))0xb229ec)(0xdc0878)) {
            if (*(int*)0xe5809c != 0) {
                if (((bool(__cdecl*)(int, int, int))*(int*)0xe5809c)(0xae, 0xb58618, 0xb44978))
                    return;
            }
            func_00972290(*(unsigned char*)0xe580b3, 0xb58680);
        }
    }
}
