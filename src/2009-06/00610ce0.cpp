// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace RBX {
class Name { public: static const Name& declare(const char* s); };
extern bool descriptorHookEnabled;
void descriptorHook();
namespace Reflection {
class ClassDescriptor;
class Descriptor {
public:
    const Name& name;
    Descriptor(const char* n) : name(Name::declare(n))
    {
        if (descriptorHookEnabled)
            descriptorHook();
    }
    virtual ~Descriptor();
};
extern ClassDescriptor ownerDescriptor;
class MemberDescriptor : public Descriptor {
public:
    const ClassDescriptor& owner;
    const Name& category;
    bool flagA;
    bool flagB;
    MemberDescriptor(const char* name, const char* category, int unused);
    virtual ~MemberDescriptor();
};
MemberDescriptor::MemberDescriptor(const char* name, const char* cat, int)
    : Descriptor(name), owner(ownerDescriptor), category(Name::declare(cat)), flagA(false), flagB(false)
{
}
}
}
