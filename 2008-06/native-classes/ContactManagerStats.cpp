// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/engine-world
// >>> native-status (generated) -- do not edit >>>
// ContactManagerStats | 2008-06 | draft (no current byte proof)
// 0/1 mapped addresses byte-exact | 1 unproved | no mapped strings | by auto
// <<< native-status | src 775f91cb | roc native-status --write
#include "v8world/ContactManager.h"
#include "v8world/SpatialHash.h"
void RBX::ContactManager::doStats() { spatialHash->doStats(); }
