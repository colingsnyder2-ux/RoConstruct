// from server: 100% by auto
// roc 2009-12 0097d310  unit: seg_00970000  size: 22 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0097d310
//
// 0097d310  b9dcbfb900           mov ecx, 0xb9bfdc
// 0097d315  e85665f7ff           call 0x8f3870
// 0097d31a  68c0a79800           push 0x98a7c0
// 0097d31f  e80576e7ff           call 0x7f4929
// 0097d324  59                   pop ecx
// 0097d325  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\auxdata.cpp (function ??__EafxData@@YAXXZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/auxdata.cpp
