// roc 2009-12 004199a9  unit: InsertService  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 004199a9
//
// 004199a9  b88c994100           mov eax, 0x41998c
// 004199ae  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\appcore.cpp (function ?GetThisMessageMap@CWinApp@@KGPBUAFX_MSGMAP@@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/appcore.cpp
