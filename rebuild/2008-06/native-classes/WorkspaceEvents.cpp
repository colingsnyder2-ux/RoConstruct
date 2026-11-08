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
