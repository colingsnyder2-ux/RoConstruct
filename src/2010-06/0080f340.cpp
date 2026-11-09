// from server: 100% by auto
// roc 2010-06 0080f340  unit: CXTPStatusBar  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0080f340
//
// 0080f340  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0080f344  8b542408             mov edx, dword ptr [esp + 8]
// 0080f348  50                   push eax
// 0080f349  8b442408             mov eax, dword ptr [esp + 8]
// 0080f34d  52                   push edx
// 0080f34e  6a00                 push 0
// 0080f350  50                   push eax
// 0080f351  e81afaffff           call 0x80ed70
// 0080f356  c20c00               ret 0xc
// library mfc-9.0/atlmfc\src\mfc\afxribbonbar.cpp (function ?Create@CMFCRibbonBar@@QAEHPAVCWnd@@KI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxribbonbar.cpp
