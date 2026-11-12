// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: openrbx-client-dll App/reflection/reflection_object.cpp

// Candidate translation unit (score above; library headers required).
#include "reflection/reflection.h"

namespace RBX {
namespace Reflection {

// GLOBAL: WEBSERVICE 0x102f59a1
// GLOBAL: ROBLOX 0x0095b001
bool ClassDescriptor::lockedDown;

// FUNCTION: WEBSERVICE 0x10047430
// FUNCTION: ROBLOX 0x005a9370
bool ClassDescriptor::operator==(const ClassDescriptor& other) const
{
	return this == &other;
}

bool ClassDescriptor::operator!=(const ClassDescriptor& other) const
{
	return this != &other;
}

// FUNCTION: WEBSERVICE 0x10047800
// FUNCTION: ROBLOX 0x005a9ab0
ClassDescriptor::ClassDescriptor()
	: Descriptor("<<<ROOT>>>"), MemberDescriptorContainer<PropertyDescriptor>(NULL),
	  MemberDescriptorContainer<SignalDescriptor>(NULL), MemberDescriptorContainer<FunctionDescriptor>(NULL), base(NULL)
{
}

// FUNCTION: WEBSERVICE 0x100478c0
// STUB: ROBLOX 0x005a9b70
ClassDescriptor::ClassDescriptor(ClassDescriptor& base, const char* name)
	: Descriptor(name), MemberDescriptorContainer<PropertyDescriptor>(&base),
	  MemberDescriptorContainer<SignalDescriptor>(&base), MemberDescriptorContainer<FunctionDescriptor>(&base),
	  base(&base)
{
	boost::recursive_mutex::scoped_lock lock(sync());

	base.derivedClasses.push_back(this);
}

// FUNCTION: WEBSERVICE 0x100479c0
// FUNCTION: ROBLOX 0x005a9c70
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
// FUNCTION: ROBLOX 0x005a9d10
bool MemberDescriptor::isMemberOf(const DescribedBase* instance) const
{
	return isMemberOf(instance->getDescriptor());
}

} // namespace Reflection
} // namespace RBX
