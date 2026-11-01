// from server: 100% by auto
// roc 2009-12 007f9000  unit: CXTPEdit  size: 17 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 007f9000
//
// 007f9000  56                   push esi
// 007f9001  8bf1                 mov esi, ecx
// 007f9003  e828aeffff           call 0x7f3e30
// 007f9008  c7465400000000       mov dword ptr [esi + 0x54], 0
// 007f900f  5e                   pop esi
// 007f9010  c3                   ret 
// library xtp-15.2.1/Source\CommandBars\XTPControlEdit.cpp (function ?OnImeEndComposition@CXTPCommandBarEditCtrl@@IAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPControlEdit.cpp
