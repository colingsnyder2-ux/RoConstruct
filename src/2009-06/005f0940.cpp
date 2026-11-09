// from server: 34% by atomic.potato
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

struct S {
    void* field0;
    void* field4;
    S* init(void* a, void* b);
};

S* S::init(void* a, void* b)
{
    field0 = a;
    field4 = 0;
    if (a) {
        Outer* o = (Outer*)((char*)a + 0x24);
        if (o) {
            o->field0 = a;
            Inner* cur = (Inner*)field4;
            if (cur != (Inner*)o->holder.ptr) {
                if (cur) {
                    _InterlockedExchangeAdd(&cur->refcount, 1);
                }
                Inner* old = (Inner*)o->holder.ptr;
                if (old) {
                    if (_InterlockedExchangeAdd(&old->refcount, -1) == 1) {
                        void** vt = *(void***)old;
                        void (*fn)(Inner*) = (void (*)(Inner*))vt[2];
                        fn(old);
                    }
                }
                o->holder.ptr = cur;
            }
        }
    }
    return this;
}
