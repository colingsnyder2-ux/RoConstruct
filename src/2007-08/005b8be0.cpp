// from server: 44% by colin
struct DescribedBase;
struct Variant;

struct EnumPropertyDescriptor {
    void* vtable;
    char pad[0x18];
    void* getset;
};

struct SurfaceEnumPropDescriptor : EnumPropertyDescriptor {
    void get(const DescribedBase* instance, Variant& value) const;
};

struct GetSet {
    bool isReadOnly() const;
    bool isWriteOnly() const;
    bool getValue(const DescribedBase* instance, Variant& out) const;
    void setValue(DescribedBase* instance, const Variant& value) const;
};

struct Variant {
    char data[0x20];
    Variant();
    ~Variant();
    Variant& operator=(const Variant& other);
};

extern "C" {
    void __stdcall Variant_ctor(Variant* self);
    void __stdcall Variant_dtor(Variant* self);
}

void SurfaceEnumPropDescriptor::get(const DescribedBase* instance, Variant& value) const {
    GetSet* gs = (GetSet*)this->getset;
    if (gs->isReadOnly()) {
        return;
    }
    if (gs->isWriteOnly()) {
        Variant tmp;
        Variant_ctor(&tmp);
        if (gs->getValue(instance, tmp)) {
            value = tmp;
        }
        Variant_dtor(&tmp);
        return;
    }
    Variant tmp;
    Variant_ctor(&tmp);
    if (gs->getValue(instance, tmp)) {
        value = tmp;
    }
    Variant_dtor(&tmp);
}
