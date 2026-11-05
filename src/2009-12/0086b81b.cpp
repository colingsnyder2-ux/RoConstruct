// roc 2009-12 0086b81b  unit: CXTPPropertyGridItemEnum  size: 6 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0086b81b
//
// 0086b81b  b821b88600           mov eax, 0x86b821
// 0086b820  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\appcore.cpp (function ?GetThisMessageMap@CWinApp@@KGPBUAFX_MSGMAP@@XZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/appcore.cpp
