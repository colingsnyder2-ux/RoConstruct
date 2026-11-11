// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/engine-world
// >>> native-status (generated) -- do not edit >>>
// ContactManagerLifetime | 2008-06 | draft (no current byte proof)
// 0/1 mapped addresses byte-exact | 1 unproved | no mapped strings | by king_originala (chatgpt:gpt-6.1-sol)
// <<< native-status | src dc2d84bc | roc native-status --write
#undef _RELEASEASSERT
#include "v8world/ContactManager.h"
#include "v8world/SpatialHash.h"
namespace RBX {
ContactManager::ContactManager(World* value) : spatialHash(new SpatialHash(value, this)), world(value) {}
ContactManager::~ContactManager() { delete spatialHash; }
}
