// from server: 100% by auto
// roc 2007-08 00531240  unit: RBX::ModelInstance  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2007-08 00531240
//
// 00531240  68e0115300           push 0x5311e0
// 00531245  e8f66cf5ff           call 0x487f40
// 0053124a  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\auxdata.cpp (function ??__FafxData@@YAXXZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/auxdata.cpp
