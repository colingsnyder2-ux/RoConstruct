// from server: 100% by auto
// roc 2011-06 00542e40  unit: G3D::Sphere  size: 8 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00542e40
//
// 00542e40  a17005a400           mov eax, dword ptr [0xa40570]
// 00542e45  dd00                 fld qword ptr [eax]
// 00542e47  c3                   ret 
// library rbx2016-g3d/g3dmath.cpp (function ?inf@G3D@@YANXZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD
// roc-lib: rbx2016-g3d g3dmath.cpp
