// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /DNDEBUG /D_MBCS /fp:fast
// 2008-06 native XBoolItem editor row (inactive until owner integration).
#include "PropertyGridItems.h"
#include "CPropGrid.h"

XBoolItem::XBoolItem(const RBX::Reflection::TypedPropertyDescriptor<bool>* property, CPropGrid* grid)
    : BoolItemBase(property, grid)
{
    SetCheckBoxStyle(TRUE);
}

XBoolItem::~XBoolItem()
{
}

int XBoolItem::OnDrawItemValue(CDC& dc, CRect rcValue)
{
    if (!m_bCheckBoxStyle)
        return FALSE;

    CRect rcSample(rcValue.left - 1, rcValue.CenterPoint().y - 6,
        rcValue.left - 1 + 13, rcValue.CenterPoint().y + 7);

    CXTPPropertyGridPaintManager* pPaintManager = m_pGrid->GetPaintManager();

    if (pPaintManager->m_buttonsStyle == xtpGridButtonsThemed && pPaintManager->m_themeButton.IsAppThemed())
    {
        pPaintManager->m_themeButton.DrawThemeBackground(dc, BP_CHECKBOX,
            GetReadOnly() ? (emptyValue() ? CBS_MIXEDDISABLED : GetBool() ? CBS_CHECKEDDISABLED : CBS_UNCHECKEDDISABLED) :
            (emptyValue() ? CBS_MIXEDNORMAL : GetBool() ? CBS_CHECKEDNORMAL : CBS_UNCHECKEDNORMAL),
            rcSample, 0);
    }
    else
    {
        dc.DrawFrameControl(rcSample, DFC_BUTTON, DFCS_BUTTONCHECK |
            (GetReadOnly() ? DFCS_INACTIVE : 0) | (GetBool() ? DFCS_CHECKED : 0));
    }

    return TRUE;
}
