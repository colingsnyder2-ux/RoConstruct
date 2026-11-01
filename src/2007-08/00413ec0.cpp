// from server: 80% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct S {
    void* p0;
    void* p4;
    int p8;
    int pC;
    S* assign(void* a, void* b, int c, int d);
};

S* S::assign(void* a, void* b, int c, int d)
{
    p0 = a;
    p4 = b;
    if (b != 0) {
        _InterlockedExchangeAdd((volatile long*)((char*)b + 4), 1);
    }
    p8 = c;
    pC = d;
    if (b != 0) {
        if (_InterlockedExchangeAdd((volatile long*)((char*)b + 4), -1) == 1) {
            void** vt = *(void***)b;
            ((void (__thiscall*)(void*))vt[1])(b);
            if (_InterlockedExchangeAdd((volatile long*)((char*)b + 8), -1) == 1) {
                void** vt2 = *(void***)b;
                ((void (__thiscall*)(void*))vt2[2])(b);
            }
        }
    }
    return this;
}
