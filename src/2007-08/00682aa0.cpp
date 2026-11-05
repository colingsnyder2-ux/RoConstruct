// from server: 100% by auto
// roc 2007-08 00682aa0  unit: CXTPPropertyGrid  size: 12 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00682aa0
//
// 00682aa0  e87bffffff           call 0x682a20
// 00682aa5  8b80e4000000         mov eax, dword ptr [eax + 0xe4]
// 00682aab  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\appui1.cpp (function ?GetRoutingView_@CCmdTarget@@KGPAVCView@@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/appui1.cpp
