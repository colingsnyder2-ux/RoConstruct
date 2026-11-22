// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS
// 2008-06 RBX::IMovingManager destructor (inactive). Kept out of IMovingManager.cpp (another batch's file); flags
// line copied from it. Declaration: native-headers/v8world/IMoving.h (__declspec(novtable), std::set moving at +0x4).
#include "v8world/IMoving.h"

namespace RBX
{
	// 00614db0 ??1IMovingManager@RBX@@UAE@XZ (registry): no vtable store (novtable), only the std::set<IMoving*>
	// member destructor 0064b230 on +0x4 (tail jump). Callers: ~Workspace 005a2bed and two EH unwind funclets
	// (007d2a94 / 007d2d8c).
	IMovingManager::~IMovingManager()
	{
	}
}
