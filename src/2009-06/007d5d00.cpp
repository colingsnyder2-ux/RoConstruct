// from server: 100% by auto
// roc 2009-06 007d5d00  unit: CXTPDockingPane  size: 15 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007d5d00
//
// 007d5d00  8b410c               mov eax, dword ptr [ecx + 0xc]
// 007d5d03  85c0                 test eax, eax
// 007d5d05  7501                 jne 0x7d5d08
// 007d5d07  c3                   ret 
// 007d5d08  8b8084000000         mov eax, dword ptr [eax + 0x84]
// 007d5d0e  c3                   ret 
// library xtp-15.2.1/Source\DockingPane\XTPDockingPaneBase.cpp (function ?GetDockingPaneManager@CXTPDockingPaneBase@@QBEPAVCXTPDockingPaneManager@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/DockingPane/XTPDockingPaneBase.cpp
