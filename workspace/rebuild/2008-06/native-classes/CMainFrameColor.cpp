#include "CMainFrame.h"
#include "CRobloxControlColorSelector.h"
#include "v8datamodel/BrickColor.h"
#include "v8datamodel/ToolsPart.h"
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

void CMainFrame::handle_4300d0(CCmdUI* ui)
{
    if (ui->m_pOther) {
        CXTPControls* controls = ((CXTPToolBar*)ui->m_pOther)->GetControls();
        int index = (int)ui->m_nIndex;
        CRobloxControlColorSelector* control = index >= 0 && index < controls->GetCount()
            ? (CRobloxControlColorSelector*)controls->GetAt(index) : NULL;
        G3D::Color3uint8 color(RBX::FillTool::color.get().color3());
        unsigned long value = (((unsigned long)color.b << 8) | color.g) << 8;
        value |= color.r;
        control->SetColor(value);
    }
    ui->Enable(TRUE);
}
