// from server: 100% by auto
// roc 2012-06 004c1670  unit: RBX::?1??ViewRbxGfx_InitModule::ViewRbxGfxFactory  size: 51 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 004c1670
//
// 004c1670  f30f1001             movss xmm0, dword ptr [ecx]
// 004c1674  8bc2                 mov eax, edx
// 004c1676  8b542404             mov edx, dword ptr [esp + 4]
// 004c167a  f30f5c02             subss xmm0, dword ptr [edx]
// 004c167e  f30f1100             movss dword ptr [eax], xmm0
// 004c1682  f30f104104           movss xmm0, dword ptr [ecx + 4]
// 004c1687  f30f5c4204           subss xmm0, dword ptr [edx + 4]
// 004c168c  f30f114004           movss dword ptr [eax + 4], xmm0
// 004c1691  f30f104108           movss xmm0, dword ptr [ecx + 8]
// 004c1696  f30f5c4208           subss xmm0, dword ptr [edx + 8]
// 004c169b  f30f114008           movss dword ptr [eax + 8], xmm0
// 004c16a0  c20400               ret 4
// library rbx2016-g3d/AABox.cpp (function ??GVector3@G3D@@QBI?AV01@ABV01@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /arch:SSE2 /fp:fast
// roc-lib: rbx2016-g3d AABox.cpp
