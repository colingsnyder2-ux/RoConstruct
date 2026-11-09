// from server: 17% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" void __stdcall sub_b22644(void*);
extern "C" void __stdcall sub_b2263c(void*);

struct Str
{
    void* pad0;
    void* pad4;
    void ctor(const Str&);
    void dtor();
};

struct S
{
    void* f0;
    void* f4;
    Str f8;
    void func(void*, void*, const Str&);
};

void S::func(void* a1, void* a2, const Str& a3)
{
    if (a2)
    {
        _InterlockedExchangeAdd((volatile long*)((char*)a2 + 8), 1);
    }
    f0 = a1;
    f4 = a2;
    if (a2)
    {
        if (_InterlockedExchangeAdd((volatile long*)((char*)a2 + 8), -1) == 1)
        {
            (*(void(**)(void*))((*(void***)a2)[2]))(a2);
        }
    }
    f8.ctor(a3);
    sub_b22644(&f8);
    if (a2)
    {
        if (_InterlockedExchangeAdd((volatile long*)((char*)a2 + 8), -1) == 1)
        {
            (*(void(**)(void*))((*(void***)a2)[2]))(a2);
        }
    }
    f8.dtor();
}
