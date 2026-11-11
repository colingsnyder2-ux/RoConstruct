// >>> native-status (generated) -- do not edit >>>
// WorkspaceGetWorkspace | 2008-06 | draft (no current byte proof)
// 0/1 mapped addresses byte-exact | 1 unproved | no mapped strings | by atomic.potato (ntech:glm-4.5-air)
// <<< native-status | src 21147416 | roc native-status --write
#include "CWorkspace.h"
#include "v8datamodel/DataModel.h"

RBX::Workspace* CWorkspace::getWorkspace()
{
    return dataModel ? dataModel->getWorkspace() : NULL;
}
