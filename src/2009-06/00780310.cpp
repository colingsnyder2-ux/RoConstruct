// from server: 100% by auto
// roc 2009-06 00780310  unit: CXTPStatusBar  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00780310
//
// 00780310  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00780314  8b542408             mov edx, dword ptr [esp + 8]
// 00780318  50                   push eax
// 00780319  8b442408             mov eax, dword ptr [esp + 8]
// 0078031d  52                   push edx
// 0078031e  6a00                 push 0
// 00780320  50                   push eax
// 00780321  e81afaffff           call 0x77fd40
// 00780326  c20c00               ret 0xc
// library mfc-9.0/atlmfc\src\mfc\afxribbonbar.cpp (function ?Create@CMFCRibbonBar@@QAEHPAVCWnd@@KI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxribbonbar.cpp
