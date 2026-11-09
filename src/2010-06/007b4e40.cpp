// from server: 100% by auto
// roc 2010-06 007b4e40  unit: CXTPEdit  size: 19 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007b4e40
//
// 007b4e40  56                   push esi
// 007b4e41  8bf1                 mov esi, ecx
// 007b4e43  e82831ffff           call 0x7a7f70
// 007b4e48  c7465400000000       mov dword ptr [esi + 0x54], 0
// 007b4e4f  5e                   pop esi
// 007b4e50  c20400               ret 4
// library xtp-13.2.1/Source\CommandBars\XTPControlComboBox.cpp (function ?OnKillFocus@CXTPCommandBarEditCtrl@@IAEXPAVCWnd@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPControlComboBox.cpp
