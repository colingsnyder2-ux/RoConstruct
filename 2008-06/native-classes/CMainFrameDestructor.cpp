#include "CMainFrame.h"
#include "v8datamodel/BrickColor.h"

namespace RBX {
class FillToolColor : public Notifier<FillToolColor, BrickColor> {};
class FillTool { public: static FillToolColor color; };
}

CMainFrame::~CMainFrame()
{
    if (resource) {
        reinterpret_cast<CCmdTarget*>(resource)->InternalRelease();
        resource = NULL;
    }
    RBX::FillTool::color.removeListener(this);
}
