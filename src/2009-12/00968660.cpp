// from server: 100% by auto
// roc 2009-12 00968660  unit: seg_00960000  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00968660
//
// 00968660  68d44ab000           push 0xb04ad4
// 00968665  e8b6bbe8ff           call 0x7f4220
// 0096866a  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\auxdata.cpp (function ??__FafxData@@YAXXZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/auxdata.cpp
