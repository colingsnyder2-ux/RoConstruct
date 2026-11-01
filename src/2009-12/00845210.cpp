// from server: 100% by auto
// roc 2009-12 00845210  unit: CXTPControls  size: 24 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00845210
//
// 00845210  56                   push esi
// 00845211  8bf1                 mov esi, ecx
// 00845213  8b4e3c               mov ecx, dword ptr [esi + 0x3c]
// 00845216  85c9                 test ecx, ecx
// 00845218  740c                 je 0x845226
// 0084521a  e8bdebfaff           call 0x7f3ddc
// 0084521f  c7463c00000000       mov dword ptr [esi + 0x3c], 0
// 00845226  5e                   pop esi
// 00845227  c3                   ret 
// library xtp-15.2.1/Source\CommandBars\XTPControls.cpp (function ?ClearOriginalControls@CXTPControls@@QAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPControls.cpp
