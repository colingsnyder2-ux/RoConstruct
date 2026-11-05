// from server: 100% by auto
// roc 2011-06 00541da0  unit: G3D::Sphere  size: 346 bytes
// Make this compile to the exact bytes below, then: roc check 2011-06 00541da0
//
// 00541da0  83ec1c               sub esp, 0x1c
// 00541da3  56                   push esi
// 00541da4  8b442428             mov eax, dword ptr [esp + 0x28]
// 00541da8  f30f105810           movss xmm3, dword ptr [eax + 0x10]
// 00541dad  f30f104004           movss xmm0, dword ptr [eax + 4]
// 00541db2  f30f104808           movss xmm1, dword ptr [eax + 8]
// 00541db7  f30f59cb             mulss xmm1, xmm3
// 00541dbb  f30f10500c           movss xmm2, dword ptr [eax + 0xc]
// 00541dc0  f30f106104           movss xmm4, dword ptr [ecx + 4]
// 00541dc5  f30f59c3             mulss xmm0, xmm3
// 00541dc9  f30f59d3             mulss xmm2, xmm3
// 00541dcd  f30f105908           movss xmm3, dword ptr [ecx + 8]
// 00541dd2  f30f59da             mulss xmm3, xmm2
// 00541dd6  f30f59e1             mulss xmm4, xmm1
// 00541dda  f30f58dc             addss xmm3, xmm4
// 00541dde  f30f1021             movss xmm4, dword ptr [ecx]
// 00541de2  f30f59e0             mulss xmm4, xmm0
// 00541de6  f30f58dc             addss xmm3, xmm4
// 00541dea  f30f585924           addss xmm3, dword ptr [ecx + 0x24]
// 00541def  f30f115c2408         movss dword ptr [esp + 8], xmm3
// 00541df5  f30f105910           movss xmm3, dword ptr [ecx + 0x10]
// 00541dfa  f30f59d9             mulss xmm3, xmm1
// 00541dfe  0f28e0               movaps xmm4, xmm0
// 00541e01  f30f59610c           mulss xmm4, dword ptr [ecx + 0xc]
// 00541e06  f30f58dc             addss xmm3, xmm4
// 00541e0a  0f28e2               movaps xmm4, xmm2
// 00541e0d  f30f596114           mulss xmm4, dword ptr [ecx + 0x14]
// 00541e12  f30f58dc             addss xmm3, xmm4
// 00541e16  f30f585928           addss xmm3, dword ptr [ecx + 0x28]
// 00541e1b  f30f106104           movss xmm4, dword ptr [ecx + 4]
// 00541e20  f30f115c240c         movss dword ptr [esp + 0xc], xmm3
// 00541e26  f30f10591c           movss xmm3, dword ptr [ecx + 0x1c]
// 00541e2b  f30f59d9             mulss xmm3, xmm1
// 00541e2f  f30f104918           movss xmm1, dword ptr [ecx + 0x18]
// 00541e34  f30f59c8             mulss xmm1, xmm0
// 00541e38  f30f104120           movss xmm0, dword ptr [ecx + 0x20]
// 00541e3d  f30f58d9             addss xmm3, xmm1
// 00541e41  f30f104808           movss xmm1, dword ptr [eax + 8]
// 00541e46  f30f59e1             mulss xmm4, xmm1
// 00541e4a  f30f59c2             mulss xmm0, xmm2
// 00541e4e  f30f105004           movss xmm2, dword ptr [eax + 4]
// 00541e53  f30f58d8             addss xmm3, xmm0
// 00541e57  f30f58592c           addss xmm3, dword ptr [ecx + 0x2c]
// 00541e5c  f30f10400c           movss xmm0, dword ptr [eax + 0xc]
// 00541e61  f30f115c2410         movss dword ptr [esp + 0x10], xmm3
// 00541e67  0f28da               movaps xmm3, xmm2
// 00541e6a  f30f5919             mulss xmm3, dword ptr [ecx]
// 00541e6e  f30f58dc             addss xmm3, xmm4
// 00541e72  f30f106108           movss xmm4, dword ptr [ecx + 8]
// 00541e77  f30f59e0             mulss xmm4, xmm0
// 00541e7b  f30f58dc             addss xmm3, xmm4
// 00541e7f  f30f115c2414         movss dword ptr [esp + 0x14], xmm3
// 00541e85  0f28d9               movaps xmm3, xmm1
// 00541e88  f30f595910           mulss xmm3, dword ptr [ecx + 0x10]
// 00541e8d  0f28e2               movaps xmm4, xmm2
// 00541e90  f30f59610c           mulss xmm4, dword ptr [ecx + 0xc]
// 00541e95  f30f58dc             addss xmm3, xmm4
// 00541e99  0f28e0               movaps xmm4, xmm0
// 00541e9c  f30f596114           mulss xmm4, dword ptr [ecx + 0x14]
// 00541ea1  f30f58dc             addss xmm3, xmm4
// 00541ea5  f30f115c2418         movss dword ptr [esp + 0x18], xmm3
// 00541eab  f30f10591c           movss xmm3, dword ptr [ecx + 0x1c]
// 00541eb0  f30f59d9             mulss xmm3, xmm1
// 00541eb4  f30f104918           movss xmm1, dword ptr [ecx + 0x18]
// 00541eb9  f30f59ca             mulss xmm1, xmm2
// 00541ebd  8b742424             mov esi, dword ptr [esp + 0x24]
// 00541ec1  f30f58d9             addss xmm3, xmm1
// 00541ec5  f30f104920           movss xmm1, dword ptr [ecx + 0x20]
// 00541eca  8d442408             lea eax, [esp + 8]
// 00541ece  50                   push eax
// 00541ecf  8d4c2418             lea ecx, [esp + 0x18]
// 00541ed3  f30f59c8             mulss xmm1, xmm0
// 00541ed7  51                   push ecx
// 00541ed8  f30f58d9             addss xmm3, xmm1
// 00541edc  8bce                 mov ecx, esi
// 00541ede  c744240c00000000     mov dword ptr [esp + 0xc], 0
// 00541ee6  f30f115c2424         movss dword ptr [esp + 0x24], xmm3
// 00541eec  e8ff050100           call 0x5524f0
// 00541ef1  8bc6                 mov eax, esi
// 00541ef3  5e                   pop esi
// 00541ef4  83c41c               add esp, 0x1c
// 00541ef7  c20800               ret 8
// library rbx2016-g3d/CoordinateFrame.cpp (function ?toWorldSpace@CoordinateFrame@G3D@@QBE?AVPlane@2@ABV32@@Z)

// roc-lang: cpp
// roc-cl: 21022
// roc-flags: /O2 /GS- /EHsc /MD /arch:SSE2 /fp:fast
// roc-lib: rbx2016-g3d CoordinateFrame.cpp
