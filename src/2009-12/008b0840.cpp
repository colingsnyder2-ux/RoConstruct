// from server: 100% by auto
// roc 2009-12 008b0840  unit: CXTPDockingPane  size: 15 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008b0840
//
// 008b0840  8b410c               mov eax, dword ptr [ecx + 0xc]
// 008b0843  85c0                 test eax, eax
// 008b0845  7501                 jne 0x8b0848
// 008b0847  c3                   ret 
// 008b0848  8b8084000000         mov eax, dword ptr [eax + 0x84]
// 008b084e  c3                   ret 
// library xtp-15.2.1/Source\DockingPane\XTPDockingPaneBase.cpp (function ?GetDockingPaneManager@CXTPDockingPaneBase@@QBEPAVCXTPDockingPaneManager@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/DockingPane/XTPDockingPaneBase.cpp
