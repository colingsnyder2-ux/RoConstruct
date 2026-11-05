// from server: 100% by auto
// roc 2011-06 00541c40  unit: G3D::Sphere  size: 346 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00541c40
//
// 00541c40  83ec1c               sub esp, 0x1c
// 00541c43  56                   push esi
// 00541c44  8b442428             mov eax, dword ptr [esp + 0x28]
// 00541c48  f30f105810           movss xmm3, dword ptr [eax + 0x10]
// 00541c4d  f30f104004           movss xmm0, dword ptr [eax + 4]
// 00541c52  f30f104808           movss xmm1, dword ptr [eax + 8]
// 00541c57  f30f10500c           movss xmm2, dword ptr [eax + 0xc]
// 00541c5c  f30f10610c           movss xmm4, dword ptr [ecx + 0xc]
// 00541c61  f30f59c3             mulss xmm0, xmm3
// 00541c65  f30f5c4124           subss xmm0, dword ptr [ecx + 0x24]
// 00541c6a  f30f59cb             mulss xmm1, xmm3
// 00541c6e  f30f5c4928           subss xmm1, dword ptr [ecx + 0x28]
// 00541c73  f30f59d3             mulss xmm2, xmm3
// 00541c77  f30f5c512c           subss xmm2, dword ptr [ecx + 0x2c]
// 00541c7c  f30f105918           movss xmm3, dword ptr [ecx + 0x18]
// 00541c81  f30f59da             mulss xmm3, xmm2
// 00541c85  f30f59e1             mulss xmm4, xmm1
// 00541c89  f30f58dc             addss xmm3, xmm4
// 00541c8d  f30f1021             movss xmm4, dword ptr [ecx]
// 00541c91  f30f59e0             mulss xmm4, xmm0
// 00541c95  f30f58dc             addss xmm3, xmm4
// 00541c99  f30f115c2408         movss dword ptr [esp + 8], xmm3
// 00541c9f  f30f105904           movss xmm3, dword ptr [ecx + 4]
// 00541ca4  f30f59d8             mulss xmm3, xmm0
// 00541ca8  0f28e2               movaps xmm4, xmm2
// 00541cab  f30f59611c           mulss xmm4, dword ptr [ecx + 0x1c]
// 00541cb0  f30f58dc             addss xmm3, xmm4
// 00541cb4  0f28e1               movaps xmm4, xmm1
// 00541cb7  f30f596110           mulss xmm4, dword ptr [ecx + 0x10]
// 00541cbc  f30f58dc             addss xmm3, xmm4
// 00541cc0  f30f10610c           movss xmm4, dword ptr [ecx + 0xc]
// 00541cc5  f30f115c240c         movss dword ptr [esp + 0xc], xmm3
// 00541ccb  f30f105908           movss xmm3, dword ptr [ecx + 8]
// 00541cd0  f30f59d8             mulss xmm3, xmm0
// 00541cd4  f30f104120           movss xmm0, dword ptr [ecx + 0x20]
// 00541cd9  f30f59c2             mulss xmm0, xmm2
// 00541cdd  f30f105004           movss xmm2, dword ptr [eax + 4]
// 00541ce2  f30f58d8             addss xmm3, xmm0
// 00541ce6  f30f104114           movss xmm0, dword ptr [ecx + 0x14]
// 00541ceb  f30f59c1             mulss xmm0, xmm1
// 00541cef  f30f104808           movss xmm1, dword ptr [eax + 8]
// 00541cf4  f30f58d8             addss xmm3, xmm0
// 00541cf8  f30f10400c           movss xmm0, dword ptr [eax + 0xc]
// 00541cfd  f30f115c2410         movss dword ptr [esp + 0x10], xmm3
// 00541d03  f30f59e1             mulss xmm4, xmm1
// 00541d07  0f28da               movaps xmm3, xmm2
// 00541d0a  f30f5919             mulss xmm3, dword ptr [ecx]
// 00541d0e  f30f58dc             addss xmm3, xmm4
// 00541d12  f30f106118           movss xmm4, dword ptr [ecx + 0x18]
// 00541d17  f30f59e0             mulss xmm4, xmm0
// 00541d1b  f30f58dc             addss xmm3, xmm4
// 00541d1f  f30f115c2414         movss dword ptr [esp + 0x14], xmm3
// 00541d25  0f28da               movaps xmm3, xmm2
// 00541d28  f30f595904           mulss xmm3, dword ptr [ecx + 4]
// 00541d2d  0f28e1               movaps xmm4, xmm1
// 00541d30  f30f596110           mulss xmm4, dword ptr [ecx + 0x10]
// 00541d35  f30f58dc             addss xmm3, xmm4
// 00541d39  0f28e0               movaps xmm4, xmm0
// 00541d3c  f30f59611c           mulss xmm4, dword ptr [ecx + 0x1c]
// 00541d41  f30f58dc             addss xmm3, xmm4
// 00541d45  f30f115c2418         movss dword ptr [esp + 0x18], xmm3
// 00541d4b  f30f105908           movss xmm3, dword ptr [ecx + 8]
// 00541d50  f30f59da             mulss xmm3, xmm2
// 00541d54  f30f105114           movss xmm2, dword ptr [ecx + 0x14]
// 00541d59  8b742424             mov esi, dword ptr [esp + 0x24]
// 00541d5d  f30f59d1             mulss xmm2, xmm1
// 00541d61  f30f104920           movss xmm1, dword ptr [ecx + 0x20]
// 00541d66  8d442408             lea eax, [esp + 8]
// 00541d6a  50                   push eax
// 00541d6b  8d4c2418             lea ecx, [esp + 0x18]
// 00541d6f  f30f58da             addss xmm3, xmm2
// 00541d73  f30f59c8             mulss xmm1, xmm0
// 00541d77  51                   push ecx
// 00541d78  f30f58d9             addss xmm3, xmm1
// 00541d7c  8bce                 mov ecx, esi
// 00541d7e  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 00541d86  f30f115c2424         movss dword ptr [esp + 0x24], xmm3
// 00541d8c  e85f070100           call 0x5524f0
// 00541d91  8bc6                 mov eax, esi
// 00541d93  5e                   pop esi
// 00541d94  83c41c               add esp, 0x1c
// 00541d97  c20800               ret 8
// library rbx2016-g3d/CoordinateFrame.cpp (function ?toObjectSpace@CoordinateFrame@G3D@@QBE?AVPlane@2@ABV32@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /arch:SSE2 /fp:fast
// roc-lib: rbx2016-g3d CoordinateFrame.cpp
