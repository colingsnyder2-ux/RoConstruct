// from server: 100% by auto
// roc 2012-06 004d7650  unit: Ogre::RbxSceneManagerFactory  size: 86 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 004d7650
//
// 004d7650  53                   push ebx
// 004d7651  8b5c2408             mov ebx, dword ptr [esp + 8]
// 004d7655  f30f104308           movss xmm0, dword ptr [ebx + 8]
// 004d765a  0f2f4108             comiss xmm0, dword ptr [ecx + 8]
// 004d765e  56                   push esi
// 004d765f  57                   push edi
// 004d7660  8d7b08               lea edi, [ebx + 8]
// 004d7663  8d7108               lea esi, [ecx + 8]
// 004d7666  8bc2                 mov eax, edx
// 004d7668  7702                 ja 0x4d766c
// 004d766a  8bf7                 mov esi, edi
// 004d766c  f30f100e             movss xmm1, dword ptr [esi]
// 004d7670  f30f104304           movss xmm0, dword ptr [ebx + 4]
// 004d7675  0f2f4104             comiss xmm0, dword ptr [ecx + 4]
// 004d7679  8d7b04               lea edi, [ebx + 4]
// 004d767c  8d7104               lea esi, [ecx + 4]
// 004d767f  7702                 ja 0x4d7683
// 004d7681  8bf7                 mov esi, edi
// 004d7683  f30f1013             movss xmm2, dword ptr [ebx]
// 004d7687  0f2f11               comiss xmm2, dword ptr [ecx]
// 004d768a  f30f1006             movss xmm0, dword ptr [esi]
// 004d768e  7702                 ja 0x4d7692
// 004d7690  8bcb                 mov ecx, ebx
// 004d7692  d901                 fld dword ptr [ecx]
// 004d7694  5f                   pop edi
// 004d7695  5e                   pop esi
// 004d7696  d918                 fstp dword ptr [eax]
// 004d7698  f30f114004           movss dword ptr [eax + 4], xmm0
// 004d769d  f30f114808           movss dword ptr [eax + 8], xmm1
// 004d76a2  5b                   pop ebx
// 004d76a3  c20400               ret 4
// library rbx2016-g3d/Box.cpp (function ?min@Vector3@G3D@@QBI?AV12@ABV12@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /arch:SSE2 /fp:fast
// roc-lib: rbx2016-g3d Box.cpp
