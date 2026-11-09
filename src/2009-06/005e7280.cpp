// from server: 100% by EspClaude
// roc 2009-06 005e7280  unit: RBX::Reflection::TypedPropertyDescriptor<BrickColor>::writeValue
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
class XmlValue {
public:
    int head;
    int type;
    int data;
    void clear();
    void setBrickColor(int v) { clear(); data = v; type = 5; }
};
class XmlElement {
public:
    char pad[0x10];
    XmlValue value;
};
namespace RBX {
class BrickColor { public: int number; };
namespace Reflection {
class DescribedBase;
template<class V> class TypedPropertyDescriptor {
public:
    class GetSet {
    public:
        virtual ~GetSet();
        virtual void setValue(DescribedBase*, const V&) const;
        virtual V getValue(const DescribedBase* object) const = 0;
    };
    virtual ~TypedPropertyDescriptor();
    virtual void writeValue(const DescribedBase* instance, XmlElement* element) const;
    char pad[0x14];
    GetSet* getset;  // 0x18
};
template<>
void TypedPropertyDescriptor<BrickColor>::writeValue(const DescribedBase* instance, XmlElement* element) const
{
    BrickColor value = getset->getValue(instance);
    element->value.setBrickColor(value.number);
}
}
}
