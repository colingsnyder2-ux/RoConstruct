// from server: 100% by EspClaude
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
namespace RBX {
class Name;
namespace Reflection {
class SignalDescriptor;
class DescribedBase;
struct CIter { void* cont; void* ptr; };
template<class D> class MemberDescriptorContainer {
public:
    class Iterator {
        DescribedBase* instance;
        CIter iter;
    public:
        Iterator(const CIter& iter, DescribedBase* instance) : instance(instance), iter(iter) {}
    };
    CIter findDescriptor(const Name& name) const;
    Iterator findMember(const Name& name, DescribedBase* instance) const
    {
        return Iterator(findDescriptor(name), instance);
    }
};
class ClassDescriptor {
public:
    char pad[0x3c];
    MemberDescriptorContainer<SignalDescriptor> signals;
};
class DescribedBase {
public:
    virtual ~DescribedBase();
    const ClassDescriptor* descriptor;
    const ClassDescriptor& getDescriptor() const { return *descriptor; }
    MemberDescriptorContainer<SignalDescriptor>::Iterator findSignal(const Name& name);
};
MemberDescriptorContainer<SignalDescriptor>::Iterator DescribedBase::findSignal(const Name& name)
{
    return getDescriptor().signals.findMember(name, this);
}
}}
