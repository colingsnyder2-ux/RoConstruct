// from server: 100% by auto
// roc 2010-06 008a7090  unit: CXTPDockingPaneAutoHidePanel  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 008a7090
//
// 008a7090  83794400             cmp dword ptr [ecx + 0x44], 0
// 008a7094  7503                 jne 0x8a7099
// 008a7096  33c0                 xor eax, eax
// 008a7098  c3                   ret 
// 008a7099  8b4140               mov eax, dword ptr [ecx + 0x40]
// 008a709c  85c0                 test eax, eax
// 008a709e  7505                 jne 0x8a70a5
// 008a70a0  e9a70bf0ff           jmp 0x7a7c4c
// 008a70a5  8b4008               mov eax, dword ptr [eax + 8]
// 008a70a8  c3                   ret 
// library xtp-13.2.1/Source\DockingPane\XTPDockingPaneBaseContainer.cpp (function ?GetLastPane@CXTPDockingPaneBaseContainer@@QBEPAVCXTPDockingPaneBase@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/DockingPane/XTPDockingPaneBaseContainer.cpp
