// from server: 42% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" void __stdcall _invalid_parameter_noinfo();

struct Inner {
    int a;
    volatile long ref1;
    volatile long ref2;
    virtual void v1();
    virtual void v2();
};

struct Outer {
    char pad[0xa0];
    Inner* begin;
    Inner* end;
};

struct Holder {
    void* p;
};

extern "C" void* __stdcall make_value_004e6350();
void* func_004e6350();

struct S {
    int f();
};

extern "C" int __cdecl sub_004f1020();
extern "C" void __cdecl sub_004e9fa0(void*);
extern "C" void __cdecl sub_00401690(void*, void*, void*);
extern "C" void __cdecl sub_00402090(void*, void*);
extern "C" void __cdecl sub_00598d90(void*, void*);

int S::f() {
    int result;
    if (sub_004f1020() != 0) {
        return 0;
    }
    Holder h;
    sub_004e9fa0(&h);
    Outer* self = (Outer*)this;
    sub_00401690((void*)0x4e77a0, (void*)0xc06690, 0);
    void* val = func_004e6350();
    int idx = (int)val;
    int count = (int)((char*)self->end - (char*)self->begin) >> 3;
    if ((unsigned)idx >= (unsigned)count) {
        _invalid_parameter_noinfo();
    }
    Inner* slot = (Inner*)((char*)self->begin + idx * 8);
    slot->a = (int)h.p;
    sub_00402090((void*)&slot->ref1, &h);
    sub_00598d90((void*)this, (void*)0);
    Inner* obj = (Inner*)h.p;
    if (obj != 0) {
        if (_InterlockedExchangeAdd(&obj->ref1, -1) == 1) {
            obj->v1();
            if (_InterlockedExchangeAdd(&obj->ref2, -1) == 1) {
                obj->v2();
            }
        }
    }
    result = (int)h.p;
    return result;
}
