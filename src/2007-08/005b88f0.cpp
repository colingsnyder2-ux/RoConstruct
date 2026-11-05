// from server: 100% by tajop
struct Obj_005b80d0 {
    bool func_005b80d0();
};

extern "C" Obj_005b80d0* __stdcall func_005b7e80(const void* v, const void** out);

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
    if (func_005b7e80(b, &b)->func_005b80d0()) {
        getset->getValue(a, &b);
        return true;
    }
    return false;
}
