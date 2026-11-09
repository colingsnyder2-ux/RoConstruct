// from server: 57% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" void __cdecl _free(void*);

struct RefCounted {
    void** vptr;
    long m_ref;
};

struct S_func_0048ee70 {
    void** vptr;
    char pad[4];
    RefCounted* m_ref;
    void dtor(char flag);
};

void S_func_0048ee70::dtor(char flag)
{
    vptr = (void**)0x9b2eec;
    RefCounted* r = m_ref;
    if (r) {
        if (_InterlockedExchangeAdd(&r->m_ref, -1) == 1) {
            void** vt = r->vptr;
            void (*fn)(RefCounted*) = (void (*)(RefCounted*))vt[2];
            fn(r);
        }
    }
    if (flag & 1) {
        _free(this);
    }
}
