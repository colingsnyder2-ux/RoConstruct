// from server: 100% by tester
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: rbxgs reflection/reflection_function.cpp

// Candidate translation unit (score above; library headers required).
#include "reflection/function.h"
#include "reflection/object.h"

namespace RBX
{
	namespace Reflection
	{
		FunctionDescriptor::FunctionDescriptor(ClassDescriptor& classDescriptor, const char* name, Security security)
			: MemberDescriptor(classDescriptor, name, "Function"),
			  security(security),
			  signature()
		{
			classDescriptor.FunctionContainer::declare(this);
		}
	}
}
