// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace std {
class string {
public:
    string(const string&);
    ~string();
    char buf[0x1c];
};
}
class XmlNameValuePair {
public:
    void setValue(std::string value);
    int a, b;
};
class XmlBases { public: int s[4]; };
class XmlElement : public XmlBases, public XmlNameValuePair {
};
namespace RBX {
class DescribedBase;
namespace Reflection {
template<class T> class TypedPropertyDescriptor {
public:
    virtual void writeValue(const DescribedBase* instance, XmlElement* element) const;
    T getValue(const DescribedBase* instance) const;
};
template<>
void TypedPropertyDescriptor<std::string>::writeValue(const DescribedBase* instance, XmlElement* element) const
{
    element->setValue(getValue(instance));
}
}
}
