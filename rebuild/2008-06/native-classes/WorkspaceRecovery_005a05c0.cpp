// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /U_RELEASEASSERT /I{headers}/engine-world
#include "v8datamodel/Workspace.h"
#include "v8datamodel/Camera.h"
#include "v8world/World.h"

namespace RBX {

// INFERRED: 005a05c0, placeholder name (identity tier), body byte-proved
Camera* Workspace::sub_005a05c0() const
{
	// mov eax, dword ptr [ecx + 0x3fc]   ; currentCamera (shared_ptr<Camera>) px, a real field at +0x3fc
	// ret
	return currentCamera.get();
}

// 005a0df0 ?reset@Workspace@RBX@@QAEXXZ (52 B; registry placeholder func_005a0df0). Identity: the donor
// v8datamodel/Workspace.cpp reset() { stop(); world->reset(); } -- stop 005a0260 inlined (isSimulating +0x3d0 = false,
// getCamera through the camera-owner vtable at +0x288 slot 1, Camera::autoMode 005cc450), then World::reset inlined
// (world +0x2e4, worldStepId +0xa8 = 0 in the engine-world 2008 World.h; no RBXASSERT code, hence /U_RELEASEASSERT). stop() lives out of line in the split unit AppUnit5A0_2008Workspace.cpp, so
// its two statements are spelled here (one original unit: the compiler inlined it).
void Workspace::reset()
{
	isSimulating = false;          // stop() 005a0260, inlined
	getCamera()->autoMode();
	world->reset();
}
}
