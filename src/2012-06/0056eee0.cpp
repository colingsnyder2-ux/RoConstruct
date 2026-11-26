// from server: 100% by Xemicl
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// RBX::Network::IdSerializer::serializeRef, standalone with the 2012-06 layout:
// RefPropertyDescriptor::getRefValue is vtable slot 12 and DescribedBase sits at Instance+0x1c.
struct BitStream;
struct Base0 { virtual ~Base0(); char pad[0x18]; };
struct DescribedBase { virtual ~DescribedBase(); };
struct Instance : Base0, DescribedBase {};
struct PropertyDescriptor {
    virtual void v0(); virtual void v1(); virtual void v2(); virtual void v3();
    virtual void v4(); virtual void v5(); virtual void v6(); virtual void v7();
    virtual void v8(); virtual void v9(); virtual void v10(); virtual void v11();
};
struct RefPropertyDescriptor : PropertyDescriptor {
    virtual DescribedBase* getRefValue(const DescribedBase* instance) const = 0;
};
class ConstProperty {
    const PropertyDescriptor* descriptor; const DescribedBase* instance;
public:
    const PropertyDescriptor& getDescriptor() const { return *descriptor; }
    const DescribedBase* getInstance() const { return instance; }
};
struct IdSerializer {
    void serializeId(BitStream& stream, const Instance* instance);
    void serializeRef(const ConstProperty& property, BitStream& stream);
};
void IdSerializer::serializeRef(const ConstProperty& property, BitStream& bitStream)
{
    const RefPropertyDescriptor& prop = static_cast<const RefPropertyDescriptor&>(property.getDescriptor());
    serializeId(bitStream, (Instance*)prop.getRefValue(property.getInstance()));
}