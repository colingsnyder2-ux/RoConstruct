// from server: 100% by auto
// roc 2012-06 0062c0a0  unit: G3D::Sphere  size: 8 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0062c0a0
//
// 0062c0a0  a11c25b200           mov eax, dword ptr [0xb2251c]
// 0062c0a5  d900                 fld dword ptr [eax]
// 0062c0a7  c3                   ret 
// library rbx2016-g3d/g3dmath.cpp (function ?finf@G3D@@YAMXZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbx2016-g3d g3dmath.cpp
