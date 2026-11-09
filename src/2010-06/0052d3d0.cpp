// from server: 72% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct S_func_0052d3d0 {
    void f(int a1, int a2, int a3, int a4, int a5, int a6);
};

void S_func_0052d3d0::f(int a1, int a2, int a3, int a4, int a5, int a6)
{
    int* p = (int*)a6;
    if (p != 0) {
        if (_InterlockedExchangeAdd((volatile long*)((char*)p + 4), -1) == 1) {
            (*(void (__thiscall**)(int*))(*(int*)p + 4))(p);
        }
        if (_InterlockedExchangeAdd((volatile long*)((char*)p + 8), -1) == 1) {
            (*(void (__thiscall**)(int*))(*(int*)p + 8))(p);
        }
    }
}
