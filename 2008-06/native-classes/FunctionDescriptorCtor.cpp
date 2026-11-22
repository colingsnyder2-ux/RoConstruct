// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL
// Reflection::FunctionDescriptor constructor (inactive), reflection/function.h declares it without a body. Flags
// line copied from the sibling PropertyDescriptorCtor.cpp. Identity: registry
// ??0FunctionDescriptor@Reflection@RBX@@IAE@AAVClassDescriptor@12@PBDW4Security@012@@Z at 00595790; every
// BoundFuncDesc constructor calls it (BoundFuncDescPartInstanceVoid.cpp, BoundFuncDescRecovery_00559cb0.cpp).
// Shape: header-inline MemberDescriptor(classDescriptor, name, "Function" 00832268) 0056b480, security at +0x10,
// SignatureDescriptor() 00594bf0 at +0x14 (EH state 0 covers it), then
// MemberDescriptorContainer<FunctionDescriptor>::declare 0056fff0 on the function container at ClassDescriptor+0x70.
// The class is __declspec(novtable): no vftable store.
#include "reflection/function.h"
#include "reflection/object.h"

namespace RBX
{
	namespace Reflection
	{
		// 00595790
		FunctionDescriptor::FunctionDescriptor(ClassDescriptor& classDescriptor, const char* name, Security security)
			: MemberDescriptor(classDescriptor, name, "Function"),
			  security(security)
		{
			classDescriptor.FunctionContainer::declare(this);
		}
	}
}
