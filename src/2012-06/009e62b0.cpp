// roc 2012-06 009e62b0  unit: CXTSplitterWnd  size: 43 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009e62b0
//
// 009e62b0  8b44240c             mov eax, dword ptr [esp + 0xc]
// 009e62b4  8b542404             mov edx, dword ptr [esp + 4]
// 009e62b8  56                   push esi
// 009e62b9  8bf1                 mov esi, ecx
// 009e62bb  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 009e62bf  50                   push eax
// 009e62c0  51                   push ecx
// 009e62c1  52                   push edx
// 009e62c2  8bce                 mov ecx, esi
// 009e62c4  e867380b00           call 0xa99b30
// 009e62c9  8b4620               mov eax, dword ptr [esi + 0x20]
// 009e62cc  6a01                 push 1
// 009e62ce  6a00                 push 0
// 009e62d0  50                   push eax
// 009e62d1  ff15ec3bb200         call dword ptr [0xb23bec]
// 009e62d7  5e                   pop esi
// 009e62d8  c20c00               ret 0xc
// copied from an identical function in another client (function ?OnLButtonUp@CXTSplitterWnd@@IAEXIVCPoint@@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /MD /GS /EHsc /Ob1
// roc-lib: xtp-11.2.2-shared-mfc-internals Source/Controls/XTSplitterWnd.cpp
// MFC 9 afximpl.h: AFX_CX_BORDER = AFX_CY_BORDER = 1.
#define CX_BORDER 1
#define CY_BORDER 1