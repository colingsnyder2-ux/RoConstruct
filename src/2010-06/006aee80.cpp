// from server: 36% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)
extern "C" void __stdcall sub_9ea37c(int);

struct RefCounted {
    virtual void f0();
    virtual void f1();
    virtual void f2();
    long m_ref1;
    long m_ref2;
};

struct T4_006aee80 {
    void* m_vptr;
    char pad_04[0x14];
    void* m_p18;
    char pad_1c[0x04];
    void* m_p20;
    char pad_24[0x18];
    RefCounted* m_p3c;
    char pad_40[0x04];
    RefCounted* m_p44;
    void dtor();
};

void T4_006aee80::dtor()
{
    m_vptr = (void*)0xa41564;
    RefCounted* p = m_p44;
    if (p) {
        if (_InterlockedExchangeAdd(&p->m_ref1, -1) == 1) {
            p->f1();
            if (_InterlockedExchangeAdd(&p->m_ref2, -1) == 1)
                p->f2();
        }
    }
    p = m_p3c;
    if (p) {
        if (_InterlockedExchangeAdd(&p->m_ref1, -1) == 1) {
            p->f1();
            if (_InterlockedExchangeAdd(&p->m_ref2, -1) == 1)
                p->f2();
        }
    }
    void* q = m_p18;
    if (q) {
        void (*fn)(void*, int) = *(void(**)(void*, int))q;
        if (fn) {
            fn(m_p20, 2);
        }
        m_p18 = 0;
    }
    sub_9ea37c(0xc007ac);
    m_vptr = (void*)0xa0399c;
}
