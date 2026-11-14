// >>> native-status (generated) -- do not edit >>>
// WorkspaceFinalConstruct | 2008-06 | draft (no current byte proof)
// 0/1 mapped addresses byte-exact | 1 unproved | no mapped strings | by EspClaude (deepseek:deepseek-chat)
// <<< native-status | src a01e1073 | roc native-status --write
#include <afxwin.h>
#include "CWorkspace.h"
#include "v8datamodel/DataModel.h"
#include "v8datamodel/Selection.h"
#include "v8datamodel/Workspace.h"
#include "util/RunStateOwner.h"

// 0046b5c0 CWorkspace::FinalConstruct
// Original calls 004153b0 (registry: ServiceProvider::create<Selection>), not
// 00415200 (find<Selection>); find -> create fixed from that call target.
HRESULT CWorkspace::FinalConstruct() {
    dataModel = RBX::DataModel::createDataModel(true);
    RBX::DataModel::Lock lock(dataModel);
    runService = RBX::shared_from(dataModel->create<RBX::RunService>());
    RBX::Notifier<RBX::Workspace, RBX::DrawChanged>::connect(dataModel->getWorkspace(), this);
    RBX::Notifier<RBX::Selection, RBX::SelectionChanged>::connect(dataModel->create<RBX::Selection>(), this);
    return S_OK;
}
