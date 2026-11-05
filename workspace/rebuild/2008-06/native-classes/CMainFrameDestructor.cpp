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
