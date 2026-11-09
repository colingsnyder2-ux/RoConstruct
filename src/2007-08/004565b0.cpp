// from server: 100% by auto
// roc 2007-08 004565b0  unit: CRobloxView  size: 8 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 004565b0
//
// 004565b0  6a00                 push 0
// 004565b2  e899feffff           call 0x456450
// 004565b7  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\olepset.cpp (function ?Get@CProperty@@QAEPAXXZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/olepset.cpp
