// from server: 100% by auto
// roc 2009-06 008182a0  unit: CXTPDockingPaneAutoHidePanel  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 008182a0
//
// 008182a0  83794400             cmp dword ptr [ecx + 0x44], 0
// 008182a4  7503                 jne 0x8182a9
// 008182a6  33c0                 xor eax, eax
// 008182a8  c3                   ret 
// 008182a9  8b4140               mov eax, dword ptr [ecx + 0x40]
// 008182ac  85c0                 test eax, eax
// 008182ae  7505                 jne 0x8182b5
// 008182b0  e92f0af0ff           jmp 0x718ce4
// 008182b5  8b4008               mov eax, dword ptr [eax + 8]
// 008182b8  c3                   ret 
// library xtp-15.2.1/Source\DockingPane\XTPDockingPaneBaseContainer.cpp (function ?GetLastPane@CXTPDockingPaneBaseContainer@@QBEPAVCXTPDockingPaneBase@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/DockingPane/XTPDockingPaneBaseContainer.cpp
