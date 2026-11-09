// from server: 100% by auto
// roc 2011-06 006653e0  unit: RBX::VCamera::?$FactoryProduct  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 006653e0
//
// 006653e0  8b44240c             mov eax, dword ptr [esp + 0xc]
// 006653e4  8b542408             mov edx, dword ptr [esp + 8]
// 006653e8  50                   push eax
// 006653e9  8b442408             mov eax, dword ptr [esp + 8]
// 006653ed  52                   push edx
// 006653ee  6a00                 push 0
// 006653f0  50                   push eax
// 006653f1  e85afdffff           call 0x665150
// 006653f6  c20c00               ret 0xc
// library mfc-9.0/atlmfc\src\mfc\afxribbonbar.cpp (function ?Create@CMFCRibbonBar@@QAEHPAVCWnd@@KI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxribbonbar.cpp
