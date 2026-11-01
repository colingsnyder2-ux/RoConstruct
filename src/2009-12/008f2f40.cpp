// from server: 100% by auto
// roc 2009-12 008f2f40  unit: CXTPDockingPaneAutoHidePanel  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008f2f40
//
// 008f2f40  83794400             cmp dword ptr [ecx + 0x44], 0
// 008f2f44  7503                 jne 0x8f2f49
// 008f2f46  33c0                 xor eax, eax
// 008f2f48  c3                   ret 
// 008f2f49  8b4140               mov eax, dword ptr [ecx + 0x40]
// 008f2f4c  85c0                 test eax, eax
// 008f2f4e  7505                 jne 0x8f2f55
// 008f2f50  e9b70bf0ff           jmp 0x7f3b0c
// 008f2f55  8b4008               mov eax, dword ptr [eax + 8]
// 008f2f58  c3                   ret 
// library xtp-15.2.1/Source\DockingPane\XTPDockingPaneBaseContainer.cpp (function ?GetLastPane@CXTPDockingPaneBaseContainer@@QBEPAVCXTPDockingPaneBase@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/DockingPane/XTPDockingPaneBaseContainer.cpp
