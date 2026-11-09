// from server: 48% by colin
// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-11.2.2-shared-mfc Source/ReportControl/XTPReportRows.cpp

// Candidate translation unit (score above; library headers required).
// XTPReportRows.cpp : implementation of the CXTPReportRows class.
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

#include "Common/XTPVc50Helpers.h"

#include "XTPReportRow.h"
#include "XTPReportGroupRow.h"
#include "XTPReportRecord.h"
#include "XTPReportRecords.h"
#include "XTPReportRecordItem.h"
#include "XTPReportRecordItemText.h"
#include "XTPReportControl.h"
#include "XTPReportColumns.h"
#include "XTPReportColumn.h"
#include "XTPReportInplaceControls.h"
#include "XTPReportRows.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

//////////////////////////////////////////////////////////////////////////
// CXTPReportRows

CXTPReportRows::CXTPReportRows()
{
	m_pVirtualRow = 0;
	m_nVirtualRowsCount = 0;
}

CXTPReportRows::~CXTPReportRows()
{
	Clear();
}


//////////////////////////////////////////////////////////////////////////
// CXTPReportRows member functions

void CXTPReportRows::Clear(BOOL bResetRow)
{
	// array cleanup
	for (int nRow = (int)m_arrRows.GetSize() - 1; nRow >= 0; nRow--)
	{
		CXTPReportRow* pRow = m_arrRows.GetAt(nRow);
		if (bResetRow)
		{
			pRow->m_bVisible = FALSE;
			pRow->m_nIndex = -1;
		}
		pRow->InternalRelease();
	}

	m_arrRows.RemoveAll();

	if (m_pVirtualRow)
	{
		m_pVirtualRow->InternalRelease();
		m_pVirtualRow = 0;
	}

}

CXTPReportRow* CXTPReportRows::GetNext(CXTPReportRow* pRow, BOOL bSkipGroupFocus)
{
	if (pRow)
	{
		int index = pRow->GetIndex();

		while (index < GetCount() - 1)
		{
			index++;
			pRow = GetAt(index);

			if (!bSkipGroupFocus || !pRow->IsGroupRow() || !pRow->IsExpanded())
				return pRow;
		}
	}
	else if (GetCount() > 0)
	{
		return GetAt(0);
	}
	return pRow;
}

CXTPReportRow* CXTPReportRows::GetPrev(CXTPReportRow* pRow, BOOL bSkipGroupFocus)
{
	if (pRow)
	{
		int index = pRow->GetIndex();

		while (index > 0)
		{
			index--;
			pRow = GetAt(index);

			if (!bSkipGroupFocus || !pRow->IsGroupRow() || !pRow->IsExpanded())
				return pRow;

		}
	}
	else if (GetCount() > 0)
	{
		return GetAt(0);
	}
	return pRow;
}

void CXTPReportRows::InsertAt(int nIndex, CXTPReportRow* pRow)
{
	m_arrRows.InsertAt(nIndex, pRow);
}

int CXTPReportRows::Add(CXTPReportRow* pRow)
{
	int nIndex = (int)m_arrRows.Add(pRow);

	pRow->m_nChildIndex = nIndex;
	pRow->m_pParentRows = this;

	return nIndex;
}

void CXTPReportRows::RemoveAt(int nIndex)
{
	m_arrRows.GetAt(nIndex)->InternalRelease();
	m_arrRows.RemoveAt(nIndex);
}

int CXTPReportRows::RemoveRow(CXTPReportRow* pRow)
{
	for (int i = 0; i < (int)m_arrRows.GetSize(); i++)
	{
		if (m_arrRows.GetAt(i) == pRow)
		{
			RemoveAt(i);
			return i;
		}
	}
	return -1;
}

void CXTPReportRows::SetVirtualMode(CXTPReportRow* pRow, int nCount)
{
	ASSERT(m_pVirtualRow == NULL);

	m_pVirtualRow = pRow;
	m_nVirtualRowsCount = nCount;
}


int _cdecl CXTPReportRows::CompareRows(const CXTPReportRow** ppRow1, const CXTPReportRow** ppRow2)
{
	CXTPReportColumns* pColumns = (**ppRow1).GetControl()->GetColumns();

	CXTPReportRecord* pRecord1 = (**ppRow1).GetRecord();
	CXTPReportRecord* pRecord2 = (**ppRow2).GetRecord();

	ASSERT(pColumns);
	ASSERT(pRecord1 && pRecord2 || !pRecord1 && !pRecord2);

	if (pRecord1 == pRecord2 && pRecord1)
		return 0;

	if (!pRecord1 && !pRecord2)
	{
		// compare groupRows by its first not group child rows
		if ((*ppRow1)->HasChildren() && (*ppRow2)->HasChildren())
		{
			CXTPReportRow* pRow1a = (CXTPReportRow*)(*ppRow1);
			CXTPReportRow* pRow2a = (CXTPReportRow*)(*ppRow2);

			if (pRow1a->GetChilds() && pRow1a->GetChilds()->GetCount() &&
				pRow2a->GetChilds() && pRow2a->GetChilds()->GetCount())
			{
				pRow1a = pRow1a->GetChilds()->GetAt(0);
				pRow2a = pRow2a->GetChilds()->GetAt(0);

				return CompareRows((const CXTPReportRow**)&pRow1a, (const CXTPReportRow**)&pRow2a);
			}
		}
	}

	if (!pRecord1 || !pRecord2)
	{
		ASSERT(FALSE);
		return 0;
	}

	for (int nGroupOrder = 0; nGroupOrder < pColumns->GetGroupsOrder()->GetCount(); nGroupOrder++)
	{
		CXTPReportColumn* pColumn = pColumns->GetGroupsOrder()->GetAt(nGroupOrder);
		if (!pColumn->m_bAutoSortWhenGrouped)
			continue;

		BOOL bIncreasing = pColumn->m_bSortIncreasing;

		CXTPReportRecordItem* pItem1 = pRecord1->GetItem(pColumn);
		CXTPReportRecordItem* pItem2 = pRecord2->GetItem(pColumn);

		if (!pItem1 || !pItem2)
			continue;

		int nCompareResult = pItem1->CompareGroupCaption(pColumn, pItem2);

		if (nCompareResult != 0)
			return nCompareResult * (bIncreasing ? 1 : -1);
	}


	for (int nSortOrder = 0; nSortOrder < pColumns->GetSortOrder()->GetCount(); nSortOrder++)
	{
		CXTPReportColumn* pColumn = pColumns->GetSortOrder()->GetAt(nSortOrder);
		BOOL bIncreasing = pColumn->IsSortedIncreasing();

		CXTPReportRecordItem* pItem1 = pRecord1->GetItem(pColumn);
		CXTPReportRecordItem* pItem2 = pRecord2->GetItem(pColumn);

		if (!pItem1 || !pItem2)
			continue;

		int nCompareResult = pItem1->Compare(pColumn, pItem2);

		if (nCompareResult != 0)
			return nCompareResult * (bIncreasing ? 1 : -1);
	}

	return pRecord1->GetIndex() > pRecord2->GetIndex() ? 1 : -1;
}

int _cdecl CXTPReportRows::CompareRows2(const CXTPReportRow** ppRow1, const CXTPReportRow** ppRow2)
{
	CXTPReportColumns* pColumns = (**ppRow1).GetControl()->GetColumns();

	CXTPReportRecord* pRecord1 = (**ppRow1).GetRecord();
	CXTPReportRecord* pRecord2 = (**ppRow2).GetRecord();

	ASSERT(pColumns);
	ASSERT(pRecord1 && pRecord2 || !pRecord1 && !pRecord2);

	if (pRecord1 == pRecord2 && pRecord1)
		return 0;

	if (!pRecord1 && !pRecord2)
	{
		// compare groupRows by its first not group child rows
		if ((*ppRow1)->HasChildren() && (*ppRow2)->HasChildren())
		{
			CXTPReportRow* pRow1a = (CXTPReportRow*)(*ppRow1);
			CXTPReportRow* pRow2a = (CXTPReportRow*)(*ppRow2);

			if (pRow1a->GetChilds() && pRow1a->GetChilds()->GetCount() &&
				pRow2a->GetChilds() && pRow2a->GetChilds()->GetCount())
			{
				pRow1a = pRow1a->GetChilds()->GetAt(0);
				pRow2a = pRow2a->GetChilds()->GetAt(0);

				return CompareRows((const CXTPReportRow**)&pRow1a, (const CXTPReportRow**)&pRow2a);
			}
		}
	}

	if (!pRecord1 || !pRecord2)
	{
		ASSERT(FALSE);
		return 0;
	}

	for (int nGroupOrder = 0; nGroupOrder < pColumns->GetGroupsOrder()->GetCount(); nGroupOrder++)
	{
		CXTPReportColumn* pColumn = pColumns->GetGroupsOrder()->GetAt(nGroupOrder);
		if (!pColumn->m_bAutoSortWhenGrouped)
			continue;

		BOOL bIncreasing = pColumn->m_bSortIncreasing;

		CXTPReportRecordItem* pItem1 = pRecord1->GetItem(pColumn);
		CXTPReportRecordItem* pItem2 = pRecord2->GetItem(pColumn);

		if (!pItem1 || !pItem2)
			continue;

		int nCompareResult = pItem1->CompareGroupCaption(pColumn, pItem2);

		if (nCompareResult != 0)
		{
			if(nGroupOrder > 0)
				nCompareResult = bIncreasing ? -1 : 1;
			return nCompareResult * (bIncreasing ? 1 : -1);
		}
	}


	for (int nSortOrder = 0; nSortOrder < pColumns->GetSortOrder()->GetCount(); nSortOrder++)
	{
		CXTPReportColumn* pColumn = pColumns->GetSortOrder()->GetAt(nSortOrder);
		BOOL bIncreasing = pColumn->IsSortedIncreasing();

		CXTPReportRecordItem* pItem1 = pRecord1->GetItem(pColumn);
		CXTPReportRecordItem* pItem2 = pRecord2->GetItem(pColumn);

		if (!pItem1 || !pItem2)
			continue;

		int nCompareResult = pItem1->Compare(pColumn, pItem2);

		if (nCompareResult != 0)
			return nCompareResult * (bIncreasing ? 1 : -1);
	}

	return 0;
}

void CXTPReportRows::SortEx(T_CompareFunc pCompareFunc)
{
	typedef int (_cdecl *GENERICCOMPAREFUNC)(const void *, const void*);

	qsort(m_arrRows.GetData(), (size_t)m_arrRows.GetSize(), sizeof(CXTPReportRow*), (GENERICCOMPAREFUNC)pCompareFunc);
}

void CXTPReportRows::Sort()
{
	SortEx(CompareRows);
}

int CXTPReportRows::GetCount() const
{
	if (m_pVirtualRow)
		return m_nVirtualRowsCount;

	return (int)m_arrRows.GetSize();
}

CXTPReportRow* CXTPReportRows::GetAt(int nIndex) const
{
	if (m_pVirtualRow)
	{
		m_pVirtualRow->m_nIndex = nIndex;
		return m_pVirtualRow;
	}

	return (nIndex >= 0) && (nIndex < GetCount()) ? m_arrRows.GetAt(nIndex) : NULL;
}

CXTPReportRow* CXTPReportRows::Find(CXTPReportRecord* pRecord)
{
	for (int i = 0; i < (int)m_arrRows.GetSize(); i++)
	{
		if (m_arrRows.GetAt(i)->GetRecord() == pRecord)
			return m_arrRows.GetAt(i);
	}
	return 0;
}

CXTPReportRow* CXTPReportRows::FindInTree(CXTPReportRecord* pRecord)
{
	for (int i = 0; i < (int)m_arrRows.GetSize(); i++)
	{
		if (m_arrRows.GetAt(i)->GetRecord() == pRecord)
			return m_arrRows.GetAt(i);

		if (m_arrRows.GetAt(i)->HasChildren())
		{
			CXTPReportRow* pRow = m_arrRows.GetAt(i)->GetChilds()->FindInTree(pRecord);
			if (pRow)
				return pRow;
		}
	}
	return 0;
}

CXTPReportRow* CXTPReportRows::FindInsertionPos(CXTPReportRow* pRow, BOOL& bInsertAfter)
{
	CXTPReportRow* pInsertionRowPos = NULL;
	bInsertAfter = FALSE;

	for(int i = 0; i < (int)m_arrRows.GetSize(); i++)
	{
		CXTPReportRow* pCurRow = m_arrRows.GetAt(i);
		if(pCurRow->IsGroupRow())
		{
			// compare group caption
			CXTPReportRecord* pRecord = pRow->GetRecord();
			CXTPReportColumns* pColumns = pRow->GetControl()->GetColumns();
			if(!(pRecord && pColumns))
				continue;
			CXTPReportColumn* pColumn = pColumns->GetGroupsOrder()->GetAt(pCurRow->GetGroupLevel());
			CXTPReportRecordItem* pItem = pRecord->GetItem(pColumn);
			COleVariant varGroup(pItem ? (LPCTSTR)pItem->GetGroupCaption(pColumn) : _T(""));
			COleVariant varGroupRowCaption((LPCTSTR)((CXTPReportGroupRow*)pCurRow)->GetCaption());
			ULONG dwFlags = pRecord->GetRecords()->IsCaseSensitive() ? 0 : NORM_IGNORECASE;
			LCID lcidnSortLocale = CXTPReportRecordItemVariant::m_nSortLocale;
			if (lcidnSortLocale == LOCALE_USER_DEFAULT)
			{
				lcidnSortLocale = CXTPReportControlLocale::GetActiveLCID();
			}
			int nCompareResult = VARCMP_S(varGroup, varGroupRowCaption, lcidnSortLocale, dwFlags) - VARCMP_EQ;
			if(pColumn->m_bSortIncreasing && nCompareResult > 0 || !pColumn->m_bSortIncreasing && nCompareResult < 0)
				continue;
			// find in children
			if(!pCurRow->GetChilds())
				continue;
			if(nCompareResult == 0)
				pInsertionRowPos = pCurRow->GetChilds()->FindInsertionPos(pRow, bInsertAfter);
			if(!pInsertionRowPos)
			{
				if(nCompareResult != 0)
					pInsertionRowPos = pCurRow;
				else
				{
					pInsertionRowPos = pCurRow->GetChilds()->GetAt(pCurRow->GetChilds()->GetCount() - 1);
					bInsertAfter = TRUE;
				}
			}
			break;
		}
		if(CompareRows2((const CXTPReportRow**)&pRow, (const CXTPReportRow**)&pCurRow) <= 0)
		{
			pInsertionRowPos = pCurRow;
			break;
		}
	}

	return pInsertionRowPos;
}

void CXTPReportRows::RefreshChildIndices(BOOL bRunInChildren)
{
	for(int nIndex = 0; nIndex < GetCount(); nIndex++)
	{
		CXTPReportRow* pRow = GetAt(nIndex);
		pRow->m_nChildIndex = nIndex;
		ASSERT(pRow->m_pParentRows == this);
		if(bRunInChildren && pRow->HasChildren() && pRow->GetChilds())
			pRow->GetChilds()->RefreshChildIndices(bRunInChildren);
	}
}

void CXTPReportRows::SetSize(INT_PTR nNewSize, INT_PTR nGrowBy)
{
	int nSize = GetCount();
	if (nNewSize < nSize)
	{
		for (int i = (int)nNewSize; i < nSize; i++)
		{
			CXTPReportRow* pRow = GetAt(i);
			if (pRow)
				pRow->InternalRelease();
		}
	}

	m_arrRows.SetSize(nNewSize, nGrowBy);
}

void CXTPReportRows::ReserveSize(INT_PTR nNewSize, INT_PTR nGrowBy)
{
	m_arrRows.ReserveSize(nNewSize, nGrowBy);
}


void CXTPReportRows::SetAt(INT_PTR nIndex, CXTPReportRow* pRow)
{
	ASSERT(pRow);
	ASSERT(nIndex >= 0 && nIndex < GetCount());

	if (!pRow || nIndex < 0 || nIndex >= GetCount())
		return;

	CXTPReportRow* pRow_prev = GetAt((int)nIndex);
	if (pRow_prev)
		pRow_prev->InternalRelease();

	pRow->m_nChildIndex = (int)nIndex;
	pRow->m_pParentRows = this;

	m_arrRows.SetAt(nIndex, pRow);
}

//////////////////////////////////////////////////////////////////////////
// CXTPReportSelectedRows

CXTPReportSelectedRows::CXTPReportSelectedRows(CXTPReportControl* pControl)
	: m_pControl(pControl)
{


	m_nRowBlockBegin = -1;
	m_nPosSelected = 0;
	m_bChanged = FALSE;
	m_nRowType = xtpRowTypeBody;
}

void CXTPReportSelectedRows::Clear()
{
	if (m_arrSelectedBlocks.GetSize() > 0)
	{
		m_bChanged = TRUE;

		_NotifySelChanging(xtpReportSelectionClear);
	}

	m_arrSelectedBlocks.RemoveAll();
	m_nRowBlockBegin = -1;
	m_nRowType = xtpRowTypeBody;
	m_pControl->RedrawControl();
}

void CXTPReportSelectedRows::_InsertBlock(int nIndexInsert, int nIndexBegin, int nIndexEnd)
{
	SELECTED_BLOCK block;
	block.nIndexBegin = nIndexBegin;
	block.nIndexEnd = nIndexEnd;
	m_arrSelectedBlocks.InsertAt(nIndexInsert, block);
}


void CXTPReportSelectedRows::_OnCollapsed(int nIndex, int nCount)
{
	ASSERT(nCount > 0);

	for (int i = (int)m_arrSelectedBlocks.GetSize() - 1; i >= 0 ; i--)
	{
		int& nIndexBegin = m_arrSelectedBlocks[i].nIndexBegin;
		int& nIndexEnd = m_arrSelectedBlocks[i].nIndexEnd;

		if (nIndexBegin <= nIndex && nIndexEnd > nIndex + 1)
		{
			nIndexEnd = max(nIndexBegin + 1, nIndexEnd - nCount);

		}
		else if (nIndexBegin > nIndex + nCount)
		{
			nIndexBegin -= nCount;
			nIndexEnd -= nCount;
		}
		else if (nIndexEnd < nIndex)
			break;
		else if (nIndexBegin > nIndex)
		{
			nIndexBegin = nIndex;
			nIndexEnd = max(nIndexBegin + 1, nIndexEnd - nCount);
		}
	}
}

void CXTPReportSelectedRows::_OnExpanded(int nIndex, int nCount)
{
	ASSERT(nCount > 0);

	for (int i = (int)m_arrSelectedBlocks.GetSize() - 1; i >= 0 ; i--)
	{
		int& nIndexBegin = m_arrSelectedBlocks[i].nIndexBegin;
		int& nIndexEnd = m_arrSelectedBlocks[i].nIndexEnd;

		if (nIndexBegin <= nIndex && nIndexEnd > nIndex + 1)
		{
			_InsertBlock(i + 1, nIndex + 1 + nCount, nIndexEnd + nCount);
			m_arrSelectedBlocks[i].nIndexEnd = nIndex + 1;

		}
		else if (nIndexBegin > nIndex)
		{
			nIndexBegin += nCount;
			nIndexEnd += nCount;
		}
		else if (nIndexEnd < nIndex)
			break;

	}
}

void CXTPReportSelectedRows::AddBlock(int ib, int ie)
{
	int i = 0;
	int nCount = (int)m_arrSelectedBlocks.GetSize();

	if (nCount > 0)
	{
		int& nIndexEnd = m_arrSelectedBlocks[nCount - 1].nIndexEnd;

		if (nIndexEnd == ib)
		{
			nIndexEnd = ie + 1;
			m_pControl->RedrawControl();
			return;
		}

		if (nIndexEnd < ib)
		{
			i = nCount;
		}
	}

	for (; i < nCount; i++)
	{
		int& nIndexBegin = m_arrSelectedBlocks[i].nIndexBegin;
		int& nIndexEnd = m_arrSelectedBlocks[i].nIndexEnd;

		if ((nIndexBegin <= ib) && (nIndexEnd > ie))
		{
			return;
		}

		if (nIndexEnd == ib)
		{
			nIndexEnd = ie + 1;
			if (i + 1 < nCount && m_arrSelectedBlocks[i + 1].nIndexBegin == nIndexEnd)
			{
				nIndexEnd = m_arrSelectedBlocks[i + 1].nIndexEnd;
				m_arrSelectedBlocks.RemoveAt(i + 1);
			}

			m_pControl->RedrawControl();
			return;
		}
		if (nIndexBegin == ie + 1)
		{
			nIndexBegin = ib;
			m_pControl->RedrawControl();
			return;
		}

		if (nIndexBegin > ie)
			break;
	}

	_InsertBlock(i, ib, ie + 1);
	m_pControl->RedrawControl();
}

void CXTPReportSelectedRows::Add(CXTPReportRow* pRow)
{
	if (!pRow)
		return;

	_NotifySelChanging(xtpReportSelectionAdd, pRow);

	int nIndex = pRow->GetIndex();

	if (nIndex != -1)
	{
		AddBlock(nIndex, nIndex);
	}
}

void CXTPReportSelectedRows::Remove(CXTPReportRow* pRow)
{
	if (!pRow)
		return;

	_NotifySelChanging(xtpReportSelectionRemove, pRow);

	int nIndex = pRow->GetIndex();

	for (int i = 0; i < (int)m_arrSelectedBlocks.GetSize(); i++)
	{
		int nIndexBegin = m_arrSelectedBlocks[i].nIndexBegin;
		int nIndexEnd = m_arrSelectedBlocks[i].nIndexEnd;

		if ((nIndexBegin <= nIndex) && (nIndexEnd > nIndex))
		{
			if (nIndexBegin != nIndex)
			{
				_InsertBlock(i, nIndexBegin, nIndex);
				i++;
			}

			if (nIndexEnd - 1 != nIndex)
			{
				_InsertBlock(i + 1, nIndex + 1, nIndexEnd);
			}

			m_arrSelectedBlocks.RemoveAt(i);
			m_pControl->RedrawControl();
			return;
		}
	}

}

void CXTPReportSelectedRows::Select(CXTPReportRow* pRow)
{
	if (!pRow)
		return;

	// If new selected row belongs to the other type - clear previous selection.
	if (m_nRowType != pRow->GetType())
		Clear();

	if (m_arrSelectedBlocks.GetSize() == 1 && m_arrSelectedBlocks[0].nIndexBegin ==
		m_arrSelectedBlocks[0].nIndexEnd - 1 && m_arrSelectedBlocks[0].nIndexBegin == pRow->GetIndex())
	{

	}
	else
	{
		Clear();
		Add(pRow);
		m_bChanged = TRUE;
		m_nRowType = pRow->GetType();
	}
}

void CXTPReportSelectedRows::SelectBlock(int nBlockBegin, int nEnd)
{
	CXTPReportRows* pRows;
	switch(m_nRowType)
	{
		case xtpRowTypeHeader : pRows = m_pControl->GetHeaderRows(); break;
		case xtpRowTypeFooter : pRows = m_pControl->GetFooterRows(); break;
		default : pRows = m_pControl->GetRows(); break;
	}
	ASSERT(nBlockBegin >= 0 && nBlockBegin < pRows->GetCount() && nEnd < pRows->GetCount() );

	nBlockBegin = m_nRowBlockBegin != -1 ? m_nRowBlockBegin : nBlockBegin;

	int nBegin = nBlockBegin;

	if (nBegin == -1 || nEnd == -1)
		return;

	if (nBegin > nEnd)
	{
		nBegin = nEnd;
		nEnd = nBlockBegin;
	}

	if (m_arrSelectedBlocks.GetSize() == 1 && m_arrSelectedBlocks[0].nIndexBegin == nBegin &&
		m_arrSelectedBlocks[0].nIndexEnd == nEnd + 1)
	{
		return;
	}

	XTPReportRowType nRowType = m_nRowType;
	Clear();
	m_nRowType = nRowType;
	if (m_nRowBlockBegin == -1) m_nRowBlockBegin = nBlockBegin;


	BOOL bSkipGroupFocus = m_pControl->IsSkipGroupsFocusEnabled();
	BOOL bHasGroups = m_pControl->GetColumns()->GetGroupsOrder()->GetCount() != 0;

	if (!bHasGroups || !bSkipGroupFocus)
	{
		_InsertBlock(0, nBegin, nEnd + 1);
	}
	else
	{
		for (int i = nBegin; i <= nEnd; i++)
		{
			CXTPReportRow* pRow = pRows->GetAt(i);
			if (!pRow)
				continue;

			if (!bSkipGroupFocus || !pRow->IsGroupRow() || !pRow->IsExpanded() || (i == nBegin) || (i == nEnd))
			{
				Add(pRow);
			}
		}
	}
}

BOOL CXTPReportSelectedRows::Contains(const CXTPReportRow* pRow)
{
	if (!pRow)
		return FALSE;

	if (m_nRowType != pRow->GetType())
		return FALSE;

	int nIndex = pRow->GetIndex();

	int nCount = (int)m_arrSelectedBlocks.GetSize();
	if (nCount == 0)
		return FALSE;

	if (m_arrSelectedBlocks[0].nIndexBegin > nIndex)
		return FALSE;

	if (m_arrSelectedBlocks[nCount - 1].nIndexEnd <= nIndex)
		return FALSE;

	for (int i = 0; i < nCount; i++)
	{
		if ((m_arrSelectedBlocks[i].nIndexBegin <= nIndex) &&
			(m_arrSelectedBlocks[i].nIndexEnd > nIndex))
		{
			return TRUE;
		}
	}
	return FALSE;
}

void CXTPReportSelectedRows::Invert(CXTPReportRow* pRow)
{
	if(pRow->GetType() != m_nRowType)
		return;

	if (Contains(pRow))
		Remove (pRow);
	else Add(pRow);

	m_nRowBlockBegin = -1;
	m_bChanged = TRUE;
}


int CXTPReportSelectedRows::GetCount()
{
	int nCount = 0;
	for (int i = 0; i < (int)m_arrSelectedBlocks.GetSize(); i++)
	{
		nCount += m_arrSelectedBlocks[i].nIndexEnd - m_arrSelectedBlocks[i].nIndexBegin;
	}
	return nCount;
}


POSITION CXTPReportSelectedRows::GetFirstSelectedRowPosition()
{
	if (m_arrSelectedBlocks.GetSize() == 0)
		return 0;

	m_nPosSelected = 0;

	POSITION pos = 0;
	pos = (POSITION)(DWORD_PTR)(m_arrSelectedBlocks[0].nIndexBegin + 1);
	return pos;
}

CXTPReportRow* CXTPReportSelectedRows::GetNextSelectedRow(POSITION& pos)
{
	ASSERT(m_nPosSelected < m_arrSelectedBlocks.GetSize());

	int nIndex = (int)(DWORD_PTR)pos - 1;
	CXTPReportRow* pRow;
	switch(m_nRowType)
	{
		case xtpRowTypeHeader : pRow = m_pControl->GetHeaderRows()->GetAt(nIndex); break;
		case xtpRowTypeFooter : pRow = m_pControl->GetFooterRows()->GetAt(nIndex); break;
		default : pRow = m_pControl->GetRows()->GetAt(nIndex); break;
	}

	if (nIndex < m_arrSelectedBlocks[m_nPosSelected].nIndexEnd - 1)
	{
		(int)(DWORD_PTR)pos++;
	}
	else
	{
		if (m_nPosSelected >= m_arrSelectedBlocks.GetSize() - 1)
		{
			pos = NULL;
		}
		else
		{
			m_nPosSelected++;
			pos = (POSITION)(DWORD_PTR)(m_arrSelectedBlocks[m_nPosSelected].nIndexBegin + 1);
		}
	}

	return pRow;
}



CXTPReportRow* CXTPReportSelectedRows::GetAt (int nIndex)
{
	for (int i = 0; i < (int)m_arrSelectedBlocks.GetSize(); i++)
	{
		int nCount = m_arrSelectedBlocks[i].nIndexEnd - m_arrSelectedBlocks[i].nIndexBegin;
		if (nCount <= nIndex)
		{
			nIndex -= nCount;
			continue;
		}

		CXTPReportRow* pRow;
		switch(m_nRowType)
		{
			case xtpRowTypeHeader : pRow = m_pControl->GetHeaderRows()->GetAt(m_arrSelectedBlocks[i].nIndexBegin + nIndex); break;
			case xtpRowTypeFooter : pRow = m_pControl->GetFooterRows()->GetAt(m_arrSelectedBlocks[i].nIndexBegin + nIndex); break;
			default : pRow = m_pControl->GetRows()->GetAt(m_arrSelectedBlocks[i].nIndexBegin + nIndex); break;
		}
		return pRow;
	}

	return 0;
}

void CXTPReportSelectedRows::_NotifySelChanging(XTPReportSelectionChangeType nType, CXTPReportRow* pRow)
{
	ASSERT(m_pControl);
	if (!m_pControl)
		return;

	XTP_NM_SELECTION_CHANGING nm;
	::ZeroMemory(&nm, sizeof(nm));

	nm.pRow = pRow;
	nm.nType = nType;

	m_pControl->SendNotifyMessage(XTP_NM_REPORT_SELCHANGING,(NMHDR*)&nm);
}

