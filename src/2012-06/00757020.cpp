// from server: 75% by colin
extern "C" int __cdecl func_004015a0(int, int);
extern "C" int __cdecl func_00756fb0();

struct S {
};

bool __cdecl f(void* a)
{
    func_004015a0(0xe364f8, 0x757010);
    int r = func_00756fb0();
    int* p = (int*)a;
    int v = *p;
    int out;
    bool ok = ((bool (__thiscall*)(void*, int, int, int*))*(int*)(v + 0x2c))(p, 1, r, &out);
    if (!ok)
        return false;
    *p = out;
    return true;
}
