// from server: 100% by auto
// roc 2010-06 00490b20  unit: std::D::DU?$char_traits::V?$basic_string::?$Set  size: 157 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00490b20
//
// 00490b20  8b442408             mov eax, dword ptr [esp + 8]
// 00490b24  f30f104804           movss xmm1, dword ptr [eax + 4]
// 00490b29  f30f104008           movss xmm0, dword ptr [eax + 8]
// 00490b2e  f30f1010             movss xmm2, dword ptr [eax]
// 00490b32  f30f105904           movss xmm3, dword ptr [ecx + 4]
// 00490b37  f30f106108           movss xmm4, dword ptr [ecx + 8]
// 00490b3c  8b442404             mov eax, dword ptr [esp + 4]
// 00490b40  f30f59d9             mulss xmm3, xmm1
// 00490b44  f30f59e0             mulss xmm4, xmm0
// 00490b48  f30f58dc             addss xmm3, xmm4
// 00490b4c  0f28e2               movaps xmm4, xmm2
// 00490b4f  f30f5921             mulss xmm4, dword ptr [ecx]
// 00490b53  f30f58dc             addss xmm3, xmm4
// 00490b57  f30f585924           addss xmm3, dword ptr [ecx + 0x24]
// 00490b5c  f30f106110           movss xmm4, dword ptr [ecx + 0x10]
// 00490b61  f30f1118             movss dword ptr [eax], xmm3
// 00490b65  f30f10590c           movss xmm3, dword ptr [ecx + 0xc]
// 00490b6a  f30f59da             mulss xmm3, xmm2
// 00490b6e  f30f59e1             mulss xmm4, xmm1
// 00490b72  f30f58dc             addss xmm3, xmm4
// 00490b76  f30f106114           movss xmm4, dword ptr [ecx + 0x14]
// 00490b7b  f30f59e0             mulss xmm4, xmm0
// 00490b7f  f30f58dc             addss xmm3, xmm4
// 00490b83  f30f585928           addss xmm3, dword ptr [ecx + 0x28]
// 00490b88  f30f115804           movss dword ptr [eax + 4], xmm3
// 00490b8d  f30f105918           movss xmm3, dword ptr [ecx + 0x18]
// 00490b92  f30f59da             mulss xmm3, xmm2
// 00490b96  f30f10511c           movss xmm2, dword ptr [ecx + 0x1c]
// 00490b9b  f30f59d1             mulss xmm2, xmm1
// 00490b9f  f30f104920           movss xmm1, dword ptr [ecx + 0x20]
// 00490ba4  f30f58da             addss xmm3, xmm2
// 00490ba8  f30f59c8             mulss xmm1, xmm0
// 00490bac  f30f58d9             addss xmm3, xmm1
// 00490bb0  f30f58592c           addss xmm3, dword ptr [ecx + 0x2c]
// 00490bb5  f30f115808           movss dword ptr [eax + 8], xmm3
// 00490bba  c20800               ret 8
// library rbx2016-g3d/Capsule.cpp (function ?pointToWorldSpace@CoordinateFrame@G3D@@QBE?AVVector3@2@ABV32@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /arch:SSE2 /fp:fast
// roc-lib: rbx2016-g3d Capsule.cpp
