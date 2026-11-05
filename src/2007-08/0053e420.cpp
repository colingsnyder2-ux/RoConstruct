// from server: 29% by TrollStein
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct RefCounted {
    long refcount;
};

struct GetSet {
    void* vptr;
};

struct BoundPropGetSet {
    void* vptr;
    void* desc;
    int member;
    int changed;
};

struct BoundProp {
    char pad[0x44];
    BoundPropGetSet* getset;
};

struct TypedPropertyDescriptor {
    void* vptr;
};

struct PropertyDescriptor {
    void* vptr;
};

struct DescribedBase {
    void* vptr;
};

struct BoundPropGetSetCtor {
    BoundPropGetSet* __cdecl construct(BoundProp* desc, int member, int changed);
};

BoundPropGetSet* BoundPropGetSetCtor::construct(BoundProp* desc, int member, int changed)
{
    BoundPropGetSet* self = (BoundPropGetSet*)this;
    if (self)
        self = (BoundPropGetSet*)((char*)self - 0x44);

    void* args[4];
    args[0] = desc;
    args[1] = (void*)member;
    if (member)
        _InterlockedExchangeAdd((volatile long*)(member + 4), 1);
    args[2] = (void*)changed;
    args[3] = (void*)changed;
    if (changed)
        _InterlockedExchangeAdd((volatile long*)(changed + 4), 1);

    void** vtbl = *(void***)changed;
    void (*fn)(void*) = (void (*)(void*))vtbl[0];
    fn(self);

    return self;
}
