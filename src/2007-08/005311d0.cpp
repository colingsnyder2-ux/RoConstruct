// from server: 100% by auto
// roc 2007-08 005311d0  unit: RBX::ModelInstance  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 005311d0
//
// 005311d0  6870115300           push 0x531170
// 005311d5  e8666df5ff           call 0x487f40
// 005311da  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\auxdata.cpp (function ??__FafxData@@YAXXZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/auxdata.cpp
