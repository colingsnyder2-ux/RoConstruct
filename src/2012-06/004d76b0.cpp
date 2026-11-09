// from server: 100% by auto
// roc 2012-06 004d76b0  unit: Ogre::RbxSceneManagerFactory  size: 86 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 004d76b0
//
// 004d76b0  f30f104108           movss xmm0, dword ptr [ecx + 8]
// 004d76b5  53                   push ebx
// 004d76b6  8b5c2408             mov ebx, dword ptr [esp + 8]
// 004d76ba  0f2f4308             comiss xmm0, dword ptr [ebx + 8]
// 004d76be  56                   push esi
// 004d76bf  57                   push edi
// 004d76c0  8d7108               lea esi, [ecx + 8]
// 004d76c3  8d7b08               lea edi, [ebx + 8]
// 004d76c6  8bc2                 mov eax, edx
// 004d76c8  7702                 ja 0x4d76cc
// 004d76ca  8bf7                 mov esi, edi
// 004d76cc  f30f100e             movss xmm1, dword ptr [esi]
// 004d76d0  f30f104104           movss xmm0, dword ptr [ecx + 4]
// 004d76d5  0f2f4304             comiss xmm0, dword ptr [ebx + 4]
// 004d76d9  8d7104               lea esi, [ecx + 4]
// 004d76dc  8d7b04               lea edi, [ebx + 4]
// 004d76df  7702                 ja 0x4d76e3
// 004d76e1  8bf7                 mov esi, edi
// 004d76e3  f30f1011             movss xmm2, dword ptr [ecx]
// 004d76e7  0f2f13               comiss xmm2, dword ptr [ebx]
// 004d76ea  f30f1006             movss xmm0, dword ptr [esi]
// 004d76ee  7702                 ja 0x4d76f2
// 004d76f0  8bcb                 mov ecx, ebx
// 004d76f2  d901                 fld dword ptr [ecx]
// 004d76f4  5f                   pop edi
// 004d76f5  5e                   pop esi
// 004d76f6  d918                 fstp dword ptr [eax]
// 004d76f8  f30f114004           movss dword ptr [eax + 4], xmm0
// 004d76fd  f30f114808           movss dword ptr [eax + 8], xmm1
// 004d7702  5b                   pop ebx
// 004d7703  c20400               ret 4
// library rbx2016-g3d/Box.cpp (function ?max@Vector3@G3D@@QBI?AV12@ABV12@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /arch:SSE2 /fp:fast
// roc-lib: rbx2016-g3d Box.cpp
