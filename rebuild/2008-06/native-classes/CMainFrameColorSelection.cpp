// >>> native-status (generated) -- do not edit >>>
// CMainFrameColorSelection | 2008-06 | selection unverified
// unmapped (no binary link) | by -
// <<< native-status | src 462d916f | roc native-status --write
#include "CMainFrame.h"
#include "CRobloxControlColorSelector.h"
#include "v8datamodel/ToolsPart.h"
#include "v8datamodel/DataModel.h"
#include "v8tree/Verb.h"
#include <G3D/Color3uint8.h>

boost::shared_ptr<RBX::DataModel> getActiveDataModel();

void CMainFrame::handle_431260(NMHDR* notification, LRESULT* result)
{
    CRobloxControlColorSelector* control = static_cast<CRobloxControlColorSelector*>(
        reinterpret_cast<NMXTPCONTROL*>(notification)->pControl);
    G3D::Color3uint8 color;
    color.r = GetRValue(control->GetColor());
    color.g = GetGValue(control->GetColor());
    color.b = GetBValue(control->GetColor());
    RBX::FillTool::color.set(RBX::BrickColor::closest(color));
    if (getActiveDataModel()) {
        RBX::DataModel::Lock lock(getActiveDataModel());
        RBX::Verb* verb = getActiveDataModel()->getVerb("FillTool");
        verb->doIt(getActiveDataModel().get());
    }
    *result = TRUE;
}
