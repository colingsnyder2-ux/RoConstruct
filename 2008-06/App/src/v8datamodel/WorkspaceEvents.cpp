// >>> native-status (generated) -- do not edit >>>
// WorkspaceEvents | 2008-06 | inactive
// unmapped (no indexed address) | unmapped (no binary link) | by -
// <<< native-status | src ec1e22e6 | roc native-status --write
#include <afxwin.h>
#include "CWorkspace.h"
#include "v8datamodel/Workspace.h"
#include "v8datamodel/SelectionChanged.h"
#include "util/RunStateOwner.h"

void CWorkspace::onEvent(const RBX::Workspace*, RBX::DrawChanged) {
    runService->invalidateRunViews();
}

void CWorkspace::onEvent(const RBX::Selection*, RBX::SelectionChanged) {
    runService->invalidateRunViews();
}
