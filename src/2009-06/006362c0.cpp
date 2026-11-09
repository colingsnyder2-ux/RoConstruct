// from server: 43% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" void* __cdecl sub_006babb0(void*, int, void*);

struct T4_006362c0 {
    void __cdecl f_006362c0(void*);
};

void T4_006362c0::f_006362c0(void* a)
{
    void* p = sub_006babb0(*(void**)0xa22b18, 1, a);
    void* q = *(void**)((char*)p + 8);
    if (q) {
        if (_InterlockedExchangeAdd((volatile long*)((char*)q + 8), -1) == 1) {
            void** vt = *(void***)q;
            ((void (__thiscall*)(void*))vt[2])(q);
        }
    }
}
