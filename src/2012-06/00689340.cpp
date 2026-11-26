// from server: 100% by Xemicl
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
namespace G3D { struct CoordinateFrame { float rotation[9]; float translation[3]; }; }
struct GetSet {
    virtual void slot0();
    virtual void slot1();
    virtual G3D::CoordinateFrame getValue(const void* instance) const;
};
struct Any { void assign(const G3D::CoordinateFrame& v); };
const void* typeSingleton();
struct Variant {
    const void* type;
    Any value;
    void set(const G3D::CoordinateFrame& v);
};
inline void Variant::set(const G3D::CoordinateFrame& v) { type = typeSingleton(); value.assign(v); }
struct TypedPropertyDescriptor {
    char pad[0x28];
    GetSet* getset;
    void getVariant(const void* instance, Variant& out) const;
};
void TypedPropertyDescriptor::getVariant(const void* instance, Variant& out) const { out.set(getset->getValue(instance)); }