// from server: 34% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct SubObj {
    void sub_479690();
    void sub_479cd0();
    void sub_479c70();
};

struct FactoryProduct {
    char pad0[0x68];
    void* field68;
    void* field6c;
    char pad70[0x2c];
    SubObj* field9c;
    void* fielda0;
    void* fielda4;
};

struct LocalObj {
    char pad0[0x2c];
    LocalObj();
    ~LocalObj();
};

extern "C" void __cdecl sub_40d550(void*);
extern "C" void __cdecl sub_5081c0(void*);
extern "C" void __cdecl sub_5082d0(void*);
extern "C" void __cdecl sub_5579e0(void*, void*);
extern "C" void __cdecl sub_55b5a0(void*, void*);
extern "C" void __cdecl sub_5595a0(void*);

void SubObj::sub_479690() {}
void SubObj::sub_479cd0() {}
void SubObj::sub_479c70() {}

void FactoryProduct_ctor(FactoryProduct* self, char flag)
{
    self->field9c->sub_479690();

    void* b = self->field6c;
    if (b) {
        _InterlockedExchangeAdd((volatile long*)((char*)b + 4), 1);
    }

    LocalObj local;
    sub_40d550(&local);

    void* p = self->field9c;
    void* q = self->fielda0;
    void* vt = *(void**)q;
    void (*fn)(void*, void*) = *(void (**)(void*, void*))((char*)vt + 4);
    fn(q, p);

    void* q2 = self->fielda0;
    void* vt2 = *(void**)q2;
    void* (*fn2)(void*) = *(void* (**)(void*))((char*)vt2 + 0x1c);
    void* r = fn2(q2);
    sub_5081c0(r);

    void* a4 = self->fielda4;
    void* c68 = self->field68;
    sub_5579e0(c68, a4);

    if (flag) {
        self->field9c->sub_479cd0();
        void* a4b = self->fielda4;
        void* c68b = self->field68;
        sub_55b5a0(c68b, a4b);
        self->field9c->sub_479c70();
    }

    sub_5082d0(r);
    sub_5595a0(&local);
}
