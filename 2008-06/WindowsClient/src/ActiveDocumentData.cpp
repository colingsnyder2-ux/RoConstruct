// >>> native-status (generated) -- do not edit >>>
// ActiveDocumentData | 2008-06 | selection unverified
// unmapped (no indexed address) | by -
// <<< native-status | src 580163ed | roc native-status --write
#include "ActiveDocView.h"
#include "CRobloxDoc.h"

CRobloxDoc* activeRobloxDoc = 0;
std::set<ActiveDocView*> activeDocViews;
boost::shared_ptr<RBX::DataModel> activeDocDataModel;

