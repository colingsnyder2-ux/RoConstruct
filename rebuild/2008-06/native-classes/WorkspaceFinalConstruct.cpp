// >>> native-status (generated) -- do not edit >>>
// WorkspaceFinalConstruct | 2008-06 | inactive
// unmapped (no binary link) | by -
// <<< native-status | src a01e1073 | roc native-status --write
#include <afxwin.h>
#include "CWorkspace.h"
#include "v8datamodel/DataModel.h"
#include "v8datamodel/Selection.h"
#include "v8datamodel/Workspace.h"
#include "util/RunStateOwner.h"

HRESULT CWorkspace::FinalConstruct() {
    dataModel = RBX::DataModel::createDataModel(true);
    RBX::DataModel::Lock lock(dataModel);
    runService = RBX::shared_from(dataModel->create<RBX::RunService>());
    RBX::Notifier<RBX::Workspace, RBX::DrawChanged>::connect(dataModel->getWorkspace(), this);
    RBX::Notifier<RBX::Selection, RBX::SelectionChanged>::connect(dataModel->find<RBX::Selection>(), this);
    return S_OK;
}
