// from server: 100% by auto
// roc 2009-12 0067f300  unit: RBX::ModelInstance  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0067f300
//
// 0067f300  68a0f26700           push 0x67f2a0
// 0067f305  e8664edeff           call 0x464170
// 0067f30a  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\auxdata.cpp (function ??__FafxData@@YAXXZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/auxdata.cpp
