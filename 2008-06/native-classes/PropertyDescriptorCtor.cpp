// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL
// 2008-06 native Reflection::PropertyDescriptor constructor (inactive), reflection/property.cpp area 0056c000.
// reflection/property.h declares the protected constructor without a body. Same shape as SignalDescriptor's
// constructor 0056bab0 (AppUnit568Signal.cpp): the header-inline MemberDescriptor(ClassDescriptor&, name, category)
// 0056b480, then the two flag bits merged into the bitfield word +0x10 (bIsPublic = flags & UI; bCanStreamWrite from
// a signed shift: the target computes (flags sar 2) & 1, then add/or into bit 1; '!= 0' folds to shr 1 / and 2 and
// was rejected, as was the same pair assigned in the body), the Type reference at +0x14, and MemberDescriptorContainer<PropertyDescriptor>::declare 0056c170 on the
// property container at ClassDescriptor+8. The class is __declspec(novtable): no vftable store.
#include "reflection/property.h"
#include "reflection/object.h"

namespace RBX
{
	namespace Reflection
	{
		// 0056c650 ??0PropertyDescriptor@Reflection@RBX@@IAE@AAVClassDescriptor@12@ABVType@12@PBD2W4Functionality@012@@Z
		PropertyDescriptor::PropertyDescriptor(ClassDescriptor& classDescriptor, const Type& type, const char* name, const char* category, Functionality flags)
			: MemberDescriptor(classDescriptor, name, category),
			  bIsPublic(flags & UI),
			  bCanStreamWrite((flags & STREAMING) >> 2),
			  type(type)
		{
			classDescriptor.PropertyContainer::declare(this);
		}
	}
}
