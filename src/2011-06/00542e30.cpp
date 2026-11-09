// from server: 100% by auto
// roc 2011-06 00542e30  unit: G3D::Sphere  size: 8 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00542e30
//
// 00542e30  a16c05a400           mov eax, dword ptr [0xa4056c]
// 00542e35  d900                 fld dword ptr [eax]
// 00542e37  c3                   ret 
// library rbx2016-g3d/g3dmath.cpp (function ?finf@G3D@@YAMXZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbx2016-g3d g3dmath.cpp
