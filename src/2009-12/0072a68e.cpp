// roc 2009-12 0072a68e  unit: VWinHttpRequest_source::?$stream_buffer  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0072a68e
//
// 0072a68e  b894a67200           mov eax, 0x72a694
// 0072a693  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\appcore.cpp (function ?GetThisMessageMap@CWinApp@@KGPBUAFX_MSGMAP@@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/appcore.cpp
