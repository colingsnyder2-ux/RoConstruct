// Startup descriptor initialization body at 004448f0.
#include "v8tree/Instance.h"
#include "reflection/Metadata.h"

void nativeInitializeTypes()
{
	RBX::Instance::classDescriptor();
	RBX::Reflection::Metadata::Classes::classDescriptor();
	RBX::Reflection::Metadata::Functions::classDescriptor();
	RBX::Reflection::Metadata::Member::classDescriptor();
	RBX::Reflection::Metadata::Properties::classDescriptor();
	RBX::Reflection::Metadata::Events::classDescriptor();
}
