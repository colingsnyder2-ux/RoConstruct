// from server: 100% by auto
// roc 2011-06 0086cad0  unit: CXTPStatusBar  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0086cad0
//
// 0086cad0  8b44240c             mov eax, dword ptr [esp + 0xc]
// 0086cad4  8b542408             mov edx, dword ptr [esp + 8]
// 0086cad8  50                   push eax
// 0086cad9  8b442408             mov eax, dword ptr [esp + 8]
// 0086cadd  52                   push edx
// 0086cade  6a00                 push 0
// 0086cae0  50                   push eax
// 0086cae1  e81afaffff           call 0x86c500
// 0086cae6  c20c00               ret 0xc
// library mfc-9.0/atlmfc\src\mfc\afxribbonbar.cpp (function ?Create@CMFCRibbonBar@@QAEHPAVCWnd@@KI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxribbonbar.cpp
