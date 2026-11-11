// >>> native-status (generated) -- do not edit >>>
// ActiveDocViewRefresh | 2008-06 | selection unverified
// unmapped (no binary link) | by -
// <<< native-status | src 8f34f2cd | roc native-status --write
#include "ActiveDocView.h"

void ActiveDocView::refresh()
{
    update(activeDocDataModel, boost::shared_ptr<RBX::DataModel>());
}
