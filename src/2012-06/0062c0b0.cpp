// from server: 100% by auto
// roc 2012-06 0062c0b0  unit: G3D::Sphere  size: 8 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0062c0b0
//
// 0062c0b0  a11825b200           mov eax, dword ptr [0xb22518]
// 0062c0b5  dd00                 fld qword ptr [eax]
// 0062c0b7  c3                   ret 
// library rbx2016-g3d/g3dmath.cpp (function ?inf@G3D@@YANXZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbx2016-g3d g3dmath.cpp
