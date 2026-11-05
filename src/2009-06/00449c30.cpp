// from server: 24% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct Inner {
    char pad0[8];
    volatile long refcount;
};

struct Outer {
    char pad0[4];
    Inner* ptr;
};

struct Holder {
    Outer* p;
    Outer* q;
};

struct S {
    void* field0;
    void* field4;
    S* construct(void* a, void* b);
};

S* S::construct(void* a, void* b) {
    this->field0 = a;
    ((Holder*)((char*)this + 4))->p = (Outer*)a;
    ((Holder*)((char*)this + 4))->q = (Outer*)a;
    if (a != 0) {
        Outer* o = (Outer*)a;
        Inner* ip = (Inner*)((char*)o + 0x24);
        if (ip != 0) {
            ip->refcount = (long)o;
            Inner* cur = ((Holder*)((char*)this + 4))->p ? ((Holder*)((char*)this + 4))->p->ptr : 0;
            if (cur != ip) {
                if (cur != 0) {
                    _InterlockedExchangeAdd(&cur->refcount, 1);
                }
                Inner* old = ((Holder*)((char*)this + 4))->q ? ((Holder*)((char*)this + 4))->q->ptr : 0;
                if (old != 0) {
                    if (_InterlockedExchangeAdd(&old->refcount, -1) == 1) {
                        void** vt = *(void***)old;
                        void (*fn)(void*) = (void (*)(void*))vt[2];
                        fn(old);
                    }
                }
                ((Holder*)((char*)this + 4))->q = (Outer*)cur;
            }
        }
    }
    return this;
}
