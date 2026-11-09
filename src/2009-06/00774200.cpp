// from server: 100% by auto
// roc 2009-06 00774200  unit: CXTPPropertyGrid  size: 19 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 00774200
//
// 00774200  6a01                 push 1
// 00774202  6a00                 push 0
// 00774204  6a01                 push 1
// 00774206  e845ebffff           call 0x772d50
// 0077420b  8bc8                 mov ecx, eax
// 0077420d  e85eb10100           call 0x78f370
// 00774212  c3                   ret 
// library xtp-13.2.1/Source\PropertyGrid\XTPPropertyGrid.cpp (function ?OnSortAlphabetic@CXTPPropertyGrid@@IAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: xtp-13.2.1 Source/PropertyGrid/XTPPropertyGrid.cpp
