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

// Template members emitted by this unit (bodies byte-identical to the 2008-06 client).
template class std::_Tree<std::_Tset_traits<ActiveDocView *,std::less<ActiveDocView *>,std::allocator<ActiveDocView *>,0> >;
