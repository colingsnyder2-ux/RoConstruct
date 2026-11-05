// roc 2009-12 00419e5a  unit: InsertObject  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00419e5a
//
// 00419e5a  b83d9e4100           mov eax, 0x419e3d
// 00419e5f  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\appcore.cpp (function ?GetThisMessageMap@CWinApp@@KGPBUAFX_MSGMAP@@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/appcore.cpp
