// from server: 100% by Intel_Inside
// roc-flags: /O2 /GS- /EHsc /MD

#include <string>

class DescribedBase;
class IReferenceBinder;

class XmlValue {
public:
    bool isString() const;
    bool get(std::string& value) const;
    bool get(int& value) const;
};

class XmlElement {
public:
    bool isXsiNil() const;
    char pad[0xc];
    XmlValue value;
};

template<class T> class EnumDesc {
public:
    static EnumDesc& singleton();
    bool convertToValue(const std::string& text, T& value) const;
};

template<class T> class GetSet {
public:
    virtual T get(const DescribedBase* instance) const = 0;
    virtual bool isReadOnly() const = 0;
    virtual void set(DescribedBase* instance, const T& value) const = 0;
};

enum InputType { NO_INPUT = 0 };

class SurfaceEnumPropDescriptor {
public:
    virtual ~SurfaceEnumPropDescriptor();
    char pad[0x18];
    GetSet<InputType>* getset;
    void readValue(DescribedBase* instance, const XmlElement* element, IReferenceBinder& binder) const;
};

void SurfaceEnumPropDescriptor::readValue(DescribedBase* instance, const XmlElement* element, IReferenceBinder& binder) const
{
    if (element->isXsiNil())
        return;
    const XmlValue& v = element->value;
    if (v.isString()) {
        std::string s;
        if (v.get(s)) {
            InputType value;
            if (EnumDesc<InputType>::singleton().convertToValue(s, value)) {
                getset->set(instance, value);
                return;
            }
        }
    }
    int i;
    if (v.get(i)) {
        InputType value = (InputType)i;
        getset->set(instance, value);
    }
}
