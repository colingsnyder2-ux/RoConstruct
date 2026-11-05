// from server: 100% by auto
// roc 2011-06 00542be0  unit: G3D::Sphere  size: 25 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00542be0
//
// 00542be0  8b442404             mov eax, dword ptr [esp + 4]
// 00542be4  f30f1001             movss xmm0, dword ptr [ecx]
// 00542be8  f30f1100             movss dword ptr [eax], xmm0
// 00542bec  f30f114004           movss dword ptr [eax + 4], xmm0
// 00542bf1  f30f114008           movss dword ptr [eax + 8], xmm0
// 00542bf6  c20400               ret 4
// library rbx2016-g3d/Vector2.cpp (function ?xxx@Vector2@G3D@@QBE?AVVector3@2@XZ)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /arch:SSE2 /fp:fast
// roc-lib: rbx2016-g3d Vector2.cpp
