// from server: 100% by tajop
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD

#include <string>

class DescribedBase;

class XmlNameValuePair
{
public:
    const void* name;
    int valueType;
    std::string* stringValue;
    void setValue(std::string value);
};

class XmlNodeLinks
{
    char pad0[0x10];
};

class XmlElement : public XmlNodeLinks, public XmlNameValuePair
{
};

class StringPropertyDescriptor
{
public:
    std::string getValue(const DescribedBase* object) const;
    void writeValue(const DescribedBase* instance, XmlElement* element) const;
};

void StringPropertyDescriptor::writeValue(const DescribedBase* instance, XmlElement* element) const
{
    element->setValue(getValue(instance));
}
