// from server: 100% by auto
// roc 2011-06 0053ff20  unit: G3D::MemoryManager  size: 99 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 0053ff20
//
// 0053ff20  f30f106908           movss xmm5, dword ptr [ecx + 8]
// 0053ff25  f30f105904           movss xmm3, dword ptr [ecx + 4]
// 0053ff2a  8bc2                 mov eax, edx
// 0053ff2c  8b542404             mov edx, dword ptr [esp + 4]
// 0053ff30  f30f105208           movss xmm2, dword ptr [edx + 8]
// 0053ff35  f30f106204           movss xmm4, dword ptr [edx + 4]
// 0053ff3a  0f28cd               movaps xmm1, xmm5
// 0053ff3d  f30f59cc             mulss xmm1, xmm4
// 0053ff41  0f28c3               movaps xmm0, xmm3
// 0053ff44  f30f59c2             mulss xmm0, xmm2
// 0053ff48  f30f5cc1             subss xmm0, xmm1
// 0053ff4c  f30f100a             movss xmm1, dword ptr [edx]
// 0053ff50  f30f1100             movss dword ptr [eax], xmm0
// 0053ff54  f30f1001             movss xmm0, dword ptr [ecx]
// 0053ff58  0f28f1               movaps xmm6, xmm1
// 0053ff5b  f30f59f5             mulss xmm6, xmm5
// 0053ff5f  0f28e8               movaps xmm5, xmm0
// 0053ff62  f30f59ea             mulss xmm5, xmm2
// 0053ff66  f30f59c4             mulss xmm0, xmm4
// 0053ff6a  f30f59cb             mulss xmm1, xmm3
// 0053ff6e  f30f5cf5             subss xmm6, xmm5
// 0053ff72  f30f5cc1             subss xmm0, xmm1
// 0053ff76  f30f117004           movss dword ptr [eax + 4], xmm6
// 0053ff7b  f30f114008           movss dword ptr [eax + 8], xmm0
// 0053ff80  c20400               ret 4
// library rbx2016-g3d/Capsule.cpp (function ?cross@Vector3@G3D@@QBI?AV12@ABV12@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /arch:SSE2 /fp:fast
// roc-lib: rbx2016-g3d Capsule.cpp
