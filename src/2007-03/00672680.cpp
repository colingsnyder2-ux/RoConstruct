// from server: 100% by auto
// roc 2007-03 00672680  unit: seg_00670000  size: 24 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00672680
//
// 00672680  56                   push esi
// 00672681  8bf1                 mov esi, ecx
// 00672683  8b4e3c               mov ecx, dword ptr [esi + 0x3c]
// 00672686  85c9                 test ecx, ecx
// 00672688  740c                 je 0x672696
// 0067268a  e8e3bffaff           call 0x61e672
// 0067268f  c7463c00000000       mov dword ptr [esi + 0x3c], 0
// 00672696  5e                   pop esi
// 00672697  c3                   ret 
// library xtp-15.2.1/Source\CommandBars\XTPControls.cpp (function ?ClearOriginalControls@CXTPControls@@QAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/CommandBars/XTPControls.cpp
