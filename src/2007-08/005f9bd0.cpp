// from server: 30% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct RefCounted {
    void* vptr;
    long refcount;
};

struct Arg {
    void* vptr;
    void* data;
};

struct Descriptor {
    void* vptr;
};

struct FuncDesc {
    char pad[0x28];
    void* funcPtr;
    void* arg0;
    void* arg1;
    void* arg2;
    void* arg3;
};

struct Args {
    void* vptr;
    void addArg(int index, void* value);
};

struct BoundFuncDesc {
    char pad[0x28];
    void* funcPtr;
    void* arg0;
    void* arg1;
    void* arg2;
    void* arg3;
    void invoke(Args* args);
};

extern "C" void* __cdecl sub_630D36(void* a, void* b, void* c, void* d, void* e);
extern "C" void __cdecl sub_630B9E(void* a, void* b);
extern "C" void* __cdecl sub_56F210(void* a);
extern "C" void* __cdecl sub_56FA60(void* a, double b);
extern "C" void __cdecl sub_77E710(void* a);

void BoundFuncDesc::invoke(Args* args)
{
    void* a0 = this->arg0;
    void* a1 = this->arg1;
    void* a2 = this->arg2;
    void* a3 = this->arg3;

    args->addArg(1, &a0);
    args->addArg(2, &a1);

    void* result = sub_630D36(a2, (void*)0x88209C, (void*)0x8B3DEC, 0, 0);
    if (!result) {
        sub_77E710((void*)0x786E04);
        sub_630B9E((void*)0x841E0C, (void*)0x786E04);
    }

    void* d = sub_56F210(&a3);
    double val = *(double*)d;
    void* obj = sub_56FA60(&a3, val);

    void* vptr = *(void**)obj;
    void* ref = *(void**)((char*)obj + 4);
    if (ref) {
        _InterlockedExchangeAdd((volatile long*)((char*)ref + 4), 1);
    }

    void* fn = this->funcPtr;
    void* self = (char*)this + 0x28;
    ((void (__thiscall*)(void*, void*))fn)(self, obj);

    if (a1) {
        void* v = *(void**)a1;
        ((void (__thiscall*)(void*, int))v)(a1, 1);
    }
    if (a0) {
        void* v = *(void**)a0;
        ((void (__thiscall*)(void*, int))v)(a0, 1);
    }
}
