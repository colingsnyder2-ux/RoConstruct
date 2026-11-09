// from server: 21% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct T4_006ffb80 {
    void f_006ffac0(int, int, int, int, int, int);
    void f_006ffb80(int, int, int, int, int, int);
};

void T4_006ffb80::f_006ffb80(int a1, int a2, int a3, int a4, int a5, int a6)
{
    int* p = (int*)a5;
    int* q = (int*)a6;
    int local[2];
    local[0] = a3;
    local[1] = a4;
    int* ref = 0;
    if (q)
    {
        _InterlockedExchangeAdd((volatile long*)((char*)q + 4), 1);
        ref = q;
    }
    f_006ffac0(a1, a2, local[0], local[1], a5, a6);
    if (ref)
    {
        if (_InterlockedExchangeAdd((volatile long*)((char*)ref + 4), -1) == 1)
        {
            (*(void(**)(void*))(*ref))(ref);
            if (_InterlockedExchangeAdd((volatile long*)((char*)ref + 8), -1) == 1)
                (*(void(**)(void*))(*(int*)ref + 8))(ref);
        }
    }
}
