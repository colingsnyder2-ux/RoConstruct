// from server: 63% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct Inner {
    char pad0[4];
    volatile long ref1;
    volatile long ref2;
};

struct Outer {
    char pad0[4];
    Inner* p;
};

struct Holder {
    char pad0[0x18];
};

extern "C" Outer* __cdecl sub_5bb220(Outer** out);

struct S {
    void* f(void* out);
};

void* S::f(void* out) {
    Outer* tmp = 0;
    Outer* r = sub_5bb220(&tmp);
    void* result;
    if (r->p) {
        result = (char*)r->p + 0x18;
    } else {
        result = 0;
    }
    *(void**)out = result;
    Inner* inner = r->p;
    *(Inner**)((char*)out + 4) = inner;
    if (inner) {
        _InterlockedExchangeAdd(&inner->ref1, 1);
    }
    Inner* esi = *(Inner**)((char*)&tmp + 0);
    if (esi) {
        if (_InterlockedExchangeAdd(&esi->ref1, -1) == 1) {
            void** vt = *(void***)esi;
            ((void (__thiscall*)(void*))vt[1])(esi);
            if (_InterlockedExchangeAdd(&esi->ref2, -1) == 1) {
                void** vt2 = *(void***)esi;
                ((void (__thiscall*)(void*))vt2[2])(esi);
            }
        }
    }
    return out;
}
