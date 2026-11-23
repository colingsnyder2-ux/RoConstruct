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

void Workspace::reset()
{
	isSimulating = false;          // stop() 005a0260, inlined
	getCamera()->autoMode();
	world->reset();
}
}
