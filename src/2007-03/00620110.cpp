// from server: 100% by auto
// roc 2007-03 00620110  unit: seg_00620000  size: 17 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00620110
//
// 00620110  56                   push esi
// 00620111  8bf1                 mov esi, ecx
// 00620113  e8bae5ffff           call 0x61e6d2
// 00620118  c7465400000000       mov dword ptr [esi + 0x54], 0
// 0062011f  5e                   pop esi
// 00620120  c3                   ret 
// library xtp-15.2.1/Source\CommandBars\XTPControlEdit.cpp (function ?OnImeEndComposition@CXTPCommandBarEditCtrl@@IAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPControlEdit.cpp
