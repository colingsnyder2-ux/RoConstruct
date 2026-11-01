// from server: 100% by auto
// roc 2009-12 007f8fe0  unit: CXTPEdit  size: 17 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007f8fe0
//
// 007f8fe0  56                   push esi
// 007f8fe1  8bf1                 mov esi, ecx
// 007f8fe3  e848aeffff           call 0x7f3e30
// 007f8fe8  c7465401000000       mov dword ptr [esi + 0x54], 1
// 007f8fef  5e                   pop esi
// 007f8ff0  c3                   ret 
// library xtp-15.2.1/Source\CommandBars\XTPControlEdit.cpp (function ?OnImeStartComposition@CXTPCommandBarEditCtrl@@IAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPControlEdit.cpp
