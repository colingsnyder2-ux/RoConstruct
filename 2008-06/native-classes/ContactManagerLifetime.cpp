// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/engine-world
#undef _RELEASEASSERT
#include "v8world/ContactManager.h"
#include "v8world/SpatialHash2008.h" // the 0x8c-byte SpatialHash: ContactManager() 0060d260 allocates `push 0x8c`
namespace RBX {
// 0060d260 (ret 4): new SpatialHash(world, this) 0065b4e0, world +0x4, the empty tempPrimitives array +0x8..+0x10.
ContactManager::ContactManager(World* value) : spatialHash(new SpatialHash(value, this)), world(value) {}
// 0060ccf0
ContactManager::~ContactManager() { delete spatialHash; }
}
