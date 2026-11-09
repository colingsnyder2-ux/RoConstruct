// from server: 100% by auto
// roc 2008-06 0070ec40  unit: CXTPStatusBar  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0070ec40
//
// 0070ec40  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0070ec44  8b542408             mov edx, dword ptr [esp + 8]
// 0070ec48  50                   push eax
// 0070ec49  8b442408             mov eax, dword ptr [esp + 8]
// 0070ec4d  52                   push edx
// 0070ec4e  6a00                 push 0
// 0070ec50  50                   push eax
// 0070ec51  e81afaffff           call 0x70e670
// 0070ec56  c20c00               ret 0xc
// library mfc-9.0/atlmfc\src\mfc\afxribbonbar.cpp (function ?Create@CMFCRibbonBar@@QAEHPAVCWnd@@KI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxribbonbar.cpp
