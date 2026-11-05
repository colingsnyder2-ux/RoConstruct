// from server: 100% by auto
// roc 2009-12 009692a0  unit: seg_00960000  size: 22 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 009692a0
//
// 009692a0  b9d8b2b700           mov ecx, 0xb7b2d8
// 009692a5  e8e65eaeff           call 0x44f190
// 009692aa  6870e89700           push 0x97e870
// 009692af  e875b6e8ff           call 0x7f4929
// 009692b4  59                   pop ecx
// 009692b5  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\auxdata.cpp (function ??__EafxData@@YAXXZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/auxdata.cpp
