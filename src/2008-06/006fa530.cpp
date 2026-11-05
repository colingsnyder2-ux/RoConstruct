// from server: 100% by auto
// roc 2008-06 006fa530  unit: CXTPPropertyGrid  size: 12 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 006fa530
//
// 006fa530  e87bfeffff           call 0x6fa3b0
// 006fa535  8b80e4000000         mov eax, dword ptr [eax + 0xe4]
// 006fa53b  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\appui1.cpp (function ?GetRoutingView_@CCmdTarget@@KGPAVCView@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/appui1.cpp
