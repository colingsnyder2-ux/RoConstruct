// from server: 100% by colin
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: openrbx-client App/reflection/reflection_object.cpp

// Candidate translation unit (score above; library headers required).
#include "reflection/reflection.h"

namespace RBX {
namespace Reflection {

// GLOBAL: WEBSERVICE 0x102f59a1
bool ClassDescriptor::lockedDown;

// FUNCTION: WEBSERVICE 0x10047430
bool ClassDescriptor::operator==(const ClassDescriptor& other) const
{
	return this == &other;
}

// FUNCTION: WEBSERVICE 0x10047800
ClassDescriptor::ClassDescriptor()
	: Descriptor("<<<ROOT>>>"), MemberDescriptorContainer<PropertyDescriptor>(NULL),
	  MemberDescriptorContainer<SignalDescriptor>(NULL), MemberDescriptorContainer<FunctionDescriptor>(NULL), base(NULL)
{
}

// FUNCTION: WEBSERVICE 0x100478c0
ClassDescriptor::ClassDescriptor(ClassDescriptor& base, const char* name)
	: Descriptor(name), MemberDescriptorContainer<PropertyDescriptor>(&base),
	  MemberDescriptorContainer<SignalDescriptor>(&base), MemberDescriptorContainer<FunctionDescriptor>(&base),
	  base(&base)
{
	boost::recursive_mutex::scoped_lock lock(sync());

	base.derivedClasses.push_back(this);
}

// FUNCTION: WEBSERVICE 0x100479c0
bool MemberDescriptor::isMemberOf(const ClassDescriptor& classDescriptor) const
{
	const ClassDescriptor* c = &classDescriptor;

	do {
		if (c == &owner) {
			return true;
		}
	} while ((c = c->getBase()) != &ClassDescriptor::rootDescriptor());

	return false;
}

// FUNCTION: WEBSERVICE 0x10047a60
bool MemberDescriptor::isMemberOf(const DescribedBase* instance) const
{
	return isMemberOf(instance->getDescriptor());
}

} // namespace Reflection
} // namespace RBX
