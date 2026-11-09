// from server: 32% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" {
    void* __stdcall sub_439330();
    void __stdcall sub_482590();
    void __stdcall sub_6dde00();
    int __stdcall sub_7e1af0(int, void*);
    void* __stdcall sub_b22648();
    void* __stdcall sub_b2263c();
}

struct RefCounted {
    void* vptr;
    long refcount;
    long refcount2;
};

struct Holder {
    void* vptr;
    RefCounted* ptr;
};

struct String {
    char pad[0x1c];
};

struct Big {
    char pad[0x8c];
    void* field_8c;
};

struct S {
    int f(int, int, int, int, int, int, int, int);
};

int S::f(int a1, int a2, int a3, int a4, int a5, int a6, int a7, int a8)
{
    int result = 3;
    Holder h;
    h.vptr = 0;
    h.ptr = 0;

    if (a1 == 1) {
        sub_439330();
        RefCounted* p = h.ptr;
        if (p != 0) {
            Big* big = (Big*)p;
            void* v = big->field_8c;
            if (sub_7e1af0((int)v, &h) != 0) {
                sub_6dde00();
                return result;
            }
        }
        if (p != 0) {
            if (_InterlockedExchangeAdd(&p->refcount, -1) == 1) {
                void** vt = (void**)p->vptr;
                ((void (__stdcall*)(RefCounted*))vt[1])(p);
                if (_InterlockedExchangeAdd(&p->refcount2, -1) == 1) {
                    void** vt2 = (void**)p->vptr;
                    ((void (__stdcall*)(RefCounted*))vt2[2])(p);
                }
            }
        }
    }

    sub_b22648();
    sub_482590();

    if (h.ptr != 0) {
        if (_InterlockedExchangeAdd(&h.ptr->refcount2, -1) == 1) {
            void** vt = (void**)h.ptr->vptr;
            ((void (__stdcall*)(RefCounted*))vt[2])(h.ptr);
        }
    }

    sub_b2263c();

    if (h.ptr != 0) {
        void* v = *(void**)h.ptr;
        if (v != 0) {
            ((void (__stdcall*)(int, void*, void*))v)(2, &h, &h);
        }
        h.ptr = 0;
    }

    return result;
}
