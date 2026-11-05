// from server: 19% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct Sub1 {
    void f1();
    void f2();
};

struct Sub2 {
    void f1();
    void f2();
};

struct RefCounted {
    virtual void v1();
    virtual void v2();
    virtual void v3();
    volatile long ref1;
    volatile long ref2;
};

struct PartChunk {
    void* vptr0;
    char pad0[8];
    void* vptr1;
    char pad1[0xdc];
    RefCounted* ptr_e8;
    Sub2 sub_ec;
    Sub1 sub_f4;
    void dtor_helper();
    void dtor();
};

void PartChunk::dtor() {
    this->vptr0 = (void*)0xa1ef04;
    this->vptr1 = (void*)0xa1eee8;
    this->sub_f4.f1();
    this->sub_f4.f2();
    this->sub_ec.f1();
    this->sub_ec.f2();
    RefCounted* p = this->ptr_e8;
    if (p) {
        if (_InterlockedExchangeAdd(&p->ref1, -1) == 1) {
            p->v1();
            if (_InterlockedExchangeAdd(&p->ref2, -1) == 1) {
                p->v2();
            }
        }
    }
    this->dtor_helper();
}
