// from server: 41% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct Inner {
    char pad0[8];
    volatile long ref;
};

struct Mid {
    char pad0[4];
    Inner* p;
};

struct Holder {
    Mid* m;
    char pad4[0x28];
    Mid* q;
};

struct Outer {
    char pad0[0x2c];
    Holder h;
};

extern "C" void __stdcall sub_4e7350(void*, void*);

struct VRayHolder {
    void* field0;
    char pad4[4];
    void* field8;
    VRayHolder* assign(void* a, void* b);
};

VRayHolder* VRayHolder::assign(void* a, void* b) {
    void* saved;
    this->field0 = a;
    sub_4e7350(&this->field8, a);
    saved = 0;
    if (a) {
        Outer* o = (Outer*)a;
        Holder* h = &o->h;
        if (h) {
            h->m = (Mid*)a;
            Mid* cur = *(Mid**)&this->field8;
            if (cur != h->q) {
                if (cur) {
                    _InterlockedExchangeAdd(&cur->p->ref, 1);
                }
                Mid* old = h->q;
                if (old) {
                    if (_InterlockedExchangeAdd(&old->p->ref, -1) == 1) {
                        void** vt = *(void***)old->p;
                        void (*fn)(void*) = (void (*)(void*))vt[2];
                        fn(old->p);
                    }
                }
                h->q = cur;
            }
        }
    }
    return this;
}
