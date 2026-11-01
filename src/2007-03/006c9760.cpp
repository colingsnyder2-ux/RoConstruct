// from server: 100% by auto
// roc 2007-03 006c9760  unit: seg_006c0000  size: 22 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 006c9760
//
// 006c9760  8b4118               mov eax, dword ptr [ecx + 0x18]
// 006c9763  3b442404             cmp eax, dword ptr [esp + 4]
// 006c9767  750a                 jne 0x6c9773
// 006c9769  51                   push ecx
// 006c976a  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 006c976e  e8fd900100           call 0x6e2870
// 006c9773  c20800               ret 8
// library xtp-15.2.1/Source\DockingPane\XTPDockingPaneBase.cpp (function ?FindPane@CXTPDockingPaneBase@@UBEXW4XTPDockingPaneType@@PAV?$CList@PAVCXTPDockingPaneBase@@PAV1@@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: xtp-15.2.1 Source/DockingPane/XTPDockingPaneBase.cpp
