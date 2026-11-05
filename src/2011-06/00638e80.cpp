// from server: 52% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" void __stdcall SetEvent(void*);

struct RefCounted {
    void** vptr;
    volatile long m_ref1;
    volatile long m_ref2;
};

struct Holder {
    RefCounted* m_ptr;
    char m_flag;
};

struct S_func_00638e80 {
    char pad0[0xdc];
    char m_lock;
    void f(RefCounted* p);
};

extern "C" void __cdecl sub_5b8730(void*);
extern "C" void __cdecl sub_411500(void*);
extern "C" void __cdecl sub_638530(void*);
extern "C" void __cdecl sub_597910(void*, void*);
extern "C" void* __cdecl sub_40a2b0();

extern void* g_ccca34;

void S_func_00638e80::f(RefCounted* p)
{
    void* local;
    sub_5b8730(&local);

    if (p != 0) {
        if (_InterlockedExchangeAdd(&p->m_ref1, -1) == 1) {
            ((void (__thiscall*)(RefCounted*))p->vptr[1])(p);
            if (_InterlockedExchangeAdd(&p->m_ref2, -1) == 1) {
                ((void (__thiscall*)(RefCounted*))p->vptr[2])(p);
            }
        }
    }

    Holder h;
    h.m_ptr = (RefCounted*)((char*)this + 0xdc);
    h.m_flag = 0;
    sub_411500(&h);

    if (g_ccca34 == 0) {
        void* tmp;
        sub_638530(&tmp);
        h.m_flag = 1;
        sub_597910(tmp, this);
        h.m_flag = 0;
        RefCounted* q = *(RefCounted**)&tmp;
        if (q != 0) {
            if (_InterlockedExchangeAdd(&q->m_ref1, -1) == 1) {
                ((void (__thiscall*)(RefCounted*))q->vptr[1])(q);
                if (_InterlockedExchangeAdd(&q->m_ref2, -1) == 1) {
                    ((void (__thiscall*)(RefCounted*))q->vptr[2])(q);
                }
            }
        }
    }

    if (h.m_flag) {
        long old = _InterlockedExchangeAdd((volatile long*)h.m_ptr, (long)0x80000000);
        if ((old & 0x40000000) == 0 && old > (long)0x80000000) {
            long prev = _InterlockedExchangeAdd((volatile long*)h.m_ptr, 0);
            if ((prev & 0x40000000) == 0) {
                SetEvent(sub_40a2b0());
            }
        }
    }
}
