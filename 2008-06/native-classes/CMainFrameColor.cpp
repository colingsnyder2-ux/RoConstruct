#include "CMainFrame.h"
#include "v8datamodel/BrickColor.h"
#include <G3D/Color3uint8.h>

IMPLEMENT_DYNAMIC(CMainFrame, CXTPMDIFrameWnd)

void CMainFrame::onEvent(const RBX::FillToolColor*, RBX::BrickColor color)
{
    G3D::Color3uint8 rgb(color.color3());
    unsigned long value = (((unsigned long)rgb.b << 8) | rgb.g) << 8;
    value |= rgb.r;
    CXTPControlPopupColor* popup = static_cast<CXTPControlPopupColor*>(
        GetCommandBars()->FindControl(xtpControlPopup, 0x8040, TRUE, TRUE));
    if (popup) popup->SetColor(value);
}
