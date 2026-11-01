// from server: 100% by auto
// roc 2007-03 00621290  unit: seg_00620000  size: 19 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00621290
//
// 00621290  56                   push esi
// 00621291  8bf1                 mov esi, ecx
// 00621293  e83ad4ffff           call 0x61e6d2
// 00621298  c7465400000000       mov dword ptr [esi + 0x54], 0
// 0062129f  5e                   pop esi
// 006212a0  c20400               ret 4
// library xtp-15.2.1/Source\CommandBars\XTPControlEdit.cpp (function ?OnKillFocus@CXTPCommandBarEditCtrl@@IAEXPAVCWnd@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPControlEdit.cpp
