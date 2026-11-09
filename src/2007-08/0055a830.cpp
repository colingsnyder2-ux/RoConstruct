// from server: 33% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" void __stdcall _invalid_parameter_noinfo();

struct CreatorImpl {
    void* vptr;
    int refcount1;
    int refcount2;
};

struct FactoryProduct {
    char pad[0x134];
    CreatorImpl** creatorsBegin;
    CreatorImpl** creatorsEnd;

    int sub_55a2e0();
    void sub_559470(void** out);
    void sub_557860();
    void sub_541630(void* arg);
    void sub_402a60(void* arg);
};

extern "C" void* __cdecl sub_725520(void* a, void* b, void* c);

void* FactoryProduct_ctor(FactoryProduct* self) {
    if (self->sub_55a2e0() != 0) {
        return self;
    }

    void* local8 = 0;
    self->sub_559470(&local8);

    void* ebx = local8;

    sub_725520((void*)0x8c1f18, (void*)0x5588c0, (void*)0);
    self->sub_557860();

    int edi = 0;
    CreatorImpl** begin = self->creatorsBegin;
    if (begin != 0) {
        CreatorImpl** end = self->creatorsEnd;
        int count = (int)((char*)end - (char*)begin) >> 3;
        if (edi < count) {
            goto ok;
        }
    }
    _invalid_parameter_noinfo();
ok:
    CreatorImpl** slot = self->creatorsBegin + edi;
    *slot = (CreatorImpl*)ebx;
    self->sub_402a60(&local8);

    self->sub_541630(ebx);

    CreatorImpl* obj = (CreatorImpl*)local8;
    if (obj != 0) {
        if (_InterlockedExchangeAdd((volatile long*)&obj->refcount1, -1) == 1) {
            void** vt = (void**)obj->vptr;
            void (*fn)(void*) = (void (*)(void*))vt[1];
            fn(obj);
            if (_InterlockedExchangeAdd((volatile long*)&obj->refcount2, -1) == 1) {
                void** vt2 = (void**)obj->vptr;
                void (*fn2)(void*) = (void (*)(void*))vt2[2];
                fn2(obj);
            }
        }
    }

    return ebx;
}
