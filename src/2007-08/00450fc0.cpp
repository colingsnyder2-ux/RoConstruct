// from server: 25% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct RefCounted {
    void* vptr;
    long ref1;
    long ref2;
};

struct Inner {
    void* vptr;
    RefCounted* ptr;
};

struct Outer {
    char pad[0xc];
    void* field_c;

    char func_00450fc0();
};

extern "C" void* __cdecl func_00403830(void* out, void* arg);
extern "C" void __cdecl func_0040d550(void* p);
extern "C" void* __cdecl func_0040e750(void* p);
extern "C" char __cdecl func_00491980(void* p);
extern "C" void __cdecl func_005595a0(void* p);

char Outer::func_00450fc0()
{
    Inner inner;
    void* tmp;
    RefCounted* rc;
    char result;

    func_00403830(&tmp, this->field_c);
    inner.vptr = *(void**)tmp;
    inner.ptr = *(RefCounted**)((char*)tmp + 4);
    if (inner.ptr)
        _InterlockedExchangeAdd(&inner.ptr->ref1, 1);

    func_0040d550(&inner);

    rc = inner.ptr;
    if (rc) {
        if (_InterlockedExchangeAdd(&rc->ref1, -1) == 1) {
            (*(void(__thiscall**)(RefCounted*))(*(void***)rc)[1])(rc);
            if (_InterlockedExchangeAdd(&rc->ref2, -1) == 1)
                (*(void(__thiscall**)(RefCounted*))(*(void***)rc)[2])(rc);
        }
    }

    func_00403830(&tmp, this->field_c);
    result = func_00491980(func_0040e750(*(void**)tmp));

    if (inner.ptr) {
        RefCounted* r = inner.ptr;
        if (_InterlockedExchangeAdd(&r->ref1, -1) == 1) {
            (*(void(__thiscall**)(RefCounted*))(*(void***)r)[1])(r);
            if (_InterlockedExchangeAdd(&r->ref2, -1) == 1)
                (*(void(__thiscall**)(RefCounted*))(*(void***)r)[2])(r);
        }
    }

    func_005595a0(&inner);
    return result;
}
