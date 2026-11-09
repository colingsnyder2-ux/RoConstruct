// from server: 100% by auto
// roc 2009-12 0084ef60  unit: CXTPPropertyGrid  size: 19 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0084ef60
//
// 0084ef60  6a01                 push 1
// 0084ef62  6a00                 push 0
// 0084ef64  6a01                 push 1
// 0084ef66  e815ebffff           call 0x84da80
// 0084ef6b  8bc8                 mov ecx, eax
// 0084ef6d  e81eb40100           call 0x86a390
// 0084ef72  c3                   ret 
// library xtp-13.2.1/Source\PropertyGrid\XTPPropertyGrid.cpp (function ?OnSortAlphabetic@CXTPPropertyGrid@@IAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: xtp-13.2.1 Source/PropertyGrid/XTPPropertyGrid.cpp
