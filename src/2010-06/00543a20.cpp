// from server: 100% by auto
// roc 2010-06 00543a20  unit: RBX::AggregatingSceneManager  size: 158 bytes
// Make this compile to the exact bytes below, then: roc check 2010-06 00543a20
//
// 00543a20  8b442408             mov eax, dword ptr [esp + 8]
// 00543a24  f30f104804           movss xmm1, dword ptr [eax + 4]
// 00543a29  f30f5c4928           subss xmm1, dword ptr [ecx + 0x28]
// 00543a2e  f30f105008           movss xmm2, dword ptr [eax + 8]
// 00543a33  f30f5c512c           subss xmm2, dword ptr [ecx + 0x2c]
// 00543a38  f30f105918           movss xmm3, dword ptr [ecx + 0x18]
// 00543a3d  f30f10610c           movss xmm4, dword ptr [ecx + 0xc]
// 00543a42  f30f1000             movss xmm0, dword ptr [eax]
// 00543a46  f30f5c4124           subss xmm0, dword ptr [ecx + 0x24]
// 00543a4b  8b442404             mov eax, dword ptr [esp + 4]
// 00543a4f  f30f59da             mulss xmm3, xmm2
// 00543a53  f30f59e1             mulss xmm4, xmm1
// 00543a57  f30f58dc             addss xmm3, xmm4
// 00543a5b  f30f1021             movss xmm4, dword ptr [ecx]
// 00543a5f  f30f59e0             mulss xmm4, xmm0
// 00543a63  f30f58dc             addss xmm3, xmm4
// 00543a67  f30f106110           movss xmm4, dword ptr [ecx + 0x10]
// 00543a6c  f30f1118             movss dword ptr [eax], xmm3
// 00543a70  f30f10591c           movss xmm3, dword ptr [ecx + 0x1c]
// 00543a75  f30f59da             mulss xmm3, xmm2
// 00543a79  f30f59e1             mulss xmm4, xmm1
// 00543a7d  f30f58dc             addss xmm3, xmm4
// 00543a81  f30f106104           movss xmm4, dword ptr [ecx + 4]
// 00543a86  f30f59e0             mulss xmm4, xmm0
// 00543a8a  f30f58dc             addss xmm3, xmm4
// 00543a8e  f30f115804           movss dword ptr [eax + 4], xmm3
// 00543a93  f30f105920           movss xmm3, dword ptr [ecx + 0x20]
// 00543a98  f30f59da             mulss xmm3, xmm2
// 00543a9c  f30f105114           movss xmm2, dword ptr [ecx + 0x14]
// 00543aa1  f30f59d1             mulss xmm2, xmm1
// 00543aa5  f30f104908           movss xmm1, dword ptr [ecx + 8]
// 00543aaa  f30f58da             addss xmm3, xmm2
// 00543aae  f30f59c8             mulss xmm1, xmm0
// 00543ab2  f30f58d9             addss xmm3, xmm1
// 00543ab6  f30f115808           movss dword ptr [eax + 8], xmm3
// 00543abb  c20800               ret 8
// library rbx2016-g3d/CollisionDetection.cpp (function ?pointToObjectSpace@CoordinateFrame@G3D@@QBE?AVVector3@2@ABV32@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /arch:SSE2 /fp:fast
// roc-lib: rbx2016-g3d CollisionDetection.cpp
