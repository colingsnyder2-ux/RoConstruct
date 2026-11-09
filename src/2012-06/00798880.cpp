// from server: 100% by auto
// roc 2012-06 00798880  unit: RBX::Reflection::$$A6AXPBVPropertyDescriptor::?$signal::Vslot::?$callable  size: 8 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 00798880
//
// 00798880  6a02                 push 2
// 00798882  e839ffffff           call 0x7987c0
// 00798887  c3                   ret 
// library mfc-9.0/atlmfc\src\mfc\dlgcore.cpp (function ?OnCancel@CDialog@@MAEXXZ)

// roc-lang: cpp
// roc-cl: 30729
// roc-flags: /O1 /GS- /MD
// roc-lib: mfc-9.0 atlmfc/src/mfc/dlgcore.cpp
