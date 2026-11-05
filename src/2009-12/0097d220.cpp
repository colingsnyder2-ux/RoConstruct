// from server: 100% by auto
// roc 2009-12 0097d220  unit: seg_00970000  size: 22 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0097d220
//
// 0097d220  b974bfb900           mov ecx, 0xb9bf74
// 0097d225  e81c94faff           call 0x926646
// 0097d22a  68a0a79800           push 0x98a7a0
// 0097d22f  e8f576e7ff           call 0x7f4929
// 0097d234  59                   pop ecx
// 0097d235  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\auxdata.cpp (function ??__EafxData@@YAXXZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/auxdata.cpp
