// from server: 100% by tester
// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/ReportControl/XTPReportRow.cpp

// Candidate translation unit (score above; library headers required).
// XTPReportRow.cpp : implementation of the CXTPReportRow class.
//
// This file is a part of the XTREME REPORTCONTROL MFC class library.
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

#include "Common/XTPDrawHelpers.h"
#include "Common/XTPToolTipContext.h"

#include "XTPReportRecord.h"
#include "XTPReportControl.h"
#include "XTPReportPaintManager.h"
#include "XTPReportRow.h"
#include "XTPReportColumns.h"
#include "XTPReportColumn.h"
#include "XTPReportRecordItem.h"
#include "XTPReportRecordItemText.h"
#include "XTPReportTip.h"
#include "XTPReportInplaceControls.h"
#include "XTPReportHeader.h"

//<<TC>>
#include "Common/Resource.h"
#include "Common/XTPResourceManager.h"
//<<TC>>

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

IMPLEMENT_DYNAMIC(CXTPReportRow, CCmdTarget)
/////////////////////////////////////////////////////////////////////////////
// CXTPReportRow


CXTPReportRow::CXTPReportRow()
	: m_pParentRow(NULL), m_pRecord(NULL), m_pControl(NULL), m_pParentRows(NULL)
{
	m_nGroupLevel = m_nRowLevel = 0;


	m_bVisible = FALSE;

	m_pChilds = NULL;
	m_bExpanded = TRUE;

	m_rcRow.SetRectEmpty();
	m_rcCollapse.SetRectEmpty();
	m_nChildIndex = m_nIndex = -1;
	m_bHasSelectedChilds = FALSE;

	m_nPreviewHeight = 0;
	m_nRowType = xtpRowTypeBody;
 //<<TC>>
	m_nFreeHeight = 0;
 //<<TC>>
	EnableAutomation();

}

void CXTPReportRow::InitRow(CXTPReportControl* pControl, CXTPReportRecord* pRecord)
{
	ASSERT(pRecord || IsGroupRow());

	m_pControl = pControl;
 //<<TC>>
	if (m_pControl->m_bFreeHeightMode)
		m_nFreeHeight = m_pControl->m_nDefaultRowFreeHeight;
 //<<TC>>
	if (pRecord)
	{
		m_pRecord = pRecord;
		m_bExpanded = pRecord->m_bExpanded;
		m_pRecord->InternalAddRef();
	}
}

void CXTPReportRow::InitRow(CXTPReportRow* pRow)
{
	ASSERT(pRow->m_pRecord);
	ASSERT(pRow->m_pParentRow == NULL);

	m_pControl = pRow->m_pControl;
	m_pRecord = pRow->m_pRecord;
	if (m_pRecord)
		m_pRecord->InternalAddRef();
	m_rcRow = pRow->m_rcRow;
	m_nIndex = pRow->m_nIndex;
	m_nPreviewHeight = pRow->m_nPreviewHeight;
	m_nRowLevel = pRow->m_nRowLevel;
	m_nGroupLevel = pRow->m_nGroupLevel;
//<<TC>>
	if (m_pControl->m_bFreeHeightMode)
		m_nFreeHeight = m_pControl->m_nDefaultRowFreeHeight;
 //<<TC>>
}


CXTPReportRows* CXTPReportRow::GetChilds(BOOL bCreate)
{
	if (!m_pChilds && bCreate)
		m_pChilds = new CXTPReportRows();

	return m_pChilds;
}



CXTPReportRow::~CXTPReportRow()
{
	if (m_pChilds)
		m_pChilds->InternalRelease();

	if (m_pRecord)
		m_pRecord->InternalRelease();
}

int CXTPReportRow::GetHeight(CDC* pDC, int nWidth)
{
	ASSERT(m_pControl);
	if (!m_pControl)
		return 0;
	int nHeight = m_pControl->GetPaintManager()->GetRowHeight(pDC, this, nWidth);

	if (!IsGroupRow() && !IsItemsVisible())
		nHeight = 0;

	if (pDC->IsPrinting())
		return nHeight;

	m_nPreviewHeight = 0;

	if (IsPreviewVisible())
	{
		CXTPReportRecordItemPreview* pItem = GetRecord()->GetItemPreview();

		m_nPreviewHeight = pItem->GetPreviewHeight(pDC, this, m_pControl->GetReportHeader()->GetWidth());
		m_nPreviewHeight = m_pControl->GetPaintManager()->GetPreviewItemHeight(pDC, this, m_pControl->GetReportHeader()->GetWidth(), m_nPreviewHeight);

		return nHeight + m_nPreviewHeight;
	}

	return nHeight;
}


BOOL CXTPReportRow::IsFocused() const
{
	switch (m_nRowType)
	{
		case xtpRowTypeBody:
			return m_pControl->m_nFocusedRow == m_nIndex;
		case xtpRowTypeHeader:
			return m_pControl->m_nFocusedHeaderRow == m_nIndex;
		case xtpRowTypeFooter:
			return m_pControl->m_nFocusedFooterRow == m_nIndex;
	}

	return FALSE;
}

BOOL CXTPReportRow::IsSelected() const
{
	return m_pControl->GetSelectedRows()->Contains(this);
}

void CXTPReportRow::SetSelected(BOOL bSelected)
{
	if (bSelected == IsSelected())
		return;

	if (bSelected)
	{
		if (!m_pControl->IsMultipleSelection())
			m_pControl->GetSelectedRows()->Clear();

		m_pControl->GetSelectedRows()->Add(this);
	}
	else
	{
		m_pControl->GetSelectedRows()->Remove(this);
	}

	m_pControl->RedrawControl();
}

int CXTPReportRow::GetLastChildRow(CXTPReportRows* pChilds) const
{
	CXTPReportRow* pRow = pChilds->GetAt(pChilds->GetCount() - 1);

	if (!pRow)
		return -1;

	if (pRow->HasChildren() && pRow->IsExpanded())
		return GetLastChildRow(pRow->GetChilds());

	return pRow->GetIndex();
}

void CXTPReportRow::SelectChilds()
{
	BOOL bM = m_pControl->IsMultipleSelection();
	BOOL bC = HasChildren();
	BOOL bE = IsExpanded();
	if (!(bM && bC && bE && m_nIndex != -1))
		return;

	m_pControl->BeginUpdate();

	int nIndexBegin = m_nIndex + 1;
	int nIndexEnd = GetLastChildRow(GetChilds());

	m_pControl->GetSelectedRows()->AddBlock(nIndexBegin, nIndexEnd);

	m_pControl->EndUpdate();
}

BOOL CXTPReportRow::IsItemsVisible() const
{
	return TRUE;
}


BOOL CXTPReportRow::IsPreviewVisible() const
{
	return !IsGroupRow()
		&& m_pRecord
		&& m_pControl->IsPreviewMode()
		&& !m_pControl->IsIconView()
		&& m_pRecord->GetItemPreview();
}

void CXTPReportRow::Draw(CDC* pDC, CRect rcRow, int nLeftOffset)
{
	ASSERT(m_pControl);
	if (!m_pControl)
		return;

	BOOL bControlFocused = m_pControl->HasFocus();
	int nFreezeCols = m_pControl->m_nFreezeColumnsCount;
	CRect rcClipBox = m_pControl->GetReportRectangle();
	int nIconColumnIndex = -1;
	CXTPReportColumn* pRecNumCol = m_pControl->GetColumns()->Find(m_pControl->m_iColumnForNum);
	if (pRecNumCol)
		nIconColumnIndex = pRecNumCol->GetIndex();

	m_rcRow = rcRow;
	m_rcRow.left -= nLeftOffset;
	m_rcRow.right -= nLeftOffset;

	if (nFreezeCols == 0)
		rcRow = m_rcRow;

	XTP_REPORTRECORDITEM_DRAWARGS drawArgs;
	drawArgs.pDC = pDC;
	drawArgs.pControl = m_pControl;
	drawArgs.pRow = this;
	int nIndentWidth = m_pControl->GetHeaderIndent();
	CXTPReportPaintManager* pPaintManager = m_pControl->GetPaintManager();

	CXTPReportColumns arrVisibleColumns(m_pControl);
	m_pControl->GetColumns()->GetVisibleColumns(arrVisibleColumns);
	int nVisColCount = arrVisibleColumns.GetCount();
	nFreezeCols = min(nFreezeCols, nVisColCount);

	// paint row background
	CRect rcFullRow(m_rcRow);
	rcFullRow.right += nLeftOffset;
	pPaintManager->FillRow(pDC, this, rcFullRow);

	CRect rcItem(m_rcRow.left, m_rcRow.top, m_rcRow.right, m_rcRow.bottom - m_nPreviewHeight);

	CRect rcIndent(nFreezeCols ? rcRow : m_rcRow);
	rcIndent.right = rcIndent.left + nIndentWidth;

	if (m_pRecord) // if drawing record, not group
	{
		int xMinCol_0 = rcRow.left + nIndentWidth;
		// paint record items
		for (int nColumn = nVisColCount - 1; nColumn >= 0; nColumn--)
		{
			BOOL bFreezeCol = nColumn < nFreezeCols;
			int nColIdx = bFreezeCol ? nFreezeCols - 1 - nColumn : nColumn;

			CXTPReportColumn* pColumn = arrVisibleColumns.GetAt(nColIdx);
			ASSERT(pColumn && pColumn->IsVisible());

			if (pColumn && IsItemsVisible())
			{
				rcItem.left = pColumn->GetRect().left;
				if (nColIdx == 0)
					rcItem.left = max(xMinCol_0, rcItem.left);
				rcItem.right = pColumn->GetRect().right;

				if (!CRect().IntersectRect(rcClipBox, rcItem))
					continue;

				if (bFreezeCol)
				{
					pDC->FillSolidRect(rcItem, pPaintManager->GetControlBackColor(GetControl()));
					pPaintManager->FillRow(pDC, this, rcItem);
				}

				CRect rcGridItem(rcItem);
				rcGridItem.left--;

				// draw shade background if sorted by this row
				if (pColumn->IsSorted())
					pPaintManager->FillItemShade(pDC, rcItem);

				CXTPReportRecordItem* pItem = m_pRecord->GetItem(pColumn);

				if (pItem)
				{
					// draw item
					drawArgs.pColumn = pColumn;
					drawArgs.rcItem = rcItem;
					drawArgs.nTextAlign = pColumn->GetAlignment();
					drawArgs.pItem = pItem;
					// draw item
					int nItemTextWidth = pItem->Draw(&drawArgs);

					pColumn->m_nMaxItemWidth = max(pColumn->m_nMaxItemWidth, nItemTextWidth);
				}
				else if (m_pControl->IsIconView()
					&& !m_pControl->IsVirtualMode())
				{
					// IconView - non Virtual Mode!
					pItem = new CXTPReportRecordItemIcon();
					drawArgs.pColumn = pColumn;
					drawArgs.rcItem = rcItem;
					CXTPReportColumn* pDataColumn = m_pControl->GetColumns()->GetAt(m_pControl->m_iIconPropNum);
					CXTPReportRecordItem* pDataItem = GetRecord()->GetItem(m_pControl->m_iIconPropNum);
					if (pDataColumn != NULL && pDataItem != NULL)
					{
						pItem->SetCaption(pDataItem->GetCaption(pDataColumn));
						pItem->SetIconIndex(m_pControl->m_iIconNum);
					}
					drawArgs.pItem = pItem;
					pItem->Draw(&drawArgs);
					delete pItem;
				}
				else if (nIconColumnIndex > -1
					&& !m_pControl->IsIconView()
					&& !m_pControl->IsVirtualMode()) //no Item! (ghost)
				{
					CRect rcIcon = m_pControl->GetColumns()->GetAt(nIconColumnIndex)->GetRect();
					rcIcon.top = m_rcRow.top;
					rcIcon.bottom = m_rcRow.bottom - m_nPreviewHeight;
					rcIcon.left = 0;
					pPaintManager->DrawRowNumber(pDC, rcIcon, this);
				}

				pPaintManager->DrawGrid(pDC, TRUE, rcGridItem);

				if (nColIdx == nFreezeCols - 1)
					pPaintManager->DrawFreezeColsDivider(pDC, rcGridItem, GetControl(), this);
			}
		}

		if (IsPreviewVisible())
		{
			CRect rcPreviewItem(m_rcRow);
			rcPreviewItem.DeflateRect(nIndentWidth, rcPreviewItem.Height() - m_nPreviewHeight, 0, 0);

			drawArgs.rcItem = rcPreviewItem;
			drawArgs.nTextAlign = DT_LEFT;
			drawArgs.pItem = m_pRecord->GetItemPreview();
			drawArgs.pColumn = NULL;

			drawArgs.pItem->Draw(&drawArgs);
		}

		if (nIndentWidth > 0) // draw indent column
			pPaintManager->FillIndent(pDC, rcIndent);
	}

	BOOL bGridVisible = pPaintManager->IsGridVisible(FALSE);

	CRect rcFocus(rcIndent.right, m_rcRow.top, m_rcRow.right, m_rcRow.bottom - (bGridVisible ? 1 : 0));

	if (!m_pControl->IsIconView()
		&& IsFocused()
		&& bControlFocused
		&& m_pControl->IsRowFocusVisible())
		pPaintManager->DrawFocusedRow(pDC, rcFocus);

	if (m_nIndex < m_pControl->GetRows()->GetCount() - 1
		&& nIndentWidth > 0)
	{
		CXTPReportRow* pNextRow = m_pControl->GetRows()->GetAt(m_nIndex + 1);
		ASSERT(pNextRow);
		if (pNextRow)
			rcFocus.left = rcIndent.left + min(nIndentWidth, pPaintManager->m_nTreeIndent * pNextRow->GetTreeDepth());
	}
	else
	{
		rcFocus.left = m_rcRow.left;
	}

	pPaintManager->DrawGrid(pDC, FALSE, rcFocus);

//<<TC>>
	if (m_pControl->m_bTrackControlMode)
	{
		m_rcRow.left += nLeftOffset;
		m_rcRow.right += nLeftOffset;
	}
//<<TC>>
}

int CXTPReportRow::GetTreeDepth() const
{
	return m_nRowLevel;
}

INT_PTR CXTPReportRow::OnToolHitTest(CPoint point, TOOLINFO* pTI)
{
	CRect rcItem;
	CXTPReportRecordItem* pItem = HitTest(point, &rcItem);

	if (!pItem)
		return -1;

	INT_PTR nHit = (INT_PTR) pItem;
	CString strTip = pItem->GetTooltip();

	m_pControl->OnGetToolTipInfo(this, pItem, strTip);

	if (strTip.IsEmpty() || strTip == _T(" "))
		return -1;

	if (m_pControl->GetPaintManager()->m_bCleanTooltip)
	{
		//Clean markup
		CString s(strTip), u, v;
		int j = s.Find(_T("<"));
		int k = s.Find(_T(">"));
		while (j > -1 && k > -1)
		{
			u = s.Left(j);
			v = s.Mid(k + 1);
			s = u + v;
			strTip = s;
			j = s.Find(_T("<"));
			k = s.Find(_T(">"));
		}
	}

	CXTPToolTipContext::FillInToolInfo(pTI, m_pControl->m_hWnd, rcItem, nHit, strTip);

	return nHit;
}

BOOL CXTPReportRow::OnLButtonDown(XTP_REPORTRECORDITEM_CLICKARGS* pClickArgs)
{
//<<TC>>
	if (m_pControl->m_bFreeHeightMode)
	{
		if (m_pControl->GetFocusedRow() == this)
		{
			XTPReportMouseMode mouseMode = m_pControl->GetMouseMode();
			if (mouseMode == xtpReportMouseOverRowDivide)
			{
				m_pControl->SetCapture();
				m_pControl->SetMouseMode(xtpReportMouseNothing);
				CPoint point = pClickArgs->ptClient;
				m_pControl->ClientToScreen(&point);
				CRect rcControl = m_pControl->GetReportRectangle();
				CRect rcRow(GetRect());
				rcRow.right = rcControl.right;
				m_pControl->ClientToScreen(&rcRow);
				m_pControl->ClientToScreen(&rcControl);

				//CXTPSplitterTracker tracker(TRUE, FALSE);
				CXTPSplitterTracker tracker(TRUE, m_pControl->m_bDesktopTrackerMode);

				CRect rcBound(rcRow.left, rcRow.top + m_pControl->m_nDefaultRowFreeHeight, rcRow.right, point.y);
				CRect rcTracker(rcRow.left, point.y - 2, rcRow.right, point.y - 1);
				CRect rcAvail(rcRow.left, rcRow.top + m_pControl->m_nDefaultRowFreeHeight, rcRow.right, rcControl.bottom);
				tracker.SetBoundRect(rcBound);
				if (tracker.Track(m_pControl, rcAvail, rcTracker, point, FALSE))
				{
					m_nFreeHeight = rcTracker.bottom - rcRow.top;
					
					if (GetRecord())
						GetRecord()->m_nFreeHeight = m_nFreeHeight;

					m_pControl->RedrawControl();
				}
				return TRUE;
			}
		}
	}
//<<TC>>

	if (pClickArgs->pItem && pClickArgs->pItem->OnLButtonDown(pClickArgs))
		return TRUE;

	return (BOOL)m_pControl->SendMessageToParent(this, pClickArgs->pItem, pClickArgs->pColumn, XTP_NM_REPORT_LBUTTONDOWN, &pClickArgs->ptClient);
}

BOOL CXTPReportRow::OnLButtonUp(XTP_REPORTRECORDITEM_CLICKARGS* pClickArgs)
{
//<<TC>>
	if (m_pControl->m_bFreeHeightMode)
	{
		m_pControl->SetMouseMode(xtpReportMouseNothing);
		ReleaseCapture();
	}
//<<TC>>

	if (pClickArgs->pItem)
		pClickArgs->pItem->OnLButtonUp(pClickArgs);

	return TRUE;
}

void CXTPReportRow::OnClick(CPoint ptClicked)
{
	XTP_REPORTRECORDITEM_CLICKARGS clickArgs;
	clickArgs.pControl = m_pControl;
	clickArgs.pRow = this;
	clickArgs.ptClient = ptClicked;
	clickArgs.pColumn = NULL;

	// find clicked item
	clickArgs.pItem = HitTest(ptClicked, &clickArgs.rcItem, &clickArgs.pColumn);

	if (m_pControl->IsVirtualMode())
	{
		//if (m_nRowLevel == 0 && m_rcCollapse.PtInRect(ptClicked) //old restriction for 2-levels case only
		if (m_rcCollapse.PtInRect(ptClicked)
			&& clickArgs.pColumn && clickArgs.pColumn->IsTreeColumn()
			&& m_rcCollapse.PtInRect(m_pControl->m_ptMouseDown))
		{
			m_pControl->SendMessageToParent(this, NULL, clickArgs.pColumn, XTP_NM_REPORT_ROWEXPANDED, NULL);
			return;
		}
	}
	if (HasChildren() && m_rcCollapse.PtInRect(ptClicked)
		&& clickArgs.pColumn && clickArgs.pColumn->IsTreeColumn()
		&& m_rcCollapse.PtInRect(m_pControl->m_ptMouseDown))
	{
		SetExpanded(!IsExpanded());
		return;
	}

	// notify item if found
	if (!clickArgs.pItem)
		return;

	clickArgs.pItem->OnClick(&clickArgs);
}

void CXTPReportRow::OnDblClick(CPoint ptClicked)
{
	XTP_REPORTRECORDITEM_CLICKARGS clickArgs;
	clickArgs.pControl = m_pControl;
	clickArgs.pRow = this;
	clickArgs.ptClient = ptClicked;
	clickArgs.pColumn = NULL;

	// find clicked item
	clickArgs.pItem = HitTest(ptClicked, &clickArgs.rcItem, &clickArgs.pColumn);

	// notify item if found
	if (clickArgs.pItem != NULL)
	{
		clickArgs.pItem->OnDblClick(&clickArgs);
	}
	else
	{
		// just notify parent
		m_pControl->SendMessageToParent(this, NULL, clickArgs.pColumn, NM_DBLCLK, &ptClicked, -1);
	}
}

CRect CXTPReportRow::GetItemRect(CXTPReportRecordItem* pItem)
{
	if (!IsItemsVisible() || !pItem || !m_pRecord)
		return CRect(0, 0, 0, 0);

	if (IsPreviewVisible() && pItem == GetRecord()->GetItemPreview())
	{
		return CRect(m_rcRow.left + m_pControl->GetHeaderIndent(),
			m_rcRow.bottom - m_nPreviewHeight, m_rcRow.right, m_rcRow.bottom);
	}

	CXTPReportColumns* pColumns = m_pControl->GetColumns();
	int nColumnCount = pColumns->GetCount();

	CRect rcItem(0, m_rcRow.top, 0, m_rcRow.bottom - m_nPreviewHeight);

	int nFreezeColCount = m_pControl->GetFreezeColumnsCount();
	if (nFreezeColCount > m_pControl->GetColumns()->GetCount() - 1)
	{
		m_pControl->SetFreezeColumnsCount(0);
		nFreezeColCount = 0;
	}

	int nLeft = nFreezeColCount ? pColumns->GetAt(nFreezeColCount - 1)->GetRect().right : 0;

	for (int nColumn = 0; nColumn < nColumnCount; nColumn++)
	{
		CXTPReportColumn* pColumn = pColumns->GetAt(nColumn);
		if (pColumn && pColumn->IsVisible())
		{
			if (m_pRecord->GetItem(pColumn) != pItem)
				continue;

			rcItem.left = pColumn->GetRect().left;
			rcItem.right = pColumn->GetRect().right;
			if (pColumn->GetIndex() >= nFreezeColCount)
			{
				rcItem.left = max(rcItem.left, nLeft);
				rcItem.right = max(rcItem.right, nLeft);
			}
			if (rcItem.Width() <= 0)
				return CRect(0, 0, 0, 0);
			ShiftTreeIndent(rcItem, pColumn);
			return rcItem;
		}
	}
	return CRect(0, 0, 0, 0);
}

void CXTPReportRow::ShiftTreeIndent(CRect& rcItem, CXTPReportColumn* pColumn) const
{
	if (pColumn->IsTreeColumn())
	{
		int nTreeDepth = GetTreeDepth() - m_nGroupLevel;
		if (nTreeDepth > 0)
			nTreeDepth++;
		rcItem.left += m_pControl->GetIndent(nTreeDepth);

		CRect rcBitmap(rcItem);
		int nIndent = m_pControl->GetPaintManager()->DrawCollapsedBitmap(NULL, this, rcBitmap).cx;
		rcItem.left += nIndent + 1;
	}
}

CXTPReportRecordItem* CXTPReportRow::HitTest(CPoint ptPoint, CRect* pRectItem, CXTPReportColumn** ppColumn) const
{
	if (!m_pRecord)
		return NULL;

	// find record item
	int x = m_rcRow.left + m_pControl->GetHeaderIndent();

	CXTPReportColumns* pColumns = m_pControl->GetColumns();
	int nColumnCount = pColumns->GetCount();

	// if hittest for Preview item
	if (IsPreviewVisible())
	{
		CXTPReportRecordItemPreview* pPreviewItem = GetRecord()->GetItemPreview();
		if (pPreviewItem)
		{
			CRect rcItem(x, m_rcRow.bottom - m_nPreviewHeight, m_rcRow.right, m_rcRow.bottom);
			if (rcItem.PtInRect(ptPoint))
			{
				if (pRectItem)
				{
					*pRectItem = rcItem;
				}
				return pPreviewItem;
			}
		}
	}

	CRect rcItem(0, m_rcRow.top, 0, m_rcRow.bottom - m_nPreviewHeight);

	if (!IsItemsVisible())
		return NULL;

	int nFreezeColCount = m_pControl->GetFreezeColumnsCount();
	if (nFreezeColCount > m_pControl->GetColumns()->GetCount() - 1)
	{
		m_pControl->SetFreezeColumnsCount(0);
		nFreezeColCount = 0;
	}

	int nLeft = nFreezeColCount ? pColumns->GetAt(nFreezeColCount - 1)->GetRect().right : 0;

	for (int nColumn = 0; nColumn < nColumnCount; nColumn++)
	{
		CXTPReportColumn* pColumn = pColumns->GetAt(nColumn);
		if (pColumn && pColumn->IsVisible())
		{
			rcItem.left = pColumn->GetRect().left;
			rcItem.right = pColumn->GetRect().right;
			if (pColumn->GetIndex() >= nFreezeColCount)
			{
				rcItem.left = max(rcItem.left, nLeft);
				rcItem.right = max(rcItem.right, nLeft);
			}
			if (!rcItem.Width())
				continue;

			if (rcItem.PtInRect(ptPoint) && ppColumn)
			{
				*ppColumn = pColumn;
			}
			// make tooltip shift if tree view (see also Draw function)
			ShiftTreeIndent(rcItem, pColumn);

			// check point
			if (rcItem.PtInRect(ptPoint))
			{
				if (pRectItem)
				{
					*pRectItem = rcItem;
				}

				return m_pRecord->GetItem(pColumn);
			}
		}
	}

	return NULL;
}

void CXTPReportRow::OnMouseMove(UINT nFlags, CPoint point)
{
//<<TC>>
	if (m_pControl->m_bFreeHeightMode)
	{
		if (m_pControl->GetFocusedRow() == this)
		{
			XTPReportMouseMode mouseMode = m_pControl->GetMouseMode();
			if (mouseMode == xtpReportMouseNothing || mouseMode == xtpReportMouseOverRowDivide)
			{
				CRect rc = GetRect();
				if (rc.bottom - point.y > -2 && rc.bottom - point.y < 4)
				{
					if (mouseMode == xtpReportMouseNothing)
						SetCursor(XTPResourceManager()->LoadCursor(XTP_IDC_VSPLITBAR));

					m_pControl->SetMouseMode(xtpReportMouseOverRowDivide);
				}
				return;
			}
		}
	}
//<<TC>>

	// find clicked item
	CRect rcItem;
	CXTPReportRecordItem* pItem = HitTest(point, &rcItem);

	// notify item if found
	if (pItem != NULL)
	{
		pItem->OnMouseMove(nFlags, point, m_pControl);
	}
	//else if (IsGroupRow())
	//{
	//	CXTPReportGroupRow* pGrRow = (CXTPReportGroupRow* ) this;
	//	pGrRow->
	//}
}

void CXTPReportRow::FillMetrics(CXTPReportColumn* pColumn, CXTPReportRecordItem* pItem, XTP_REPORTRECORDITEM_METRICS* pMetrics)
{
	m_pControl->m_nLockUpdateCount++;
	XTP_REPORTRECORDITEM_DRAWARGS drawArgs;
	drawArgs.pDC = NULL;
	drawArgs.pColumn = pColumn;
	drawArgs.pControl = m_pControl;
	drawArgs.pRow = this;
	drawArgs.rcItem.SetRectEmpty();
	drawArgs.pItem = pItem;
	drawArgs.nTextAlign = pColumn ? pColumn->GetAlignment() : DT_LEFT;
	GetItemMetrics(&drawArgs, pMetrics);
	m_pControl->m_nLockUpdateCount--;
}

void CXTPReportRow::ShowToolTip(CPoint ptTip, CXTPReportTip* pTipWnd)
{
	CRect rcItem(0, 0, 0, 0);
	CXTPReportColumn* pColumn = NULL;
	CXTPReportRecordItem* pItem = HitTest(ptTip, &rcItem, &pColumn);
	// show tooltip
	if (!(pItem &&
		(pItem->IsPreviewItem() || !pItem->IsPreviewItem() && pColumn)))
	{
		pTipWnd->m_pItem = NULL;
		pTipWnd->m_nRowIndex = -1;
		return;
	}

	if (!m_pControl->IsIconView() &&
		!CXTPDrawHelpers::IsTopParentActive(m_pControl->GetSafeHwnd())
		|| m_pControl->GetActiveItem())
		return;

	if ((pItem != pTipWnd->m_pItem)
		|| (m_nIndex != pTipWnd->m_nRowIndex))
	{
		pTipWnd->m_pItem = pItem;
		pTipWnd->m_nRowIndex = m_nIndex;

		CString strTip = pItem->GetTooltip();
		m_pControl->OnGetToolTipInfo(this, pItem, strTip);

		if (!strTip.IsEmpty()
			|| strTip == _T(" ")
			|| pColumn
			&& (pColumn->GetAlignment() & DT_WORDBREAK))
			return;

		if (pItem->GetMarkupUIElement() != NULL)
			return;

		XTP_REPORTRECORDITEM_METRICS* pMetrics = new XTP_REPORTRECORDITEM_METRICS();
		pMetrics->strText = pItem->GetCaption(pColumn);
		FillMetrics(pColumn, pItem, pMetrics);

		CString strText(pMetrics->strText);

		strText.TrimRight();

		if (strText.IsEmpty())
		{
			pMetrics->InternalRelease();
			return;
		}
		if (!pItem->GetFormula().IsEmpty())
			strText = pItem->GetFormula();

		XTP_REPORTRECORDITEM_ARGS itemArgs;
		itemArgs.pControl = m_pControl;
		itemArgs.pRow = this;

		pItem->GetCaptionRect(&itemArgs, rcItem);

		m_pControl->ClientToScreen(&rcItem);

		if (!pTipWnd->GetSafeHwnd())
		{
			pTipWnd->Create(m_pControl);
		}

		CWindowDC dc(m_pControl);
		CXTPFontDC font(&dc, pMetrics->pFont);
		CRect rcTooltip(rcItem);
		BOOL bActivate = FALSE;
		if (pItem->IsPreviewItem())
		{
			CRect rcCalc(rcTooltip.left, 0, rcTooltip.right, 0);
			dc.DrawText(strText, &rcCalc, DT_WORDBREAK | DT_CALCRECT | DT_NOPREFIX);
			bActivate = (rcCalc.Height() / dc.GetTextExtent(_T(" "), 1).cy) > m_pControl->GetPaintManager()->GetMaxPreviewLines();
			rcTooltip.bottom = rcTooltip.top + rcCalc.Height();
			rcTooltip.right++;
		}
		else if (m_pControl->IsIconView())
		{
			CRect rcCalc;
			rcCalc = m_pControl->GetPaintManager()->CalculateMaxTextRect(&dc,
				pMetrics->strText, &rcItem, TRUE, FALSE, DT_NOPREFIX | DT_WORDBREAK);
			bActivate = ((rcCalc.Width() >= rcItem.Width() - 3)
				|| (rcCalc.Height() >= rcItem.Height() - 3));

			rcTooltip.bottom = rcTooltip.top + rcCalc.Height() + 5;
			rcTooltip.right = rcTooltip.left + rcCalc.Width() + 5;
		}
		else
		{
			CSize sz = dc.GetTextExtent(strText);
			bActivate = sz.cx > (rcTooltip.Width() - 4);
		}
		if (bActivate ||  m_pControl->GetPaintManager()->m_bForceShowTooltip)
		{
			rcTooltip.InflateRect(1, 1, 0, 0);

			CRect rcHover(m_rcRow);
			m_pControl->ClientToScreen(&rcHover);
			pTipWnd->SetFont(pMetrics->pFont);
			pTipWnd->SetTooltipText(strText);
			pTipWnd->SetHoverRect(m_pControl->IsIconView() ? rcHover : rcTooltip);
			pTipWnd->SetTooltipRect(rcTooltip);
			pTipWnd->Activate(TRUE, pItem->IsPreviewItem() || m_pControl->IsIconView());

			TRACKMOUSEEVENT tme =
			{
				sizeof(TRACKMOUSEEVENT), TME_LEAVE, m_pControl->GetSafeHwnd(), 0
			};
			_TrackMouseEvent (&tme);
		}

		pMetrics->InternalRelease();
	}
}

BOOL CXTPReportRow::HasParent(CXTPReportRow* pRow)
{
	if (m_pParentRow == NULL)
		return FALSE;
	if (pRow == m_pParentRow)
		return TRUE;
	return m_pParentRow->HasParent(pRow);
}

void CXTPReportRow::SetFullExpanded(BOOL bExpanded)
{
	if (bExpanded != m_bExpanded && HasChildren())
	{
		if (bExpanded)
		{
			m_pControl->_DoExpand(this);
		}
		else
		{
			m_pControl->_DoCollapse(this);
		}

		if (m_pRecord)
		{
			m_pRecord->m_bExpanded = bExpanded;
		}

		m_bExpanded = bExpanded;

		m_pControl->_RefreshIndexes();
		m_pControl->SendMessageToParent(this, NULL, NULL, XTP_NM_REPORT_ROWEXPANDED, NULL);

		int n = GetChilds()->GetCount();
		for (int i = n - 1; i >= 0; i--)
		{
			CXTPReportRow* pRow = GetChilds()->GetAt(i);
			if (pRow)
			{
				m_pControl->EndUpdate();
				m_pControl->BeginUpdate();

				pRow->SetExpanded(bExpanded, TRUE);
				m_pControl->_RefreshIndexes();
				m_pControl->SendMessageToParent(pRow, NULL, NULL, XTP_NM_REPORT_ROWEXPANDED, NULL);
			}
		}
	}
	else
	{
		m_bExpanded = bExpanded;
	}
}

void CXTPReportRow::SetExpanded(BOOL bExpanded, BOOL bRecursive)
{
	if (bExpanded != m_bExpanded && HasChildren())
	{
		if (bExpanded)
		{
			m_pControl->_DoExpand(this);
		}
		else
		{
			m_pControl->_DoCollapse(this);
		}

		if (m_pRecord)
		{
			//m_pRecord->m_bExpanded = bExpanded;
			m_pRecord->SetExpanded(bExpanded);
		}

		m_bExpanded = bExpanded;

		m_pControl->_RefreshIndexes();
		m_pControl->SendMessageToParent(this, NULL, NULL, XTP_NM_REPORT_ROWEXPANDED, NULL);

		if (bRecursive)
		{
			int n = GetChilds()->GetCount();
			for (int i = n - 1; i >= 0; i--)
			{
				CXTPReportRow* pRow = GetChilds()->GetAt(i);
				if (pRow)
				{
					m_pControl->EndUpdate();
					m_pControl->BeginUpdate();

					pRow->SetExpanded(bExpanded, bRecursive);
					m_pControl->_RefreshIndexes();
					m_pControl->SendMessageToParent(pRow, NULL, NULL, XTP_NM_REPORT_ROWEXPANDED, NULL);
				}
			}
		}
	}
	else
	{
		m_bExpanded = bExpanded;
	}
}

CXTPReportRow* CXTPReportRow::AddChild(CXTPReportRow* pRow)
{
	GetChilds()->Add(pRow);
	pRow->m_pParentRow = this;

	return pRow;
}

void CXTPReportRow::OnContextMenu(CPoint ptClick)
{
	CXTPReportColumn* pColumn = NULL;
	CXTPReportRecordItem* pItem = HitTest(ptClick, NULL, &pColumn);

	m_pControl->ClientToScreen(&ptClick);

	// send process notification to the user and wait for the reaction
	m_pControl->SendMessageToParent(this, pItem, pColumn, NM_RCLICK, &ptClick);
}

void CXTPReportRow::GetItemMetrics(XTP_REPORTRECORDITEM_DRAWARGS* pDrawArgs, XTP_REPORTRECORDITEM_METRICS* pItemMetrics)
{
	ASSERT(m_pRecord);
	ASSERT(pDrawArgs->pRow == this);
	ASSERT(pDrawArgs->pItem != NULL);
	if (!m_pRecord || !pDrawArgs->pItem)
		return;

	CXTPReportPaintManager* pPaintManager = pDrawArgs->pControl->GetPaintManager();

	pItemMetrics->pFont = &pPaintManager->m_fontText;
	pItemMetrics->clrForeground = pPaintManager->m_clrWindowText;
	pItemMetrics->clrBackground = XTP_REPORT_COLOR_DEFAULT;
	pItemMetrics->nColumnAlignment = pDrawArgs->nTextAlign;
	pItemMetrics->nItemIcon = XTP_REPORT_NOICON;

	m_pRecord->GetItemMetrics(pDrawArgs, pItemMetrics);
	pDrawArgs->pItem->GetItemMetrics(pDrawArgs, pItemMetrics);

	m_pControl->GetItemMetrics(pDrawArgs, pItemMetrics);
	pDrawArgs->nTextAlign = pItemMetrics->nColumnAlignment;

	if (IsSelected()
		&& (pDrawArgs->pDC
		&& !pDrawArgs->pDC->IsPrinting())
		&& !pDrawArgs->pControl->IsIconView())
	{
		if (pDrawArgs->pColumn
			&& IsFocused()
			&& m_pControl->m_pFocusedColumn == pDrawArgs->pColumn)
			return;

		if (GetControl()->HasFocus())
		{
			pItemMetrics->clrForeground = pPaintManager->m_clrHighlightText;
			pItemMetrics->clrBackground = pPaintManager->m_clrHighlight;
		}
		else if (!pPaintManager->m_bHideSelection)
		{
			pItemMetrics->clrForeground = pPaintManager->m_clrSelectedRowText;
			pItemMetrics->clrBackground = pPaintManager->m_clrSelectedRow;
		}
	}
}

BOOL CXTPReportRow::HasChildren() const
{
	return m_pChilds && m_pChilds->GetCount() > 0;
}

int CXTPReportRow::GetIndex() const
{
	return m_nIndex;
}

BOOL CXTPReportRow::IsGroupRow() const
{
	return FALSE;
}

BOOL CXTPReportRow::IsExpanded() const
{
	return m_bExpanded;
}

BOOL CXTPReportRow::IsLastTreeRow() const
{
	if (!m_pParentRow)
		return FALSE;

	CXTPReportRows* pRows = m_pParentRow->GetChilds();

	return pRows->GetCount() > 0 && pRows->GetAt(pRows->GetCount() - 1) == this;
}

void CXTPReportRow::EnsureVisible()
{
	m_pControl->EnsureVisible(this);
}

CXTPReportRow* CXTPReportRow::GetNextSiblingRow() const
{
	if (!m_pParentRows)
		return 0;

	if (m_nChildIndex == -1)
		return 0;

	ASSERT(m_pParentRows->GetAt(m_nChildIndex) == this);

	if (m_nChildIndex < m_pParentRows->GetCount() - 1)
		return m_pParentRows->GetAt(m_nChildIndex + 1);

	return 0;
}


void CXTPReportRow::DrawFixed(CDC* pDC, CRect rcRow, int nLeftOffset, CRect rcArea)
{
	ASSERT(m_pControl);
	if (!m_pControl)
		return;

	int nFreezeCols = m_pControl->m_nFreezeColumnsCount;

	CRect rcClipBox = rcArea;

	m_rcRow = rcRow;
	m_rcRow.left -= nLeftOffset;
	m_rcRow.right -= nLeftOffset;

	if (nFreezeCols == 0)
	{
		rcRow = m_rcRow;
	}

	XTP_REPORTRECORDITEM_DRAWARGS drawArgs;
	drawArgs.pDC = pDC;
	drawArgs.pControl = m_pControl;
	drawArgs.pRow = this;
	int nIndentWidth = m_pControl->GetHeaderIndent();

	CXTPReportPaintManager* pPaintManager = m_pControl->GetPaintManager();

	// whether to draw header's last horizontal grid depends on header divider style.
	BOOL bDrawLastHeaderGrid = TRUE;
	if (GetType() == xtpRowTypeHeader)
	{
		bDrawLastHeaderGrid = xtpReportFixedRowsDividerNone == (pPaintManager->GetHeaderRowsDividerStyle() & ~xtpReportFixedRowsDividerShade);
	}

	// whether to draw footer's first horizontal grid depends on footer divider style.
	BOOL bDrawFirstFooterGrid = TRUE;
	if (GetType() == xtpRowTypeFooter)
	{
		bDrawFirstFooterGrid = xtpReportFixedRowsDividerNone == (pPaintManager->GetFooterRowsDividerStyle() & ~xtpReportFixedRowsDividerShade);
	}

	CXTPReportColumns arrVisibleColumns(m_pControl);
	m_pControl->GetColumns()->GetVisibleColumns(arrVisibleColumns);
	int nVisColCount = arrVisibleColumns.GetCount();
	nFreezeCols = min(nFreezeCols, nVisColCount);

	// paint row background
	pDC->FillSolidRect(m_rcRow, pPaintManager->GetControlBackColor(GetControl()));

	CRect rcItem(m_rcRow.left, m_rcRow.top, m_rcRow.right, m_rcRow.bottom - m_nPreviewHeight);

	CRect rcIndent(nFreezeCols ? rcRow : m_rcRow);
	rcIndent.right = rcIndent.left + nIndentWidth;

	if (m_pRecord) // if drawing record, not group
	{
		int xMinCol_0 = rcRow.left + nIndentWidth;
		// paint record items
		for (int nColumn = nVisColCount-1; nColumn >= 0; nColumn--)
		{
			BOOL bFreezeCol = nColumn < nFreezeCols;
			int nColIdx = bFreezeCol ? nFreezeCols - 1 - nColumn : nColumn;

			CXTPReportColumn* pColumn = arrVisibleColumns.GetAt(nColIdx);
			ASSERT(pColumn && pColumn->IsVisible());

			if (pColumn && IsItemsVisible())
			{
				rcItem.left = pColumn->GetRect().left;
				if (nColIdx == 0)
				{
					rcItem.left = max(xMinCol_0, rcItem.left);
				}
				rcItem.right = pColumn->GetRect().right;

				if (!CRect().IntersectRect(rcClipBox, rcItem))
					continue;

				if (bFreezeCol)
				{
					pDC->FillSolidRect(rcItem, pPaintManager->GetControlBackColor(GetControl()));
					pPaintManager->FillRow(pDC, this, rcItem);
				}

				CRect rcGridItem(rcItem);
				rcGridItem.left--;

				// draw shade background if sorted by this row
				if (pColumn->IsSorted())
				{
					pPaintManager->FillItemShade(pDC, rcItem);
				}

				CXTPReportRecordItem* pItem = m_pRecord->GetItem(pColumn);

				if (pItem)
				{
					// draw item
					drawArgs.pColumn = pColumn;
					drawArgs.rcItem = rcItem;
					drawArgs.nTextAlign = pColumn->GetAlignment();
					drawArgs.pItem = pItem;
					// draw item
					int nItemTextWidth = pItem->Draw(&drawArgs);

					pColumn->m_nMaxItemWidth = max(pColumn->m_nMaxItemWidth, nItemTextWidth);
				}

				// is vertical grid required
				if (GetType() == xtpRowTypeHeader)
				{
					if (pColumn->GetDrawHeaderRowsVGrid())
						pPaintManager->DrawGrid(pDC, TRUE, rcGridItem);
				}
				else if (GetType() == xtpRowTypeFooter)
				{
					if (pColumn->GetDrawFooterRowsVGrid())
						pPaintManager->DrawGrid(pDC, TRUE, rcGridItem);

					if (bDrawFirstFooterGrid)
					{
						// horizontal grid above
						CRect rcTop(rcGridItem);
						rcTop.bottom = --rcGridItem.top;
						pPaintManager->DrawGrid(pDC, FALSE, rcTop);
					}
					bDrawFirstFooterGrid = TRUE;
				}
				if (nColIdx == nFreezeCols - 1)
					pPaintManager->DrawFreezeColsDivider(pDC, rcGridItem, GetControl(), this);
			}
		}

		if (nIndentWidth > 0)
		{
			// draw indent column
			pPaintManager->FillIndent(pDC, rcIndent);
		}
	}

	// draw focus
	BOOL bControlFocused = m_pControl->HasFocus();
	BOOL bGridVisible = pPaintManager->IsGridVisible(FALSE);
	CRect rcFocus(rcIndent.right, m_rcRow.top, m_rcRow.right, m_rcRow.bottom - (bGridVisible ? 1 : 0));

	if (IsFocused() && bControlFocused && m_pControl->IsRowFocusVisible())
		pPaintManager->DrawFocusedRow(pDC, rcFocus);

	// last header grid line
	if (bDrawLastHeaderGrid)
		pPaintManager->DrawGrid(pDC, FALSE, rcFocus);

//<<TC>>
	if (m_pControl->m_bTrackControlMode)
	{
		m_rcRow.left += nLeftOffset;
		m_rcRow.right += nLeftOffset;
	}
//<<TC>>
}


CCmdTarget* CXTPReportRow::GetAccessible()
{
	return this;
}

HRESULT CXTPReportRow::GetAccessibleParent(IDispatch* FAR* ppdispParent)
{
	SAFE_MANAGE_STATE(m_pModuleState);

	*ppdispParent = m_pControl->GetIDispatch(TRUE);
	return S_OK;
}

HRESULT CXTPReportRow::GetAccessibleChildCount(long FAR* pChildCount)
{
	if (pChildCount == 0)
	{
		return E_INVALIDARG;
	}
	*pChildCount = 0;

	if (m_pRecord)
	{
		*pChildCount = m_pRecord->GetItemCount();

	}

	return S_OK;
}

HRESULT CXTPReportRow::GetAccessibleChild(VARIANT varChild, IDispatch* FAR* ppdispChild)
{
	*ppdispChild = NULL;
	int nChild = GetChildIndex(&varChild);

	if (nChild <= 0)
	{
		return E_INVALIDARG;
	}

	*ppdispChild = NULL;
	return S_FALSE;
}

HRESULT CXTPReportRow::GetAccessibleName(VARIANT varChild, BSTR* pszName)
{
	int nIndex = GetChildIndex(&varChild);

	if (nIndex == CHILDID_SELF)
	{
		CString strCaption = _T("Report Row");
		*pszName = strCaption.AllocSysString();
		return S_OK;
	}

	CXTPReportRecordItem* pItem = m_pRecord->GetItem(nIndex - 1);
	if (!pItem)
		return E_INVALIDARG;

	CString strCaption = pItem->GetCaption(m_pControl->GetColumns()->Find(pItem->GetIndex()));
	*pszName = strCaption.AllocSysString();
	return S_OK;

}

HRESULT CXTPReportRow::GetAccessibleRole(VARIANT varChild, VARIANT* pvarRole)
{
	int nIndex = GetChildIndex(&varChild);

	if (nIndex == CHILDID_SELF)
	{
		pvarRole->vt = VT_I4;
		pvarRole->lVal = ROLE_SYSTEM_ROW;

	}
	else
	{
		pvarRole->vt = VT_I4;
		pvarRole->lVal = ROLE_SYSTEM_CELL;
	}
	return S_OK;
}

HRESULT CXTPReportRow::GetAccessibleState(VARIANT varChild, VARIANT* pvarState)
{
	pvarState->vt = VT_I4;
	pvarState->lVal = 0;
	int nChild = GetChildIndex(&varChild);

	if (nChild == CHILDID_SELF)
	{
		pvarState->lVal = 0;

		if (IsSelected())
			pvarState->lVal = STATE_SYSTEM_SELECTED;
	}
	else
	{
		CXTPReportRecordItem* pItem = m_pRecord->GetItem(nChild - 1);
		if (pItem)
		{
			CXTPReportColumn* pColumn = m_pControl->GetColumns()->Find(pItem->GetIndex());
			if (pColumn && !pColumn->IsVisible())
			{
				pvarState->lVal = STATE_SYSTEM_INVISIBLE;
			}
		}
	}

	return S_OK;
}


HRESULT CXTPReportRow::AccessibleLocation(long* pxLeft, long* pyTop, long* pcxWidth, long* pcyHeight, VARIANT varChild)
{
	*pxLeft = *pyTop = *pcxWidth = *pcyHeight = 0;

	CRect rc(0, 0, 0, 0);

	int nChild = GetChildIndex(&varChild);

	if (nChild == CHILDID_SELF)
	{
		rc = GetRect();
		m_pControl->ClientToScreen(&rc);
	}
	else
	{
		CXTPReportRecordItem* pItem = m_pRecord->GetItem(nChild - 1);
		if (pItem)
		{
			rc = GetItemRect(pItem);
			m_pControl->ClientToScreen(&rc);
		}

	}

	*pxLeft = rc.left;
	*pyTop = rc.top;
	*pcxWidth = rc.Width();
	*pcyHeight = rc.Height();

	return S_OK;
}

HRESULT CXTPReportRow::AccessibleHitTest(long xLeft, long yTop, VARIANT* pvarID)
{
	if (pvarID == NULL)
		return E_INVALIDARG;

	pvarID->vt = VT_I4;
	pvarID->lVal = CHILDID_SELF;

	CPoint pt(xLeft, yTop);
	m_pControl->ScreenToClient(&pt);

	if (!GetRect().PtInRect(pt))
		return S_FALSE;


	CXTPReportRecordItem* pItem = HitTest(pt);
	if (pItem)
	{
		pvarID->lVal = pItem->GetIndex() + 1;
		return S_OK;
	}

	return S_OK;
}


BEGIN_INTERFACE_MAP(CXTPReportRow, CCmdTarget)
	INTERFACE_PART(CXTPReportRow, IID_IAccessible, ExternalAccessible)
END_INTERFACE_MAP()
