// from server: 100% by auto
// roc 2007-03 00678da0  unit: seg_00670000  size: 17 bytes
// Make this compile to the exact bytes below, then: roc check 2007-03 00678da0
//
// 00678da0  51                   push ecx
// 00678da1  83c120               add ecx, 0x20
// 00678da4  e877070500           call 0x6c9520
// 00678da9  8bc8                 mov ecx, eax
// 00678dab  e8a01dfeff           call 0x65ab50
// 00678db0  c3                   ret 
// library xtp-15.2.1/Source\DockingPane\XTPDockingPane.cpp (function ?Close@CXTPDockingPane@@QAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O2 /GS- /MD
// roc-lib: xtp-15.2.1 Source/DockingPane/XTPDockingPane.cpp
