// from server: 100% by auto
// roc 2009-12 0067f290  unit: RBX::ModelInstance  size: 11 bytes
// Make this compile to the exact bytes below, then: roc check 2009-12 0067f290
//
// 0067f290  6830f26700           push 0x67f230
// 0067f295  e8d64edeff           call 0x464170
// 0067f29a  c3                   ret 
// library mfc-8.0/atlmfc\src\mfc\auxdata.cpp (function ??__FafxData@@YAXXZ)

// roc-lang: cpp
// roc-cl: 50727
// roc-flags: /O2 /GS- /MD
// roc-lib: mfc-8.0 atlmfc/src/mfc/auxdata.cpp
