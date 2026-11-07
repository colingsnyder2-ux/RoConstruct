// Inactive 2008-06 native recovery: the reflection_object unit of the application range 00570000..0057c000.
// Rows (verified by tests/record_native_app_unit570_2008.py):
//   MemberDescriptorContainer<Property/Signal/FunctionDescriptor>::mergeMembers 005703a0 / 00570440 / 005704e0 and
//   their constructors 00570580 / 00570660 / 00570740 (the member.h templates, first instantiated by this unit),
//   ClassDescriptor() 00570820 ("<<<ROOT>>>", base +0xbc = NULL), ClassDescriptor::`scalar deleting destructor'
//   005708d0 (~ClassDescriptor 0040abc0), MemberDescriptor::isMemberOf(const ClassDescriptor&) 00570ba0 (owner +0xc,
//   base +0xbc, inline rootDescriptor() static 0096c3a0) and isMemberOf(const DescribedBase*) 00570c40 (descriptor +8).
// ClassDescriptor and DescribedBase are the donor reflection/object.h declarations (read-only); MemberDescriptor and
// MemberDescriptorContainer are the native reflection/member.h ones (read-only).
#include "reflection/reflection.h"

namespace RBX
{
	namespace Reflection
	{
		ClassDescriptor::ClassDescriptor()
			: Descriptor("<<<ROOT>>>"),
			  PropertyContainer(NULL),
			  SignalContainer(NULL),
			  FunctionContainer(NULL),
			  derivedClasses(),
			  base(NULL)
		{
		}

		bool MemberDescriptor::isMemberOf(const ClassDescriptor& classDescriptor) const
		{
			const ClassDescriptor* p = &classDescriptor;
			do
			{
				if (p == &owner)
					return true;
				p = p->getBase();
			}
			while (p != &ClassDescriptor::rootDescriptor());

			return false;
		}

		bool MemberDescriptor::isMemberOf(const DescribedBase* instance) const
		{
			return isMemberOf(instance->getDescriptor());
		}
	}
}
