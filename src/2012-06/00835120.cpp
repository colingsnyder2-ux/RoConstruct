// from server: 39% by Intel
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct LuaArguments {
    int vptr;
    int refCount;

    LuaArguments* __thiscall ctor_00835120(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8);
};

void __stdcall func_00834aa0(LuaArguments* thisptr);
void __stdcall func_006a2870(int* ptr);
void __stdcall func_00b22644(int* dest, int* src);
void __stdcall func_00b2263c(int* ptr);

LuaArguments* __thiscall LuaArguments::ctor_00835120(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8) {
    LuaArguments* esi = this;
    int* stackArg = &a8;
    *stackArg = a8;
    int* eax = stackArg;
    int local_18 = 1;
    int* local_c = eax;
    if (eax) {
        eax += 1;
        _InterlockedExchangeAdd((volatile long*)eax, 1);
    }
    func_00834aa0(esi);
    int* src = &a8;
    int* dest = (int*)((char*)esi + 4);
    char local_14 = 2;
    func_00b22644(dest, src);
    int* ptr = (int*)a4;
    local_14 = 0;
    if (ptr) {
        ptr += 1;
        func_006a2870(ptr);
    }
    int* cleanup = &a8;
    local_14 = -1;
    func_00b2263c(cleanup);
    return esi;
}
