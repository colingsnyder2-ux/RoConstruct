// from server: 100% by auto
// roc 2010-06 00864910  unit: CXTPDockingPane  size: 15 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00864910
//
// 00864910  8b410c               mov eax, dword ptr [ecx + 0xc]
// 00864913  85c0                 test eax, eax
// 00864915  7501                 jne 0x864918
// 00864917  c3                   ret 
// 00864918  8b8084000000         mov eax, dword ptr [eax + 0x84]
// 0086491e  c3                   ret 
// library xtp-13.2.1/Source\DockingPane\XTPDockingPaneBase.cpp (function ?GetDockingPaneManager@CXTPDockingPaneBase@@QBEPAVCXTPDockingPaneManager@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-13.2.1 Source/DockingPane/XTPDockingPaneBase.cpp
