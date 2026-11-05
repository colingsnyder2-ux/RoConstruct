// from server: 100% by auto
// roc 2007-08 00692ce0  unit: CXTPStatusBar  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00692ce0
//
// 00692ce0  8b44240c             mov eax, dword ptr [esp + 0xc]
// 00692ce4  8b542408             mov edx, dword ptr [esp + 8]
// 00692ce8  50                   push eax
// 00692ce9  8b442408             mov eax, dword ptr [esp + 8]
// 00692ced  52                   push edx
// 00692cee  6a00                 push 0
// 00692cf0  50                   push eax
// 00692cf1  e8dafaffff           call 0x6927d0
// 00692cf6  c20c00               ret 0xc
// library mfc-9.0/atlmfc\src\mfc\afxribbonbar.cpp (function ?Create@CMFCRibbonBar@@QAEHPAVCWnd@@KI@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/afxribbonbar.cpp
