// from server: 100% by EspClaude
// from server: 44% by colin
// roc 2007-08 006a88c0  unit: CXTPRibbonBar::CControlQuickAccessMorePopup  size: 724 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 006a88c0
//
// 006a88c0  6aff                 push -1
// 006a88c2  68e54b7600           push 0x764be5
// 006a88c7  64a100000000         mov eax, dword ptr fs:[0]
// 006a88cd  50                   push eax
// 006a88ce  83ec08               sub esp, 8
// 006a88d1  53                   push ebx
// 006a88d2  55                   push ebp
// 006a88d3  56                   push esi
// 006a88d4  57                   push edi
// 006a88d5  a188518b00           mov eax, dword ptr [0x8b5188]
// 006a88da  33c4                 xor eax, esp
// 006a88dc  50                   push eax
// 006a88dd  8d44241c             lea eax, [esp + 0x1c]
// 006a88e1  64a300000000         mov dword ptr fs:[0], eax
// 006a88e7  8bf1                 mov esi, ecx
// 006a88e9  89742414             mov dword ptr [esp + 0x14], esi
// 006a88ed  e80eddffff           call 0x6a6600
// 006a88f2  c786c4010000b04e7d00 mov dword ptr [esi + 0x1c4], 0x7d4eb0
// 006a88fc  8daec4010000         lea ebp, [esi + 0x1c4]
// 006a8902  33db                 xor ebx, ebx
// 006a8904  6a40                 push 0x40
// 006a8906  895c2428             mov dword ptr [esp + 0x28], ebx
// 006a890a  c706dc517d00         mov dword ptr [esi], 0x7d51dc
// 006a8910  c74654cc517d00       mov dword ptr [esi + 0x54], 0x7d51cc
// 006a8917  c7465c6c517d00       mov dword ptr [esi + 0x5c], 0x7d516c
// 006a891e  c7450060517d00       mov dword ptr [ebp], 0x7d5160
// 006a8925  e8cc75f8ff           call 0x62fef6
// 006a892a  83c404               add esp, 4
// 006a892d  89442418             mov dword ptr [esp + 0x18], eax
// 006a8931  3bc3                 cmp eax, ebx
// 006a8933  c644242401           mov byte ptr [esp + 0x24], 1
// 006a8938  7409                 je 0x6a8943
// 006a893a  8bc8                 mov ecx, eax
// 006a893c  e8af040700           call 0x718df0
// 006a8941  eb02                 jmp 0x6a8945
// 006a8943  33c0                 xor eax, eax
// 006a8945  56                   push esi
// 006a8946  8bc8                 mov ecx, eax
// 006a8948  885c2428             mov byte ptr [esp + 0x28], bl
// 006a894c  898660020000         mov dword ptr [esi + 0x260], eax
// 006a8952  e8e91cfdff           call 0x67a640
// 006a8957  8b8ef8000000         mov ecx, dword ptr [esi + 0xf8]
// 006a895d  e88278f8ff           call 0x6301e4
// 006a8962  6a40                 push 0x40
// 006a8964  e88d75f8ff           call 0x62fef6
// 006a8969  83c404               add esp, 4
// 006a896c  89442418             mov dword ptr [esp + 0x18], eax
// 006a8970  3bc3                 cmp eax, ebx
// 006a8972  c644242402           mov byte ptr [esp + 0x24], 2
// 006a8977  7409                 je 0x6a8982
// 006a8979  8bc8                 mov ecx, eax
// 006a897b  e890030700           call 0x718d10
// 006a8980  eb02                 jmp 0x6a8984
// 006a8982  33c0                 xor eax, eax
// 006a8984  56                   push esi
// 006a8985  8bc8                 mov ecx, eax
// 006a8987  885c2428             mov byte ptr [esp + 0x28], bl
// 006a898b  8986f8000000         mov dword ptr [esi + 0xf8], eax
// 006a8991  e8aa1cfdff           call 0x67a640
// 006a8996  8b3d14ee7700         mov edi, dword ptr [0x77ee14]
// 006a899c  8d86d8010000         lea eax, [esi + 0x1d8]
// 006a89a2  50                   push eax
// 006a89a3  c7868c02000001000000 mov dword ptr [esi + 0x28c], 1
// 006a89ad  899e74020000         mov dword ptr [esi + 0x274], ebx
// 006a89b3  899eec000000         mov dword ptr [esi + 0xec], ebx
// 006a89b9  ffd7                 call edi
// 006a89bb  8d8ee8010000         lea ecx, [esi + 0x1e8]
// 006a89c1  51                   push ecx
// 006a89c2  ffd7                 call edi
// 006a89c4  8d96f8010000         lea edx, [esi + 0x1f8]
// 006a89ca  52                   push edx
// 006a89cb  ffd7                 call edi
// 006a89cd  8d8608020000         lea eax, [esi + 0x208]
// 006a89d3  50                   push eax
// 006a89d4  ffd7                 call edi
// 006a89d6  8d8e18020000         lea ecx, [esi + 0x218]
// 006a89dc  51                   push ecx
// 006a89dd  ffd7                 call edi
// 006a89df  56                   push esi
// 006a89e0  8bcd                 mov ecx, ebp
// 006a89e2  e809feffff           call 0x6a87f0
// 006a89e7  6878010000           push 0x178
// 006a89ec  e80575f8ff           call 0x62fef6
// 006a89f1  83c404               add esp, 4
// 006a89f4  89442418             mov dword ptr [esp + 0x18], eax
// 006a89f8  3bc3                 cmp eax, ebx
// 006a89fa  c644242403           mov byte ptr [esp + 0x24], 3
// 006a89ff  7409                 je 0x6a8a0a
// 006a8a01  8bc8                 mov ecx, eax
// 006a8a03  e868eeffff           call 0x6a7870
// 006a8a08  eb02                 jmp 0x6a8a0c
// 006a8a0a  33c0                 xor eax, eax
// 006a8a0c  8b8ef8000000         mov ecx, dword ptr [esi + 0xf8]
// 006a8a12  53                   push ebx
// 006a8a13  6aff                 push -1
// 006a8a15  53                   push ebx
// 006a8a16  6883250000           push 0x2583
// 006a8a1b  50                   push eax
// 006a8a1c  885c2438             mov byte ptr [esp + 0x38], bl
// 006a8a20  e8bb47fdff           call 0x67d1e0
// 006a8a25  6878010000           push 0x178
// 006a8a2a  898668020000         mov dword ptr [esi + 0x268], eax
// 006a8a30  e8c174f8ff           call 0x62fef6
// 006a8a35  83c404               add esp, 4
// 006a8a38  89442418             mov dword ptr [esp + 0x18], eax
// 006a8a3c  3bc3                 cmp eax, ebx
// 006a8a3e  c644242404           mov byte ptr [esp + 0x24], 4
// 006a8a43  7409                 je 0x6a8a4e
// 006a8a45  8bc8                 mov ecx, eax
// 006a8a47  e8f4eeffff           call 0x6a7940
// 006a8a4c  eb02                 jmp 0x6a8a50
// 006a8a4e  33c0                 xor eax, eax
// 006a8a50  8b8ef8000000         mov ecx, dword ptr [esi + 0xf8]
// 006a8a56  53                   push ebx
// 006a8a57  6aff                 push -1
// 006a8a59  53                   push ebx
// 006a8a5a  688b250000           push 0x258b
// 006a8a5f  50                   push eax
// 006a8a60  885c2438             mov byte ptr [esp + 0x38], bl
// 006a8a64  e87747fdff           call 0x67d1e0
// 006a8a69  6808020000           push 0x208
// 006a8a6e  89866c020000         mov dword ptr [esi + 0x26c], eax
// 006a8a74  e87d74f8ff           call 0x62fef6
// 006a8a79  83c404               add esp, 4
// 006a8a7c  89442418             mov dword ptr [esp + 0x18], eax
// 006a8a80  3bc3                 cmp eax, ebx
// 006a8a82  c644242405           mov byte ptr [esp + 0x24], 5
// 006a8a87  7409                 je 0x6a8a92
// 006a8a89  8bc8                 mov ecx, eax
// 006a8a8b  e8f0e90600           call 0x717480
// 006a8a90  eb02                 jmp 0x6a8a94
// 006a8a92  33c0                 xor eax, eax
// 006a8a94  8b8ef8000000         mov ecx, dword ptr [esi + 0xf8]
// 006a8a9a  53                   push ebx
// 006a8a9b  6aff                 push -1
// 006a8a9d  53                   push ebx
// 006a8a9e  6884250000           push 0x2584
// 006a8aa3  50                   push eax
// 006a8aa4  885c2438             mov byte ptr [esp + 0x38], bl
// 006a8aa8  e83347fdff           call 0x67d1e0
// 006a8aad  bf01000000           mov edi, 1
// 006a8ab2  6a14                 push 0x14
// 006a8ab4  898664020000         mov dword ptr [esi + 0x264], eax
// 006a8aba  c786f400000003000000 mov dword ptr [esi + 0xf4], 3
// 006a8ac4  c786e800000040040000 mov dword ptr [esi + 0xe8], 0x440
// 006a8ace  899e34010000         mov dword ptr [esi + 0x134], ebx
// 006a8ad4  89be3c020000         mov dword ptr [esi + 0x23c], edi
// 006a8ada  89be40020000         mov dword ptr [esi + 0x240], edi
// 006a8ae0  c78678020000fa000000 mov dword ptr [esi + 0x278], 0xfa
// 006a8aea  899e60010000         mov dword ptr [esi + 0x160], ebx
// 006a8af0  899e88020000         mov dword ptr [esi + 0x288], ebx
// 006a8af6  899e7c020000         mov dword ptr [esi + 0x27c], ebx
// 006a8afc  899e70020000         mov dword ptr [esi + 0x270], ebx
// 006a8b02  89be38020000         mov dword ptr [esi + 0x238], edi
// 006a8b08  899e54020000         mov dword ptr [esi + 0x254], ebx
// 006a8b0e  899e44020000         mov dword ptr [esi + 0x244], ebx
// 006a8b14  89be48020000         mov dword ptr [esi + 0x248], edi
// 006a8b1a  e8d773f8ff           call 0x62fef6
// 006a8b1f  83c404               add esp, 4
// 006a8b22  89442418             mov dword ptr [esp + 0x18], eax
// 006a8b26  3bc3                 cmp eax, ebx
// 006a8b28  c644242406           mov byte ptr [esp + 0x24], 6
// 006a8b2d  7409                 je 0x6a8b38
// 006a8b2f  8bc8                 mov ecx, eax
// 006a8b31  e89ada0600           call 0x7165d0
// 006a8b36  eb02                 jmp 0x6a8b3a
// 006a8b38  33c0                 xor eax, eax
// 006a8b3a  57                   push edi
// 006a8b3b  8bce                 mov ecx, esi
// 006a8b3d  885c2428             mov byte ptr [esp + 0x28], bl
// 006a8b41  898680020000         mov dword ptr [esi + 0x280], eax
// 006a8b47  89be6c010000         mov dword ptr [esi + 0x16c], edi
// 006a8b4d  899e4c020000         mov dword ptr [esi + 0x24c], ebx
// 006a8b53  89be50020000         mov dword ptr [esi + 0x250], edi
// 006a8b59  899e84020000         mov dword ptr [esi + 0x284], ebx
// 006a8b5f  899e58020000         mov dword ptr [esi + 0x258], ebx
// 006a8b65  899ec8010000         mov dword ptr [esi + 0x1c8], ebx
// 006a8b6b  89be5c020000         mov dword ptr [esi + 0x25c], edi
// 006a8b71  e8aaacf9ff           call 0x643820
// 006a8b76  57                   push edi
// 006a8b77  8bce                 mov ecx, esi
// 006a8b79  e872acf9ff           call 0x6437f0
// 006a8b7e  8bc6                 mov eax, esi
// 006a8b80  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 006a8b84  64890d00000000       mov dword ptr fs:[0], ecx
// 006a8b8b  59                   pop ecx
// 006a8b8c  5f                   pop edi
// 006a8b8d  5e                   pop esi
// 006a8b8e  5d                   pop ebp
// 006a8b8f  5b                   pop ebx
// 006a8b90  83c414               add esp, 0x14
// 006a8b93  c3                   ret 


// CXTPRibbonBar::CXTPRibbonBar() (XTP ribbon constructor shape). Offsets, allocation sizes,
// control ids and stored values are read off the target bytes above.
typedef int BOOL;
typedef unsigned long DWORD;
typedef struct tagRECT { long left, top, right, bottom; } RECT, *LPRECT;
extern "C" __declspec(dllimport) BOOL __stdcall SetRectEmpty(LPRECT lprc);

class CRect : public tagRECT {
public:
    void SetRectEmpty() throw() { ::SetRectEmpty(this); }
};

class CXTPCommandBar;

class CXTPControl {
public:
    int _c;
};

class CXTPControls {
public:
    void SetParent(CXTPCommandBar* pParent);                       // 0x67a640
    void InternalRelease();                                        // 0x6301e4
    CXTPControl* Add(CXTPControl* pControl, int nId, const char* strParameter = 0,
                     int nBefore = -1, BOOL bTemporary = 0);        // 0x67d1e0
};

class CXTPRibbonQuickAccessControls : public CXTPControls {
public:
    CXTPRibbonQuickAccessControls();                               // 0x718df0
    char _p[0x40];
};
class CXTPRibbonControls : public CXTPControls {
public:
    CXTPRibbonControls();                                          // 0x718d10
    char _p[0x40];
};
class CXTPRibbonBarControlQuickAccessPopup : public CXTPControl {
public:
    CXTPRibbonBarControlQuickAccessPopup();                        // 0x6a7870
    char _p[0x178 - 4];
};
class CControlQuickAccessMorePopup : public CXTPControl {
public:
    CControlQuickAccessMorePopup();                                // 0x6a7940
    char _p[0x178 - 4];
};
class CXTPRibbonControlTab : public CXTPControl {
public:
    CXTPRibbonControlTab();                                        // 0x717480
    char _p[0x208 - 4];
};
class CXTPRibbonTabContextHeaders {
public:
    CXTPRibbonTabContextHeaders();                                 // 0x7165d0
    char _p[0x14];
};

class CWnd {
public:
    virtual ~CWnd();
    char _w[0x54 - 4];
};
class CXTPHookManagerHookAble {
public:
    virtual void _hook();
    char _h[0x5c - 0x54 - 4];
};
class CXTPAccessible {
public:
    virtual void _acc();
};

class CXTPCommandBar : public CWnd, public CXTPHookManagerHookAble, public CXTPAccessible {
public:
    void EnableAnimation(BOOL bEnable = 1);                        // 0x6437f0
    void EnableDoubleBuffer(BOOL bEnable = 1);                     // 0x643820
    char _c0[0xe8 - 0x60];
    DWORD m_dwFlags;            // +0xe8
    DWORD m_dwStyle;            // +0xec
    char _c1[0xf4 - 0xf0];
    int m_barType;              // +0xf4
    CXTPControls* m_pControls;  // +0xf8
    char _c2[0x134 - 0xfc];
    BOOL m_bCustomizable;       // +0x134
    char _c3[0x160 - 0x138];
    BOOL m_bTrackOnHover;       // +0x160
    char _c4[0x16c - 0x164];
    BOOL m_bMultiLine;          // +0x16c
    char _c5[0x1c4 - 0x170];
};

class CXTPMenuBar : public CXTPCommandBar {
public:
    CXTPMenuBar();                                                 // 0x6a6600
};

class CXTPRibbonScrollableBar {
public:
    CXTPRibbonScrollableBar() {}
    virtual void _scroll();
    void InitScrollableBar(CXTPCommandBar* pParent);              // 0x6a87f0
    int m_nGroupsScrollPos;     // +0x1c8 (+4)
    char _s[0x1d8 - 0x1cc];
};

class CXTPRibbonBar : public CXTPMenuBar, public CXTPRibbonScrollableBar {
public:
    CXTPRibbonBar();
    virtual ~CXTPRibbonBar();

    CRect m_rcTabControl;       // +0x1d8
    CRect m_rcGroups;           // +0x1e8
    CRect m_rcCaption;          // +0x1f8
    CRect m_rcCaptionText;      // +0x208
    CRect m_rcHeader;           // +0x218
    char _r0[0x238 - 0x228];
    BOOL m_bRibbonBarVisible;   // +0x238
    BOOL m_bGroupsVisible;      // +0x23c
    BOOL m_bTabsVisible;        // +0x240
    BOOL m_bShowQuickAccessBelow;   // +0x244
    BOOL m_bShowQuickAccess;    // +0x248
    BOOL m_bAllowQuickAccessDuplicates;     // +0x24c
    BOOL m_bAllowQuickAccessCustomization;  // +0x250
    BOOL m_bGroupReducedChanged;    // +0x254
    int m_nQuickAccessHeight;   // +0x258
    BOOL m_bAllowMinimize;      // +0x25c
    CXTPRibbonQuickAccessControls* m_pQuickAccessControls;  // +0x260
    CXTPControl* m_pControlTab;             // +0x264
    CXTPControl* m_pControlQuickAccess;     // +0x268
    CXTPControl* m_pControlQuickAccessMore; // +0x26c
    void* m_pControlSystemButton;           // +0x270
    void* m_pHighlightedGroup;              // +0x274
    int m_nMinVisibleWidth;                 // +0x278
    void* m_pFrameHook;                     // +0x27c
    CXTPRibbonTabContextHeaders* m_pContextHeaders;  // +0x280
    int m_nGroupsHeight;                    // +0x284
    BOOL m_bMinimized;                      // +0x288
    BOOL m_bShowCaptionAlways;              // +0x28c
};

CXTPRibbonBar::CXTPRibbonBar()
{
    m_pQuickAccessControls = new CXTPRibbonQuickAccessControls;
    m_pQuickAccessControls->SetParent(this);

    m_pControls->InternalRelease();
    m_pControls = new CXTPRibbonControls;
    m_pControls->SetParent(this);

    m_bShowCaptionAlways = 1;

    m_pHighlightedGroup = 0;

    m_dwStyle = 0;
    m_rcTabControl.SetRectEmpty();
    m_rcGroups.SetRectEmpty();
    m_rcCaption.SetRectEmpty();
    m_rcCaptionText.SetRectEmpty();
    m_rcHeader.SetRectEmpty();

    InitScrollableBar(this);

    m_pControlQuickAccess = m_pControls->Add(new CXTPRibbonBarControlQuickAccessPopup, 0x2583);
    m_pControlQuickAccessMore = m_pControls->Add(new CControlQuickAccessMorePopup, 0x258b);
    m_pControlTab = m_pControls->Add(new CXTPRibbonControlTab, 0x2584);

    m_barType = 3;
    m_dwFlags = 0x440;
    m_bCustomizable = 0;
    m_bGroupsVisible = 1;
    m_bTabsVisible = 1;
    m_nMinVisibleWidth = 250;
    m_bTrackOnHover = 0;
    m_bMinimized = 0;
    m_pFrameHook = 0;
    m_pControlSystemButton = 0;
    m_bRibbonBarVisible = 1;
    m_bGroupReducedChanged = 0;
    m_bShowQuickAccessBelow = 0;
    m_bShowQuickAccess = 1;

    m_pContextHeaders = new CXTPRibbonTabContextHeaders;

    m_bMultiLine = 1;
    m_bAllowQuickAccessDuplicates = 0;
    m_bAllowQuickAccessCustomization = 1;
    m_nGroupsHeight = 0;
    m_nQuickAccessHeight = 0;
    m_nGroupsScrollPos = 0;
    m_bAllowMinimize = 1;

    EnableDoubleBuffer();
    EnableAnimation();
}
