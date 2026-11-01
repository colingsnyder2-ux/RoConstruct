// from server: 100% by auto
// roc 2011-06 0086a670  unit: CXTPPropertyGrid  size: 19 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0086a670
//
// 0086a670  6a01                 push 1
// 0086a672  6a00                 push 0
// 0086a674  6a01                 push 1
// 0086a676  e835ebffff           call 0x8691b0
// 0086a67b  8bc8                 mov ecx, eax
// 0086a67d  e8dee20000           call 0x878960
// 0086a682  c3                   ret 
// library xtp-13.2.1/Source\PropertyGrid\XTPPropertyGrid.cpp (function ?OnSortAlphabetic@CXTPPropertyGrid@@IAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: xtp-13.2.1 Source/PropertyGrid/XTPPropertyGrid.cpp
