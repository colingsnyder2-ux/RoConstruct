// from server: 100% by tajop
struct Obj_005dc2a0 {
    bool func_005dc2a0();
};

extern "C" Obj_005dc2a0* __stdcall func_005b7ee0(const void* v, const void** out);

struct GetSet {
    virtual void v0();
    virtual void v1();
    virtual void getValue(const void* instance, const void** value);
};

struct SurfaceEnumPropDescriptor {
    char pad[0x1c];
    GetSet* getset;
    bool equalValues(const void* a, const void* b) const;
};

bool SurfaceEnumPropDescriptor::equalValues(const void* a, const void* b) const
{
    if (func_005b7ee0(b, &b)->func_005dc2a0()) {
        getset->getValue(a, &b);
        return true;
    }
    return false;
}
