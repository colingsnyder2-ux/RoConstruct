// from server: 57% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" void* __cdecl sub_504D40(void*);

struct S {
    void __cdecl f(void*);
};

void S::f(void* a)
{
    void* p = sub_504D40(a);
    void* r = *(void**)p;
    *(void**)a = r;
    long v = *((long*)p + 1);
    *((long*)a + 1) = v;
    if (v != 0) {
        _InterlockedExchangeAdd((volatile long*)((char*)p + 8), 1);
    }
}
