// from server: 32% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" void* __stdcall sub_98B208(void*);

struct RefCounted {
    virtual void slot4();
    virtual void slot8();
    long m_ref4;
    long m_ref8;
};

struct S_func_0066bc90 {
    void* m_vtbl;
    char pad0[0x14];
    void* m_18;
    char pad1[0x4];
    void* m_20;
    char pad2[0x18];
    RefCounted* m_3c;
    char pad3[0x4];
    RefCounted* m_44;
    void dtor();
};

void S_func_0066bc90::dtor()
{
    m_vtbl = (void*)0x9cea8c;
    RefCounted* p = m_44;
    if (p) {
        if (_InterlockedExchangeAdd(&p->m_ref4, -1) == 1) {
            p->slot4();
            if (_InterlockedExchangeAdd(&p->m_ref8, -1) == 1) {
                p->slot8();
            }
        }
    }
    p = m_3c;
    if (p) {
        if (_InterlockedExchangeAdd(&p->m_ref4, -1) == 1) {
            p->slot4();
            if (_InterlockedExchangeAdd(&p->m_ref8, -1) == 1) {
                p->slot8();
            }
        }
    }
    void* q = m_18;
    if (q) {
        void* f = *(void**)q;
        if (f) {
            ((void (__stdcall*)(void*, void*, int))f)((void*)((char*)this + 0x20), (void*)((char*)this + 0x20), 2);
        }
        m_18 = 0;
    }
    sub_98B208((void*)0xb7a224);
    m_vtbl = (void*)0x9a2cc4;
}
