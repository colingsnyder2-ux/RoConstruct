// from server: 38% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct Inner {
    char pad0[8];
    volatile long ref;
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
    void* f0;
    Holder h;
    S* ctor(void* a, void* b);
};

extern "C" void __stdcall sub_4f0010(void*, void*);

S* S::ctor(void* a, void* b)
{
    S* self = this;
    self->f0 = a;
    sub_4f0010(&self->h, b);
    if (a != 0) {
        Outer* o = (Outer*)((char*)a + 0x2c);
        if (o != 0) {
            o->pad0;
            *(void**)o = a;
            Inner* old = self->h.p;
            if (old != o->h.q) {
                if (old != 0) {
                    _InterlockedExchangeAdd(&old->ref, 1);
                }
                Inner* cur = o->h.q;
                if (cur != 0) {
                    if (_InterlockedExchangeAdd(&cur->ref, -1) == 1) {
                        void** vt = *(void***)cur;
                        void (*fn)(Inner*) = (void (*)(Inner*))vt[2];
                        fn(cur);
                    }
                }
                o->h.q = old;
            }
        }
    }
    return self;
}
