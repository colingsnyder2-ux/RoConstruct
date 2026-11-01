// from server: 100% by auto
// roc 2009-06 0076a430  unit: CXTPControls  size: 24 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0076a430
//
// 0076a430  56                   push esi
// 0076a431  8bf1                 mov esi, ecx
// 0076a433  8b4e3c               mov ecx, dword ptr [esi + 0x3c]
// 0076a436  85c9                 test ecx, ecx
// 0076a438  740c                 je 0x76a446
// 0076a43a  e869ebfaff           call 0x718fa8
// 0076a43f  c7463c00000000       mov dword ptr [esi + 0x3c], 0
// 0076a446  5e                   pop esi
// 0076a447  c3                   ret 
// library xtp-15.2.1/Source\CommandBars\XTPControls.cpp (function ?ClearOriginalControls@CXTPControls@@QAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPControls.cpp
