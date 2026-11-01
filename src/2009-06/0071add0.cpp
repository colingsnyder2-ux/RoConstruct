// from server: 100% by auto
// roc 2009-06 0071add0  unit: CXTPEdit  size: 17 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0071add0
//
// 0071add0  56                   push esi
// 0071add1  8bf1                 mov esi, ecx
// 0071add3  e830e2ffff           call 0x719008
// 0071add8  c7465401000000       mov dword ptr [esi + 0x54], 1
// 0071addf  5e                   pop esi
// 0071ade0  c3                   ret 
// library xtp-15.2.1/Source\CommandBars\XTPControlEdit.cpp (function ?OnImeStartComposition@CXTPCommandBarEditCtrl@@IAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPControlEdit.cpp
