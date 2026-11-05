// from server: 36% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct Inner {
    char pad0[8];
    volatile long refcount;
};

struct Holder {
    Inner* p;
};

struct Sub {
    char pad0[0x2c];
    Holder* h;
};

struct Outer {
    Sub* s;
    char pad4[4];
    Holder* h;
    int f(Sub* a, int b);
};

int Outer::f(Sub* a, int b) {
    this->s = a;
    if (a) {
        Holder* h = (Holder*)((char*)a + 0x2c);
        if (h) {
            h->p = (Inner*)a;
            Inner* old = this->h->p;
            if (old != h->p) {
                if (old) {
                    _InterlockedExchangeAdd(&old->refcount, 1);
                }
                Inner* prev = h->p;
                if (prev) {
                    if (_InterlockedExchangeAdd(&prev->refcount, -1) == 1) {
                        void** vt = *(void***)prev;
                        void (*fn)(Inner*) = (void (*)(Inner*))vt[2];
                        fn(prev);
                    }
                }
                h->p = old;
            }
        }
    }
    return (int)this;
}
