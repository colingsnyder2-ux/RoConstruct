// from server: 100% by auto
// roc 2007-03 0065c6f0  unit: seg_00650000  size: 12 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0065c6f0
//
// 0065c6f0  e88bffffff           call 0x65c680
// 0065c6f5  8b80e4000000         mov eax, dword ptr [eax + 0xe4]
// 0065c6fb  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\appui1.cpp (function ?GetRoutingView_@CCmdTarget@@KGPAVCView@@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/appui1.cpp
