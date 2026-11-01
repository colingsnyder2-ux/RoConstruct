// from server: 100% by auto
// roc 2009-12 0097d37f  unit: seg_00970000  size: 22 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0097d37f
//
// 0097d37f  b958c0b900           mov ecx, 0xb9c058
// 0097d384  e89f89f7ff           call 0x8f5d28
// 0097d389  68e9a79800           push 0x98a7e9
// 0097d38e  e89675e7ff           call 0x7f4929
// 0097d393  59                   pop ecx
// 0097d394  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\auxdata.cpp (function ??__EafxData@@YAXXZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/auxdata.cpp
