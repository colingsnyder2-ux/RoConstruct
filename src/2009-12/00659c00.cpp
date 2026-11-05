// from server: 45% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct Inner {
    char pad0[8];
    volatile long refcnt;
};

struct Holder {
    Inner* p;
    Inner* q;
};

struct Outer {
    char pad0[4];
    Holder h;
};

struct S {
    void* field0;
    Holder h;
    S* f(void* a, void* b);
};

void sub_659B70(Holder* h, void* a, void* b);

S* S::f(void* a, void* b)
{
    S* self = this;
    self->field0 = a;
    sub_659B70(&self->h, a, b);
    if (a != 0) {
        Holder* d = (Holder*)((char*)a + 0x2c);
        if (d != 0) {
            d->p = (Inner*)a;
            Inner* old = self->h.p;
            if (old != d->q) {
                if (old != 0) {
                    _InterlockedExchangeAdd(&old->refcnt, 1);
                }
                Inner* q = d->q;
                if (q != 0) {
                    if (_InterlockedExchangeAdd(&q->refcnt, -1) == 1) {
                        void** vt = *(void***)q;
                        void (*fn)(Inner*) = (void (*)(Inner*))vt[2];
                        fn(q);
                    }
                }
                d->q = old;
            }
        }
    }
    return self;
}
