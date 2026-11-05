// from server: 100% by auto
// roc 2010-06 007b3dd0  unit: CXTPEdit  size: 17 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007b3dd0
//
// 007b3dd0  56                   push esi
// 007b3dd1  8bf1                 mov esi, ecx
// 007b3dd3  e89841ffff           call 0x7a7f70
// 007b3dd8  c7465400000000       mov dword ptr [esi + 0x54], 0
// 007b3ddf  5e                   pop esi
// 007b3de0  c3                   ret 
// library xtp-13.2.1/Source\CommandBars\XTPControlComboBox.cpp (function ?OnImeEndComposition@CXTPCommandBarEditCtrl@@IAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPControlComboBox.cpp
