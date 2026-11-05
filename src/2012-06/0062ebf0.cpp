// from server: 100% by auto
// roc 2012-06 0062ebf0  unit: G3D::Line  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0062ebf0
//
// 0062ebf0  8b442404             mov eax, dword ptr [esp + 4]
// 0062ebf4  f30f1001             movss xmm0, dword ptr [ecx]
// 0062ebf8  f30f1100             movss dword ptr [eax], xmm0
// 0062ebfc  f30f114004           movss dword ptr [eax + 4], xmm0
// 0062ec01  f30f114008           movss dword ptr [eax + 8], xmm0
// 0062ec06  c20400               ret 4
// library rbx2016-g3d/Vector2.cpp (function ?xxx@Vector2@G3D@@QBE?AVVector3@2@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /arch:SSE2 /fp:fast
// roc-lib: rbx2016-g3d Vector2.cpp
