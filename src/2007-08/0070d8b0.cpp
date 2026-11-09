// from server: 100% by EspClaude
// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS /EHsc /MD
// roc-lib: xtp-11.2.2-vc8-shared-mfc roc_espclaude_ebecf9e15a3e1219.cpp

// Candidate translation unit (score above; library headers required).
// XTColorPageCustom.cpp as found in the 2007-08 client (older XTP layout,
// derived from the exe: CXTColorBase has an 8-byte GDI object @0x54, bool @0x5c,
// COLORREF @0x60, doubles @0x68/0x70/0x78, CPoint @0x80; virtual SetColor(COLORREF,bool),
// GetColor(), UpdateCursorPos(CPoint,BOOL), Init(); CXTColorLum has an int @0x88).
#define __XTCOLORCUSTOM_H__
class CXTColorBase; class CXTColorWnd; class CXTColorLum; class CXTColorPageCustom;
#include "stdafx.h"
#include "Controls/Resource.h"

#include "Common/XTPDrawHelpers.h"
#include "Common/XTPColorManager.h"
#include "Common/XTPSystemHelpers.h"

#include "Controls/XTNotify.h"
#include "Controls/XTColorRef.h"

class CXTColorDialog;

class _XTP_EXT_CLASS CXTColorBase : public CStatic
{
public:
	enum FocusedControl { focusNone, focusColorWheel, focusLumination };
	CXTColorBase();
	virtual ~CXTColorBase();
	virtual void SetColor(COLORREF clr, bool bUpdate = true);
	virtual COLORREF GetColor() { return m_clr; }
	virtual void UpdateCursorPos(CPoint point, BOOL bNotify = TRUE);
	static COLORREF HLStoRGB(double h, double l, double s);
	static void RGBtoHSL(COLORREF color, double* h, double* s, double* l);
protected:
	virtual bool Init();
	virtual void PreSubclassWindow();
	virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
	afx_msg void OnLButtonDown(UINT nFlags, CPoint point);
	afx_msg void OnMouseMove(UINT nFlags, CPoint point);
	afx_msg void OnLButtonUp(UINT nFlags, CPoint point);
	afx_msg void OnLButtonDblClk(UINT nFlags, CPoint point);
	afx_msg int OnCreate(LPCREATESTRUCT lpCreateStruct);
	DECLARE_MESSAGE_MAP()
protected:
	static FocusedControl m_eHasFocus;
	CBitmap        m_bmpPicker;
	bool           m_bPreSubclassInit;
	COLORREF       m_clr;
public:
	double m_nLum;
	double m_nSat;
	double m_nHue;
	CPoint m_ptMousePos;
};

class _XTP_EXT_CLASS CXTColorWnd : public CXTColorBase
{
public:
	CXTColorWnd();
	virtual ~CXTColorWnd();
	virtual void SetColor(COLORREF clr, bool bUpdate = true);
	virtual void UpdateCursorPos(CPoint point, BOOL bNotify = TRUE);
	void SetHue(double h);
	void SetSaturation(double s);
	virtual BOOL PreTranslateMessage(MSG* pMsg);
	void DrawCrossHair(CDC* pDC);
protected:
	afx_msg void OnPaint();
	afx_msg void OnSetFocus(CWnd* pOldWnd);
	afx_msg void OnKillFocus(CWnd* pNewWnd);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	DECLARE_MESSAGE_MAP()
};

class _XTP_EXT_CLASS CXTColorLum : public CXTColorBase
{
public:
	CXTColorLum();
	virtual ~CXTColorLum();
	virtual void SetColor(COLORREF clr, bool bUpdate = true);
	virtual void UpdateCursorPos(CPoint point, BOOL bNotify = TRUE);
	void SetLuminance(double l);
	void GetLumBarRect(CRect& rect);
	virtual BOOL PreTranslateMessage(MSG* pMsg);
protected:
	afx_msg void OnPaint();
	afx_msg void OnSetFocus(CWnd* pOldWnd);
	afx_msg void OnKillFocus(CWnd* pNewWnd);
	afx_msg BOOL OnEraseBkgnd(CDC* pDC);
	DECLARE_MESSAGE_MAP()
protected:
	int m_nLumPos;
};

class _XTP_EXT_CLASS CXTColorPageCustom : public CPropertyPage
{
public:
	CXTColorPageCustom(CXTColorDialog* pParentSheet = NULL);
	virtual ~CXTColorPageCustom();
	void RGBtoHSL(COLORREF color, int* lum, int* sat, int* hue);
protected:
	virtual BOOL OnSetActive();
	virtual void DoDataExchange(CDataExchange* pDX);
	virtual BOOL OnInitDialog();
	void UpdateRGB(COLORREF clr);
	afx_msg void OnChangeEdit();
	afx_msg void OnChangeEditLum();
	afx_msg void OnChangeEditHue();
	afx_msg void OnChangeEditSat();
	afx_msg LRESULT OnUpdateColor(WPARAM wParam, LPARAM lParam);
	DECLARE_MESSAGE_MAP()
protected:
	enum { IDD = XT_IDD_COLORCUSTOM };
	CXTColorWnd m_colorWnd;
	CXTColorLum m_colorLum;
	CStatic m_txtSat;
	CStatic m_txtRed;
	CStatic m_txtLum;
	CStatic m_txtHue;
	CStatic m_txtGreen;
	CStatic m_txtBlue;
	CSpinButtonCtrl m_spinSat;
	CSpinButtonCtrl m_spinRed;
	CSpinButtonCtrl m_spinLum;
	CSpinButtonCtrl m_spinHue;
	CSpinButtonCtrl m_spinGreen;
	CSpinButtonCtrl m_spinBlue;
	CEdit m_editHue;
	CEdit m_editGreen;
	CEdit m_editBlue;
	CEdit m_editLum;
	CEdit m_editRed;
	CEdit m_editSat;
	int     m_nR;
	int     m_nB;
	int     m_nG;
	int     m_nH;
	int     m_nL;
	int     m_nS;
	CXTColorDialog*     m_pParentSheet;
	friend class CXTColorLum;
};

#include "Controls/XTColorDialog.h"

void CXTColorBase::OnLButtonDown(UINT nFlags, CPoint point)
{
	CWnd::OnLButtonDown(nFlags, point);
	SetCapture();
	UpdateCursorPos(point);

	if (GetFocus() != this)
	{
		SetFocus();
	}
}

void CXTColorBase::OnLButtonDblClk(UINT nFlags, CPoint point)
{
	CStatic::OnLButtonDblClk(nFlags, point);

	UpdateCursorPos(point);

	CPropertyPage* pParentPage = (CPropertyPage*)GetParent();
	CPropertySheet* pParentSheet = (CPropertySheet*)pParentPage->GetParent();
	pParentSheet->EndDialog(IDOK);
}

void CXTColorWnd::SetColor(COLORREF clr, bool bUpdate)
{
	CXTColorBase::SetColor(clr, bUpdate);
	if (bUpdate)
	{
		CRect rc;
		GetClientRect(&rc);
		m_ptMousePos.x = (long)((double)rc.Width() * m_nHue);
		m_ptMousePos.y = rc.Height() - (long)((double)rc.Height() * m_nSat);
	}
}

void CXTColorWnd::SetHue(double h)
{
	m_nHue = h;
	CRect rc;
	GetClientRect(&rc);
	m_ptMousePos.x = (long)((double)rc.Width() * h);
	UpdateCursorPos(m_ptMousePos, FALSE);
}

void CXTColorWnd::SetSaturation(double s)
{
	m_nSat = s;
	CRect rc;
	GetClientRect(&rc);
	m_ptMousePos.y = rc.Height() - (long)((double)rc.Height() * s);
	UpdateCursorPos(m_ptMousePos, FALSE);
}

void CXTColorLum::SetLuminance(double l)
{
	m_nLum = l;

	CRect rcBar;
	GetLumBarRect(rcBar);

	m_ptMousePos.y = m_nLumPos = rcBar.Height() - (long)((double)rcBar.Height() * l);
	UpdateCursorPos(m_ptMousePos, FALSE);
}

void CXTColorPageCustom::DoDataExchange(CDataExchange* pDX)
{
	CPropertyPage::DoDataExchange(pDX);
	DDX_Control(pDX, XT_IDC_CLR_WND, m_colorWnd);
	DDX_Control(pDX, XT_IDC_CLR_LUM, m_colorLum);
	DDX_Control(pDX, XT_IDC_TXT_SAT, m_txtSat);
	DDX_Control(pDX, XT_IDC_TXT_RED, m_txtRed);
	DDX_Control(pDX, XT_IDC_TXT_LUM, m_txtLum);
	DDX_Control(pDX, XT_IDC_TXT_HUE, m_txtHue);
	DDX_Control(pDX, XT_IDC_TXT_GREEN, m_txtGreen);
	DDX_Control(pDX, XT_IDC_TXT_BLUE, m_txtBlue);
	DDX_Control(pDX, XT_IDC_SPIN_SAT, m_spinSat);
	DDX_Control(pDX, XT_IDC_SPIN_RED, m_spinRed);
	DDX_Control(pDX, XT_IDC_SPIN_LUM, m_spinLum);
	DDX_Control(pDX, XT_IDC_SPIN_HUE, m_spinHue);
	DDX_Control(pDX, XT_IDC_SPIN_GREEN, m_spinGreen);
	DDX_Control(pDX, XT_IDC_SPIN_BLUE, m_spinBlue);
	DDX_Control(pDX, XT_IDC_EDIT_HUE, m_editHue);
	DDX_Control(pDX, XT_IDC_EDIT_GREEN, m_editGreen);
	DDX_Control(pDX, XT_IDC_EDIT_BLUE, m_editBlue);
	DDX_Control(pDX, XT_IDC_EDIT_LUM, m_editLum);
	DDX_Control(pDX, XT_IDC_EDIT_RED, m_editRed);
	DDX_Control(pDX, XT_IDC_EDIT_SAT, m_editSat);
	DDX_Text(pDX, XT_IDC_EDIT_RED, m_nR);
	DDV_MinMaxInt(pDX, m_nR, 0, 255);
	DDX_Text(pDX, XT_IDC_EDIT_BLUE, m_nB);
	DDV_MinMaxInt(pDX, m_nB, 0, 255);
	DDX_Text(pDX, XT_IDC_EDIT_GREEN, m_nG);
	DDV_MinMaxInt(pDX, m_nG, 0, 255);
	DDX_Text(pDX, XT_IDC_EDIT_HUE, m_nH);
	DDV_MinMaxInt(pDX, m_nH, 0, 255);
	DDX_Text(pDX, XT_IDC_EDIT_LUM, m_nL);
	DDV_MinMaxInt(pDX, m_nL, 0, 255);
	DDX_Text(pDX, XT_IDC_EDIT_SAT, m_nS);
	DDV_MinMaxInt(pDX, m_nS, 0, 255);
}

BOOL CXTColorPageCustom::OnInitDialog()
{
	CPropertyPage::OnInitDialog();

	m_spinSat.SetBuddy(&m_editSat);
	m_spinSat.SetRange(0, 255);

	m_spinLum.SetBuddy(&m_editLum);
	m_spinLum.SetRange(0, 255);

	m_spinHue.SetBuddy(&m_editHue);
	m_spinHue.SetRange(0, 255);

	m_spinRed.SetBuddy(&m_editRed);
	m_spinRed.SetRange(0, 255);

	m_spinGreen.SetBuddy(&m_editGreen);
	m_spinGreen.SetRange(0, 255);

	m_spinBlue.SetBuddy(&m_editBlue);
	m_spinBlue.SetRange(0, 255);

	return TRUE;
}

BOOL CXTColorPageCustom::OnSetActive()
{
	COLORREF clr = m_pParentSheet->GetColor();

	m_colorWnd.SetColor(clr, true);
	m_colorLum.SetColor(clr, true);
	RGBtoHSL(clr, &m_nL, &m_nS, &m_nH);

	UpdateRGB(clr);

	return CPropertyPage::OnSetActive();
}

void CXTColorPageCustom::OnChangeEditLum()
{
	UpdateData();
	m_colorLum.SetLuminance((double)m_nL/255);

	COLORREF clr = m_colorLum.GetColor();

	if (clr != m_colorWnd.GetColor())
		m_colorWnd.SetColor(clr, false);

	if (clr != m_pParentSheet->GetColor())
		m_pParentSheet->SetNewColor(clr, FALSE);

	UpdateRGB(clr);
}

void CXTColorPageCustom::UpdateRGB(COLORREF clr)
{
	m_nR = GetRValue(clr);
	m_nG = GetGValue(clr);
	m_nB = GetBValue(clr);

	UpdateData(FALSE);
}

void CXTColorPageCustom::OnChangeEditHue()
{
	UpdateData();
	m_colorWnd.SetHue((double)m_nH/255);

	COLORREF clr = m_colorWnd.GetColor();

	if (clr != m_colorLum.GetColor())
		m_colorLum.SetColor(clr, false);

	if (clr != m_pParentSheet->GetColor())
		m_pParentSheet->SetNewColor(clr, FALSE);

	UpdateRGB(clr);
}

void CXTColorPageCustom::OnChangeEditSat()
{
	UpdateData();
	m_colorWnd.SetSaturation((double)m_nS/255);

	COLORREF clr = m_colorWnd.GetColor();

	if (clr != m_colorLum.GetColor())
		m_colorLum.SetColor(clr, false);

	if (clr != m_pParentSheet->GetColor())
		m_pParentSheet->SetNewColor(clr, FALSE);

	UpdateRGB(clr);
}

void CXTColorLum::SetColor(COLORREF clr, bool bUpdate)
{
	CXTColorBase::SetColor(clr, bUpdate);
	if (bUpdate)
	{
		CRect rcBar;
		GetLumBarRect(rcBar);
		m_ptMousePos.y = m_nLumPos = rcBar.Height() - (long)((double)rcBar.Height() * m_nLum);
	}
}

void CXTColorBase::UpdateCursorPos(CPoint point, BOOL bNotify)
{
	CXTPCompatibleDC dc(NULL, m_bmpPicker);
	COLORREF clr = ::GetPixel(dc, point.x, point.y);
	if (clr != CLR_INVALID)
	{
		m_clr = clr;
		if (bNotify)
		{
			GetParent()->SendMessage(XTWM_UPDATECOLOR, (WPARAM)m_clr, (LPARAM)m_hWnd);
		}
	}
	m_ptMousePos = point;
}

void CXTColorLum::UpdateCursorPos(CPoint point, BOOL bNotify)
{
	point.x = 0;
	CXTPCompatibleDC dc(NULL, m_bmpPicker);
	COLORREF clr = ::GetPixel(dc, point.x, point.y);
	if (clr != CLR_INVALID)
	{
		m_clr = clr;
		if (bNotify)
		{
			GetParent()->SendMessage(XTWM_UPDATECOLOR, (WPARAM)m_clr, (LPARAM)m_hWnd);
		}
		m_ptMousePos = point;
		m_nLumPos = point.y;
		Invalidate(FALSE);
	}
}
