// from server: 100% by auto
// roc 2007-08 006c6a30  unit: CXTPCustomizeSheet::CCustomizeEdit  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 006c6a30
//
// 006c6a30  6800030000           push 0x300
// 006c6a35  e8665af7ff           call 0x63c4a0
// 006c6a3a  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\array_b.cpp (function ??__E_init_CByteArray@@YAXXZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/array_b.cpp
