// from server: 45% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct RefCounted {
    void* vptr;
    volatile long refs;
    volatile long weakRefs;
    virtual void destroy();
    virtual void destroyWeak();
};

struct Conn {
    void* vptr;
    void* slot;
    void* signal;
};

struct Slot {
    void* vptr;
    void* a;
    void* b;
};

struct Impl {
    void* vptr;
    void* a;
    void* b;
};

struct Holder {
    char pad0[4];
    void* ptr;
    char pad1[4];
};

struct Arg {
    void* a;
    void* b;
    void* c;
};

struct Fn {
    void* a;
    void* b;
    void* c;
};

struct S {
    char pad0[4];
    void* f4;
    void* f8;
    bool method(void*, void*, void*, void*, void*, void*);
};

bool S::method(void* a, void* b, void* c, void* d, void* e, void* f) {
    if (*(int*)this == 0) {
        void* p = ((void* (*)())0x413c00)();
        ((void (*)(void*))0x414170)(p);
    }
    RefCounted* r1 = (RefCounted*)d;
    RefCounted* r2 = (RefCounted*)e;
    if (r1) {
        _InterlockedExchangeAdd(&r1->refs, 1);
    }
    if (r2) {
        _InterlockedExchangeAdd(&r2->refs, 1);
    }
    bool result = ((bool (*)(void*, void*, void*, void*, void*, void*))this->f8)(this->f4, a, b, c, d, e);
    if (r2) {
        if (_InterlockedExchangeAdd(&r2->refs, -1) == 1) {
            r2->destroy();
            if (_InterlockedExchangeAdd(&r2->weakRefs, -1) == 1) {
                r2->destroyWeak();
            }
        }
    }
    if (r1) {
        if (_InterlockedExchangeAdd(&r1->refs, -1) == 1) {
            r1->destroy();
            if (_InterlockedExchangeAdd(&r1->weakRefs, -1) == 1) {
                r1->destroyWeak();
            }
        }
    }
    return result;
}
