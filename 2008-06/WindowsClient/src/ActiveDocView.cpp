// >>> native-status (generated) -- do not edit >>>
// ActiveDocView | 2008-06 | selection unverified
// unmapped (no indexed address) | by -
// <<< native-status | src d705953b | roc native-status --write
#include "ActiveDocView.h"
ActiveDocView::ActiveDocView() { activeDocViews.insert(this); }
ActiveDocView::~ActiveDocView() { activeDocViews.erase(this); }
