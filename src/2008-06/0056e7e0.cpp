// from server: 100% by colin
class XmlElement {
public:
    bool isXsiNil() const;
};

namespace RBX {
class DescribedBase;
namespace Reflection {
class IReferenceBinder;

struct GetSet {
    virtual ~GetSet();
    virtual bool isReadOnly() const;
    virtual bool getValue() const;
    virtual void setValue(DescribedBase*, const int&);
};

template<typename T>
class TypedPropertyDescriptor {
public:
    virtual void readValue(DescribedBase*, const XmlElement*, IReferenceBinder&) const;
};

struct XmlValueBase {
    bool getValue(int&) const;
};

template<>
void TypedPropertyDescriptor<int>::readValue(DescribedBase* instance, const XmlElement* element, IReferenceBinder& binder) const
{
    if (!element->isXsiNil())
    {
        int value;
        const XmlValueBase* vb = reinterpret_cast<const XmlValueBase*>(reinterpret_cast<const char*>(element) + 0x10);
        if (vb->getValue(value))
        {
            GetSet* gs = *reinterpret_cast<GetSet**>(const_cast<char*>(reinterpret_cast<const char*>(this)) + 0x18);
            gs->setValue(instance, value);
        }
    }
}
}
}

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD