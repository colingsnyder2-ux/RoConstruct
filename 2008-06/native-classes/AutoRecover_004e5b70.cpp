// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHs /MD /D_AFXDLL /DNDEBUG /D_MBCS
#include "v8world/Block.h"

namespace RBX
{
	// INFERRED: cornerRadius sits at this+0x14 (Geometry vtable + gridSize = 0x10, then vertices, then cornerRadius).
	float Block::getRadius() const
	{
		return this->cornerRadius;
	}
}
