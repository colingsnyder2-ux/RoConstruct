// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/engine-world
// >>> native-status (generated) -- do not edit >>>
// ContactManagerLifetime | 2008-06 | selection unverified
// unmapped (no binary link) | by -
// <<< native-status | src dc2d84bc | roc native-status --write
#undef _RELEASEASSERT
#include "v8world/ContactManager.h"
#include "v8world/SpatialHash.h"
namespace RBX {
ContactManager::ContactManager(World* value) : spatialHash(new SpatialHash(value, this)), world(value) {}
ContactManager::~ContactManager() { delete spatialHash; }
}
