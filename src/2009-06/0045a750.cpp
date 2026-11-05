// from server: 100% by auto
// roc 2009-06 0045a750  unit: RBX::VInstance::?$NonFactoryProduct  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2009-06 0045a750
//
// 0045a750  d94108               fld dword ptr [ecx + 8]
// 0045a753  d94104               fld dword ptr [ecx + 4]
// 0045a756  d901                 fld dword ptr [ecx]
// 0045a758  dcc8                 fmul st(0), st(0)
// 0045a75a  d9c1                 fld st(1)
// 0045a75c  deca                 fmulp st(2)
// 0045a75e  dec1                 faddp st(1)
// 0045a760  d9c1                 fld st(1)
// 0045a762  deca                 fmulp st(2)
// 0045a764  dec1                 faddp st(1)
// 0045a766  d9fa                 fsqrt 
// 0045a768  c3                   ret 
// library rbx2016-g3d/Capsule.cpp (function ?magnitude@Vector3@G3D@@QBEMXZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /arch:SSE2 /fp:fast
// roc-lib: rbx2016-g3d Capsule.cpp
