// from server: 100% by auto
// roc 2010-06 00802fc0  unit: CXTPPropertyGrid  size: 19 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00802fc0
//
// 00802fc0  6a01                 push 1
// 00802fc2  6a00                 push 0
// 00802fc4  6a01                 push 1
// 00802fc6  e815ebffff           call 0x801ae0
// 00802fcb  8bc8                 mov ecx, eax
// 00802fcd  e8beb30100           call 0x81e390
// 00802fd2  c3                   ret 
// library xtp-13.2.1/Source\PropertyGrid\XTPPropertyGrid.cpp (function ?OnSortAlphabetic@CXTPPropertyGrid@@IAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: xtp-13.2.1 Source/PropertyGrid/XTPPropertyGrid.cpp
