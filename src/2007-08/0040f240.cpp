// from server: 51% by colin
extern "C" long __cdecl _InterlockedExchangeAdd(volatile long*, long);
#pragma intrinsic(_InterlockedExchangeAdd)

struct RBXNameRef {
    void* ptr;
};

struct RefCounted {
    void* vfptr;
    volatile long refCount;
    volatile long weakRefCount;
};

struct CreatorBase {
    void* vfptr;
};

struct FactoryProductCreator {
    void* vfptr;
};

struct CreatorHolder {
    void* ptr;
    RefCounted* ref;
};

extern "C" void __cdecl sub_40EFD0(CreatorHolder* out, void* name);
extern "C" void __cdecl sub_55D3D0();

struct VCRenderSettings_FactoryProduct_Creator {
    void* vfptr;
    void* field4;
    CreatorHolder* getCreators();
    void destroy();
    void* construct(CreatorHolder* out);
};

void* VCRenderSettings_FactoryProduct_Creator::construct(CreatorHolder* out) {
    CreatorHolder local;
    local.ptr = 0;
    local.ref = 0;
    sub_40EFD0(&local, this);
    out->ptr = local.ptr;
    RefCounted* r = local.ref;
    out->ref = r;
    if (r) {
        _InterlockedExchangeAdd(&r->refCount, 1);
    }
    RefCounted* old = local.ref;
    if (old) {
        if (_InterlockedExchangeAdd(&old->refCount, -1) == 1) {
            void** vt = *(void***)old;
            typedef void (__thiscall *Fn)(RefCounted*);
            ((Fn)vt[1])(old);
            if (_InterlockedExchangeAdd(&old->weakRefCount, -1) == 1) {
                void** vt2 = *(void***)old;
                ((Fn)vt2[2])(old);
            }
        }
    }
    return out;
}
