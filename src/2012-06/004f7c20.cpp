// from server: 100% by auto
// roc 2012-06 004f7c20  unit: Ogre::RbxMeshPartAdapter  size: 158 bytes
// Make this compile to the exact bytes below, then: roc check 2012-06 004f7c20
//
// 004f7c20  8b442408             mov eax, dword ptr [esp + 8]
// 004f7c24  f30f104804           movss xmm1, dword ptr [eax + 4]
// 004f7c29  f30f5c4928           subss xmm1, dword ptr [ecx + 0x28]
// 004f7c2e  f30f105008           movss xmm2, dword ptr [eax + 8]
// 004f7c33  f30f5c512c           subss xmm2, dword ptr [ecx + 0x2c]
// 004f7c38  f30f105918           movss xmm3, dword ptr [ecx + 0x18]
// 004f7c3d  f30f10610c           movss xmm4, dword ptr [ecx + 0xc]
// 004f7c42  f30f1000             movss xmm0, dword ptr [eax]
// 004f7c46  f30f5c4124           subss xmm0, dword ptr [ecx + 0x24]
// 004f7c4b  8b442404             mov eax, dword ptr [esp + 4]
// 004f7c4f  f30f59da             mulss xmm3, xmm2
// 004f7c53  f30f59e1             mulss xmm4, xmm1
// 004f7c57  f30f58dc             addss xmm3, xmm4
// 004f7c5b  f30f1021             movss xmm4, dword ptr [ecx]
// 004f7c5f  f30f59e0             mulss xmm4, xmm0
// 004f7c63  f30f58dc             addss xmm3, xmm4
// 004f7c67  f30f106110           movss xmm4, dword ptr [ecx + 0x10]
// 004f7c6c  f30f1118             movss dword ptr [eax], xmm3
// 004f7c70  f30f10591c           movss xmm3, dword ptr [ecx + 0x1c]
// 004f7c75  f30f59da             mulss xmm3, xmm2
// 004f7c79  f30f59e1             mulss xmm4, xmm1
// 004f7c7d  f30f58dc             addss xmm3, xmm4
// 004f7c81  f30f106104           movss xmm4, dword ptr [ecx + 4]
// 004f7c86  f30f59e0             mulss xmm4, xmm0
// 004f7c8a  f30f58dc             addss xmm3, xmm4
// 004f7c8e  f30f115804           movss dword ptr [eax + 4], xmm3
// 004f7c93  f30f105920           movss xmm3, dword ptr [ecx + 0x20]
// 004f7c98  f30f59da             mulss xmm3, xmm2
// 004f7c9c  f30f105114           movss xmm2, dword ptr [ecx + 0x14]
// 004f7ca1  f30f59d1             mulss xmm2, xmm1
// 004f7ca5  f30f104908           movss xmm1, dword ptr [ecx + 8]
// 004f7caa  f30f58da             addss xmm3, xmm2
// 004f7cae  f30f59c8             mulss xmm1, xmm0
// 004f7cb2  f30f58d9             addss xmm3, xmm1
// 004f7cb6  f30f115808           movss dword ptr [eax + 8], xmm3
// 004f7cbb  c20800               ret 8
// library rbx2016-g3d/CollisionDetection.cpp (function ?pointToObjectSpace@CoordinateFrame@G3D@@QBE?AVVector3@2@ABV32@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /arch:SSE2 /fp:fast
// roc-lib: rbx2016-g3d CollisionDetection.cpp
