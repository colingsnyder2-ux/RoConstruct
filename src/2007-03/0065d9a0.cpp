// from server: 100% by auto
// roc 2007-03 0065d9a0  unit: seg_00650000  size: 19 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 0065d9a0
//
// 0065d9a0  6a01                 push 1
// 0065d9a2  6a00                 push 0
// 0065d9a4  6a01                 push 1
// 0065d9a6  e8d5ecffff           call 0x65c680
// 0065d9ab  8bc8                 mov ecx, eax
// 0065d9ad  e83ebc0200           call 0x6895f0
// 0065d9b2  c3                   ret 
// library xtp-13.2.1/Source\PropertyGrid\XTPPropertyGrid.cpp (function ?OnSortAlphabetic@CXTPPropertyGrid@@IAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: xtp-13.2.1 Source/PropertyGrid/XTPPropertyGrid.cpp
