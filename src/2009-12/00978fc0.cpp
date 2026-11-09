// from server: 100% by auto
// roc 2009-12 00978fc0  unit: seg_00970000  size: 22 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00978fc0
//
// 00978fc0  b9e860b900           mov ecx, 0xb960e8
// 00978fc5  e8069bbbff           call 0x532ad0
// 00978fca  6850809800           push 0x988050
// 00978fcf  e855b9e7ff           call 0x7f4929
// 00978fd4  59                   pop ecx
// 00978fd5  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\auxdata.cpp (function ??__EafxData@@YAXXZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/auxdata.cpp
