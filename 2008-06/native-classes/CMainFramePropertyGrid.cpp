#include "CMainFrame.h"
#include "../native-headers/mainframe-getter/v8datamodel/ToolsPart.h"
#include <Controls/XTColorDialog.h>
#include <G3D/Color3uint8.h>


void CMainFrame::handle_431160(NMHDR*, LRESULT*)
{
    G3D::Color3uint8 rgb(RBX::FillTool::color.get().color3());
    unsigned long color = (((unsigned long)rgb.b << 8) | rgb.g) << 8;
    color |= rgb.r;
    CXTColorDialog dialog(color, color, CPS_XT_SHOW3DSELECTION, this);
    if (dialog.DoModal() == 1) {
        COLORREF selectedColor = dialog.GetColor();
        RBX::FillTool::color.set(RBX::BrickColor::closest(G3D::Color3uint8(GetRValue(selectedColor), GetGValue(selectedColor), GetBValue(selectedColor))));
    }
}
