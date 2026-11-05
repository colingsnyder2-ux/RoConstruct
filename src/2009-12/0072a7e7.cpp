// roc 2009-12 0072a7e7  unit: VWinHttpRequest_source::?$stream_buffer  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0072a7e7
//
// 0072a7e7  b8eda77200           mov eax, 0x72a7ed
// 0072a7ec  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\appcore.cpp (function ?GetThisMessageMap@CWinApp@@KGPBUAFX_MSGMAP@@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/appcore.cpp
