// from server: 100% by auto
// roc 2007-08 0044cfa0  unit: CRobloxDHtmlDialog  size: 8 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0044cfa0
//
// 0044cfa0  6a00                 push 0
// 0044cfa2  e8d9070e00           call 0x52d780
// 0044cfa7  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\olepset.cpp (function ?Get@CProperty@@QAEPAXXZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/olepset.cpp
