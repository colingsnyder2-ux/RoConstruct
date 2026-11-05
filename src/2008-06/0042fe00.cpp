// from server: 100% by EspClaude
// roc 2008-06 0042fe00  unit: CMainFrame
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
typedef int BOOL;
typedef unsigned long DWORD;
typedef unsigned int UINT;
typedef const char* LPCTSTR;
#define TRUE 1
#define FALSE 0

struct CRuntimeClass;
class CObject { public: virtual ~CObject(); };
CObject* __cdecl AfxDynamicDownCast(CRuntimeClass* pClass, CObject* pObject);
#define RUNTIME_CLASS(c) c::GetThisClass()
#define DYNAMIC_DOWNCAST(c, p) ((c*)AfxDynamicDownCast(RUNTIME_CLASS(c), p))

class CCmdTarget : public CObject { public: DWORD InternalRelease(); };

class CXTPControl : public CCmdTarget {
public:
    void SetStyle(int buttonStyle);
    void SetFlags(DWORD dwFlags);
    DWORD GetFlags() const;
    void SetCaption(LPCTSTR lpszCaption);
};
class CXTPControlButton : public CXTPControl { public: static CXTPControlButton* CreateObject(); };
class CXTPControlComboBox : public CXTPControl { public: void SetDropDownListStyle(BOOL bSet = TRUE); };
class CPatchedControlComboBox : public CXTPControlComboBox { public: CPatchedControlComboBox(); char pad[0x1e0 - 4]; };
class CRobloxControlColorSelector : public CXTPControl { public: CRobloxControlColorSelector(); char pad[0x184 - 4]; };
class CXTPControls { public: CXTPControl* Add(CXTPControl* pControl, int nId, LPCTSTR lpszParameter = 0, int nBefore = -1, BOOL bTemporary = FALSE); };
class CXTPCommandBars;
class CXTPCommandBar : public CCmdTarget {
public:
    char pad[0xfc - 4];
    CXTPControls* m_pControls;
    CXTPControls* GetControls() const { return m_pControls; }
    void EnableCustomization(BOOL bEnable = TRUE);
};
class CXTPToolBar : public CXTPCommandBar { public: static CRuntimeClass* __stdcall GetThisClass(); };
class CXTPPopupBar : public CXTPCommandBar {
public:
    void SetTearOffPopup(LPCTSTR lpszCaption, UINT nID, int nWidth = 400);
};
class CXTPPopupToolBar : public CXTPPopupBar { public: static CXTPPopupToolBar* __cdecl CreatePopupToolBar(CXTPCommandBars* pCommandBars); };
class CXTPControlPopup : public CXTPControl { public: void SetCommandBar(CXTPCommandBar* pBar); };
class CXTPControlPopupColor : public CXTPControlPopup { public: static CXTPControlPopupColor* CreateObject(); };

struct XTP_COMMANDBARS_CREATECONTROL {
    UINT nID;
    CXTPControl* pControl;
    BOOL bToolBar;
    void* pMenu;
    int nIndex;
    CXTPCommandBar* pCommandBar;
    void* strCaption;
    int controlType;
};
typedef XTP_COMMANDBARS_CREATECONTROL* LPCREATECONTROLSTRUCT;

class CMainFrame {
public:
    char pad[0xec];
    CXTPCommandBars* m_pCommandBars;
    CXTPCommandBars* GetCommandBars() const { return m_pCommandBars; }
    int OnCreateControl(LPCREATECONTROLSTRUCT lpCreateControl);
};

int CMainFrame::OnCreateControl(LPCREATECONTROLSTRUCT lpCreateControl)
{
    if (lpCreateControl->bToolBar)
    {
        CXTPToolBar* pToolBar = DYNAMIC_DOWNCAST(CXTPToolBar, lpCreateControl->pCommandBar);
        if (!pToolBar)
            return FALSE;

        if (lpCreateControl->nID == 0xe12b)
        {
            lpCreateControl->controlType = 4;
            return TRUE;
        }
        if (lpCreateControl->nID == 0xe12c)
        {
            lpCreateControl->controlType = 4;
            return TRUE;
        }
        if (lpCreateControl->nID == 0x80db)
        {
            lpCreateControl->pControl = CXTPControlButton::CreateObject();
            lpCreateControl->pControl->SetFlags(lpCreateControl->pControl->GetFlags() & ~8);
            lpCreateControl->pControl->SetStyle(1);
            return TRUE;
        }
        if (lpCreateControl->nID == 0x80f6)
        {
            lpCreateControl->pControl = CXTPControlButton::CreateObject();
            lpCreateControl->pControl->SetFlags(lpCreateControl->pControl->GetFlags() & ~8);
            lpCreateControl->pControl->SetStyle(1);
            return TRUE;
        }
        if (lpCreateControl->nID == 0x80c3)
        {
            CXTPControlComboBox* pCombo = new CPatchedControlComboBox();
            pCombo->SetDropDownListStyle(TRUE);
            pCombo->SetCaption("Command >");
            pCombo->SetStyle(1);
            pCombo->SetFlags(0x20);
            lpCreateControl->pControl = pCombo;
            return TRUE;
        }
        if (lpCreateControl->nID == 0x8040)
        {
            CXTPControlPopupColor* pPopupColor = CXTPControlPopupColor::CreateObject();
            CXTPPopupBar* pColorBar = CXTPPopupToolBar::CreatePopupToolBar(GetCommandBars());
            pPopupColor->SetCommandBar(pColorBar);
            pColorBar->GetControls()->Add(new CRobloxControlColorSelector(), 0x8d);
            pColorBar->SetTearOffPopup("Color", 0x3ed, FALSE);
            pColorBar->EnableCustomization(TRUE);
            pColorBar->InternalRelease();
            lpCreateControl->pControl = pPopupColor;
            return TRUE;
        }
    }
    return FALSE;
}
