// from server: 100% by auto
// roc 2009-12 007fa140  unit: CXTPEdit  size: 19 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007fa140
//
// 007fa140  56                   push esi
// 007fa141  8bf1                 mov esi, ecx
// 007fa143  e8e89cffff           call 0x7f3e30
// 007fa148  c7465400000000       mov dword ptr [esi + 0x54], 0
// 007fa14f  5e                   pop esi
// 007fa150  c20400               ret 4
// library xtp-15.2.1/Source\CommandBars\XTPControlEdit.cpp (function ?OnKillFocus@CXTPCommandBarEditCtrl@@IAEXPAVCWnd@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPControlEdit.cpp
