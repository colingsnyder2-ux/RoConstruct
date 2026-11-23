// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast
// 2008-06 native World / SpatialHash / ContactManager statics (inactive).
#define NATIVE_PRIMITIVE_NATIVE_BODY
#include "v8world/Contact2008.h"
#include "v8world/World2008.h"
#include "v8world/SpatialHash2008.h"
#include "v8world/ContactManager.h"

namespace RBX
{
	World::EThrottle World::environmentalThrottle = World::DefaultAuto; // 0097ac54 (.bss, 0)
	int SpatialHash::gridSize = 8;                                       // 009625ac (.data, initial 8)
	bool ContactManager::ignoreBool = false;                             // INFERRED: address unknown, zero
}
