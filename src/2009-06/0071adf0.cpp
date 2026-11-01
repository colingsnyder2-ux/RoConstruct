// from server: 100% by auto
// roc 2009-06 0071adf0  unit: CXTPEdit  size: 17 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0071adf0
//
// 0071adf0  56                   push esi
// 0071adf1  8bf1                 mov esi, ecx
// 0071adf3  e810e2ffff           call 0x719008
// 0071adf8  c7465400000000       mov dword ptr [esi + 0x54], 0
// 0071adff  5e                   pop esi
// 0071ae00  c3                   ret 
// library xtp-15.2.1/Source\CommandBars\XTPControlEdit.cpp (function ?OnImeEndComposition@CXTPCommandBarEditCtrl@@IAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPControlEdit.cpp
