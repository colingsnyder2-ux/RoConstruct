// from server: 100% by auto
// roc 2010-06 008a7070  unit: CXTPDockingPaneAutoHidePanel  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008a7070
//
// 008a7070  83794400             cmp dword ptr [ecx + 0x44], 0
// 008a7074  7503                 jne 0x8a7079
// 008a7076  33c0                 xor eax, eax
// 008a7078  c3                   ret 
// 008a7079  8b413c               mov eax, dword ptr [ecx + 0x3c]
// 008a707c  85c0                 test eax, eax
// 008a707e  7505                 jne 0x8a7085
// 008a7080  e9c70bf0ff           jmp 0x7a7c4c
// 008a7085  8b4008               mov eax, dword ptr [eax + 8]
// 008a7088  c3                   ret 
// library xtp-13.2.1/Source\DockingPane\XTPDockingPaneBaseContainer.cpp (function ?GetFirstPane@CXTPDockingPaneBaseContainer@@QBEPAVCXTPDockingPaneBase@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/DockingPane/XTPDockingPaneBaseContainer.cpp
