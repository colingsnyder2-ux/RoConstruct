#define NATIVE_CLUMP_DECL
#include "v8world/AssemblyLayout.h"
#include "v8world/Primitive2008.h"

namespace RBX
{
	// 005e7560 (placeholder func_005e7560; INFERRED name): clump->assembly without the NULL check of getAssembly 005e7570
	Assembly* Primitive::getAssemblyNoCheck() const
	{
		return clump->getAssembly();
	}
}
