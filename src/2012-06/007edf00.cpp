// from server: 31% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

extern "C" void* __cdecl sub_801040(void*);

struct Inner {
    void** vptr;
    long refcount;
};

struct Obj {
    void* field0;
    Inner* field4;
    long field8;
};

struct S {
    void* field0;
    Obj* field4;
    long field8;
    void ctor(Obj* a, Obj* b, Obj* c, Obj* d);
};

void S::ctor(Obj* a, Obj* b, Obj* c, Obj* d)
{
    Inner* inner = (Inner*)d;
    if (inner)
        _InterlockedExchangeAdd(&inner->refcount, 1);

    void* r = sub_801040((void*)0xdd44f4);
    this->field0 = (r != 0) ? (void*)0xdd44f4 : 0;

    if (inner)
    {
        if (_InterlockedExchangeAdd(&inner->refcount, -1) == 1)
        {
            ((void (__thiscall*)(Inner*))inner->vptr[1])(inner);
            if (_InterlockedExchangeAdd(&inner->refcount, -1) == 1)
                ((void (__thiscall*)(Inner*))inner->vptr[2])(inner);
        }
    }
}
