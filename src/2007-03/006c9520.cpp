// from server: 100% by auto
// roc 2007-03 006c9520  unit: seg_006c0000  size: 15 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006c9520
//
// 006c9520  8b410c               mov eax, dword ptr [ecx + 0xc]
// 006c9523  85c0                 test eax, eax
// 006c9525  7501                 jne 0x6c9528
// 006c9527  c3                   ret 
// 006c9528  8b8084000000         mov eax, dword ptr [eax + 0x84]
// 006c952e  c3                   ret 
// library xtp-15.2.1/Source\DockingPane\XTPDockingPaneBase.cpp (function ?GetDockingPaneManager@CXTPDockingPaneBase@@QBEPAVCXTPDockingPaneManager@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/DockingPane/XTPDockingPaneBase.cpp
