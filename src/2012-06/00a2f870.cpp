// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /MD /GS /EHsc /Ob1
// roc-lib: xtp-11.2.2-lib-strlen Source\ReportControl\XTPReportNavigator.cpp

// Candidate translation unit (score above; library headers required).
// XTPReportNavigator.cpp : implementation of the CXTPReportNavigator class.
//
// This file is a part of the XTREME REPORTCONTROL MFC class library.
// (c)1998-2007 Codejock Software, All Rights Reserved.
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

#include "Common/XTPResourceManager.h"
#include "Common/XTPDrawHelpers.h"
#include "Common/XTPImageManager.h"
#include "Common/XTPVC80Helpers.h"

#include "XTPReportNavigator.h"
#include "XTPReportControl.h"
#include "XTPReportRecord.h"
#include "XTPReportRecordItem.h"
#include "XTPReportColumn.h"
#include "XTPReportColumns.h"
#include "XTPReportInplaceControls.h"


#ifdef _DEBUG
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#define new DEBUG_NEW
#endif


//////////////////////////////////////////////////////////////////////
// CXTPReportNavigator

CXTPReportNavigator::CXTPReportNavigator(CXTPReportControl* pReportControl)
	: m_pReportControl(pReportControl), m_bCurrentFocusInHeadersRows(FALSE), m_bCurrentFocusInFootersRows(FALSE)
{

}

CXTPReportNavigator::~CXTPReportNavigator()
{
}

void CXTPReportNavigator::MoveDown(BOOL bSelectBlock, BOOL bIgnoreSelection)
{
	if  (!m_pReportControl)
		return;

	CXTPReportRow* pNextRow = NULL;
	CXTPReportRow* pFocusedRow = m_pReportControl->GetFocusedRow();

	if (m_bCurrentFocusInHeadersRows)
	{
		pNextRow = m_pReportControl->m_pHeaderRows->GetNext(pFocusedRow, m_pReportControl->m_bSkipGroupsFocus);

		// from the last header row jump to the first visible body row
		if (pFocusedRow == pNextRow)
		{
			MoveFirstVisibleRow(xtpRowTypeBody);
		}
		else
		{
			m_pReportControl->SetFocusedRow(pNextRow, bSelectBlock, bIgnoreSelection);
		}
	}
	else if (m_bCurrentFocusInFootersRows)
	{
		m_pReportControl->SetFocusedRow(
				m_pReportControl->m_pFooterRows->GetNext(pFocusedRow, m_pReportControl->m_bSkipGroupsFocus),
				bSelectBlock,
				bIgnoreSelection);
	}
	else
	{
		// body rows
		pNextRow = m_pReportControl->m_pRows->GetNext(pFocusedRow, m_pReportControl->m_bSkipGroupsFocus);

		if (pNextRow)
		{
			// from the last body row jump to the first header row
			if (m_pReportControl->m_nFocusedRow == pNextRow->GetIndex())
			{
				if (m_pReportControl->IsFooterRowsVisible() && m_pReportControl->IsFooterRowsAllowAccess())
					MoveFirstVisibleRow(xtpRowTypeFooter);
			}
			else
			{
				m_pReportControl->SetFocusedRow(pNextRow, bSelectBlock, bIgnoreSelection);
			}
		}
	}
}

void CXTPReportNavigator::MoveUp(BOOL bSelectBlock, BOOL bIgnoreSelection)
{
	if  (!m_pReportControl)
		return;

	CXTPReportRow* pPrevRow = NULL;
	CXTPReportRow* pFocusedRow = m_pReportControl->GetFocusedRow();

	if (m_bCurrentFocusInHeadersRows)
	{
		m_pReportControl->SetFocusedRow(
			m_pReportControl->m_pHeaderRows->GetPrev(pFocusedRow, m_pReportControl->m_bSkipGroupsFocus),
			bSelectBlock,
			bIgnoreSelection);
	}
	else if (m_bCurrentFocusInFootersRows)
	{
		pPrevRow = m_pReportControl->m_pFooterRows->GetPrev(pFocusedRow, m_pReportControl->m_bSkipGroupsFocus);

		// from the first footer row jump to the last visible body row
		if (pFocusedRow == pPrevRow)
		{
			MoveLastVisibleRow(xtpRowTypeBody);
		}
		else
		{
			m_pReportControl->SetFocusedRow(pPrevRow, bSelectBlock, bIgnoreSelection);
		}
	}
	else
	{
		// body rows
		pPrevRow = m_pReportControl->m_pRows->GetPrev(pFocusedRow, m_pReportControl->m_bSkipGroupsFocus);

		if (pPrevRow)
		{
			// from the first body row jump to the last header row
			if (m_pReportControl->m_nFocusedRow == pPrevRow->GetIndex())
			{
				if (m_pReportControl->IsHeaderRowsVisible() && m_pReportControl->IsHeaderRowsAllowAccess())
					MoveLastVisibleRow(xtpRowTypeHeader);
			}
			else
			{
				m_pReportControl->SetFocusedRow(pPrevRow, bSelectBlock, bIgnoreSelection);
			}
		}
	}
}

void CXTPReportNavigator::MovePageDown(BOOL bSelectBlock, BOOL bIgnoreSelection)
{
	if  (!m_pReportControl)
		return;

	int nCurrentRowIndex = m_pReportControl->m_nFocusedRow != -1 ? m_pReportControl->m_nFocusedRow : 0;
	nCurrentRowIndex = min(
		m_pReportControl->m_pRows->GetCount() - 1,
		nCurrentRowIndex + m_pReportControl->GetReportAreaRows(nCurrentRowIndex, true));

	m_pReportControl->SetFocusedRow(
		m_pReportControl->m_pRows->GetAt(nCurrentRowIndex),
		bSelectBlock,
		bIgnoreSelection);
}

void CXTPReportNavigator::MovePageUp(BOOL bSelectBlock, BOOL bIgnoreSelection)
{
	if  (!m_pReportControl)
		return;

	int nCurrentRowIndex = m_pReportControl->m_nFocusedRow != -1 ? m_pReportControl->m_nFocusedRow : 0;
	nCurrentRowIndex = max(0, nCurrentRowIndex - m_pReportControl->GetReportAreaRows(nCurrentRowIndex, false));

	m_pReportControl->SetFocusedRow(
		m_pReportControl->m_pRows->GetAt(nCurrentRowIndex),
		bSelectBlock,
		bIgnoreSelection);
}

void CXTPReportNavigator::MoveFirstRow(BOOL bSelectBlock, BOOL bIgnoreSelection)
{
	if  (!m_pReportControl)
		return;

	m_pReportControl->SetFocusedRow(
		m_pReportControl->m_pRows->GetAt(0),
		bSelectBlock,
		bIgnoreSelection);
}

void CXTPReportNavigator::MoveLastRow(BOOL bSelectBlock, BOOL bIgnoreSelection)
{
	if  (!m_pReportControl)
		return;

	m_pReportControl->SetFocusedRow(
		m_pReportControl->m_pRows->GetAt(m_pReportControl->m_pRows->GetCount() - 1),
		bSelectBlock,
		bIgnoreSelection);
}

void CXTPReportNavigator::MoveToRow(int nRowIndex, BOOL bSelectBlock, BOOL bIgnoreSelection)
{
	if  (!m_pReportControl)
		return;

	int nCurrentRowIndex = max(0, nRowIndex);
	nCurrentRowIndex = min(nCurrentRowIndex, m_pReportControl->m_pRows->GetCount() - 1);
	if (nCurrentRowIndex < 0)
	{
		return;
	}

	m_pReportControl->SetFocusedRow(
		m_pReportControl->m_pRows->GetAt(nCurrentRowIndex),
		bSelectBlock,
		bIgnoreSelection);
}


void CXTPReportNavigator::BeginEdit()
{
	if  (!m_pReportControl)
		return;

	m_pReportControl->AdjustScrollBars();
	m_pReportControl->RedrawControl();
	m_pReportControl->UpdateWindow();

	CXTPReportRow* pFocusedRow = m_pReportControl->GetFocusedRow();

	if (m_pReportControl->m_pFocusedColumn &&
		pFocusedRow && pFocusedRow->GetRecord())
	{
		XTP_REPORTRECORDITEM_ARGS itemArgs(m_pReportControl, pFocusedRow, m_pReportControl->m_pFocusedColumn);

		if (itemArgs.pItem && itemArgs.pItem->IsAllowEdit(&itemArgs))
		{
			if (!m_pReportControl->IsVirtualMode())
			{
				m_pReportControl->EnsureVisible(pFocusedRow);
			}

			m_pReportControl->EditItem(&itemArgs);

			if (m_pReportControl->GetInplaceEdit()->GetSafeHwnd() &&
				m_pReportControl->GetInplaceEdit()->GetItem() == itemArgs.pItem)
			{
				CXTPReportRecordItemEditOptions* pEditOptions = itemArgs.pItem->GetEditOptions(itemArgs.pColumn);
				if (pEditOptions && pEditOptions->m_bSelectTextOnEdit)
				{
					m_pReportControl->GetInplaceEdit()->SetSel(0, -1);
				}
				else
				{
					CString str;
					m_pReportControl->GetInplaceEdit()->GetWindowText(str);
					m_pReportControl->GetInplaceEdit()->SetSel(str.GetLength(), str.GetLength());
				}
			}
		}
	}
}

void CXTPReportNavigator::MoveLeftRight(BOOL bBack, BOOL bSelectBlock, BOOL bIgnoreSelection)
{
	if  (!m_pReportControl)
		return;

	CXTPReportControl::CUpdateContext updateContext(m_pReportControl);

	CXTPReportRow* pFocusedRow = m_pReportControl->GetFocusedRow();
	CXTPReportColumn* pFocusedColumn = m_pReportControl->GetNextFocusableColumn(pFocusedRow,
		m_pReportControl->m_pFocusedColumn ? m_pReportControl->m_pFocusedColumn->GetIndex() : -1,
		bBack ? -1 : 1);

	if (pFocusedColumn)
	{
		m_pReportControl->SetFocusedColumn(pFocusedColumn);
	}
	else
	{
		CXTPReportRows* pRows;
		int nFocusedRow = m_pReportControl->GetFocusedRow() ? m_pReportControl->GetFocusedRow()->GetIndex() : -1;
		switch(pFocusedRow->GetType())
		{
			case xtpRowTypeHeader : pRows = m_pReportControl->GetHeaderRows(); break;
			case xtpRowTypeFooter : pRows = m_pReportControl->GetFooterRows(); break;
			default : pRows = m_pReportControl->GetRows(); break;
		}
		CXTPReportRow* pRow = bBack ? pRows->GetPrev(pFocusedRow, FALSE) : pRows->GetNext(pFocusedRow, FALSE);
		if (pRow && pRow->GetIndex() != nFocusedRow)
		{
			m_pReportControl->SetFocusedRow(pRow, bSelectBlock, bIgnoreSelection);
			m_pReportControl->SetFocusedColumn(
				m_pReportControl->GetNextFocusableColumn(
					m_pReportControl->GetFocusedRow(),
					bBack ? m_pReportControl->m_pColumns->GetCount() : -1,
					bBack ? -1 : +1)
				);
		}
	}
}

void CXTPReportNavigator::MoveLeft(BOOL bSelectBlock, BOOL bIgnoreSelection)
{
	MoveLeftRight(TRUE, bSelectBlock, bIgnoreSelection);
}

void CXTPReportNavigator::MoveRight(BOOL bSelectBlock, BOOL bIgnoreSelection)
{
	MoveLeftRight(FALSE, bSelectBlock, bIgnoreSelection);
}

void CXTPReportNavigator::MoveFirstColumn()
{
	if  (!m_pReportControl)
		return;

	CXTPReportControl::CUpdateContext updateContext(m_pReportControl);
	CXTPReportRow* pFocusedRow = m_pReportControl->GetFocusedRow();
	CXTPReportColumn* pFocusedColumn = m_pReportControl->GetNextFocusableColumn(pFocusedRow, -1, +1);
	if (pFocusedColumn)
	{
		m_pReportControl->SetFocusedColumn(pFocusedColumn);
	}
}

void CXTPReportNavigator::MoveLastColumn()
{
	if  (!m_pReportControl)
		return;

	CXTPReportControl::CUpdateContext updateContext(m_pReportControl);
	CXTPReportRow* pFocusedRow = m_pReportControl->GetFocusedRow();
	CXTPReportColumn* pFocusedColumn = m_pReportControl->GetNextFocusableColumn(pFocusedRow, m_pReportControl->GetColumns()->GetCount(), -1);
	if (pFocusedColumn)
	{
		m_pReportControl->SetFocusedColumn(pFocusedColumn);
	}
}

void CXTPReportNavigator::MoveToColumn(int nColumnIndex, BOOL bClearIfNonFocusable)
{
	if (!m_pReportControl)
	{
		return;
	}

	nColumnIndex = max(0, nColumnIndex);
	nColumnIndex = min(nColumnIndex, m_pReportControl->GetColumns()->GetCount()-1);
	if (nColumnIndex < 0)
	{
		return;
	}

	CXTPReportControl::CUpdateContext updateContext(m_pReportControl);

	CXTPReportRow* pFocusedRow = m_pReportControl->GetFocusedRow();
	CXTPReportColumn* pColumn = m_pReportControl->GetColumns()->GetAt(nColumnIndex);
	if (!pColumn)
	{
		return;
	}

	CXTPReportRecordItem* pItem = pFocusedRow->GetRecord()->GetItem(pColumn);

	if (!pItem || !pItem->IsFocusable())
	{
		if (bClearIfNonFocusable)
		{
			pColumn = NULL;
		}
		else
		{
			return;
		}
	}

	m_pReportControl->SetFocusedColumn(pColumn);
}

void CXTPReportNavigator::SetCurrentFocusInHeadersRows(BOOL bCurrentFocusInHeadersRows)
{
	if(m_pReportControl->m_bHeaderRecordsVisible && m_pReportControl->m_bHeaderRowsAllowAccess)
	{
		m_bCurrentFocusInHeadersRows = bCurrentFocusInHeadersRows;
	}
	else
	{
		m_bCurrentFocusInHeadersRows = FALSE;
	}


	if (m_bCurrentFocusInHeadersRows)
	{
		MoveFirstVisibleRow(xtpRowTypeHeader);
	}
	else if (!m_bCurrentFocusInFootersRows && m_pReportControl->m_bHeaderRowsAllowAccess)
	{
		MoveFirstVisibleRow(xtpRowTypeBody);    // neither header nor footer is active
	}
}

void CXTPReportNavigator::SetCurrentFocusInFootersRows(BOOL bCurrentFocusInFootersRows)
{
	if(m_pReportControl->m_bFooterRecordsVisible && m_pReportControl->m_bFooterRowsAllowAccess)
	{
		m_bCurrentFocusInFootersRows = bCurrentFocusInFootersRows;
	}
	else
	{
		m_bCurrentFocusInFootersRows = FALSE;
	}

	if (m_bCurrentFocusInFootersRows)
	{
		MoveFirstVisibleRow(xtpRowTypeFooter);
	}
	else if (!m_bCurrentFocusInHeadersRows && m_pReportControl->m_bFooterRowsAllowAccess)
	{
		MoveFirstVisibleRow(xtpRowTypeBody);    // neither header nor footer is active
	}
}

BOOL CXTPReportNavigator::GetCurrentFocusInHeadersRows()
{
	return m_bCurrentFocusInHeadersRows;
}

BOOL CXTPReportNavigator::GetCurrentFocusInFootersRows()
{
	return m_bCurrentFocusInFootersRows;
}

void CXTPReportNavigator::SetMovePosition(XTPReportRowType RowType)
{
	switch(RowType)
	{
		case xtpRowTypeBody:    m_bCurrentFocusInHeadersRows = FALSE;   m_bCurrentFocusInFootersRows = FALSE; break;
		case xtpRowTypeHeader:  m_bCurrentFocusInHeadersRows = TRUE;    m_bCurrentFocusInFootersRows = FALSE; break;
		case xtpRowTypeFooter:  m_bCurrentFocusInHeadersRows = FALSE;   m_bCurrentFocusInFootersRows = TRUE; break;
	}
}

void CXTPReportNavigator::MoveFirstVisibleRow(XTPReportRowType TargetType)
{
	switch(TargetType)
	{
		case xtpRowTypeBody:    m_pReportControl->SetFocusedRow(m_pReportControl->m_pRows->GetAt(m_pReportControl->m_nTopRow));

								break;

		case xtpRowTypeHeader:  if (m_pReportControl->m_pHeaderRows)
								{
									if (m_pReportControl->m_pHeaderRows->GetCount()>0)
										m_pReportControl->SetFocusedRow(m_pReportControl->m_pHeaderRows->GetAt(0));
								}
								break;

		case xtpRowTypeFooter:  if (m_pReportControl->m_pFooterRows)
								{
									if (m_pReportControl->m_pFooterRows->GetCount()>0)
										m_pReportControl->SetFocusedRow(m_pReportControl->m_pFooterRows->GetAt(0));
								}
								break;
	}
}

void CXTPReportNavigator::MoveLastVisibleRow(XTPReportRowType TargetType)
{
	switch(TargetType)
	{
		case xtpRowTypeBody:    {
									int nRows = m_pReportControl->GetReportAreaRows(m_pReportControl->m_nTopRow, TRUE);

									if (nRows > -1 && m_pReportControl->m_pRows->GetCount()>0)
									{
										int nIdx = min(m_pReportControl->m_nTopRow + nRows, m_pReportControl->m_pRows->GetCount()-1);

										m_pReportControl->SetFocusedRow(m_pReportControl->m_pRows->GetAt(nIdx));
									}
								}
								break;

		case xtpRowTypeHeader:  if (m_pReportControl->m_pHeaderRows && m_pReportControl->m_pHeaderRows->GetCount()>0)
								{
									m_pReportControl->SetFocusedRow(
										m_pReportControl->m_pHeaderRows->GetAt(m_pReportControl->m_pHeaderRows->GetCount()-1));

								}
								break;

		case xtpRowTypeFooter:  if (m_pReportControl->m_pFooterRows && m_pReportControl->m_pFooterRows->GetCount()>0)
								{
									m_pReportControl->SetFocusedRow(
										m_pReportControl->m_pFooterRows->GetAt(m_pReportControl->m_pFooterRows->GetCount()-1));
								}
								break;
	}
}

//////////////////////////////////////////////////////////////////////////

