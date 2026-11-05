// from server: 100% by auto
// roc 2010-06 00652cd0  unit: RBX::VCamera::?$FactoryProduct  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00652cd0
//
// 00652cd0  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00652cd4  8b542408             mov edx, dword ptr [esp + 8]
// 00652cd8  50                   push eax
// 00652cd9  8b442408             mov eax, dword ptr [esp + 8]
// 00652cdd  52                   push edx
// 00652cde  6a00                 push 0
// 00652ce0  50                   push eax
// 00652ce1  e87afdffff           call 0x652a60
// 00652ce6  c20c00               ret 0xc
// library mfc-9.0/atlmfc\src\mfc\afxribbonbar.cpp (function ?Create@CMFCRibbonBar@@QAEHPAVCWnd@@KI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxribbonbar.cpp
