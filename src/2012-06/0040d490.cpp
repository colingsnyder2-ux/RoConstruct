// from server: 100% by tajop
// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD

// Accessor at +0x28; vtable slot 2 reads a bool from an instance.
struct Accessor {
    virtual void slot0();
    virtual void slot1();
    virtual bool get(const void* instance) const;
};

struct BoolDescriptor {
    char pad[0x28];
    Accessor* accessor;
    bool getValue(const void* instance) const { return accessor->get(instance); }
    bool equalValues(const void* a, const void* b) const;
};

bool BoolDescriptor::equalValues(const void* a, const void* b) const
{
    bool va = getValue(a);
    return va == getValue(b);
}