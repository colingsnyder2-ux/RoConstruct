// from server: 100% by auto
// roc 2007-03 006200f0  unit: seg_00620000  size: 17 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006200f0
//
// 006200f0  56                   push esi
// 006200f1  8bf1                 mov esi, ecx
// 006200f3  e8dae5ffff           call 0x61e6d2
// 006200f8  c7465401000000       mov dword ptr [esi + 0x54], 1
// 006200ff  5e                   pop esi
// 00620100  c3                   ret 
// library xtp-15.2.1/Source\CommandBars\XTPControlEdit.cpp (function ?OnImeStartComposition@CXTPCommandBarEditCtrl@@IAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPControlEdit.cpp
