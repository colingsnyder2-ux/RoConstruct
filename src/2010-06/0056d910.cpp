// from server: 100% by auto
// roc 2010-06 0056d910  unit: seg_00560000  size: 143 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 0056d910
//
// 0056d910  8b442408             mov eax, dword ptr [esp + 8]
// 0056d914  f30f105808           movss xmm3, dword ptr [eax + 8]
// 0056d919  f30f5c590c           subss xmm3, dword ptr [ecx + 0xc]
// 0056d91e  f30f105004           movss xmm2, dword ptr [eax + 4]
// 0056d923  f30f5c5108           subss xmm2, dword ptr [ecx + 8]
// 0056d928  f30f104118           movss xmm0, dword ptr [ecx + 0x18]
// 0056d92d  f30f1008             movss xmm1, dword ptr [eax]
// 0056d931  f30f5c4904           subss xmm1, dword ptr [ecx + 4]
// 0056d936  8b442404             mov eax, dword ptr [esp + 4]
// 0056d93a  f30f59c3             mulss xmm0, xmm3
// 0056d93e  f30f105914           movss xmm3, dword ptr [ecx + 0x14]
// 0056d943  f30f59da             mulss xmm3, xmm2
// 0056d947  f30f105110           movss xmm2, dword ptr [ecx + 0x10]
// 0056d94c  f30f58c3             addss xmm0, xmm3
// 0056d950  f30f105918           movss xmm3, dword ptr [ecx + 0x18]
// 0056d955  f30f59d1             mulss xmm2, xmm1
// 0056d959  f30f104910           movss xmm1, dword ptr [ecx + 0x10]
// 0056d95e  f30f58c2             addss xmm0, xmm2
// 0056d962  f30f105114           movss xmm2, dword ptr [ecx + 0x14]
// 0056d967  f30f59c8             mulss xmm1, xmm0
// 0056d96b  f30f59d0             mulss xmm2, xmm0
// 0056d96f  f30f59d8             mulss xmm3, xmm0
// 0056d973  f30f104104           movss xmm0, dword ptr [ecx + 4]
// 0056d978  f30f58c1             addss xmm0, xmm1
// 0056d97c  f30f1100             movss dword ptr [eax], xmm0
// 0056d980  f30f104108           movss xmm0, dword ptr [ecx + 8]
// 0056d985  f30f58c2             addss xmm0, xmm2
// 0056d989  f30f114004           movss dword ptr [eax + 4], xmm0
// 0056d98e  f30f10410c           movss xmm0, dword ptr [ecx + 0xc]
// 0056d993  f30f58c3             addss xmm0, xmm3
// 0056d997  f30f114008           movss dword ptr [eax + 8], xmm0
// 0056d99c  c20800               ret 8
// library rbx2016-g3d/Line.cpp (function ?closestPoint@Line@G3D@@QBE?AVVector3@2@ABV32@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /arch:SSE2 /fp:fast
// roc-lib: rbx2016-g3d Line.cpp
