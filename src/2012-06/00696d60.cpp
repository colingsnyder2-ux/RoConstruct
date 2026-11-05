// from server: 66% by atomic.potato
extern "C" void __stdcall func_004015a0(int, int);
extern "C" void __cdecl func_00695720();

struct S {
};

bool __cdecl f(void* a)
{
    func_004015a0(0x695780, 0xe2c880);
    func_00695720();
    int* p = (int*)a;
    int v;
    bool ok = ((bool (__thiscall*)(void*, int, int*, int))((*(int**)p)[0x2c/4]))(p, 1, &v, 0);
    if (!ok)
        return false;
    *(int*)a = v;
    return true;
}
