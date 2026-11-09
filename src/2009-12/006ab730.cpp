// from server: 38% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct Sub1 {
    char pad0[0x4c];
    int field4c;
};

struct Sub2 {
    virtual void v0();
    virtual void v1();
    virtual void v2();
};

struct Obj {
    char pad0[0xc4];
    int fieldc4;
};

extern "C" void* __cdecl sub_6e55b0(int);
extern "C" void* __cdecl sub_6e3250(void*);
extern "C" int __cdecl sub_6ab530(void*);
extern "C" void __cdecl sub_636d80(Obj*, int);

struct VHat {
    void func(Obj* a, Sub2* b);
};

void VHat::func(Obj* a, Sub2* b)
{
    if (a->fieldc4 == 2) {
        Sub1* s = (Sub1*)b;
        int v = s->field4c;
        void* p = sub_6e55b0(v);
        if (p) {
            void* q = sub_6e3250(p);
            if (q) {
                if (sub_6ab530((void*)v) == 0) {
                    sub_636d80(a, v);
                }
            }
        }
    }
    if (b) {
        if (_InterlockedExchangeAdd((volatile long*)((char*)b + 4), -1) == 1) {
            b->v1();
            if (_InterlockedExchangeAdd((volatile long*)((char*)b + 8), -1) == 1) {
                b->v2();
            }
        }
    }
}
