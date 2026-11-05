// from server: 20% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct Inner {
    char pad0[4];
    volatile long ref;
    char pad1[4];
    virtual void destroy();
};

struct Mid {
    Inner* p;
    Inner* q;
};

struct Outer {
    Mid* m;
    char pad0[4];
    Mid mid;
    Outer* construct(Mid* src, int unused);
};

Outer* Outer::construct(Mid* src, int unused) {
    this->m = src;
    Mid* dst = &this->mid;
    dst->p = 0;
    dst->q = 0;
    if (src) {
        Inner* s = src->p;
        if (s) {
            dst->p = s;
            Inner* old = dst->q;
            if (old != s) {
                if (s) {
                    _InterlockedExchangeAdd(&s->ref, 1);
                }
                if (old) {
                    if (_InterlockedExchangeAdd(&old->ref, -1) == 1) {
                        old->destroy();
                    }
                }
                dst->q = s;
            }
        }
    }
    return this;
}
