// from server: 100% by auto
// roc 2012-06 009e1890  unit: CXTPPropertyGrid  size: 12 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 009e1890
//
// 009e1890  e88bfeffff           call 0x9e1720
// 009e1895  8b80e4000000         mov eax, dword ptr [eax + 0xe4]
// 009e189b  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\appui1.cpp (function ?GetRoutingView_@CCmdTarget@@KGPAVCView@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/appui1.cpp
