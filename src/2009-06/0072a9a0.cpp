// from server: 98% by EspClaude
// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-11.2.2 roc_espclaude_2ea99f17a31c8841.cpp

// Candidate translation unit (score above; library headers required).
#ifndef _DLL
#define _DLL
#endif
#ifndef _AFXDLL
#define _AFXDLL
#endif
#include <afxwin.h>
class CXTPControl {
public:
    virtual void c0();
    virtual void c1();
    virtual void c2();
    virtual void c3();
    virtual void c4();
    virtual void c5();
    virtual void c6();
    virtual void c7();
    virtual void c8();
    virtual void c9();
    virtual void c10();
    virtual void c11();
    virtual void c12();
    virtual void c13();
    virtual void c14();
    virtual void c15();
    virtual void c16();
    virtual void c17();
    virtual void c18();
    virtual void c19();
    virtual void c20();
    virtual void c21();
    virtual void c22();
    virtual void c23();
    virtual void c24();
    virtual void c25();
    virtual void c26();
    virtual void c27();
    virtual void c28();
    virtual void c29();
    virtual void c30();
    virtual void c31();
    virtual void c32();
    virtual void c33();
    virtual void c34();
    virtual void c35();
    virtual void c36();
    virtual void c37();
    virtual void c38();
    virtual void c39();
    virtual void c40();
    virtual void c41();
    virtual void c42();
    virtual void c43();
    virtual void c44();
    virtual void c45();
    virtual void c46();
    virtual void OnThemeChanged();
};
class CXTPToolBar {
public:
    virtual void t0();
    virtual void t1();
    virtual void t2();
    virtual void t3();
    virtual void t4();
    virtual void t5();
    virtual void t6();
    virtual void t7();
    virtual void t8();
    virtual void t9();
    virtual void t10();
    virtual void t11();
    virtual void t12();
    virtual void t13();
    virtual void t14();
    virtual void t15();
    virtual void t16();
    virtual void t17();
    virtual void t18();
    virtual void t19();
    virtual void t20();
    virtual void t21();
    virtual void t22();
    virtual void t23();
    virtual void t24();
    virtual void t25();
    virtual void t26();
    virtual void t27();
    virtual void t28();
    virtual void t29();
    virtual void t30();
    virtual void t31();
    virtual void t32();
    virtual void t33();
    virtual void t34();
    virtual void t35();
    virtual void t36();
    virtual void t37();
    virtual void t38();
    virtual void t39();
    virtual void t40();
    virtual void t41();
    virtual void t42();
    virtual void t43();
    virtual void t44();
    virtual void t45();
    virtual void t46();
    virtual void t47();
    virtual void t48();
    virtual void t49();
    virtual void t50();
    virtual void t51();
    virtual void t52();
    virtual void t53();
    virtual void t54();
    virtual void t55();
    virtual void t56();
    virtual void t57();
    virtual void t58();
    virtual void t59();
    virtual void t60();
    virtual void t61();
    virtual void t62();
    virtual void t63();
    virtual void t64();
    virtual void t65();
    virtual void t66();
    virtual void t67();
    virtual void t68();
    virtual void t69();
    virtual void t70();
    virtual void t71();
    virtual void t72();
    virtual void t73();
    virtual void t74();
    virtual void t75();
    virtual void t76();
    virtual void t77();
    virtual void t78();
    virtual void t79();
    virtual void t80();
    virtual void t81();
    virtual void t82();
    virtual void t83();
    virtual void t84();
    virtual void t85();
    virtual void t86();
    virtual void t87();
    virtual void t88();
    virtual void t89();
    virtual BOOL IsVisible();
    virtual void u0();
    virtual void u1();
    virtual void u2();
    virtual void u3();
    virtual void u4();
    virtual void u5();
    virtual void OnRecalcLayout();
    int GetControlCount() const;
    CXTPControl* GetControl(int nIndex) const;
};
class CXTPTabClientWnd : public CWnd {
    DECLARE_DYNAMIC(CXTPTabClientWnd)
public:
    void Refresh(BOOL bRecalcLayout = TRUE);
};
class CXTPCommandBars {
public:
    char pad0[0x84];
    int m_nCount;
    char pad88[0xa0 - 0x88];
    CWnd* m_pFrame;
    char pada4[0xc0 - 0xa4];
    BOOL m_bRecalcLayout;
    int GetCount() const { return m_nCount; }
    CXTPToolBar* GetAt(int nIndex) const;
    CWnd* GetSite() const { return m_pFrame; }
    void RecalcFrameLayout(BOOL bDelay = FALSE);
    void RedrawCommandBars();
};
void CXTPCommandBars::RedrawCommandBars()
{
	m_bRecalcLayout = TRUE;

	for (int i = 0; i < GetCount(); i++)
	{
		CXTPToolBar* pBar = GetAt(i);

		for (int j = 0; j < pBar->GetControlCount(); j++)
		{
			pBar->GetControl(j)->OnThemeChanged();
		}

		if (pBar->IsVisible())
		{
			pBar->OnRecalcLayout();
		}
	}

	CMDIFrameWnd* pMDIFrame = DYNAMIC_DOWNCAST(CMDIFrameWnd, GetSite());
	if (pMDIFrame)
	{
		CXTPTabClientWnd* pClient = DYNAMIC_DOWNCAST(CXTPTabClientWnd, CWnd::FromHandle(pMDIFrame->m_hWndMDIClient));
		if (pClient)
			pClient->Refresh();
	}

	CWnd* pWnd = GetSite()->GetDlgItem(AFX_IDW_STATUS_BAR);
	if (pWnd)
	{
		pWnd->Invalidate(FALSE);
	}

	m_bRecalcLayout = FALSE;
	RecalcFrameLayout();

	GetSite()->SendMessage(WM_NCPAINT);
}

