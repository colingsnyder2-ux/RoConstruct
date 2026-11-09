// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
class XmlNameValuePair {
public:
    bool getValue(int& value) const;
};
class XmlBases { public: int s[4]; };
class XmlElement : public XmlBases, public XmlNameValuePair {
public:
    bool isXsiNil() const;
};
namespace RBX {
class BrickColor {
public:
    BrickColor(int number);
    int number;
};
namespace Reflection {
class DescribedBase;
class IReferenceBinder;
template<class T> class TypedPropertyDescriptor {
public:
    class GetSet {
    public:
        virtual bool isReadOnly() const = 0;
        virtual bool isWriteOnly() const = 0;
        virtual T getValue(const DescribedBase* object) const = 0;
        virtual void setValue(DescribedBase* object, const T& value) const = 0;
    };
private:
    virtual void readValue(DescribedBase* instance, const XmlElement* element, IReferenceBinder& binder) const;
public:
    char pad[0x14];
    GetSet* getset;
    void setValue(DescribedBase* instance, const T& value) const { getset->setValue(instance, value); }
};
template<>
void TypedPropertyDescriptor<BrickColor>::readValue(DescribedBase* instance, const XmlElement* element, IReferenceBinder& binder) const
{
    if (!element->isXsiNil())
    {
        int value;
        if (element->getValue(value))
        {
            setValue(instance, BrickColor(value));
        }
    }
}
}
}
