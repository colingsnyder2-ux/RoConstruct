// from server: 100% by auto
// roc 2009-06 00774220  unit: CXTPPropertyGrid  size: 19 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00774220
//
// 00774220  6a01                 push 1
// 00774222  6a00                 push 0
// 00774224  6a00                 push 0
// 00774226  e825ebffff           call 0x772d50
// 0077422b  8bc8                 mov ecx, eax
// 0077422d  e83eb10100           call 0x78f370
// 00774232  c3                   ret 
// library xtp-13.2.1/Source\PropertyGrid\XTPPropertyGrid.cpp (function ?OnSortCategorized@CXTPPropertyGrid@@IAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: xtp-13.2.1 Source/PropertyGrid/XTPPropertyGrid.cpp
