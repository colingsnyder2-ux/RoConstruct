// >>> native-status (generated) -- do not edit >>>
// ActiveDocView | 2008-06 | selection unverified
// unmapped (no binary link) | by -
// <<< native-status | src 3ec1904f | roc native-status --write
#include "ActiveDocView.h"
ActiveDocView::ActiveDocView() { activeDocViews.insert(this); }
ActiveDocView::~ActiveDocView() { activeDocViews.erase(this); }

// Template members emitted by this unit (bodies byte-identical to the 2008-06 client).
template class std::pair<std::_Tree<std::_Tset_traits<ActiveDocView *,std::less<ActiveDocView *>,std::allocator<ActiveDocView *>,0> >::iterator,std::_Tree<std::_Tset_traits<ActiveDocView *,std::less<ActiveDocView *>,std::allocator<ActiveDocView *>,0> >::iterator>;
