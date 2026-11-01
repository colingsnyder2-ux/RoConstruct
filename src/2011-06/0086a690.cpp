// from server: 100% by auto
// roc 2011-06 0086a690  unit: CXTPPropertyGrid  size: 19 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0086a690
//
// 0086a690  6a01                 push 1
// 0086a692  6a00                 push 0
// 0086a694  6a00                 push 0
// 0086a696  e815ebffff           call 0x8691b0
// 0086a69b  8bc8                 mov ecx, eax
// 0086a69d  e8bee20000           call 0x878960
// 0086a6a2  c3                   ret 
// library xtp-13.2.1/Source\PropertyGrid\XTPPropertyGrid.cpp (function ?OnSortCategorized@CXTPPropertyGrid@@IAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: xtp-13.2.1 Source/PropertyGrid/XTPPropertyGrid.cpp
