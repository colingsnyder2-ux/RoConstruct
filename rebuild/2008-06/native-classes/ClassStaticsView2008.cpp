// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast
// 2008-06 native BrickMesh const floats (inactive): normalPerturbation 00826e3c = 0.05f, bevel 00826e38 = 0.0f.
// Header: native-headers/ViewNew/BrickMesh.h.
#include "ViewNew/BrickMesh.h"

namespace RBX
{
	namespace ViewNew
	{
		const float BrickMesh::normalPerturbation = 0.05f;
		const float BrickMesh::bevel = 0.0f;
	}
}
