// >>> native-status (generated) -- do not edit >>>
// ActiveDocument | 2008-06 | inactive
// unmapped (no indexed address) | unmapped (no binary link) | by -
// <<< native-status | src cf4da001 | roc native-status --write
#include "ActiveDocView.h"
#include "CRobloxDoc.h"

// Original 00405aa0, cdecl; historical function name remains unknown.
extern CRobloxDoc* activeRobloxDoc;
void setActiveDocument(bool active, CRobloxDoc* document)
{
    boost::shared_ptr<RBX::DataModel> previous(activeDocDataModel);
    if (active) {
        activeRobloxDoc = document;
        activeDocDataModel = document->getDataModel();
    } else {
        if (document == activeRobloxDoc) activeRobloxDoc = NULL;
        if (document->getDataModel() == activeDocDataModel) activeDocDataModel.reset();
    }
    if (activeDocDataModel != previous) {
        for (std::set<ActiveDocView*>::iterator it = activeDocViews.begin(); it != activeDocViews.end(); ++it)
            (*it)->update(activeDocDataModel, previous);
    }
}
