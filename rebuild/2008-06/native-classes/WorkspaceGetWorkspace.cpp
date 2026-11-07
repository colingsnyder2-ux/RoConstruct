// >>> native-status (generated) -- do not edit >>>
// WorkspaceGetWorkspace | 2008-06 | inactive
// unmapped (no binary link) | by -
// <<< native-status | src 21147416 | roc native-status --write
#include "CWorkspace.h"
#include "v8datamodel/DataModel.h"

RBX::Workspace* CWorkspace::getWorkspace()
{
    return dataModel ? dataModel->getWorkspace() : NULL;
}
