// >>> native-status (generated) -- do not edit >>>
// CMainFrameDestructor | 2008-06 | inactive
// unmapped (no binary link) | by -
// <<< native-status | src 80b5ae42 | roc native-status --write
#include "CMainFrame.h"
#include "v8datamodel/ToolsPart.h"

CMainFrame::~CMainFrame()
{
    if (resource) {
        reinterpret_cast<CCmdTarget*>(resource)->InternalRelease();
        resource = NULL;
    }
    RBX::FillTool::color.removeListener(this);
}
