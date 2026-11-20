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

// 004382b0: reads CRobloxControlColorSelector::m_bColorPicked (+0x17c) through the friend declaration in
// CRobloxControlColorSelector.h.
void CPropertyGridItemBrickColor::OnInplaceButtonDown(CXTPPropertyGridInplaceButton* pButton)
{
    if (m_pGrid->SendNotifyMessage(XTP_PGN_INPLACEBUTTONDOWN, (LPARAM)pButton) == TRUE)
        return;
    if (!OnRequestEdit())
        return;

    CRect rcItem = GetItemRect();
    m_pGrid->ClientToScreen(&rcItem);
    rcItem.left = rcItem.right - 158;

    CXTPPopupBar* pPopup = CXTPPopupToolBar::CreatePopupToolBar(0);  // 006ee720 (CreateObject of CXTPPopupToolBar 0097e038)
    CRobloxControlColorSelector* pSelector = new CRobloxControlColorSelector;
    pPopup->GetControls()->Add(pSelector, 0);
    if (GetValue() != _T(""))
        pSelector->SetColor(GetColor());

    if (CXTPCommandBars::TrackPopupMenu(pPopup, TPM_RIGHTALIGN | TPM_NONOTIFY, rcItem.right, rcItem.bottom,
                                        AfxGetMainWnd()) && pSelector->m_bColorPicked)
        OnValueChanged(brickColorName(pSelector->GetColor()));
    pPopup->InternalRelease();
}

// 2008-06 native Vector3Item editor row (draft recovery; inactive until proved).
// 0043d710: OnAfterEdit (primary vftable slot) - parse the edited text into the vector.
// 0043d790: update (Item vftable slot 0) - forward to the three component rows.
#include "PropertyGridItems2008.h"
#include "util/Utilities.h"

void Vector3Item::update(RBX::SelectionGroup* group)
{
    Vector3ItemBase::update(group);
    for (int i = 0; i < 3; ++i)
        if (components[i])
            components[i]->update(group);
}

BOOL Vector3Item::OnAfterEdit(CString& strValue)
{
    G3D::Vector3 value(0.0f, 0.0f, 0.0f);
    std::string text(strValue);
    return RBX::StringConverter<G3D::Vector3>::convertToValue(text, value);
}

// Inactive native 2008-06 property-grid rows: ContentItem<T> constructors, Vector3Item::OnAfterEdit and update.
#include <afxwin.h>
#include <afxdlgs.h>
#include <string>

// NEEDS-DECL: template<class T> struct RBX::StringConverter { static bool convertToValue(const std::string&, T&); };

// 0043e840 / 0043ea20: constructors of the ContentItem<T> template, instantiated explicitly.
template ContentItem<RBX::Soundscape::SoundId>::ContentItem(const RBX::Reflection::TypedPropertyDescriptor<RBX::Soundscape::SoundId>* property, CPropGrid* grid);
template ContentItem<RBX::TextureId>::ContentItem(const RBX::Reflection::TypedPropertyDescriptor<RBX::TextureId>* property, CPropGrid* grid);



#include "CPropGrid.h"

IMPLEMENT_DYNAMIC(CPropGrid, CXTPPropertyGrid)

CPropGrid::CPropGrid() : dataModel(NULL), posted(false), dirty(false)
{
    m_bHelpVisible = FALSE;
}

CPropGrid::~CPropGrid()
{
}

// Template members emitted by this unit (bodies byte-identical to the 2008-06 client).
template class RBX::Listener<RBX::Instance,RBX::PropertyChanged>;
template class std::_Container_base_aux_alloc_real<std::allocator<std::pair<RBX::Reflection::ClassDescriptor const * const,std::vector<boost::shared_ptr<RBX::Instance>,std::allocator<boost::shared_ptr<RBX::Instance> > > > > >;
template class std::_Container_base_aux_alloc_real<std::allocator<std::pair<RBX::Reflection::PropertyDescriptor const * const,CPropGrid::Item *> > >;
template class std::_Container_base_aux_alloc_real<std::allocator<std::pair<void * const,void *> > >;
template class std::_Tmap_traits<RBX::Reflection::ClassDescriptor const *,std::vector<boost::shared_ptr<RBX::Instance>,std::allocator<boost::shared_ptr<RBX::Instance> > >,std::less<RBX::Reflection::ClassDescriptor const *>,std::allocator<std::pair<RBX::Reflection::ClassDescriptor const * const,std::vector<boost::shared_ptr<RBX::Instance>,std::allocator<boost::shared_ptr<RBX::Instance> > > > >,0>;
template class std::_Tmap_traits<RBX::Reflection::PropertyDescriptor const *,CPropGrid::Item *,std::less<RBX::Reflection::PropertyDescriptor const *>,std::allocator<std::pair<RBX::Reflection::PropertyDescriptor const * const,CPropGrid::Item *> >,0>;
template class std::_Tmap_traits<void *,void *,std::less<void *>,std::allocator<std::pair<void * const,void *> >,0>;
template class std::_Tree<std::_Tmap_traits<RBX::Reflection::ClassDescriptor const *,std::vector<boost::shared_ptr<RBX::Instance>,std::allocator<boost::shared_ptr<RBX::Instance> > >,std::less<RBX::Reflection::ClassDescriptor const *>,std::allocator<std::pair<RBX::Reflection::ClassDescriptor const * const,std::vector<boost::shared_ptr<RBX::Instance>,std::allocator<boost::shared_ptr<RBX::Instance> > > > >,0> >;
template class std::_Tree<std::_Tmap_traits<RBX::Reflection::PropertyDescriptor const *,CPropGrid::Item *,std::less<RBX::Reflection::PropertyDescriptor const *>,std::allocator<std::pair<RBX::Reflection::PropertyDescriptor const * const,CPropGrid::Item *> >,0> >;
template class std::_Tree<std::_Tmap_traits<void *,void *,std::less<void *>,std::allocator<std::pair<void * const,void *> >,0> >;
template class std::_Vector_val<boost::shared_ptr<RBX::Instance>,std::allocator<boost::shared_ptr<RBX::Instance> > >;
template class std::allocator<std::_Tree_nod<std::_Tmap_traits<RBX::Reflection::ClassDescriptor const *,std::vector<boost::shared_ptr<RBX::Instance>,std::allocator<boost::shared_ptr<RBX::Instance> > >,std::less<RBX::Reflection::ClassDescriptor const *>,std::allocator<std::pair<RBX::Reflection::ClassDescriptor const * const,std::vector<boost::shared_ptr<RBX::Instance>,std::allocator<boost::shared_ptr<RBX::Instance> > > > >,0> >::_Node *>;
template class std::allocator<std::_Tree_nod<std::_Tmap_traits<RBX::Reflection::PropertyDescriptor const *,CPropGrid::Item *,std::less<RBX::Reflection::PropertyDescriptor const *>,std::allocator<std::pair<RBX::Reflection::PropertyDescriptor const * const,CPropGrid::Item *> >,0> >::_Node *>;
template class std::allocator<std::_Tree_nod<std::_Tmap_traits<void *,void *,std::less<void *>,std::allocator<std::pair<void * const,void *> >,0> >::_Node *>;
template class std::allocator<std::pair<RBX::Reflection::ClassDescriptor const * const,std::vector<boost::shared_ptr<RBX::Instance>,std::allocator<boost::shared_ptr<RBX::Instance> > > > >;
template class std::allocator<std::pair<RBX::Reflection::PropertyDescriptor const * const,CPropGrid::Item *> >;
template class std::allocator<std::pair<void * const,void *> >;
template class std::map<RBX::Reflection::ClassDescriptor const *,std::vector<boost::shared_ptr<RBX::Instance>,std::allocator<boost::shared_ptr<RBX::Instance> > >,std::less<RBX::Reflection::ClassDescriptor const *>,std::allocator<std::pair<RBX::Reflection::ClassDescriptor const * const,std::vector<boost::shared_ptr<RBX::Instance>,std::allocator<boost::shared_ptr<RBX::Instance> > > > > >;
template class std::map<RBX::Reflection::PropertyDescriptor const *,CPropGrid::Item *,std::less<RBX::Reflection::PropertyDescriptor const *>,std::allocator<std::pair<RBX::Reflection::PropertyDescriptor const * const,CPropGrid::Item *> > >;
template class std::map<void *,void *,std::less<void *>,std::allocator<std::pair<void * const,void *> > >;

// 2008-06 native XBoolItem editor row (inactive until owner integration).
#include "PropertyGridItems.h"

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
