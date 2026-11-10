#include "ActiveDocView.h"
#include "CRobloxDoc.h"

CRobloxDoc* currentDocument = 0;
// Transitional provider for still-linked recovered bodies. currentDocument is
// the 2008 state used by the native document source.
CRobloxDoc* activeRobloxDoc = 0;
std::set<ActiveDocView*> activeDocViews;
boost::shared_ptr<RBX::DataModel> activeDocDataModel;

void setCurrentDocument(bool makeCurrent, CRobloxDoc* document) {
    boost::shared_ptr<RBX::DataModel> oldDataModel(activeDocDataModel);
    if (makeCurrent) {
        currentDocument = document;
        activeDocDataModel = document->getDataModel();
    } else {
        if (document == currentDocument)
            currentDocument = 0;
        if (document->getDataModel() == activeDocDataModel)
            activeDocDataModel.reset();
    }
    if (activeDocDataModel != oldDataModel)
        for (std::set<ActiveDocView*>::iterator it = activeDocViews.begin(); it != activeDocViews.end(); ++it)
            (*it)->update(activeDocDataModel, oldDataModel);
}
// Native recovery draft: ActiveDocumentData currentDocument/activeDocViews provider is inactive pending link/runtime proof.
