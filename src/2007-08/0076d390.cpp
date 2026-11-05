// from server: 100% by auto
// roc 2007-08 0076d390  unit: seg_00760000  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 0076d390
//
// 0076d390  68bc928800           push 0x8892bc
// 0076d395  e85631ecff           call 0x6304f0
// 0076d39a  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\auxdata.cpp (function ??__FafxData@@YAXXZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/auxdata.cpp
