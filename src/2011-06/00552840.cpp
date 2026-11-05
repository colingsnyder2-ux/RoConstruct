// from server: 100% by auto
// roc 2011-06 00552840  unit: G3D::Sphere  size: 143 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00552840
//
// 00552840  8b442408             mov eax, dword ptr [esp + 8]
// 00552844  f30f105808           movss xmm3, dword ptr [eax + 8]
// 00552849  f30f5c590c           subss xmm3, dword ptr [ecx + 0xc]
// 0055284e  f30f105004           movss xmm2, dword ptr [eax + 4]
// 00552853  f30f5c5108           subss xmm2, dword ptr [ecx + 8]
// 00552858  f30f104118           movss xmm0, dword ptr [ecx + 0x18]
// 0055285d  f30f1008             movss xmm1, dword ptr [eax]
// 00552861  f30f5c4904           subss xmm1, dword ptr [ecx + 4]
// 00552866  8b442404             mov eax, dword ptr [esp + 4]
// 0055286a  f30f59c3             mulss xmm0, xmm3
// 0055286e  f30f105914           movss xmm3, dword ptr [ecx + 0x14]
// 00552873  f30f59da             mulss xmm3, xmm2
// 00552877  f30f105110           movss xmm2, dword ptr [ecx + 0x10]
// 0055287c  f30f58c3             addss xmm0, xmm3
// 00552880  f30f105918           movss xmm3, dword ptr [ecx + 0x18]
// 00552885  f30f59d1             mulss xmm2, xmm1
// 00552889  f30f104910           movss xmm1, dword ptr [ecx + 0x10]
// 0055288e  f30f58c2             addss xmm0, xmm2
// 00552892  f30f105114           movss xmm2, dword ptr [ecx + 0x14]
// 00552897  f30f59c8             mulss xmm1, xmm0
// 0055289b  f30f59d0             mulss xmm2, xmm0
// 0055289f  f30f59d8             mulss xmm3, xmm0
// 005528a3  f30f104104           movss xmm0, dword ptr [ecx + 4]
// 005528a8  f30f58c1             addss xmm0, xmm1
// 005528ac  f30f1100             movss dword ptr [eax], xmm0
// 005528b0  f30f104108           movss xmm0, dword ptr [ecx + 8]
// 005528b5  f30f58c2             addss xmm0, xmm2
// 005528b9  f30f114004           movss dword ptr [eax + 4], xmm0
// 005528be  f30f10410c           movss xmm0, dword ptr [ecx + 0xc]
// 005528c3  f30f58c3             addss xmm0, xmm3
// 005528c7  f30f114008           movss dword ptr [eax + 8], xmm0
// 005528cc  c20800               ret 8
// library rbx2016-g3d/Line.cpp (function ?closestPoint@Line@G3D@@QBE?AVVector3@2@ABV32@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /arch:SSE2 /fp:fast
// roc-lib: rbx2016-g3d Line.cpp
