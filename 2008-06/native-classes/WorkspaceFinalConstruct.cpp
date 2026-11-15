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
    // 0046b5c0 calls ServiceProvider::create<Selection>, not find.
    RBX::Notifier<RBX::Selection, RBX::SelectionChanged>::connect(dataModel->create<RBX::Selection>(), this);
    return S_OK;
}
