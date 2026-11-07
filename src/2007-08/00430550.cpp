// from server: 100% by Intel
// from server: 99% by EspClaude
// roc 2007-08 00430550  unit: CPatchedControlComboBox  size: 529 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00430550
//
// 00430550  6aff                 push -1
// 00430552  6834d97300           push 0x73d934
// 00430557  64a100000000         mov eax, dword ptr fs:[0]
// 0043055d  50                   push eax
// 0043055e  53                   push ebx
// 0043055f  56                   push esi
// 00430560  57                   push edi
// 00430561  a188518b00           mov eax, dword ptr [0x8b5188]
// 00430566  33c4                 xor eax, esp
// 00430568  50                   push eax
// 00430569  8d442410             lea eax, [esp + 0x10]
// 0043056d  64a300000000         mov dword ptr fs:[0], eax
// 00430573  8bf1                 mov esi, ecx
// 00430575  8b7c2420             mov edi, dword ptr [esp + 0x20]
// 00430579  837f0800             cmp dword ptr [edi + 8], 0
// 0043057d  0f84c7010000         je 0x43074a
// 00430583  8b4714               mov eax, dword ptr [edi + 0x14]
// 00430586  50                   push eax
// 00430587  e8d4e42100           call 0x64ea60
// 0043058c  50                   push eax
// 0043058d  e870fc1f00           call 0x630202
// 00430592  83c408               add esp, 8
// 00430595  85c0                 test eax, eax
// 00430597  0f84ad010000         je 0x43074a
// 0043059d  8b07                 mov eax, dword ptr [edi]
// 0043059f  3d2be10000           cmp eax, 0xe12b
// 004305a4  7521                 jne 0x4305c7
// 004305a6  c7471c04000000       mov dword ptr [edi + 0x1c], 4
// 004305ad  b801000000           mov eax, 1
// 004305b2  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 004305b6  64890d00000000       mov dword ptr fs:[0], ecx
// 004305bd  59                   pop ecx
// 004305be  5f                   pop edi
// 004305bf  5e                   pop esi
// 004305c0  5b                   pop ebx
// 004305c1  83c40c               add esp, 0xc
// 004305c4  c20400               ret 4
// 004305c7  3d2ce10000           cmp eax, 0xe12c
// 004305cc  74d8                 je 0x4305a6
// 004305ce  3ddb800000           cmp eax, 0x80db
// 004305d3  753f                 jne 0x430614
// 004305d5  e896e82400           call 0x67ee70
// 004305da  8bc8                 mov ecx, eax
// 004305dc  894704               mov dword ptr [edi + 4], eax
// 004305df  e84c9b2000           call 0x63a130
// 004305e4  8b4f04               mov ecx, dword ptr [edi + 4]
// 004305e7  83e0f7               and eax, 0xfffffff7
// 004305ea  50                   push eax
// 004305eb  e8309b2000           call 0x63a120
// 004305f0  8b4f04               mov ecx, dword ptr [edi + 4]
// 004305f3  6a01                 push 1
// 004305f5  e8c6a6fdff           call 0x40acc0
// 004305fa  b801000000           mov eax, 1
// 004305ff  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00430603  64890d00000000       mov dword ptr fs:[0], ecx
// 0043060a  59                   pop ecx
// 0043060b  5f                   pop edi
// 0043060c  5e                   pop esi
// 0043060d  5b                   pop ebx
// 0043060e  83c40c               add esp, 0xc
// 00430611  c20400               ret 4
// 00430614  3df6800000           cmp eax, 0x80f6
// 00430619  74ba                 je 0x4305d5
// 0043061b  3dc3800000           cmp eax, 0x80c3
// 00430620  7576                 jne 0x430698
// 00430622  68d4010000           push 0x1d4
// 00430627  e8caf81f00           call 0x62fef6
// 0043062c  83c404               add esp, 4
// 0043062f  89442420             mov dword ptr [esp + 0x20], eax
// 00430633  85c0                 test eax, eax
// 00430635  c744241800000000     mov dword ptr [esp + 0x18], 0
// 0043063d  740b                 je 0x43064a
// 0043063f  8bc8                 mov ecx, eax
// 00430641  e80ae6ffff           call 0x42ec50
// 00430646  8bf0                 mov esi, eax
// 00430648  eb02                 jmp 0x43064c
// 0043064a  33f6                 xor esi, esi
// 0043064c  6a01                 push 1
// 0043064e  8bce                 mov ecx, esi
// 00430650  c744241cffffffff     mov dword ptr [esp + 0x1c], 0xffffffff
// 00430658  e8c3582000           call 0x635f20
// 0043065d  68e8ac7800           push 0x78ace8
// 00430662  8bce                 mov ecx, esi
// 00430664  e897a02000           call 0x63a700
// 00430669  6a01                 push 1
// 0043066b  8bce                 mov ecx, esi
// 0043066d  e84ea6fdff           call 0x40acc0
// 00430672  6a20                 push 0x20
// 00430674  8bce                 mov ecx, esi
// 00430676  e8a59a2000           call 0x63a120
// 0043067b  897704               mov dword ptr [edi + 4], esi
// 0043067e  b801000000           mov eax, 1
// 00430683  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00430687  64890d00000000       mov dword ptr fs:[0], ecx
// 0043068e  59                   pop ecx
// 0043068f  5f                   pop edi
// 00430690  5e                   pop esi
// 00430691  5b                   pop ebx
// 00430692  83c40c               add esp, 0xc
// 00430695  c20400               ret 4
// 00430698  3d40800000           cmp eax, 0x8040
// 0043069d  0f85a7000000         jne 0x43074a
// 004306a3  e8481f2400           call 0x6725f0
// 004306a8  8bd8                 mov ebx, eax
// 004306aa  8b86d8000000         mov eax, dword ptr [esi + 0xd8]
// 004306b0  50                   push eax
// 004306b1  e81a722400           call 0x6778d0
// 004306b6  83c404               add esp, 4
// 004306b9  8bf0                 mov esi, eax
// 004306bb  56                   push esi
// 004306bc  8bcb                 mov ecx, ebx
// 004306be  e8ad092400           call 0x671070
// 004306c3  6878010000           push 0x178
// 004306c8  e829f81f00           call 0x62fef6
// 004306cd  83c404               add esp, 4
// 004306d0  89442420             mov dword ptr [esp + 0x20], eax
// 004306d4  85c0                 test eax, eax
// 004306d6  c744241801000000     mov dword ptr [esp + 0x18], 1
// 004306de  7409                 je 0x4306e9
// 004306e0  8bc8                 mov ecx, eax
// 004306e2  e8c9c20100           call 0x44c9b0
// 004306e7  eb02                 jmp 0x4306eb
// 004306e9  33c0                 xor eax, eax
// 004306eb  8b8ef8000000         mov ecx, dword ptr [esi + 0xf8]
// 004306f1  6a00                 push 0
// 004306f3  6aff                 push -1
// 004306f5  6a00                 push 0
// 004306f7  688d000000           push 0x8d
// 004306fc  50                   push eax
// 004306fd  c744242cffffffff     mov dword ptr [esp + 0x2c], 0xffffffff
// 00430705  e8d6ca2400           call 0x67d1e0
// 0043070a  6a00                 push 0
// 0043070c  68ed030000           push 0x3ed
// 00430711  68e0ac7800           push 0x78ace0
// 00430716  8bce                 mov ecx, esi
// 00430718  e8c36c2400           call 0x6773e0
// 0043071d  6a01                 push 1
// 0043071f  8bce                 mov ecx, esi
// 00430721  e89aeaffff           call 0x42f1c0
// 00430726  8bce                 mov ecx, esi
// 00430728  e8b7fa1f00           call 0x6301e4
// 0043072d  895f04               mov dword ptr [edi + 4], ebx
// 00430730  b801000000           mov eax, 1
// 00430735  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00430739  64890d00000000       mov dword ptr fs:[0], ecx
// 00430740  59                   pop ecx
// 00430741  5f                   pop edi
// 00430742  5e                   pop esi
// 00430743  5b                   pop ebx
// 00430744  83c40c               add esp, 0xc
// 00430747  c20400               ret 4
// 0043074a  33c0                 xor eax, eax
// 0043074c  8b4c2410             mov ecx, dword ptr [esp + 0x10]
// 00430750  64890d00000000       mov dword ptr fs:[0], ecx
// 00430757  59                   pop ecx
// 00430758  5f                   pop edi
// 00430759  5e                   pop esi
// 0043075a  5b                   pop ebx
// 0043075b  83c40c               add esp, 0xc
// 0043075e  c20400               ret 4

// from server: 100% by EspClaude
// roc 2008-06 0042fe00  unit: CMainFrame
// roc-cl: 50727
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
class CPatchedControlComboBox : public CXTPControlComboBox { public: CPatchedControlComboBox(); char pad[0x1d4 - 4]; };
class CRobloxControlColorSelector : public CXTPControl { public: CRobloxControlColorSelector(); char pad[0x178 - 4]; };
class CXTPControls { public: CXTPControl* Add(CXTPControl* pControl, int nId, LPCTSTR lpszParameter = 0, int nBefore = -1, BOOL bTemporary = FALSE); };
class CXTPCommandBars;
class CXTPCommandBar : public CCmdTarget {
public:
    char pad[0xf8 - 4];
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
    char pad[0xd8];
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
