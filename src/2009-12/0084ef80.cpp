// from server: 100% by auto
// roc 2009-12 0084ef80  unit: CXTPPropertyGrid  size: 19 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0084ef80
//
// 0084ef80  6a01                 push 1
// 0084ef82  6a00                 push 0
// 0084ef84  6a00                 push 0
// 0084ef86  e8f5eaffff           call 0x84da80
// 0084ef8b  8bc8                 mov ecx, eax
// 0084ef8d  e8feb30100           call 0x86a390
// 0084ef92  c3                   ret 
// library xtp-13.2.1/Source\PropertyGrid\XTPPropertyGrid.cpp (function ?OnSortCategorized@CXTPPropertyGrid@@IAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: xtp-13.2.1 Source/PropertyGrid/XTPPropertyGrid.cpp
