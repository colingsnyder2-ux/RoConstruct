// from server: 100% by auto
// roc 2011-06 005526c0  unit: G3D::Sphere  size: 86 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 005526c0
//
// 005526c0  f30f104108           movss xmm0, dword ptr [ecx + 8]
// 005526c5  53                   push ebx
// 005526c6  8b5c2408             mov ebx, dword ptr [esp + 8]
// 005526ca  0f2f4308             comiss xmm0, dword ptr [ebx + 8]
// 005526ce  56                   push esi
// 005526cf  57                   push edi
// 005526d0  8d7108               lea esi, [ecx + 8]
// 005526d3  8d7b08               lea edi, [ebx + 8]
// 005526d6  8bc2                 mov eax, edx
// 005526d8  7702                 ja 0x5526dc
// 005526da  8bf7                 mov esi, edi
// 005526dc  f30f100e             movss xmm1, dword ptr [esi]
// 005526e0  f30f104104           movss xmm0, dword ptr [ecx + 4]
// 005526e5  0f2f4304             comiss xmm0, dword ptr [ebx + 4]
// 005526e9  8d7104               lea esi, [ecx + 4]
// 005526ec  8d7b04               lea edi, [ebx + 4]
// 005526ef  7702                 ja 0x5526f3
// 005526f1  8bf7                 mov esi, edi
// 005526f3  f30f1011             movss xmm2, dword ptr [ecx]
// 005526f7  0f2f13               comiss xmm2, dword ptr [ebx]
// 005526fa  f30f1006             movss xmm0, dword ptr [esi]
// 005526fe  7702                 ja 0x552702
// 00552700  8bcb                 mov ecx, ebx
// 00552702  d901                 fld dword ptr [ecx]
// 00552704  5f                   pop edi
// 00552705  5e                   pop esi
// 00552706  d918                 fstp dword ptr [eax]
// 00552708  f30f114004           movss dword ptr [eax + 4], xmm0
// 0055270d  f30f114808           movss dword ptr [eax + 8], xmm1
// 00552712  5b                   pop ebx
// 00552713  c20400               ret 4
// library rbx2016-g3d/Box.cpp (function ?max@Vector3@G3D@@QBI?AV12@ABV12@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /arch:SSE2 /fp:fast
// roc-lib: rbx2016-g3d Box.cpp
