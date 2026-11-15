// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/engine-world
#include "v8world/ContactManager.h"
#include "v8world/SpatialHash.h"
void RBX::ContactManager::doStats() { spatialHash->doStats(); }
