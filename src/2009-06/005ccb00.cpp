// from server: 100% by EspClaude
// roc 2009-06 005ccb00  unit: VCRenderSettingsItem::?$EnumPropDescriptor  size: 48 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 005ccb00
//
// 005ccb00  8b491c               mov ecx, dword ptr [ecx + 0x1c]
// 005ccb03  8b01                 mov eax, dword ptr [ecx]
// 005ccb05  8b542404             mov edx, dword ptr [esp + 4]
// 005ccb09  8b4008               mov eax, dword ptr [eax + 8]
// 005ccb0c  56                   push esi
// 005ccb0d  57                   push edi
// 005ccb0e  52                   push edx
// 005ccb0f  ffd0                 call eax
// 005ccb11  8b742410             mov esi, dword ptr [esp + 0x10]
// 005ccb15  83c610               add esi, 0x10
// 005ccb18  8bce                 mov ecx, esi
// 005ccb1a  8bf8                 mov edi, eax
// 005ccb1c  e8afcf0300           call 0x609ad0
// 005ccb21  897e08               mov dword ptr [esi + 8], edi
// 005ccb24  5f                   pop edi
// 005ccb25  c7460405000000       mov dword ptr [esi + 4], 5
// 005ccb2c  5e                   pop esi
// 005ccb2d  c20800               ret 8
// copied from an identical function in another client (function ?writeValue@?$EnumPropDescriptor@VFaceInstance@RBX@@W4NormalId@2@@Reflection@RBX@@UBEXPBVDescribedBase@23@PAVXmlElement@@@Z)

#include <memory>
#include <string>

namespace RBX {
class Name;
class ContentId;
class BrickColor
{
    int number;
public:
    int asInt() const { return number; }
    bool operator==(const BrickColor& other) const { return number == other.number; }
};
namespace Reflection {
class DescribedBase;
class IReferenceBinder;
}
}

class XmlNameValuePair
{
public:
    enum ValueType { NONE, HANDLE, NAME, BOOL, FLOAT, INT, UINT, CONTENTID, STRING };

private:
    const RBX::Name& tag;
    ValueType valueType;
    union
    {
        bool boolValue;
        float floatValue;
        int intValue;
        unsigned uintValue;
        std::string* stringValue;
    };

    void clearValue();

public:
    bool getValue(int&) const;
    bool getValue(std::string& value) const;

    void setValue(int value)
    {
        clearValue();
        intValue = value;
        valueType = INT;
    }
    void setValue(std::string value);
};

class XmlNode
{
    void* links[4];
};

class XmlElement : public XmlNode, public XmlNameValuePair
{
public:
    bool isXsiNil() const;
};

namespace RBX {
namespace Reflection {
class PropertyDescriptor
{
    char data[0x14];
public:
    virtual ~PropertyDescriptor();
    virtual bool equalValues(const DescribedBase* a, const DescribedBase* b) const = 0;
    virtual void readValue(DescribedBase* instance, const XmlElement* element, IReferenceBinder& binder) const = 0;
    virtual void writeValue(const DescribedBase* instance, XmlElement* element) const = 0;
};

template<typename PropType>
class TypedPropertyDescriptor : public PropertyDescriptor
{
public:
    class GetSet
    {
    public:
        virtual ~GetSet();
        virtual bool isReadOnly() const = 0;
        virtual PropType getValue(const DescribedBase* object) const = 0;
        virtual void setValue(DescribedBase* object, const PropType& value) const = 0;
    };

protected:
    std::auto_ptr<GetSet> getset;

public:
    PropType getValue(const DescribedBase* object) const
    {
        return getset->getValue(object);
    }
    void setValue(DescribedBase* object, const PropType& value) const
    {
        getset->setValue(object, value);
    }
    virtual bool equalValues(const DescribedBase* a, const DescribedBase* b) const
    {
        return getValue(b) == getValue(a);
    }

private:
    virtual void readValue(DescribedBase* instance, const XmlElement* element, IReferenceBinder& binder) const;
    virtual void writeValue(const DescribedBase* instance, XmlElement* element) const;
};
}
}

namespace RBX {
namespace Reflection {
class EnumDescriptor;

class EnumPropertyDescriptor : public PropertyDescriptor
{
protected:
    const EnumDescriptor& enumDescriptor;
};

template<class Class, typename Enum>
class EnumPropDescriptor : public EnumPropertyDescriptor
{
private:
    std::auto_ptr<typename TypedPropertyDescriptor<Enum>::GetSet> getset;

public:
    Enum getValue(const DescribedBase* object) const
    {
        return getset->getValue(object);
    }
    virtual bool equalValues(const DescribedBase* a, const DescribedBase* b) const
    {
        return getValue(a) == getValue(b);
    }
    virtual void readValue(DescribedBase* instance, const XmlElement* element, IReferenceBinder& binder) const;
    virtual void writeValue(const DescribedBase* instance, XmlElement* element) const
    {
        element->setValue(getValue(instance));
    }
};
}

class FaceInstance;
enum NormalId { NORM_X, NORM_Y, NORM_Z, NORM_X_NEG, NORM_Y_NEG, NORM_Z_NEG };
}
template void RBX::Reflection::EnumPropDescriptor<RBX::FaceInstance, RBX::NormalId>::writeValue(const RBX::Reflection::DescribedBase*, XmlElement*) const;