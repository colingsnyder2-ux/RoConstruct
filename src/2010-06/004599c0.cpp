// from server: 55% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" int __stdcall _type_info_equals(const void*, const void*);

struct RefCounted
{
    void* vptr;
    volatile long ref1;
    volatile long ref2;
};

struct Holder
{
    void* p0;
    void* p1;
    RefCounted* p2;
};

struct S
{
};

void __cdecl func(int op, Holder* dst, Holder* src)
{
    if (op == 0 || op == 1)
    {
        if (dst)
        {
            dst->p0 = src->p0;
            dst->p1 = src->p1;
            dst->p2 = src->p2;
            if (dst->p2)
            {
                _InterlockedExchangeAdd(&dst->p2->ref1, 1);
            }
        }
        if (op == 1)
        {
            RefCounted* r = src->p2;
            if (r)
            {
                if (_InterlockedExchangeAdd(&r->ref1, -1) == 1)
                {
                    typedef void (__stdcall *Fn)(RefCounted*);
                    Fn f = *(Fn*)(*(char**)r + 4);
                    f(r);
                    if (_InterlockedExchangeAdd(&r->ref2, -1) == 1)
                    {
                        Fn g = *(Fn*)(*(char**)r + 8);
                        g(r);
                    }
                }
            }
        }
        return;
    }
    if (op == 2)
    {
        RefCounted* r = dst->p2;
        if (r)
        {
            if (_InterlockedExchangeAdd(&r->ref1, -1) == 1)
            {
                typedef void (__stdcall *Fn)(RefCounted*);
                Fn f = *(Fn*)(*(char**)r + 4);
                f(r);
                if (_InterlockedExchangeAdd(&r->ref2, -1) == 1)
                {
                    Fn g = *(Fn*)(*(char**)r + 8);
                    g(r);
                }
            }
        }
        return;
    }
    if (op == 3)
    {
        void* t = *(void**)dst;
        int eq = _type_info_equals(t, (void*)0xb82df8);
        int mask = eq ? -1 : 0;
        *(int*)dst = mask & (int)src;
        return;
    }
    *(int*)dst = 0xb82df8;
    ((char*)dst)[4] = 0;
    ((char*)dst)[5] = 0;
}
