// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /I{headers}/engine-world
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
