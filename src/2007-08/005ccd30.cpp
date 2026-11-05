// from server: 100% by auto
// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD
// roc-lib: openrbx-client App/reflection/reflection_function.cpp

// Candidate translation unit (score above; library headers required).
#include "reflection/function.h"
#include "reflection/object.h"

namespace RBX {
namespace Reflection {

// FUNCTION: WEBSERVICE 0x100713b0
FunctionDescriptor::FunctionDescriptor(ClassDescriptor& classDescriptor, const char* name, Security security)
	: MemberDescriptor(classDescriptor, name, "Function"), security(security)
{
	classDescriptor.MemberDescriptorContainer<FunctionDescriptor>::declare(this);
}

} // namespace Reflection
} // namespace RBX
