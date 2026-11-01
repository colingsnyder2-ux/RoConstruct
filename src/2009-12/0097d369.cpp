// from server: 100% by auto
// roc 2009-12 0097d369  unit: seg_00970000  size: 22 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0097d369
//
// 0097d369  b920c0b900           mov ecx, 0xb9c020
// 0097d36e  e83189f7ff           call 0x8f5ca4
// 0097d373  68dfa79800           push 0x98a7df
// 0097d378  e8ac75e7ff           call 0x7f4929
// 0097d37d  59                   pop ecx
// 0097d37e  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\auxdata.cpp (function ??__EafxData@@YAXXZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/auxdata.cpp
