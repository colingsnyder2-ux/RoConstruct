#include "CRobloxDHtmlDialog.h"
#include "util/Http.h"
#include <exdispid.h>

IMPLEMENT_DYNAMIC(CRobloxDHtmlDialog, CDHtmlDialog)

BEGIN_EVENTSINK_MAP(CRobloxDHtmlDialog, CDHtmlDialog)
    ON_EVENT(CRobloxDHtmlDialog, 102, DISPID_BEFORENAVIGATE2, BeforeNavigate2,
        VTS_DISPATCH VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PVARIANT VTS_PBOOL)
    ON_EVENT(CRobloxDHtmlDialog, 102, DISPID_WINDOWCLOSING, WindowClosing, VTS_BOOL VTS_PBOOL)
END_EVENTSINK_MAP()

__declspec(noinline) HRESULT __cdecl checkDialogUrl(const char* url)
{
    return RBX::Http::trustCheck(url) ? S_OK : E_FAIL;
}

CRobloxDHtmlDialog::CRobloxDHtmlDialog(UINT dialog, UINT html, CWnd* parent)
    : CDHtmlDialog(dialog, html, parent)
{
    m_bUseHtmlTitle = TRUE;
    SetHostFlags(m_dwHostFlags | 0x01844013);
}

CRobloxDHtmlDialog::CRobloxDHtmlDialog(UINT dialog, const char* location, CWnd* parent)
    : CDHtmlDialog(dialog, 0x72, parent), url(location)
{
    m_bUseHtmlTitle = TRUE;
    SetHostFlags(m_dwHostFlags | 0x01844013);
}

int CRobloxDHtmlDialog::OnInitDialog(void)
{
    CDHtmlDialog::OnInitDialog();
    if (url.length() != 0)
    {
        const char* (std::string::*pc)() const = &std::string::c_str;
        Navigate((url.*pc)(), 0, 0, 0, 0, 0);
        return 0;
    }
    return 1;
}

BOOL CRobloxDHtmlDialog::IsExternalDispatchSafe()
{
    return TRUE;
}

void CRobloxDHtmlDialog::BeforeNavigate2(LPDISPATCH browser, VARIANT* location,
    VARIANT*, VARIANT*, VARIANT*, VARIANT*, BOOL* cancel)
{
    extern long __cdecl checkDialogUrl(const char*);
    CString address(location->bstrVal);
    const char* (ATL::CSimpleStringT<char, 1>::*text)() const = &ATL::CSimpleStringT<char, 1>::operator const char*;
    if (checkDialogUrl((address.*text)()))
        *cancel = 1;
    else
        OnBeforeNavigate(browser, (address.*text)());
}

void CRobloxDHtmlDialog::WindowClosing(BOOL, BOOL* cancel)
{
    *cancel = -1;
    CString result;
    DDX_DHtml_ElementText("DialogResult", DISPID_A_VALUE, result, TRUE);
    const char* (ATL::CSimpleStringT<char, 1>::*text)() const = &ATL::CSimpleStringT<char, 1>::operator const char*;
    if (result.Compare("") != 0 && atoi((result.*text)()) == 1)
        OnOK();
    else
        OnCancel();
}

#include "AppLeaves2008/IDEDocManager2008.h"
#include <afxpriv.h>
#include <stdexcept>

void reportDocumentException(const std::exception& error);   // 00428850 (DocumentException.cpp)

BOOL CIDEDocManager::DoPromptFileName(CString& fileName, UINT nIDSTitle, DWORD lFlags, BOOL bOpenFileDialog,
                                      CDocTemplate* pTemplate)
{
    if (pTemplate == NULL)
        pTemplate = playTemplate;
    return CDocManager::DoPromptFileName(fileName, nIDSTitle, lFlags, bOpenFileDialog, pTemplate);
}

void CIDEDocManager::OnFileNew()
{
    pendingPlayError.reset();
    CDocument* document = playTemplate->OpenDocumentFile(NULL, TRUE);
    try
    {
        throwPendingPlayError();
    }
    catch (std::exception& e)
    {
        reportDocumentException(e);
        AfxMessageBox(AFX_IDP_FAILED_TO_CREATE_DOC);
        if (document)
            document->OnCloseDocument();
    }
}

template class boost::scoped_ptr<std::exception>;

#include "CBrowserDocManager.h"
#include "CBrowserDoc.h"
#include "CBrowserFrameWnd.h"
#include "CBrowserView.h"

CBrowserDocManager::CBrowserDocManager()
{
    browserTemplate = new CSingleDocTemplate(0xb9,
        RUNTIME_CLASS(CBrowserDoc), RUNTIME_CLASS(CBrowserFrameWnd),
        RUNTIME_CLASS(CPlayBrowserView));
    AddDocTemplate(browserTemplate);
}

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

template class std::_Container_base_aux_alloc_real<std::allocator<CRobloxControlColorSelector::CColorInfo> >;
template class std::_Vector_const_iterator<CRobloxControlColorSelector::CColorInfo,std::allocator<CRobloxControlColorSelector::CColorInfo> >;
template class std::_Vector_iterator<CRobloxControlColorSelector::CColorInfo,std::allocator<CRobloxControlColorSelector::CColorInfo> >;
