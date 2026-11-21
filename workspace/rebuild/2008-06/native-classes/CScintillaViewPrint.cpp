// native-flags: /O2 /Ob2 /Oy /GF /GS- /EHsc /MD /D_AFXDLL /D_DLL /DNDEBUG /I{headers}/mfc-noinline-pcxstr-len /I{headers}/../../../tools/openrbx/Client/win /I{headers}/../../../tools/openrbx/3rdparty/scintilla/include
// 2008-06 native Scintilla::CScintillaView print/replace members (inactive): ScintillaDocView.cpp subset, variant file.
#include "stdafx.h"
#include "ScintillaDocView.h"
#include "resource.h"

namespace Scintilla
{
class _SCINTILLA_EDIT_STATE
{
public:
//Constructors / Destructors
	_SCINTILLA_EDIT_STATE();

//Member variables
	CScintillaFindReplaceDlg* pFindReplaceDlg;    //find or replace dialog
	BOOL                      bFindOnly;          //Is pFindReplace the find or replace?
	CString                   strFind;            //last find string
	CString                   strReplace;         //last replace string
	BOOL                      bCase;              //TRUE==case sensitive, FALSE==not
	int                       bNext;              //TRUE==search down, FALSE== search up
	BOOL                      bWord;              //TRUE==match whole word, FALSE==not
  BOOL                      bRegularExpression; //TRUE==regular expression search, FALSE==not
};

_SCINTILLA_EDIT_STATE::_SCINTILLA_EDIT_STATE() : bRegularExpression(FALSE),
                                                 pFindReplaceDlg(NULL),
               	                                 bWord(FALSE),
                                                 bFindOnly(TRUE),
	                                               bCase(FALSE),
	                                               bNext(TRUE)
{
}

_SCINTILLA_EDIT_STATE _scintillaEditState;

void CScintillaView::PrintHeader(CDC* pDC, CPrintInfo* /*pInfo*/, RangeToFormat& frPrint)
{
  //By Default we print "Document Name - Printed on Date" as well as a line separator below the text
  //Derived classes are of course free to implement their own version of PrintHeader
  CString sHeader;
  AfxFormatString2(sHeader, IDS_SCINTILLA_DEFAULT_PRINT_HEADER, GetDocument()->GetTitle(), COleDateTime::GetCurrentTime().Format());

  //Setup the DC
  pDC->SetTextColor(RGB(0, 0, 0));
  UINT nAlign = pDC->SetTextAlign(TA_LEFT | TA_TOP);

  //Draw the header
  CSize sizeText = pDC->GetTextExtent(sHeader);
  int nHeaderDepth = 2*sizeText.cy;
	CRect rLine(frPrint.rcPage.left, frPrint.rcPage.top, frPrint.rcPage.right, frPrint.rcPage.top + nHeaderDepth);
  pDC->ExtTextOut(frPrint.rcPage.left, frPrint.rcPage.top + nHeaderDepth/3, 0, &rLine, sHeader, NULL);

  //Draw a line underneath the text
  pDC->MoveTo(frPrint.rcPage.left, frPrint.rcPage.top + nHeaderDepth - 5);
  pDC->LineTo(frPrint.rcPage.right, frPrint.rcPage.top + nHeaderDepth - 5);

  //Restore the DC
  pDC->SetTextAlign(nAlign);

  //Adjust the place where scintilla will draw the text
  if (frPrint.rc.top < (frPrint.rcPage.top + nHeaderDepth))
    frPrint.rc.top = frPrint.rcPage.top + nHeaderDepth;
}

void CScintillaView::PrintFooter(CDC* pDC, CPrintInfo* pInfo, RangeToFormat& frPrint)
{
  //By Default we print "Page X" as well as a line separator above the text
  //Derived classes are of course free to implement their own version of PrintFooter
  CString sPage;
  sPage.Format(_T("%d"), pInfo->m_nCurPage);
  CString sFooter;
  AfxFormatString1(sFooter, IDS_SCINTILLA_DEFAULT_PRINT_FOOTER, sPage);

  //Setup the DC
  pDC->SetTextColor(RGB(0, 0, 0));
  UINT nAlign = pDC->SetTextAlign(TA_LEFT | TA_TOP);
  
  //Draw the header
  CSize sizeText = pDC->GetTextExtent(sFooter);
  int nFooterDepth = 2*sizeText.cy;
  CRect rLine(frPrint.rcPage.left, frPrint.rcPage.bottom - nFooterDepth, frPrint.rcPage.right, frPrint.rcPage.bottom);
  pDC->ExtTextOut(frPrint.rcPage.left, frPrint.rcPage.bottom - nFooterDepth*2/3, 0, &rLine, sFooter, NULL);

  //Draw a line above the text
  pDC->MoveTo(frPrint.rcPage.left, frPrint.rcPage.bottom - nFooterDepth + 5);
  pDC->LineTo(frPrint.rcPage.right, frPrint.rcPage.bottom - nFooterDepth + 5);

  //Restore the DC
  pDC->SetTextAlign(nAlign);

  //Adjust the place where scintilla will draw the text
  if (frPrint.rc.bottom > (frPrint.rcPage.bottom - nFooterDepth))
    frPrint.rc.bottom = frPrint.rcPage.bottom - nFooterDepth;
}

void CScintillaView::OnReplaceSel(LPCTSTR lpszFind, BOOL bNext, BOOL bCase,	BOOL bWord, BOOL bRegularExpression, LPCTSTR lpszReplace)
{
	ASSERT_VALID(this);
	_scintillaEditState.strFind = lpszFind;
	_scintillaEditState.strReplace = lpszReplace;
	_scintillaEditState.bCase = bCase;
	_scintillaEditState.bWord = bWord;
	_scintillaEditState.bNext = bNext;
  _scintillaEditState.bRegularExpression = bRegularExpression;

	if (!SameAsSelected(_scintillaEditState.strFind, bCase, bWord, bRegularExpression))
	{
		if (!FindText(_scintillaEditState.strFind, bNext, bCase, bWord, bRegularExpression))
			TextNotFound(_scintillaEditState.strFind, bNext, bCase, bWord, bRegularExpression, TRUE);
		else
			AdjustFindDialogPosition();
		return;
	}

	m_Edit.ReplaceSel(_scintillaEditState.strReplace, TRUE);
	if (!FindText(_scintillaEditState.strFind, bNext, bCase, bWord, bRegularExpression))
		TextNotFound(_scintillaEditState.strFind, bNext, bCase, bWord, bRegularExpression, TRUE);
	else
		AdjustFindDialogPosition();
	ASSERT_VALID(this);
}

}
