// >>> native-status (generated) -- do not edit >>>
// CRobloxControlColorSelector | 2008-06 | 10 byte-exact, inactive (not link-selected)
// 10/13 mapped addresses byte-exact | 3 unproved | no mapped strings | by tester (+5) (mixed 5)
// <<< native-status | src 79ad607a | roc native-status --write
#include "CRobloxControlColorSelector.h"
#include "v8datamodel/BrickColor.h"
#include <G3D/Color3uint8.h>
#include <algorithm>

IMPLEMENT_XTP_CONTROL(CRobloxControlColorSelector, CXTPControl)

int CRobloxControlColorSelector::nextColorId;
std::vector<CRobloxControlColorSelector::CColorInfo> CRobloxControlColorSelector::colors;

// Inlined into addColor and SetColor: both copy the BrickColor argument into a local first.
static COLORREF toColorRef(RBX::BrickColor color)
{
    return RGB(color.color3uint8().r, color.color3uint8().g, color.color3uint8().b);
}

void CRobloxControlColorSelector::addColor(RBX::BrickColor color)
{
    CColorInfo info(toColorRef(color), nextColorId++);
    info.strTip = color.name().c_str();
    colors.push_back(info);
}

CRobloxControlColorSelector::CRobloxControlColorSelector()
    : m_bColorPicked(false)
{
    if (colors.empty())
        std::for_each(RBX::BrickColor::colorPalette().begin(), RBX::BrickColor::colorPalette().end(), &addColor);
    m_nSelected = -1;
    m_clr = (COLORREF)-1;
    SetFlags(xtpFlagNoMovable);
    m_nPressed = -1;
}

COLORREF CRobloxControlColorSelector::GetColor() const
{
    return m_clr;
}

void CRobloxControlColorSelector::SetColor(COLORREF clr)
{
    m_clr = toColorRef(RBX::BrickColor::closest(G3D::Color3uint8(GetRValue(clr), GetGValue(clr), GetBValue(clr))));
    RedrawParent();
}

CSize CRobloxControlColorSelector::GetSize(CDC* /*pDC*/)
{
    return CSize(260, 132);
}

CRect CRobloxControlColorSelector::GetRect(int nIndex) const
{
    int x = nIndex % 8, y = nIndex / 8;
    return CRect(CPoint(2 + m_rcControl.left + x * 32, 2 + m_rcControl.top + y * 32), CSize(32, 32));
}

int CRobloxControlColorSelector::HitTest(CPoint point) const
{
    int nCount = (int)colors.size();
    if (!m_rcControl.PtInRect(point))
        return -1;
    for (int i = 0; i < nCount; i++) {
        if (GetRect(i).PtInRect(point))
            return i;
    }
    return -1;
}

void CRobloxControlColorSelector::Draw(CDC* pDC)
{
    int nCount = (int)colors.size();
    for (int i = 0; i < nCount; i++) {
        CRect rcButton = GetRect(i);
        if (i == m_nSelected || colors[i].clrButton == m_clr) {
            BOOL bPressed = GetPressed() && i == m_nSelected;
            GetPaintManager()->DrawRectangle(pDC, rcButton, i == m_nSelected, bPressed, GetEnabled(),
                                             colors[i].clrButton == m_clr, FALSE, xtpBarTypeNormal, xtpBarPopup);
        }
        rcButton.DeflateRect(3, 3);
        if (GetEnabled())
            pDC->FillSolidRect(rcButton, colors[i].clrButton);
        pDC->Draw3dRect(rcButton, GetXtremeColor(COLOR_3DSHADOW), GetXtremeColor(COLOR_3DSHADOW));
    }
}

void CRobloxControlColorSelector::OnMouseMove(CPoint point)
{
    int nHit = HitTest(point);
    if (nHit != -1) {
        m_nSelected = nHit;
        RedrawParent();
    }
}

BOOL CRobloxControlColorSelector::OnSetSelected(int bSelected)
{
    if (!bSelected)
        m_nSelected = -1;
    return CXTPControl::OnSetSelected(bSelected);
}

void CRobloxControlColorSelector::OnExecute()
{
    if (m_nPressed != -1) {
        m_clr = colors[m_nPressed].clrButton;
        m_bColorPicked = true;
    }
    CXTPControl::OnExecute();
}

void CRobloxControlColorSelector::OnClick(BOOL bKeyboard, CPoint pt)
{
    if (!GetEnabled())
        return;
    int nHit = HitTest(pt);
    if (nHit == -1)
        return;
    m_nPressed = nHit;
    if (!bKeyboard)
        ClickToolBarButton();
    else
        OnExecute();
    m_nPressed = -1;
}

void CRobloxControlColorSelector::OnLButtonUp(CPoint point)
{
    if (GetEnabled() && m_pParent->GetPosition() == xtpBarPopup)
        OnClick(TRUE, point);
}

// Template members emitted by this unit (bodies byte-identical to the 2008-06 client).
template class std::_Container_base_aux_alloc_real<std::allocator<CRobloxControlColorSelector::CColorInfo> >;
template class std::_Vector_const_iterator<CRobloxControlColorSelector::CColorInfo,std::allocator<CRobloxControlColorSelector::CColorInfo> >;
template class std::_Vector_iterator<CRobloxControlColorSelector::CColorInfo,std::allocator<CRobloxControlColorSelector::CColorInfo> >;
