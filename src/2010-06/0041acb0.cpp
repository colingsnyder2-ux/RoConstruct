// from server: 100% by auto
// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1-shared-mfc Source/ReportControl/XTPReportRecordItemText.cpp

// Candidate translation unit (score above; library headers required).
// XTPReportRecordItemText.cpp : implementation of the CXTPReportRecordItemText class.
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
#include <math.h>
#include "Common/XTPDrawHelpers.h"
#include "Common/XTPPropExchange.h"
#include "Common/XTPVc50Helpers.h"
#include "Common/XTPMarkupRender.h"

#include "XTPReportRecordItem.h"
#include "XTPReportControl.h"
#include "XTPReportPaintManager.h"
#include "XTPReportRecordItemText.h"
#include "XTPReportInplaceControls.h"
#include "XTPReportRow.h"
#include "XTPReportRecord.h"
#include "XTPReportRecords.h"
#include "XTPReportColumn.h"

#ifdef _DEBUG
#define new DEBUG_NEW
#undef THIS_FILE
static char THIS_FILE[] = __FILE__;
#endif

IMPLEMENT_SERIAL(CXTPReportRecordItemIcon, CXTPReportRecordItem, VERSIONABLE_SCHEMA | _XTP_SCHEMA_CURRENT)

CXTPReportRecordItemIcon::CXTPReportRecordItemIcon() : CXTPReportRecordItem()
{
	SetAlignment(xtpColumnIconTop | xtpColumnIconCenter | xtpColumnTextWordBreak | xtpColumnTextCenter);
}

int CXTPReportRecordItemIcon::Draw(XTP_REPORTRECORDITEM_DRAWARGS* pDrawArgs)
{
	if (pDrawArgs == NULL)
		return CXTPReportRecordItem::Draw(pDrawArgs);

	CXTPReportControl* pControl = DYNAMIC_DOWNCAST(CXTPReportControl, pDrawArgs->pControl);
	if (pControl && pControl->IsIconView())
	{
		pDrawArgs->rcItem = pDrawArgs->pRow->GetRect();
		pDrawArgs->rcItem.DeflateRect(1, 1);
	}

	return CXTPReportRecordItem::Draw(pDrawArgs);
}

void CXTPReportRecordItemIcon::OnDrawCaption(XTP_REPORTRECORDITEM_DRAWARGS* pDrawArgs, XTP_REPORTRECORDITEM_METRICS* pMetrics)
{
	if (pDrawArgs == NULL)
		return;

	CXTPReportControl* pControl = DYNAMIC_DOWNCAST(CXTPReportControl, pDrawArgs->pControl);
	if (pControl && pControl->IsIconView())
	{
		// Adjust the rect for the text.
		pDrawArgs->rcItem.DeflateRect(1, 1);
		pDrawArgs->rcItem.top += pControl->m_iIconHeight;
		pDrawArgs->rcItem.left = pDrawArgs->pRow->GetRect().left + 5;
		// The left coming in here is to the right of the icon, we need to get back to the beginning.

		CXTPReportPaintManager * pPaintManager = pControl->GetPaintManager();

		const UINT c_uiDrawFlags = pDrawArgs->nTextAlign | DT_CENTER | DT_NOPREFIX | DT_WORDBREAK | DT_EDITCONTROL | DT_END_ELLIPSIS | DT_WORD_ELLIPSIS;

		// Get rect for text
		CRect rcItem(pDrawArgs->rcItem);
		rcItem.DeflateRect(2, 1, 2, 0);
		rcItem = pPaintManager->CalculateMaxTextRect(pDrawArgs->pDC, pMetrics->strText, rcItem, TRUE, TRUE, c_uiDrawFlags);
		// Center the rect.
		//rcItem.MoveToX(rcItem.left + ((pDrawArgs->rcItem.Width() - 4 - rcItem.Width()) >> 1));
		//VC6 code:
		int nShift = rcItem.left + ((pDrawArgs->rcItem.Width() - 4 - rcItem.Width()) >> 1);
		int nWidth = rcItem.Width();
		rcItem.left = nShift;
		rcItem.right = rcItem.left + nWidth;

		rcItem.InflateRect(4, 1, 4, 2);

		if (rcItem.bottom >= pDrawArgs->rcItem.bottom)
		  rcItem.bottom -= 2;

		//Draw the selection
		if (pDrawArgs->pRow->IsSelected() && (pDrawArgs->pDC && !pDrawArgs->pDC->IsPrinting()))
		{
			COLORREF clrBackground = 0;

			if (pControl->HasFocus())
			{
				pMetrics->clrForeground = pPaintManager->m_clrHighlightText;
				pDrawArgs->pDC->SetTextColor(pMetrics->clrForeground);
				clrBackground = pPaintManager->m_clrHighlight;
			}
			else if (!pPaintManager->m_bHideSelection)
			{
				pMetrics->clrForeground = pPaintManager->m_clrSelectedRowText;
				pDrawArgs->pDC->SetTextColor(pMetrics->clrForeground);
				clrBackground = pPaintManager->m_clrSelectedRow;
			}

			// fill select rect
			pDrawArgs->pDC->FillSolidRect(rcItem, clrBackground);
		}

		if (pDrawArgs->pRow->IsFocused() && pControl->HasFocus() && pControl->IsRowFocusVisible())
		{
			rcItem.InflateRect(1, 1);
			pPaintManager->DrawFocusedRow(pDrawArgs->pDC, rcItem);
		}

		pDrawArgs->nTextAlign |= c_uiDrawFlags;
	}

	CXTPReportRecordItem::OnDrawCaption(pDrawArgs, pMetrics);
}

void CXTPReportRecordItemIcon::GetCaptionRect(XTP_REPORTRECORDITEM_ARGS* pDrawArgs, CRect& rcItem)
{
	if (pDrawArgs == NULL)
		return;

	CXTPReportControl* pControl = DYNAMIC_DOWNCAST(CXTPReportControl, pDrawArgs->pControl);
	if (pControl && pControl->IsIconView())
	{
		// Adjust the rect for the text.
		pDrawArgs->rcItem.CopyRect(pDrawArgs->pRow->GetRect());
		pDrawArgs->rcItem.DeflateRect(1, 1);
		pDrawArgs->rcItem.top += pControl->m_iIconHeight;

		// The left coming in here is to the right of the icon, we need to get back to the beginning.
		pDrawArgs->rcItem.left = pDrawArgs->pRow->GetRect().left + 5;
		pDrawArgs->rcItem.DeflateRect(2, 1, 2, 0);

		rcItem = pDrawArgs->rcItem;
		return;
	}
	else
	{
		CXTPReportRecordItem::GetCaptionRect(pDrawArgs, rcItem);
	}
}

void CXTPReportRecordItemIcon::OnEditChanged(XTP_REPORTRECORDITEM_ARGS* pItemArgs, LPCTSTR szText)
{
	if (pItemArgs == NULL)
		return;

	CXTPReportRecordItem::OnEditChanged(pItemArgs, szText);

	int r = pItemArgs->pRow->GetIndex();
	int i = pItemArgs->pItem->GetIndex();
	CXTPReportRecord* pRec = pItemArgs->pRow->GetRecord();
	if (pRec)
	{
		pRec->UpdateRecordField(r, i, szText);
	}
}
//ICON_VIEW_MODE RELATED <<

//////////////////////////////////////////////////////////////////////////
// CXTPReportRecordItemText

IMPLEMENT_SERIAL(CXTPReportRecordItemText, CXTPReportRecordItem, VERSIONABLE_SCHEMA | _XTP_SCHEMA_CURRENT)

CXTPReportRecordItemText::CXTPReportRecordItemText(LPCTSTR szText)
	: CXTPReportRecordItem(), m_strText(szText)
{
}

CString CXTPReportRecordItemText::GetCaption(CXTPReportColumn* /*pColumn*/)
{
	if (!m_strCaption.IsEmpty())
		return m_strCaption;

	if (m_strFormatString == _T("%s"))
		return m_strText;

	CString strCaption;
	strCaption.Format(m_strFormatString, (LPCTSTR)m_strText);
	return strCaption;
}

void CXTPReportRecordItemText::OnEditChanged(XTP_REPORTRECORDITEM_ARGS* pItemArgs, LPCTSTR szText)
{
	SetValue(szText);

	CXTPReportRecordItem::OnEditChanged(pItemArgs, szText);
}

void CXTPReportRecordItemText::DoPropExchange(CXTPPropExchange* pPX)
{
	CXTPReportRecordItem::DoPropExchange(pPX);

	PX_String(pPX, _T("Text"), m_strText, _T(""));
}

//////////////////////////////////////////////////////////////////////////
// CXTPReportRecordItemNumber

IMPLEMENT_SERIAL(CXTPReportRecordItemNumber, CXTPReportRecordItem, VERSIONABLE_SCHEMA | _XTP_SCHEMA_CURRENT)

CXTPReportRecordItemNumber::CXTPReportRecordItemNumber(double dValue)
	: CXTPReportRecordItem(), m_dValue(dValue)
{
	static const CString cstrNumberFormatDefault(_T("%0.f")); // to avoid new string data allocation for each record
	m_strFormatString = cstrNumberFormatDefault;
}

CXTPReportRecordItemNumber::CXTPReportRecordItemNumber(double dValue, LPCTSTR strFormat)
	: CXTPReportRecordItem(), m_dValue(dValue)
{
	m_strFormatString = strFormat;
}

CString CXTPReportRecordItemNumber::GetCaption(CXTPReportColumn* /*pColumn*/)
{
	if (!m_strCaption.IsEmpty())
		return m_strCaption;

	CString strCaption;
	strCaption.Format(m_strFormatString, m_dValue);
	return strCaption;
}

int CXTPReportRecordItemNumber::Compare(CXTPReportColumn*, CXTPReportRecordItem* pItem)
{
	CXTPReportRecordItemNumber* pItemNumber = DYNAMIC_DOWNCAST(CXTPReportRecordItemNumber, pItem);
	if (!pItemNumber)
		return 0;

	if (m_dValue == pItemNumber->m_dValue)
		return 0;
	else if (m_dValue > pItemNumber->m_dValue)
		return 1;
	else
		return -1;
}

void CXTPReportRecordItemNumber::OnEditChanged(XTP_REPORTRECORDITEM_ARGS* /*pItemArgs*/, LPCTSTR szText)
{
#ifdef _UNICODE
	char astring[20];
	WideCharToMultiByte (CP_ACP, 0, szText, -1, astring, 20, NULL, NULL);
	SetValue((double)atof(astring));
#else
	SetValue((double)atof(szText));
#endif
}

void CXTPReportRecordItemNumber::DoPropExchange(CXTPPropExchange* pPX)
{
	CXTPReportRecordItem::DoPropExchange(pPX);

	PX_Double(pPX, _T("Value"), m_dValue);
}

//////////////////////////////////////////////////////////////////////////
// CXTPReportRecordItemPercentNumber

IMPLEMENT_SERIAL(CXTPReportRecordItemPercentNumber, CXTPReportRecordItemNumber, VERSIONABLE_SCHEMA | _XTP_SCHEMA_CURRENT)

CXTPReportRecordItemPercentNumber::CXTPReportRecordItemPercentNumber(double dValue, COLORREF clr, BOOL bPercentCompleteDisplay)
	: CXTPReportRecordItemNumber(dValue)
{
	m_strFormatString = _T("%2.0f%%");
	m_clr = clr;
	m_bPercentCompleteDisplay = bPercentCompleteDisplay;
}

void CXTPReportRecordItemPercentNumber::OnDrawCaption(XTP_REPORTRECORDITEM_DRAWARGS* pDrawArgs, XTP_REPORTRECORDITEM_METRICS* pMetrics)
{
	ASSERT(pDrawArgs->pItem == this);

	CString sTxt = pMetrics->strText;

	if (sTxt.Find('%') > -1)
	{
		REPLACE_S(sTxt, _T("%"), _T(""));
		int iTxt = _ttoi(sTxt);

		if (m_bPercentCompleteDisplay)
		{
			iTxt = max(0, iTxt);
			iTxt = min(100, iTxt);
			pMetrics->strText.Format(_T("%d"), iTxt);

			CDC* pDC = pDrawArgs->pDC;
			if (pDC)
			{
				CRect rc = pDrawArgs->rcItem;
				rc.DeflateRect(2, 2, 2, 2);
				int W = rc.Width();

				if (pMetrics->nColumnAlignment == xtpColumnTextLeft)
					rc.right = rc.left + W * iTxt / 100;
				else if (pMetrics->nColumnAlignment == xtpColumnTextRight)
					rc.left = rc.right - W * iTxt / 100;
				else if (pMetrics->nColumnAlignment == xtpColumnTextCenter)
				{
					rc.left += W * (100 - iTxt) / 200;
					rc.right -= W * (100 - iTxt) / 200;
				}

				if (pDrawArgs->pControl
					&& pDrawArgs->pControl->GetPaintManager()
					&& pDrawArgs->pControl->GetPaintManager()->m_bShowNonActiveInPlaceButton)
					rc.right -= rc.Height();

				pDC->FillSolidRect(rc, m_clr);

				//CRgn rgnEvent;
				//rgnEvent.CreateRoundRectRgn(rc.left, rc.top, rc.right, rc.bottom, 7, 7);
				//CXTPPaintManagerColorGradient* pGrad = new CXTPPaintManagerColorGradient(m_clr);
				//pDC->SelectClipRgn(&rgnEvent);
				//CRect rcBk = rc;
				//rcBk.DeflateRect(0, 1, 0, 1);
				//XTPDrawHelpers()->GradientFill(pDC, &rcBk, *pGrad, FALSE);
				//pDC->SelectClipRgn(NULL);
				//delete pGrad;
			}
		}
	}
	if (m_pMarkupUIElement)
	{
		CRect rcItem = pDrawArgs->rcItem;
		rcItem.DeflateRect(2, 1, 2, 0);

		XTPMarkupSetDefaultFont(XTPMarkupElementContext(m_pMarkupUIElement), (HFONT)pMetrics->pFont->GetSafeHandle(), pMetrics->clrForeground);

		XTPMarkupMeasureElement(m_pMarkupUIElement, rcItem.Width(), INT_MAX);
		XTPMarkupRenderElement(m_pMarkupUIElement, pDrawArgs->pDC->GetSafeHdc(), &rcItem);
	}
	else
	{
		pDrawArgs->pControl->GetPaintManager()->DrawItemCaption(pDrawArgs, pMetrics);
	}
}

//////////////////////////////////////////////////////////////////////////
// CXTPReportRecordItemDateTime

IMPLEMENT_SERIAL(CXTPReportRecordItemDateTime, CXTPReportRecordItem, VERSIONABLE_SCHEMA | _XTP_SCHEMA_CURRENT)

CXTPReportRecordItemDateTime::CXTPReportRecordItemDateTime(COleDateTime odtValue)
	: CXTPReportRecordItem(), m_odtValue(odtValue)
{
	static const CString cstrDateFormatDefault(_T("%a %b/%d/%Y %I:%M %p")); // to avoid new string data allocation for each record
	m_strFormatString = cstrDateFormatDefault;
}

CString CXTPReportRecordItemDateTime::GetCaption(CXTPReportColumn* /*pColumn*/)
{
	if (!m_strCaption.IsEmpty())
		return m_strCaption;

	//return m_odtValue.Format(m_strFormatString);
	return CXTPReportControlLocale::FormatDateTime(m_odtValue, m_strFormatString);
}

int CXTPReportRecordItemDateTime::Compare(CXTPReportColumn*, CXTPReportRecordItem* pItem)
{
	CXTPReportRecordItemDateTime* pItemDateTime = DYNAMIC_DOWNCAST(CXTPReportRecordItemDateTime, pItem);
	if (!pItemDateTime)
		return 0;

	if (m_odtValue == pItemDateTime->m_odtValue)
		return 0;

	if (m_odtValue.GetStatus() != COleDateTime::valid ||
		pItemDateTime->m_odtValue.GetStatus() != COleDateTime::valid)
		return int(m_odtValue.m_dt - pItemDateTime->m_odtValue.m_dt);

	if (m_odtValue > pItemDateTime->m_odtValue)
		return 1;

	return -1;
}

void CXTPReportRecordItemDateTime::OnEditChanged(XTP_REPORTRECORDITEM_ARGS* /*pItemArgs*/, LPCTSTR szText)
{
	m_odtValue.ParseDateTime(szText);
}

void CXTPReportRecordItemDateTime::DoPropExchange(CXTPPropExchange* pPX)
{
	CXTPReportRecordItem::DoPropExchange(pPX);

	PX_DateTime(pPX, _T("Value"), m_odtValue);
}

//////////////////////////////////////////////////////////////////////////
// CXTPReportRecordItemPreview
IMPLEMENT_SERIAL(CXTPReportRecordItemPreview, CXTPReportRecordItem, VERSIONABLE_SCHEMA | _XTP_SCHEMA_CURRENT)

CXTPReportRecordItemPreview::CXTPReportRecordItemPreview(LPCTSTR szPreviewText)
	: CXTPReportRecordItem()
{
	SetPreviewText(szPreviewText);
}

void CXTPReportRecordItemPreview::SetPreviewText(LPCTSTR strPreviewText)
{
	m_strPreviewText = strPreviewText;

	XTPMarkupReleaseElement(m_pMarkupUIElement);

	CXTPMarkupContext* pMarkupContext = m_pRecord ? m_pRecord->GetMarkupContext() : NULL;

	if (pMarkupContext)
	{
		m_pMarkupUIElement = XTPMarkupParseText(pMarkupContext, m_strPreviewText);
	}
}

void CXTPReportRecordItemPreview::SetCaption(LPCTSTR strCaption)
{
	SetPreviewText(strCaption);
}

CString CXTPReportRecordItemPreview::GetCaption(CXTPReportColumn* /*pColumn*/)
{
	return GetPreviewText();
}

void CXTPReportRecordItemPreview::GetItemMetrics(XTP_REPORTRECORDITEM_DRAWARGS* pDrawArgs, XTP_REPORTRECORDITEM_METRICS* pItemMetrics)
{
	pItemMetrics->clrForeground = pDrawArgs->pControl->GetPaintManager()->m_clrPreviewText;
	pItemMetrics->pFont = &pDrawArgs->pControl->GetPaintManager()->m_fontPreview;
}

void CXTPReportRecordItemPreview::OnEditChanged(XTP_REPORTRECORDITEM_ARGS* /*pItemArgs*/, LPCTSTR szText)
{
	m_strPreviewText = szText;
}

void CXTPReportRecordItemPreview::DoPropExchange(CXTPPropExchange* pPX)
{
	CXTPReportRecordItem::DoPropExchange(pPX);

	PX_String(pPX, _T("PreviewText"), m_strPreviewText);

	if (pPX->IsLoading())
	{
		XTPMarkupReleaseElement(m_pMarkupUIElement);

		CXTPMarkupContext* pMarkupContext = m_pRecord ? m_pRecord->GetMarkupContext() : NULL;
		if (pMarkupContext)
		{
			m_pMarkupUIElement = XTPMarkupParseText(pMarkupContext, m_strPreviewText);
		}
	}
}

int CXTPReportRecordItemPreview::GetPreviewHeight(CDC* pDC, CXTPReportRow* pRow, int nWidth)
{
	int nHeight = 0;
	XTP_REPORTRECORDITEM_METRICS* pMetrics = new XTP_REPORTRECORDITEM_METRICS;
	pMetrics->strText = GetPreviewText();
	pRow->FillMetrics(NULL, this, pMetrics);

	CString strPreviewText = pMetrics->strText;

	if (strPreviewText.IsEmpty())
	{
		pMetrics->InternalRelease();
		return 0;
	}

	CXTPReportControl* pControl = pRow->GetControl();

	int nIndentWidth = pControl->GetHeaderIndent();


	CRect& rcIndent = pControl->GetPaintManager()->m_rcPreviewIndent;

	CRect rcPreviewItem(nIndentWidth + rcIndent.left, 0, nWidth - rcIndent.right, 0);

	if (m_pMarkupUIElement)
	{
		// Calculate Markup item height
		XTPMarkupSetDefaultFont(XTPMarkupElementContext(m_pMarkupUIElement), (HFONT)pMetrics->pFont->GetSafeHandle(), pMetrics->clrForeground);
		CSize szMarkup = XTPMarkupMeasureElement(m_pMarkupUIElement, rcPreviewItem.Width(), INT_MAX);
		nHeight = szMarkup.cy + rcIndent.top + rcIndent.bottom;
	}
	else
	{
		// Calculate height of a usual text
		CXTPFontDC font(pDC, pMetrics->pFont);

		int nMaxPreviewLines = pControl->GetPaintManager()->GetPreviewLinesCount(pDC, rcPreviewItem, strPreviewText);
		int nFontHeight = pDC->GetTextExtent(_T(" "), 1).cy;


		nHeight = nFontHeight * nMaxPreviewLines + rcIndent.top + rcIndent.bottom;
	}

	// Cleanup
	pMetrics->InternalRelease();
	return nHeight;
}

void CXTPReportRecordItemPreview::GetCaptionRect(XTP_REPORTRECORDITEM_ARGS* pDrawArgs, CRect& rcItem)
{
	ASSERT(pDrawArgs->pControl);
	if (!pDrawArgs->pControl)
		return;

	CRect& rcIndent = pDrawArgs->pControl->GetPaintManager()->m_rcPreviewIndent;
	rcItem.DeflateRect(rcIndent.left - 2, -1, rcIndent.right, -rcIndent.bottom);
}


void CXTPReportRecordItemPreview::OnDrawCaption(XTP_REPORTRECORDITEM_DRAWARGS* pDrawArgs, XTP_REPORTRECORDITEM_METRICS* pMetrics)
{
	ASSERT(pDrawArgs->pControl);
	if (!pDrawArgs->pControl)
		return;

	if (!pDrawArgs->pControl->GetPaintManager()->OnDrawAction(pDrawArgs))
		return;

	CString strText = pMetrics->strText;

	// draw item text
	if (!strText.IsEmpty())
	{
		CRect rcItem(pDrawArgs->rcItem);

		CRect& rcIndent = pDrawArgs->pControl->GetPaintManager()->m_rcPreviewIndent;

		rcItem.DeflateRect(rcIndent.left, rcIndent.top, rcIndent.right, rcIndent.bottom);

		if (m_pMarkupUIElement)
		{
			XTPMarkupSetDefaultFont(XTPMarkupElementContext(m_pMarkupUIElement), (HFONT)pMetrics->pFont->GetSafeHandle(), pMetrics->clrForeground);

			XTPMarkupMeasureElement(m_pMarkupUIElement, rcItem.Width(), INT_MAX);

			XTPMarkupRenderElement(m_pMarkupUIElement, pDrawArgs->pDC->GetSafeHdc(), &rcItem);
		}
		else
		{
			pDrawArgs->pDC->DrawText(strText, rcItem, DT_WORDBREAK | DT_LEFT | DT_NOPREFIX);
		}
	}
}

int CXTPReportRecordItemVariant::m_nSortLocale = LOCALE_USER_DEFAULT;

//////////////////////////////////////////////////////////////////////////
// CXTPReportRecordItemVariant

IMPLEMENT_SERIAL(CXTPReportRecordItemVariant, CXTPReportRecordItem, VERSIONABLE_SCHEMA | _XTP_SCHEMA_CURRENT)

CXTPReportRecordItemVariant::CXTPReportRecordItemVariant(const VARIANT& lpValue)
{

	m_oleValue = lpValue;
	m_oleValue.ChangeType((VARTYPE)(m_oleValue.vt & ~VT_BYREF));
}

void CXTPReportRecordItemVariant::SetValue(const COleVariant& var)
{
	m_oleValue = var;
}

void CXTPReportRecordItemVariant::SetValue(const VARIANT& var)
{
	m_oleValue = var;
}

void CXTPReportRecordItemVariant::SetValue(const VARIANT* var)
{
	m_oleValue = var;
}

COleVariant CXTPReportRecordItemVariant::GetValue()
{
	return m_oleValue;
}

CString CXTPReportRecordItemVariant::GetCaption(CXTPReportColumn* pColumn)
{
	if (!m_strCaption.IsEmpty())
		return m_strCaption;

	COleVariant var(m_oleValue);

	CXTPReportRecordItemEditOptions* pEditOptions = NULL;
	if (m_pEditOptions)
		pEditOptions = m_pEditOptions;
	else if (pColumn)
		pEditOptions = pColumn->GetEditOptions();

	BOOL bConstraintEdit = FALSE;
	if (pEditOptions)
		bConstraintEdit = pEditOptions->m_bConstraintEdit;

	TRY
	{
		if (var.vt == VT_DATE && !bConstraintEdit && m_strFormatString != _T("%s"))
		{
			COleDateTime dt(var);
			//return dt.Format(m_strFormatString);
			return CXTPReportControlLocale::FormatDateTime(dt, m_strFormatString);
		}
		if (var.vt == VT_NULL)
		{
			var.vt = VT_I4;
			var.lVal = 0;
		}
		else
		{
			if (bConstraintEdit)
				CXTPReportControlLocale::VariantChangeTypeEx(var, VT_I4);
			else
				CXTPReportControlLocale::VariantChangeTypeEx(var, VT_BSTR);
		}
	}
	CATCH_ALL(e)
	{
	}
	END_CATCH_ALL

	if (bConstraintEdit)
	{
		CXTPReportRecordItemConstraint* pConstraint = pEditOptions ? pEditOptions->FindConstraint(var.lVal) : NULL;
		return pConstraint ? pConstraint->m_strConstraint : _T("");
	}

	if (var.vt != VT_BSTR) //this function expected VT_BSTR only !?
		return _T("");

	CString strVariant(var.bstrVal);
	if (m_strFormatString == _T("%s"))
		return strVariant;

	CString strCaption;
	strCaption.Format(m_strFormatString, (LPCTSTR)strVariant);
	return strCaption;
}

int CXTPReportRecordItemVariant::Compare(CXTPReportColumn*, CXTPReportRecordItem* pItem)
{
	if (GetSortPriority() != -1 || pItem->GetSortPriority() != -1)
		return GetSortPriority() - pItem->GetSortPriority();

	CXTPReportRecordItemVariant* pItemVariant = DYNAMIC_DOWNCAST(CXTPReportRecordItemVariant, pItem);
	if (!pItemVariant)
		return 0;

	ULONG dwFlags = m_pRecord->GetRecords()->IsCaseSensitive() ? 0 : NORM_IGNORECASE;

	LCID lcidnSortLocale = m_nSortLocale;
	if (lcidnSortLocale == LOCALE_USER_DEFAULT)
	{
		lcidnSortLocale = CXTPReportControlLocale::GetActiveLCID();
	}
	return VARCMP_S(m_oleValue, pItemVariant->m_oleValue, lcidnSortLocale, dwFlags) - VARCMP_EQ;
}

BOOL CXTPReportRecordItemVariant::OnValueChanging(XTP_REPORTRECORDITEM_ARGS* pItemArgs, LPVARIANT lpNewValue)
{
	UNREFERENCED_PARAMETER(pItemArgs);
	UNREFERENCED_PARAMETER(lpNewValue);
	return TRUE;

}

BOOL CXTPReportRecordItemVariant::OnEditChanging(XTP_REPORTRECORDITEM_ARGS* pItemArgs, CString& rstrNewText)
{
	UNREFERENCED_PARAMETER(pItemArgs);
	UNREFERENCED_PARAMETER(rstrNewText);
	return TRUE;
}

void CXTPReportRecordItemVariant::OnEditChanged(XTP_REPORTRECORDITEM_ARGS* pItemArgs,
												LPCTSTR szText)
{
	COleVariant var(szText);

	if (OnValueChanging(pItemArgs, &var))
	{
		TRY
		{
			CXTPReportControlLocale::VariantChangeTypeEx(var, m_oleValue.vt);
		}
		CATCH_ALL(e)
		{
			return;
		}
		END_CATCH_ALL

		m_oleValue = var;
	}
}


void CXTPReportRecordItemVariant::DoPropExchange(CXTPPropExchange* pPX)
{
	CXTPReportRecordItem::DoPropExchange(pPX);

	COleVariant varDefault(_T(""));
	PX_Variant(pPX, _T("Value"), m_oleValue, varDefault);
}

void CXTPReportRecordItemVariant::OnConstraintChanged(XTP_REPORTRECORDITEM_ARGS* pItemArgs, CXTPReportRecordItemConstraint* pConstraint)
{
	BOOL bChooseOnly = GetEditOptions(pItemArgs->pColumn)->m_bConstraintEdit;
	if (bChooseOnly)
	{
		long index = (long) pConstraint->m_dwData;
		COleVariant var;
		var.vt = VT_I4;
		var.lVal = index;

		if (m_oleValue.vt == VT_NULL)
			m_oleValue.vt = VT_I4;

		BOOL bChanged = CXTPReportControlLocale::VariantChangeTypeEx(var, m_oleValue.vt, FALSE);

		if (bChanged && OnValueChanging(pItemArgs, &var))
		{
			m_oleValue = var;
		}
	}
	else
	{
		OnEditChanged(pItemArgs, pConstraint->m_strConstraint);
	}
}

DWORD CXTPReportRecordItemVariant::GetSelectedConstraintData(XTP_REPORTRECORDITEM_ARGS* pItemArgs)
{
	if (GetEditOptions(pItemArgs->pColumn)->m_bConstraintEdit)
	{
		COleVariant var(m_oleValue);
		TRY
		{
			//var.ChangeType(VT_I4);
			CXTPReportControlLocale::VariantChangeTypeEx(var, VT_I4);
		}
		CATCH_ALL(e)
		{
			return (DWORD)-1;
		}
		END_CATCH_ALL

		return var.lVal;

	}
	else
	{
		return (DWORD)-1;
	}
}


