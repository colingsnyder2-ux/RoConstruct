// from server: 58% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct WeakThreadRef
{
    void* m_reference;
    void release();
};

extern "C" void __cdecl release_0062ac70(void*);
extern "C" void __cdecl destroy_0080a058(void*);

void WeakThreadRef::release()
{
    void* value = m_reference;
    if (value != 0)
    {
        if (_InterlockedExchangeAdd((volatile long*)value, -1) == 1)
        {
            if (value != 0)
                release_0062ac70(value);
            destroy_0080a058(value);
        }
    }
}
