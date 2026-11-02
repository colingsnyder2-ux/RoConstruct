#include "ActiveDocView.h"

class CRobloxDoc;
CRobloxDoc* activeRobloxDoc = 0;
std::set<ActiveDocView*> activeDocViews;
boost::shared_ptr<RBX::DataModel> activeDocDataModel;
