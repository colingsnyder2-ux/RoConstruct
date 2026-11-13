// >>> native-status (generated) -- do not edit >>>
// WorkspaceEvents | 2008-06 | 2 byte-exact, inactive (not link-selected)
// 2/2 mapped addresses byte-exact | 0 unproved | no mapped strings | by king_originala (mixed 2)
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
