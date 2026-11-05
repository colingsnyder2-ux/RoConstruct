// from server: 30% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" void __cdecl sub_7062b0(void *, void *, void *, void *);
extern "C" void __cdecl sub_7068c0(void *);
extern "C" void __cdecl sub_707cb0(void *, void *, void *, void *);

extern unsigned char byte_cd3089;
extern unsigned char byte_cd308d;
extern void *g_7063e0;

struct VHandles {
    void *method_707cb0(void *, void *, void *, void *);
};

void *VHandles::method_707cb0(void *a, void *b, void *c, void *d) {
    void *result;
    void *local;
    void *saved;
    unsigned char b1;
    unsigned char b2;
    long old;

    local = 0;
    b1 = byte_cd3089;
    b2 = byte_cd308d;

    sub_7062b0(&local, &b1, &b2, 0);
    sub_7068c0(&local);

    result = 0;
    sub_707cb0(this, a, b, &result);

    if (result) {
        void *vt = *(void **)result;
        if (vt) {
            void (*fn)(void *, void *, int) = *(void (**)(void *, void *, int))vt;
            fn(&result, &result, 2);
        }
        result = 0;
    }

    if (saved) {
        old = _InterlockedExchangeAdd((volatile long *)((char *)saved + 4), -1);
        if (old == 1) {
            void *vt = *(void **)saved;
            void (*fn)(void *) = *(void (**)(void *))((char *)vt + 4);
            fn(saved);
            old = _InterlockedExchangeAdd((volatile long *)((char *)saved + 8), -1);
            if (old == 1) {
                void *vt2 = *(void **)saved;
                void (*fn2)(void *) = *(void (**)(void *))((char *)vt2 + 8);
                fn2(saved);
            }
        }
    }

    return result;
}
