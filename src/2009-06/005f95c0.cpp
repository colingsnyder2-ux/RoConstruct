// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
#include <vector>
namespace RBX { namespace Reflection {
class SignalDescriptor;
template <class T>
class MemberDescriptorContainer
{
public:
	typedef std::vector<T*> Collection;
	typedef std::vector<MemberDescriptorContainer*> DerivedContainers;
	MemberDescriptorContainer(MemberDescriptorContainer* base);
	void mergeMembers(const MemberDescriptorContainer* source);
	Collection descriptors;
	DerivedContainers derivedContainers;
	const MemberDescriptorContainer* base;
};
}}
template<> void std::vector<RBX::Reflection::MemberDescriptorContainer<RBX::Reflection::SignalDescriptor>*>::push_back(RBX::Reflection::MemberDescriptorContainer<RBX::Reflection::SignalDescriptor>* const&);
namespace RBX { namespace Reflection {
template <class T>
MemberDescriptorContainer<T>::MemberDescriptorContainer(MemberDescriptorContainer* base) : base(base)
{
	if (base != NULL) {
		mergeMembers(base);
		base->derivedContainers.push_back(this);
	}
}
template class MemberDescriptorContainer<SignalDescriptor>;
}}
