// from server: 100% by auto
// roc 2010-06 00823920  unit: CXTPNewToolbarDlg  size: 19 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00823920
//
// 00823920  8b442404             mov eax, dword ptr [esp + 4]
// 00823924  83c178               add ecx, 0x78
// 00823927  51                   push ecx
// 00823928  6a64                 push 0x64
// 0082392a  50                   push eax
// 0082392b  e8a69c1500           call 0x97d5d6
// 00823930  c20400               ret 4
// library xtp-13.2.1/Source\CommandBars\XTPCustomizeTools.cpp (function ?DoDataExchange@CXTPNewToolbarDlg@@MAEXPAVCDataExchange@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPCustomizeTools.cpp
