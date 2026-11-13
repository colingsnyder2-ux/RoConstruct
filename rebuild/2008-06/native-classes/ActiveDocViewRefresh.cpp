// >>> native-status (generated) -- do not edit >>>
// ActiveDocViewRefresh | 2008-06 | draft (no current byte proof)
// 0/1 mapped addresses byte-exact | 1 unproved | no mapped strings | by colin (deepseek:deepseek-flash)
// <<< native-status | src 8f34f2cd | roc native-status --write
#include "ActiveDocView.h"

void ActiveDocView::refresh()
{
    update(activeDocDataModel, boost::shared_ptr<RBX::DataModel>());
}
