// from server: 54% by atomic.potato
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
    void* field0;
    Holder holder;
};

struct Base {
    void construct(void* a, void* b);
};

struct Creator {
    void* field0;
    Holder holder;
    Creator* create(void* a, void* b);
};

Creator* Creator::create(void* a, void* b) {
    this->field0 = a;
    ((Base*)&this->holder)->construct(a, b);
    if (a != 0) {
        Outer* o = (Outer*)((char*)a + 0x2c);
        if (o != 0) {
            o->field0 = a;
            Inner* old = this->holder.ptr;
            if (old != o->holder.ptr) {
                if (old != 0) {
                    _InterlockedExchangeAdd(&old->refcount, 1);
                }
                Inner* cur = o->holder.ptr;
                if (cur != 0) {
                    if (_InterlockedExchangeAdd(&cur->refcount, -1) == 1) {
                        void** vt = *(void***)cur;
                        void (*fn)(Inner*) = (void (*)(Inner*))vt[2];
                        fn(cur);
                    }
                }
                o->holder.ptr = old;
            }
        }
    }
    return this;
}
