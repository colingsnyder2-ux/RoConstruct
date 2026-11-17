// native-flags: /I{headers}/kernel-stages /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// 2008-06 native Primitive row called by SleepStage (inactive): kept in its own unit, like the original Primitive.cpp
// unit, so SleepStage2008.cpp sees only the declaration and keeps the two calls whose results are unused.
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
