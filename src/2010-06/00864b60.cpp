// from server: 100% by auto
// roc 2010-06 00864b60  unit: CXTPDockingPane  size: 22 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00864b60
//
// 00864b60  8b4118               mov eax, dword ptr [ecx + 0x18]
// 00864b63  3b442404             cmp eax, dword ptr [esp + 4]
// 00864b67  750a                 jne 0x864b73
// 00864b69  51                   push ecx
// 00864b6a  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 00864b6e  e82da70200           call 0x88f2a0
// 00864b73  c20800               ret 8
// library xtp-13.2.1/Source\DockingPane\XTPDockingPaneBase.cpp (function ?FindPane@CXTPDockingPaneBase@@UBEXW4XTPDockingPaneType@@PAV?$CList@PAVCXTPDockingPaneBase@@PAV1@@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: xtp-13.2.1 Source/DockingPane/XTPDockingPaneBase.cpp
