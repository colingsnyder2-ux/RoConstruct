// from server: 100% by auto
// roc 2009-06 007d5f50  unit: CXTPDockingPane  size: 22 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 007d5f50
//
// 007d5f50  8b4118               mov eax, dword ptr [ecx + 0x18]
// 007d5f53  3b442404             cmp eax, dword ptr [esp + 4]
// 007d5f57  750a                 jne 0x7d5f63
// 007d5f59  51                   push ecx
// 007d5f5a  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 007d5f5e  e86df90000           call 0x7e58d0
// 007d5f63  c20800               ret 8
// library xtp-15.2.1/Source\DockingPane\XTPDockingPaneBase.cpp (function ?FindPane@CXTPDockingPaneBase@@UBEXW4XTPDockingPaneType@@PAV?$CList@PAVCXTPDockingPaneBase@@PAV1@@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: xtp-15.2.1 Source/DockingPane/XTPDockingPaneBase.cpp
