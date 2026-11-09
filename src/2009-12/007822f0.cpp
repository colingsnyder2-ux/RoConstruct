// from server: 58% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct Inner {
    void* vt;
    long ref1;
    long ref2;
};

struct Obj {
    void* field0;
    Inner* field4;
};

struct Src {
    void* a;
    void* b;
};

extern "C" void* __cdecl sub_410330(void* out, void* in);
extern "C" void __cdecl sub_75de40(void* self, void* arg);

struct Big {
    char pad0[0x20];
    char flag20;
    char pad21[3];
    int field24;
    int field28;
    int field2c;
};

struct S {
    void* f0;
    Inner* f4;
    char pad8[0x18];
    char f20;
    char pad21[3];
    int f24;
    int f28;
    int f2c;
    Big* init(void* a, void* b, int c, int d);
};

Big* S::init(void* a, void* b, int c, int d) {
    Src tmp;
    sub_410330(&tmp, a);
    f0 = tmp.a;
    f4 = (Inner*)tmp.b;
    if (f4) {
        _InterlockedExchangeAdd(&f4->ref1, 1);
    }
    Inner* old = (Inner*)f0;
    if (old) {
        if (_InterlockedExchangeAdd(&old->ref1, -1) == 1) {
            void** vt = (void**)old->vt;
            ((void (__thiscall*)(Inner*))vt[1])(old);
            if (_InterlockedExchangeAdd(&old->ref2, -1) == 1) {
                void** vt2 = (void**)old->vt;
                ((void (__thiscall*)(Inner*))vt2[2])(old);
            }
        }
    }
    sub_75de40(&f20, b);
    f24 = c;
    f28 = d;
    f20 = 1;
    Big* p = (Big*)f28;
    int* q = (int*)((char*)p + 0x140);
    int* r = (int*)((char*)*q + 0xd0);
    f2c = *r;
    return (Big*)this;
}
