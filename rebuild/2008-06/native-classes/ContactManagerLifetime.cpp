// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/engine-world
#undef _RELEASEASSERT
#include "v8world/ContactManager.h"
#include "v8world/SpatialHash.h"
namespace RBX {
ContactManager::ContactManager(World* value) : spatialHash(new SpatialHash(value, this)), world(value) {}
ContactManager::~ContactManager() { delete spatialHash; }
}
