#include "ActiveDocView.h"
#include "CRobloxDoc.h"

CRobloxDoc* activeRobloxDoc = 0;
std::set<ActiveDocView*> activeDocViews;
boost::shared_ptr<RBX::DataModel> activeDocDataModel;

