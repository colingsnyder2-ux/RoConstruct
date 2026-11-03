// from server: 100% by EspClaude
// roc 2007-08 00580e90  RBX::Accoutrement::readProperty (rbxgs v8datamodel/Accoutrement.cpp), self-contained
#include <string>

namespace RBX {
class Name {
    int id;
    std::string name;
public:
    const std::string& toString() const { return name; }
    bool operator==(const char* s) const { return name == s; }
};
class XmlValue {
public:
    bool getValue(const Name*& value) const;
};
class XmlAttribute {
    void* tag;
    XmlValue value;
public:
    bool getValue(const Name*& v) const { return value.getValue(v); }
};
class XmlElement {
public:
    const XmlAttribute* findAttribute(const Name& tag) const;
};
extern const Name& name_name;
class IReferenceBinder;

class Instance {
protected:
    virtual void readProperty(const XmlElement* propertyElement, IReferenceBinder& binder);
};
class Accoutrement : public Instance {
protected:
    virtual void readProperty(const XmlElement* propertyElement, IReferenceBinder& binder);
};

void Accoutrement::readProperty(const XmlElement* propertyElement, IReferenceBinder& binder)
{
    const Name* name = NULL;

    if (const XmlAttribute* attrib = propertyElement->findAttribute(name_name))
    {
        if (attrib->getValue(name))
        {
            if (*name == "BackendAccoutrementState")
                return;
        }
    }

    Instance::readProperty(propertyElement, binder);
}
}
