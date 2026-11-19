// native-flags: /I{headers}/kernel-stages /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// 2008-06 native RBX::ClumpStage (inactive); evidence in native-headers/v8world/ClumpStage2008.h.
// Rows: constructor 0064cfd0, destructor 0064cf50.
#include "v8world/ClumpStage2008.h"

namespace RBX
{
	// 0064cfd0
	ClumpStage::ClumpStage(IStage* upstream, World* world)
		: IWorldStage(upstream, new TreeStage(this, world), world)
	{
	}

	// 0064cf50
	ClumpStage::~ClumpStage()
	{
	}
}
