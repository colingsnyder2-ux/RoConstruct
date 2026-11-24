// from server: 100% by auto
// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/ReportControl/XTPReportView.cpp

// Candidate translation unit (score above; library headers required).
// XTPReportView.cpp : implementation of the CXTPReportView class.
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

#include "XTPReportView.h"
#include "XTPReportColumn.h"
#include "XTPReportColumns.h"
#include "XTPReportRecordItem.h"
#include "XTPReportRecordItemText.h"
#include "XTPReportInplaceControls.h"
#include "XTPReportRecord.h"
#include "XTPReportRecords.h"

#include "Common/XTPVC80Helpers.h"
#include "Common/XTPResourceManager.h"
#include "Common/XTPImageManager.h"

#include "Common/Resource.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

/////////////////////////////////////////////////////////////////////////////

BEGIN_MESSAGE_MAP(CXTPReportPageSetupDialog, CPageSetupDialog)
	ON_BN_CLICKED(XTP_IDC_HEADER_FORMAT_BTN, OnBnClickedHeaderFormat)
	ON_BN_CLICKED(XTP_IDC_FOOTER_FORMAT_BTN, OnBnClickedFooterFormat)
END_MESSAGE_MAP()

CXTPReportPageSetupDialog::CXTPReportPageSetupDialog(
	CXTPReportViewPrintOptions* pOptions,
	DWORD dwFlags, CWnd* pParentWnd)
	: CPageSetupDialog(dwFlags, pParentWnd)
{
	ASSERT(pOptions);
	m_pOptions = pOptions;

	if (m_pOptions)
	{
		BOOL bIsInches = m_pOptions->IsMarginsMeasureInches();
		DWORD dwMeasure = bIsInches ? PSD_INTHOUSANDTHSOFINCHES : PSD_INHUNDREDTHSOFMILLIMETERS;

		m_psd.Flags &= ~PSD_INWININIINTLMEASURE;
		m_psd.Flags |= dwMeasure;
	}

	m_psd.Flags |= PSD_ENABLEPAGESETUPTEMPLATEHANDLE;
	m_psd.hPageSetupTemplate = (HGLOBAL)XTPResourceManager()->LoadDialogTemplate(IDD);
	ASSERT(m_psd.hPageSetupTemplate);

	if (m_pOptions)
		m_psd.rtMargin = m_pOptions->m_rcMargins;

	m_nIDHelp = CXTPReportPageSetupDialog::IDD;
}

CXTPReportPageSetupDialog::~CXTPReportPageSetupDialog()
{
}

#ifndef rad1
	#define rad1        0x0420
	#define rad2        0x0421

	#define grp4        0x0433
#endif

BOOL CXTPReportPageSetupDialog::OnInitDialog ()
{
	CPageSetupDialog::OnInitDialog();

	ASSERT(m_pOptions);

	VERIFY( m_ctrlHeaderFormat.SubclassDlgItem(XTP_IDC_HEADER_FORMAT, this) );
	VERIFY( m_ctrlFooterFormat.SubclassDlgItem(XTP_IDC_FOOTER_FORMAT, this) );

	VERIFY( m_ctrlHeaderFormatBtn.SubclassDlgItem(XTP_IDC_HEADER_FORMAT_BTN, this) );
	VERIFY( m_ctrlFooterFormatBtn.SubclassDlgItem(XTP_IDC_FOOTER_FORMAT_BTN, this) );

	if (m_pOptions && m_pOptions->GetPageHeader())
		m_ctrlHeaderFormat.SetWindowText(m_pOptions->GetPageHeader()->m_strFormatString);

	if (m_pOptions && m_pOptions->GetPageFooter())
		m_ctrlFooterFormat.SetWindowText(m_pOptions->GetPageFooter()->m_strFormatString);

	if (GetDlgItem(rad1))
		GetDlgItem(rad1)->EnableWindow(TRUE); //1056 Portrait
	if (GetDlgItem(rad2))
		GetDlgItem(rad2)->EnableWindow(TRUE); //1057 Landscape

	BOOL bIsInches = m_pOptions ? m_pOptions->IsMarginsMeasureInches() : FALSE;

	UINT uStrID = bIsInches ? XTP_IDS_REPORT_MARGINS_INCH : XTP_IDS_REPORT_MARGINS_MM;
	CString strCaption;
	CXTPResourceManager::AssertValid(XTPResourceManager()->LoadString(&strCaption, uStrID));

	if (!strCaption.IsEmpty() && GetDlgItem(grp4))
		GetDlgItem(grp4)->SetWindowText(strCaption);

	return FALSE;
}

void CXTPReportPageSetupDialog::OnOK()
{
	if (m_pOptions && m_pOptions->GetPageHeader())
		m_ctrlHeaderFormat.GetWindowText(m_pOptions->GetPageHeader()->m_strFormatString);

	if (m_pOptions && m_pOptions->GetPageFooter())
		m_ctrlFooterFormat.GetWindowText(m_pOptions->GetPageFooter()->m_strFormatString);

	if (m_pOptions)
		m_pOptions->m_rcMargins = m_psd.rtMargin;

	CPageSetupDialog::OnOK();
}

void CXTPReportPageSetupDialog::OnBnClickedHeaderFormat()
{
	CXTPPrintPageHeaderFooter::DoInsertHFFormatSpecifierViaMenu(
		this, &m_ctrlHeaderFormat, &m_ctrlHeaderFormatBtn);
}

void CXTPReportPageSetupDialog::OnBnClickedFooterFormat()
{
	CXTPPrintPageHeaderFooter::DoInsertHFFormatSpecifierViaMenu(
		this, &m_ctrlFooterFormat, &m_ctrlFooterFormatBtn);
}

/////////////////////////////////////////////////////////////////////////////
// CXTPReportView

IMPLEMENT_DYNCREATE(CXTPReportView, CView)

CXTPReportView::CXTPReportView()
{
	m_pReport = NULL;
	m_pPrintOptions = new CXTPReportViewPrintOptions();

	m_bPrintSelection = FALSE;
	m_bPaginated = FALSE;

	m_bPrintDirect = FALSE;
	m_bResizeControlWithView = TRUE;

	m_bAllowCut = TRUE;
	m_bAllowPaste = TRUE;

	m_pScrollBar = NULL;
	m_pScrollBarHor = NULL;
	m_pSlider = NULL;

	m_nStartColumn = 0;
	m_nEndColumn = 0;
	m_nStartIndex = 0;
	m_bSwithMode = FALSE;
}

CXTPReportView::~CXTPReportView()
{
	CMDTARGET_RELEASE(m_pPrintOptions);
	SAFE_DELETE(m_pReport);
}


CXTPReportControl& CXTPReportView::GetReportCtrl() const
{
	return m_pReport == NULL ? (CXTPReportControl&)m_wndReport : *m_pReport;
}

void CXTPReportView::SetReportCtrl(CXTPReportControl* pReport)
{
	if (::IsWindow(m_wndReport.GetSafeHwnd()))
		m_wndReport.DestroyWindow();

	m_pReport = pReport;
}

void CXTPReportView::SetScrollBarCtrl(CScrollBar* pScrollBar, BOOL bHor)
{
	if (bHor)
		m_pScrollBarHor = pScrollBar;
	else
		m_pScrollBar = pScrollBar;
}

void CXTPReportView::SetSliderCtrl(CSliderCtrl* pSlider)
{
	m_pSlider = pSlider;
}

BEGIN_MESSAGE_MAP(CXTPReportView, CView)
	//{{AFX_MSG_MAP(CXTPReportView)
	ON_WM_ERASEBKGND()
	ON_WM_SIZE()
	ON_WM_CREATE()
	ON_WM_SETFOCUS()
	ON_WM_PAINT()
	ON_WM_VSCROLL()
	ON_WM_HSCROLL()
	ON_COMMAND(ID_FILE_PRINT, OnFilePrint)
	ON_COMMAND(ID_EDIT_CUT, OnEditCut)
	ON_COMMAND(ID_EDIT_COPY, OnEditCopy)
	ON_COMMAND(ID_EDIT_PASTE, OnEditPaste)
	ON_UPDATE_COMMAND_UI(ID_EDIT_PASTE, OnUpdateEditPaste)
	ON_UPDATE_COMMAND_UI(ID_EDIT_COPY, OnUpdateEditCopy)
	ON_UPDATE_COMMAND_UI(ID_EDIT_CUT, OnUpdateEditCut)
	//}}AFX_MSG_MAP
END_MESSAGE_MAP()

/////////////////////////////////////////////////////////////////////////////
// CXTPReportView drawing

void CXTPReportView::OnDraw(CDC* pDC)
{
	UNREFERENCED_PARAMETER(pDC);
}

void CXTPReportView::OnPaint()
{
	Default();
}

BOOL CXTPReportView::OnEraseBkgnd(CDC* pDC)
{
	UNREFERENCED_PARAMETER(pDC);
	return TRUE;
}

/////////////////////////////////////////////////////////////////////////////
// CXTPReportView diagnostics

#ifdef _DEBUG
void CXTPReportView::AssertValid() const
{
	CView::AssertValid();
}

void CXTPReportView::Dump(CDumpContext& dc) const
{
	CView::Dump(dc);
}
#endif //_DEBUG

/////////////////////////////////////////////////////////////////////////////
// CXTPReportView message handlers

CScrollBar* CXTPReportView::GetScrollBarCtrl(int nBar) const
{
	if (nBar == SB_VERT && m_pScrollBar)
		return m_pScrollBar;

	if (nBar == SB_HORZ && m_pScrollBarHor)
		return m_pScrollBarHor;

	return CView::GetScrollBarCtrl(nBar);
}

void CXTPReportView::OnVScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	if (m_pScrollBar && pScrollBar == m_pScrollBar)
		GetReportCtrl().OnVScroll(nSBCode, nPos, 0);

	CView::OnVScroll(nSBCode, nPos, pScrollBar);
}

void CXTPReportView::OnHScroll(UINT nSBCode, UINT nPos, CScrollBar* pScrollBar)
{
	if (m_pScrollBarHor && pScrollBar == m_pScrollBarHor)
		GetReportCtrl().OnHScroll(nSBCode, nPos, 0);

	CView::OnHScroll(nSBCode, nPos, pScrollBar);
}

void CXTPReportView::OnSize(UINT nType, int cx, int cy)
{
	CView::OnSize(nType, cx, cy);

	int nScroll = GetSystemMetrics(SM_CXVSCROLL);

	int dx = 0;
	if (GetPaintManager()->m_bMoveScrollbarOnFixedColumnsIndent)
		dx = GetPaintManager()->m_nFixedColumnsIndent;

	BOOL bV = m_pScrollBar && m_pScrollBar->GetSafeHwnd();
	BOOL bH = m_pScrollBarHor && m_pScrollBarHor->GetSafeHwnd();
	int CX = cx;

	if (bV || bH)
	{
		if (bV && bH)
		{
			cx -= nScroll;
			cy -= nScroll;
		}
		else if (bV)
		{
			cx -= nScroll;
		}
		else if (bH)
		{
			cy -= nScroll;
		}

		if (GetReportCtrl().IsLayoutRTL())
		{
			if (bV)
				m_pScrollBar->MoveWindow(0, 0, nScroll, cy);
			if (bH)
				m_pScrollBarHor->MoveWindow(dx, cy, CX - dx, nScroll);
		}
		else
		{
			if (bV)
				m_pScrollBar->MoveWindow(cx, 0, nScroll, cy);
			if (bH)
				m_pScrollBarHor->MoveWindow(dx, cy, CX - dx, nScroll);
		}
		if (m_pSlider)
		{
			if (dx)
			{
				m_pSlider->MoveWindow(0, cy, dx, nScroll);
				m_pSlider->ShowWindow(SW_SHOW);
			}
			else
			{
				m_pSlider->MoveWindow(0, cy, dx, nScroll);
				m_pSlider->ShowWindow(SW_HIDE);
			}
		}
	}
	else
		nScroll = 0;

	if (m_bResizeControlWithView && GetReportCtrl().GetSafeHwnd())
	{
		if (nScroll > 0)
		{
			if (GetReportCtrl().IsLayoutRTL())
			{
				if (bV)
					GetReportCtrl().MoveWindow(nScroll, 0, cx, cy);
				else
					GetReportCtrl().MoveWindow(0, 0, cx, cy);
			}
			else
			{
				if (bV)
					GetReportCtrl().MoveWindow(0, 0, cx, cy);
				else
					GetReportCtrl().MoveWindow(0, 0, cx, cy);
			}
		}
		else
		{
			GetReportCtrl().MoveWindow(0, 0, CX, cy);
		}
	}
}

int CXTPReportView::OnCreate(LPCREATESTRUCT lpCreateStruct)
{
	if (CView::OnCreate(lpCreateStruct) == -1)
		return -1;

	if (!GetReportCtrl().Create(WS_CHILD | WS_TABSTOP | WS_VISIBLE,
		CRect(0, 0, 0, 0), this, XTP_ID_REPORT_CONTROL))
	{
		TRACE(_T("Failed to create report control window\n"));
		return -1;
	}
	return 0;
}

void CXTPReportView::OnSetFocus(CWnd* pOldWnd)
{
	CView::OnSetFocus(pOldWnd);

	if (IsWindow(GetReportCtrl().GetSafeHwnd()))
		GetReportCtrl().SetFocus();
}


/////////////////////////////////////////////////////////////////////////////

BOOL CXTPReportView::OnPreparePrinting(CPrintInfo* pInfo)
{
	if (GetReportCtrl().IsIconView())
	{
		GetReportCtrl().SetIconView(FALSE);
		m_bSwithMode = TRUE;
	}

	m_bShowRowNumber = GetReportCtrl().IsShowRowNumber();
	GetReportCtrl().ShowRowNumber(FALSE);

	if (GetReportCtrl().GetSelectedRows()->GetCount() > 0)
		pInfo->m_pPD->m_pd.Flags &= ~PD_NOSELECTION;

	pInfo->m_bDirect = m_bPrintDirect;

	// default preparation
	if (!DoPreparePrinting(pInfo))
		return FALSE;

	m_bPrintSelection = pInfo->m_pPD->PrintSelection();

	return TRUE;
}

void CXTPReportView::OnEndPrinting(CDC* /*pDC*/, CPrintInfo* /*pInfo*/)
{
	m_aPageStart.RemoveAll();

	if (m_pPrintOptions->m_bBlackWhitePrinting)
		m_bmpGrayDC.DeleteObject();

	if (m_bSwithMode)
	{
		GetReportCtrl().SetIconView(TRUE);
		m_bSwithMode = FALSE;
	}
	GetReportCtrl().ShowRowNumber(m_bShowRowNumber);
}

CXTPReportPaintManager* CXTPReportView::GetPaintManager() const
{
	return GetReportCtrl().GetPaintManager();
}

int CXTPReportView::GetColumnWidth(CXTPReportColumn* pColumnTest, int nTotalWidth)
{
	return pColumnTest->GetPrintWidth(nTotalWidth);
}

void CXTPReportView::PrintHeader(CDC* pDC, CRect rcHeader)
{
	CXTPReportColumns* pColumns = GetReportCtrl().GetColumns();

	GetPaintManager()->FillHeaderControl(pDC, rcHeader);

	int x = rcHeader.left;
	int nWidth;
	for (UINT i = m_nStartColumn; i < m_nEndColumn; i++)
	{
		CXTPReportColumn* pColumn = pColumns->GetAt(i);
		if (!pColumn->IsVisible())
			continue;

		if (GetPaintManager()->IsColumnWidthWYSIWYG())
			nWidth = pColumn->GetWidth();
		else
			nWidth = GetColumnWidth(pColumn, rcHeader.Width());
		CRect rcItem(x, rcHeader.top, x + nWidth, rcHeader.bottom);
		GetPaintManager()->DrawColumn(pDC, pColumn, GetReportCtrl().GetReportHeader(), rcItem);
		x += nWidth;
	}
}

void CXTPReportView::PrintFooter(CDC* pDC, CRect rcFooter)
{
	CXTPReportColumns* pColumns = GetReportCtrl().GetColumns();

	GetPaintManager()->FillFooter(pDC, rcFooter);

	int x = rcFooter.left;
	int nWidth(0);
	for (UINT i = m_nStartColumn; i < m_nEndColumn; i++)
	{
		CXTPReportColumn* pColumn = pColumns->GetAt(i);
		if (!pColumn->IsVisible())
			continue;

		if (GetPaintManager()->IsColumnWidthWYSIWYG())
			nWidth = pColumn->GetWidth();
		else
			nWidth = GetColumnWidth(pColumn, rcFooter.Width());
		CRect rcItem(x, rcFooter.top, x + nWidth, rcFooter.bottom);
		GetPaintManager()->DrawColumnFooter(pDC, pColumn, GetReportCtrl().GetReportHeader(), rcItem);
		x += nWidth;
	}
}

void CXTPReportView::PrintRow(CDC* pDC, CXTPReportRow* pRow, CRect rcRow, int nPreviewHeight)
{
	CXTPReportColumns* pColumns = GetReportCtrl().GetColumns();

	if (pRow->IsGroupRow())
	{
		pRow->Draw(pDC, rcRow, 0);
		return;
	}

	CXTPReportControl& wndReport = GetReportCtrl();

	XTP_REPORTRECORDITEM_DRAWARGS drawArgs;
	drawArgs.pDC = pDC;
	drawArgs.pControl = &wndReport;
	drawArgs.pRow = pRow;
	int nIndentWidth = wndReport.GetHeaderIndent();
	CXTPReportPaintManager* pPaintManager = GetPaintManager();

	// paint row background
	pPaintManager->FillRow(pDC, pRow, rcRow);

	CRect rcItem(rcRow);
	rcItem.bottom = rcItem.bottom - nPreviewHeight;

	CXTPReportRecord* pRecord = pRow->GetRecord();
	if (pRecord) // if drawing record, not group
	{
		BOOL bFirstVisibleColumn = TRUE;
		int x = rcRow.left;
		// paint record items
		for (UINT nColumn = m_nStartColumn; nColumn < m_nEndColumn; nColumn++)
		{
			CXTPReportColumn* pColumn = pColumns->GetAt(nColumn);
			if (pColumn && pColumn->IsVisible() && pRow->IsItemsVisible())
			{
				rcItem.left = x;
				if (GetPaintManager()->IsColumnWidthWYSIWYG())
					x = rcItem.right = rcItem.left + pColumn->GetWidth();
				else
					x = rcItem.right = rcItem.left + GetColumnWidth(pColumn, rcRow.Width());

				if (bFirstVisibleColumn)
				{
					rcItem.left += nIndentWidth;
					bFirstVisibleColumn = FALSE;
				}

				CRect rcGridItem(rcItem);
				rcGridItem.left--;

				CXTPReportRecordItem* pItem = pRecord->GetItem(pColumn);

				if (pItem)
				{
					drawArgs.pColumn = pColumn;
					drawArgs.rcItem = rcItem;
					drawArgs.nTextAlign = pColumn->GetAlignment();
					drawArgs.pItem = pItem;
					pItem->Draw(&drawArgs);
				}

				if (pRow->GetType() == xtpRowTypeHeader
					&& pColumn->GetDrawHeaderRowsVGrid())
					pPaintManager->DrawGrid(pDC, TRUE, rcGridItem);
				else if (pRow->GetType() == xtpRowTypeFooter
					&& pColumn->GetDrawFooterRowsVGrid())
					pPaintManager->DrawGrid(pDC, TRUE, rcGridItem);
				else
					pPaintManager->DrawGrid(pDC, TRUE, rcGridItem);
			}
		}

		if (nIndentWidth > 0)
		{
			CRect rcIndent(rcRow);
			rcIndent.right = rcRow.left + nIndentWidth;
			pPaintManager->FillIndent(pDC, rcIndent);
		}

		if (pRow->IsPreviewVisible())
		{
			CXTPReportRecordItemPreview* pItem = pRecord->GetItemPreview();

			CRect rcPreviewItem(rcRow);
			rcPreviewItem.DeflateRect(nIndentWidth, rcPreviewItem.Height() - nPreviewHeight, 0, 0);

			drawArgs.rcItem = rcPreviewItem;
			drawArgs.nTextAlign = DT_LEFT;
			drawArgs.pItem = pItem;
			drawArgs.pColumn = NULL;

			drawArgs.pItem->Draw(&drawArgs);
		}
	}

	BOOL bGridVisible = pPaintManager->IsGridVisible(FALSE);

	CRect rcFocus(rcRow.left, rcRow.top, rcRow.right, rcRow.bottom - (bGridVisible ? 1 : 0));

	if (pRow->GetIndex() < wndReport.GetRows()->GetCount() - 1 && nIndentWidth > 0)
	{
		CXTPReportRow* pNextRow = wndReport.GetRows()->GetAt(pRow->GetIndex() + 1);
		ASSERT(pNextRow);
		if (pNextRow)
			rcFocus.left = rcRow.left +  min(nIndentWidth, pPaintManager->m_nTreeIndent * pNextRow->GetTreeDepth());
	}

	pPaintManager->DrawGrid(pDC, FALSE, rcFocus);
}


int CXTPReportView::PrintRows(CDC* pDC, CRect rcClient, long nIndexStart, int* pnPrintedRowsHeight)
{
	int y = rcClient.top;
	CXTPReportRows* pRows = GetReportCtrl().GetRows();

	for (; nIndexStart < pRows->GetCount(); nIndexStart++)
	{
		CXTPReportRow* pRow = pRows->GetAt(nIndexStart);

		if (m_bPrintSelection && !pRow->IsSelected())
			continue;

		int nHeight = pRow->GetHeight(pDC, rcClient.Width());
		int nPreviewHeight = 0;

		if (pRow->IsPreviewVisible())
		{
			CXTPReportRecordItemPreview* pItem = pRow->GetRecord()->GetItemPreview();
			nPreviewHeight = pItem->GetPreviewHeight(pDC, pRow, rcClient.Width());
			nPreviewHeight = GetReportCtrl().GetPaintManager()->GetPreviewItemHeight(pDC, pRow, rcClient.Width(), nPreviewHeight);
			nHeight += nPreviewHeight;
		}

		CRect rcRow(rcClient.left, y, rcClient.right, y + nHeight);

		if (rcRow.bottom > rcClient.bottom)
			break;

		PrintRow(pDC, pRow, rcRow, nPreviewHeight);

		y += rcRow.Height();
	}

	if (pnPrintedRowsHeight != NULL)
		*pnPrintedRowsHeight = y - rcClient.top; // height of the printed rows

	return nIndexStart;
}

long CXTPReportView::PrintReport(CDC* pDC, CPrintInfo* pInfo, CRect rcPage, long nIndexStart)
{
	int nMaxPages = -1;
	if (pInfo->GetMaxPage() != 65535)
		nMaxPages = pInfo->GetMaxPage();

	int nHeaderHeight = PrintPageHeader(pDC, pInfo, rcPage, FALSE,
		pInfo->m_nCurPage, nMaxPages,
		m_nStartIndex, (int) GetPaintManager()->m_arStartCol.GetSize() - 1);

	int nFooterHeight = PrintPageFooter(pDC, pInfo, rcPage, FALSE,
		pInfo->m_nCurPage, nMaxPages,
		m_nStartIndex, (int) GetPaintManager()->m_arStartCol.GetSize() - 1);

	CRect rcRows(rcPage);

	if (GetPaintManager()->m_bPrintPageRectangle)
		rcRows.DeflateRect(1,1);

	rcRows.top += nHeaderHeight;
	rcRows.bottom -= nFooterHeight;
	int nFooterTop = rcRows.bottom;

	if (GetPaintManager()->m_bPrintWatermark)
	{
		CRect rcWater(rcRows);
		rcWater.top += GetReportCtrl().GetPaintManager()->GetHeaderHeight();
		rcWater.bottom -= GetReportCtrl().GetPaintManager()->GetFooterHeight(&GetReportCtrl(), pDC);
		GetReportCtrl().DrawWatermark(pDC, rcWater);
	}
	// print header rows (if exist and visible)
	if (GetReportCtrl().GetHeaderRows()->GetCount() > 0 && GetReportCtrl().IsHeaderRowsVisible())
	{
		// print on the first page, at least
		if (0 == nIndexStart || m_pPrintOptions->m_bRepeatHeaderRows)
		{
			rcRows.top += PrintFixedRows(pDC, rcRows, TRUE);

			// print divider
			rcRows.top += PrintFixedRowsDivider(pDC, rcRows, TRUE);
		}
	}

	// calculate space for footer rows
	int nNeedForFooterRows = 0;

	if (GetReportCtrl().GetFooterRows()->GetCount() > 0 && GetReportCtrl().IsFooterRowsVisible())
	{
		nNeedForFooterRows = GetReportCtrl().GetRowsHeight(GetReportCtrl().GetFooterRows(), rcRows.Width());
		nNeedForFooterRows += GetPaintManager()->GetFooterRowsDividerHeight();

		if (m_pPrintOptions->m_bRepeatFooterRows)
		{
			// decrease space for body rows, if footer rows to be repeated on every page.
			rcRows.bottom = nFooterTop - nNeedForFooterRows;
		}
	}
	// print body rows
	int nPrintedBodyRowsHeight = 0;
	nIndexStart = PrintRows(pDC, rcRows, nIndexStart, &nPrintedBodyRowsHeight);

	// print footer rows (if exist and visible)
	if (nNeedForFooterRows > 0)
	{
		CRect rcFooterRows(rcRows);
		rcFooterRows.top = rcRows.top + nPrintedBodyRowsHeight; //immediately after body rows
		//rcFooterRows.bottom = rcFooter.top;
		rcFooterRows.bottom = nFooterTop;

		// one more check, if there is enough space for footer divider + footer rows
		if (rcFooterRows.Height() > nNeedForFooterRows)
		{
			// print divider
			rcFooterRows.top += PrintFixedRowsDivider(pDC, rcFooterRows, FALSE);

			// print footer rows
			PrintFixedRows(pDC, rcFooterRows, FALSE);
		}
	}

	if (GetPaintManager()->m_bPrintPageRectangle)
		pDC->Draw3dRect(rcPage, 0, 0);

	return nIndexStart;
}

int CXTPReportView::PrintFixedRowsDivider(CDC* pDC, const CRect& rc, BOOL bHeaderRows)
{
	CRect rcDivider(rc);
	int nHeight = bHeaderRows ? GetPaintManager()->GetHeaderRowsDividerHeight() : GetPaintManager()->GetFooterRowsDividerHeight();

	rcDivider.bottom = rcDivider.top + nHeight;

	GetPaintManager()->DrawFixedRowsDivider(pDC, rcDivider, &GetReportCtrl(), bHeaderRows, FALSE);

	return nHeight;
}

long CXTPReportView::PrintPage(CDC* pDC, CPrintInfo* pInfo, CRect rcPage, long nIndexStart)
{
	if (!m_pPrintOptions || !pDC || !pInfo)
	{
		ASSERT(FALSE);
		return INT_MAX;
	}

	CRect rcPageHeader = rcPage;
	CRect rcPageFooter = rcPage;

	CString strTitle = CXTPPrintPageHeaderFooter::GetParentFrameTitle(this);

	int N = (int) GetPaintManager()->m_arStartCol.GetSize() - 1;
	int nVirPage(0);
	if (N > 0)
		nVirPage = 1 + m_nStartIndex;

	if (GetPaintManager()->m_bPrintVirtualPageNumber)
	{
		m_pPrintOptions->GetPageHeader()->FormatTexts(pInfo, strTitle, nVirPage);
		m_pPrintOptions->GetPageFooter()->FormatTexts(pInfo, strTitle, nVirPage);
	}
	else
	{
		m_pPrintOptions->GetPageHeader()->FormatTexts(pInfo, strTitle);
		m_pPrintOptions->GetPageFooter()->FormatTexts(pInfo, strTitle);
	}

	pDC->SetBkColor(RGB(255, 255, 255));
	m_pPrintOptions->GetPageFooter()->Draw(pDC, rcPageFooter, TRUE);
	m_pPrintOptions->GetPageHeader()->Draw(pDC, rcPageHeader);

	CRect rcReport = rcPage;
	rcReport.top += rcPageHeader.Height() + 2;
	rcReport.bottom -= rcPageFooter.Height() + 2;

	long nNextRow = PrintReport(pDC, pInfo, rcReport, nIndexStart);

	pDC->SetBkColor(RGB(255, 255, 255));
	m_pPrintOptions->GetPageFooter()->Draw(pDC, rcPageFooter);

	return nNextRow;
}

int CXTPReportView::PrintPageHeader(CDC* pDC, CPrintInfo* pInfo, CRect rcPage,
					BOOL bOnlyCalculate, int nPageNumber, int nNumberOfPages,
					int nHorizontalPageNumber, int nNumberOfHorizontalPages)
{
	UNREFERENCED_PARAMETER(pInfo);
	UNREFERENCED_PARAMETER(nPageNumber);
	UNREFERENCED_PARAMETER(nNumberOfPages);
	UNREFERENCED_PARAMETER(nHorizontalPageNumber);
	UNREFERENCED_PARAMETER(nNumberOfHorizontalPages);
	UNREFERENCED_PARAMETER(bOnlyCalculate);
	UNREFERENCED_PARAMETER(nPageNumber);
	UNREFERENCED_PARAMETER(nHorizontalPageNumber);
	UNREFERENCED_PARAMETER(nNumberOfHorizontalPages);

	int nHeaderHeight = 0;

	if (GetPaintManager()->m_bPrintPageRectangle)
		rcPage.DeflateRect(1,1);

	if (GetReportCtrl().IsHeaderVisible())
		nHeaderHeight = GetPaintManager()->GetHeaderHeight(&GetReportCtrl(), pDC, rcPage.Width());

	rcPage.bottom = rcPage.top + nHeaderHeight;

	if (nHeaderHeight)
		PrintHeader(pDC, rcPage);

	return nHeaderHeight;
}

int CXTPReportView::PrintPageFooter(CDC* pDC, CPrintInfo* pInfo, CRect rcPage,
					BOOL bOnlyCalculate, int nPageNumber, int nNumberOfPages,
					int nHorizontalPageNumber, int nNumberOfHorizontalPages)
{
	UNREFERENCED_PARAMETER(pInfo);
	UNREFERENCED_PARAMETER(nPageNumber);
	UNREFERENCED_PARAMETER(nNumberOfPages);
	UNREFERENCED_PARAMETER(nHorizontalPageNumber);
	UNREFERENCED_PARAMETER(nNumberOfHorizontalPages);
	UNREFERENCED_PARAMETER(bOnlyCalculate);
	UNREFERENCED_PARAMETER(nPageNumber);
	UNREFERENCED_PARAMETER(nHorizontalPageNumber);
	UNREFERENCED_PARAMETER(nNumberOfHorizontalPages);

	int nFooterHeight = 0;

	if (GetPaintManager()->m_bPrintPageRectangle)
		rcPage.DeflateRect(1,1);

	if (GetReportCtrl().IsFooterVisible())
		nFooterHeight = GetPaintManager()->GetFooterHeight(&GetReportCtrl(), pDC, rcPage.Width());

	rcPage.top = rcPage.bottom - nFooterHeight;

	if (nFooterHeight)
		PrintFooter(pDC, rcPage);

	return nFooterHeight;
}

int CXTPReportView::SetupStartCol(CDC* pDC, CPrintInfo* pInfo)
{
	CSize PaperPPI(pDC->GetDeviceCaps(LOGPIXELSX), pDC->GetDeviceCaps(LOGPIXELSY));
	CSize PaperSize = CSize(pDC->GetDeviceCaps(HORZRES), pDC->GetDeviceCaps(VERTRES));

	pDC->SetMapMode(MM_ANISOTROPIC);
	pDC->SetViewportExt(pDC->GetDeviceCaps(LOGPIXELSX), pDC->GetDeviceCaps(LOGPIXELSY));
	pDC->SetWindowExt(96, 96);
	pDC->OffsetWindowOrg(0, 0);

	pInfo->m_rectDraw.SetRect(0, 0, pDC->GetDeviceCaps(HORZRES), pDC->GetDeviceCaps(VERTRES));
	pDC->DPtoLP(&pInfo->m_rectDraw);

	CRect rcMargins = m_pPrintOptions->GetMarginsLP(pDC);
	CRect rc = pInfo->m_rectDraw;
	rc.DeflateRect(rcMargins);
	GetPaintManager()->m_PrintPageWidth = rc.Width();
	GetPaintManager()->m_arStartCol.RemoveAll();
	GetPaintManager()->m_arStartCol.Add(0);
	CXTPReportColumns* pColumns = GetReportCtrl().GetColumns();
	int nColumnCount = pColumns->GetCount();
	if (GetPaintManager()->IsColumnWidthWYSIWYG())
	{
		int x = 0, y = 0;
		for (int nColumn = 0; nColumn < nColumnCount; nColumn++)
		{
			CXTPReportColumn* pColumn = pColumns->GetAt(nColumn);
			if (pColumn && pColumn->IsVisible())
			{
				x = pColumn->GetWidth();
				if (y + x <= GetPaintManager()->m_PrintPageWidth)
					y += x;
				else
				{
					GetPaintManager()->m_arStartCol.Add(nColumn);
					y = x;
				}
			}
		}
	}
	GetPaintManager()->m_arStartCol.Add(nColumnCount);

	return (int) GetPaintManager()->m_arStartCol.GetSize() - 1;
}


//struct CPrintInfo // Printing information structure
//  CPrintDialog* m_pPD;     // pointer to print dialog
//  BOOL m_bPreview;         // TRUE if in preview mode
//  BOOL m_bDirect;          // TRUE if bypassing Print Dialog
//  BOOL m_bContinuePrinting;// set to FALSE to prematurely end printing
//  UINT m_nCurPage;         // Current page
//  UINT m_nNumPreviewPages; // Desired number of preview pages
//  CString m_strPageDesc;   // Format string for page number display
//  void SetMinPage(UINT nMinPage);
//  void SetMaxPage(UINT nMaxPage);
//  UINT GetMinPage() const;
//  UINT GetMaxPage() const;
//  UINT GetFromPage() const;
//  UINT GetToPage() const;
void CXTPReportView::OnBeginPrinting(CDC* pDC, CPrintInfo* pInfo)
{
	m_aPageStart.RemoveAll();
	m_aPageStart.Add(0);

	int nVirtualPages = SetupStartCol(pDC, pInfo);
	if (pInfo->m_bPreview)
	{
		pInfo->m_nNumPreviewPages = 1;
		AfxGetApp()->m_nNumPreviewPages = pInfo->m_nNumPreviewPages;
	}

	CString str1, str2;
	if (m_pPrintOptions && m_pPrintOptions->GetPageHeader())
		str1 = m_pPrintOptions->GetPageHeader()->m_strFormatString;
	if (m_pPrintOptions && m_pPrintOptions->GetPageFooter())
		str2 = m_pPrintOptions->GetPageFooter()->m_strFormatString;

	if (nVirtualPages > 1 && m_pPrintOptions->GetPageHeader()->m_strFormatString.IsEmpty())
		m_pPrintOptions->GetPageHeader()->m_strFormatString = _T(" &p/&P ");

	UINT pFr = pInfo->GetFromPage();
	UINT pTo = pInfo->GetToPage();
	if (pFr > 0)
	{
		pInfo->SetMinPage(pFr);
		pInfo->m_nCurPage = pFr;
	}
	if (pTo < 65535)
		pInfo->SetMaxPage(pTo);

	if (GetReportCtrl().m_bForcePagination)
		m_bPaginated = FALSE;
	if ((!pInfo->m_bPreview || GetReportCtrl().m_bForcePagination)
		&& (str1.Find(_T("&P")) >= 0
		|| nVirtualPages > 1
		|| pFr > 1
		|| pTo < 65535
		|| str2.Find(_T("&P")) >= 0))
	{
		m_nStartIndex = 0;
		m_nStartColumn = GetPaintManager()->m_arStartCol.GetAt(0);
		m_nEndColumn = GetPaintManager()->m_arStartCol.GetAt(1);

		int nCurPage = pInfo->m_nCurPage;
		pInfo->m_nCurPage = 65535;

		if (PaginateTo(pDC, pInfo))
			pInfo->SetMaxPage((int) m_aPageStart.GetSize() - 1 - m_nStartIndex);

		pInfo->m_nCurPage = nCurPage;
		if (GetReportCtrl().m_bForcePagination)
			m_bPaginated = TRUE;
	}
	m_nStartIndex = 0;
	m_nStartColumn = GetPaintManager()->m_arStartCol.GetAt(0);
	m_nEndColumn = GetPaintManager()->m_arStartCol.GetAt(1);
}

void CXTPReportView::OnPrint(CDC* pDC, CPrintInfo* pInfo)
{
	if (!m_pPrintOptions || !pDC || !pInfo)
	{
		ASSERT(FALSE);
		return;
	}
	CRect rcMargins = m_pPrintOptions->GetMarginsLP(pDC);
	CRect rc = pInfo->m_rectDraw;
	rc.DeflateRect(rcMargins);

	UINT nVirtualPages = (UINT) GetPaintManager()->m_arStartCol.GetSize() - 1;
	UINT nPage = pInfo->m_nCurPage;
	int nSize = (int) m_aPageStart.GetSize();

	ASSERT(nPage <= (UINT) nSize);

	UINT nIndex = m_aPageStart[nPage - 1];
	UINT mIndex(0);
//TRACE(_T("pInfo->m_nCurPage=%d nIndex=%d\n"), pInfo->m_nCurPage, nIndex);

	if (m_bPaginated)
	{
		m_nStartIndex = (pInfo->m_nCurPage - 1) % nVirtualPages;
		m_nStartColumn = GetPaintManager()->m_arStartCol.GetAt(m_nStartIndex);
		m_nEndColumn = GetPaintManager()->m_arStartCol.GetAt(m_nStartIndex + 1);
	}

	if (!m_pPrintOptions->m_bBlackWhitePrinting)
	{
		mIndex = PrintPage(pDC, pInfo, rc, nIndex);
	}
	else
	{
		CRect rc00(0, 0, rc.Width(), rc.Height());

		CDC memDC;
		VERIFY(memDC.CreateCompatibleDC(pDC));
		memDC.m_bPrinting = TRUE;

		if (!m_bmpGrayDC.m_hObject
			|| m_bmpGrayDC.GetBitmapDimension() != rc00.Size())
		{
			m_bmpGrayDC.DeleteObject();
			m_bmpGrayDC.CreateCompatibleBitmap(pDC, rc00.Width(), rc00.Height());
		}

		CXTPBitmapDC autpBmp(&memDC, &m_bmpGrayDC);

		memDC.FillSolidRect(rc00, RGB(255, 255, 255));

		mIndex = PrintPage(&memDC, pInfo, rc00, nIndex);

		int nCC = max(0, min(m_pPrintOptions->m_nBlackWhiteContrast, 255));
		XTPImageManager()->BlackWhiteBitmap(memDC, rc00, nCC);

		pDC->BitBlt(rc.left, rc.top, rc.Width(), rc.Height(), &memDC, 0, 0, SRCCOPY);
	}

	if (!m_bPaginated)
	{
		m_nStartIndex++;
		if (m_nStartIndex >= nVirtualPages) //done with the page!
			m_nStartIndex = 0;

		m_nStartColumn = GetPaintManager()->m_arStartCol.GetAt(m_nStartIndex);
		m_nEndColumn = GetPaintManager()->m_arStartCol.GetAt(m_nStartIndex + 1);

		if (m_nStartIndex > 0)
		{
			if (nPage == (UINT) nSize)
				m_aPageStart.Add(nIndex);
			else if (nPage < (UINT) nSize)
				m_aPageStart[nPage] = nIndex;
		}
		else
		{
			if (nPage == (UINT) nSize)
				m_aPageStart.Add(mIndex);
			else if (nPage < (UINT) nSize)
				m_aPageStart[nPage] = mIndex;

			if ((int) mIndex == GetReportCtrl().GetRows()->GetCount())
				pInfo->SetMaxPage(pInfo->m_nCurPage);
		}
	}
	if (pInfo->m_bPreview)
	{
//TRACE(_T("pInfo->m_nCurPage=%d\n"), pInfo->m_nCurPage);
		pInfo->m_nCurPage++;
	}
}

extern BOOL CALLBACK _XTPAbortProc(HDC, int);

BOOL CXTPReportView::PaginateTo(CDC* pDC, CPrintInfo* pInfo)
{
	ASSERT_VALID(this);
	ASSERT_VALID(pDC);

	UINT nVirtualPages = (UINT) GetPaintManager()->m_arStartCol.GetSize() - 1;
	BOOL bAborted = FALSE;
	CXTPPrintingDialog PrintStatus(this);
	CString strTemp;
	if (GetParentFrame())
		GetParentFrame()->GetWindowText(strTemp);

	PrintStatus.SetWindowText(_T("Calculating pages..."));
	PrintStatus.SetDlgItemText(AFX_IDC_PRINT_DOCNAME, strTemp);
	PrintStatus.SetDlgItemText(AFX_IDC_PRINT_PRINTERNAME, pInfo->m_pPD->GetDeviceName());
	PrintStatus.SetDlgItemText(AFX_IDC_PRINT_PORTNAME, pInfo->m_pPD->GetPortName());
	PrintStatus.ShowWindow(SW_SHOW);
	PrintStatus.UpdateWindow();

	CRect rectSave = pInfo->m_rectDraw;
	UINT nPageSave = pInfo->m_nCurPage;
	BOOL bBlackWhiteSaved = m_pPrintOptions->m_bBlackWhitePrinting;
	m_pPrintOptions->m_bBlackWhitePrinting = FALSE;

	ASSERT(nPageSave > 1);
	ASSERT(nPageSave >= (UINT) m_aPageStart.GetSize());
	VERIFY(pDC->SaveDC() != 0);

	pDC->IntersectClipRect(0, 0, 0, 0);
	UINT nCurPage = (UINT) m_aPageStart.GetSize();
	pInfo->m_nCurPage = nCurPage;

	while (pInfo->m_nCurPage < nPageSave && pInfo->m_nCurPage <= pInfo->GetMaxPage())
	{
		if (pInfo->m_bPreview)
			ASSERT(pInfo->m_nCurPage == (UINT) m_aPageStart.GetSize());

		OnPrepareDC(pDC, pInfo);

		if (!pInfo->m_bContinuePrinting)
			break;
		if (nVirtualPages > 1)
			strTemp.Format(_T("%d [%d - %d]"),
				pInfo->m_nCurPage,
				1 + (pInfo->m_nCurPage / nVirtualPages),
				1 + (pInfo->m_nCurPage % nVirtualPages));
		else
			strTemp.Format(_T("%d"), pInfo->m_nCurPage);

		PrintStatus.SetDlgItemText(AFX_IDC_PRINT_PAGENUM, strTemp);

		pInfo->m_rectDraw.SetRect(0, 0, pDC->GetDeviceCaps(HORZRES), pDC->GetDeviceCaps(VERTRES));
		pDC->DPtoLP(&pInfo->m_rectDraw);

		OnPrint(pDC, pInfo);

		if (!pInfo->m_bPreview)
			pInfo->m_nCurPage++;

		if (pInfo->GetMaxPage() == 65535)
			pInfo->SetMaxPage(max(pInfo->GetMaxPage(), pInfo->m_nCurPage));

		if (!_XTPAbortProc(0, 0))
		{
			bAborted = TRUE;
			break;
		}
	}
	PrintStatus.DestroyWindow();

	BOOL bResult = !bAborted
		&& (pInfo->m_nCurPage == nPageSave || nPageSave == 65535);

	pInfo->m_bContinuePrinting = bResult;
	pDC->RestoreDC(-1);
	m_pPrintOptions->m_bBlackWhitePrinting = bBlackWhiteSaved;
	pInfo->m_nCurPage = nPageSave;

	pInfo->m_rectDraw = rectSave;
	ASSERT_VALID(this);

	return bResult;
}

void CXTPReportView::OnPrepareDC(CDC* pDC, CPrintInfo* pInfo)
{
	ASSERT_VALID(this);
	ASSERT_VALID(pDC);
	if (!pInfo)
		return;

	if (!m_bPaginated)
	{
		int nRowCount = GetReportCtrl().GetRows()->GetCount();
		int nSize = (int) m_aPageStart.GetSize();
		int nPage = pInfo->m_nCurPage;
		UINT nVirtualPages = (UINT) GetPaintManager()->m_arStartCol.GetSize() - 1;
		UINT nVirPage(0);
		if (nVirtualPages > 0)
			nVirPage = 1 + m_nStartIndex;

		if (nPage == 1 && nRowCount == 0)                       //First page?
			pInfo->m_bContinuePrinting = TRUE;
		else if (nVirPage > 0 && nVirPage < nVirtualPages)      //not finished page
			pInfo->m_bContinuePrinting = TRUE;
		else if (nPage == nSize && m_aPageStart[nPage - 1] >= (UINT) nRowCount
			&& m_nStartIndex >= nVirtualPages - 1)              //Last page?
			pInfo->m_bContinuePrinting = FALSE;                 // can't paginate to that page
		else if (nPage > nSize
			&& m_nStartIndex > nVirtualPages - 1
			&& !PaginateTo(pDC, pInfo))                         //Can be last page?
			pInfo->m_bContinuePrinting = FALSE;                 // can't paginate to that page

		if (pInfo->m_nCurPage > pInfo->GetMaxPage())
			pInfo->m_bContinuePrinting = FALSE;
//TRACE(_T("OnPrepareDC pInfo->m_nCurPage=%d\n"), pInfo->m_nCurPage);
	}
	pDC->SetMapMode(MM_ANISOTROPIC);
	pDC->SetViewportExt(pDC->GetDeviceCaps(LOGPIXELSX), pDC->GetDeviceCaps(LOGPIXELSY));
	pDC->SetWindowExt(96, 96);
	pDC->OffsetWindowOrg(0, 0);

	if (GetReportCtrl().GetExStyle() & WS_EX_RTLREADING)
		pDC->SetTextAlign(TA_RTLREADING);

	if (GetReportCtrl().IsLayoutRTL())
		XTPDrawHelpers()->SetContextRTL(pDC, LAYOUT_RTL);
}

//////////////////////////////////////////////////////////////////////////
// Clipboard operations

void CXTPReportView::OnUpdateEditCopy(CCmdUI* pCmdUI)
{
	pCmdUI->Enable(GetReportCtrl().CanCopy());
}

void CXTPReportView::OnUpdateEditCut(CCmdUI* pCmdUI)
{
	pCmdUI->Enable(m_bAllowCut && GetReportCtrl().CanCut());
}

void CXTPReportView::OnUpdateEditPaste(CCmdUI* pCmdUI)
{
	pCmdUI->Enable(m_bAllowPaste && GetReportCtrl().CanPaste());
}

void CXTPReportView::OnEditCut()
{
	if (m_bAllowCut) GetReportCtrl().Cut();
}

void CXTPReportView::OnEditCopy()
{
	GetReportCtrl().Copy();
}

void CXTPReportView::OnEditPaste()
{
	if (m_bAllowPaste) GetReportCtrl().Paste();
}

void CXTPReportView::OnFilePageSetup()
{
	DWORD dwFlags = PSD_MARGINS | PSD_INWININIINTLMEASURE;
	CXTPReportPageSetupDialog dlgPageSetup(GetPrintOptions(), dwFlags, this);

	XTPGetPrinterDeviceDefaults(dlgPageSetup.m_psd.hDevMode, dlgPageSetup.m_psd.hDevNames);

	int nDlgRes = (int) dlgPageSetup.DoModal();

	if (nDlgRes == IDOK)
		AfxGetApp()->SelectPrinter(dlgPageSetup.m_psd.hDevNames, dlgPageSetup.m_psd.hDevMode, FALSE);
}

int CXTPReportView::PrintFixedRows(CDC* pDC, CRect rcClient, BOOL bHeaderRows)
{
	int y = rcClient.top;

	CXTPReportRows* pRows = bHeaderRows ? GetReportCtrl().GetHeaderRows() : GetReportCtrl().GetFooterRows();

	for (int i = 0; i < pRows->GetCount(); ++i)
	{
		CXTPReportRow* pRow = pRows->GetAt(i);

		int nHeight = pRow->GetHeight(pDC, rcClient.Width());

		CRect rcRow(rcClient.left, y, rcClient.right, y + nHeight);

		if (rcRow.bottom > rcClient.bottom)
			break;

		PrintRow(pDC, pRow, rcRow, 0);

		y += rcRow.Height();
	}

	return y - rcClient.top; // height of all printed rows
}

/////////////////////////////////////////////////////////////////////////////
//class CXTPReportViewPrintOptions

IMPLEMENT_DYNAMIC(CXTPReportViewPrintOptions, CXTPPrintOptions)
CXTPReportViewPrintOptions::CXTPReportViewPrintOptions()
{
	m_bRepeatHeaderRows = FALSE;
	m_bRepeatFooterRows = FALSE;

}

LCID CXTPReportViewPrintOptions::GetActiveLCID()
{
	return CXTPReportControlLocale::GetActiveLCID();
}

void CXTPReportViewPrintOptions::Set(const CXTPReportViewPrintOptions* pSrc)
{
	if (pSrc)
	{
		CXTPPrintOptions::Set(pSrc);

		m_bRepeatHeaderRows = pSrc->m_bRepeatHeaderRows;
		m_bRepeatFooterRows = pSrc->m_bRepeatFooterRows;
	}
}

