// from server: 100% by auto
// roc 2009-12 008b0a90  unit: CXTPDockingPane  size: 22 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 008b0a90
//
// 008b0a90  8b4118               mov eax, dword ptr [ecx + 0x18]
// 008b0a93  3b442404             cmp eax, dword ptr [esp + 4]
// 008b0a97  750a                 jne 0x8b0aa3
// 008b0a99  51                   push ecx
// 008b0a9a  8b4c240c             mov ecx, dword ptr [esp + 0xc]
// 008b0a9e  e8dd300100           call 0x8c3b80
// 008b0aa3  c20800               ret 8
// library xtp-15.2.1/Source\DockingPane\XTPDockingPaneBase.cpp (function ?FindPane@CXTPDockingPaneBase@@UBEXW4XTPDockingPaneType@@PAV?$CList@PAVCXTPDockingPaneBase@@PAV1@@@@Z)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: xtp-15.2.1 Source/DockingPane/XTPDockingPaneBase.cpp
