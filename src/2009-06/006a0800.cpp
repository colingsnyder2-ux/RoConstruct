// from server: 36% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct RefCounted {
    void* vptr;
    volatile long ref1;
    volatile long ref2;
};

extern "C" void __cdecl sub_69ec30(void*);
extern "C" void __cdecl sub_6cd9d0(void*, void*, void*);
extern "C" void* __cdecl sub_69fc20(void*);
extern "C" void __cdecl sub_6089b0(void*, void*, void*);
extern "C" void __cdecl sub_402500(void*, void*);
extern "C" void __cdecl sub_47df00(void*, void*);
extern "C" void* __cdecl sub_6a00c0(void*, void*);
extern "C" char __cdecl sub_5f9d50(void*, void*);
extern "C" void __cdecl sub_5f9b80(void*);
extern "C" void __cdecl sub_610c90(void*, void*);
extern "C" void __cdecl sub_41ab20(void*);

struct LocalBackpack {
    void method(void* a, void* b);
};

void LocalBackpack::method(void* a, void* b)
{
    char* self = (char*)this;
    if (a) {
        sub_69ec30(a);
    }
    sub_6cd9d0(self + 0xc4, a, b);
    if (!b) {
        return;
    }
    void* r = sub_69fc20(self);
    char tmp[8];
    sub_6089b0(tmp, r, 0);
    *(void**)(self + 0x118) = *(void**)tmp;
    sub_402500(self + 0x11c, tmp + 4);

    RefCounted* rc = *(RefCounted**)tmp;
    if (rc) {
        if (_InterlockedExchangeAdd(&rc->ref1, -1) == 1) {
            void** vt = (void**)rc->vptr;
            ((void(__thiscall*)(void*))vt[1])(rc);
            if (_InterlockedExchangeAdd(&rc->ref2, -1) == 1) {
                void** vt2 = (void**)rc->vptr;
                ((void(__thiscall*)(void*))vt2[2])(rc);
            }
        }
    }

    struct { void* f0; void* f4; void* f8; void* fc; } cb1;
    cb1.f0 = (void*)0x6a0750;
    cb1.f4 = 0;
    cb1.f8 = self;
    cb1.fc = 0;
    void* h1 = *(void**)(self + 0x118);
    sub_47df00(h1, &cb1);

    void* h2 = *(void**)(self + 0x118);
    struct { void* f0; void* f4; void* f8; void* fc; } cb2;
    cb2.f0 = (void*)0x6a0750;
    cb2.f4 = 0;
    cb2.f8 = self;
    cb2.fc = 0;
    void* e1 = sub_6a00c0((char*)h2 + 0x74, &cb2);
    if (sub_5f9d50(self + 0x148, e1)) {
        sub_5f9b80(self + 0x148);
        sub_610c90(self + 0x148, e1);
    }
    sub_41ab20(&cb1);

    void* h3 = *(void**)(self + 0x118);
    struct { void* f0; void* f4; void* f8; void* fc; } cb3;
    cb3.f0 = (void*)0x69e350;
    cb3.f4 = 0;
    cb3.f8 = self;
    cb3.fc = 0;
    void* e2 = sub_6a00c0((char*)h3 + 0x78, &cb3);
    if (sub_5f9d50(self + 0x150, e2)) {
        sub_5f9b80(self + 0x150);
        sub_610c90(self + 0x150, e2);
    }
    sub_41ab20(&cb2);
}
