// from server: 33% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct RefCounted {
    virtual void v0();
    virtual void v1();
    virtual void v2();
    virtual void v3();
    volatile long m_refCount;
    volatile long m_weakRefCount;
};

struct String {
    void* m_data;
    char m_buf[0x1c];
};

struct S {
    char pad0[8];
    String m_str;
    char pad1[0x18];

    void func(int arg);
};

extern "C" void __stdcall sub_4B1D30(void*);
extern "C" void __stdcall sub_541630(void*);
extern "C" void __stdcall sub_77E698(void*, int);
extern "C" void __stdcall sub_77E6AC(void*);

void S::func(int arg) {
    sub_4B1D30(&m_str);
    sub_77E698(&m_str, arg);
    void* p = m_str.m_data;
    void** vtbl = *(void***)p;
    void (*fn)(void*, void*) = (void (*)(void*, void*))vtbl[2];
    fn(p, &m_str);
    sub_77E6AC(&m_str);
    sub_541630(this);
    RefCounted* rc = (RefCounted*)m_str.m_data;
    if (rc) {
        if (_InterlockedExchangeAdd(&rc->m_refCount, -1) == 1) {
            void** v = *(void***)rc;
            void (*d)(void*) = (void (*)(void*))v[1];
            d(rc);
            if (_InterlockedExchangeAdd(&rc->m_weakRefCount, -1) == 1) {
                void** v2 = *(void***)rc;
                void (*d2)(void*) = (void (*)(void*))v2[2];
                d2(rc);
            }
        }
    }
}
