#include "CPropertyGridItemBrickColor.h"
#include "CRobloxControlColorSelector.h"
#include "v8datamodel/BrickColor.h"
#include <G3D/Color3uint8.h>

CString CPropertyGridItemBrickColor::brickColorName(COLORREF clr)
{
    const float scale = 1.0f / 255.0f;
    RBX::BrickColor color = RBX::BrickColor::closest(G3D::Color3(GetRValue(clr) * scale, GetGValue(clr) * scale,
                                                                 GetBValue(clr) * scale));
    return color.name().c_str();
}

void CPropertyGridItemBrickColor::SetColor(COLORREF clr)
{
    m_clrValue = clr;
    CXTPPropertyGridItem::SetValue(brickColorName(clr));
}

CPropertyGridItemBrickColor::CPropertyGridItemBrickColor(CString strCaption, COLORREF clr)
    : CXTPPropertyGridItemColor(strCaption, clr)
{
    m_nFlags = xtpGridItemHasComboButton;
    SetColor(clr);
    m_strDefaultValue = m_strValue;
}

COLORREF CPropertyGridItemBrickColor::brickColorRef(CString strName)
{
    G3D::Color3uint8 color = RBX::BrickColor::parse(strName).color3uint8();
    return RGB(color.r, color.g, color.b);
}

void CPropertyGridItemBrickColor::SetValue(CString strValue)
{
    if (strValue != _T("")) {
        SetColor(brickColorRef(strValue));
    } else {
        m_clrValue = (COLORREF)-1;
        CXTPPropertyGridItem::SetValue(_T(""));
    }
}

// m_bColorPicked (+0x17c) accessed via friend declaration in CRobloxControlColorSelector.h.
void CPropertyGridItemBrickColor::OnInplaceButtonDown(CXTPPropertyGridInplaceButton* pButton)
{
    if (m_pGrid->SendNotifyMessage(XTP_PGN_INPLACEBUTTONDOWN, (LPARAM)pButton) == TRUE)
        return;
    if (!OnRequestEdit())
        return;

    CRect rcItem = GetItemRect();
    m_pGrid->ClientToScreen(&rcItem);
    rcItem.left = rcItem.right - 158;

    CXTPPopupBar* pPopup = CXTPPopupBar::CreatePopupBar(0);
    CRobloxControlColorSelector* pSelector = new CRobloxControlColorSelector;
    pPopup->GetControls()->Add(pSelector, 0);
    if (GetValue() != _T(""))
        pSelector->SetColor(GetColor());

    if (CXTPCommandBars::TrackPopupMenu(pPopup, TPM_RIGHTALIGN | TPM_NONOTIFY, rcItem.right, rcItem.bottom,
                                        AfxGetMainWnd()) && pSelector->m_bColorPicked)
        OnValueChanged(brickColorName(pSelector->GetColor()));
    pPopup->InternalRelease();
}
