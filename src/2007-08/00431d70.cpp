// from server: 99% by Intel
﻿// from server: 98% by EspClaude
// roc 2007-08 00431d70  unit: CDataModelPropGrid  size: 875 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00431d70
//
// 00431d70  6aff                 push -1
// 00431d72  684edc7300           push 0x73dc4e
// 00431d77  64a100000000         mov eax, dword ptr fs:[0]
// 00431d7d  50                   push eax
// 00431d7e  83ec24               sub esp, 0x24
// 00431d81  53                   push ebx
// 00431d82  55                   push ebp
// 00431d83  56                   push esi
// 00431d84  57                   push edi
// 00431d85  a188518b00           mov eax, dword ptr [0x8b5188]
// 00431d8a  33c4                 xor eax, esp
// 00431d8c  50                   push eax
// 00431d8d  8d442438             lea eax, [esp + 0x38]
// 00431d91  64a300000000         mov dword ptr fs:[0], eax
// 00431d97  8bd9                 mov ebx, ecx
// 00431d99  837c244801           cmp dword ptr [esp + 0x48], 1
// 00431d9e  0f85cf020000         jne 0x432073
// 00431da4  8b74244c             mov esi, dword ptr [esp + 0x4c]
// 00431da8  8bce                 mov ecx, esi
// 00431daa  e801d62500           call 0x68f3b0
// 00431daf  85c0                 test eax, eax
// 00431db1  0f85e7010000         jne 0x431f9e
// 00431db7  8b86b8000000         mov eax, dword ptr [esi + 0xb8]
// 00431dbd  0574ffffff           add eax, 0xffffff74
// 00431dc2  83f836               cmp eax, 0x36
// 00431dc5  0f87a8020000         ja 0x432073
// 00431dcb  0fb680a4204300       movzx eax, byte ptr [eax + 0x4320a4]
// 00431dd2  ff24858c204300       jmp dword ptr [eax*4 + 0x43208c]
// 00431dd9  8b8390030000         mov eax, dword ptr [ebx + 0x390]
// 00431ddf  8dbb90030000         lea edi, [ebx + 0x390]
// 00431de5  33ed                 xor ebp, ebp
// 00431de7  3bc5                 cmp eax, ebp
// 00431de9  7409                 je 0x431df4
// 00431deb  396820               cmp dword ptr [eax + 0x20], ebp
// 00431dee  0f85a0010000         jne 0x431f94
// 00431df4  6818010000           push 0x118
// 00431df9  e8f8e01f00           call 0x62fef6
// 00431dfe  83c404               add esp, 4
// 00431e01  89442448             mov dword ptr [esp + 0x48], eax
// 00431e05  3bc5                 cmp eax, ebp
// 00431e07  896c2440             mov dword ptr [esp + 0x40], ebp
// 00431e0b  7409                 je 0x431e16
// 00431e0d  8bc8                 mov ecx, eax
// 00431e0f  e8fced2500           call 0x690c10
// 00431e14  eb02                 jmp 0x431e18
// 00431e16  33c0                 xor eax, eax
// 00431e18  83ceff               or esi, 0xffffffff
// 00431e1b  50                   push eax
// 00431e1c  8bcf                 mov ecx, edi
// 00431e1e  89742444             mov dword ptr [esp + 0x44], esi
// 00431e22  e8d9ecffff           call 0x430b00
// 00431e27  8b0f                 mov ecx, dword ptr [edi]
// 00431e29  8b11                 mov edx, dword ptr [ecx]
// 00431e2b  8b8240010000         mov eax, dword ptr [edx + 0x140]
// 00431e31  6800e90000           push 0xe900
// 00431e36  6800000050           push 0x50000000
// 00431e3b  6a01                 push 1
// 00431e3d  6a02                 push 2
// 00431e3f  53                   push ebx
// 00431e40  ffd0                 call eax
// 00431e42  85c0                 test eax, eax
// 00431e44  0f8429020000         je 0x432073
// 00431e4a  68c0010000           push 0x1c0
// 00431e4f  e8a2e01f00           call 0x62fef6
// 00431e54  83c404               add esp, 4
// 00431e57  89442448             mov dword ptr [esp + 0x48], eax
// 00431e5b  3bc5                 cmp eax, ebp
// 00431e5d  c744244001000000     mov dword ptr [esp + 0x40], 1
// 00431e65  7409                 je 0x431e70
// 00431e67  8bc8                 mov ecx, eax
// 00431e69  e872090300           call 0x4627e0
// 00431e6e  eb02                 jmp 0x431e72
// 00431e70  33c0                 xor eax, eax
// 00431e72  89742440             mov dword ptr [esp + 0x40], esi
// 00431e76  8db398030000         lea esi, [ebx + 0x398]
// 00431e7c  50                   push eax
// 00431e7d  8bce                 mov ecx, esi
// 00431e7f  e87cecffff           call 0x430b00
// 00431e84  8b36                 mov esi, dword ptr [esi]
// 00431e86  8b0f                 mov ecx, dword ptr [edi]
// 00431e88  89742414             mov dword ptr [esp + 0x14], esi
// 00431e8c  896c2418             mov dword ptr [esp + 0x18], ebp
// 00431e90  896c241c             mov dword ptr [esp + 0x1c], ebp
// 00431e94  896c2420             mov dword ptr [esp + 0x20], ebp
// 00431e98  896c2424             mov dword ptr [esp + 0x24], ebp
// 00431e9c  8b36                 mov esi, dword ptr [esi]
// 00431e9e  55                   push ebp
// 00431e9f  55                   push ebp
// 00431ea0  894c2450             mov dword ptr [esp + 0x50], ecx
// 00431ea4  81c65c010000         add esi, 0x15c
// 00431eaa  e801e71f00           call 0x6305b0
// 00431eaf  8b542448             mov edx, dword ptr [esp + 0x48]
// 00431eb3  50                   push eax
// 00431eb4  8b06                 mov eax, dword ptr [esi]
// 00431eb6  8d4c241c             lea ecx, [esp + 0x1c]
// 00431eba  51                   push ecx
// 00431ebb  8b4c241c             mov ecx, dword ptr [esp + 0x1c]
// 00431ebf  6801020010           push 0x10000201
// 00431ec4  6a02                 push 2
// 00431ec6  6854597800           push 0x785954
// 00431ecb  52                   push edx
// 00431ecc  ffd0                 call eax
// 00431ece  85c0                 test eax, eax
// 00431ed0  7508                 jne 0x431eda
// 00431ed2  83c8ff               or eax, 0xffffffff
// 00431ed5  e99b010000           jmp 0x432075
// 00431eda  68e0010000           push 0x1e0
// 00431edf  e812e01f00           call 0x62fef6
// 00431ee4  83c404               add esp, 4
// 00431ee7  89442448             mov dword ptr [esp + 0x48], eax
// 00431eeb  3bc5                 cmp eax, ebp
// 00431eed  c744244002000000     mov dword ptr [esp + 0x40], 2
// 00431ef5  7409                 je 0x431f00
// 00431ef7  8bc8                 mov ecx, eax
// 00431ef9  e892f9ffff           call 0x431890
// 00431efe  eb02                 jmp 0x431f02
// 00431f00  33c0                 xor eax, eax
// 00431f02  8db394030000         lea esi, [ebx + 0x394]
// 00431f08  50                   push eax
// 00431f09  8bce                 mov ecx, esi
// 00431f0b  c7442444ffffffff     mov dword ptr [esp + 0x44], 0xffffffff
// 00431f13  e8e8ebffff           call 0x430b00
// 00431f18  8b06                 mov eax, dword ptr [esi]
// 00431f1a  8b0f                 mov ecx, dword ptr [edi]
// 00431f1c  55                   push ebp
// 00431f1d  896c242c             mov dword ptr [esp + 0x2c], ebp
// 00431f21  896c2430             mov dword ptr [esp + 0x30], ebp
// 00431f25  896c2434             mov dword ptr [esp + 0x34], ebp
// 00431f29  896c2438             mov dword ptr [esp + 0x38], ebp
// 00431f2d  8b18                 mov ebx, dword ptr [eax]
// 00431f2f  55                   push ebp
// 00431f30  6a01                 push 1
// 00431f32  89442420             mov dword ptr [esp + 0x20], eax
// 00431f36  894c2454             mov dword ptr [esp + 0x54], ecx
// 00431f3a  81c33c010000         add ebx, 0x13c
// 00431f40  e86be61f00           call 0x6305b0
// 00431f45  8b4c244c             mov ecx, dword ptr [esp + 0x4c]
// 00431f49  50                   push eax
// 00431f4a  8b03                 mov eax, dword ptr [ebx]
// 00431f4c  51                   push ecx
// 00431f4d  8b4c2420             mov ecx, dword ptr [esp + 0x20]
// 00431f51  8d542434             lea edx, [esp + 0x34]
// 00431f55  52                   push edx
// 00431f56  ffd0                 call eax
// 00431f58  8b0e                 mov ecx, dword ptr [esi]
// 00431f5a  6a01                 push 1
// 00431f5c  e84f252500           call 0x6844b0
// 00431f61  8b0e                 mov ecx, dword ptr [esi]
// 00431f63  6a06                 push 6
// 00431f65  e816262500           call 0x684580
// 00431f6a  8b0e                 mov ecx, dword ptr [esi]
// 00431f6c  81c1dc010000         add ecx, 0x1dc
// 00431f72  e829bcfeff           call 0x41dba0
// 00431f77  8b0f                 mov ecx, dword ptr [edi]
// 00431f79  55                   push ebp
// 00431f7a  6a1c                 push 0x1c
// 00431f7c  55                   push ebp
// 00431f7d  e828e61f00           call 0x6305aa
// 00431f82  8b0f                 mov ecx, dword ptr [edi]
// 00431f84  8b11                 mov edx, dword ptr [ecx]
// 00431f86  8b82c8010000         mov eax, dword ptr [edx + 0x1c8]
// 00431f8c  6a08                 push 8
// 00431f8e  ffd0                 call eax
// 00431f90  8b74244c             mov esi, dword ptr [esp + 0x4c]
// 00431f94  8b0f                 mov ecx, dword ptr [edi]
// 00431f96  51                   push ecx
// 00431f97  8bce                 mov ecx, esi
// 00431f99  e852db2500           call 0x68faf0
// 00431f9e  b801000000           mov eax, 1
// 00431fa3  e9cd000000           jmp 0x432075
// 00431fa8  33ed                 xor ebp, ebp
// 00431faa  55                   push ebp
// 00431fab  55                   push ebp
// 00431fac  68f0a67800           push 0x78a6f0
// 00431fb1  53                   push ebx
// 00431fb2  8bce                 mov ecx, esi
// 00431fb4  e8a7db2500           call 0x68fb60
// 00431fb9  8bf0                 mov esi, eax
// 00431fbb  3bf5                 cmp esi, ebp
// 00431fbd  741f                 je 0x431fde
// 00431fbf  8b5620               mov edx, dword ptr [esi + 0x20]
// 00431fc2  52                   push edx
// 00431fc3  ff15bced7700         call dword ptr [0x77edbc]
// 00431fc9  85c0                 test eax, eax
// 00431fcb  7411                 je 0x431fde
// 00431fcd  8b4620               mov eax, dword ptr [esi + 0x20]
// 00431fd0  55                   push ebp
// 00431fd1  55                   push ebp
// 00431fd2  6864030000           push 0x364
// 00431fd7  50                   push eax
// 00431fd8  ff15d8ec7700         call dword ptr [0x77ecd8]
// 00431fde  b801000000           mov eax, 1
// 00431fe3  e98d000000           jmp 0x432075
// 00431fe8  33ed                 xor ebp, ebp
// 00431fea  55                   push ebp
// 00431feb  55                   push ebp
// 00431fec  e8df4f0000           call 0x436fd0
// 00431ff1  50                   push eax
// 00431ff2  53                   push ebx
// 00431ff3  8bce                 mov ecx, esi
// 00431ff5  e866db2500           call 0x68fb60
// 00431ffa  8bf0                 mov esi, eax
// 00431ffc  3bf5                 cmp esi, ebp
// 00431ffe  741f                 je 0x43201f
// 00432000  8b4e20               mov ecx, dword ptr [esi + 0x20]
// 00432003  51                   push ecx
// 00432004  ff15bced7700         call dword ptr [0x77edbc]
// 0043200a  85c0                 test eax, eax
// 0043200c  7411                 je 0x43201f
// 0043200e  8b5620               mov edx, dword ptr [esi + 0x20]
// 00432011  55                   push ebp
// 00432012  55                   push ebp
// 00432013  6864030000           push 0x364
// 00432018  52                   push edx
// 00432019  ff15d8ec7700         call dword ptr [0x77ecd8]
// 0043201f  b801000000           mov eax, 1
// 00432024  eb4f                 jmp 0x432075
// 00432026  33ed                 xor ebp, ebp
// 00432028  55                   push ebp
// 00432029  55                   push ebp
// 0043202a  e801150200           call 0x453530
// 0043202f  50                   push eax
// 00432030  53                   push ebx
// 00432031  8bce                 mov ecx, esi
// 00432033  e828db2500           call 0x68fb60
// 00432038  8bf0                 mov esi, eax
// 0043203a  3bf5                 cmp esi, ebp
// 0043203c  741f                 je 0x43205d
// 0043203e  8b4620               mov eax, dword ptr [esi + 0x20]
// 00432041  50                   push eax
// 00432042  ff15bced7700         call dword ptr [0x77edbc]
// 00432048  85c0                 test eax, eax
// 0043204a  7411                 je 0x43205d
// 0043204c  8b4e20               mov ecx, dword ptr [esi + 0x20]
// 0043204f  55                   push ebp
// 00432050  55                   push ebp
// 00432051  6864030000           push 0x364
// 00432056  51                   push ecx
// 00432057  ff15d8ec7700         call dword ptr [0x77ecd8]
// 0043205d  b801000000           mov eax, 1
// 00432062  eb11                 jmp 0x432075
// 00432064  33ed                 xor ebp, ebp
// 00432066  55                   push ebp
// 00432067  55                   push ebp
// 00432068  e863460300           call 0x4666d0
// 0043206d  50                   push eax
// 0043206e  e93effffff           jmp 0x431fb1
// 00432073  33c0                 xor eax, eax
// 00432075  8b4c2438             mov ecx, dword ptr [esp + 0x38]
// 00432079  64890d00000000       mov dword ptr fs:[0], ecx
// 00432080  59                   pop ecx
// 00432081  5f                   pop edi
// 00432082  5e                   pop esi
// 00432083  5d                   pop ebp
// 00432084  5b                   pop ebx
// 00432085  83c430               add esp, 0x30
// 00432088  c20800               ret 8
// 0043208b  90                   nop 
// 0043208c  26204300             and byte ptr es:[ebx], al
// 00432090  64204300             and byte ptr fs:[ebx], al
// 00432094  e81f4300d9           call 0xd94363b8
// 00432099  1d4300a81f           sbb eax, 0x1fa80043
// 0043209e  43                   inc ebx
// 0043209f  007320               add byte ptr [ebx + 0x20], dh
// 004320a2  43                   inc ebx
// 004320a3  0000                 add byte ptr [eax], al
// 004320a5  0505050505           add eax, 0x5050505
// 004320aa  0505050505           add eax, 0x5050505
// 004320af  0505050505           add eax, 0x5050505
// 004320b4  0505050505           add eax, 0x5050505
// 004320b9  0505050505           add eax, 0x5050505
// 004320be  0505050505           add eax, 0x5050505
// 004320c3  0505050505           add eax, 0x5050505
// 004320c8  0505050505           add eax, 0x5050505
// 004320cd  0505050505           add eax, 0x5050505
// 004320d2  0505050505           add eax, 0x5050505
// 004320d7  0102                 add dword ptr [edx], eax

// from server: 100% by king_originala
// roc-cl: 50727
// Native MFC9 and XTP11.2.2 virtual APIs plus target-proven minimal storage views.
// Frame/owner/runtime-class labels identify measured UI roles, not recovered original symbols.
// RTTI proves CXTSplitterWnd118, CSelectionCaption1c8 and CDataModelPropGrid248.
#include <stddef.h>
typedef int BOOL;typedef unsigned int UINT;typedef unsigned long DWORD;typedef unsigned long DWORD_PTR;typedef unsigned long WPARAM;typedef long LPARAM;typedef long LRESULT;typedef long HRESULT;typedef long INT_PTR;typedef long DISPID;typedef unsigned long COLORREF;
typedef void*HWND;typedef void*HMENU;typedef void*HICON;typedef void*LPVOID;typedef const char*LPCTSTR;typedef wchar_t*BSTR;
struct RECT{long left,top,right,bottom;};typedef RECT*LPRECT;
struct SIZE{long cx,cy;};struct CSize:SIZE{};
struct CRect:RECT{CRect(int a,int b,int c,int d){left=a;top=b;right=c;bottom=d;}};
struct CPoint{long x,y;};struct CREATESTRUCT;struct TOOLINFO;struct VARIANT;struct IDispatch;struct IAccessibleProxy;struct CDataExchange;struct COleControlSite;struct COleControlContainer;struct _AFX_OCC_DIALOG_INFO;struct CMenu;struct CScrollBar;struct CCreateContext;struct CView;struct CDC;struct CBrush;struct CFont;struct DRAWITEMSTRUCT;typedef DRAWITEMSTRUCT*LPDRAWITEMSTRUCT;struct GUID;typedef const GUID&REFCLSID;typedef LRESULT(__stdcall*WNDPROC)(HWND,UINT,WPARAM,LPARAM);
extern "C" __declspec(dllimport) BOOL __stdcall IsWindow(HWND);
extern "C" __declspec(dllimport) LRESULT __stdcall SendMessageA(HWND,UINT,WPARAM,LPARAM);
struct CRuntimeClass;struct CArchive;struct CDumpContext;struct CWnd;struct CException;struct MSG;struct IID;struct AFX_CMDHANDLERINFO;struct CTypeLibCache;struct CPtrArray;
struct CObject {virtual CRuntimeClass*GetRuntimeClass()const;virtual ~CObject();virtual void Serialize(CArchive&);virtual void AssertValid()const;virtual void Dump(CDumpContext&)const;};
struct CCmdTarget:CObject {
 virtual int OnCmdMsg(unsigned,int,void*,AFX_CMDHANDLERINFO*);virtual void OnFinalRelease();virtual int IsInvokeAllowed(long);virtual int GetDispatchIID(IID*);virtual unsigned GetTypeInfoCount();virtual CTypeLibCache*GetTypeLibCache();virtual long GetTypeLib(unsigned long,void**);
 virtual const void*GetMessageMap()const;virtual const void*GetCommandMap()const;virtual const void*GetDispatchMap()const;virtual const void*GetConnectionMap()const;virtual const void*GetInterfaceMap()const;virtual const void*GetEventSinkMap()const;
 virtual int OnCreateAggregates();virtual void*GetInterfaceHook(const void*);virtual int GetExtraConnectionPoints(CPtrArray*);virtual void*GetConnectionHook(const IID&);
 char opaque[0x20-4];
};

struct CWnd:CCmdTarget {
 HWND handle;char opaque[0x54-0x24];
 virtual void PreSubclassWindow();
 virtual BOOL Create(LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, CCreateContext* pContext );
 virtual BOOL CreateEx(DWORD dwExStyle, LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, int x, int y, int nWidth, int nHeight, HWND hWndParent, HMENU nIDorHMenu, LPVOID lpParam );
 virtual BOOL CreateEx(DWORD dwExStyle, LPCTSTR lpszClassName, LPCTSTR lpszWindowName, DWORD dwStyle, const RECT& rect, CWnd* pParentWnd, UINT nID, LPVOID lpParam );
 virtual BOOL DestroyWindow();
 virtual BOOL PreCreateWindow(CREATESTRUCT& cs);
 virtual void CalcWindowRect(LPRECT lpClientRect, UINT nAdjustType );
 virtual CMenu* GetMenu() const;
 virtual BOOL SetMenu(CMenu* pMenu);
 virtual INT_PTR OnToolHitTest(CPoint point, TOOLINFO* pTI) const;
 virtual CScrollBar* GetScrollBarCtrl(int nBar) const;
 virtual void WinHelp(DWORD_PTR dwData, UINT nCmd );
 virtual void HtmlHelp(DWORD_PTR dwData, UINT nCmd );
 virtual void WinHelpInternal(DWORD_PTR dwData, UINT nCmd );
 virtual BOOL ContinueModal();
 virtual void EndModalLoop(int nResult);
 virtual HRESULT EnsureStdObj();
 virtual HRESULT get_accParent(IDispatch **ppdispParent);
 virtual HRESULT get_accChildCount(long *pcountChildren);
 virtual HRESULT get_accChild(VARIANT varChild, IDispatch **ppdispChild);
 virtual HRESULT get_accName(VARIANT varChild, BSTR *pszName);
 virtual HRESULT get_accValue(VARIANT varChild, BSTR *pszValue);
 virtual HRESULT get_accDescription(VARIANT varChild, BSTR *pszDescription);
 virtual HRESULT get_accRole(VARIANT varChild, VARIANT *pvarRole);
 virtual HRESULT get_accState(VARIANT varChild, VARIANT *pvarState);
 virtual HRESULT get_accHelp(VARIANT varChild, BSTR *pszHelp);
 virtual HRESULT get_accHelpTopic(BSTR *pszHelpFile, VARIANT varChild, long *pidTopic);
 virtual HRESULT get_accKeyboardShortcut(VARIANT varChild, BSTR *pszKeyboardShortcut);
 virtual HRESULT get_accFocus(VARIANT *pvarChild);
 virtual HRESULT get_accSelection(VARIANT *pvarChildren);
 virtual HRESULT get_accDefaultAction(VARIANT varChild, BSTR *pszDefaultAction);
 virtual HRESULT accSelect(long flagsSelect, VARIANT varChild);
 virtual HRESULT accLocation(long *pxLeft, long *pyTop, long *pcxWidth, long *pcyHeight, VARIANT varChild);
 virtual HRESULT accNavigate(long navDir, VARIANT varStart, VARIANT *pvarEndUpAt);
 virtual HRESULT accHitTest(long xLeft, long yTop, VARIANT *pvarChild);
 virtual HRESULT accDoDefaultAction(VARIANT varChild);
 virtual HRESULT put_accName(VARIANT varChild, BSTR szName);
 virtual HRESULT put_accValue(VARIANT varChild, BSTR szValue);
 virtual HRESULT SetProxy(IAccessibleProxy *pProxy);
 virtual HRESULT CreateAccessibleProxy(WPARAM wParam, LPARAM lParam, LRESULT *pResult);
 virtual BOOL OnCommand(WPARAM wParam, LPARAM lParam);
 virtual BOOL OnNotify(WPARAM wParam, LPARAM lParam, LRESULT* pResult);
 virtual WNDPROC* GetSuperWndProcAddr();
 virtual void DoDataExchange(CDataExchange* pDX);
 virtual void BeginModalState();
 virtual void EndModalState();
 virtual BOOL PreTranslateMessage(MSG* pMsg);
 virtual BOOL OnAmbientProperty(COleControlSite* pSite, DISPID dispid, VARIANT* pvar);
 virtual LRESULT WindowProc(UINT message, WPARAM wParam, LPARAM lParam);
 virtual BOOL OnWndMsg(UINT message, WPARAM wParam, LPARAM lParam, LRESULT* pResult);
 virtual LRESULT DefWindowProc(UINT message, WPARAM wParam, LPARAM lParam);
 virtual void PostNcDestroy();
 virtual BOOL OnChildNotify(UINT message, WPARAM wParam, LPARAM lParam, LRESULT* pResult);
 virtual ~CWnd();
 virtual BOOL CheckAutoCenter();
 virtual void AssertValid() const;
 virtual void Dump(CDumpContext& dc) const;
 virtual BOOL IsFrameWnd() const; 
 virtual void OnFinalRelease();
 virtual BOOL CreateControlContainer(COleControlContainer** ppContainer);
 virtual BOOL CreateControlSite(COleControlContainer* pContainer, COleControlSite** ppSite, UINT nID, REFCLSID clsid);
 virtual BOOL SetOccDialogInfo(struct _AFX_OCC_DIALOG_INFO* pOccDialogInfo);
 virtual _AFX_OCC_DIALOG_INFO* GetOccDialogInfo();
 LRESULT SendMessage(UINT msg,WPARAM w=0,LPARAM l=0){return ::SendMessageA(handle,msg,w,l);}
};
struct CSplitterWnd:CWnd {
 enum ESplitType{splitBox,splitBar,splitIntersection,splitBorder};char opaque[0xdc-0x54];
 virtual BOOL Create(CWnd* pParentWnd, int nMaxRows, int nMaxCols, SIZE sizeMin, CCreateContext* pContext, DWORD dwStyle , UINT nID );
 virtual BOOL CreateStatic(CWnd* pParentWnd, int nRows, int nCols, DWORD dwStyle , UINT nID );
 virtual BOOL CreateView(int row, int col, CRuntimeClass* pViewClass, SIZE sizeInit, CCreateContext* pContext);
 virtual void RecalcLayout();
 virtual void OnDrawSplitter(CDC* pDC, ESplitType nType, const CRect& rect);
 virtual void OnInvertTracker(const CRect& rect);
 virtual BOOL CreateScrollBarCtrl(DWORD dwStyle, UINT nID);
 virtual void DeleteView(int row, int col);
 virtual BOOL SplitRow(int cyBefore);
 virtual BOOL SplitColumn(int cxBefore);
 virtual void DeleteRow(int rowDelete);
 virtual void DeleteColumn(int colDelete);
 virtual CWnd* GetActivePane(int* pRow , int* pCol );
 virtual void SetActivePane(int row, int col, CWnd* pWnd );
 virtual BOOL CanActivateNext(BOOL bPrev );
 virtual void ActivateNext(BOOL bPrev );
 virtual BOOL DoKeyboardSplit();
 virtual BOOL DoScroll(CView* pViewFrom, UINT nScrollCode, BOOL bDoScroll );
 virtual BOOL DoScrollBy(CView* pViewFrom, CSize sizeScroll, BOOL bDoScroll );
 virtual ~CSplitterWnd();
 virtual void AssertValid() const;
 virtual void Dump(CDumpContext& dc) const;
 virtual int HitTest(CPoint pt) const;
 virtual void GetInsideRect(CRect& rect) const;
 virtual void GetHitRect(int ht, CRect& rect);
 virtual void TrackRowSize(int y, int row);
 virtual void TrackColumnSize(int x, int col);
 virtual void DrawAllSplitBars(CDC* pDC, int cxInside, int cyInside);
 virtual void SetSplitCursor(int ht);
 virtual void StartTracking(int ht);
 virtual void StopTracking(BOOL bAccept);
 virtual BOOL OnCommand(WPARAM wParam, LPARAM lParam);
 virtual BOOL OnNotify(WPARAM wParam, LPARAM lParam, LRESULT* pResult);
 int IdFromRowCol(int,int)const;void SetRowInfo(int,int,int);
};
struct CXTThemeManagerStyleFactory;
struct CXTThemeManagerStyleHost {
 virtual ~CXTThemeManagerStyleHost();virtual CXTThemeManagerStyleFactory*CreateThemeFactory();virtual void OnThemeChanged();
 BOOL autoDelete;CRuntimeClass*factoryClass;CXTThemeManagerStyleFactory*customFactory;CXTThemeManagerStyleFactory*defaultFactory;CXTThemeManagerStyleHost*nextHost;
};
struct CXTSplitterWnd:CSplitterWnd,CXTThemeManagerStyleHost {
 CXTSplitterWnd();
 virtual ~CXTSplitterWnd();
 virtual void ShowColumn();
 virtual void HideColumn(int nColHide);
 virtual void ShowRow();
 virtual void HideRow(int nRowHide);
 virtual BOOL SwitchView(int nRow, int nCol, CView* pNewView);
 virtual CView* ReplaceView(int nRow, int nCol, CView* pNewView);
 virtual CView* ReplaceView(int nRow, int nCol, CRuntimeClass* pViewClass);
 virtual void SetSplitterStyle(DWORD dwxStyle);
 virtual DWORD GetSplitterStyle();
 virtual void EnableFlatLook(BOOL bFlatSplitter);
 virtual void SetActivePane(int row, int col, CWnd* pWnd );
 virtual void SetSplitCursor(int ht);
 virtual void OnInvertTracker(const CRect& rect);
 virtual void StartTracking(int ht);
 virtual void StopTracking(BOOL bAccept);
 virtual void DrawTracker(const CRect& rect, CBrush* pBrush);
 virtual void OnDrawSplitter(CDC* pDC, ESplitType nType, const CRect& rectArg);
 int hiddenCol,hiddenRow;BOOL fullDrag,forceFullDrag,flatSplit;DWORD splitStyle;CPoint point;BOOL clipStyles;
};
struct CStatic:CWnd {
 virtual BOOL Create(LPCTSTR,DWORD,const RECT&,CWnd*,UINT);virtual void DrawItem(LPDRAWITEMSTRUCT);virtual ~CStatic();
};
struct CXTCaption:CStatic,CXTThemeManagerStyleHost {
 char opaque[0x190-0x54-24];
 virtual ~CXTCaption();
 virtual void SetCaptionColors(COLORREF clrBorder, COLORREF clrFace, COLORREF clrText);
 virtual void ModifyCaptionStyle(int nBorderSize, CFont* pFont , LPCTSTR lpszWindText , HICON hIcon );
 virtual void SetChildWindow(CWnd* pChild, CWnd* pNotifyWnd);
 virtual void KillChildWindow();
 virtual BOOL ShowPopupWindow();
 virtual void UpdateCaption(LPCTSTR lpszWindowText, HICON hIcon);
 virtual BOOL Create(CWnd* pParentWnd, LPCTSTR lpszWindowName, DWORD dwExStyle, DWORD dwStyle, const CRect& rect, UINT nID);
 virtual CRect GetTextRect() const;
 virtual void DrawCaptionBack(CDC* pDC, CRect& rcItem);
 virtual void DrawCaptionText(CDC* pDC);
 virtual void DrawCaptionIcon(CDC* pDC, CRect& rcItem);
 virtual void UpdateCaptionText(CDC* pDC);
 virtual CRect GetButtonRect() const;
};
struct CSelectionCaption:CXTCaption {char opaque[0x1c0-0x190];CSelectionCaption();};
struct CXTPPropertyGrid:CWnd {
 char opaque[0x188-0x54];virtual BOOL Create(const RECT&,CWnd*,UINT,DWORD);void ShowToolBar(BOOL);void SetTheme(int);
};
struct ActiveDocView {virtual ~ActiveDocView();void refresh();};
struct CDataModelPropGrid:CXTPPropertyGrid {char opaque[0x244-0x188];ActiveDocView activeDoc;CDataModelPropGrid();};
struct CDocument;
struct CXTPDockingPane {char opaque[0xb8];int id;int GetID()const{return id;}BOOL IsValid()const;void Attach(CWnd*);CWnd*AttachView(CWnd*,CRuntimeClass*,CDocument*,CCreateContext*);};
template<class T>struct WindowOwner {T*pointer;void reset(CWnd*);T*get()const{return pointer;}};
struct CMainFrame:CWnd {
 char opaque[0x390-0x54];WindowOwner<CXTSplitterWnd>splitter;WindowOwner<CDataModelPropGrid>properties;WindowOwner<CSelectionCaption>caption;
 LRESULT OnDockingPaneNotify(WPARAM,LPARAM);
};
CRuntimeClass* __stdcall viewClassA();CRuntimeClass* __stdcall viewClassB();CRuntimeClass* __stdcall viewClassC();extern CRuntimeClass viewClassD;
LRESULT CMainFrame::OnDockingPaneNotify(WPARAM notification,LPARAM parameter){
 if(notification==1){
 CXTPDockingPane*pane=(CXTPDockingPane*)parameter;
 if(!pane->IsValid()){
 switch(pane->GetID()){
 case 0xc1:{
  if(!splitter.get()||!splitter.get()->handle){
   splitter.reset(new CXTSplitterWnd);
   if(!splitter.get()->CreateStatic(this,2,1,0x50000000,0xe900))return 0;
   caption.reset(new CSelectionCaption);
   if(!((CSelectionCaption*)caption.get())->Create(splitter.get(),"",2,0x10000201,CRect(0,0,0,0),splitter.get()->IdFromRowCol(0,0)))return -1;
   properties.reset(new CDataModelPropGrid);
   properties.get()->Create(CRect(0,0,0,0),splitter.get(),splitter.get()->IdFromRowCol(1,0),0);
   properties.get()->ShowToolBar(1);properties.get()->SetTheme(6);properties.get()->activeDoc.refresh();
   splitter.get()->SetRowInfo(0,28,0);splitter.get()->SetSplitterStyle(8);
  }
  pane->Attach(splitter.get());return 1;
 }
 case 0xc2:{CWnd*view=pane->AttachView(this,&viewClassD,0,0);if(view&&IsWindow(view->handle))view->SendMessage(0x364);return 1;}
 case 0xc0:{CWnd*view=pane->AttachView(this,viewClassA(),0,0);if(view&&IsWindow(view->handle))view->SendMessage(0x364);return 1;}
 case 0x8c:{CWnd*view=pane->AttachView(this,viewClassB(),0,0);if(view&&IsWindow(view->handle))view->SendMessage(0x364);return 1;}
 case 0xbf:{CWnd*view=pane->AttachView(this,viewClassC(),0,0);if(view&&IsWindow(view->handle))view->SendMessage(0x364);return 1;}
 }
 }else return 1;
 }
 return 0;
}
typedef char cwnd_size[sizeof(CWnd)==0x54?1:-1];
typedef char splitter_size[sizeof(CXTSplitterWnd)==0x118?1:-1];
typedef char caption_size[sizeof(CSelectionCaption)==0x1c0?1:-1];
typedef char grid_size[sizeof(CDataModelPropGrid)==0x248?1:-1];
typedef char splitter_member[offsetof(CMainFrame,splitter)==0x390?1:-1];
typedef char active_member[offsetof(CDataModelPropGrid,activeDoc)==0x244?1:-1];

