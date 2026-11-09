// from server: 100% by tajop
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD

class DescribedBase;
class IReferenceBinder;

class BrickColor
{
public:
    int number;
    BrickColor(int number);
    int asInt() const { return number; }
};

class XmlNameValuePair
{
public:
    const void* name;
    int valueType;
    int intValue;
    bool getValue(int&) const;
};

class XmlElement
{
    char pad0[0x10];
    XmlNameValuePair data;
public:
    bool isXsiNil() const;
    bool getValue(int& value) const
    {
        return data.getValue(value);
    }
};

class GetSet
{
public:
    virtual bool isReadOnly() const = 0;
    virtual bool isWriteable() const = 0;
    virtual BrickColor getValue(const DescribedBase*) const = 0;
    virtual void setValue(DescribedBase*, const BrickColor&) const = 0;
};

class BrickColorPropertyDescriptor
{
    char pad0[0x28];
    GetSet* getset;
public:
    void setValue(DescribedBase* object, const BrickColor& value) const
    {
        getset->setValue(object, value);
    }
    void readValue(DescribedBase* instance, const XmlElement* element, IReferenceBinder& binder) const;
};

void BrickColorPropertyDescriptor::readValue(DescribedBase* instance, const XmlElement* element, IReferenceBinder& binder) const
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
