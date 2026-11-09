// from server: 100% by auto
// roc 2011-06 00552660  unit: G3D::Sphere  size: 86 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00552660
//
// 00552660  53                   push ebx
// 00552661  8b5c2408             mov ebx, dword ptr [esp + 8]
// 00552665  f30f104308           movss xmm0, dword ptr [ebx + 8]
// 0055266a  0f2f4108             comiss xmm0, dword ptr [ecx + 8]
// 0055266e  56                   push esi
// 0055266f  57                   push edi
// 00552670  8d7b08               lea edi, [ebx + 8]
// 00552673  8d7108               lea esi, [ecx + 8]
// 00552676  8bc2                 mov eax, edx
// 00552678  7702                 ja 0x55267c
// 0055267a  8bf7                 mov esi, edi
// 0055267c  f30f100e             movss xmm1, dword ptr [esi]
// 00552680  f30f104304           movss xmm0, dword ptr [ebx + 4]
// 00552685  0f2f4104             comiss xmm0, dword ptr [ecx + 4]
// 00552689  8d7b04               lea edi, [ebx + 4]
// 0055268c  8d7104               lea esi, [ecx + 4]
// 0055268f  7702                 ja 0x552693
// 00552691  8bf7                 mov esi, edi
// 00552693  f30f1013             movss xmm2, dword ptr [ebx]
// 00552697  0f2f11               comiss xmm2, dword ptr [ecx]
// 0055269a  f30f1006             movss xmm0, dword ptr [esi]
// 0055269e  7702                 ja 0x5526a2
// 005526a0  8bcb                 mov ecx, ebx
// 005526a2  d901                 fld dword ptr [ecx]
// 005526a4  5f                   pop edi
// 005526a5  5e                   pop esi
// 005526a6  d918                 fstp dword ptr [eax]
// 005526a8  f30f114004           movss dword ptr [eax + 4], xmm0
// 005526ad  f30f114808           movss dword ptr [eax + 8], xmm1
// 005526b2  5b                   pop ebx
// 005526b3  c20400               ret 4
// library rbx2016-g3d/Box.cpp (function ?min@Vector3@G3D@@QBI?AV12@ABV12@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /arch:SSE2 /fp:fast
// roc-lib: rbx2016-g3d Box.cpp
