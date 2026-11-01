// from server: 100% by auto
// roc 2007-03 00693e40  unit: seg_00690000  size: 19 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00693e40
//
// 00693e40  8b442404             mov eax, dword ptr [esp + 4]
// 00693e44  83c178               add ecx, 0x78
// 00693e47  51                   push ecx
// 00693e48  6a64                 push 0x64
// 00693e4a  50                   push eax
// 00693e4b  e86eaaf8ff           call 0x61e8be
// 00693e50  c20400               ret 4
// library xtp-15.2.1/Source\CommandBars\XTPCustomizeTools.cpp (function ?DoDataExchange@CXTPNewToolbarDlg@@MAEXPAVCDataExchange@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPCustomizeTools.cpp
