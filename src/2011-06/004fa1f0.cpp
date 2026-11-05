// from server: 70% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct RefCounted
{
    void *vtable;
    volatile long refCount1;
    volatile long refCount2;
};

void __stdcall ReleaseRefCounted(RefCounted *p)
{
    if (p != 0)
    {
        if (_InterlockedExchangeAdd(&p->refCount1, -1) == 1)
        {
            void (__thiscall *fn1)(RefCounted *) = *(void (__thiscall **)(RefCounted *))((char *)p->vtable + 4);
            fn1(p);
            if (_InterlockedExchangeAdd(&p->refCount2, -1) == 1)
            {
                void (__thiscall *fn2)(RefCounted *) = *(void (__thiscall **)(RefCounted *))((char *)p->vtable + 8);
                fn2(p);
            }
        }
    }
}
