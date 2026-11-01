// from server: 100% by auto
// roc 2009-12 00877580  unit: CXTPControlGallery  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00877580
//
// 00877580  6815100000           push 0x1015
// 00877585  e80610f8ff           call 0x7f8590
// 0087758a  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\array_b.cpp (function ??__E_init_CByteArray@@YAXXZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/array_b.cpp
