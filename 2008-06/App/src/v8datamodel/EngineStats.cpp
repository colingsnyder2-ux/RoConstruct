// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/engine-world
// >>> native-status (generated) -- do not edit >>>
// EngineStats | 2008-06 | inactive
// unmapped (no indexed address) | unmapped (no binary link) | by -
// <<< native-status | src 8440b627 | roc native-status --write
#include "v8datamodel/DataModel.h"
#include "v8datamodel/Workspace.h"
#include "v8world/World.h"
#include "v8world/ContactManager.h"
#include "v8world/SpatialHash.h"
#include "StandardVerbs.h"
namespace RBX {
void EngineStatsCommand::doIt(IDataState*) {
    dataModel->getWorkspace()->getWorld()->getContactManager().doStats();
}
}
