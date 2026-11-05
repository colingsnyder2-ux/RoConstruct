// from server: 100% by EspClaude
// roc 2009-06 00428e40  unit: CPatchedControlComboBox  size: 513 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00428e40
//
// 00428e40  64a100000000         mov eax, dword ptr fs:[0]
// 00428e46  6aff                 push -1
// 00428e48  68c41b8500           push 0x851bc4
// 00428e4d  50                   push eax
// 00428e4e  64892500000000       mov dword ptr fs:[0], esp
// 00428e55  53                   push ebx
// 00428e56  56                   push esi
// 00428e57  57                   push edi
// 00428e58  8b7c241c             mov edi, dword ptr [esp + 0x1c]
// 00428e5c  837f0800             cmp dword ptr [edi + 8], 0
// 00428e60  8bf1                 mov esi, ecx
// 00428e62  0f84c3010000         je 0x42902b
// 00428e68  8b4714               mov eax, dword ptr [edi + 0x14]
// 00428e6b  50                   push eax
// 00428e6c  e8df113100           call 0x73a050
// 00428e71  50                   push eax
// 00428e72  e84f012f00           call 0x718fc6
// 00428e77  83c408               add esp, 8
// 00428e7a  85c0                 test eax, eax
// 00428e7c  0f84a9010000         je 0x42902b
// 00428e82  8b07                 mov eax, dword ptr [edi]
// 00428e84  3d2be10000           cmp eax, 0xe12b
// 00428e89  7520                 jne 0x428eab
// 00428e8b  c7471c04000000       mov dword ptr [edi + 0x1c], 4
// 00428e92  b801000000           mov eax, 1
// 00428e97  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00428e9b  64890d00000000       mov dword ptr fs:[0], ecx
// 00428ea2  5f                   pop edi
// 00428ea3  5e                   pop esi
// 00428ea4  5b                   pop ebx
// 00428ea5  83c40c               add esp, 0xc
// 00428ea8  c20400               ret 4
// 00428eab  3d2ce10000           cmp eax, 0xe12c
// 00428eb0  74d9                 je 0x428e8b
// 00428eb2  3ddb800000           cmp eax, 0x80db
// 00428eb7  753e                 jne 0x428ef7
// 00428eb9  e8c2603400           call 0x76ef80
// 00428ebe  8bc8                 mov ecx, eax
// 00428ec0  894704               mov dword ptr [edi + 4], eax
// 00428ec3  e8e8093600           call 0x7898b0
// 00428ec8  8b4f04               mov ecx, dword ptr [edi + 4]
// 00428ecb  83e0f7               and eax, 0xfffffff7
// 00428ece  50                   push eax
// 00428ecf  e86c6b2f00           call 0x71fa40
// 00428ed4  8b4f04               mov ecx, dword ptr [edi + 4]
// 00428ed7  6a01                 push 1
// 00428ed9  e8d23ffeff           call 0x40ceb0
// 00428ede  b801000000           mov eax, 1
// 00428ee3  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00428ee7  64890d00000000       mov dword ptr fs:[0], ecx
// 00428eee  5f                   pop edi
// 00428eef  5e                   pop esi
// 00428ef0  5b                   pop ebx
// 00428ef1  83c40c               add esp, 0xc
// 00428ef4  c20400               ret 4
// 00428ef7  3df6800000           cmp eax, 0x80f6
// 00428efc  74bb                 je 0x428eb9
// 00428efe  3dc3800000           cmp eax, 0x80c3
// 00428f03  7575                 jne 0x428f7a
// 00428f05  68e0010000           push 0x1e0
// 00428f0a  e829fb2e00           call 0x718a38
// 00428f0f  83c404               add esp, 4
// 00428f12  8944241c             mov dword ptr [esp + 0x1c], eax
// 00428f16  c744241400000000     mov dword ptr [esp + 0x14], 0
// 00428f1e  85c0                 test eax, eax
// 00428f20  740b                 je 0x428f2d
// 00428f22  8bc8                 mov ecx, eax
// 00428f24  e8f7e4ffff           call 0x427420
// 00428f29  8bf0                 mov esi, eax
// 00428f2b  eb02                 jmp 0x428f2f
// 00428f2d  33f6                 xor esi, esi
// 00428f2f  6a01                 push 1
// 00428f31  8bce                 mov ecx, esi
// 00428f33  c7442418ffffffff     mov dword ptr [esp + 0x18], 0xffffffff
// 00428f3b  e820232f00           call 0x71b260
// 00428f40  68c4138b00           push 0x8b13c4
// 00428f45  8bce                 mov ecx, esi
// 00428f47  e8d4702f00           call 0x720020
// 00428f4c  6a01                 push 1
// 00428f4e  8bce                 mov ecx, esi
// 00428f50  e85b3ffeff           call 0x40ceb0
// 00428f55  6a20                 push 0x20
// 00428f57  8bce                 mov ecx, esi
// 00428f59  e8e26a2f00           call 0x71fa40
// 00428f5e  897704               mov dword ptr [edi + 4], esi
// 00428f61  b801000000           mov eax, 1
// 00428f66  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00428f6a  64890d00000000       mov dword ptr fs:[0], ecx
// 00428f71  5f                   pop edi
// 00428f72  5e                   pop esi
// 00428f73  5b                   pop ebx
// 00428f74  83c40c               add esp, 0xc
// 00428f77  c20400               ret 4
// 00428f7a  3d40800000           cmp eax, 0x8040
// 00428f7f  0f85a6000000         jne 0x42902b
// 00428f85  e8d68e3300           call 0x761e60
// 00428f8a  8bd8                 mov ebx, eax
// 00428f8c  8b86ec000000         mov eax, dword ptr [esi + 0xec]
// 00428f92  50                   push eax
// 00428f93  e848e13300           call 0x7670e0
// 00428f98  83c404               add esp, 4
// 00428f9b  8bf0                 mov esi, eax
// 00428f9d  56                   push esi
// 00428f9e  8bcb                 mov ecx, ebx
// 00428fa0  e8db783300           call 0x760880
// 00428fa5  6884010000           push 0x184
// 00428faa  e889fa2e00           call 0x718a38
// 00428faf  83c404               add esp, 4
// 00428fb2  8944241c             mov dword ptr [esp + 0x1c], eax
// 00428fb6  c744241401000000     mov dword ptr [esp + 0x14], 1
// 00428fbe  85c0                 test eax, eax
// 00428fc0  7409                 je 0x428fcb
// 00428fc2  8bc8                 mov ecx, eax
// 00428fc4  e8f73d0200           call 0x44cdc0
// 00428fc9  eb02                 jmp 0x428fcd
// 00428fcb  33c0                 xor eax, eax
// 00428fcd  8b8efc000000         mov ecx, dword ptr [esi + 0xfc]
// 00428fd3  6a00                 push 0
// 00428fd5  6aff                 push -1
// 00428fd7  6a00                 push 0
// 00428fd9  688d000000           push 0x8d
// 00428fde  50                   push eax
// 00428fdf  c7442428ffffffff     mov dword ptr [esp + 0x28], 0xffffffff
// 00428fe7  e844423400           call 0x76d230
// 00428fec  6a00                 push 0
// 00428fee  68ed030000           push 0x3ed
// 00428ff3  68bc138b00           push 0x8b13bc
// 00428ff8  8bce                 mov ecx, esi
// 00428ffa  e801dc3300           call 0x766c00
// 00428fff  6a01                 push 1
// 00429001  8bce                 mov ecx, esi
// 00429003  e8a8e1ffff           call 0x4271b0
// 00429008  8bce                 mov ecx, esi
// 0042900a  e899ff2e00           call 0x718fa8
// 0042900f  895f04               mov dword ptr [edi + 4], ebx
// 00429012  b801000000           mov eax, 1
// 00429017  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0042901b  64890d00000000       mov dword ptr fs:[0], ecx
// 00429022  5f                   pop edi
// 00429023  5e                   pop esi
// 00429024  5b                   pop ebx
// 00429025  83c40c               add esp, 0xc
// 00429028  c20400               ret 4
// 0042902b  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 0042902f  5f                   pop edi
// 00429030  5e                   pop esi
// 00429031  33c0                 xor eax, eax
// 00429033  64890d00000000       mov dword ptr fs:[0], ecx
// 0042903a  5b                   pop ebx
// 0042903b  83c40c               add esp, 0xc
// 0042903e  c20400               ret 4
// copied from an identical function in another client (function ?OnCreateControl@CMainFrame@@QAEHPAUXTP_COMMANDBARS_CREATECONTROL@@@Z)

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