// >>> native-status (generated) -- do not edit >>>
// CMainFrameDestructor | 2008-06 | linked
// 1/1 exact by name (100%) | 1/1 exact bodies | no strings | verified 2026-11-07| by colin (deepseek:deepseek-chat)
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
