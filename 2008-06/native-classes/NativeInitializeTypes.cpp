// Startup descriptor initialization body at 004448f0.
#include "v8tree/Instance.h"
#include "reflection/Metadata.h"

// 004448f0: the first call 00444550 is Described<RBX::Metadata::Reflection, ..., sReflection>::classDescriptor() (registry
// name; it passes Instance::classDescriptor 0040ad80 as the base), not Instance::classDescriptor itself.
void nativeInitializeTypes()
{
	RBX::Metadata::Reflection::classDescriptor();
	RBX::Reflection::Metadata::Classes::classDescriptor();
	RBX::Reflection::Metadata::Functions::classDescriptor();
	RBX::Reflection::Metadata::Member::classDescriptor();
	RBX::Reflection::Metadata::Properties::classDescriptor();
	RBX::Reflection::Metadata::Events::classDescriptor();
}
