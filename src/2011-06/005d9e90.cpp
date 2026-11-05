// from server: 47% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct Inner {
    char pad0[8];
    volatile long ref;
};

struct Holder {
    Inner* p;
};

struct Sub {
    char pad0[4];
    Holder h;
};

struct Obj {
    char pad0[8];
    volatile long ref;
    virtual void vf();
};

struct Outer {
    char pad0[4];
    Sub* sub;
};

struct S {
    void* field0;
    Outer outer;
    S* f(void* a, void* b);
};

S* S::f(void* a, void* b) {
    S* self = this;
    self->field0 = a;
    Sub* s = (Sub*)&self->outer;
    s->h.p = 0;
    if (a) {
        Sub* t = (Sub*)((char*)a + 0x2c);
        if (t) {
            t->h.p = (Inner*)a;
            Inner* cur = s->h.p;
            if (cur != t->h.p) {
                if (cur) {
                    _InterlockedExchangeAdd(&cur->ref, 1);
                }
                Inner* old = t->h.p;
                if (old) {
                    if (_InterlockedExchangeAdd(&old->ref, -1) == 1) {
                        ((Obj*)old)->vf();
                    }
                }
                t->h.p = cur;
            }
        }
    }
    return self;
}
