// from server: 100% by auto
// roc 2009-06 00772ec0  unit: CXTPPropertyGrid  size: 12 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00772ec0
//
// 00772ec0  e88bfeffff           call 0x772d50
// 00772ec5  8b80e4000000         mov eax, dword ptr [eax + 0xe4]
// 00772ecb  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\appui1.cpp (function ?GetRoutingView_@CCmdTarget@@KGPAVCView@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/appui1.cpp
