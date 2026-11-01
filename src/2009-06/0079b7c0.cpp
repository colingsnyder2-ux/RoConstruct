// from server: 100% by auto
// roc 2009-06 0079b7c0  unit: CXTPNewToolbarDlg  size: 19 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0079b7c0
//
// 0079b7c0  8b442404             mov eax, dword ptr [esp + 4]
// 0079b7c4  83c178               add ecx, 0x78
// 0079b7c7  51                   push ecx
// 0079b7c8  6a64                 push 0x64
// 0079b7ca  50                   push eax
// 0079b7cb  e8580f0b00           call 0x84c728
// 0079b7d0  c20400               ret 4
// library xtp-15.2.1/Source\CommandBars\XTPCustomizeTools.cpp (function ?DoDataExchange@CXTPNewToolbarDlg@@MAEXPAVCDataExchange@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPCustomizeTools.cpp
