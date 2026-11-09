// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
#include <vector>
namespace RBX { namespace Reflection {
class DescribedBase;
enum Enum { E0 };
class EnumDescriptor {
public:
    char pad[0x2c];
    unsigned int enumCount;
    char pad2[0xbc - 0x30];
    std::vector<Enum> allValues;
    __forceinline bool convertToValue(unsigned int index, Enum& value) const
    {
        if (index < enumCount) {
            value = allValues[index];
            return true;
        }
        return false;
    }
};
class GetSet {
public:
    virtual void a();
    virtual void b();
    virtual void c();
    virtual void set(DescribedBase* instance, const Enum& value) const;
};
class EnumPropDescriptor {
public:
    virtual bool setIndexValue(DescribedBase* instance, unsigned index) const;
    char pad[0x18];
    GetSet* getset;
    const EnumDescriptor* enumDescriptor;
    void setValue(DescribedBase* instance, Enum value) const { getset->set(instance, value); }
};
bool EnumPropDescriptor::setIndexValue(DescribedBase* instance, unsigned index) const
{
    Enum val;
    if (enumDescriptor->convertToValue(index, val)) {
        setValue(instance, val);
        return true;
    }
    return false;
}
}}
