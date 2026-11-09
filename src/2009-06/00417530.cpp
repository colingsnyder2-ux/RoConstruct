// from server: 47% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct RefCounted {
    void* vptr;
    long ref;
};

struct Holder {
    void* ptr;
    RefCounted* ref;
};

struct Inner {
    char pad[0x14];
};

struct Outer {
    Inner* inner;
    RefCounted* ref;
};

extern "C" void* __cdecl sub_4174B0(void** out);

struct S {
    Holder* f(Holder* out);
};

Holder* S::f(Holder* out) {
    void* tmp = 0;
    sub_4174B0(&tmp);
    Outer* o = (Outer*)tmp;
    Inner* inner = o->inner;
    void* p;
    if (inner) {
        p = (char*)inner + 0x14;
    } else {
        p = 0;
    }
    out->ptr = p;
    RefCounted* r = o->ref;
    out->ref = r;
    if (r) {
        _InterlockedExchangeAdd(&r->ref, 1);
    }
    RefCounted* old = (RefCounted*)tmp;
    if (old) {
        if (_InterlockedExchangeAdd(&old->ref, -1) == 1) {
            void** vt = (void**)old->vptr;
            ((void (__thiscall*)(RefCounted*))vt[1])(old);
            if (_InterlockedExchangeAdd((volatile long*)((char*)old + 8), -1) == 1) {
                void** vt2 = (void**)old->vptr;
                ((void (__thiscall*)(RefCounted*))vt2[2])(old);
            }
        }
    }
    return out;
}
