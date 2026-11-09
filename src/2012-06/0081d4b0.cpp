// from server: 65% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct S {
    void __cdecl f(void* out, void* src);
};

void S::f(void* out, void* src)
{
    int* p = (int*)src;
    int* o = (int*)out;
    int v = *p;
    int r;
    if (v != 0)
        r = v - 0x1c;
    else
        r = 0;
    o[0] = r;
    int c = p[1];
    o[1] = c;
    if (c != 0)
        _InterlockedExchangeAdd((volatile long*)(c + 4), 1);
}
