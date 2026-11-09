// from server: 100% by auto
// roc 2011-06 00869320  unit: CXTPPropertyGrid  size: 12 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00869320
//
// 00869320  e88bfeffff           call 0x8691b0
// 00869325  8b80e4000000         mov eax, dword ptr [eax + 0xe4]
// 0086932b  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\appui1.cpp (function ?GetRoutingView_@CCmdTarget@@KGPAVCView@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/appui1.cpp
