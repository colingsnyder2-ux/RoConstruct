// from server: 48% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct RefCounted {
    void* vptr;
    volatile long refcount;
};

struct Arg {
    void* ptr;
    RefCounted* ref;
};

struct Inner {
    int a;
    int b;
};

struct BoundFuncDesc {
    void* vptr;
    int field4;
    Inner inner;

    BoundFuncDesc(Arg* arg);
};

extern "C" void __stdcall sub_4181b0(void*);
extern "C" void __stdcall sub_49c0c0(void*);
extern "C" void* __cdecl sub_62fef6(unsigned int);
extern "C" void __stdcall sub_728830(void*);

BoundFuncDesc::BoundFuncDesc(Arg* arg)
{
    this->vptr = 0;
    this->field4 = 0;

    void* p = arg->ptr;
    RefCounted* r = arg->ref;

    Inner tmp;
    tmp.a = *(int*)p;
    tmp.b = *(int*)((char*)p + 4);

    if (r != 0) {
        _InterlockedExchangeAdd(&r->refcount, 1);
    }

    sub_49c0c0(&this->inner);

    void* mem = sub_62fef6(0x20);
    if (mem != 0) {
        *(int*)((char*)mem + 4) = 0;
        *(int*)((char*)mem + 8) = 0;
        *(int*)((char*)mem + 0xc) = 0;
        *(int*)((char*)mem + 0x14) = 0;
        *(int*)((char*)mem + 0x18) = 0;
        *(char*)((char*)mem + 0x1c) = 0;
    } else {
        mem = 0;
    }

    sub_4181b0(mem);
    sub_728830(this);
}
