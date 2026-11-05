// from server: 36% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" void __cdecl func_006a4750(void*);

struct S_func_0070a670 {
    void* m_ref;
    void* assign(void* p);
};

void* S_func_0070a670::assign(void* p)
{
    m_ref = p;
    if (p != 0) {
        _InterlockedExchangeAdd((volatile long*)p, 1);
    }
    if (p != 0) {
        func_006a4750(p);
    }

    return this;
}
