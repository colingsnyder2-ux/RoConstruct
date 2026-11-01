// from server: 100% by auto
// roc 2009-12 0086f910  unit: CXTPNewToolbarDlg  size: 19 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0086f910
//
// 0086f910  8b442404             mov eax, dword ptr [esp + 4]
// 0086f914  83c178               add ecx, 0x78
// 0086f917  51                   push ecx
// 0086f918  6a64                 push 0x64
// 0086f91a  50                   push eax
// 0086f91b  e874730b00           call 0x926c94
// 0086f920  c20400               ret 4
// library xtp-15.2.1/Source\CommandBars\XTPCustomizeTools.cpp (function ?DoDataExchange@CXTPNewToolbarDlg@@MAEXPAVCDataExchange@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPCustomizeTools.cpp
