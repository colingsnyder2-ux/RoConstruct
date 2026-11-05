// from server: 100% by auto
// roc 2012-06 0063f680  unit: G3D::Sphere  size: 143 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0063f680
//
// 0063f680  8b442408             mov eax, dword ptr [esp + 8]
// 0063f684  f30f105808           movss xmm3, dword ptr [eax + 8]
// 0063f689  f30f5c590c           subss xmm3, dword ptr [ecx + 0xc]
// 0063f68e  f30f105004           movss xmm2, dword ptr [eax + 4]
// 0063f693  f30f5c5108           subss xmm2, dword ptr [ecx + 8]
// 0063f698  f30f104118           movss xmm0, dword ptr [ecx + 0x18]
// 0063f69d  f30f1008             movss xmm1, dword ptr [eax]
// 0063f6a1  f30f5c4904           subss xmm1, dword ptr [ecx + 4]
// 0063f6a6  8b442404             mov eax, dword ptr [esp + 4]
// 0063f6aa  f30f59c3             mulss xmm0, xmm3
// 0063f6ae  f30f105914           movss xmm3, dword ptr [ecx + 0x14]
// 0063f6b3  f30f59da             mulss xmm3, xmm2
// 0063f6b7  f30f105110           movss xmm2, dword ptr [ecx + 0x10]
// 0063f6bc  f30f58c3             addss xmm0, xmm3
// 0063f6c0  f30f105918           movss xmm3, dword ptr [ecx + 0x18]
// 0063f6c5  f30f59d1             mulss xmm2, xmm1
// 0063f6c9  f30f104910           movss xmm1, dword ptr [ecx + 0x10]
// 0063f6ce  f30f58c2             addss xmm0, xmm2
// 0063f6d2  f30f105114           movss xmm2, dword ptr [ecx + 0x14]
// 0063f6d7  f30f59c8             mulss xmm1, xmm0
// 0063f6db  f30f59d0             mulss xmm2, xmm0
// 0063f6df  f30f59d8             mulss xmm3, xmm0
// 0063f6e3  f30f104104           movss xmm0, dword ptr [ecx + 4]
// 0063f6e8  f30f58c1             addss xmm0, xmm1
// 0063f6ec  f30f1100             movss dword ptr [eax], xmm0
// 0063f6f0  f30f104108           movss xmm0, dword ptr [ecx + 8]
// 0063f6f5  f30f58c2             addss xmm0, xmm2
// 0063f6f9  f30f114004           movss dword ptr [eax + 4], xmm0
// 0063f6fe  f30f10410c           movss xmm0, dword ptr [ecx + 0xc]
// 0063f703  f30f58c3             addss xmm0, xmm3
// 0063f707  f30f114008           movss dword ptr [eax + 8], xmm0
// 0063f70c  c20800               ret 8
// library rbx2016-g3d/Line.cpp (function ?closestPoint@Line@G3D@@QBE?AVVector3@2@ABV32@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /arch:SSE2 /fp:fast
// roc-lib: rbx2016-g3d Line.cpp
