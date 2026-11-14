// >>> native-status (generated) -- do not edit >>>
// InsertModelFromRobloxVerb | 2008-06 | 1 byte-exact, inactive (not link-selected)
// 1/4 mapped addresses byte-exact | 3 unproved | no mapped strings | by colin (+3) (mixed 3)
// <<< native-status | src 935331d0 | roc native-status --write
#include <afxwin.h>
#include "../native-headers/InsertModelFromRobloxVerb.h"
#include "../native-headers/CRobloxView.h"
#include "../native-headers/v8datamodel/DataModel.h"
#include <G3D/System.h>

// 00495e60: true when a NetworkClient is present under the instance.
namespace RBX { namespace Network {
class Client { public: static bool clientIsPresent(const Instance*, bool); };
} }

InsertModelFromRobloxVerb::InsertModelFromRobloxVerb(CRobloxView* view, RBX::DataModel* model)
    : RBX::Verb(model, "ToggleToolbox"), view(view), model(model), createdAt(G3D::System::getTick()) {}
// 00458ec0 ctor and 00458f50 isEnabled both call 005083d0 = G3D::System::getTick
// (identity registry); the earlier getLocalTime (00508410) draft was rejected.

// 00458f50
bool InsertModelFromRobloxVerb::isEnabled() const
{
    double now = G3D::System::getTick();
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
