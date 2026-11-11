// >>> native-status (generated) -- do not edit >>>
// ActiveDocumentData | 2008-06 | selection unverified
// unmapped (no binary link) | by -
// <<< native-status | src 1578f3cc | roc native-status --write
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

// Template members emitted by this unit (bodies byte-identical to the 2008-06 client).
template class std::_Container_base_aux_alloc_real<std::allocator<ActiveDocView *> >;
template class std::allocator<ActiveDocView *>;
template class std::allocator<std::_Tree_nod<std::_Tset_traits<ActiveDocView *,std::less<ActiveDocView *>,std::allocator<ActiveDocView *>,0> >::_Node *>;
