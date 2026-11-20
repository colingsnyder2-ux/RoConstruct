#include "ActiveDocView.h"
ActiveDocView::ActiveDocView() { activeDocViews.insert(this); }
ActiveDocView::~ActiveDocView() { activeDocViews.erase(this); }

template class std::pair<std::_Tree<std::_Tset_traits<ActiveDocView *,std::less<ActiveDocView *>,std::allocator<ActiveDocView *>,0> >::iterator,std::_Tree<std::_Tset_traits<ActiveDocView *,std::less<ActiveDocView *>,std::allocator<ActiveDocView *>,0> >::iterator>;

void ActiveDocView::refresh()
{
    update(activeDocDataModel, boost::shared_ptr<RBX::DataModel>());
}
