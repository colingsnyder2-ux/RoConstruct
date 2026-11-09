// from server: 100% by auto
// roc 2008-06 0045b310  unit: CRobloxWnd  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2008-06 0045b310
//
// 0045b310  d94108               fld dword ptr [ecx + 8]
// 0045b313  d94104               fld dword ptr [ecx + 4]
// 0045b316  d901                 fld dword ptr [ecx]
// 0045b318  dcc8                 fmul st(0), st(0)
// 0045b31a  d9c1                 fld st(1)
// 0045b31c  deca                 fmulp st(2)
// 0045b31e  dec1                 faddp st(1)
// 0045b320  d9c1                 fld st(1)
// 0045b322  deca                 fmulp st(2)
// 0045b324  dec1                 faddp st(1)
// 0045b326  d9fa                 fsqrt 
// 0045b328  c3                   ret 
// library rbx2016-g3d/Capsule.cpp (function ?magnitude@Vector3@G3D@@QBEMXZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /arch:SSE2 /fp:fast
// roc-lib: rbx2016-g3d Capsule.cpp
