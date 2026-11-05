// from server: 100% by auto
// roc 2011-06 00551d40  unit: G3D::Sphere  size: 92 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00551d40
//
// 00551d40  8b442404             mov eax, dword ptr [esp + 4]
// 00551d44  f30f104104           movss xmm0, dword ptr [ecx + 4]
// 00551d49  f30f5c00             subss xmm0, dword ptr [eax]
// 00551d4d  f30f10510c           movss xmm2, dword ptr [ecx + 0xc]
// 00551d52  f30f5c5008           subss xmm2, dword ptr [eax + 8]
// 00551d57  f30f104908           movss xmm1, dword ptr [ecx + 8]
// 00551d5c  f30f5c4804           subss xmm1, dword ptr [eax + 4]
// 00551d61  f30f105910           movss xmm3, dword ptr [ecx + 0x10]
// 00551d66  0f28e0               movaps xmm4, xmm0
// 00551d69  f30f59e0             mulss xmm4, xmm0
// 00551d6d  0f28c2               movaps xmm0, xmm2
// 00551d70  f30f59c2             mulss xmm0, xmm2
// 00551d74  f30f58e0             addss xmm4, xmm0
// 00551d78  0f28c1               movaps xmm0, xmm1
// 00551d7b  f30f59c1             mulss xmm0, xmm1
// 00551d7f  f30f58e0             addss xmm4, xmm0
// 00551d83  0f28c3               movaps xmm0, xmm3
// 00551d86  f30f59c3             mulss xmm0, xmm3
// 00551d8a  0f2fc4               comiss xmm0, xmm4
// 00551d8d  7208                 jb 0x551d97
// 00551d8f  b801000000           mov eax, 1
// 00551d94  c20400               ret 4
// 00551d97  33c0                 xor eax, eax
// 00551d99  c20400               ret 4
// library rbx2016-g3d/Sphere.cpp (function ?contains@Sphere@G3D@@QBE_NABVVector3@2@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /arch:SSE2 /fp:fast
// roc-lib: rbx2016-g3d Sphere.cpp
