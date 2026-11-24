// from server: 100% by auto
// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/Ribbon/XTPRibbonSystemButton.cpp

// Candidate translation unit (score above; library headers required).
// XTPRibbonSystemButton.cpp : implementation file
//
// This file is a part of the XTREME RIBBON MFC class library.
// (c)1998-2009 Codejock Software, All Rights Reserved.
//
// THIS SOURCE FILE IS THE PROPERTY OF CODEJOCK SOFTWARE AND IS NOT TO BE
// RE-DISTRIBUTED BY ANY MEANS WHATSOEVER WITHOUT THE EXPRESSED WRITTEN
// CONSENT OF CODEJOCK SOFTWARE.
//
// THIS SOURCE CODE CAN ONLY BE USED UNDER THE TERMS AND CONDITIONS OUTLINED
// IN THE XTREME TOOLKIT PRO LICENSE AGREEMENT. CODEJOCK SOFTWARE GRANTS TO
// YOU (ONE SOFTWARE DEVELOPER) THE LIMITED RIGHT TO USE THIS SOFTWARE ON A
// SINGLE COMPUTER.
//
// CONTACT INFORMATION:
// support@codejock.com
// http://www.codejock.com
//
/////////////////////////////////////////////////////////////////////////////

#include "stdafx.h"
#include "Resource.h"

#include "Common/XTPOffice2007Image.h"
#include "Common/XTPIntel80Helpers.h"
#include "Common/XTPVc50Helpers.h"
#include "Common/XTPImageManager.h"
#include "Common/XTPResourceManager.h"

#include "CommandBars/XTPCommandBars.h"
#include "CommandBars/XTPControlExt.h"
#include "XTPRibbonSystemButton.h"
#include "XTPRibbonBar.h"
#include "XTPRibbonPaintManager.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

IMPLEMENT_XTP_CONTROL(CXTPRibbonControlSystemButton, CXTPControlPopup)

CXTPRibbonControlSystemButton::CXTPRibbonControlSystemButton()
{
	SetFlags(xtpFlagNoMovable | xtpFlagManualUpdate);
	m_bShowShadow = FALSE;
}

BOOL CXTPRibbonControlSystemButton::IsSimpleButton() const
{
	return GetStyle() != xtpButtonAutomatic;

}

CSize CXTPRibbonControlSystemButton::GetSize(CDC* pDC)
{
	CSize sz = CXTPControlPopup::GetSize(pDC);

	if (IsSimpleButton())
	{
		sz.cx = max(sz.cx, 54);
		sz.cy = max(sz.cy, 23);

	}

	return sz;
}

void CXTPRibbonControlSystemButton::Draw(CDC* pDC)
{
	((CXTPRibbonBar*)GetParent())->GetRibbonPaintManager()->DrawRibbonFrameSystemButton(pDC, this, GetRect());
}

BOOL CXTPRibbonControlSystemButton::OnLButtonDblClk(CPoint /*point*/)
{
	GetParent()->GetCommandBars()->ClosePopups();

	CWnd* pSite = GetParent()->GetSite();

	if (!IsSimpleButton() && (pSite->GetStyle() & WS_CHILD) == 0)
	{
		pSite->SendMessage(WM_SYSCOMMAND, SC_CLOSE | HTSYSMENU, 0);
	}
	else
	{
		OnExecute();
	}

	return TRUE;
}

void CXTPRibbonControlSystemButton::AdjustExcludeRect(CRect& rc, BOOL bVertical)
{
	CXTPRibbonBar* pRibbonBar = DYNAMIC_DOWNCAST(CXTPRibbonBar, GetParent());
	if (!pRibbonBar)
	{
		CXTPControlPopup::AdjustExcludeRect(rc, bVertical);
		return;
	}

	if (IsSimpleButton())
		return;

	if (pRibbonBar->IsCaptionVisible() && pRibbonBar->IsTabsVisible() &&
		DYNAMIC_DOWNCAST(CXTPRibbonSystemPopupBar, GetCommandBar()))
	{
		rc.bottom -= 18;
		return;
	}

	CXTPControlPopup::AdjustExcludeRect(rc, bVertical);
}

//////////////////////////////////////////////////////////////////////////

IMPLEMENT_XTP_COMMANDBAR(CXTPRibbonSystemPopupBar, CXTPPopupBar)

BEGIN_MESSAGE_MAP(CXTPRibbonSystemPopupBar, CXTPPopupBar)
	ON_WM_NCHITTEST_EX()
END_MESSAGE_MAP()

CXTPRibbonSystemPopupBar::CXTPRibbonSystemPopupBar()
{
	m_rcBorders.SetRect(6, 18, 6, 29);
	SetShowGripper(FALSE);
}

CRect CXTPRibbonSystemPopupBar::GetBorders()
{
	return m_rcBorders;
}

void CXTPRibbonSystemPopupBar::FillCommandBarEntry(CDC* pDC)
{
	CXTPClientRect rc(this);
	CXTPRibbonPaintManager* pPaintManager = GetPaintManager()->GetRibbonPaintManager();

	pPaintManager->FillSystemPopupBarEntry(pDC, this);
}

LRESULT CXTPRibbonSystemPopupBar::OnNcHitTest(CPoint point)
{
	if (!DYNAMIC_DOWNCAST(CXTPRibbonControlSystemButton, m_pControlPopup))
		return CXTPPopupBar::OnNcHitTest(point);

	CRect rcPopup = m_pControlPopup->GetRect();
	m_pControlPopup->GetParent()->ClientToScreen(rcPopup);
	if (rcPopup.PtInRect(point))
		return HTTRANSPARENT;

	return CXTPPopupBar::OnNcHitTest(point);
}

CSize CXTPRibbonSystemPopupBar::CalcDynamicLayout(int nLength, DWORD dwMode)
{
	CArray<CXTPControl*, CXTPControl*> arrButtons;
	int i;

	for (i = 0; i < GetControlCount(); i++)
	{
		CXTPControl* pControl = GetControl(i);
		if (pControl && pControl->IsKindOf(RUNTIME_CLASS(CXTPRibbonControlSystemPopupBarButton)))
		{
			arrButtons.Add(pControl);
			pControl->SetHideFlag(xtpHideDockingPosition, TRUE);
		}
	}

	CSize sz = CXTPPopupBar::CalcDynamicLayout(nLength, dwMode);

	if (arrButtons.GetSize() == 0)
		return sz;

	CClientDC dc(this);
	CXTPFontDC font(&dc, GetPaintManager()->GetCommandBarFont(this));

	int nRight = sz.cx - m_rcBorders.right + 1;

	for (i = (int)arrButtons.GetSize() - 1; i >= 0; i--)
	{
		CXTPControl* pControl = arrButtons[i];
		pControl->SetHideFlag(xtpHideDockingPosition, FALSE);

		CSize szControl = pControl->GetSize(&dc);
		pControl->SetRect(CRect(nRight - szControl.cx, sz.cy - m_rcBorders.bottom + 4, nRight, sz.cy - 3));
		nRight -= szControl.cx + 6;
	}

	return sz;
}

//////////////////////////////////////////////////////////////////////////
// CXTPRibbonControlSystemPopupBarButton

IMPLEMENT_XTP_CONTROL(CXTPRibbonControlSystemPopupBarButton, CXTPControlButton)

CXTPRibbonControlSystemPopupBarButton::CXTPRibbonControlSystemPopupBarButton()
{

}

BOOL CXTPRibbonControlSystemPopupBarButton::IsSystemPopupButton() const
{
	return m_pParent && m_pParent->IsKindOf(RUNTIME_CLASS(CXTPRibbonSystemPopupBar));
}

BOOL CXTPRibbonControlSystemPopupBarButton::IsTransparent() const
{
	if (IsSystemPopupButton())
		return TRUE;

	return CXTPControlButton::IsTransparent();
}

void CXTPRibbonControlSystemPopupBarButton::Draw(CDC* pDC)
{
	if (IsSystemPopupButton())
	{
		CXTPRibbonPaintManager* pPaintManager = GetPaintManager()->GetRibbonPaintManager();
		pPaintManager->DrawSystemPopupBarButton(pDC, this);
	}
	else
	{
		CXTPControlButton::Draw(pDC);
	}
}

CSize CXTPRibbonControlSystemPopupBarButton::GetSize(CDC* pDC)
{
	if (IsSystemPopupButton())
		return GetPaintManager()->DrawControlToolBarParent(pDC, this, FALSE);

	return CXTPControlButton::GetSize(pDC);
}

CSize CXTPRibbonControlSystemPopupBarButton::GetButtonSize() const
{
	return CSize(22, 22);
}

CSize CXTPRibbonControlSystemPopupBarButton::GetIconSize() const
{
	return CSize(16, 16);
}


//////////////////////////////////////////////////////////////////////////
// CXTPControlRecentFileList
IMPLEMENT_XTP_CONTROL(CXTPRibbonControlSystemPopupBarListItem, CXTPControlButton)

CXTPRibbonControlSystemPopupBarListItem::CXTPRibbonControlSystemPopupBarListItem()
{
	m_nWidth = 300;
	m_nHeight = 21;
	m_bAlignShortcut = FALSE;
}

CSize CXTPRibbonControlSystemPopupBarListItem::GetSize(CDC* /*pDC*/)
{
	return CSize(m_nWidth, m_nHeight);
}

void CXTPRibbonControlSystemPopupBarListItem::Draw(CDC* pDC)
{
	CXTPPaintManager* pPaintManager = (CXTPPaintManager*)GetPaintManager();

	pPaintManager->DrawControlEntry(pDC, this);

	COLORREF clrText = pPaintManager->GetControlTextColor(this);

	pDC->SetTextColor(clrText);
	pDC->SetBkMode (TRANSPARENT);

	CRect rc(GetRect());
	CRect rcText(rc.left + 7, rc.top, rc.right, rc.bottom);
	CString strText(GetCaption());

	if (m_bAlignShortcut)
	{
		if (strText.GetLength() > 2 && strText[0] == _T('&') && strText[2] == _T(' '))
		{
			pDC->DrawText(strText.Left(2), &rcText, DT_SINGLELINE | DT_VCENTER);
			DELETE_S(strText, 0, 3);
		}

		rcText.left += pDC->GetTextExtent(_T("0"), 1).cx + 7;
	}

	pDC->DrawText(strText, &rcText, DT_SINGLELINE | DT_VCENTER | DT_END_ELLIPSIS);
}

//////////////////////////////////////////////////////////////////////////
// CXTPRibbonControlSystemPopupBarPinableListItem

IMPLEMENT_XTP_CONTROL(CXTPRibbonControlSystemPopupBarPinableListItem, CXTPRibbonControlSystemPopupBarListItem)

#define  PIN_WIDTH 28

CXTPRibbonControlSystemPopupBarPinableListItem::CXTPRibbonControlSystemPopupBarPinableListItem()
{
	m_pIcons = new CXTPImageManager();

	m_pIcons->SetIcons(XTP_IDB_RIBBON_PINICON, 0, 2, 0, xtpImageNormal);

}

CXTPRibbonControlSystemPopupBarPinableListItem::~CXTPRibbonControlSystemPopupBarPinableListItem()
{
	SAFE_DELETE(m_pIcons);
}

void CXTPRibbonControlSystemPopupBarPinableListItem::Draw(CDC* pDC)
{
	CXTPPaintManager* pPaintManager = (CXTPPaintManager*)GetPaintManager();

	if (m_bSelected == TRUE_SPLITDROPDOWN)
	{
		CRect rcCheck(GetRect());
		rcCheck.left = rcCheck.right - PIN_WIDTH;

		pPaintManager->DrawRectangle(pDC, rcCheck, GetSelected(), GetPressed(), GetEnabled(), FALSE,
			FALSE, GetParent()->GetType(), GetParent()->GetPosition());
	}
	else
	{
		pPaintManager->DrawRectangle(pDC, GetRect(), GetSelected(), GetPressed(), GetEnabled(), FALSE,
			FALSE, GetParent()->GetType(), GetParent()->GetPosition());
	}

	COLORREF clrText = pPaintManager->GetControlTextColor(this);

	pDC->SetTextColor(clrText);
	pDC->SetBkMode (TRANSPARENT);

	CRect rc(GetRect());
	CRect rcText(rc.left + 7, rc.top, rc.right - PIN_WIDTH, rc.bottom);
	CString strText(GetCaption());

	if (m_bAlignShortcut)
	{
		if (strText.GetLength() > 2 && strText[0] == _T('&') && strText[2] == _T(' '))
		{
			pDC->DrawText(strText.Left(2), &rcText, DT_SINGLELINE | DT_VCENTER);
			DELETE_S(strText, 0, 3);
		}

		rcText.left += pDC->GetTextExtent(_T("0"), 1).cx + 7;
	}

	pDC->DrawText(strText, &rcText, DT_SINGLELINE | DT_VCENTER | DT_END_ELLIPSIS);


	CRect rcCheck(rc.right - PIN_WIDTH, rc.top, rc.right, rc.bottom);

	m_pIcons->GetImage(GetChecked() ? 0 : 1)->Draw(pDC, CPoint(rcCheck.CenterPoint().x - 8, rcCheck.CenterPoint().y - 8));
}

void CXTPRibbonControlSystemPopupBarPinableListItem::OnMouseMove(CPoint point)
{
	CRect rcCheck(GetRect());
	rcCheck.left = rcCheck.right - PIN_WIDTH;

	if (m_bSelected && rcCheck.PtInRect(point) && m_bSelected != TRUE_SPLITDROPDOWN)
	{
		m_bSelected = TRUE_SPLITDROPDOWN;
		RedrawParent(FALSE);
		return;
	}
	else if (m_bSelected == TRUE_SPLITDROPDOWN && !rcCheck.PtInRect(point) && GetRect().PtInRect(point))
	{
		m_bSelected = TRUE;
		RedrawParent(FALSE);
		return;
	}

	CXTPRibbonControlSystemPopupBarListItem::OnMouseMove(point);
}


BOOL CXTPRibbonControlSystemPopupBarPinableListItem::OnSetSelected(int bSelected)
{
	if (!CXTPRibbonControlSystemPopupBarListItem::OnSetSelected(bSelected))
		return FALSE;

	if (bSelected && !IsKeyboardSelected(bSelected))
	{
		CRect rcCheck(GetRect());
		rcCheck.left = rcCheck.right - PIN_WIDTH;

		CPoint point;
		GetCursorPos(&point);
		GetParent()->ScreenToClient(&point);

		if (rcCheck.PtInRect(point))
			m_bSelected = TRUE_SPLITDROPDOWN;
	}


	return TRUE;
}

void CXTPRibbonControlSystemPopupBarPinableListItem::OnLButtonUp(CPoint point)
{
	CRect rcCheck(GetRect());
	rcCheck.left = rcCheck.right - PIN_WIDTH;

	if (rcCheck.PtInRect(point))
	{
		SetChecked(!GetChecked());
		return;
	}

	CXTPRibbonControlSystemPopupBarListItem::OnLButtonUp(point);

}

//////////////////////////////////////////////////////////////////////////
// CXTPRibbonControlSystemPopupBarListCaption


IMPLEMENT_XTP_CONTROL(CXTPRibbonControlSystemPopupBarListCaption, CXTPControl)

CXTPRibbonControlSystemPopupBarListCaption::CXTPRibbonControlSystemPopupBarListCaption()
{
	SetFlags(xtpFlagManualUpdate | xtpFlagSkipFocus | xtpFlagNoMovable | xtpFlagWrapRow);
	m_nWidth = 300;
	m_nHeight = 27;
}

CSize CXTPRibbonControlSystemPopupBarListCaption::GetSize(CDC* /*pDC*/)
{
	return CSize(m_nWidth, m_nHeight);
}

void CXTPRibbonControlSystemPopupBarListCaption::Draw(CDC* pDC)
{
	CXTPPaintManager* pPaintManager = GetPaintManager();
	CXTPFontDC dont(pDC, pPaintManager->GetRegularBoldFont());

	COLORREF clrText = pPaintManager->GetControlTextColor(this);

	pDC->SetTextColor(clrText);
	pDC->SetBkMode (TRANSPARENT);

	CRect rc(GetRect());
	CRect rcText(rc.left + 7, rc.top + 4, rc.right, rc.bottom - 5);

	pDC->DrawText(GetCaption(), &rcText, DT_SINGLELINE | DT_TOP);

	pPaintManager->HorizontalLine(pDC, rc.left, rc.bottom - 6, rc.right,
		pPaintManager->GetRibbonPaintManager()->m_clrRecentFileListEdgeShadow);
	pPaintManager->HorizontalLine(pDC, rc.left, rc.bottom - 5, rc.right,
		pPaintManager->GetRibbonPaintManager()->m_clrRecentFileListEdgeHighLight);
}

IMPLEMENT_XTP_CONTROL(CXTPRibbonControlSystemRecentFileList, CXTPRibbonControlSystemPopupBarListCaption)

CXTPRibbonControlSystemRecentFileList::CXTPRibbonControlSystemRecentFileList()
{
}

CRecentFileList* CXTPRibbonControlSystemRecentFileList::GetRecentFileList()
{
	USES_PROTECTED_ACCESS(CXTPRibbonControlSystemRecentFileList, CWinApp, CRecentFileList*, m_pRecentFileList)

	return PROTECTED_ACCESS(CWinApp, AfxGetApp(), m_pRecentFileList);

}

int CXTPRibbonControlSystemRecentFileList::GetFirstMruID()
{
	return ID_FILE_MRU_FILE1;
}

UINT AFXAPI AfxGetFileTitle(LPCTSTR lpszPathName, LPTSTR lpszTitle, UINT nMax);

CString CXTPRibbonControlSystemRecentFileList::ConstructCaption(const CString& lpszTitle, int nIndex)
{
	CString strTemp;

	// double up any '&' characters so they are not underlined
	LPCTSTR lpszSrc = lpszTitle;
	LPTSTR lpszDest = strTemp.GetBuffer(lpszTitle.GetLength() * 2);

	while (*lpszSrc != 0)
	{
		if (*lpszSrc == '&')
			*lpszDest++ = '&';

		if (_istlead(*lpszSrc))
			*lpszDest++ = *lpszSrc++;
		*lpszDest++ = *lpszSrc++;
	}

	*lpszDest = 0;
	strTemp.ReleaseBuffer();

	CString strTitle;

	if (nIndex == 0)
		return strTemp;

	if (nIndex < 10)
	{
		strTitle.Format(_T("&%i %s"), nIndex, (LPCTSTR)strTemp);
	}
	else
	{
		strTitle = strTemp;
	}

	return strTitle;
}

class CXTPRibbonControlSystemRecentFileList::CControlFileItem : public CXTPRibbonControlSystemPopupBarListItem
{
public:
	CControlFileItem()
	{
		m_bAlignShortcut = TRUE;
	}
};

class CXTPRibbonControlSystemRecentFileList::CControlPinableFileItem : public CXTPRibbonControlSystemPopupBarPinableListItem
{
public:
	CControlPinableFileItem(CXTPPinableRecentFileList* pFileList, int iMRU)
	{
		m_bAlignShortcut = TRUE;
		m_iMRU = iMRU;
		m_bChecked = pFileList->m_pbPinState[iMRU];
		m_pFileList = pFileList;
	}

	void SetChecked(BOOL bChecked)
	{
		CXTPControl::SetChecked(bChecked);

		m_pFileList->m_pbPinState[m_iMRU] = bChecked;
	}

protected:
	int m_iMRU;
	CXTPPinableRecentFileList* m_pFileList;
};


void CXTPRibbonControlSystemRecentFileList::OnCalcDynamicSize(DWORD /*dwMode*/)
{
	CRecentFileList* pRecentFileList = GetRecentFileList();

	if (!pRecentFileList)
		return;

	ASSERT(pRecentFileList->m_arrNames != NULL);
	if (!pRecentFileList->m_arrNames)
		return;

	while (m_nIndex + 1 < m_pControls->GetCount())
	{
		CXTPControl* pControl = m_pControls->GetAt(m_nIndex + 1);
		if (pControl->GetID() >= GetFirstMruID() && pControl->GetID() <= GetFirstMruID() + pRecentFileList->m_nSize)
		{
			m_pControls->Remove(pControl);
		}
		else break;
	}

	if (m_pParent->IsCustomizeMode())
	{
		m_dwHideFlags = 0;
		SetEnabled(TRUE);
		return;
	}

	CString strName;
	BOOL bPinable = pRecentFileList->m_strOriginal == _T("PinableRecentFileList")  && ((CXTPPinableRecentFileList*)pRecentFileList)->m_bPinable;

	for (int iMRU = 0; iMRU < pRecentFileList->m_nSize; iMRU++)
	{
		if (pRecentFileList->m_arrNames[iMRU].IsEmpty())
			break;

		// copy file name only since directories are same
		AfxGetFileTitle(pRecentFileList->m_arrNames[iMRU], strName.GetBuffer(_MAX_PATH), _MAX_PATH);
		strName.ReleaseBuffer();

		int nId = iMRU + GetFirstMruID();

		CXTPControl* pControl = m_pControls->Add(!bPinable ? (CXTPControl*)new CControlFileItem() :
			(CXTPControl*) new CControlPinableFileItem((CXTPPinableRecentFileList*)pRecentFileList, iMRU),
			nId, _T(""), m_nIndex + iMRU + 1 , TRUE);

		pControl->SetCaption(ConstructCaption(strName, iMRU + 1));
		pControl->SetFlags(xtpFlagManualUpdate|xtpFlagShowPopupBarTip);
		pControl->SetTooltip(pRecentFileList->m_arrNames[iMRU]);
		pControl->SetParameter(pRecentFileList->m_arrNames[iMRU]);
		pControl->SetDescription(NULL);
	}
}

BOOL CXTPRibbonControlSystemRecentFileList::IsCustomizeDragOverAvail(CXTPCommandBar* pCommandBar, CPoint /*point*/, DROPEFFECT& dropEffect)
{
	if (pCommandBar->GetType() != xtpBarTypePopup)
	{
		dropEffect = DROPEFFECT_NONE;
		return FALSE;
	}
	return TRUE;
}



//////////////////////////////////////////////////////////////////////////
// CXTPRibbonSystemPopupBarPage


IMPLEMENT_XTP_COMMANDBAR(CXTPRibbonSystemPopupBarPage, CXTPPopupBar)

CXTPRibbonSystemPopupBarPage::CXTPRibbonSystemPopupBarPage()
{
}

CSize CXTPRibbonSystemPopupBarPage::CalcDynamicLayout(int nLength, DWORD dwMode)
{
	CSize sz = CXTPPopupBar::CalcDynamicLayout(nLength, dwMode);

	if (!m_pControlPopup->GetParent()->IsKindOf(RUNTIME_CLASS(CXTPRibbonSystemPopupBar)))
		return sz;

	CXTPRibbonSystemPopupBar* pParent = ((CXTPRibbonSystemPopupBar*)m_pControlPopup->GetParent());

	int nHeight = CXTPClientRect(pParent).Height() - (pParent->GetBorders().top + pParent->GetBorders().bottom) - 2;

	m_nMaxHeight = nHeight;

	if (nHeight > sz.cy)
		sz.cy = nHeight;

	return sz;
}

void CXTPRibbonSystemPopupBarPage::AdjustExcludeRect(CRect& rc, BOOL bVertical)
{
	if (!m_pControlPopup->GetParent()->IsKindOf(RUNTIME_CLASS(CXTPRibbonSystemPopupBar)))
	{
		CXTPPopupBar::AdjustExcludeRect(rc, bVertical);
		return;
	}

	rc.top = ((CXTPRibbonSystemPopupBar*)m_pControlPopup->GetParent())->GetBorders().top + 1;
	rc.right += 1;
}


//////////////////////////////////////////////////////////////////////////
// CXTPPinableRecentFileList

CXTPPinableRecentFileList::CXTPPinableRecentFileList(UINT nStart, LPCTSTR lpszSection, LPCTSTR lpszEntryFormat, int nSize, int nMaxDispLen)
	: CRecentFileList(nStart, lpszSection, lpszEntryFormat, nSize, nMaxDispLen)
{

	m_pbPinState = new BOOL[nSize];
	memset(m_pbPinState, 0, m_nSize * sizeof(BOOL));
	m_strOriginal = _T("PinableRecentFileList");

	m_bPinable = TRUE;

}

CXTPPinableRecentFileList::~CXTPPinableRecentFileList()
{
	delete[] m_pbPinState;
}

BOOL AFXAPI AfxFullPath(LPTSTR lpszPathOut, LPCTSTR lpszFileIn);
BOOL AFXAPI AfxComparePath(LPCTSTR lpszPath1, LPCTSTR lpszPath2);

void CXTPPinableRecentFileList::Add(LPCTSTR lpszPathName)
{
	ASSERT(m_arrNames != NULL);
	ASSERT(lpszPathName != NULL);
	ASSERT(AfxIsValidString(lpszPathName));

	// fully qualify the path name
	TCHAR szTemp[_MAX_PATH];
	AfxFullPath(szTemp, lpszPathName);

	int iMRU = 0;
	BOOL bPinState = FALSE;

	// update the MRU list, if an existing MRU string matches file name
	for (; iMRU < m_nSize-1; iMRU++)
	{
		if (AfxComparePath(m_arrNames[iMRU], szTemp))
		{
			bPinState = m_pbPinState[iMRU];
			break;      // iMRU will point to matching entry
		}
	}

	if (iMRU == m_nSize - 1) // Not found
	{
		for (; iMRU >= 0; iMRU--)
		{
			if (!m_pbPinState[iMRU])
				break;
		}
	}

	if (iMRU < 0)
		return;

	// move MRU strings before this one down
	for (; iMRU > 0; iMRU--)
	{
		ASSERT(iMRU > 0);
		ASSERT(iMRU < m_nSize);
		m_arrNames[iMRU] = m_arrNames[iMRU - 1];
		m_pbPinState[iMRU] = m_pbPinState[iMRU - 1];
	}
	// place this one at the beginning
	m_arrNames[0] = szTemp;
	m_pbPinState[0] = bPinState;
}

void CXTPPinableRecentFileList::Remove(int nIndex)
{
	ASSERT(nIndex >= 0);
	ASSERT(nIndex < m_nSize);

	if (m_pbPinState[nIndex])
		return;

	m_arrNames[nIndex].Empty();
	m_pbPinState[nIndex] = FALSE;

	int iMRU(0);
	for (iMRU = nIndex; iMRU < m_nSize - 1; iMRU++)
	{
		m_arrNames[iMRU] = m_arrNames[iMRU + 1];
		m_pbPinState[iMRU] = m_pbPinState[iMRU + 1];
	}

	ASSERT(iMRU < m_nSize);
	m_arrNames[iMRU].Empty();
	m_pbPinState[iMRU] = FALSE;
}

void CXTPPinableRecentFileList::WriteList()
{
	ASSERT(m_arrNames != NULL);
	ASSERT(!m_strSectionName.IsEmpty());
	ASSERT(!m_strEntryFormat.IsEmpty());
	LPTSTR pszEntry = new TCHAR[m_strEntryFormat.GetLength() + 7];

	CWinApp* pApp = AfxGetApp();
	pApp->WriteProfileString(m_strSectionName, NULL, NULL);

	for (int iMRU = 0; iMRU < m_nSize; iMRU++)
	{
		wsprintf(pszEntry, m_strEntryFormat, iMRU + 1);
		if (!m_arrNames[iMRU].IsEmpty())
		{
			pApp->WriteProfileString(m_strSectionName, pszEntry, m_arrNames[iMRU]);

			if (m_pbPinState[iMRU])
			{
				wsprintf(pszEntry, _T("Pinned%d"), iMRU + 1);
				pApp->WriteProfileInt(m_strSectionName, pszEntry, 1);
			}
		}
	}
	delete[] pszEntry;
}

void CXTPPinableRecentFileList::ReadList()
{
	ASSERT(m_arrNames != NULL);
	ASSERT(!m_strSectionName.IsEmpty());
	ASSERT(!m_strEntryFormat.IsEmpty());
	LPTSTR pszEntry = new TCHAR[m_strEntryFormat.GetLength() + 7];
	CWinApp* pApp = AfxGetApp();
	for (int iMRU = 0; iMRU < m_nSize; iMRU++)
	{
		wsprintf(pszEntry, m_strEntryFormat, iMRU + 1);
		m_arrNames[iMRU] = pApp->GetProfileString(m_strSectionName, pszEntry, _T(""));

		wsprintf(pszEntry, _T("Pinned%d"), iMRU + 1);
		m_pbPinState[iMRU] = pApp->GetProfileInt(m_strSectionName, pszEntry, FALSE);
	}
	delete[] pszEntry;
}

