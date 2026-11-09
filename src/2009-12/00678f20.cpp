// from server: 40% by atomic.potato
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

struct ClearBackpack {
    void* field0;
    Holder holder;
    void sub_678a30(void* a, void* b);
    ClearBackpack* ClearBackpack_fn(void* a, void* b);
};

ClearBackpack* ClearBackpack::ClearBackpack_fn(void* a, void* b) {
    void* local = a;
    this->field0 = a;
    this->sub_678a30(a, b);
    if (a != 0) {
        Outer* p = (Outer*)((char*)a + 0x2c);
        if (p != 0) {
            p->field0 = a;
            Inner* old = this->holder.ptr;
            if (old != p->holder.ptr) {
                if (old != 0) {
                    _InterlockedExchangeAdd(&old->refcount, 1);
                }
                Inner* cur = p->holder.ptr;
                if (cur != 0) {
                    if (_InterlockedExchangeAdd(&cur->refcount, -1) == 1) {
                        void** vt = *(void***)cur;
                        void (*fn)(Inner*) = (void (*)(Inner*))vt[2];
                        fn(cur);
                    }
                }
                p->holder.ptr = old;
            }
        }
    }
    return this;
}
