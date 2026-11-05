#include <afxwin.h>
#include "CRobloxDoc.h"
#include "CWorkspace.h"
#include "CUploadPlaceDialog.h"
#include "v8datamodel/DataModel.h"
#include "v8datamodel/Visit.h"
#include "util/RunStateOwner.h"

template<class T> inline T* findService(const RBX::ServiceProvider* context)
{
    return context ? context->find<T>() : 0;
}

template<class T> inline T* createService(const RBX::ServiceProvider* context)
{
    return context ? context->create<T>() : 0;
}

BOOL CRobloxDoc::SaveModified()
{
    if (!workspace || !workspace->getDataModel()) return TRUE;
    if (!IsModified()) return TRUE;
    RBX::DataModel::Lock request(getDataModel());
    bool wasRunning = createService<RBX::RunService>(getDataModel().get())->getRunState() == RBX::RS_RUNNING;
    createService<RBX::RunService>(getDataModel().get())->setRunState(RBX::RS_PAUSED);
    RBX::Visit* visit = findService<RBX::Visit>(getDataModel().get());
    if (!visit || visit->getUploadUrl() == "NoVisit") {
        SetForegroundWindow(AfxGetMainWnd()->m_hWnd);
        return CDocument::SaveModified();
    }
    if (visit->getUploadUrl().size() == 0) return TRUE;
    FlashWindow(AfxGetMainWnd()->m_hWnd, FALSE);
    CUploadPlaceDialog dlg(workspace, 0);
    int result = dlg.DoModal() == IDOK;
    if (!result && wasRunning)
        createService<RBX::RunService>(workspace->getDataModel().get())->setRunState(RBX::RS_RUNNING);
    return result;
}

