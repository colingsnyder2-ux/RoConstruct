// from server: 100% by auto
// roc 2009-12 0088b1f0  unit: CXTPCustomizeSheet::CCustomizeEdit  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0088b1f0
//
// 0088b1f0  6800030000           push 0x300
// 0088b1f5  e896d3f6ff           call 0x7f8590
// 0088b1fa  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\array_b.cpp (function ??__E_init_CByteArray@@YAXXZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/array_b.cpp
