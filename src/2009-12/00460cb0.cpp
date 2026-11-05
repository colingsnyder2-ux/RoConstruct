// from server: 17% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct Inner {
    void* vt;
    char pad[0x64];
};

struct Obj {
    char pad0[0x20];
    int f20;
    char pad1[0x188];
    int f1a8;
    int f1ac;
    char pad2[8];
    Inner f1b8;
    char pad3[0x1c];
    int f1d8;
};

struct Holder {
    void* p;
};

extern "C" void __cdecl sub_66ff30(void*);
extern "C" void __cdecl sub_66aa30(void*);
extern "C" void __cdecl sub_4f60b0(void*);
extern "C" void __cdecl sub_4104a0(void);
extern "C" void __cdecl sub_5123a0(void);
extern "C" void __cdecl sub_514ad0(void);
extern "C" void __cdecl sub_42d470(void);

struct Self {
    char pad0[0x20];
    int f20;
    char pad1[0x188];
    int f1a8;
    int f1ac;
    char pad2[8];
    Inner f1b8;
    char pad3[0x1c];
    int f1d8;

    void* sub_45f630(void*);
    void sub_45f670();
    void method(bool);
};

void Self::method(bool b)
{
    if (f20 == 0)
        return;

    Holder h;
    h.p = 0;

    int* p1 = &f1a8;
    int* p2 = &f1ac;
    int a = *p1;
    int c = *p2;
    h.p = 0;
    (void)a;
    (void)c;

    sub_66ff30(&h);

    void* r;
    sub_45f630(&r);
    void* v = *(void**)&r;
    if (v != 0) {
        sub_4104a0();
    }

    void* edi = 0;
    if (edi != 0) {
        if (_InterlockedExchangeAdd((volatile long*)((char*)edi + 4), -1) == 1) {
            void** vt = *(void***)edi;
            void (*fn)(void*) = (void (*)(void*))vt[1];
            fn(edi);
            if (_InterlockedExchangeAdd((volatile long*)((char*)edi + 8), -1) == 1) {
                void** vt2 = *(void***)edi;
                void (*fn2)(void*) = (void (*)(void*))vt2[2];
                fn2(edi);
            }
        }
    }

    if (v != 0) {
        void* r2;
        sub_45f630(&r2);
        void* v2 = *(void**)&r2;
        sub_5123a0();
        sub_514ad0();
        sub_4f60b0(&r2);
    }

    sub_66aa30(&h);

    bool flag = (f1d8 != 0);
    if (b == flag)
        return;

    if (b) {
        void* r3;
        sub_45f630(&r3);
        void* v3 = *(void**)&r3;
        sub_42d470();
        sub_4f60b0(&r3);
    } else {
        void** vt = *(void***)&f1b8;
        void (*fn)(void*) = (void (*)(void*))vt[0x68/4];
        fn(&f1b8);
    }

    sub_45f670();
}
