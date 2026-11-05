// from server: 100% by auto
// roc 2010-06 00802fe0  unit: CXTPPropertyGrid  size: 19 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00802fe0
//
// 00802fe0  6a01                 push 1
// 00802fe2  6a00                 push 0
// 00802fe4  6a00                 push 0
// 00802fe6  e8f5eaffff           call 0x801ae0
// 00802feb  8bc8                 mov ecx, eax
// 00802fed  e89eb30100           call 0x81e390
// 00802ff2  c3                   ret 
// library xtp-13.2.1/Source\PropertyGrid\XTPPropertyGrid.cpp (function ?OnSortCategorized@CXTPPropertyGrid@@IAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: xtp-13.2.1 Source/PropertyGrid/XTPPropertyGrid.cpp
