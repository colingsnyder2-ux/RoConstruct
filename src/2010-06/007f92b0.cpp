// from server: 100% by auto
// roc 2010-06 007f92b0  unit: CXTPControls  size: 24 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 007f92b0
//
// 007f92b0  56                   push esi
// 007f92b1  8bf1                 mov esi, ecx
// 007f92b3  8b4e3c               mov ecx, dword ptr [esi + 0x3c]
// 007f92b6  85c9                 test ecx, ecx
// 007f92b8  740c                 je 0x7f92c6
// 007f92ba  e85decfaff           call 0x7a7f1c
// 007f92bf  c7463c00000000       mov dword ptr [esi + 0x3c], 0
// 007f92c6  5e                   pop esi
// 007f92c7  c3                   ret 
// library xtp-13.2.1/Source\CommandBars\XTPControls.cpp (function ?ClearOriginalControls@CXTPControls@@QAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/CommandBars/XTPControls.cpp
