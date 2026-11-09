// from server: 100% by auto
// roc 2012-06 004c16f0  unit: RBX::?1??ViewRbxGfx_InitModule::ViewRbxGfxFactory  size: 99 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 004c16f0
//
// 004c16f0  f30f106908           movss xmm5, dword ptr [ecx + 8]
// 004c16f5  f30f105904           movss xmm3, dword ptr [ecx + 4]
// 004c16fa  8bc2                 mov eax, edx
// 004c16fc  8b542404             mov edx, dword ptr [esp + 4]
// 004c1700  f30f105208           movss xmm2, dword ptr [edx + 8]
// 004c1705  f30f106204           movss xmm4, dword ptr [edx + 4]
// 004c170a  0f28cd               movaps xmm1, xmm5
// 004c170d  f30f59cc             mulss xmm1, xmm4
// 004c1711  0f28c3               movaps xmm0, xmm3
// 004c1714  f30f59c2             mulss xmm0, xmm2
// 004c1718  f30f5cc1             subss xmm0, xmm1
// 004c171c  f30f100a             movss xmm1, dword ptr [edx]
// 004c1720  f30f1100             movss dword ptr [eax], xmm0
// 004c1724  f30f1001             movss xmm0, dword ptr [ecx]
// 004c1728  0f28f1               movaps xmm6, xmm1
// 004c172b  f30f59f5             mulss xmm6, xmm5
// 004c172f  0f28e8               movaps xmm5, xmm0
// 004c1732  f30f59ea             mulss xmm5, xmm2
// 004c1736  f30f59c4             mulss xmm0, xmm4
// 004c173a  f30f59cb             mulss xmm1, xmm3
// 004c173e  f30f5cf5             subss xmm6, xmm5
// 004c1742  f30f5cc1             subss xmm0, xmm1
// 004c1746  f30f117004           movss dword ptr [eax + 4], xmm6
// 004c174b  f30f114008           movss dword ptr [eax + 8], xmm0
// 004c1750  c20400               ret 4
// library rbx2016-g3d/Capsule.cpp (function ?cross@Vector3@G3D@@QBI?AV12@ABV12@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /arch:SSE2 /fp:fast
// roc-lib: rbx2016-g3d Capsule.cpp
