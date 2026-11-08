// >>> native-status (generated) -- do not edit >>>
// InsertModelFromRobloxVerb | 2008-06 | selection unverified
// unmapped (no indexed address) | by -
// <<< native-status | src dcbd7260 | roc native-status --write
#include "../../native-headers/InsertModelFromRobloxVerb.h"
#include "../../native-headers/CRobloxView.h"
#include "../../native-headers/v8datamodel/DataModel.h"
#include <G3D/System.h>

// 00495e60: true when a NetworkClient is present under the instance.
namespace RBX { namespace Network {
class Client { public: static bool clientIsPresent(const Instance*, bool); };
} }

InsertModelFromRobloxVerb::InsertModelFromRobloxVerb(CRobloxView* view, RBX::DataModel* model)
    : RBX::Verb(model, "ToggleToolbox"), view(view), model(model), createdAt(G3D::System::getLocalTime()) {}

bool InsertModelFromRobloxVerb::isEnabled() const
{
    double now = G3D::System::getLocalTime();
    if (createdAt + 10.0 > now)
        return false;
    return !RBX::Network::Client::clientIsPresent(model, true);
}

bool InsertModelFromRobloxVerb::isChecked() const
{
    return view->slot_1d8 != 0;
}

void InsertModelFromRobloxVerb::doIt(RBX::IDataState*)
{
    view->PostMessage(WM_COMMAND, 0x80fe);
}
