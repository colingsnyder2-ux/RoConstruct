// from server: 49% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct Inner {
    char pad_0[8];
    volatile long ref;
};

struct Outer {
    char pad_0[4];
    Inner* f_4;
    char pad_8[0x24];
    Outer* f_2c;
    Inner* f_30;
};

struct S {
    void* f_0;
    Inner* f_4;
    S* run(void* a, void* b);
};

extern "C" void __fastcall sub_70c2e0(void* self, void* unused, void* a, void* b);

S* S::run(void* a, void* b) {
    void* arg1 = a;
    void* arg2 = b;
    f_0 = arg1;
    sub_70c2e0(&f_4, 0, arg1, arg2);
    if (arg1 != 0) {
        Outer* p = (Outer*)((char*)arg1 + 0x2c);
        if (p != 0) {
            p->f_2c = (Outer*)arg1;
            Inner* old = f_4;
            if (old != p->f_30) {
                if (old != 0) {
                    _InterlockedExchangeAdd(&old->ref, 1);
                }
                Inner* cur = p->f_30;
                if (cur != 0) {
                    if (_InterlockedExchangeAdd(&cur->ref, -1) == 1) {
                        void** vt = *(void***)cur;
                        void (*fn)(Inner*) = (void (*)(Inner*))vt[2];
                        fn(cur);
                    }
                }
                p->f_30 = old;
            }
        }
    }
    return this;
}
