// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace G3D { class Vector3 { public: float x, y, z; }; }
namespace RBX { class Name; }
extern const RBX::Name& tag_X;
extern const RBX::Name& tag_Y;
extern const RBX::Name& tag_Z;
namespace RBX {
template<class T> class Sibling {
public:
    T* next;
    Sibling() : next(0) {}
    T* nextSibling() const { return next; }
};
template<class T> class Parent {
public:
    T* first;
    T* last;
    Parent() : first(0), last(0) {}
    void pushBackChild(T* child)
    {
        if (!last)
            first = child;
        else
            last->next = child;
        last = child;
    }
};
}
class XmlNameValuePair
{
public:
    enum ValueType { NONE = 0, STRING, CONTENTID, BOOL, INT, UINT, NAME, FLOAT };
    XmlNameValuePair(const RBX::Name& tag) : tag(tag), valueType(NONE) {}
    const RBX::Name& tag;
    mutable ValueType valueType;
    union {
        void* stringValue;
        mutable float floatValue;
        mutable int intValue;
        mutable double doubleValue;
    };
    void clearValue() const;
    void setValue(float value)
    {
        clearValue();
        floatValue = value;
        valueType = FLOAT;
    }
};
class XmlAttribute;
class XmlElement : public RBX::Sibling<XmlElement>, public RBX::Parent<XmlElement>, public XmlNameValuePair
{
    RBX::Parent<XmlAttribute> attributes;
public:
    XmlElement(const RBX::Name& tag) : XmlNameValuePair(tag) {}
};
namespace RBX { namespace Reflection {
class DescribedBase;
class PropertyDescriptor {
public:
    virtual ~PropertyDescriptor();
    char pad[0x14];
};
template<class PropType>
class TypedPropertyDescriptor : public PropertyDescriptor
{
public:
    class GetSet {
    public:
        virtual ~GetSet();
        virtual bool isReadOnly() const = 0;
        virtual PropType getValue(const DescribedBase*) const = 0;
    };
    GetSet* getset;
    PropType getValue(const DescribedBase* object) const { return getset->getValue(object); }
    virtual void writeValue(const DescribedBase* instance, XmlElement* element) const;
};
template<>
void TypedPropertyDescriptor<G3D::Vector3>::writeValue(const DescribedBase* instance, XmlElement* element) const
{
    const Name* xName = &tag_X;
    XmlElement* xElement = new XmlElement(*xName);
    element->pushBackChild(xElement);

    const Name* yName = &tag_Y;
    XmlElement* yElement = new XmlElement(*yName);
    element->pushBackChild(yElement);

    const Name* zName = &tag_Z;
    XmlElement* zElement = new XmlElement(*zName);
    element->pushBackChild(zElement);

    G3D::Vector3 value = getValue(instance);

    xElement->setValue(value.x);
    yElement->setValue(value.y);
    zElement->setValue(value.z);
}
}}
