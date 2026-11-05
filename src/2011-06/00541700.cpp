// from server: 100% by auto
// roc 2011-06 00541700  unit: G3D::Sphere  size: 157 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00541700
//
// 00541700  8b442408             mov eax, dword ptr [esp + 8]
// 00541704  f30f104804           movss xmm1, dword ptr [eax + 4]
// 00541709  f30f104008           movss xmm0, dword ptr [eax + 8]
// 0054170e  f30f1010             movss xmm2, dword ptr [eax]
// 00541712  f30f105904           movss xmm3, dword ptr [ecx + 4]
// 00541717  f30f106108           movss xmm4, dword ptr [ecx + 8]
// 0054171c  8b442404             mov eax, dword ptr [esp + 4]
// 00541720  f30f59d9             mulss xmm3, xmm1
// 00541724  f30f59e0             mulss xmm4, xmm0
// 00541728  f30f58dc             addss xmm3, xmm4
// 0054172c  0f28e2               movaps xmm4, xmm2
// 0054172f  f30f5921             mulss xmm4, dword ptr [ecx]
// 00541733  f30f58dc             addss xmm3, xmm4
// 00541737  f30f585924           addss xmm3, dword ptr [ecx + 0x24]
// 0054173c  f30f106110           movss xmm4, dword ptr [ecx + 0x10]
// 00541741  f30f1118             movss dword ptr [eax], xmm3
// 00541745  f30f10590c           movss xmm3, dword ptr [ecx + 0xc]
// 0054174a  f30f59da             mulss xmm3, xmm2
// 0054174e  f30f59e1             mulss xmm4, xmm1
// 00541752  f30f58dc             addss xmm3, xmm4
// 00541756  f30f106114           movss xmm4, dword ptr [ecx + 0x14]
// 0054175b  f30f59e0             mulss xmm4, xmm0
// 0054175f  f30f58dc             addss xmm3, xmm4
// 00541763  f30f585928           addss xmm3, dword ptr [ecx + 0x28]
// 00541768  f30f115804           movss dword ptr [eax + 4], xmm3
// 0054176d  f30f105918           movss xmm3, dword ptr [ecx + 0x18]
// 00541772  f30f59da             mulss xmm3, xmm2
// 00541776  f30f10511c           movss xmm2, dword ptr [ecx + 0x1c]
// 0054177b  f30f59d1             mulss xmm2, xmm1
// 0054177f  f30f104920           movss xmm1, dword ptr [ecx + 0x20]
// 00541784  f30f58da             addss xmm3, xmm2
// 00541788  f30f59c8             mulss xmm1, xmm0
// 0054178c  f30f58d9             addss xmm3, xmm1
// 00541790  f30f58592c           addss xmm3, dword ptr [ecx + 0x2c]
// 00541795  f30f115808           movss dword ptr [eax + 8], xmm3
// 0054179a  c20800               ret 8
// library rbx2016-g3d/Capsule.cpp (function ?pointToWorldSpace@CoordinateFrame@G3D@@QBE?AVVector3@2@ABV32@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /arch:SSE2 /fp:fast
// roc-lib: rbx2016-g3d Capsule.cpp
