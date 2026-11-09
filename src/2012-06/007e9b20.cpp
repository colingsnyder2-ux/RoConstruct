// from server: 100% by tajop
struct UDim2 { float xs; int xo; float ys; int yo; };
struct GetSet {
    virtual void slot0();
    virtual void slot1();
    virtual UDim2 getValue(const void* instance) const;
};
struct Any { void assign(const UDim2& v); };
const void* typeSingleton();
struct Variant {
    const void* type;
    Any value;
    void set(const UDim2& v);
};
inline void Variant::set(const UDim2& v) { type = typeSingleton(); value.assign(v); }
struct TypedPropertyDescriptor {
    char pad[0x28];
    GetSet* getset;
    void getVariant(const void* instance, Variant& out) const;
};
void TypedPropertyDescriptor::getVariant(const void* instance, Variant& out) const { out.set(getset->getValue(instance)); }
