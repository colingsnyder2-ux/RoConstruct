// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast
// 2008-06 RBX::Humanoid::getLocalHeadFromContext (inactive). The native Humanoid2008.h (Humanoid2008*.cpp, other
// owners) does not declare it, so this unit takes the declaration from native-headers/humanoid/Humanoid.h (same
// static cdecl signature, ?getLocalHeadFromContext@Humanoid@RBX@@SAPAVPartInstance@2@PBVInstance@2@@Z) as the
// MouseCommand / LaserTool / ShootTool callers do. Flags line from Humanoid2008Parts.cpp.
#include "humanoid/Humanoid.h"
#include "Network/Players.h"

namespace RBX
{
	// 005d7990: Network::Players::findLocalCharacter 0049aca0 (cdecl, context), then a tail jump to
	// getHeadFromCharacter 005d75a0 with the result. Callers: MouseCommand::distanceFromCharacter 00615830 /
	// characterCanReach 00615880, ShootTool::shoot 0063e890, LaserTool::onMouseDown 0063f970.
	PartInstance* Humanoid::getLocalHeadFromContext(const Instance* context)
	{
		return getHeadFromCharacter(Network::Players::findLocalCharacter(context));
	}
}
