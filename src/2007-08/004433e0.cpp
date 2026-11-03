// from server: 83% by EspClaude
// roc 2007-08 004433e0  Reflection::Metadata lookup of an event's metadata instance
// roc-flags: /O2 /GS /EHsc /MD
#include <string>
namespace RBX {
class Name {
    int id;
    std::string name;
public:
    const std::string& toString() const { return name; }
};
class Instance {
public:
    virtual ~Instance();
    Instance* findFirstChildByName(const std::string& name) const;
    template<class T> T* findFirstChildOfType() const;
};
namespace Reflection {
class Descriptor {
public:
    virtual ~Descriptor();
    const Name& name;
};
class ClassDescriptor : public Descriptor {};
class MemberDescriptor : public Descriptor {
public:
    const Name& category;
    const ClassDescriptor& owner;
};
class PropertyDescriptor : public MemberDescriptor {};
class EventDescriptor : public MemberDescriptor {};
class FunctionDescriptor : public MemberDescriptor {};
namespace Metadata {
class Classes : public Instance {};
class Properties : public Instance {};
class Events : public Instance {};
class Functions : public Instance {};
class Reflection {
    char pad[0xe8];
    Classes* classes;  // exe +0xe8
public:
    template<class Members, class Desc> Instance* findMember(const Desc& desc) const
    {
        Instance* c = classes ? classes->findFirstChildByName(desc.owner.name.toString()) : 0;
        if (c)
            if (Members* m = c->findFirstChildOfType<Members>())
                return m->findFirstChildByName(desc.name.toString());
        return 0;
    }
    Instance* get(const PropertyDescriptor& desc) const;
};
}}}
template RBX::Instance* RBX::Reflection::Metadata::Reflection::findMember<RBX::Reflection::Metadata::Events, RBX::Reflection::EventDescriptor>(const RBX::Reflection::EventDescriptor&) const;
