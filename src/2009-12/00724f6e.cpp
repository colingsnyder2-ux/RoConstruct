// roc 2009-12 00724f6e  unit: UString_sink::?$stream_buffer  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00724f6e
//
// 00724f6e  b8744f7200           mov eax, 0x724f74
// 00724f73  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\appcore.cpp (function ?GetThisMessageMap@CWinApp@@KGPBUAFX_MSGMAP@@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/appcore.cpp
