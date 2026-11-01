// from server: 100% by auto
// roc 2009-12 008f2f20  unit: CXTPDockingPaneAutoHidePanel  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008f2f20
//
// 008f2f20  83794400             cmp dword ptr [ecx + 0x44], 0
// 008f2f24  7503                 jne 0x8f2f29
// 008f2f26  33c0                 xor eax, eax
// 008f2f28  c3                   ret 
// 008f2f29  8b413c               mov eax, dword ptr [ecx + 0x3c]
// 008f2f2c  85c0                 test eax, eax
// 008f2f2e  7505                 jne 0x8f2f35
// 008f2f30  e9d70bf0ff           jmp 0x7f3b0c
// 008f2f35  8b4008               mov eax, dword ptr [eax + 8]
// 008f2f38  c3                   ret 
// library xtp-15.2.1/Source\DockingPane\XTPDockingPaneBaseContainer.cpp (function ?GetFirstPane@CXTPDockingPaneBaseContainer@@QBEPAVCXTPDockingPaneBase@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/DockingPane/XTPDockingPaneBaseContainer.cpp
