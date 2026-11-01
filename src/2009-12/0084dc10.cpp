// from server: 100% by auto
// roc 2009-12 0084dc10  unit: CXTPPropertyGrid  size: 12 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0084dc10
//
// 0084dc10  e86bfeffff           call 0x84da80
// 0084dc15  8b80e4000000         mov eax, dword ptr [eax + 0xe4]
// 0084dc1b  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\appui1.cpp (function ?GetRoutingView_@CCmdTarget@@KGPAVCView@@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/appui1.cpp
