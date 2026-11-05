// from server: 53% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" void __stdcall SetEvent(void*);

struct RefCounted {
    void** vptr;
    long ref1;
    long ref2;
};

struct Holder {
    RefCounted* p;
    char flag;
};

struct Inner {
    void* p;
};

extern void* g_0xcb1778;
extern void* g_0xa40374;

void* __cdecl sub_40a2b0();
void __cdecl sub_411500(Holder*);
void __cdecl sub_423e30(Inner*);
void __cdecl sub_597910(void*, void*);
void __cdecl sub_5b8730(Inner*);

struct CInsertObjectDialog {
    char pad[0xdc];
    void* field_dc;
    void method();
};

void CInsertObjectDialog::method()
{
    Inner local;
    Holder h;
    void* ev;

    sub_5b8730(&local);
    RefCounted* rc = (RefCounted*)local.p;
    if (rc) {
        if (_InterlockedExchangeAdd(&rc->ref1, -1) == 1) {
            ((void (__thiscall*)(RefCounted*))rc->vptr[1])(rc);
            if (_InterlockedExchangeAdd(&rc->ref2, -1) == 1) {
                ((void (__thiscall*)(RefCounted*))rc->vptr[2])(rc);
            }
        }
    }

    h.p = (RefCounted*)&this->field_dc;
    h.flag = 0;
    sub_411500(&h);

    if (g_0xcb1778 == 0) {
        Inner local2;
        sub_423e30(&local2);
        void* p = local2.p;
        h.flag = 1;
        sub_597910(p, this);
        RefCounted* rc2 = (RefCounted*)local2.p;
        h.flag = 0;
        if (rc2) {
            if (_InterlockedExchangeAdd(&rc2->ref1, -1) == 1) {
                ((void (__thiscall*)(RefCounted*))rc2->vptr[1])(rc2);
                if (_InterlockedExchangeAdd(&rc2->ref2, -1) == 1) {
                    ((void (__thiscall*)(RefCounted*))rc2->vptr[2])(rc2);
                }
            }
        }
    }

    ev = g_0xcb1778;
    if (h.flag) {
        RefCounted* rc3 = h.p;
        long old = _InterlockedExchangeAdd(&rc3->ref1, (long)0x80000000);
        if (!(old & 0x40000000) && old > (long)0x80000000) {
            long prev = _InterlockedExchangeAdd((volatile long*)rc3, 0);
            if (!(prev & (1 << 0x1e))) {
                _InterlockedExchangeAdd((volatile long*)rc3, 0);
                SetEvent(sub_40a2b0());
            }
        }
    }
    return;
}
