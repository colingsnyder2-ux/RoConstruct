// from server: 100% by EspClaude
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
#include <string>
namespace RBX {
class Name {
public:
    int dictionaryIndex;
    std::string name;
    const std::string& toString() const { return name; }
};
namespace Reflection {
class Descriptor {
public:
    virtual ~Descriptor() {}
    const Name& name;
};
class ClassDescriptor : public Descriptor {};
class MemberDescriptor : public Descriptor {
public:
    int category;
    const ClassDescriptor& owner;
};
}
}
class Reporter {
public:
    std::string describe(const RBX::Reflection::MemberDescriptor* desc);
};

std::string Reporter::describe(const RBX::Reflection::MemberDescriptor* desc)
{
    return desc->owner.name.toString() + ":" + desc->name.toString();
}
