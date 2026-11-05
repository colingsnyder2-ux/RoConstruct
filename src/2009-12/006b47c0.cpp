// from server: 39% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct Inner {
    char pad0[8];
    volatile long refcount;
};

struct Holder {
    Inner* ptr;
};

struct Outer {
    char pad0[4];
    Holder holder;
};

struct Sub {
    void method(void* x, void* y);
};

struct S {
    void* field0;
    void* field4;
    S* construct(void* a, void* b);
};

S* S::construct(void* a, void* b) {
    void* p = a;
    this->field0 = p;
    void* q = b;
    ((Sub*)&this->field4)->method(q, p);
    if (p != 0) {
        Outer* o = (Outer*)((char*)p + 0x2c);
        if (o != 0) {
            o->holder.ptr = (Inner*)p;
            Inner* old = (Inner*)this->field4;
            if (old != o->holder.ptr) {
                if (old != 0) {
                    _InterlockedExchangeAdd(&old->refcount, 1);
                }
                Inner* cur = o->holder.ptr;
                if (cur != 0) {
                    if (_InterlockedExchangeAdd(&cur->refcount, -1) == 1) {
                        void** vt = *(void***)cur;
                        void (*fn)(void*) = (void (*)(void*))vt[2];
                        fn(cur);
                    }
                }
                o->holder.ptr = old;
            }
        }
    }
    return this;
}
