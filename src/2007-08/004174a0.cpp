// from server: 39% by colin
extern "C" int __cdecl func_0062fef6(int);
extern "C" void __cdecl func_00415980(int, int, int);
extern "C" void __cdecl func_004923a0(int);
extern "C" bool __cdecl func_004879d0(int);

struct S {
    int f(int, int, int, int, int, int, int, int, int, int, int, int, int);
};

int S::f(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8, int a9, int a10, int a11, int a12, int a13)
{
    int local = 0;
    if (!func_004879d0((int)&local)) {
        *(int*)((char*)this + 8) = 0x416b40;
        *(int*)this = 0x416b70;
        int p = func_0062fef6(0x30);
        func_00415980(p, (int)&local, 0);
        *(int*)((char*)this + 4) = p;
    }
    func_004923a0((int)&local);
    return 0;
}
