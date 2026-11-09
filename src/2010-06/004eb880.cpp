// from server: 67% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct RefCounted
{
    virtual void onZeroRefs();
    virtual void onFinalRelease();
    volatile long refCount;
    volatile long weakRefCount;
};

void __stdcall ReleaseRefCounted(RefCounted *obj, int)
{
    if (obj != 0)
    {
        if (_InterlockedExchangeAdd(&obj->refCount, -1) == 1)
        {
            obj->onZeroRefs();
            if (_InterlockedExchangeAdd(&obj->weakRefCount, -1) == 1)
            {
                obj->onFinalRelease();
            }
        }
    }
}
