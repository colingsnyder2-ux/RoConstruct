// from server: 43% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct RefCounted {
    void** vptr;
    long refcount;
    long weakrefcount;
};

struct Sub {
    char pad[0x388];
    void dtor();
};

struct Obj {
    void** vptr;
    char pad0[0x37c - 4];
    RefCounted* field37c;
    char pad1[0x384 - 0x380];
    RefCounted* field384;
    Sub sub388;
    void baseDtor();
};

void __fastcall release_ref(RefCounted* p) {
    if (p) {
        if (_InterlockedExchangeAdd(&p->refcount, -1) == 1) {
            ((void (__thiscall*)(RefCounted*))p->vptr[1])(p);
            if (_InterlockedExchangeAdd(&p->weakrefcount, -1) == 1) {
                ((void (__thiscall*)(RefCounted*))p->vptr[2])(p);
            }
        }
    }
}

void Obj::baseDtor() {
    vptr = (void**)0xa11494;
    sub388.dtor();
    release_ref(field384);
    release_ref(field37c);
}
