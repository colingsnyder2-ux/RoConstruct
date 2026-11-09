// from server: 100% by tajop
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD

class DescribedBase;

class BrickColor
{
public:
    int number;
    BrickColor(int number);
    int asInt() const { return number; }
};

class XmlValue
{
public:
    void* vtbl;
    int type;
    int value;
    void clear();
    void set(int v)
    {
        clear();
        value = v;
        type = 5;
    }
};

class XmlElement
{
    char pad0[0x10];
    XmlValue data;
public:
    void setValue(int v)
    {
        data.set(v);
    }
};

class GetSet
{
public:
    virtual bool isReadOnly() const = 0;
    virtual bool isWriteable() const = 0;
    virtual BrickColor getValue(const DescribedBase*) const = 0;
};

class BrickColorPropertyDescriptor
{
    char pad0[0x28];
    GetSet* getset;
public:
    BrickColor getValue(const DescribedBase* object) const
    {
        return getset->getValue(object);
    }
    void writeValue(const DescribedBase* instance, XmlElement* element) const;
};

void BrickColorPropertyDescriptor::writeValue(const DescribedBase* instance, XmlElement* element) const
{
    element->setValue(getValue(instance).asInt());
}
