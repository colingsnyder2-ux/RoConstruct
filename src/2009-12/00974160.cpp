// from server: 100% by auto
// roc 2009-12 00974160  unit: seg_00970000  size: 22 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 00974160
//
// 00974160  b9f019b900           mov ecx, 0xb919f0
// 00974165  e816c6e2ff           call 0x7a0780
// 0097416a  68a0559800           push 0x9855a0
// 0097416f  e8b507e8ff           call 0x7f4929
// 00974174  59                   pop ecx
// 00974175  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\auxdata.cpp (function ??__EafxData@@YAXXZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/auxdata.cpp
