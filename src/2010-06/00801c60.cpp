// from server: 100% by auto
// roc 2010-06 00801c60  unit: CXTPPropertyGrid  size: 12 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00801c60
//
// 00801c60  e87bfeffff           call 0x801ae0
// 00801c65  8b80e4000000         mov eax, dword ptr [eax + 0xe4]
// 00801c6b  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\appui1.cpp (function ?GetRoutingView_@CCmdTarget@@KGPAVCView@@XZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/appui1.cpp
