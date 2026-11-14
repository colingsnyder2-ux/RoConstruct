// Inactive 2008-06 PartInstance extent accessors.
#include "v8datamodel/PartInstance.h"

namespace RBX
{
	// 00598d90
	Extents PartInstance::getExtentsLocal() const
	{
		return primitive.getExtentsLocal();
	}
}
// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /fp:fast /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/part-embedded /I{headers}/engine-world
