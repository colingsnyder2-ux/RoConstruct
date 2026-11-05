// from server: 57% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct S
{
    void f(void*);
    void* vptr;
    int pad[4];
    void* value;
};

void S::f(void* out)
{
    *(void**)out = *(void**)((char*)this + 0x14);
    void* p = *(void**)((char*)this + 0x18);
    *(void**)((char*)out + 4) = p;
    if (p)
        _InterlockedExchangeAdd((volatile long*)((char*)p + 4), 1);
}
