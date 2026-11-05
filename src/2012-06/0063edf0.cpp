// from server: 100% by auto
// roc 2012-06 0063edf0  unit: G3D::Sphere  size: 92 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 0063edf0
//
// 0063edf0  8b442404             mov eax, dword ptr [esp + 4]
// 0063edf4  f30f104104           movss xmm0, dword ptr [ecx + 4]
// 0063edf9  f30f5c00             subss xmm0, dword ptr [eax]
// 0063edfd  f30f10510c           movss xmm2, dword ptr [ecx + 0xc]
// 0063ee02  f30f5c5008           subss xmm2, dword ptr [eax + 8]
// 0063ee07  f30f104908           movss xmm1, dword ptr [ecx + 8]
// 0063ee0c  f30f5c4804           subss xmm1, dword ptr [eax + 4]
// 0063ee11  f30f105910           movss xmm3, dword ptr [ecx + 0x10]
// 0063ee16  0f28e0               movaps xmm4, xmm0
// 0063ee19  f30f59e0             mulss xmm4, xmm0
// 0063ee1d  0f28c2               movaps xmm0, xmm2
// 0063ee20  f30f59c2             mulss xmm0, xmm2
// 0063ee24  f30f58e0             addss xmm4, xmm0
// 0063ee28  0f28c1               movaps xmm0, xmm1
// 0063ee2b  f30f59c1             mulss xmm0, xmm1
// 0063ee2f  f30f58e0             addss xmm4, xmm0
// 0063ee33  0f28c3               movaps xmm0, xmm3
// 0063ee36  f30f59c3             mulss xmm0, xmm3
// 0063ee3a  0f2fc4               comiss xmm0, xmm4
// 0063ee3d  7208                 jb 0x63ee47
// 0063ee3f  b801000000           mov eax, 1
// 0063ee44  c20400               ret 4
// 0063ee47  33c0                 xor eax, eax
// 0063ee49  c20400               ret 4
// library rbx2016-g3d/Sphere.cpp (function ?contains@Sphere@G3D@@QBE_NABVVector3@2@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /arch:SSE2 /fp:fast
// roc-lib: rbx2016-g3d Sphere.cpp
