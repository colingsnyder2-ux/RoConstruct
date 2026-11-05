// from server: 34% by atomic.potato
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct RefCounted {
    void** vptr;
    volatile long ref1;
    volatile long ref2;
};

struct VVisitBoundFuncDesc {
    char pad0[8];
    void* ptr8;
    void* ptrC;
    int ctor(void* a, void* b, void* c, void* d, void* e, void* f);
};

int VVisitBoundFuncDesc::ctor(void* a, void* b, void* c, void* d, void* e, void* f) {
    RefCounted* p1 = (RefCounted*)e;
    RefCounted* p2 = (RefCounted*)f;
    if (p1) {
        _InterlockedExchangeAdd(&p1->ref1, 1);
    }
    ((void (__thiscall*)(void*, void*, void*))0x63ff30)(this, a, b);
    this->ptr8 = c;
    this->ptrC = d;
    if (p2) {
        _InterlockedExchangeAdd(&p2->ref1, 1);
    }
    if (p1) {
        if (_InterlockedExchangeAdd(&p1->ref1, -1) == 1) {
            ((void (__thiscall*)(void*))p1->vptr[1])(p1);
            if (_InterlockedExchangeAdd(&p1->ref2, -1) == 1) {
                ((void (__thiscall*)(void*))p1->vptr[2])(p1);
            }
        }
    }
    if (p2) {
        if (_InterlockedExchangeAdd(&p2->ref1, -1) == 1) {
            ((void (__thiscall*)(void*))p2->vptr[1])(p2);
            if (_InterlockedExchangeAdd(&p2->ref2, -1) == 1) {
                ((void (__thiscall*)(void*))p2->vptr[2])(p2);
            }
        }
    }
    return (int)this;
}
