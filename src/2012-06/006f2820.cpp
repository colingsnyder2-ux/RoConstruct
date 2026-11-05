// from server: 100% by auto
// roc 2012-06 006f2820  unit: RBX::DataModel  size: 8 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 006f2820
//
// 006f2820  6a02                 push 2
// 006f2822  e8d9990900           call 0x78c200
// 006f2827  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\dlgcore.cpp (function ?OnCancel@CDialog@@MAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/dlgcore.cpp
