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
